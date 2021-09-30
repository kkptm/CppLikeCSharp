/// @file
/// @brief Contains Switch::System::Net::Sockets::Socket class.
#pragma once

#include <Switch/Types.hpp>
#include <Switch/RefPtr.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/IntPtr.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/ObjectDisposedException.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Collections/Generic/IList.hpp>
#include "../../../SystemExport.hpp"
#include "../EndPoint.hpp"
#include "../IPEndPoint.hpp"
#include "../IPAddress.hpp"
#include "AddressFamily.hpp"
#include "IOControlCode.hpp"
#include "LingerOption.hpp"
#include "ProtocolType.hpp"
#include "SelectMode.hpp"
#include "SocketFlags.hpp"
#include "SocketInformation.hpp"
#include "SocketOptionLevel.hpp"
#include "SocketOptionName.hpp"
#include "SocketType.hpp"
#include "SocketShutdown.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief Implements the Berkeley sockets interface.
        /// @remarks The Socket class provides a rich set of methods and properties for network communications. The Socket class allows you to perform both synchronous and asynchronous data transfer using any of the communication protocols listed in the ProtocolType enumeration.
        /// @remarks The Socket class follows the .NET Framework naming pattern for asynchronous methods. For example, the synchronous Receive method corresponds to the asynchronous BeginReceive and EndReceive methods.
        /// @remarks If your application only requires one thread during execution, use the following methods, which are designed for synchronous operation mode.
        /// @remarks If you are using a connection-oriented protocol such as TCP, your server can listen for connections using the Listen method. The Accept method processes any incoming connection requests and returns a Socket that you can use to communicate data with the remote host. Use this returned Socket to call the Send or Receive method. Call the Bind method prior to calling the Listen method if you want to specify the local IP address and port number. Use a port number of zero if you want the underlying service provider to assign a free port for you. If you want to connect to a listening host, call the Connect method. To communicate data, call the Send or Receive method.
        /// @remarks If you are using a connectionless protocol such as UDP, you do not need to listen for connections at all. Call the ReceiveFrom method to accept any incoming datagrams. Use the SendTo method to send datagrams to a remote host.
        /// @remarks To process communications using separate threads during execution, use the following methods, which are designed for asynchronous operation mode.
        /// @remarks If you are using a connection-oriented protocol such as TCP, use the Socket, BeginConnect, and EndConnect methods to connect with a listening host. Use the BeginSend and EndSend or BeginReceive and EndReceive methods to communicate data asynchronously. Incoming connection requests can be processed using BeginAccept and EndAccept.
        /// @remarks If you are using a connectionless protocol such as UDP, you can use BeginSendTo and EndSendTo to send datagrams, and BeginReceiveFrom and EndReceiveFrom to receive datagrams.
        /// @remarks If you perform multiple asynchronous operations on a socket, they do not necessarily complete in the order in which they are started.
        /// @remarks When you are finished sending and receiving data, use the Shutdown method to disable the Socket. After calling Shutdown, call the Close method to release all resources associated with the Socket.
        /// @remarks The Socket class allows you to configure your Socket using the SetSocketOption method. Retrieve these settings using the GetSocketOption method.
        /// @note If you are writing a relatively simple application and do not require maximum performance, consider using TcpClient, TcpListener, and UdpClient. These classes provide a simpler and more user-friendly interface to Socket communications.
        /// @par Library
        /// Switch.System
        class system_export_ Socket : public Object {
        public:
          /// @brief Initializes a new instance of the Socket class using the specified address family, socket type and protocol.
          /// @param addressFamily One of the AddressFamily values.
          /// @param socketType One of the SocketType values.
          /// @param protocolType One of the ProtocolType values.
          /// @exception SocketException The combination of addressFamily, socketType, and protocolType results in an invalid socket.
          /// @remarks The addressFamily parameter specifies the addressing scheme that the Socket class uses, the socketType parameter specifies the type of the Socket class, and the protocolType parameter specifies the protocol used by Socket. The three parameters are not independent. Some address families restrict which protocols can be used with them, and often the Socket type is implicit in the protocol. If the combination of address family, Socket type, and protocol type results in an invalid Socket, this constructor throws a SocketException.
          /// @note If this constructor throws a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          Socket(System::Net::Sockets::AddressFamily addressFamily, System::Net::Sockets::SocketType socketType, System::Net::Sockets::ProtocolType protocolType);

          /// @brief Initializes a new instance of the Socket class using the specified value returned from DuplicateAndClose.
          /// @param socketInformation The socket information returned by DuplicateAndClose.
          /// @remarks If you call the Socket constructor multiple times with the same byte array as the argument for each call, you will create multiple managed Sockets with the same underlying socket. This practice is strongly discouraged.
          explicit Socket(const SocketInformation& socketInformation)  {}

          /// @cond
          Socket() {}
          Socket(const Socket& socket) : data(socket.data) {}
          Socket& operator=(const Socket& socket) {this->data = socket.data; return *this;}
          ~Socket();
          /// @endcond

          /// @brief Gets the address family of the Socket.
          /// @return AddressFamily One of the AddressFamily values.
          /// @remarks The AddressFamily specifies the addressing scheme that an instance of the Socket class can use. This property is read-only and is set when the Socket is created.
          property_<System::Net::Sockets::AddressFamily, readonly_> AddressFamily {
            get_ {return this->data->addressFamily;}
          };

          /// @brief Gets the amount of data that has been received from the network and is available to be read.
          /// @return int32 The number of bytes of data received from the network and available to be read.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks If you are using a non-blocking Socket, Available is a good way to determine whether data is queued for reading, before calling Receive. The available data is the total amount of data queued in the network buffer for reading. If no data is queued in the network buffer, Available returns 0.
          /// @remarks If the remote host shuts down or closes the connection, Available can throw a SocketException. If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          property_<int32, readonly_> Available {
            get_ {return this->GetAvailable();}
          };

          /// @brief Gets a value that indicates whether the Socket is in blocking mode.
          /// @return bool true if the Socket will block; otherwise, false. The default is true
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Blocking property indicates whether a Socket is in blocking mode.
          /// @remarks If you are in blocking mode, and you make a method call which does not complete immediately, your application will block execution until the requested operation completes. If you want execution to continue even though the requested operation is not complete, change the Blocking property to false. The Blocking property has no effect on asynchronous methods. If you are sending and receiving data asynchronously and want to block execution, use the ManualResetEvent class.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          property_<bool> Blocking {
            get_ {return this->GetBlocking();},
            set_ {this->SetBlocking(value);}
          };

          /// @brief Gets a value that indicates whether a Socket is connected to a remote host as of the last Send or Receive operation.
          /// @return bool true if the Socket was connected to a remote resource as of the most recent operation; otherwise, false.
          property_<bool, readonly_> Connected {
            get_ {return this->data->connected;}
          };

          /// @brief Gets a Boolean value that specifies whether the Socket allows Internet Protocol (IP) datagrams to be fragmented.
          /// @return bool true if the Socket allows datagram fragmentation; otherwise, false. The default is true.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Datagrams require fragmentation when their size exceeds the Maximum Transfer Unit (MTU) of the transmission medium. Datagrams may be fragmented by the sending host (all Internet Protocol versions) or an intermediate router (Internet Protocol Version 4 only). If a datagram must be fragmented, and the DontFragment option is set, the datagram is discarded, and an Internet Control Message Protocol (ICMP) error message is sent back to the sender of the datagram.
          /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket will have no effect.
          property_<bool> DontFragment {
            get_ {return this->GetDontFragment();},
            set_ {this->SetDontFragment(value);}
          };

          /// @brief Gets or sets a Boolean value that specifies whether the Socket is a dual-mode socket used for both IPv4 and IPv6.
          /// @return bool true if the Socket is a dual-mode socket; otherwise, false. The default is false.
          property_<bool> DualMode {
            get_ {return this->GetDualMode();},
            set_ {this->SetDualMode(value);}
          };

          /// @brief Gets a Boolean value that specifies whether the Socket can send or receive broadcast packets.
          /// @return bool true if the Socket allows only one socket to bind to a specific port; otherwise, false. The default is true.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Broadcasting is limited to a specific subnet, and must use User Datagram Protocol (UDP.) For Internet Protocol version 4, you can broadcast to your local subnet by sending a packet to 255.255.255.255; or you can use the directed broadcast address, which is the network portion of an Internet Protocol (IP) address with all bits set in the host portion. For example, if your IP address is 192.168.1.40 (a Class C address, with a netmask of 255.255.255.0 -- the network portion is the first three octets, and the host portion is the last octet), your directed broadcast address is 192.168.1.255.
          /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket will have no effect.
          property_<bool> EnableBroadcast {
            get_ {return this->GetEnableBroadcast();},
            set_ {this->SetEnableBroadcast(value);}
          };

          /// @brief Gets or sets a Boolean value that specifies whether the Socket allows only one process to bind to a port.
          /// @return bool true if the Socket allows broadcast packets; otherwise, false. The default is false.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks If ExclusiveAddressUse is false, multiple sockets can use the Bind method to bind to a specific port; however only one of the sockets can perform operations on the network traffic sent to the port. If more than one socket attempts to use the Bind(EndPoint) method to bind to a particular port, then the one with the more specific IP address will handle the network traffic sent to that port.
          /// @remarks If ExclusiveAddressUse is true, the first use of the Bind method to attempt to bind to a particular port, regardless of Internet Protocol (IP) address, will succeed; all subsequent uses of the Bind method to attempt to bind to that port will fail until the original bound socket is destroyed.
          /// @remarks This property must be set before Bind is called; otherwise an InvalidOperationException will be thrown.
          property_<bool> ExclusiveAddressUse {
            get_ {return this->GetExclusiveAddressUse();},
            set_ {this->SetExclusiveAddressUse(value);}
          };

          /// @brief Gets the operating system handle for the Socket.
          /// @return IntPtr An IntPtr that represents the operating system handle for the Socket.
          property_<intptr, readonly_> Handle {
            get_ {return (intptr)this->data->socket;}
          };

          /// @brief Gets a value that indicates whether the Socket is bound to a specific local port.
          /// @return bool true if the Socket is bound to a local port; otherwise, false.
          /// @remarks A socket is considered bound to a local port if it is explicitly bound by calling the Bind method, or implicitly bound by calling members like Connect, SendTo, or ReceiveFrom, which use an ephemeral local port (a free port greater than 1024, selected by the operating system.) Servers use the Bind method to bind to a well-known port so that clients may connect to them.
          property_<bool, readonly_> IsBound {
            get_ {return this->data->bound;}
          };

          /// @brief Gets os sets a value that specifies whether the Socket will delay closing a socket in an attempt to send all pending data.
          /// @return A LingerOption that specifies how to linger while closing a socket.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The LingerState property changes the way Close method behaves. This property when set modifies the conditions under which the connection can be reset by Winsock. Connection resets can still occur based on the IP protocol behavior.
          /// @remarks This property controls the length of time that a connection-oriented connection will remain open after a call to Close when data remains to be sent.
          /// @remarks When you call methods to send data to a peer, this data is placed in the outgoing network buffer. This property can be used to ensure that this data is sent to the remote host before the Close method drops the connection.
          /// @remarks To enable lingering, create a LingerOption instance containing the desired values, and set the LingerState property to this instance.
          /// @remarks The following table describes the behavior of the Close method for the possible values of the Enabled property and the LingerTime property stored in the LingerState property.
          /// | enable                              | seconds                                    | Behavior                                                                                                                          |
          /// |-------------------------------------|--------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
          /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data for a connection-oriented socket (TCP, for example) until the default IP protocol time-out expires. |
          /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
          /// | true (enabled)                      | A zero timeout.                            | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
          /// @remarks he IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the LingerState property is not set.
          /// @remarks When the LingerTime property stored in the LingerState property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
          property_<LingerOption> LingerState {
            get_ {return this->GetLingerState();},
            set_ {this->SetLingerState(value);}
          };

          /// @brief Gets the local endpoint.
          /// @return The EndPoint that the Socket is using for communications.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The LocalEndPoint property gets an EndPoint that contains the local IP address and port number to which your Socket is bound. You must cast this EndPoint to an IPEndPoint before retrieving any information. You can then call the IPEndPoint.Address method to retrieve the local IPAddress, and the IPEndPoint.Port method to retrieve the local port number.
          /// @remarks The LocalEndPoint property is usually set after you make a call to the Bind method. If you allow the system to assign your socket's local IP address and port number, the LocalEndPoint property will be set after the first I/O operation. For connection-oriented protocols, the first I/O operation would be a call to the Connect or Accept method. For connectionless protocols, the first I/O operation would be any of the send or receive calls.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          property_<const EndPoint&, readonly_> LocalEndPoint {
            get_->const EndPoint& {return this->GetLocalEndPoint();}
          };

          /// @brief Gets a value that specifies whether outgoing multicast packets are delivered to the sending application.
          /// @return bool true if the Socket receives outgoing multicast packets; otherwise, false.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Multicast is a scalable method for many-to-many communication on the Internet. A process subscribes to a multicast address; then, any packets sent by a subscribed process are received by every other process subscribed to the multicast address.
          /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket will have no effect.
          property_<bool> MulticastLoopback {
            get_ {return this->GetMulticastLoopback();},
            set_ {this->SetMulticastLoopback(value);}
          };

          /// @brief Gets a Boolean value that specifies whether the stream Socket is using the Nagle algorithm.
          /// @return bool false if the Socket uses the Nagle algorithm; otherwise, true. The default is false.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Nagle algorithm is designed to reduce network traffic by causing the socket to buffer small packets and then combine and send them in one packet under certain circumstances. A TCP packet consists of 40 bytes of header plus the data being sent. When small packets of data are sent with TCP, the overhead resulting from the TCP header can become a significant part of the network traffic. On heavily loaded networks, the congestion resulting from this overhead can result in lost datagrams and retransmissions, as well as excessive propagation time caused by congestion. The Nagle algorithm inhibits the sending of new TCP segments when new outgoing data arrives from the user if any previouslytransmitted data on the connection remains unacknowledged.
          /// @remarks The majority of network applications should use the Nagle algorithm.
          /// @remarks Setting this property on a User Datagram Protocol (UDP) socket will have no effect.
          property_<bool> NoDelay {
            get_ {return this->GetNoDelay();},
            set_ {this->SetNoDelay(value);}
          };

          /// @brief Indicates whether the underlying operating system and network adaptors support Internet Protocol version 4 (IPv4).
          /// @return bool true if the operating system and network adaptors support the IPv4 protocol; otherwise, false.
          /// @remarks The majority of operating system may support both IPv4 and IPv6 protocols.
          static property_<bool, readonly_> OSSupportsIPv4;

          /// @brief Indicates whether the underlying operating system and network adaptors support Internet Protocol version 6 (IPv6).
          /// @return bool true if the operating system and network adaptors support the IPv6 protocol; otherwise, false.
          /// @remarks The majority of operating system may support both IPv4 and IPv6 protocols.
          static property_<bool, readonly_> OSSupportsIPv6;

          /// @brief Gets the protocol type of the Socket.
          /// @return One of the ProtocolType values.
          /// @remarks The ProtocolType property is set when the Socket is created, and specifies the protocol used by that Socket.
          property_<System::Net::Sockets::ProtocolType, readonly_> ProtocolType {
            get_ {return this->data->protocolType;}
          };

          /// @brief Gets a value that specifies the size of the receive buffer of the Socket.
          /// @return An int32 that contains the size, in bytes, of the receive buffer. The default is 8192.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks A larger buffer size potentially reduces the number of empty acknowledgements (TCP packets with no data portion), but might also delay the recognition of connection difficulties. Consider increasing the buffer size if you are transferring large files, or you are using a high bandwidth, high latency connection (such as a satellite broadband provider.)
          property_<int32> ReceiveBufferSize {
            get_ {return this->GetReceiveBufferSize();},
            set_ {this->SetReceiveBufferSize(value);}
          };

          /// @brief Gets a value that specifies the amount of time after which a synchronous Receive call will time out.
          /// @return The time-out value, in milliseconds. The default value is 0, which indicates an infinite time-out period. Specifying -1 also indicates an infinite time-out period.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks This option applies to synchronous Receive calls only. If the time-out period is exceeded, the Receive method will throw a SocketException.
          property_<int32> ReceiveTimeout {
            get_ {return this->GetReceiveTimeout();},
            set_ {this->SetReceiveTimeout(value);}
          };

          /// @brief Gets the remote endpoint.
          /// @return The EndPoint with which the Socket is communicating.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks If you are using a connection-oriented protocol, the RemoteEndPoint property gets the EndPoint that contains the remote IP address and port number to which the Socket is connected. If you are using a connectionless protocol, RemoteEndPoint contains the default remote IP address and port number with which the Socket will communicate. You must cast this EndPoint to an IPEndPoint before retrieving any information. You can then call the IPEndPoint.Address method to retrieve the remote IPAddress, and the IPEndPoint.Port method to retrieve the remote port number.
          /// @remarks The RemoteEndPoint is set after a call to either Accept or Connect. If you try to access this property earlier, RemoteEndPoint will throw a SocketException. If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          property_<const EndPoint&, readonly_> RemoteEndPoint {
            get_->const EndPoint& {return this->GetRemoteEndPoint();}
          };

          /// @brief Gets a value that specifies the size of the send buffer of the Socket.
          /// @return An int32 that contains the size, in bytes, of the send buffer. The default is 8192.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks A larger buffer size potentially reduces the number of empty acknowledgements (TCP packets with no data portion), but might also delay the recognition of connection difficulties. Consider increasing the buffer size if you are transferring large files, or you are using a high bandwidth, high latency connection (such as a satellite broadband provider.)
          property_<int32> SendBufferSize {
            get_ {return this->GetSendBufferSize();},
            set_ {this->SetSendBufferSize(value);}
          };

          /// @brief Gets a value that specifies the amount of time after which a synchronous Send call will time out.
          /// @return The time-out value, in milliseconds. The default value is 0, which indicates an infinite time-out period. Specifying -1 also indicates an infinite time-out period.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks This option applies to synchronous Receive calls only. If the time-out period is exceeded, the Receive method will throw a SocketException.
          property_<int32> SendTimeout {
            get_ {return this->GetSendTimeout();},
            set_ {this->SetSendTimeout(value);}
          };

          /// @brief Gets the type of the Socket.
          /// @return SocketType One of the SocketType values.
          /// @remarks SocketType is read-only and is set when the Socket is created.
          property_<System::Net::Sockets::SocketType, readonly_> SocketType {
            get_ {return this->data->socketType;}
          };

          /// @brief Gets a value that specifies the Time To Live (TTL) value of Internet Protocol (IP) packets sent by the Socket.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information. - or - socketOptionName was set to the unsupported value SocketOptionNameMaxConnections.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @return The TTL value.
          /// @remarks The TTL value indicates the maximum number of routers the packet can traverse before the router discards the packet and an Internet Control Message Protocol (ICMP) "TTL exceeded" error message is returned to the sender.
          /// @remarks The TTL value may be set to a value from 0 to 255. When this property is not set, the default TTL value for a socket is 32.
          /// @remarks Setting this property on a Transmission Control Protocol (TCP) socket is ignored by the TCP/IP stack if a successful connection has been established using the socket.
          /// @remarks If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          property_<int32> Ttl {
            get_ {return this->GetTtl();},
            set_ {this->SetTtl(value);}
          };

          /// @brief Creates a new Socket for a newly created connection.
          /// @return Socket A Socket for a newly created connection.
          /// @remarks Accept synchronously extracts the first pending connection request from the connection request queue of the listening socket, and then creates and returns a new Socket. You cannot use this returned Socket to accept any additional connections from the connection queue. However, you can call the RemoteEndPoint method of the returned Socket to identify the remote host's network address and port number.
          /// @remarks In blocking mode, Accept blocks until an incoming connection attempt is queued. Once a connection is accepted, the original Socket continues queuing incoming connection requests until you close it.
          /// @remarks If you call this method using a non-blocking Socket, and no connection requests are queued, Accept throws a SocketException. If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note Before calling the Accept method, you must first call the Listen method to listen for and queue incoming connection requests.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          Socket Accept();

          /// @brief Associates a Socket with a local endpoint.
          /// @param localEndPoint The local EndPoint to associate with the Socket.
          /// @exception ArgumentNullException localEndPoint is null.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException he Socket has been closed.
          /// @remarks Use the Bind method if you need to use a specific local endpoint. You must call Bind before you can call the Listen method. You do not need to call Bind before using the Connect method unless you need to use a specific local endpoint. You can use the Bind method on both connectionless and connection-oriented protocols.
          /// @remarks Before calling Bind, you must first create the local IPEndPoint from which you intend to communicate data. If you do not care which local address is assigned, you can create an IPEndPoint using IPAddress.Any as the address parameter, and the underlying service provider will assign the most appropriate network address. This might help simplify your application if you have multiple network interfaces. If you do not care which local port is used, you can create an IPEndPoint using 0 for the port number. In this case, the service provider will assign an available port number between 1024 and 5000.
          /// @remarks If you use the above approach, you can discover what local network address and port number has been assigned by calling the LocalEndPoint. If you are using a connection-oriented protocol, LocalEndPoint will not return the locally assigned network address until after you have made a call to the Connect or EndConnect method. If you are using a connectionless protocol, you will not have access to this information until you have completed a send or receive.
          /// @remarks If a UDP socket wants to receive interface information on received packets, the SetSocketOption method should be explicitly called with the socket option set to PacketInformation immediately after calling the Bind method.
          /// @note If you intend to receive multicast datagrams, you must call the Bind method with a multicast port number.
          /// @note You must call the Bind method if you intend to receive connectionless datagrams using the ReceiveFrom method.
          /// @note If you receive a SocketException when calling the Bind method, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          template<typename TEndPoint>
          void Bind(const TEndPoint& localEndPoint) {
            if (this->data->socket == 0)
              throw ObjectDisposedException(caller_);

            this->data->localEndPoint = as<EndPoint>(localEndPoint.template MemberwiseClone<TEndPoint>());
            InnerBind();
          }

          /// @brief Closes the Socket connection and releases all associated resources.
          /// @remarks The Close method closes the remote host connection and releases all managed and unmanaged resources associated with the Socket. Upon closing, the Connected property is set to false.
          /// @remarks For connection-oriented protocols, it is recommended that you call Shutdown before calling the Close method. This ensures that all data is sent and received on the connected socket before it is closed.
          /// @remarks If you need to call Close without first calling Shutdown, you can ensure that data queued for outgoing transmission will be sent by setting the DontLinger Socket option to false and specifying a non-zero time-out interval. Close will then block until this data is sent or until the specified time-out expires. If you set DontLinger to false and specify a zero time-out interval, Close releases the connection and automatically discards outgoing queued data.
          /// @note To set the DontLinger socket option to false, create a LingerOption, set the enabled property to true, and set the LingerTime property to the desired time out period. Use this LingerOption along with the DontLinger socket option to call the SetSocketOption method.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          void Close();

          /// @brief Establishes a connection to a remote host.
          /// @param endPoint An EndPoint that represents the remote device.
          /// @exception ArgumentNullException endPoint is null.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @exception InvalidOperationException The Socket is Listening.
          /// @remarks If you are using a connection-oriented protocol such as TCP, the Connect method synchronously establishes a network connection between LocalEndPoint and the specified remote endpoint. If you are using a connectionless protocol, Connect establishes a default remote host. After you call Connect, you can send data to the remote device with the Send method, or receive data from the remote device with the Receive method.
          /// @remarks If you are using a connectionless protocol such as UDP, you do not have to call Connect before sending and receiving data. You can use SendTo and ReceiveFrom to synchronously communicate with a remote host. If you do call Connect, any datagrams that arrive from an address other than the specified default will be discarded. If you want to set your default remote host to a broadcast address, you must first call the SetSocketOption method and set the socket option to SocketOptionName.Broadcast, or Connect will throw a SocketException. If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @remarks The Connect method will block, unless you specifically set the Blocking property to false prior to calling Connect. If you are using a connection-oriented protocol like TCP and you do disable blocking, Connect will throw a SocketException because it needs time to make the connection. Connectionless protocols will not throw an exception because they simply establish a default remote host. You can use SocketException.ErrorCode to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error. If the error returned WSAEWOULDBLOCK, the remote host connection has been initiated by a connection-oriented Socket, but has not yet completed successfully. Use the Poll method to determine when the Socket is finished connecting.
          /// @note If you are using a connection-oriented protocol and did not call Bind before calling Connect, the underlying service provider will assign the local network address and port number. If you are using a connectionless protocol, the service provider will not assign a local network address and port number until you complete a send or receive operation. If you want to change the default remote host, call Connect again with the desired endpoint.
          /// @note If the socket has been previously disconnected, then you cannot use this method to restore the connection. Use one of the asynchronous BeginConnect methods to reconnect. This is a limitation of the underlying provider.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          template<typename TEndPoint>
          void Connect(const TEndPoint& endPoint) {
            if (this->data->socket == 0)
              throw ObjectDisposedException(caller_);
            if (this->data->listening == true)
              throw InvalidOperationException(caller_);

            this->data->remoteEndPoint = as<EndPoint>(endPoint.template MemberwiseClone<TEndPoint>());
            InnerConnect();
          }

          /// @brief Establishes a connection to a remote host. The host is specified by an IP address and a port number.
          /// @param address The IP address of the remote host.
          /// @param port The port number of the remote host.
          /// @exception ArgumentNullException address is null.
          /// @exception ArgumentOutOfRangeException The port number is not valid.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception NotSupportedException This method is valid for sockets in the AddressFamillyInterNetwork or AddressFamilyInterNetworkV6 families.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @exception InvalidOperationException The Socket is Listening.
          /// @remarks If you are using a connection-oriented protocol such as TCP, the Connect method synchronously establishes a network connection between LocalEndPoint and the specified remote endpoint. If you are using a connectionless protocol, Connect establishes a default remote host. After you call Connect, you can send data to the remote device with the Send method, or receive data from the remote device with the Receive method.
          /// @remarks If you are using a connectionless protocol such as UDP, you do not have to call Connect before sending and receiving data. You can use SendTo and ReceiveFrom to synchronously communicate with a remote host. If you do call Connect, any datagrams that arrive from an address other than the specified default will be discarded. If you want to set your default remote host to a broadcast address, you must first call the SetSocketOption method and set the socket option to SocketOptionName.Broadcast, or Connect will throw a SocketException. If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @remarks The Connect method will block, unless you specifically set the Blocking property to false prior to calling Connect. If you are using a connection-oriented protocol like TCP and you do disable blocking, Connect will throw a SocketException because it needs time to make the connection. Connectionless protocols will not throw an exception because they simply establish a default remote host. You can use SocketException.ErrorCode to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error. If the error returned WSAEWOULDBLOCK, the remote host connection has been initiated by a connection-oriented Socket, but has not yet completed successfully. Use the Poll method to determine when the Socket is finished connecting.
          /// @note If you are using a connection-oriented protocol and did not call Bind before calling Connect, the underlying service provider will assign the local network address and port number. If you are using a connectionless protocol, the service provider will not assign a local network address and port number until you complete a send or receive operation. If you want to change the default remote host, call Connect again with the desired endpoint.
          /// @note If the socket has been previously disconnected, then you cannot use this method to restore the connection. Use one of the asynchronous BeginConnect methods to reconnect. This is a limitation of the underlying provider.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          void Connect(const IPAddress& address, int32 port);

          /// @brief Establishes a connection to a remote host. The host is specified by an array of IP addresses and a port number.
          /// @param address The IP address of the remote host.
          /// @param port The port number of the remote host.
          /// @exception ArgumentNullException addresses is null.
          /// @exception ArgumentOutOfRangeException The port number is not valid.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception NotSupportedException This method is valid for sockets in the AddressFamillyInterNetwork or AddressFamilyInterNetworkV6 families.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @exception InvalidOperationException The Socket is Listening.
          /// @remarks This method is typically used immediately after a call to GetHostAddresses, which can return multiple IP addresses for a single host. If you are using a connection-oriented protocol such as TCP, the Connect method synchronously establishes a network connection between LocalEndPoint and the specified remote endpoint. If you are using a connectionless protocol, Connect establishes a default remote host. After you call Connect you can send data to the remote device with the Send method, or receive data from the remote device with the Receive method.
          /// @remarks If you are using a connectionless protocol such as UDP, you do not have to call Connect before sending and receiving data. You can use SendTo and ReceiveFrom to synchronously communicate with a remote host. If you do call Connect any datagrams that arrive from an address other than the specified default will be discarded. If you want to set your default remote host to a broadcast address, you must first call the SetSocketOption method and set the socket option to SocketOptionName.Broadcast, or Connect will throw a SocketException. If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @remarks Connect method will block, unless you specifically set the Blocking property to false prior to calling Connect. If you are using a connection-oriented protocol like TCP and you do disable blocking, Connect will throw a SocketException because it needs time to make the connection. Connectionless protocols will not throw an exception because they simply establish a default remote host. You can use SocketException.ErrorCode to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error. If the error returned WSAEWOULDBLOCK, the remote host connection has been initiated by a connection-oriented Socket, but has not yet completed successfully. Use the Poll method to determine when the Socket is finished connecting.
          /// @note If you are using a connection-oriented protocol and did not call Bind before calling Connect, the underlying service provider will assign the local network address and port number. If you are using a connectionless protocol, the service provider will not assign a local network address and port number until you complete a send or receive operation. If you want to change the default remote host, call Connect again with the desired endpoint.
          /// @note If the socket has been previously disconnected, then you cannot use this method to restore the connection. Use one of the asynchronous BeginConnect methods to reconnect. This is a limitation of the underlying provider.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          void Connect(const Array<IPAddress>& addresses, int32 port);

          void Connect(const string& host, int32 port);

          /// @brief Closes the socket connection and allows reuse of the socket.
          /// @param reuseSocket true if this socket can be reused after the current connection is closed; otherwise, false.
          /// @exception NotSupportedException This method requires Windows 2000 or earlier, or the exception will be thrown.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @remarks If you are using a connection-oriented protocol, you can use this method to close the socket. This method ends the connection and sets the Connected property to false. However, if reuseSocket is true, you can reuse the socket.
          /// @remarks To ensure that all data is sent and received before the socket is closed, you should call Shutdown before calling the Disconnect method.
          /// @remarks If you need to call Disconnect without first calling Shutdown, you can set the DontLinger Socket option to false and specify a nonzero time-out interval to ensure that data queued for outgoing transmission is sent. Disconnect then blocks until the data is sent or until the specified time-out expires. If you set DontLinger to false and specify a zero time-out interval, Close releases the connection and automatically discards outgoing queued data.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          void Disconnect(bool reuseSocket);

          /// @brief Duplicates the socket reference for the target process, and closes the socket for this process.
          /// @param targetProcessId The ID of the target process where a duplicate of the socket reference is created.
          /// @exception SocketException targetProcessID is not a valid process id. -or- Duplication of the socket reference failed.
          /// @remarks The target process should use Socket to create the duplicate socket instance.
          /// @remarks If you call the Socket constructor multiple times with the same byte array as the argument for each call, you will create multiple managed Socket instances with the same underlying socket. This practice is strongly discouraged.
          /// @remarks If the process creating the socket uses asynchronous methods (BeginReceive or BeginSend), the process must first set the UseOnlyOverlappedIO property to true; otherwise, the socket is bound to the completion port of the creating process, which may cause an ArgumentNullException to be thrown on the target process.
          SocketInformation DuplicateAndClose(int32 targetProcessId);

          /// @brief Returns the value of a specified Socket option, represented as an object.
          /// @param socketOptionLevel One of the SocketOptionLevel values.
          /// @param socketOptionName One of the SocketOptionName values.
          /// @return object An object that represents the value of the option. When the socketOptionName parameter is set to SocketoptionNameLinger the return value is an instance of the LingerOption class. When socketOptionName is set to SocketOptionNameAddMembership or SocketOptionDropMembership, the return value is an instance of the MulticastOption class. When socketOptionName is any other value, the return value is an int32.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information. - or - socketOptionName was set to the unsupported value SocketOptionNameMaxConnections.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Socket options determine the behavior of the current Socket. Use this overload to get the SocketOptionNameLinger, SocketOptionNameAddMembership, and SocketOptionNameDropMembership Socket options. For the SocketOptionNameLinger option, use Socket for the socketOptionLevel parameter. For SocketOptionNameAddMembership and SocketOptionNameDropMembership, use IP. If you want to set the value of any of the options listed above, use the SetSocketOption method.
          refptr<Object> GetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName) const;

          /// @brief Sets low-level operating modes for the Socket using the IOControlCode enumeration to specify control codes.
          /// @param ioControlCode A IOControlCode value that specifies the control code of the operation to perform.
          /// @param optionInValue An array of type Byte that contains the input data required by the operation.
          /// @param optionOutValue An array of type Byte that contains the output data returned by the operation.
          /// @return The number of bytes in the optionOutValue parameter.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @exception InvalidOperationException An attempt was made to change the blocking mode without using the Blocking property.
          /// @remarks This method provides low-level access to the operating system Socket underlying the current instance of the Socket class. For more, see the WSAIoctl documentation in the MSDN library or see ioctl in the man.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 IOControl(IOControlCode ioControlCode, const Array<byte>& optionInValue, Array<byte>& optionOutValue);

          /// @brief Places a Socket in a listening state.
          /// @param backlog The maximum length of the pending connections queue.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Listen causes a connection-oriented Socket to listen for incoming connection attempts. The backlog parameter specifies the number of incoming connections that can be queued for acceptance. To determine the maximum number of connections you can specify, retrieve the MaxConnections value. Listen does not block.
          /// @remarks If you receive a SocketException, use the ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error. Use Accept or BeginAccept to accept a connection from the queue.
          /// @note You must call the Bind method before calling Listen, or Listen will throw a SocketException.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          /// @note The backlog parameter is limited to different values depending on the Operating System. You may specify a higher value, but the backlog will be limited based on the Operating System::
          void Listen(int32 backlog);

          /// @brief Determines the status of the Socket.
          /// @param microseconds The time to wait for a response, in microseconds.
          /// @param mode One of the SelectMode values.
          /// @return The status of the Socket based on the polling mode value passed in the mode parameter.
          /// | Mode                  | Return Value                                                                                                                                                                                         |
          /// |-----------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
          /// | SelectModeSelectRead  | true if Listen has been called and a connection is pending; -or- true if data is available for reading; -or- true if the connection has been closed, reset, or terminated; otherwise, returns false. |
          /// | SelectModeSelectWrite | true, if processing a Connect, and the connection has succeeded; -or- true if data can be sent; otherwise, returns false.                                                                            |
          /// | SelectModeSelectError | true if processing a Connect that does not block, and the connection has failed; -or- true if OutOfBandInline is not set and out-of-band data is available; otherwise, returns false.                |
          /// @exception NotSupportedException The mode parameter is not one of the SelectMode values.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Poll method will check the state of the Socket. Specify SelectModeSelectRead for the selectMode parameter to determine if the Socket is readable. Specify SelectModeSelectWrite to determine if the Socket is writable. Use SelectModeSelectError to detect an error condition. Poll will block execution until the specified time period, measured in microseconds, elapses. Set the microseconds parameter to a negative integer if you would like to wait indefinitely for a response. If you want to check the status of multiple sockets, you might prefer to use the Select method.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This method cannot detect certain kinds of connection problems, such as a broken network cable, or that the remote host was shut down ungracefully. You must attempt to send or receive data to detect these kinds of errors.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          bool Poll(int32 microseconds, SelectMode mode);

          /// @brief Receives data from a bound Socket into a receive buffer.
          /// @param buffer An array of type Byte that is the storage location for the received data.
          /// @return int32 The number of bytes received.
          /// @exception ArgumentNullException bufer is null
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call Receive from both connection-oriented and connectionless sockets.
          /// @remarks This overload only requires you to provide a receive buffer. The buffer offset defaults to 0, the size defaults to the length of the buffer parameter, and the SocketFlags value defaults to None.
          /// @remarks If you are using a connection-oriented protocol, you must either call Connect to establish a remote host connection, or Accept to accept an incoming connection prior to calling Receive. The Receive method will only read data that arrives from the remote host established in the Connect or Accept method. If you are using a connectionless protocol, you can also use the ReceiveFrom method. ReceiveFrom will allow you to receive data arriving from any host.
          /// @remarks If no data is available for reading, the Receive method will block until data is available, unless a time-out value was set by using Socket.ReceiveTimeout. If the time-out value was exceeded, the Receive call will throw a SocketException. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the Receive method will complete immediately and throw a SocketException. You can use the Available property to determine if data is available for reading. When Available is non-zero, retry the receive operation.
          /// @remarks If you are using a connection-oriented Socket, the Receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the Socket connection with the Shutdown method, and all available data has been received, the Receive method will complete immediately and return zero bytes.
          /// @remarks If you are using a connectionless Socket, Receive will read the first queued datagram from the destination address you specify in the Connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a SocketException is thrown.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 Receive(Array<byte>& buffer) {return this->Receive(buffer, 0, buffer.Length, SocketFlags::None);}

          /// @brief Receives data from a bound Socket into a receive buffer, using the specified SocketFlags.
          /// @param buffer An array of type Byte that is the storage location for the received data.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @return int32 The number of bytes received.
          /// @exception ArgumentNullException bufer is null
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call Receive from both connection-oriented and connectionless sockets.
          /// @remarks This overload only requires you to provide a receive buffer. The buffer offset defaults to 0, the size defaults to the length of the buffer parameter, and the SocketFlags value defaults to None.
          /// @remarks If you are using a connection-oriented protocol, you must either call Connect to establish a remote host connection, or Accept to accept an incoming connection prior to calling Receive. The Receive method will only read data that arrives from the remote host established in the Connect or Accept method. If you are using a connectionless protocol, you can also use the ReceiveFrom method. ReceiveFrom will allow you to receive data arriving from any host.
          /// @remarks If no data is available for reading, the Receive method will block until data is available, unless a time-out value was set by using Socket.ReceiveTimeout. If the time-out value was exceeded, the Receive call will throw a SocketException. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the Receive method will complete immediately and throw a SocketException. You can use the Available property to determine if data is available for reading. When Available is non-zero, retry the receive operation.
          /// @remarks If you are using a connection-oriented Socket, the Receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the Socket connection with the Shutdown method, and all available data has been received, the Receive method will complete immediately and return zero bytes.
          /// @remarks If you are using a connectionless Socket, Receive will read the first queued datagram from the destination address you specify in the Connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a SocketException is thrown.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 Receive(Array<byte>& buffer, SocketFlags socketFlags) {return this->Receive(buffer, 0, buffer.Length, socketFlags);}

          /// @brief Receives the specified number of bytes of data from a bound Socket into a receive buffer, using the specified SocketFlags.
          /// @param buffer An array of type Byte that is the storage location for the received data.
          /// @param size The number of bytes to receive.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @return int32 The number of bytes received.
          /// @exception ArgumentNullException bufer is null
          /// @exception ArgumentOutOfRangeException size is less than 0 or exceeds the size of the buffer.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call Receive from both connection-oriented and connectionless sockets.
          /// @remarks This overload only requires you to provide a receive buffer. The buffer offset defaults to 0, the size defaults to the length of the buffer parameter, and the SocketFlags value defaults to None.
          /// @remarks If you are using a connection-oriented protocol, you must either call Connect to establish a remote host connection, or Accept to accept an incoming connection prior to calling Receive. The Receive method will only read data that arrives from the remote host established in the Connect or Accept method. If you are using a connectionless protocol, you can also use the ReceiveFrom method. ReceiveFrom will allow you to receive data arriving from any host.
          /// @remarks If no data is available for reading, the Receive method will block until data is available, unless a time-out value was set by using Socket.ReceiveTimeout. If the time-out value was exceeded, the Receive call will throw a SocketException. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the Receive method will complete immediately and throw a SocketException. You can use the Available property to determine if data is available for reading. When Available is non-zero, retry the receive operation.
          /// @remarks If you are using a connection-oriented Socket, the Receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the Socket connection with the Shutdown method, and all available data has been received, the Receive method will complete immediately and return zero bytes.
          /// @remarks If you are using a connectionless Socket, Receive will read the first queued datagram from the destination address you specify in the Connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a SocketException is thrown.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 Receive(Array<byte>& buffer, int32 size, SocketFlags socketFlags) {return this->Receive(buffer, 0, size, socketFlags);}

          /// @brief Receives the specified number of bytes from a bound Socket into the specified offset position of the receive buffer, using the specified SocketFlags.
          /// @param buffer An array of type Byte that is the storage location for the received data.
          /// @param offset The location in buffer to store the received data.
          /// @param size The number of bytes to receive.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @return int32 The number of bytes received.
          /// @exception ArgumentNullException bufer is null
          /// @exception ArgumentOutOfRangeException offset is less than 0. -or- offset is greater than the length of buffer. -or- size is less than 0. -or- size is greater than the length of buffer minus the value of the offset parameter.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call Receive from both connection-oriented and connectionless sockets.
          /// @remarks This overload only requires you to provide a receive buffer. The buffer offset defaults to 0, the size defaults to the length of the buffer parameter, and the SocketFlags value defaults to None.
          /// @remarks If you are using a connection-oriented protocol, you must either call Connect to establish a remote host connection, or Accept to accept an incoming connection prior to calling Receive. The Receive method will only read data that arrives from the remote host established in the Connect or Accept method. If you are using a connectionless protocol, you can also use the ReceiveFrom method. ReceiveFrom will allow you to receive data arriving from any host.
          /// @remarks If no data is available for reading, the Receive method will block until data is available, unless a time-out value was set by using Socket.ReceiveTimeout. If the time-out value was exceeded, the Receive call will throw a SocketException. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the Receive method will complete immediately and throw a SocketException. You can use the Available property to determine if data is available for reading. When Available is non-zero, retry the receive operation.
          /// @remarks If you are using a connection-oriented Socket, the Receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the Socket connection with the Shutdown method, and all available data has been received, the Receive method will complete immediately and return zero bytes.
          /// @remarks If you are using a connectionless Socket, Receive will read the first queued datagram from the destination address you specify in the Connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a SocketException is thrown.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 Receive(Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags);

          /// @brief Receives the specified number of bytes from a bound Socket into the specified offset position of the receive buffer, using the specified SocketFlags.
          /// @param buffer An array of type Byte that is the storage location for the received data.
          /// @param offset The location in buffer to store the received data.
          /// @param size The number of bytes to receive.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @param errorCode A SocketError object that stores the socket error.
          /// @return int32 The number of bytes received.
          /// @exception ArgumentNullException bufer is null
          /// @exception ArgumentOutOfRangeException offset is less than 0. -or- offset is greater than the length of buffer. -or- size is less than 0. -or- size is greater than the length of buffer minus the value of the offset parameter.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call Receive from both connection-oriented and connectionless sockets.
          /// @remarks This overload only requires you to provide a receive buffer. The buffer offset defaults to 0, the size defaults to the length of the buffer parameter, and the SocketFlags value defaults to None.
          /// @remarks If you are using a connection-oriented protocol, you must either call Connect to establish a remote host connection, or Accept to accept an incoming connection prior to calling Receive. The Receive method will only read data that arrives from the remote host established in the Connect or Accept method. If you are using a connectionless protocol, you can also use the ReceiveFrom method. ReceiveFrom will allow you to receive data arriving from any host.
          /// @remarks If no data is available for reading, the Receive method will block until data is available, unless a time-out value was set by using Socket.ReceiveTimeout. If the time-out value was exceeded, the Receive call will throw a SocketException. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the Receive method will complete immediately and throw a SocketException. You can use the Available property to determine if data is available for reading. When Available is non-zero, retry the receive operation.
          /// @remarks If you are using a connection-oriented Socket, the Receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the Socket connection with the Shutdown method, and all available data has been received, the Receive method will complete immediately and return zero bytes.
          /// @remarks If you are using a connectionless Socket, Receive will read the first queued datagram from the destination address you specify in the Connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a SocketException is thrown.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 Receive(Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, SocketError& error);

          /// @brief Receives data from a bound Socket into a receive buffer.
          /// @param buffer An array of type Byte that is the storage location for the received data.
          /// @param endPoint: the remote host
          /// @return int32 The number of bytes received.
          /// @exception ArgumentNullException bufer is null
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call Receive from both connection-oriented and connectionless sockets.
          /// @remarks This overload only requires you to provide a receive buffer. The buffer offset defaults to 0, the size defaults to the length of the buffer parameter, and the SocketFlags value defaults to None.
          /// @remarks If you are using a connection-oriented protocol, you must either call Connect to establish a remote host connection, or Accept to accept an incoming connection prior to calling Receive. The Receive method will only read data that arrives from the remote host established in the Connect or Accept method. If you are using a connectionless protocol, you can also use the ReceiveFrom method. ReceiveFrom will allow you to receive data arriving from any host.
          /// @remarks If no data is available for reading, the Receive method will block until data is available, unless a time-out value was set by using Socket.ReceiveTimeout. If the time-out value was exceeded, the Receive call will throw a SocketException. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the Receive method will complete immediately and throw a SocketException. You can use the Available property to determine if data is available for reading. When Available is non-zero, retry the receive operation.
          /// @remarks If you are using a connection-oriented Socket, the Receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the Socket connection with the Shutdown method, and all available data has been received, the Receive method will complete immediately and return zero bytes.
          /// @remarks If you are using a connectionless Socket, Receive will read the first queued datagram from the destination address you specify in the Connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a SocketException is thrown.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 ReceiveFrom(Array<byte>& buffer, IPEndPoint& endPoint) {return this->ReceiveFrom(buffer, 0, buffer.Length, SocketFlags::None, endPoint);}

          /// @brief Receives data from a bound Socket into a receive buffer, using the specified SocketFlags.
          /// @param buffer An array of type Byte that is the storage location for the received data.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @param endPoint: the remote host
          /// @return int32 The number of bytes received.
          /// @exception ArgumentNullException bufer is null
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call Receive from both connection-oriented and connectionless sockets.
          /// @remarks This overload only requires you to provide a receive buffer. The buffer offset defaults to 0, the size defaults to the length of the buffer parameter, and the SocketFlags value defaults to None.
          /// @remarks If you are using a connection-oriented protocol, you must either call Connect to establish a remote host connection, or Accept to accept an incoming connection prior to calling Receive. The Receive method will only read data that arrives from the remote host established in the Connect or Accept method. If you are using a connectionless protocol, you can also use the ReceiveFrom method. ReceiveFrom will allow you to receive data arriving from any host.
          /// @remarks If no data is available for reading, the Receive method will block until data is available, unless a time-out value was set by using Socket.ReceiveTimeout. If the time-out value was exceeded, the Receive call will throw a SocketException. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the Receive method will complete immediately and throw a SocketException. You can use the Available property to determine if data is available for reading. When Available is non-zero, retry the receive operation.
          /// @remarks If you are using a connection-oriented Socket, the Receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the Socket connection with the Shutdown method, and all available data has been received, the Receive method will complete immediately and return zero bytes.
          /// @remarks If you are using a connectionless Socket, Receive will read the first queued datagram from the destination address you specify in the Connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a SocketException is thrown.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 ReceiveFrom(Array<byte>& buffer, SocketFlags socketFlags, IPEndPoint& endPoint) {return this->ReceiveFrom(buffer, 0, buffer.Length, socketFlags, endPoint);}

          /// @brief Receives the specified number of bytes of data from a bound Socket into a receive buffer, using the specified SocketFlags.
          /// @param buffer An array of type Byte that is the storage location for the received data.
          /// @param size The number of bytes to receive.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @param endPoint: the remote host
          /// @return int32 The number of bytes received.
          /// @exception ArgumentNullException bufer is null
          /// @exception ArgumentOutOfRangeException size is less than 0 or exceeds the size of the buffer.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call Receive from both connection-oriented and connectionless sockets.
          /// @remarks This overload only requires you to provide a receive buffer. The buffer offset defaults to 0, the size defaults to the length of the buffer parameter, and the SocketFlags value defaults to None.
          /// @remarks If you are using a connection-oriented protocol, you must either call Connect to establish a remote host connection, or Accept to accept an incoming connection prior to calling Receive. The Receive method will only read data that arrives from the remote host established in the Connect or Accept method. If you are using a connectionless protocol, you can also use the ReceiveFrom method. ReceiveFrom will allow you to receive data arriving from any host.
          /// @remarks If no data is available for reading, the Receive method will block until data is available, unless a time-out value was set by using Socket.ReceiveTimeout. If the time-out value was exceeded, the Receive call will throw a SocketException. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the Receive method will complete immediately and throw a SocketException. You can use the Available property to determine if data is available for reading. When Available is non-zero, retry the receive operation.
          /// @remarks If you are using a connection-oriented Socket, the Receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the Socket connection with the Shutdown method, and all available data has been received, the Receive method will complete immediately and return zero bytes.
          /// @remarks If you are using a connectionless Socket, Receive will read the first queued datagram from the destination address you specify in the Connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a SocketException is thrown.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 ReceiveFrom(Array<byte>& buffer, int32 size, SocketFlags socketFlags, IPEndPoint& endPoint) {return this->ReceiveFrom(buffer, 0, size, socketFlags, endPoint);}

          /// @brief Receives the specified number of bytes from a bound Socket into the specified offset position of the receive buffer, using the specified SocketFlags.
          /// @param buffer An array of type Byte that is the storage location for the received data.
          /// @param offset The location in buffer to store the received data.
          /// @param size The number of bytes to receive.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @param endPoint: the remote host
          /// @return int32 The number of bytes received.
          /// @exception ArgumentNullException bufer is null
          /// @exception ArgumentOutOfRangeException offset is less than 0. -or- offset is greater than the length of buffer. -or- size is less than 0. -or- size is greater than the length of buffer minus the value of the offset parameter.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks The Receive method reads data into the buffer parameter and returns the number of bytes successfully read. You can call Receive from both connection-oriented and connectionless sockets.
          /// @remarks This overload only requires you to provide a receive buffer. The buffer offset defaults to 0, the size defaults to the length of the buffer parameter, and the SocketFlags value defaults to None.
          /// @remarks If you are using a connection-oriented protocol, you must either call Connect to establish a remote host connection, or Accept to accept an incoming connection prior to calling Receive. The Receive method will only read data that arrives from the remote host established in the Connect or Accept method. If you are using a connectionless protocol, you can also use the ReceiveFrom method. ReceiveFrom will allow you to receive data arriving from any host.
          /// @remarks If no data is available for reading, the Receive method will block until data is available, unless a time-out value was set by using Socket.ReceiveTimeout. If the time-out value was exceeded, the Receive call will throw a SocketException. If you are in non-blocking mode, and there is no data available in the in the protocol stack buffer, the Receive method will complete immediately and throw a SocketException. You can use the Available property to determine if data is available for reading. When Available is non-zero, retry the receive operation.
          /// @remarks If you are using a connection-oriented Socket, the Receive method will read as much data as is available, up to the size of the buffer. If the remote host shuts down the Socket connection with the Shutdown method, and all available data has been received, the Receive method will complete immediately and return zero bytes.
          /// @remarks If you are using a connectionless Socket, Receive will read the first queued datagram from the destination address you specify in the Connect method. If the datagram you receive is larger than the size of the buffer parameter, buffer gets filled with the first part of the message, the excess data is lost and a SocketException is thrown.
          /// @note If you receive a SocketException, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 ReceiveFrom(Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, IPEndPoint& endPoint);

          /// @brief Determines the status of one or more sockets.
          /// @param checkRead An IList of Socket instances to check for readability.
          /// @param checkWrite An IList of Socket instances to check for writability.
          /// @param checkError An IList of Socket instances to check for errors.
          /// @param microseconds The time-out value, in microseconds. A -1 value indicates an infinite time-out.
          /// @return 0 if the timeout expired; otherwise, the total number of sockets returned in the lists.
          /// @exception ArgumentNullException The checkRead parameter is null or empty -and- The checkWrite parameter is null or empty -and- The checkError parameter is null or empty.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @remarks Select is a static method that determines the status of one or more Socket instances. You must place one or more sockets into an IList before you can use the Select method.
          /// @remarks Check for readability by calling Select with the IList as the checkRead parameter. To check your sockets for writability, use the checkWrite parameter. For detecting error conditions,
          /// @remarks use checkError. After calling Select, the IList will be filled with only those sockets that satisfy the conditions.
          /// @remarks If you are in a listening state, readability means that a call to Accept will succeed without blocking. If you have already accepted the connection,
          /// @remarks readability means that data is available for reading. In these cases, all receive operations will succeed without blocking. Readability can also indicate whether the remote Socket
          /// @remarks has shut down the connection; in that case a call to Receive will return immediately, with zero bytes returned.
          /// @remarks Select returns when at least one of the sockets of interest (the sockets in the checkRead, checkWrite, and checkError lists) meets its specified criteria,
          /// @remarks or the microseconds parameter is exceeded, whichever comes first. Setting microseconds to -1 specifies an infinite time-out.
          /// @remarks If you make a nonblocking call to Connect, writability means that you have connected successfully. If you already have a connection established, writability means that all send operations
          /// @remarks will succeed without blocking.
          /// @remarks If you have made a non-blocking call to Connect, the checkerror parameter identifies sockets that have not connected successfully.
          /// @note This method cannot detect certain kinds of connection problems, such as a broken network cable, or that the remote host was shut down ungracefully.
          /// @note You must attempt to send or receive data to detect these kinds of errors.
          /// @note If you receive a SocketException, use the SocketException::ErrorCode property to obtain the specific error code. After you have obtained this code,
          /// @note refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          static int32 Select(Collections::Generic::IList<Socket>& checkRead, Collections::Generic::IList<Socket>& checkWrite, Collections::Generic::IList<Socket>& checkError, int32 microseconds);

          /// @brief Sends data to a connected Socket.
          /// @param buffer An array of type Byte that contains the data to be sent.
          /// @return int32 The number of bytes sent to the Socket.
          /// @exception ArgumentNullException bufer is null
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Send synchronously sends data to the remote host specified in the Connect or Accept method and returns the number of bytes successfully sent. Send can be used for both connection-oriented and connectionless protocols.
          /// @remarks This overload requires a buffer that contains the data you want to send. The SocketFlags value defaults to 0, the buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer.
          /// @remarks If you are using a connectionless protocol, you must call Connect before calling this method, or Send will throw a SocketException. If you are using a connection-oriented protocol, you must either use Connect to establish a remote host connection, or use Accept to accept an incoming connection.
          /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the SendTo method. If you do not use the SendTo method, you will have to call Connect before each call to Send. You can use SendTo even after you have established a default remote host with Connect. You can also change the default remote host prior to calling Send by making another call to Connect.
          /// @remarks If you are using a connection-oriented protocol, Send will block until all of the bytes in the buffer are sent, unless a time-out was set by using Socket.SendTimeout. If the time-out value was exceeded, the Send call will throw a SocketException. In nonblocking mode, Send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
          /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 Send(const Array<byte>& buffer) {return this->Send(buffer, 0, buffer.Length, SocketFlags::None);}

          /// @brief Sends data to a connected Socket using the specified SocketFlags.
          /// @param buffer An array of type Byte that contains the data to be sent.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @return int32 The number of bytes sent to the Socket.
          /// @exception ArgumentNullException bufer is null
          /// @exception SocketException socketFlags is not a valid combination of values. -or- An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Send synchronously sends data to the remote host specified in the Connect or Accept method and returns the number of bytes successfully sent. Send can be used for both connection-oriented and connectionless protocols.
          /// @remarks This overload requires a buffer that contains the data you want to send. The SocketFlags value defaults to 0, the buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer.
          /// @remarks If you are using a connectionless protocol, you must call Connect before calling this method, or Send will throw a SocketException. If you are using a connection-oriented protocol, you must either use Connect to establish a remote host connection, or use Accept to accept an incoming connection.
          /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the SendTo method. If you do not use the SendTo method, you will have to call Connect before each call to Send. You can use SendTo even after you have established a default remote host with Connect. You can also change the default remote host prior to calling Send by making another call to Connect.
          /// @remarks If you are using a connection-oriented protocol, Send will block until all of the bytes in the buffer are sent, unless a time-out was set by using Socket.SendTimeout. If the time-out value was exceeded, the Send call will throw a SocketException. In nonblocking mode, Send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
          /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 Send(const Array<byte>& buffer, SocketFlags socketFlags) {return this->Send(buffer, 0, buffer.Length, socketFlags);}

          /// @brief Sends the specified number of bytes of data to a connected Socket, using the specified SocketFlags.
          /// @param buffer An array of type Byte that contains the data to be sent.
          /// @param size The number of bytes to send.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @return int32 The number of bytes sent to the Socket.
          /// @exception ArgumentNullException bufer is null
          /// @exception ArgumentOutOfRangeException size is less than 0 or exceeds the size of the buffer.
          /// @exception SocketException socketFlags is not a valid combination of values. -or- An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Send synchronously sends data to the remote host specified in the Connect or Accept method and returns the number of bytes successfully sent. Send can be used for both connection-oriented and connectionless protocols.
          /// @remarks This overload requires a buffer that contains the data you want to send. The SocketFlags value defaults to 0, the buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer.
          /// @remarks If you are using a connectionless protocol, you must call Connect before calling this method, or Send will throw a SocketException. If you are using a connection-oriented protocol, you must either use Connect to establish a remote host connection, or use Accept to accept an incoming connection.
          /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the SendTo method. If you do not use the SendTo method, you will have to call Connect before each call to Send. You can use SendTo even after you have established a default remote host with Connect. You can also change the default remote host prior to calling Send by making another call to Connect.
          /// @remarks If you are using a connection-oriented protocol, Send will block until all of the bytes in the buffer are sent, unless a time-out was set by using Socket.SendTimeout. If the time-out value was exceeded, the Send call will throw a SocketException. In nonblocking mode, Send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
          /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 Send(const Array<byte>& buffer, int32 size, SocketFlags socketFlags) {return this->Send(buffer, 0, size, socketFlags);}

          /// @brief Sends the specified number of bytes of data to a connected Socket, starting at the specified offset, and using the specified SocketFlags.
          /// @param buffer An array of type Byte that contains the data to be sent.
          /// @param offset TThe position in the data buffer at which to begin sending data.
          /// @param size The number of bytes to send.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @return int32 The number of bytes sent to the Socket.
          /// @exception ArgumentNullException bufer is null
          /// @exception ArgumentOutOfRangeException offset is less than 0. -or- offset is greater than the length of buffer. -or- size is less than 0. -or- size is greater than the length of buffer minus the value of the offset parameter.
          /// @exception SocketException socketFlags is not a valid combination of values. -or- An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Send synchronously sends data to the remote host specified in the Connect or Accept method and returns the number of bytes successfully sent. Send can be used for both connection-oriented and connectionless protocols.
          /// @remarks This overload requires a buffer that contains the data you want to send. The SocketFlags value defaults to 0, the buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer.
          /// @remarks If you are using a connectionless protocol, you must call Connect before calling this method, or Send will throw a SocketException. If you are using a connection-oriented protocol, you must either use Connect to establish a remote host connection, or use Accept to accept an incoming connection.
          /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the SendTo method. If you do not use the SendTo method, you will have to call Connect before each call to Send. You can use SendTo even after you have established a default remote host with Connect. You can also change the default remote host prior to calling Send by making another call to Connect.
          /// @remarks If you are using a connection-oriented protocol, Send will block until all of the bytes in the buffer are sent, unless a time-out was set by using Socket.SendTimeout. If the time-out value was exceeded, the Send call will throw a SocketException. In nonblocking mode, Send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
          /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 Send(const Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags);

          /// @brief Sends the specified number of bytes of data to a connected Socket, starting at the specified offset, and using the specified SocketFlags.
          /// @param buffer An array of type Byte that contains the data to be sent.
          /// @param offset TThe position in the data buffer at which to begin sending data.
          /// @param size The number of bytes to send.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @param errorCode A SocketError object that stores the socket error.
          /// @return int32 The number of bytes sent to the Socket.
          /// @exception ArgumentNullException bufer is null
          /// @exception ArgumentOutOfRangeException offset is less than 0. -or- offset is greater than the length of buffer. -or- size is less than 0. -or- size is greater than the length of buffer minus the value of the offset parameter.
          /// @exception SocketException socketFlags is not a valid combination of values. -or- An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Send synchronously sends data to the remote host specified in the Connect or Accept method and returns the number of bytes successfully sent. Send can be used for both connection-oriented and connectionless protocols.
          /// @remarks This overload requires a buffer that contains the data you want to send. The SocketFlags value defaults to 0, the buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer.
          /// @remarks If you are using a connectionless protocol, you must call Connect before calling this method, or Send will throw a SocketException. If you are using a connection-oriented protocol, you must either use Connect to establish a remote host connection, or use Accept to accept an incoming connection.
          /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the SendTo method. If you do not use the SendTo method, you will have to call Connect before each call to Send. You can use SendTo even after you have established a default remote host with Connect. You can also change the default remote host prior to calling Send by making another call to Connect.
          /// @remarks If you are using a connection-oriented protocol, Send will block until all of the bytes in the buffer are sent, unless a time-out was set by using Socket.SendTimeout. If the time-out value was exceeded, the Send call will throw a SocketException. In nonblocking mode, Send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
          /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 Send(const Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, SocketError& errorCode);

          /// @brief Sends data to a connected Socket.
          /// @param buffer An array of type Byte that contains the data to be sent.
          /// @param endPoint: the remote host
          /// @return int32 The number of bytes sent to the Socket.
          /// @exception ArgumentNullException bufer is null
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Send synchronously sends data to the remote host specified in the Connect or Accept method and returns the number of bytes successfully sent. Send can be used for both connection-oriented and connectionless protocols.
          /// @remarks This overload requires a buffer that contains the data you want to send. The SocketFlags value defaults to 0, the buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer.
          /// @remarks If you are using a connectionless protocol, you must call Connect before calling this method, or Send will throw a SocketException. If you are using a connection-oriented protocol, you must either use Connect to establish a remote host connection, or use Accept to accept an incoming connection.
          /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the SendTo method. If you do not use the SendTo method, you will have to call Connect before each call to Send. You can use SendTo even after you have established a default remote host with Connect. You can also change the default remote host prior to calling Send by making another call to Connect.
          /// @remarks If you are using a connection-oriented protocol, Send will block until all of the bytes in the buffer are sent, unless a time-out was set by using Socket.SendTimeout. If the time-out value was exceeded, the Send call will throw a SocketException. In nonblocking mode, Send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
          /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 SendTo(const Array<byte>& buffer, const IPEndPoint& endPoint) {return this->SendTo(buffer, 0, buffer.Length, SocketFlags::None, endPoint);}

          /// @brief Sends data to a connected Socket using the specified SocketFlags.
          /// @param buffer An array of type Byte that contains the data to be sent.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @param endPoint: the remote host
          /// @return int32 The number of bytes sent to the Socket.
          /// @exception ArgumentNullException bufer is null
          /// @exception SocketException socketFlags is not a valid combination of values. -or- An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Send synchronously sends data to the remote host specified in the Connect or Accept method and returns the number of bytes successfully sent. Send can be used for both connection-oriented and connectionless protocols.
          /// @remarks This overload requires a buffer that contains the data you want to send. The SocketFlags value defaults to 0, the buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer.
          /// @remarks If you are using a connectionless protocol, you must call Connect before calling this method, or Send will throw a SocketException. If you are using a connection-oriented protocol, you must either use Connect to establish a remote host connection, or use Accept to accept an incoming connection.
          /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the SendTo method. If you do not use the SendTo method, you will have to call Connect before each call to Send. You can use SendTo even after you have established a default remote host with Connect. You can also change the default remote host prior to calling Send by making another call to Connect.
          /// @remarks If you are using a connection-oriented protocol, Send will block until all of the bytes in the buffer are sent, unless a time-out was set by using Socket.SendTimeout. If the time-out value was exceeded, the Send call will throw a SocketException. In nonblocking mode, Send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
          /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 SendTo(const Array<byte>& buffer, SocketFlags socketFlags, const IPEndPoint& endPoint) {return this->SendTo(buffer, 0, buffer.Length, socketFlags, endPoint);}

          /// @brief Sends the specified number of bytes of data to a connected Socket, using the specified SocketFlags.
          /// @param buffer An array of type Byte that contains the data to be sent.
          /// @param size The number of bytes to send.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @param endPoint: the remote host
          /// @return int32 The number of bytes sent to the Socket.
          /// @exception ArgumentNullException bufer is null
          /// @exception ArgumentOutOfRangeException size is less than 0 or exceeds the size of the buffer.
          /// @exception SocketException socketFlags is not a valid combination of values. -or- An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Send synchronously sends data to the remote host specified in the Connect or Accept method and returns the number of bytes successfully sent. Send can be used for both connection-oriented and connectionless protocols.
          /// @remarks This overload requires a buffer that contains the data you want to send. The SocketFlags value defaults to 0, the buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer.
          /// @remarks If you are using a connectionless protocol, you must call Connect before calling this method, or Send will throw a SocketException. If you are using a connection-oriented protocol, you must either use Connect to establish a remote host connection, or use Accept to accept an incoming connection.
          /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the SendTo method. If you do not use the SendTo method, you will have to call Connect before each call to Send. You can use SendTo even after you have established a default remote host with Connect. You can also change the default remote host prior to calling Send by making another call to Connect.
          /// @remarks If you are using a connection-oriented protocol, Send will block until all of the bytes in the buffer are sent, unless a time-out was set by using Socket.SendTimeout. If the time-out value was exceeded, the Send call will throw a SocketException. In nonblocking mode, Send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
          /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 SendTo(const Array<byte>& buffer, int32 size, SocketFlags socketFlags, const IPEndPoint& endPoint) {return this->SendTo(buffer, 0, size, socketFlags, endPoint);}

          /// @brief Sends the specified number of bytes of data to a connected Socket, starting at the specified offset, and using the specified SocketFlags.
          /// @param buffer An array of type Byte that contains the data to be sent.
          /// @param offset TThe position in the data buffer at which to begin sending data.
          /// @param size The number of bytes to send.
          /// @param socketFlags A bitwise combination of the SocketFlags values.
          /// @param endPoint: the remote host
          /// @return int32 The number of bytes sent to the Socket.
          /// @exception ArgumentNullException bufer is null
          /// @exception ArgumentOutOfRangeException offset is less than 0. -or- offset is greater than the length of buffer. -or- size is less than 0. -or- size is greater than the length of buffer minus the value of the offset parameter.
          /// @exception SocketException socketFlags is not a valid combination of values. -or- An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks Send synchronously sends data to the remote host specified in the Connect or Accept method and returns the number of bytes successfully sent. Send can be used for both connection-oriented and connectionless protocols.
          /// @remarks This overload requires a buffer that contains the data you want to send. The SocketFlags value defaults to 0, the buffer offset defaults to 0, and the number of bytes to send defaults to the size of the buffer.
          /// @remarks If you are using a connectionless protocol, you must call Connect before calling this method, or Send will throw a SocketException. If you are using a connection-oriented protocol, you must either use Connect to establish a remote host connection, or use Accept to accept an incoming connection.
          /// @remarks If you are using a connectionless protocol and plan to send data to several different hosts, you should use the SendTo method. If you do not use the SendTo method, you will have to call Connect before each call to Send. You can use SendTo even after you have established a default remote host with Connect. You can also change the default remote host prior to calling Send by making another call to Connect.
          /// @remarks If you are using a connection-oriented protocol, Send will block until all of the bytes in the buffer are sent, unless a time-out was set by using Socket.SendTimeout. If the time-out value was exceeded, the Send call will throw a SocketException. In nonblocking mode, Send may complete successfully even if it sends less than the number of bytes in the buffer. It is your application's responsibility to keep track of the number of bytes sent and to retry the operation until the application sends the bytes in the buffer. There is also no guarantee that the data you send will appear on the network immediately. To increase network efficiency, the underlying system may delay transmission until a significant amount of outgoing data is collected. A successful completion of the Send method means that the underlying system has had room to buffer your data for a network send.
          /// @note The successful completion of a send does not indicate that the data was successfully delivered. If no buffer space is available within the transport system to hold the data to be transmitted, send will block unless the socket has been placed in nonblocking mode.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          int32 SendTo(const Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, const IPEndPoint& endPoint);

          /// @brief Sets the specified Socket option to the specified Boolean value.
          /// @param socketOptionLevel One of the SocketOptionLevel values.
          /// @param socketOptionName One of the SocketOptionName values.
          /// @param optionValue The value of the option, represented as a Boolean.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @remarks Socket options determine the behavior of the current Socket. Set optionValue to true to enable the option, or to false to disable the option.
          /// @remarks Socket options are grouped by level of protocol support.
          /// @remarks Listed below are the various Socket options that can be set using this overload. These options are grouped by the appropriate SocketOptionLevel value. If you intend to set any of these options, be sure to use the appropriate SocketOptionLevel value for the optionLevel parameter. The option you choose to set must be specified in the optionName parameter. If you want to get the current value of any of the options listed, use the GetSocketOption method.
          ///  - SocketOptionLevelSocket options that can be set using this overload:
          ///    - SocketOptionNameAcceptConnection
          ///    - SocketOptionNameBroadcast
          ///    - SocketOptionNameDontLinger
          ///    - SocketOptionNameDebug
          ///    - SocketOptionNameKeepAlive
          ///    - SocketOptionNameOutOfBandInline
          ///    - SocketOptionNameReuseAddress
          ///  - SocketOptionLevelIP options that can be set using this overload:
          ///    - SocketOptionNameHeaderIncluded
          ///    - SocketOptionNameMulticastLoopback
          ///    - SocketOptionNameUseLoopback
          ///  - SocketOptionLevelTcp options that can be set using this overload:
          ///    - ocketOptionNameBsdUrgent
          ///    - SocketOptionNameExpedited
          ///    - SocketOptionNameNoDelay
          ///  - SocketOptionLevelUdp options that can be set using this overload :
          ///    - SocketOptionNameNoChecksum
          /// @remarks <br />For more information on these options, refer to the SocketOptionName enumeration.
          /// @note If you receive a SocketException exception, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          void SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, bool optionValue);

          /// @brief Sets the specified Socket option to the specified value, represented as a byte array.
          /// @param socketOptionLevel One of the SocketOptionLevel values.
          /// @param socketOptionName One of the SocketOptionName values.
          /// @param optionValue An array of type Byte that represents the value of the option.
          /// @exception ArgumentNullException optionValue is null.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @remarks Socket options determine the behavior of the current Socket. Use this overload to set those Socket options that require a byte array as an option value.
          /// @note If you receive a SocketException, use the SocketException::ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          /// @note You must call the Bind method before using SocketOptionNameAddMembership as the socketOptionName parameter.
          void SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, const Array<byte>& optionValue);

          /// @brief Sets the specified Socket option to the specified integer value.
          /// @param socketOptionLevel One of the SocketOptionLevel values.
          /// @param socketOptionName One of the SocketOptionName values.
          /// @param optionValue A value of the option.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @remarks Socket options determine the behavior of the current Socket. For an option with a Boolean data type, specify a nonzero value to enable the option, and a zero value to disable the option. For an option with an integer data type, specify the appropriate value. Socket options are grouped by level of protocol support.
          /// @remarks Listed below are the various Socket options that can be set using this overload. These options are grouped by the appropriate SocketOptionLevel. If you intend to set any of these options, be sure to use the appropriate SocketOptionLevel for the optionLevel parameter. The option you choose to set must be specified in the optionName parameter. If you want to get the current value of any of the options listed, use the GetSocketOption method.
          /// - SocketOptionLevelSocket options that can be set using this overload:
          ///   - SocketOptionNameBroadcast
          ///   - SocketOptionNameDontLinger
          ///   - SocketOptionNameDebug
          ///   - SocketOptionNameError
          ///   - SocketOptionNameKeepAlive
          ///   - SocketOptionNameOutOfBandInline
          ///   - SocketOptionNameReceiveBuffer
          ///   - SocketOptionNameReceiveTimeout
          ///   - SocketOptionNameReuseAddress
          ///   - SocketOptionNameSendBuffer
          ///   - SocketOptionNameSendTimeout
          ///   - SocketOptionNameType
          /// - SocketOptionLevelIP options that can be set using this overload:
          ///   - SocketOptionNameHeaderIncluded
          ///   - SocketOptionNameIPOptions
          ///   - SocketOptionNameIpTimeToLive
          ///   - SocketOptionNameMulticastInterface
          ///   - SocketOptionNameMulticastLoopback
          ///   - SocketOptionNameMulticastTimeToLive
          ///   - SocketOptionNameUseLoopback
          /// - SocketOptionLevelTcp options that can be set using this overload:
          ///   - SocketOptionNameBsdUrgent
          ///   - SocketOptionNameExpedited
          ///   - SocketOptionNameNoDelay
          /// - SocketOptionLevelUdp options that can be set using this overload:
          ///   - SocketOptionNameChecksumCoverage
          ///   - SocketOptionNameNoChecksum
          /// - SocketOptionLevelIPv6 options that can be set using this overload:
          ///   - SocketOptionNameHopLimit
          /// @remarks <br />For more information on these options, refer to the SocketOptionName enumeration.
          /// @note If you receive a SocketException exception, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          void SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, int32 optionValue);

          /// @brief Sets the specified Socket option to the specified value, represented as an object.
          /// @param socketOptionLevel One of the SocketOptionLevel values.
          /// @param socketOptionName One of the SocketOptionName values.
          /// @param optionValue A LingerOption or MulticastOption that contains the value of the option.
          /// @exception ArgumentNullException optionValue is null.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @remarks Socket options determine the behavior of the current Socket. Use this overload to set the SocketOptionNameLinger, SocketOptionNameAddMembership, and SocketOptionNameDropMembership Socket options. For the SocketOptionNameLinger option, use SocketOptionLevelSocket for the socketOptionLevel parameter. For SocketOptionNameAddMembership and SocketOptionNameDropMembership, use SocketOptionLevelIP. If you want to get the current value of any of the options listed above, use the GetSocketOption method.
          /// @note If you receive a SocketException, use the SocketException::ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          /// @note You must call the Bind method before using SocketOptionNameAddMembership as the socketOptionName parameter.
          void SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, const Object& optionValue);

          /// @brief Disables sends and receives on a Socket.
          /// @param how One of the SocketShutdown values that specifies the operation that will no longer be allowed.
          /// @exception SocketException An error occurred when attempting to access the socket. See the Remarks section for more information.
          /// @exception ObjectDisposedException The Socket has been closed.
          /// @remarks When using a connection-oriented Socket, always call the Shutdown method before closing the Socket. This ensures that all data is sent and received on the connected socket before it is closed.
          /// @remarks Call the Close method to free all managed and unmanaged resources associated with the Socket. Do not attempt to reuse the Socket after closing.
          /// @remarks The following table shows the SocketShutdown enumeration values that are valid for the how parameter.
          /// | Value                 | Description                                        |
          /// |-----------------------|----------------------------------------------------|
          /// | SocketShutdownSend    | Disable sending on this Socket.                    |
          /// | SocketShutdownReceive | Disable receiving on this Socket.                  |
          /// | SocketShutdownBoth    | Disable both sending and receiving on this Socket. |
          /// @remarks Setting how to Send specifies that subsequent calls to Send are not allowed. If you are using a connectionless Socket, specifying Send will have no effect.
          /// @remarks Setting how to Receive specifies that subsequent calls to Receive are not allowed. This has no effect on lower protocol layers. If you are using a connection-oriented protocol, the connection is terminated if either of the following conditions exist after a call to Shutdown :
          /// @remarks Data is in the incoming network buffer waiting to be received.
          /// @remarks More data has arrived.
          /// @remarks If you are using a connectionless protocol, datagrams are accepted and queued. However, if no buffer space is available for additional incoming datagrams, they will be discarded and no error will be returned to the sender. Using Shutdown on a connectionless Socket is not recommended.
          /// @remarks Setting how to Both disables both sends and receives as described above.
          /// @note If you receive a SocketException when calling the Shutdown method, use the SocketException.ErrorCode property to obtain the specific error code. After you have obtained this code, refer to the Windows Sockets version 2 API error code documentation in the MSDN library for a detailed description of the error.
          /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
          void Shutdown(SocketShutdown how);

        private :
          Socket(intptr socket);
          void InnerBind();
          void InnerConnect();
          int32 GetAvailable() const;
          bool GetBlocking() const;
          bool GetDontFragment() const {return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::DontFragment).ChangeType<Int32>().ToObject() == 1;}
          bool GetDualMode() const {return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::IPv6Only).ChangeType<Int32>().ToObject() == 0;}
          bool GetEnableBroadcast() const {return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Broadcast).ChangeType<Int32>().ToObject() == 1;}
          bool GetExclusiveAddressUse() const {return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ExclusiveAddressUse).ChangeType<Int32>().ToObject() == 1;}
          LingerOption GetLingerState() const {return LingerOption(GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Linger).ChangeType<LingerOption>().ToObject());}
          const EndPoint& GetLocalEndPoint() const;
          bool GetMulticastLoopback() const {return GetSocketOption(SocketOptionLevel::IP, SocketOptionName::MulticastLoopback).ChangeType<Int32>().ToObject() == 1;}
          bool GetNoDelay() const {return GetSocketOption(SocketOptionLevel::Tcp, SocketOptionName::NoDelay).ChangeType<Int32>().ToObject() == 1;}
          int32 GetReceiveBufferSize() const {return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveBuffer).ChangeType<Int32>().ToObject();}
          int32 GetReceiveTimeout() const {return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout).ChangeType<Int32>().ToObject();}
          const EndPoint& GetRemoteEndPoint() const;
          int32 GetSendBufferSize() const {return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendBuffer).ChangeType<Int32>().ToObject();}
          int32 GetSendTimeout() const {return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout).ChangeType<Int32>().ToObject();}
          int32 GetTtl() const {return GetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout).ChangeType<Int32>().ToObject();}
          void SetBlocking(bool blocking);
          void SetDontFragment(bool dontFragment);
          void SetDualMode(bool dualMode);
          void SetEnableBroadcast(bool enableBroadcast);
          void SetExclusiveAddressUse(bool exclusiveAddressUse);
          void SetLingerState(const LingerOption& lingerOption);
          void SetMulticastLoopback(bool multicastLoopback);
          void SetNoDelay(bool noDelay);
          void SetReceiveBufferSize(int32 bufferSize);
          void SetReceiveTimeout(int32 value);
          void SetSendBufferSize(int32 bufferSize);
          void SetSendTimeout(int32 timeout);
          void SetTtl(int32 ttl);

          struct SocketData {
            intptr socket = 0;
            System::Net::Sockets::AddressFamily addressFamily = System::Net::Sockets::AddressFamily::Unspecified;
            System::Net::Sockets::ProtocolType protocolType = System::Net::Sockets::ProtocolType::Unspecified;
            System::Net::Sockets::SocketType socketType = System::Net::Sockets::SocketType::Unknown;
            refptr<EndPoint> localEndPoint;
            refptr<EndPoint> remoteEndPoint;
            bool connected = false;
            bool listening = false;
            bool nonBlocking = false;
            bool bound = false;
          };
          refptr<SocketData> data = ref_new<SocketData>();

        };
      }
    }
  }
}

using namespace Switch;
