/// @file
/// @brief Contains Switch::System::Windows::Forms::Button class.
#pragma once

#include <Switch/System/Environment.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "ButtonBase.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a Windows button control.
        /// @remarks A Button can be clicked by using the mouse, ENTER key, or SPACEBAR if the button has focus.
        /// @remarks Set the AcceptButton or CancelButton property of a Form to allow users to click a button by pressing the ENTER or ESC keys even if the button does not have focus. This gives the form the behavior of a dialog box.
        /// @remarks When you display a form using the ShowDialog method, you can use the DialogResult property of a button to specify the return value of ShowDialog.
        /// @remarks You can change the button's appearance. For example, to make it appear flat for a Web look, set the FlatStyle property to FlatStyle.Flat. The FlatStyle property can also be set to FlatStyle.Popup, which appears flat until the mouse pointer passes over the button; then the button takes on the standard Windows button appearance.
        /// @note If the control that has focus accepts and processes the ENTER key press, the Button does not process it. For example, if a multiline TextBox or another button has focus, that control processes the ENTER key press instead of the accept button.
        class system_windows_forms_export_ Button : public ButtonBase {
        public:
          Button() : ButtonBase("", 0, 0, 75, 25) {
            this->SetStyle(ControlStyles::UserPaint, false);
          }
          /// @cond
          Button(const Button& button) : ButtonBase(button), isDefault(button.isDefault) {};
          /// @endcond

          property_<bool> IsDefault {
            get_ {return this->isDefault;},
            set_ {this->SetIsDefault(value);}
          };

        protected:
          void CreateHandle() override;
          System::Drawing::Size GetDefaultSize() const override { return System::Drawing::Size(75, 25); }
          void SetIsDefault(bool isDefault);

          /// @cond
          bool isDefault = false;
          /// @endcond
        };
      }
    }
  }
}
