/// @file
/// @brief Contains Switch::System::Text::StringBuilder class.
#pragma once

#include <codecvt>
#include <locale>
#include "../Array.hpp"
#include "../Byte.hpp"
#include "../Char.hpp"
#include "../Decimal.hpp"
#include "../Double.hpp"
#include "../Environment.hpp"
#include "../Int16.hpp"
#include "../Int32.hpp"
#include "../Int64.hpp"
#include "../Object.hpp"
#include "../SByte.hpp"
#include "../Single.hpp"
#include "../SystemException.hpp"
#include "../UInt16.hpp"
#include "../UInt32.hpp"
#include "../UInt64.hpp"
#include "../_String.hpp"

namespace Switch {
  namespace System {
    namespace Text {
      /// @brief Represents a mutable string of characters. This class cannot be inherited.
      /// @remarks This class represents a string-like object whose value is a mutable sequence of characters.
      class core_export_ StringBuilder final : public Object {
        #if defined(_WIN32)
        using __char32 = __int32;
        #else
        using __char32 = char32;
        #endif
      public:
        /// @brief Initializes a new instance of the System::Text::StringBuilder class.
        ///
        /// The following example demonstrates how to call the StringBuilder constructor with no parameters.
        /// @code
        /// StringBuilder stringBuilder;
        /// @endcode
        StringBuilder() {this->string.reserve(16);}

        /// @cond
        StringBuilder(const StringBuilder& sb) : string(sb.string) {this->string.reserve(sb.string.capacity());}

        StringBuilder& operator=(const StringBuilder& sb) {
          this->string = sb.string;
          this->string.reserve(sb.string.capacity());
          return *this;
        }

        StringBuilder(const char* value) : string((const char32*)std::wstring_convert<std::codecvt_utf8<__char32>, __char32>().from_bytes(String(value).Data()).c_str()) {this->string.reserve(16);}
        StringBuilder(const char16* value) : string((const char32*)std::wstring_convert<std::codecvt_utf8<__char32>, __char32>().from_bytes(String(value).Data()).c_str()) {this->string.reserve(16);}
        StringBuilder(const char32* value) : string((const char32*)std::wstring_convert<std::codecvt_utf8<__char32>, __char32>().from_bytes(String(value).Data()).c_str()) {this->string.reserve(16);}
        StringBuilder(const wchar* value) : string((const char32*)std::wstring_convert<std::codecvt_utf8<__char32>, __char32>().from_bytes(String(value).Data()).c_str()) {this->string.reserve(16);}
        /// @endcond

        /// @brief Initializes a new instance of the StringBuilder class using the specified capacity.
        /// @param capacity The suggested starting size of this instance.
        /// @exception ArguemntOutOfRangeException capacity is less than zero.
        /// @par Examples
        /// The following example demonstrates how to call the StringBuilder constructor with a specified capacity.
        /// @code
        /// int capacity = 255;
        /// StringBuilder stringBuilder(capacity);
        /// @endcode
        explicit StringBuilder(int32 capacity) {
          if (capacity < 0)
            throw ArgumentOutOfRangeException(caller_);
          this->string.reserve(capacity);
        }

        /// @brief Initializes a new instance of the StringBuilder class that starts with a specified capacity and can grow to a specified maximum.
        /// @param capacity The suggested starting size of this instance.
        /// @param maxCapacity The maximum number of characters the current string can contain.
        /// @exception ArguemntOutOfRangeException maxCapacity is less than one, capacity is less than zero, or capacity is greater than maxCapacity.
        /// @par Examples
        /// The following example demonstrates how to call the StringBuilder constructor with a specified capacity and maximum capacity.
        /// @code
        /// int capacity = 255;
        /// int maxCapacity = 1024
        /// StringBuilder stringBuilder(capacity, maxCapacity);
        /// @endcode
        StringBuilder(int32 capacity, int32 maxCapacity) : maxCapacity(maxCapacity) {
          if (maxCapacity < 1 || capacity < 0 || maxCapacity < capacity)
            throw ArgumentOutOfRangeException(caller_);
          this->string.reserve(capacity);
        }

