/// @file
/// @brief Contains Switch::System::Net::DnsEndPoint class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemExport.hpp"
#include "EndPoint.hpp"
#include "Sockets/AddressFamily.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Represents a network endpoint as a host name or a string representation of an IP address and a port number.
      /// @remarks The DnsEndPoint class contains a host name or an IP address and remote port information needed by an application to connect to a service on a host. By combining the host name or IP address and port number of a service, the DnsEndPoint class forms a connection point to a service.
      /// @par Library
      /// Switch.System
      class system_export_ DnsEndPoint : public EndPoint {
      public:
        /// @brief Initializes a new instance of the DnsEndPoint class with the host name or string representation of an IP address and a port number.
        /// @param host The host name or a string representation of the IP address.
        /// @param port The port number associated with the address, or 0 to specify any available port. port is in host order.
        /// @exception ArgumentException The host parameter contains an empty string.
        /// @exception ArgumentNullException The host parameter is a null.
        /// @exception ArgumentOutOfRangeException port is less than IPEndPoint::MinPort. -or- port is greater than IPEndPoint::MaxPort.
        /// @remarks The DnsEndPoint(string, Int32) constructor can be used to initialize a DnsEndPoint class using either a host name or a string that represents an IP address and a port. This constructor sets the AddressFamily property to Unknown.
        /// @remarks When using this constructor with a host name rather than a string representation of an IP address, the address family of the DnsEndPoint will remain Unknown even after use. The AddressFamily property of any Socket that is created by calls to the ConnectAsync method will be the address family of the first address to which a connection can be successfully established (not necessarily the first address to be resolved).
        DnsEndPoint(const String& host, int32 port);

        /// @brief Initializes a new instance of the DnsEndPoint class with the host name or string representation of an IP address, a port number, and an address family.
        /// @param host The host name or a string representation of the IP address.
        /// @param port The port number associated with the address, or 0 to specify any available port. port is in host order.
        /// @param addressFamily One of the AddressFamily values.
        /// @exception ArgumentException The host parameter contains an empty string.
        /// @exception ArgumentNullException The host parameter is a null.
        /// @exception ArgumentOutOfRangeException port is less than IPEndPoint::MinPort. -or- port is greater than IPEndPoint::MaxPort.
        /// @remarks The DnsEndPoint(string, Int32, AddressFamily) constructor can be used to initialize a DnsEndPoint class using either a host name or a string that represents an IP address, a port, and an address family.
        /// @remarks When using the constructor with a host name rather than a string representation of an IP address, the address family restricts DNS resolution to prefer addresses of the specified address family value. When using the constructor with the address family specified as Unknown, the address family of the DnsEndPoint will remain Unknown even after use. The AddressFamily property of any Socket that is created by calls to the ConnectAsync method will be the address family of the first address to which a connection can be successfully established (not necessarily the first address to be resolved).
        DnsEndPoint(const String& host, int32 port, Sockets::AddressFamily addressFamily);

        /// @cond
        DnsEndPoint(const DnsEndPoint& dnsEndPoint) : EndPoint(dnsEndPoint), host(dnsEndPoint.host), port(dnsEndPoint.port) {}
        /// @endcond

        /// @brief Gets or sets the host name or string representation of the Internet Protocol (IP) address of the host.
        /// @param value The host name or a string representation of the IP address.
        /// @exception ArgumentException The host parameter contains an empty string.
        /// @exception ArgumentNullException The host parameter is a null.
        property_<const String&> Host {
          get_->const string& {return this->host;},
          set_ {this->SetHost(value);}
        };

        /// @brief Gets the port number of the endpoint.
        /// @param value An integer value in the range IPEndPoint::MinPort to IPEndPoint::MaxPort indicating the port number of the endpoint.
        /// @exception ArgumentOutOfRangeException port is less than IPEndPoint::MinPort. -or- port is greater than IPEndPoint::MaxPort.
        property_<int32> Port {
          get_ {return this->port;},
          set_ {this->SetPort(value);}
        };

        /// @brief Serializes endpoint information into a SocketAddress instance.
        /// @return A new SocketAddress instance that contains the endpoint information.
        SocketAddress Serialize() const override;

        /// @brief Returns a string that represents the current object.
        /// @return string A string that represents the current object.
        String ToString() const override;

      private :
        void SetHost(const String& host);
        void SetPort(int32 port);

        String host;
        int32 port;
      };
    }
  }
}

using namespace Switch;
