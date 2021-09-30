/// @file
/// @brief Contains Switch::System::Globalization::NumberStyles enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Globalization namespace contains classes that define culture-related information, including language, country/region, calendars in use, format patterns for dates, currency, and numbers, and sort order for strings. These classes are useful for writing globalized (internationalized) applications. Classes such as StringInfo and TextInfo provide advanced globalization functionalities, including surrogate support and text element processing.
    namespace Globalization {
      /// @brief Determines the styles permitted in numeric string arguments that are passed to the Parse and TryParse methods of the integral and floating-point numeric types.
      /// This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
      enum class NumberStyles {
        /// @brief Indicates that no style elements, such as leading or trailing white space, thousands separators, or a decimal separator, can be present in the parsed string. The string to be parsed must consist of integral decimal digits only.
        None = 0,
        /// @brief Indicates that leading white-space characters can be present in the parsed string. Valid white-space characters have the Unicode values U+0009, U+000A, U+000B, U+000C, U+000D, and U+0020. Note that this is a subset of the characters for which the Char.IsWhiteSpace method returns true.
        AllowLeadingWhite = 1,
        AllowTrailingWhite = 2,
        AllowLeadingSign = 4,
        AllowTrailingSign = 8,
        AllowParentheses = 16,
        AllowDecimalPoint = 32,
        AllowThousands = 64,
        AllowExponent = 128,
        AllowCurrencySymbol = 256,
        AllowHexSpecifier = 512,
        Integer = 7,
        HexNumber = 515,
        Number = 111,
        Float = 167,
        Currency = 383,
        Any = 511
      };
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Globalization::NumberStyles> : public TrueType {};

template<>
struct EnumRegister<System::Globalization::NumberStyles> {
  void operator()(System::Collections::Generic::IDictionary<System::Globalization::NumberStyles, string>& values, bool& flags) {
    values[System::Globalization::NumberStyles::None] = "None";
    values[System::Globalization::NumberStyles::AllowLeadingWhite] = "AllowLeadingWhite";
    values[System::Globalization::NumberStyles::AllowTrailingWhite] = "AllowTrailingWhite";
    values[System::Globalization::NumberStyles::AllowLeadingSign] = "AllowLeadingSign";
    values[System::Globalization::NumberStyles::AllowTrailingSign] = "AllowTrailingSign";
    values[System::Globalization::NumberStyles::AllowParentheses] = "AllowParentheses";
    values[System::Globalization::NumberStyles::AllowDecimalPoint] = "AllowDecimalPoint";
    values[System::Globalization::NumberStyles::AllowThousands] = "AllowThousands";
    values[System::Globalization::NumberStyles::AllowExponent] = "AllowExponent";
    values[System::Globalization::NumberStyles::AllowCurrencySymbol] = "AllowCurrencySymbol";
    values[System::Globalization::NumberStyles::AllowHexSpecifier] = "AllowHexSpecifier";
    values[System::Globalization::NumberStyles::Integer] = "Integer";
    values[System::Globalization::NumberStyles::HexNumber] = "HexNumber";
    values[System::Globalization::NumberStyles::Number] = "Number";
    values[System::Globalization::NumberStyles::Float] = "Float";
    values[System::Globalization::NumberStyles::Currency] = "Currency";
    values[System::Globalization::NumberStyles::Any] = "Any";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
