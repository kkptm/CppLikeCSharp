/// @file
/// @brief Contains Switch::System::Net::WebSockets::WebSocketMessageType enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::WebSockets namespace provides a managed implementation of the WebSocket interface for developers.
      namespace WebSockets {
        /// @brief ndicates the message type.
        /// @par Library
        /// Switch.System
        enum class WebSocketMessageType {
          /// @brief The message is clear text.
          Text,
          /// @brief The message is in binary format.
          Binary,
          /// @brief A receive has completed because a close message was received.
          Closed
        };
      }
    }
  }
}

using namespace Switch;
