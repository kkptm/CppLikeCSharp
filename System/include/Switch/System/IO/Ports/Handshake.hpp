/// @file
/// @brief Contains Switch::System::IO::Ports::Handshake enum.
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
        /// @brief Specifies the control protocol used in establishing a serial port communication for a SerialPort object.
        /// @par Library
        /// Switch.System
        enum class Handshake {
          /// @brief No control is used for the handshake.
          None = 0,
          /// @brief he XON/XOFF software control protocol is used. The XOFF control is sent to stop the transmission of data. The XON control is sent to resume the transmission. These software controls are used instead of Request to Send (RTS) and Clear to Send (CTS) hardware controls.
          XOnXOff = 1,
          /// @brief Request-to-Send (RTS) hardware flow control is used. RTS signals that data is available for transmission. If the input buffer becomes full, the RTS line will be set to false. The RTS line will be set to true when more room becomes available in the input buffer.
          RequestToSend = 2,
          /// @brief
          RequestToSendXOnXOff = 3,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::IO::Ports::Handshake> {
  void operator()(System::Collections::Generic::IDictionary<System::IO::Ports::Handshake, string>& values, bool& flags) {
    values[System::IO::Ports::Handshake::None] = "None";
    values[System::IO::Ports::Handshake::XOnXOff] = "XOnXOff";
    values[System::IO::Ports::Handshake::RequestToSend] = "RequestToSend";
    values[System::IO::Ports::Handshake::RequestToSendXOnXOff] = "RequestToSendXOnXOff";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
