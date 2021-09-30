/// @file
/// @brief Contains Switch::System::Net::Sockets::ProtocolType enum.
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
        /// @brief  Specifies the protocols that the Socket class supports.
        /// @remarks The Socket class uses the ProtocolType enumeration to inform the Windows Sockets API of the requested protocol. Low-level driver software for the requested protocol must be present on the computer for the Socket to be created successfully.
        /// @par Library
        /// Switch.System
        enum class ProtocolType {
          /// @brief Specifies an unknown Socket type.
          Unknown = -1,
          /// @brief IPv6 Hop by Hop Options header.
          IPv6HopByHopOptions = 0,
          /// @brief Undpecified Protocol.
          Unspecified = 0,
          /// @brief Internet Protocol.
          IP = 0,
          /// @brief Internet Control Message Protocol.
          Icmp = 1,
          /// @brief Internet Group Management Protocol.
          Igmp = 2,
          /// @brief Gateway To Gateway Protocol.
          Ggp = 3,
          /// @brief Internet Protocol version 4.
          IPv4 = 4,
          /// @brief Transmission Control Protocol.
          Tcp = 6,
          /// @brief PARC Universal Packet Protocol.
          Pup = 12,
          /// @brief User Datagram Protocol.
          Udp = 17,
          /// @brief Internet Datagram Protocol.
          Idp = 22,
          /// @brief Internet Protocol version 6 (IPv6).
          IPv6 = 41,
          /// @brief IPv6 Routing header.
          IPv6RoutingHeader = 43,
          /// @brief IPv6 Fragment header.
          IPv6FragmentHeader = 44,
          /// @brief IPv6 Encapsulating Security Payload header.
          IPSecEncapsulatingSecurityPayload = 50,
          /// @brief IPv6 Authentication header. For details, see RFC 2292 section 2.2.1, available at http://www.ietf.org.
          IPSecAuthenticationHeader = 51,
          /// @brief Internet Control Message Protocol for IPv6.
          IcmpV6 = 58,
          /// @brief IPv6 No next header.
          IPv6NoNextHeader = 59,
          /// @brief IPv6 Destination Options header.
          IPv6DestinationOptions = 60,
          /// @brief Net Disk Protocol (unofficial).
          ND = 77,
          /// @brief Raw IP packet protocol.
          Raw = 255,
          /// @brief Internet Packet Exchange Protocol.
          Ipx = 1000,
          /// @brief Sequenced Packet Exchange protocol.
          Spx = 1256,
          /// @brief Sequenced Packet Exchange version 2 protocol.
          SpxII = 1257,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Net::Sockets::ProtocolType> {
  void operator()(System::Collections::Generic::IDictionary<System::Net::Sockets::ProtocolType, string>& values, bool& flags) {
    values[System::Net::Sockets::ProtocolType::Unknown] = "Unknown";
    //values[System::Net::Sockets::ProtocolType::IPv6HopByHopOptions] = "IPv6HopByHopOptions";
    //values[System::Net::Sockets::ProtocolType::Unspecified] = "Unspecified";
    values[System::Net::Sockets::ProtocolType::IP] = "IP";
    values[System::Net::Sockets::ProtocolType::Icmp] = "Icmp";
    values[System::Net::Sockets::ProtocolType::Igmp] = "Igmp";
    values[System::Net::Sockets::ProtocolType::Ggp] = "Ggp";
    values[System::Net::Sockets::ProtocolType::IPv4] = "IPv4";
    values[System::Net::Sockets::ProtocolType::Tcp] = "Tcp";
    values[System::Net::Sockets::ProtocolType::Pup] = "Pup";
    values[System::Net::Sockets::ProtocolType::Udp] = "Udp";
    values[System::Net::Sockets::ProtocolType::Idp] = "Idp";
    values[System::Net::Sockets::ProtocolType::IPv6] = "IPv6";
    values[System::Net::Sockets::ProtocolType::IPv6RoutingHeader] = "IPv6RoutingHeader";
    values[System::Net::Sockets::ProtocolType::IPv6FragmentHeader] = "IPv6FragmentHeader";
    values[System::Net::Sockets::ProtocolType::IPSecEncapsulatingSecurityPayload] = "IPSecEncapsulatingSecurityPayload";
    values[System::Net::Sockets::ProtocolType::IPSecAuthenticationHeader] = "IPSecAuthenticationHeader";
    values[System::Net::Sockets::ProtocolType::IcmpV6] = "IcmpV6";
    values[System::Net::Sockets::ProtocolType::IPv6NoNextHeader] = "IPv6NoNextHeader";
    values[System::Net::Sockets::ProtocolType::IPv6DestinationOptions] = "IPv6DestinationOptions";
    values[System::Net::Sockets::ProtocolType::ND] = "ND";
    values[System::Net::Sockets::ProtocolType::Raw] = "Raw";
    values[System::Net::Sockets::ProtocolType::Ipx] = "Ipx";
    values[System::Net::Sockets::ProtocolType::Spx] = "Spx";
    values[System::Net::Sockets::ProtocolType::SpxII] = "SpxII";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
