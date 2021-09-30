#include <Switch/System/Array.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/Math.hpp>
#include <Switch/System/OutOfMemoryException.hpp>
#include <Switch/System/IO//BinaryReader.hpp>

#include "../../../../include/Switch/System/Drawing/Image.hpp"
#include "../../../../include/Switch/System/Drawing/Imaging/FrameDimension.hpp"

namespace Switch {
  namespace System {
    namespace Drawing {
      struct BitmapFileHeader {
        int16 type;
        int32 size;
        int16 reserved1;
        int16 reserved2;
        int32 offBits;
      };

      struct BitmapInfoHeader {
        int32 size;
        int32 width;
        int32 height;
        int16 planes;
        int16 bitCount;
        int32 compression;
        int32 sizeImage;
        int32 xPixelsPerMeter;
        int32 yPixelsPerMeter;
        int32 colorUsed;
        int32 colorImportant;
      };

      struct RgbQuad {
        byte blue;
        byte green;
        byte red;
        byte reserved;
      };

      class Bmp : public object {
      public:
        template<typename TStream>
        Bmp(const TStream& stream) : reader(stream) {}

        void Read(Image& image) {
          BitmapFileHeader bmpFile = ReadBitmapFileHeader();
          BitmapInfoHeader bmpInfo = ReadBitmapInfoHeader();

          this->reader.BaseStream().Seek(bmpInfo.size - (bmpInfo.size < 40 ? 12 : 40), Switch::System::IO::SeekOrigin::Current);

          Array<Color> colors;
          if (bmpInfo.compression == bitmapInfoCompressionRgb && bmpInfo.bitCount <= 8)
            colors = ReadColorTable(bmpInfo.colorUsed ? bmpInfo.colorUsed : 1 << bmpInfo.bitCount);

          int32 pixelFormatInfo = 0;
          if (bmpInfo.bitCount == 16)
            pixelFormatInfo = this->reader.ReadInt32();

          this->reader.BaseStream().Seek(bmpFile.offBits, Switch::System::IO::SeekOrigin::Begin);

          System::Array<byte> rawData = ReadData(bmpInfo.width, bmpInfo.height, bmpInfo.bitCount, bmpInfo.compression, pixelFormatInfo, colors);

          ToImage(image, bmpFile, bmpInfo, colors, rawData, pixelFormatInfo);
        }

      private:
        static const int32 bitmapInfoCompressionRgb = 0;
        static const int32 bitmapInfoCompressionRle8 = 1;
        static const int32 bitmapInfoCompressionRle4 = 2;
        static const int32 bitmapInfoCompressionBkitFields = 3;

        BitmapFileHeader ReadBitmapFileHeader() {
          BitmapFileHeader bmpFile;
          bmpFile.type = this->reader.ReadInt16();
          bmpFile.size = this->reader.ReadInt32();
          bmpFile.reserved1 = this->reader.ReadInt16();
          bmpFile.reserved2 = this->reader.ReadInt16();
          bmpFile.offBits = this->reader.ReadInt32();
          return bmpFile;
        }

        BitmapInfoHeader ReadBitmapInfoHeader() {
          BitmapInfoHeader bmpInfo;
          bmpInfo.size = this->reader.ReadInt32();
          bmpInfo.width = this->reader.ReadInt32();
          bmpInfo.height = this->reader.ReadInt32();
          bmpInfo.planes = this->reader.ReadInt16();
          bmpInfo.bitCount = this->reader.ReadInt16();

          if (bmpInfo.size < 40) {
            bmpInfo.compression = bitmapInfoCompressionRgb;
            bmpInfo.sizeImage = 0;
            bmpInfo.xPixelsPerMeter = 2835; // To check
            bmpInfo.yPixelsPerMeter = 2835; // To check
            bmpInfo.colorUsed = 0;
            bmpInfo.colorImportant = 0;
          } else {
            bmpInfo.compression = this->reader.ReadInt32();
            bmpInfo.sizeImage = this->reader.ReadInt32();
            bmpInfo.xPixelsPerMeter = this->reader.ReadInt32();
            bmpInfo.yPixelsPerMeter = this->reader.ReadInt32();
            bmpInfo.colorUsed = this->reader.ReadInt32();
            bmpInfo.colorImportant = this->reader.ReadInt32();
          }
          return bmpInfo;
        }

