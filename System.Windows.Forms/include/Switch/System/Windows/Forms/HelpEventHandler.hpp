/// @file
/// @brief Contains Switch::System::Windows::Forms::HelpEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "HelpEventArgs.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Represents the method that will handle the HelpRequested event of a Control.
        /// @param sender he object where the event handler is attached.
        /// @param e The event data.
        /// @remarks When you create a HelpEventHandler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate. For more information about handling events with delegates, see Events and Delegates.
        using HelpEventHandler = GenericEventHandler<HelpEventArgs&>;
      }
    }
  }
}
