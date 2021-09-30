/// @file
/// @brief Contains Switch::System::Windows::Forms::KeyPressEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "Keys.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        class system_windows_forms_export_ KeyPressEventArgs : public EventArgs {
        public:
          KeyPressEventArgs() {}
          KeyPressEventArgs(char32 keyChar) : keyChar(keyChar), handled(false) {}

          /// @cond
          KeyPressEventArgs(const KeyPressEventArgs& keyPressEventArgs): keyChar(keyPressEventArgs.keyChar), handled(keyPressEventArgs.handled) {}
          KeyPressEventArgs& operator =(const KeyPressEventArgs& keyPressEventArgs) {
            this->keyChar = keyPressEventArgs.keyChar;
            this->handled = keyPressEventArgs.handled;
            return *this;
          }
          /// @endcond

          property_<bool> Handled {
            get_ {return this->handled;},
            set_ {this->handled = value;}
          };

          property_<char32, readonly_> KeyChar {
            get_ {return this->keyChar;}
          };

        private:
          char32 keyChar = 0;
          bool handled = false;
        };
      }
    }
  }
}
