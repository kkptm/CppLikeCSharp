/// @file
/// @brief Contains Switch::System::Collections::Concurrent::ConcurrentQueue class.
#pragma once

#include "../../../Lock.hpp"
#include "../../../Property.hpp"
#include "../Generic/List.hpp"
#include "IProducerConsumerCollection.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Concurrent namespace provides several thread-safe collection classes that should be used in place of the corresponding types in the System::Collections and System::Collections::Generic namespaces whenever multiple threads are accessing the collection concurrently.
      namespace Concurrent {
        /// @brief Represents a thread-safe first in-first out (FIFO) collection.
        /// @par Library
        /// Switch.Core
        /// @par Examples
        /// The following example shows how to use a ConcurrentQueue<T> to enqueue and dequeue items:
        /// @include ConcurrentQueue.cpp
        template<typename T, typename TAllocator = Allocator<T>>
        class ConcurrentQueue : public Object, public IProducerConsumerCollection<T> {
        public:
          /// @brief Initializes a new instance of the ConcurrentQueue<T> class.
          ConcurrentQueue() {}

          ConcurrentQueue(const ConcurrentQueue& concurrentQueue) : queue(concurrentQueue.queue) {}

          /// @cond
          ConcurrentQueue(ConcurrentQueue&& concurrentQueue) : queue(Move(concurrentQueue.queue)) {}
          /// @endcond

          /// @brief Initializes a new instance of the ConcurrentQueue<T> class that contains elements copied from the specified collection.
          /// @param collection The collection whose elements are copied to the new ConcurrentQueue<T>.
          /// @exception ArgumentNullException collection is a null reference.
          ConcurrentQueue(const Generic::IEnumerable<T>& collection) {
            lock_(this->queue.SyncRoot) {
              for (T item : collection)
                this->queue.Add(item);
            }
          }

          /// @cond
          ConcurrentQueue(InitializerList<T> il)  {
            lock_(this->queue.SyncRoot) {
              for (T item : il)
                this->queue.Add(item);
            }
          }
          /// @endcond

          /// @brief Gets a value that indicates whether the ConcurrentQueue<T> is empty.
          /// @return Boolean true if the ConcurrentQueue<T> is empty; otherwise, false.
          property_<bool, readonly_> IsEmpty {
            get_ {
              return this->queue.Count == 0;
            }
          };

          /// @brief Enqueue an object to the ConcurrentQueue<T>.
          /// @param item The object to be Enqueued to the ConcurrentQueue<T>.
          void Enqueue(const T& item) {
            lock_(this->queue.SyncRoot)
            this->queue.Add(item);
          }

          /// @brief Removes all objects from the ConcurrentQueue<T>.
          void Clear() override {
            lock_(this->queue.SyncRoot)
            this->queue.Clear();
          }

          /// @brief Copies the elements of the IProducerConsumerCollection<T> to an Array, starting at a specified index.
          /// @param array TThe one-dimensional Array that is the destination of the elements copied from the IProducerConsumerCollection<T>. The array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins;
          void CopyTo(System::Array<T>& array, int32 index) const override {
            if (index + this->queue.Count > array.Length)
              throw System::ArgumentOutOfRangeException(caller_);

            lock_(this->queue.SyncRoot) {
              System::Int32 pos = index;
              for (T item : this->queue)
                array[pos++] = item;
            }
          }

          /// @brief Copies the elements contained in the IProducerConsumerCollection<T> to a new array.
          /// @return A new array containing the elements copied from the IProducerConsumerCollection<T>.
          System::Array<T> ToArray() const override {
            lock_(this->queue.SyncRoot)
            return this->queue.ToArray();
            return this->queue.ToArray();
          }

          /// @brief Returns an enumerator that iterates through the ConcurrentQueue<T>.
          /// @return Int32 A List<T>::Enumerator for the List<T>.
          /// @remarks The enumeration represents a moment-in-time snapshot of the contents of the queue. It does not reflect any updates to the collection after GetEnumerator was called. The enumerator is safe to use concurrently with reads from and writes to the queue.
          /// @remarks The enumerator returns the collection elements in the order in which they were added, which is FIFO order (first-in, first-out).
          Generic::Enumerator<T> GetEnumerator() const override {
            lock_(this->queue.SyncRoot)
            return Generic::Enumerator<T>(new Enumerator(this));
            return Generic::Enumerator<T>(new Enumerator(this));
          }

          /// @brief Attempts to return an object from the ConcurrentQueue<T> without removing it.
          /// @param result When this method returns, result contains an object from the ConcurrentQueue<T> or the default value of T if the operation failed.
          /// @return true if and object was returned successfully; otherwise, false.
          bool TryPeek(T& result) {
            lock_(this->queue.SyncRoot) {
              if (this->queue.Count > 0) {
                result = this->queue[0];
                return true;
              }
            }
            return false;
          }

          /// @brief Attempts to remove and return an object from the IProducerConsumerCollection<T>.
          /// @param result When this method returns, if the object was removed and returned successfully, item contains the removed object. If no object was available to be removed, the value is unspecified.
          /// @return true if an object was removed and returned successfully; otherwise, false.
          bool TryDequeue(T& result) {
            lock_(this->queue.SyncRoot) {
              if (this->queue.Count > 0) {
                result = this->queue[0];
                this->queue.RemoveAt(0);
                return true;
              }
            }
            return false;
          }

        private:
          int32 GetCount() const override {return this->queue.Count;}

          bool GetIsReadOnly() const override {return false;}

          bool GetIsSynchronized() const override {return true;}

          const object& GetSyncRoot() const override {return this->queue.SyncRoot;}

          void Add(const T& item) override {Enqueue(item);}

          bool Contains(const T& value) const override {
            lock_(this->queue.SyncRoot)
            return this->queue.Contains(value);
            return false;
          }

          bool Remove(const T& value) override {return false;}

          bool TryAdd(const T& item) override {
            Enqueue(item);
            return true;
          }

          bool TryTake(T& result) override {return TryDequeue(result);}

          class Enumerator : public Object, public Generic::IEnumerator<T> {
          public:
            Enumerator(const ConcurrentQueue* concurrentQueue) : array(concurrentQueue->queue.ToArray()) {}
            void Reset() {this->index = -1;}
            virtual bool MoveNext() {return ++this->index < this->array.Length;}

          protected:
            const T& GetCurrent() const {
              if (this->index < 0 || this->index >= this->array.Length)
                throw InvalidOperationException(caller_);

              return this->array[this->index];
            }

            int32 index = -1;
            System::Array<T, 1, TAllocator> array;
          };

          Generic::List<T, TAllocator> queue;
        };
      }
    }
  }
}
