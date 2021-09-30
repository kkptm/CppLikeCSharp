/// @file
/// @brief Contains Switch::System::String class.
#pragma once

#include "_String.hpp"
#include "_String.h"
#include "Enum.hpp"

/// @cond
template<>
struct EnumRegister<System::StringSplitOptions> {
  void operator()(System::Collections::Generic::IDictionary<System::StringSplitOptions, string>& values, bool& flags) {
    values[System::StringSplitOptions::None] = "None";
    values[System::StringSplitOptions::RemoveEmptyEntries] = "RemoveEmptyEntries";
    flags = false;
  }
};
/// @endcond
