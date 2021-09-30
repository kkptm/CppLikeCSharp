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
      /// @brief This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
      /// @par Library
      /// Switch.System.Drawing
      enum class FontStyle {
        /// @brief Normal text.
        Regular = 0,
        /// @brief Bold text.
        Bold = 0b1,
        /// @brief Italic text.
        Italic = 0b10,
        /// @brief Underline text.
        Underline = 0b100,
        /// @brief Text with a line through the middle.
        Strikeout = 0b1000
      };
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Drawing::FontStyle> : public TrueType {};

template<>
struct EnumRegister<System::Drawing::FontStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Drawing::FontStyle, string>& values, bool& flags) {
    values[System::Drawing::FontStyle::Regular] = "Regular";
    values[System::Drawing::FontStyle::Bold] = "Bold";
    values[System::Drawing::FontStyle::Italic] = "Italic";
    values[System::Drawing::FontStyle::Underline] = "Underline";
    values[System::Drawing::FontStyle::Strikeout] = "Strikeout";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