        /// @brief Initializes a new instance of the System::Text::StringBuilder class using the specified string.
        /// @param value The string used to initialize the value of the instance.
        /// @par Examples
        /// The following example demonstrates how to call the StringBuilder constructor with the specified string.
        /// @code
        /// string initialString = "Initial string.";
        /// StringBuilder stringBuilder(initialString);
        /// @endcode
        StringBuilder(const String& value) : string((const char32*)std::wstring_convert<std::codecvt_utf8<__char32>, __char32>().from_bytes(value.Data()).c_str()) {this->string.reserve(16);}

        /// @brief Initializes a new instance of the StringBuilder class using the specified string and capacity.
        /// @param value The string used to initialize the value of the instance.
        /// @param capacity The suggested starting size of this instance.
        /// @exception ArguemntOutOfRangeException capacity is less than zero.
        /// @par Examples
        /// The following example demonstrates how to call the StringBuilder constructor with the specified string and capacity.
        /// @code
        /// string initialString = "Initial string.";
        /// int capacity = 255;
        /// StringBuilder stringBuilder(initialString, capacity);
        /// @endcode
        StringBuilder(const String& value, int32 capacity) : string((const char32*)std::wstring_convert<std::codecvt_utf8<__char32>, __char32>().from_bytes(value.Data()).c_str()) {
          if (capacity < 0)
            throw ArgumentOutOfRangeException(caller_);
          this->string.reserve(capacity);
        }

        /// @brief Initializes a new instance of the System::Text::StringBuilder class from the specified substring and capacity.
        /// @param value The string that contains the substring used to initialize the value of this instance. If value is null, the new System::Text::StringBuilder will contain the empty string (that is, it contains System::String.Empty).
        /// @param startIndex The position within value where the substring begins.
        /// @param length The number of characters in the substring.
        /// @exception System::ArgumentOutOfRangeException capacity is less than zero. or  startIndex plus length is not a position within value.
        /// @par Examples
        /// The following example demonstrates how to call the StringBuilder constructor with the specified string.
        /// @code
        /// string initialString = "Initial string for stringbuilder.";
        /// int startIndex = 0;
        /// int substringLength = 14;
        /// int capacity = 255;
        /// StringBuilder stringBuilder(initialString, startIndex, substringLength, capacity);
        /// @endcode
        StringBuilder(const String& value, int32 startIndex, int32 length, int32 capacity) {
          if (startIndex < 0 || length < 0)
            throw ArgumentOutOfRangeException(caller_);
          if (startIndex + length > value.Length())
            throw ArgumentOutOfRangeException(caller_);
          if (capacity < 0)
            throw ArgumentOutOfRangeException(caller_);

          this->string = std::u32string((const char32*)std::wstring_convert<std::codecvt_utf8<__char32>, __char32>().from_bytes(value.Data()).c_str(), startIndex, length);
          this->string.reserve(capacity);
        }

        /// @brief Gets or sets the character at the specified character position in this instance.
        /// @param index The position of the character.
        /// @return The Unicode character at position index.
        /// @exception ArgumentOutOfRangeException index is outside the bounds of this instance while setting a character.
        /// @exception IndexOutOfRangeException index is outside the bounds of this instance while getting a character.
        /// @remarks The index parameter is the position of a character within the StringBuilder. The first character in the string is at index 0. The length of a string is the number of characters it contains. The last accessible character of a StringBuilder instance is at index Length - 1.
        /// @par Examples
        /// Chars is the default property of the StringBuilder class. In C++, it is an indexer. This means that individual characters can be retrieved from the Chars property as shown in the following example, which counts the number of alphabetic, white-space, and punctuation characters in a string.
        /// @include StringBuilder.cpp
        char32 operator [](int32 index) const {
          if (index < 0 || index >= static_cast<int32>(this->string.size()))
            throw IndexOutOfRangeException(caller_);
          return this->string[index];
        }

