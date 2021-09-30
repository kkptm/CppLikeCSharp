/// @file
/// @brief Contains Switch::System::Windows::Forms::MessageBox class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include "DialogResult.hpp"
#include "Form.hpp"
#include "MessageBoxButtons.hpp"
#include "MessageBoxDefaultButton.hpp"
#include "MessageBoxIcon.hpp"
#include "MessageBoxOptions.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a window or dialog box that makes up an application's user interface.
        class system_windows_forms_export_ MessageBox : public Form {
        public:
          static DialogResult Show(const string& message) {return MessageBox::Show(message, "", MessageBoxButtons::OK, MessageBoxIcon::None, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, false);}

          static DialogResult Show(const string& message, const string& caption) {return Show(message, caption, MessageBoxButtons::OK, MessageBoxIcon::None, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, false);}

          static DialogResult Show(const string& message, const string& caption, MessageBoxButtons buttons) {return Show(message, caption, buttons, MessageBoxIcon::None, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, false);}

          static DialogResult Show(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon) {return Show(message, caption, buttons, icon, MessageBoxDefaultButton::Button1, (MessageBoxOptions)0, false);}

          static DialogResult Show(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton) {return Show(message, caption, buttons, icon, defaultButton, (MessageBoxOptions)0, false);}

          static DialogResult Show(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options) {return Show(message, caption, buttons, icon, defaultButton, options, false);}

          static DialogResult Show(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton);

        private:
          MessageBox() = delete;
        };
      }
    }
  }
}
