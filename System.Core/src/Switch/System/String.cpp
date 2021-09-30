#include <codecvt>
#include <locale>
#include "../../../include/Switch/System/String.hpp"
#include "../../../include/Switch/System/Array.hpp"
#include "../../../include/Switch/System/Convert.hpp"
#include "../../../include/Switch/System/FormatProvider.hpp"
#include "../../../include/Switch/System/Math.hpp"
#include "../../../include/Switch/System/StringSplitOptions.hpp"
#include "../../../include/Switch/System/Text/UTF8Encoding.hpp"
#include "../../../include/Switch/System/Text/ANSIEncoding.hpp"
#include "../../../include/Switch/Boxing.hpp"
#include "ArrayAlgorithms.hpp"

#if defined(_WIN32)
using __char16 = __int16;
using __char32 = __int32;
#else
using __char16 = char16;
using __char32 = char32;
#endif

using namespace System;

String String::Empty;

String::String() {}

String::String(const char* str) {
  if (str == null)
    throw ArgumentNullException(caller_);

  this->string = StringType(str);
}

//String::String(const char16* str) : string(std::wstring_convert<std::codecvt_utf8<__char16>, __char16>().to_bytes((const __char16*)str).c_str()) {}

//String::String(const char32* str) : string(std::wstring_convert<std::codecvt_utf8<__char32>, __char32>().to_bytes((const __char32*)str).c_str()) {}

String::String(const char16* str) {
  if (str == null)
    throw ArgumentNullException(caller_);

  int i = 0;
  while (str[i] != 0)
    this->string.append(str[i++]);
}

String::String(const char32* str) {
  if (str == null)
    throw ArgumentNullException(caller_);

  int i = 0;
  while (str[i] != 0)
    this->string.append(str[i++]);
}

String::String(const wchar* str) {
  if (str == null)
    throw ArgumentNullException(caller_);

  int i = 0;
  while (str[i] != 0)
    this->string.append(str[i++]);
}

String::String(const sbyte* str) {
  if (str == null)
    throw ArgumentNullException(caller_);

  this->string = StringType(reinterpret_cast<const char*>(str));
}

String::String(const Array<sbyte>& str) : string(reinterpret_cast<const char*>(str.Data())) {
}

String::String(const Array<char>& chars) {
  for (auto c : chars)
    this->string.append(c);
}

String::String(const Array<char32>& chars) : string(chars.Data, 0, chars.Length) {
}

String::String(const char* str, int32 startIndex, int32 length) {
  if (str == null)
    throw ArgumentNullException(caller_);

  if (startIndex < 0  || length < 0)
    throw ArgumentOutOfRangeException(caller_);

  if (static_cast<uint32>(startIndex + length) >  strlen(str))
    throw ArgumentOutOfRangeException(caller_);

  if (length != 0)
    this->string = StringType(str, startIndex, length);
}

String::String(const char* str, int32 maxSize) {
  if (str == null)
    throw ArgumentNullException(caller_);

  if (maxSize < 0)
    throw ArgumentOutOfRangeException(caller_);

  if (maxSize > 0)
    this->string = StringType(str, 0, maxSize);
}

String::String(const char32* chars, int32 maxSize) {
  if (chars == null)
    throw ArgumentNullException(caller_);

  if (maxSize < 0)
    throw ArgumentOutOfRangeException(caller_);

  if (maxSize == 0)
    return;

  this->string.reserve(maxSize * 4);
  for (int32 i = 0; i < maxSize; i += 1) {
    if (chars[i] == 0) return;
    this->string.append(chars[i]);
  }
}

String::String(const char32 chars[], int32 charsSize, int32 index, int32 count) {
  if (chars == null && count > 0)
    throw ArgumentNullException(caller_);

  if (charsSize < 0 || index < 0  || count < 0)
    throw ArgumentOutOfRangeException(caller_);

  if (index + count >  charsSize)
    throw ArgumentOutOfRangeException(caller_);

  this->string.reserve(count * 4);
  for (int32 i = index; i < index + count; i += 1)
    this->string.append(chars[i]);
}

String::String(const String& str) : string(str.string) {
}

String::String(const std::string& str) : string(str.c_str()) {
}

String::String(const std::wstring& str) : string(std::wstring_convert<std::codecvt_utf8<wchar>, wchar>().to_bytes(str).c_str()) {
}

//String::String(const std::u16string& str) : string((const char*)std::wstring_convert<std::codecvt_utf8<__char16>, __char16>().to_bytes((const __char16*)str.c_str()).c_str()) {}

//String::String(const std::u32string& str) : string((const char*)std::wstring_convert<std::codecvt_utf8<__char32>, __char32>().to_bytes((const __char32*)str.c_str()).c_str()) {}

String::String(const std::u16string& str) {
  int i = 0;
  while (str[i] != 0)
    this->string.append(str[i++]);
}

String::String(const std::u32string& str) {
  int i = 0;
  while (str[i] != 0)
    this->string.append(str[i++]);
}

String::String(char32 c, int32 length) {
  this->string.reserve(length * 4);
  while (length-- > 0)
    this->string.append(c);
}

String::String(const String& strA, const String& strB) {
  this->string.reserve(strA.string.length() + strB.string.length());
  this->string = strA.string;
  this->string.append(strB.string);
}

String::String(const StringType& string) : string(string) {
}

