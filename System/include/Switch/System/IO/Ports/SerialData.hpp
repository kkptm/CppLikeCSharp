/// @file
/// @brief Contains Switch::System::IO::Ports::SerialData enum.
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
        /// @brief Specifie the SerialData values
        /// @par Library
        /// Switch.System
        enum class SerialData {
          /// @brief A character was received and placed in the input buffer.
          Chars = 1,
          /// @brief The end of file character was received and placed in the input buffer.
          Eof = 2,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::IO::Ports::SerialData> {
  void operator()(System::Collections::Generic::IDictionary<System::IO::Ports::SerialData, string>& values, bool& flags) {
    values[System::IO::Ports::SerialData::Chars] = "Chars";
    values[System::IO::Ports::SerialData::Eof] = "Eof";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
