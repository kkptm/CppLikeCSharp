/// @file
/// @brief Contains Switch::System::ComponentModel::Component class.
#pragma once

#include <Switch/System/Delegate.hpp>
#include "../../SystemWindowsFormsExport.hpp"

namespace Switch {
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    /// The classes in this namespace divide into the following categories:
    /// * Core component classes. See the Component, IComponent, Container, and IContainer classes.
    /// * Component licensing. See the License, LicenseManager, LicenseProvider, and LicenseProviderAttribute classes.
    /// * Attributes. See the Attribute class.
    /// * Descriptors and persistence. See the TypeDescriptor, EventDescriptor, and PropertyDescriptor classes.
    /// * Type converters. See the TypeConverter class.
    namespace ComponentModel {
      /// @brief Provides a simple list of delegates. This class cannot be inherited.
      template<typename Result, typename... Arguments>
      class system_windows_forms_export_ EventHandlerList final : public object {
      public:
        /// @brief Initializes a new instance of the EventHandlerList class.
        EventHandlerList() {}

        /// @cond
        EventHandlerList(const EventHandlerList& eventHandlerList) = default;
        /// @endcond

        delegate<Result, Arguments...> operator[](ref<object>) {}

      private:
        struct Item {
          ref<object> key;
          delegate<Result, Arguments...> handler;
          refptr<Item> next;
        };

        refptr<Item> head;
      };
    }
  }
}
