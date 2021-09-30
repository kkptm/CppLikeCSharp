/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief This Enumeration represents the styles the ProgressBar can take. Blocks and Continuous.
        enum class ProgressBarStyle {
          /// @brief The progress bar displays the progress status as a segmented bar.
          Blocks,
          /// @brief The progress bar displays the progress status in a smooth scrolling bar.
          Continuous,
          /// @brief The progress bar displays the progress status in the marquee style.
          Marquee
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::ProgressBarStyle> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::ProgressBarStyle, string>& values, bool& flags) {
    values[System::Windows::Forms::ProgressBarStyle::Blocks] = "Blocks";
    values[System::Windows::Forms::ProgressBarStyle::Continuous] = "Continuous";
    values[System::Windows::Forms::ProgressBarStyle::Marquee] = "Marquee";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
