#include "../../../include/Switch/System/UInt32.hpp"
#include "../../../include/Switch/System/Convert.hpp"
#include "../../../include/Switch/System/DivideByZeroException.hpp"
#include "../../../include/Switch/System/NumericalFormat.hpp"
#include "../../../include/Switch/System/NumericalParsing.hpp"

using namespace System;

constexpr uint32 UInt32::MaxValue;

constexpr uint32 UInt32::MinValue;

uint32 UInt32::Parse(const string& str) {
  return Parse(str, 10);
}

uint32 UInt32::Parse(const string& str, const int32 base) {
  uint64 value = NumericalParsing::ParseUnsigned(str, base);
  return Convert::ToUInt32(value);
}

bool UInt32::TryParse(const string& str, uint32& value) {
  return TryParse(str, 10, value);
}

bool UInt32::TryParse(const string& str, UInt32& value) {
  return TryParse(str, 10, value);
}

bool UInt32::TryParse(const string& str, int32 base, uint32& value) {
  try {
    value = Parse(str, base);
  } catch (const Exception&) {
    return false;
  }
  return true;
}

bool UInt32::TryParse(const string& str, int32 base, UInt32& value) {
  return TryParse(str, base, value.value);
}

int32 UInt32::GetHashCode() const {
  return this->value;
}

string UInt32::ToString() const {
  return ToString("g", ref<IFormatProvider>::Null());
}

string UInt32::ToString(const string& format) const {
  return ToString(format, ref<IFormatProvider>::Null());
}

string UInt32::ToString(const string& format, const IFormatProvider&) const {
  uint64 arg = Convert::ToUInt64(this->value);
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch (type) {
  case 0:   return NumericalFormat::Format_Custom(arg, format);
  case 'b': return NumericalFormat::Format_B(arg, precision);
  case 'd': return NumericalFormat::Format_D(arg, precision);
  case 'e': return NumericalFormat::Format_E(Convert::ToUInt64(this->value), precision == 0 ? 10 : precision, false);
  case 'E': return NumericalFormat::Format_E(Convert::ToUInt64(this->value), precision == 0 ? 10 : precision, true);
  case 'f':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_F(arg, precision);
  case 'g':
  case 'G': {
    if (precision == 0) precision = 10;
    return NumericalFormat::Format_G(arg, precision, type == 'G');
  }
  case 'n':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_N(arg, precision);
  case 'p':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_P(arg, precision);
  case 'x': return NumericalFormat::Format_X(arg, precision, false, 8);
  case 'X': return NumericalFormat::Format_X(arg, precision, true, 8);
  }
  return format;
}

int32 UInt32::CompareTo(const UInt32& value) const {
  return this->value - value.value;
}

int32 UInt32::CompareTo(const IComparable& obj) const {
  if (!is<UInt32>(obj))
    return 1;

  return CompareTo(static_cast<const UInt32&>(obj));

}

TypeCode UInt32::GetTypeCode() const {
  return TypeCode::UInt32;
}

bool UInt32::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte UInt32::ToByte(const IFormatProvider&) const {
  if (this->value > Byte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)this->value;
}

char32 UInt32::ToChar(const IFormatProvider&) const {
  if (this->value > Char::MaxValue)
    throw OverflowException(caller_);

  return (char32)this->value;
}

DateTime UInt32::ToDateTime(const IFormatProvider&) const {
  return DateTime((int64)this->value);
}

double UInt32::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 UInt32::ToInt16(const IFormatProvider&) const {
  if (this->value > (uint32)Int16::MaxValue)
    throw OverflowException(caller_);

  return (int16)this->value;
}

int32 UInt32::ToInt32(const IFormatProvider&) const {
  if (this->value > (uint32)Int32::MaxValue)
    throw OverflowException(caller_);

  return (int32)this->value;
}

int64 UInt32::ToInt64(const IFormatProvider&) const {
  return (int64)this->value;
}

uint16 UInt32::ToUInt16(const IFormatProvider&) const {
  if (this->value > UInt16::MaxValue)
    throw OverflowException(caller_);

  return (uint16)this->value;
}

uint32 UInt32::ToUInt32(const IFormatProvider&) const {
  return this->value;
}

uint64 UInt32::ToUInt64(const IFormatProvider&) const {
  return (uint64)this->value;
}

sbyte UInt32::ToSByte(const IFormatProvider&) const {
  if (this->value > (uint32)SByte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)this->value;
}

float UInt32::ToSingle(const IFormatProvider&) const {
  return (float)this->value;
}

string UInt32::ToString(const IFormatProvider&) const {
  return ToString();
}

UInt32::operator uint32() const {
  return this->value;
}

UInt32& UInt32::operator =(const UInt32& value) {
  this->value = value.value;
  return *this;
}

UInt32& UInt32::operator +=(const UInt32& value) {
  this->value += value.value;
  return *this;
}

UInt32& UInt32::operator -=(const UInt32& value) {
  this->value -= value.value;
  return *this;
}

UInt32& UInt32::operator *=(const UInt32& value) {
  this->value *= value.value;
  return *this;
}

UInt32& UInt32::operator /=(const UInt32& value) {
  if (value.value == 0)
    throw DivideByZeroException(caller_);

  this->value /= value.value;
  return *this;
}

UInt32& UInt32::operator %=(const UInt32& value) {
  if (value.value == 0)
    throw DivideByZeroException(caller_);

  this->value %= value;
  return *this;
}

UInt32& UInt32::operator &=(const UInt32& value) {
  this->value &= value.value;
  return *this;
}

UInt32& UInt32::operator |=(const UInt32& value) {
  this->value |= value.value;
  return *this;
}

UInt32& UInt32::operator ^=(const UInt32& value) {
  this->value ^= value.value;
  return *this;
}

UInt32& UInt32::operator <<=(const UInt32& value) {
  this->value <<= value.value;
  return *this;
}

UInt32& UInt32::operator >>=(const UInt32& value) {
  this->value >>= value.value;
  return *this;
}

UInt32& UInt32::operator ++() {
  ++this->value;
  return *this;
}

const UInt32 UInt32::operator ++(int) {
  return this->value++;
}

UInt32& UInt32::operator --() {
  --this->value;
  return *this;
}

const UInt32 UInt32::operator --(int) {
  return this->value--;
}

