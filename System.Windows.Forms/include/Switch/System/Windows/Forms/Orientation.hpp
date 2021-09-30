/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the orientation of controls or elements of controls.
        enum class Orientation {
          /// @brief The control or element is oriented horizontally.
          Horizontal = 0,
          /// @brief The control or element is oriented vertically.
          Vertical = 1,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::Orientation> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::Orientation, string>& values, bool& flags) {
    values[System::Windows::Forms::Orientation::Horizontal] = "Horizontal";
    values[System::Windows::Forms::Orientation::Vertical] = "Vertical";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
