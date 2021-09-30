/// @file
/// @brief Contains Switch::System::IO::Ports::SerialPinChange enum.
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
        /// @brief Specifie the SerialPinChange values
        /// @par Library
        /// Switch.System
        enum class SerialPinChange {
          /// @brief The Clear to Send (CTS) signal changed state. This signal is used to indicate whether data can be sent over the serial port.
          CtsChanged = 8,
          /// @brief The Data Set Ready (DSR) signal changed state. This signal is used to indicate whether the device on the serial port is ready to operate.
          DsrChanged = 16,
          /// @brief The Carrier Detect (CD) signal changed state. This signal is used to indicate whether a modem is connected to a working phone line and a data carrier signal is detected.
          CDChanged = 32,
          /// @brief A break was detected on input.
          Break = 64,
          /// @brief A ring indicator was detected.
          Ring = 256
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::IO::Ports::SerialPinChange> {
  void operator()(System::Collections::Generic::IDictionary<System::IO::Ports::SerialPinChange, string>& values, bool& flags) {
    values[System::IO::Ports::SerialPinChange::CtsChanged] = "CtsChanged";
    values[System::IO::Ports::SerialPinChange::DsrChanged] = "DsrChanged";
    values[System::IO::Ports::SerialPinChange::CDChanged] = "CDChanged";
    values[System::IO::Ports::SerialPinChange::Break] = "Break";
    values[System::IO::Ports::SerialPinChange::Ring] = "Ring";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
