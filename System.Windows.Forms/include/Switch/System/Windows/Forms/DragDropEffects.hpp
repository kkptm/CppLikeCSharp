/// @file
/// @brief Contains Switch::System::Windows::Forms::DragDropEffects enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifie the DragDropEffects values
        enum class DragDropEffects {
          None = 0,
          Copy = 0b1,
          Move = 0x10,
          Link = 0b100,
          Scroll = 0b1000000000000000,
          All = 0b1000000000000111,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::DragDropEffects> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::DragDropEffects> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::DragDropEffects, string>& values, bool& flags) {
    values[System::Windows::Forms::DragDropEffects::None] = "None";
    values[System::Windows::Forms::DragDropEffects::Copy] = "Copy";
    values[System::Windows::Forms::DragDropEffects::Move] = "Move";
    values[System::Windows::Forms::DragDropEffects::Link] = "Link";
    values[System::Windows::Forms::DragDropEffects::Scroll] = "Scroll";
    values[System::Windows::Forms::DragDropEffects::All] = "All";
    flags = true;
  }
};

/// @endcond

using namespace Switch;
