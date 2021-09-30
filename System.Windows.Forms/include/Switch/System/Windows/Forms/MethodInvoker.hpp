/// @file
/// @brief Contains Switch::System::Windows::Forms::MethodInvoker delegate.
#pragma once

#include <Switch/System/Delegate.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Represents a delegate that can execute any method in managed code that is declared void and takes no parameters.
        /// @remarks MethodInvoker provides a simple delegate that is used to invoke a method with a void parameter list. This delegate can be used when making calls to a control's Invoke method, or when you need a simple delegate but do not want to define one yourself.
        using MethodInvoker = Delegate<void>;
      }
    }
  }
}
