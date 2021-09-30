/// @file
/// @brief Contains Switch::System::Collections::DictionaryEntry class.
#pragma once

#include "../../Any.hpp"
#include "Generic/KeyValuePair.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Defines a dictionary key/value pair that can be set or retrieved.
      using DictionaryEntry = Generic::KeyValuePair<Any, Any>;
    }
  }
}

using namespace Switch;