int32 String::Compare(const String& strA, const String& strB) {
  return Compare(strA, strB, false);
}

int32 String::Compare(const String& strA, const String& strB, bool ignoreCase) {
  if (ignoreCase)
    return strA.string.compare_ignore_case(strB.string);
  return strA.string.compare(strB.string);
}

int32 String::Compare(const String& strA, int32 indexA, const String& strB, int32 indexB, int32 length) {
  return Compare(strA, indexA, strB, indexB, length, false);
}

int32 String::Compare(const String& strA, int32 indexA, const String& strB, int32 indexB, int32 length, bool ignoreCase) {
  int32 retValue = 0;

  if (ignoreCase == true) {
    StringType sa(strA.ToLower().string.substr(indexA, length));
    StringType sb(strB.ToLower().string.substr(indexB, length));
    retValue = sa.compare(sb);
  } else {
    StringType sa(strA.string.substr(indexA, length));
    StringType sb(strB.string.substr(indexB, length));
    retValue = sa.compare(sb);
  }
  return retValue;
}

String String::Concat(const object& obj) {
  return obj.ToString();
}

String String::Concat(const System::Collections::Generic::IEnumerable<String>& objs) {
  System::String str;
  int32 size = 0;
  for (String item : objs)
    size += static_cast<int32>(item.string.length());
  str.string.reserve(size);
  for (String item : objs)
    str.string.append(item.string);
  return str;
}

String String::Concat(const object& objA, const object& objB) {
  StringType result;
  result.reserve(objA.ToString().string.length() + objB.ToString().string.length());
  return result.append(objA.ToString().string).append(objB.ToString().string).c_str();
}

String String::Concat(const String& strA, const String& strB) {
  StringType result;
  result.reserve(strA.string.length() + strB.string.length());
  return result.append(strA.string).append(strB.string).c_str();
}

String String::Concat(const object& objA, const object& objB, const object& objC) {
  StringType result;
  result.reserve(objA.ToString().string.length() + objB.ToString().string.length() + objC.ToString().string.length());
  return result.append(objA.ToString().string).append(objB.ToString().string).append(objC.ToString().string).c_str();
}

String String::Concat(const String& strA, const String& strB, const String& strC) {
  StringType result;
  result.reserve(strA.string.length() + strB.string.length() + strC.string.length());
  return result.append(strA.string).append(strB.string).append(strC.string).c_str();
}

String String::Concat(const object& objA, const object& objB, const object& objC, const object& objD) {
  StringType result;
  result.reserve(objA.ToString().string.length() + objB.ToString().string.length() + objC.ToString().string.length() + objD.ToString().string.length());
  return result.append(objA.ToString().string).append(objB.ToString().string).append(objC.ToString().string).append(objD.ToString().string).c_str();
}

String String::Concat(const String& strA, const String& strB, const String& strC, const String& strD) {
  StringType result;
  result.reserve(strA.string.length() + strB.string.length() + strC.string.length() + strD.string.length());
  return result.append(strA.string).append(strB.string).append(strC.string).append(strD.string).c_str();
}

bool String::Contains(const String& value) const {
  return (IndexOf(value) != -1);
}

String String::Copy(const String& str) {
  return str;
}

void String::CopyTo(int32 sourceIndex, Array<char32>& destination, int32 destinationIndex, int32 count) const {
  if (destinationIndex + count >= destination.Length && static_cast<uint32>(sourceIndex + count) > this->string.length())
    throw ArgumentException(caller_);

  int32 i = 0;
  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++) {
    if (it.get_logical_index() >= sourceIndex) {
      destination[destinationIndex + i] = *it;
      i += 1;
    }
  }
}

bool String::EndsWith(const String& value) const {
  return EndsWith(value, false);
}

bool String::EndsWith(char32 value) const {
  return EndsWith(value, false);
}

bool String::EndsWith(const String& value, bool ignoreCase) const {
  if (ignoreCase == true)
    return ToLower().string.ends_with(value.ToLower().string);
  else
    return this->string.ends_with(value.string);
}

bool String::EndsWith(char32 value, bool ignoreCase) const {
  if (Length() == 0) return false;
  if (ignoreCase)
    return Char::ToLower(operator[](Length() - 1)) == Char::ToLower(value);
  else
    return operator[](Length() - 1) == value;
}

bool String::Equals(const String& value) const {
  return this->string == value.string;
}

bool String::Equals(const String& value, bool ignoreCase) const {
  if (ignoreCase == true) return (ToLower().CompareTo(value.ToLower()) == 0);
  return Equals(value);
}

bool String::Equals(const String& strA, const String& strB) {
  return strA.string == strB.string;
}

bool String::Equals(const String& strA, const String& strB, bool ignoreCase) {
  return strA.Equals(strB, ignoreCase);
}

using CharEnum = System::Collections::Generic::Enumerator<char32>;

// { uX }
static char32 ReadUnicodeLitteral(ref<CharEnum> enumerator) {
  String toParse;
  do {
    char32 c = enumerator().Current;
    if (c == '}')
      return (char32)UInt32::Parse(toParse, 16);
    else
      toParse += Char(c);
  } while (enumerator().MoveNext());
  throw FormatException("An opened bracket '{' is !closed by '}'", caller_);
}

struct FormatInformation {
  int32 align;
  String format;
  int32 index;
};

