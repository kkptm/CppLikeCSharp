/// @file
/// @brief Contains Switch::System::Collections::ArrayList class.
#pragma once

#include "../../Any.hpp"
#include "Generic/List.hpp"
#include "IList.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Implements the IList interface using an array whose size is dynamically increased as required.
      /// @par Library
      /// Switch.Core
      /// @par Examples
      /// The following code example shows how to create and initialize an ArrayList and how to print out its values.
      /// @include ArrayList.cpp
      using ArrayList = Generic::List<Any>;
    }
  }
}

using namespace Switch;
