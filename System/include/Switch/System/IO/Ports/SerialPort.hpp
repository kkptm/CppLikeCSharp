/// @file
/// @brief Contains Switch::System::IO::Ports::SerialPort class.
#pragma once

#include <Switch/Property.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../../../SystemExport.hpp"
#include "Parity.hpp"
#include "StopBits.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief The System::IO::Ports namespace contains classes for controlling serial ports. The most important class, SerialPort, provides a framework for synchronous and event-driven I/O, access to pin and break states, and access to serial driver properties. It can be used to wrap a Stream objects, allowing the serial port to be accessed by classes that use streams.
      /// The namespace includes enumerations that simplify the control of serial ports, such as Handshake, Parity, SerialPinChange, and StopBits.
      namespace Ports {
        /// @brief Represents a serial port resource.
        /// @par Library
        /// Switch.System
        class system_export_ SerialPort : public Object {
        public:
          SerialPort() {}
          /// @cond
          SerialPort(const SerialPort& serialPort) = delete;
          SerialPort& operator=(const SerialPort& serialPort) = delete;
          /// @endcond

          SerialPort(const String& port) : port(port) {}

          SerialPort(const String& port, int32 baudRate) : port(port), baudRate(baudRate) {}

          SerialPort(const String& port, int32 baudRate, Parity parity) : port(port), baudRate(baudRate), parity(parity) {}

          SerialPort(const String& port, int32 baudRate, Parity parity, int32 dataBits) : port(port), baudRate(baudRate), parity(parity), dataBits(dataBits) {}

          SerialPort(const String& port, int32 baudRate, Parity parity, int32 dataBits, StopBits stopBits) : port(port), baudRate(baudRate), parity(parity), dataBits(dataBits), stopBits(stopBits) {}

          static Array<String> GetPortNames();

          property_<int32, readonly_> BaudRate {
            get_ {return this->baudRate;}
          };

          property_<int32, readonly_> DataBits {
            get_ {return this->dataBits;}
          };

          property_<System::IO::Ports::Parity, readonly_> Parity {
            get_ {return this->parity;}
          };

          property_<const string&, readonly_> Port {
            get_->const string& {return this->port;}
          };

          property_<System::IO::Ports::StopBits, readonly_> StopBits {
            get_ {return this->stopBits;}
          };

        private:
          String port;
          int32 baudRate = 9600;
          System::IO::Ports::Parity parity = System::IO::Ports::Parity::None;
          int32 dataBits = 8;
          System::IO::Ports::StopBits stopBits = System::IO::Ports::StopBits::One;
        };
      }
    }
  }
}

using namespace Switch;
