/// @file
/// @brief Contains Switch::System::Net::Sockets::SocketOptionName enum.
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
        /// @brief Defines configuration option names.
        /// @remarks The SocketOptionName enumeration defines the name of each Socket configuration option. Sockets can be configured with the Socket::SetSocketOption method.
        /// @par Library
        /// Switch.System
        enum class SocketOptionName {
          /// @brief Record debugging information.
          Debug = 1,
          /// @brief The socket is listening.
          AcceptConnection = 2,
          /// @brief Allows the socket to be bound to an address that is already in use.
          ReuseAddress = 4,
          /// @brief Use keep-alives.
          KeepAlive = 8,
          /// @brief Do not route; send the packet directly to the interface addresses.
          DontRoute = 16,
          /// @brief Permit sending broadcast messages on the socket.
          Broadcast = 32,
          /// @brief Bypass hardware when possible.
          UseLoopback = 64,
          /// @brief Linger on close if unsent data is present.
          Linger = 128,
          /// @brief Receives out-of-band data in the normal data stream.
          OutOfBandInline = 256,
          /// @brief Close the socket gracefully without lingering.
          DontLinger = -129,
          /// @brief Enables a socket to be bound for exclusive access.
          ExclusiveAddressUse = -5,
          /// @brief Specifies the total per-socket buffer space reserved for sends. This is unrelated to the maximum message size or the size of a TCP window.
          SendBuffer = 4097,
          /// @brief Specifies the total per-socket buffer space reserved for receives. This is unrelated to the maximum message size or the size of a TCP window.
          ReceiveBuffer = 4098,
          /// @brief Specifies the low water mark for Send operations.
          SendLowWater = 4099,
          /// @brief Specifies the low water mark for Receive operations.
          ReceiveLowWater = 4100,
          /// @brief Send a time-out. This option applies only to synchronous methods; it has no effect on asynchronous methods such as the BeginSend method.
          SendTimeout = 4101,
          /// @brief Receive a time-out. This option applies only to synchronous methods; it has no effect on asynchronous methods such as the BeginSend method.
          ReceiveTimeout = 4102,
          /// @brief Get the error status and clear.
          Error = 4103,
          /// @brief Get the socket type.
          Type = 4104,
          /// @brief Not supported; will throw a SocketException Exception if used.
          MaxConnections = 2147483647,
          /// @brief Specifies the IP options to be inserted into outgoing datagrams.
          IPOptions = 1,
          /// @brief Indicates that the application provides the IP header for outgoing datagrams.
          HeaderIncluded = 2,
          /// @brief Change the IP header type of the service field.
          _typeofService = 3,
          /// @brief Set the IP header Time-to-Live field.
          IpTimeToLive = 4,
          /// @brief Set the interface for outgoing multicast packets.
          MulticastInterface = 9,
          /// @brief An IP multicast Time to Live.
          MulticastTimeToLive = 10,
          /// @brief An IP multicast loopback.
          MulticastLoopback = 11,
          /// @brief Add an IP group membership.
          AddMembership = 12,
          /// @brief Drop an IP group membership.
          DropMembership = 13,
          /// @brief Do not fragment IP datagrams.
          DontFragment = 14,
          /// @brief Join a source group.
          AddSourceMembership = 15,
          /// @brief Drop a source group.
          DropSourceMembership = 16,
          /// @brief Block data from a source.
          BlockSource = 17,
          /// @brief Unblock a previously blocked source.
          UnblockSource = 18,
          /// @brief Return information about received packets.
          PacketInformation = 19,
          /// @brief Specifies the maximum number of router hops for an Internet Protocol version 6 (IPv6) packet. This is similar to Time to Live (TTL) for Internet Protocol version 4.
          HopLimit = 21,
          /// @brief Enables restriction of a IPv6 socket to a specified scope, such as addresses with the same link local or site local prefix.This socket option enables applications to place access restrictions on IPv6 sockets. Such restrictions enable an application running on a private LAN to simply and robustly harden itself against external attacks. This socket option widens or narrows the scope of a listening socket, enabling unrestricted access from public and private users when appropriate, or restricting access only to the same site, as required. This socket option has defined protection levels specified in the IPProtectionLevel enumeration.
          IPProtectionLevel = 22,
          /// @brief Indicates if a socket created for the AF_INET6 address family is restricted to IPv6 communications only. Sockets created for the AF_INET6 address family may be used for both IPv6 and IPv4 communications. Some applications may want to restrict their use of a socket created for the AF_INET6 address family to IPv6 communications only. When this value is non-zero (the default on Windows), a socket created for the AF_INET6 address family can be used to send and receive IPv6 packets only. When this value is zero, a socket created for the AF_INET6 address family can be used to send and receive packets to and from an IPv6 address or an IPv4 address. Note that the ability to interact with an IPv4 address requires the use of IPv4 mapped addresses. This socket option is supported on Windows Vista or later.
          IPv6Only = 23,
          /// @brief Disables the Nagle algorithm for send coalescing.
          NoDelay = 1,
          /// @brief Use urgent data as defined in RFC-1222. This option can be set only once; after it is set, it cannot be turned off.
          BsdUrgent = 2,
          /// @brief Use expedited data as defined in RFC-1222. This option can be set only once; after it is set, it cannot be turned off.
          Expedited = 2,
          /// @brief Send UDP datagrams with checksum set to zero.
          NoChecksum = 1,
          /// @brief Set or get the UDP checksum coverage.
          ChecksumCoverage = 20,
          /// @brief Updates an accepted socket's properties by using those of an existing socket. This is equivalent to using the Winsock2 SO_UPDATE_ACCEPT_CONTEXT socket option and is supported only on connection-oriented sockets.
          UpdateAcceptContext = 28683,
          /// @brief Updates a connected socket's properties by using those of an existing socket. This is equivalent to using the Winsock2 SO_UPDATE_CONNECT_CONTEXT socket option and is supported only on connection-oriented sockets.
          UpdateConnectContext = 28688
        };
      }
    }
  }
}

