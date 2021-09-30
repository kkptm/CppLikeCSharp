/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the state of a control, such as a check box, that can be checked, unchecked, or set to an indeterminate state.
        enum class CheckState {
          /// @brief The control is unchecked.
          Unchecked = 0,
          /// @brief The control is checked.
          Checked = 1,
          /// @brief The control is indeterminate. An indeterminate control generally has a shaded appearance.
          Indeterminate = 2,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::CheckState> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::CheckState, string>& values, bool& flags) {
    values[System::Windows::Forms::CheckState::Unchecked] = "Unchecked";
    values[System::Windows::Forms::CheckState::Checked] = "Checked";
    values[System::Windows::Forms::CheckState::Indeterminate] = "Indeterminate";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
