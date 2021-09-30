#include "../../../include/Switch/System/UInt16.hpp"
#include "../../../include/Switch/System/Convert.hpp"
#include "../../../include/Switch/System/DivideByZeroException.hpp"
#include "../../../include/Switch/System/NumericalFormat.hpp"
#include "../../../include/Switch/System/NumericalParsing.hpp"

using namespace System;

constexpr uint16 UInt16::MaxValue;

constexpr uint16 UInt16::MinValue;

uint16 UInt16::Parse(const string& str) {
  return Parse(str, 10);
}

uint16 UInt16::Parse(const string& str, const int32 base) {
  uint64 value = NumericalParsing::ParseUnsigned(str, base);
  return Convert::ToUInt16(value);
}

bool UInt16::TryParse(const string& str, uint16& value) {
  return TryParse(str, 10, value);
}

bool UInt16::TryParse(const string& str, UInt16& value) {
  return TryParse(str, 10, value);
}

bool UInt16::TryParse(const string& str, int32 base, uint16& value) {
  try {
    value = Parse(str, base);
  } catch (const Exception&) {
    return false;
  }
  return true;
}

bool UInt16::TryParse(const string& str, int32 base, UInt16& value) {
  return TryParse(str, base, value.value);
}

int32 UInt16::GetHashCode() const {
  return this->value;
}

string UInt16::ToString() const {
  return ToString("g", ref<IFormatProvider>::Null());
}

string UInt16::ToString(const string& format) const {
  return ToString(format, ref<IFormatProvider>::Null());
}

string UInt16::ToString(const string& format, const IFormatProvider&) const {
  uint64 arg = Convert::ToUInt64(this->value);
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch (type) {
  case 0:   return NumericalFormat::Format_Custom(arg, format);
  case 'b': return NumericalFormat::Format_B(arg, precision);
  case 'd': return NumericalFormat::Format_D(arg, precision);
  case 'e': return NumericalFormat::Format_E(Convert::ToUInt64(this->value), precision == 0 ? 5 : precision, false);
  case 'E': return NumericalFormat::Format_E(Convert::ToUInt64(this->value), precision == 0 ? 5 : precision, true);
  case 'f':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_F(arg, precision);
  case 'g':
  case 'G': {
    if (precision == 0) precision = 5;
    return NumericalFormat::Format_G(arg, precision, type == 'G');
  }
  case 'n':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_N(arg, precision);
  case 'p':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_P(arg, precision);
  case 'x': return NumericalFormat::Format_X(arg, precision, false, 8);
  case 'X': return NumericalFormat::Format_X(arg, precision, true,  8);
  }
  return format;
}

int32 UInt16::CompareTo(const UInt16& value) const {
  return this->value - value.value;
}

int32 UInt16::CompareTo(const IComparable& obj) const {
  if (!is<UInt16>(obj))
    return 1;

  return CompareTo(static_cast<const UInt16&>(obj));
}

TypeCode UInt16::GetTypeCode() const {
  return TypeCode::UInt16;
}

bool UInt16::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte UInt16::ToByte(const IFormatProvider&) const {
  if (this->value > Byte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)this->value;
}

char32 UInt16::ToChar(const IFormatProvider&) const {
  return (char)this->value;
}

DateTime UInt16::ToDateTime(const IFormatProvider&) const {
  return DateTime((int64)this->value);
}

double UInt16::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 UInt16::ToInt16(const IFormatProvider&) const {
  if (this->value > Int16::MaxValue)
    throw OverflowException(caller_);

  return (int16)this->value;
}

int32 UInt16::ToInt32(const IFormatProvider&) const {
  return (int32)this->value;
}

int64 UInt16::ToInt64(const IFormatProvider&) const {
  return (int64)this->value;
}

uint16 UInt16::ToUInt16(const IFormatProvider&) const {
  return this->value;
}

uint32 UInt16::ToUInt32(const IFormatProvider&) const {
  return (uint32)this->value;
}

uint64 UInt16::ToUInt64(const IFormatProvider&) const {
  return (uint64)this->value;
}

sbyte UInt16::ToSByte(const IFormatProvider&) const {
  if (this->value > SByte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)this->value;
}

float UInt16::ToSingle(const IFormatProvider&) const {
  return (float)this->value;
}

string UInt16::ToString(const IFormatProvider&) const {
  return ToString();
}

UInt16::operator uint16() const {
  return this->value;
}

UInt16& UInt16::operator =(const UInt16& value) {
  this->value = value.value;
  return *this;
}

UInt16& UInt16::operator +=(const UInt16& value) {
  this->value += value.value;
  return *this;
}

UInt16& UInt16::operator -=(const UInt16& value) {
  this->value -= value.value;
  return *this;
}

UInt16& UInt16::operator *=(const UInt16& value) {
  this->value *= value.value;
  return *this;
}

UInt16& UInt16::operator /=(const UInt16& value) {
  if (value == 0)
    throw DivideByZeroException(caller_);

  this->value /= value.value;
  return *this;
}

UInt16& UInt16::operator %=(const UInt16& value) {
  if (value == 0)
    throw DivideByZeroException(caller_);

  this->value %= value;
  return *this;
}

UInt16& UInt16::operator &=(const UInt16& value) {
  this->value &= value.value;
  return *this;
}

UInt16& UInt16::operator |=(const UInt16& value) {
  this->value |= value.value;
  return *this;
}

UInt16& UInt16::operator ^=(const UInt16& value) {
  this->value ^= value.value;
  return *this;
}

UInt16& UInt16::operator <<=(const UInt16& value) {
  this->value <<= value.value;
  return *this;
}

UInt16& UInt16::operator >>=(const UInt16& value) {
  this->value >>= value.value;
  return *this;
}

UInt16& UInt16::operator ++() {
  ++this->value;
  return *this;
}

const UInt16 UInt16::operator ++(int) {
  return this->value++;
}

UInt16& UInt16::operator --() {
  --this->value;
  return *this;
}

const UInt16 UInt16::operator --(int) {
  return this->value--;
}

