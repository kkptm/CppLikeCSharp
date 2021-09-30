/// @file
/// @brief Contains Switch::System::Collections::Generic::IList <T> class.
#pragma once

#include "ICollection.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @interface IList
        /// @brief Represents a non-generic collection of objects that can be individually accessed by index.
        template<typename T>
        class IList : public ICollection<T> {
        public:
          /// @cond
          IList() {}
          /// @endcond

          /// @brief Gets a value indicating whether the IList has a fixed size.
          /// @return Boolean true if the IList has a fixed size; otherwise, false.
          property_<bool, readonly_> IsFixedSize {
            get_ {return this->GetIsFixedSize();}
          };

          /// @brief Determines the index of a specific item in the IList.
          /// @param value The object to locate in the IList.
          /// @return Int32 The index of value if found in the list; otherwise, -1.
          virtual int32 IndexOf(const T& value) const = 0;

          /// @brief Inserts an item to the IList at the specified index.
          /// @param index The zero-based index at which value should be inserted
          /// @param value The object to insert into the IList.
          virtual void Insert(int32 index, const T& value) = 0;

          /// @brief Removes the IList item at the specified index.
          /// @param index The zero-based index of the item to remove
          virtual void RemoveAt(int32 index) = 0;

          /// @brief Gets the element at the specified index.
          /// @param index The zero-based index of the element to get.
          /// @return T The element at the specified index.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
          virtual const T& operator[](int32 index) const = 0;

          /// @brief Gets the element at the specified index.
          /// @param index The zero-based index of the element to get.
          /// @return T The element at the specified index.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
          virtual T& operator[](int32 index) = 0;

        protected:
          /// @brief Gets a value indicating whether the IList has a fixed size.
          /// @return Boolean true if the IList has a fixed size; otherwise, false.
          virtual bool GetIsFixedSize() const = 0;
        };
      }
    }
  }
}

using namespace Switch;
