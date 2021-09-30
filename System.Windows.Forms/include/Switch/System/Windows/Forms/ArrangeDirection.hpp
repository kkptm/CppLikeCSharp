/// @file
/// @brief Contains Switch::System::Windows::Forms::MouseButtons enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the direction the system uses to arrange minimized windows.
        enum class ArrangeDirection {
          /// @brief Arranges vertically, from top to bottom.
          Down = 0x0004,
          /// @brief Arranges horizontally, from left to right.
          Left = 0x0000,
          /// @brief Arranges horizontally, from right to left.
          Right = 0x0000,
          /// @brief Arranges vertically, from bottom to top.
          Up = 0x0004,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::ArrangeDirection> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::ArrangeDirection> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::ArrangeDirection, string>& values, bool& flags) {
    // values[System::Windows::Forms::ArrangeDirection::Down] = "Down";
    values[System::Windows::Forms::ArrangeDirection::Left] = "Left";
    // values[System::Windows::Forms::ArrangeDirection::Right] = "Right";
    values[System::Windows::Forms::ArrangeDirection::Up] = "Up";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