        Array<Color> ReadColorTable(int32 length) {
          Array<Color> colors(length);
          for (int32 i  = 0; i < colors.Length(); i++) {
            RgbQuad rgbQuad = ReadRgbQuad();
            colors[i] = Color::FromArgb(0xFF, rgbQuad.red, rgbQuad.green, rgbQuad.blue);
          }
          return colors;
        }

        System::Array<byte> ReadData(int32 width, int32 height, int32 bitCount, int32 compression, int32 pixelFormatInfo, const Array<Color>& colors) {
          int size = width * Math::Abs(height) * (bitCount == 32 ? 4 : 3);
          System::Array<byte> rawData(size);

          int32 start = Math::Abs(height) - 1;
          int32 end = -1;

          if (height < 0) {
            start = 0;
            end = Math::Abs(height);
          }

          for (int32 y = start; y != end; y -= height / Math::Abs(height)) {
            byte* ptr = &rawData[y * width * (bitCount == 32 ? 4 : 3)];

            switch (bitCount) {
            case 1: ReadLine1Bit(ptr, width, colors); break;
            case 4: ReadLine4Bits(ptr, width, compression, colors); break;
            case 8: ReadLine8Bits(ptr, width, compression, colors); break;
            case 16: ReadLine16Bits(ptr, width, pixelFormatInfo); break;
            case 24: ReadLine24Bits(ptr, width, pixelFormatInfo); break;
            case 32: ReadLine32Bits(ptr, width); break;
            default: throw OutOfMemoryException(caller_); break;
            }
          }

          return rawData;
        }

        void ReadLine1Bit(byte* ptr, int32 width, const Array<Color>& colors) {
          byte value = 0;
          for (int x = width, bit = 128; x > 0; x --) {
            if (bit == 128)
              value = this->reader.ReadByte();

            if (value & bit) {
              ptr[0] = colors[1].R();
              ptr[1] = colors[1].G();
              ptr[2] = colors[1].B();
            } else {
              ptr[0] = colors[0].R();
              ptr[1] = colors[0].G();
              ptr[2] = colors[0].B();
            }
            ptr += 3;

            if (bit > 1)
              bit >>= 1;
            else
              bit = 128;
          }

          for (int32 align = (width + 7) / 8; align & 3; align ++)
            this->reader.ReadByte();
        }

        void ReadLine4Bits(byte* ptr, int32 width, int32 compression, const Array<Color>& colors) {
          if (compression != bitmapInfoCompressionRle4) {
            byte value = 0;
            for (int x = width, bit = 0xf0; x > 0; x--) {
              if (bit == 0xf0) {
                value = this->reader.ReadByte();

                ptr[0] = colors[(value >> 4) & 15].R();
                ptr[1] = colors[(value >> 4) & 15].G();
                ptr[2] = colors[(value >> 4) & 15].B();

                bit  = 0x0f;
              } else {
                ptr[0] = colors[value & 15].R();
                ptr[1] = colors[value & 15].G();
                ptr[2] = colors[value & 15].B();

                bit  = 0xf0;
              }
              ptr += 3;

              for (int32 align = (width + 1) / 2; align & 3; align ++)
                this->reader.ReadByte();
            }
          }
        }

        void ReadLine8Bits(byte* ptr, int32 width, int32 compression, const Array<Color>& colors) {
          if (compression != bitmapInfoCompressionRle8) {
            for (int32 x = width; x > 0; x--) {
              int32 color = 0;

              color = this->reader.ReadByte();

              ptr[0] = colors[color].R();
              ptr[1] = colors[color].G();
              ptr[2] = colors[color].B();
              ptr += 3;
            }

            for (int32 align = width; align & 3; align ++)
              this->reader.ReadByte();
          }
        }

