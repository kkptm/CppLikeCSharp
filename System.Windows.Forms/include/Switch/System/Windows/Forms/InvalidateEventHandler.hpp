/// @file
/// @brief Contains Switch::System::Windows::Forms::InvalidateEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "InvalidateEventArgs.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Represents the method that will handle the Invalidated event of a Control.
        /// @param sender he object where the event handler is attached.
        /// @param e The event data.
        /// @remarks When you create an InvalidateEventHandler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate. For more information about handling events with delegates, see Events and Delegates.
        using InvalidateEventHandler = GenericEventHandler<const InvalidateEventArgs&>;
      }
    }
  }
}
