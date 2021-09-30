/// @file
/// @brief Contains Switch::System::Collections::Comparer class.
#pragma once

#include "../../Any.hpp"
#include "Generic/Comparer.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Exposes a method that compares two objects.
      using Comparer = System::Collections::Generic::Comparer<Any>;
    }
  }
}

using namespace Switch;
