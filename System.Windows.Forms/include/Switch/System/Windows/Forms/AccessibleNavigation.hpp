/// @file
/// @brief Contains Switch::System::Windows::Forms::AccessibleNavigation enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifie the AccessibleNavigation values
        enum class AccessibleNavigation {
          Up = 1,
          Down,
          Left,
          Right,
          Next,
          Previous,
          FirstChild,
          LastChild,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::AccessibleNavigation> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::AccessibleNavigation, string>& values, bool& flags) {
    values[System::Windows::Forms::AccessibleNavigation::Up] = "Up";
    values[System::Windows::Forms::AccessibleNavigation::Down] = "Down";
    values[System::Windows::Forms::AccessibleNavigation::Left] = "Left";
    values[System::Windows::Forms::AccessibleNavigation::Right] = "Right";
    values[System::Windows::Forms::AccessibleNavigation::Next] = "Next";
    values[System::Windows::Forms::AccessibleNavigation::Previous] = "Previous";
    values[System::Windows::Forms::AccessibleNavigation::FirstChild] = "FirstChild";
    values[System::Windows::Forms::AccessibleNavigation::LastChild] = "LastChild";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