// { index[,alignment][ : formatString] }
static void ReadFormat(ref<CharEnum> enumerator, FormatInformation& info) {
  String format;
  do {
    char32 c = enumerator().Current;
    if (c == '}') {
      int32 formatIndex = format.IndexOf(':');
      if (formatIndex == -1)
        info.format = "";
      else {
        info.format = format.Substring(formatIndex + 1);
        format = format.Substring(0, formatIndex);
      }

      int32 alignIndex = format.IndexOf(',');
      if (alignIndex == -1)
        info.align = 0;
      else {
        info.align = Convert::ToInt32(format.Substring(alignIndex + 1));
        format = format.Substring(0, alignIndex);
      }

      info.index = Convert::ToInt32(format);
      return;
    } else
      format += Char(c);
  } while (enumerator().MoveNext());
  throw FormatException("An opened bracket '{' is !closed by '}'", caller_);
}

String String::Format(const String& format, const Array<ref<Object>>& args) {
  return Format(System::FormatProvider(), format, args);
}

String String::Format(const IFormatProvider& provider, const String& format, const Array<ref<Object>>& args) {
  return FormatToString(provider, format, args);
}

String String::FormatToString(const IFormatProvider& provider, const String& format, const Array<__opaque_format_item__>& args) {
  StringType output;
  output.reserve(2048);
  CharEnum enumerator = format.GetEnumerator();

  while (enumerator.MoveNext()) {
    char32 c = enumerator.Current;
    if (c == '{') {
      if (!enumerator.MoveNext())
        throw FormatException("An opened bracket '{' is !closed by '}'", caller_);

      c = enumerator.Current;

      // we have "{{" -- it is replaced by "{"
      if (c == '{')
        output.append(c);
      else {
        // we have "{" it is a unicode litteral, or a format {x,a:f} string

        // unicode litteral case
        if (c == 'u' || c == 'U') {
          if (!enumerator.MoveNext())
            throw FormatException("An opened bracket '{' is !closed by '}'", caller_);
          char32 litteral = ReadUnicodeLitteral(enumerator);
          output.append(litteral);
        } else { // format {x,a:f} string case
          FormatInformation info;
          ReadFormat(enumerator, info);
          if (info.index < 0 || info.index >= args.Length)
            throw FormatException(Format("Index out of bounds (used {0} where the number of Arguments is {1})", info.index, args.Length), caller_);

          StringType formatted;
          formatted.reserve(2048);
          const Object& argument = args[info.index].ToObject();
          const IFormattable* iformattable = dynamic_cast<const IFormattable*>(&argument);
          if (iformattable != null)
            formatted = iformattable->ToString(info.format, provider).string;
          else
            formatted = argument.ToString().string;

          if ((int32)formatted.length() < Math::Abs(info.align)) {
            int32 padCount = Math::Abs(info.align) - static_cast<int32>(formatted.length());
            if (info.align < 0) output += formatted;
            output.append(padCount, ' ');
            if (info.align > 0) output += formatted;
          } else
            output.append(formatted);
        }
      }
    } else if (c == '}') {
      if (!enumerator.MoveNext())
        throw FormatException("Closing bracket '}' found without matching '{'", caller_);
      c = enumerator.Current;
      if (c != '}')
        throw FormatException("Closing bracket '}' found without matching '{'", caller_);
      output.append(c);
    } else
      output.append(c);
  }
  return output;
}

String String::FormatToString(const IFormatProvider& provider, const String& format, const Array<ref<object>>& args) {
  StringType output;
  output.reserve(2048);
  CharEnum enumerator = format.GetEnumerator();

  while (enumerator.MoveNext()) {
    char32 c = enumerator.Current;
    if (c == '{') {
      if (!enumerator.MoveNext())
        throw FormatException("An opened bracket '{' is !closed by '}'", caller_);

      c = enumerator.Current;

      // we have "{{" -- it is replaced by "{"
      if (c == '{')
        output.append(c);
      else {
        // we have "{" it is a unicode litteral, or a format {x,a:f} string

        // unicode litteral case
        if (c == 'u' || c == 'U') {
          if (!enumerator.MoveNext())
            throw FormatException("An opened bracket '{' is !closed by '}'", caller_);
          char32 litteral = ReadUnicodeLitteral(enumerator);
          output.append(litteral);
        } else { // format {x,a:f} string case
          FormatInformation info;
          ReadFormat(enumerator, info);
          if (info.index < 0 || info.index >= args.Length)
            throw FormatException(Format("Index out of bounds (used {0} where the number of Arguments is {1})", info.index, args.Length), caller_);

          StringType formatted;
          formatted.reserve(2048);
          const Object& argument = args[info.index].ToObject();
          const IFormattable* iformattable = dynamic_cast<const IFormattable*>(&argument);
          if (iformattable != null)
            formatted = iformattable->ToString(info.format, provider).string;
          else
            formatted = argument.ToString().string;

          if ((int32)formatted.length() < Math::Abs(info.align)) {
            int32 padCount = Math::Abs(info.align) - static_cast<int32>(formatted.length());
            if (info.align < 0) output += formatted;
            output.append(padCount, ' ');
            if (info.align > 0) output += formatted;
          } else
            output.append(formatted);
        }
      }
    } else if (c == '}') {
      if (!enumerator.MoveNext())
        throw FormatException("Closing bracket '}' found without matching '{'", caller_);
      c = enumerator.Current;
      if (c != '}')
        throw FormatException("Closing bracket '}' found without matching '{'", caller_);
      output.append(c);
    } else
      output.append(c);
  }
  return output;
}

