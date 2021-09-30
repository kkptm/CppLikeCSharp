/// @file
/// @brief Contains Switch::System::Net::IPHostEntry class.
#pragma once

#include <Switch/System/Array.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemExport.hpp"
#include "IPAddress.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Provides a container class for Internet host address information.
      /// @par Library
      /// Switch.System
      class system_export_ IPHostEntry : public Object {
      public:
        /// @brief Initializes a new instance of the IPHostEntry.
        IPHostEntry() {}
        /// @cond
        IPHostEntry(const IPHostEntry& ipHostEntry) : addresses(ipHostEntry.addresses), aliases(ipHostEntry.aliases), hostName(ipHostEntry.hostName) {}
        IPHostEntry& operator=(const IPHostEntry& ipHostEntry) {
          this->addresses = ipHostEntry.addresses;
          this->aliases = ipHostEntry.aliases;
          this->hostName = ipHostEntry.hostName;
          return *this;
        }
        /// @endcond

        /// @brief Get List of IP addresses that are associated with a host.
        /// @return Array<IPAddress> An IPAddress array on List of IP addresses that are associated with a host.
        property_<const Array<IPAddress>&, readonly_> AddressList {
          get_->const Array<IPAddress>& {return this->GetAddressList();}
        };

        /// @brief Get List of aliases that are associated with a host.
        /// @return Array<string> A string array on List of aliases that are associated with a host.
        property_<const Array<string>&, readonly_> Aliases {
          get_->const Array<string>& {return this->GetAliases();}
        };

        /// @brief Get the DNS name of the host.
        /// @return string A string represent the DNS name of the host.
        property_<const string&, readonly_> HostName {
          get_->const string& {return this->GetHostName();}
        };

      private:
        friend class Dns;
        IPHostEntry(const Array<IPAddress>& addresses, const Array<string>& aliases, const string& hostName) : addresses(addresses), aliases(aliases), hostName(hostName) {}

        const Array<IPAddress>& GetAddressList() const;
        const Array<string>& GetAliases() const;
        const String& GetHostName() const;

        Array<IPAddress> addresses;
        Array<string> aliases;
        string hostName;
      };
    }
  }
}

using namespace Switch;
