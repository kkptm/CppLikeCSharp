/// @file
/// @brief Contains Switch::System::Windows::Forms::KeyPressEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "KeyPressEventArgs.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        using KeyPressEventHandler = GenericEventHandler<KeyPressEventArgs&>;
      }
    }
  }
}
