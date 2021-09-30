/// @file
/// @brief Contains Switch::System::Windows::Forms::MouseEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/Point.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "MouseButtons.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        class system_windows_forms_export_ MouseEventArgs : public EventArgs {
        public:
          MouseEventArgs() {}

          MouseEventArgs(MouseButtons button, const System::Drawing::Point& location, int32 clicks, int32 delta) : button(button), location(location), clicks(clicks), delta(delta) {}
          MouseEventArgs(MouseButtons button, int32 x, int32 y, int32 clicks, int32 delta) : button(button), location(x, y), clicks(clicks), delta(delta) {}

          /// @cond
          MouseEventArgs(const MouseEventArgs& mouseEventArgs) : button(mouseEventArgs.button), location(mouseEventArgs.location), clicks(mouseEventArgs.clicks), delta(mouseEventArgs.delta) {}
          MouseEventArgs& operator =(const MouseEventArgs& mouseEventArgs) {
            this->button = mouseEventArgs.button;
            this->location = mouseEventArgs.location;
            this->clicks = mouseEventArgs.clicks;
            this->delta = mouseEventArgs.delta;
            return *this;
          }
          /// @endcond

          property_<MouseButtons, readonly_> Button {
            get_ {return this->button;}
          };

          property_<const System::Drawing::Point&, readonly_> Location {
            get_->const System::Drawing::Point& {return this->location;}
          };

          property_<int32, readonly_> Clicks {
            get_ {return this->clicks;}
          };

          property_<int32, readonly_> Delta {
            get_ {return this->delta;}
          };

          property_<int32, readonly_> X {
            get_ {return this->Location().X();}
          };

          property_<int32, readonly_> Y {
            get_ {return this->Location().Y();}
          };

        private:
          MouseButtons button;
          System::Drawing::Point location;
          int32 clicks = 0;
          int32 delta = 0;
        };
      }
    }
  }
}
