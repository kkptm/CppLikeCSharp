/// @file
/// @brief Contains Switch::System::Windows::Forms::ImageLayout enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the position of the image on the control.
        enum class ImageLayout {
          /// @brief The image is left-aligned at the top across the control's client rectangle.
          None = 0,
          /// @brief The image is tiled across the control's client rectangle.
          Tile = 1,
          /// @brief The image is centered within the control's client rectangle.
          Center = 2,
          /// @brief The image is streched across the control's client rectangle.
          Stretch = 3,
          /// @brief The image is enlarged within the control's client rectangle.
          Zoom = 4
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::ImageLayout> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::ImageLayout, string>& values, bool& flags) {
    values[System::Windows::Forms::ImageLayout::None] = "None";
    values[System::Windows::Forms::ImageLayout::Tile] = "Tile";
    values[System::Windows::Forms::ImageLayout::Center] = "Center";
    values[System::Windows::Forms::ImageLayout::Stretch] = "Stretch";
    values[System::Windows::Forms::ImageLayout::Zoom] = "Zoom";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
