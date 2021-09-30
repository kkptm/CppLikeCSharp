#include <limits>
#include "../../../include/Switch/System/UInt64.hpp"
#include "../../../include/Switch/System/Byte.hpp"
#include "../../../include/Switch/System/Char.hpp"
#include "../../../include/Switch/System/DateTime.hpp"
#include "../../../include/Switch/System/DivideByZeroException.hpp"
#include "../../../include/Switch/System/Int16.hpp"
#include "../../../include/Switch/System/UInt16.hpp"
#include "../../../include/Switch/System/UInt32.hpp"
#include "../../../include/Switch/System/NumericalFormat.hpp"
#include "../../../include/Switch/System/NumericalParsing.hpp"
#include "../../../include/Switch/System/SByte.hpp"
#include "../../../include/Switch/System/SystemException.hpp"
#include "../../../include/Switch/System/TypeCode.hpp"

using namespace System;

constexpr uint64 UInt64::MaxValue;

constexpr uint64 UInt64::MinValue;

uint64 UInt64::Parse(const string& str) {
  return Parse(str, 10);
}

uint64 UInt64::Parse(const string& str, const int32 base) {
  return NumericalParsing::ParseUnsigned(str, base);
}

bool UInt64::TryParse(const string& str, uint64& value) {
  return TryParse(str, 10, value);
}

bool UInt64::TryParse(const string& str, UInt64& value) {
  return TryParse(str, 10, value);
}

bool UInt64::TryParse(const string& str, int32 base, uint64& value) {
  try {
    value = Parse(str, base);
  } catch (const Exception&) {
    return false;
  }
  return true;
}

bool UInt64::TryParse(const string& str, int32 base, UInt64& value) {
  return TryParse(str, base, value.value);
}

int32 UInt64::GetHashCode() const {
  int32 hash = 0;

  hash += (int32)(this->value & 0x00000000FFFFFFFF);
  hash = hash ^ (int32)((this->value >> 32) & 0x00000000FFFFFFFF);

  return hash;
}

string UInt64::ToString() const {
  return ToString("g", ref<IFormatProvider>::Null());
}

string UInt64::ToString(const string& format) const {
  return ToString(format, ref<IFormatProvider>::Null());
}

string UInt64::ToString(const string& format, const IFormatProvider&) const {
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch (type) {
  case 0:   return NumericalFormat::Format_Custom(this->value, format);
  case 'b': return NumericalFormat::Format_B(this->value, precision);
  case 'd': return NumericalFormat::Format_D(this->value, precision);
  case 'e': return NumericalFormat::Format_E(this->value, precision == 0 ? 20 : precision, false);
  case 'E': return NumericalFormat::Format_E(this->value, precision == 0 ? 20 : precision, true);
  case 'f':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_F(this->value, precision);
  case 'g':
  case 'G': {
    if (precision == 0) precision = 20;
    return NumericalFormat::Format_G(this->value, precision, type == 'G');
  }
  case 'n':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_N(this->value, precision);
  case 'p':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_P(this->value, precision);
  case 'x': return NumericalFormat::Format_X(this->value, precision, false, 16);
  case 'X': return NumericalFormat::Format_X(this->value, precision, true, 16);
  }
  return format;
}

int32 UInt64::CompareTo(const UInt64& value) const {
  if (this->value < value.value)
    return -1;

  if (this->value == value.value)
    return 0;

  return 1;
}

int32 UInt64::CompareTo(const IComparable& obj) const {
  if (!is<UInt64>(obj))
    return 1;

  return CompareTo((const UInt64&)obj);
}

TypeCode UInt64::GetTypeCode() const {
  return TypeCode::UInt64;
}

bool UInt64::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte UInt64::ToByte(const IFormatProvider&) const {
  if (this->value > Byte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)this->value;
}

char32 UInt64::ToChar(const IFormatProvider&) const {
  if (this->value > Char::MaxValue)
    throw OverflowException(caller_);

  return static_cast<uint32>(this->value);
}

DateTime UInt64::ToDateTime(const IFormatProvider&) const {
  if (this->value > static_cast<uint64>(DateTime::MaxValue.Ticks()))
    throw OverflowException(caller_);

  return DateTime((int64)this->value);
}

double UInt64::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 UInt64::ToInt16(const IFormatProvider&) const {
  if (this->value > (uint16)Int16::MaxValue)
    throw OverflowException(caller_);

  return (int16)this->value;
}

int32 UInt64::ToInt32(const IFormatProvider&) const {
  if (this->value > (uint32)Int32::MaxValue)
    throw OverflowException(caller_);

  return (int32)this->value;
}

int64 UInt64::ToInt64(const IFormatProvider&) const {
  if (this->value > (uint64)Int64::MaxValue)
    throw OverflowException(caller_);

  return (int64)this->value;
}

uint16 UInt64::ToUInt16(const IFormatProvider&) const {
  if (this->value > (uint64)UInt16::MaxValue)
    throw OverflowException(caller_);

  return (uint16)this->value;
}

uint32 UInt64::ToUInt32(const IFormatProvider&) const {
  if (this->value > UInt32::MaxValue)
    throw OverflowException(caller_);

  return (uint32)this->value;
}

uint64 UInt64::ToUInt64(const IFormatProvider&) const {
  return this->value;
}

sbyte UInt64::ToSByte(const IFormatProvider&) const {
  if (this->value > (byte)SByte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)this->value;
}

float UInt64::ToSingle(const IFormatProvider&) const {
  return (float)this->value;
}

string UInt64::ToString(const IFormatProvider&) const {
  return ToString();
}

UInt64::operator uint64() const {
  return this->value;
}

UInt64& UInt64::operator=(const UInt64& value) {
  this->value = value.value;
  return *this;
}

UInt64& UInt64::operator+=(const UInt64& value) {
  this->value += value.value;
  return *this;
}

UInt64& UInt64::operator-=(const UInt64& value) {
  this->value -= value.value;
  return *this;
}

UInt64& UInt64::operator*=(const UInt64& value) {
  this->value *= value.value;
  return *this;
}

UInt64& UInt64::operator /=(const UInt64& value) {
  if (value.value == 0)
    throw DivideByZeroException(caller_);

  this->value /= value.value;
  return *this;
}

UInt64& UInt64::operator %=(const UInt64& value) {
  if (value.value == 0)
    throw DivideByZeroException(caller_);

  this->value %= value;
  return *this;
}

UInt64& UInt64::operator &=(const UInt64& value) {
  this->value &= value.value;
  return *this;
}

UInt64& UInt64::operator |=(const UInt64& value) {
  this->value |= value.value;
  return *this;
}

UInt64& UInt64::operator ^=(const UInt64& value) {
  this->value ^= value.value;
  return *this;
}

UInt64& UInt64::operator<<=(const UInt64& value) {
  this->value <<= value.value;
  return *this;
}

UInt64& UInt64::operator>>=(const UInt64& value) {
  this->value >>= value.value;
  return *this;
}

UInt64& UInt64::operator++() {
  ++this->value;
  return *this;
}

const UInt64 UInt64::operator++(int) {
  return this->value++;
}

UInt64& UInt64::operator--() {
  --this->value;
  return *this;
}

const UInt64 UInt64::operator--(int) {
  return this->value--;
}

