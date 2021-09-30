/// @file
/// @brief Contains Switch::System::Collections::Specialized::StringDictionary, Switch::System::Collections::Specialized::StringKeyValuePair, Switch::System::Collections::Specialized::StringKeyValuePairEnumerator classes and Switch::System::Collections::Specialized::IStringKeyValuePairEnumerator interface.
#pragma once

#include <Switch/System/String.hpp>
#include <Switch/System/Collections/Generic/SortedDictionary.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Specialized namespace contains specialized and strongly-typed collections; for example, a linked list dictionary, a bit vector, and collections that contain only strings.
      namespace Specialized {
        /// @brief Implements a hash table with the key and the value strongly typed to be strings rather than objects.
        /// @par Library
        /// Switch.System
        /// @par Examples
        /// The following code example demonstrates several of the properties and methods of StringDictionary.
        /// @include StringDictionary.cpp
        using StringDictionary = System::Collections::Generic::SortedDictionary<String, String>;

        /// @brief Implements a KeyValuePair with the key and the value strongly typed to be strings rather than objects.
        /// @par Examples
        /// The following code example demonstrates a StringKeyValuePair using.
        /// @include StringDictionary.cpp
        using StringKeyValuePair = System::Collections::Generic::KeyValuePair<String, String>;

        /// @brief Implements a KeyValuePair IEnumartor with the key and the value strongly typed to be strings rather than objects.
        /// @par Examples
        /// The following code example demonstrates a IStringKeyValuePairEnumerator using.
        /// @include StringDictionary.cpp
        using IStringKeyValuePairEnumerator = System::Collections::Generic::IEnumerator<StringKeyValuePair>;

        /// @brief Implements a KeyValuePair IEnumartor with the key and the value strongly typed to be strings rather than objects.
        /// @par Examples
        /// The following code example demonstrates a IStringKeyValuePairEnumerator using.
        /// @include StringDictionary.cpp
        using StringKeyValuePairEnumerator = System::Collections::Generic::Enumerator<StringKeyValuePair>;
      }
    }
  }
}