/// @cond
template<>
class AddFlagOperators<System::Net::Sockets::SocketOptionName> : public TrueType {};

template<>
struct EnumRegister<System::Net::Sockets::SocketOptionName> {
  void operator()(System::Collections::Generic::IDictionary<System::Net::Sockets::SocketOptionName, string>& values, bool& flags) {
    values[System::Net::Sockets::SocketOptionName::Debug] = "Debug";
    values[System::Net::Sockets::SocketOptionName::AcceptConnection] = "AcceptConnection";
    values[System::Net::Sockets::SocketOptionName::ReuseAddress] = "ReuseAddress";
    values[System::Net::Sockets::SocketOptionName::KeepAlive] = "KeepAlive";
    values[System::Net::Sockets::SocketOptionName::DontRoute] = "DontRoute";
    values[System::Net::Sockets::SocketOptionName::Broadcast] = "Broadcast";
    values[System::Net::Sockets::SocketOptionName::UseLoopback] = "UseLoopback";
    values[System::Net::Sockets::SocketOptionName::Linger] = "Linger";
    values[System::Net::Sockets::SocketOptionName::OutOfBandInline] = "OutOfBandInline";
    values[System::Net::Sockets::SocketOptionName::DontLinger] = "DontLinger";
    values[System::Net::Sockets::SocketOptionName::ExclusiveAddressUse] = "ExclusiveAddressUse";
    values[System::Net::Sockets::SocketOptionName::SendBuffer] = "SendBuffer";
    values[System::Net::Sockets::SocketOptionName::ReceiveBuffer] = "ReceiveBuffer";
    values[System::Net::Sockets::SocketOptionName::SendLowWater] = "SendLowWater";
    values[System::Net::Sockets::SocketOptionName::ReceiveLowWater] = "ReceiveLowWater";
    values[System::Net::Sockets::SocketOptionName::SendTimeout] = "SendTimeout";
    values[System::Net::Sockets::SocketOptionName::ReceiveTimeout] = "ReceiveTimeout";
    values[System::Net::Sockets::SocketOptionName::Error] = "Error";
    values[System::Net::Sockets::SocketOptionName::Type] = "Type";
    values[System::Net::Sockets::SocketOptionName::MaxConnections] = "MaxConnections";
    values[System::Net::Sockets::SocketOptionName::IPOptions] = "IPOptions";
    values[System::Net::Sockets::SocketOptionName::HeaderIncluded] = "HeaderIncluded";
    values[System::Net::Sockets::SocketOptionName::_typeofService] = "_typeofService";
    values[System::Net::Sockets::SocketOptionName::IpTimeToLive] = "IpTimeToLive";
    values[System::Net::Sockets::SocketOptionName::MulticastInterface] = "MulticastInterface";
    values[System::Net::Sockets::SocketOptionName::MulticastTimeToLive] = "MulticastTimeToLive";
    values[System::Net::Sockets::SocketOptionName::MulticastLoopback] = "MulticastLoopback";
    values[System::Net::Sockets::SocketOptionName::AddMembership] = "AddMembership";
    values[System::Net::Sockets::SocketOptionName::DropMembership] = "DropMembership";
    values[System::Net::Sockets::SocketOptionName::DontFragment] = "DontFragment";
    values[System::Net::Sockets::SocketOptionName::AddSourceMembership] = "AddSourceMembership";
    values[System::Net::Sockets::SocketOptionName::DropSourceMembership] = "DropSourceMembership";
    values[System::Net::Sockets::SocketOptionName::BlockSource] = "BlockSource";
    values[System::Net::Sockets::SocketOptionName::UnblockSource] = "UnblockSource";
    values[System::Net::Sockets::SocketOptionName::PacketInformation] = "PacketInformation";
    values[System::Net::Sockets::SocketOptionName::HopLimit] = "HopLimit";
    values[System::Net::Sockets::SocketOptionName::IPProtectionLevel] = "IPProtectionLevel";
    values[System::Net::Sockets::SocketOptionName::IPv6Only] = "IPv6Only";
    values[System::Net::Sockets::SocketOptionName::NoDelay] = "NoDelay";
    values[System::Net::Sockets::SocketOptionName::BsdUrgent] = "BsdUrgent";
    values[System::Net::Sockets::SocketOptionName::Expedited] = "Expedited";
    values[System::Net::Sockets::SocketOptionName::NoChecksum] = "NoChecksum";
    values[System::Net::Sockets::SocketOptionName::ChecksumCoverage] = "ChecksumCoverage";
    values[System::Net::Sockets::SocketOptionName::UpdateAcceptContext] = "UpdateAcceptContext";
    values[System::Net::Sockets::SocketOptionName::UpdateConnectContext] = "UpdateConnectContext";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
