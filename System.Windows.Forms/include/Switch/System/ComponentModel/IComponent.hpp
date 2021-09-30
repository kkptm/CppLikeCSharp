/// @file
/// @brief Contains Switch::System::ComponentModel::IComponent interface.
#pragma once

#include <Switch/Interface.hpp>
#include <Switch/System/EventHandler.hpp>
#include "../../SystemWindowsFormsExport.hpp"

namespace Switch {
  namespace System {
    namespace ComponentModel {
      /// @interface IComponent
      /// @brief Provides the base implementation for the IComponent interface and enables object sharing between applications.
      class system_windows_forms_export_ IComponent interface_ {
      public:
        /// @brief Performs application-defined tasks associated with freeing, releasing, or resetting resources.
        virtual void Close() = 0;

        /// @brief Represents the method that handles the Closed event of a component.
        /// @remarks When you create a Closed delegate, you identify the method that handles the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate.
        System::EventHandler Closed;
      };
    }
  }
}
