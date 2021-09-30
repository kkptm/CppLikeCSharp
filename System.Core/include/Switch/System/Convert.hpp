/// @file
/// @brief Contains Switch::System::Convert class.
#pragma once

#include "../NullPtr.hpp"
#include "../Types.hpp"
#include "../RefPtr.hpp"
#include "Boolean.hpp"
#include "Byte.hpp"
#include "Char.hpp"
#include "DateTime.hpp"
#include "Decimal.hpp"
#include "Double.hpp"
#include "IConvertible.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Int64.hpp"
#include "IntPtr.hpp"
#include "InvalidCastException.hpp"
#include "OverflowException.hpp"
#include "SByte.hpp"
#include "Single.hpp"
#include "_String.hpp"
#include "SystemException.hpp"
#include "UInt16.hpp"
#include "UInt32.hpp"
#include "UInt64.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @cond
  class Any;
  /// @endcond

  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents API to convert base TypeCode.
    /// This class cannot be inherited.
    class core_export_ Convert final {
    public:
      /// @cond
      Convert() = delete;
      /// @endcond

      /// @brief Convert IConvertible object to bool
      /// @param converter IConvertible object to convert
      /// @return bool A new bool object converted from converter
      static bool ToBoolean(const IConvertible& converter) {return converter.ToBoolean(*provider);}

      /// @brief Convert object to bool
      /// @param value object to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(object& value) {return ToBoolean((const object&)value);}

      /// @brief Convert object to bool
      /// @param value object to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const object& value) {
        if (is<Boolean>(value)) return ToBoolean(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToBoolean(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToBoolean(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToBoolean(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToBoolean(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToBoolean(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToBoolean(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToBoolean(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToBoolean(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToBoolean(static_cast<const Single&>(value));
        if (is<String>(value)) return ToBoolean(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToBoolean(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToBoolean(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToBoolean(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to bool
      /// @param value object to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(Any& value);

      /// @brief Convert Any to bool
      /// @param value object to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const Any& value);

      /// @brief Convert bool to bool
      /// @param value bool to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(bool value) { return value; }

      /// @brief Convert bool to bool
      /// @param value bool to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const Boolean& value) { return value; }

      /// @brief Convert byte to bool
      /// @param value bool to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(byte value) { return value != 0; }

      /// @brief Convert byte to bool
      /// @param value byte to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const Byte& value) { return value != 0; }

      /// @brief Calling this method always throws InvalidCastException.
      static bool ToBoolean(char value) { throw InvalidCastException(caller_); }

      /// @brief Calling this method always throws InvalidCastException.
      static bool ToBoolean(char32 value) { throw InvalidCastException(caller_); }

      /// @brief Calling this method always throws InvalidCastException.
      static bool ToBoolean(const Char& value) { throw InvalidCastException(caller_); }

      /// @brief Calling this method always throws InvalidCastException.
      static bool ToBoolean(const DateTime& value) { throw InvalidCastException(caller_); }

      /// @brief Convert decimal to bool
      /// @param value decimal to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(decimal value) { return value != 0; }

      /// @brief Convert double to bool
      /// @param value double to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(double value) { return value != 0; }

      /// @brief Convert double to bool
      /// @param value double to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const Double& value) { return value != 0; }

      /// @brief Convert int16 to bool
      /// @param value int16 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(int16 value) { return value != 0; }

      /// @brief Convert int16 to bool
      /// @param value int16 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const Int16& value) { return value != 0; }

      /// @brief Convert int32 to bool
      /// @param value int32 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(int32 value) { return value != 0; }

      /// @brief Convert int32 to bool
      /// @param value int32 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const Int32& value) { return value != 0; }

      /// @brief Convert int64 to bool
      /// @param value int64 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(int64 value) { return value != 0; }

      /// @brief Convert int64 to bool
      /// @param value int64 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const Int64& value) { return value != 0; }

      /// @brief Convert sbyte to bool
      /// @param value sbyte to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(sbyte value) { return value != 0; }

      /// @brief Convert sbyte to bool
      /// @param value sbyte to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const SByte& value) { return value != 0; }

      /// @brief Convert single to bool
      /// @param value single to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(float value) { return value != 0.0; }

      /// @brief Convert single to bool
      /// @param value single to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const Single& value) { return value != 0.0; }

      /// @brief Convert string to bool
      /// @param value string to convert
      /// @return bool A new bool object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      static bool ToBoolean(const char* value) { return Boolean::Parse(value); }

      /// @brief Convert string to bool
      /// @param value string to convert
      /// @return bool A new bool object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      static bool ToBoolean(const string& value) { return Boolean::Parse(value); }

      /// @brief Convert uint16 to bool
      /// @param value uint16 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(uint16 value) { return value != 0; }

      /// @brief Convert uint16 to bool
      /// @param value uint16 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const UInt16& value) { return value.value != 0; }

      /// @brief Convert uint32 to bool
      /// @param value uint32 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(uint32 value) { return value != 0; }

      /// @brief Convert uint32 to bool
      /// @param value uint32 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const UInt32& value) { return value.value != 0; }

      /// @brief Convert uint64 to bool
      /// @param value uint64 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(uint64 value) { return value != 0; }

      /// @brief Convert uint64 to bool
      /// @param value uint64 to convert
      /// @return bool A new bool object converted from value
      static bool ToBoolean(const UInt64& value) { return value.value != 0; }

      /// @brief Calling this method always throws InvalidCastException.
      template<typename T>
      static bool ToBoolean(T value) { return ToBoolean(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static bool ToBoolean(llong value) { return Int64((uint64)value).ToBoolean(*provider); }
      static bool ToBoolean(ullong value) { return UInt64((uint64)value).ToBoolean(*provider); }
      template<class T, class Attribute>
      static bool ToBoolean(const property_<T, Attribute>& value) { return ToBoolean(value()); }
      /// @endcond

      /// @brief Convert IConvertible object to byte
      /// @param converter IConvertible object to convert
      /// @return byte A new byte object converted from converter
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const IConvertible& converter) {return converter.ToByte(*provider);}

      /// @brief Convert object to byte
      /// @param value object to convert
      /// @return byte A new byte object converted from value
      static byte ToByte(object& value) {return ToByte((const object&)value);}

      /// @brief Convert object to bool
      /// @param value object to convert
      /// @return bool A new bool object converted from value
      static byte ToByte(const object& value) {
        if (is<Boolean>(value)) return ToByte(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToByte(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToByte(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToByte(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToByte(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToByte(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToByte(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToByte(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToByte(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToByte(static_cast<const Single&>(value));
        if (is<String>(value)) return ToByte(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToByte(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToByte(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToByte(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to byte
      /// @param value object to convert
      /// @return byte A new byte object converted from value
      static byte ToByte(Any& value);

      /// @brief Convert Any to byte
      /// @param value object to convert
      /// @return byte A new byte object converted from value
      static byte ToByte(const Any& value);

      /// @brief Convert bool to byte
      /// @param value bool to convert
      /// @return byte A new byte object converted from value
      static byte ToByte(bool value) { return value ? 1 : 0; }

      /// @brief Convert bool to byte
      /// @param value bool to convert
      /// @return byte A new byte object converted from value
      static byte ToByte(const Boolean& value) { return value ? 1 : 0; }

      /// @brief Convert byte to byte
      /// @param value byte to convert
      /// @return byte A new byte object converted from value
      static byte ToByte(byte value) { return value; }

      /// @brief Convert byte to byte
      /// @param value byte to convert
      /// @return byte A new byte object converted from value
      static byte ToByte(const Byte& value) { return value; }

      /// @brief Convert char to byte
      /// @param value char to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(char value) {
        return static_cast<byte>(value);
      }

      /// @brief Convert Char to byte
      /// @param value Char to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(char32 value) {
        if (value > Byte::MaxValue)
          throw OverflowException(caller_);
        return static_cast<byte>(value);
      }

      /// @brief Convert Char to byte
      /// @param value Char to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const Char& value) {
        if (static_cast<char32>(value) > Byte::MaxValue)
          throw OverflowException(caller_);
        return static_cast<byte>(static_cast<char32>(value));
      }

      /// @brief Convert DateTime to byte
      /// @param value DateTime to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const DateTime& value) { throw InvalidCastException(caller_); }

      /// @brief Convert decimal to byte
      /// @param value decimal to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(decimal value) { return Decimal(value).ToByte(*provider); }

      /// @brief Convert double to byte
      /// @param value double to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(double value) { return Double(value).ToByte(*provider); }

      /// @brief Convert double to byte
      /// @param value double to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const Double& value) { return value.ToByte(*provider); }

      /// @brief Convert int16 to byte
      /// @param value int16 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(int16 value) { return Int16(value).ToByte(*provider); }

      /// @brief Convert int16 to byte
      /// @param value int16 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const Int16& value) { return value.ToByte(*provider); }

      /// @brief Convert int32 to byte
      /// @param value int32 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(int32 value) {return Int32(value).ToByte(*provider);}

      /// @brief Convert int32 to byte
      /// @param value int32 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const Int32& value) {return value.ToByte(*provider);}

      /// @brief Convert int64 to byte
      /// @param value int64 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(int64 value) { return Int64(value).ToByte(*provider); }

      /// @brief Convert int64 to byte
      /// @param value int64 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const Int64& value) { return value.ToByte(*provider); }

      /// @brief Convert sbyte to byte
      /// @param value sbyte to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue.
      static byte ToByte(sbyte value) { return SByte(value).ToByte(*provider); }
      /// @brief Convert sbyte to byte
      /// @param value sbyte to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue.
      static byte ToByte(const SByte& value) { return value.ToByte(*provider); }

      /// @brief Convert single to byte
      /// @param value single to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(float value) { return Single(value).ToByte(*provider); }

      /// @brief Convert single to byte
      /// @param value single to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const Single& value) { return value.ToByte(*provider); }

      /// @brief Convert string to byte
      /// @param value string to convert
      /// @return byte A new byte object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const char* value) { return Byte::Parse(value); }

      /// @brief Convert string to byte
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return byte A new byte object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const char* value, int32 base) { return Byte::Parse(value, base); }

      /// @brief Convert string to byte
      /// @param value string to convert
      /// @return byte A new byte object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const string& value) { return Byte::Parse(value); }

      /// @brief Convert string to byte
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return byte A new byte object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const string& value, int32 base) { return Byte::Parse(value, base); }

      /// @brief Convert uint16 to byte
      /// @param value uint16 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(uint16 value) { return UInt16(value).ToByte(*provider); }

      /// @brief Convert uint16 to byte
      /// @param value uint16 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const UInt16& value) { return value.ToByte(*provider); }

      /// @brief Convert uint32 to byte
      /// @param value uint32 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(uint32 value) { return UInt32(value).ToByte(*provider); }

      /// @brief Convert uint32 to byte
      /// @param value uint32 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const UInt32& value) { return value.ToByte(*provider); }

      /// @brief Convert uint64 to byte
      /// @param value uint64 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(uint64 value) { return UInt64(value).ToByte(*provider); }

      /// @brief Convert uint64 to byte
      /// @param value uint64 to convert
      /// @return byte A new byte object converted from value
      /// @exception OverflowException value is less than System::Byte::MinValue or greater than System::Byte::MaxValue.
      static byte ToByte(const UInt64& value) { return value.ToByte(*provider); }

      /// @brief Convert T to byte
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static byte ToByte(T value) { return ToByte(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static byte ToByte(llong value) { return Int64((uint64)value).ToByte(*provider); }
      static byte ToByte(ullong value) { return UInt64((uint64)value).ToByte(*provider); }
      template<class T, class Attribute>
      static byte ToByte(const property_<T, Attribute>& value) { return ToByte(value()); }
      /// @endcond

      /// @brief Convert IConvertible object to char32
      /// @param converter IConvertible object to convert
      /// @return char32 A new char32 object converted from converter
      /// @exception OverflowException value is less than System::Char::MinValue or greater than System::Char::MaxValue.
      static char32 ToChar(const IConvertible& converter) {return converter.ToChar(*provider);}

      /// @brief Convert object to char32
      /// @param value object to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(object& value) {return ToChar((const object&)value);}

      /// @brief Convert object to bool
      /// @param value object to convert
      /// @return bool A new bool object converted from value
      static char32 ToChar(const object& value) {
        if (is<Boolean>(value)) return ToChar(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToChar(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToChar(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToChar(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToChar(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToChar(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToChar(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToChar(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToChar(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToChar(static_cast<const Single&>(value));
        if (is<String>(value)) return ToChar(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToChar(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToChar(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToChar(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to char32
      /// @param value object to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(Any& value);

      /// @brief Convert Any to char32
      /// @param value object to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(const Any& value);

      /// @brief Convert bool to char32
      /// @param value bool to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(bool value) { return Boolean(value).ToChar(*provider); }

      /// @brief Convert bool to char32
      /// @param value bool to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(const Boolean& value) { return value.ToChar(*provider); }

      /// @brief Convert byte to char32
      /// @param value byte to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(byte value) { return Byte(value).ToChar(*provider); }

      /// @brief Convert byte to char32
      /// @param value byte to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(const Byte& value) { return value.ToChar(*provider); }

      /// @brief Convert char to char32
      /// @param value char to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(char value) { return value; }

      /// @brief Convert Char to char32
      /// @param value Char to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(char32 value) { return value; }

      /// @brief Convert Char to char32
      /// @param value Char to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(const Char& value) { return value; }

      /// @brief Convert DateTime to char32
      /// @param value DateTime to convert
      /// @return char32 A new char32 object converted from value
      /// @exception OverflowException value is less than System::Char::MinValue or greater than System::Char::MaxValue.
      static char32 ToChar(const DateTime& value);

      /// @brief Convert decimal to char32
      /// @param value decimal to convert
      /// @return char32 A new char32 object converted from value
      /// @exception ArgumentException value is greater than System.char32.MaxValue -or- value is lower than System.char32.MinValue
      /// @exception OverflowException value is less than System::Char::MinValue or greater than System::Char::MaxValue.
      static char32 ToChar(decimal value) { return Decimal(value).ToChar(*provider); }

      /// @brief Convert double to char32
      /// @param value double to convert
      /// @return char32 A new char32 object converted from value
      /// @exception ArgumentException value is greater than System.char32.MaxValue -or- value is lower than System.char32.MinValue
      /// @exception OverflowException value is less than System::Char::MinValue or greater than System::Char::MaxValue.
      static char32 ToChar(double value) { return Double(value).ToChar(*provider); }

      /// @brief Convert double to char32
      /// @param value double to convert
      /// @return char32 A new char32 object converted from value
      /// @exception ArgumentException value is greater than System.char32.MaxValue -or- value is lower than System.char32.MinValue
      /// @exception OverflowException value is less than System::Char::MinValue or greater than System::Char::MaxValue.
      static char32 ToChar(const Double& value) { return value.ToChar(*provider); }

      /// @brief Convert int16 to char32
      /// @param value int16 to convert
      /// @return char32 A new char32 object converted from value
      /// @exception OverflowException value is less than System::Char::MinValue.
      static char32 ToChar(int16 value) { return Int16(value).ToChar(*provider); }

      /// @brief Convert int16 to char32
      /// @param value int16 to convert
      /// @return char32 A new char32 object converted from value
      /// @exception OverflowException value is less than System::Char::MinValue.
      static char32 ToChar(const Int16& value) { return value.ToChar(*provider); }

      /// @brief Convert int32 to char32
      /// @param value int32 to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(int32 value) { return Int32(value).ToChar(*provider); }

      /// @brief Convert int32 to char32
      /// @param value int32 to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(const Int32& value) { return value.ToChar(*provider); }

      /// @brief Convert int64 to char32
      /// @param value int64 to convert
      /// @return char32 A new char32 object converted from value
      /// @exception OverflowException value is less than System::Char::MinValue or greater than System::Char::MaxValue.
      static char32 ToChar(int64 value) { return Int64(value).ToChar(*provider); }

      /// @brief Convert int64 to char32
      /// @param value int64 to convert
      /// @return char32 A new char32 object converted from value
      /// @exception OverflowException value is less than System::Char::MinValue or greater than System::Char::MaxValue.
      static char32 ToChar(const Int64& value) { return value.ToChar(*provider); }

      /// @brief Convert sbyte to char32
      /// @param value sbyte to convert
      /// @return char32 A new char32 object converted from value
      /// @exception OverflowException value is less than System::Char::MinValue.
      static char32 ToChar(sbyte value) { return SByte(value).ToChar(*provider); }

      /// @brief Convert sbyte to char32
      /// @param value sbyte to convert
      /// @return char32 A new char32 object converted from value
      /// @exception OverflowException value is less than System::Char::MinValue.
      static char32 ToChar(const SByte& value) { return value.ToChar(*provider); }

      /// @brief Convert single to char32
      /// @param value single to convert
      /// @return char32 A new char32 object converted from value
      /// @exception OverflowException value is less than System::Char::MinValue or greater than System::Char::MaxValue.
      static char32 ToChar(float value) { return Single(value).ToChar(*provider); }

      /// @brief Convert single to char32
      /// @param value single to convert
      /// @return char32 A new char32 object converted from value
      /// @exception OverflowException value is less than System::Char::MinValue or greater than System::Char::MaxValue.
      static char32 ToChar(const Single& value) { return value.ToChar(*provider); }

      /// @brief Convert string to char32
      /// @param value string to convert
      /// @return char32 A new char32 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      static char32 ToChar(const char* value) { return Char::Parse(value); }

      /// @brief Convert string to char32
      /// @param value string to convert
      /// @return char32 A new char32 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      static char32 ToChar(const string& value) { return Char::Parse(value); }

      /// @brief Convert uint16 to char32
      /// @param value uint16 to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(uint16 value) { return UInt16(value).ToChar(*provider); }

      /// @brief Convert uint16 to char32
      /// @param value uint16 to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(const UInt16& value) { return value.ToChar(*provider); }

      /// @brief Convert uint32 to char32
      /// @param value uint32 to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(uint32 value) { return UInt32(value).ToChar(*provider); }

      /// @brief Convert uint32 to char32
      /// @param value uint32 to convert
      /// @return char32 A new char32 object converted from value
      static char32 ToChar(const UInt32& value) { return value.ToChar(*provider); }

      /// @brief Convert uint64 to char32
      /// @param value uint64 to convert
      /// @return char32 A new char32 object converted from value
      /// @exception OverflowException value is less than System::Char::MinValue or greater than System::Char::MaxValue.
      static char32 ToChar(uint64 value) { return UInt64(value).ToChar(*provider); }

      /// @brief Convert uint64 to char32
      /// @param value uint64 to convert
      /// @return char32 A new char32 object converted from value
      /// @exception OverflowException value is less than System::Char::MinValue or greater than System::Char::MaxValue.
      static char32 ToChar(const UInt64& value) { return value.ToChar(*provider); }

      /// @brief Convert T to char32
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static char32 ToChar(T value) { return ToChar(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static char32 ToChar(llong value) { return Int64((uint64)value).ToChar(*provider); }
      static char32 ToChar(ullong value) { return UInt64((uint64)value).ToChar(*provider); }
      template<class T, class Attribute>
      static char32 ToChar(const property_<T, Attribute>& value) { return ToChar(value()); }
      /// @endcond

      /// @brief Convert IConvertible object to DateTime
      /// @param converter IConvertible object to convert
      /// @return DateTime A new DateTime object converted from converter
      /// @exception OverflowException value is less than System::DateTime::MinValue or greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(const IConvertible& converter);

      /// @brief Convert object to DateTime
      /// @param value object to convert
      /// @return DateTime A new DateTime object converted from value
      static DateTime ToDateTime(object& value);

      /// @brief Convert Any to DateTime
      /// @param value object to convert
      /// @return DateTime A new DateTime object converted from value
      static DateTime ToDateTime(Any& value);

      /// @brief Convert Any to DateTime
      /// @param value object to convert
      /// @return DateTime A new DateTime object converted from value
      static DateTime ToDateTime(const Any& value);

      /// @brief Convert object to DateTime
      /// @param value object to convert
      /// @return DateTime A new DateTime object converted from value
      static DateTime ToDateTime(const object& value);

      /// @brief Convert bool to DateTime
      /// @param value bool to convert
      /// @return DateTime A new DateTime object converted from value
      static DateTime ToDateTime(bool value);

      /// @brief Convert bool to DateTime
      /// @param value bool to convert
      /// @return DateTime A new DateTime object converted from value
      static DateTime ToDateTime(const Boolean& value);

      /// @brief Convert byte to DateTime
      /// @param value byte to convert
      /// @return DateTime A new DateTime object converted from value
      static DateTime ToDateTime(byte value);

      /// @brief Convert byte to DateTime
      /// @param value byte to convert
      /// @return DateTime A new DateTime object converted from value
      static DateTime ToDateTime(const Byte& value);

      /// @brief Convert char to DateTime
      /// @param value char32 to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue.
      static DateTime ToDateTime(char value);

      /// @brief Convert char32 to DateTime
      /// @param value char32 to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue.
      static DateTime ToDateTime(char32 value);

      /// @brief Convert char32 to DateTime
      /// @param value char32 to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue.
      static DateTime ToDateTime(const Char& value);

      /// @brief Convert DateTime to DateTime
      /// @param value DateTime to convert
      /// @return DateTime A new DateTime object converted from value
      static DateTime ToDateTime(const DateTime& value);

      /// @brief Convert decimal to DateTime
      /// @param value decimal to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception ArgumentException value is greater than System.DateTime.MaxValue -or- value is lower than System.DateTime.MinValue
      /// @exception OverflowException value is less than System::DateTime::MinValue or greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(decimal value);

      /// @brief Convert double to DateTime
      /// @param value double to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception ArgumentException value is greater than System.DateTime.MaxValue -or- value is lower than System.DateTime.MinValue
      /// @exception OverflowException value is less than System::DateTime::MinValue or greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(double value);

      /// @brief Convert double to DateTime
      /// @param value double to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception ArgumentException value is greater than System.DateTime.MaxValue -or- value is lower than System.DateTime.MinValue
      /// @exception OverflowException value is less than System::DateTime::MinValue or greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(const Double& value);

      /// @brief Convert int16 to DateTime
      /// @param value int16 to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue.
      static DateTime ToDateTime(int16 value);

      /// @brief Convert int16 to DateTime
      /// @param value int16 to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue.
      static DateTime ToDateTime(const Int16& value);

      /// @brief Convert int32 to DateTime
      /// @param value int32 to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue.
      static DateTime ToDateTime(int32 value);

      /// @brief Convert int32 to DateTime
      /// @param value int32 to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue.
      static DateTime ToDateTime(const Int32& value);

      /// @brief Convert int64 to DateTime
      /// @param value int64 to convert
      /// @return DateTime A new byte object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue or greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(int64 value);

      /// @brief Convert int64 to DateTime
      /// @param value int64 to convert
      /// @return DateTime A new byte object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue or greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(const Int64& value);

      /// @brief Convert sbyte to DateTime
      /// @param value sbyte to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue.
      static DateTime ToDateTime(sbyte value);

      /// @brief Convert sbyte to DateTime
      /// @param value sbyte to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue.
      static DateTime ToDateTime(const SByte& value);

      /// @brief Convert single to DateTime
      /// @param value single to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue or greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(float value);

      /// @brief Convert single to DateTime
      /// @param value single to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is less than System::DateTime::MinValue or greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(const Single& value);

      /// @brief Convert string to DateTime
      /// @param value string to convert
      /// @return DateTime A new byte object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::DateTime::MinValue or greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(const char* value);

      /// @brief Convert string to DateTime
      /// @param value string to convert
      /// @return DateTime A new byte object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::DateTime::MinValue or greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(const string& value);

      /// @brief Convert uint16 to DateTime
      /// @param value uint16 to convert
      /// @return DateTime A new byte object converted from value
      static DateTime ToDateTime(uint16 value);

      /// @brief Convert uint16 to DateTime
      /// @param value uint16 to convert
      /// @return DateTime A new byte object converted from value
      static DateTime ToDateTime(const UInt16& value);

      /// @brief Convert uint32 to DateTime
      /// @param value uint32 to convert
      /// @return DateTime A new DateTime object converted from value
      static DateTime ToDateTime(uint32 value);

      /// @brief Convert uint32 to DateTime
      /// @param value uint32 to convert
      /// @return DateTime A new DateTime object converted from value
      static DateTime ToDateTime(const UInt32& value);

      /// @brief Convert uint64 to DateTime
      /// @param value uint64 to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(uint64 value);

      /// @brief Convert uint64 to DateTime
      /// @param value uint64 to convert
      /// @return DateTime A new DateTime object converted from value
      /// @exception OverflowException value is greater than System::DateTime::MaxValue.
      static DateTime ToDateTime(const UInt64& value);

      /// @brief Convert T to bool
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      /*
       template<typename T>
       static DateTime ToDateTime(T value) { return ToDateTime(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }
       */

      /// @cond
      static DateTime ToDateTime(llong value);
      static DateTime ToDateTime(ullong value);
      template<class T, class Attribute>
      static DateTime ToDateTime(const property_<T, Attribute>& value) { return ToDateTime(value()); }
      /// @endcond

      /// @brief Convert IConvertible object to double
      /// @param converter IConvertible object to convert
      /// @return double A new double object converted from converter
      /// @exception OverflowException value is less than System::Double::MinValue or greater than System::Double::MaxValue.
      static double ToDouble(const IConvertible& converter) {return converter.ToDouble(*provider);}

      /// @brief Convert object to double
      /// @param value object to convert
      /// @return double A new double object converted from value
      static double ToDouble(object& value) {return ToDouble((const object&)value);}

      /// @brief Convert object to double
      /// @param value object to convert
      /// @return double A new double object converted from value
      static double ToDouble(const object& value) {
        if (is<Boolean>(value)) return ToDouble(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToDouble(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToDouble(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToDouble(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToDouble(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToDouble(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToDouble(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToDouble(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToDouble(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToDouble(static_cast<const Single&>(value));
        if (is<String>(value)) return ToDouble(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToDouble(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToDouble(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToDouble(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to double
      /// @param value object to convert
      /// @return double A new double object converted from value
      static double ToDouble(Any& value);

      /// @brief Convert Any to double
      /// @param value object to convert
      /// @return double A new double object converted from value
      static double ToDouble(const Any& value);

      /// @brief Convert bool to double
      /// @param value bool to convert
      /// @return double A new double object converted from value
      static double ToDouble(bool value) { return Boolean(value).ToDouble(*provider); }

      /// @brief Convert bool to double
      /// @param value bool to convert
      /// @return double A new double object converted from value
      static double ToDouble(const Boolean& value) { return value.ToDouble(*provider); }

      /// @brief Convert byte to double
      /// @param value byte to convert
      /// @return double A new double object converted from value
      static double ToDouble(byte value) { return Byte(value).ToDouble(*provider); }

      /// @brief Convert byte to double
      /// @param value byte to convert
      /// @return double A new double object converted from value
      static double ToDouble(const Byte& value) { return value.ToDouble(*provider); }

      /// @brief Convert char to double
      /// @param value char to convert
      /// @return double A new double object converted from value
      static double ToDouble(char value) { return Char(value).ToDouble(*provider); }

      /// @brief Convert Char to double
      /// @param value Char to convert
      /// @return double A new double object converted from value
      static double ToDouble(char32 value) { return Char(value).ToDouble(*provider); }

      /// @brief Convert Char to double
      /// @param value Char to convert
      /// @return double A new double object converted from value
      static double ToDouble(const Char& value) { return value.ToDouble(*provider); }

      /// @brief Convert DateTime to double
      /// @param value DateTime to convert
      /// @return double A new double object converted from value
      static double ToDouble(const DateTime& value);

      /// @brief Convert decimal to double
      /// @param value decimal to convert
      /// @return double A new double object converted from value
      static double ToDouble(decimal value) { return Decimal(value).ToDouble(*provider); }

      /// @brief Convert double to double
      /// @param value double to convert
      /// @return double A new double object converted from value
      static double ToDouble(double value) { return value; }

      /// @brief Convert double to double
      /// @param value double to convert
      /// @return double A new double object converted from value
      static double ToDouble(const Double& value) { return value; }

      /// @brief Convert int16 to double
      /// @param value int16 to convert
      /// @return double A new double object converted from value
      static double ToDouble(int16 value) { return Int16(value).ToDouble(*provider); }

      /// @brief Convert int16 to double
      /// @param value int16 to convert
      /// @return double A new double object converted from value
      static double ToDouble(const Int16& value) { return value.ToDouble(*provider); }

      /// @brief Convert int32 to double
      /// @param value int32 to convert
      /// @return double A new double object converted from value
      static double ToDouble(int32 value) { return Int32(value).ToDouble(*provider); }

      /// @brief Convert int32 to double
      /// @param value int32 to convert
      /// @return double A new double object converted from value
      static double ToDouble(const Int32& value) { return value.ToDouble(*provider); }

      /// @brief Convert int64 to double
      /// @param value int64 to convert
      /// @return double A new double object converted from value
      /// @exception OverflowException value is less than System::Double::MinValue or greater than System::Double::MaxValue.
      static double ToDouble(int64 value) { return Int64(value).ToDouble(*provider); }

      /// @brief Convert int64 to double
      /// @param value int64 to convert
      /// @return double A new double object converted from value
      /// @exception OverflowException value is less than System::Double::MinValue or greater than System::Double::MaxValue.
      static double ToDouble(const Int64& value) { return value.ToDouble(*provider); }

      /// @brief Convert sbyte to double
      /// @param value sbyte to convert
      /// @return double A new double object converted from value
      static double ToDouble(sbyte value) { return SByte(value).ToDouble(*provider); }

      /// @brief Convert sbyte to double
      /// @param value sbyte to convert
      /// @return double A new double object converted from value
      static double ToDouble(const SByte& value) { return value.ToDouble(*provider); }

      /// @brief Convert single to double
      /// @param value single to convert
      /// @return double A new double object converted from value
      static double ToDouble(float value) { return Single(value).ToDouble(*provider); }

      /// @brief Convert single to double
      /// @param value single to convert
      /// @return double A new double object converted from value
      static double ToDouble(const Single& value) { return value.ToDouble(*provider); }

      /// @brief Convert string to double
      /// @param value string to convert
      /// @return double A new double object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is greater than System::Double::MaxValue.
      static double ToDouble(const char* value) { return Double::Parse(value); }

      /// @brief Convert string to double
      /// @param value string to convert
      /// @return double A new double object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is greater than System::Double::MaxValue.
      static double ToDouble(const string& value) { return Double::Parse(value); }

      /// @brief Convert uint16 to double
      /// @param value uint16 to convert
      /// @return double A new double object converted from value
      static double ToDouble(uint16 value) { return UInt16(value).ToDouble(*provider); }

      /// @brief Convert uint16 to double
      /// @param value uint16 to convert
      /// @return double A new double object converted from value
      static double ToDouble(const UInt16& value) { return value.ToDouble(*provider); }

      /// @brief Convert uint32 to double
      /// @param value uint32 to convert
      /// @return double A new double object converted from value
      static double ToDouble(uint32 value) { return UInt32(value).ToDouble(*provider); }

      /// @brief Convert uint32 to double
      /// @param value uint32 to convert
      /// @return double A new double object converted from value
      static double ToDouble(const UInt32& value) { return value.ToDouble(*provider); }

      /// @brief Convert uint64 to double
      /// @param value uint64 to convert
      /// @return double A new double object converted from value
      /// @exception OverflowException value is greater than System::Double::MaxValue.
      static double ToDouble(uint64 value) { return UInt64(value).ToDouble(*provider); }

      /// @brief Convert uint64 to double
      /// @param value uint64 to convert
      /// @return double A new double object converted from value
      /// @exception OverflowException value is greater than System::Double::MaxValue.
      static double ToDouble(const UInt64& value) { return value.ToDouble(*provider); }

      /// @brief Convert T to double
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static double ToDouble(T value) { return ToDouble(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static double ToDouble(llong value) { return Int64((uint64)value).ToDouble(*provider); }
      static double ToDouble(ullong value) { return UInt64((uint64)value).ToDouble(*provider); }
      template<class T, class Attribute>
      static double ToDouble(const property_<T, Attribute>& value) { return ToDouble(value()); }
      /// @endcond

      /// @brief Convert IConvertible object to int16
      /// @param converter IConvertible object to convert
      /// @return int16 A new int16 object converted from converter
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(const IConvertible& converter) {return converter.ToInt16(*provider);}

      /// @brief Convert object to int16
      /// @param value object to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(object& value) {return ToInt16((const object&)value);}

      /// @brief Convert object to int16
      /// @param value object to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(const object& value) {
        if (is<Boolean>(value)) return ToInt16(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToInt16(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToInt16(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToInt16(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToInt16(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToInt16(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToInt16(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToInt16(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToInt16(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToInt16(static_cast<const Single&>(value));
        if (is<String>(value)) return ToInt16(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToInt16(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToInt16(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToInt16(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to int16
      /// @param value object to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(Any& value);

      /// @brief Convert Any to int16
      /// @param value object to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(const Any& value);

      /// @brief Convert bool to int16
      /// @param value bool to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(bool value) { return Boolean(value).ToInt16(*provider); }

      /// @brief Convert bool to int16
      /// @param value bool to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(const Boolean& value) { return value.ToInt16(*provider); }

      /// @brief Convert byte to int16
      /// @param value byte to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(byte value) { return Byte(value).ToInt16(*provider); }

      /// @brief Convert byte to int16
      /// @param value byte to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(const Byte& value) { return value.ToInt16(*provider); }

      /// @brief Convert char to int16
      /// @param value char to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(char value) { return Char(value).ToInt16(*provider); }

      /// @brief Convert Char to int16
      /// @param value Char to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(char32 value) { return Char(value).ToInt16(*provider); }

      /// @brief Convert Char to int16
      /// @param value Char to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(const Char& value) { return value.ToInt16(*provider); }

      /// @brief Convert DateTime to int16
      /// @param value DateTime to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(const DateTime& value);

      /// @brief Convert decimal to int16
      /// @param value decimal to convert
      /// @return* int16 A new int16 object converted from value
      /// @exception ArgumentException value is greater than System.int16.MaxValue -or- mValue_d is lower than System.int16.MinValue
      static int16 ToInt16(decimal value) { return Decimal(value).ToInt16(*provider); }

      /// @brief Convert double to int16
      /// @param value double to convert
      /// @return* int16 A new int16 object converted from value
      /// @exception ArgumentException value is greater than System.int16.MaxValue -or- mValue_d is lower than System.int16.MinValue
      static int16 ToInt16(double value) { return Double(value).ToInt16(*provider); }

      /// @brief Convert double to int16
      /// @param value int16 to convert
      /// @return* int16 A new int16 object converted from value
      /// @exception ArgumentException value is greater than System.int16.MaxValue -or- mValue_d is lower than System.int16.MinValue
      static int16 ToInt16(const Double& value) { return value.ToInt16(*provider); }

      /// @brief Convert int16 to int16
      /// @param value int16 to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(int16 value) { return value; }

      /// @brief Convert int16 to int16
      /// @param value int16 to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(const Int16& value) { return value; }

      /// @brief Convert int32 to int16
      /// @param value int32 to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(int32 value) { return Int32(value).ToInt16(*provider); }

      /// @brief Convert int32 to int16
      /// @param value int32 to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(const Int32& value) { return value.ToInt16(*provider); }

      /// @brief Convert int64 to int16
      /// @param value int64 to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(int64 value) { return Int64(value).ToInt16(*provider); }

      /// @brief Convert int64 to int16
      /// @param value int64 to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(const Int64& value) { return value.ToInt16(*provider); }

      /// @brief Convert void* to int16
      /// @param value void* to convert

      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(void* value) { return Int32(IntPtr((intptr)value).ToInt32()).ToInt16(*provider); }

      /// @brief Convert void* to int16
      /// @param value void* to convert
      /// @return int16 A new int16 object converted from value

      static int16 ToInt16(const IntPtr& value) { return Int32(value.ToInt32()).ToInt16(*provider); }

      /// @brief Convert sbyte to int16
      /// @param value sbyte to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(sbyte value) { return SByte(value).ToInt16(*provider); }

      /// @brief Convert sbyte to int16
      /// @param value sbyte to convert
      /// @return int16 A new int16 object converted from value
      static int16 ToInt16(const SByte& value) { return value.ToInt16(*provider); }

      /// @brief Convert single to int16
      /// @param value single to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(float value) { return Single(value).ToInt16(*provider); }

      /// @brief Convert single to int16
      /// @param value single to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(const Single& value) { return value.ToInt16(*provider); }

      /// @brief Convert string to int16
      /// @param value string to convert
      /// @return int16 A new int16 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(const char* value) { return Int16::Parse(value); }

      /// @brief Convert string to int16
      /// @param value string to convert
      /// @return int16 A new int16 object converted from value
      /// @param base The base of number to parse
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(const char* value, int32 base) { return Int16::Parse(value, base); }

      /// @brief Convert string to int16
      /// @param value string to convert
      /// @return int16 A new int16 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(const string& value) { return Int16::Parse(value); }

      /// @brief Convert string to int16
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return int16 A new int16 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int16::MinValue or greater than System::Int16::MaxValue.
      static int16 ToInt16(const string& value, int32 base) { return Int16::Parse(value, base); }

      /// @brief Convert uint16 to int16
      /// @param value uint16 to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is greater than System::Int16::MaxValue.
      static int16 ToInt16(uint16 value) { return UInt16(value).ToInt16(*provider); }

      /// @brief Convert uint16 to int16
      /// @param value uint16 to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is greater than System::Int16::MaxValue.
      static int16 ToInt16(const UInt16& value) { return value.ToInt16(*provider); }

      /// @brief Convert uint32 to int16
      /// @param value uint32 to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is greater than System::Int16::MaxValue.
      static int16 ToInt16(uint32 value) { return UInt32(value).ToInt16(*provider); }

      /// @brief Convert uint32 to int16
      /// @param value uint32 to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is greater than System::Int16::MaxValue.
      static int16 ToInt16(const UInt32& value) { return value.ToInt16(*provider); }

      /// @brief Convert uint64 to int16
      /// @param value uint64 to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is greater than System::Int16::MaxValue.
      static int16 ToInt16(uint64 value) { return UInt64(value).ToInt16(*provider); }

      /// @brief Convert uint64 to int16
      /// @param value uint64 to convert
      /// @return int16 A new int16 object converted from value
      /// @exception OverflowException value is greater than System::Int16::MaxValue.
      static int16 ToInt16(const UInt64& value) { return value.ToInt16(*provider); }

      /// @brief Convert T to int16
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static int16 ToInt16(T value) { return ToInt16(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static int16 ToInt16(llong value) { return Int64((uint64)value).ToInt16(*provider); }
      static int16 ToInt16(ullong value) { return UInt64((uint64)value).ToInt16(*provider); }
      template<class T, class Attribute>
      static int16 ToInt16(const property_<T, Attribute>& value) { return ToInt16(value()); }
      /// @endcond

      /// @brief Convert IConvertible object to int32
      /// @param converter IConvertible object to convert
      /// @return int32 A new int32 object converted from converter
      /// @exception OverflowException value is less than System::Int32::MinValue or greater than System::Int32::MaxValue.
      static int32 ToInt32(const IConvertible& converter) {return converter.ToInt32(*provider);}

      /// @brief Convert object to int32
      /// @param value object to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(object& value) {return ToInt32((const object&)value);}

      /// @brief Convert object to int32
      /// @param value object to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(const object& value) {
        if (is<Boolean>(value)) return ToInt32(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToInt32(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToInt32(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToInt32(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToInt32(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToInt32(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToInt32(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToInt32(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToInt32(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToInt32(static_cast<const Single&>(value));
        if (is<String>(value)) return ToInt32(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToInt32(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToInt32(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToInt32(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to int32
      /// @param value object to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(Any& value);

      /// @brief Convert Any to int32
      /// @param value object to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(const Any& value);

      /// @brief Convert bool to int32
      /// @param value bool to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(bool value) { return Boolean(value).ToInt32(*provider); }

      /// @brief Convert bool to int32
      /// @param value bool to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(const Boolean& value) { return value.ToInt32(*provider); }

      /// @brief Convert byte to int32
      /// @param value byte to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(byte value) { return Byte(value).ToInt32(*provider); }

      /// @brief Convert byte to int32
      /// @param value byte to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(const Byte& value) { return value.ToInt32(*provider); }

      /// @brief Convert char to int32
      /// @param value char to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(char value) { return Char(value).ToInt32(*provider); }

      /// @brief Convert Char to int32
      /// @param value Char to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(char32 value) { return Char(value).ToInt32(*provider); }

      /// @brief Convert Char to int32
      /// @param value Char to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(const Char& value) { return value.ToInt32(*provider); }

      /// @brief Convert DateTime to int32
      /// @param value DateTime to convert
      /// @return int32 A new int32 object converted from value
      /// @exception OverflowException value is less than System::Int32::MinValue or greater than System::Int32::MaxValue.
      static int32 ToInt32(const DateTime& value);

      /// @brief Convert decimal to int32
      /// @param value decimal to convert
      /// @return int32 A new int32 object converted from value
      /// @exception OverflowException value is less than System::Int32::MinValue or greater than System::Int32::MaxValue.
      static int32 ToInt32(decimal value) { return Decimal(value).ToInt32(*provider); }

      /// @brief Convert double to int32
      /// @param value double to convert
      /// @return int32 A new int32 object converted from value
      /// @exception OverflowException value is less than System::Int32::MinValue or greater than System::Int32::MaxValue.
      static int32 ToInt32(double value) { return Double(value).ToInt32(*provider); }

      /// @brief Convert double to int32
      /// @param value double to convert
      /// @return int32 A new int32 object converted from value
      /// @exception OverflowException value is less than System::Int32::MinValue or greater than System::Int32::MaxValue.
      static int32 ToInt32(const Double& value) { return value.ToInt32(*provider); }

      /// @brief Convert int16 to int32
      /// @param value int16 to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(int16 value) { return Int16(value).ToInt32(*provider); }

      /// @brief Convert int16 to int32
      /// @param value int16 to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(const Int16& value) { return value.ToInt32(*provider); }

      /// @brief Convert int32 to int32
      /// @param value int32 to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(int32 value) { return value; }

      /// @brief Convert int32 to int32
      /// @param value int32 to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(const Int32& value) { return value; }

      /// @brief Convert int64 to int32
      /// @param value int64 to convert
      /// @return int32 A new int32 object converted from value
      /// @exception OverflowException value is less than System::Int32::MinValue or greater than System::Int32::MaxValue.
      static int32 ToInt32(int64 value) { return Int64(value).ToInt32(*provider); }

      /// @brief Convert int64 to int32
      /// @param value int64 to convert
      /// @return int32 A new int32 object converted from value
      /// @exception OverflowException value is less than System::Int32::MinValue or greater than System::Int32::MaxValue.
      static int32 ToInt32(const Int64& value) { return value.ToInt32(*provider); }

      /// @brief Convert void* to int64
      /// @param value void* to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(void* value) { return IntPtr((intptr)value).ToInt32(); }

      /// @brief Convert void* to int64
      /// @param value void* to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(const IntPtr& value) { return value.ToInt32(); }

      /// @brief Convert sbyte to int32
      /// @param value sbyte to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(sbyte value) { return SByte(value).ToInt32(*provider); }

      /// @brief Convert sbyte to int32
      /// @param value sbyte to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(const SByte& value) { return value.ToInt32(*provider); }

      /// @brief Convert single to int32
      /// @param value single to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(float value) { return Single(value).ToInt32(*provider); }

      /// @brief Convert single to int32
      /// @param value single to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(const Single& value) { return value.ToInt32(*provider); }

      /// @brief Convert string to int32
      /// @param value string to convert
      /// @return int32 A new int32 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int32::MinValue or greater than System::Int32::MaxValue.
      static int32 ToInt32(const char* value) { return Int32::Parse(value); }

      /// @brief Convert string to int32
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return int32 A new int32 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int32::MinValue or greater than System::Int32::MaxValue.
      static int32 ToInt32(const char* value, int32 base) { return Int32::Parse(value, base); }

      /// @brief Convert string to int32
      /// @param value string to convert
      /// @return int32 A new int32 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int32::MinValue or greater than System::Int32::MaxValue.
      static int32 ToInt32(const string& value) { return Int32::Parse(value); }

      /// @brief Convert string to int32
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return int32 A new int32 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int32::MinValue or greater than System::Int32::MaxValue.
      static int32 ToInt32(const string& value, int32 base) { return Int32::Parse(value, base); }

      /// @brief Convert uint16 to int32
      /// @param value uint16 to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(uint16 value) { return UInt16(value).ToInt32(*provider); }

      /// @brief Convert uint16 to int32
      /// @param value uint16 to convert
      /// @return int32 A new int32 object converted from value
      static int32 ToInt32(const UInt16& value) { return value.ToInt32(*provider); }

      /// @brief Convert uint32 to int32
      /// @param value uint32 to convert
      /// @return int32 A new int32 object converted from value
      /// @exception OverflowException value is greater than System::Int32::MaxValue.
      static int32 ToInt32(uint32 value) { return UInt32(value).ToInt32(*provider); }

      /// @brief Convert uint32 to int32
      /// @param value uint32 to convert
      /// @return int32 A new int32 object converted from value
      /// @exception OverflowException value is greater than System::Int32::MaxValue.
      static int32 ToInt32(const UInt32& value) { return value.ToInt32(*provider); }

      /// @brief Convert uint64 to int32
      /// @param value uint64 to convert
      /// @return int32 A new int32 object converted from value
      /// @exception OverflowException value is greater than System::Int32::MaxValue.
      static int32 ToInt32(uint64 value) { return UInt64(value).ToInt32(*provider); }

      /// @brief Convert uint64 to int32
      /// @param value uint64 to convert
      /// @return int32 A new int32 object converted from value
      /// @exception OverflowException value is greater than System::Int32::MaxValue.
      static int32 ToInt32(const UInt64& value) { return value.ToInt32(*provider); }

      /// @brief Convert T to int32
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static int32 ToInt32(T value) { return ToInt32(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static int32 ToInt32(llong value) { return Int64(value).ToInt32(*provider); }
      static int32 ToInt32(ullong value) { return UInt64(value).ToInt32(*provider); }
      template<class T, class Attribute>
      static int32 ToInt32(const property_<T, Attribute>& value) { return ToInt32(value()); }
      /// @endcond

      /// @brief Convert IConvertible object to int64
      /// @param converter IConvertible object to convert
      /// @return int64 A new int64 object converted from converter
      /// @exception OverflowException value is less than System::Int64::MinValue or greater than System::Int64::MaxValue.
      static int64 ToInt64(const IConvertible& converter) {return converter.ToInt64(*provider);}

      /// @brief Convert object to int64
      /// @param value object to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(object& value) {return ToInt64((const object&)value);}

      /// @brief Convert object to int64
      /// @param value object to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const object& value) {
        if (is<Boolean>(value)) return ToInt64(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToInt64(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToInt64(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToInt64(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToInt64(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToInt64(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToInt64(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToInt64(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToInt64(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToInt64(static_cast<const Single&>(value));
        if (is<String>(value)) return ToInt64(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToInt64(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToInt64(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToInt64(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to int64
      /// @param value object to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(Any& value);

      /// @brief Convert Any to int64
      /// @param value object to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const Any& value);

      /// @brief Convert bool to int64
      /// @param value bool to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(bool value) { return Boolean(value).ToInt64(*provider); }

      /// @brief Convert bool to int64
      /// @param value bool to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const Boolean& value) { return value.ToInt64(*provider); }

      /// @brief Convert byte to int64
      /// @param value byte to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(byte value) { return Byte(value).ToInt64(*provider); }

      /// @brief Convert byte to int64
      /// @param value byte to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const Byte& value) { return value.ToInt64(*provider); }

      /// @brief Convert char to int64
      /// @param value char to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(char value) { return Char(value).ToInt64(*provider); }

      /// @brief Convert Char to int64
      /// @param value Char to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(char32 value) { return Char(value).ToInt64(*provider); }

      /// @brief Convert Char to int64
      /// @param value Char to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const Char& value) { return value.ToInt64(*provider); }

      /// @brief Convert DateTime to int64
      /// @param value DateTime to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const DateTime& value);

      /// @brief Convert decimal to int64
      /// @param value decimal to convert
      /// @return int64 A new int64 object converted from value
      /// @exception ArgumentException value is greater than System.int64.MaxValue -or- value is lower than System.int64.MinValue
      static int64 ToInt64(decimal value) { return Decimal(value).ToInt64(*provider); }

      /// @brief Convert double to int64
      /// @param value double to convert
      /// @return int64 A new int64 object converted from value
      /// @exception ArgumentException value is greater than System.Int64.MaxValue -or- value is lower than System.int64.MinValue
      static int64 ToInt64(double value) { return Double(value).ToInt64(*provider); }

      /// @brief Convert double to int64
      /// @param value double to convert
      /// @return int64 A new int64 object converted from value
      /// @exception ArgumentException value is greater than System.int64.MaxValue -or- value is lower than System.int64.MinValue
      static int64 ToInt64(const Double& value) { return value.ToInt64(*provider); }

      /// @brief Convert int16 to int64
      /// @param value int16 to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(int16 value) { return Int16(value).ToInt64(*provider); }

      /// @brief Convert int16 to int64
      /// @param value int16 to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const Int16& value) { return value.ToInt64(*provider); }

      /// @brief Convert int32 to int64
      /// @param value int32 to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(int32 value) { return Int32(value).ToInt64(*provider); }

      /// @brief Convert int32 to int64
      /// @param value int32 to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const Int32& value) { return value.ToInt64(*provider); }

      /// @brief Convert int64 to int64
      /// @param value int64 to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(int64 value) { return value; }

      /// @brief Convert int64 to int64
      /// @param value int64 to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const Int64& value) { return value; }

      /// @brief Convert void* to int64
      /// @param value void* to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(void* value) { return IntPtr((intptr)value).ToInt64(); }

      /// @brief Convert void* to int64
      /// @param value void* to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const IntPtr& value) { return value.ToInt64(); }

      /// @brief Convert sbyte to int64
      /// @param value sbyte to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(sbyte value) { return SByte(value).ToInt64(*provider); }

      /// @brief Convert sbyte to int64
      /// @param value sbyte to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const SByte& value) { return value.ToInt64(*provider); }

      /// @brief Convert single to int64
      /// @param value single to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(float value) { return Single(value).ToInt64(*provider); }

      /// @brief Convert single to int64
      /// @param value single to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const Single& value) { return value.ToInt64(*provider); }

      /// @brief Convert string to int64
      /// @param value string to convert
      /// @return int64 A new int64 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int64::MinValue or greater than System::Int64::MaxValue.
      static int64 ToInt64(const char* value) { return Int64::Parse(value); }

      /// @brief Convert string to int64
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return int64 A new int64 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int64::MinValue or greater than System::Int64::MaxValue.
      static int64 ToInt64(const char* value, int32 base) { return Int64::Parse(value, base); }

      /// @brief Convert string to int64
      /// @param value string to convert
      /// @return int64 A new int64 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int64::MinValue or greater than System::Int64::MaxValue.
      static int64 ToInt64(const string& value) { return Int64::Parse(value); }

      /// @brief Convert string to int64
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return int64 A new int64 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Int64::MinValue or greater than System::Int64::MaxValue.
      static int64 ToInt64(const string& value, int32 base) { return Int64::Parse(value, base); }

      /// @brief Convert uint16 to int64
      /// @param value uint16 to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(uint16 value) { return UInt16(value).ToInt64(*provider); }

      /// @brief Convert uint16 to int64
      /// @param value uint16 to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const UInt16& value) { return value.ToInt64(*provider); }

      /// @brief Convert uint32 to int64
      /// @param value uint32 to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(uint32 value) { return UInt32(value).ToInt64(*provider); }

      /// @brief Convert uint32 to int64
      /// @param value uint32 to convert
      /// @return int64 A new int64 object converted from value
      static int64 ToInt64(const UInt32& value) { return value.ToInt64(*provider); }

      /// @brief Convert uint64 to int64
      /// @param value uint64 to convert
      /// @return int64 A new int64 object converted from value
      /// @exception OverflowException value is greater than System::Int64::MaxValue.
      static int64 ToInt64(uint64 value) { return UInt64(value).ToInt64(*provider); }

      /// @brief Convert uint64 to int64
      /// @param value uint64 to convert
      /// @return int64 A new int64 object converted from value
      /// @exception OverflowException value is greater than System::Int64::MaxValue.
      static int64 ToInt64(const UInt64& value) { return value.ToInt64(*provider); }

      /// @brief Convert T to int64
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static int64 ToInt64(T value) { return ToInt64(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static int64 ToInt64(llong value) { return Int64(value).ToInt64(*provider); }
      static int64 ToInt64(ullong value) { return UInt64(value).ToInt64(*provider); }
      template<class T, class Attribute>
      static int64 ToInt64(const property_<T, Attribute>& value) { return ToInt64(value()); }
      /// @endcond

      /// @brief Convert int32 to void*
      /// @param value int32 to convert
      /// @return void* A new void* object converted from value
      static const void* ToIntPtr(int32 value) {
        return reinterpret_cast<const char*>(static_cast<int64>(value));
      }

      /// @brief Convert int64 to void*
      /// @param value int64 to convert
      /// @return void* A new void* object converted from value
      static const void* ToIntPtr(int64 value) {
        size_t size = 4;
        if (sizeof(void*) == size && (value < Int32::MinValue || value > Int32::MaxValue))
          throw OverflowException(caller_);

        return reinterpret_cast<void*>(value);
      }

      /// @brief Convert T to void*
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static const void* ToIntPtr(T value) {throw ArgumentException(caller_);}

      /// @brief Convert IConvertible object to sbyte
      /// @param converter IConvertible object to convert
      /// @return sbyte A new sbyte object converted from converter
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const IConvertible& converter) {return converter.ToSByte(*provider);}

      /// @brief Convert object to sbyte
      /// @param value object to convert
      /// @return sbyte A new sbyte object converted from value
      static sbyte ToSByte(object& value) {return ToSByte((const object&)value);}

      /// @brief Convert object to sbyte
      /// @param value object to convert
      /// @return sbyte A new sbyte object converted from value
      static sbyte ToSByte(const object& value) {
        if (is<Boolean>(value)) return ToSByte(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToSByte(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToSByte(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToSByte(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToSByte(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToSByte(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToSByte(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToSByte(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToSByte(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToSByte(static_cast<const Single&>(value));
        if (is<String>(value)) return ToSByte(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToSByte(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToSByte(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToSByte(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to sbyte
      /// @param value object to convert
      /// @return sbyte A new sbyte object converted from value
      static sbyte ToSByte(Any& value);

      /// @brief Convert Any to sbyte
      /// @param value object to convert
      /// @return sbyte A new sbyte object converted from value
      static sbyte ToSByte(const Any& value);

      /// @brief Convert bool to sbyte
      /// @param value bool to convert
      /// @return sbyte A new sbyte object converted from value
      static sbyte ToSByte(bool value) { return Boolean(value).ToSByte(*provider); }

      /// @brief Convert bool to sbyte
      /// @param value bool to convert
      /// @return sbyte A new sbyte object converted from value
      static sbyte ToSByte(const Boolean& value) { return value.ToSByte(*provider); }

      /// @brief Convert byte to sbyte
      /// @param value byte to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is greater than System::SByte::MaxValue.
      static sbyte ToSByte(byte value) { return Byte(value).ToSByte(*provider); }

      /// @brief Convert byte to sbyte
      /// @param value byte to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is greater than System::SByte::MaxValue.
      static sbyte ToSByte(const Byte& value) { return value.ToSByte(*provider); }

      /// @brief Convert Char to sbyte
      /// @param value Char to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(char value) { return Char(value).ToSByte(*provider); }

      /// @brief Convert Char to sbyte
      /// @param value Char to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(char32 value) { return Char(value).ToSByte(*provider); }

      /// @brief Convert Char to sbyte
      /// @param value Char to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const Char& value) { return value.ToSByte(*provider); }

      /// @brief Convert DateTime to sbyte
      /// @param value DateTime to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const DateTime& value);

      /// @brief Convert decimal to sbyte
      /// @param value decimal to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(decimal value) { return Decimal(value).ToSByte(*provider); }

      /// @brief Convert double to sbyte
      /// @param value double to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(double value) { return Double(value).ToSByte(*provider); }

      /// @brief Convert double to sbyte
      /// @param value double to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const Double& value) { return value.ToSByte(*provider); }

      /// @brief Convert int16 to sbyte
      /// @param value int16 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(int16 value) { return Int16(value).ToSByte(*provider); }

      /// @brief Convert int16 to sbyte
      /// @param value int16 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const Int16& value) { return value.ToSByte(*provider); }

      /// @brief Convert int32 to sbyte
      /// @param value int32 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(int32 value) { return Int32(value).ToSByte(*provider); }

      /// @brief Convert int32 to sbyte
      /// @param value int32 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const Int32& value) { return value.ToSByte(*provider); }

      /// @brief Convert int64 to sbyte
      /// @param value int64 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(int64 value) { return Int64(value).ToSByte(*provider); }

      /// @brief Convert int64 to sbyte
      /// @param value int64 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const Int64& value) { return value.ToSByte(*provider); }

      /// @brief Convert sbyte to sbyte
      /// @param value sbyte to convert
      /// @return sbyte A new sbyte object converted from value
      static sbyte ToSByte(sbyte value) { return value; }

      /// @brief Convert sbyte to sbyte
      /// @param value sbyte to convert
      /// @return sbyte A new sbyte object converted from value
      static sbyte ToSByte(const SByte& value) { return value; }

      /// @brief Convert single to sbyte
      /// @param value single to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(float value) { return Single(value).ToSByte(*provider); }

      /// @brief Convert single to sbyte
      /// @param value single to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const Single& value) { return value.ToSByte(*provider); }

      /// @brief Convert string to sbyte
      /// @param value string to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const char* value) { return SByte::Parse(value); }

      /// @brief Convert string to sbyte
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return sbyte A new sbyte object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const char* value, int32 base) { return SByte::Parse(value, base); }

      /// @brief Convert string to sbyte
      /// @param value string to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const string& value) { return SByte::Parse(value); }

      /// @brief Convert string to sbyte
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return sbyte A new sbyte object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::SByte::MinValue or greater than System::SByte::MaxValue.
      static sbyte ToSByte(const string& value, int32 base) { return SByte::Parse(value, base); }

      /// @brief Convert uint16 to sbyte
      /// @param value uint16 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is greater than System::SByte::MaxValue.
      static sbyte ToSByte(uint16 value) { return UInt16(value).ToSByte(*provider); }

      /// @brief Convert uint16 to sbyte
      /// @param value uint16 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is greater than System::SByte::MaxValue.
      static sbyte ToSByte(const UInt16& value) { return value.ToSByte(*provider); }

      /// @brief Convert uint32 to sbyte
      /// @param value uint32 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is greater than System::SByte::MaxValue.
      static sbyte ToSByte(uint32 value) { return UInt32(value).ToSByte(*provider); }

      /// @brief Convert uint32 to sbyte
      /// @param value uint32 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is greater than System::SByte::MaxValue.
      static sbyte ToSByte(const UInt32& value) { return value.ToSByte(*provider); }

      /// @brief Convert uint64 to sbyte
      /// @param value uint64 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is greater than System::SByte::MaxValue.
      static sbyte ToSByte(uint64 value) { return UInt64(value).ToSByte(*provider); }

      /// @brief Convert uint64 to sbyte
      /// @param value uint64 to convert
      /// @return sbyte A new sbyte object converted from value
      /// @exception OverflowException value is greater than System::SByte::MaxValue.
      static sbyte ToSByte(const UInt64& value) { return value.ToSByte(*provider); }

      /// @brief Convert T to sbyte
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static sbyte ToSByte(T value) { return ToSByte(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static sbyte ToSByte(llong value) { return Int64(value).ToSByte(*provider); }
      static sbyte ToSByte(ullong value) { return UInt64(value).ToSByte(*provider); }
      template<class T, class Attribute>
      static sbyte ToSByte(const property_<T, Attribute>& value) { return ToSByte(value()); }
      /// @endcond

      /// @brief Convert IConvertible object to single
      /// @param converter IConvertible object to convert
      /// @return single A new single object converted from converter
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(const IConvertible& converter) {return converter.ToSingle(*provider);}

      /// @brief Convert object to float
      /// @param value object to convert
      /// @return float A new float object converted from value
      static float ToSingle(object& value) {return ToSingle((const object&)value);}

      /// @brief Convert object to float
      /// @param value object to convert
      /// @return float A new float object converted from value
      static float ToSingle(const object& value) {
        if (is<Boolean>(value)) return ToSingle(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToSingle(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToSingle(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToSingle(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToSingle(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToSingle(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToSingle(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToSingle(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToSingle(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToSingle(static_cast<const Single&>(value));
        if (is<String>(value)) return ToSingle(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToSingle(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToSingle(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToSingle(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to float
      /// @param value object to convert
      /// @return float A new float object converted from value
      static float ToSingle(Any& value);

      /// @brief Convert Any to float
      /// @param value object to convert
      /// @return float A new float object converted from value
      static float ToSingle(const Any& value);

      /// @brief Convert bool to single
      /// @param value bool to convert
      /// @return single A new single object converted from value
      static float ToSingle(bool value) { return Boolean(value).ToSingle(*provider); }

      /// @brief Convert bool to single
      /// @param value bool to convert
      /// @return single A new single object converted from value
      static float ToSingle(const Boolean& value) { return value.ToSingle(*provider); }

      /// @brief Convert byte to single
      /// @param value byte to convert
      /// @return single A new single object converted from value
      static float ToSingle(byte value) { return Byte(value).ToSingle(*provider); }

      /// @brief Convert byte to single
      /// @param value byte to convert
      /// @return single A new single object converted from value
      static float ToSingle(const Byte& value) { return value.ToSingle(*provider); }

      /// @brief Convert Char to single
      /// @param value Char to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(char value) { return Char(value).ToSingle(*provider); }

      /// @brief Convert Char to single
      /// @param value Char to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(char32 value) { return Char(value).ToSingle(*provider); }

      /// @brief Convert Char to single
      /// @param value Char to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(const Char& value) { return value.ToSingle(*provider); }

      /// @brief Convert DateTime to single
      /// @param value DateTime to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(const DateTime& value);

      /// @brief Convert decimal to single
      /// @param value decimal to convert
      /// @return single A new single object converted from value
      /// @exception ArgumentException value is greater than System.single.MaxValue -or- value is lower than System.single.MinValue
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(decimal value) { return Decimal(value).ToSingle(*provider); }

      /// @brief Convert double to single
      /// @param value double to convert
      /// @return single A new single object converted from value
      /// @exception ArgumentException value is greater than System.single.MaxValue -or- value is lower than System.single.MinValue
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(double value) { return Double(value).ToSingle(*provider); }

      /// @brief Convert double to single
      /// @param value double to convert
      /// @return single A new single object converted from value
      /// @exception ArgumentException value is greater than System.single.MaxValue -or- value is lower than System.single.MinValue
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(const Double& value) { return value.ToSingle(*provider); }

      /// @brief Convert int16 to single
      /// @param value int16 to convert
      /// @return single A new single object converted from value
      static float ToSingle(int16 value) { return Int16(value).ToSingle(*provider); }

      /// @brief Convert int16 to single
      /// @param value int16 to convert
      /// @return single A new single object converted from value
      static float ToSingle(const Int16& value) { return value.ToSingle(*provider); }

      /// @brief Convert int32 to single
      /// @param value int32 to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(int32 value) { return Int32(value).ToSingle(*provider); }

      /// @brief Convert int32 to single
      /// @param value int32 to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(const Int32& value) { return value.ToSingle(*provider); }

      /// @brief Convert int64 to single
      /// @param value int64 to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(int64 value) { return Int64(value).ToSingle(*provider); }

      /// @brief Convert int64 to single
      /// @param value int64 to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(const Int64& value) { return value.ToSingle(*provider); }

      /// @brief Convert sbyte to single
      /// @param value sbyte to convert
      /// @return single A new single object converted from value
      static float ToSingle(sbyte value) { return SByte(value).ToSingle(*provider); }

      /// @brief Convert sbyte to single
      /// @param value sbyte to convert
      /// @return single A new single object converted from value
      static float ToSingle(const SByte& value) { return value.ToSingle(*provider); }

      /// @brief Convert single to single
      /// @param value single to convert
      /// @return single A new single object converted from value
      static float ToSingle(float value) { return value; }

      /// @brief Convert single to single
      /// @param value single to convert
      /// @return single A new single object converted from value
      static float ToSingle(const Single& value) { return value; }

      /// @brief Convert string to single
      /// @param value string to convert
      /// @return single A new single object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(const char* value) { return Single::Parse(value); }

      /// @brief Convert string to single
      /// @param value string to convert
      /// @return single A new single object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      static float ToSingle(const string& value) { return Single::Parse(value); }

      /// @brief Convert uint16 to single
      /// @param value uint16 to convert
      /// @return single A new single object converted from value
      static float ToSingle(uint16 value) { return UInt16(value).ToSingle(*provider); }

      /// @brief Convert uint16 to single
      /// @param value uint16 to convert
      /// @return single A new single object converted from value
      static float ToSingle(const UInt16& value) { return value.ToSingle(*provider); }

      /// @brief Convert uint32 to single
      /// @param value uint32 to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is greater than System::Single::MaxValue.
      static float ToSingle(uint32 value) { return UInt32(value).ToSingle(*provider); }

      /// @brief Convert uint32 to single
      /// @param value uint32 to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is greater than System::Single::MaxValue.
      static float ToSingle(const UInt32& value) { return value.ToSingle(*provider); }

      /// @brief Convert uint64 to single
      /// @param value uint64 to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      /// @exception OverflowException value is greater than System::Single::MaxValue.
      static float ToSingle(uint64 value) { return UInt64(value).ToSingle(*provider); }

      /// @brief Convert uint64 to single
      /// @param value uint64 to convert
      /// @return single A new single object converted from value
      /// @exception OverflowException value is less than System::Single::MinValue or greater than System::Single::MaxValue.
      /// @exception OverflowException value is greater than System::Single::MaxValue.
      static float ToSingle(const UInt64& value) { return value.ToSingle(*provider); }

      /// @brief Convert T to single
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static float ToSingle(T value) { return ToSingle(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static float ToSingle(llong value) { return Int64(value).ToSingle(*provider); }
      static float ToSingle(ullong value) { return UInt64(value).ToSingle(*provider); }
      template<class T, class Attribute>
      static float ToSingle(const property_<T, Attribute>& value) { return ToSingle(value()); }
      /// @endcond

      /// @brief Convert an object to string
      /// @param The object to convert
      /// @return string A new string object converted from converter
      static string ToString(object& obj) {return obj.ToString();}

      /// @brief Convert an object to string
      /// @param The object to convert
      /// @return string A new string object converted from converter
      static string ToString(const object& obj) {return obj.ToString();}

      /// @brief Convert a pointer to string (hexadecimal value of the memory address)
      /// @param The object to convert
      /// @return string A new string object converted from converter
      static string ToString(const void* a) { return string::Format("0x{0:X}", a); }

      /// @brief Convert a bool to string
      /// @param The value to convert
      /// @return string A new string object converted from converter
      static string ToString(NullPtr) { return "(null)"; }

      template<typename T>
      static string ToString(refptr<T> value) { return value.ToString().c_str(); }

      template<typename T>
      static string ToString(ref<T> value) { return value.ToString().c_str(); }

      /// @brief Convert bool to string
      /// @param value bool to convert
      /// @return string A new string object converted from value
      static string ToString(bool value) { return Boolean(value).ToString(*provider); }

      /// @brief Convert bool to string
      /// @param value bool to convert
      /// @return string A new string object converted from value
      static string ToString(const Boolean& value) { return value.ToString(*provider); }

      /// @brief Convert byte to string
      /// @param value byte to convert
      /// @return string A new string object converted from value
      static string ToString(byte value) { return Byte(value).ToString(*provider); }

      /// @brief Convert byte to string
      /// @param value byte to convert
      /// @return string A new string object converted from value
      static string ToString(const Byte& value) { return value.ToString(*provider); }

      /// @brief Convert a bool to string
      /// @param value char to convert
      /// @return string A new string object converted from converter
      /// @exception ArgumentNullException The parameters converter is null.
      static string ToString(char value) { return Char(value).ToString(); }

      /// @brief Convert Char to string
      /// @param value Char to convert
      /// @return string A new string object converted from value
      static string ToString(char32 value) { return Char(value).ToString(*provider); }

      /// @brief Convert Char to string
      /// @param value Char to convert
      /// @return string A new string object converted from value
      static string ToString(const Char& value) { return value.ToString(*provider); }

      /// @brief Convert DateTime to string
      /// @param value DateTime to convert
      /// @return string A new string object converted from value
      static string ToString(const DateTime& value);

      /// @brief Convert decimal to string
      /// @param value decimal to convert
      /// @return string A new string object converted from value
      static string ToString(decimal value) { return Decimal(value).ToString(*provider); }

      /// @brief Convert double to string
      /// @param value double to convert
      /// @return string A new string object converted from value
      static string ToString(double value) { return Double(value).ToString(*provider); }

      /// @brief Convert double to string
      /// @param value double to convert
      /// @return string A new string object converted from value
      static string ToString(const Double& value) { return value.ToString(*provider); }

      /// @brief Convert int16 to string
      /// @param value int16 to convert
      /// @return string A new string object converted from value
      static string ToString(int16 value) { return Int16(value).ToString(*provider); }

      /// @brief Convert int16 to string
      /// @param value int16 to convert
      /// @return string A new string object converted from value
      static string ToString(const Int16& value) { return value.ToString(*provider); }

      /// @brief Convert int32 to string
      /// @param value int32 to convert
      /// @return string A new string object converted from value
      static string ToString(int32 value) { return Int32(value).ToString(*provider); }

      /// @brief Convert int32 to string
      /// @param value int32 to convert
      /// @return string A new string object converted from value
      static string ToString(const Int32& value) { return value.ToString(*provider); }

      /// @brief Convert int64 to string
      /// @param value int64 to convert
      /// @return string A new string object converted from value
      static string ToString(int64 value) { return Int64(value).ToString(*provider); }

      /// @brief Convert int64 to string
      /// @param value int64 to convert
      /// @return string A new string object converted from value
      static string ToString(const Int64& value) { return value.ToString(*provider); }

      /// @brief Convert sbyte to string
      /// @param value sbyte to convert
      /// @return string A new string object converted from value
      static string ToString(sbyte value) { return SByte(value).ToString(*provider); }

      /// @brief Convert sbyte to string
      /// @param value sbyte to convert
      /// @return string A new string object converted from value
      static string ToString(const SByte& value) { return value.ToString(*provider); }

      /// @brief Convert single to string
      /// @param value single to convert
      /// @return string A new string object converted from value
      static string ToString(float value) { return Single(value).ToString(*provider); }

      /// @brief Convert single to string
      /// @param value single to convert
      /// @return string A new string object converted from value
      static string ToString(const Single& value) { return value.ToString(*provider); }

      /// @brief Convert string to string
      /// @param value string to convert
      /// @return string A new string object converted from value
      static string ToString(const char* value) { return String(value); }

      /// @brief Convert string to string
      /// @param value string to convert
      /// @return string A new string object converted from value
      static string ToString(const string& value) { return value; }

      /// @brief Convert uint16 to string
      /// @param value uint16 to convert
      /// @return string A new string object converted from value
      static string ToString(uint16 value) { return UInt16(value).ToString(*provider); }

      /// @brief Convert uint16 to string
      /// @param value uint16 to convert
      /// @return string A new string object converted from value
      static string ToString(const UInt16& value) { return value.ToString(*provider); }

      /// @brief Convert uint32 to string
      /// @param value uint32 to convert
      /// @return string A new string object converted from value
      static string ToString(uint32 value) { return UInt32(value).ToString(*provider); }

      /// @brief Convert uint32 to string
      /// @param value uint32 to convert
      /// @return string A new string object converted from value
      static string ToString(const UInt32& value) { return value.ToString(*provider); }

      /// @brief Convert uint64 to string
      /// @param value uint64 to convert
      /// @return string A new string object converted from value
      static string ToString(uint64 value) { return UInt64(value).ToString(*provider); }

      /// @brief Convert uint64 to string
      /// @param value uint64 to convert
      /// @return string A new string object converted from value
      static string ToString(const UInt64& value) { return value.ToString(*provider); }

      static string ToString(byte value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(const Byte& value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(int16 value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(const Int16& value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(int32 value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(const Int32& value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(int64 value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(const Int64& value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(sbyte value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(const SByte& value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(uint16 value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(const UInt16& value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(uint32 value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(const UInt32& value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(uint64 value, int32 base) { return ToStringTemplate(value, base); }

      static string ToString(const UInt64& value, int32 base) { return ToStringTemplate(value, base); }

      /// @brief Convert T to string
      /// @param value T to convert
      /// Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      /*
       template<typename T>
       static string ToString(T value) { return ToString(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }
       */

      /// @cond
      static string ToString(llong value) { return Int64(value).ToString(*provider); }
      static string ToString(ullong value) { return UInt64(value).ToString(*provider); }
      template<class T, class Attribute>
      static string ToString(const property_<T, Attribute>& value) { return ToString(value()); }
      /// @endcond

      /// @brief Convert IConvertible object to uint16
      /// @param converter IConvertible object to convert
      /// @return uint16 A new uint16 object converted from converter
      /// @exception OverflowException value is less than System::UInt16::MinValue or greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(const IConvertible& converter) {return converter.ToUInt16(*provider);}

      /// @brief Convert object to uint16
      /// @param value object to convert
      /// @return uint16 A new uint16 object converted from value
      static uint16 ToUInt16(object& value) {return ToUInt16((const object&)value);}

      /// @brief Convert object to uint16
      /// @param value object to convert
      /// @return uint16 A new uint16 object converted from value
      static uint16 ToUInt16(const object& value) {
        if (is<Boolean>(value)) return ToUInt16(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToUInt16(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToUInt16(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToUInt16(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToUInt16(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToUInt16(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToUInt16(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToUInt16(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToUInt16(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToUInt16(static_cast<const Single&>(value));
        if (is<String>(value)) return ToUInt16(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToUInt16(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToUInt16(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToUInt16(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to uint16
      /// @param value object to convert
      /// @return uint16 A new uint16 object converted from value
      static uint16 ToUInt16(Any& value);

      /// @brief Convert Any to uint16
      /// @param value object to convert
      /// @return uint16 A new uint16 object converted from value
      static uint16 ToUInt16(const Any& value);

      /// @brief Convert bool to uint16
      /// @param value bool to convert
      /// @return uint16 A new uint16 object converted from value
      static uint16 ToUInt16(bool value) { return Boolean(value).ToUInt16(*provider); }

      /// @brief Convert byte to uint16
      /// @param value byte to convert
      /// @return uint16 A new uint16 object converted from value
      static uint16 ToUInt16(byte value) { return Byte(value).ToUInt16(*provider); }

      /// @brief Convert char to uint16
      /// @param value char to convert
      /// @return uint16 A new uint16 object converted from value
      static uint16 ToUInt16(char value) { return Char(value).ToUInt16(*provider); }

      /// @brief Convert char32 to uint16
      /// @param value char32 to convert
      /// @return uint16 A new uint16 object converted from value
      static uint16 ToUInt16(char32 value) { return Char(value).ToUInt16(*provider); }

      /// @brief Convert Char to uint16
      /// @param value Char to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception OverflowException value is greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(Char value) { return value.ToUInt16(*provider); }

      /// @brief Convert DateTime to uint16
      /// @param value DateTime to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception OverflowException value is less than System::UInt16::MinValue.
      static uint16 ToUInt16(const DateTime& value);

      /// @brief Convert decimal to uint16
      /// @param value decimal to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception ArgumentException value is greater than System.uint16.MaxValue -or- value is lower than System.uint16.MinValue
      /// @exception OverflowException value is less than System::UInt16::MinValue or greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(decimal value) { return Decimal(value).ToUInt16(*provider); }

      /// @brief Convert double to uint16
      /// @param value double to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception ArgumentException value is greater than System.uint16.MaxValue -or- value is lower than System.uint16.MinValue
      /// @exception OverflowException value is less than System::UInt16::MinValue or greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(double value) { return Double(value).ToUInt16(*provider); }

      /// @brief Convert int16 to uint16
      /// @param value int16 to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception OverflowException value is less than System::UInt16::MinValue.
      static uint16 ToUInt16(int16 value) { return Int16(value).ToUInt16(*provider); }

      /// @brief Convert int32 to uint16
      /// @param value int32 to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception OverflowException value is less than System::UInt16::MinValue or greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(int32 value) { return Int32(value).ToUInt16(*provider); }

      /// @brief Convert int64 to uint16
      /// @param value int64 to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception OverflowException value is less than System::UInt16::MinValue or greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(int64 value) { return Int64(value).ToUInt16(*provider); }

      /// @brief Convert sbyte to uint16
      /// @param value sbyte to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception OverflowException value is less than System::UInt16::MinValue.
      static uint16 ToUInt16(sbyte value) { return SByte(value).ToUInt16(*provider); }

      /// @brief Convert single to uint16
      /// @param value single to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception OverflowException value is less than System::UInt16::MinValue or greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(float value) { return Single(value).ToUInt16(*provider); }

      /// @brief Convert string to uint16
      /// @param value string to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt16::MinValue or greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(const char* value) { return UInt16::Parse(value); }

      /// @brief Convert string to uint16
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return uint16 A new uint16 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt16::MinValue or greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(const char* value, int32 base) { return UInt16::Parse(value, base); }

      /// @brief Convert string to uint16
      /// @param value string to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt16::MinValue or greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(const string& value) { return UInt16::Parse(value); }

      /// @brief Convert string to uint16
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return uint16 A new uint16 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt16::MinValue or greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(const string& value, int32 base) { return UInt16::Parse(value, base); }

      /// @brief Convert uint16 to uint16
      /// @param value uint16 to convert
      /// @return uint16 A new uint16 object converted from value
      static uint16 ToUInt16(uint16 value) { return value; }

      /// @brief Convert uint32 to uint16
      /// @param value uint32 to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception OverflowException value is greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(uint32 value) { return UInt32(value).ToUInt16(*provider); }

      /// @brief Convert uint64 to uint16
      /// @param value uint64 to convert
      /// @return uint16 A new uint16 object converted from value
      /// @exception OverflowException value is greater than System::UInt16::MaxValue.
      static uint16 ToUInt16(uint64 value) { return UInt64(value).ToUInt16(*provider); }

      /// @brief Convert T to uint16
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static uint16 ToUInt16(T value) { return ToUInt16(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static uint16 ToUInt16(llong value) { return Int64(value).ToUInt16(*provider); }
      static uint16 ToUInt16(ullong value) { return UInt64(value).ToUInt16(*provider); }
      template<class T, class Attribute>
      static uint16 ToUInt16(const property_<T, Attribute>& value) { return ToUInt16(value()); }
      /// @endcond

      /// @brief Convert IConvertible object to uint32
      /// @param converter IConvertible object to convert
      /// @return uint32 A new uint32 object converted from converter
      /// @exception OverflowException value is less than System::UInt32::MinValue or greater than System::UInt32::MaxValue.
      static uint32 ToUInt32(const IConvertible& converter) {return converter.ToUInt32(*provider);}

      /// @brief Convert object to uint32
      /// @param value object to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(object& value) {return ToUInt32((const object&)value);}

      /// @brief Convert object to uint32
      /// @param value object to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(const object& value) {
        if (is<Boolean>(value)) return ToUInt32(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToUInt32(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToUInt32(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToUInt32(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToUInt32(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToUInt32(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToUInt32(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToUInt32(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToUInt32(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToUInt32(static_cast<const Single&>(value));
        if (is<String>(value)) return ToUInt32(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToUInt32(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToUInt32(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToUInt32(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to uint32
      /// @param value object to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(Any& value);

      /// @brief Convert Any to uint32
      /// @param value object to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(const Any& value);

      /// @brief Convert bool to uint32
      /// @param value bool to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(bool value) { return Boolean(value).ToUInt32(*provider); }

      /// @brief Convert bool to uint32
      /// @param value bool to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(const Boolean& value) { return value.ToUInt32(*provider); }

      /// @brief Convert byte to uint32
      /// @param value byte to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(byte value) { return Byte(value).ToUInt32(*provider); }

      /// @brief Convert byte to uint32
      /// @param value byte to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(const Byte& value) { return value.ToUInt32(*provider); }

      /// @brief Convert char to uint32
      /// @param value char to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(char value) { return Char(value).ToUInt32(*provider); }

      /// @brief Convert Char to uint32
      /// @param value Char to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(char32 value) { return Char(value).ToUInt32(*provider); }

      /// @brief Convert Char to uint32
      /// @param value Char to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(const Char& value) { return value.ToUInt32(*provider); }

      /// @brief Convert DateTime to uint32
      /// @param value DateTime to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is less than System::UInt32::MinValue.
      static uint32 ToUInt32(const DateTime& value);

      /// @brief Convert decimal to uint32
      /// @param value decimal to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception ArgumentException value is greater than System.uint32.MaxValue -or- value is lower than System.uint32.MinValue
      static uint32 ToUInt32(decimal value) { return Decimal(value).ToUInt32(*provider); }

      /// @brief Convert double to uint32
      /// @param value double to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception ArgumentException value is greater than System.uint32.MaxValue -or- value is lower than System.uint32.MinValue
      static uint32 ToUInt32(double value) { return Double(value).ToUInt32(*provider); }

      /// @brief Convert double to uint32
      /// @param value double to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception ArgumentException value is greater than System.uint32.MaxValue -or- value is lower than System.uint32.MinValue
      static uint32 ToUInt32(const Double& value) { return value.ToUInt32(*provider); }

      /// @brief Convert int16 to uint32
      /// @param value int16 to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is less than System::UInt32::MinValue.
      static uint32 ToUInt32(int16 value) { return Int16(value).ToUInt32(*provider); }

      /// @brief Convert int16 to uint32
      /// @param value int16 to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is less than System::UInt32::MinValue.
      static uint32 ToUInt32(const Int16& value) { return value.ToUInt32(*provider); }

      /// @brief Convert int32 to uint32
      /// @param value int32 to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is less than System::UInt32::MinValue.
      static uint32 ToUInt32(int32 value) { return Int32(value).ToUInt32(*provider); }

      /// @brief Convert int32 to uint32
      /// @param value int32 to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is less than System::UInt32::MinValue.
      static uint32 ToUInt32(const Int32& value) { return value.ToUInt32(*provider); }

      /// @brief Convert int64 to uint32
      /// @param value int64 to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is less than System::UInt32::MinValue or greater than System::UInt32::MaxValue.
      static uint32 ToUInt32(int64 value) { return Int64(value).ToUInt32(*provider); }

      /// @brief Convert int64 to uint32
      /// @param value int64 to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is less than System::UInt32::MinValue or greater than System::UInt32::MaxValue.
      static uint32 ToUInt32(const Int64& value) { return value.ToUInt32(*provider); }

      /// @brief Convert sbyte to uint32
      /// @param value sbyte to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is less than System::UInt32::MinValue.
      static uint32 ToUInt32(sbyte value) { return SByte(value).ToUInt32(*provider); }

      /// @brief Convert sbyte to uint32
      /// @param value sbyte to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is less than System::UInt32::MinValue.
      static uint32 ToUInt32(const SByte& value) { return value.ToUInt32(*provider); }

      /// @brief Convert single to uint32
      /// @param value single to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is less than System::UInt32::MinValue.
      static uint32 ToUInt32(float value) { return Single(value).ToUInt32(*provider); }

      /// @brief Convert single to uint32
      /// @param value single to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is less than System::UInt32::MinValue.
      static uint32 ToUInt32(const Single& value) { return value.ToUInt32(*provider); }

      /// @brief Convert string to uint32
      /// @param value string to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt32::MinValue or greater than System::UInt32::MaxValue.
      static uint32 ToUInt32(const char* value) { return UInt32::Parse(value); }

      /// @brief Convert string to uint32
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return uint32 A new uint32 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt32::MinValue or greater than System::UInt32::MaxValue.
      static uint32 ToUInt32(const char* value, int32 base) { return UInt32::Parse(value, base); }

      /// @brief Convert string to uint32
      /// @param value string to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt32::MinValue or greater than System::UInt32::MaxValue.
      static uint32 ToUInt32(const string& value) { return UInt32::Parse(value); }

      /// @brief Convert string to uint32
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return uint32 A new uint32 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt32::MinValue or greater than System::UInt32::MaxValue.
      static uint32 ToUInt32(const string& value, int32 base) { return UInt32::Parse(value, base); }

      /// @brief Convert uint16 to uint32
      /// @param value uint16 to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(uint16 value) { return UInt16(value).ToUInt32(*provider); }

      /// @brief Convert uint16 to uint32
      /// @param value uint16 to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(const UInt16& value) { return value.ToUInt32(*provider); }

      /// @brief Convert uint32 to uint32
      /// @param value uint32 to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(uint32 value) { return value; }

      /// @brief Convert uint32 to uint32
      /// @param value uint32 to convert
      /// @return uint32 A new uint32 object converted from value
      static uint32 ToUInt32(const UInt32& value) { return value; }

      /// @brief Convert uint64 to uint32
      /// @param value uint64 to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is greater than System::UInt32::MaxValue.
      static uint32 ToUInt32(uint64 value) { return UInt64(value).ToUInt32(*provider); }

      /// @brief Convert uint64 to uint32
      /// @param value uint64 to convert
      /// @return uint32 A new uint32 object converted from value
      /// @exception OverflowException value is greater than System::UInt32::MaxValue.
      static uint32 ToUInt32(const UInt64& value) { return value.ToUInt32(*provider); }

      /// @brief Convert T to uint32
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static uint32 ToUInt32(T value) { return ToUInt32(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static uint32 ToUInt32(llong value) { return Int64(value).ToUInt32(*provider); }
      static uint32 ToUInt32(ullong value) { return UInt64(value).ToUInt32(*provider); }
      template<class T, class Attribute>
      static uint32 ToUInt32(const property_<T, Attribute>& value) { return ToUInt32(value()); }
      /// @endcond

      /// @brief Convert IConvertible object to uint64
      /// @param converter IConvertible object to convert
      /// @return uint64 A new uint64 object converted from converter
      /// @exception OverflowException value is less than System::UInt64::MinValue or greater than System::UInt64::MaxValue.
      static uint64 ToUInt64(const IConvertible& converter) {return converter.ToUInt64(*provider);}

      /// @brief Convert object to uint64
      /// @param value object to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(object& value) {return ToUInt64((const object&)value);}

      /// @brief Convert object to uint64
      /// @param value object to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(const object& value) {
        if (is<Boolean>(value)) return ToUInt64(static_cast<const Boolean&>(value));
        if (is<Byte>(value)) return ToUInt64(static_cast<const Byte&>(value));
        if (is<Char>(value)) return ToUInt64(static_cast<const Char&>(value));
        if (is<DateTime>(value)) return ToUInt64(static_cast<const DateTime&>(value));
        if (is<Double>(value)) return ToUInt64(static_cast<const Double&>(value));
        if (is<Int16>(value)) return ToUInt64(static_cast<const Int16&>(value));
        if (is<Int32>(value)) return ToUInt64(static_cast<const Int32&>(value));
        if (is<Int64>(value)) return ToUInt64(static_cast<const Int64&>(value));
        if (is<SByte>(value)) return ToUInt64(static_cast<const SByte&>(value));
        if (is<Single>(value)) return ToUInt64(static_cast<const Single&>(value));
        if (is<String>(value)) return ToUInt64(static_cast<const String&>(value));
        if (is<UInt16>(value)) return ToUInt64(static_cast<const UInt16&>(value));
        if (is<UInt32>(value)) return ToUInt64(static_cast<const UInt32&>(value));
        if (is<UInt64>(value)) return ToUInt64(static_cast<const UInt64&>(value));
        throw InvalidCastException(caller_);
      }

      /// @brief Convert Any to uint64
      /// @param value object to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(Any& value);

      /// @brief Convert Any to uint64
      /// @param value object to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(const Any& value);

      /// @brief Convert bool to uint64
      /// @param value bool to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(bool value) { return Boolean(value).ToUInt64(*provider); }

      /// @brief Convert bool to uint64
      /// @param value bool to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(const Boolean& value) { return value.ToUInt64(*provider); }

      /// @brief Convert byte to uint64
      /// @param value byte to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(byte value) { return Byte(value).ToUInt64(*provider); }

      /// @brief Convert byte to uint64
      /// @param value byte to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(const Byte& value) { return value.ToUInt64(*provider); }

      /// @brief Convert char to uint64
      /// @param value char to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(char value) { return Char(value).ToUInt64(*provider); }

      /// @brief Convert Char to uint64
      /// @param value Char to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(char32 value) { return Char(value).ToUInt64(*provider); }

      /// @brief Convert Char to uint64
      /// @param value Char to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(const Char& value) { return value.ToUInt64(*provider); }

      /// @brief Convert DateTime to uint64
      /// @param value DateTime to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(const DateTime& value);

      /// @brief Convert decimal to uint64
      /// @param value decimal to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception ArgumentException value is greater than System.uint64.MaxValue -or- value is lower than System.uint64.MinValue
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(decimal value) { return Decimal(value).ToUInt64(*provider); }

      /// @brief Convert double to uint64
      /// @param value double to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception ArgumentException value is greater than System.uint64.MaxValue -or- value is lower than System.uint64.MinValue
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(double value) { return Double(value).ToUInt64(*provider); }

      /// @brief Convert double to uint64
      /// @param value double to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception ArgumentException value is greater than System.uint64.MaxValue -or- value is lower than System.uint64.MinValue
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(const Double& value) { return value.ToUInt64(*provider); }

      /// @brief Convert int16 to uint64
      /// @param value int16 to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(int16 value) { return Int16(value).ToUInt64(*provider); }

      /// @brief Convert int16 to uint64
      /// @param value int16 to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(const Int16& value) { return value.ToUInt64(*provider); }

      /// @brief Convert int32 to uint64
      /// @param value int32 to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(int32 value) { return Int32(value).ToUInt64(*provider); }

      /// @brief Convert int32 to uint64
      /// @param value int32 to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(const Int32& value) { return value.ToUInt64(*provider); }

      /// @brief Convert int64 to uint64
      /// @param value int64 to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(int64 value) { return Int64(value).ToUInt64(*provider); }

      /// @brief Convert int64 to uint64
      /// @param value int64 to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(const Int64& value) { return value.ToUInt64(*provider); }

      /// @brief Convert sbyte to uint64
      /// @param value sbyte to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(sbyte value) { return SByte(value).ToUInt64(*provider); }

      /// @brief Convert sbyte to uint64
      /// @param value sbyte to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(const SByte& value) { return value.ToUInt64(*provider); }

      /// @brief Convert single to uint64
      /// @param value single to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(float value) { return Single(value).ToUInt64(*provider); }

      /// @brief Convert single to uint64
      /// @param value single to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception OverflowException value is less than System::UInt64::MinValue.
      static uint64 ToUInt64(const Single& value) { return value.ToUInt64(*provider); }

      /// @brief Convert string to uint64
      /// @param value string to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt64::MinValue or greater than System::UInt64::MaxValue.
      static uint64 ToUInt64(const char* value) { return UInt64::Parse(value); }

      /// @brief Convert string to uint64
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return uint64 A new uint64 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt64::MinValue or greater than System::UInt64::MaxValue.
      static uint64 ToUInt64(const char* value, int32 base) { return UInt64::Parse(value, base); }

      /// @brief Convert string to uint64
      /// @param value string to convert
      /// @return uint64 A new uint64 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt64::MinValue or greater than System::UInt64::MaxValue.
      static uint64 ToUInt64(const string& value) { return UInt64::Parse(value); }

      /// @brief Convert string to uint64
      /// @param value string to convert
      /// @param base The base of number to parse
      /// @return uint64 A new uint64 object converted from value
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception OverflowException value is less than System::UInt64::MinValue or greater than System::UInt64::MaxValue.
      static uint64 ToUInt64(const string& value, int32 base) { return UInt64::Parse(value, base); }

      /// @brief Convert uint16 to uint64
      /// @param value uint16 to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(uint16 value) { return UInt16(value).ToUInt64(*provider); }

      /// @brief Convert uint16 to uint64
      /// @param value uint16 to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(const UInt16& value) { return value.ToUInt64(*provider); }

      /// @brief Convert uint32 to uint64
      /// @param value uint32 to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(uint32 value) { return UInt32(value).ToUInt64(*provider); }

      /// @brief Convert uint32 to uint64
      /// @param value uint32 to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(const UInt32& value) { return UInt32(value).ToUInt64(*provider); }

      /// @brief Convert uint64 to uint64
      /// @param value uint64 to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(const UInt64& value) { return value; }

      /// @brief Convert uint64 to uint64
      /// @param value uint64 to convert
      /// @return uint64 A new uint64 object converted from value
      static uint64 ToUInt64(uint64 value) { return value; }

      /// @brief Convert T to uint64
      /// @param value T to convert
      /// @remarks Always throw ArgumentException
      /// @exception ArgumentException value is not convertible.
      template<typename T>
      static uint64 ToUInt64(T value) { return ToUInt64(CastToUnderlyingTypeIfEnumClass<T, typename std::conditional_t<std::is_enum<T>::value, std::true_type, std::false_type>::type>::Cast(value)); }

      /// @cond
      static uint64 ToUInt64(llong value) { return Int64(value).ToUInt64(*provider); }
      static uint64 ToUInt64(ullong value) { return UInt64(value).ToUInt64(*provider); }
      template<class T, class Attribute>
      static uint64 ToUInt64(const property_<T, Attribute>& value) { return ToUInt64(value()); }
      /// @endcond

    private:
      template <typename T, typename C>
      struct CastToUnderlyingTypeIfEnumClass {
        static int32 Cast(T value) {
          throw InvalidCastException(caller_);
        }
      };

      template <typename T>
      struct CastToUnderlyingTypeIfEnumClass<T, std::true_type> {
        static typename std::underlying_type<T>::type Cast(T value) {
          return static_cast<typename std::underlying_type<T>::type>(value);
        }
      };

      template<typename T>
      static string ToStringTemplate(T value, int32 base) {
        if (base == 2)
          return string::Format("{0:b}", value);

        if (base == 8) {
          std::stringstream ss;
          ss << std::oct << value;
          return ss.str();
        }

        if (base == 10)
          return string::Format("{0:d}", value);

        if (base == 16)
          return string::Format("{0:x}", value);

        throw ArgumentException(caller_);
      }

      static IFormatProvider* provider;
    };
  }

  /// @cond
  template<typename TT> inline TT as(bool value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(bool value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(bool value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(bool value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(bool value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(bool value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(bool value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(bool value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(bool value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(bool value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(bool value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(bool value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(bool value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(bool value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(bool value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(byte value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(byte value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(byte value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(byte value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(byte value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(byte value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(byte value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(byte value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(byte value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(byte value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(byte value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(byte value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(byte value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(byte value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(byte value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(char32 value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(char32 value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(char32 value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(char32 value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(char32 value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(char32 value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(char32 value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(char32 value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(char32 value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(char32 value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(char32 value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(char32 value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(char32 value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(char32 value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(char32 value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(double value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(double value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(double value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(double value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(double value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(double value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(double value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(double value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(double value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(double value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(double value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(double value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(double value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(double value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(double value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(int16 value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(int16 value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(int16 value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(int16 value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(int16 value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(int16 value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(int16 value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(int16 value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(int16 value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(int16 value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(int16 value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(int16 value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(int16 value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(int16 value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(int16 value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(int32 value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(int32 value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(int32 value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(int32 value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(int32 value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(int32 value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(int32 value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(int32 value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(int32 value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(int32 value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(int32 value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(int32 value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(int32 value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(int32 value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(int32 value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(int64 value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(int64 value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(int64 value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(int64 value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(int64 value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(int64 value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(int64 value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(int64 value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(int64 value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(int64 value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(int64 value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(int64 value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(int64 value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(int64 value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(int64 value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(sbyte value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(sbyte value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(sbyte value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(sbyte value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(sbyte value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(sbyte value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(sbyte value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(sbyte value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(sbyte value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(sbyte value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(sbyte value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(sbyte value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(sbyte value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(sbyte value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(sbyte value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(float value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(float value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(float value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(float value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(float value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(float value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(float value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(float value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(float value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(float value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(float value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(float value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(float value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(float value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(float value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(uint16 value) {return as<TT, uint16>(value);}
  template<> inline bool as<bool>(uint16 value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(uint16 value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(uint16 value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(uint16 value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(uint16 value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(uint16 value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(uint16 value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(uint16 value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(uint16 value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(uint16 value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(uint16 value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(uint16 value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(uint16 value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(uint16 value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(uint32 value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(uint32 value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(uint32 value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(uint32 value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(uint32 value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(uint32 value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(uint32 value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(uint32 value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(uint32 value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(uint32 value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(uint32 value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(uint32 value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(uint32 value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(uint32 value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(uint32 value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(uint64 value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(uint64 value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(uint64 value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(uint64 value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(uint64 value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(uint64 value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(uint64 value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(uint64 value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(uint64 value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(uint64 value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(uint64 value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(uint64 value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(uint64 value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(uint64 value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(uint64 value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(llong value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(llong value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(llong value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(llong value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(llong value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(llong value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(llong value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(llong value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(llong value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(llong value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(llong value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(llong value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(llong value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(llong value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(llong value) {return System::Convert::ToUInt64(value);}

  template<typename TT> inline TT as(ullong value) {return static_cast<TT>(value);}
  template<> inline bool as<bool>(ullong value) {return System::Convert::ToBoolean(value);}
  template<> inline byte as<byte>(ullong value) {return System::Convert::ToByte(value);}
  template<> inline char32 as<char32>(ullong value) {return System::Convert::ToChar(value);}
  template<> inline System::DateTime as<System::DateTime>(ullong value) {return System::Convert::ToDateTime(value);}
  template<> inline double as<double>(ullong value) {return System::Convert::ToDouble(value);}
  template<> inline int16 as<int16>(ullong value) {return System::Convert::ToInt16(value);}
  template<> inline int32 as<int32>(ullong value) {return System::Convert::ToInt32(value);}
  template<> inline int64 as<int64>(ullong value) {return System::Convert::ToInt64(value);}
  template<> inline sbyte as<sbyte>(ullong value) {return System::Convert::ToSByte(value);}
  template<> inline float as<float>(ullong value) {return System::Convert::ToSingle(value);}
  template<> inline string as<string>(ullong value) {return System::Convert::ToString(value);}
  template<> inline uint16 as<uint16>(ullong value) {return System::Convert::ToUInt16(value);}
  template<> inline uint32 as<uint32>(ullong value) {return System::Convert::ToUInt32(value);}
  template<> inline uint64 as<uint64>(ullong value) {return System::Convert::ToUInt64(value);}
  /// @endcond
}

#include "../LiteralOperatorConverter.hpp"

using namespace Switch;
