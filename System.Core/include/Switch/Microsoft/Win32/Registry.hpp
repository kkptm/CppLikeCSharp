/// @file
/// @brief Contains Switch::Microsoft::Win32::Registry class.
#pragma once

#include "RegistryHive.hpp"
#include "RegistryKey.hpp"
#include "RegistryOptions.hpp"
#include "../../System/Threading/ThreadLocal.hpp"

namespace Switch {
  /// @brief The Microsoft namespace provide Microsoft specific classes.
  namespace Microsoft {
    namespace Win32 {
      //class Switch::Microsoft::Win32::RegistryKey  ClassesRoot;
      /// @brief Provides RegistryKey objects that represent the root keys in the Windows registry, and static methods to access key/value pairs.
      class core_export_ Registry : public object {
      private:
        Registry() {}

        static RegistryHive ToRegistryHive(const System::String& name) {
          if (name == "HKEY_CLASSES_ROOT")
            return RegistryHive::ClassesRoot;
          if (name == "HKEY_CURRENT_USER")
            return RegistryHive::CurrentUser;
          if (name == "HKEY_LOCAL_MACHINE")
            return RegistryHive::LocalMachine;
          if (name == "HKEY_USERS")
            return RegistryHive::Users;
          if (name == "HKEY_PERFORMANCE_DATA")
            return RegistryHive::PerformanceData;
          if (name == "HKEY_CURRENT_CONFIG")
            return RegistryHive::CurrentConfig;
          if (name == "HKEY_DYN_DATA")
            return RegistryHive::DynData;

          throw System::ArgumentException(caller_);
        }

      public:
        /// @brief Retrieves the value associated with the specified name, in the specified registry key. If the name is not found in the specified key, returns a default value that you provide, or null if the specified key does not exist.
        /// @param keyName The full registry path of the key, beginning with a valid registry root, such as "HKEY_CURRENT_USER".
        /// @param valueName The name of the name/value pair.
        /// @param defaultValue null if the subkey specified by keyName does not exist; otherwise, the value associated with valueName, or defaultValue if valueName is not found.
        template<typename T>
        static const object& GetValue(const System::String& keyName, const System::String& valueName, const T& defaultValue) {
          static System::Threading::ThreadLocal<RegistryKey> key;
          System::Array<System::String> subKeys = keyName.Split('\\');
          key.Value =  RegistryKey::OpenBaseKey(ToRegistryHive(subKeys[0]));
          for (int i = 1; i < subKeys.Length; ++i)
            key.Value = key.Value().OpenSubKey(subKeys[i]);
          return key.Value().GetValue(valueName, defaultValue);
        }

        /// @brief Defines the types (or classes) of documents and the properties associated with those types. This field reads the Windows registry base key HKEY_CLASSES_ROOT.
        static RegistryKey ClassesRoot() { return RegistryKey::OpenBaseKey(RegistryHive::ClassesRoot); }

        /// @brief Contains configuration information pertaining to the hardware that is not specific to the user. This field reads the Windows registry base key HKEY_CURRENT_CONFIG.
        static RegistryKey CurrentConfig() { return RegistryKey::OpenBaseKey(RegistryHive::CurrentConfig); }

        /// @brief Contains information about the current user preferences. This field reads the Windows registry base key HKEY_CURRENT_USER
        static RegistryKey CurrentUser() { return RegistryKey::OpenBaseKey(RegistryHive::CurrentUser); }

        /// @brief Contains dynamic registry data. This field reads the Windows registry base key HKEY_DYN_DATA.
        /// @deprecated Replaced by Switch::Microsoft::Win32::Registry::PerformanceData()
        [[deprecated("Replaced by Switch::Microsoft::Win32::Registry::PerformanceData()")]]
        static RegistryKey DynData() { return RegistryKey::OpenBaseKey(RegistryHive::DynData); }

        /// @brief Contains the configuration data for the local machine. This field reads the Windows registry base key HKEY_LOCAL_MACHINE.
        static RegistryKey LocalMachine() { return RegistryKey::OpenBaseKey(RegistryHive::LocalMachine); }

        /// @brief Contains performance information for software components. This field reads the Windows registry base key HKEY_PERFORMANCE_DATA.
        static RegistryKey PerformanceData() { return RegistryKey::OpenBaseKey(RegistryHive::PerformanceData); }

        /// @brief Contains information about the default user configuration. This field reads the Windows registry base key HKEY_USERS.
        static RegistryKey Users() { return RegistryKey::OpenBaseKey(RegistryHive::Users); }
      };
    }
  }
}
