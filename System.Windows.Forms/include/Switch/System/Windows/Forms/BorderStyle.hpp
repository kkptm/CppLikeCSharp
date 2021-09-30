/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifie the BorderStyle values
        enum class BorderStyle {
          None,
          FixedSingle,
          Fixed3D,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::BorderStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::BorderStyle, string>& values, bool& flags) {
    values[System::Windows::Forms::BorderStyle::None] = "None";
    values[System::Windows::Forms::BorderStyle::FixedSingle] = "FixedSingle";
    values[System::Windows::Forms::BorderStyle::Fixed3D] = "Fixed3D";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
