/// @file
/// @brief Contains Switch::System::Collections::ObjectModel::ReadOnlyCollection <T> class.
#pragma once

#include "../../../Allocator.hpp"
#include "../../../Types.hpp"
#include "../../NotSupportedException.hpp"
#include "../../Object.hpp"
#include "../../_String.hpp"
#include "../../../System/Collections/Generic/IList.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @cond
      namespace Generic {
        template<typename T, typename TAllocator = Allocator<T>> class List;
      }
      /// @endcond

      /// @brief The System::Collections::ObjectModel namespace contains classes that can be used as collections in the object model of a reusable library. Use these classes when properties or methods return collections.
      namespace ObjectModel {
        /// @brief Provides the base class for a generic read-only collection.
        template<typename T, typename TAllocator = Allocator<T>>
        class ReadOnlyCollection : public System::Collections::Generic::IList<T> {
        public:
          /// @brief Initializes a new instance of the ReadOnlyCollection<T> class that contains elements copied from the specified List and has sufficient capacity to accommodate the number of elements copied.
          /// @param List The IList whose elements are copied to the new Collection.
          /// @exception ArgumentNullException The parameters List is null or element reference null in collection.
          /// @remarks The ReadOnlyCollection<T> class is not thread safe.
          explicit ReadOnlyCollection(const Generic::IList<T>& list) : list(list) {}

          /// @brief Initializes a new instance of the ReadOnlyCollection<T> class that with items specified.
          /// @remarks The Collection<T> class is not thread safe.
          ReadOnlyCollection(T items[], int32 capacity) : list(items, capacity) {}

          /// @brief Default copy constructor
          /// @remarks The Collection<T> class is not thread safe.
          ReadOnlyCollection(const ReadOnlyCollection<T>& collection) : list(collection.list) {}

          /// @brief Determines whether an element is in the Collection<T>.
          /// @param value The object to be added to the end of the Collection<T>. The value can not be null for reference types.
          bool Contains(const T& value) const override {return this->list.IndexOf(value) > -1;}

          /// @brief Copies the entire Collection<T> to a compatible one-dimensional array.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @return Int32 Number of elements copied.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the Collection<T>.
          void CopyTo(System::Array<T>& array) const {this->CopyTo(0, array, 0, array.GetLegnth());}

          /// @brief Copies the entire Collection<T> to a compatible one-dimensional array, starting at the specified index of the target array.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @param arrayIndex The zero-based index in array at which copying begins;
          /// @return Int32 Number of elements copied.
          /// @exception ArgumentException arrayIndex is equal to or greater than the length of array - or -  The number of elements in the source Collection<T> is greater than the available space from arrayIndex to the end of the destination array.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the Collection<T>.
          void CopyTo(System::Array<T>& array, int32 arrayIndex) const override {this->CopyTo(0, array, arrayIndex, array.Length);}

          /// @brief Copies the entire Collection<T> to a compatible one-dimensional array, starting at the specified index of the target array.
          /// @param index The zero-based index in the source Collection<T> at which copying begins.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @param arrayIndex The zero-based index in array at which copying begins;
          /// @param count The number of elements to copy.
          /// @return Int32 Number of elements copied.
          /// @exception ArgumentOutOfRangeException The arrayIndex is less than 0.
          /// @exception ArgumentException index is equal to or greater than the Count of the source Collection<T>. -or-  arrayIndex is equal to or greater than the length of array -or-  the number of elements in the source Collection<T> is greater than the available space from arrayIndex to the end of the destination array.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the Collection<T>.
          void CopyTo(int32 index, System::Array<T>& array, int32 arrayIndex, int32 count) const {this->list.CopyTo(index, array, arrayIndex, count);}

          /// @brief Gets the total number of elements the internal data structure.
          /// @return Int32 The number of elements that the Collection<T> can contain.
          int32 GetCapacity() const {return this->list.GetCapacity();}

          /// @brief Returns an enumerator that iterates through the Collection<T>.
          /// @return Int32 A Collection<T>::Enumerator for the Collection<T>.
          Generic::Enumerator<T> GetEnumerator() const override {return this->list.GetEnumerator();}

          /// @brief Determines the index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @return Int32 The index of value if found in the Collection; otherwise, -1.
          virtual int32 IndexOf(const T& value) const override {return IndexOf(value, 0, this->Count);}

          /// @brief Determines the index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @param index The zero-based starting index of the search.
          /// @return Int32 The index of value if found in the Collection; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0.
          virtual int32 IndexOf(const T& value, int32 index) const {return IndexOf(value, index, this->Count - index);}

          /// @brief Determines the index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @param index The zero-based starting index of the search.
          /// @param count The number of elements in the section to search
          /// @return Int32 The index of value if found in the Collection; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0 or The parameters count is less than 0 or index and count do not specify a valid section in the Collection<T>.
          virtual int32 IndexOf(const T& value, int32 index, int32 count) const {return this->list.IndexOf(value, index, count);}

          /// @brief Determines the last index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @return Int32 The last index of value if found in the Collection; otherwise, -1.
          int32 LastIndexOf(const T& value) const {return this->list.LastIndexOf(value);}

          /// @brief Determines the last index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @param index The zero-based starting index of the search.
          /// @return Int32 The last index of value if found in the Collection; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0.
          int32 LastIndexOf(const T& value, int32 index) const {return this->list.LastIndexOf(value, index);}

          /// @brief Determines the last index of a specific item in the Collection.
          /// @param value The object to locate in the Collection.
          /// @param index The zero-based starting index of the search.
          /// @param count The number of elements in the section to search
          /// @return Int32 The last index of value if found in the Collection; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0 or The parameters count is less than 0 or index and count do not specify a valid section in the Collection<T>.
          int32 LastIndexOf(const T& value, int32 index, int32 count) const {return this->list.LastIndexOf(value, index, count);}

          /// @brief Gets the element at the specified index.
          /// @param index The zero-based index of the element to get.
          /// @return T The element at the specified index.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
          const T& operator[](int32 index) const override {return this->list[index];}

          /// @brief Gets the element at the specified index.
          /// @param index The zero-based index of the element to get.
          /// @return  T The element at the specified index.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
          T& operator[](int32 index) override {throw NotSupportedException("Collection is read-only.", caller_);}

          /// @brief Clear the Collection and insert the element of the Collection given in argument.
          /// @param collection the Collection which elements will be inserted from
          /// @return Collection<T> the Collection
          ReadOnlyCollection<T>& operator=(const ReadOnlyCollection<T>& collection) {throw NotSupportedException("Collection is read-only.", caller_);}

        protected:
          /// @cond
          System::Collections::Generic::List<T, TAllocator> list;
          /// @endcond

        private:
          int32 GetCount() const override {return this->list.Count;}
          bool GetIsFixedSize() const override {return true;}
          bool GetIsReadOnly() const override {return true;}
          bool GetIsSynchronized() const override {return false;}
          const Object& GetSyncRoot() const override {return this->list.SyncRoot;}
          void Add(const T&) override {throw NotSupportedException("Collection is read-only.", caller_);}
          void Clear() override {throw NotSupportedException("Collection is read-only.", caller_);}
          void Insert(int32, const T&) override {throw NotSupportedException("Collection is read-only.", caller_);}
          bool Remove(const T&) override {throw NotSupportedException("Collection is read-only.", caller_);}
          void RemoveAt(int32 index) override {throw NotSupportedException("Collection is read-only.", caller_);}
        };
      }
    }
  }
}

using namespace Switch;
