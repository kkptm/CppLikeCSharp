/// @file
/// @brief Contains Switch::System::Collections::Concurrent::ConcurrentBag class.
#pragma once

#include <Switch/Lock.hpp>
#include <Switch/Property.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Collections/Concurrent/IProducerConsumerCollection.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Concurrent namespace provides several thread-safe collection classes that should be used in place of the corresponding types in the System::Collections and System::Collections::Generic namespaces whenever multiple threads are accessing the collection concurrently.
      namespace Concurrent {
        /// @brief Represents a thread-safe, unordered collection of objects.
        /// @remarks Bags are useful for storing objects when ordering doesn't matter, and unlike sets, bags support duplicates. ConcurrentBag<T> is a thread-safe bag implementation, optimized for scenarios where the same thread will be both producing and consuming data stored in the bag.
        /// @par Library
        /// Switch.System
        /// @par Examples
        /// The following example shows how to add and remove items from a ConcurrentBag<T>:
        /// @include ConcurrentBag.cpp
        template<typename T, typename TAllocator = Allocator<T>>
        class ConcurrentBag : public Object, public IProducerConsumerCollection<T> {
        public:
          /// @brief Initializes a new instance of the ConcurrentBag<T> class.
          ConcurrentBag() {}

          ConcurrentBag(const ConcurrentBag& concurrentBag) : list(concurrentBag.list) {}

          /// @cond
          ConcurrentBag(ConcurrentBag&& concurrentBag) : list(Move(concurrentBag.list)) {}
          /// @endcond

          /// @brief Initializes a new instance of the ConcurrentBag<T> class that contains elements copied from the specified collection.
          /// @param collection The collection whose elements are copied to the new ConcurrentBag<T>.
          /// @exception ArgumentNullException collection is a null reference.
          ConcurrentBag(const Generic::IEnumerable<T>& collection) {
            lock_(this->list.SyncRoot) {
              for (T item : collection)
                this->list.Add(item);
            }
          }

          /// @cond
          ConcurrentBag(InitializerList<T> il)  {
            lock_(this->list.SyncRoot) {
              for (T item : il)
                this->list.Add(item);
            }
          }
          /// @endcond

          /// @brief Gets a value that indicates whether the ConcurrentBag<T> is empty.
          /// @return Boolean true if the ConcurrentBag<T> is empty; otherwise, false.
          property_<bool, readonly_> IsEmpty {
            get_ {
              return this->list.Count == 0;
            }
          };

          /// @brief Adds an object to the ConcurrentBag<T>.
          /// @param item The object to be added to the ConcurrentBag<T>.
          void Add(const T& item) override {
            lock_(this->list.SyncRoot)
            this->list.Add(item);
          }

          /// @brief Copies the elements of the IProducerConsumerCollection<T> to an Array, starting at a specified index.
          /// @param array TThe one-dimensional Array that is the destination of the elements copied from the IProducerConsumerCollection<T>. The array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins;
          void CopyTo(System::Array<T>& array, int32 index) const override {
            if (index + this->list.Count > array.Length)
              throw ArgumentOutOfRangeException(caller_);

            lock_(this->list.SyncRoot) {
              for (T item : this->list)
                array[index++] = item;
            }
          }

          /// @brief Copies the elements contained in the IProducerConsumerCollection<T> to a new array.
          /// @return A new array containing the elements copied from the IProducerConsumerCollection<T>.
          System::Array<T> ToArray() const override {
            lock_(this->list.SyncRoot)
            return this->list.ToArray();
            return this->list.ToArray();
          }

          /// @brief Returns an enumerator that iterates through the ConcurrentBag<T>.
          /// @return Int32 A List<T>::Enumerator for the List<T>.
          Generic::Enumerator<T> GetEnumerator() const override {
            lock_(this->list.SyncRoot)
            return Generic::Enumerator<T>(new Enumerator(this));
            return Generic::Enumerator<T>(new Enumerator(this));
          }

          /// @brief Attempts to add an object to the IProducerConsumerCollection<T>.
          /// @param item The object to add to the IProducerConsumerCollection<T>.
          /// @return true if the object was added successfully; otherwise, false.
          /// @exception ArgumentException The item was invalid for this collection.
          bool TryAdd(const T& item) override {
            lock_(this->list.SyncRoot) {
              try {
                this->list.Add(item);
                return true;
              } catch (...) {
                return false;
              }
            }
            return false;
          }

          /// @brief Attempts to return an object from the ConcurrentBag<T> without removing it.
          /// @param result When this method returns, result contains an object from the ConcurrentBag<T> or the default value of T if the operation failed.
          /// @return true if and object was returned successfully; otherwise, false.
          bool TryPeek(T& result) {
            lock_(this->list.SyncRoot) {
              if (this->list.Count > 0) {
                result = this->list[this->Count - 1];
                return true;
              }
            }
            return false;
          }

          /// @brief Attempts to remove and return an object from the IProducerConsumerCollection<T>.
          /// @param result When this method returns, if the object was removed and returned successfully, item contains the removed object. If no object was available to be removed, the value is unspecified.
          /// @return true if an object was removed and returned successfully; otherwise, false.
          bool TryTake(T& result) override {
            lock_(this->list.SyncRoot) {
              if (this->list.Count > 0) {
                result = this->list[this->Count - 1];
                this->list.RemoveAt(this->Count - 1);
                return true;
              }
            }
            return false;
          }

        private:
          int32 GetCount() const override {return this->list.Count;}

          bool GetIsReadOnly() const override {return false;}

          bool GetIsSynchronized() const override { return true; }

          const object& GetSyncRoot() const override {return this->list.SyncRoot;}

          void Clear() override {
            lock_(this->list.SyncRoot)
            this->list.Clear();
          }

          bool Contains(const T& value) const override {
            lock_(this->list.SyncRoot)
            return this->list.Contains(value);
            return this->list.Contains(value);
          }

          bool Remove(const T& value) override {
            lock_(this->list.SyncRoot)
            return this->list.Remove(value);
            return this->list.Remove(value);
          }

          class Enumerator : public object, public Generic::IEnumerator<T> {
          public:
            Enumerator(const ConcurrentBag* bag) : array(bag->list.ToArray()) {}
            void Reset() { this->index = -1; }
            virtual bool MoveNext() { return ++this->index < this->array.Length; }

          protected:
            const T& GetCurrent() const {
              if (this->index < 0 || this->index >= this->array.Length)
                throw InvalidOperationException(caller_);
              return this->array[this->index];
            }

            int32 index = -1;
            System::Array<T> array;
          };

          Generic::List<T, TAllocator> list;
        };
      }
    }
  }
}
