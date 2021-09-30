/// @file
/// @brief Contains Switch::System::Windows::Forms::DragEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "DragEventArgs.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Represents a method that will handle drag-and-drop routed events, for example UIElement::DragEnter.
        /// @param sender he object where the event handler is attached.
        /// @param e The event data.
        /// @remarks This delegate is used with the following attached events.
        /// * DragDrop::DragEnter
        /// * DragDrop::DragLeave
        /// * DragDrop::DragOver
        /// * DragDrop::Drop
        /// * DragDrop::PreviewDragEnter
        /// * DragDrop::PreviewDragLeave
        /// * DragDrop::PreviewDragOver
        /// * DragDrop::PreviewDrop
        /// This delegate is also used with the following routed events on base elements. These routed events forward the previously listed attached events to make them more accessible to the general element model in WPF.
        /// * UIElement::DragEnter
        /// * UIElement::DragLeave
        /// * UIElement::DragOver
        /// * UIElement::Drop
        /// * UIElement::PreviewDragEnter
        /// * UIElement::PreviewDragLeave
        /// * UIElement::PreviewDragOver
        /// * UIElement::PreviewDrop
        /// * ContentElement::DragEnter
        /// * ContentElement::DragLeave
        /// * ContentElement::DragOver
        /// * ContentElement::Drop
        /// * ContentElement::PreviewDragEnter
        /// * ContentElement::PreviewDragLeave
        /// * ContentElement::PreviewDragOver
        /// * ContentElement::PreviewDrop
        /// The attached events and the base element routed events share their event data, and the bubbling and tunneling versions of the routed events also share event data. This can affect the handled characteristics of the event as it travels the event route. For details, see Input Overview.
        using DragEventHandler = GenericEventHandler<DragEventArgs&>;
      }
    }
  }
}
