/// @file
/// @brief Contains Switch::System::Windows::Forms::Button class.
#pragma once

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
        /// @brief Represents a standard Windows label.
        /// @remarks Label controls are typically used to provide descriptive text for a control. For example, you can use a Label to add descriptive text for a TextBox control to inform the user about the type of data expected in the control. Label controls can also be used to add descriptive text to a Form to provide the user with helpful information. For example, you can add a Label to the top of a Form that provides instructions to the user on how to input data in the controls on the form. Label controls can be also used to display run time information on the status of an application. For example, you can add a Label control to a form to display the status of each file as a list of files is processed.
        /// @remarks A Label participates in the tab order of a form, but does not receive focus (the next control in the tab order receives focus). For example, if the UseMnemonic property is set to true, and a mnemonic character—the first character after an ampersand (&)—is specified in the Text property of the control, when a user presses ALT+ the mnemonic key, focus moves to the next control in the tab order. This feature provides keyboard navigation for a form. In addition to displaying text, the Label control can also display an image using the Image property, or a combination of the ImageIndex and ImageList properties.
        /// @note A Label can be made transparent by setting its BackColor property to Color.Transparent. When you use a transparent label, use only the current device coordinate system to draw on the container, or the Label background might paint improperly.
        class system_windows_forms_export_ Label : public Control {
        public:
          Label() : Control("", 0, 0, 100, 23) {
            this->SetStyle(ControlStyles::UserPaint, false);
            this->TabStop = false;
          }

          /// @cond
          Label(const Label& label) : Control(label) {}
          /// @endcond

        protected:
          void CreateHandle() override;
          System::Drawing::Size GetDefaultSize() const override { return System::Drawing::Size(100, 23); }
        };
      }
    }
  }
}
