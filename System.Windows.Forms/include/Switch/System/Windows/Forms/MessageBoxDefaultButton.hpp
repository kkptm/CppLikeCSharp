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
        /// @brief Specifies constants defining the default button on a MessageBox.
        /// @remarks This enumeration is used by the MessageBox class.
        enum class MessageBoxDefaultButton {
          /// @brief The first button on the message box is the default button.
          Button1 = 0,
          /// @brief The second button on the message box is the default button.
          Button2 = 0x00000100L,
          /// @brief The third button on the message box is the default button.
          Button3 = 0x00000200L
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::MessageBoxDefaultButton> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::MessageBoxDefaultButton, string>& values, bool& flags) {
    values[System::Windows::Forms::MessageBoxDefaultButton::Button1] = "Button1";
    values[System::Windows::Forms::MessageBoxDefaultButton::Button2] = "Button2";
    values[System::Windows::Forms::MessageBoxDefaultButton::Button3] = "Button3";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
