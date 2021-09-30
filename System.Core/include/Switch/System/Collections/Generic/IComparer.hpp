/// @file
/// @brief Contains Switch::System::Collections::Generic::IComparer <T> interface.
#pragma once

#include "../../../Types.hpp"
#include "../../../Interface.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @interface IComparer
        /// @brief Exposes a method that compares two objects.
        template<typename T>
        class IComparer interface_ {
        public:
          /// @brief Compares two entities and returns a value indicating whether one is less than, equal to, or greater than the other.
          /// @param x The first entity to compare.
          /// @param y The second entity to compare.
          /// @return int32 A 32-bit signed integer that indicates the relative order of the entities being compared. The return value has these meanings:
          /// | Value             | Condition            |
          /// |-------------------|----------------------|
          /// | Less than zero    | x is less than y.    |
          /// | Zero              | x equals y.          |
          /// | Greater than zero | x is greater than y. |
          virtual int32 Compare(const T& x, const T& y) const = 0;
        };
      }
    }
  }
}

using namespace Switch;
