/// @file
/// @brief Contains Switch::System::Collections::Generic::Comparer <T> class.
#pragma once

#include "../../Object.hpp"
#include "IComparer.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @brief Exposes a method that compares two objects.
        template<typename T>
        class Comparer : public Object, public IComparer<T> {
        public:
          /// @cond
          Comparer() {}
          /// @endcond

          /// @brief Returns a default sort order comparer for the type specified by the generic argument
          static const Comparer<T> Default;

          /// @brief Compares two entities and returns a value indicating whether one is less than, equal to, or greater than the other.
          /// @param x The first entity to compare.
          /// @param y The second entity to compare.
          /// @return Int32 A 32-bit signed integer that indicates the relative order of the entities being compared. The return value has these meanings:
          /// - Less than zero      x is less than y.
          /// - Zero                x equals y.
          /// - Greater than zero   x is greater than y.
          virtual int32 Compare(const T& x, const T& y) const {return x < y ? -1 : (x == y ? 0 : 1);}
        };

        /// @cond
        template<typename T>
        const Comparer<T> Comparer<T>::Default;

        template<typename T>
        class EmptyComparer : public Object, public IComparer<T> {
        public:
          EmptyComparer() {}
          virtual int32 Compare(const T& x, const T& y) const {return 0;}
        };
        /// @endcond
      }
    }
  }
}

using namespace Switch;
