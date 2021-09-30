/// @file
/// @brief Contains Switch::System::IO::Ports::Parity enum.
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
        /// @brief Specifie the Parity values
        /// @par Library
        /// Switch.System
        enum class Parity {
          /// @brief No parity check occurs.
          None = 0,
          /// @brief Sets the parity bit so that the count of bits set is an odd number.
          Odd = 1,
          /// @brief Sets the parity bit so that the count of bits set is an even number.
          Even = 2,
          /// @brief Leaves the parity bit set to 1.
          Mark = 3,
          /// @brief Leaves the parity bit set to 0.
          Space = 4,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::IO::Ports::Parity> {
  void operator()(System::Collections::Generic::IDictionary<System::IO::Ports::Parity, string>& values, bool& flags) {
    values[System::IO::Ports::Parity::None] = "None";
    values[System::IO::Ports::Parity::Odd] = "Odd";
    values[System::IO::Ports::Parity::Even] = "Even";
    values[System::IO::Ports::Parity::Mark] = "Mark";
    values[System::IO::Ports::Parity::Space] = "Space";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
