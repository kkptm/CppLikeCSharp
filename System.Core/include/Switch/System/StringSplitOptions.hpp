/// @file
/// @brief Contains Switch::System::StringSplitOptions enum.
#pragma once

#include "../Types.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @enum StringSplitOptions
    /// @brief Specifies whether applicable string::Split method overloads include or omit empty substrings from the return value.
    /// @see string
    enum class StringSplitOptions {
      /// @brief The return value includes array elements that contain an empty string.
      None,
      /// @brief The return value does not include array elements that contain an empty string.
      RemoveEmptyEntries
    };
  }
}

using namespace Switch;
