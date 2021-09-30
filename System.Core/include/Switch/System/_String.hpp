/// @file
/// @brief Contains Switch::System::String class.
#pragma once

#include "../__opaque_unicode_string__.hpp"
#include "../InitializerList.hpp"
#include "../Move.hpp"
#include "../Property.hpp"
#include "../Ref.hpp"
#include "Object.hpp"

#include "Collections/Generic/IEnumerable.hpp"
#include "CharEnumerator.hpp"
#include "ICloneable.hpp"
#include "IComparable.hpp"
#include "IConvertible.hpp"
#include "StringSplitOptions.hpp"
#include "ValueType.hpp"

/// @cond
class __opaque_format_item__;
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    struct Char;
    /// @endcond

    /// @brief Represents text as a series of Unicode characters.
    /// @remarks A String is a sequential collection of Unicode characters that is used to represent text. A String object is a sequential collection of System::Char objects that represent a String. The value of the String object is the content of the sequential collection, and that value is immutable (that is, it is read-only).
    /// @remarks By assigning a String literal to a String variable. This is the most commonly used method for creating a String. The following example uses assignment to create several Strings. Note that in C++, because the backslash (\) is an escape character, literal backslashes in a String must be escaped.
    /// @include String1.cpp
    /// @remarks By calling a String class constructor. The following example instantiates Strings by calling several class constructors. Note that some of the constructors include pointers to character arrays or signed byte arrays as parameters.
    /// @include String2.cpp
    /// @remarks By using the String concatenation operator (+ in C++) to create a single String from any combination of String instances and String literals. The following example illustrates the use of the String concatenation operator.
    /// @include String3.cpp
    /// @remarks By retrieving a property or calling a method that returns a String. The following example uses the methods of the String class to extract a substring from a larger String.
    /// @include String4.cpp
    class core_export_ String final : public ValueType, public ICloneable, public IComparable, public IConvertible, public Collections::Generic::IEnumerable<char32> {
      friend class Convert;
    public:
      using StringType = __opaque_unicode_string__;
      /// @brief Represents the empty String. This field is constant.
      static String Empty;

      /// @brief Create a new instance of class String
      /// @remarks String is initialized with default value String::Empty
      String();

      /// @brief Create a new instance of class String
      /// @param str Value for the String.
      /// @exception ArgumentNullException The parameters str is null.
      String(const char* str);

      /// @brief Create a new instance of class String
      /// @param str Value for the String.
      /// @exception ArgumentNullException The parameters str is null.
      String(const char16* str);

      /// @brief Create a new instance of class String
      /// @param str Value for the String.
      /// @exception ArgumentNullException The parameters str is null.
      String(const char32* str);

      /// @brief Create a new instance of class String
      /// @param str Value for the String.
      /// @exception ArgumentNullException The parameters str is null.
      String(const wchar* str);

      /// @brief Create a new instance of class String
      /// @param str Value for the String.
      /// @exception ArgumentNullException The parameters str is null.
      explicit String(const Array<sbyte>& str);

      /// @brief Create a new instance of class String
      /// @param str Value for the String.
      /// @exception ArgumentNullException The parameters str is null.
      explicit String(const sbyte* str);

      /// @brief Create a new instance of class String
      /// @param chars char array.
      explicit String(const Array<char>& chars);

      /// @brief Create a new instance of class String
      /// @param chars char32 array.
      explicit String(const Array<char32>& chars);

      /// @brief Initializes a new instance of the String class to the value indicated by a specified pointer to an array of characters, a starting character position within that array, and a length.
      /// @param str Value for the String (not null terminated).
      /// @param startIndex The starting position within str.
      /// @param length The number of characters within str to use.
      /// @exception ArgumentNullException The parameters str is null.
      String(const char* str, int32 startIndex, int32 length);

      /// @brief Initializes a new instance of the String class to the value indicated by a specified pointer to an array of characters, a starting character position within that array, and a length.
      /// @param str Value for the String (not null terminated).
      /// @param startIndex The starting position within str.
      /// @param length The number of characters within str to use.
      /// @exception ArgumentNullException The parameters str is null.
      String(const char* str, int32 maxSize);

      /// @brief Initializes a new instance of the String class to the value indicated by a specified pointer to an array of characters, a starting character position within that array, and a length.
      /// @param str Value for the String (not null terminated).
      /// @param startIndex The starting position within str.
      /// @param length The number of characters within str to use.
      /// @exception ArgumentNullException The parameters str is null.
      String(const char32* str, int32 maxSize);

      /// @brief Initializes a new instance of the String class to the value indicated by a specified pointer to an array of characters, a starting character position within that array, and a length.
      /// @param str Value for the String (not null terminated).
      /// @param startIndex The starting position within str.
      /// @param length The number of characters within str to use.
      /// @exception ArgumentNullException The parameters str is null.
      String(const char32* chars, int32 charsSize, int32 index, int32 count);

      /// @brief Create a new instance of class String
      /// @param str Value for the String.
      /// @exception ArgumentNullException The parameters str is null.
      String(const String& str);
      String(String&& str) : string(Move(str.string)) {}

      /// @brief Create a new instance of class String
      /// @param str Value for the String.
      /// @exception ArgumentNullException The parameters str is null.
      String(const std::string& str);

      /// @brief Create a new instance of class String
      /// @param str Value for the String.
      /// @exception ArgumentNullException The parameters str is null.
      String(const std::wstring& str);

      /// @brief Create a new instance of class String
      /// @param str Value for the String.
      /// @exception ArgumentNullException The parameters str is null.
      String(const std::u16string& str);

      /// @brief Create a new instance of class String
      /// @param str Value for the String.
      /// @exception ArgumentNullException The parameters str is null.
      String(const std::u32string& str);

      /// @brief Create a new instance of class String
      /// @param c character to fill the String
      /// @param length length of the String
      explicit String(char32 c, int32 length);

      /// @brief Create a new instance of class String
      /// @param c character to fill the String
      /// @param length length of the String
      explicit String(const String& strA, const String& strB);

      /// @cond
      String(InitializerList<char> il) {
        for (auto c : il)
          this->string.append(c);
      }

      String(InitializerList<char16> il) {
        for (auto c : il)
          this->string.append(c);
      }

      String(InitializerList<char32> il) {
        for (auto c : il)
          this->string.append(c);
      }

      String(InitializerList<wchar> il) {
        for (auto c : il)
          this->string.append(c);
      }

      friend core_export_ std::ostream& operator<<(std::ostream& output, const String& value) {return output << value.c_str();}
      /// @endcond

      /// @brief Return the length of String
      /// @return int32 Length of String
      property_<int32, readonly_> Length {
        get_ {return this->GetLength();}
      };

      /// @brief Get access to raw data of the String.
      /// @return A pointer to raw data of the String.
      /// @remarks If the String contains unicode characters, this function will return raw unicode encoding data which can be hazardous, therefore prefer usage of ToCCharArray instead.
      property_<const char*, readonly_> Data {
        get_->const char* {return this->c_str();}
      };

      /// @brief Compares two specified String objects.
      /// @param strA The first String.
      /// @param strB The second String.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero      strA is less than strB.
      /// @return Zero                strA is equal to strB.
      /// @return Greater than zero   strA is greater than strB.
      static int32 Compare(const String& strA, const String& strB);

      /// @brief Compares two specified String objects, ignoring or honoring their case.
      /// @param strA The first String.
      /// @param strB The second String.
      /// @param ignoreCase A bool indicating a case-sensitive or insensitive comparison. (true indicates a case-insensitive comparison.)
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero      strA is less than strB.
      /// @return Zero                strA is equal to strB.
      /// @return Greater than zero   strA is greater than strB.
      static int32 Compare(const String& strA, const String& strB, bool ignoreCase);

      /// @brief Compares substrings of two specified String objects.
      /// @param strA The first String.
      /// @param indexA The position of the substring within strA.
      /// @param strB The second String.
      /// @param indexB The position of the substring within strB.
      /// @param length The maximum number of characters in the substrings to compare
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero      strA is less than strB.
      /// @return Zero                strA is equal to strB.
      /// @return Greater than zero   strA is greater than strB.
      static int32 Compare(const String& strA, int32 indexA, const String& strB, int32 indexB, int32 length);

      /// @brief Compares substrings of two specified String objects, ignoring or honoring their case.
      /// @param strA The first String.
      /// @param indexA The position of the substring within strA.
      /// @param strB The second String.
      /// @param indexB The position of the substring within strB.
      /// @param length The maximum number of characters in the substrings to compare
      /// @param ignoreCase A bool indicating a case-sensitive or insensitive comparison. (true indicates a case-insensitive comparison.)
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero      strA is less than strB.
      /// @return Zero                strA is equal to strB.
      /// @return Greater than zero   strA is greater than strB.
      static int32 Compare(const String& strA, int32 indexA, const String& strB, int32 indexB, int32 length, bool ignoreCase);

      /// @brief Creates the String representation of a specified object.
      /// @param obj An Object.
      /// @return String The String representation of the value of obj.
      /// @exception ArgumentNullException The parameters obj is null.
      /// @return @see Object
      static String Concat(const Object& obj);

      /// @brief Creates the String representation of a specified object.
      /// @param obj An Object.
      /// @return String The String representation of the value of obj.
      /// @exception ArgumentNullException The parameters obj is null.
      /// @return @see Object
      template<typename T, int32 length>
      static String Concat(const T(&objs)[length]);

      /// @brief Concatenates the String representations of the elements in a specified IEnumerable object.
      /// objs : A IEnumerable object of objects.
      /// @param length Length of obj
      /// @return String The concatenated String representations of the values of the elements in objs.
      /// @exception ArgumentNullException The parameters obj or an object in obj is null.
      /// @return @see Object
      static String Concat(const System::Collections::Generic::IEnumerable<String>& objs);

      /// @brief Concatenates the String representations of two specified objects.
      /// @param objA The first Object.
      /// @param objB The second Object.
      /// @return String The concatenated String representations of the values of objA and objB.
      /// @exception ArgumentNullException The parameters objA or objB is null.
      /// @return @see Object
      static String Concat(const Object& objA, const Object& objB);

      /// @brief Concatenates two specified instances of String.
      /// @param strA The first String.
      /// @param strB The second String.
      /// @return String The concatenation of strA and strB
      /// @exception ArgumentNullException The parameters strA or strB is null.
      static String Concat(const String& strA, const String& strB);

      /// @brief Concatenates the String representations of three specified objects.
      /// @param objA The first Object.
      /// @param objB The second Object.
      /// @param objC The third Object.
      /// @return String The concatenated String representations of the values of objA, objB and objC.
      /// @exception ArgumentNullException The parameters objA or objB or objC is null.
      /// @return @see Object
      static String Concat(const Object& objA, const Object& objB, const Object& objC);

      /// @brief Concatenates three specified instances of String.
      /// @param strA The first String.
      /// @param strB The second String.
      /// @param strC The third String.
      /// @return String The concatenation of strA, strB and strC
      /// @exception ArgumentNullException The parameters strA or strB or strC is null.
      static String Concat(const String& strA, const String& strB, const String& strC);

      /// @brief Concatenates the String representations of four specified objects.
      /// @param objA The first Object.
      /// @param objB The second Object.
      /// @param objC The third Object.
      /// @param objD The fourth Object.
      /// @return String The concatenated String representations of the values of objA, objB, objC and objD.
      /// @exception ArgumentNullException The parameters objA or objB or objC or objD is null.
      /// @return @see Object
      static String Concat(const Object& objA, const Object& objB, const Object& objC, const Object& objD);

      /// @brief Concatenates four specified instances of String.
      /// @param strA The first String.
      /// @param strB The second String.
      /// @param strC The third String.
      /// @param strD The fourth String.
      /// @return String The concatenation of strA, strB, strC and strD
      /// @exception ArgumentNullException The parameters strA or strB or strC or strD is null.
      static String Concat(const String& strA, const String& strB, const String& strC, const String& strD);

      /// @brief Concatenates the String representations of the elements in a specified IEnumerable object.
      /// objs : A IEnumerable object of objects.
      /// @param length Length of obj
      /// @return String The concatenated String representations of the values of the elements in objs.
      /// @exception ArgumentNullException The parameters obj or an object in obj is null.
      /// @return @see Object
      template<typename T>
      static String Concat(const System::Collections::Generic::IEnumerable<T>& objs);

      /// @brief Returns a value indicating whether the specified String object occurs within this String.
      /// @param value The first String.
      /// @return bool true if the value parameter occurs within this String, or if value is the empty String (""); otherwise, false
      /// @exception ArgumentNullException The parameters value is null.
      virtual bool Contains(const String& value) const;

      /// @brief Creates a new instance of String with the same value as a specified String.
      /// @param str The String to copy.
      /// @return String A new String with the same value as str.
      /// @exception ArgumentNullException The parameters str is null.
      static String Copy(const String& str);

      /// @brief Copies a specified number of characters from a specified position in this instance to a specified position in an array of Unicode characters.
      /// @param sourceIndex A character position in this instance.
      /// destination[] : An array of Unicode characters.
      /// @param destinationSize Size of array destination.
      /// @param destinationIndex An array element in destination.
      /// @param count The number of characters in this instance to copy to destination.
      /// @return None.
      /// @exception ArgumentNullException The parameters str is null.
      /// @remarks count characters are copied from the sourceIndex position of this instance to the destinationIndex position of destination.
      /// @remarks sourceIndex and destinationIndex are zero-based.
      void CopyTo(int32 sourceIndex, Array<char32>& destination, int32 destinationIndex, int32 count) const;

      /// @brief Determines whether the end of this instance matches the specified String.
      /// @param value A String to compare to.
      /// @return bool true if value matches the end of this instance; otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      /// @remarks This method compares value to the substring at the end of this instance that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the end of this instance.
      bool EndsWith(const String& value) const;

      /// @brief Determines whether the end of this instance matches the specified String.
      /// @param value A String to compare to.
      /// @return bool true if value matches the end of this instance; otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      /// @remarks This method compares value to the substring at the end of this instance that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the end of this instance.
      bool EndsWith(char32 value) const;

      /// @brief Determines whether the end of this instance matches the specified String, ignoring or honoring their case.
      /// @param value A String to compare to.
      /// @param ignoreCase true to ignore case when comparing this instance and value; otherwise, false
      /// @return bool true if value matches the end of this instance; otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      /// @remarks This method compares value to the substring at the end of this instance that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the end of this instance.
      bool EndsWith(const String& value, bool ignoreCase) const;

      /// @brief Determines whether the end of this instance matches the specified String, ignoring or honoring their case.
      /// @param value A String to compare to.
      /// @param ignoreCase true to ignore case when comparing this instance and value; otherwise, false
      /// @return bool true if value matches the end of this instance; otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      /// @remarks This method compares value to the substring at the end of this instance that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the end of this instance.
      bool EndsWith(char32 value, bool ignoreCase) const;

      /// @brief Determines whether this instance and another specified String object have the same value.
      /// @param value The String to compare.
      /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      bool Equals(const String& value) const;

      /// @brief Determines whether this instance and another specified String object have the same value, ignoring or honoring their case.
      /// @param value The String to compare.
      /// @param ignoreCase true to ignore case when comparing this instance and value; otherwise, false
      /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
      bool Equals(const String& value, bool ignoreCase) const;

      /// @brief Determines whether two specified String objects have the same value.
      /// @param strA The first String to compare.
      /// @param strB The second String to compare.
      /// @return bool true if the value of strA is the same as the value of strB; otherwise, false.
      /// @exception ArgumentNullException The parameters strA or strB is null.
      static bool Equals(const String& strA, const String& strB);

      /// @brief Determines whether two specified String objects have the same value, ignoring or honoring their case.
      /// @param strA The first String to compare.
      /// @param strB The second String to compare.
      /// @param ignoreCase true to ignore case when comparing this instance and value; otherwise, false
      /// @return bool true if the value of strA is the same as the value of strB; otherwise, false.
      /// @exception ArgumentNullException The parameters strA or strB is null.
      static bool Equals(const String& strA, const String& strB, bool ignoreCase);

      /// @brief Replaces the format item in a specified String with the text equivalent of the value of a corresponding Object instance in a specified array. A specified parameter supplies culture-specific formatting information.
      /// @param format A composite format String.
      /// @param args Object list to format.
      /// @return String A copy of format in which the first format item has been replaced by the String equivalent of args.
      /// @exception ArgumentNullException The parameters provider or format or arg is null.
      /// @remarks This function work only with base type specified in TypeCode
      template<typename ...Args>
      static String Format(const String& format, const Args& ... args);

      /// @brief Replaces the format item in a specified String with the text equivalent of the value of a corresponding Object instance in a specified array. A specified parameter supplies culture-specific formatting information.
      /// @param format A composite format String.
      /// @param args An Object to format.
      /// @return String A copy of format in which the first format item has been replaced by the String equivalent of arg.
      /// @exception ArgumentNullException The parameters provider or format or arg is null.
      /// @remarks This function work only with base type specified in TypeCode
      /// @see TypeCode
      static String Format(const String& format, const Array<ref<Object>>& args);

      /// @brief Replaces the format item in a specified String with the text equivalent of the value of a corresponding Object instance in a specified array. A specified parameter supplies culture-specific formatting information.
      /// @param provider An IFormatProvider that supplies culture-specific formatting information
      /// @param format A composite format String.
      /// @param args Object list to format.
      /// @return String A copy of format in which the first format item has been replaced by the String equivalent of args.
      /// @exception ArgumentNullException The parameters provider or format or arg is null.
      /// @remarks This function work only with base type specified in TypeCode
      template<typename ...Args>
      static String Format(const IFormatProvider& provider, const String& format, const Args& ... args);

      /// @brief Replaces the format item in a specified String with the text equivalent of the value of a corresponding Object instance in a specified array. A specified parameter supplies culture-specific formatting information.
      /// @param provider An IFormatProvider that supplies culture-specific formatting information
      /// @param format A composite format String.
      /// @param args An Object to format.
      /// @return String A copy of format in which the first format item has been replaced by the String equivalent of arg.
      /// @exception ArgumentNullException The parameters provider or format or arg is null.
      /// @remarks This function work only with base type specified in TypeCode
      /// @see TypeCode
      static String Format(const IFormatProvider& provider, const String& format, const Array<ref<Object>>& args);

      /// @brief Retrieves an object that can iterate through the individual characters in this String.
      /// @return CharEnumerator An enumerator object.
      /// @remarks This method enables you to iterate the individual characters in a String. For example, the foreach statements invoke this method to return a CharEnumerator object that can provide read-only access to the characters in this String instance.
      /// @par Examples
      /// The following example iterates the characters in several Strings and displays information about their individual characters.
      /// @include String.GetEnumerator.cpp
      CharEnumerator GetEnumerator() const override;

      /// @brief Retrieves an object that can iterate through the individual characters in this String.
      /// @return CharEnumerator An enumerator object.
      /// @remarks This method enables you to iterate the individual characters in a String. For example, the foreach statements invoke this method to return a CharEnumerator object that can provide read-only access to the characters in this String instance.
      /// @par Examples
      /// The following example iterates the characters in several Strings and displays information about their individual characters.
      /// @include String.GetEnumerator.cpp
      CharEnumerator GetReverseEnumerator() const;

      /// @brief Reports the index of the first occurrence of the specified Unicode character in this String.
      /// @param value A Unicode character to seek
      /// @return int32 The index position of value if that character is found, or -1 if it is not.
      int32 IndexOf(char32 value) const;

      /// @brief Reports the index of the first occurrence of the specified Unicode character in this String. The search starts at a specified character position.
      /// @param value A Unicode character to seek
      /// @param startIndex The search starting position
      /// @return int32 The index position of value if that character is found, or -1 if it is not.
      /// @exception ArgumentOutOfRangeException The parameters startIndex specify a position not within this instance.
      int32 IndexOf(const String& value) const;

      /// @brief Reports the index of the first occurrence of the specified Unicode character in this String. The search starts at a specified character position and examines a specified number of character positions.
      /// @param value A Unicode character to seek
      /// @param startIndex The search starting position
      /// @param count The number of character positions to examine
      /// @return int32 The index position of value if that character is found, or -1 if it is not.
      /// @exception ArgumentOutOfRangeException The parameters startIndex plus count specify a position not within this instance.
      int32 IndexOf(char32 value, int32 startIndex) const;

      /// @brief Reports the index of the first occurrence of the specified Unicode String in this String.
      /// @param value A Unicode String to seek
      /// @return int32 The index position of value if that String is found, or -1 if it is not.
      int32 IndexOf(const String& value, int32 startIndex) const;

      /// @brief Reports the index of the first occurrence of the specified Unicode String in this String. The search starts at a specified character position.
      /// @param value A Unicode String to seek
      /// @param startIndex The search starting position
      /// @return int32 The index position of value if that String is found, or -1 if it is not.
      /// @exception ArgumentNullException The parameter value is null.
      /// @exception ArgumentOutOfRangeException The parameter startIndex specify a position not within this instance.
      int32 IndexOf(char32 value, int32 startIndex, int32 count) const;

      /// @brief Reports the index of the first occurrence of the specified Unicode String in this String. The search starts at a specified character position and examines a specified number of character positions.
      /// @param value A Unicode String to seek
      /// @param startIndex The search starting position
      /// @param count The number of character positions to examine
      /// @return int32 The index position of value if that String is found, or -1 if it is not.
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex plus count specify a position not within this instance.
      int32 IndexOf(const String& value, int32 startIndex, int32 count) const;

      /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of Unicode characters.
      /// @param anyOf A Unicode character array containing one or more characters to seek
      /// @return int32 The index position of the first occurrence in this instance where any character in anyOf was found; otherwise, -1 if no character in anyOf was found.
      /// @exception ArgumentNullException The parameters anyOf is null.
      int32 IndexOfAny(const char32 anyOf[], int32 anyOfSize) const;

      /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of Unicode characters.
      /// @param anyOf A Unicode character array containing one or more characters to seek
      /// @return int32 The index position of the first occurrence in this instance where any character in anyOf was found; otherwise, -1 if no character in anyOf was found.
      /// @exception ArgumentNullException The parameters anyOf is null.
      int32 IndexOfAny(const Array<char32>& anyOf) const;

      /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of Unicode characters. The search starts at a specified character position.
      /// @param anyOf A Unicode character array containing one or more characters to seek
      /// @param startIndex The search starting position
      /// @return int32 The index position of the first occurrence in this instance where any character in anyOf was found; otherwise, -1 if no character in anyOf was found.
      /// @exception ArgumentNullException The parameters anyOf is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex specify a position not within this instance.
      int32 IndexOfAny(const char32 anyOf[], int32 anyOfSize, int32 startIndex) const;

      /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of Unicode characters. The search starts at a specified character position.
      /// @param anyOf A Unicode character array containing one or more characters to seek
      /// @param startIndex The search starting position
      /// @return int32 The index position of the first occurrence in this instance where any character in anyOf was found; otherwise, -1 if no character in anyOf was found.
      /// @exception ArgumentNullException The parameters anyOf is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex specify a position not within this instance.
      int32 IndexOfAny(const Array<char32>& anyOf, int32 startIndex) const;

      /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of Unicode characters. The search starts at a specified character position.
      /// @param anyOf A Unicode character array containing one or more characters to seek
      /// @param startIndex The search starting position
      /// @param count The number of character positions to examine.
      /// @return int32 The index position of the first occurrence in this instance where any character in anyOf was found; otherwise, -1 if no character in anyOf was found.
      /// @exception ArgumentNullException The parameters anyOf is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex plus count specify a position not within this instance.
      int32 IndexOfAny(const char32 anyOf[], int32 anyOfSize, int32 startIndex, int32 count) const;

      /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of Unicode characters. The search starts at a specified character position.
      /// @param anyOf A Unicode character array containing one or more characters to seek
      /// @param startIndex The search starting position
      /// @param count The number of character positions to examine.
      /// @return int32 The index position of the first occurrence in this instance where any character in anyOf was found; otherwise, -1 if no character in anyOf was found.
      /// @exception ArgumentNullException The parameters anyOf is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex plus count specify a position not within this instance.
      int32 IndexOfAny(const Array<char32>& anyOf, int32 startIndex, int32 count) const;

      /// @brief Inserts a specified instance of String at a specified index position in this instance.
      /// @param startIndex The index position of the insertion.
      /// @param value The String to insert.
      /// @return String A new String equivalent to this instance but with value inserted at position startIndex.
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex specify a position not within this instance.
      /// @remarks If startIndex is equal to the length of this instance, value is appended to the end of this instance.
      /// @remarks For example, the return value of "abc".Insert(2, "XYZ") is "abXYZc".
      String Insert(int32 startIndex, const String& value) const;

      /// @brief Indicates whether the specified String object is an null or Empty String.
      /// @param value A String reference.
      /// @return bool true if the value parameter is null or an empty String (""); otherwise, false.
      static bool IsNullOrEmpty(const String& value);

      /// @brief Concatenates a specified separator String between each element of a specified String array, yielding a single concatenated String.
      /// @param separator A String separator.
      /// @param values An array of String.
      /// @return A String consisting of the elements of value interspersed with the separator String.
      /// @exception ArgumentNullException The parameters value or a String of value is null.
      /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
      static String Join(const String& separator, const Array<String>& values);

      /// @brief Concatenates a specified separator String between each element of a specified Object array, yielding a single concatenated String.
      /// @param separator A String separator.
      /// @param values An array of Object.
      /// @return A String consisting of the elements of value interspersed with the separator String.
      /// @exception ArgumentNullException The parameters value or a String of value is null.
      /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
      /// @remarks ToString() method is called on each object to generate the content.
      template<typename T>
      static String Join(const String& separator, const Array<T>& values);

      /// @brief Concatenates a specified separator String between each element of a specified Object array, yielding a single concatenated String.
      /// @param separator A String separator.
      /// @param values An array of Object.
      /// @param startIndex The first array element in value to use.
      /// @param count The number of elements of value to use.
      /// @return A String consisting of the elements of value interspersed with the separator String.
      /// @exception ArgumentNullException The parameters value or a String of value is null.
      /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
      /// @remarks ToString() method is called on each object to generate the content.
      template<typename T>
      static String Join(const String& separator, const Array<T>& values, int32 startIndex, int32 count);

      /// @brief Concatenates a specified separator String between each element of a specified Object array, yielding a single concatenated String.
      /// @param separator A String separator.
      /// @param values An array of Object.
      /// @return A String consisting of the elements of value interspersed with the separator String.
      /// @exception ArgumentNullException The parameters value or a String of value is null.
      /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
      /// @remarks ToString() method is called on each object to generate the content.
      template<typename T>
      static String Join(const String& separator, const System::Collections::Generic::IEnumerable<T>& values);

      /// @brief Concatenates a specified separator String between each element of a specified Object array, yielding a single concatenated String.
      /// @param separator A String separator.
      /// @param values An array of Object.
      /// @param startIndex The first array element in value to use.
      /// @param count The number of elements of value to use.
      /// @return A String consisting of the elements of value interspersed with the separator String.
      /// @exception ArgumentNullException The parameters value or a String of value is null.
      /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
      /// @remarks ToString() method is called on each object to generate the content.
      template<typename T>
      static String Join(const String& separator, const System::Collections::Generic::IEnumerable<T>& values, int32 startIndex, int32 count);

      /// @brief Concatenates a specified separator String between each element of a specified Object array, yielding a single concatenated String.
      /// @param separator A String separator.
      /// @param values An array of Object.
      /// @return A String consisting of the elements of value interspersed with the separator String.
      /// @exception ArgumentNullException The parameters value or a String of value is null.
      /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
      /// @remarks ToString() method is called on each object to generate the content.
      template<typename T, int32 len>
      static String Join(const String& separator, const T(&values)[len]);

      /// @brief Concatenates a specified separator String between each element of a specified String array, yielding a single concatenated String.
      /// Parameters specify the first array element and number of elements to use.
      /// @param separator A String separator.
      /// @param values An array of String.
      /// @param startIndex The first array element in value to use.
      /// @param count The number of elements of value to use.
      /// @return A String consisting of the elements of value interspersed with the separator String.
      /// @exception ArgumentNullException The parameters value or a String of value is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex plus count specify a position not within this instance.
      /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value, 2, 2) returns "green, yellow".
      static String Join(const String& separator, const Array<String>& values, int32 startIndex, int32 count);

      /// @brief Concatenates a specified separator String between each element of a specified String array, yielding a single concatenated String.
      /// @param separator A String separator.
      /// @param value An array of String.
      /// @param length Length of array of String value
      /// @return A String consisting of the elements of value interspersed with the separator String.
      /// @exception ArgumentNullException The parameters value or a String of value is null.
      /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value, 4) returns "red, blue, green, yellow".
      static String Join(const String& separator, const String value[], int32 length);

      /// @brief Concatenates a specified separator String between each element of a specified String array, yielding a single concatenated String.
      /// Parameters specify the first array element and number of elements to use.
      /// @param separator A String separator.
      /// @param value An array of String.
      /// @param length Length of array of String value.
      /// @param startIndex The first array element in value to use.
      /// @param count The number of elements of value to use.
      /// @return A String consisting of the elements of value interspersed with the separator String.
      /// @exception ArgumentNullException The parameters value or a String of value is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex plus count specify a position not within this instance.
      /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value, 4, 2, 2) returns "green, yellow".
      static String Join(const String& separator, const String value[], int32 length, int32 startIndex, int32 count);

      /// @brief Reports the index of the last occurrence of the specified Unicode character in this String.
      /// @param value A Unicode character to seek
      /// @return int32 The index position of value if that character is found, or -1 if it is not.
      int32 LastIndexOf(char32 value) const;

      /// @brief Reports the index of the last occurrence of the specified Unicode character in this String. The search starts at a specified character position.
      /// @param value A Unicode character to seek
      /// @param startIndex The search starting position
      /// @return int32 The index position of value if that character is found, or -1 if it is not.
      /// @exception ArgumentOutOfRangeException The parameters startIndex specify a position not within this instance.
      int32 LastIndexOf(char32 value, int32 startIndex) const;

      /// @brief Reports the index of the last occurrence of the specified Unicode character in this String. The search starts at a specified character position and examines a specified number of character positions.
      /// @param value A Unicode character to seek
      /// @param startIndex The search starting position
      /// @param count The number of character positions to examine
      /// @return int32 The index position of value if that character is found, or -1 if it is not.
      /// @exception ArgumentOutOfRangeException The parameters startIndex plus count specify a position not within this instance.
      int32 LastIndexOf(char32 value, int32 startIndex, int32 count) const;

      /// @brief Reports the index of the last occurrence of the specified Unicode String in this String.
      /// @param value A Unicode String to seek
      /// @return int32 The index position of value if that String is found, or -1 if it is not.
      /// @exception ArgumentNullException The parameters value is null.
      int32 LastIndexOf(const String& value) const;

      /// @brief Reports the index of the last occurrence of the specified Unicode String in this String. The search starts at a specified character position.
      /// @param value A Unicode String to seek
      /// @param startIndex The search starting position
      /// @return int32 The index position of value if that String is found, or -1 if it is not.
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex specify a position not within this instance.
      int32 LastIndexOf(const String& value, int32 startIndex) const;

      /// @brief Reports the index of the last occurrence of the specified Unicode String in this String. The search starts at a specified character position and examines a specified number of character positions.
      /// @param value A Unicode String to seek
      /// @param startIndex The search starting position
      /// @param count The number of character positions to examine
      /// @return int32 The index position of value if that String is found, or -1 if it is not.
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex plus count specify a position not within this instance.
      int32 LastIndexOf(const String& value, int32 startIndex, int32 count) const;

      /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of Unicode characters.
      /// @param anyOf A Unicode character array containing one or more characters to seek
      /// @return int32 The index position of the last occurrence in this instance where any character in anyOf was found; otherwise, -1 if no character in anyOf was found.
      /// @exception ArgumentNullException The parameters anyOf is null.
      int32 LastIndexOfAny(const Array<char32>& anyOf) const;

      /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of Unicode characters. The search starts at a specified character position.
      /// @param anyOf A Unicode character array containing one or more characters to seek
      /// @param startIndex The search starting position
      /// @return int32 The index position of the last occurrence in this instance where any character in anyOf was found; otherwise, -1 if no character in anyOf was found.
      /// @exception ArgumentNullException The parameters anyOf is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex specify a position not within this instance.
      int32 LastIndexOfAny(const Array<char32>& anyOf, int32 startIndex) const;

      /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of Unicode characters. The search starts at a specified character position.
      /// @param anyOf A Unicode character array containing one or more characters to seek
      /// @param startIndex The search starting position
      /// @param count The number of character positions to examine.
      /// @return int32 The index position of the last occurrence in this instance where any character in anyOf was found; otherwise, -1 if no character in anyOf was found.
      /// @exception ArgumentNullException The parameters anyOf is null.
      /// @exception ArgumentOutOfRangeException The parameters startIndex plus count specify a position not within this instance.
      int32 LastIndexOfAny(const Array<char32>& anyOf, int32 startIndex, int32 count) const;

      /// @brief Right-aligns the characters in this instance, padding with spaces on the left for a specified total length.
      /// @param totalWidth The number of characters in the resulting String, equal to the number of original characters plus any additional padding characters.
      /// @return String A new String that is equivalent to this instance, but right-aligned and padded on the left with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of this instance, a new String object that is identical to this instance.
      /// @remarks A Unicode space is defined as hexadecimal 0x20.
      /// @remarks The PadLeft(int32) method pads the beginning of the returned String. This means that, when used with right-to-left languages, it pads the right portion of the String..
      String PadLeft(int32 totalWidth) const;

      /// @brief Right-aligns the characters in this instance, padding with spaces on the left for a specified total length.
      /// @param totalWidth The number of characters in the resulting String, equal to the number of original characters plus any additional padding characters.
      /// @param paddingChar A Unicode padding character.
      /// @return String A new String that is equivalent to this instance, but right-aligned and padded on the left with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of this instance, a new String object that is identical to this instance.
      /// @remarks A Unicode space is defined as hexadecimal 0x20.
      /// @remarks The PadLeft(int32) method pads the beginning of the returned String. This means that, when used with right-to-left languages, it pads the right portion of the String..
      String PadLeft(int32 totalWidth, char32 paddingChar) const;

      /// @brief Left-aligns the characters in this instance, padding with spaces on the right for a specified total length.
      /// @param totalWidth The number of characters in the resulting String, equal to the number of original characters plus any additional padding characters.
      /// @return String A new String that is equivalent to this instance, but left-aligned and padded on the right with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of this instance, a new String object that is identical to this instance.
      /// @remarks A Unicode space is defined as hexadecimal 0x20.
      /// @remarks The PadRight(int32) method pads the end of the returned String. This means that, when used with right-to-left languages, it pads the left portion of the String..
      String PadRight(int32 totalWidth) const;

      /// @brief Left-aligns the characters in this instance, padding with spaces on the right for a specified total length.
      /// @param totalWidth The number of characters in the resulting String, equal to the number of original characters plus any additional padding characters.
      /// @param paddingChar A Unicode padding character.
      /// @return String A new String that is equivalent to this instance, but left-aligned and padded on the tight with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of this instance, a new String object that is identical to this instance.
      /// @remarks A Unicode space is defined as hexadecimal 0x20.
      /// @remarks The PadRight(int32) method pads the end of the returned String. This means that, when used with right-to-left languages, it pads the left portion of the String..
      String PadRight(int32 totalWidth, char32 paddingChar) const;

      /// @brief Deletes all the characters from this String beginning at a specified position and continuing through the last position.
      /// @param startIndex The position to begin deleting characters.
      /// @return String A A new String object that is equivalent to this String less the removed characters.
      /// @exception ArgumentOutOfRangeException The parameters startIndex specify a position not within this instance.
      String Remove(int32 startIndex) const;

      /// @brief Deletes all the characters from this String beginning at a specified position and continuing through the last position.
      /// @param startIndex The position to begin deleting characters.
      /// @param count The number of characters to delete.
      /// @return String A A new String object that is equivalent to this String less the removed characters.
      /// @exception ArgumentOutOfRangeException The parameters startIndex plus count specify a position not within this instance.
      String Remove(int32 startIndex, int32 count) const;

      /// @brief Replaces all occurrences of a specified Unicode character in this instance with another specified Unicode character.
      /// @param oldChar A Unicode character to be replaced.
      /// @param newChar A Unicode character to replace all occurrences of oldChar.
      /// @return String A A new String equivalent to this instance but with all instances of oldChar replaced with newChar.
      String Replace(char32 oldChar, char32 newChar) const;

      /// @brief Replaces all occurrences of a specified Unicode String in this instance with another specified Unicode String.
      /// @param oldString A Unicode String to be replaced.
      /// @param newChar A Unicode String to replace all occurrences of oldString.
      /// @return String A A new String equivalent to this instance but with all instances of oldString replaced with newChar.
      /// @exception ArgumentNullException The parameters oldString or newChar is null.
      /// @remarks If newValue is null or empty, all occurrences of oldString are removed
      String Replace(const String& oldString, const String& newChar) const;

      /// @brief Returns a String array that contains the substrings in this String that are delimited by elements of a specified Unicode character array. A parameter specifies whether to return empty array elements.
      /// @param splitSeparator A Unicode character that delimit the substrings in this String.
      /// @return Array<String>* An array whose elements contain the substrings in this instance that are delimited by one or more characters in separator.
      Array<String> Split(char32 splitCharSeparator) const;

      /// @brief Returns a String array that contains the substrings in this String that are delimited by elements of a specified Unicode character array. A parameter specifies whether to return empty array elements.
      /// @param splitSeparators A Unicode character aray that delimit the substrings in this String.
      /// @return Array<String>* An array whose elements contain the substrings in this instance that are delimited by one or more characters in separator.
      Array<String> Split(const Array<char32>& splitCharSeparators) const;

      /// @brief Returns a String array that contains the substrings in this String that are delimited by elements of a specified Unicode character array. A parameter specifies whether to return empty array elements.
      /// @param splitSeparators A Unicode character array that delimit the substrings in this String.
      /// @param count The maximum number of substrings to return.
      /// @return Array<String>* An array whose elements contain the substrings in this instance that are delimited by one or more characters in separator.
      /// @exception ArgumentOutOfRangeException count is negative.
      Array<String> Split(const Array<char32>& splitCharSeparators, int32 count) const;

      /// @brief Returns a String array that contains the substrings in this String that are delimited by elements of a specified Unicode character array. A parameter specifies whether to return empty array elements.
      /// @param splitSeparators A Unicode character array that delimit the substrings in this String.
      /// @param options StringSplitOptionsRemoveEmptyEntries to omit empty array elements from the array returned; or StringSplitOptionsNone to include empty array elements in the array returned.
      /// @return Array<String>* An array whose elements contain the substrings in this instance that are delimited by one or more characters in separator.
      Array<String> Split(const Array<char32>& splitCharSeparators, const StringSplitOptions& options) const;

      /// @brief Returns a String array that contains the substrings in this String that are delimited by elements of a specified Unicode character array. A parameter specifies whether to return empty array elements.
      /// @param splitSeparators A Unicode character array that delimit the substrings in this String.
      /// @param options StringSplitOptionsRemoveEmptyEntries to omit empty array elements from the array returned; or StringSplitOptionsNone to include empty array elements in the array returned.
      /// @return Array<String>* An array whose elements contain the substrings in this instance that are delimited by one or more characters in separator.
      Array<String> Split(char32 c, const StringSplitOptions& options) const;

      /// @brief Returns a String array that contains the substrings in this String that are delimited by elements of a specified Unicode character array. A parameter specifies whether to return empty array elements.
      /// @param splitSeparator A Unicode character array that delimit the substrings in this String.
      /// @param count The maximum number of substrings to return.
      /// @param options StringSplitOptionsRemoveEmptyEntries to omit empty array elements from the array returned; or StringSplitOptionsNone to include empty array elements in the array returned.
      /// @return Array<String>* An array whose elements contain the substrings in this instance that are delimited by one or more characters in separator.
      /// @exception ArgumentOutOfRangeException count is negative.
      Array<String> Split(const Array<char32>& splitCharSeparators, int32 count, const StringSplitOptions& options) const;

      /// @brief Determines whether the beginning of an instance of String matches a specified String.
      /// @param value A String to compare to.
      /// @return bool true if value matches the beginning of this instance; otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      /// @remarks This method compares value to the substring at the beginning of this instance that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of this instance.
      bool StartsWith(const String& value) const;

      /// @brief Determines whether the beginning of an instance of String matches a specified String.
      /// @param value A String to compare to.
      /// @return bool true if value matches the beginning of this instance; otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      /// @remarks This method compares value to the substring at the beginning of this instance that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of this instance.
      bool StartsWith(char32 value) const;

      /// @brief Determines whether the beginning of an instance of String matches a specified String, ignoring or honoring their case.
      /// @param value A String to compare to.
      /// @param ignoreCase true to ignore case when comparing this instance and value; otherwise, false
      /// @return bool true if value matches the beginning of this instance; otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      /// @remarks This method compares value to the substring at the beginning of this instance that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of this instance.
      bool StartsWith(const String& value, bool ignoreCase) const;

      /// @brief Determines whether the beginning of an instance of String matches a specified String, ignoring or honoring their case.
      /// @param value A String to compare to.
      /// @param ignoreCase true to ignore case when comparing this instance and value; otherwise, false
      /// @return bool true if value matches the beginning of this instance; otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      /// @remarks This method compares value to the substring at the beginning of this instance that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of this instance.
      bool StartsWith(char32 value, bool ignoreCase) const;

      /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
      /// @param startIndex The zero-based starting character position of a substring in this instance.
      /// @return String A String equivalent to the substring of length length that begins at startIndex in this instance, or Empty if startIndex is equal to the length of this instance and length is zero.
      /// @exception ArgumentOutOfRangeException The parameters startIndex specify a position not within this instance.
      String Substring(int32 startIndex) const;

      /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
      /// @param startIndex The zero-based starting character position of a substring in this instance.
      /// @param length The number of characters in the substring.
      /// @return String A String equivalent to the substring of length length that begins at startIndex in this instance, or Empty if startIndex is equal to the length of this instance and length is zero.
      /// @exception ArgumentOutOfRangeException The parameters startIndex plus length specify a position not within this instance.
      String Substring(int32 startIndex, int32 length) const;

      /// @brief Copies the characters in this instance to a Unicode character array.
      /// @return char* A Unicode character array whose elements are the individual characters of this instance. If this instance is an empty String, the returned array is empty and has a zero length.
      Array<char> ToCCharArray() const;

      /// @brief Copies the characters in this instance to a Unicode character array.
      /// @return char* A Unicode character array whose elements are the individual characters of this instance. If this instance is an empty String, the returned array is empty and has a zero length.
      Array<char> ToCCharArray(int32 startIndex, int32 length) const;

      /// @brief Copies the characters in this instance to a Unicode character array.
      /// @return char* A Unicode character array whose elements are the individual characters of this instance. If this instance is an empty String, the returned array is empty and has a zero length.
      Array<char> ToCCharArray(int32 codePage) const;

      /// @brief Copies the characters in this instance to a Unicode character array.
      /// @return char* A Unicode character array whose elements are the individual characters of this instance. If this instance is an empty String, the returned array is empty and has a zero length.
      Array<char> ToCCharArray(int32 startIndex, int32 length, int32 codePage) const;

      /// @brief Copies the characters in a specified substring in this instance to a Unicode character array.
      /// @return Array<char32> A Unicode character array whose elements are the length number of characters in this instance starting from character position startIndex.
      /// @exception ArgumentNullException The parameters charArray is null.
      /// @exception ArgumentException The parameters sizeCharArray specify is less than Length of this instance.
      Array<char32> ToCharArray() const;

      /// @brief Copies the characters in a specified substring in this instance to a Unicode character array.
      /// @param startIndex The starting position of a substring in this instance.
      /// @param length The length of the substring in this instance.
      /// @return Array<char32> A Unicode character array whose elements are the length number of characters in this instance starting from character position startIndex.
      /// @exception ArgumentNullException The parameters charArray is null.
      /// @exception ArgumentException The parameters sizeCharArray specify is less than Length of this instance.
      /// @remarks If length is zero, the entire String is copied starting from the beginning of this instance, and ignoring the value of startIndex. If this instance is an empty String (""), the returned array is empty and has a zero length.
      Array<char32> ToCharArray(int32 startIndex, int32 length) const;

      /// @brief Returns a copy of this String converted to lowercase.
      /// @return String A new String in lowercase.
      String ToLower() const;

      /// @brief Returns a copy of this String converted to uppercase.
      /// @return String A new String in uppercase.
      String ToUpper() const;

      /// @brief Removes all leading and trailing white-space characters from the current String object.
      /// @return The string that remains after all white-space characters are removed from the start and end of the current string. If no characters can be trimmed from the current instance, the method returns the current instance unchanged.
      String Trim() const {return TrimStart().TrimEnd();}

      /// @brief Removes all leading and trailing occurrences of a character specified in an array from the current String object.
      /// @param trimChar An Unicode character to remove.
      String Trim(char32 trimChar) const {return TrimStart(trimChar).TrimEnd(trimChar);}

      /// @brief Removes all leading and trailing occurrences of a set of characters specified in an array from the current String object.
      /// @param trimChars An array of Unicode characters to remove.
      String Trim(const Array<char32>& trimChars) const {return TrimStart(trimChars).TrimEnd(trimChars);}

      /// @brief Removes all trailing occurrences of a character specified from the current String object.
      /// @return The String that remains after all occurrences of the character in the trimChar parameter are removed from the end of the current String object.
      String TrimEnd() const {return TrimEnd(' ');}

      /// @brief Removes all trailing occurrences of white-space characters from the current String object.
      /// @param trimChar A Unicode character to remove
      /// @return The String that remains after all occurrences of the character in the trimChar parameter are removed from the end of the current String object.
      String TrimEnd(char32 trimChar) const;

      /// @brief Removes all trailing occurrences of a set of characters specified in an array from the current String object.
      /// @param trimChars An array of Unicode characters to remove
      /// @return The String that remains after all occurrences of the characters in the trimChars parameter are removed from the end of the current String object.
      /// @exception ArgumentNullException The parameters trimChars is null.
      String TrimEnd(const Array<char32>& trimChars) const;

      /// @brief Removes all leading occurrences of white-space characters from the current String object.
      /// @param trimChar A Unicode character to remove
      /// @return The String that remains after all occurrences of the character in the trimChar parameter are removed from the start of the current String object.
      String TrimStart() const {return TrimStart(' ');}

      /// @brief Removes all leading occurrences of a character specified from the current String object.
      /// @param trimChar A Unicode character to remove
      /// @return The String that remains after all occurrences of the character in the trimChar parameter are removed from the start of the current String object.
      String TrimStart(char32 trimChar) const;

      /// @brief Removes all leading occurrences of a set of characters specified in an array from the current String object.
      /// @param trimChars An array of Unicode characters to remove
      /// @return The String that remains after all occurrences of the characters in the trimChars parameter are removed from the start of the current String object.
      /// @exception ArgumentNullException The parameters trimChars is null.
      String TrimStart(const Array<char32>& trimChars) const;

      /// @brief Determines whether this instance of String and a specified object, which must also be a String object, have the same value.
      /// @param obj The Object to compare with the current Object.
      /// @return bool true if the specified Object is equal to the current Object. otherwise, false.
      bool Equals(const Object& obj) const override;

      /// @brief Serves as a hash function for a particular type.
      /// @return int32 A hash code for the current Object.
      /// @return @see Object
      int32 GetHashCode() const override;

      /// @brief Returns a String that represents the current String.
      /// @return const String A String that represents the current String.
      String ToString() const override;

      /// @brief Creates a new object that is a copy of the current instance.
      /// @return Object* A new object that is a copy of this instance.
      /// @return @see Object
      refptr<Object> Clone() const override;

      /// @brief Compares this instance to a specified Char object and returns an indication of their relative values.
      /// @param value An String object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero        This instance is less than value.
      /// @return Zero                This instance is equal to value.
      /// @return Greater than zero   This instance is greater than value.
      int32 CompareTo(const String& value) const;

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero      This instance is less than value.
      /// @return Zero                This instance is equal to value.
      /// @return Greater than zero   This instance is greater than value.
      /// -or-
      /// @return obj is nullNothingnullptra null reference.
      int32 CompareTo(const IComparable& obj) const override;

      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      /// @return @see TypeCode
      TypeCode GetTypeCode() const override;

      /// @cond
      using const_iterator = StringType::const_iterator;
      using iterator = StringType::iterator;
      using const_reverse_iterator = StringType::const_reverse_iterator;
      using reverse_iterator = StringType::reverse_iterator;

      const_iterator cbegin() const {return this->string.begin();}
      const_iterator cend() const {return this->string.end();}
      const_iterator begin() const {return this->string.begin();}
      iterator begin() {return this->string.begin();}
      const_iterator end() const {return this->string.end();}
      iterator end() {return this->string.end();}
      const_reverse_iterator rbegin() const {return this->string.rbegin();}
      reverse_iterator rbegin() {return this->string.rbegin();}
      const_reverse_iterator rend() const {return this->string.rend();}
      reverse_iterator rend() {return this->string.rend();}
      const char* c_str() const { return this->string.c_str(); }
      std::wstring w_str() const;

      /// @endcond

    private:
      String(const StringType& string);

      static bool IsDistant(StringType::const_iterator& it, const StringType::const_iterator& end,  int32 count);
      static bool IsLastElement(const StringType::const_iterator& it, const StringType& str);
      static String FormatToString(const IFormatProvider& provider, const String& format, const Array<__opaque_format_item__>& args);
      static String FormatToString(const IFormatProvider& provider, const String& format, const Array<ref<object>>& args);
      int32 GetLength() const;

      class Enumerator : public System::Object, public Collections::Generic::IEnumerator<char32> {
      public:
        explicit Enumerator(const String& str);
        Enumerator(const Enumerator& other);
        ~Enumerator();
        void Reset() override;
        bool MoveNext() override;

        Enumerator& operator=(const Enumerator& other);
        bool Equals(const Object& other) const override;

      protected:
        const char32& GetCurrent() const override;
        bool IsFinished() const;
        int64 operationNumber;
        bool beforeFirst;
        const StringType* string;
        StringType::const_iterator iterator;
        char32 value;
      };

      class ReverseEnumerator : public System::Object, public Collections::Generic::IEnumerator<char32> {
      public:
        explicit ReverseEnumerator(const String& str);
        ReverseEnumerator(const ReverseEnumerator& other);
        ~ReverseEnumerator();
        void Reset() override;
        bool MoveNext() override;

        ReverseEnumerator& operator=(const ReverseEnumerator& other);
        bool Equals(const Object& other) const override;

      protected:
        const char32& GetCurrent() const override;
        bool IsFinished() const;
        int64 operationNumber;
        bool beforeFirst;
        const StringType* string;
        StringType::const_reverse_iterator iterator;
        char32 value;
      };

      StringType string;
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

      /// @cond
    public:
      String& operator=(const String& str);
      String& operator=(const char str[]);
      char32 operator [](int32 index) const;
      bool operator==(const String& str) const;
      bool operator !=(const String& str) const;
      bool operator<(const String& str) const;
      bool operator>(const String& str) const;
      bool operator<=(const String& str) const;
      bool operator>=(const String& str) const;

      String& operator+=(const String& str);
      String& operator+=(const char value[]);
      String& operator+=(bool value);
      String& operator+=(char value);
      String& operator+=(char16 value);
      String& operator+=(char32 value);
      String& operator+=(wchar value);
      String& operator+=(const Object& value);

      String operator+(const Object& value) const;
      /// @endcond
    };

    /// @cond
    inline bool operator==(const char* valueA, const String& valueB) {return valueB == valueA;}
    inline bool operator==(const char16* valueA, const String& valueB) {return valueB == valueA;}
    inline bool operator==(const char32* valueA, const String& valueB) {return valueB == valueA;}

    core_export_ String operator+(const char str[], const Object& obj);
    core_export_ String operator+(const Object& obj, const char str[]);

    core_export_ String operator+(const String& str, const char value[]);
    core_export_ String operator+(const String& str, bool value);
    core_export_ String operator+(const String& str, byte value);
    core_export_ String operator+(const String& str, char value);
    core_export_ String operator+(const String& str, char16 value);
    core_export_ String operator+(const String& str, char32 value);
    core_export_ String operator+(const String& str, wchar value);
    core_export_ String operator+(const String& str, double value);
    core_export_ String operator+(const String& str, int16 value);
    core_export_ String operator+(const String& str, int32 value);
    core_export_ String operator+(const String& str, int64 value);
    core_export_ String operator+(const String& str, sbyte value);
    core_export_ String operator+(const String& str, float value);
    core_export_ String operator+(const String& str, uint16 value);
    core_export_ String operator+(const String& str, uint32 value);
    core_export_ String operator+(const String& str, uint64 value);
    core_export_ String operator+(const String& str, llong value);
    core_export_ String operator+(const String& str, ullong value);

    template<typename T, typename Attribute>
    String operator+(const char str[], const property_<T, Attribute>& value) { return String(str) + value(); }

    template<typename T, typename Attribute>
    String operator+(const String& str, const property_<T, Attribute>& value) { return str + value(); }

    /// @endcond
  }

  /// @brief Represents text as a series of Unicode characters.
  /// @see System::String class
  /// @ingroup Types
  using string = System::String;
}

using namespace Switch;
