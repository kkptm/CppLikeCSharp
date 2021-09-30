/// @file
/// @brief Contains Switch::System::IntPtr struct.
#pragma once

#include "Object.hpp"
#include "../Property.hpp"
#include "../Types.hpp"
#include "_String.hpp"
#include "IComparable.hpp"
#include "IFormattable.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    struct Int32;
    struct Int64;
    /// @endcond

    /// @brief A platform-specific type that is used to represent a pointer or a handle.
    struct core_export_ IntPtr final : public object, public IComparable, public IFormattable {
    public:
      /// @brief A read-only field that represents a pointer or handle that has been initialized to zero.
      static constexpr intptr Zero = 0;

      /// @brief Gets the size of this instance.
      /// @return Int32 The size of a pointer or handle on this platform, measured in bytes. The value of this property is 4 on a 32-bit platform, and 8 on a 64-bit platform.
      static constexpr int32 Size = static_cast<int32>(sizeof(intptr));

      /// @brief Create a new instance of class IntPtr
      /// @remarks IntPtr is initialized by default to null.
      IntPtr() {}

      /// @brief Create a new instance of class IntPtr
      /// @param value A pointer or handle contained in a 32-bit signed integer.
      explicit IntPtr(const Int32& value);

      /// @brief Create a new instance of class IntPtr
      /// @param value A pointer or handle contained in a 64-bit signed integer.
      /// @exception OverflowException On a 32-bit platform, value is too large or too small to represent as an IntPtr
      explicit IntPtr(const Int64& value);

      /// @brief Create a new instance of class IntPtr
      /// @param value A pointer to an unspecified type.
      IntPtr(intptr value);

      /// @brief Determines whether this instance of IntPtr and a specified object, which must also be a IntPtr object, have the same value.
      /// @param value The IntPtr to compare with the current object.
      /// @return bool true if the specified value is equal to the current object. otherwise, false.
      bool Equals(const IntPtr& value) const;

      /// @brief Determines whether this instance of IntPtr and a specified object, which must also be a IntPtr object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const object& obj) const override;

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current object.
      int32 GetHashCode() const override;

      /// @brief Converts the value of this instance to a 32-bit signed integer.
      /// @return Int32 A 32-bit signed integer equal to the value of this instance.
      /// @exception OverflowException On a 64-bit platform, the value of this instance is too large or too small to represent as a 32-bit signed integer.
      int32 ToInt32() const;

      /// @brief Converts the value of this instance to a 64-bit signed integer.
      /// @return Int64 A 64-bit signed integer equal to the value of this instance.
      int64 ToInt64() const;

      /// @brief Converts the value of this instance to a pointer to an unspecified type.
      /// @return void* A pointer to void; that is, a pointer to memory containing data of an unspecified type.
      void* ToPointer() const;

      /// @brief Converts the numeric value of the current IntPtr object to its equivalent String representation.
      /// @return const String The String representation of the value of this instance.
      String ToString() const override;

      /// @brief Converts the numeric value of the current IntPtr object to its equivalent String representation.
      /// @param format Format-control String.
      /// @return String The String representation of the value of the current IntPtr object.
      String ToString(const String& format) const;

      /// @brief Returns a String that represents the current IntPtr.
      /// @param format Format-control String.
      /// @param formatProvider an IFormatProvider for specifie the format.
      /// @return String A String that represents the current IntPtr.
      String ToString(const String& format, const IFormatProvider& formatProvider) const override;

      /// @brief Compares this instance to a specified Int32 object and returns an indication of their relative values.
      /// @param value An Int32 object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      int32 CompareTo(const IntPtr& value) const;

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      /// -or-
      /// obj is nullNothingnullptra null reference.
      int32 CompareTo(const IComparable& obj) const override;

    private:
      friend class String;

      intptr value = 0;

    public:
      /// @cond
      IntPtr(const IntPtr& value) : value(value.value) {}
      operator intptr() const;
      IntPtr& operator =(const IntPtr& value);
      /// @endcond
    };
  }
}

using namespace Switch;
