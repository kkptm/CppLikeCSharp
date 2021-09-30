/// @file
/// @brief Contains Switch::System::Collections::ObjectModel::Collection <T> class.
#pragma once

#include "../Generic/List.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::ObjectModel namespace contains classes that can be used as collections in the object model of a reusable library. Use these classes when properties or methods return collections.
      namespace ObjectModel {
        /// @brief Represents a non-generic collection of objects that can be individually accessed by index.
        template<typename T, typename TAllocator = Allocator<T>>
        class Collection : public Object, public Generic::IList<T> {
        public:
          /// @brief Initializes a new instance of the Collection<T> class that is empty.
          /// @remarks The Collection<T> class is not thread safe.
          Collection() {}

          /// @brief Initializes a new instance of the Collection<T> class that contains elements copied from the specified collection and has sufficient capacity to accommodate the number of elements copied.
          /// @param collection The collection whose elements are copied to the new Collection.
          /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
          /// @remarks The Collection<T> class is not thread safe.
          Collection(const Generic::IList<T>& list) : collection(list) {}

          /// @brief Initializes a new instance of the Collection<T> class that is empty and has the default initial capacity (512 items).
          /// @remarks The Collection<T> class is not thread safe.
          Collection(T itemsArray[], int32 capacity) : collection(itemsArray, capacity) {}

          /// @brief Default copy constructor
          /// @remarks The Collection<T> class is not thread safe.
          Collection(const Collection<T>& collection) : collection(collection) {}

          /// @brief Adds an object to the end of the Collection<T>.
          /// @param value The object to be added to the end of the Collection<T>. The value can not be null for reference types.
          /// @exception ArgumentNullException The parameters value is null.
          /// @remarks Collection<T> allows duplicate elements.
          void Add(const T& value) {this->collection.Add(value);}

          /// @brief Adds an object to the end of the Collection<T>.
          /// @param value The pointer object to be added to the end of the Collection<T>. The value can be null.
          /// @remarks Collection<T> allows duplicate elements.
          void Add(T* value) {this->collection.Add(value);}

          /// @brief Removes all elements from the Collection<T>.
          void Clear() {this->collection.Clear();}

          /// @brief Removes all elements from the Collection<T>.
          void ClearItems() {this->collection.Clear();}

          /// @brief Determines whether an element is in the Collection<T>.
          /// @param value The object to be added to the end of the Collection<T>. The value can not be null for reference types.
          virtual bool Contains(const T& value) const {return this->collection.Contains(value);}

          /// @brief Copies the entire Collection<T> to a compatible one-dimensional array.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @param arraySize The size of Array that is the destination.
          /// @return Int32 Number of elements copied.
          /// @exception ArgumentNullException The parameters array is null.
          /// @exception ArgumentOutOfRangeException The arraySize is less than 0.
          /// @exception ArgumentException arrayIndex is equal to or greater than the length of array.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the Collection<T>.
          int32 CopyTo(T array[], int32 arraySize) const {return this->collection.CopyTo(array, arraySize);}

          /// @brief Copies the entire Collection<T> to a compatible one-dimensional array, starting at the specified index of the target array.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @param arraySize The size of Array that is the destination.
          /// @param arrayIndex The zero-based index in array at which copying begins;
          /// @return int32 Number of elements copied.
          /// @exception ArgumentNullException The parameters array is null.
          /// @exception ArgumentOutOfRangeException The arraySize is less than 0 - or - The arrayIndex is less than 0.
          /// @exception ArgumentException arrayIndex is equal to or greater than the length of array -or-
          /// @return The number of elements in the source Collection<T> is greater than the available space from arrayIndex to the end of the destination array.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the Collection<T>.
          int32 CopyTo(T array[], int32 arraySize, int32 arrayIndex) const {return this->collection.CopyTo(array, arraySize, arrayIndex);}

          /// @brief Copies the entire Collection<T> to a compatible one-dimensional array, starting at the specified index of the target array.
          /// @param index The zero-based index in the source Collection<T> at which copying begins.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @param arraySize The size of Array that is the destination.
          /// @param arrayIndex The zero-based index in array at which copying begins;
          /// @param count The number of elements to copy.
          /// @return Int32 Number of elements copied.
          /// @exception ArgumentNullException The parameters array is null.
          /// @exception ArgumentOutOfRangeException The arrayIndex is less than 0.
          /// @exception ArgumentException index is equal to or greater than the Count of the source Collection<T>. -or-
          /// @return arrayIndex is equal to or greater than the length of array -or-
          /// @return The number of elements in the source Collection<T> is greater than the available space from arrayIndex to the end of the destination array.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the Collection<T>.
          int32 CopyTo(int32 index, T array[], int32 arraySize, int32 arrayIndex, int32 count) const {return this->collection.CopyTo(index, array, arraySize, arrayIndex, count);}

          /// @brief Gets the total number of elements the internal data structure.
          /// @return Int32 The number of elements that the Collection<T> can contain.
          int32 GetCapacity() const {return this->collection.GetCapacity();}

          int32 GetMaxCapacity() const {return this->collection.GetMaxCapacity();}

          /// @brief Returns an enumerator that iterates through the Collection<T>.
          /// @return Int32 A Collection<T>::Enumerator for the Collection<T>.
          Generic::Enumerator<T> GetEnumerator() const override {return this->collection.GetEnumerator();}

          /// @brief Determines the index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @return Int32 The index of value if found in the Collection; otherwise, -1.
          virtual int32 IndexOf(const T& value) const {return this->collection.IndexOf(value);}

          /// @brief Determines the index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @param index The zero-based starting index of the search.
          /// @return Int32 The index of value if found in the Collection; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0.
          virtual int32 IndexOf(const T& value, Int32 index) const {return this->collection.IndexOf(value, index);}

          /// @brief Determines the index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @param index The zero-based starting index of the search.
          /// @param count The number of elements in the section to search
          /// @return Int32 The index of value if found in the Collection; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0 or The parameters count is less than 0 or index and count do not specify a valid section in the Collection<T>.
          virtual int32 IndexOf(const T& value, Int32 index, Int32 count) const {return this->collection.IndexOf(value, index, count);}

          /// @brief Inserts an element into the Collection<T> at the specified index.
          /// @param index The zero-based index at which the new element should be inserted.
          /// @param value The element should be inserted into the Collection<T>. The value can not be null.
          /// @exception ArgumentNullException The parameters value is null.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
          /// @remarks Collection<T> allows duplicate elements.
          virtual void Insert(int32 index, const T& value) {return this->collection.Insert(index, value);}

          /// @brief Inserts an element into the Collection<T> at the specified index.
          /// @param index The zero-based index at which the new element should be inserted.
          /// @param value The element should be inserted into the Collection<T>. The value can not be null.
          /// @exception ArgumentNullException The parameters value is null.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
          /// @remarks Collection<T> allows duplicate elements.
          void Insert(int32 index, T* value) {return this->collection.Insert(index, value);}

          /// @brief Inserts an element into the Collection<T> at the specified index.
          /// @param index The zero-based index at which the new element should be inserted.
          /// @param value The element should be inserted into the Collection<T>. The value can not be null.
          /// @exception ArgumentNullException The parameters value is null.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
          /// @remarks Collection<T> allows duplicate elements.
          void InsertItem(int32 index, const T& value) {return this->collection.Insert(index, value);}

          /// @brief Inserts an element into the Collection<T> at the specified index.
          /// @param index The zero-based index at which the new element should be inserted.
          /// @param value The element should be inserted into the Collection<T>. The value can not be null.
          /// @exception ArgumentNullException The parameters value is null.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
          /// @remarks Collection<T> allows duplicate elements.
          void InsertItem(int32 index, T* value) {return this->collection.Insert(index, value);}

          /// @brief Determines the last index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @return Int32 The last index of value if found in the Collection; otherwise, -1.
          int32 LastIndexOf(const T& value) const {return this->collection.LastIndexOf(value);}

          /// @brief Determines the last index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @param index The zero-based starting index of the search.
          /// @return Int32 The last index of value if found in the Collection; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0.
          int32 LastIndexOf(const T& value, int32 index) const {return this->collection.LastIndexOf(value, index);}

          /// @brief Determines the last index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @param index The zero-based starting index of the search.
          /// @param count The number of elements in the section to search
          /// @return Int32 The last index of value if found in the Collection; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0 or The parameters count is less than 0 or index and count do not specify a valid section in the Collection<T>.
          int32 LastIndexOf(const T& value, int32 index, int32 count) const {return this->collection.LastIndexOf(value, index, count);}

          /// @brief Removes the first occurrence of a specific object from the Collection<T>.
          /// @param item The object to remove from the Collection<(Of <(T>)>). The value can not be null.
          /// @return Boolean true if item is successfully removed; otherwise, false. This method also returns false if item was not found in the Collection<T>.
          /// @exception ArgumentNullException The parameters item is null.
          virtual bool Remove(const T& item) {return this->collection.Remove(item);}

          /// @brief Removes the first occurrence of a specific object from the Collection<T>.
          /// @param item The object to remove from the Collection<(Of <(T>)>). The value can not be null.
          /// @return Boolean true if item is successfully removed; otherwise, false. This method also returns false if item was not found in the Collection<T>.
          /// @exception ArgumentNullException The parameters item is null.
          virtual bool Remove(T* item) {return this->collection.Remove(item);}

          /// @brief Removes the element at the specified index of the Collection<T>.
          /// @param index The zero-based index of the item to remove
          /// @return None.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
          virtual void RemoveAt(int32 index) {return this->collection.RemoveAt(index);}

          /// @brief Removes the first occurrence of a specific object from the Collection<T>.
          /// @param item The object to remove from the Collection<T>. The value can not be null.
          /// @return Boolean true if item is successfully removed; otherwise, false. This method also returns false if item was not found in the Collection<T>.
          /// @exception ArgumentNullException The parameters item is null.
          Boolean RemoveItem(const T& item) {return this->collection.Remove(item);}

          /// @brief Removes the first occurrence of a specific object from the Collection<T>.
          /// @param item The object to remove from the Collection<T>. The value can not be null.
          /// @return Boolean true if item is successfully removed; otherwise, false. This method also returns false if item was not found in the Collection<T>.
          /// @exception ArgumentNullException The parameters item is null.
          Boolean RemoveItem(T* item) {return this->collection.Remove(item);}

          /// @brief Gets the element at the specified index.
          /// @param index The zero-based index of the element to get.
          /// @return T The element at the specified index.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
          const T& operator[](int32 index) const {return this->collection[index];}

          /// @brief Gets the element at the specified index.
          /// @param index The zero-based index of the element to get.
          /// @return T The element at the specified index.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
          T& operator[](int32 index) {return this->collection[index];}

          /// @brief Clear the Collection and insert the element of the Collection given in argument.
          /// @param collection the Collection which elements will be inserted from
          /// @return Collection<T> the Collection
          Collection<T>& operator=(const Collection<T>& collection) {this->collection = collection.collection;}

        protected:
          /// @cond
          Generic::List<T, TAllocator> collection;
          /// @endcond

        private:
          virtual int32 GetCount() const {return this->collection.Count;}
          virtual bool GetIsFixedSize() const {return this->collection.IsFixedSize;}
          virtual bool GetIsReadOnly() const {return this->collection.IsReadOnly;}
          virtual bool GetIsSynchronized() const {return this->collection.IsSynchronized;}
          virtual const object& GetSyncRoot() const {return this->collection.SyncRoot;}
        };
      }
    }
  }
}
