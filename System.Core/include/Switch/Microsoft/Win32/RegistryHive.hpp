/// @file
/// @brief Contains Switch::Microsoft::Win32::RegistryHive enum.
#pragma once

#include "../../System/Enum.hpp"

namespace Switch {
  namespace Microsoft {
    namespace Win32 {
      /// @brief Represents the possible values for a top-level node on a foreign machine.
      enum class RegistryHive {
        /// @brief Represents the HKEY_CLASSES_ROOT base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        ClassesRoot = 0,
        /// @brief Represents the HKEY_CURRENT_USER base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        CurrentUser = 1,
        /// @brief Represents the HKEY_LOCAL_MACHINE base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        LocalMachine = 2,
        /// @brief Represents the HKEY_USERS base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        Users = 3,
        /// @brief Represents the HKEY_PERFORMANCE_DATA base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        PerformanceData = 4,
        /// @brief Represents the HKEY_CURRENT_CONFIG base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        CurrentConfig = 5,
        /// @brief Represents the HKEY_DYN_DATA base key on another computer. This value can be passed to the OpenRemoteBaseKey method, to open this node remotely.
        DynData = 6
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<Microsoft::Win32::RegistryHive> {
  void operator()(System::Collections::Generic::IDictionary<Microsoft::Win32::RegistryHive, string>& values, bool& flags) {
    values[Microsoft::Win32::RegistryHive::ClassesRoot] = "ClassesRoot";
    values[Microsoft::Win32::RegistryHive::CurrentUser] = "CurrentUser";
    values[Microsoft::Win32::RegistryHive::LocalMachine] = "LocalMachine";
    values[Microsoft::Win32::RegistryHive::Users] = "Users";
    values[Microsoft::Win32::RegistryHive::PerformanceData] = "PerformanceData";
    values[Microsoft::Win32::RegistryHive::CurrentConfig] = "CurrentConfig";
    values[Microsoft::Win32::RegistryHive::DynData] = "DynData";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
