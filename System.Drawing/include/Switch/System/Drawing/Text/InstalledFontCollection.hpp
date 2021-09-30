/// @file
/// @brief Contains Switch::System::Drawing::FontFamily class.
#pragma once

#include "../../../SystemDrawingExport.hpp"
#include "FontCollection.hpp"

/// @cond
namespace Native {
  class DrawingApi;
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief The System::Drawing::Text namespace provides advanced GDI+ typography functionality.
      namespace Text {
        /// @brief Represents the fonts installed on the system. This class cannot be inherited.
        /// @remarks The InstalledFontCollection allows you to get a list of fonts families that are installed on the computer running the application with its Families property. For additional information on fonts and text, including example code, see Using Fonts and Text.
        /// @remarks Do not use the InstalledFontCollection class to install a font to Windows. Instead use the GDI AddFontResource function. An InstalledFontCollection object sees only fonts that are installed in Windows before the object is created.
        /// @par Library
        /// Switch.System.Drawing
        class system_drawing_export_ InstalledFontCollection final : public FontCollection {
        public:
          /// @brief Initializes a new instance of the InstalledFontCollection class.
          InstalledFontCollection();
        };
      }
    }
  }
}
