/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the location of tick marks in a TrackBar control.
        enum class TickStyle {
          /// @brief No tick marks appear in the control.
          None = 0,
          /// @brief Tick marks are located on the top of horizontal control or on the left of a vertical control.
          TopLeft = 1,
          /// @brief Tick marks are located on the bottom of a horizontal control or on the right side of a vertical control.
          BottomRight = 2,
          /// @brief Tick marks are located on both sides of the control.
          Both = 3,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::TickStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::TickStyle, string>& values, bool& flags) {
    values[System::Windows::Forms::TickStyle::None] = "None";
    values[System::Windows::Forms::TickStyle::TopLeft] = "TopLeft";
    values[System::Windows::Forms::TickStyle::BottomRight] = "BottomRight";
    values[System::Windows::Forms::TickStyle::Both] = "Both";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
