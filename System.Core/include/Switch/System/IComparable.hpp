/// @file
/// @brief Contains Switch::System::IComparable interface.
#pragma once

#include "../Interface.hpp"
#include "../Types.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @interface IComparable
    /// @brief Defines a generalized comparison method that a value type or class implements to create a type-specific comparison method.
    class core_export_ IComparable interface_ {
    public:
      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared.
      /// The return value has these meanings:
      /// | Value             | Condition                          |
      /// |-------------------|------------------------------------|
      /// | Less than zero    | This instance is less than obj.    |
      /// | Zero              | This instance is equal to obj.     |
      /// | Greater than zero | This instance is greater than obj. |
      virtual int32 CompareTo(const IComparable& obj) const = 0;

      ///@cond
      // Not correct for an interface but necessary for C++ language.
      bool operator<(const IComparable& obj) const { return CompareTo(obj) < 0; }
      bool operator<=(const IComparable& obj) const { return CompareTo(obj) <= 0; }
      bool operator>(const IComparable& obj) const { return CompareTo(obj) > 0; }
      bool operator>=(const IComparable& obj) const { return CompareTo(obj) >= 0; }
      ///@endcond
    };
  }
}

using namespace Switch;