        void ReadLine16Bits(byte* ptr, int32 width, int32 pixelFormatInfo) {
          for (int32 x = width; x > 0; x--) {
            byte b = this->reader.ReadByte();
            byte a = this->reader.ReadByte();
            if (pixelFormatInfo == 0xF800) {
              ptr[2] = (byte)((b << 3) & 0xf8);
              ptr[1] = (byte)(((a << 5) & 0xe0) | ((b >> 3) & 0x1c));
              ptr[0] = (byte)(a & 0xf8);
            } else {
              ptr[2] = (byte)((b << 3) & 0xf8);
              ptr[1] = (byte)(((a << 6) & 0xc0) | ((b >> 2) & 0x38));
              ptr[0] = (byte)((a << 1) & 0xf8);
            }
            ptr += 3;

          }

          for (int32 align = width * 2; align & 3; align ++)
            this->reader.ReadByte();
        }

        void ReadLine24Bits(byte* ptr, int32 width, int32 pixelFormatInfo) {
          for (int32 x = width; x > 0; x--) {
            ptr[2] = this->reader.ReadByte();
            ptr[1] = this->reader.ReadByte();
            ptr[0] = this->reader.ReadByte();
            ptr += 3;
          }

          for (int32 align = width * 3; align & 3; align ++)
            this->reader.ReadByte();

        }

        void ReadLine32Bits(byte* ptr, int32 width) {
          for (int32 x = width; x > 0; x--) {
            this->reader.ReadByte(); // Read unsed value...
            ptr[3] = 0xFF; // alpha value is always equal to 0xFF
            ptr[2] = this->reader.ReadByte();
            ptr[1] = this->reader.ReadByte();
            ptr[0] = this->reader.ReadByte();
            ptr += 4;
          }
        }

        RgbQuad ReadRgbQuad() {
          RgbQuad rgbQuad;
          rgbQuad.blue = this->reader.ReadByte();
          rgbQuad.green = this->reader.ReadByte();
          rgbQuad.red = this->reader.ReadByte();
          rgbQuad.reserved = this->reader.ReadByte();
          return rgbQuad;
        }

        void ToImage(Image& image, const BitmapFileHeader& bmpFile, const BitmapInfoHeader& bmpInfo, const Array<Color>& colors, Array<byte> rawData, int32 pixelFormatInfo) {
          static const float inchesPerMeter = 39.3700787f;

          image.flags = Imaging::ImageFlags::ReadOnly | Imaging::ImageFlags::HasRealPixelSize | Imaging::ImageFlags::HasRealDpi | Imaging::ImageFlags::ColorSpaceRgb;
          image.frameDimensionList = {Imaging::FrameDimension::Page().Guid};
          image.horizontalResolution = Convert::ToSingle(bmpInfo.xPixelsPerMeter) / inchesPerMeter;
          image.palette.entries = colors;

          switch (bmpInfo.bitCount) {
          case 8: image.pixelFormat = Imaging::PixelFormat::Format8bppIndexed; break;
          case 16: image.pixelFormat = pixelFormatInfo == 0xF800 ? Imaging::PixelFormat::Format16bppRgb565 : Imaging::PixelFormat::Format16bppRgb555; break;
          case 24: image.pixelFormat = Imaging::PixelFormat::Format24bppRgb; break;
          case 32: image.pixelFormat = Imaging::PixelFormat::Format32bppRgb; break;
          default: image.pixelFormat = Imaging::PixelFormat::Undefined; break;
          }

          image.verticalResolution = Convert::ToSingle(bmpInfo.yPixelsPerMeter) / inchesPerMeter;
          image.size = Size(bmpInfo.width, Math::Abs(bmpInfo.height));

          image.rawFormat = Imaging::ImageFormat::Bmp;
          //image.rawData = Array<byte>(rawData.Data, image.size.Width() * image.size.Height() * (image.PixelFormat() == System::Drawing::Imaging::PixelFormat::Format32bppRgb ? 4 : 3));
          image.rawData = rawData;
        }

        System::IO::BinaryReader reader;
      };
    }
  }
}
