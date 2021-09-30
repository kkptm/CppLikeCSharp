/// @file
/// @brief Contains Switch::System::ComponentModel::ComponentCollection class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/RefPtr.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/Collections/ArrayList.hpp>
#include "../../SystemWindowsFormsExport.hpp"

namespace Switch {
  namespace System {
    namespace ComponentModel {
      class IComponent;

      /// @brief Provides a read-only container for a collection of IComponent objects.
      class system_windows_forms_export_ ComponentCollection : public object {
      public:
        /// @brief Initializes a new instance of the ComponentCollection class using the specified array of components.
        /// @param components An array of IComponent objects to initialize the collection with.
        /// @remarks This method adds each IComponent in the specified IComponent array to the collection.
        ComponentCollection(const Array<Any>& components) {
          for (auto component : components)
            this->components.Add(component);
        }

        int32 Count() const { return this->components.Count(); }

        const System::Collections::ArrayList& GetInnerList() const { return this->components; }

        Any operator [](int32 index) const { return this->components[index]; }

        Any operator [](int32 index) { return this->components[index]; }

        Any operator [](string name) {
          /*
          for(refptr<Object> component : components) {
            if (component.As<IComponent>().GetSite().Name() == name)
              return component.ChangeType<IComponent>();
          }
           */
          return "";
        }

      private:
        System::Collections::ArrayList components;
      };
    }
  }
}
