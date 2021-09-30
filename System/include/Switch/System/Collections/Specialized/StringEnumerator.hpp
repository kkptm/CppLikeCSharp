/// @file
/// @brief Contains Switch::System::Collections::Specialized::StringEnumerator class.
#pragma once

#include "Switch/System/String.hpp"
#include "Switch/System/Collections/Generic/IEnumerator.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Specialized namespace contains specialized and strongly-typed collections; for example, a linked list dictionary, a bit vector, and collections that contain only strings.
      namespace Specialized {
        /// @brief Supports a simple iteration over a StringCollection.
        /// @par Library
        /// Switch.System
        using StringEnumerator = System::Collections::Generic::Enumerator<String>;
      }
    }
  }
}

