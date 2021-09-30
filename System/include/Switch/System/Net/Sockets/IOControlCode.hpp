/// @file
/// @brief Contains Switch::System::Net::Sockets::IOControlCode enum.
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
        /// @brief  Specifies the IO control codes supported by the IOControl method.
        /// @remarks The IOControlCode enumeration defines the socket option levels that can be passed to the Socket.SetSocketOption and Socket.GetSocketOption methods. SocketOptionName enumerated values are grouped by IOControlCode.
        /// @par Library
        /// Switch.System
        enum class IOControlCode : int64 {
          /// @brief Replace the oldest queued datagram with an incoming datagram when the incoming message queues are full. This value is equal to the Winsock†2 SIO_ENABLE_CIRCULAR_QUEUEING constant.
          EnableCircularQueuing = 671088642,
          /// @brief Discard the contents of the sending queue. This value is equal to the Winsock†2 SIO_FLUSH constant.
          Flush = 671088644,
          /// @brief Enable receiving notification when the list of local interfaces for the socket's protocol family changes. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_ADDRESS_LIST_CHANGE constant.
          AddressListChange = 671088663,
          /// @brief Return the number of bytes available for reading. This value is equal to the Winsock†2 FIONREAD constant.
          DataToRead = 1074030207,
          /// @brief Return information about out-of-band data waiting to be received. When using this control code on stream sockets, the return value indicates the number of bytes available.
          OobDataRead = 1074033415,
          /// @brief Return a SOCKADDR structure that contains the broadcast address for the address family of the current socket. The returned address can be used with the Overload:System::Net::Sockets::Socket.SendTo method. This value is equal to the Winsock†2 SIO_GET_BROADCAST_ADDRESS constant. This value can be used on User Datagram Protocol (UDP) sockets only.
          GetBroadcastAddress = 1207959557,
          /// @brief Return the list of local interfaces that the socket can bind to. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_ADDRESS_LIST_QUERY constant.
          AddressListQuery = 1207959574,
          /// @brief Retrieve the underlying provider's SOCKET handle. This handle can be used to receive plug-and-play event notification. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_QUERY_TARGET_PNP_HANDLE constant.
          QueryTargetPnpHandle = 1207959576,
          /// @brief Enable notification for when data is waiting to be received. This value is equal to the Winsock†2 FIOASYNC constant.
          AsyncIO = 2147772029UL,
          /// @brief Control the blocking behavior of the socket. If the argument specified with this control code is zero, the socket is placed in blocking mode. If the argument is nonzero, the socket is placed in nonblocking mode. This value is equal to the Winsock†2 FIONBIO constant.
          NonBlockingIO = 2147772030UL,
          /// @brief Associate this socket with the specified handle of a companion interface. Refer to the appropriate protocol-specific annex in the Winsock†2 reference or documentation for the particular companion interface for additional details. It is recommended that the Component object Model (COM) be used instead of this IOCTL to discover and track other interfaces that might be supported by a socket. This control code is present for backward compatibility with systems where COM is not available or cannot be used for some other reason. This value is equal to the Winsock†2 SIO_ASSOCIATE_HANDLE constant.
          AssociateHandle = 2281701377UL,
          /// @brief Control whether multicast data sent by the socket appears as incoming data in the sockets receive queue. This value is equal to the Winsock†2 SIO_MULTIPOINT_LOOPBACK constant.
          MultipointLoopback = 2281701385UL,
          /// @brief Control the number of times a multicast packet can be forwarded by a router, also known as the Time to Live (TTL), or hop count. This value is equal to the Winsock†2 SIO_MULTICAST_SCOPE constant.
          MulticastScope = 2281701386UL,
          /// @brief Set the Quality of Service (QOS) attributes for the socket. QOS defines the bandwidth requirements for the socket. This control code is supported on Windows Me, Windows 2000, and later operating systems. This value is equal to the Winsock†2 SIO_SET_QOS constant.
          SetQos = 2281701387UL,
          /// @brief Set the Quality of Service (QOS) attributes for the socket group. This value is reserved for future use and is equal to the Winsock†2 SIO_SET_GROUP_QOS constant.
          SetGroupQos = 2281701388UL,
          /// @brief Enable receiving notification when the local interface used to access a remote endpoint changes. This value is equal to the Winsock†2 SIO_ROUTING_INTERFACE_CHANGE constant.
          RoutingInterfaceChange = 2281701397UL,
          /// @brief Control whether the socket receives notification when a namespace query becomes invalid. This control code is supported on Windows XP and later operating systems. This value is equal to the Winsock†2 SIO_NSP_NOTIFY_CHANGE constant.
          NamespaceChange = 2281701401UL,
          /// @brief Enable receiving all IPv4 packets on the network. The socket must have address family System::Net::Sockets::AddressFamily.InterNetwork, the socket type must be System::Net::Sockets::SocketType.Raw, and the protocol type must be System::Net::Sockets::ProtocolType.IP. The current user must belong to the Administrators group on the local computer, and the socket must be bound to a specific port. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_RCVALL constant.
          ReceiveAll = 2550136833UL,
          /// @brief Enable receiving all multicast IPv4 packets on the network. These are packets with destination addresses in the range 224.0.0.0 through 239.255.255.255. The socket must have address family System::Net::Sockets::AddressFamily.InterNetwork, the socket type must be System::Net::Sockets::SocketType.Raw, and the protocol type must be System::Net::Sockets::ProtocolType.Udp. The current user must belong to the Administrators group on the local computer, and the socket must be bound to a specific port. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_RCVALL_MCAST constant.
          ReceiveAllMulticast = 2550136834UL,
          /// @brief Enable receiving all Internet Group Management Protocol (IGMP) packets on the network. The socket must have address family System::Net::Sockets::AddressFamily.InterNetwork, the socket type must be System::Net::Sockets::SocketType.Raw, and the protocol type must be System::Net::Sockets::ProtocolType.Igmp. The current user must belong to the Administrators group on the local computer, and the socket must be bound to a specific port. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_RCVALL_IGMPMCAST constant.
          ReceiveAllIgmpMulticast = 2550136835UL,
          /// @brief Control sending TCP keep-alive packets and the interval at which they are sent. This control code is supported on Windows 2000 and later operating systems. For additional information, see RFC 1122 section 4.2.3.6. This value is equal to the Winsock†2 SIO_KEEPALIVE_VALS constant.
          KeepAliveValues = 2550136836UL,
          /// @brief This value is equal to the Winsock†2 SIO_ABSORB_RTRALERT constant.
          AbsorbRouterAlert = 2550136837UL,
          /// @brief Set the interface used for outgoing unicast packets. This value is equal to the Winsock†2 SIO_UCAST_IF constant.
          UnicastInterface = 2550136838UL,
          /// @brief This value is equal to the Winsock†2 SIO_LIMIT_BROADCASTS constant.
          LimitBroadcasts = 2550136839UL,
          /// @brief Bind the socket to a specified interface index. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_INDEX_BIND constant.
          BindToInterface = 2550136840UL,
          /// @brief Set the interface used for outgoing multicast packets. The interface is identified by its index. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_INDEX_MCASTIF constant.
          MulticastInterface = 2550136841UL,
          /// @brief Join a multicast group using an interface identified by its index. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_INDEX_ADD_MCAST constant.
          AddMulticastGroupOnInterface = 2550136842UL,
          /// @brief Remove the socket from a multicast group. This control code is supported on Windows 2000 and later operating systems. This value is equal to the Winsock†2 SIO_INDEX_ADD_MCAST constant.
          DeleteMulticastGroupFromInterface = 2550136843UL,
          /// @brief Obtain provider-specific functions that are not part of the Winsock specification. Functions are specified using their provider-assigned GUID. This value is equal to the Winsock†2 SIO_GET_EXTENSION_FUNCTION_POINTER constant.
          GetExtensionFunctionPointer = 3355443206UL,
          /// @brief Retrieve the QOS structure associated with the socket. This control is only supported on platforms that provide a QOS capable transport (Windows Me, Windows 2000, and later.) This value is equal to the Winsock†2 SIO_GET_QOS constant.
          GetQos = 3355443207UL,
          /// @brief Return the Quality of Service (QOS) attributes for the socket group. This value is reserved for future use, and is equal to the Winsock†2 SIO_GET_GROUP_QOS constant.
          GetGroupQos = 3355443208UL,
          /// @brief Return a handle for the socket that is valid in the context of a companion interface. This value is equal to the Winsock†2 SIO_TRANSLATE_HANDLE constant.
          TranslateHandle = 3355443213UL,
          /// @brief Return the interface addresses that can be used to connect to the specified remote address. This value is equal to the Winsock†2 SIO_ROUTING_INTERFACE_QUERY constant.
          RoutingInterfaceQuery = 3355443220UL,
          /// @brief Sort the structure returned by the System::Net::Sockets::IOControlCode.AddressListQuery field and add scope ID information for IPv6 addresses. This control code is supported on Windows XP and later operating systems. This value is equal to the Winsock†2 SIO_ADDRESS_LIST_SORT constant.
          AddressListSort = 3355443225UL
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Net::Sockets::IOControlCode> {
  void operator()(System::Collections::Generic::IDictionary<System::Net::Sockets::IOControlCode, string>& values, bool& flags) {
    values[System::Net::Sockets::IOControlCode::EnableCircularQueuing] = "EnableCircularQueuing";
    values[System::Net::Sockets::IOControlCode::Flush] = "CodeFlush";
    values[System::Net::Sockets::IOControlCode::DataToRead] = "DataToRead";
    values[System::Net::Sockets::IOControlCode::OobDataRead] = "OoDataRead";
    values[System::Net::Sockets::IOControlCode::GetBroadcastAddress] = "GetBroadcastAddress";
    values[System::Net::Sockets::IOControlCode::AddressListQuery] = "AddressListQuery";
    values[System::Net::Sockets::IOControlCode::QueryTargetPnpHandle] = "TargetPnpHandle";
    values[System::Net::Sockets::IOControlCode::AsyncIO] = "AsyncIO";
    values[System::Net::Sockets::IOControlCode::NonBlockingIO] = "NonBlockingIO";
    values[System::Net::Sockets::IOControlCode::AssociateHandle] = "AssociateHandle";
    values[System::Net::Sockets::IOControlCode::MultipointLoopback] = "MultipointLoopback";
    values[System::Net::Sockets::IOControlCode::MulticastScope] = "MulticastScope";
    values[System::Net::Sockets::IOControlCode::SetQos] = "SetQos";
    values[System::Net::Sockets::IOControlCode::SetGroupQos] = "SetGroupQos";
    values[System::Net::Sockets::IOControlCode::RoutingInterfaceChange] = "RoutingInterfaceChange";
    values[System::Net::Sockets::IOControlCode::NamespaceChange] = "NamespaceChange";
    values[System::Net::Sockets::IOControlCode::ReceiveAll] = "ReceiveAll";
    values[System::Net::Sockets::IOControlCode::ReceiveAllMulticast] = "ReceiveMulticast";
    values[System::Net::Sockets::IOControlCode::ReceiveAllIgmpMulticast] = "ReceiveAllIgmpMulticast";
    values[System::Net::Sockets::IOControlCode::KeepAliveValues] = "KeepAliveValues";
    values[System::Net::Sockets::IOControlCode::AbsorbRouterAlert] = "CodeAbsorbRouterAlert";
    values[System::Net::Sockets::IOControlCode::UnicastInterface] = "UnicastInterface";
    values[System::Net::Sockets::IOControlCode::LimitBroadcasts] = "LimitBroadcasts";
    values[System::Net::Sockets::IOControlCode::BindToInterface] = "BindToInterface";
    values[System::Net::Sockets::IOControlCode::MulticastInterface] = "MulticastInterface";
    values[System::Net::Sockets::IOControlCode::AddMulticastGroupOnInterface] = "AddMulticastGroupOnInterface";
    values[System::Net::Sockets::IOControlCode::DeleteMulticastGroupFromInterface] = "DeleteMulticastGroupFromInterface";
    values[System::Net::Sockets::IOControlCode::GetExtensionFunctionPointer] = "GetExtensionFunctionPointer";
    values[System::Net::Sockets::IOControlCode::GetQos] = "GetQos";
    values[System::Net::Sockets::IOControlCode::GetGroupQos] = "GetGroupQos";
    values[System::Net::Sockets::IOControlCode::TranslateHandle] = "TranslateHandle";
    values[System::Net::Sockets::IOControlCode::RoutingInterfaceQuery] = "RoutingInterfaceQuery";
    values[System::Net::Sockets::IOControlCode::AddressListSort] = "AddressListSort";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