        /// @brief Gets or sets the character at the specified character position in this instance.
        /// @param index The position of the character.
        /// @return The Unicode character at position index.
        /// @exception ArgumentOutOfRangeException index is outside the bounds of this instance while setting a character.
        /// @exception IndexOutOfRangeException index is outside the bounds of this instance while getting a character.
        /// @remarks The index parameter is the position of a character within the StringBuilder. The first character in the string is at index 0. The length of a string is the number of characters it contains. The last accessible character of a StringBuilder instance is at index Length - 1.
        /// @par Examples
        /// Chars is the default property of the StringBuilder class. In C++, it is an indexer. This means that individual characters can be retrieved from the Chars property as shown in the following example, which counts the number of alphabetic, white-space, and punctuation characters in a string.
        /// @include StringBuilder.cpp
        char32& operator [](int32 index) {
          if (index < 0 || index >= static_cast<int32>(this->string.size()))
            throw ArgumentOutOfRangeException(caller_);
          return this->string[index];
        }

        /// @brief Gets or sets the maximum number of characters that can be contained in the memory allocated by the current instance.
        /// @param value The maximum number of characters that can be contained in the memory allocated by the current instance. Its value can range from Length to MaxCapacity.
        /// @exception ArgumentOutOfRangeException The value specified for a set operation is less than the current length of this instance. -or- The value specified for a set operation is greater than the maximum capacity.
        /// @remarks Capacity does not affect the string value of the current instance. Capacity can be decreased as long as it is not less than Length.
        /// @remarks The StringBuilder dynamically allocates more space when required and increases Capacity accordingly. For performance reasons, a StringBuilder might allocate more memory than needed. The amount of memory allocated is implementation-specific.
        /// @par Examples
        /// The following example demonstrates the Capacity property.
        /// @include StringBuilder.Capacity.cpp
        property_<int32> Capacity {
          get_ {return static_cast<int32>(this->string.capacity());},
          set_ {
            if (value < static_cast<int32>(this->string.size()) || value > this->maxCapacity)
              throw ArgumentOutOfRangeException(caller_);
            this->string.reserve(value);
          }
        };

        /// @brief Gets the length of the current System::Text::StringBuilder object.
        /// @param The length of this instance.
        /// @exception ArgumentOutOfRange The value specified for a set operation is less than zero or greater than MaxCapacity.
        /// @remarks The length of a StringBuilder object is defined by its number of Char objects.
        /// @remarks Like the String.Length property, the Length property indicates the length of the current string object. Unlike the String.Length property, which is read-only, the Length property allows you to modify the length of the string stored to the StringBuilder object.
        /// @remarks If the specified length is less than the current length, the current StringBuilder object is truncated to the specified length. If the specified length is greater than the current length, the end of the string value of the current StringBuilder object is padded with the Unicode null character (U+0000).
        /// @remarks If the specified length is greater than the current capacity, Capacity increases so that it is greater than or equal to the specified length.
        /// @par Examples
        /// The following example demonstrates the Legnth property.
        /// @include StringBuilder.Capacity.cpp
        property_<int32> Length {
          get_ {return static_cast<int32>(this->string.size());},
          set_ {
            if (value < 0 || value >= MaxCapacity())
              throw ArgumentOutOfRangeException(caller_);
            if (value > static_cast<int32>(this->string.size()))
              this->string.append(value - static_cast<int32>(this->string.size()), 0);
            else
              this->string.resize(value);
          }
        };

        /// @brief Gets the maximum capacity of this instance.
        /// @return The maximum number of characters this instance can hold.
        /// @remarks The maximum capacity for this implementation is Int32.MaxValue. However, this value is implementation-specific and might be different in other or later implementations. You can explicitly set the maximum capacity of a StringBuilder object by calling the StringBuilder(Int32, Int32) constructor.
        /// @remarks In the Switch when you instantiate the StringBuilder object by calling the StringBuilder(Int32, Int32) constructor, both the length and the capacity of the StringBuilder instance can grow beyond the value of its MaxCapacity property. This can occur particularly when you call the Append and AppendFormat methods to append small strings.
        property_<int32, readonly_> MaxCapacity {
          get_ {return this->maxCapacity;}
        };