CharEnumerator String::GetEnumerator() const {
  return CharEnumerator(new Enumerator(*this));
}

CharEnumerator String::GetReverseEnumerator() const {
  return CharEnumerator(new ReverseEnumerator(*this));
}

int32 String::GetLength() const {
  return static_cast<int32>(this->string.length());
}

int32 String::IndexOf(char32 value) const {
  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++)
    if (*it == value)
      return it.get_logical_index();
  return -1;
}

bool String::IsDistant(StringType::const_iterator& it, const StringType::const_iterator& end,  int32 count) {
  while (count--) {
    it++;
    if (it == end)
      return false;
  }
  return true;
}

int32 String::IndexOf(char32 value, int32 startIndex) const {
  if (startIndex < 0)
    throw ArgumentOutOfRangeException(caller_);

  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++) {
    if (startIndex > 0)
      startIndex -= 1;
    else {
      if (value == *it)
        return it.get_logical_index();
    }
  }

  if (startIndex > 0)
    throw ArgumentOutOfRangeException(caller_);

  return -1;
}

int32 String::IndexOf(char32 value, int32 startIndex, int32 count) const {
  if (startIndex < 0 || count < 0)
    throw ArgumentOutOfRangeException(caller_);

  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++) {
    if (startIndex > 0)
      startIndex -= 1;
    else {
      if (count > 0) {
        count -= 1;
        if (value == *it) {
          if (!IsDistant(it, this->string.end(), count))
            throw ArgumentOutOfRangeException(caller_);
          return it.get_logical_index();
        }
      }
    }
  }

  if (startIndex > 0 || count > 0)
    throw ArgumentOutOfRangeException(caller_);

  return -1;
}

int32 String::IndexOf(const String& value) const {
  return static_cast<int32>(this->string.find(value.string));
}

int32 String::IndexOf(const String& value, int32 startIndex) const {
  return static_cast<int32>(this->string.find(value.string, startIndex));
}

int32 String::IndexOf(const String& value, int32 startIndex, int32 count) const {
  if (startIndex < 0 || count < 0) throw ArgumentOutOfRangeException(caller_);

  size_t length = this->string.size();
  if ((static_cast<uint32>(startIndex) > length || static_cast<uint32>(startIndex + count) > length))
    throw ArgumentOutOfRangeException(caller_);

  return static_cast<int32>(this->string.find(value.string, startIndex, count));
}

int32 String::IndexOfAny(const Array<char32>& anyOf) const {
  return IndexOfAny(anyOf.Data, anyOf.Length);
}

int32 String::IndexOfAny(const char32 anyOf[], int32 anyOfSize) const {
  if (anyOf == null) throw ArgumentNullException(caller_);
  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++) {
    if (ArrayAlgorithms::Contains(anyOf, anyOfSize, char32(*it)))
      return it.get_logical_index();
  }
  return -1;
}

int32 String::IndexOfAny(const Array<char32>& anyOf, int32 startIndex) const {
  if (startIndex < 0) throw ArgumentOutOfRangeException(caller_);

  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++) {
    if (startIndex > 0)
      startIndex -= 1;
    else {
      if (anyOf.Contains(*it))
        return it.get_logical_index();
    }
  }
  if (startIndex > 0) throw ArgumentOutOfRangeException(caller_);
  return -1;
}

int32 String::IndexOfAny(const char32 anyOf[], int32 anyOfSize, int32 startIndex) const {
  return IndexOfAny(anyOf, anyOfSize, startIndex, Length());
}

int32 String::IndexOfAny(const Array<char32>& anyOf, int32 startIndex, int32 count) const {
  return IndexOfAny(anyOf.Data, anyOf.Length, startIndex, count);
}

int32 String::IndexOfAny(const char32 anyOf[], int32 anyOfSize, int32 startIndex, int32 count) const {
  if (anyOf == null) throw ArgumentNullException(caller_);
  if (startIndex < 0 || count < 0) throw ArgumentOutOfRangeException(caller_);

  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++) {
    if (startIndex > 0)
      startIndex -= 1;
    else {
      if (count > 0) {
        count -= 1;
        if (ArrayAlgorithms::Contains(anyOf, anyOfSize, char32(*it))) {
          if (!IsDistant(it, this->string.end(), count))
            throw ArgumentOutOfRangeException(caller_);
          return it.get_logical_index();
        }
      }
    }
  }
  if (startIndex > 0 || count > 0) throw ArgumentOutOfRangeException(caller_);
  return -1;
}

String String::Insert(int32 startIndex, const String& value) const {
  if (startIndex < 0) throw ArgumentOutOfRangeException(caller_);

  StringType inserted;
  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++) {
    if (startIndex > 0) {
      startIndex -= 1;
      inserted.append(*it);
    } else if (startIndex == 0) {
      startIndex = -1;
      for (char32 c : value)
        inserted.append(c);
      inserted.append(*it);
    } else
      inserted.append(*it);
  }

  if (startIndex == 0) {
    for (char32 c : value)
      inserted.append(c);
  }

  if (startIndex > 0) throw ArgumentOutOfRangeException(caller_);
  return inserted;
}

bool String::IsNullOrEmpty(const String& value) {
  return value.string.size() == 0;
}

String String::Join(const String& separator, const Array<String>& values) {
  return String::Join(separator, values, 0, values.Length);
}

