/// @file
/// @brief Contains Switch::System::Windows::Forms::GiveFeedbackEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "GiveFeedbackEventArgs.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Represents the method that handles the GiveFeedback event of a Control.
        /// @param sender he object where the event handler is attached.
        /// @param e The event data.
        /// @remarks When you create a GiveFeedbackEventHandler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate. For more information about handling events with delegates, see Handling and Raising Events.
        /// @remarks The following example demonstrates a drag-and-drop operation between two ListBox controls. The example calls the DoDragDrop method when the drag action starts. The drag action starts if the mouse has moved more than SystemInformation.DragSize from the mouse location during the MouseDown event. The IndexFromPoint method is used to determine the index of the item to drag during the MouseDown event.
        /// @remarks The example also demonstrates using custom cursors for the drag-and-drop operation. The example assumes that two cursor files, 3dwarro.cur and 3dwno.cur, exist in the application directory, for the custom drag and no-drop cursors, respectively. The custom cursors will be used if the UseCustomCursorsCheck CheckBox is checked. The custom cursors are set in the GiveFeedback event handler.
        /// @remarks The keyboard state is evaluated in the DragOver event handler for the right ListBox, to determine what the drag operation will be based upon state of the SHIFT, CTRL, ALT, or CTRL+ALT keys. The location in the ListBox where the drop would occur is also determined during the DragOver event. If the data to drop is not a String, then the DragEventArgs.Effect is set to DragDropEffects.None. Finally, the status of the drop is displayed in the DropLocationLabel Label.
        /// @remarks The data to drop for the right ListBox is determined in the DragDrop event handler and the String value is added at the appropriate place in the ListBox. If the drag operation moves outside the bounds of the form, then the drag-and-drop operation is canceled in the QueryContinueDrag event handler.
        /// @par Examples
        /// This code excerpt demonstrates using the GiveFeedbackEventHandler delegate with the GiveFeedback event. See the DoDragDrop method for the complete code example.
        /// @code
        /// void ListDragSource_GiveFeedback(const object& sender, System::Windows::Forms::GiveFeedbackEventArgs& e) {
        ///   // Use custom cursors if the check box is checked.
        ///   if (UseCustomCursorsCheck.Checked()) {
        ///     // Sets the custom cursor based upon the effect.
        ///     e.UseDefaultCursors(false);
        ///     if ((e.Effect() & DragDropEffects::Move) == DragDropEffects::Move)
        ///       Cursor->SetCurrent(MyNormalCursor);
        ///     else
        ///       Cursor->SetCurrent(MyNoDropCursor);
        ///   }
        /// }
        /// @endcode
        using GiveFeedbackEventHandler = GenericEventHandler<GiveFeedbackEventArgs&>;
      }
    }
  }
}