        /// @brief Appends the string representation of a specified bool value to this instance.
        /// @param value The value to append.
        /// @return A reference to this instance after the append operation has completed.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @remarks The Append(Boolean) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// bool flag = false;
        /// System::Text::StringBuilder sb;
        /// sb.Append("The value of the flag is ").Append(flag).Append(".");
        /// Console::WriteLine(sb.ToString());
        /// // The example displays the following output:
        /// //
        /// // The value of the flag is False.
        /// @endcode
        StringBuilder& Append(bool value) {return this->Append(Boolean(value).ToString());}

        /// @brief Appends the string representation of a specified 8-bits unsigned integer value to this instance.
        /// @param value The value to append.
        /// @return A reference to this instance after the append operation has completed.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @remarks The Append(Byte) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// Array<Byte> bytes = { 16, 132, 27, 253 };
        /// System::Text::StringBuilder sb;
        /// for (auto value : bytes)
        ///   sb.Append(value).Append(" ");
        ///
        /// Console::WriteLine("The byte array: {0}", sb.ToString());
        /// // The example displays the following output:
        /// //
        /// // The byte array: 16 132 27 253
        /// @endcode
        StringBuilder& Append(byte value) {return this->Append(Byte(value).ToString());}

        /// @brief Appends the string representation of a specified char value to this instance.
        /// @param value The value to append.
        /// @return A reference to this instance after the append operation has completed.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @remarks The Append(Char) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// string str = "Characters in a string.";
        /// System::Text::StringBuilder sb;
        /// for (auto ch : str)
        ///   sb.Append(" '").Append(ch).Append("' ");
        ///
        /// Console::WriteLine("Characters in the string:");
        /// Console::WriteLine("  {0}", sb);
        /// // The example displays the following output:
        /// //
        /// // Characters in the string:
        /// //   'C'  'h'  'a'  'r'  'a'  'c'  't'  'e'  'r'  's'  ' '  'i'  'n'  ' '  'a'  ' '  's'  't' 'r'  'i'  'n'  'g'  '.'
        /// @endcode
        StringBuilder& Append(char value) {return this->Append(Char(value).ToString());}

        /// @brief Appends the string representation of a specified char32 value to this instance.
        /// @param value The value to append.
        /// @return A reference to this instance after the append operation has completed.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @remarks The Append(Char) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// string str = "Characters in a string.";
        /// System::Text::StringBuilder sb;
        /// for (auto ch : str)
        ///   sb.Append(" '").Append(ch).Append("' ");
        ///
        /// Console::WriteLine("Characters in the string:");
        /// Console::WriteLine("  {0}", sb);
        /// // The example displays the following output:
        /// //
        /// // Characters in the string:
        /// //   'C'  'h'  'a'  'r'  'a'  'c'  't'  'e'  'r'  's'  ' '  'i'  'n'  ' '  'a'  ' '  's'  't' 'r'  'i'  'n'  'g'  '.'
        /// @endcode
        StringBuilder& Append(char32 value) {return this->Append(Char(value).ToString());}

        /// @brief Appends an array of Unicode characters starting at a specified address to this instance.
        /// @param value  A pointer to an array of characters.
        /// @param valueCount The number of characters in the array.
        /// @return A reference to this instance after the append operation has completed.
        /// @exception valueCount is less than zero. -or- Enlarging the value of this instance would exceed MaxCapacity.
        /// @remarks This method appends valueCount characters starting at address value to the current instance.
        /// @remarks The Append(Char*, Int32) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object.
        /// @remarks The capacity of this instance is adjusted as needed.
        StringBuilder& Append(const char* value, int32 valueCount) {
          if (valueCount < 0)
            throw ArgumentOutOfRangeException(caller_);
          for (int index = 0; index < valueCount; index++)
            this->Append(Char(value[index]).ToString());
          return *this;
        }

        /// @brief Appends an array of Unicode characters starting at a specified address to this instance.
        /// @param value  A pointer to an array of characters.
        /// @param valueCount The number of characters in the array.
        /// @return A reference to this instance after the append operation has completed.
        /// @exception valueCount is less than zero. -or- Enlarging the value of this instance would exceed MaxCapacity.
        /// @remarks This method appends valueCount characters starting at address value to the current instance.
        /// @remarks The Append(Char*, Int32) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object.
        /// @remarks The capacity of this instance is adjusted as needed.
        StringBuilder& Append(const char32* value, int32 valueCount) {
          if (valueCount < 0)
            throw ArgumentOutOfRangeException(caller_);
          for (int index = 0; index < valueCount; index++)
            this->Append(Char(value[index]).ToString());
          return *this;
        }

