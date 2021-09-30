/// @file
/// @brief Contains Switch::Unused <> operator.
#pragma once

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief  It may be used to suppress the "unused variable" or "unused local typedefs" compiler warnings when the variable or typedef can't be removed or commented out, e.g. when some blocks of the code are conditionally activated.
  /// @param args variables to suppress the unsed warning
  /// @par Examples
  /// This example sho how to use Unused():
  /// @include Unused.cpp
  template <typename ...Args>
  void Unused(Args&& ... args) {}
}

using namespace Switch;
