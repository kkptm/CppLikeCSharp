/// @file
/// @brief Contains Switch::System::Net::WebSockets::WebSocketCloseStatus enum.
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
        /// @brief Represents well known WebSocket close codes as defined in section 11.7 of the WebSocket protocol spec.
        /// @par Library
        /// Switch.System
        enum class WebSocketCloseStatus {
          /// @brief No error specified.
          Empty = 0,
          /// @brief The connection will be closed by the server because of an error on the server.
          InternalServerError,
          /// @brief (1000) The connection has closed after the request was fulfilled.
          NormalClosure = 1000,
          /// @brief (1001) Indicates an endpoint is being removed. Either the server or client will become unavailable.
          EndpointUnavailable = 1001,
          /// @brief (1002) The client or server is terminating the connection because of a protocol error.
          ProtocolError = 1002,
          /// @brief (1003) The client or server is terminating the connection because it cannot accept the data type it received.
          InvalidMessageType = 1003,
          /// @brief (1004) Reserved for future use.
          MessageTooBig = 1004,
          /// @brief (1007) The client or server is terminating the connection because it has received data inconsistent with the message type.
          InvalidPayloadData = 1007,
          /// @brief (1008) The connection will be closed because an endpoint has received a message that violates its policy.
          PolicyViolation = 1008,
          /// @brief (1010) The client is terminating the connection because it expected the server to negotiate an extension.
          MandatoryExtension = 1010
        };
      }
    }
  }
}

using namespace Switch;
