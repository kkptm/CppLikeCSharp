/// @file
/// @brief Contains Switch::System::Collections::Generic::IDictionary <TKey, TValue> interface.
#pragma once

#include "../../../Property.hpp"
#include "../../../Types.hpp"
#include "ICollection.hpp"
#include "List.hpp"
#include "KeyValuePair.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @interface IDictionary
        /// @brief Represents a generic collection of key/value pairs.
        template<typename TKey, typename TValue>
        class IDictionary : public ICollection<KeyValuePair<TKey, TValue>> {
        public:
          /// @brief Represents the collection of keys in a Dictionary<TKey, TValue>. This class cannot be inherited.
          using KeyCollection = List<TKey>;

          /// @brief Represents the collection of values in a Dictionary<TKey, TValue>. This class cannot be inherited.
          using ValueCollection = List<TValue>;

          /// @cond
          IDictionary() {}
          /// @endcond

          /// @brief Gets an ICollection<T> containing the keys of the IDictionary<TKey, TValue>.
          /// @return ICollection<TKey> An ICollection<T> containing the keys of the object that implements IDictionary<TKey, TValue>.
          property_<KeyCollection, readonly_> Keys {
            get_ {return this->GetKeys();}
          };

          /// @brief Gets an ICollection<T> containing the values of the IDictionary<TKey, TValue>.
          /// @return ICollection<TValue> An ICollection<T> containing the values of the object that implements IDictionary<TKey, TValue>.
          property_<ValueCollection, readonly_> Values {
            get_ {return this->GetValues();}
          };

          using ICollection<KeyValuePair<TKey, TValue>>::Add;
          /// @brief Adds an element with the provided key and value to the IDictionary<TKey,TValue>.
          /// @param key The object to use as the key of the element to add.
          /// @param value The object to use as the value of the element to add.
          /// @exception ArgumentNullException key or value is null.
          /// @exception ArgumentException An element with the same key already exists in the IDictionary<TKey,TValue>.
          /// @exception NotSupportedException The IDictionary<TKey,TValue> is read-only.
          virtual void Add(const TKey& key, const TValue& value) = 0;

          /// @brief Determines whether the IDictionary<TKey,TValue> contains an element with the specified key.
          /// @param key The key to locate in the IDictionary<TKey,TValue>.
          /// @return Boolean true if the IDictionary<TKey,TValue> contains an element with the key; otherwise, false
          /// @exception ArgumentNullException key is null.
          virtual bool ContainsKey(const TKey& key) const = 0;

          /// @brief Removes the element with the specified key from the IDictionary<TKey,TValue>.
          /// @param key The key of the element to remove
          /// @return Boolean true if the element is successfully removed; otherwise, false. This method also returns false if key was not found in the original IDictionary<TKey,TValue>.
          /// @exception ArgumentNullException key is null.
          virtual bool Remove(const TKey& key) = 0;

          using ICollection<KeyValuePair<TKey, TValue>>::Remove;

          /// @brief Gets the value associated with the specified key.
          /// @param key The key whose value to get
          /// @param value When this method returns, the value associated with the specified key, if the key is found.
          /// @return Boolean true if the object that implements IDictionary<TKey,TValue> contains an element with the specified key; otherwise, false.
          /// @exception ArgumentNullException key or value is null.
          virtual bool TryGetValue(const TKey& key, TValue& value) const = 0;

          /// @brief Sets the value associated with the specified key.
          /// @param key The TKey whose value to get
          /// @return TValue The element at the specified key.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
          virtual TValue& operator[](const TKey& key) = 0;

          /// @brief Gets the element at the specified key.
          /// @param key The key whose value to get
          /// @return TValue The element at the specified key.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
          virtual const TValue& operator[](const TKey& key) const = 0;

        protected:
          /// @brief Gets an ICollection<T> containing the keys of the IDictionary<TKey, TValue>.
          /// @return ICollection<TKey> An ICollection<T> containing the keys of the object that implements IDictionary<TKey, TValue>.
          virtual KeyCollection GetKeys() const = 0;

          /// @brief Gets an ICollection<T> containing the values of the IDictionary<TKey, TValue>.
          /// @return ICollection<TValue> An ICollection<T> containing the values of the object that implements IDictionary<TKey, TValue>.
          virtual ValueCollection GetValues() const = 0;
        };
      }
    }
  }
}

using namespace Switch;
