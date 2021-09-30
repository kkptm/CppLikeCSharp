/// @file
/// @brief Contains Switch::System::ConsoleColor enum.
#pragma once

#include "../Types.hpp"
#include "Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @enum ConsoleColor
    /// @brief Specifies constants that define foreground and background colors for the console.
    /// @see Console
    enum class ConsoleColor {
      /// @brief The color black.
      Black,
      /// @brief The color dark blue.
      DarkBlue,
      /// @brief The color dark green.
      DarkGreen,
      /// @brief The color dark cyan (dark blue-green).
      DarkCyan,
      /// @brief The color dark red.
      DarkRed,
      /// @brief The color dark magenta (dark purplish-red).
      DarkMagenta,
      /// @brief The color dark yellow (ochre).
      DarkYellow,
      /// @brief The color gray.
      Gray,
      /// @brief The color dark gray.
      DarkGray,
      /// @brief The color blue.
      Blue,
      /// @brief The color green.
      Green,
      /// @brief The color cyan (blue-green).
      Cyan,
      /// @brief The color red.
      Red,
      /// @brief The color magenta (purplish red).
      Magenta,
      /// @brief The color yellow.
      Yellow,
      /// @brief The color white.
      White
    };
  }
}

/// @cond
template<>
struct EnumRegister<System::ConsoleColor> {
  void operator()(System::Collections::Generic::IDictionary<System::ConsoleColor, string>& values, bool& flags) {
    values[System::ConsoleColor::Black] = "Black";
    values[System::ConsoleColor::DarkBlue] = "DarkBlue";
    values[System::ConsoleColor::DarkGreen] = "DarkGreen";
    values[System::ConsoleColor::DarkCyan] = "DarkCyan";
    values[System::ConsoleColor::DarkRed] = "DarkRed";
    values[System::ConsoleColor::DarkMagenta] = "DarkMagenta";
    values[System::ConsoleColor::DarkYellow] = "DarkYellow";
    values[System::ConsoleColor::Gray] = "Gray";
    values[System::ConsoleColor::DarkGray] = "DarkGray";
    values[System::ConsoleColor::Blue] = "Blue";
    values[System::ConsoleColor::Green] = "Green";
    values[System::ConsoleColor::Cyan] = "Cyan";
    values[System::ConsoleColor::Red] = "Red";
    values[System::ConsoleColor::Magenta] = "Magenta";
    values[System::ConsoleColor::Yellow] = "Yellow";
    values[System::ConsoleColor::White] = "White";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
