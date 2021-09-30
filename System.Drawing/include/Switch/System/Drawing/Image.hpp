/// @file
/// @brief Contains Switch::System::Drawing::Image class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include <Switch/RefPtr.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/IComparable.hpp>
#include <Switch/System/IO/Stream.hpp>
#include "../../SystemDrawingExport.hpp"
#include "Imaging/ColorPalette.hpp"
#include "Imaging/ImageFlags.hpp"
#include "Imaging/ImageFormat.hpp"
#include "Imaging/PixelFormat.hpp"
#include "Size.hpp"
#include "SizeF.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @cond
  /// TODO : To remove as soon as possible...
  namespace Resources {
    class Image;
  }
  /// @endcond

  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @cond
      class Bmp;
      class Jpg;
      class Png;
      class Gif;
      /// @endcond

      /// @brief An abstract base class that provides functionality for the System::Drawing::Bitmap and System::Drawing::Imaging::Metafile descended classes.
      /// @remarks To draw an System::Drawing::Image on a Windows Form, you should use one of the Graphics::DrawImage(Image, Point) methods.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ Image : public object, public IComparable {
      public:
        /// @cond
        Image();
        Image(const Image& image);
        /// @endcond

        property_<const byte*, readonly_> Data {
          get_ {return this->rawData.Data();}
        };

        static property_<Image, readonly_> None;

        /// @brief Gets attribute flags for the pixel data of this System::Drawing::Image.
        /// @return a value of System::Drawing::Imaging::ImageFlags.
        /// @remarks The integer value returned from this method will correspond to a sum of System::Drawing::Imaging::ImageFlags, as described in the following table.
        /// | ImageFlag value              | Integer representation |
        /// |------------------------------|------------------------|
        /// | ImageFlagsNone               | 0                      |
        /// | IImageFlagsScalable          | 1                      |
        /// | IImageFlagsHasAlpha          | 2                      |
        /// | IImageFlagsHasTranslucent    | 4                      |
        /// | IImageFlagsPartiallyScalable | 8                      |
        /// | IImageFlagsColorSpaceRGB     | 16                     |
        /// | IImageFlagsColorSpaceCMYK    | 32                     |
        /// | IImageFlagsColorSpaceGRAY    | 64                     |
        /// | IImageFlagsColorSpaceYCBCR   | 128                    |
        /// | IImageFlagsColorSpaceYCCK    | 256                    |
        /// | IImageFlagsHasRealDPI        | 4096                   |
        /// | IImageFlagsHasRealPixelSize  | 8192                   |
        /// | IImageFlagsReadOnly          | 65536                  |
        /// | IImageFlagsCaching           | 131072                 |
        /// @remarks For example, if the Image::Flags property for an image returned 77960, the System::Drawing::Imaging::ImageFlags for the image would be System::Drawing::Imaging::ImageFlags::ReadOnly, System::Drawing::Imaging::ImageFlags::HasRealDpi, System::Drawing::Imaging::ImageFlags::HasRealPixelSize, System::Drawing::Imaging::ImageFlags::ColorSpaceYcbcr, and System::Drawing::Imaging::ImageFlags::PartiallyScalable.
        property_<int32, readonly_> Flags {
          get_ {return (int32)this->flags;}
        };

        property_<Array<System::Guid>, readonly_> FrameDimensionsList {
          get_ {return frameDimensionList;}
        };

        property_<int32, readonly_> Height {
          get_ {return this->size.Height();}
        };

        property_<float, readonly_> HorizontalResolution {
          get_ {return this->horizontalResolution;}
        };

        property_<Imaging::ColorPalette> Palette {
          get_ {return this->palette;},
          set_ {this->palette = value;}
        };

        property_<SizeF, readonly_> PhysicalDimension {
          get_ {return SizeF(Convert::ToSingle(this->size.Width()) * this->horizontalResolution, Convert::ToSingle(this->size.Height()) * this->verticalResolution);}
        };

        property_<Imaging::PixelFormat, readonly_> PixelFormat {
          get_ {return this->pixelFormat;}
        };

        property_<Imaging::ImageFormat, readonly_> RawFormat {
          get_ {return this->rawFormat;}
        };

        property_<System::Drawing::Size, readonly_> Size {
          get_ {return this->size;}
        };

        property_<const object&> Tag {
          get_->const object& {return *this->tag;},
          set_ {this->tag = &value;}
        };

        property_<float, readonly_> VerticalResolution {
          get_ {return this->verticalResolution;}
        };

        property_<int32, readonly_> Width {
          get_ {return this->size.Width();}
        };

        static refptr<Image> FromFile(const string& fileName);

        template<typename TStream>
        static refptr<Image> FromStream(const TStream& stream) {return new Image(stream.template MemberwiseClone<TStream>().template As<TStream>());}

        static refptr<Image> FromStream(refptr<System::IO::Stream> stream) {return new Image(stream);}

        static refptr<Image> FromData(const char* data[]);

        virtual int32 CompareTo(const IComparable& obj) const {
          if (!is<Image>(obj))
            return 1;
          return CompareTo(as<Image>(obj));
        }

        virtual int32 CompareTo(const Image& value) const {return IntPtr((intptr)&rawData).CompareTo(IntPtr((intptr)&rawData));}

        virtual int32 GetHashCode() const {return IntPtr((intptr)&rawData).GetHashCode();}

      protected:
        /// @cond
        friend Bmp;
        friend Jpg;
        friend Png;
        friend Gif;
        friend Resources::Image;
        Image(const string& fileName);
        Image(refptr<System::IO::Stream> stream);

        void ReadStream(refptr<System::IO::Stream> stream);
        void ReadWindowsBmp(refptr<System::IO::Stream> stream);

        Imaging::ImageFlags flags;
        Array<Guid> frameDimensionList;
        float horizontalResolution = 1.0f;
        Imaging::PixelFormat pixelFormat;
        Imaging::ColorPalette palette;
        Array<byte> rawData;
        Imaging::ImageFormat rawFormat;
        System::Drawing::Size size;
        const object* tag = null;
        float verticalResolution = 1.0f;
        /// @endcond
      };
    }
  }
}
