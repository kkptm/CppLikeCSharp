/// @file
/// @brief Contains Switch::System::Byte struct.
#pragma once

#include <limits>
#include "../Property.hpp"
#include "../Types.hpp"
#include "IComparable.hpp"
#include "IConvertible.hpp"
#include "IFormattable.hpp"
#include "Object.hpp"
#include "_String.hpp"
#include "ValueType.hpp"
#include "DivideByZeroException.hpp"
#include "OverflowException.hpp"
#include "TypeCode.hpp"

/// @cond
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents a 8-bit unsigned integer.
    struct core_export_ Byte final : public ValueType, public IComparable, public IConvertible, public IFormattable {
    public:
      /// @brief Create a new instance of struct Byte
      /// @remarks Byte is initialized by default to 0.
      Byte() {}

      /// @brief Create a new instance of struct Byte
      /// @param value Value for the Byte.
      Byte(byte value) : value(value) {}

      /// @cond
      Byte(const Byte& value) : value(value.value) {}
      Byte& operator=(const Byte& value) {
        this->value = value.value;
        return *this;
      }
      operator const byte& () const {return this->value;}
      template<typename T> Byte& operator=(T value) {this->value = value; return *this;}
      template<typename T> Byte& operator+=(T value) {this->value += value.value; return *this;}
      template<typename T> Byte& operator-=(T value) {this->value -= value; return *this;}
      template<typename T> Byte& operator*=(T value) {this->value *= value; return *this;}
      template<typename T> Byte& operator/=(T value) {if (value.value == 0) throw DivideByZeroException(caller_); this->value /= value.value; return *this;}
      template<typename T> Byte& operator%=(T value) {if (value.value == 0) throw DivideByZeroException(caller_); this->value %= value.value; return *this;}
      template<typename T> Byte& operator&=(T value) {this->value &= value; return *this;}
      template<typename T> Byte& operator|=(T value) {this->value |= value; return *this;}
      template<typename T> Byte& operator^=(T value) {this->value ^= value; return *this;}
      template<typename T> Byte& operator<<=(T value) {this->value <<= value; return *this;}
      template<typename T> Byte& operator>>=(T value) {this->value >>= value; return *this;}
      template<typename T> bool operator==(T value) const {return this->value == value;}
      template<typename T> bool operator!=(T value) const {return !this->operator==(value);}
      Byte& operator++() {++this->value; return *this;}
      const Byte operator++(int) {return this->value++;}
      Byte& operator--() {--this->value; return *this;}
      const Byte operator--(int) {return this->value--;}

      friend core_export_ std::ostream& operator<<(std::ostream& output, const Byte& value);
      /// @endcond

      /// @brief Represents the largest possible value of an Byte 255 (0xFF). This field is constant.
      static constexpr byte MaxValue = std::numeric_limits<byte>::max();

      /// @brief Represents the smallest possible value of Byte 0 (0x00). This field is constant.
      static constexpr byte MinValue = std::numeric_limits<byte>::min();

      /// @brief Compares this instance to a specified Byte object and returns an indication of their relative values.
      /// @param value An Byte object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// | result            | Condition                                                                   |
      /// |-------------------|-----------------------------------------------------------------------------|
      /// | Less than zero    | This instance is false and value is true.                                   |
      /// | Zero              | This instance and value are equal (either both are true or both are false). |
      /// | Greater than zero | This instance is true and value is false.  -or- value is null reference.    |
      int32 CompareTo(const Byte& value) const {return this->value - value.value;}

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// | result            | Condition                                                   ,             |
      /// |-------------------|---------------------------------------------------------------------------|
      /// | Less than zero    | This instance is false and obj is true.                                   |
      /// | Zero              | This instance and obj are equal (either both are true or both are false). |
      /// | Greater than zero | This instance is true and obj is false.  -or- obj is null reference.      |
      int32 CompareTo(const IComparable& obj) const override {
        if (!is<Byte>(obj))
          return 1;
        return CompareTo(static_cast<const Byte&>(obj));
      }

      /// @brief Determines whether two specified DateTime objects have the same value.
      /// @param dateTimeA The first DateTime to compare.
      /// @param dateTimeB The second DateTime to compare.
      /// @return bool true if the value of dateTimenA is the same as the value of dateTimeB; otherwise, false.
      bool Equals(byte value) const {return this->value == value;}

      /// @cond
      bool Equals(const Byte& value) const {return this->value == value;}

      template<typename T>
      bool Equals(T value) const {return false;}
      /// @endcond

      /// @brief Determines whether this instance of Exception and a specified object, which must also be a Exception object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const object& obj) const override {return is<Byte>(obj) && Equals(((const Byte&)obj).value);}

      /// @brief Serves as a hash function for a particular type.
      /// @return int32 A hash code for the current object.
      int32 GetHashCode() const override {return this->value;}

      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      TypeCode GetTypeCode() const override {return TypeCode::Byte;}

      /// @brief Converts the specified String representation of a logical value to its 8-bit unsigned integer equivalent.
      /// @param str A String containing the value to convert.
      /// @return A 8-bit unsigned integer equivalent to the number contained in str.
      static byte Parse(const String& str) {return Parse(str, 10);}

      /// @brief Converts the specified String representation of a logical value to its 8-bit unsigned integer equivalent.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @return A 8-bit unsigned integer equivalent to the number contained in str.
      static byte Parse(const String& str, const int32 base);

      /// @brief Returns a String that represents the current Byte.
      /// @return String A String that represents the current Byte.
      String ToString() const override {return ToString("g", ref<IFormatProvider>::Null());}

      /// @brief Returns a String that represents the current Byte.
      /// @param format Format-control String.
      /// @return String A String that represents the current Byte.
      String ToString(const String& format) const {return ToString(format, ref<IFormatProvider>::Null());}

      /// @brief Returns a String that represents the current Byte.
      /// @param format Format-control String.
      /// @return String A String that represents the current Byte.
      String ToString(const String& format, const IFormatProvider& formatProvider) const override;

      /// @brief Converts the specified String representation of a logical value to its 8-bit unsigned integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param retValue When this method returns, contains the 8-bit unsigned integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, byte& retValue) {return TryParse(str, 10, retValue);}

      /// @brief Converts the specified String representation of a logical value to its 8-bit unsigned integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @param retValue When this method returns, contains the 8-bit unsigned integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, int32 base, byte& retValue) {
        try {
          retValue = Parse(str, base);
          return true;
        } catch (const Exception&) {
          return false;
        }
      }

    private:
      friend class Convert;
      bool ToBoolean(const IFormatProvider& provider) const override {return this->value != 0;}
      byte ToByte(const IFormatProvider& provider) const override {return this->value;}
      char32 ToChar(const IFormatProvider& provider) const override {return this->value;}
      DateTime ToDateTime(const IFormatProvider& provider) const override;
      double ToDouble(const IFormatProvider& provider) const override {return this->value;}
      int16 ToInt16(const IFormatProvider& provider) const override {return this->value;}
      int32 ToInt32(const IFormatProvider& provider) const override {return this->value;}
      int64 ToInt64(const IFormatProvider& provider) const override {return this->value;}
      uint16 ToUInt16(const IFormatProvider& provider) const override {return this->value;}
      uint32 ToUInt32(const IFormatProvider& provider) const override {return this->value;}
      uint64 ToUInt64(const IFormatProvider& provider) const override {return this->value;}
      sbyte ToSByte(const IFormatProvider& provider) const override {if (this->value > std::numeric_limits<sbyte>::max()) throw OverflowException(caller_); return this->value;}
      float ToSingle(const IFormatProvider& provider) const override {return this->value;}
      String ToString(const IFormatProvider& provider) const override {return ToString();}

      byte value = 0;
    };
  }
}

using namespace Switch;
