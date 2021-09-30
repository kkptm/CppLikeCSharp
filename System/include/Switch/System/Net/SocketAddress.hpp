/// @file
/// @brief Contains Switch::System::Net::SocketAddress class.
#pragma once

#include <Switch/Types.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemExport.hpp"
#include "Sockets/AddressFamily.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @cond
      class IPEndPoint;
      namespace Sockets {class Socket;}
      /// @endcond

      /// @brief Stores serialized information from EndPoint derived classes.
      /// @remarks The first 2 bytes of the underlying buffer are reserved for the AddressFamily enumerated value.
      /// @remarks When the SocketAddress is used to store a serialized IPEndPoint, the third and fourth bytes are
      /// @remarks used to store port number information. The next bytes are used to store the IP address. You can
      /// @remarks access any information within this underlying byte buffer by referring to its index position; the
      /// @remarks byte buffer uses zero-based indexing. You can also use the Family and Size properties to get the
      /// @remarks AddressFamily value and the buffer size, respectively. To view any of this information as a string,
      /// @remarks use the ToString method.
      /// @par Library
      /// Switch.System
      class system_export_ SocketAddress : public Object {
      public:
        /// @brief Creates a new instance of the SocketAddress class for the given address family.
        SocketAddress(Sockets::AddressFamily addressFamily) : SocketAddress(addressFamily, 32) {}

        /// @brief Creates a new instance of the SocketAddress class using the specified address family and buffer size.
        SocketAddress(Sockets::AddressFamily addressFamily, int32 bufferSize);

        /// @brief Creates a new instance of the SocketAddress class using the specified byte buffer .
        SocketAddress(const Array<byte>& buffer);

        /// @cond
        SocketAddress(const SocketAddress& socketAddress): bytes(socketAddress.bytes) {}
        SocketAddress& operator=(const SocketAddress& socketAddress) {this->bytes = socketAddress.bytes; return *this;}
        /// @endcond

        /// @brief Gets the address family to which the endpoint belongs.
        /// @return One of the AddressFamily values.
        property_<Sockets::AddressFamily, readonly_> AddressFamily {
          get_ {return this->GetAddressFamily();}
        };

        /// @brief Gets the underlying buffer size of the SocketAddress.
        /// @return int32 The underlying buffer size of the SocketAddress.
        property_<int32, readonly_> Size {
          get_ {return this->bytes.Length();}
        };

        /// @brief Gets or sets the specified index element in the underlying buffer.
        /// @param index The array index element of the desired information.
        /// @return byte The value of the specified index element in the underlying buffer.
        byte& operator[](int32 index) { return this->bytes[index]; }

        /// @brief Gets the specified index element in the underlying buffer.
        /// @param index The array index element of the desired information.
        /// @return byte The value of the specified index element in the underlying buffer.
        /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
        /// @remarks This property gets or sets the specified byte position in the underlying buffer.
        /// @note Be sure to call GetSize before referring to elements in the underlying buffer. Referring to an index that does not exist will cause the SocketAddress to throw an ArgumentOutOfRangeException.
        const byte& operator[](int32 index) const { return bytes[index]; }

        /// @brief Returns information about the socket address.(
        /// @return string A string that contains information about the SocketAddress.
        /// @remarks The ToString method returns a string that contains the AddressFamily enumerated value, the size of the underlying buffer of the SocketAddress structure, and the remaining contents of the buffer.
        virtual String ToString() const;

      private :
        friend class IPEndPoint;
        friend class Sockets::Socket;
        Sockets::AddressFamily GetAddressFamily() const;
        Array<byte> bytes;
      };
    }
  }
}

using namespace Switch;
