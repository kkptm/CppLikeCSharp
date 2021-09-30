/// @file
/// @brief Contains Switch::System::Windows::Forms::AutoSizeMode class.
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
        /// @brief Specifies how a control will behave when its AutoSize property is enabled.
        /// @remarks Setting the GrowAndShrink value produces the same behavior that you get for controls with the AutoSize property enabled but which have no
        /// @remarks AutoSizeMode property. The MinimumSize and MaximumSize properties are respected, but the current value of the Size property is ignored.
        enum class AutoSizeMode {
          /// @brief The control grows or shrinks to fit its contents. The control cannot be resized manually.
          GrowAndShrink,
          /// @brief The control grows as much as necessary to fit its contents but does not shrink smaller than the value of its Size property. The form can be resized, but cannot be made so small that any of its contained controls are hidden.
          GrowOnly,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::AutoSizeMode> {
public:
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::AutoSizeMode, string>& values, bool& flags) {
    values[System::Windows::Forms::AutoSizeMode::GrowAndShrink] = "GrowAndShrink";
    values[System::Windows::Forms::AutoSizeMode::GrowOnly] = "GrowOnly";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
