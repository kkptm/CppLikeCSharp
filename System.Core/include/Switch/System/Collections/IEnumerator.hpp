/// @file
/// @brief Contains Switch::System::Collections::IEnumerator interface.
#pragma once

#include "../../Any.hpp"
#include "Generic/IEnumerator.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Supports a simple iteration over a non-generic collection.
      using IEnumerator = System::Collections::Generic::IEnumerator<Any>;

      using Enumerator = System::Collections::Generic::Enumerator<Any>;
    }
  }
}

using namespace Switch;
