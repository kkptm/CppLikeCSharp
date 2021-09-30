/// @file
/// @brief Contains Switch::System::Net::Sockets::SocketError enum.
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
        /// @brief Defines error codes for the Socket class.
        /// @par Library
        /// Switch.System
        enum class SocketError {
          /// @brief An unspecified error occurred
          SockError = -1,
          /// @brief Operation successful
          Success = 0,
          /// @brief The overlapped operation was aborted due to the closure of the socket
          OperationAborted = 995,
          /// @brief The application has initiated an overlapped operation that cannot be completed immediately
          IOPending = 997,
          /// @brief A blocking call was canceled
          Interrupted = 10004,
          /// @brief Access denied
          AccessDenied = 10013,
          /// @brief Invalid pointer address
          Fault = 10014,
          /// @brief Invalid argument
          InvalidArgument = 10022,
          /// @brief Too many sockets opened
          TooManyOpenSockets = 10024,
          /// @brief An operation on a nonblocking socket cannot be completed immediately
          WouldBlock = 10035,
          /// @brief A blocking operation is in progress
          InProgress = 10036,
          /// @brief The nonblocking socket has an operation in progress
          AlreadyInProgress = 10037,
          /// @brief Operation attempted on a non-socket object
          NotSocket = 10038,
          /// @brief Required destination missing
          DestinationAddressRequired = 10039,
          /// @brief Datagram message is too long
          MessageSize = 10040,
          /// @brief The protocol type is incorrect
          ProtocolType = 10041,
          /// @brief An unknown, invalid, or unsupported option or level was used
          ProtocolOption = 10042,
          /// @brief The protocol is not implemented or has not been configured
          ProtocolNotSupported = 10043,
          /// @brief  The support for the specified socket type does not exist in this address family
          SocketNotSupported = 10044,
          /// @brief The address family is not supported by the protocol family
          OperationNotSupported = 10045,
          /// @brief The protocol family is not implemented or has not been configured
          ProtocolFamilyNotSupported = 10046,
          /// @brief The address family specified is not supported. This error is returned if
          /// the IPv6 address family was specified and the IPv6 stack is not installed
          /// on the local machine. This error is returned if the IPv4 address family was
          /// specified and the IPv4 stack is not installed on the local machine.
          AddressFamilyNotSupported = 10047,
          /// @brief Only one use of an address is normally permitted
          AddressAlreadyInUse = 10048,
          /// @brief The selected IP address is not valid in this context
          AddressNotAvailable = 10049,
          /// @brief The network is not available
          NetworkDown = 10050,
          /// @brief No route to the remote host exists
          NetworkUnreachable = 10051,
          /// @brief The application tried to set "keep alive" on a connection that timed out
          NetworkReset = 10052,
          /// @brief Connection aborted
          ConnectionAborted = 10053,
          /// @brief Connection reset by the remote peer
          ConnectionReset = 10054,
          /// @brief No free buffer space available
          NoBufferSpaceAvailable = 10055,
          /// @brief Already connected
          IsConnected = 10056,
          /// @brief The socket is not connected
          NotConnected = 10057,
          /// @brief A request to send or receive data was disallowed because the socket is closed
          Shutdown = 10058,
          /// @brief The connection attempt timed out, or the connected host has failed to respond
          TimedOut = 10060,
          /// @brief The remote host is actively refusing a connection
          ConnectionRefused = 10061,
          /// @brief The operation failed because the remote host is down
          HostDown = 10064,
          /// @brief There is no network route to the specified host
          HostUnreachable = 10065,
          /// @brief Too many processes are using the underlying socket provider
          ProcessLimit = 10067,
          /// @brief The network subsystem is unavailable
          SystemNotReady = 10091,
          /// @brief The version of the underlying socket provider is out of range
          VersionNotSupported = 10092,
          /// @brief The underlying socket provider has not been initialized
          NotInitialized = 10093,
          /// @brief A graceful shutdown is in progress
          Disconnecting = 10101,
          /// @brief The specified class was not found
          TypeNotFound = 10109,
          /// @brief No such host is known. The name is not an official host name or alias.
          HostNotFound = 11001,
          /// @brief The name of the host could not be resolved. Try again later.
          TryAgain = 11002,
          /// @brief The error is unrecoverable or the requested database cannot be located.
          NoRecovery = 11003,
          /// @brief The requested name or IP address was not found on the name server.
          NoData = 11004,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Net::Sockets::SocketError> {
  void operator()(System::Collections::Generic::IDictionary<System::Net::Sockets::SocketError, string>& values, bool& flags) {
    values[System::Net::Sockets::SocketError::SockError] = "SockError";
    values[System::Net::Sockets::SocketError::Success] = "Success";
    values[System::Net::Sockets::SocketError::OperationAborted] = "OperationAborted";
    values[System::Net::Sockets::SocketError::IOPending] = "IOPending";
    values[System::Net::Sockets::SocketError::Interrupted] = "Interrupted";
    values[System::Net::Sockets::SocketError::AccessDenied] = "AccessDenied";
    values[System::Net::Sockets::SocketError::Fault] = "Fault";
    values[System::Net::Sockets::SocketError::InvalidArgument] = "InvalidArgument";
    values[System::Net::Sockets::SocketError::TooManyOpenSockets] = "TooManyOpenSockets";
    values[System::Net::Sockets::SocketError::WouldBlock] = "WouldBlock";
    values[System::Net::Sockets::SocketError::InProgress] = "InProgress";
    values[System::Net::Sockets::SocketError::AlreadyInProgress] = "AlreadyInProgress";
    values[System::Net::Sockets::SocketError::NotSocket] = "NotSocket";
    values[System::Net::Sockets::SocketError::DestinationAddressRequired] = "DestinationAddressRequired";
    values[System::Net::Sockets::SocketError::MessageSize] = "MessageSize";
    values[System::Net::Sockets::SocketError::ProtocolType] = "ProtocolType";
    values[System::Net::Sockets::SocketError::ProtocolOption] = "ProtocolOption";
    values[System::Net::Sockets::SocketError::ProtocolNotSupported] = "ProtocolNotSupported";
    values[System::Net::Sockets::SocketError::SocketNotSupported] = "SocketNotSupported";
    values[System::Net::Sockets::SocketError::OperationNotSupported] = "OperationNotSupported";
    values[System::Net::Sockets::SocketError::ProtocolFamilyNotSupported] = "ProtocolFamilyNotSupported";
    values[System::Net::Sockets::SocketError::AddressFamilyNotSupported] = "AddressFamilyNotSupported";
    values[System::Net::Sockets::SocketError::AddressAlreadyInUse] = "AddressAlreadyInUse";
    values[System::Net::Sockets::SocketError::AddressNotAvailable] = "AddressNotAvailable";
    values[System::Net::Sockets::SocketError::NetworkDown] = "NetworkDown";
    values[System::Net::Sockets::SocketError::NetworkUnreachable] = "NetworkUnreachable";
    values[System::Net::Sockets::SocketError::NetworkReset] = "NetworkReset";
    values[System::Net::Sockets::SocketError::ConnectionAborted] = "ConnectionAborted";
    values[System::Net::Sockets::SocketError::ConnectionReset] = "ConnectionReset";
    values[System::Net::Sockets::SocketError::NoBufferSpaceAvailable] = "NoBufferSpaceAvailable";
    values[System::Net::Sockets::SocketError::IsConnected] = "IsConnected";
    values[System::Net::Sockets::SocketError::NotConnected] = "NotConnected";
    values[System::Net::Sockets::SocketError::Shutdown] = "Shutdown";
    values[System::Net::Sockets::SocketError::TimedOut] = "TimedOut";
    values[System::Net::Sockets::SocketError::ConnectionRefused] = "ConnectionRefused";
    values[System::Net::Sockets::SocketError::HostDown] = "HostDown";
    values[System::Net::Sockets::SocketError::HostUnreachable] = "HostUnreachable";
    values[System::Net::Sockets::SocketError::ProcessLimit] = "ProcessLimit";
    values[System::Net::Sockets::SocketError::SystemNotReady] = "SystemNotReady";
    values[System::Net::Sockets::SocketError::VersionNotSupported] = "VersionNotSupported";
    values[System::Net::Sockets::SocketError::NotInitialized] = "NotInitialized";
    values[System::Net::Sockets::SocketError::Disconnecting] = "Disconnecting";
    values[System::Net::Sockets::SocketError::TypeNotFound] = "TypeNotFound";
    values[System::Net::Sockets::SocketError::HostNotFound] = "HostNotFound";
    values[System::Net::Sockets::SocketError::TryAgain] = "TryAgain";
    values[System::Net::Sockets::SocketError::NoRecovery] = "NoRecovery";
    values[System::Net::Sockets::SocketError::NoData] = "NoData";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