        /// @brief Appends a specified number of copies of the string representation of a Unicode character to this instance.
        /// @param value The character to append.
        /// @param repeatCount The number of times to append value.
        /// @return A reference to this instance after the append operation has completed.
        /// @exception ArgumentOutOfRange repeatCount is less than zero. -or- Enlarging the value of this instance would exceed MaxCapacity.
        /// @exception OutOfMemoryException Out of memory.
        /// @remarks The Append(Char, Int32) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// decimal value = 1346.19;
        /// System::Text::StringBuilder sb;
        /// sb.Append('*', 5).AppendFormat("{0:C2}", value).Append('*', 5);
        /// Console::WriteLine(sb);
        ///
        /// // The example displays the following output:
        /// //
        /// // *****$1,346.19*****
        /// @endcode
        StringBuilder& Append(char32 value, int32 repeatCount) {
          if (repeatCount < 0)
            throw ArgumentOutOfRangeException(caller_);
          this->Capacity += repeatCount;
          this->string.append(repeatCount, value);
          return *this;
        }

        /// @brief Appends the string representation of the Unicode characters in a specified array to this instance.
        /// @param value The array of characters to append.
        /// @return A reference to this instance after the append operation has completed.
        /// @exception ArgumentOutOfRange Enlarging the value of this instance would exceed MaxCapacity.
        /// @remarks This method appends all the characters in the specified array to the current instance in the same order as they appear in value. If value is null, no changes are made.
        /// @remarks The Append(Char[]) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// Array<char32> chars = { 'a', 'e', 'i', 'o', 'u' };
        /// System::Text::StringBuilder sb;
        /// sb.Append("The characters in the array: ").Append(chars);
        /// Console::WriteLine(sb);
        ///
        /// // The example displays the following output:
        /// //
        /// // The characters in the array: aeiou
        /// @endcode
        StringBuilder& Append(const Array<char32>& value) {return this->Append(value, 0, value.Length);}

        /// @brief Appends the string representation of the Unicode characters in a specified array to this instance.
        /// @param value The array of characters to append.
        /// @return A reference to this instance after the append operation has completed.
        /// @exception ArgumentOutOfRange Enlarging the value of this instance would exceed MaxCapacity.
        /// @remarks This method appends all the characters in the specified array to the current instance in the same order as they appear in value. If value is null, no changes are made.
        /// @remarks The Append(Char[]) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// Array<char32> chars = { 'a', 'e', 'i', 'o', 'u' };
        /// System::Text::StringBuilder sb;
        /// sb.Append("The characters in the array: ").Append(chars);
        /// Console::WriteLine(sb);
        ///
        /// // The example displays the following output:
        /// //
        /// // The characters in the array: aeiou
        /// @endcode
        StringBuilder& Append(const Array<char32>& value, int32 startIndex, int32 count) {
          if (startIndex < 0 || count < 0 || startIndex + count > value.Length)
            throw ArgumentOutOfRangeException(caller_);
          this->Capacity += value.Count();
          for (int i = startIndex; i < startIndex + count; i++)
            this->Append(value[i]);
          return *this;
        }

        /// @brief Appends the string representation of a specified decimal number to this instance.
        /// @param value The value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        /// @remarks The Append(Char, Int32) method modifies the existing instance of this class; it does not return a new class instance.Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// decimal value = 1346.19;
        /// System::Text::StringBuilder sb;
        /// sb.Append('*', 5).AppendFormat("{0:C2}", value).Append('*', 5);
        /// Console::WriteLine(sb);
        ///
        /// // The example displays the following output:
        /// //
        /// // *****$1,346.19*****
        /// @endcode
        StringBuilder& Append(decimal value) {return this->Append(Decimal(value).ToString());}

