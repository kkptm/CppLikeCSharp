/// @file
/// @brief Contains Switch::System::Windows::Forms::MouseButtons enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the starting position that the system uses to arrange minimized windows.
        enum class ArrangeStartingPosition {
          /// @brief Starts at the lower-left corner of the screen, which is the default position.
          BottomLeft = 0,
          /// @brief Starts at the lower-right corner of the screen.
          BottomRight = 1,
          /// @brief Starts at the upper-left corner of the screen.
          TopLeft = 2,
          /// @brief Starts at the upper-right corner of the screen.
          TopRight = 3,
          /// @brief Hides minimized windows by moving them off the visible area of the screen.
          Hide = 8
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::ArrangeStartingPosition> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::ArrangeStartingPosition> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::ArrangeStartingPosition, string>& values, bool& flags) {
    values[System::Windows::Forms::ArrangeStartingPosition::BottomLeft] = "BottomLeft";
    values[System::Windows::Forms::ArrangeStartingPosition::BottomRight] = "BottomRight";
    values[System::Windows::Forms::ArrangeStartingPosition::TopLeft] = "TopLeft";
    values[System::Windows::Forms::ArrangeStartingPosition::TopRight] = "TopRight";
    values[System::Windows::Forms::ArrangeStartingPosition::Hide] = "Hide";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
