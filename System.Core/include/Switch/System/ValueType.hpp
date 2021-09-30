/// @file
/// @brief Contains Switch::System::ValueType class.
#pragma once

#include "Object.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    class String;
    /// @endcond

    /// @brief Provides the base class for value types.
    struct core_export_ ValueType : public Object {
    };
  }
}

#include "_String.hpp"

using namespace Switch;
