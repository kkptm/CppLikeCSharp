/// @file
/// @brief Contains Switch::System::Drawing::SolidBrush class.
#pragma once

#include "../../SystemDrawingExport.hpp"
#include "Brush.hpp"
#include "Color.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      class system_drawing_export_ SolidBrush : public Brush {
      public:
        explicit SolidBrush(const System::Drawing::Color& color);
        SolidBrush(const SolidBrush& brush) : SolidBrush(brush.color) {}
        SolidBrush& operator=(const SolidBrush& brush);

        property_<System::Drawing::Color, readonly_> Color {
          get_ {return this->color;}
        };

        refptr<object> Clone() const override {return ref_new<SolidBrush>(this->color);};

      private:
        System::Drawing::Color color;
      };
    }
  }
}
