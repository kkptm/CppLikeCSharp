/// @file
/// @brief Contains Switch::System::Collections::IEnumerable interface.
#pragma once

#include "../../Any.hpp"
#include "IEnumerator.hpp"
#include "Generic/IEnumerable.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Exposes the enumerator, which supports a simple iteration over a non-generic collection.
      using IEnumerable = System::Collections::Generic::IEnumerable<Any>;
    }
  }
}

using namespace Switch;
