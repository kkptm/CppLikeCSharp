/// @file
/// @brief Contains Switch::System::Net::Sockets::SocketFlags enum.
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
        /// @brief Specifies socket send and receive behaviors. This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
        /// @par Library
        /// Switch.System
        enum class SocketFlags {
          /// @brief Use no flags for this call.
          None = 0x0000,
          /// @brief Process out-of-band data.
          OutOfBand = 0x0001,
          /// @brief Peek at the incoming message.
          Peek = 0x0002,
          /// @brief Send without using routing tables.
          DontRoute = 0x0004,
          /// @brief Provides a standard value for the number of WSABUF structures that are used to send and receive data.
          MaxIOVectorLength = 0x0010,
          /// @brief The message was too large to fit into the specified buffer and was truncated.
          Truncated = 0x0100,
          /// @brief Indicates that the control data did not fit into an internal 64-KB buffer and was truncated.
          ControlDataTruncated = 0x0200,
          /// @brief Indicates a broadcast packet.
          Broadcast = 0x0400,
          /// @brief Indicates a multicast packet.
          Multicast = 0x0800,
          /// @brief Partial send or receive for message.
          Partial = 0x8000,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Net::Sockets::SocketFlags> : public TrueType {};

template<>
struct EnumRegister<System::Net::Sockets::SocketFlags> {
  void operator()(System::Collections::Generic::IDictionary<System::Net::Sockets::SocketFlags, string>& values, bool& flags) {
    values[System::Net::Sockets::SocketFlags::None] = "None";
    values[System::Net::Sockets::SocketFlags::OutOfBand] = "OutOfBand";
    values[System::Net::Sockets::SocketFlags::Peek] = "Peek";
    values[System::Net::Sockets::SocketFlags::DontRoute] = "DontRoute";
    values[System::Net::Sockets::SocketFlags::MaxIOVectorLength] = "MaxIOVectorLength";
    values[System::Net::Sockets::SocketFlags::Truncated] = "Truncated";
    values[System::Net::Sockets::SocketFlags::ControlDataTruncated] = "ControlDataTruncated";
    values[System::Net::Sockets::SocketFlags::Broadcast] = "Broadcast";
    values[System::Net::Sockets::SocketFlags::Multicast] = "Multicast";
    values[System::Net::Sockets::SocketFlags::Partial] = "Partial";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