String String::Join(const String& separator, const Array<String>& values, int32 startIndex, int32 count) {
  if (startIndex + count > values.Length) throw ArgumentOutOfRangeException(caller_);

  StringType str;
  for (int32 i = startIndex; i < startIndex + count; i++) {
    if (i != startIndex)
      str.append(separator.string);
    str.append(values[i].string);
  }
  return str;
}

String String::Join(const String& separator, const String value[], int32 length) {
  return String::Join(separator, value, length, 0, length);
}

String String::Join(const String& separator, const String value[], int32 length, int32 startIndex, int32 count) {
  if (value == null) throw ArgumentNullException(caller_);
  if (startIndex + count > length) throw ArgumentOutOfRangeException(caller_);

  String str;
  for (int32 i = startIndex; i < startIndex + count; i++) {
    str += value[i];
    if (i < startIndex + count - 1) str += separator;
  }
  return str;
}

int32 String::LastIndexOf(char32 value) const {
  return LastIndexOf(value, 0, static_cast<int32>(this->string.length()));
}

int32 String::LastIndexOf(char32 value, int32 startIndex) const {
  return LastIndexOf(value, startIndex, static_cast<int32>(this->string.length()) - startIndex);
}

int32 String::LastIndexOf(char32 value, int32 startIndex, int32 count) const {
  if (startIndex > static_cast<int32>(this->string.length()) || (startIndex + count) > static_cast<int32>(this->string.length()))
    throw ArgumentOutOfRangeException(caller_);

  int32 index = static_cast<int32>(this->string.rfind(value, startIndex + count - 1));
  if (index < startIndex) return -1;
  return index;
}

int32 String::LastIndexOf(const String& value) const {
  return LastIndexOf(value, 0, static_cast<int32>(this->string.length()));
}

int32 String::LastIndexOf(const String& value, int32 startIndex) const {
  return LastIndexOf(value, startIndex, static_cast<int32>(this->string.length()) - startIndex);
}

int32 String::LastIndexOf(const String& value, int32 startIndex, int32 count) const {
  if (startIndex > static_cast<int32>(this->string.length()) || (startIndex + count) > static_cast<int32>(this->string.length()))
    throw ArgumentOutOfRangeException(caller_);

  int32 index = static_cast<int32>(this->string.rfind(value.string, startIndex + count - static_cast<int32>(value.string.length())));
  if (index < startIndex) return -1;
  return index;
}

int32 String::LastIndexOfAny(const Array<char32>& anyOf) const {
  return LastIndexOfAny(anyOf, 0, static_cast<int32>(this->string.length()));
}

int32 String::LastIndexOfAny(const Array<char32>& anyOf, int32 startIndex) const {
  return LastIndexOfAny(anyOf, startIndex, static_cast<int32>(this->string.length()) - startIndex);
}

// todo iterator
int32 String::LastIndexOfAny(const Array<char32>& anyOf, int32 startIndex, int32 count) const {
  int32 index = Int32::MinValue;
  int32 lastIndex = -1;

  for (int32 i = 0; i < anyOf.Length; i++) {
    lastIndex = LastIndexOf(anyOf[i], startIndex, count);
    if (lastIndex > index)
      index = lastIndex;
  }
  return index;
}

String String::PadLeft(int32 totalWidth) const {
  return PadLeft(totalWidth, ' ');
}

String String::PadLeft(int32 totalWidth, char32 paddingChar) const {
  if (static_cast<uint32>(totalWidth) > this->string.length())
    return String(paddingChar,  totalWidth - static_cast<int32>(this->string.length())) + *this;
  return *this;
}

String String::PadRight(int32 totalWidth) const {
  return PadRight(totalWidth, ' ');
}

String String::PadRight(int32 totalWidth, char32 paddingChar) const {
  if (static_cast<uint32>(totalWidth) > this->string.length())
    return *this + String(paddingChar,  totalWidth - static_cast<int32>(this->string.length()));
  return *this;
}

String String::Remove(int32 startIndex) const {
  return Remove(startIndex, static_cast<int32>(this->string.length()) - startIndex);
}

String String::Remove(int32 startIndex, int32 count) const {
  if (static_cast<uint32>(startIndex) > this->string.length() || static_cast<uint32>(startIndex + count) > this->string.length())
    throw ArgumentOutOfRangeException(caller_);
  if (startIndex < 0 || count < 0) throw ArgumentException(caller_);

  String str(*this);
  str.string.erase(startIndex, count);
  return str;
}

// TODO THIS IS FALSE BECAUSE OF UNICODE -> MUST BUILD A NEW STRING (variable char size)
String String::Replace(char32 oldChar, char32 newChar) const {
  String str(*this);
  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++) {
    if (*it == oldChar)
      str.string.replace(it.get_logical_index(), 1, 1, (char)newChar);
  }
  return str;
}

String String::Replace(const String& oldString, const String& newStr) const {
  String str(*this);
  int32 index;
  int32 position = 0;
  while ((index = str.IndexOf(oldString, position, str.Length() - position)) != -1) {
    str.string.replace(index, oldString.string.length(), newStr.string);
    position = index + newStr.Length();
  }
  return str;
}

Array<String> String::Split(char32 splitCharSeparator) const {
  return Split({splitCharSeparator}, Int32::MaxValue, StringSplitOptions::None);
}

