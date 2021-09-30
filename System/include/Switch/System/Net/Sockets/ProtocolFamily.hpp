/// @file
/// @brief Contains Switch::System::Net::Sockets::ProtocolFamily enum.
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
        /// @brief Specifies the type of protocol that an instance of the Socket class can use.
        /// @par Library
        /// Switch.System
        enum class ProtocolFamily {
          /// @brief Unknown protocol.
          Unknown = -1,
          /// @brief Unspecified protocol.
          Unspecified = 0,
          /// @brief Unix local to host protocol.
          Unix = 1,
          /// @brief IP version 4 protocol.
          InterNetwork = 2,
          /// @brief ARPANET IMP protocol.
          ImpLink = 3,
          /// @brief PUP protocols.
          Pup = 4,
          /// @brief AMIT CHAOS protocols.
          Chaos = 5,
          /// @brief NS protocol.
          NS = 6,
          /// @brief IPX or SPX protocol.
          Ipx = 6,
          /// @brief ISO protocol.
          Iso = 7,
          /// @brief OSI protocol.
          Osi = 7,
          /// @brief European Computer Manufacturers Association (ECMA) Protocol.
          Ecma = 8,
          /// @brief Datakit protocols.
          DataKit = 9,
          /// @brief CCITT protocols, such as X.25.
          Ccitt = 10,
          /// @brief IBM SNA protocol.
          Sna = 11,
          /// @brief DECnet protocol.
          DecNet = 12,
          /// @brief Direct data-link interface protocol.
          DataLink = 13,
          /// @brief LAT protocol.
          Lat = 14,
          /// @brief NSC Hyperchannel protocol.
          HyperChannel = 15,
          /// @brief AppleTalk protocol.
          AppleTalk = 16,
          /// @brief NetBios protocol.
          NetBios = 17,
          /// @brief VoiceView protocol.
          VoiceView = 18,
          /// @brief FireFox protocol.
          FireFox = 19,
          /// @brief Banyan protocol.
          Banyan = 21,
          /// @brief Native ATM services protocol.
          Atm = 22,
          /// @brief IP version 6 protocol.
          InterNetworkV6 = 23,
          /// @brief Microsoft cluster products protocol.
          Cluster = 24,
          /// @brief IEEE 1284.4 workgroup protocol.
          Ieee12844 = 25,
          /// @brief IrDA address.
          Irda = 26,
          /// @brief Network Designers OSI gateway-enabled protocols.
          NetworkDesigners = 28,
          /// @brief MAX protocol.
          Max = 29,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Net::Sockets::ProtocolFamily> {
  void operator()(System::Collections::Generic::IDictionary<System::Net::Sockets::ProtocolFamily, string>& values, bool& flags) {
    values[System::Net::Sockets::ProtocolFamily::Unknown] = "Unknown";
    values[System::Net::Sockets::ProtocolFamily::Unspecified] = "Unspecified";
    values[System::Net::Sockets::ProtocolFamily::Unix] = "Unix";
    values[System::Net::Sockets::ProtocolFamily::InterNetwork] = "InterNetwork";
    values[System::Net::Sockets::ProtocolFamily::ImpLink] = "ImpLink";
    values[System::Net::Sockets::ProtocolFamily::Pup] = "Pup";
    values[System::Net::Sockets::ProtocolFamily::Chaos] = "Chaos";
    //values[System::Net::Sockets::ProtocolFamily::NS] = "NS";
    values[System::Net::Sockets::ProtocolFamily::Ipx] = "Ipx";
    values[System::Net::Sockets::ProtocolFamily::Iso] = "Iso";
    //values[System::Net::Sockets::ProtocolFamily::Osi] = "Osi";
    values[System::Net::Sockets::ProtocolFamily::Ecma] = "Ecma";
    values[System::Net::Sockets::ProtocolFamily::DataKit] = "DataKit";
    values[System::Net::Sockets::ProtocolFamily::Ccitt] = "Ccitt";
    values[System::Net::Sockets::ProtocolFamily::Sna] = "Sna";
    values[System::Net::Sockets::ProtocolFamily::DecNet] = "DecNet";
    values[System::Net::Sockets::ProtocolFamily::DataLink] = "DataLink";
    values[System::Net::Sockets::ProtocolFamily::Lat] = "Lat";
    values[System::Net::Sockets::ProtocolFamily::HyperChannel] = "HyperChannel";
    values[System::Net::Sockets::ProtocolFamily::AppleTalk] = "AppleTalk";
    values[System::Net::Sockets::ProtocolFamily::NetBios] = "NetBios";
    values[System::Net::Sockets::ProtocolFamily::VoiceView] = "VoiceView";
    values[System::Net::Sockets::ProtocolFamily::FireFox] = "FireFox";
    values[System::Net::Sockets::ProtocolFamily::Banyan] = "Banyan";
    values[System::Net::Sockets::ProtocolFamily::Atm] = "Atm";
    values[System::Net::Sockets::ProtocolFamily::InterNetworkV6] = "InterNetworkV6";
    values[System::Net::Sockets::ProtocolFamily::Cluster] = "Cluster";
    values[System::Net::Sockets::ProtocolFamily::Ieee12844] = "Ieee12844";
    values[System::Net::Sockets::ProtocolFamily::Irda] = "Irda";
    values[System::Net::Sockets::ProtocolFamily::NetworkDesigners] = "NetworkDesigners";
    values[System::Net::Sockets::ProtocolFamily::Max] = "Max";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
