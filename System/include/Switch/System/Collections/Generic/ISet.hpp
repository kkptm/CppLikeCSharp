/// @file
/// @brief Contains Switch::System::Collections::Generic::ISet <T> interface.
#pragma once

#include <Switch/Types.hpp>
#include <Switch/System/Collections/Generic/IEnumerable.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @interface ISet
        /// @brief Provides the base interface for the abstraction of sets.
        /// @par Library
        /// Switch.System
        template<typename T>
        class ISet : public IEnumerable<T> {
        public:
          /// @cond
          ISet() {}
          /// @endcond

          /// @brief Gets the number of elements contained in the ISet.
          /// @return Int32 The number of elements contained in the ICollection.
          property_<int32, readonly_> Count {
            get_ {return this->GetCount();}
          };

          /// @brief Gets a value indicating whether the ISet is read-only.
          /// @return Boolean true if the ISet is read-only; otherwise; otherwise, false.
          property_<bool, readonly_> IsReadOnly {
            get_ {return this->GetIsReadOnly();}
          };

          /// @brief Adds an element to the current set and returns a value to indicate if the element was successfully added.
          /// @param item The emement to add.
          /// @return Boolean true if the element is added to the set; false if the element is already in the set.
          virtual bool Add(const T& item) = 0;

          /// @brief Removes all elements from the set.
          virtual void Clear() = 0;

          /// @brief Determines whether the set contains a specific element.
          /// @param item The element to test.
          /// @return true if the set contains the element, false otherwise.
          virtual bool Contains(const T& item) const = 0;

          /// @brief Copies the complete SortedSet<T> to a compatible one-dimensional array, starting at the specified array index.
          /// @param array A one-dimensional array that is the destination of the elements copied from the SortedSet<T>. The array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins.
          /// @exception ArgumentException  The number of elements in the source array is greater than the available space from index to the end of the destination array.
          /// @exception ArgumentNullException  array is null.
          /// @exception ArgumentOutOfRangeException  index is less than zero.
          virtual void CopyTo(Array<T>& array, int32 index) const = 0;

          /// @brief Removes all elements that are in a specified collection from the current SortedSet<T> object.
          /// @param other The collection of items to remove from the SortedSet<T> object.
          /// @exception ArgumentNullException  other is null.
          virtual void ExceptWith(const IEnumerable<T>& other) = 0;

          /// @brief Modifies the current SortedSet<T> object so that it contains only elements that are also in a specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @exception ArgumentNullException  other is null.
          virtual void IntersectWith(const IEnumerable<T>& other) = 0;

          /// @brief Determines whether a SortedSet<T> object is a proper subset of the specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @return true if the current set is a proper subset of other.
          /// @exception ArgumentNullException other is null.
          virtual bool IsProperSubsetOf(const IEnumerable<T>& other) const = 0;

          /// @brief Determines whether a SortedSet<T> object is a proper superset of the specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @return true if the current set is a proper superset of other.
          /// @exception ArgumentNullException  other is null.
          virtual bool IsProperSupersetOf(const IEnumerable<T>& other) const = 0;

          /// @brief Determines whether a SortedSet<T> object is a subset of the specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @return true if the current set is a subset of other.
          /// @exception ArgumentNullException other is null.
          virtual bool IsSubsetOf(const IEnumerable<T>& other) const = 0;

          /// @brief Determines whether a SortedSet<T> object is a superset of the specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @return true if the current set is a superset of other.
          /// @exception ArgumentNullException  other is null.
          virtual bool IsSupersetOf(const IEnumerable<T>& other) const = 0;

          /// @brief Determines whether the current SortedSet<T> object and a specified collection share common elements.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @return true if the SortedSet<T> object and other share at least one common element; otherwise, false.
          /// @exception ArgumentNullException  other is null.
          virtual bool Overlaps(const IEnumerable<T>& other) const = 0;

          /// @brief Removes a specified item from the SortedSet<T>.
          /// @param item The element to remove.
          /// @return true if the element was removed, false otherwise.
          /// @exception ArgumentNullException item is null.
          virtual bool Remove(const T& item) = 0;

          /// @brief Determines whether the current SortedSet<T> object and the specified collection contain the same elements.
          /// @param other The collection to compare to the current SortedSet<T>
          /// @return true if the two sets are equivalent.
          virtual bool SetEquals(const IEnumerable<T>& other) const = 0;

          /// @brief Modifies the current SortedSet<T> object so that it contains only elements that are present either in the current object or in the specified collection, but not both. Any duplicate in the provided collection (other) are ignored.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @exception ArgumentNullException  other is null.
          virtual void SymmetricExceptWith(const IEnumerable<T>& other) = 0;

          /// @brief Modifies the current SortedSet<T> object so that it contains all elements that are present in either the current object or the specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @exception ArgumentNullException other is null.
          virtual void UnionWith(const IEnumerable<T>& other) = 0;

        protected:
          /// @brief Gets the number of elements contained in the ISet.
          /// @return Int32 The number of elements contained in the ICollection.
          virtual int32 GetCount() const = 0;

          /// @brief Gets a value indicating whether the ISet is read-only.
          /// @return Boolean true if the ISet is read-only; otherwise; otherwise, false.
          virtual bool GetIsReadOnly() const = 0;
        };
      }
    }
  }
}

using namespace Switch;
