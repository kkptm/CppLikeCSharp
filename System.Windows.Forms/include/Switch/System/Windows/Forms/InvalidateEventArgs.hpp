/// @file
/// @brief Contains Switch::System::Windows::Forms::InvalidateEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/Rectangle.hpp>
#include "../../../SystemWindowsFormsExport.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Provides data for the Invalidated event.
        class system_windows_forms_export_ InvalidateEventArgs : public EventArgs {
        public:
          /// @brief Initializes a new instance of the InvalidateEventArgs class.
          /// @param invalidRect The Rectangle that contains the invalidated window area.
          InvalidateEventArgs(const Switch::System::Drawing::Rectangle& invalidRect) : invalidRect(invalidRect) {}

          /// @brief Gets the Rectangle that contains the invalidated window area.
          /// @return The invalidated window area.
          const Switch::System::Drawing::Rectangle& InvalidRect() const { return this->invalidRect; }

        private:
          Switch::System::Drawing::Rectangle invalidRect;
        };
      }
    }
  }
}
