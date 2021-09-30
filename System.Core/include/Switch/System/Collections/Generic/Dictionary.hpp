/// @file
/// @brief Contains Switch::System::Collections::Generic::Dictionary <TKey, TValue> class.
#pragma once

#include <unordered_map>

#include "../../../Allocator.hpp"
#include "../../../InitializerList.hpp"
#include "../../../Move.hpp"
#include "../../Object.hpp"
#include "../../../Types.hpp"
#include "../../Array.hpp"
#include "../../_String.hpp"
#include "Comparer.hpp"
#include "IComparer.hpp"
#include "IDictionary.hpp"
#include "List.hpp"
#include "../../Linq/Enumerable.hpp"

#include "../../../GetHashCode.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace System {
    /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @brief Represents a non-generic collection of objects that can be individually accessed by index.
        /// @par Examples
        /// The following code example creates an empty Dictionary<TKey, TValue> of strings with string keys and uses the Add method to add some elements. The example demonstrates that the Add method throws an ArgumentException when attempting to add a duplicate key.
        /// The example uses the Item property to retrieve values, demonstrating that a KeyNotFoundException is thrown when a requested key is ! present, and showing that the value associated with a key can be replaced.
        /// The example shows how to use the TryGetValue method as a more efficient way to retrieve values if a program often must try key values that are ! in the dictionary, and it shows how to use the ContainsKey method to test whether a key exists before calling the Add method.
        /// The example shows how to enumerate the keys and values in the dictionary and how to enumerate the keys and values alone using the Keys property and the Values property.
        /// Finally, the example demonstrates the Remove method.
        /// @include Dictionary.cpp
        template<typename TKey, typename TValue, typename TAllocator = Allocator<std::pair<const TKey, TValue>>>
            class Dictionary : public Object, public Linq::Extension::Enumerable<Dictionary<TKey, TValue, TAllocator>, KeyValuePair<TKey, TValue>>, public IDictionary<TKey, TValue> {
public:
          using Item = KeyValuePair<TKey, TValue>;

          /// @brief Represents the collection of keys in a Dictionary<TKey, TValue>. This class cannot be inherited.
          using KeyCollection = typename IDictionary<TKey, TValue>::KeyCollection;

          /// @brief Represents the collection of values in a Dictionary<TKey, TValue>. This class cannot be inherited.
          using ValueCollection = typename IDictionary<TKey, TValue>::ValueCollection;

          /// @brief Initializes a new instance of the Dictionary<TKey, TValue> class that is empty and has the default initial capacity (512 items).
          /// @remarks Every key in a Dictionary<TKey, TValue> must be unique according to the default equality comparer.
          /// @remarks The Dictionary<TKey, TValue> class is ! thread safe.
          Dictionary() : operationNumber(0) {}

          /// @brief Initializes a new instance of the Dictionary<TKey, TValue> class that contains elements copied from the specified IDictionary<TKey, TValue>.
          /// @param dictionary The IDictionary<TKey, TValue> whose elements are copied to the new Dictionary<TKey, TValue>.
          /// @remarks Every key in a Dictionary<TKey, TValue> must be unique according to the default equality comparer.
          /// @remarks The Dictionary<TKey, TValue> class is ! thread safe.
          Dictionary(const Dictionary& dictionary) : comparer(dictionary.comparer), operationNumber(dictionary.operationNumber) {
            for (const auto& item : dictionary)
              Add(item);
          }

          /// @cond
          Dictionary(Dictionary&& dictionary) : hashmap(Move(dictionary.hashmap)), comparer(dictionary.comparer), operationNumber(dictionary.operationNumber) {
            dictionary.comparer.Reset();
            dictionary.operationNumber = 0;
          }
          /// @endcond

          /// @brief Initializes a new instance of the Dictionary<TKey, TValue> class that contains elements copied from the specified IDictionary<TKey, TValue>.
          /// @param dictionary The IDictionary<TKey, TValue> whose elements are copied to the new Dictionary<TKey, TValue>.
          /// @exception ArgumentNullException The parameters dictionary is null.
          /// @remarks Every key in a Dictionary<TKey, TValue> must be unique according to the default equality comparer.
          /// @remarks The Dictionary<TKey, TValue> class is ! thread safe.
          Dictionary(const IDictionary<TKey, TValue>& dictionary) : operationNumber(0) {
            for (const auto& item : dictionary)
              Add(item);
          }

          /// @brief Initializes a new instance of the Dictionary<TKey, TValue> class with Tkey and TValue array specified.
          /// @param array An array of Tkey and TValue to initialize Dictionnary.
          /// @param capacity The number of elements that the new list can initially store (maximum 512 items).
          /// @exception ArgumentNullException The parameters array is null.
          /// @remarks The Dictionary<TKey, TValue> class is ! thread safe.
          Dictionary(const System::Array<Item>& array) : operationNumber(0) {
            for (const auto& item : array)
              Add(item);
          }

          /// @brief Initializes a new instance of the Dictionary and copy array[] T.
          /// @param array the Array to copy.
          /// @remarks The Dictionary class is ! thread safe.
          template<int32 len>
          Dictionary(const Item(&array)[len]) : operationNumber(0) {
            for (int32 index = 0; index < len; index++)
                this->Add(array[index]);
          }

          /// @cond
          Dictionary(InitializerList<KeyValuePair<TKey, TValue>> il) : operationNumber(0) {
            for (typename InitializerList<Item>::const_iterator iterator = il.begin(); iterator != il.end(); ++iterator)
              this->Add(*iterator);
          }
          /// @endcond

          /// @brief Adds an KeyValuePair<TKey, TValue> object to the end of the Dictionary<TKey, TValue>.
          /// @param keyValue The pointer object to be added to the end of the Dictionary<TKey, TValue>. The value can ! be null for reference types.
          /// @exception ArgumentNullException The parameters keyValue is null.
          /// @exception ArgumentException An element with the same key already exists in the Dictionary<TKey, TValue>.
          /// @remarks Every key in a Dictionary<TKey, TValue> must be unique according to the default equality comparer.
          /// @par Examples
          /// The following sample show how to use Add function:
          /// @include DictionaryAdd.cpp
          void Add(const Item& item) override {Add(item.Key(), item.Value());}

          /// @brief Adds an element with the provided key and value to the Dictionary<TKey,TValue>.
          /// @param key The object to use as the key of the element to add.
          /// @param value The object to use as the value of the element to add.
          /// @exception ArgumentNullException key is null.
          /// @exception ArgumentException An element with the same key already exists in the IDictionary<TKey,TValue>.
          /// @par Examples
          /// The following sample show how to use Add function:
          /// @include DictionaryAdd.cpp
          void Add(const TKey& key, const TValue& value) override {
            if (ContainsKey(key))
              throw ArgumentException(caller_);
            (*this)[key] = value;
          }

          /// @brief Removes all elements from the List<T>.
          void Clear() override {this->hashmap.clear();}

          /// @brief Determines whether an element is in the Dictionary<TKey,TValue>.
          /// @param keyValue The object to be added to the end of the Dictionary<TKey,TValue>. The value can ! be null for reference types.
          bool Contains(const KeyValuePair<TKey, TValue>& item) const override {
            if (!ContainsKey(item.Key()))
              return false;

            return (*this)[item.Key()] == item.Value();
          }

          /// @brief Determines whether an element is in the Dictionary<TKey,TValue>.
          /// @param key The object to be added to the end of the Dictionary<TKey,TValue>. The value can ! be null for reference types.
          bool ContainsKey(const TKey& key) const override {return this->hashmap.find(key) != this->hashmap.end();}

          /// @brief Determines whether an element is in the Dictionary<TKey,TValue>.
          /// @param value The object to be added to the end of the Dictionary<TKey,TValue>. The value can ! be null for reference types.
          bool ContainsValue(const TValue& value) const {
            for (const auto& item : *this)
              if (value == item.Value)
                return true;
            return false;
          }

          /// @brief Copies the entire Dictionary<TKey,TValue> to a compatible one-dimensional array.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @return Int32 Number of elements copied.
          /// @exception ArgumentNullException The parameters array is null.
          /// @exception ArgumentOutOfRangeException The index is greater then number elements of Dictionary<TKey,TValue>
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the List<T>.
          void CopyTo(System::Array<KeyValuePair<TKey, TValue>>& array) const {CopyTo(array, 0);}

          /// @brief Copies the entire Dictionary<TKey,TValue> to a compatible one-dimensional array, starting at the specified index of the target array.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins;
          /// @return Int32 Number of elements copied.
          /// @exception ArgumentNullException The parameters array is null.
          /// @exception ArgumentOutOfRangeException The index is greater then number elements of Dictionary<TKey,TValue>
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the List<T>.
          void CopyTo(System::Array<KeyValuePair<TKey, TValue>>& array, int32 index) const override {
            if (index < 0 || array.Length < index + this->Count)
              throw System::ArgumentOutOfRangeException(caller_);
            int32 count = 0;
            for (const Item& item : *this)
              array[count++] = Item(item);
          }

          /// @brief Gets the total number of elements the internal data structure.
          /// @return Int32 The number of elements that the Dictionary<TKey,TValue> can contain.
          int32 GetCapacity() const {return static_cast<int32>(this->hashmap.size());}

          /// @brief Returns an enumerator that iterates through the Dictionary<TKey,TValue>.
          /// @return Int32 A Dictionary<TKey,TValue>::Enumerator for the Dictionary<TKey,TValue>.
          System::Collections::Generic::Enumerator<KeyValuePair<TKey, TValue>> GetEnumerator() const override {return System::Collections::Generic::Enumerator<KeyValuePair<TKey, TValue>>(new Dictionary::Enumerator(*((Dictionary*)this)));}

          /// @brief Removes the first occurrence of a specific object from the Dictionary<TKey, TValue>.
          /// @param keyValue The object to remove from the Dictionary<TKey, TValue>. The value can ! be null.
          /// @return true if item is successfully removed; otherwise, false. This method also returns false if item was ! found in the Dictionary<TKey, TValue>.
          /// @exception ArgumentNullException The parameters keyValue is null.
          bool Remove(const KeyValuePair<TKey, TValue>& item) override {
            if (! Contains(item))
              return false;
            this->operationNumber++;
            this->hashmap.erase(item.Key());
            return true;
          }

          /// @brief Removes the first occurrence of a specific object from the Dictionary<TKey, TValue>.
          /// @param key The object to remove from the Dictionary<TKey, TValue>. The value can ! be null.
          /// @return Boolean true if item is successfully removed; otherwise, false. This method also returns false if item was ! found in the Dictionary<TKey, TValue>.
          /// @exception ArgumentNullException The parameters key is null.
          bool Remove(const TKey& key) override {
            if (! ContainsKey(key))
              return false;
            this->operationNumber++;
            this->hashmap.erase(key);
            return true;
          }

          /// @brief Gets the value associated with the specified key.
          /// @param key The key of the value to get.
          /// @param value When this method returns, contains the value associated with the specified key, if the key is found; otherwise, the default value for the type of the value parameter. This parameter is passed uninitialized.
          /// @return true if the System::Collections::Generic::Dictionary<TKey,TValue> contains an element with the specified key; otherwise, false.
          /// @exception System::ArgumentNullException key is null.
          bool TryGetValue(const TKey& key, TValue& value) const override {
            if (!ContainsKey(key))
              return false;
            value = (*this)[key];
            return true;
          }

          /// @brief Set the element at the specified key. If the key is ! found, the element is added at the specified key.
          /// @param key The key of the element to set.
          /// @return TValue The element at the specified key.
          /// @exception ArgumentNullException key is null.
          /// @par Examples
          /// The following sample show how to use [] operators:
          /// @include DictionaryOperators.cpp
          TValue& operator[](const TKey& key) override {
            this->operationNumber++;
            return this->hashmap[key];
          }

          /// @brief Gets the element at the specified index.
          /// @param key The key of the element to get.
          /// @return TValue The element at the specified key.
          /// @exception ArgumentNullException key is null.
          /// @exception ArgumentException key is ! present.
          /// @par Examples
          /// The following sample show how to use [] operators:
          /// @include DictionaryOperators.cpp
          const TValue& operator[](const TKey& key) const override {
            if (! ContainsKey(key))
              throw ArgumentException(caller_);
            return const_cast<std::unordered_map<TKey, TValue, Hasher, EqualTo, TAllocator>&>(this->hashmap)[key];
          }

          /// @brief Clears the list and insert the elements of the list given in argument.
          /// @param dictionnary the list which elements will be inserted from
          /// @return List<T> the list
          /// @exception ArgumentNullException dictionary is null.
          Dictionary& operator=(const Dictionary& dictionary) {
            this->hashmap = dictionary.hashmap;
            this->operationNumber++;
            return *this;
          }

private:
          class Hasher {
          public:
            size_t operator()(const TKey& key) const { return Switch::GetHashCode(key); }
          };

          class EqualTo {
          public:
            bool operator()(const TKey& a, const TKey& b) const {return a == b; }
          };

public:
          /// @cond
          class const_iterator : public std::iterator<std::input_iterator_tag, System::Collections::Generic::KeyValuePair<TKey, TValue>> {
          public:
            const_iterator(const typename std::unordered_map<TKey, TValue, Hasher, EqualTo, TAllocator>::const_iterator& value) : value(value) {}
            const_iterator(const const_iterator& value) : value(value.value) {}
            const_iterator& operator++() {++this->value; return *this;}
            const_iterator operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
            bool operator==(const const_iterator& rhs) const {return this->value == rhs.value;}
            bool operator!=(const const_iterator& rhs) const {return this->value != rhs.value;}
            const System::Collections::Generic::KeyValuePair<TKey, TValue> operator*() {return System::Collections::Generic::KeyValuePair<TKey, TValue>((*value).first, (*value).second);}

          private:
            typename std::unordered_map<TKey, TValue, Hasher, EqualTo, TAllocator>::const_iterator value;
          };

          class iterator : public std::iterator<std::input_iterator_tag, System::Collections::Generic::KeyValuePair<TKey, TValue>> {
          public:
            iterator(const typename std::unordered_map<TKey, TValue, Hasher, EqualTo, TAllocator>::iterator& value) : value(value) {}
            iterator(const iterator& value) : value(value.value) {}
            iterator& operator++() {++this->value; return *this;}
            iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
            bool operator==(const iterator& rhs) {return this->value == rhs.value;}
            bool operator!=(const iterator& rhs) {return this->value != rhs.value;}
            System::Collections::Generic::KeyValuePair<TKey, TValue> operator*() {return System::Collections::Generic::KeyValuePair<TKey, TValue>((*value).first, (*value).second);}

          private:
            typename std::unordered_map<TKey, TValue, Hasher, EqualTo, TAllocator>::iterator value;
          };

          const_iterator cbegin() const {return const_iterator(this->hashmap.begin());}
          const_iterator cend() const {return const_iterator(this->hashmap.end());}
          iterator begin() {return iterator(this->hashmap.begin());}
          const_iterator begin() const {return const_iterator(this->hashmap.begin());}
          iterator end() {return iterator(this->hashmap.end());}
          const_iterator end() const {return const_iterator(this->hashmap.end());}

          class Enumerator : public Object, public IEnumerator<KeyValuePair<TKey, TValue>> {
          public:
            Enumerator(Dictionary& dictionary) : dictionary(dictionary) {Reset();}

            Enumerator(const Enumerator& enumerator) : operationNumber(enumerator.operationNumber), dictionary(enumerator.dictionary), currentKeyValuePair(enumerator.currentKeyValuePair), iterator(enumerator.iterator), beforeFirst(enumerator.beforeFirst) {}

            void Reset() {
              this->operationNumber = this->dictionary.operationNumber;
              this->iterator = this->dictionary.hashmap.begin();
              this->beforeFirst = true;
            }

            virtual bool MoveNext() {
              if (this->operationNumber != this->dictionary.operationNumber)
                throw System::InvalidOperationException(caller_);

              if (IsFinished())
                return false;

              if (this->beforeFirst)
                this->beforeFirst = false;
              else
                this->iterator++;

              if (IsFinished())
                return false;

              this->currentKeyValuePair = ref_new<Item>((*this->iterator).first, (*this->iterator).second);
              return true;
            }

          protected:
            const KeyValuePair<TKey, TValue>& GetCurrent() const {
              if (this->beforeFirst || IsFinished())
                throw System::InvalidOperationException(caller_);
              return *this->currentKeyValuePair;
            }

            bool IsFinished() const {return this->iterator == this->dictionary.hashmap.end();}
            int64 operationNumber;
            Dictionary& dictionary;
            refptr<Item> currentKeyValuePair;
            typename std::unordered_map<TKey, TValue, Hasher, EqualTo, TAllocator>::iterator iterator;
            bool beforeFirst;
          };

protected:
          std::unordered_map<TKey, TValue, Hasher, EqualTo, TAllocator> hashmap;
          refptr< IComparer<TKey>> comparer;
          int64 operationNumber;
          Object syncRoot;
          /// @endcond

private:
          int32 GetCount() const override {return static_cast<int32>(this->hashmap.size());}
          bool GetIsReadOnly() const override {return false;}
          bool GetIsSynchronized() const override {return false;}

          KeyCollection GetKeys() const override {
            KeyCollection keys;
            for (auto item : this->hashmap)
              keys.Add(item.first);
            return keys;
          }

          ValueCollection GetValues() const override {
            ValueCollection values;
            for (auto item : this->hashmap)
              values.Add(item.second);
            return values;
          }

          const Object& GetSyncRoot() const override {return syncRoot;}
        };
      }
    }
  }
}

using namespace Switch;

