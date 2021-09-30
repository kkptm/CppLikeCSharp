/// @file
/// @brief Contains Switch::System::Net::IPEndPoint class.
#pragma once

#include "../../SystemExport.hpp"
#include "EndPoint.hpp"
#include "IPAddress.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Represents a network endpoint as an IP address and a port number.
      /// @remarks The IPEndPoint class contains the host and local or remote port information needed by an application to connect to a service on a host. By combining the host's IP address and port number of a service, the IPEndPoint class forms a connection point to a service.
      /// @par Library
      /// Switch.System
      class system_export_ IPEndPoint : public EndPoint {
      public:
        /// @brief Specifies the minimum value that can be assigned to the Port property. The MinPort value is set to 0x00000000. This field is read-only.
        static property_<int32, readonly_> MinPort;

        /// @brief Specifies the maximum value that can be assigned to the Port property. The MaxPort value is set to 0x0000FFFF. This field is read-only.
        static property_<int32, readonly_> MaxPort;

        /// @brief Initializes a new instance of the EndPoint class.
        /// @param address The IP address of the Internet host.
        /// @param port The port number associated with the address, or 0 to specify any available port. port is in host order.
        /// @exception ArgumentOutOfRangeException port is less than IPEndPoint::MinPort. -or- port is greater than IPEndPoint::MaxPort.
        IPEndPoint(int64 address, int32 port);

        /// @brief Initializes a new instance of the EndPoint class.
        /// @param address An IPAddress.
        /// @param port The port number associated with the address, or 0 to specify any available port. port is in host order.
        /// @exception ArgumentNullException The address parameter is a null.
        /// @exception ArgumentOutOfRangeException port is less than IPEndPoint::MinPort. -or- port is greater than IPEndPoint::MaxPort.
        IPEndPoint(const IPAddress& address, int32 port);

        /// @cond
        IPEndPoint() = default;
        IPEndPoint(const IPEndPoint& ipEndPoint) : EndPoint(ipEndPoint), address(ipEndPoint.address), port(ipEndPoint.port) {}
        /// @endcond

        /// @brief Creates an EndPoint instance from a SocketAddress instance.
        /// @param socketAddress The socket address that serves as the endpoint for a connection.
        /// @return A new EndPoint instance that is initialized from the specified SocketAddress instance.
        /// @exception NotSupportedException Any attempt is made to access the method when the method is not overridden in a descendant class.
        refptr<EndPoint> Create(const SocketAddress& socketAddress) const override;

        /// @brief Gets the IP address of the endpoint.
        /// @param value An IPAddress instance containing the IP address of the endpoint.
        /// @exception ArgumentNullException The address parameter is a null.
        property_<const IPAddress&> Address{
          get_->const IPAddress& { return this->address; },
          set_ {this->SetAddress(value);}
        };

        /// @brief Gets or sets the port number of the endpoint.
        /// @param value An integer value in the range MinPort to MaxPort indicating the port number of the endpoint.
        /// @exception ArgumentOutOfRangeException port is less than IPEndPoint::MinPort. -or- port is greater than IPEndPoint::MaxPort.
        property_<int32> Port {
          get_ { return this->port; },
          set_ {this->SetPort(value);}
        };

        /// @brief Serializes endpoint information into a SocketAddress instance.
        /// @return A new SocketAddress instance that contains the endpoint information.
        SocketAddress Serialize() const override;

        /// @brief Returns a string that represents the current object.
        /// @return string A string that represents the current object.
        String ToString() const override;

      private :
        void SetAddress(const IPAddress& address);
        void SetPort(int32 port);

        IPAddress address;
        int32 port = 0;
      };
    }
  }
}

using namespace Switch;
