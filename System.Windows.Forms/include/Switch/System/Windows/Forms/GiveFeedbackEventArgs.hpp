/// @file
/// @brief Contains Switch::System::Windows::Forms::GiveFeedbackEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "DragDropEffects.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Provides data for the GiveFeedback event, which occurs during a drag operation.
        class system_windows_forms_export_ GiveFeedbackEventArgs : public EventArgs {
        public:
          /// @brief Initializes a new instance of the GiveFeedbackEventArgs class.
          GiveFeedbackEventArgs() : useDefaultCursors(true) {}
          /// @brief Initializes a new instance of the GiveFeedbackEventArgs class.
          /// @param effects The type of drag-and-drop operation. Possible values are obtained by applying the bitwise OR (|) operation to the constants defined in the DragDropEffects.
          /// @param true if default pointers are used; otherwise, false.
          GiveFeedbackEventArgs(DragDropEffects effect, bool useDefaultCursors) : effect(effect), useDefaultCursors(useDefaultCursors) {}

          /// @brief Gets the drag-and-drop operation feedback that is displayed.
          /// @return One of the DragDropEffects values.
          DragDropEffects Effect() const { return this->effect; }

          /// @brief Gets whether drag operation should use the default cursors that are associated with drag-drop effects.
          /// @return true if the default pointers are used; otherwise, false.
          bool UseDefaultCursors() const { return this->useDefaultCursors; }

          /// @brief Sets whether drag operation should use the default cursors that are associated with drag-drop effects.
          /// @param useDefaultCursors true if the default pointers are used; otherwise, false.
          void UseDefaultCursors(bool useDefaultCursors) { this->useDefaultCursors = useDefaultCursors; }

        private:
          DragDropEffects effect;
          bool useDefaultCursors;
        };
      }
    }
  }
}
