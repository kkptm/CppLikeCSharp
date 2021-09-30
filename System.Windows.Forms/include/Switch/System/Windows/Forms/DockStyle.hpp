/// @file
/// @brief Contains Switch::System::Windows::Forms::DockStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the position and manner in which a control is docked.
        /// @remarks When a control is docked to an edge of its container, it is always positioned flush against that edge when the container is resized. If more than one control is docked to an edge, the controls appear side by side according to their z-order; controls higher in the z-order are positioned farther from the container's edge.
        /// @remarks If Left, Right, Top, or Bottom is selected, the specified and opposite edges of the control are resized to the size of the containing control's corresponding edges. If Fill is selected, all four sides of the control are resized to match the containing control's edges.
        enum class DockStyle {
          /// @brief The control is not docked.
          None = 0,
          /// @brief The control's top edge is docked to the top of its containing control.
          Top,
          /// @brief The control's bottom edge is docked to the bottom of its containing control.
          Bottom,
          /// @brief The control's left edge is docked to the left edge of its containing control.
          Left,
          /// @brief The control's right edge is docked to the right edge of its containing control.
          Right,
          /// @brief The control's bottom edge is docked to the bottom of its containing control.
          Fill
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::DockStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::DockStyle, string>& values, bool& flags) {
    values[System::Windows::Forms::DockStyle::None] = "None";
    values[System::Windows::Forms::DockStyle::None] = "None";
    values[System::Windows::Forms::DockStyle::Top] = "Top";
    values[System::Windows::Forms::DockStyle::Bottom] = "Bottom";
    values[System::Windows::Forms::DockStyle::Left] = "Left";
    values[System::Windows::Forms::DockStyle::Right] = "Right";
    values[System::Windows::Forms::DockStyle::Fill] = "Fill";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
