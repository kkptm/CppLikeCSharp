/// @file
/// @brief Contains Switch::System::Windows::Forms::FormStartPosition enum.
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
        /// @brief Specifies the initial position of a form.
        enum class FormStartPosition {
          /// @brief The position of the form is determined by the Location property.
          Manual,
          /// @brief The form is centered on the current display, and has the dimensions specified in the form's size.
          CenterScreen,
          /// @brief The form is positioned at the Windows default location and has the dimensions specified in the form's size.
          WindowsDefaultLocation,
          /// @brief The form is positioned at the Windows default location and has the bounds determined by Windows default.
          WindowsDefaultBounds,
          /// @brief The form is centered within the bounds of its parent form.
          CenterParent
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::FormStartPosition> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::FormStartPosition, string>& values, bool& flags) {
    values[System::Windows::Forms::FormStartPosition::Manual] = "Manual";
    values[System::Windows::Forms::FormStartPosition::CenterScreen] = "CenterScreen";
    values[System::Windows::Forms::FormStartPosition::WindowsDefaultLocation] = "WindowsDefaultLocation";
    values[System::Windows::Forms::FormStartPosition::WindowsDefaultBounds] = "WindowsDefaultBounds";
    values[System::Windows::Forms::FormStartPosition::CenterParent] = "CenterParent";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
