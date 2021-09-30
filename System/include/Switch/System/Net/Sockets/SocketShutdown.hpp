/// @file
/// @brief Contains Switch::System::Net::Sockets::SocketShutdown enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief Defines constants that are used by the Socket::Shutdown method.
        /// @remarks The SocketShutdown enumeration defines the values that can be passed to the Socket::Shutdown method.
        /// @par Library
        /// Switch.System
        enum class SocketShutdown {
          /// @brief Disables a Socket for receiving. This field is constant.
          Receive = 0,
          /// @brief Disables a Socket for sending. This field is constant.
          Send = 1,
          /// @brief Disables a Socket for both sending and receiving. This field is constant.
          Both = 2
        };
      }
    }
  }
}

/// @cond
template<>
class AddFlagOperators<System::Net::Sockets::SocketShutdown> : public TrueType {};

template<>
struct EnumRegister<System::Net::Sockets::SocketShutdown> {
  void operator()(System::Collections::Generic::IDictionary<System::Net::Sockets::SocketShutdown, string>& values, bool& flags) {
    values[System::Net::Sockets::SocketShutdown::Receive] = "Receive";
    values[System::Net::Sockets::SocketShutdown::Send] = "Send";
    values[System::Net::Sockets::SocketShutdown::Both] = "Both";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
