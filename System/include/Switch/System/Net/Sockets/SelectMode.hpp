/// @file
/// @brief Contains Switch::System::Net::Sockets::SelectMode enum.
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
        /// @brief Defines the polling modes for the Socket::Poll method.
        /// @remarks The SelectMode enumeration defines the polling modes that can be passed to the Socket::Poll method. Use the SelectModeSelectRead value to determine if a listening Socket has incoming connection requests. Use the SelectModeSelectWrite value to determine if a Socket is writeable. Use the SelectError value to determine if there is an error condition present on the Socket. For explanations of writeability, readability, and the presence of error conditions, see the Socket::Poll method.
        /// @par Library
        /// Switch.System
        enum class SelectMode {
          /// @brief Read status mode.
          SelectRead = 0,
          /// @brief Write status mode.
          SelectWrite = 1,
          /// @brief Error status mode.
          SelectError = 2
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Net::Sockets::SelectMode> {
  void operator()(System::Collections::Generic::IDictionary<System::Net::Sockets::SelectMode, string>& values, bool& flags) {
    values[System::Net::Sockets::SelectMode::SelectRead] = "SelectRead";
    values[System::Net::Sockets::SelectMode::SelectWrite] = "SelectWrite";
    values[System::Net::Sockets::SelectMode::SelectError] = "SelectError";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
