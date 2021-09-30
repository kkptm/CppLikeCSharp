/// @file
/// @brief Contains Switch::System::Collections::Generic::SortedSet <T> class.
#pragma once

#include <set>

#include <Switch/Allocator.hpp>
#include <Switch/InitializerList.hpp>
#include <Switch/Types.hpp>
#include <Switch/RefPtr.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/Predicate.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Type.hpp>
#include <Switch/System/Collections/Generic/Comparer.hpp>
#include <Switch/System/Collections/Generic/GenericException.hpp>
#include <Switch/System/Collections/Generic/IEnumerable.hpp>
#include <Switch/System/Collections/Generic/IEnumerator.hpp>
#include <Switch/System/Linq/Enumerable.hpp>
#include "ISet.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @brief Represents a collection of objects that is maintained in sorted order.
        /// @remarks A SortedSet<T> object maintains a sorted order without affecting performance as elements are inserted and deleted. Duplicate elements are ! allowed. Changing the sort values of existing items is ! supported and may lead to unexpected behavior.
        /// @par Library
        /// Switch.System
        /// @par Examples
        /// The following example demonstrates how to merge two disparate sets. This example creates two SortedSet<T> objects, and populates them with even and odd numbers, respectively. A third SortedSet<T> object is created from the set that contains the even numbers. The example then calls the UnionWith method, which adds the odd number set to the third set.
        /// @include SortedSet.cpp
        template<typename T, typename TAllocator = Allocator<T>>
        class SortedSet : public Object, public System::Linq::Extension::Enumerable<SortedSet<T, TAllocator>, T>, public ISet<T> {
          using Item = T;
        public:
          /// @brief Initializes a new instance of the SortedSet<T> class
          SortedSet() : comparer(new System::Collections::Generic::Comparer<T>()), set(new std::set<T, SetComparer, TAllocator>(SetComparer(this->comparer.ToPointer()))), operationNumber(0) {}

          /// @brief Initializes a new instance of the SortedSet<T> class that uses a specified comparer
          /// @param comparer an instance of IComparer<T> used to determine the sort order of the set.
          SortedSet(const refptr<IComparer<T>>& comparer) : comparer(comparer), set(new std::set<T, SetComparer, TAllocator>(SetComparer(this->comparer.ToPointer()))), operationNumber(0) {}

          /// @brief Initializes a new instance of the SortedSet<T> class that contains elements copied from a specified enumerable collection
          /// @param collection The elements to copy
          SortedSet(const IEnumerable<T>& collection) : comparer(new System::Collections::Generic::Comparer<T>()), set(new std::set<T, SetComparer, TAllocator>(SetComparer(this->comparer.ToPointer()))), operationNumber(0) {
            for (T item : collection)
              this->Add(item);
          }

          /// @brief Initializes a new instance of the SortedSet<T> class that contains elements copied from a specified enumerable collection and that uses a specified comparer.
          /// @param collection The elements to copy
          /// @param comparer an instance of IComparer<T> used to determine the sort order of the set.
          SortedSet(const IEnumerable<T>& collection, const refptr<IComparer<T>>& comparer) : comparer(comparer), set(new std::set<T, SetComparer, TAllocator>(SetComparer(this->comparer.ToPointer()))), operationNumber(0) {
            for (const T& item : collection)
              this->Add(item);
          }

          /// @brief Initializes a new instance of the SortedSet and copy array[] T.
          /// @param array the Array to copy.
          /// @remarks The SortedSet class is ! thread safe.
          template<int32 len>
          SortedSet(const T(&array)[len]) : comparer(new System::Collections::Generic::Comparer<T>()), set(new std::set<T, SetComparer, TAllocator>(SetComparer(this->comparer.ToPointer()))), operationNumber(0) {
            for (int32 index = 0; index < len; index++)
              this->Add(array[index]);
          }

          /// @cond
          SortedSet(InitializerList<T> il) : comparer(new System::Collections::Generic::Comparer<T>()), set(new std::set<T, SetComparer, TAllocator>(SetComparer(this->comparer.ToPointer()))), operationNumber(0) {
            for (typename InitializerList<Item>::const_iterator iterator = il.begin(); iterator != il.end(); ++iterator)
              this->Add(*iterator);
          }

          SortedSet(const SortedSet& s) : comparer(s.comparer), set(new std::set<T, SetComparer, TAllocator>(SetComparer(this->comparer.ToPointer()))), operationNumber(0) {*set = *s.set;}

          SortedSet(SortedSet&& s) : comparer(s.comparer), set(Move(s.set)), operationNumber(s.operationNumber) {s.operationNumber = 0; s.set = new std::set<T, SetComparer, TAllocator>(SetComparer(s.comparer.ToPointer()));}

          SortedSet& operator=(const SortedSet& s) {
            this->comparer = s.comparer;
            *this->set = *s.set;
            this->operationNumber++;
            return *this;
          }
          /// @endcond

          /// @brief Adds an element to the set and returns a value that indicates if it was successfully added. If the element is already prensent, the value is ! replaced.
          /// @param item The emement to add.
          /// @return Boolean true if the element is added to the set; false if the element is already in the set.
          bool Add(const T& item) override {
            this->operationNumber++;
            return this->set->insert(item).second;
          }

          /// @brief Removes all elements from the set.
          void Clear() override {
            this->operationNumber++;
            this->set->clear();
          }

          /// @brief Determines whether the set contains a specific element.
          /// @param item The element to test.
          /// @return Boolean true if the set contains the element, false otherwise.
          bool Contains(const T& item) const override {
            return this->set->find(item) != this->set->end();
          }

          /// @brief Copies the complete SortedSet<T> to a compatible one-dimensional array, starting at the beginning of the target array.
          /// @param array A one-dimensional array that is the destination of the elements copied from the SortedSet<T>.
          /// @exception ArgumentException  The number of elements in the source SortedSet<T> exceeds the number of elements that the destination array can contain.
          /// @exception ArgumentNullException  array is null.
          void CopyTo(Array<T>& array) const {
            this->CopyTo(0, array, 0, this->Count);
          }

          /// @brief Copies the complete SortedSet<T> to a compatible one-dimensional array, starting at the specified array index.
          /// @param array A one-dimensional array that is the destination of the elements copied from the SortedSet<T>. The array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins.
          /// @exception ArgumentException  The number of elements in the source array is greater than the available space from index to the end of the destination array.
          /// @exception ArgumentNullException  array is null.
          /// @exception ArgumentOutOfRangeException  index is less than zero.
          void CopyTo(Array<T>& array, int32 index) const override {
            this->CopyTo(0, array, index, this->Count);
          }

          /// @brief Copies a specified number of elements from SortedSet<T> to a compatible one-dimensional array, starting at the specified array index
          /// @param array A one-dimensional array that is the destination of the elements copied from the SortedSet<T>. The array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins.
          /// @param count The number of elements to copy.
          /// @exception ArgumentException  The number of elements in the source (count) array is greater than the available space from index to the end of the destination array.
          /// @exception ArgumentNullException  array is null.
          /// @exception ArgumentOutOfRangeException  index is less than zero or count is less than zero.
          void CopyTo(int32 index, Array<T>& array, int32 arrayIndex, int32 count) const {
            if (index < 0 || array.Length < 0 || arrayIndex < 0 || count < 0)
              throw ArgumentOutOfRangeException(caller_);

            if (index + count > this->Count || arrayIndex + count > array.Length)
              throw ArgumentException(caller_);

            int32 i = 0, c = 0;
            for (T item : *this) {
              if (i >= index + count) return;
              if (i >= index) {
                array[arrayIndex + c] = item;
                c += 1;
              }
              i += 1;
            }
          }

          /// @brief Removes all elements that are in a specified collection from the current SortedSet<T> object.
          /// @param other The collection of items to remove from the SortedSet<T> object.
          /// @exception ArgumentNullException  other is null.
          void ExceptWith(const IEnumerable<T>& other) override {
            this->operationNumber++;
            if (&other == this) {
              Clear();
              return;
            }
            for (T item : other)
              Remove(item);
          }

          /// @brief Returns a view of a subset in a SortedSet<T>.
          /// @param lowerValue The lowest desired value in the view.
          /// @param upperValue The highest desired value in the view.
          /// @return A subset view that contains only the values in the specified range.
          /// @exception ArgumentNullException lowerValue or upperValue is null.
          SortedSet GetViewBetween(const T& lowerValue, const T& upperValue) const {
            SortedSet set(this->comparer);
            for (T item : *this) {
              if (this->comparer->Compare(item, lowerValue) >= 0 && this->comparer->Compare(item, upperValue) <= 0)
                set.Add(item);
            }
            return set;
          }

          /// @brief Modifies the current SortedSet<T> object so that it contains only elements that are also in a specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @exception ArgumentNullException  other is null.
          void IntersectWith(const IEnumerable<T>& other) override {
            SortedSet toKeep(other);
            SortedSet toRemove;

            for (T item : *this)
              if (!toKeep.Contains(item))
                toRemove.Add(item);

            ExceptWith(toRemove); // performs operationNumber++;
          }

          /// @brief Determines whether a SortedSet<T> object is a proper subset of the specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @return true if the current set is a proper subset of other.
          /// @exception ArgumentNullException other is null.
          bool IsProperSubsetOf(const IEnumerable<T>& other) const  override {
            SortedSet set(other);
            if (this->Count == 0) return set.Count > 0;
            if (this->Count >= set.Count) return false;
            return this->SubSet(set);
          }

          /// @brief Determines whether a SortedSet<T> object is a proper superset of the specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @return true if the current set is a proper superset of other.
          /// @exception ArgumentNullException  other is null.
          bool IsProperSupersetOf(const IEnumerable<T>& other) const override {
            SortedSet set(other);
            if (set.Count == 0) return this->Count > 0;
            if (set.Count >= this->Count) return false;
            return this->SuperSet(set);
          }

          /// @brief Determines whether a SortedSet<T> object is a subset of the specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @return true if the current set is a subset of other.
          /// @exception ArgumentNullException other is null.
          bool IsSubsetOf(const IEnumerable<T>& other) const override {
            SortedSet set(other);
            return this->SubSet(set);
          }

          /// @brief Determines whether a SortedSet<T> object is a superset of the specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @return true if the current set is a superset of other.
          /// @exception ArgumentNullException  other is null.
          bool IsSupersetOf(const IEnumerable<T>& other) const override {
            SortedSet set(other);
            return this->SuperSet(set);
          }

          /// @brief Determines whether the current SortedSet<T> object and a specified collection share common elements.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @return true if the SortedSet<T> object and other share at least one common element; otherwise, false.
          /// @exception ArgumentNullException  other is null.
          bool Overlaps(const IEnumerable<T>& other) const override {
            if (this->Count == 0)
              return false;

            for (T item : other)
              if (Contains(item))
                return true;

            return false;
          }

          /// @brief Returns an enumerator that iterates through the SortedSet<T>.
          /// @return An enumerator that iterates through the SortedSet<T> in sorted order.
          System::Collections::Generic::Enumerator<T> GetEnumerator() const override {
            return System::Collections::Generic::Enumerator<T>(new SortedSet::Enumerator(*const_cast<SortedSet*>(this)));
          }

          /// @brief Removes a specified item from the SortedSet<T>.
          /// @param item The element to remove.
          /// @return true if the element was removed, false otherwise.
          /// @exception ArgumentNullException item is null.
          bool Remove(const T& item) override {
            typename std::set<T, SetComparer, TAllocator>::iterator it = this->set->find(item);

            // if item is ! found, do ! alter the set and return false
            if (it == this->set->end())
              return false;

            this->operationNumber++;
            this->set->erase(it);
            return true;
          }

          /// @brief Removes all elements that match the conditions defined by the specified predicate from a SortedSet<T> collection.
          /// @param match The Predicate<T> delegate that defines the conditions of the elements to remove.
          /// @return Int32 The number of elements that were removed from the SortedSet<T> collection.
          /// @exception ArgumentNullException match is null
          int32 RemoveWhere(const Predicate<const T&>& match) {
            int32 nbRemoved = 0;
            for (T elem : *this)
              if (match(elem) && Remove(elem))
                nbRemoved++;
            return nbRemoved;
          }

          /// @brief Determines whether the current SortedSet<T> object and the specified collection contain the same elements.
          /// @param other The collection to compare to the current SortedSet<T>
          /// @return true if the two sets are equivalent.
          bool SetEquals(const IEnumerable<T>& other) const override {
            SortedSet set(other);
            if (this->Count != set.Count)
              return false;

            for (T item : other)
              if (!Contains(item))
                return false;

            return true;
          }

          /// @brief Modifies the current SortedSet<T> object so that it contains only elements that are present either in the current object or in the specified collection, but ! both. Any duplicate in the provided collection (other) are ignored.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @exception ArgumentNullException  other is null.
          void SymmetricExceptWith(const IEnumerable<T>& other) override {
            for (T item : other) {
              if (Contains(item))
                Remove(item);
              else
                Add(item);
            }
          }

          /// @brief Modifies the current SortedSet<T> object so that it contains all elements that are present in either the current object or the specified collection.
          /// @param other The collection to compare to the current SortedSet<T> object.
          /// @exception ArgumentNullException other is null.
          void UnionWith(const IEnumerable<T>& other) override {
            for (T item : other)
              if (!Contains(item))
                this->set->insert(item); // avoid a second test
          }

        private:
          /// @cond
          int32 GetCount() const override {return static_cast<int>(this->set->size());}
          bool GetIsReadOnly() const override {return false;}

          class SetComparer : public std::binary_function<T, T, bool> {
          private:
            const IComparer<T>* comparer;

          public:
            SetComparer(const IComparer<T>* c) : comparer(c) { }
            SetComparer(const SetComparer& mc) { *this = mc; }
            ~SetComparer() { }

            SetComparer& operator=(const SetComparer& mc) { comparer = mc.comparer; return *this; }
            bool operator()(const T& e1, const T& e2) const { return comparer->Compare(e1, e2) < 0; }
          };

          bool SubSet(const SortedSet& set) const {
            if (this->Count == 0)
              return true;

            if (this->Count > set.Count)
              return false;

            for (T item : *this)
              if (! set.Contains(item))
                return false;

            return true;
          }

          bool SuperSet(const SortedSet& set) const {
            if (set.Count == 0)
              return true;

            if (set.Count > this->Count)
              return false;

            for (T item : set)
              if (! Contains(item))
                return false;

            return true;
          }

        public:
          class Enumerator : public object, public IEnumerator<T> {
          public:
            Enumerator(SortedSet& set) : set(set) {Reset();}
            Enumerator(const Enumerator& other) : operationNumber(other.operationNumber), beforeFirst(other.beforeFirst), set(other.set), iterator(other.iterator) {}

            void Reset() {
              this->beforeFirst = true;
              this->operationNumber = this->set.operationNumber;
              this->iterator = this->set.set->begin();
            }

            virtual bool MoveNext() {
              if (this->operationNumber != this->set.operationNumber)
                throw InvalidOperationException(caller_);

              if (IsFinished())
                return false;

              if (this->beforeFirst)
                this->beforeFirst = false;
              else
                this->iterator++;

              return !IsFinished();
            }

          protected:
            const T& GetCurrent() const {
              if (this->beforeFirst || IsFinished())
                throw InvalidOperationException(caller_);

              return *this->iterator;
            }

            bool IsFinished() const {return this->iterator == this->set.set->end();}
            int64 operationNumber;
            bool beforeFirst;
            SortedSet& set;
            typename std::set<T, SetComparer, TAllocator>::iterator iterator;
          };

          class ReverseEnumerator : public object, public IEnumerator<T> {
          public:
            ReverseEnumerator(SortedSet& set) : set(set) {Reset();}

            ReverseEnumerator(const ReverseEnumerator& other) : operationNumber(other.operationNumber), beforeFirst(other.beforeFirst), set(other.set), iterator(other.iterator) {}

            void Reset() {
              this->beforeFirst = true;
              this->operationNumber = this->set.operationNumber;
              this->iterator = this->set.set->rbegin();
            }

            virtual bool MoveNext() {
              if (this->operationNumber != this->set.operationNumber)
                throw InvalidOperationException(caller_);

              if (IsFinished())
                return false;

              if (this->beforeFirst)
                this->beforeFirst = false;
              else
                this->iterator++;

              return ! IsFinished();
            }

          private:
            const T& GetCurrent() const {
              if (this->beforeFirst || IsFinished())
                throw InvalidOperationException(caller_);

              return *this->iterator;
            }

            bool IsFinished() const {return this->iterator == this->set.set->rend();}
            int64 operationNumber;
            bool beforeFirst;
            SortedSet& set;
            typename std::set<T, SetComparer, TAllocator>::reverse_iterator iterator;
          };

          /// @cond
          using const_iterator = typename std::set<T, SetComparer, TAllocator>::const_iterator;
          using iterator = typename std::set<T, SetComparer, TAllocator>::iterator;

          const_iterator cbegin() const {return this->set->begin();}
          const_iterator cend() const {return this->set->end();}
          iterator begin() {return this->set->begin();}
          const_iterator begin() const {return this->set->begin();}
          iterator end() {return this->set->end();}
          const_iterator end() const {return this->set->end();}
          /// @endcond

        private:
          refptr<IComparer<T>> comparer;
          refptr<std::set<T, SetComparer, TAllocator>> set;
          int64 operationNumber;
          /// @endcond
        };
      }
    }
  }
}

using namespace Switch;
