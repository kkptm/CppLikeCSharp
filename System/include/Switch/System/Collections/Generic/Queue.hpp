/// @file
/// @brief Contains Switch::System::Collections::Generic::Queue <T> class.
#pragma once

#include <list>

#include <Switch/Allocator.hpp>
#include <Switch/Types.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Type.hpp>
#include <Switch/System/Collections/Generic/GenericException.hpp>
#include <Switch/System/Collections/Generic/ICollection.hpp>
#include <Switch/System/Collections/Generic/IEnumerable.hpp>
#include <Switch/System/Collections/Generic/IEnumerator.hpp>
#include <Switch/System/Linq/Enumerable.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @brief Represents a first-in, first-out collection of objects.
        /// @remarks This class implements a generic queue as a circular array. Objects stored in a Queue<T> are inserted at one end and removed from the other. Queues and stacks are useful when you need temporary storage for information; that is, when you might want to discard an element after retrieving its value. Use Queue<T> if you need to access the information in the same order that it is stored in the collection. Use Stack<T> if you need to access the information in reverse order. Use ConcurrentQueue<T> or ConcurrentStack<T> if you need to access the collection from multiple threads concurrently.
        /// @remarks Three main operations can be performed on a Queue<T> and its elements:
        /// * Enqueue adds an element to the end of the Queue<T>.
        /// * Dequeue removes the oldest element from the start of the Queue<T>.
        /// * Peek peek returns the oldest element that is at the start of the Queue<T> but does not remove it from the Queue<T>.
        /// @remarks The capacity of a Queue<T> is the number of elements the Queue<T> can hold. As elements are added to a Queue<T>, the capacity is automatically increased as required by reallocating the internal array. The capacity can be decreased by calling TrimExcess.
        /// @remarks Queue<T> accepts null as a valid value for reference types and allows duplicate elements.
        /// @par Library
        /// Switch.System
        template<typename T, typename TAllocator = Allocator<T>>
        class Queue : public Object, public System::Linq::Extension::Enumerable<Queue<T, TAllocator>, T>, public ICollection<T> {
          using Item = T;
        public:
          /// @brief Initializes a new instance of the Queue<T> class that is empty and has the default initial capacity.
          Queue() : capacity(0), operationNumber(0) {}

          /// @brief Initializes a new instance of the System::Collections::Generic::Queue<T> class
          /// that contains elements copied from the specified collection and has sufficient
          /// capacity to accommodate the number of elements copied.
          /// @param collection The collection whose elements are copied to the new System::Collections::Generic::Queue<T>.
          /// @exception System::ArgumentNullException collection is null.
          Queue(const IEnumerable<T>& collection) : capacity(0), operationNumber(0) {
            for (const T& item : collection)
              Enqueue(item);
          }

          /// @brief Initializes a new instance of the System::Collections::Generic::Queue<T> class
          /// that is empty and has the specified initial capacity.
          /// @param capacity The initial number of elements that the System::Collections::Generic::Queue<T>
          ///                 can contain.
          /// @exception System::ArgumentOutOfRangeException capacity is less than zero.
          Queue(int32 capacity) : capacity(capacity), operationNumber(0) {}

          /// @brief Default copy constructor
          /// @param queue the Queue<T> which elements will be inserted from
          Queue(const Queue& queue) : queue(queue.queue), capacity(queue.capacity), operationNumber(queue.operationNumber) {}

          /// @cond
          Queue(InitializerList<T> il) : operationNumber(0) {
            for (const T& item : il)
              this->Enqueue(item);
          }

          Queue(Queue&& queue) : queue(Move(queue.queue)), capacity(queue.capacity), operationNumber(queue.operationNumber) {
            queue.capacity = 0;
            queue.operationNumber = 0;
          }
          /// @endcond

          /// @brief Removes all elements from the Queue<T>.
          void Clear() override {
            this->operationNumber++;
            this->queue.clear();
          }

          /// @brief Determines whether an element is in the System::Collections::Generic::Queue<T>.
          /// @param item The object to locate in the System::Collections::Generic::Queue<T>. The value
          ///             can be null for reference types.
          /// @return true if item is found in the System::Collections::Generic::Queue<T>; otherwise,
          ///         false.
          virtual bool Contains(const T& value) const override {
            typename std::list<T, TAllocator>::const_iterator it;
            for (it = this->queue.begin(); it != this->queue.end() ; it++)
              if (*it == value) return true;
            return false;
          }

          /// @brief Copies the System::Collections::Generic::Queue<T> elements to an existing one-dimensional
          /// System::Array, starting at the specified array index.
          /// @param array The one-dimensional System::Array that is the destination of the elements
          ///              copied from System::Collections::Generic::Queue<T>. The System::Array must have
          ///              zero-based indexing.
          /// @param arrayIndex The zero-based index in array at which copying begins.
          /// @exception System::ArgumentNullException array is null.
          /// @exception System::ArgumentOutOfRangeException arrayIndex is less than zero.
          /// @exception System::ArgumentException The number of elements in the source System::Collections::Generic::Queue<T>
          ///            is greater than the available space from arrayIndex to the end of the destination
          ///            array.
          virtual void CopyTo(System::Array<T>& array, int32 arrayIndex) const override {
            //_list.CopyTo(array, arrayIndex);
            if (arrayIndex < 0) throw ArgumentOutOfRangeException(caller_);
            if (arrayIndex + this->Count > array.Length) throw ArgumentException(caller_);

            typename std::list<T, TAllocator>::const_iterator it;
            for (it = this->queue.begin(); it != this->queue.end() ; it++)
              array[arrayIndex++] = *it;
          }

          /// @brief Removes and returns the object at the beginning of the System::Collections::Generic::Queue<T>.
          /// @return The object that is removed from the beginning of the System::Collections::Generic::Queue<T>.
          /// @exception System::InvalidOperationException The System::Collections::Generic::Queue<T> is empty.
          T Dequeue() {
            T copy = Peek();
            this->queue.pop_front();
            this->operationNumber++;
            return copy;
          }

          /// @brief Adds an object to the end of the System::Collections::Generic::Queue<T>.
          /// @param item The object to add to the System::Collections::Generic::Queue<T>. The value can be null for reference types.
          void Enqueue(const T& value) {
            this->queue.push_back(value);
            this->operationNumber++;
            if (this->capacity < static_cast<int32>(this->queue.size())) this->capacity = static_cast<int32>(this->queue.size());
          }

          /// @brief Returns an enumerator that iterates through the System::Collections::Generic::Queue<T>.
          /// @return An System::Collections::Generic::Queue<T>.Enumerator for the System::Collections::Generic::Queue<T>.
          System::Collections::Generic::Enumerator<T> GetEnumerator() const override {
            return System::Collections::Generic::Enumerator<T>(new Queue::Enumerator(*const_cast<Queue*>(this)));
          }

          /// @brief Returns the object at the beginning of the System::Collections::Generic::Queue<T>
          /// without removing it.
          /// @return The object at the beginning of the System::Collections::Generic::Queue<T>.
          /// @exception System::InvalidOperationException The System::Collections::Generic::Queue<T> is empty.
          const T& Peek() const {
            if (this->queue.size() == 0)
              throw InvalidOperationException(caller_);

            return this->queue.front();
          }

          T& Peek() {
            if (this->queue.size() == 0)
              throw InvalidOperationException(caller_);

            return this->queue.front();
          }

          /// @brief Copies the System::Collections::Generic::Queue<T> elements to a new array.
          /// @return A new array containing elements copied from the System::Collections::Generic::Queue<T>.
          Array<T> ToArray() const {
            Array<T> array(this->Count);
            typename std::list<T, TAllocator>::const_iterator it;
            int32 index = 0;
            for (it = this->queue.begin(); it != this->queue.end() ; it++)
              array[index++] = *it;

            return array;
          }

          /// @brief Sets the capacity to the actual number of elements in the System::Collections::Generic::Queue<T>,
          /// if that number is less than 90 percent of current capacity.
          void TrimExcess() {
            // capacity is not supported by STL
          }

          /// @brief Copies the elements in queue to the current queue (they are equal after this operation).
          /// @return a reference to the current queue.
          Queue& operator=(const Queue& queue) {
            this->operationNumber++;
            this->queue.clear();
            typename std::list<T, TAllocator>::const_iterator it;
            for (it = queue._list.begin(); it != queue._list.end() ; it++)
              this->queue.push_back(*it);
            return *this;
          }

          /// @cond
          using const_iterator = typename std::list<T, TAllocator>::const_iterator;
          using iterator = typename std::list<T, TAllocator>::iterator;

          const_iterator cbegin() const {return this->queue.begin();}
          const_iterator cend() const {return this->queue.end();}
          iterator begin() {return this->queue.begin();}
          const_iterator begin() const {return this->queue.begin();}
          iterator end() {return this->queue.end();}
          const_iterator end() const {return this->queue.end();}
          /// @endcond

        protected:
          /// @cond
          std::list<T, TAllocator> queue;
          int32 capacity;
          int32 operationNumber;
          Object syncRoot;
          /// @endcond

        private:
          int32 GetCount() const override {return static_cast<int32>(this->queue.size());}
          bool GetIsReadOnly() const override {return false;}
          bool GetIsSynchronized() const override {return false;}
          const Object& GetSyncRoot() const override {return this->syncRoot;}

          class Enumerator : public Object, public IEnumerator<T> {
          public:
            Enumerator(Queue& queue) : queue(queue) {Reset();}

            void Reset() {
              this->beforeFirst = true;
              this->operationNumber = this->queue.operationNumber;
              this->iterator = this->queue.queue.begin();
            }

            virtual bool MoveNext() {
              if (this->operationNumber != this->queue.operationNumber)
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

            bool IsFinished() const {return this->iterator == this->queue.queue.end();}
            int64 operationNumber;
            bool beforeFirst;
            Queue& queue;
            typename std::list<T, TAllocator>::iterator iterator;
          };

          void Add(const T&) override {}
          bool Remove(const T&) override {return false;}
        };
      }
    }
  }
}

using namespace Switch;
