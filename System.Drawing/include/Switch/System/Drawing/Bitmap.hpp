/// @file
/// @brief Contains Switch::System::Drawing::Bitmap class.
#pragma once

#include <Switch/RefPtr.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/IO/Stream.hpp>
#include "../../SystemDrawingExport.hpp"
#include "Image.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief An abstract base class that provides functionality for the System::Drawing::Bitmap and System::Drawing::Imaging::Metafile descended classes.
      /// @remarks To draw an System::Drawing::Image on a Windows Form, you should use one of the Graphics::DrawImage(Image, Point) methods.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ Bitmap : public Image {
      public:
        Bitmap(const Image& image) : Image(image) {}

        Bitmap(const string& fileName);

        template<typename TStream>
        Bitmap(const TStream& stream) : Image(stream) {}

        Bitmap(refptr<System::IO::Stream> stream) : Image(stream) {}

      private:
        Bitmap() {}
      };
    }
  }
}
