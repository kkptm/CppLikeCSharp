/// @file
/// @brief Contains Switch::System::Windows::Forms::FormClosedEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "FormClosedEventArgs.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Represents the method that will handle the MouseUp or MouseDown event of a Control.
        /// @param sender The source of the event.
        /// @param A MouseEventArgs that contains the event data.
        /// @remarks When you create a MouseEventHandler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate. For more information about handling events with delegates, see Handling and Raising Events.
        using FormClosedEventHandler = GenericEventHandler<const FormClosedEventArgs&>;
      }
    }
  }
}