        /// @brief Appends the string representation of a specified double-precision floating-point number to this instance.
        /// @param value The value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        /// @remarks The Append(Char, Int32) method modifies the existing instance of this class; it does not return a new class instance.Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// double value = 1346.19;
        /// System::Text::StringBuilder sb;
        /// sb.Append('*', 5).AppendFormat("{0:C2}", value).Append('*', 5);
        /// Console::WriteLine(sb);
        ///
        /// // The example displays the following output:
        /// //
        /// // *****$1,346.19*****
        /// @endcode
        StringBuilder& Append(double value) {return this->Append(Double(value).ToString());}

        /// @brief Appends the string representation of a specified 16-bit signed integer to this instance.
        /// @param value The value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        /// @remarks The Append(Int16) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// System::Text::StringBuilder sb("The range of a 16-bit integer: ");
        /// sb.Append(Int16::MinValue).Append(" to ").Append(Int16::MaxValue);
        /// Console::WriteLine(sb);
        /// // The example displays the following output:
        /// //
        /// // The range of a 16-bit integer: -32768 to 32767
        /// @endcode
        StringBuilder& Append(int16 value) {return this->Append(Int16(value).ToString());}

        /// @brief Appends the string representation of a specified 32-bit signed integer to this instance.
        /// @param value The value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        /// @remarks The Append(Int32) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// System::Text::StringBuilder sb("The range of a 32-bit integer: ");
        /// sb.Append(Int32::MinValue).Append(" to ").Append(Int32::MaxValue);
        /// Console::WriteLine(sb);
        /// // The example displays the following output:
        /// //
        /// // The range of a 32-bit integer: -2147483648 to 2147483647
        /// @endcode
        StringBuilder& Append(int32 value) {return this->Append(Int32(value).ToString());}

        /// @brief Appends the string representation of a specified 64-bit signed integer to this instance.
        /// @param value The value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        /// @remarks The Append(Int64) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// System::Text::StringBuilder sb("The range of a 64-bit integer: ");
        /// sb.Append(Int64::MinValue).Append(" to ").Append(Int64::MaxValue);
        /// Console::WriteLine(sb);
        /// // The example displays the following output:
        /// //
        /// // The range of a 64-bit integer: -9223372036854775808 to 9223372036854775807
        /// @endcode
        StringBuilder& Append(int64 value) {return this->Append(Int64(value).ToString());}

        /// @brief Appends the string representation of a specified object to this instance.
        /// @param value The value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        StringBuilder& Append(const Object& value) {return this->Append(value.ToString());}

        /// @brief Appends the string representation of a specified object to this instance.
        /// @param value The value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        template<typename T>
        StringBuilder& Append(const T& value) {return this->Append(value.ToString());}

        /// @brief Appends the string representation of a specified 8-bits unsigned integer value to this instance.
        /// @param value The value to append.
        /// @return A reference to this instance after the append operation has completed.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @remarks The Append(Byte) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// Array<Byte> bytes = { 16, 132, 27, 253 };
        /// System::Text::StringBuilder sb;
        /// for (auto value : bytes)
        ///   sb.Append(value).Append(" ");
        ///
        /// Console::WriteLine("The byte array: {0}", sb.ToString());
        /// // The example displays the following output:
        /// //
        /// // The byte array: 16 132 27 253
        /// @endcode
        StringBuilder& Append(sbyte value) {return this->Append(SByte(value).ToString());}

        /// @brief Appends the string representation of a specified single-precision floating-point number to this instance.
        /// @param value The value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        /// @remarks The Append(Char, Int32) method modifies the existing instance of this class; it does not return a new class instance.Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// float value = 1346.19;
        /// System::Text::StringBuilder sb;
        /// sb.Append('*', 5).AppendFormat("{0:C2}", value).Append('*', 5);
        /// Console::WriteLine(sb);
        ///
        /// // The example displays the following output:
        /// //
        /// // *****$1,346.19*****
        /// @endcode
        StringBuilder& Append(float value) {return this->Append(Single(value).ToString());}

