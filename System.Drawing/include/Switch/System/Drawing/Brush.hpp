/// @file
/// @brief Contains Switch::System::Drawing::Brush class.
#pragma once

#include <Switch/System/IntPtr.hpp>
#include <Switch/System/Object.hpp>
#include "../../SystemDrawingExport.hpp"

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
    namespace Drawing {
      class system_drawing_export_ Brush : public object, public ICloneable {
      public:
        /// @cond
        Brush(const Brush& brush) = delete;
        Brush& operator=(const Brush& brush) = delete;
        ~Brush();
        /// @endcond

      protected:
        /// @brief Initializes a new instance of the Brush class.
        Brush() {}

        /// @brief In a derived class, sets a reference to a GDI+ brush object.
        /// @param brush A pointer to the GDI+ brush object.
        void SetNativeBrush(intptr brush);
      private:
        friend class Native::GdiApi;
        friend class Windows::Forms::Control;
        intptr GetNativeBrush() const { return this->brush; }

        void ReleaseNativeBrush();

        intptr brush = IntPtr::Zero;
      };
    }
  }
}
