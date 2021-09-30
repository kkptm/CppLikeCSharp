/// @file
/// @brief Contains Switch::System::Collections::Generic::HashSet <T> class.
#pragma once

#include <unordered_set>

#include <Switch/InitializerList.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include <Switch/System/Collections/Generic/ISet.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @brief Represents a set of values.
        /// @remarks The HashSet<T> class provides high-performance set operations. A set is a collection that contains no duplicate elements, and whose elements are in no particular order.
        /// @remarks The capacity of a HashSet<T> object is the number of elements that the object can hold. A HashSet<T> object's capacity automatically increases as elements are added to the object.
        /// @remarks For very large HashSet<T> objects, you can increase the maximum capacity to 2 billion elements on a 64-bit system by setting the enabled attribute of the gcAllowVeryLargeObjects configuration element to true in the run-time environment.
        /// @par Library
        /// Switch.System.Core
        /// @par Examples
        /// The following example demonstrates how to merge two disparate sets. This example creates two HashSet<T> objects, and populates them with even and odd numbers, respectively. A third HashSet<T> object is created from the set that contains the even numbers. The example then calls the UnionWith method, which adds the odd number set to the third set.
        /// @include HashSet.cpp
        template<typename T, typename TAllocator = Allocator<T>>
        class HashSet : public Object, public System::Linq::Extension::Enumerable<HashSet<T, TAllocator>, T>, public ISet<T> {
          using Item = T;
        public:
          /// @brief Initializes a new instance of the HashSet<T> class that is empty and uses the default equality comparer for the set type.
          HashSet() : operationNumber(0), comparer(new System::Collections::Generic::EmptyComparer<T>()) {}

          /// @brief Initializes a new instance of the HashSet<T> class that uses a specified comparer
          /// @param comparer an instance of IComparer<T> used to determine the sort order of the set.
          HashSet(const refptr< IComparer<T>>& comparer) : comparer(comparer) {}

          /// @cond
          HashSet(InitializerList<T> il) : operationNumber(0), comparer(new System::Collections::Generic::EmptyComparer<T>()) {
            for (typename InitializerList<Item>::const_iterator iterator = il.begin(); iterator != il.end(); ++iterator)
              this->Add(*iterator);
          }

          HashSet(const HashSet& s) : operationNumber(s.operationNumber), comparer(s.comparer) {
            for (const T& item : s)
              Add(item);
          }

          HashSet(HashSet&& s) : hashset(Move(s.hashset)), operationNumber(s.operationNumber), comparer(Move(s.comparer)) {s.operationNumber = 0;}

          HashSet& operator=(const HashSet& s) {
            this->operationNumber = s.operationNumber;
            this->comparer = s.comparer;
            for (T elem : s)
              Add(elem);
            return *this;
          }
          /// @endcond

          /// @brief Initializes a new instance of the HashSet<T> class that uses the default equality comparer for the set type, contains elements copied from the specified collection, and has sufficient capacity to accommodate the number of elements copied.
          /// @param collection The elements to copy
          HashSet(const IEnumerable<T>& collection) : operationNumber(0), comparer(new System::Collections::Generic::EmptyComparer<T>()) {
            for (const T& item : collection)
              Add(item);
          }

          /// @brief Initializes a new instance of the HashSet<T> class that contains elements copied from a specified enumerable collection and that uses a specified comparer.
          /// @param collection The elements to copy
          /// @param comparer an instance of IComparer<T> used to determine the sort order of the set.
          HashSet(const IEnumerable<T>& collection, const refptr<IComparer<T>>& comparer) : operationNumber(0), comparer(comparer) {
            for (T item : collection)
              Add(item);
          }

          /// @brief Initializes a new instance of the HashSet and copy array[] T.
          /// @param array the Array to copy.
          /// @remarks The HashSet class is ! thread safe.
          template<int32 len>
          HashSet(const T(&array)[len]) : operationNumber(0), comparer(new System::Collections::Generic::EmptyComparer<T>()) {
            for (int32 index = 0; index < len; index++)
              this->Add(array[index]);
          }

          /// @brief Adds an element to the set and returns a value that indicates if it was successfully added. If the element is already prensent, the value is ! replaced.
          /// @param item The emement to add.
          /// @return Boolean true if the element is added to the set; false if the element is already in the set.
          bool Add(const T& item) override {
            return this->hashset.insert(item).second;
          }

          /// @brief Removes all elements from the set.
          void Clear() override {
            this->hashset.clear();
          }

          /// @brief Determines whether the set contains a specific element.
          /// @param item The element to test.
          /// @return Boolean true if the set contains the element, false otherwise.
          bool Contains(const T& item) const override {
            return this->hashset.find(item) != this->hashset.end();
          }

          /// @brief Returns an enumerator that iterates through the HashSet<T>.
          /// @return An enumerator that iterates through the HashSet<T> in sorted order.
          System::Collections::Generic::Enumerator<T> GetEnumerator() const override {
            return System::Collections::Generic::Enumerator<T>(new HashSet::Enumerator(*const_cast<HashSet*>(this)));
          }

          /// @brief Copies the complete HashSet<T> to a compatible one-dimensional array, starting at the beginning of the target array.
          /// @param array A one-dimensional array that is the destination of the elements copied from the HashSet<T>.
          /// @exception ArgumentException The number of elements in the source HashSet<T> exceeds the number of elements that the destination array can contain.
          /// @exception ArgumentNullException array is null.
          void CopyTo(Array<T>& array) const {
            CopyTo(0, array, 0, this->Count);
          }

          /// @brief Copies the complete HashSet<T> to a compatible one-dimensional array, starting at the specified array index.
          /// @param array A one-dimensional array that is the destination of the elements copied from the HashSet<T>. The array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins.
          /// @exception ArgumentException The number of elements in the source array is greater than the available space from index to the end of the destination array.
          /// @exception ArgumentNullException array is null.
          /// @exception ArgumentOutOfRangeException index is less than zero.
          void CopyTo(Array<T>& array, int32 index) const override {
            CopyTo(0, array, index, this->Count);
          }

          /// @brief Copies a specified number of elements from HashSet<T> to a compatible one-dimensional array, starting at the specified array index
          /// @param array A one-dimensional array that is the destination of the elements copied from the HashSet<T>. The array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins.
          /// @param count The number of elements to copy.
          /// @exception ArgumentException The number of elements in the source (count) array is greater than the available space from index to the end of the destination array.
          /// @exception ArgumentNullException array is null.
          /// @exception ArgumentOutOfRangeException index is less than zero or count is less than zero.
          void CopyTo(Int32 index, Array<T>& array, int32 arrayIndex, int32 count) const {
            if (index < 0 || array.Length < 0 || arrayIndex < 0 || count < 0)
              throw ArgumentOutOfRangeException(caller_);

            if (index + count > this->Count || arrayIndex + count > array.Length)
              throw ArgumentException(caller_);

            int32 i = 0, c = 0;
            for (T item : *this) {
              if (i >= index + count)
                return;
              if (i >= index) {
                array[arrayIndex + c] = item;
                c += 1;
              }
              i += 1;
            }
          }

          /// @brief Removes all elements that are in a specified collection from the current HashSet<T> object.
          /// @param other The collection of items to remove from the HashSet<T> object.
          /// @exception ArgumentNullException other is null.
          void ExceptWith(const IEnumerable<T>& other) override {
            if (&other == this) {
              Clear();
              return;
            }

            for (T item : other)
              Remove(item);
          }

          /// @brief Returns a view of a subset in a HashSet<T>.
          /// @param lowerValue The lowest desired value in the view.
          /// @param upperValue The highest desired value in the view.
          /// @return A subset view that contains only the values in the specified range.
          /// @exception ArgumentNullException lowerValue or upperValue is null.
          HashSet GetViewBetween(const T& lowerValue, const T& upperValue) const {
            HashSet set(this->comparer);

            for (T item : *this) {
              if (this->comparer->Compare(item, lowerValue) >= 0 && this->comparer->Compare(item, upperValue) <= 0)
                set.Add(item);
            }
            return set;
          }

          /// @brief Modifies the current HashSet<T> object so that it contains only elements that are also in a specified collection.
          /// @param other The collection to compare to the current HashSet<T> object.
          /// @exception ArgumentNullException other is null.
          void IntersectWith(const IEnumerable<T>& other) override {
            HashSet toKeep(other);
            HashSet toRemove;

            for (T item : *this)
              if (! toKeep.Contains(item))
                toRemove.Add(item);

            ExceptWith(toRemove);
          }

          /// @brief Determines whether a HashSet<T> object is a proper subset of the specified collection.
          /// @param other The collection to compare to the current HashSet<T> object.
          /// @return true if the current set is a proper subset of other.
          /// @exception ArgumentNullException other is null.
          bool IsProperSubsetOf(const IEnumerable<T>& other) const override {
            HashSet set(other);
            if (this->Count == 0)
              return set.Count > 0;

            if (this->Count >= set.Count)
              return false;

            return this->SubSet(set);
          }

          /// @brief Determines whether a HashSet<T> object is a proper superset of the specified collection.
          /// @param other The collection to compare to the current HashSet<T> object.
          /// @return true if the current set is a proper superset of other.
          /// @exception ArgumentNullException other is null.
          bool IsProperSupersetOf(const IEnumerable<T>& other) const override {
            HashSet set(other);

            if (set.Count == 0)
              return this->Count > 0;

            if (set.Count >= this->Count)
              return false;

            return this->SuperSet(set);
          }

          /// @brief Determines whether a HashSet<T> object is a subset of the specified collection.
          /// @param other The collection to compare to the current HashSet<T> object.
          /// @return true if the current set is a subset of other.
          /// @exception ArgumentNullException other is null.
          bool IsSubsetOf(const IEnumerable<T>& other) const override {
            HashSet set(other);
            return this->SubSet(set);
          }

          /// @brief Determines whether a HashSet<T> object is a superset of the specified collection.
          /// @param other The collection to compare to the current HashSet<T> object.
          /// @return true if the current set is a superset of other.
          /// @exception ArgumentNullException other is null.
          bool IsSupersetOf(const IEnumerable<T>& other) const override {
            HashSet set(other);
            return this->SuperSet(set);
          }

          /// @brief Determines whether the current HashSet<T> object and a specified collection share common elements.
          /// @param other The collection to compare to the current HashSet<T> object.
          /// @return true if the HashSet<T> object and other share at least one common element; otherwise, false.
          /// @exception ArgumentNullException other is null.
          bool Overlaps(const IEnumerable<T>& other) const override {
            if (this->Count == 0)
              return false;

            for (T item : other)
              if (Contains(item))
                return true;

            return false;
          }

          /// @brief Removes a specified item from the HashSet<T>.
          /// @param item The element to remove.
          /// @return true if the element was removed, false otherwise.
          /// @exception ArgumentNullException item is null.
          bool Remove(const T& item) override {
            return this->hashset.erase(item) == 1;
          }

          /// @brief Removes all elements that match the conditions defined by the specified predicate from a HashSet<T> collection.
          /// @param match The Predicate<T> delegate that defines the conditions of the elements to remove.
          /// @return Int32 The number of elements that were removed from the HashSet<T> collection.
          /// @exception ArgumentNullException match is null
          int32 RemoveWhere(const Predicate<const T&>& match) {
            int32 nbRemoved = 0;
            for (T elem : *this)
              if (match(elem) && Remove(elem))
                nbRemoved++;

            return nbRemoved;
          }

          /// @brief Determines whether the current HashSet<T> object and the specified collection contain the same elements.
          /// @param other The collection to compare to the current HashSet<T>
          /// @return true if the two sets are equivalent.
          bool SetEquals(const IEnumerable<T>& other) const override {
            HashSet set(other);

            if (this->Count != set.Count)
              return false;

            for (T item : other)
              if (! Contains(item))
                return false;

            return true;
          }

          /// @brief Modifies the current HashSet<T> object so that it contains only elements that are present
          /// either in the current object or in the specified collection, but ! both. Any duplicate
          /// in the provided collection (other) are ignored.
          /// @param other The collection to compare to the current HashSet<T> object.
          /// @exception ArgumentNullException other is null.
          void SymmetricExceptWith(const IEnumerable<T>& other) override {
            for (T item : other) {
              if (Contains(item))
                Remove(item);
              else
                Add(item);
            }
          }

          /// @brief Modifies the current HashSet<T> object so that it contains all elements that are present in either the current object or the specified collection.
          /// @param other The collection to compare to the current HashSet<T> object.
          /// @exception ArgumentNullException other is null.
          void UnionWith(const IEnumerable<T>& other) override {
            for (T item : other)
              if (! Contains(item))
                this->hashset.insert(item); // avoid a second test
          }

        private:
          template<typename THasher>
          class Hasher {
          public:
            size_t operator()(const THasher& value) const { return Switch::GetHashCode(value); }
          };

          template<typename TEqual>
          class EqualTo {
          public:
            constexpr bool operator()(const TEqual& a, const TEqual& b) const {return a == b; }
          };

          int32 GetCount() const override {return static_cast<int32>(this->hashset.size());}
          bool GetIsReadOnly() const override {return false;}

          bool SubSet(const HashSet& set) const {
            if (this->Count == 0)
              return true;

            if (this->Count > set.Count)
              return false;

            for (T item : *this)
              if (! set.Contains(item))
                return false;

            return true;
          }

          bool SuperSet(const HashSet& set) const {
            if (set.Count == 0)
              return true;

            if (set.Count > this->Count)
              return false;

            for (T item : set)
              if (! Contains(item))
                return false;

            return true;
          }

          std::unordered_set<T, Hasher<T>, EqualTo<T>, TAllocator> hashset;
          int64 operationNumber;
          refptr< IComparer<T>> comparer;

        public:
          /// @cond
          using const_iterator = typename std::unordered_set<T, Hasher<T>, EqualTo<T>, TAllocator>::const_iterator;
          using iterator = typename std::unordered_set<T, Hasher<T>, EqualTo<T>, TAllocator>::iterator;
          /// @endcond

          class Enumerator : public object, public IEnumerator<T> {
          public:
            Enumerator(HashSet& set) : set(set) {Reset();}
            Enumerator(const Enumerator& other) : operationNumber(other.operationNumber), beforeFirst(other.beforeFirst), set(other.set), iterator(other.iterator) {}

            void Reset() {
              this->beforeFirst = true;
              this->operationNumber = this->set.operationNumber;
              this->iterator = this->set.hashset.begin();
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

          protected:
            const T& GetCurrent() const {
              if (this->beforeFirst || IsFinished())
                throw InvalidOperationException(caller_);

              return *this->iterator;
            }

            bool IsFinished() const {return this->iterator == this->set.hashset.end();}
            int64 operationNumber;
            bool beforeFirst;
            HashSet& set;
            typename std::unordered_set<T, Hasher<T>, EqualTo<T>, TAllocator>::iterator iterator;
          };

          class ReverseEnumerator : public object, public IEnumerator<T> {
          public:
            ReverseEnumerator(HashSet<T>& set) : set(set) {Reset();}
            ReverseEnumerator(const ReverseEnumerator& other) : operationNumber(other.operationNumber), beforeFirst(other.beforeFirst), set(other.set), iterator(other.iterator) {}

            void Reset() {
              this->beforeFirst = true;
              this->operationNumber = this->set.operationNumber;
              this->iterator = this->set.hashset.rbegin();
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

            bool IsFinished() const {return this->iterator == this->set._hashse.rend();}
            int64 operationNumber;
            bool beforeFirst;
            HashSet& set;
            typename std::unordered_set<T, Hasher<T>, EqualTo<T>, TAllocator>::reverse_iterator iterator;
          };
        };
      }
    }
  }
}

using namespace Switch;
