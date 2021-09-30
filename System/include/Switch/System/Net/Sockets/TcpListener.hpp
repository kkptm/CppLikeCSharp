/// @file
/// @brief Contains Switch::System::Net::Sockets::TcpListener class.
#pragma once

#include <Switch/System/ApplicationException.hpp>
#include "../../../SystemExport.hpp"
#include "../IPAddress.hpp"
#include "../IPEndPoint.hpp"
#include "Socket.hpp"
#include "TcpClient.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief Listens for connections from TCP network clients.
        /// @remarks The TcpListener class provides simple methods that listen for and accept incoming connection requests in blocking synchronous mode. You can use either
        /// @remarks a TcpClient or a Socket to connect with a TcpListener. Create a TcpListener using an IPEndPoint, a Local IP address and port number, or just a port number.
        /// @remarks Specify Any for the local IP address and 0 for the local port number if you want the underlying service provider to assign those values for you.
        /// @remarks If you choose to do this, you can use the LocalEndpoint property to identify the assigned information, after the socket has connected.
        /// @remarks Use the Start method to begin listening for incoming connection requests. Start will queue incoming connections until you either call the Stop method or
        /// @remarks it has queued MaxConnections. Use either AcceptSocket or AcceptTcpClient to pull a connection from the incoming connection request queue. These two methods will block.
        /// @remarks If you want to avoid blocking, you can use the Pending method first to determine if connection requests are available in the queue.
        /// @remarks Call the Stop method to close the TcpListener.
        /// @note The Stop method does not close any accepted connections. You are responsible for closing these separately.
        /// @note The 0 for local port functionality is not available.
        /// @par Library
        /// Switch.System
        class system_export_ TcpListener : public Object {
        public:
          /// @brief Initializes a new instance of the TcpListener class with the specified local endpoint.
          /// @param ipEndPoint An IPEndPoint that represents the local endpoint to which to bind the listener Socket.
          /// @exception ArgumentNullException
          /// @remarks This constructor allows you to specify the local IP address and port number on which to listen for incoming connection attempts.
          /// @remarks Before using this constructor, you must create an IPEndPoint using the desired local IP address and port number. Pass this IPEndPoint to the constructor
          /// @remarks as the localEP parameter.
          /// @remarks If you do not care which local address is assigned, you can create an IPEndPoint using IPAddress::Any as the address parameter, and the underlying service
          /// @remarks provider will assign the most appropriate network address. This might help simplify your application if you have multiple network interfaces.
          /// @remarks If you do not care which local port is used, you can create an IPEndPoint using 0 for the port number. In this case, the service provider will assign an
          /// @remarks available port number between 1024 and 5000. If you use this approach, you can discover what local network address and port number has been assigned
          /// @remarks by using the LocalEndpoint property.
          /// @remarks Call the Start method to begin listening for incoming connection attempts.
          /// @note The 0 for local port functionality is not available.
          TcpListener(const IPEndPoint& ipEndPoint);

          /// Initializes a new instance of the TcpListener class that listens for incoming connection attempts on the specified local IP address and port number.
          /// @param ipAddress An IPAddress that represents the local IP address.
          /// @param port The port on which to listen for incoming connection attempts.
          /// @exception ArgumentNullException
          /// @exception ArgumentOutOfRangeException
          /// @remarks This constructor allows you to specify the local IP address and port number on which to listen for incoming connection attempts.
          /// @remarks Before calling this constructor you must first create an IPAddress using the desired local address. Pass this IPAddress to the constructor as the ipAddress parameter.
          /// @remarks If you do not care which local address is assigned, specify IPAddress::Any for the localaddr parameter, and the underlying service provider
          /// @remarks will assign the most appropriate network address. This might help simplify your application if you have multiple network interfaces. If you do not care which
          /// @remarks local port is used, you can specify 0 for the port number. In this case, the service provider will assign an available port number between 1024 and 5000.
          /// @remarks If you use this approach, you can discover what local network address and port number has been assigned by using the LocalEndpoint property.
          /// @remarks Call the Start method to begin listening for incoming connection attempts.
          /// @note The 0 for local port functionality is not available.
          TcpListener(const IPAddress& ipAddress, int32 port) : TcpListener(IPEndPoint(ipAddress, port)) {}

          /// @cond
          TcpListener(const TcpListener& tcpListener) : data(tcpListener.data) {}
          /// @endcond

          /// @brief Gets a bool value that specifies whether the TcpListener allows only one underlying socket to listen to a specific port.
          /// @return true if the TcpListener allows only one TcpListener to listen to a specific port; otherwise, false. .
          /// @exception InvalidOperationException The TcpListener has been started. Call the Stop() method and then set the exclusiveAddressUse property.
          /// @exception SocketException An error occurred when attempting to access the underlying socket.
          /// @exception ObjectDisposedException The underlying Socket has been closed.
          /// @remarks By default, multiple listeners can listen to a specific port. However, only one of the listeners can perform operations on the network traffic sent to the port.
          /// @remarks If more than one listener attempts to bind to a particular port, then the one with the more specific IP address handles the network traffic sent to that port.
          /// @remarks You can use the exclusiveAddressUse property to prevent multiple listeners from listening to a specific port.
          /// @remarks Set this property before calling Start, or call the Stop method and then set this property.
          /// @note Not available on MacOs/Linux/Android
          property_<bool> ExclusiveAddressUse {
            get_ {return this->data->serverSocket.ExclusiveAddressUse(); },
            set_ {
              if (this->data->active)
                throw ApplicationException(caller_); // tcplistener must be stopped

              this->data->serverSocket.ExclusiveAddressUse = value;
            }
          };

          /// @brief Gets the underlying EndPoint of the current TcpListener.
          /// @return The EndPoint to which the Socket is bound.
          /// @remarks You can use the LocalEndpoint property to identify the local network interface and port number being used to listen for incoming client connection requests,
          /// @remarks after a socket connection has been made. You must first cast this EndPoint to an IPEndPoint. You can then call the IPEndPoint::Address property to retrieve
          /// @remarks the local IP address, and the IPEndPoint::Port property to retrieve the local port number.
          property_<const EndPoint&, readonly_> LocalEndPoint {
            get_->const EndPoint& { return this->data->serverSocket.LocalEndPoint(); }
          };

          /// @brief Gets the underlying network Socket.
          /// @return The underlying Socket.
          /// @remarks TcpListener creates a Socket to listen for incoming client connection requests. Classes deriving from TcpListener can use this property to get this Socket.
          /// @remarks Use the underlying Socket returned by the Server property if you require access beyond that which TcpListener provides.
          /// @note The Server property only returns the Socket used to listen for incoming client connection requests. Use the AcceptSocket method to accept a pending connection
          /// @note request and obtain a Socket for sending and receiving data. You can also use the AcceptTcpClient method to accept a pending connection request and obtain a
          /// @note TcpClient for sending and receiving data.
          property_<Socket, readonly_> Server {
            get_ {return this->data->serverSocket; }
          };

          /// @brief Creates a new TcpListener instance to listen on the specified port.
          /// @param port The port on which to listen for incoming connection attempts.
          /// @return TcpListener A new TcpListener instance to listen on the specified port.
          static TcpListener Create(int32 port) { return TcpListener(IPAddress::Any, port); }

          /// @brief Accepts a pending connection request.
          /// @return A Socket used to send and receive data.
          /// @exception InvalidOperationException The listener has not been started with a call to Start.
          /// @remarks AcceptSocket is a blocking method that returns a Socket that you can use to send and receive data. If you want to avoid blocking, use the Pending method
          /// @remarks to determine if connection requests are available in the incoming connection queue.
          /// @remarks The Socket returned is initialized with the IP address and port number of the remote host.
          /// @remarks You can use any of the Send and Receive methods available in the Socket class to communicate with the remote host. When you are finished using the Socket,
          /// @remarks be sure to call its Close method. If your application is relatively simple, consider using the AcceptTcpClient method rather than the AcceptSocket method.
          /// @remarks TcpClient provides you with simple methods for sending and receiving data over a network in blocking synchronous mode.
          Socket AcceptSocket();

          /// @brief Accepts a pending connection request.
          /// @return A TcpClient used to send and receive data.
          /// @exception InvalidOperationException The listener has not been started with a call to Start.
          /// @exception SocketException
          /// @remarks AcceptTcpClient is a blocking method that returns a TcpClient that you can use to send and receive data. Use the Pending method to determine if connection
          /// @remarks requests are available in the incoming connection queue if you want to avoid blocking.
          /// @remarks Use the TcpClient::GetStream method to obtain the underlying NetworkStream of the returned TcpClient. The NetworkStream will provide you with methods for sending
          /// @remarks and receiving with the remote host. When you are through with the TcpClient, be sure to call its Close method. If you want greater flexibility than a TcpClient
          /// @remarks offers, consider using AcceptSocket.
          TcpClient AcceptTcpClient();

          /// @brief Starts listening for incoming connection requests.
          /// @exception SocketException
          /// @remarks The Start method initializes the underlying Socket, binds it to a local endpoint, and listens for incoming connection attempts. If a connection request is received,
          /// @remarks the Start method will queue the request and continue listening for additional requests until you call the Stop method. If TcpListener receives a connection request
          /// @remarks after it has already queued the maximum number of connections, it will throw a SocketException on the client.
          /// @remarks To remove a connection from the incoming connection queue, use either the AcceptTcpClient method or the AcceptSocket method. The AcceptTcpClient method will remove
          /// @remarks a connection from the queue and return a TcpClient that you can use to send and receive data. The AcceptSocket method will return a Socket that you can use to do
          /// @remarks the same. If your application only requires synchronous I/O, use AcceptTcpClient. For more detailed behavioral control, use AcceptSocket. Both of these methods block
          /// @remarks until a connection request is available in the queue.
          /// @remarks Use the Stop method to close the TcpListener and stop listening. You are responsible for closing your accepted connections separately.
          void Start();

          /// @brief Starts listening for incoming connection requests with a maximum number of pending connection.
          /// @param backlog The maximum length of the pending connections queue.
          /// @exception SocketException An error occurred while accessing the socket. See the Remarks section for more information.
          /// @exception ArgumentOutOfRangeException The backlog parameter is less than zero or exceeds the maximum number of permitted connections.
          /// @exception InvalidOperationException The underlying Socket is null.
          /// @remarks The Start method initializes the underlying Socket, binds it to a local endpoint, and listens for incoming connection attempts. If a connection request is received,
          /// @remarks Start will queue the request and continue listening for additional requests until you call the Stop method. If TcpListener receives a connection request after it
          /// @remarks has already queued the maximum number of connections it will throw a SocketException on the client.
          /// @remarks To remove a connection from the incoming connection queue, use either the AcceptTcpClient method or the AcceptSocket method. The AcceptTcpClient method will remove
          /// @remarks a connection from the queue and return a TcpClient that you can use to send and receive data. The AcceptSocket method will return a Socket that you can use to do
          /// @remarks the same. If your application only requires synchronous I/O, use the AcceptTcpClient. For more detailed behavioral control, use AcceptSocket method. Both of these
          /// @remarks methods block until a connection request is available in the queue.
          /// @remarks Use the Stop method to close the TcpListener and stop listening. You are responsible for closing your accepted connections separately.
          void Start(int32 backlog);

          /// @brief Closes the listener.
          /// @exception SocketException
          /// @remarks Stop closes the listener. Any unaccepted connection requests in the queue will be lost. Remote hosts waiting for a connection to be accepted will throw
          /// @remarks a SocketException. You are responsible for closing your accepted connections separately.
          /// @note The Stop method also closes the underlying Socket, and creates a new Socket for the TcpListener. If you set any properties on the underlying Socket prior
          /// @note to calling the Stop method, those properties will not carry over to the new Socket.
          void Stop();

          /// @brief Determines if there are pending connection requests.
          /// @return true if connections are pending; otherwise, false.
          /// @exception InvalidOperationException The listener has not been started with a call to Start.
          /// @remarks This non-blocking method determines if there are any pending connection requests. Because the AcceptSocket and AcceptTcpClient methods block execution until
          /// @remarks the Start method has queued an incoming connection request, the Pending method can be used to determine if connections are available before attempting to accept them.
          bool Pending();

        protected:
          /// @brief Gets a value that indicates whether TcpListener is actively listening for client connections.
          /// @return true if TcpListener is actively listening; otherwise, false.
          /// @remarks Classes deriving from TcpListener can use this property to determine if the Socket is currently listening for incoming connection attempts.
          /// @remarks The Active property can be used to avoid redundant Start attempts.
          property_<bool, readonly_> Active {
            get_ {return this->data->active; }
          };

        private:
          struct TcpListenerData {
            IPEndPoint serverIPEndPoint;
            Socket serverSocket;
            bool active = false;
          };
          refptr<TcpListenerData> data = ref_new<TcpListenerData>();
        };
      }
    }
  }
}







using namespace Switch;
