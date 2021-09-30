/// @file
/// @brief Contains Switch::System::IO::Ports::StopBits enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief The System::IO::Ports namespace contains classes for controlling serial ports. The most important class, SerialPort, provides a framework for synchronous and event-driven I/O, access to pin and break states, and access to serial driver properties. It can be used to wrap a Stream objects, allowing the serial port to be accessed by classes that use streams.
      /// The namespace includes enumerations that simplify the control of serial ports, such as Handshake, Parity, SerialPinChange, and StopBits.
      namespace Ports {
        /// @brief Specifie the StopBits values
        /// @par Library
        /// Switch.System
        enum class StopBits {
          /// @brief No stop bits are used. This value is not supported by the StopBits property.
          None = 0,
          /// @brief One stop bit is used.
          One = 1,
          /// @brief Two stop bits are used.
          Two = 2,
          /// @brief 1.5 stop bits are used.
          OnePointFive = 3,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::IO::Ports::StopBits> {
  void operator()(System::Collections::Generic::IDictionary<System::IO::Ports::StopBits, string>& values, bool& flags) {
    values[System::IO::Ports::StopBits::None] = "None";
    values[System::IO::Ports::StopBits::One] = "One";
    values[System::IO::Ports::StopBits::Two] = "Two";
    values[System::IO::Ports::StopBits::OnePointFive] = "OnePointFive";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
