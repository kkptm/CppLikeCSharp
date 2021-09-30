/// @file
/// @brief Contains Switch::System::Windows::Forms::Form class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include "ContainerControl.hpp"
#include "FormBorderStyle.hpp"
#include "FormClosedEventHandler.hpp"
#include "FormClosingEventHandler.hpp"
#include "FormStartPosition.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a window or dialog box that makes up an application's user interface.
        class system_windows_forms_export_ Form : public ContainerControl {
        public:
          Form() : ContainerControl("", 0, 0, 300, 300) {
            this->visible = false;
            this->SetStyle(ControlStyles::UserPaint, false);
            //this->BackColor = System::Drawing::SystemColors::Window;
          }

          /// @cond
          Form(const Form& form) : ContainerControl(form), formBorderStyle(form.formBorderStyle), maximizeBox(form.maximizeBox), minimizeBox(form.minimizeBox), startPosition(form.startPosition), messageActions(form.messageActions) {}
          /// @endcond

          property_<System::Windows::Forms::FormBorderStyle> FormBorderStyle {
            get_{return this->formBorderStyle;},
            set_{this->formBorderStyle = value;}
          };

          property_<bool> MaximizeBox {
            get_ {return this->maximizeBox;},
            set_ {this->maximizeBox = value;}
          };

          property_<bool> MinimizeBox {
            get_ {return this->minimizeBox;},
            set_ {this->minimizeBox = value;}
          };

          property_<FormStartPosition> StartPosition{
            get_{return this->startPosition;},
            set_{this->startPosition = value;}
          };

          void Close() override;

          void WndProc(Message& message) override;

          FormClosedEventHandler FormClosed;

          FormClosingEventHandler FormClosing;

        protected:
          void CreateHandle() override;
          System::Drawing::Size GetDefaultSize() const override { return System::Drawing::Size(300, 300); }

          virtual void OnFormClosed(const FormClosedEventArgs& e) { this->FormClosed(*this, e); }
          virtual void OnFormClosing(FormClosingEventArgs& e) { this->FormClosing(*this, e); }

          /// @cond
          System::Windows::Forms::FormBorderStyle formBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
          bool maximizeBox = true;
          bool minimizeBox = true;
          System::Windows::Forms::FormStartPosition startPosition = FormStartPosition::WindowsDefaultLocation;
          System::Collections::Generic::Dictionary<int32, Action<Message&>> messageActions;
          /// @endcond

        private:
          void WmClose(Message& message);
        };
      }
    }
  }
}
