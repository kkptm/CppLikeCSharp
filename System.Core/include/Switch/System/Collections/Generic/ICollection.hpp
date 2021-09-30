/// @file
/// @brief Contains Switch::System::Collections::Generic::ICollection <T> interface.
#pragma once

#include "../../../Allocator.hpp"
#include "../../../Interface.hpp"
#include "../../../Types.hpp"
#include "../../Object.hpp"
#include "IEnumerable.hpp"
#include "../../../Property.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @interface ICollection
        /// @brief Defines size, enumerators, and synchronization methods for all non-generic collections.
        template<typename T>
        class ICollection : public IEnumerable<T> {
        public:
          /// @cond
          ICollection() {}
          /// @endcond

          /// @brief Gets the number of elements contained in the ICollection.
          /// @return Int32 The number of elements contained in the ICollection.
          property_<int32, readonly_> Count {
            get_ {return this->GetCount();}
          };

          /// @brief Gets a value indicating whether the ICollection is read-only.
          /// @return Boolean true if the ICollection is read-only; otherwise; otherwise, false.
          property_<bool, readonly_> IsReadOnly {
            get_ {return this->GetIsReadOnly();}
          };

          /// @brief Gets a value indicating whether access to the ICollection is synchronized (thread safe).
          /// @return Boolean true if access to the ICollection is synchronized (thread safe); otherwise, false.
          property_<bool, readonly_> IsSynchronized {
            get_ {return this->GetIsSynchronized();}
          };

          /// @brief Gets an object that can be used to synchronize access to the ICollection.
          /// @return object An object that can be used to synchronize access to the ICollection.
          /// @remarks In the absence of a Synchronized method on a collection, the expected usage for SyncRoot looks as follows:
          /// @code
          /// refptr<ICollection> collection;
          /// // Instantiate and populate the collection
          /// lock_ (collection->SyncRoot) {
          ///   // Some operation on the collection, which is now thread safe.
          /// }
          /// @endcode
          property_<const Object&, readonly_> SyncRoot {
            get_->const object& {return this->GetSyncRoot();}
          };

          /// @brief Adds an item to the IList.
          /// @param value The pointer object to add to the IList.
          virtual void Add(const T& value) = 0;

          /// @brief Removes all items from the IList.
          /// @return UInt32 The position into which the new element was inserted.
          /// Implementations of this method can vary in how they handle the ICollection..::.Count and the capacity of a collection.
          /// Typically, the count is set to zero, and references to other objects from elements of the collection are also released.
          /// The capacity can be set to zero or a default value, or it can remain unchanged.
          virtual void Clear() = 0;

          /// @brief Determines whether the IList contains a specific value.
          /// @param value The object to locate in the IList.
          /// @return Boolean true if the object is found in the IList; otherwise, false.
          virtual bool Contains(const T& value) const = 0;

          /// @brief Copies the elements of the ICollection to an Array, starting at a particular Array index.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins;
          /// @return Int32 Number of elements copied.
          /// @return @see object
          virtual void CopyTo(System::Array<T>& array, int32 index) const = 0;

          /// @brief Removes the first occurrence of a specific object from the IList.
          /// @param value The object to remove from the IList.
          /// @return Boolean true if item is successfully removed; otherwise, false. This method also returns false if item was not found in the ICollection.
          virtual bool Remove(const T& value) = 0;

        protected:
          /// @brief Gets the number of elements contained in the ICollection.
          /// @return Int32 The number of elements contained in the ICollection.
          virtual int32 GetCount() const = 0;

          /// @brief Gets a value indicating whether the ICollection is read-only.
          /// @return Boolean true if the ICollection is read-only; otherwise; otherwise, false.
          virtual bool GetIsReadOnly() const = 0;

          /// @brief Gets a value indicating whether access to the ICollection is synchronized (thread safe).
          /// @return Boolean true if access to the ICollection is synchronized (thread safe); otherwise, false.
          virtual bool GetIsSynchronized() const = 0;

          /// @brief Gets an object that can be used to synchronize access to the ICollection.
          /// @return object An object that can be used to synchronize access to the ICollection.
          /// @remarks In the absence of a Synchronized method on a collection, the expected usage for SyncRoot looks as follows:
          /// @code
          /// refptr<ICollection> collection;
          /// // Instantiate and populate the collection
          /// lock_ (collection->SyncRoot) {
          ///   // Some operation on the collection, which is now thread safe.
          /// }
          /// @endcode
          virtual const Object& GetSyncRoot() const = 0;
        };
      }
    }
  }
}

using namespace Switch;
