/// @file
/// @brief Contains Switch::System::Collections::Stack class.
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
      /// @brief Represents a simple last-in-first-out (LIFO) non-generic collection of objects.
      class Stack : public object, public System::Linq::Extension::Enumerable<Stack, any>, public ICollection {
      public:
        /// @brief Initializes a new instance of the Stack<T> class that is empty and has the default initial capacity.
        Stack() {}

        /// @brief Initializes a new instance of the Stack<T> class that contains elements copied from the specified collection and has sufficient capacity to accommodate the number of elements copied.
        /// @param collection The collection whose elements are copied to the new Stack.
        /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
        Stack(const IEnumerable& collection) {
          for (any item : collection)
            Push(item);
        }
        /// @brief Initializes a new instance of the Stack<T> class that is empty and has the specified initial capacity.
        /// @param capacity The number of elements that the new Stack can initially store.
        /// @exception ArgumentException The parameters capacity is less than 0.
        Stack(Int32 capacity) : stack(capacity) { }

        /// @brief Default copy constructor
        /// @param stack the Stack<T> which elements will be inserted from
        Stack(const Stack& stack) : stack(stack.stack) {}

        /// @cond
        Stack(InitializerList<any> il) {
          for (const any& item : il)
            this->Push(item);
        }

        Stack(Stack&& stack) : stack(Move(stack.stack)) {}
        /// @endcond

        /// @brief Destroy instance of the class Stack<T>.
        ~Stack() {}

        /// @brief Removes all elements from the Stack<T>.
        void Clear() override {this->stack.Clear();}

        /// @brief Determines whether an element is in the Stack<T>.
        /// @param value The object to be added to the end of the Stack<T>. The value can not be null for reference types.
        virtual bool Contains(const any& value) const override {return this->stack.Contains(value);}

        /// @brief Copies the entire Stack<T> to a compatible Nhu-dimensional array.
        /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
        /// @return Int32 Number of elements copied.
        /// @exception ArgumentNullException The parameters array is null.
        /// @exception ArgumentException arrayIndex is equal to or greater than the length of array.
        /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the Stack<T>.
        void CopyTo(System::Array<any>& array) const {this->stack.CopyTo(array);}

        /// @brief Copies the entire Stack<T> to a compatible one-dimensional array, starting at the specified index of the target array.
        /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
        /// @param arrayIndex The zero-based index in array at which copying begins;
        /// @return Int32 Number of elements copied.
        /// @exception ArgumentNullException The parameters array is null.
        /// @exception ArgumentException arrayIndex is equal to or greater than the length of array -or-
        /// The number of elements in the source Stack<T> is greater than the available space from arrayIndex to the end of the destination array.
        /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the Stack<T>.
        virtual void CopyTo(System::Array<any>& array, int32 arrayIndex) const override {this->stack.CopyTo(array, arrayIndex);}

        /// @brief Copies the entire Stack<T> to a compatible one-dimensional array, starting at the specified index of the target array.
        /// @param index The zero-based index in the source List<T> at which copying begins.
        /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
        /// @param arrayIndex The zero-based index in array at which copying begins;
        /// @param count The number of elements to copy.
        /// @return Int32 Number of elements copied.
        /// @exception ArgumentNullException The parameters array is null.
        /// @exception ArgumentOutOfRangeException The arrayIndex is less than 0.
        /// @exception ArgumentException index is equal to or greater than the Count of the source Stack<T>. -or-
        /// arrayIndex is equal to or greater than the length of array -or-
        /// The number of elements in the source List<T> is greater than the available space from arrayIndex to the end of the destination array.
        /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the Stack<T>.
        void CopyTo(int32 index, Array<any>& array, int32 arrayIndex, int32 count) const {this->stack.CopyTo(index, array, arrayIndex, count);}

        /// @brief Removes and returns the object at the top of the Stack<T>.
        /// @return refptr<T> The object removed
        /// @exception InvalidOperationException The Stack<T> is Empty.
        any Pop() {
          any value = Peek();
          this->stack.RemoveAt(0);
          return value;
        }

        /// @brief AInserts an object at the top of the Stack<T>.
        /// @param value The object to be added to the end of the Stack<T>. The value can not be null for reference types.
        /// @remarks Stack<T> allows duplicate elements.
        void Push(const any& value) {this->stack.Insert(0, value);}

        /// @brief Returns an enumerator that iterates through the Stack<T>.
        /// @return Int32 A Stack<T>::Enumerator for the Stack<T>.
        Enumerator GetEnumerator() const override {return this->stack.GetEnumerator();}

        /// @brief Returns the object at the top of the Stack<T> without removing it.
        /// @return refptr<T> The object to peek from the Stack<T>. The value can not be null.
        /// @exception InvalidOperationException The Stack<T> is Empty.
        any Peek() {
          if (this->stack.Count == 0)
            throw InvalidOperationException(caller_);
          return this->stack[0];
        }

        /// @brief Copies the Stack<T> elements to a new array.
        /// @return Array<T>*> The new Array<T> copied.
        Array<any> ToArray() const {
          return this->stack.ToArray();
        }

        /// @brief Copies the Stack<T> elements to a new array.
        /// @return Array<T>*> The new Array<T> copied.
        void TrimExcess() { this->stack.TrimExcess(); }

        /// @brief Sets the capacity to the actual number of elements in the Stack<T>, if that number is less than 90 percent of current capacity.
        /// @remarks This function is not yet implemented so an Exception NotSupportedException is always generate.
        Stack& operator=(const Stack& stack) {this->stack = stack.stack; return *this;}

        /// @cond
        using const_iterator = typename ArrayList::const_iterator;
        using iterator = typename ArrayList::iterator;

        const_iterator cbegin() const {return this->stack.begin();}
        const_iterator cend() const {return this->stack.end();}
        iterator begin() {return this->stack.begin();}
        const_iterator begin() const {return this->stack.begin();}
        iterator end() {return this->stack.end();}
        const_iterator end() const {return this->stack.end();}
        /// @endcond

      protected:
        /// @cond
        ArrayList stack;
        /// @endcond
      private:
        int32 GetCount() const override {return this->stack.Count;}
        bool GetIsReadOnly() const override {return false;}
        bool GetIsSynchronized() const override {return this->stack.IsSynchronized;}
        const object& GetSyncRoot() const override {return this->stack.SyncRoot;}

        void Add(const any&) override { }
        bool Remove(const any&) override { return false; }
      };
    }
  }
}

using namespace Switch;