        /// @brief Appends the string representation of a specified String value to this instance.
        /// @param value The String value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        /// @remarks The Append(Char, Int32) method modifies the existing instance of this class; it does not return a new class instance.Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// bool flag = false;
        /// System::Text::StringBuilder sb;
        /// sb.Append("The value of the flag is ").Append(flag).Append(".");
        /// Console::WriteLine(sb.ToString());
        ///
        /// // The example displays the following output:
        /// //
        /// // The value of the flag is False.
        /// @endcode
        StringBuilder& Append(const String& value) {
          if (this->Length() + value.Length() > this->MaxCapacity())
            throw ArgumentOutOfRangeException(caller_);
          this->string.append((const char32*)std::wstring_convert<std::codecvt_utf8<__char32>, __char32>().from_bytes(value.Data()).c_str());
          return *this;
        }

        /// @brief Appends a copy of a specified substring to this instance.
        /// @param value The string that contains the substring to append.
        /// @param startIndex The starting position of the substring within value.
        /// @param count The number of characters in value to append.
        /// @return A reference to this instance after the append operation has completed.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        StringBuilder& Append(const String& value, int32 startIndex, int32 count) {
          this->Append(value.Substring(startIndex, count));
          return *this;
        }

        /// @cond
        StringBuilder& Append(const char* value) {
          this->Append(String(value));
          return *this;
        }

        StringBuilder& Append(const wchar* value) {
          this->Append(String(value));
          return *this;
        }

        StringBuilder& Append(const char16* value) {
          this->Append(String(value));
          return *this;
        }

        StringBuilder& Append(const char32* value) {
          this->Append(String(value));
          return *this;
        }

        template<typename T, typename Attribute>
        StringBuilder& Append(const property_<T, Attribute>& value) {return this->Append(value());}
        /// @endcond

        /// @brief Appends the string representation of a specified 16-bit unsigned integer to this instance.
        /// @param value The value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        /// @remarks The Append(UInt16) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// System::Text::StringBuilder sb("The range of a 16-bit unsigned integer: ");
        /// sb.Append(UInt16::MinValue).Append(" to ").Append(UInt16::MaxValue);
        /// Console::WriteLine(sb);
        /// // The example displays the following output:
        /// //
        /// // The range of a 16-bit unsigned integer: 0 to 65535
        /// @endcode
        StringBuilder& Append(uint16 value) {return this->Append(UInt16(value).ToString());}

        /// @brief Appends the string representation of a specified 32-bit unsigned integer to this instance.
        /// @param value The value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        /// @remarks The Append(UInt32) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// System::Text::StringBuilder sb("The range of a 32-bit unsigned integer: ");
        /// sb.Append(UInt32::MinValue).Append(" to ").Append(UInt32::MaxValue);
        /// Console::WriteLine(sb);
        /// // The example displays the following output:
        /// //
        /// // The range of a 32-bit unsigned integer: 0 to 4294967295
        /// @endcode
        StringBuilder& Append(uint32 value) {return this->Append(UInt32(value).ToString());}

        /// @brief Appends the string representation of a specified 64-bit unsigned integer to this instance.
        /// @param value The value to append.
        /// @exception Enlarging the value of this instance would exceed MaxCapacity.
        /// @return A reference to this instance after the append operation has completed.
        /// @remarks The Append(UInt64) method modifies the existing instance of this class; it does not return a new class instance. Because of this, you can call a method or property on the existing reference and you do not have to assign the return value to a StringBuilder object, as the following example illustrates.
        /// @par Examples
        /// @code
        /// System::Text::StringBuilder sb("The range of a 64-bit unsigned integer: ");
        /// sb.Append(UInt64::MinValue).Append(" to ").Append(UInt64::MaxValue);
        /// Console::WriteLine(sb);
        /// // The example displays the following output:
        /// //
        /// // The range of a 64-bit unsigned integer: 0 to 18446744073709551615
        /// @endcode
        StringBuilder& Append(uint64 value) {return this->Append(UInt64(value).ToString());}

        StringBuilder& AppendFormat(const string& format) {return this->Append(format);}

        template<typename T1>
        StringBuilder& AppendFormat(const string& format, const T1& a1) {return this->Append(string::Format(format, a1));}

        template<typename T1, typename T2>
        StringBuilder& AppendFormat(const string& format, const T1& a1, const T2& a2) {return this->Append(string::Format(format, a1, a2));}

