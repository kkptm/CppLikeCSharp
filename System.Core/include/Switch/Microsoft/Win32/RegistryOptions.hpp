/// @file
/// @brief Contains Switch::Microsoft::Win32::RegistryOptions enum.
#pragma once

#include "../../System/Enum.hpp"

namespace Switch {
  /// @brief The Microsoft namespace provide Microsoft specific classes.
  namespace Microsoft {
    /// @brief The Microsoft::Win32 namespace provides two types of classes: those that handle events raised by the operating system and those that manipulate the system registry.
    namespace Win32 {
      /// @brief Specifies options to use when creating a registry key.
      /// @remarks You can create a registry key that is available only in memory and that will not be persisted when the computer is restarted. This is known as a volatile key. You can specify that you want to create a volatile or non-volatile key by using the RegistryKey.CreateSubKey method overloads that take an options parameter.
      enum class RegistryOptions {
        /// @brief A non-volatile key. This is the default.
        None = 0,
        /// @brief A volatile key. The information is stored in memory and is not preserved when the corresponding registry hive is unloaded.
        Volatile = 1
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<Microsoft::Win32::RegistryOptions> {
  void operator()(System::Collections::Generic::IDictionary<Microsoft::Win32::RegistryOptions, string>& values, bool& flags) {
    values[Microsoft::Win32::RegistryOptions::None] = "None";
    values[Microsoft::Win32::RegistryOptions::Volatile] = "Volatile";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
