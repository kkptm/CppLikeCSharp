/// @file
/// @brief Contains Switch::System::Net::WebSockets::WebSocketState enum.
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
        /// @brief Defines the different states a WebSockets instance can be in.
        /// @par Library
        /// Switch.System
        enum class WebSocketState {
          /// @brief Reserved for future use.
          None,
          /// @brief The connection is negotiating the handshake with the remote endpoint.
          Connecting,
          /// @brief The initial state after the HTTP handshake has been completed.
          Open,
          /// @brief A close message was sent to the remote endpoint.
          CloseSent,
          /// @brief A close message was received from the remote endpoint.
          CloseReceive,
          /// @brief Indicates the WebSocket close handshake completed gracefully.
          Closed,
          /// @brief Reserved for future use.
          Aborted
        };
      }
    }
  }
}

using namespace Switch;
