/// @file
/// @brief Contains Switch::System::Windows::Forms::DialogResult class.
#pragma once

#include <Switch/System/Enum.hpp>

#include "Control.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        enum class DialogResult {
          None = 0,
          OK = 1,
          Cancel = 2,
          Abort = 3,
          Retry = 4,
          Ignore = 5,
          Yes = 6,
          No = 7
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::DialogResult> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::DialogResult, string>& values, bool& flags) {
    values[System::Windows::Forms::DialogResult::None] = "None";
    values[System::Windows::Forms::DialogResult::OK] = "OK";
    values[System::Windows::Forms::DialogResult::Cancel] = "Cancel";
    values[System::Windows::Forms::DialogResult::Abort] = "Abort";
    values[System::Windows::Forms::DialogResult::Retry] = "Retry";
    values[System::Windows::Forms::DialogResult::Ignore] = "Ignore";
    values[System::Windows::Forms::DialogResult::Yes] = "Yes";
    values[System::Windows::Forms::DialogResult::No] = "No";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
