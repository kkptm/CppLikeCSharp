/// @file
/// @brief Contains Switch::Microsoft::Win32::RegistryValueKind enum.
#pragma once

#include "../../System/Enum.hpp"

namespace Switch {
  /// @brief The Microsoft namespace provide Microsoft specific classes.
  namespace Microsoft {
    /// @brief The Microsoft::Win32 namespace provides two types of classes: those that handle events raised by the operating system and those that manipulate the system registry.
    namespace Win32 {
      /// @brief Specifies options to use when creating a registry key.
      /// @remarks You can create a registry key that is available only in memory and that will not be persisted when the computer is restarted. This is known as a volatile key. You can specify that you want to create a volatile or non-volatile key by using the RegistryKey.CreateSubKey method overloads that take an options parameter.
      enum class RegistryValueKind {
        /// @brief An unsupported registry data type. For example, the Microsoft Win32 API registry data type REG_RESOURCE_LIST is unsupported. Use this value to specify that the SetValue method should determine the appropriate registry data type when storing a name/value pair.
        Unknown = 0,
        /// @brief A null-terminated string. This value is equivalent to the Win32 API registry data type REG_SZ.
        String = 1,
        /// @brief A null-terminated string that contains unexpanded references to environment variables, such as %PATH%, that are expanded when the value is retrieved. This value is equivalent to the Win32 API registry data type REG_EXPAND_SZ.
        ExpandString = 2,
        /// @brief Binary data in any form. This value is equivalent to the Win32 API registry data type REG_BINARY.
        Binary = 3,
        /// @brief A 32-bit binary number. This value is equivalent to the Win32 API registry data type REG_DWORD.
        DWord = 4,
        /// @brief An array of null-terminated strings, terminated by two null characters. This value is equivalent to the Win32 API registry data type REG_MULTI_SZ.
        MultiString = 7,
        /// @brief A 64-bit binary number. This value is equivalent to the Win32 API registry data type REG_QWORD.
        QWord = 11,
        /// @brief No data type.
        None = -1
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<Microsoft::Win32::RegistryValueKind> {
  void operator()(System::Collections::Generic::IDictionary<Microsoft::Win32::RegistryValueKind, string>& values, bool& flags) {
    values[Microsoft::Win32::RegistryValueKind::Unknown] = "Unknown";
    values[Microsoft::Win32::RegistryValueKind::String] = "String";
    values[Microsoft::Win32::RegistryValueKind::ExpandString] = "ExpandString";
    values[Microsoft::Win32::RegistryValueKind::Binary] = "Binary";
    values[Microsoft::Win32::RegistryValueKind::DWord] = "DWord";
    values[Microsoft::Win32::RegistryValueKind::MultiString] = "MultiString";
    values[Microsoft::Win32::RegistryValueKind::QWord] = "QWord";
    values[Microsoft::Win32::RegistryValueKind::None] = "None";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
