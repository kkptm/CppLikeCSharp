/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the border styles for a form.
        enum class FormBorderStyle {
          /// @brief No border.
          None,
          /// @brief A fixed, single-line border.
          FixedSingle,
          /// @brief A fixed, three-dimensional border.
          Fixed3D,
          /// @brief A thick, fixed dialog-style border.
          FixedDialog = 3,
          /// @brief A resizable border.
          Sizable = 4,
          /// @brief A tool window border
          FixedToolWindow = 5,
          /// @brief A resizable tool window border.
          SizableToolWindow = 6,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::FormBorderStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::FormBorderStyle, string>& values, bool& flags) {
    values[System::Windows::Forms::FormBorderStyle::None] = "None";
    values[System::Windows::Forms::FormBorderStyle::FixedSingle] = "FixedSingle";
    values[System::Windows::Forms::FormBorderStyle::Fixed3D] = "Fixed3D";
    values[System::Windows::Forms::FormBorderStyle::FixedDialog] = "FixedDialog";
    values[System::Windows::Forms::FormBorderStyle::Sizable] = "Sizable";
    values[System::Windows::Forms::FormBorderStyle::FixedToolWindow] = "FixedToolWindow";
    values[System::Windows::Forms::FormBorderStyle::Fixed3D] = "SizableToolWindow";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
