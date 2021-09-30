/// @file
/// @brief Contains Switch::System::Boolean struct.
#pragma once

#include <cstdbool>

#include "../Is.hpp"
#include "../Property.hpp"
#include "../Types.hpp"
#include "IComparable.hpp"
#include "IConvertible.hpp"
#include "Object.hpp"
#include "_String.hpp"
#include "TypeCode.hpp"
#include "ValueType.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents a Boolean value.
    /// The following example illustrates formatting with the ToString method. Note that the example uses the composite formatting feature, so the ToString method is called implicitly.
    /// @include Boolean1.cpp
    /// Because the Boolean structure can have only two values, it is easy to add custom formatting. For simple custom formatting in which other string literals are substituted for "true" and "false", you can use any conditional evaluation feature supported by your language, such as the conditional operator in C++ or the If operator in Visual Basic. The following example uses this technique to format Boolean values as "Yes" and "No" rather than "true" and "false".
    /// @include Boolean2.cpp
    /// All conversions from integral or floating-point numbers to Boolean values convert non-zero values to true and zero values to false. The following example illustrates this by calling selected overloads of the Convert.ToBoolean class.
    /// @include Boolean3.cpp
    /// When converting from floating-point values to Boolean values, the conversion methods perform an exact comparison with zero. If the floating-point value has lost precision, the result can be unexpected. This is illustrated in the following example, in which a Double variable whose value should be zero is converted to a Boolean value. As the example shows, the result is true because repeated additions of 0.2 have resulted in a loss of precision.
    /// When converting from Boolean to numeric values, the conversion methods of the Convert class convert true to 1 and false to 0. However, Visual Basic conversion functions convert true to either 255 (for conversions to Byte values) or -1 (for all other numeric conversions). The following example converts true to numeric values by using a Convert method, and, in the case of the Visual Basic example, by using the Visual Basic language's own conversion operator.
    /// @include Boolean4.cpp
    /// For conversions from Boolean to string values, see the Formatting Boolean Values section. For conversions from strings to Boolean values, see the Parsing Boolean Values section.
    /// Parsing Boolean values
    /// The Boolean structure includes two static parsing methods, Parse and TryParse, that convert a string to a Boolean value. The string representation of a Boolean value is defined by the case-insensitive equivalents of the values of the TrueString and FalseString fields, which are "true" and "false", respectively. In other words, the only strings that parse successfully are "true", "false", "true", "false", or some mixed-case equivalent. You cannot successfully parse numeric strings such as "0" or "1". Leading or trailing white-space characters are not considered when performing the string comparison.
    /// The following example uses the Parse and TryParse methods to parse a number of strings. Note that only the case-insensitive equivalents of "true" and "false" can be successfully parsed.
    /// @include Boolean5.cpp
    /// To convert the string representation of a number to a Boolean value you must convert your numeric string to a number before converting it to a Boolean. The following example illustrates this by converting an array of integers to Boolean values.
    /// @include  Boolean6.cpp
    /// Comparing Boolean values
    /// Because Boolean values are either true or false, there is little reason to explicitly call the CompareTo method, which indicates whether an instance is greater than, less than, or equal to a specified value. Typically, to compare two Boolean variables, you call the Equals method or use your language's equality operator.
    /// However, when you want to compare a Boolean variable with the literal Boolean value true or false, it is not necessary to do an explicit comparison, because the result of evaluating a Boolean value is that Boolean value. For example, the expressions
    /// @code
    /// if (booleanValue) {
    /// @endcode
    /// and
    /// @include Boolean8.cpp
    /// are equivalent, but the second is more compact. However, both techniques offer comparable performance.
    struct core_export_ Boolean final : public ValueType, public IComparable, public IConvertible {
    public:
      /// @brief Create a new instance of struct Boolean
      /// @remarks Boolean is initialized by default to false.
      Boolean() {}

      /// @brief Create a new instance of struct Boolean
      /// @param value Value for the Boolean. true or false.
      Boolean(int32 value) : value(value != 0) {} // int value instead of bool to avoid too many implicit casts (int vs bool in c++)

      /// @cond
      Boolean(const Boolean& value) : value(value.value) {}
      virtual Boolean& operator =(const Boolean& value) {this->value = value; return *this;}
      virtual Boolean& operator =(int32 value) {this->value = value != 0; return *this;}
      operator bool() const { return this->value; }

      friend core_export_ std::ostream& operator<<(std::ostream& output, const Boolean& value);
      /// @endcond

      /// @brief Represent false bool value
      static constexpr bool False = false;

      /// @brief Represent true bool value
      static constexpr bool True = true;

      /// @brief Returns a string that represents true value.
      static const String FalseString;

      /// @brief Returns a string that represents false value.
      static const String TrueString;

      /// @brief Compares this instance to a specified Boolean Object and returns an indication of their relative values.
      /// @param value An Boolean Object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the Objects being compared. The return value has these meanings:
      /// | result            | Condition                                                                   |
      /// |-------------------|-----------------------------------------------------------------------------|
      /// | Less than zero    | This instance is false and value is true.                                   |
      /// | Zero              | This instance and value are equal (either both are true or both are false). |
      /// | Greater than zero | This instance is true and value is false.  -or- value is null reference.    |
      int32 CompareTo(const Boolean& value) const {return this->value - value.value;}

      /// @brief Compares the current instance with another Object of the same type.
      /// @param obj An Object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the Objects being compared. The return value has these meanings:
      /// | result            | Condition                                                   ,             |
      /// |-------------------|---------------------------------------------------------------------------|
      /// | Less than zero    | This instance is false and obj is true.                                   |
      /// | Zero              | This instance and obj are equal (either both are true or both are false). |
      /// | Greater than zero | This instance is true and obj is false.  -or- obj is null reference.      |
      int32 CompareTo(const IComparable& obj) const override {
        if (!is<Boolean>(obj)) return 1;
        return CompareTo(static_cast<const Boolean&>(obj));
      }

      /// @brief Determines whether this instance of Boolean and a specified Object, which must also be a Boolean Object, have the same value.
      /// @param value The Boolean to compare with the current Object.
      /// @return Boolean true if the specified value is equal to the current Object. otherwise, false.
      bool Equals(bool value) const { return this->value == value; }

      /// @brief Determines whether this instance of Boolean and a specified Object, which must also be a Boolean Object, have the same value.
      /// @param obj The Object to compare with the current Object.
      /// @return Boolean true if the specified Object is equal to the current Object. otherwise, false.
      bool Equals(const Object& obj) const override {return is<Boolean>(obj) && Equals(((const Boolean&)obj).value);}

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current Object.
      int32 GetHashCode() const override { return this->value; }

      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      TypeCode GetTypeCode() const override {return TypeCode::Boolean;}

      /// @brief Converts the specified string representation of a logical value to its Boolean equivalent.
      /// @param str A string containing the value to convert.
      /// @return Boolean true if str is equivalent to TrueString; otherwise, false.
      /// @exception ArgumentException str is not equivalent to TrueString or FalseString.
      static bool Parse(const String& str);

      /// @brief Converts the specified string representation of a logical value to its Boolean equivalent.
      /// @param str A string containing the value to convert.
      /// @param result When this method returns, if the conversion succeeded, contains true if str is equivalent to TrueString or false if str is equivalent to FalseString. If the conversion failed, contains false. The conversion fails if value is null reference or is not equivalent to either TrueString or FalseString. This parameter is passed uninitialized.
      /// @return Boolean true if value was converted successfully; otherwise, false.
      static bool TryParse(const String& str, bool& result);

      /// @brief Returns a string that represents the current Boolean.
      /// @return const string A string that represents the current Boolean.
      String ToString() const override;

    protected:
      /// @cond
      bool value = false;
      /// @endcond

    private:
      friend class Convert;
      bool ToBoolean(const IFormatProvider& provider) const override {return this->value;}
      byte ToByte(const IFormatProvider& provider) const override {return this->value ? 1 : 0;}
      char32 ToChar(const IFormatProvider& provider) const override {return this->value ? '1' : '0';}
      DateTime ToDateTime(const IFormatProvider& provider) const override;
      double ToDouble(const IFormatProvider& provider) const override {return this->value ? 1 : 0;}
      int16 ToInt16(const IFormatProvider& provider) const override {return this->value ? 1 : 0;}
      int32 ToInt32(const IFormatProvider& provider) const override {return this->value ? 1 : 0;}
      int64 ToInt64(const IFormatProvider& provider) const override {return this->value ? 1 : 0;}
      uint16 ToUInt16(const IFormatProvider& provider) const override {return this->value ? 1 : 0;}
      uint32 ToUInt32(const IFormatProvider& provider) const override {return this->value ? 1 : 0;}
      uint64 ToUInt64(const IFormatProvider& provider) const override {return this->value ? 1 : 0;}
      sbyte ToSByte(const IFormatProvider& provider) const override {return this->value ? 1 : 0;}
      float ToSingle(const IFormatProvider& provider) const override {return this->value ? 1.0f : 0.0f;}
      String ToString(const IFormatProvider& provider) const override;
    };
  }
}

using namespace Switch;
