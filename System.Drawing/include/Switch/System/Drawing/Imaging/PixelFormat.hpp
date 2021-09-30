/// @file
/// @brief Contains Switch::System::Drawing::Imaging::PixelFormat enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief The System::Drawing::Imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the System::Drawing namespace.
      namespace Imaging {
        /// @brief Specifies the format of the color data for each pixel in the image.
        /// @remarks The pixel format defines the number of bits of memory associated with one pixel of data. The format also defines the order of the color components within a single pixel of data.
        /// @remarks PixelFormat48bppRGB, PixelFormat64bppARGB, and PixelFormat64bppPARGB use 16 bits per color component (channel). GDI+ version 1.0 and 1.1 can read 16-bits-per-channel images, but such images are converted to an 8-bits-per-channel format for processing, displaying, and saving. Each 16-bit color channel can hold a value in the range 0 through 2^13.
        /// @remarks Some of the pixel formats contain premultiplied color values. Premultiplied means that the color values have already been multiplied by an alpha value.
        /// @par Library
        /// Switch.System.Drawing
        enum class PixelFormat {
          /// @brief The pixel data contains alpha values that are not premultiplied.
          Alpha = 262144,
          /// @brief The default pixel format of 32 bits per pixel. The format specifies 24-bit color depth and an 8-bit alpha channel.
          Canonical = 2097152,
          /// @brief No pixel format is specified.
          DontCare = 0,
          /// @brief Reserved.
          Extended = 1048576,
          /// @brief The pixel format is 16 bits per pixel. The color information specifies 32,768 shades of color, of which 5 bits are red, 5 bits are green, 5 bits are blue, and 1 bit is alpha.
          Format16bppArgb1555 = 397319,
          /// @brief The pixel format is 16 bits per pixel. The color information specifies 65536 shades of gray.
          Format16bppGrayScale = 1052676,
          /// @brief Specifies that the format is 16 bits per pixel; 5 bits each are used for the red, green, and blue components. The remaining bit is not used.
          Format16bppRgb555 = 135173,
          /// @brief Specifies that the format is 16 bits per pixel; 5 bits are used for the red component, 6 bits are used for the green component, and 5 bits are used for the blue component.
          Format16bppRgb565,
          /// @brief Specifies that the pixel format is 1 bit per pixel and that it uses indexed color. The color table therefore has two colors in it.
          Format1bppIndexed = 196865,
          /// @brief Specifies that the format is 24 bits per pixel; 8 bits each are used for the red, green, and blue components.
          Format24bppRgb = 137224,
          /// @brief Specifies that the format is 32 bits per pixel; 8 bits each are used for the alpha, red, green, and blue components.
          Format32bppArgb = 2498570,
          /// @brief Specifies that the format is 32 bits per pixel; 8 bits each are used for the alpha, red, green, and blue components. The red, green, and blue components are premultiplied, according to the alpha component.
          Format32bppPArgb = 925707,
          /// @brief Specifies that the format is 32 bits per pixel; 8 bits each are used for the red, green, and blue components. The remaining 8 bits are not used.
          Format32bppRgb = 139273,
          /// @brief Specifies that the format is 48 bits per pixel; 16 bits each are used for the red, green, and blue components.
          Format48bppRgb = 1060876,
          /// @brief Specifies that the format is 4 bits per pixel, indexed.
          Format4bppIndexed = 197634,
          /// @brief Specifies that the format is 64 bits per pixel; 16 bits each are used for the alpha, red, green, and blue components.
          Format64bppArgb = 3424269,
          /// @brief Specifies that the format is 64 bits per pixel; 16 bits each are used for the alpha, red, green, and blue components. The red, green, and blue components are premultiplied according to the alpha component.
          Format64bppPArgb = 1851406,
          /// @brief Specifies that the format is 8 bits per pixel, indexed. The color table therefore has 256 colors in it.
          Format8bppIndexed = 198659,
          /// @brief The pixel data contains GDI colors.
          Gdi = 131072,
          /// @brief The pixel data contains color-indexed values, which means the values are an index to colors in the system color table, as opposed to individual color values.
          Indexed = 65536,
          /// @brief The maximum value for this enumeration.
          Max = 15,
          /// The pixel format contains premultiplied alpha values.
          PAlpha = 524288,
          /// The pixel format is undefined.
          Undefined = 0
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Drawing::Imaging::PixelFormat> {
  void operator()(System::Collections::Generic::IDictionary<System::Drawing::Imaging::PixelFormat, string>& values, bool& flags) {
    values[System::Drawing::Imaging::PixelFormat::Alpha] = "Alpha";
    values[System::Drawing::Imaging::PixelFormat::Canonical] = "Canonical";
    values[System::Drawing::Imaging::PixelFormat::DontCare] = "DontCare";
    values[System::Drawing::Imaging::PixelFormat::Format16bppArgb1555] = "Format16bppArgb1555";
    values[System::Drawing::Imaging::PixelFormat::Format16bppGrayScale] = "Format16bppGrayScale";
    values[System::Drawing::Imaging::PixelFormat::Format16bppRgb555] = "Format16bppRgb555";
    values[System::Drawing::Imaging::PixelFormat::Format16bppRgb565] = "Format16bppRgb565";
    values[System::Drawing::Imaging::PixelFormat::Format1bppIndexed] = "Format1bppIndexed";
    values[System::Drawing::Imaging::PixelFormat::Format24bppRgb] = "Format24bppRgb";
    values[System::Drawing::Imaging::PixelFormat::Format32bppArgb] = "Format32bppArgb";
    values[System::Drawing::Imaging::PixelFormat::Format32bppPArgb] = "Format32bppPArgb";
    values[System::Drawing::Imaging::PixelFormat::Format32bppRgb] = "Format32bppRgb";
    values[System::Drawing::Imaging::PixelFormat::Format48bppRgb] = "Format48bppRgb";
    values[System::Drawing::Imaging::PixelFormat::Format4bppIndexed] = "Format4bppIndexed";
    values[System::Drawing::Imaging::PixelFormat::Format64bppArgb] = "Format64bppArgb";
    values[System::Drawing::Imaging::PixelFormat::Format64bppPArgb] = "Format64bppPArgb";
    values[System::Drawing::Imaging::PixelFormat::Format8bppIndexed] = "Format8bppIndexed";
    values[System::Drawing::Imaging::PixelFormat::Gdi] = "Gdi";
    values[System::Drawing::Imaging::PixelFormat::Indexed] = "Indexed";
    values[System::Drawing::Imaging::PixelFormat::Max] = "Max";
    values[System::Drawing::Imaging::PixelFormat::PAlpha] = "PAlpha";
    values[System::Drawing::Imaging::PixelFormat::Undefined] = "Undefined";
    flags = false;
  }
};
/// @endcond
