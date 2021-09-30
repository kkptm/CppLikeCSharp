/// @file
/// @brief Contains Switch::System::Drawing::Pen class.
#pragma once

#include <Switch/System/Object.hpp>
#include "../../SystemDrawingExport.hpp"
#include "Drawing2D/DashStyle.hpp"
#include "Brush.hpp"
#include "SolidBrush.hpp"
#include "Color.hpp"

/// @cond
namespace Native {
  class GdiApi;
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    namespace Windows {
      namespace Forms {
        class Control;
      }
    }
    /// @endcond

    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    /// @par Library
    /// Switch.System.Drawing
    namespace Drawing {
      class system_drawing_export_ Pen : public object {
      public:
        Pen() {}

        /// @cond
        ~Pen() { this->Destroy(); }
        Pen(const Pen& pen) : brush(pen.brush), dashStyle(pen.dashStyle), width(pen.width) { this->Create(); }
        Pen& operator=(const Pen& pen) {
          this->brush = pen.brush;
          this->dashStyle = pen.dashStyle;
          this->width = pen.width;
          this->Create();
          return *this;
        }
        /// @endcond

        Pen(const Brush& brush) : brush(as<System::Drawing::Brush>(brush.Clone())) { this->Create(); }

        Pen(const Brush& brush, float width) : brush(as<System::Drawing::Brush>(brush.Clone())), width(width) { this->Create(); }

        Pen(System::Drawing::Color color) : brush(as<System::Drawing::Brush>(ref_new<SolidBrush>(color))) { this->Create(); }

        Pen(System::Drawing::Color color, float width) : brush(as<System::Drawing::Brush>(ref_new<SolidBrush>(color))), width(width) { this->Create(); }

        property_<const System::Drawing::Brush&> Brush{
          get_->const System::Drawing::Brush& { return this->brush(); },
          set_ {this->brush = as<System::Drawing::Brush>(value.Clone()); }
        };

        property_<System::Drawing::Color, readonly_> Color{
          get_{ return as<SolidBrush>(this->brush)().Color(); }
        };

        property_<System::Drawing::Drawing2D::DashStyle> DashStyle {
          get_ {return this->dashStyle;},
          set_ {
            if (this->dashStyle != value) {
              this->dashStyle = value;
              this->Create();
            }
          }
        };

        property_<float> Width{
          get_ {return this->width;},
          set_ {this->width = value;}
        };

      private:
        friend class Native::GdiApi;
        friend class Windows::Forms::Control;
        intptr GetNativePen() const { return this->pen; }
        void Create();
        void Destroy();
        refptr<System::Drawing::Brush> brush  = as<System::Drawing::Brush>(ref_new<SolidBrush>(System::Drawing::Color::Black()));
        System::Drawing::Drawing2D::DashStyle dashStyle = System::Drawing::Drawing2D::DashStyle::Solid;
        float width = 1;
        intptr pen = IntPtr::Zero;
      };
    }
  }
}
