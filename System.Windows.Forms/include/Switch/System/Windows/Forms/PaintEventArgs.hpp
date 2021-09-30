/// @file
/// @brief Contains Switch::System::Windows::Forms::PaintEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/Graphics.hpp>
#include <Switch/System/Drawing/Rectangle.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "Keys.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @cond
        class Control;
        /// @endcond

        class system_windows_forms_export_ PaintEventArgs : public EventArgs {
        public:
          PaintEventArgs() {}
          PaintEventArgs(const System::Drawing::Rectangle& clipRectangle, System::Drawing::Graphics& graphics) : clipRectangle(clipRectangle), graphics(&graphics) {}
          /// @cond
          PaintEventArgs(const PaintEventArgs& paintEventArgs) : clipRectangle(paintEventArgs.clipRectangle), graphics(paintEventArgs.graphics) {}
          PaintEventArgs& operator =(const PaintEventArgs& paintEventArgs) {
            this->clipRectangle = paintEventArgs.clipRectangle;
            this->graphics = paintEventArgs.graphics;
            return *this;
          }
          /// @endcond

          property_<const System::Drawing::Rectangle&, readonly_> ClipRectangle {
            get_->const System::Drawing::Rectangle& {return this->clipRectangle;}
          };

          property_<System::Drawing::Graphics&, readonly_> Graphics {
            get_->System::Drawing::Graphics& {return *this->graphics;}
          };

        private:
          System::Drawing::Rectangle clipRectangle;
          System::Drawing::Graphics* graphics = null;
        };
      }
    }
  }
}
