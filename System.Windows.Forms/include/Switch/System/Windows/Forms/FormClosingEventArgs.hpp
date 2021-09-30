/// @file
/// @brief Contains Switch::System::Windows::Forms::FormClosingEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "../../ComponentModel/CancelEventArgs.hpp"
#include "CloseReason.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        class system_windows_forms_export_ FormClosingEventArgs : public ComponentModel::CancelEventArgs {
        public:
          FormClosingEventArgs() {}
          FormClosingEventArgs(bool cancel, System::Windows::Forms::CloseReason closeReason) : ComponentModel::CancelEventArgs(cancel), closeReason(closeReason) {}
          FormClosingEventArgs(const FormClosingEventArgs& e) : ComponentModel::CancelEventArgs(e), closeReason(e.closeReason) {}

          property_<System::Windows::Forms::CloseReason, readonly_> CloseReason {
            get_ { return this->closeReason; }
          };

        private:
          System::Windows::Forms::CloseReason closeReason = System::Windows::Forms::CloseReason::UserClosing;
        };
      }
    }
  }
}
