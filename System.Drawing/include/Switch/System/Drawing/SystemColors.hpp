/// @file
/// @brief Contains Switch::System::Drawing::SystemColors enum.
#pragma once

#include <Switch/Static.hpp>
#include "../../SystemDrawingExport.hpp"
#include "Color.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Each property of the System::Drawing::SystemColors class is a System::Drawing::Color structure that is the color of a Windows display element.
      /// @remarks Better performance is achieved by using the properties of the System::Drawing::SystemPens or System::Drawing::SystemBrushes classes rather than creating a new pen or brush based on a value from System::Drawing::SystemColors. For example, if you wanted to get a brush for the face color of a 3-D element, use the SystemBrushes.Control property because it gets a brush that already exists, whereas calling the SolidBrush.#ctor(Color) constructor with a parameter value of SystemColors::Control will create a new brush.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ SystemColors static_ {
      public:
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
        static property_<Color, readonly_> ActiveBorder;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF0054E3. This field is constant.
        static property_<Color, readonly_> ActiveCaption;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static property_<Color, readonly_> ActiveCaptionText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF808080. This field is constant.
        static property_<Color, readonly_> AppWorkspace;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
        static property_<Color, readonly_> Control;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
        static property_<Color, readonly_> ControlDark;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF716F64. This field is constant.
        static property_<Color, readonly_> ControlDarkDark;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF1EFE2. This field is constant.
        static property_<Color, readonly_> ControlLight;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static property_<Color, readonly_> ControlLightLight;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static property_<Color, readonly_> ControlText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF004E98. This field is constant.
        static property_<Color, readonly_> Desktop;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
        static property_<Color, readonly_> GrayText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF316AC5. This field is constant.
        static property_<Color, readonly_> Highlight;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static property_<Color, readonly_> HighlightText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000080. This field is constant.
        static property_<Color, readonly_> HotTrack;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
        static property_<Color, readonly_> InactiveBorder;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF7A96DF. This field is constant.
        static property_<Color, readonly_> InactiveCaption;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD8E4F8. This field is constant.
        static property_<Color, readonly_> InactiveCaptionText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFE1. This field is constant.
        static property_<Color, readonly_> Info;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static property_<Color, readonly_> InfoText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static property_<Color, readonly_> Menu;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static property_<Color, readonly_> MenuText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
        static property_<Color, readonly_> ScrollBar;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static property_<Color, readonly_> Window;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static property_<Color, readonly_> WindowFrame;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static property_<Color, readonly_> WindowText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
        static property_<Color, readonly_> ButtonFace;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static property_<Color, readonly_> ButtonHighlight;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
        static property_<Color, readonly_> ButtonShadow;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF3D95FF. This field is constant.
        static property_<Color, readonly_> GradientActiveCaption;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF9DB9EB. This field is constant.
        static property_<Color, readonly_> GradientInactiveCaption;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
        static property_<Color, readonly_> MenuBar;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF316AC5. This field is constant.
        static property_<Color, readonly_> MenuHighlight;
      };
    }
  }
}
