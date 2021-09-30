/// @file
/// @brief Contains Switch::System::Drawing::Imaging::ColorPalette class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/Array.hpp>
#include "../../../SystemDrawingExport.hpp"
#include "../Color.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @cond
      class Bmp;
      class Image;
      /// @endcond

      /// @brief The System::Drawing::Imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the System::Drawing namespace.
      /// @par Library
      /// Switch.System.Drawing
      namespace Imaging {
        class system_drawing_export_ ColorPalette : public object {
        public:
          /// @cond
          ColorPalette(const ColorPalette& colorPalette) : entries(colorPalette.entries), flags(colorPalette.flags) {}
          /// @endcond
          property_<Array<Color>, readonly_> Entries {
            get_ {return this->entries;}
          };

          property_<int32, readonly_> Falgs {
            get_ {return this->flags;}
          };

        private:
          friend class Switch::System::Drawing::Bmp;
          friend class Switch::System::Drawing::Image;
          ColorPalette() : flags(0) {}

          Array<Color> entries;
          int32 flags;
        };
      }
    }
  }
}
