/// @file
/// @brief Contains Switch::System::Windows::Forms::HelpEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include "../../../SystemWindowsFormsExport.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Provides data for the HelpRequested event.
        class system_windows_forms_export_ HelpEventArgs : public EventArgs {
        public:
          /// @brief Initializes a new instance of the HelpEventArgs class.
          HelpEventArgs() : handled(false) {}
          /// @brief Initializes a new instance of the HelpEventArgs class.
          /// @param mousePos The coordinates of the mouse pointer.
          HelpEventArgs(const Switch::System::Drawing::Point& mousePos) : handled(false), mousePos(mousePos) {}

          /// @brief Gets a value indicating whether the help event was handled.
          /// @return true if the event is handled; otherwise, false. The default is false.
          bool Handled() const { return this->handled; }

          /// @brief Gets the screen coordinates of the mouse pointer.
          /// @return A Point representing the screen coordinates of the mouse pointer.
          const Switch::System::Drawing::Point& MousePos() const { return this->mousePos; }

          /// @brief Sets a value indicating whether the help event was handled.
          /// @param handled true if the event is handled; otherwise, false. The default is false.
          void Handled(bool handled) {
            this->handled = handled;
          }

        private:
          bool handled;
          Switch::System::Drawing::Point mousePos;
        };
      }
    }
  }
}
