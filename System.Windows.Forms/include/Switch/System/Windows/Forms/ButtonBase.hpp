/// @file
/// @brief Contains Switch::System::Windows::Forms::ButtonBase class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include "Control.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a Windows button control.
        class system_windows_forms_export_ ButtonBase : public Control {
        public:
          ButtonBase() : autoElipsis(false) {}
          ButtonBase(const string& text, int32 left, int32 top, int32 height, int32 width) : Control(text, left, top, height, width), autoElipsis(false) {}

          /// @cond
          ButtonBase(const ButtonBase& buttonBase) : Control(buttonBase) {}
          /// @endcond

          bool AutoElispis() const {
            return this->autoElipsis;
          }

          void AutoElipsis(bool autoElipsis) {
            this->autoElipsis = autoElipsis;
          }

        private:
          bool autoElipsis;
        };
      }
    }
  }
}
