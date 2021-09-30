/// @file
/// @brief Contains Switch::System::IO::Ports::SerialPinChangedEventArgs class.
#pragma once

#include <Switch/Property.hpp>
#include <Switch/System/EventArgs.hpp>
#include "SerialPinChange.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief The System::IO::Ports namespace contains classes for controlling serial ports. The most important class, SerialPort, provides a framework for synchronous and event-driven I/O, access to pin and break states, and access to serial driver properties. It can be used to wrap a Stream objects, allowing the serial port to be accessed by classes that use streams.
      /// The namespace includes enumerations that simplify the control of serial ports, such as Handshake, Parity, SerialPinChange, and StopBits.
      namespace Ports {
        /// @brief Provides data for the PinChanged event.
        /// @remarks This class is used with the PinChanged event.|
        /// @par Library
        /// Switch.System
        class system_export_ SerialPinChangedEventArgs : public System::EventArgs {
        public:
          SerialPinChangedEventArgs(SerialPinChange eventType) : eventType(eventType) {}
          SerialPinChangedEventArgs(const SerialPinChangedEventArgs& spcea) : eventType(spcea.eventType) {}

          /// @brief Gets the event type.
          /// @return One of the SerialPinChange values.
          /// @remarks This property provides information about the event type that caused the PinChanged event.
          property_<SerialPinChange, readonly_> EventType {
            get_ {return this->eventType;}
          };

        private:
          SerialPinChange eventType;
        };
      }
    }
  }
}

using namespace Switch;
