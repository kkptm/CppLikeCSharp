/// @file
/// @brief Contains Switch::System::ConsoleModifiers enum.
#pragma once

#include "Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @enum ConsoleModifiers
    /// @brief Represents the SHIFT, ALT, and CTRL modifier keys on a keyboard.
    /// @see Console
    enum class ConsoleModifiers {
      /// @brief The left or right ALT modifier key.
      Alt = 0b1,
      /// @brief The left or right SHIFT modifier key.
      Shift = 0b10,
      /// @brief The left or right CTRL modifier key.
      Control = 0b100
    };
  }
}
/// @cond
template <>
class AddFlagOperators<System::ConsoleModifiers> : public TrueType {};

template<>
struct EnumRegister<System::ConsoleModifiers> {
  void operator()(System::Collections::Generic::IDictionary<System::ConsoleModifiers, string>& values, bool& flags) {
    values[System::ConsoleModifiers::Alt] = "Alt";
    values[System::ConsoleModifiers::Shift] = "Shift";
    values[System::ConsoleModifiers::Control] = "Control";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
