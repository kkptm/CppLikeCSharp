/// @file
/// @brief Contains Switch::System::Collections::Concurrent::IProducerConsumerCollection interface.
#pragma once

#include "../../../Types.hpp"
#include "../../Array.hpp"
#include "../Generic/ICollection.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Concurrent namespace provides several thread-safe collection classes that should be used in place of the corresponding types in the System::Collections and System::Collections::Generic namespaces whenever multiple threads are accessing the collection concurrently.
      namespace Concurrent {
        /// @interface IProducerConsumerCollection
        /// @brief Defines methods to manipulate thread-safe collections intended for producer/consumer usage. This interface provides a unified representation for producer/consumer collections so that higher level abstractions such as System::Collections::Concurrent::BlockingCollection<T> can use the collection as the underlying storage mechanism.
        /// @par Library
        /// Switch.Core
        template<typename T>
        class IProducerConsumerCollection : public Generic::ICollection<T> {
        public:
          /// @brief Copies the elements of the IProducerConsumerCollection<T> to an Array, starting at a specified index.
          /// @param array TThe one-dimensional Array that is the destination of the elements copied from the IProducerConsumerCollection<T>. The array must have zero-based indexing.
          /// @param index The zero-based index in array at which copying begins;
          virtual void CopyTo(System::Array<T>& array, int32 index) const = 0;

          /// @brief Copies the elements contained in the IProducerConsumerCollection<T> to a new array.
          /// @return A new array containing the elements copied from the IProducerConsumerCollection<T>.
          virtual System::Array<T> ToArray() const = 0;

          /// @brief Attempts to add an object to the IProducerConsumerCollection<T>.
          /// @param item The object to add to the IProducerConsumerCollection<T>.
          /// @return true if the object was added successfully; otherwise, false.
          /// @exception ArgumentException The item was invalid for this collection.
          virtual bool TryAdd(const T& item) = 0;

          /// @brief Attempts to remove and return an object from the IProducerConsumerCollection<T>.
          /// @param result When this method returns, if the object was removed and returned successfully, item contains the removed object. If no object was available to be removed, the value is unspecified.
          /// @return true if an object Netwas removed and returned successfully; otherwise, false.
          virtual bool TryTake(T& result) = 0;
        };
      }
    }
  }
}
