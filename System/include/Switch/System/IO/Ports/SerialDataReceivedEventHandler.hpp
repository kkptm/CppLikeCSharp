/// @file
/// @brief Contains Switch::System::IO::Ports::SerialDataReceivedEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>
#include "SerialData.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief The System::IO::Ports namespace contains classes for controlling serial ports. The most important class, SerialPort, provides a framework for synchronous and event-driven I/O, access to pin and break states, and access to serial driver properties. It can be used to wrap a Stream objects, allowing the serial port to be accessed by classes that use streams.
      /// The namespace includes enumerations that simplify the control of serial ports, such as Handshake, Parity, SerialPinChange, and StopBits.
      namespace Ports {
        /// @brief Represents the method that will handle the DataReceived event of a SerialPort object.
        /// @remarks When you create a SerialDataReceivedEventHandler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate. For more information about event-handler delegates, see Handling and Raising Events.
        /// @par Library
        /// Switch.System
        using SerialDataReceivedEventHandler = System::GenericEventHandler<SerialDataReceivedEventArgs>;
      }
    }
  }
}

using namespace Switch;
