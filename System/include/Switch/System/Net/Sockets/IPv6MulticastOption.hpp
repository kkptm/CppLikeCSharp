/// @file
/// @brief Contains Switch::System::Net::Sockets::IPv6MulticastOption enum.
#pragma once

#include <Switch/Property.hpp>
#include "../../../SystemExport.hpp"
#include "../IPAddress.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief Contains option values for joining an IPv6 multicast group.
        /// @par Library
        /// Switch.System
        class system_export_ IPv6MulticastOption : public Object {
        public:
          /// @brief Initializes a new version of the IPv6MulticastOption class for the specified IP multicast group.
          /// @param group The IPAddress of the multicast group.
          /// @exception ArgumentNullException group is null.
          IPv6MulticastOption(const IPAddress& group) : group(group) {}

          /// @brief Initializes a new instance of the IPv6MulticastOption class with the specified IP multicast group and the local interface address.
          /// @param group The IPAddress of the multicast group.
          /// @param interfaceIndex The local interface address.
          /// @exception ArgumentNullException group is null.
          /// @exception ArgumentOutOfRangeException interfaceIndex is less than 0. -or- interfaceIndex is greater than 0x00000000FFFFFFFF.
          IPv6MulticastOption(const IPAddress& group, int64 interfaceIndex) : group(group) {InterfaceIndex = interfaceIndex;}

          /// @cond
          IPv6MulticastOption(const IPv6MulticastOption& ipv6MulticastOption) : group(ipv6MulticastOption.group), interfaceIndex(ipv6MulticastOption.interfaceIndex) {}
          /// @endcond

          /// @brief Gets or Set the IP address of a multicast group.
          /// @param group An IPAddress that contains the Internet address of a multicast group.
          /// @return IPAddress An IPAddress that contains the Internet address of a multicast group.
          /// @exception ArgumentNullException group is null.
          property_<const IPAddress&> Group {
            get_->const IPAddress& {return this->group;},
            set_ {this->group = value;}
          };

          /// @brief Gets the interface index that is associated with a multicast group.
          /// @param interfaceIndex A Int64 value that specifies the address of the interface.
          /// @return int64 A Int64 value that specifies the address of the interface.
          /// @exception ArgumentOutOfRangeException interfaceIndex is less than 0. -or- interfaceIndex is greater than 0x00000000FFFFFFFF.
          property_<int64> InterfaceIndex {
            get_ {return this->interfaceIndex;},
            set_ {
              if (value < 0 || value > 0x00000000FFFFFFFF)
                throw ArgumentOutOfRangeException(caller_);
              this->interfaceIndex = int32(value);
            }
          };

        private:
          IPAddress group;
          int32 interfaceIndex = 0;
        };
      }
    }
  }
}

using namespace Switch;
