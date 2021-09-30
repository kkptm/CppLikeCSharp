/// @file
/// @brief Contains Switch::System::TypeCode enum.
#pragma once

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @enum TypeCode
    /// @brief Specifies the type of an object.
    /// @see IConvertible
    enum class TypeCode {
      /// @brief A null reference.
      Empty = 0,
      /// @brief A general type representing any reference or value type not explicitly represented by another TypeCode.
      Object = 1,
      ///
      DBNull = 2,
      /// @brief A simple type representing Boolean values of true or false.
      Boolean = 3,
      /// @brief An integral type representing unsigned 8-bit integers with values between 0 and 255. The set of possible values for the System::TypeCode.Char type corresponds to the Unicode character set.
      Char = 4,
      /// @brief An integral type representing signed 8-bit integers with values between -128 and 127.
      SByte = 5,
      /// @brief An integral type representing unsigned 8-bit integers with values between 0 and 255.
      Byte = 6,
      /// @brief An integral type representing signed 16-bit integers with values between -32768 and 32767.
      Int16 = 7,
      /// @brief An integral type representing unsigned 16-bit integers with values between 0 and 65535.
      UInt16 = 8,
      /// @brief An integral type representing signed 32-bit integers with values between -2147483648 and 2147483647.
      Int32 = 9,
      /// @brief An integral type representing unsigned 32-bit integers with values between 0 and 4294967295.
      UInt32 = 10,
      /// @brief An integral type representing signed 64-bit integers with values between -9223372036854775808 and 9223372036854775807.
      Int64 = 11,
      /// @brief An integral type representing unsigned 64-bit integers with values between 0 and 18446744073709551615.
      UInt64 = 12,
      /// @brief A floating point type representing values ranging from approximately 1.5 x 10 -45 to 3.4 x 10 38 with a precision of 7 digits.
      Single = 13,
      /// @brief A floating point type representing values ranging from approximately 5.0 x 10 -324 to 1.7 x 10 308 with a precision of 15-16 digits.
      Double = 14,
      ///
      Decimal = 15,
      /// @brief A type representing a date and time value.
      DateTime = 16,
      /// @brief A sealed class type representing Unicode character strings.
      String = 18,
    };
  }
}

/*
#include "Enum.hpp"

/// @cond
template<>
struct EnumRegister<System::TypeCode> {
  void operator()(System::Collections::Generic::IDictionary<System::TypeCode, string>& values, bool& flags) {
    values[System::TypeCode::Empty] = "Empty";
    values[System::TypeCode::Object] = "Object";
    values[System::TypeCode::Boolean] = "Boolean";
    values[System::TypeCode::Char] = "Char";
    values[System::TypeCode::SByte] = "SByte";
    values[System::TypeCode::Byte] = "Byte";
    values[System::TypeCode::Int16] = "Int16";
    values[System::TypeCode::UInt16] = "UInt16";
    values[System::TypeCode::Int32] = "Int32";
    values[System::TypeCode::UInt32] = "UInt32";
    values[System::TypeCode::Int64] = "Int64";
    values[System::TypeCode::UInt64] = "UInt64";
    values[System::TypeCode::Single] = "Single";
    values[System::TypeCode::Double] = "Double";
    values[System::TypeCode::DateTime] = "DateTime";
    values[System::TypeCode::String] = "String";
    flags = false;
  }
};
/// @endcond
 */

using namespace Switch;
