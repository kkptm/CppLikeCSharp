/// @file
/// @brief Contains Switch::System::Windows::Forms::MouseButtons enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        enum class MouseButtons {
          None = 0,
          Left = 0x100000,
          Right = 0x200000,
          Middle = 0x400000,
          XButton1 = 0x800000,
          XButton2 = 0x1000000
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::MouseButtons> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::MouseButtons> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::MouseButtons, string>& values, bool& flags) {
    values[System::Windows::Forms::MouseButtons::None] = "None";
    values[System::Windows::Forms::MouseButtons::Left] = "Left";
    values[System::Windows::Forms::MouseButtons::Right] = "Right";
    values[System::Windows::Forms::MouseButtons::Middle] = "Middle";
    values[System::Windows::Forms::MouseButtons::XButton1] = "XButton1";
    values[System::Windows::Forms::MouseButtons::XButton2] = "XButton2";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
