/// @file
/// @brief Contains Switch::System::Collections::Queue class.
#pragma once

#include "../../Any.hpp"
#include "ArrayList.hpp"
#include "ICollection.hpp"
#include "IEnumerable.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Represents a first-in, first-out collection of objects.
      class Queue : public Object, public System::Linq::Extension::Enumerable<Queue, any>, public ICollection {
      public:
        /// @brief Initializes a new instance of the Queue<T> class that is empty and has the default initial capacity.
        Queue() {}

        /// @brief Initializes a new instance of the System::Collections::Generic::Queue<T> class
        /// that contains elements copied from the specified collection and has sufficient
        /// capacity to accommodate the number of elements copied.
        /// @param collection The collection whose elements are copied to the new System::Collections::Generic::Queue<T>.
        /// @exception System::ArgumentNullException collection is null.
        Queue(const IEnumerable& collection) {
          for (const any& item : collection)
            Enqueue(item);
        }

        /// @brief Initializes a new instance of the System::Collections::Generic::Queue<T> class
        /// that is empty and has the specified initial capacity.
        /// @param capacity The initial number of elements that the System::Collections::Generic::Queue<T>
        ///                 can contain.
        /// @exception System::ArgumentOutOfRangeException capacity is less than zero.
        Queue(int32 capacity) : queue(capacity) {}

        /// @brief Default copy constructor
        /// @param queue the Queue<T> which elements will be inserted from
        Queue(const Queue& queue) : queue(queue.queue) {}

        /// @cond
        Queue(InitializerList<any> il) {
          for (const any& item : il)
            this->Enqueue(item);
        }

        Queue(Queue&& queue) : queue(Move(queue.queue)) {}
        /// @endcond

        /// @brief Removes all elements from the Queue<T>.
        void Clear() override {this->queue.Clear();}

        /// @brief Determines whether an element is in the System::Collections::Generic::Queue<T>.
        /// @param item The object to locate in the System::Collections::Generic::Queue<T>. The value
        ///             can be null for reference types.
        /// @return true if item is found in the System::Collections::Generic::Queue<T>; otherwise,
        ///         false.
        virtual bool Contains(const any& value) const override {return this->queue.Contains(value);}

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
        virtual void CopyTo(System::Array<any>& array, int32 arrayIndex) const override {this->queue.CopyTo(array);}

        /// @brief Removes and returns the object at the beginning of the System::Collections::Generic::Queue<T>.
        /// @return The object that is removed from the beginning of the System::Collections::Generic::Queue<T>.
        /// @exception System::InvalidOperationException The System::Collections::Generic::Queue<T> is empty.
        any Dequeue() {
          any copy = Peek();
          this->queue.RemoveAt(0);
          return copy;
        }

        /// @brief Adds an object to the end of the System::Collections::Generic::Queue<T>.
        /// @param item The object to add to the System::Collections::Generic::Queue<T>. The value can be null for reference types.
        void Enqueue(const any& value) {this->queue.Add(value);}

        /// @brief Returns an enumerator that iterates through the System::Collections::Generic::Queue<T>.
        /// @return An System::Collections::Generic::Queue<T>.Enumerator for the System::Collections::Generic::Queue<T>.
        Enumerator GetEnumerator() const override {return this->queue.GetEnumerator();}

        /// @brief Returns the object at the beginning of the System::Collections::Generic::Queue<T>
        /// without removing it.
        /// @return The object at the beginning of the System::Collections::Generic::Queue<T>.
        /// @exception System::InvalidOperationException The System::Collections::Generic::Queue<T> is empty.
        const any& Peek() const {
          if (this->queue.Count == 0)
            throw InvalidOperationException(caller_);
          return this->queue[0];
        }

        any& Peek() {
          if (this->queue.Count == 0)
            throw InvalidOperationException(caller_);
          return this->queue[0];
        }

        /// @brief Copies the System::Collections::Generic::Queue<T> elements to a new array.
        /// @return A new array containing elements copied from the System::Collections::Generic::Queue<T>.
        Array<any> ToArray() const {return this->queue.ToArray();}

        /// @brief Sets the capacity to the actual number of elements in the System::Collections::Generic::Queue<T>,
        /// if that number is less than 90 percent of current capacity.
        void TrimExcess() {this->queue.TrimExcess();}

        /// @brief Copies the elements in queue to the current queue (they are equal after this operation).
        /// @return a reference to the current queue.
        Queue& operator=(const Queue& queue) {this->queue = queue.queue; return *this;;}

        /// @cond
        using const_iterator = typename ArrayList::const_iterator;
        using iterator = typename ArrayList::iterator;

        const_iterator cbegin() const {return this->queue.begin();}
        const_iterator cend() const {return this->queue.end();}
        iterator begin() {return this->queue.begin();}
        const_iterator begin() const {return this->queue.begin();}
        iterator end() {return this->queue.end();}
        const_iterator end() const {return this->queue.end();}
        /// @endcond

      protected:
        /// @cond
        ArrayList queue;
        /// @endcond

      private:
        int32 GetCount() const override {return this->queue.Count;}
        bool GetIsReadOnly() const override {return false;}
        bool GetIsSynchronized() const override {return this->queue.IsSynchronized;}
        const object& GetSyncRoot() const override {return this->queue.SyncRoot;}

        void Add(const any&) override { }
        bool Remove(const any&) override { return false; }
      };
    }
  }
}

using namespace Switch;
