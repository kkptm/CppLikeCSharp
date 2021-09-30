/// @file
/// @brief Contains Switch::System::Comparison delegate.
#pragma once

#include "../Types.hpp"
#include "Delegate.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents the method that compares two objects of the same type.
    /// @param T The type of the objects to compare.
    /// @param x The first object to compare.
    /// @param y The second object to compare.
    /// @return Int32 A signed integer that indicates the relative values of x and y, as shown in the following table.
    /// | Value          | Meaning              |
    /// |----------------|----------------------|
    /// | less than 0    | x is less than y.    |
    /// | 0              | x equals y.          |
    /// | Greater than 0 | x is greater than y. |
    template<typename T>
    using Comparison = Delegate<int32, T, T>;
  }
}

using namespace Switch;
