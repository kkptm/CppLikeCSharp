#include "../../../include/Switch/System/SByte.hpp"
#include "../../../include/Switch/System/Convert.hpp"
#include "../../../include/Switch/System/DivideByZeroException.hpp"
#include "../../../include/Switch/System/NumericalFormat.hpp"
#include "../../../include/Switch/System/NumericalParsing.hpp"

using namespace System;

constexpr sbyte SByte::MaxValue;

constexpr sbyte SByte::MinValue;

sbyte SByte::Parse(const string& str) {
  return Parse(str, 10);
}

sbyte SByte::Parse(const string& str, const int32 base) {
  int64 value = NumericalParsing::ParseSigned(str, base, 8);
  return Convert::ToSByte(value);
}

bool SByte::TryParse(const string& str, sbyte& value) {
  return TryParse(str, 10, value);
}

bool SByte::TryParse(const string& str, SByte& value) {
  return TryParse(str, 10, value.value);
}

bool SByte::TryParse(const string& str, int32 base, sbyte& value) {
  try {
    value = Parse(str, base);
  } catch (const Exception&) {
    return false;
  }
  return true;
}

bool SByte::TryParse(const string& str, int32 base, SByte& value) {
  return TryParse(str, base, value.value);
}

int32 SByte::GetHashCode() const {
  return this->value;
}

string SByte::ToString() const {
  return ToString("g3", ref<IFormatProvider>::Null());
}

string SByte::ToString(const string& format) const {
  return ToString(format, ref<IFormatProvider>::Null());
}

string SByte::ToString(const string& format, const IFormatProvider&) const {
  int64 arg = Convert::ToInt64(this->value);
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch (type) {
  case 0:   return NumericalFormat::Format_Custom(arg, format);
  case 'b': return NumericalFormat::Format_B(arg, precision, 8);
  case 'd': return NumericalFormat::Format_D(arg, precision);
  case 'e': return NumericalFormat::Format_E(Convert::ToInt64(this->value), precision == 0 ? 3 : precision, false);
  case 'E': return NumericalFormat::Format_E(Convert::ToInt64(this->value), precision == 0 ? 3 : precision, true);
  case 'f':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_F(arg, precision);
  case 'g':
  case 'G': {
    if (precision == 0) precision = 3;
    return NumericalFormat::Format_G(arg, precision, type == 'G');
  }
  case 'n':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_N(arg, precision);
  case 'p':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_P(arg, precision);
  case 'x': return NumericalFormat::Format_X(arg, precision, false, 2);
  case 'X': return NumericalFormat::Format_X(arg, precision, true,  2);
  }
  return format;
}

int32 SByte::CompareTo(const SByte& value) const {
  return (this->value - value.value);
}

int32 SByte::CompareTo(const IComparable& obj) const {
  if (!is<SByte>(obj))
    return 1;
  return CompareTo(static_cast<const SByte&>(obj));
}

TypeCode SByte::GetTypeCode() const {
  return TypeCode::SByte;
}

bool SByte::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte SByte::ToByte(const IFormatProvider&) const {
  if (this->value < Byte::MinValue)
    throw OverflowException(caller_);

  return (sbyte)this->value;
}

char32 SByte::ToChar(const IFormatProvider&) const {
  return (char)this->value;
}

DateTime SByte::ToDateTime(const IFormatProvider&) const {
  return DateTime((int64)this->value);
}

double SByte::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 SByte::ToInt16(const IFormatProvider&) const {
  return (int16)this->value;
}

int32 SByte::ToInt32(const IFormatProvider&) const {
  return (int32)this->value;
}

int64 SByte::ToInt64(const IFormatProvider&) const {
  return (int64)this->value;
}

uint16 SByte::ToUInt16(const IFormatProvider&) const {
  if (this->value < UInt16::MinValue)
    throw OverflowException(caller_);

  return (uint16)this->value;
}

uint32 SByte::ToUInt32(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(caller_);

  return (uint32)this->value;
}

uint64 SByte::ToUInt64(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(caller_);

  return (uint64)this->value;
}

sbyte SByte::ToSByte(const IFormatProvider&) const {
  return this->value;
}

float SByte::ToSingle(const IFormatProvider&) const {
  return (float)this->value;
}

string SByte::ToString(const IFormatProvider&) const {
  return ToString();
}

SByte::operator sbyte() const {
  return this->value;
}

SByte& SByte::operator =(const SByte& value) {
  this->value = value.value;
  return *this;
}

SByte& SByte::operator +=(const SByte& value) {
  this->value += value.value;
  return *this;
}

SByte& SByte::operator -=(const SByte& value) {
  this->value -= value.value;
  return *this;
}

SByte& SByte::operator *=(const SByte& value) {
  this->value *= value.value;
  return *this;
}

SByte& SByte::operator /=(const SByte& value) {
  if (value == 0)
    throw DivideByZeroException(caller_);

  this->value /= value.value;
  return *this;
}

SByte& SByte::operator %=(const SByte& value) {
  if (value == 0)
    throw DivideByZeroException(caller_);

  this->value %= value;
  return *this;
}

SByte& SByte::operator &=(const SByte& value) {
  this->value &= value.value;
  return *this;
}

SByte& SByte::operator |=(const SByte& value) {
  this->value |= value.value;
  return *this;
}

SByte& SByte::operator ^=(const SByte& value) {
  this->value ^= value.value;
  return *this;
}

SByte& SByte::operator <<=(const SByte& value) {
  this->value <<= value.value;
  return *this;
}

SByte& SByte::operator >>=(const SByte& value) {
  this->value >>= value.value;
  return *this;
}

SByte& SByte::operator ++() {
  ++this->value;
  return *this;
}

const SByte SByte::operator ++(int) {
  return this->value++;
}

SByte& SByte::operator --() {
  --this->value;
  return *this;
}

const SByte SByte::operator --(int) {
  return this->value--;
}

