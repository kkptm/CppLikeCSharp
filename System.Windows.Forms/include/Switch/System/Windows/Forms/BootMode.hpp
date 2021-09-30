/// @file
/// @brief Contains Switch::System::Windows::Forms::MouseButtons enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the mode to start the computer in.
        enum class BootMode {
          /// @brief Starts the computer in standard mode.
          Normal = 0,
          /// @brief Starts the computer by using only the basic files and drivers.
          FailSafe = 1,
          /// @brief Starts the computer by using the basic files, drivers and the services and drivers necessary to start networking.
          FailSafeWithNetwork = 2,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::BootMode> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::BootMode, string>& values, bool& flags) {
    values[System::Windows::Forms::BootMode::Normal] = "Normal";
    values[System::Windows::Forms::BootMode::FailSafe] = "FailSafe";
    values[System::Windows::Forms::BootMode::FailSafeWithNetwork] = "FailSafeWithNetwork";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