Array<String> String::Split(char32 splitCharSeparator, const StringSplitOptions& options) const {
  return Split({splitCharSeparator}, Int32::MaxValue, options);
}

Array<String> String::Split(const Array<char32>& splitCharSeparators) const {
  return Split(splitCharSeparators, Int32::MaxValue, StringSplitOptions::None);
}

Array<String> String::Split(const Array<char32>& splitCharSeparators, int32 count) const {
  return Split(splitCharSeparators, count, StringSplitOptions::None);
}

Array<String> String::Split(const Array<char32>& splitCharSeparators, const StringSplitOptions& options) const {
  return Split(splitCharSeparators, Int32::MaxValue, options);
}

bool String::IsLastElement(const StringType::const_iterator& it, const StringType& str) {
  return it.get_logical_index() == static_cast<int32>(str.size()) - 1;
}

Array<String> String::Split(const Array<char32>& splitCharSeparators, int32 count, const StringSplitOptions& options) const {
  if (count < 0) throw ArgumentOutOfRangeException(caller_);

  Collections::Generic::List<String> list;
  if (count == 0) return list.ToArray();
  if (count == 1) {
    list.Add(*this);
    return list.ToArray();
  }

  String piece;
  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++) {
    char32 c = *it;
    bool isSeparator = splitCharSeparators.Contains(c);
    if (!isSeparator) piece.string.append(c);
    if (IsLastElement(it, this->string) || isSeparator) {
      if (piece.string.length() > 0 || (piece.string.length() == 0 && options != StringSplitOptions::RemoveEmptyEntries)) {
        if (list.Count == count - 1) {
          if (isSeparator)
            piece += Substring(it.get_logical_index());
          else
            piece += Substring(it.get_logical_index() + 1);

          list.Add(piece);
          return list.ToArray();
        } else {
          list.Add(piece);
          piece = "";
        }
      }
    }
  }

  return list.ToArray();
}


bool String::StartsWith(const String& value) const {
  return StartsWith(value, false);
}

bool String::StartsWith(char32 value) const {
  return StartsWith(value, false);
}

bool String::StartsWith(const String& value, bool ignoreCase) const {
  int32 index = 0;
  if (ignoreCase == true)
    index = static_cast<int32>(ToLower().string.find(value.ToLower().string, 0, 1));
  else
    index = static_cast<int32>(this->string.find(value.string, 0, 1));
  return (index != -1 && index == 0);
}

bool String::StartsWith(char32 value, bool ignoreCase) const {
  if (Length() == 0) return false;
  if (ignoreCase)
    return Char::ToLower(operator[](0)) == Char::ToLower(value);
  else
    return operator[](0) == value;
}

String String::Substring(int32 startIndex) const {
  return Substring(startIndex, static_cast<int32>(this->string.length()) - startIndex);
}

String String::Substring(int32 startIndex, int32 length) const {
  return this->string.substr(startIndex, length).c_str();
}

Array<char> String::ToCCharArray() const  {
  Array<char> result(Text::CodePage437Encoding().GetByteCount(*this) + 1);
  Text::CodePage437Encoding().GetBytes(*this, (byte*)const_cast<char*>(result.Data()), result.Count);
  return result;
}

Array<char> String::ToCCharArray(int32 startIndex, int32 length) const  {
  String str = this->Substring(startIndex, length);
  Array<char> result(Text::CodePage437Encoding().GetByteCount(str) + 1);
  Text::CodePage437Encoding().GetBytes(str, (byte*)const_cast<char*>(result.Data()), result.Count);
  return result;
}

Array<char> String::ToCCharArray(int32 codePage) const {
  refptr<Text::Encoding> encoding = Text::Encoding::CreateEncoding(codePage);
  if (!encoding->IsSingleByte())
    throw InvalidOperationException(caller_);

  Array<char> result(encoding().GetByteCount(*this) + 1);
  encoding().GetBytes(*this, (byte*)const_cast<char*>(result.Data()), result.Count);
  return result;
}

Array<char> String::ToCCharArray(int32 startIndex, int32 length, int32 codePage) const {
  refptr<Text::Encoding> encoding = Text::Encoding::CreateEncoding(codePage);
  if (!encoding->IsSingleByte())
    throw InvalidOperationException(caller_);

  String str = this->Substring(startIndex, length);
  Array<char> result(encoding().GetByteCount(str) + 1);
  encoding().GetBytes(str, (byte*)const_cast<char*>(result.Data()), result.Count);
  return result;
}

Array<char32> String::ToCharArray() const {
  return this->ToCharArray(0, this->Length);
}

Array<char32> String::ToCharArray(int32 startIndex, int32 length) const {
  String str = this->Substring(startIndex, length);
  Array<char32> chars(length);
  for (StringType::iterator it = str.string.begin(); it != str.string.end(); it++)
    chars[it.get_logical_index()] = *it;
  return chars;
}

String String::ToLower() const {
  return String(this->string.to_lower().c_str());
}

String String::ToUpper() const {
  return String(this->string.to_upper().c_str());
}

String String::TrimEnd(char32 trimChar) const {
  for (StringType::const_reverse_iterator it = (this->string).rbegin(); it != (this->string).rend(); it++) {
    if (*it != trimChar)
      return Substring(0, it.get_logical_index() + 1);
  }
  return String();
}

