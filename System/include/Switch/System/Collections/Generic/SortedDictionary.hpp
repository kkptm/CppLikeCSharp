/// @file
/// @brief Contains Switch::System::Collections::Generic::SortedDictionary <TKey, TValue> class.
#pragma once

#include <map>

#include <Switch/Allocator.hpp>
#include <Switch/InitializerList.hpp>
#include <Switch/Types.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Collections/Generic/Comparer.hpp>
#include <Switch/System/Collections/Generic/IComparer.hpp>
#include <Switch/System/Collections/Generic/IDictionary.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Linq/Enumerable.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @brief Represents a collection of key/value pairs that are sorted on the key.
        /// @par Examples
        /// The following code example creates an empty SortedDictionary<TKey, TValue> of strings with string keys and uses the Add method to add some elements. The example demonstrates that the Add method throws an ArgumentException when attempting to add a duplicate key.
        /// The example uses the Item property to retrieve values, demonstrating that a KeyNotFoundException is thrown when a requested key is ! present, and showing that the value associated with a key can be replaced.
        /// The example shows how to use the TryGetValue method as a more efficient way to retrieve values if a program often must try key values that are ! in the dictionary, and it shows how to use the ContainsKey method to test whether a key exists before calling the Add method.
        /// The example shows how to enumerate the keys and values in the dictionary and how to enumerate the keys and values alone using the Keys property and the Values property.
        /// Finally, the example demonstrates the Remove method.
        /// @include SortedDictionary.cpp
        template<typename TKey, typename TValue, typename TAllocator = Allocator<std::pair<const TKey, TValue>>>
            class SortedDictionary : public Object, public System::Linq::Extension::Enumerable<SortedDictionary<TKey, TValue, TAllocator>, System::Collections::Generic::KeyValuePair<TKey, TValue>>, public IDictionary<TKey, TValue> {
          using Item = System::Collections::Generic::KeyValuePair<TKey, TValue>;
public:
          /// @brief Represents the collection of keys in a Dictionary<TKey, TValue>. This class cannot be inherited.
          using KeyCollection = typename IDictionary<TKey, TValue>::KeyCollection;

          /// @brief Represents the collection of values in a Dictionary<TKey, TValue>. This class cannot be inherited.
          using ValueCollection = typename IDictionary<TKey, TValue>::ValueCollection;

          /// @brief Initializes a new instance of the System::Collections::Generic::SortedDictionary<TKey,TValue>
          /// class that is empty and uses the default System::Collections::Generic::IComparer<T>
          /// implementation for the key type.
          SortedDictionary() : operationNumber(0), comparer(new System::Collections::Generic::Comparer<TKey>()), map(MapComparer(*this->comparer)) {}

          /// @brief Initializes a new instance of the System::Collections::Generic::SortedDictionary<TKey,TValue> class that is empty and uses the specified System::Collections::Generic::IComparer<T> implementation to compare keys.
          /// @param comparer The System::Collections::Generic::IComparer<T> implementation to use when comparing keys, or null to use the default System::Collections::Generic::Comparer<T> for the type of the key.
          SortedDictionary(refptr<IComparer<TKey>>& comparer) : operationNumber(0), comparer(comparer), map(MapComparer(*this->comparer)) {this->init(comparer);}

          /// @brief Initializes a new instance of the System::Collections::Generic::SortedDictionary<TKey,TValue> class that contains elements copied from the specified System::Collections::Generic::IDictionary<TKey,TValue> and uses the default System::Collections::Generic::IComparer<T> implementation for the key type.
          /// @param dictionary The System::Collections::Generic::IDictionary<TKey,TValue> whose elements are  copied to the new System::Collections::Generic::SortedDictionary<TKey,TValue>.
          /// @exception System::ArgumentException dictionary contains one or more duplicate keys.
          SortedDictionary(const SortedDictionary& dictionary) : operationNumber(dictionary.operationNumber), comparer(dictionary.comparer), map(MapComparer(*this->comparer)) {
            for (const auto& item : dictionary)
              Add(item);
          }

          /// @cond
          SortedDictionary(SortedDictionary&& dictionary) : operationNumber(dictionary.operationNumber), comparer(dictionary.comparer), map(Move(dictionary.map)) {
            dictionary.operationNumber = 0;
            dictionary.comparer.Reset();
          }
          /// @endcond

          SortedDictionary(const IDictionary<TKey, TValue>& dictionary) : operationNumber(0), comparer(new System::Collections::Generic::Comparer<TKey>()), map(MapComparer(*this->comparer)) {
            for (const auto& item : dictionary)
              Add(item);
          }

          /// @brief Initializes a new instance of the System::Collections::Generic::SortedDictionary<TKey,TValue> class that contains elements copied from the specified System::Collections::Generic::IDictionary<TKey,TValue> and uses the specified System::Collections::Generic::IComparer<T> implementation to compare keys.
          /// @param dictionary The System::Collections::Generic::IDictionary<TKey,TValue> whose elements are copied to the new System::Collections::Generic::SortedDictionary<TKey,TValue>.
          /// @param comparer The System::Collections::Generic::IComparer<T> implementation to use when comparing keys, or null to use the default System::Collections::Generic::Comparer<T> for the type of the key.
          /// @exception System::ArgumentNullException dictionary is null.
          /// @exception System::ArgumentException dictionary contains one or more duplicate keys.
          SortedDictionary(const IDictionary<TKey, TValue>& dictionary, refptr<IComparer<TKey>>& comparer) : operationNumber(0), comparer(comparer), map(MapComparer(*this->comparer)) {
            for (auto p : dictionary)
              Add(p.Key(), p.Value());
          }

          /// @brief Initializes a new instance of the SortedDictionary<TKey, TValue> class with Tkey and TValue array specified.
          /// @param array An array of Tkey and TValue to initialize Dictionnary.
          /// @param capacity The number of elements that the new list can initially store (maximum 512 items).
          /// @exception ArgumentNullException The parameters array is null.
          /// @remarks The SortedDictionary<TKey, TValue> class is ! thread safe.
          SortedDictionary(const System::Array<KeyValuePair<TKey, TValue>>& array) : operationNumber(0), comparer(new System::Collections::Generic::Comparer<TKey>()), map(MapComparer(*this->comparer)) {
            for (auto elem : array)
              Add(elem.Key(), elem.Value());
          }

          /// @brief Initializes a new instance of the SortedDictionary and copy array[] T.
          /// @param array the Array to copy.
          /// @remarks The SortedDictionary class is ! thread safe.
          template<int32 len>
          SortedDictionary(const Item(&array)[len]) : operationNumber(0), comparer(new System::Collections::Generic::Comparer<TKey>()), map(MapComparer(*this->comparer)) {
            for (int32 index = 0; index < len; index++)
                this->Add(array[index].Key(), array[index].Value());
          }

          /// @cond
          SortedDictionary(InitializerList<KeyValuePair<TKey, TValue>> il) : operationNumber(0), comparer(new System::Collections::Generic::Comparer<TKey>()), map(MapComparer(*this->comparer)) {
            for (typename InitializerList<Item>::const_iterator iterator = il.begin(); iterator != il.end(); ++iterator)
              this->Add(*iterator);
          }
          /// @endcond

          /// @brief Adds an KeyValuePair<TKey, TValue> object to the end of the SortedDictionary<TKey, TValue>.
          /// @param keyValue The pointer object to be added to the end of the SortedDictionary<TKey, TValue>. The value can ! be null for reference types.
          /// @exception ArgumentNullException The parameters keyValue is null.
          /// @exception ArgumentException An element with the same key already exists in the SortedDictionary<TKey, TValue>.
          /// @remarks Every key in a SortedDictionary<TKey, TValue> must be unique according to the default equality comparer.
          /// @par Examples
          /// The following sample show how to use Add function:
          /// @include SortedDictionaryAdd.cpp
          void Add(const KeyValuePair<TKey, TValue>& keyValue) override {
            Add(keyValue.Key(), keyValue.Value());
          }

          /// @brief Adds an element with the specified key and value into the System::Collections::Generic::SortedDictionary<TKey,TValue>.
          /// @param key The key of the element to add.
          /// @param value The value of the element to add. The value can be null for reference types.
          /// @exception System::ArgumentNullException key is null.
          /// @exception System::ArgumentException An element with the same key already exists in the System::Collections::Generic::SortedDictionary<TKey,TValue>.
          void Add(const TKey& key, const TValue& value) override {
            if (ContainsKey(key))
              throw System::ArgumentException(caller_);

            (*this)[key] = value;
          }

          /// @brief Removes all elements from the SortedDictionary<TKey,TValue>.
          void Clear() override {
            this->map.clear();
          }

          /// @brief Determines whether an element is in the SortedDictionary<TKey,TValue>.
          /// @param keyValue The object to be added to the end of the SortedDictionary<TKey,TValue>. The value can ! be null for reference types.
          virtual bool Contains(const KeyValuePair<TKey, TValue>& keyValue) const override {
            if (!ContainsKey(keyValue.Key()))
              return false;

            return keyValue.Value() == (*this)[keyValue.Key()];
          }

          /// @brief Determines whether the System::Collections::Generic::SortedDictionary<TKey,TValue> contains an element with the specified key.
          /// @param key The key to locate in the System::Collections::Generic::SortedDictionary<TKey,TValue>.
          /// @return true if the System::Collections::Generic::SortedDictionary<TKey,TValue> contains an element with the specified key; otherwise, false.
          /// @exception System::ArgumentNullException key is null.
          virtual bool ContainsKey(const TKey& key) const override {
            return this->map.find(key) != this->map.end();
          }

          /// @brief Determines whether the System::Collections::Generic::SortedDictionary<TKey,TValue> contains an element with the specified value.
          /// @param value The value to locate in the System::Collections::Generic::SortedDictionary<TKey,TValue>. The value can be null for reference types.
          /// @return true if the System::Collections::Generic::SortedDictionary<TKey,TValue> contains an element with the specified value; otherwise, false.
          bool ContainsValue(const TValue& value) const {
            for (auto p : *this) {
              if (p.Value() == value)
                return true;
            }

            return false;
          }

          /// @brief Copies the entire SortedDictionary<TKey,TValue> to a compatible one-dimensional array.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @exception ArgumentNullException The parameters array is null.
          /// @exception ArgumentOutOfRangeException The index is greater then number elements of SortedDictionary<TKey,TValue>
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the SortedDictionary
          void CopyTo(System::Array<KeyValuePair<TKey, TValue>>& array) const {
            this->CopyTo(array, 0);
          }

          /// @brief Copies the elements of the System::Collections::Generic::SortedDictionary<TKey,TValue> to the specified array of System::Collections::Generic::KeyValuePair<TKey,TValue> structures, starting at the specified index.
          /// @param array The one-dimensional array of System::Collections::Generic::KeyValuePair<TKey,TValue> structures that is the destination of the elements copied from the current System::Collections::Generic::SortedDictionary<TKey,TValue> The array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins.
          /// @exception System::ArgumentNullException array is null.
          /// @exception System::ArgumentOutOfRangeException index is less than 0.
          /// @exception System::ArgumentException The number of elements in the source System::Collections::Generic::SortedDictionary<TKey,TValue> is greater than the available space from index to the end of the destination array.
          void CopyTo(System::Array<KeyValuePair<TKey, TValue>>& array, int32 index) const override {
            if (index < 0 || array.Length < index + this->Count)
              throw ArgumentOutOfRangeException(caller_);

            int32 count = index;
            for (auto elem : *this)
              array[count++] = KeyValuePair<TKey, TValue>(elem.Key(), elem.Value());

            return;
          }

          /// @brief Returns an enumerator that iterates through the System::Collections::Generic::SortedDictionary<TKey,TValue>.KeyCollection.
          /// @return A System::Collections::Generic::SortedDictionary<TKey,TValue>.KeyCollection.Enumerator structure for the System::Collections::Generic::SortedDictionary<TKey,TValue>.KeyCollection.
          System::Collections::Generic::Enumerator<KeyValuePair<TKey, TValue>> GetEnumerator() const override {
            return System::Collections::Generic::Enumerator<KeyValuePair<TKey, TValue>>(new SortedDictionary::Enumerator(*const_cast<SortedDictionary*>(this)));
          }

          /// @brief Removes the element with the specified key from the System::Collections::Generic::SortedDictionary<TKey,TValue>.
          /// @param key The key of the element to remove.
          /// @return true if the element is successfully removed; otherwise, false. This method also returns false if key is ! found in the System::Collections::Generic::SortedDictionary<TKey,TValue>.
          /// @exception System::ArgumentNullException key is null.
          bool Remove(const KeyValuePair<TKey, TValue>& kvp) override {
            if (!Contains(kvp))
              return false;

            this->operationNumber++;
            return this->map.erase(kvp.Key()) >= 1;
          }

          /// @brief Removes the element with the specified key from the System::Collections::Generic::SortedDictionary<TKey,TValue>.
          /// @param key The key of the element to remove.
          /// @return true if the element is successfully removed; otherwise, false. This method also returns false if key is ! found in the System::Collections::Generic::SortedDictionary<TKey,TValue>.
          /// @exception System::ArgumentNullException key is null.
          virtual bool Remove(const TKey& key) override {
            this->operationNumber++;
            return this->map.erase(key) >= 1;
          }

          /// @brief Gets the value associated with the specified key.
          /// @param key The key of the value to get.
          /// @param value When this method returns, the value associated with the specified key, if the key is found; otherwise, the default value for the type of the value parameter.
          /// @return true if the System::Collections::Generic::SortedDictionary<TKey,TValue> contains an element with the specified key; otherwise, false.
          /// @exception System::ArgumentNullException key is null.
          virtual bool TryGetValue(const TKey& key, TValue& value) const override {
            if (! ContainsKey(key)) {
              value = TValue();
              return false;
            }

            value = (*this)[key];
            return true;
          }

          /// @brief Set the element at the specified key. If the key is ! found, the element is added at the specified key.
          /// @param key The key of the element to set.
          /// @return TValue The element at the specified key.
          /// @exception ArgumentNullException key is null.
          /// @par Examples
          /// The following sample show how to use [] operators:
          /// @include SortedDictionaryOperators.cpp
          TValue& operator[](const TKey& key) override {
            this->operationNumber++;
            return this->map[key];
          }

          /// @brief Gets the element at the specified index.
          /// @param key The key of the element to get.
          /// @return TValue The element at the specified key.
          /// @exception ArgumentNullException key is null.
          /// @exception ArgumentException key is ! present.
          /// @par Examples
          /// The following sample show how to use [] operators:
          /// @include SortedDictionaryOperators.cpp
          const TValue& operator[](const TKey& key) const override {
            if (! ContainsKey(key))
              throw ArgumentException(caller_);

            return const_cast<std::map<TKey, TValue, MapComparer, TAllocator>&>(this->map)[key];
          }

          /// @brief Clear the SortedDictionary and insert the element of the SortedDictionary given in argument.
          /// @param dictionnary the SortedDictionary which elements will be inserted from
          /// @return a reference to the current SortedDictionary
          /// @exception ArgumentNullException dictionary is null.
          SortedDictionary& operator=(const SortedDictionary& dictionary) {
            this->comparer = dictionary.comparer;
            this->map = dictionary.map;
            this->operationNumber = 0;
            return *this;
          }

private:
          /// @cond
          class MapComparer : public std::binary_function<TKey, TKey, bool> {
          private:
            ref<IComparer<TKey>> comparer;

          public:
            MapComparer(ref<IComparer<TKey>> c) : comparer(c) { }
            MapComparer(const MapComparer& mc) { comparer = mc.comparer; }
            ~MapComparer() { }

            MapComparer& operator=(const MapComparer& mc) { comparer = mc.comparer; return *this; }
            bool operator()(const TKey& e1, const TKey& e2) const { return comparer().Compare(e1, e2) < 0; }
          };
          /// @endcond

public:
          /// @cond
          class const_iterator : public std::iterator<std::input_iterator_tag, System::Collections::Generic::KeyValuePair<TKey, TValue>> {
          public:
            const_iterator(const typename std::map<TKey, TValue, MapComparer, TAllocator>::const_iterator& value) : value(value) {}
            const_iterator(const const_iterator& value) : value(value.value) {}
            const_iterator& operator++() {++this->value; return *this;}
            const_iterator operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
            bool operator==(const const_iterator& rhs) const {return this->value == rhs.value;}
            bool operator!=(const const_iterator& rhs) const {return this->value != rhs.value;}
            const System::Collections::Generic::KeyValuePair<TKey, TValue> operator*() {return System::Collections::Generic::KeyValuePair<TKey, TValue>((*value).first, (*value).second);}

          private:
            typename std::map<TKey, TValue, MapComparer, TAllocator>::const_iterator value;
          };

          class iterator : public std::iterator<std::input_iterator_tag, System::Collections::Generic::KeyValuePair<TKey, TValue>> {
          public:
            iterator(const typename std::map<TKey, TValue, MapComparer, TAllocator>::iterator& value) : value(value) {}
            iterator(const iterator& value) : value(value.value) {}
            iterator& operator++() {++this->value; return *this;}
            iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
            bool operator==(const iterator& rhs) {return this->value == rhs.value;}
            bool operator!=(const iterator& rhs) {return this->value != rhs.value;}
            System::Collections::Generic::KeyValuePair<TKey, TValue> operator*() {return System::Collections::Generic::KeyValuePair<TKey, TValue>((*value).first, (*value).second);}

          private:
            typename std::map<TKey, TValue, MapComparer, TAllocator>::iterator value;
          };

          const_iterator cbegin() const {return const_iterator(this->map.begin());}
          const_iterator cend() const {return const_iterator(this->map.end());}
          iterator begin() {return iterator(this->map.begin());}
          const_iterator begin() const {return const_iterator(this->map.begin());}
          iterator end() {return iterator(this->map.end());}
          const_iterator end() const {return const_iterator(this->map.end());}
          /// @endcond

          class Enumerator : public object, public IEnumerator<KeyValuePair<TKey, TValue>> {
          public:
            Enumerator(SortedDictionary<TKey, TValue>& dictionary) : dictionary(dictionary) {Reset();}
            Enumerator(const Enumerator& other): operationNumber(other.operationNumber), dictionary(other.dictionary), currentKeyValuePair(other.currentKeyValuePair), iterator(other.iterator), beforeFirst(other.beforeFirst) {}

            void Reset() {
              this->operationNumber = this->dictionary.operationNumber;
              this->iterator = this->dictionary.map.begin();
              this->beforeFirst = true;
            }

            virtual bool MoveNext() {

              if (this->operationNumber != this->dictionary.operationNumber)
                throw InvalidOperationException(caller_);

              if (IsFinished())
                return false;

              if (this->beforeFirst)
                this->beforeFirst = false;
              else
                this->iterator++;

              if (IsFinished()) return false;

              this->currentKeyValuePair = KeyValuePair<TKey, TValue>((*this->iterator).first, (*this->iterator).second);

              return true;
            }

          protected:
            const KeyValuePair<TKey, TValue>& GetCurrent() const  {
              if (this->beforeFirst || IsFinished())
                throw InvalidOperationException(caller_);
              return this->currentKeyValuePair;
            }

            bool IsFinished() const {return this->iterator == this->dictionary.map.end();}
            int64 operationNumber;
            SortedDictionary& dictionary;
            KeyValuePair<TKey, TValue> currentKeyValuePair;
            typename std::map<TKey, TValue, MapComparer, TAllocator>::iterator iterator;
            bool beforeFirst;
          };

protected:
          int64 operationNumber;
          refptr<IComparer<TKey>> comparer;
          std::map<TKey, TValue, MapComparer, TAllocator> map;
          object syncRoot;
          /// @endcond

private:
          int32 GetCount() const override {return static_cast<int32>(this->map.size());}

          bool GetIsReadOnly() const override {return false;}

          bool GetIsSynchronized() const override {return false;}

          KeyCollection GetKeys() const override {
            KeyCollection keys;
            for (auto item : this->map)
              keys.Add(item.first);
            return keys;
          }

          ValueCollection GetValues() const override {
            ValueCollection values;
            for (auto item : this->map)
              values.Add(item.second);
            return values;
          }


          const object& GetSyncRoot() const override {return this->syncRoot;}
        };
      }
    }
  }
}

using namespace Switch;
