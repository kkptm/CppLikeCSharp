/// @file
/// @brief Contains Switch::System::Collections::IList interface.
#pragma once

#include "../../Any.hpp"
#include "ICollection.hpp"
#include "Generic/IList.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Represents a non-generic collection of objects that can be individually accessed by index.
      using IList = System::Collections::Generic::IList<Any>;
    }
  }
}

using namespace Switch;
