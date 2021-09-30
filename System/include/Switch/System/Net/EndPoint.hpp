/// @file
/// @brief Contains Switch::System::Net::EndPoint class.
#pragma once

#include <Switch/Types.hpp>
#include <Switch/RefPtr.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemExport.hpp"
#include "SocketAddress.hpp"
#include "Sockets/AddressFamily.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Identifies a network address. This is an abstract class.
      /// @par Library
      /// Switch.System
      class system_export_ EndPoint : public Object {
      public:
        /// @cond
        EndPoint() {}
        EndPoint(const EndPoint& endPoint) : addressFamily(endPoint.addressFamily) {}
        /// @endcond

        /// @brief Creates an EndPoint instance from a SocketAddress instance.
        /// @param socketAddress The socket address that serves as the endpoint for a connection.
        /// @return A new EndPoint instance that is initialized from the specified SocketAddress instance.
        /// @exception NotSupportedException Any attempt is made to access the method when the method is not overridden in a descendant class.
        virtual refptr<EndPoint> Create(const SocketAddress& socketAddress) const;

        /// @brief Gets the address family to which the endpoint belongs.
        /// @return One of the AddressFamily values.
        property_<Sockets::AddressFamily, readonly_> AddressFamily {
          get_ {return this->addressFamily;}
        };

        /// @brief Serializes endpoint information into a SocketAddress instance.
        /// @return A new SocketAddress instance that contains the endpoint information.
        virtual SocketAddress Serialize() const;

        /// @brief Returns a string that represents the current object.
        /// @return string A string that represents the current object.
        String ToString() const override;

      protected:
        /// @brief Initializes a new instance of the EndPoint class.
        EndPoint(Sockets::AddressFamily addressFamily) : addressFamily(addressFamily) {}

        /// @cond
        Sockets::AddressFamily addressFamily = Sockets::AddressFamily::Unknown;
        /// @endcond
      };
    }
  }
}

using namespace Switch;