String String::TrimEnd(const Array<char32>& trimChars) const {
  for (StringType::const_reverse_iterator it = (this->string).rbegin(); it != (this->string).rend(); it++) {
    if (!trimChars.Contains(*it))
      return Substring(0, it.get_logical_index() + 1);
  }
  return String();
}

String String::TrimStart(char32 trimChar) const {
  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++) {
    if (*it != trimChar)
      return String(&this->string.c_str()[it.get_byte_index()]);
  }
  return String();
}

String String::TrimStart(const Array<char32>& trimChars) const {
  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++) {
    if (!trimChars.Contains(*it))
      return String(&this->string.c_str()[it.get_byte_index()]);
  }
  return String();
}

bool String::Equals(const object& obj) const {
  if (GetType() == obj.GetType())
    return Equals(static_cast<const String&>(obj));

  return false;
}

int32 String::GetHashCode() const {
  int32 hash = 0;
  for (StringType::const_iterator it = (this->string).begin(); it != (this->string).end(); it++)
    hash = 5 * hash + *it;
  return hash;
}

string String::ToString() const {
  return *this;
}

refptr<object> String::Clone() const {
  return ref_new<String>(*this);
}

int32 String::CompareTo(const String& value) const {
  return strcmp(this->string.c_str(), value.string.c_str());
}

int32 String::CompareTo(const IComparable& obj) const {
  if (!is<String>(obj))
    return 1;

  return CompareTo(static_cast<const String&>(obj));
}

TypeCode String::GetTypeCode() const {
  return TypeCode::String;
}

bool String::ToBoolean(const IFormatProvider&) const {
  return Boolean::Parse(*this);
}

byte String::ToByte(const IFormatProvider&) const {
  return Byte::Parse(*this);
}

char32 String::ToChar(const IFormatProvider&) const {
  return Char::Parse(*this);
}

DateTime String::ToDateTime(const IFormatProvider&) const {
  return DateTime::Parse(*this);
}

double String::ToDouble(const IFormatProvider&) const {
  return Double::Parse(*this);
}

int16 String::ToInt16(const IFormatProvider&) const {
  return Int16::Parse(*this);
}

int32 String::ToInt32(const IFormatProvider&) const {
  return Int32::Parse(*this);
}

int64 String::ToInt64(const IFormatProvider&) const {
  return Int64::Parse(*this);
}

uint16 String::ToUInt16(const IFormatProvider&) const {
  return UInt16::Parse(*this);
}

uint32 String::ToUInt32(const IFormatProvider&) const {
  return UInt32::Parse(*this);
}

uint64 String::ToUInt64(const IFormatProvider&) const {
  return UInt64::Parse(*this);
}

sbyte String::ToSByte(const IFormatProvider&) const {
  return SByte::Parse(*this);
}

float String::ToSingle(const IFormatProvider&) const {
  return Single::Parse(*this);
}

string String::ToString(const IFormatProvider&) const {
  return ToString();
}

String& String::operator=(const String& str) {
  this->string = str.string;
  return *this;
}

String& String::operator=(const char str[]) {
  if (str == null)
    throw ArgumentNullException(caller_);

  this->string = StringType(str);
  return *this;
}

char32 String::operator [](int32 index) const {
  if (static_cast<uint32>(index) > this->string.length())
    throw ArgumentOutOfRangeException(caller_);

  return char32(this->string[index]);
}

bool String::operator==(const String& str) const {
  return Equals(str);
}

bool String::operator !=(const String& str) const {
  return !Equals(str);
}

bool String::operator<(const String& str) const {
  return CompareTo(str) < 0;
}

bool String::operator>(const String& str) const {
  return CompareTo(str) > 0;
}

bool String::operator<=(const String& str) const {
  return CompareTo(str) <= 0;
}

bool String::operator>=(const String& str) const {
  return CompareTo(str) >= 0;
}

String& String::operator+=(const String& str) {
  this->string.append(str.string);
  return *this;
}

String& String::operator+=(char value) {
  this->string.append(value);
  return *this;
}

String& String::operator+=(bool value) {
  this->string.append(Boolean(value).ToString().string);
  return *this;
}

String& String::operator+=(char16 value) {
  this->string.append(value);
  return *this;
}

String& String::operator+=(char32 value) {
  this->string.append(value);
  return *this;
}

String& String::operator+=(wchar value) {
  this->string.append(value);
  return *this;
}

String& String::operator+=(const object& value) {
  this->string.append(value.ToString().string);
  return *this;
}

String& String::operator+=(const char str[]) {
  if (str == null)
    throw ArgumentNullException(caller_);

  this->string.append(StringType(str));
  return *this;
}

String String::operator+(const object& obj) const {
  return String(*this, obj.ToString());
}

String System::operator+(const char str[], const object& obj) {
  if (str == null)
    throw ArgumentNullException(caller_);
  return String(str, obj.ToString());
}

String System::operator+(const object& obj, const char str[]) {
  if (str == null)
    throw ArgumentNullException(caller_);
  return String(obj.ToString(), str);
}

String System::operator+(const String& obj, const char str[]) {
  return String(obj, str);
}

String System::operator+(const String& str, bool value) {
  return String(str, Boolean(value).ToString());
}

String System::operator+(const String& str, byte value) {
  return String(str, Byte(value).ToString());
}

String System::operator+(const String& str, char value) {
  string copy(str);
  copy += value;
  return copy;
}

String System::operator+(const String& str, char16 value) {
  string copy(str);
  copy += value;
  return copy;
}