        template<typename T1, typename T2, typename T3>
        StringBuilder& AppendFormat(const string& format, const T1& a1, const T2& a2, const T3& a3) {return this->Append(string::Format(format, a1, a2, a3));}

        template<typename T1, typename T2, typename T3, typename T4>
        StringBuilder& AppendFormat(const string& format, const T1& a1, const T2& a2, const T3& a3, const T4& a4) {return this->Append(string::Format(format, a1, a2, a3, a4));}

        template<typename T1, typename T2, typename T3, typename T4, typename T5>
        StringBuilder& AppendFormat(const string& format, const T1& a1, const T2& a2, const T3& a3, const T4& a4, const T5& a5) {return this->Append(string::Format(format, a1, a2, a3, a4, a5));}

        template<typename T1, typename T2, typename T3, typename T4, typename T5,  typename T6>
        StringBuilder& AppendFormat(const string& format, const T1& a1, const T2& a2, const T3& a3, const T4& a4, const T5& a5, const T6& a6) {return this->Append(string::Format(format, a1, a2, a3, a4, a5, a6));}

        template<typename T1, typename T2, typename T3, typename T4, typename T5,  typename T6,  typename T7>
        StringBuilder& AppendFormat(const string& format, const T1& a1, const T2& a2, const T3& a3, const T4& a4, const T5& a5, const T6& a6, const T7& a7) {return this->Append(string::Format(format, a1, a2, a3, a4, a5, a6, a7));}

        template<typename T1, typename T2, typename T3, typename T4, typename T5,  typename T6,  typename T7, typename T8>
        StringBuilder& AppendFormat(const string& format, const T1& a1, const T2& a2, const T3& a3, const T4& a4, const T5& a5, const T6& a6, const T7& a7, const T8& a8) {return this->Append(string::Format(format, a1, a2, a3, a4, a5, a6, a7, a8));}

        template<typename T1, typename T2, typename T3, typename T4, typename T5,  typename T6,  typename T7, typename T8, typename T9>
        StringBuilder& AppendFormat(const string& format, const T1& a1, const T2& a2, const T3& a3, const T4& a4, const T5& a5, const T6& a6, const T7& a7, const T8& a8, const T9& a9) {return this->Append(string::Format(format, a1, a2, a3, a4, a5, a6, a7, a8, a9));}

        template<typename T1, typename T2, typename T3, typename T4, typename T5,  typename T6,  typename T7, typename T8, typename T9,  typename T10>
        StringBuilder& AppendFormat(const string& format, const T1& a1, const T2& a2, const T3& a3, const T4& a4, const T5& a5, const T6& a6, const T7& a7, const T8& a8, const T9& a9, const T10& a10) {return this->Append(string::Format(format, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10));}

        StringBuilder& AppendFormat(const string& format, const Array<ref<object>>& objects) {return this->Append(string::Format(format, objects));}

        StringBuilder& AppendLine() {return this->Append(Environment::NewLine);}

        StringBuilder& AppendLine(const string& value) {return this->Append(value).AppendLine();}

        StringBuilder& Clear() {
          this->string.clear();
          return *this;
        }

        /// @brief Determines whether this instance of String and a specified object, which must also be a String object, have the same value.
        /// @param obj The Object to compare with the current Object.
        /// @return bool true if the specified Object is equal to the current Object. otherwise, false.
        bool Equals(const object& obj) const override {return GetType() == obj.GetType() && Equals(static_cast<const StringBuilder&>(obj));}

        /// @brief Determines whether this instance and another specified StringBuilder object have the same value.
        /// @param value The StringBuilder to compare.
        /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
        bool Equals(const StringBuilder& value) const {return this->string == value.string;}

        int EnsureCapacity(int capacity) {
          if (this->Capacity < capacity)
            this->Capacity = capacity;
          return this->Capacity;
        }

        /// @brief Returns a String that represents the current StringBuilder.
        /// @return const String A String that represents the current StringBuilder.
        String ToString() const override {return std::wstring_convert<std::codecvt_utf8<__char32>, __char32>().to_bytes((const __char32*)this->string.c_str());}

      private:
        std::u32string string;
        int32 maxCapacity = Int32::MaxValue;
      };
    }
  }
}

using namespace Switch;
