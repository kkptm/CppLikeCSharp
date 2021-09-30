/// @file
/// @brief Contains Switch::System::ComponentModel::CancelEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "CancelEventArgs.hpp"

namespace Switch {
  namespace System {
    namespace ComponentModel {
      using CancelEventHandler = GenericEventHandler<CancelEventArgs&>;
    }
  }
}
