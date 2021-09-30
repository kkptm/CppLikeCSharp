#include "../../../include/Switch/System/Int32.hpp"
#include "../../../include/Switch/System/Convert.hpp"
#include "../../../include/Switch/System/DivideByZeroException.hpp"
#include "../../../include/Switch/System/NumericalFormat.hpp"
#include "../../../include/Switch/System/NumericalParsing.hpp"

using namespace System;

constexpr int32 Int32::MaxValue;

constexpr int32 Int32::MinValue;

int32 Int32::Parse(const string& value) {
  return Parse(value, 10);
}

int32 Int32::Parse(const string& str, int32 base) {
  int64 value = NumericalParsing::ParseSigned(str, base, 32);
  return Convert::ToInt32(value);
}

bool Int32::TryParse(const string& value, int32& retValue) {
  return TryParse(value, 10, retValue);
}

bool Int32::TryParse(const string& value, Int32& retValue) {
  return TryParse(value, 10, retValue);
}

bool Int32::TryParse(const string& str, int32 base, int32& value) {
  try {
    value = Parse(str, base);
  } catch (const Exception&) {
    return false;
  }
  return true;
}

bool Int32::TryParse(const string& str, int32 base, Int32& value) {
  return TryParse(str, base, value.value);
}

int32 Int32::GetHashCode() const {
  return this->value;
}

string Int32::ToString() const {
  return ToString("d", ref<IFormatProvider>::Null());
}

string Int32::ToString(const string& format) const {
  return ToString(format, ref<IFormatProvider>::Null());
}

string Int32::ToString(const string& format, const IFormatProvider&) const {
  int64 arg = Convert::ToInt64(this->value);
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch (type) {
  case 0:   return NumericalFormat::Format_Custom(arg, format);
  case 'b': return NumericalFormat::Format_B(arg, precision, 32);
  case 'd': return NumericalFormat::Format_D(arg, precision);
  case 'e': return NumericalFormat::Format_E(Convert::ToInt64(this->value), precision == 0 ? 10 : precision, false);
  case 'E': return NumericalFormat::Format_E(Convert::ToInt64(this->value), precision == 0 ? 10 : precision, true);
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
  case 'X': return NumericalFormat::Format_X(arg, precision, true,  8);
  }
  return format;
}

int32 Int32::CompareTo(const Int32& value) const {
  return this->value - value.value;
}

int32 Int32::CompareTo(const IComparable& obj) const {
  if (!is<Int32>(obj))
    return 1;
  return CompareTo(static_cast<const Int32&>(obj));
}

TypeCode Int32::GetTypeCode() const {
  return TypeCode::Int32;
}

bool Int32::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte Int32::ToByte(const IFormatProvider&) const {
  if (this->value < Byte::MinValue)
    throw OverflowException(caller_);

  if (this->value > Byte::MaxValue)
    throw OverflowException(caller_);

  return (byte)this->value;
}

char32 Int32::ToChar(const IFormatProvider&) const {
  if (this->value < 0 || this->value > static_cast<int32>(Char::MaxValue))
    throw OverflowException(caller_);

  return char32(this->value);
}

DateTime Int32::ToDateTime(const IFormatProvider&) const {
  return DateTime((int64)this->value);
}

double Int32::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 Int32::ToInt16(const IFormatProvider&) const {
  if (this->value < Int16::MinValue)
    throw OverflowException(caller_);

  if (this->value > Int16::MaxValue)
    throw OverflowException(caller_);

  return (int16)this->value;
}

int32 Int32::ToInt32(const IFormatProvider&) const {
  return this->value;
}

int64 Int32::ToInt64(const IFormatProvider&) const {
  return (int64)this->value;
}

uint16 Int32::ToUInt16(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(caller_);

  if (this->value > UInt16::MaxValue)
    throw OverflowException(caller_);

  return (uint16)this->value;
}

uint32 Int32::ToUInt32(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(caller_);

  return (uint32)this->value;
}

uint64 Int32::ToUInt64(const IFormatProvider&) const {
  if (this->value < 0)
    throw OverflowException(caller_);

  return (uint64)this->value;
}

sbyte Int32::ToSByte(const IFormatProvider&) const {
  if (this->value < SByte::MinValue)
    throw OverflowException(caller_);

  if (this->value > SByte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)this->value;
}

float Int32::ToSingle(const IFormatProvider&) const {
  return (float)this->value;
}

string Int32::ToString(const IFormatProvider&) const {
  return ToString();
}

Int32::operator int32() const {
  return this->value;
}

Int32& Int32::operator =(const Int32& value) {
  this->value = value.value;
  return *this;
}

Int32& Int32::operator +=(const Int32& value) {
  this->value += value.value;
  return *this;
}

Int32& Int32::operator -=(const Int32& value) {
  this->value -= value.value;
  return *this;
}

Int32& Int32::operator *=(const Int32& value) {
  this->value *= value.value;
  return *this;
}

Int32& Int32::operator /=(const Int32& value) {
  if (value == 0)
    throw DivideByZeroException(caller_);

  this->value /= value.value;
  return *this;
}

Int32& Int32::operator %=(const Int32& value) {
  if (value == 0)
    throw DivideByZeroException(caller_);

  this->value %= value;
  return *this;
}

Int32& Int32::operator &=(const Int32& value) {
  this->value &= value.value;
  return *this;
}

Int32& Int32::operator |=(const Int32& value) {
  this->value |= value.value;
  return *this;
}

Int32& Int32::operator ^=(const Int32& value) {
  this->value ^= value.value;
  return *this;
}

Int32& Int32::operator <<=(const Int32& value) {
  this->value <<= value.value;
  return *this;
}

Int32& Int32::operator >>=(const Int32& value) {
  this->value >>= value.value;
  return *this;
}

Int32& Int32::operator ++() {
  ++this->value;
  return *this;
}

const Int32 Int32::operator ++(int) {
  return this->value++;
}

Int32& Int32::operator --() {
  --this->value;
  return *this;
}

const Int32 Int32::operator --(int) {
  return this->value--;
}

