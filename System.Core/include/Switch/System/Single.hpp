/// @file
/// @brief Contains Switch::System::Single struct.
#pragma once

#include <limits>
#include "Object.hpp"
#include "../Property.hpp"
#include "../Types.hpp"
#include "_String.hpp"
#include "IComparable.hpp"
#include "IConvertible.hpp"
#include "IFormattable.hpp"
#include "ValueType.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents a single-precision floating-point number.
    struct core_export_ Single final : public ValueType, public IComparable, public IConvertible, public IFormattable {
    public:
      /// @brief Represents the smallest positive Single value greater than zero. This field is constant.
      static constexpr float Epsilon = 1.401298E-45F;

      /// @brief Represents the largest possible value of an Single 3.40282e+038f. This field is constant.
      static constexpr float MaxValue = std::numeric_limits<float>::max();

      /// @brief Represents the smallest possible value of Single -3.40282e+038f. This field is constant.
      static constexpr float MinValue = -std::numeric_limits<float>::max();

      /// @brief Represents not a number (NaN). This field is constant.
      static constexpr float NaN = std::numeric_limits<float>::quiet_NaN();

      /// @brief Represents negative infinity. This field is constant.
      static constexpr float NegativeInfinity = -std::numeric_limits<float>::infinity();

      /// @brief Represents positive infinity. This field is constant.
      static constexpr float PositiveInfinity = std::numeric_limits<float>::infinity();

      /// @brief Create a new instance of struct Single
      /// @remarks Single is initialized with the default value 0.
      Single() {}

      /// @brief Create a new instance of struct Single
      /// @param value Value for the Single.
      Single(float value) : value(value) {}

      /// @brief Converts the specified String representation of a logical value to its single-precision floating-point number equivalent.
      /// @param str A String containing the value to convert.
      /// @return A single-precision floating-point number equivalent to the number contained in str.
      /// @exception ArgumentNullException The parameters str is null.
      static float Parse(const String& str);

      /// @brief Returns a value indicating whether the specified number evaluates to negative or positive infinity.
      /// @param value A single-precision floating-point number.
      /// @return bool true if value evaluates to PositiveInfinity or NegativeInfinity; otherwise, false.
      static bool IsInfinity(float value);

      /// @brief Returns a value indicating whether the specified number evaluates to not a number.
      /// @param value A single-precision floating-point number.
      /// @return bool true if value evaluates to not a number; otherwise, false.
      static bool IsNaN(float value);

      /// @brief Returns a value indicating whether the specified number evaluates to negative infinity.
      /// @param value A single-precision floating-point number.
      /// @return bool true if value evaluates to NegativeInfinity; otherwise, false.
      static bool IsNegativeInfinity(float value);

      /// @brief Returns a value indicating whether the specified number evaluates to positive infinity.
      /// @param value A single-precision floating-point number.
      /// @return bool true if value evaluates to PositiveInfinity; otherwise, false.
      static bool IsPositiveInfinity(float value);

      /// @brief Determines whether this instance of Single and a specified Object, which must also be a Single Object, have the same value.
      /// @param value The Single to compare with the current Object.
      /// @return bool true if the specified value is equal to the current Object. otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      bool Equals(const Single& value) const;

      /// @brief Determines whether this instance of Single and a specified Object, which must also be a Single Object, have the same value.
      /// @param obj The Object to compare with the current Object.
      /// @return bool true if the specified Object is equal to the current Object. otherwise, false.
      bool Equals(const Object& obj) const override;

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current Object.
      int32 GetHashCode() const override;

      /// @brief Returns a String that represents the current Single.
      /// @return String A String that represents the current Single.
      String ToString() const override;

      /// @brief Returns a String that represents the current Single.
      /// @param format Format-control String.
      /// @param formatProvider an IFormatProvider for specifie the format.
      /// @return String A String that represents the current Single.
      String ToString(const String& format, const IFormatProvider& formatProvider) const override;

      /// @brief Returns a String that represents the current Single.
      /// @param format Format-control String.
      /// @return String A String that represents the current Single.
      String ToString(const String& format) const;

      /// @brief Compares this instance to a specified Single Object and returns an indication of their relative values.
      /// @param value An Single Object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the Objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      int32 CompareTo(const Single& value) const;

      /// @brief Compares the current instance with another Object of the same type.
      /// @param obj An Object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the Objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      /// -or-
      /// obj is nullNothingnullptra null reference.
      int32 CompareTo(const IComparable& obj) const override;

      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      TypeCode GetTypeCode() const override;

    private:
      friend class Convert;

      bool ToBoolean(const IFormatProvider& provider) const override;
      byte ToByte(const IFormatProvider& provider) const override;
      char32 ToChar(const IFormatProvider& provider) const override;
      DateTime ToDateTime(const IFormatProvider& provider) const override;
      double ToDouble(const IFormatProvider& provider) const override;
      int16 ToInt16(const IFormatProvider& provider) const override;
      int32 ToInt32(const IFormatProvider& provider) const override;
      int64 ToInt64(const IFormatProvider& provider) const override;
      uint16 ToUInt16(const IFormatProvider& provider) const override;
      uint32 ToUInt32(const IFormatProvider& provider) const override;
      uint64 ToUInt64(const IFormatProvider& provider) const override;
      sbyte ToSByte(const IFormatProvider& provider) const override;
      float ToSingle(const IFormatProvider& provider) const override;
      String ToString(const IFormatProvider& provider) const override;

      float value = 0;

    public:
      /// @cond
      Single(const Single& value) : value(value.value) {}
      operator float() const;
      Single& operator =(const Single& value);
      Single& operator +=(const Single& value);
      Single& operator -=(const Single& value);
      Single& operator *=(const Single& value);
      Single& operator /=(const Single& value);
      Single& operator ++();
      const Single operator ++(int);
      Single& operator --();
      const Single operator --(int);
      /// @endcond
    };
  }
}

using namespace Switch;
