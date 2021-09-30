/// @file
/// @brief Contains Switch::System::Net::WebSockets::ClientWebSocket class.
#pragma once

#include <Switch/System/ArraySegment.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <Switch/System/Collections/Concurrent/ConcurrentQueue.hpp>
#include "../../../SystemExport.hpp"
#include "../../Threading/Semaphore.hpp"
#include "WebSocket.hpp"

/// @cond
namespace easywsclient {class WebSocket;}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::WebSockets namespace provides a managed implementation of the WebSocket interface for developers.
      namespace WebSockets {
        /// @brief Provides a client for connecting to WebSocket services.
        /// @par Library
        /// Switch.System
        /// @par Examples
        /// This example show how to receive and send with ClientWebSocket :
        /// @include ClientWebSocket.cpp
        class system_export_ ClientWebSocket : public WebSocket {
        public:
          /// @brief Creates an instance of the ClientWebSocket class.
          ClientWebSocket();

          /// @cond
          ~ClientWebSocket();
          /// @endcond

          /// @brief Aborts the WebSocket connection and cancels any pending IO operations.
          void Abort() override {throw NotSupportedException(caller_);}

          /// @brief Connect to a WebSocket server.
          /// @param uri The URI of the WebSocket server to connect to.
          void Connect(const string& uri);

          /// @brief Close the ClientWebSocket instance
          /// @param closeStatus The WebSocket close status.
          /// @param statusDescription A description of the close status.
          void Close(WebSocketCloseStatus closeStatus, const string& statusDescription);

          /// @brief Receive data on ClientWebSocket.
          /// @return The buffer to receive the response.
          ArraySegment<byte> Receive();

          /// @brief Send data on ClientWebSocket
          /// @param buffer The buffer containing the message to be sent.
          /// @param messageType Specifies whether the buffer is clear text or in a binary format.
          /// @param endOfMessage Specifies whether this is the final asynchronous send. Set to true if this is the final send; false otherwise.
          void Send(const ArraySegment<byte>& buffer, WebSocketMessageType messageType, bool endOfMessage);

        protected:
          /// @cond
          WebSocketCloseStatus GetCloseStatus() const override {return this->closeStatus;}

          string GetCloseStatusDescription() const override {
            switch (this->closeStatus) {
            case WebSocketCloseStatus::Empty: return "No error specified.";
            case WebSocketCloseStatus::InternalServerError: return "The connection will be closed by the server because of an error on the server.";
            case WebSocketCloseStatus::NormalClosure: return "(1000) The connection has closed after the request was fulfilled.";
            case WebSocketCloseStatus::EndpointUnavailable: return "(1001) Indicates an endpoint is being removed. Either the server or client will become unavailable.";
            case WebSocketCloseStatus::ProtocolError: return "(1002) The client or server is terminating the connection because of a protocol error.";
            case WebSocketCloseStatus::InvalidMessageType: return "(1003) The client or server is terminating the connection because it cannot accept the data type it received.";
            case WebSocketCloseStatus::MessageTooBig: return "(1004) Reserved for future use.";
            case WebSocketCloseStatus::InvalidPayloadData: return "(1007) The client or server is terminating the connection because it has received data inconsistent with the message type.";
            case WebSocketCloseStatus::PolicyViolation: return "(1008) The connection will be closed because an endpoint has received a message that violates its policy.";
            case WebSocketCloseStatus::MandatoryExtension: return "(1010) The client is terminating the connection because it expected the server to negotiate an extension.";
            default : throw InvalidOperationException(caller_);
            }
          }

          WebSocketState GetState() const override;

          string GetSubProtocol() const override {return this->subProtocol;}
          /// @endcond

        private:
          ClientWebSocket(const ClientWebSocket&) = delete;
          ClientWebSocket& operator =(const ClientWebSocket&) = delete;

          WebSocketCloseStatus closeStatus = WebSocketCloseStatus::Empty;
          string subProtocol;
          easywsclient::WebSocket* socket = null;
          System::Threading::Thread thread;
          System::Collections::Concurrent::ConcurrentQueue<string> items;
          System::Threading::Semaphore startReceive {1, Int32::MaxValue};
          System::Threading::Semaphore itemsReceive {0, Int32::MaxValue};
        };
      }
    }
  }
}

using namespace Switch;
