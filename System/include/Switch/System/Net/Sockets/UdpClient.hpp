/// @file
/// @brief Contains Switch::System::Net::Sockets::UdpClient class.
#pragma once

#include "../../../SystemExport.hpp"
#include "Socket.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief Provides User Datagram Protocol (UDP) network services.
        /// @par Library
        /// Switch.System
        /// @par Examples
        /// This example show how to use UdpClient class as listener :
        /// @include UdpClientListener.cpp
        /// This example show how to use UdpClient class as talker :
        /// @include UdpClientTalker.cpp
        class system_export_ UdpClient : public Object {
        public:
          /// @brief Initializes a new instance of the UdpClient class
          /// This constructor creates a new UdpClient and allows the underlying service
          /// provider to assign the most appropriate local IPv4 address and port number.
          /// If this constructor is used, the UdpClient instance is set with an address
          /// family of IPv4 that cannot be changed or overwritten by a connect method
          /// call with an IPv6 target.
          UdpClient();

          /// @brief Initializes a new instance of the UdpClient class
          /// @param addressFamily one of the AddressFamily values that specifies the addressing scheme of the socket.
          UdpClient(AddressFamily addressFamily);

          /// @brief Initializes a new instance of the UdpClient class and binds it to the local port number provided.
          /// @param port the local port number to use.
          UdpClient(int32 port);

          /// @brief Initializes a new instance of the UdpClient class and binds it to the specified local endpoint.
          UdpClient(const IPEndPoint& endPoint);

          /// @brief Initializes a new instance of the UdpClient class and binds to the provided local port
          /// @param port the local port number to use.
          /// @param addressFamily one of the AddressFamily values that specifies the addressing scheme of the socket.
          UdpClient(int32 port, AddressFamily addressFamily);

          /// @brief Initializes a new instance of the UdpClient class and connects to specified host@port
          /// @param hostname the hostname to connect to.
          /// @param port the local port number to use.
          UdpClient(const String& hostname, int32 port);

          /// @brief Gets the amount of data that has been received from the network and is available to be read.
          /// @return int32 The number of bytes of data received from the network and available to be read.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks If you are using a non-blocking Socket, Available is a good way to determine whether data is queued for reading, before calling Receive. The available data is the total amount of data queued in the network buffer for reading. If no data is queued in the network buffer, Available returns 0.
          /// @remarks If the remote host shuts down or closes the connection, Available can throw a SocketException. If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          int32 GetAvailable() const;

          /// @brief Gets the underlying network Socket
          refptr<Socket> GetClient();

          /// @brief Gets the underlying network Socket
          const refptr<Socket> GetClient() const;

          /// @brief Sets the underlying network Socket
          /// @param client the socket to use
          void SetClient(const refptr<Socket>& client);

          /// @brief Gets a value that indicates whether a Socket is connected to a remote host as of the last Send or Receive operation.
          /// @return bool true if the Socket was connected to a remote resource as of the most recent operation; otherwise, false.
          bool GetConnected() const;

          /// @brief Gets or sets a value that allows IP datagrams to be fragmented
          bool GetDontFragment() const;
          void SetDontFragment(bool dontFragment);

          /// @brief Gets or sets a value indicating that the UpdClient can send or receive broadcasts packets
          bool GetEnableBroadcast() const;
          void SetEnableBroadcast(bool enableBroadcast);

          /// @brief Gets or sets a value indicating that the UpdClient allows only one client to use the port
          bool GetExclusiveAddressUse() const;
          void SetExclusiveAddressUse(bool exclusiveAddressUse);

          /// @brief Gets or sets a value specifying whether outgoing multicast packets are delivered to the sending application
          bool GetMulticastLoopback() const;
          void SetMulticastLoopback(bool multicastLoopback);

          /// @brief Gets a value that specifies the Time To Live (TTL) value of Internet Protocol (IP) packets sent by the Socket.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information. - or - socketOptionName was set to the unsupported value SocketOptionNameMaxConnections.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @return The TTL value.
          /// @remarks The TTL value indicates the maximum number of routers the packet can traverse before the router discards the packet and an Internet Control Message Protocol (ICMP) "TTL exceeded" error message is returned to the sender.
          /// @remarks The TTL value may be set to a value from 0 to 255. When this property is not set, the default TTL value for a socket is 32.
          /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket is ignored by the TCP/IP stack if a successful connection has been established using the socket.
          /// @remarks If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          int32 GetTtl() const;

          /// @brief Sets a value that specifies the Time To Live (TTL) value of Internet Protocol (IP) packets sent by the Socket.
          /// @param ttl The TTL value.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information. - or - socketOptionName was set to the unsupported value SocketOptionNameMaxConnections.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @exception ArgumentOutOfRangeException The TTL value can't be set to a negative number.
          /// @exception NotSupportedException This property can be set only for sockets in the AddressFamilyInterNetwork or AddressFamilyInterNetworkV6 families.
          /// @remarks The TTL value indicates the maximum number of routers the packet can traverse before the router discards the packet and an Internet Control Message Protocol (ICMP) "TTL exceeded" error message is returned to the sender.
          /// @remarks The TTL value may be set to a value from 0 to 255. When this property is not set, the default TTL value for a socket is 32.
          /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket is ignored by the TCP/IP stack if a successful connection has been established using the socket.
          /// @remarks If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          void SetTtl(int32 ttl);

          /// @brief  Closes the UDP connection
          void Close();

          /// @brief Establishes a default remote host using the specified network endpoint
          /// @param endPoint An IPEndPoint that specifies the network endpoint to which you intend to send data
          void Connect(const IPEndPoint& endPoint);

          /// @brief Establishes a default remote host using the specified IP address and port number
          /// @param ipAddress The IPAddress of the remote host to which you intend to send data
          /// @param port The port number to which you intend send data
          void Connect(const IPAddress& ipAddress, int32 port);

          /// @brief Establishes a default remote host using the specified hostname and port number
          /// @param hostname the hostname to connect to.
          /// @param port The port number to which you intend send data
          void Connect(const String& hostname, int32 port);

          /// @brief Adds a UdpClient to a multicast group.
          /// @param multicastAddress the address of the multicast group
          void JoinMulticastGroup(const IPAddress& multicastAddress);

          /// @brief Adds a UdpClient to a multicast group.
          /// @param ifIndex the interface index
          /// @param multicastAddress the address of the multicast group
          void JoinMulticastGroup(int32 ifIndex, const IPAddress& multicastAddress);

          /// @brief Adds a UdpClient to a multicast group.
          /// @param multicastAddress the address of the multicast group
          /// @param ttl the TTL in router hops
          void JoinMulticastGroup(const IPAddress& multicastAddress, int32 ttl);

          /// @brief Adds a UdpClient to a multicast group.
          /// @param multicastAddress the address of the multicast group
          /// @param localAddress the local address
          void JoinMulticastGroup(const IPAddress& multicastAddress, const IPAddress& localAddress);

          /// @brief Returns a UDP datagram sent by a remote host
          /// @param buffer:
          /// @param endPoint will be filled with the sender information
          /// @remarks The Receive method will block until a datagram arrives from a remote host.
          /// @remarks When data is available, the Receive method will read the first enqueued
          /// @remarks datagram and return the data portion as a byte array. This method populates
          /// @remarks the remoteEP parameter with the IPAddress and port number of the sender.
          /// @remarks If you specify a default remote host in the Connect method, the Receive
          /// @remarks method will accept datagrams from that host only. All other datagrams will be discarded.
          int32 Receive(Array<byte>& buffer, IPEndPoint& endPoint);

          /// @brief Sends a UDP datagram to a remote host
          /// @param data the data to send
          /// @return the number of bytes successfully sent
          /// @remarks This overload sends datagrams to the remote host established in the Connect method
          /// @remarks and returns the number of bytes sent. If you do not call Connect before calling this
          /// @remarks overload, the Send method will throw a SocketException. If you receive a SocketException,
          /// @remarks use SocketException.ErrorCode to obtain the specific error code. Once you have obtained
          /// @remarks this code, you can refer to the Windows Sockets version 2 API error code documentation
          /// @remarks in MSDN for a detailed description of the error.
          /// @remarks If you want to send datagrams to a different remote host, you must call the Connect method
          /// @remarks and specify the desired remote host. Use either of the other Send method overloads to send
          /// @remarks datagrams to a broadcast address.
          int32 Send(const Array<byte>& data);

          /// @brief Sends a UDP datagram to the specified end point
          /// @param data the data to send
          /// @param endPoint the end point to send data to
          /// @return the number of bytes successfully sent
          int32 Send(const Array<byte>& data, const IPEndPoint& endPoint);

          /// @brief Sends a UDP datagram to the specified end point
          /// @param data the data to send
          /// @param hostname the hostname where to send data or "255.255.255.255" (default broadcast address)
          /// @param port The port number to which you intend send data
          /// @return the number of bytes successfully sent
          int32 Send(const Array<byte>& data, const String& hostname, int32 port);

        private:
          refptr<Socket> client;
        };
      }
    }
  }
}

using namespace Switch;
