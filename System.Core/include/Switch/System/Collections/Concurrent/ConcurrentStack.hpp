/// @file
/// @brief Contains Switch::System::Collections::Concurrent::ConcurrentStack class.
#pragma once

#include "../../../Lock.hpp"
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
        /// @brief Represents a thread-safe last in-first out (LIFO) collection.
        /// @par Library
        /// Switch.Core
        /// @par Examples
        /// The following example shows how to use a ConcurrentStack<T> to push and pop individual items:
        /// @include ConcurrentStack.cpp
        template<typename T, typename TAllocator = Allocator<T>>
        class ConcurrentStack : public Object, public IProducerConsumerCollection<T> {
        public:
          /// @brief Initializes a new instance of the ConcurrentStack<T> class.
          ConcurrentStack() {}

          ConcurrentStack(const ConcurrentStack& concurrentStack) : stack(concurrentStack.stack) {}

          /// @cond
          ConcurrentStack(ConcurrentStack&& concurrentStack) : stack(Move(concurrentStack.stack)) {}
          /// @endcond

          /// @brief Initializes a new instance of the ConcurrentStack<T> class that contains elements copied from the specified collection.
          /// @param collection The collection whose elements are copied to the new ConcurrentStack<T>.
          /// @exception ArgumentNullException collection is a null reference.
          ConcurrentStack(const Generic::IEnumerable<T>& collection) {
            lock_(this->stack.SyncRoot) {
              for (T item : collection)
                this->stack.Insert(0, item);
            }
          }

          /// @cond
          ConcurrentStack(InitializerList<T> il)  {
            lock_(this->stack.SyncRoot) {
              for (T item : il)
                this->stack.Insert(0, item);
            }
          }
          /// @endcond

          /// @brief Gets a value that indicates whether the ConcurrentStack<T> is empty.
          /// @return Boolean true if the ConcurrentStack<T> is empty; otherwise, false.
          property_<bool, readonly_> IsEmpty {
            get_ {
              return this->stack.Count == 0;
            }
          };

          /// @brief Inserts multiple objects at the top of the ConcurrentStack<T> atomically.
          /// @param item The object to be inserted to the ConcurrentStack<T>.
          void Push(const T& item) {
            lock_(this->stack.SyncRoot)
            this->stack.Insert(0, item);
          }

          /// @brief Inserts multiple objects at the top of the ConcurrentStack<T> atomically.
          /// @param items The objects to push onto the ConcurrentStack<T>.
          /// @exception ArgumentNullException items is a null.
          void PushRange(const System::Array<T>& items) {PushRange(items, 0, items.Length);}

          /// @brief Inserts multiple objects at the top of the ConcurrentStack<T> atomically.
          /// @param items The objects to push onto the ConcurrentStack<T>.
          /// @param startIndex The zero-based offset in items at which to begin inserting elements onto the top of the ConcurrentStack<T>.
          /// @param count The number of elements to be inserted onto the top of the ConcurrentStack<T>.
          /// @exception ArgumentNullException items is a null.
          /// @exception ArgumentOutOfRangeException startIndex or count is negative. Or startIndex is greater than or equal to the length of items.
          /// @exception ArgumentException startIndex + count is greater than the length of items.
          void PushRange(const System::Array<T>& items, int32 startIndex, int32 count) {
            if (startIndex < 0 || count < 0 || startIndex > items.Length)
              throw ArgumentOutOfRangeException(caller_);

            if (startIndex + count > items.Length)
              throw ArgumentException(caller_);

            lock_(this->stack.SyncRoot) {
              for (int32 i = startIndex; i < startIndex + count; i++)
                this->stack.Insert(0, items[i]);
            }
          }

          /// @brief Removes all objects from the ConcurrentStack<T>.
          void Clear() override {
            lock_(this->stack.SyncRoot)
            this->stack.Clear();
          }

          /// @brief Copies the elements of the IProducerConsumerCollection<T> to an Array, starting at a specified index.
          /// @param array TThe one-dimensional Array that is the destination of the elements copied from the IProducerConsumerCollection<T>. The array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins;
          void CopyTo(System::Array<T>& array, int32 index) const override {
            lock_(this->stack.SyncRoot)
            this->stack.CopyTo(array, index);
          }

          /// @brief Copies the elements contained in the IProducerConsumerCollection<T> to a new array.
          /// @return A new array containing the elements copied from the IProducerConsumerCollection<T>.
          System::Array<T> ToArray() const override {
            lock_(this->stack.SyncRoot)
            return this->stack.ToArray();
            return this->stack.ToArray();
          }

          /// @brief Returns an enumerator that iterates through the ConcurrentStack<T>.
          /// @return Int32 A List<T>::Enumerator for the List<T>.
          Generic::Enumerator<T> GetEnumerator() const override {
            lock_(this->stack.SyncRoot)
            return Generic::Enumerator<T>(new Enumerator(this));
            return Generic::Enumerator<T>(new Enumerator(this));
          }

          /// @brief Attempts to return an object from the ConcurrentStack<T> without removing it.
          /// @param result When this method returns, result contains an object from the ConcurrentStack<T> or the default value of T if the operation failed.
          /// @return true if and object was returned successfully; otherwise, false.
          bool TryPeek(T& result) {
            lock_(this->stack.SyncRoot) {
              if (this->stack.Count > 0) {
                result = this->stack[0];
                return true;
              }
            }
            return false;
          }

          /// @brief Attempts to pop and return the object at the top of the ConcurrentStack<T>.
          /// @param result When this method returns, if the object was removed and returned successfully, item contains the removed object. If no object was available to be removed, the value is unspecified.
          /// @return true if an object was removed and returned successfully; otherwise, false.
          bool TryPop(T& result) {
            lock_(this->stack.SyncRoot) {
              if (this->stack.Count > 0) {
                result = this->stack[0];
                this->stack.RemoveAt(0);
                return true;
              }
            }
            return false;
          }

          /// @brief Attempts to pop and return multiple objects from the top of the ConcurrentStack<T> atomically.
          /// @param results The Array to which objects popped from the top of the ConcurrentStack<T> will be added.
          /// @return Int32 The number of objects successfully popped from the top of the stack and inserted in items.
          /// @exception ArgumentNullException items is a null.
          int32 TryPopRange(System::Array<T>& results) {return TryPopRange(results, 0, results.Length);}

          /// @brief Attempts to pop and return multiple objects from the top of the ConcurrentStack<T> atomically.
          /// @param items The Array to which objects popped from the top of the ConcurrentStack<T> will be added.
          /// @param startIndex he zero-based offset in items at which to begin inserting elements from the top of the ConcurrentStack<T>.
          /// @param count The number of elements to be popped from top of the ConcurrentStack<T> and inserted into items.
          /// @return Int32 The number of objects successfully popped from the top of the stack and inserted in items.
          /// @exception ArgumentNullException items is a null.
          /// @exception ArgumentOutOfRangeException startIndex or count is negative. Or startIndex is greater than or equal to the length of items.
          /// @exception ArgumentException startIndex + count is greater than the length of items.
          int32 TryPopRange(System::Array<T>& results, int32 startIndex, int32 count) {
            if (startIndex < 0 || count < 0 || startIndex > results.Length)
              throw ArgumentOutOfRangeException(caller_);

            if (startIndex + count > results.Length)
              throw ArgumentException(caller_);

            int32 nbItemPoped = 0;
            lock_(this->stack.SyncRoot) {
              for (int32 i = startIndex; i < startIndex + count; i++) {
                if (this->stack.Count == 0)
                  break;

                results[i] = this->stack[0];
                this->stack.RemoveAt(0);
                nbItemPoped++;
              }
            }
            return nbItemPoped;
          }

        private:
          int32 GetCount() const override {return this->stack.Count;}

          bool GetIsReadOnly() const override {return false;}

          bool GetIsSynchronized() const override {return true;}

          const object& GetSyncRoot() const override {return this->stack.SyncRoot;}

          void Add(const T& item) override {Push(item);}

          bool Contains(const T& value) const override {
            lock_(this->stack.SyncRoot)
            return this->stack.Contains(value);
            return this->stack.Contains(value);
          }

          bool Remove(const T& value) override {return false;}

          bool TryAdd(const T& item) override {
            Push(item);
            return true;
          }

          bool TryTake(T& result) override {return TryPop(result);}

          class Enumerator : public Object, public Generic::IEnumerator<T> {
          public:
            Enumerator(const ConcurrentStack* cs) : array(cs->stack.ToArray()) {}
            void Reset() {this->index = -1;}
            virtual bool MoveNext() {return ++this->index < this->array.Length;}

          protected:
            const T& GetCurrent() const {
              if (this->index < 0 || this->index >= this->array.Length)
                throw InvalidOperationException(caller_);
              return this->array[this->index];
            }

            int32 index = -1;
            System::Array<T> array;
          };

          Generic::List<T, TAllocator> stack;
        };
      }
    }
  }
}
