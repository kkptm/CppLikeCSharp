/// @file
/// @brief Contains Switch::System::Windows::Forms::KeyEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "KeyEventArgs.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Represents the method that will handle the KeyUp or KeyDown event of a Control.
        /// @param sender The source of the event.
        /// @param e A KeyEventArgs that contains the event data.
        /// @remarks When you create a KeyEventHandler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate. For more information about handling events with delegates, see Handling and Raising Events.
        using KeyEventHandler = GenericEventHandler<KeyEventArgs&>;
      }
    }
  }
}
