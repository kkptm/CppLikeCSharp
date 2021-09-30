/// @file
/// @brief Contains Switch::System::ComponentModel::ISite interface.
#pragma once

#include <Switch/Interface.hpp>
#include "../../SystemWindowsFormsExport.hpp"
#include "IComponent.hpp"

/// @cond
namespace Switch {
  namespace System {
    namespace ComponentModel {
      class IComponenent;
    }
  }
}
/// @endcond

namespace Switch {
  namespace System {
    namespace ComponentModel {
      /// @interface ISite
      /// @brief Provides functionality required by sites.
      class system_windows_forms_export_ ISite interface_ {
      public:
        /// @brief A valid value for this property (that is, the value is not null) indicates that the component has been added to a container.
        virtual const IComponenent& GetComponent() const = 0;
      };
    }
  }
}
