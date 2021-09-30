#include <Switch/System/IO/File.hpp>
#include "../../../../include/Switch/System/Drawing/Image.hpp"

#include <csetjmp>
#include <cstdio>

#include <zlib.h>
//#define HAVE_BOOLEAN  // Must be define because boolean definition is ambigous...
#include <jpeglib.h>
//#undef HAVE_BOOLEAN

#include "Bmp.hpp"
#include "Gif.hpp"
#pragma warning(push)
#pragma warning(disable:4324)
#pragma warning(disable:4611)
#include "Jpg.hpp"
#include "Png.hpp"
#pragma warning(pop)
#include "Tif.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::IO;

property_<Image, readonly_> Image::None {
  [] {return Image();}
};

Image::Image() {
}

Image::Image(refptr<System::IO::Stream> stream) {
  ReadStream(stream);
}

Image::Image(const string& fileName) {
  FileStream fs = File::Open(fileName, FileMode::Open, FileAccess::Read);
  ReadStream(fs.MemberwiseClone<FileStream>().As<FileStream>());
}

Image::Image(const Image& image) : flags(image.flags), frameDimensionList(image.frameDimensionList), horizontalResolution(image.horizontalResolution), pixelFormat(image.pixelFormat), palette(image.palette), rawData(image.rawData), rawFormat(image.rawFormat), size(image.size), tag(image.tag), verticalResolution(image.verticalResolution) {
}

refptr<Image> Image::FromFile(const string& fileName) {
  return new Image(fileName);
}

refptr<Image> Image::FromData(const char* data[]) {
  refptr<Image> image = ref_new<Image>();

  Array<string> infos = string(data[0]).Split(' ');
  int32 columns = Int32::Parse(infos[0]);
  int32 rows = Int32::Parse(infos[1]);
  int32 colors = Int32::Parse(infos[2]);
  int32 charPerPixel = Int32::Parse(infos[3]);

  System::Collections::Generic::Dictionary<String, Color> palette;

  for (int32 index1 = 0; index1 < colors; index1++) {
    string colorLine(data[1 + index1]);
    if (colorLine.Contains("None"))
      palette[colorLine.Substring(0, charPerPixel)] = Color::Transparent;
    else
      palette[colorLine.Substring(0, charPerPixel)] = Color::FromArgb(255, Int32::Parse(colorLine.Substring(4 + charPerPixel, 2), 16), Int32::Parse(colorLine.Substring(6 + charPerPixel, 2), 16), Int32::Parse(colorLine.Substring(8 + charPerPixel, 2), 16));
  }

  image->rawData = Array<byte>(columns * rows * 3);

  for (int32 index1 = 0; index1 < rows; index1++) {
    string colorLine(data[1 + colors + index1]);
    for (int32 index2 = 0; index2 < columns; index2++) {
      string pixel = colorLine.Substring(0, charPerPixel);
      colorLine = colorLine.Remove(0, charPerPixel);
      image->rawData[(index1 * columns * 3) + (index2 * 3)] = static_cast<byte>(palette[pixel].R());
      image->rawData[(index1 * columns * 3) + (index2 * 3) + 1] = static_cast<byte>(palette[pixel].G());
      image->rawData[(index1 * columns * 3) + (index2 * 3) + 2] = static_cast<byte>(palette[pixel].B());
    }
  }

  image->flags = Imaging::ImageFlags::ReadOnly | Imaging::ImageFlags::HasRealPixelSize | Imaging::ImageFlags::HasRealDpi | Imaging::ImageFlags::ColorSpaceRgb;
  image->frameDimensionList = {Imaging::FrameDimension::Page().Guid};
  //image->horizontalResolution = Convert::ToSingle(bmpInfo.xPixelsPerMeter) / inchesPerMeter;
  image->pixelFormat = Imaging::PixelFormat::Format24bppRgb;
  //image->verticalResolution = Convert::ToSingle(bmpInfo.yPixelsPerMeter) / inchesPerMeter;
  image->size = System::Drawing::Size(columns, rows);
  image->rawFormat = Imaging::ImageFormat::MemoryBmp;

  return image;
}

void Image::ReadStream(refptr<System::IO::Stream> stream) {
  refptr<BinaryReader> reader = new BinaryReader(stream);

  uint16 magicNumber = reader->ReadUInt16();
  reader->BaseStream().Seek(0, Switch::System::IO::SeekOrigin::Begin);

  // List of file signatures
  // http://en.wikipedia.org/wiki/List_of_file_signatures

  switch (magicNumber) {
  case 0x4D42: Bmp(stream).Read(*this); break;
  case 0xD8FF: Jpg(stream).Read(*this); break;
  case 0x4947: Gif(stream).Read(*this); break;
  case 0x5089: Png(stream).Read(*this); break;
  case 0x4949: Tif(stream).Read(*this); break;
  case 0x4D4D: Tif(stream).Read(*this); break;
  default: throw OutOfMemoryException(caller_); break;
  }
}
