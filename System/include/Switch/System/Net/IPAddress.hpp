/// @file
/// @brief Contains Switch::System::Net::IPAddress class.
#pragma once

#include <Switch/Types.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemExport.hpp"
#include "Sockets/SocketException.hpp"
#include "Sockets/AddressFamily.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Provides an Internet Protocol (IP) address.
      /// @par Library
      /// Switch.System
      class system_export_ IPAddress : public Object {
      public:
        /// @brief Provides an IP address that indicates that the server must listen for client activity on all network interfaces. This field is constant.
        /// @remarks The cAny field is equivalent to 0.0.0.0 in dotted-quad notation
        static property_<IPAddress, readonly_> Any;

        /// @brief Provides the IP broadcast address. This field is constant.
        /// @remarks The cBroadcast field is equivalent to 255.255.255.255 in dotted-quad notation.
        static property_<IPAddress, readonly_> Broadcast;

        /// @brief The Socket::Bind method uses the cIPv6Any field to indicate that a Socket must listen for client activity on all network interfaces. This field is constant.
        /// @remarks The cIPv6Any field is equivalent to 0:0:0:0:0:0:0:0 in colon-hexadecimal notation, or to :: in compact notation.
        static property_<IPAddress, readonly_> IPv6Any;

        /// @brief Provides the IP loopback address. This field is constant.
        /// @remarks The cIPv6Loopback field is equivalent to 0:0:0:0:0:0:0:1 in colon-hexadecimal notation, or to ::1 in compact notation.
        static property_<IPAddress, readonly_> IPv6Loopback;

        /// @brief Provides an IP address that indicates that no network interface should be used. This field is constant.
        /// @remarks The Socket::Bind method uses the cIPv6None field to indicate that a Socket must not listen for client activity.
        /// @remarks The cIPv6None field is equivalent to 0:0:0:0:0:0:0:0 in colon-hexadecimal notation, or to ::0 in compact notation.
        static property_<IPAddress, readonly_> IPv6None;

        /// @brief Provides the IP loopback address. This field is constant.
        /// @remarks The cLoopback field is equivalent to 127.0.0.1 in dotted-quad notation.
        static property_<IPAddress, readonly_> Loopback;

        /// @brief Provides an IP address that indicates that no network interface should be used. This field is constant.
        /// @remarks The cNone field is equivalent to 255.255.255.255 in dotted-quad notation.
        static property_<IPAddress, readonly_> None;

        /// @brief Initializes a new instance of the IPAddress class with the address specified as an Int64.
        /// @remarks IPAddress is initialized by default value cNone.
        IPAddress();

        /// @brief Initializes a new instance of the IPAddress class with the address specified as an IPAddress object.
        /// @param address The IP address object to set.
        /// @exception ArgumentNUllException address is null.
        IPAddress(const IPAddress& address);
        /// @cond
        IPAddress& operator=(const IPAddress& address);
        /// @endcond

        /// @brief Initializes a new instance of the IPAddress class with the address specified as an Int64.
        /// @param address The long value of the IP address. For example, the value 0x2414188F in big-endian format would be the IP address "143.24.20.36".
        IPAddress(int64 address);

        /// @brief Initializes a new instance of the IPAddress class with the address specified as a Byte array.
        /// @param address The Byte array value of the IP address.
        /// @exception ArgumentNullException The parameters address is null.
        IPAddress(const Array<byte>& address);

        /// @brief Initializes a new instance of the IPAddress class with the address specified as a Byte array.
        /// @param address The Byte array value of the IP address.
        /// @param scopeId The long value of the scope identifier.
        /// @exception ArgumentNullException The parameters address is null.
        /// @exception ArgumentOutOfRangeException scopeId < 0 or scopeId > 0x00000000FFFFFFFF.
        /// @remarks This constructor instantiates an IPv6 address. The scopeid identifies a network interface in the case of a link-local address.
        /// @remarks The scope is valid only for link-local and site-local addresses.
        /// @remarks The Byte array is assumed to be in network byte order with the most significant byte first in index position 0.
        IPAddress(const Array<byte>& address, int64 scopeId);

        /// @brief Initializes a new instance of the IPAddress class with the address specified as a four Bytes.
        /// @param quadPartAddress1 The first quad part of the IP address.
        /// @param quadPartAddress2 The second quad part of the IP address.
        /// @param quadPartAddress3 The third quad part of the IP address.
        /// @param quadPartAddress4 The fourth quad part of the IP address.
        IPAddress(byte quadPartAddress1, byte quadPartAddress2, byte quadPartAddress3, byte quadPartAddress4);

        /// @brief Gets the address family of the IP address.
        /// @return Returns InterNetwork for IPv4 or InterNetworkV6 for IPv6.
        property_<Sockets::AddressFamily, readonly_> AddressFamily {
          get_ {return this->GetAddressFamily();}
        };

        /// @brief Gets the IPv6 address scope identifier.
        /// @param value A Int64 that specifies the scope of the address.
        /// @exception SocketException AddressFamily = AddressFamilyInterNetwork
        /// @exception SocketException AddressFamily = AddressFamilyInterNetwork
        /// @exception ArgumentOutOfRangeException scopeId < 0 or scopeId > 0x00000000FFFFFFFF.
        property_<int64> ScopeId {
          get_ {return this->GetScopeId();},
          set_ {this->SetScopeId(value);}
        };

        /// @brief Gets whether the address is an IPv6 link local address.
        /// @return bool true if the IP address is an IPv6 link local address; otherwise, false.
        property_<bool, readonly_> IsIPv6LinkLocal {
          get_ {return this->GetIsIPv6LinkLocal();}
        };

        /// @brief Gets whether the address is an IPv6 multicast global address.
        /// @return bool true if the IP address is an IPv6 multicast global address; otherwise, false.
        property_<bool, readonly_> IsIPv6Multicast {
          get_ {return this->GetIsIPv6Multicast();}
        };

        /// @brief Gets whether the address is an IPv6 site local address.
        /// @return bool true if the IP address is an IPv6 site local address; otherwise, false.
        property_<bool, readonly_> IsIPv6SiteLocal {
          get_ {return this->GetIsIPv6SiteLocal();}
        };

        /// @brief Determines whether this instance of IPAddress and a specified object, which must also be a IPAddress object, have the same value.
        /// @param value The IPAddress to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        bool Equals(const IPAddress& value) const;

        /// @brief Determines whether this instance of IPAddress and a specified object, which must also be a IPAddress object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override;

        /// @brief Provides a copy of the IPAddress as an array of bytes.
        /// @return  A Byte array.
        Array<byte> GetAddressBytes() const;

        /// @brief Provides a copy of the IPAddress as four Bytes.
        /// @param quadPartAddress1 the first quad part to get a copy of IPAddress.
        /// @param quadPartAddress2 the second quad part to get a copy of IPAddress.
        /// @param quadPartAddress3 the third quad part to get a copy of IPAddress.
        /// @param quadPartAddress4 the fourth quad part to get a copy of IPAddress.
        /// @exception ArgumentNullException The parameters quadPartAddress1 or quadPartAddress2 or quadPartAddress3 or quadPartAddress4 is null.
        void GetAddressBytes(byte& quadPartAddress1, byte& quadPartAddress2, byte& quadPartAddress3, byte& quadPartAddress4) const;

        /// @brief Serves as a hash function for a particular type.
        /// @return int32 A hash code for the current object.
        int32 GetHashCode() const override;

        /// @brief Converts a Double value from host byte order to network byte order.
        /// @param host The number to convert, expressed in host byte order.
        /// @return double A Double value, expressed in network byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static double HostToNetworkOrder(double host);

        /// @brief Converts a short value from host byte order to network byte order.
        /// @param host The number to convert, expressed in host byte order.
        /// @return int16 A short value, expressed in network byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static int16 HostToNetworkOrder(int16 host);

        /// @brief Converts a integer value from host byte order to network byte order.
        /// @param host The number to convert, expressed in host byte order.
        /// @return int32 A integer value, expressed in network byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static int32 HostToNetworkOrder(int32 host);

        /// @brief Converts a long value from host byte order to network byte order.
        /// @param host The number to convert, expressed in host byte order.
        /// @return int64 A long value, expressed in network byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static int64 HostToNetworkOrder(int64 host);

        /// @brief Converts a Single value from host byte order to network byte order.
        /// @param host The number to convert, expressed in host byte order.
        /// @return single A Single value, expressed in network byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static float HostToNetworkOrder(float host);

        /// @brief Converts a short value from host byte order to network byte order.
        /// @param host The number to convert, expressed in host byte order.
        /// @return uint16 A unsigned short value, expressed in network byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static uint16 HostToNetworkOrder(uint16 host);

        /// @brief Converts a integer value from host byte order to network byte order.
        /// @param host The number to convert, expressed in host byte order.
        /// @return uint32 A unsigned integer value, expressed in network byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static uint32 HostToNetworkOrder(uint32 host);

        /// @brief Converts a long value from host byte order to network byte order.
        /// @param host The number to convert, expressed in host byte order.
        /// @return uint64 A unsigned long value, expressed in network byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static uint64 HostToNetworkOrder(uint64 host);

        /// @brief Indicates whether the specified IP address is the loopback address.
        /// @param address An IP address.
        /// @return bool true if address is the loopback address; otherwise, false.
        /// @exception ArgumentNullException The parameters address is null.
        static bool IsLoopback(const IPAddress& address);

        /// @brief Converts a Double value from network byte order to host byte order.
        /// @param network The number to convert, expressed in network byte order.
        /// @return double A Double value, expressed in host byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static double NetworkToHostOrder(double network);

        /// @brief Converts a short value from network byte order to host byte order.
        /// @param network The number to convert, expressed in network byte order.
        /// @return int16 A short value, expressed in host byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static int16 NetworkToHostOrder(int16 network);

        /// @brief Converts a integer value from network byte order to host byte order.
        /// @param host The number to convert, expressed in network byte order.
        /// @return int32 A integer value, expressed in host byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static int32 NetworkToHostOrder(int32 host);

        /// @brief Converts a long value from network byte order to host byte order.
        /// @param network The number to convert, expressed in network byte order.
        /// @return int64 A long value, expressed in host byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static int64 NetworkToHostOrder(int64 network);

        /// @brief Converts a Single value from network byte order to host byte order.
        /// @param network The number to convert, expressed in host byte order.
        /// @return single A Single value, expressed in host byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static float NetworkToHostOrder(float network);

        /// @brief Converts a short value from network byte order to host byte order.
        /// @param network The number to convert, expressed in network byte order.
        /// @return uint16 A unsigned short value, expressed in host byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static uint16 NetworkToHostOrder(uint16 network);

        /// @brief Converts a integer value from network byte order to host byte order.
        /// @param network The number to convert, expressed in network byte order.
        /// @return uint32 A unsigned integer value, expressed in host byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static uint32 NetworkToHostOrder(uint32 network);

        /// @brief Converts a long value from network byte order to host byte order.
        /// @param network The number to convert, expressed in network byte order.
        /// @return uint64 A unsigned long value, expressed in host byte order.
        /// @remarks Different computers use different conventions for ordering the bytes within multibyte integer values.
        /// @remarks Some computers put the most significant byte first (known as big-endian order) and others put the least-significant byte first (known as little-endian order).
        /// @remarks To work with computers that use different byte ordering, all integer values that are sent over the network are sent in network byte order which has
        /// @remarks the most significant byte first.
        /// @remarks The HostToNetworkOrder method converts multibyte integer values that are stored on the host system from the byte order used by the host to the byte
        /// @remarks order used by the network.
        static uint64 NetworkToHostOrder(uint64 network);

        /// @brief Converts an IP address string to an IPAddress instance.
        /// @param str A string that contains an IP address in dotted-quad notation for IPv4 and in colon-hexadecimal notation for IPv6.
        /// @return IPAddress An IPAddress instance.
        /// @exception ArgumentNullException str is null.
        /// @exception ArgumentException str is not a valid IP address.
        /// @remarks The static Parse method creates an IPAddress instance from an IP address expressed in dotted-quad notation for IPv4 and in colon-hexadecimal notation for IPv6.
        /// @remarks The number of parts (each part is separated by a period) in ipString determines how the IP address is constructed. A one part address is stored directly
        /// @remarks in the network address. A two part address, convenient for specifying a class A address, puts the leading part in the first byte and the trailing part
        /// @remarks in the right-most three bytes of the network address. A three part address, convenient for specifying a class B address, puts the first part in the
        /// @remarks first byte, the second part in the second byte, and the final part in the right-most two bytes of the network address.
        static IPAddress Parse(const string& str);

        /// @brief Converts an Internet address to its standard notation.
        /// @return string A string that contains the IP address in either IPv4 dotted-quad or in IPv6 colon-hexadecimal notation.
        String ToString() const override;

        /// @brief Determines whether a string is a valid IP address.
        /// @param str The string to validate.
        /// @param address The IPAddress version of the string.
        /// @return bool true if str is a valid IP address; otherwise, false.
        static bool TryParse(const string& str, IPAddress& address);

      private :
        IPAddress(const std::vector<byte>& address);
        Sockets::AddressFamily GetAddressFamily() const;
        int64 GetScopeId() const;
        void SetScopeId(int64 scopeId);
        bool GetIsIPv6LinkLocal() const;
        bool GetIsIPv6Multicast() const;
        bool GetIsIPv6SiteLocal() const;

        uint32 address = 0xFFFFFFFF; // IPv4 value
        Array<uint16> numbers = Array<>::CreateInstance<uint16>(8); // IPv6 value
        uint32 scopeId = 0;
        Sockets::AddressFamily family = Sockets::AddressFamily::InterNetwork;
      };
    }
  }
}

using namespace Switch;
