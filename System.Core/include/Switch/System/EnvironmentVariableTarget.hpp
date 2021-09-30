/// @file
/// @brief Contains Switch::System::EnvironmentVariableTarget enum.
#pragma once

#include "../Types.hpp"
#include "Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Specifies the location where an environment variable is stored or retrieved in a set or get operation.
    enum class EnvironmentVariableTarget {
      /// @brief The environment variable is stored or retrieved from the environment block associated with the current process.
      Process = 0,
      /// @brief The environment variable is stored or retrieved from the HKEY_CURRENT_USER\Environment key in the Windows operating system registry.
      User,
      /// @brief The environment variable is stored or retrieved from the HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment key in the Windows operating system registry.
      Machine = 2,
    };
  }
}

/// @cond
template<>
struct EnumRegister<System::EnvironmentVariableTarget> {
  void operator()(System::Collections::Generic::IDictionary<System::EnvironmentVariableTarget, string>& values, bool& flags) {
    values[System::EnvironmentVariableTarget::Process] = "Process";
    values[System::EnvironmentVariableTarget::User] = "User";
    values[System::EnvironmentVariableTarget::Machine] = "Machine";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
