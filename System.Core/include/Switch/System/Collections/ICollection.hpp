/// @file
/// @brief Contains Switch::System::Collections::ICollection interface.
#pragma once

#include "../../Any.hpp"
#include "IEnumerable.hpp"
#include "Generic/ICollection.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Defines size, enumerators, and synchronization methods for all non-generic collections.
      using ICollection = System::Collections::Generic::ICollection<Any>;
    }
  }
}

using namespace Switch;
