/// @file
/// @brief Contains Switch::System::Drawing::FontStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief The System.Drawing::Drawing2D namespace provides advanced two-dimensional and vector graphics functionality.
      namespace Drawing2D {
        /// @brief Specifies the style of dashed lines drawn with a System::Drawing::Pen object.
        /// @par Library
        /// Switch.System.Drawing
        enum class DashStyle {
          /// @brief Specifies a solid line.
          Solid = 0,
          /// @brief Specifies a line consisting of dashes.
          Dash = 1,
          /// @brief Specifies a line consisting of dots.
          Dot = 2,
          /// @brief Specifies a line consisting of a repeating pattern of dash-dot.
          DashDot = 3,
          /// @brief Specifies a line consisting of a repeating pattern of dash-dot-dot.
          DashDotDot = 4,
          /// @brief Specifies a user-defined custom dash style.
          Custom = 5
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Drawing::Drawing2D::DashStyle> : public TrueType {};

template<>
struct EnumRegister<System::Drawing::Drawing2D::DashStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Drawing::Drawing2D::DashStyle, string>& values, bool& flags) {
    values[System::Drawing::Drawing2D::DashStyle::Solid] = "Solid";
    values[System::Drawing::Drawing2D::DashStyle::Dash] = "Dash";
    values[System::Drawing::Drawing2D::DashStyle::Dot] = "Dot";
    values[System::Drawing::Drawing2D::DashStyle::DashDot] = "DashDot";
    values[System::Drawing::Drawing2D::DashStyle::DashDotDot] = "DashDotDot";
    values[System::Drawing::Drawing2D::DashStyle::Custom] = "Custom";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
