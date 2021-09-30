#include "../../../include/Switch/System/Int16.hpp"
#include "../../../include/Switch/System/Convert.hpp"
#include "../../../include/Switch/System/DivideByZeroException.hpp"
#include "../../../include/Switch/System/NumericalFormat.hpp"
#include "../../../include/Switch/System/NumericalParsing.hpp"

using namespace System;

constexpr int16 Int16::MaxValue;

constexpr int16 Int16::MinValue;

int16 Int16::Parse(const string& value) {
  return Parse(value, 10);
}

int16 Int16::Parse(const string& str, const int32 base) {
  int64 value = NumericalParsing::ParseSigned(str, base, 16);
  return Convert::ToInt16(value);
}

bool Int16::TryParse(const string& value, int16& retValue) {
  return TryParse(value, 10, retValue);
}

bool Int16::TryParse(const string& value, Int16& retValue) {
  return TryParse(value, 10, retValue.value);
}

bool Int16::TryParse(const string& str, int32 base, int16& value) {
  try {
    value = Parse(str, base);
  } catch (const Exception&) {
    return false;
  }
  return true;
}

bool Int16::TryParse(const string& value, int32 base, Int16& retValue) {
  return TryParse(value, base, retValue.value);
}

int32 Int16::GetHashCode() const {
  return this->value;
}

string Int16::ToString() const {
  return ToString("g", ref<IFormatProvider>::Null());
}

string Int16::ToString(const string& format) const {
  return ToString(format, ref<IFormatProvider>::Null());
}

string Int16::ToString(const string& format, const IFormatProvider&) const {
  int64 arg = Convert::ToInt64(this->value);
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch (type) {
  case 0:   return NumericalFormat::Format_Custom(arg, format);
  case 'b': return NumericalFormat::Format_B(arg, precision, 16);
  case 'd': return NumericalFormat::Format_D(arg, precision);
  case 'e': return NumericalFormat::Format_E(Convert::ToInt64(this->value), precision == 0 ? 5 : precision, false);
  case 'E': return NumericalFormat::Format_E(Convert::ToInt64(this->value), precision == 0 ? 5 : precision, true);
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
  case 'x': return NumericalFormat::Format_X(arg, precision, false, 4);
  case 'X': return NumericalFormat::Format_X(arg, precision, true,  4);
  }
  return format;
}

int32 Int16::CompareTo(const Int16& value) const {
  return this->value - value.value;
}

int32 Int16::CompareTo(const IComparable& obj) const {
  if (!is<Int16>(obj))
    return 1;
  return CompareTo(static_cast<const Int16&>(obj));
}

TypeCode Int16::GetTypeCode() const {
  return TypeCode::Int16;
}

bool Int16::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte Int16::ToByte(const IFormatProvider&) const {
  if (this->value < Byte::MinValue)
    throw OverflowException(caller_);

  if (this->value > Byte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)value;
}

char32 Int16::ToChar(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(caller_);

  return this->value;
}

DateTime Int16::ToDateTime(const IFormatProvider&) const {
  return DateTime((int64)this->value);
}

double Int16::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 Int16::ToInt16(const IFormatProvider&) const {
  return this->value;
}

int32 Int16::ToInt32(const IFormatProvider&) const {
  return (int32)this->value;
}

int64 Int16::ToInt64(const IFormatProvider&) const {
  return (int64)this->value;
}

uint16 Int16::ToUInt16(const IFormatProvider&) const {
  if (this->value < UInt16::MinValue)
    throw OverflowException(caller_);

  return (uint16)this->value;
}

uint32 Int16::ToUInt32(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(caller_);

  return (uint32)this->value;
}

uint64 Int16::ToUInt64(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(caller_);

  return (uint64)this->value;
}

sbyte Int16::ToSByte(const IFormatProvider&) const {
  if (this->value < SByte::MinValue)
    throw OverflowException(caller_);

  if (this->value > SByte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)this->value;
}

float Int16::ToSingle(const IFormatProvider&) const {
  return (float)this->value;
}

string Int16::ToString(const IFormatProvider&) const {
  return ToString();
}

Int16::operator int16() const {
  return this->value;
}

Int16& Int16::operator =(const Int16& value) {
  this->value = value.value;
  return *this;
}

Int16& Int16::operator +=(const Int16& value) {
  this->value += value.value;
  return *this;
}

Int16& Int16::operator -=(const Int16& value) {
  this->value -= value.value;
  return *this;
}

Int16& Int16::operator *=(const Int16& value) {
  this->value *= value.value;
  return *this;
}

Int16& Int16::operator /=(const Int16& value) {
  if (value == 0)
    throw DivideByZeroException(caller_);

  this->value /= value.value;
  return *this;
}

Int16& Int16::operator %=(const Int16& value) {
  if (value == 0)
    throw DivideByZeroException(caller_);

  this->value %= value;
  return *this;
}

Int16& Int16::operator &=(const Int16& value) {
  this->value &= value.value;
  return *this;
}

Int16& Int16::operator |=(const Int16& value) {
  this->value |= value.value;
  return *this;
}

Int16& Int16::operator ^=(const Int16& value) {
  this->value ^= value.value;
  return *this;
}

Int16& Int16::operator <<=(const Int16& value) {
  this->value <<= value.value;
  return *this;
}

Int16& Int16::operator >>=(const Int16& value) {
  this->value >>= value.value;
  return *this;
}

Int16& Int16::operator ++() {
  ++this->value;
  return *this;
}

const Int16 Int16::operator ++(int) {
  return this->value++;
}

Int16& Int16::operator --() {
  --this->value;
  return *this;
}

const Int16 Int16::operator --(int) {
  return this->value--;
}

