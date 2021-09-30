/// @file
/// @brief Contains Switch::System::ConsoleSpecialKey enum.
#pragma once

#include "Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Specifies combinations of modifier and console keys that can interrupt the current process.
    /// @remarks The ConsoleCancelEventArgs.SpecialKey property returns the ConsoleSpecialKey enumeration type.
    /// @remarks Simultaneously pressing certain key combinations signals the operating system to interrupt the currently running process. The two valid key combinations are ConsoleModifiers.Control plus BREAK (CTRL+BREAK) and ConsoleModifiers.Control plus ConsoleKey.C (CTRL+C).
    enum class ConsoleSpecialKey {
      /// @brief The ConsoleModifiers.Control modifier key plus the BREAK console key.
      ControlBreak,
      /// @brief The ConsoleModifiers.Control modifier key plus the ConsoleKey C console key.
      ControlC,
      /// @brief The ConsoleModifiers.Control modifier key plus the ConsoleKey \\ console key.
      ControlBackslash,
      /// @brief The ConsoleModifiers.Control modifier key plus the ConsoleKey Z console key.
      ControlZ,
    };
  }
}

/// @cond
template<>
struct EnumRegister<System::ConsoleSpecialKey> {
  void operator()(System::Collections::Generic::IDictionary<System::ConsoleSpecialKey, string>& values, bool& flags) {
    values[System::ConsoleSpecialKey::ControlBreak] = "ControlBreak";
    values[System::ConsoleSpecialKey::ControlC] = "ControlC";
    values[System::ConsoleSpecialKey::ControlBackslash] = "ControlBackslash";
    values[System::ConsoleSpecialKey::ControlZ] = "ControlZ";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
