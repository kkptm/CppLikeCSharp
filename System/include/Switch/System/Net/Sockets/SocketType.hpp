/// @file
/// @brief Contains Switch::System::Net::Sockets::SocketType enum.
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
        /// @brief Specifies the type of socket that an instance of the Socket class represents.
        /// @remarks Before a Socket can send and receive data, it must first be created using an AddressFamily, a SocketType, and a ProtocolType. The SocketType enumeration provides several options for defining the type of Socket that you intend to open.
        /// @note SocketType will sometimes implicitly indicate which ProtocolType will be used within an AddressFamily. For example when the SocketType is Dgram, the ProtocolType is always Udp.When the SocketType is Stream, the ProtocolType is always Tcp. If you try to create a Socket with an incompatible combination, Socket will throw a SocketException.
        /// @par Library
        /// Switch.System
        enum class SocketType {
          /// @brief Specifies an unknown Socket type.
          Unknown = -1,
          /// @brief Supports reliable, two-way, connection-based byte streams without the duplication of data and without preservation of boundaries. A Socket of this type communicates with a single peer and requires a remote host connection before communication can begin. Stream uses the Transmission Control Protocol (Tcp) ProtocolType and the InterNetwork AddressFamily.
          Stream = 1,
          /// @brief Supports datagrams, which are connectionless, unreliable messages of a fixed (typically small) maximum length. Messages might be lost or duplicated and might arrive out of order. A Socket of type Dgram requires no connection prior to sending and receiving data, and can communicate with multiple peers. Dgram uses the Datagram Protocol (Udp) and the InterNetwork AddressFamily.
          Dgram = 2,
          /// @brief Supports access to the underlying transport protocol. Using the SocketType Raw, you can communicate using protocols like Internet Control Message Protocol (Icmp) and Internet Group Management Protocol (Igmp). Your application must provide a complete IP header when sending. Received datagrams return with the IP header and options intact.
          Raw = 3,
          /// @brief Supports connectionless, message-oriented, reliably delivered messages, and preserves message boundaries in data. Rdm (Reliably Delivered Messages) messages arrive unduplicated and in order. Furthermore, the sender is notified if messages are lost. If you initialize a Socket using Rdm, you do not require a remote host connection before sending and receiving data. With Rdm, you can communicate with multiple peers.
          Rdm = 4,
          /// @brief Provides connection-oriented and reliable two-way transfer of ordered byte streams across a network. Seqpacket does not duplicate data, and it preserves boundaries within the data stream. A Socket of type Seqpacket communicates with a single peer and requires a remote host connection before communication can begin.
          Seqpacket = 5,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Net::Sockets::SocketType> {
  void operator()(System::Collections::Generic::IDictionary<System::Net::Sockets::SocketType, string>& values, bool& flags) {
    values[System::Net::Sockets::SocketType::Unknown] = "Unknown";
    values[System::Net::Sockets::SocketType::Stream] = "Stream";
    values[System::Net::Sockets::SocketType::Dgram] = "Dgram";
    values[System::Net::Sockets::SocketType::Raw] = "Raw";
    values[System::Net::Sockets::SocketType::Rdm] = "Rdm";
    values[System::Net::Sockets::SocketType::Seqpacket] = "Seqpacket";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
