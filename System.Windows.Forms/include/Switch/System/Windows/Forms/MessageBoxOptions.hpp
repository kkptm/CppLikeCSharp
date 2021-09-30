/// @file
/// @brief Contains Switch::System::Windows::Forms::MessageBoxButtons enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies options on a MessageBox.
        /// This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
        /// @remarks This enumeration is used by the MessageBox class.
        /// @remarks If you do not want to specify this parameter when calling methods on MessageBox, you can pass in 0 instead.
        enum class MessageBoxOptions {
          /// @brief The message box is displayed on the active desktop.
          DefaultDesktopOnly = 0x00020000L,
          /// @brief The message box text is right-aligned.
          RightAlign = 0x00080000L,
          /// @brief Specifies that the message box text is displayed with right to left reading order.
          RtlReading = 0x00100000L,
          /// @brief The message box is displayed on the active desktop.
          ServiceNotification = 0x00200000L
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::MessageBoxOptions> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::MessageBoxOptions, string>& values, bool& flags) {
    values[System::Windows::Forms::MessageBoxOptions::DefaultDesktopOnly] = "DefaultDesktopOnly";
    values[System::Windows::Forms::MessageBoxOptions::RightAlign] = "RightAlign";
    values[System::Windows::Forms::MessageBoxOptions::RtlReading] = "RtlReading";
    values[System::Windows::Forms::MessageBoxOptions::ServiceNotification] = "ServiceNotification";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