String System::operator+(const String& str, char32 value) {
  string copy(str);
  copy += value;
  return copy;
}

String System::operator+(const String& str, wchar value) {
  string copy(str);
  copy += value;
  return copy;
}

String System::operator+(const String& str, double value) {
  return String(str, Double(value).ToString());
}

String System::operator+(const String& str, int16 value) {
  return String(str, Int16(value).ToString());
}

String System::operator+(const String& str, int32 value) {
  return String(str, Int32(value).ToString());
}

String System::operator+(const String& str, int64 value) {
  return String(str, Int64(value).ToString());
}

/*
String System::operator+(const String& str, void* value) {
  return String(str, IntPtr(value).ToString("%p"));
}
*/

String System::operator+(const String& str, sbyte value) {
  return String(str, SByte(value).ToString());
}

String System::operator+(const String& str, float value) {
  return String(str, Single(value).ToString());
}

String System::operator+(const String& str, uint16 value) {
  return String(str, UInt16(value).ToString());
}

String System::operator+(const String& str, uint32 value) {
  return String(str, UInt32(value).ToString());
}

String System::operator+(const String& str, uint64 value) {
  return String(str, UInt64(value).ToString());
}

String System::operator+(const String& str, llong value) {
  return String(str, Int64(value).ToString());
}

String System::operator+(const String& str, ullong value) {
  return String(str, UInt64(value).ToString());

}

String::Enumerator::Enumerator(const String& str) : string(&str.string), iterator(str.string.begin()) {
  Reset();
}

String::Enumerator::Enumerator(const String::Enumerator& other) : operationNumber(other.operationNumber), beforeFirst(other.beforeFirst), string(other.string), iterator(other.iterator), value(other.value) {

}

String::Enumerator::~Enumerator() { }

const char32& String::Enumerator::GetCurrent() const {
  if (this->beforeFirst || IsFinished())
    throw System::InvalidOperationException(caller_);

  Enumerator* enmerator = (Enumerator*)this;
  enmerator->value =  *this->iterator;
  return value;
}

void String::Enumerator::Reset() {
  this->beforeFirst = true;
  this->operationNumber = 0; // todo
  this->iterator = this->string->begin();
}

bool String::Enumerator::MoveNext() {
  // todo
  /*if (_operationNumber != this->string->_operationNumber)
    throw System::InvalidOperationException(caller_);*/

  if (IsFinished())
    return false;

  if (this->beforeFirst)
    this->beforeFirst = false;
  else
    this->iterator++;

  return !IsFinished();
}

bool String::Enumerator::IsFinished() const {
  return this->iterator == this->string->end();
}

String::Enumerator& String::Enumerator::operator=(const String::Enumerator& other) {
  this->operationNumber = other.operationNumber;
  this->beforeFirst = other.beforeFirst;
  this->string = other.string;
  this->iterator = other.iterator;
  value = other.value;
  return *this;
}

bool String::Enumerator::Equals(const Object& obj) const {
  const String::Enumerator* other = dynamic_cast<const String::Enumerator*>(&obj);
  if (other == null) return false;

  if (this->string != other->string) return false;
  return this->iterator == other->iterator;
}

String::ReverseEnumerator::ReverseEnumerator(const String& str) : string(&str.string), iterator(str.string.rbegin()) {
  Reset();
}

String::ReverseEnumerator::ReverseEnumerator(const String::ReverseEnumerator& other) : operationNumber(other.operationNumber), beforeFirst(other.beforeFirst), string(other.string), iterator(other.iterator), value(other.value) {
}

String::ReverseEnumerator::~ReverseEnumerator() {
}

const char32& String::ReverseEnumerator::GetCurrent() const {
  if (this->beforeFirst || IsFinished())
    throw System::InvalidOperationException(caller_);

  ReverseEnumerator* enumerator = (ReverseEnumerator*)this;
  enumerator->value =  *this->iterator;
  return value;
}

void String::ReverseEnumerator::Reset() {
  this->beforeFirst = true;
  this->operationNumber = 0; // todo
  this->iterator = this->string->rbegin();
}

bool String::ReverseEnumerator::MoveNext() {
  // todo
  /*if (_operationNumber != this->string->_operationNumber)
    throw System::InvalidOperationException(caller_);*/

  if (IsFinished())
    return false;

  if (this->beforeFirst)
    this->beforeFirst = false;
  else
    this->iterator++;

  return !IsFinished();
}

bool String::ReverseEnumerator::IsFinished() const {
  return this->iterator == this->string->rend();
}

String::ReverseEnumerator& String::ReverseEnumerator::operator=(const String::ReverseEnumerator& other) {
  this->operationNumber = other.operationNumber;
  this->beforeFirst = other.beforeFirst;
  this->string = other.string;
  this->iterator = other.iterator;
  value = other.value;
  return *this;
}

bool String::ReverseEnumerator::Equals(const Object& obj) const {
  const String::ReverseEnumerator* other = dynamic_cast<const String::ReverseEnumerator*>(&obj);
  if (other == null) return false;

  if (this->string != other->string) return false;
  return this->iterator == other->iterator;
}

#include <comutil.h>  
#pragma comment(lib, "comsuppw.lib")
std::wstring String::w_str() const {
    _bstr_t t = this->string.c_str();
    wchar_t* pwchar = (wchar_t*)t;
    std::wstring result = pwchar;
    return result;
}
