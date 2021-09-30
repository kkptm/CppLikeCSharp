/// @file
/// @brief Contains Switch::System::OperatingSystem class.
#pragma once

#include "../Property.hpp"
#include "../Types.hpp"
#include "PlatformID.hpp"
#include "Version.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents information about an operating system, such as the version and platform identifier. This class cannot be inherited.
    class core_export_ OperatingSystem final : public object {
    public:
      /// @brief Initializes a new instance of the OperatingSystem class, using the specified platform identifier value and version object.
      /// @param platform One of the PlatformID values that indicates the operating system platform.
      /// @param version A Version object that indicates the version of the operating system.
      /// @exception ArgumentNullException version is null.
      /// @exception ArgumentException platform is not a PlatformID enumeration value.
      OperatingSystem(PlatformID platform, const Version& version) : platform(platform), version(version) {}
      /// @cond
      OperatingSystem(const OperatingSystem& operatingSystem) : platform(operatingSystem.platform), version(operatingSystem.version) {}
      OperatingSystem& operator=(const OperatingSystem& operatingSystem) {
        this->platform = operatingSystem.platform;
        this->version = operatingSystem.version;
        return *this;
      }
      /// @endcond

      property_<bool, readonly_> IsWindowsFamilly {
        get_ {return this->platform == PlatformID::Win32NT || this->platform == PlatformID::Win32S || this->platform == PlatformID::Win32Windows || this->platform == PlatformID::WinCE || this->platform == PlatformID::Xbox;}
      };

      property_<bool, readonly_> IsUnixFamilly {
        get_ {return this->platform == PlatformID::Unix || this->platform == PlatformID::MacOSX || this->platform == PlatformID::IOs || this->platform == PlatformID::Android;}
      };

      /// @brief Gets a System::PlatformID enumeration value that identifies the operating system platform.
      /// @return PlatformID One of the PlatformID values.
      property_<PlatformID, readonly_> Platform {
        get_ {return this->platform;}
      };

      /// @brief Gets the service pack version represented by this OperatingSystem object.
      /// @return string The service pack version, if service packs are supported and at least one is installed; otherwise, an empty string ("").
      /// @remarks A service pack is used to distribute software updates for the operating system on which it is installed. However, not every operating system uses service packs.
      /// @remarks The service pack version, if available, is already correctly formatted for display.
      property_<String, readonly_> ServicePack {
        get_ {
          //if ((this->platform == PlatformID::Win32S || this->platform == PlatformID::Win32Windows || this->platform == PlatformID::Win32NT || this->platform == PlatformID::WinCE || this->platform == PlatformID::Xbox) && this->version.Build() % 10)
          //  return String::Format("Service Pack {0}", this->version.Minor() % 10);
          return String::Empty;
        }
      };

      /// @brief Gets a System::Version object that identifies the operating system.
      /// @return Version A Version object that describes the major version, minor version, build, and revision numbers for the operating system.
      /// @remarks For Window system only: See http://msdn.microsoft.com/library/windows/desktop/ms724832.aspx on the Windows Dev Center for a list of Windows operating system versions and their corresponding version numbers.
      property_<const System::Version&, readonly_> Version {
        get_->const System::Version& {return this->version;}
      };

      /// @brief Gets the concatenated string representation of the platform identifier, version, and service pack that are currently installed on the operating system.
      /// @return The string representation of the values returned by the Platform, Version, and ServicePack properties.
      /// @remarks By default, the value returned by VersionString is the same as the value returned by the ToString method. However, an implementation of the .NET Framework for a different platform might return a more appropriate string for that platform.
      property_<String, readonly_> VersionString {
        get_ {
          String operatingSystem;

          switch (this->platform) {
          case PlatformID::Win32S: operatingSystem = "Microsoft Win32S"; break;
          case PlatformID::Win32Windows: operatingSystem = "Microsoft Windows 98"; break;
          case PlatformID::Win32NT: operatingSystem = "Microsoft Windows NT"; break;
          case PlatformID::WinCE: operatingSystem = "Microsoft Windows CE"; break;
          case PlatformID::Unix: operatingSystem = "Unix"; break;
          case PlatformID::Xbox: operatingSystem = "Xbox"; break;
          case PlatformID::MacOSX: operatingSystem = "macOS"; break;
          case PlatformID::IOs: operatingSystem = "IOs"; break;
          case PlatformID::Android: operatingSystem = "Android"; break;
          case PlatformID::Unknown: operatingSystem = "<Unknown>"; break;
          }

          return String::Format("{0} {1} {2}", operatingSystem, this->version, this->ServicePack).TrimEnd(' ');
        }
      };

      /// @brief Converts the value of this OperatingSystem object to its equivalent string representation.
      /// @return string The string representation of the values returned by the Platform, Version, and ServicePack properties.
      String ToString() const override {return VersionString;}

    private:
      PlatformID platform = PlatformID::Unknown;
      System::Version version;
    };
  }
}

using namespace Switch;
