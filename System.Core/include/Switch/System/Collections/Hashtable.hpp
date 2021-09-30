/// @file
/// @brief Contains Switch::System::Collections::Hashtable class.
#pragma once

#include "../../Any.hpp"
#include "Generic/Dictionary.hpp"
#include "DictionaryEntry.hpp"
#include "IDictionary.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Represents a collection of key/value pairs that are organized based on the hash code of the key.
      /// @remarks Each element is a key/value pair stored in a DictionaryEntry object. A key cannot be null, but a value can be.
      /// @remarks The objects used as keys by a Hashtable are required to override the Object.GetHashCode method (or the IHashCodeProvider interface) and the Object.Equals method (or the IComparer interface). The implementation of both methods and interfaces must handle case sensitivity the same way; otherwise, the Hashtable might behave incorrectly. For example, when creating a Hashtable, you must use the CaseInsensitiveHashCodeProvider class (or any case-insensitive IHashCodeProvider implementation) with the CaseInsensitiveComparer class (or any case-insensitive IComparer implementation).
      /// @remarks Furthermore, these methods must produce the same results when called with the same parameters while the key exists in the Hashtable. An alternative is to use a Hashtable constructor with an IEqualityComparer parameter. If key equality were simply reference equality, the inherited implementation of Object.GetHashCode and Object.Equals would suffice.
      /// @remarks Key objects must be immutable as long as they are used as keys in the Hashtable.
      /// @remarks When an element is added to the Hashtable, the element is placed into a bucket based on the hash code of the key. Subsequent lookups of the key use the hash code of the key to search in only one particular bucket, thus substantially reducing the number of key comparisons required to find an element.
      /// @remarks The load factor of a Hashtable determines the maximum ratio of elements to buckets. Smaller load factors cause faster average lookup times at the cost of increased memory consumption. The default load factor of 1.0 generally provides the best balance between speed and size. A different load factor can also be specified when the Hashtable is created.
      /// @remarks As elements are added to a Hashtable, the actual load factor of the Hashtable increases. When the actual load factor reaches the specified load factor, the number of buckets in the Hashtable is automatically increased to the smallest prime number that is larger than twice the current number of Hashtable buckets.
      /// @remarks Each key object in the Hashtable must provide its own hash function, which can be accessed by calling GetHash. However, any object implementing IHashCodeProvider can be passed to a Hashtable constructor, and that hash function is used for all objects in the table
      /// @remarks The capacity of a Hashtable is the number of elements the Hashtable can hold. As elements are added to a Hashtable, the capacity is automatically increased as required through reallocation.
      /// @remarks The foreach statement returns an object of the type of the elements in the collection. Since each element of the Hashtable is a key/value pair, the element type is not the type of the key or the type of the value. Instead, the element type is DictionaryEntry. For example:
      /// @code
      /// for (DictionaryEntry de : myHashtable) {
      ///   // ...
      /// }
      /// @endcode
      /// @remarks The foreach statement is a wrapper around the enumerator, which only allows reading from, not writing to, the collection.
      /// @remarks Because serializing and deserializing an enumerator for a Hashtable can cause the elements to become reordered, it is not possible to continue enumeration without calling the Reset method.
      /// @note Because keys can be inherited and their behavior changed, their absolute uniqueness cannot be guaranteed by comparisons using the Equals method.
      /// @par Exemples
      /// The following example shows how to create, initialize and perform various functions to a Hashtable and how to print out its keys and values.
      /// @include Hashtable.cpp
      using Hashtable = System::Collections::Generic::Dictionary<Any, Any>;
    }
  }
}

using namespace Switch;
