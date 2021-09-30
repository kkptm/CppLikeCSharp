/// @file
/// @brief Contains Switch::System::Windows::Forms::DragEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>

#include "../../../SystemWindowsFormsExport.hpp"
#include "DragDropEffects.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Contains arguments relevant to all drag-and-drop events (DragEnter, DragLeave, DragOver, and Drop).
        /// @remarks The DragDrop event occurs when the user completes a drag-and-drop operation by dragging an object over the control and then dropping it onto the control by releasing the mouse button. The DragEnter event occurs when the user moves the mouse pointer onto the control while dragging an object with the mouse. The DragOver event occurs when the user moves the mouse pointer over the control while dragging an object with the mouse.
        /// @remarks A DragEventArgs object specifies any data associated with this event; the current state of the SHIFT, CTRL, and ALT keys; the location of the mouse pointer; and the drag-and-drop effects allowed by the source and target of the drag event.
        /// @remarks For information about the event model, see Handling and Raising Events.
        /// @remarks The following example demonstrates a drag-and-drop operation between two ListBox controls. The example calls the DoDragDrop method when the drag action starts. The drag action starts if the mouse has moved more than SystemInformation.DragSize from the mouse location during the MouseDown event. The IndexFromPoint method is used to determine the index of the item to drag during the MouseDown event.
        /// @remarks The example also demonstrates using custom cursors for the drag-and-drop operation. The example assumes that two cursor files, 3dwarro.cur and 3dwno.cur, exist in the application directory, for the custom drag and no-drop cursors, respectively. The custom cursors will be used if the UseCustomCursorsCheck CheckBox is checked. The custom cursors are set in the GiveFeedback event handler.
        /// @remarks The keyboard state is evaluated in the DragOver event handler for the right ListBox, to determine what the drag operation will be based upon state of the SHIFT, CTRL, ALT, or CTRL+ALT keys. The location in the ListBox where the drop would occur is also determined during the DragOver event. If the data to drop is not a String, then the DragEventArgs.Effect is set to DragDropEffects.None. Finally, the status of the drop is displayed in the DropLocationLabel Label.
        /// @remarks The data to drop for the right ListBox is determined in the DragDrop event handler and the String value is added at the appropriate place in the ListBox. If the drag operation moves outside the bounds of the form, then the drag-and-drop operation is canceled in the QueryContinueDrag event handler.
        /// @par Examples
        /// This code excerpt demonstrates using the DragEventArgs class. See the DoDragDrop method for the complete code example.
        /// @code
        /// void ListDragTarget_DragOver(const object& sender, System::Windows::Forms::DragEventArgs& e) {
        ///   // Determine whether string data exists in the drop data. If not, then
        ///   // the drop effect reflects that the drop cannot occur.
        ///   if (!e.GetData().GetDataPresent<System::String>())) {
        ///     e.Effect(DragDropEffects::None);
        ///     DropLocationLabel->Text("None - no string data.");
        ///     return;
        ///   }
        ///   // Set the effect based upon the KeyState.
        ///   if ((e.KeyState() & (8+32)) == (8+32) && (e.AllowedEffect() & DragDropEffects::Link) == DragDropEffects::Link) {
        ///     // KeyState 8 + 32 = CTL + ALT
        ///     // Link drag-and-drop effect.
        ///     e.Effect(DragDropEffects::Link);
        ///   } else if ((e.KeyState() & 32) == 32 && (e.AllowedEffect() & DragDropEffects::Link) == DragDropEffects::Link) {
        ///     // ALT KeyState for link.
        ///     e.Effect(DragDropEffects::Link);
        ///   } else if ((e.KeyState() & 4) == 4 && (e.AllowedEffect() & DragDropEffects::Move) == DragDropEffects::Move) {
        ///     // SHIFT KeyState for move.
        ///     e.Effect(DragDropEffects::Move);
        ///   } else if ((e.KeyState() & 8) == 8 && (e.AllowedEffect() & DragDropEffects::Copy) == DragDropEffects::Copy) {
        ///     // CTL KeyState for copy.
        ///     e.Effect(DragDropEffects::Copy);
        ///   } else if ((e.AllowedEffect() & DragDropEffects::Move) == DragDropEffects::Move) {
        ///     // By default, the drop action should be move, if allowed.
        ///     e.Effect(DragDropEffects::Move);
        ///   } else
        ///     e.Effect(DragDropEffects::None);
        ///   // Get the index of the item the mouse is below.
        ///   // The mouse locations are relative to the screen, so they must be
        ///   // converted to client coordinates.
        ///   indexOfItemUnderMouseToDrop =
        ///   ListDragTarget->SetIndexFromPoint(ListDragTarget->SetPointToClient(Point(e.X, e.Y)));
        ///   // Updates the label text.
        ///   if (indexOfItemUnderMouseToDrop != ListBox->NoMatches()) {
        ///     DropLocationLabel->Text("Drops before item #" + (indexOfItemUnderMouseToDrop + 1));
        ///   } else {
        ///     DropLocationLabel->Text("Drops at the end.");
        ///   }
        /// }
        /// @endcode
        class system_windows_forms_export_ DragEventArgs : public EventArgs {
        public:
          /// @brief Initializes a new instance of the DragEventArgs class.
          DragEventArgs() {}
          /// @brief Initializes a new instance of the ControlEventArgs class for the specified control.
          DragEventArgs(const object& data, DragDropEffects allowedEffect, DragDropEffects effect, int32 keystate, int32 x, int32 y) : data(&data), allowedEffect(allowedEffect), effect(effect), keyState(keystate), x(x), y(y) {}

          /// @cond
          DragEventArgs(const DragEventArgs& dragEventArgs) : data(dragEventArgs.data), allowedEffect(dragEventArgs.allowedEffect), effect(dragEventArgs.effect), keyState(dragEventArgs.keyState), x(dragEventArgs.x), y(dragEventArgs.y) {}
          DragEventArgs& operator =(const DragEventArgs dragEventArgs) {
            this->data = dragEventArgs.data;
            this->allowedEffect = dragEventArgs.allowedEffect;
            this->effect = dragEventArgs.effect;
            this->keyState = dragEventArgs.keyState;
            this->x = dragEventArgs.x;
            this->y = dragEventArgs.y;
            return *this;
          }
          /// @endcond

          /// @brief Gets which drag-and-drop operations are allowed by the originator (or source) of the drag event.
          /// @return One of the DragDropEffects values.
          property_<DragDropEffects, readonly_> AllowedEffect {
            get_ {return this->allowedEffect;}
          };

          property_<const object&, readonly_> Data {
            get_->const object& {return *this->data;}
          };

          /// @brief Gets or sets the target drop effect in a drag-and-drop operation.
          /// @param value One of the DragDropEffects values.
          /// By default, the effect applied determines the mouse cursor for the target of a drag-and-drop operation. This is useful to provide feedback to the user on the operation that will occur. For example, if you press the CTRL key when you drag a file from a source, specify DragDropEffects.Copy to indicate the target will try to perform a copy operation.
          /// @remarks To use custom cursors for a drag operation, see GiveFeedbackEventArgs.UseDefaultCursors.
          /// @remarks The following example demonstrates a drag-and-drop operation between two ListBox controls. The example calls the DoDragDrop method when the drag action starts. The drag action starts if the mouse has moved more than SystemInformation.DragSize from the mouse location during the MouseDown event. The IndexFromPoint method is used to determine the index of the item to drag during the MouseDown event.
          /// @remarks The example also demonstrates using custom cursors for the drag-and-drop operation. The example assumes that two cursor files, 3dwarro.cur and 3dwno.cur, exist in the application directory, for the custom drag and no-drop cursors, respectively. The custom cursors will be used if the UseCustomCursorsCheck CheckBox is checked. The custom cursors are set in the GiveFeedback event handler.
          /// @remarks The keyboard state is evaluated in the DragOver event handler for the right ListBox, to determine what the drag operation will be based upon state of the SHIFT, CTRL, ALT, or CTRL+ALT keys. The location in the ListBox where the drop would occur is also determined during the DragOver event. If the data to drop is not a String, then the DragEventArgs.Effect is set to DragDropEffects.None. Finally, the status of the drop is displayed in the DropLocationLabel Label.
          /// @remarks The data to drop for the right ListBox is determined in the DragDrop event handler and the String value is added at the appropriate place in the ListBox. If the drag operation moves outside the bounds of the form, then the drag-and-drop operation is canceled in the QueryContinueDrag event handler.
          /// @par Examples
          /// This code excerpt demonstrates using the DragEventArgs class. See the DoDragDrop method for the complete code example.
          /// @code
          /// void ListDragTarget_DragOver(const object& sender, System::Windows::Forms::DragEventArgs& e) {
          ///   // Determine whether string data exists in the drop data. If not, then
          ///   // the drop effect reflects that the drop cannot occur.
          ///   if (!e.GetData().GetDataPresent<System::String>())) {
          ///     e.Effect(DragDropEffects::None);
          ///     DropLocationLabel->Text("None - no string data.");
          ///     return;
          ///   }
          ///   // Set the effect based upon the KeyState.
          ///   if ((e.KeyState() & (8+32)) == (8+32) && (e.AllowedEffect() & DragDropEffects::Link) == DragDropEffects::Link) {
          ///     // KeyState 8 + 32 = CTL + ALT
          ///     // Link drag-and-drop effect.
          ///     e.Effect(DragDropEffects::Link);
          ///   } else if ((e.KeyState() & 32) == 32 && (e.AllowedEffect() & DragDropEffects::Link) == DragDropEffects::Link) {
          ///     // ALT KeyState for link.
          ///     e.Effect(DragDropEffects::Link);
          ///   } else if ((e.KeyState() & 4) == 4 && (e.AllowedEffect() & DragDropEffects::Move) == DragDropEffects::Move) {
          ///     // SHIFT KeyState for move.
          ///     e.Effect(DragDropEffects::Move);
          ///   } else if ((e.KeyState() & 8) == 8 && (e.AllowedEffect() & DragDropEffects::Copy) == DragDropEffects::Copy) {
          ///     // CTL KeyState for copy.
          ///     e.Effect(DragDropEffects::Copy);
          ///   } else if ((e.AllowedEffect() & DragDropEffects::Move) == DragDropEffects::Move) {
          ///     // By default, the drop action should be move, if allowed.
          ///     e.Effect(DragDropEffects::Move);
          ///   } else
          ///     e.Effect(DragDropEffects::None);
          ///   // Get the index of the item the mouse is below.
          ///   // The mouse locations are relative to the screen, so they must be
          ///   // converted to client coordinates.
          ///   indexOfItemUnderMouseToDrop =
          ///   ListDragTarget->SetIndexFromPoint(ListDragTarget->SetPointToClient(Point(e.X, e.Y)));
          ///   // Updates the label text.
          ///   if (indexOfItemUnderMouseToDrop != ListBox->NoMatches()) {
          ///     DropLocationLabel->Text("Drops before item #" + (indexOfItemUnderMouseToDrop + 1));
          ///   } else {
          ///     DropLocationLabel->Text("Drops at the end.");
          ///   }
          /// }
          /// @endcode
          property_<DragDropEffects> Effect {
            get_ {return this->effect;},
            set_ {this->effect = value;}
          };

          /// @brief Gets the current state of the SHIFT, CTRL, and ALT keys, as well as the state of the mouse buttons.
          /// @return The current state of the SHIFT, CTRL, and ALT keys and of the mouse buttons.
          /// You can make the effect of a drag-and-drop operation to depend on the state of a particular key. For example, you may decide to copy or move data depending on whether the CTRL or SHIFT keys are pressed during the drag-and-drop operation.
          /// @remarks The bits that are set in the KeyState property identify the keys or mouse buttons that were pressed during the operation. For example, if the left mouse button is pressed, the first bit in the KeyState property is set. You can use the bitwise AND operator to test for a given key state.
          /// @remarks The following table lists the values that are used for a specified event.
          /// | Value      | Key                      |
          /// |------------|--------------------------|
          /// | 1 (bit 0)  | The left mouse button.   |
          /// | 2 (bit 1)  | The right mouse button.  |
          /// | 4 (bit 2)  | The SHIFT key.           |
          /// | 8 (bit 3)  | The CTRL key.            |
          /// | 16 (bit 4) | The middle mouse button. |
          /// | 32 (bit 5) | The ALT key.             |
          /// | 64 (bit 6) | The CMD key.             |
          /// @remarks The following example demonstrates a drag-and-drop operation between two ListBox controls. The example calls the DoDragDrop method when the drag action starts. The drag action starts if the mouse has moved more than SystemInformation.DragSize from the mouse location during the MouseDown event. The IndexFromPoint method is used to determine the index of the item to drag during the MouseDown event.
          /// @remarks The example also demonstrates using custom cursors for the drag-and-drop operation. The example assumes that two cursor files, 3dwarro.cur and 3dwno.cur, exist in the application directory, for the custom drag and no-drop cursors, respectively. The custom cursors will be used if the UseCustomCursorsCheck CheckBox is checked. The custom cursors are set in the GiveFeedback event handler.
          /// @remarks The keyboard state is evaluated in the DragOver event handler for the right ListBox, to determine what the drag operation will be based upon state of the SHIFT, CTRL, ALT, or CTRL+ALT keys. The location in the ListBox where the drop would occur is also determined during the DragOver event. If the data to drop is not a String, then the DragEventArgs.Effect is set to DragDropEffects.None. Finally, the status of the drop is displayed in the DropLocationLabel Label.
          /// @remarks The data to drop for the right ListBox is determined in the DragDrop event handler and the String value is added at the appropriate place in the ListBox. If the drag operation moves outside the bounds of the form, then the drag-and-drop operation is canceled in the QueryContinueDrag event handler.
          /// @par Examples
          /// This code excerpt demonstrates using the DragEventArgs class. See the DoDragDrop method for the complete code example.
          /// @code
          /// void ListDragTarget_DragOver(const object& sender, System::Windows::Forms::DragEventArgs& e) {
          ///   // Determine whether string data exists in the drop data. If not, then
          ///   // the drop effect reflects that the drop cannot occur.
          ///   if (!e.GetData().GetDataPresent<System::String>())) {
          ///     e.Effect(DragDropEffects::None);
          ///     DropLocationLabel->Text("None - no string data.");
          ///     return;
          ///   }
          ///   // Set the effect based upon the KeyState.
          ///   if ((e.KeyState() & (8+32)) == (8+32) && (e.AllowedEffect() & DragDropEffects::Link) == DragDropEffects::Link) {
          ///     // KeyState 8 + 32 = CTL + ALT
          ///     // Link drag-and-drop effect.
          ///     e.Effect(DragDropEffects::Link);
          ///   } else if ((e.KeyState() & 32) == 32 && (e.AllowedEffect() & DragDropEffects::Link) == DragDropEffects::Link) {
          ///     // ALT KeyState for link.
          ///     e.Effect(DragDropEffects::Link);
          ///   } else if ((e.KeyState() & 4) == 4 && (e.AllowedEffect() & DragDropEffects::Move) == DragDropEffects::Move) {
          ///     // SHIFT KeyState for move.
          ///     e.Effect(DragDropEffects::Move);
          ///   } else if ((e.KeyState() & 8) == 8 && (e.AllowedEffect() & DragDropEffects::Copy) == DragDropEffects::Copy) {
          ///     // CTL KeyState for copy.
          ///     e.Effect(DragDropEffects::Copy);
          ///   } else if ((e.AllowedEffect() & DragDropEffects::Move) == DragDropEffects::Move) {
          ///     // By default, the drop action should be move, if allowed.
          ///     e.Effect(DragDropEffects::Move);
          ///   } else
          ///     e.Effect(DragDropEffects::None);
          ///   // Get the index of the item the mouse is below.
          ///   // The mouse locations are relative to the screen, so they must be
          ///   // converted to client coordinates.
          ///   indexOfItemUnderMouseToDrop =
          ///   ListDragTarget->SetIndexFromPoint(ListDragTarget->SetPointToClient(Point(e.X, e.Y)));
          ///   // Updates the label text.
          ///   if (indexOfItemUnderMouseToDrop != ListBox->NoMatches()) {
          ///     DropLocationLabel->Text("Drops before item #" + (indexOfItemUnderMouseToDrop + 1));
          ///   } else {
          ///     DropLocationLabel->Text("Drops at the end.");
          ///   }
          /// }
          /// @endcode
          property_<int32, readonly_> KeyState {
            get_ {return this->keyState;}
          };

          property_<int32, readonly_> X {
            get_ {return this->x;}
          };

          property_<int32, readonly_> Y {
            get_ {return this->y;}
          };

        private:
          const object* data = null;
          DragDropEffects allowedEffect = DragDropEffects::None;
          DragDropEffects effect = DragDropEffects::None;
          int32 keyState = 0;
          int32 x = 0;
          int32 y = 0;
        };
      }
    }
  }
}
