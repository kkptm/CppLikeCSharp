/// @file
/// @brief Contains Switch::System::CharEnumerator type.
#pragma once

#include "../Types.hpp"
#include "Collections/Generic/IEnumerator.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Supports iterating over a string object and reading its individual characters. This class cannot be inherited.
    using CharEnumerator = Collections::Generic::Enumerator<char32>;
  }
}

using namespace Switch;
