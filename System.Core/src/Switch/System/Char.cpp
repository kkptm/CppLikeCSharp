#include <cstdio>
#include <cwchar>
#include <cwctype>

#include "../../../include/Switch/System/Char.hpp"
#include "../../../include/Switch/System/Byte.hpp"
#include "../../../include/Switch/System/DateTime.hpp"
#include "../../../include/Switch/System/InvalidCastException.hpp"
#include "../../../include/Switch/System/OverflowException.hpp"
#include "../../../include/Switch/System/SByte.hpp"
#include "../../Native/Api.hpp"

using namespace System;

constexpr char32 Char::MaxValue;
constexpr char32 Char::MinValue;

bool Char::IsControl(char32 value) {
  return iscntrl(value) != 0;
}

bool Char::IsControl(const String& value, int32 index) {
  return Char::IsControl(value[index]);
}

bool Char::IsDigit(char32 value) {
  return Native::UnicodeCharactersApi::IsDigit(value);
}

bool Char::IsDigit(const String& value, int32 index) {
  return Char::IsDigit(value[index]);
}

bool Char::IsLetter(char32 value) {
  return Native::UnicodeCharactersApi::IsAlpha(value);
}

bool Char::IsLetter(const String& value, int32 index) {
  return Char::IsLetter(value[index]);
}

bool Char::IsLetterOrDigit(const String& value, int32 index) {
  return Char::IsLetterOrDigit(value[index]);
}

bool Char::IsLower(char32 value) {
  return Native::UnicodeEncodingsApi::ToLower(value) == value;
}

bool Char::IsLower(const String& value, int32 index) {
  return Char::IsLower(value[index]);
}

bool Char::IsPunctuation(char32 value) {
  return Native::UnicodeCharactersApi::IsPunctuation(value);
}

bool Char::IsPunctuation(const String& value, int32 index) {
  return Char::IsPunctuation(value[index]);
}

bool Char::IsSeparator(char32 value) {
  return isspace(value) || value == '\n';
}

bool Char::IsSeparator(const String& value, int32 index) {
  return Char::IsSeparator(value[index]);
}

bool Char::IsSymbol(const String& value, int32 index) {
  return Char::IsSymbol(value[index]);
}

bool Char::IsUpper(char32 value) {
  return Native::UnicodeEncodingsApi::ToUpper(value) == value;
}

bool Char::IsUpper(const String& value, int32 index) {
  return Char::IsUpper(value[index]);
}

bool Char::IsWhiteSpace(char32 value) {
  return isspace(value) != 0;
}

bool Char::IsWhiteSpace(const String& value, int32 index) {
  return Char::IsWhiteSpace(value[index]);
}

char32 Char::Parse(const String& value) {
  if (value.Length() != 1)
    throw FormatException(caller_);

  return value[0];
}

char32 Char::ToLower(char32 value) {
  return tolower(value);
}

char32 Char::ToUpper(char32 value) {
  return toupper(value);
}

String Char::ToString() const {
  byte bytes[5];
  int32 count = Native::UnicodeEncodingsApi::UTF8::Encode(this->value, bytes);
  bytes[count] = 0;
  return String((char*)bytes);
}

bool Char::ToBoolean(const IFormatProvider& provider) const {
  throw InvalidCastException(caller_);
}

byte Char::ToByte(const IFormatProvider& provider) const {
  if (this->value > (char32)Byte::MaxValue)
    throw OverflowException(caller_);
  return static_cast<byte>(this->value);
}

DateTime Char::ToDateTime(const IFormatProvider& provider) const {
  return DateTime(this->value);
}

int16 Char::ToInt16(const IFormatProvider& provider) const {
  if (this->value > (char32)Int16::MaxValue)
    throw OverflowException(caller_);
  return static_cast<int16>(this->value);
}

uint16 Char::ToUInt16(const IFormatProvider& provider) const {
  if (this->value > (char32)UInt16::MaxValue)
    throw OverflowException(caller_);
  return static_cast<uint16>(this->value);
}

sbyte Char::ToSByte(const IFormatProvider& provider) const {
  if (this->value > static_cast<uint32>(SByte::MaxValue)) // MaxValue has to be positive...
    throw OverflowException(caller_);
  return static_cast<sbyte>(this->value);
}

float Char::ToSingle(const IFormatProvider& provider) const {
  if (this->value > (char32)Single::MaxValue)
    throw OverflowException(caller_);
  return static_cast<float>(this->value);
}
