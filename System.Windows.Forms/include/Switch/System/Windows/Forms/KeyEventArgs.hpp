/// @file
/// @brief Contains Switch::System::Windows::Forms::KeyEventArgs class.
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

        /// @brief Provides data for the KeyDown or KeyUp event.
        /// @remarks A KeyEventArgs, which specifies the key the user pressed and whether any modifier keys (CTRL, ALT, and SHIFT) were pressed at the same time, is passed with each KeyDown or KeyUp event.
        /// @remarks The KeyDown event occurs when the user presses any key. The KeyUp event occurs when the user releases the key. Duplicate KeyDown events occur each time the key repeats, if the key is held down, but only one KeyUp event is generated when the user releases the key.
        /// @remarks The KeyPress event also occurs when a key is pressed. A KeyPressEventArgs is passed with each KeyPress event, and specifies the character that was composed as a result of each key press.
        /// @remarks For information about the event model, see Handling and Raising Events.
        class system_windows_forms_export_ KeyEventArgs : public EventArgs {
        public:
          /// @brief Initializes a new instance of the KeyEventArgs class.
          KeyEventArgs() {}
          /// @brief Initializes a new instance of the KeyEventArgs class for the specified keys.
          /// @param keyData A Keys representing the key that was pressed, combined with any modifier flags that indicate which CTRL, SHIFT, and ALT keys were pressed at the same time. Possible values are obtained be applying the bitwise OR (|) operator to constants from the Keys enumeration.
          KeyEventArgs(const Keys& keyData) : keyData(keyData), handled(false), suppressKeyPress(false) {}

          /// @cond
          KeyEventArgs(const KeyEventArgs& keyEventArgs) : keyData(keyEventArgs.keyData), handled(keyEventArgs.handled), suppressKeyPress(keyEventArgs.suppressKeyPress) {}
          KeyEventArgs& operator =(const KeyEventArgs& keyEventArgs) {
            this->keyData = keyEventArgs.keyData;
            this->handled = keyEventArgs.handled;
            this->suppressKeyPress = keyEventArgs.suppressKeyPress;
            return *this;
          }
          /// @endcond

          property_<bool, readonly_> Alt {
            get_ {return Enum<Keys>(this->keyData).HasFlag(Keys::Alt);}
          };

          property_<bool, readonly_> Command {
            get_ {return Enum<Keys>(this->keyData).HasFlag(Keys::Command);}
          };

          property_<bool, readonly_> Control {
            get_ {return Enum<Keys>(this->keyData).HasFlag(Keys::Control);}
          };

          property_<bool> Handled {
            get_ {return this->handled;},
            set_ {this->handled = value;}
          };

          property_<Keys, readonly_> KeyCode {
            get_ {return Keys(this->keyData & Keys::KeyCode);}
          };

          /// @brief Gets the key data for a KeyDown or KeyUp event.
          /// @return A Keys representing the key code for the key that was pressed, combined with modifier flags that indicate which combination of CTRL, SHIFT, and ALT keys was pressed at the same time.
          /// @remarks You can use constants from Keys to extract information from the KeyData property. Use the bitwise AND operator to compare data returned by KeyData with constants in Keys to obtain information about which keys the user pressed. To determine whether a specific modifier key was pressed, use the Control, Shift, and Alt properties.
          property_<Keys, readonly_> KeyData {
            get_ {return this->keyData;}
          };

          property_<int32, readonly_> KeyValue {
            get_ {return (int32)(this->keyData) & 0xFFFF;}
          };

          property_<Keys, readonly_> Modifiers {
            get_ {return Keys(this->keyData & Keys::Modifiers);}
          };

          property_<bool, readonly_> Shift {
            get_ {return Enum<Keys>(this->keyData).HasFlag(Keys::Shift);}
          };

          property_<bool> SuppressKeyPress {
            get_ {return this->suppressKeyPress;},
            set_ {this->suppressKeyPress = value;}
          };

        private:
          Keys keyData;
          bool handled = false;
          bool suppressKeyPress = false;
        };
      }
    }
  }
}
