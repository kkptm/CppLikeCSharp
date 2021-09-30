/// @file
/// @brief Contains Switch::System::Predicate <T> delegate.
#pragma once

#include "Delegate.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents the method that defines a set of criteria and determines whether the specified object meets those criteria.
    /// @param T The type of the object to compare.
    /// @param obj The object to compare against the criteria defined within the method represented by this delegate.
    /// @return true if obj meets the criteria defined within the method represented by this delegate; otherwise, false.
    template<typename T>
    using Predicate = Delegate<bool, T>;
  }
}

using namespace Switch;
