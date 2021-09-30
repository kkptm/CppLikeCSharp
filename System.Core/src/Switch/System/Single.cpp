#include "../../../include/Switch/System/Single.hpp"
#include "../../../include/Switch/System/Convert.hpp"
#include "../../../include/Switch/System/DivideByZeroException.hpp"
#include "../../../include/Switch/System/Math.hpp"
#include "../../../include/Switch/System/SystemException.hpp"
#include "../../../include/Switch/System/NumericalFormat.hpp"

using namespace System;

constexpr float Single::Epsilon;

constexpr float Single::MaxValue;

constexpr float Single::MinValue;

constexpr float Single::NaN;

constexpr float Single::NegativeInfinity;

constexpr float Single::PositiveInfinity;

float Single::Parse(const string& str) {
  return Convert::ToSingle(atof(str.ToCCharArray().Data()));
}

bool Single::IsInfinity(float value) {
  return (IsNegativeInfinity(value) || IsPositiveInfinity(value));
}

bool Single::IsNaN(float value) {
  return value != value;
}

bool Single::IsNegativeInfinity(float value) {
  return value == NegativeInfinity;
}

bool Single::IsPositiveInfinity(float value) {
  return value == PositiveInfinity;
}

bool Single::Equals(const Single& value) const {
  return (this->value == value.value);
}

bool Single::Equals(const object& obj) const {
  return is<Single>(obj) && Equals(static_cast<const Single&>(obj));
}

int32 Single::GetHashCode() const {
  return *((int32*)&this->value);
}

string Single::ToString() const {
  return ToString("G", ref<IFormatProvider>::Null());
}

string Single::ToString(const string& format) const {
  return ToString(format, ref<IFormatProvider>::Null());
}

string Single::ToString(const string& format, const IFormatProvider&) const {
  if (IsNaN(this->value))
    return "NaN";
  if (IsNegativeInfinity(this->value))
    return "-Infinity";
  if (IsPositiveInfinity(this->value))
    return "Infinity";

  double arg = Convert::ToDouble(this->value);
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch (type) {
  case 0:   return NumericalFormat::Format_Custom(arg, format);
  case 'b': throw FormatException(caller_);
  case 'd': throw FormatException(caller_);
  case 'e': return NumericalFormat::Format_E(Convert::ToDouble(this->value), precision == 0 ? 7 : precision, false);
  case 'E': return NumericalFormat::Format_E(Convert::ToDouble(this->value), precision == 0 ? 7 : precision, true);
  case 'f':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_F(arg, precision);
  case 'g':
  case 'G': {
    if (precision == 0) precision = 7;
    return NumericalFormat::Format_G(arg, precision, type == 'G');
  }
  case 'n':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_N(arg, precision);
  case 'p':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_P(arg, precision);
  case 'x': throw FormatException(caller_);
  case 'X': throw FormatException(caller_);
  }
  return format;
}

int32 Single::CompareTo(const Single& value) const {
  if (this->value > value.value)
    return 1;

  if (this->value < value.value)
    return  -1;

  return 0;
}

int32 Single::CompareTo(const IComparable& obj) const {
  if (!is<Single>(obj))
    return 1;

  return CompareTo(static_cast<const Single&>(obj));
}

TypeCode Single::GetTypeCode() const {
  return TypeCode::Single;
}

bool Single::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte Single::ToByte(const IFormatProvider&) const {
  if (this->value < Byte::MinValue)
    throw OverflowException(caller_);

  if (this->value > Byte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)Math::Round(this->value);
}

char32 Single::ToChar(const IFormatProvider&) const {
  if (this->value < Char::MinValue)
    throw OverflowException(caller_);

  if (this->value > Char::MaxValue)
    throw OverflowException(caller_);

  return (char)Math::Round(this->value);
}

DateTime Single::ToDateTime(const IFormatProvider&) const {
  if (DateTime(static_cast<int64>(this->value)) < DateTime::MinValue)
    throw OverflowException(caller_);

  if (DateTime(static_cast<int64>(this->value)) > DateTime::MaxValue)
    throw OverflowException(caller_);

  return DateTime((int64)Math::Round(this->value));
}

double Single::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 Single::ToInt16(const IFormatProvider&) const {
  if (this->value < Int16::MinValue)
    throw OverflowException(caller_);

  if (this->value > Int16::MaxValue)
    throw OverflowException(caller_);

  return (int16)Math::Round(this->value);
}

int32 Single::ToInt32(const IFormatProvider&) const {
  if (this->value < Int32::MinValue)
    throw OverflowException(caller_);

  if (this->value > Int32::MaxValue)
    throw OverflowException(caller_);

  return (int32)Math::Round(this->value);
}

int64 Single::ToInt64(const IFormatProvider&) const {
  if (this->value < Int64::MinValue)
    throw OverflowException(caller_);

  if (this->value > Int64::MaxValue)
    throw OverflowException(caller_);

  return (int64)Math::Round(this->value);
}

uint16 Single::ToUInt16(const IFormatProvider&) const {
  if (this->value < UInt16::MinValue)
    throw OverflowException(caller_);

  if (this->value > UInt16::MaxValue)
    throw OverflowException(caller_);

  return (uint16)Math::Round(this->value);
}

uint32 Single::ToUInt32(const IFormatProvider&) const {
  if (this->value < UInt32::MinValue)
    throw OverflowException(caller_);

  if (this->value > UInt32::MaxValue)
    throw OverflowException(caller_);

  return (uint32)Math::Round(this->value);
}

uint64 Single::ToUInt64(const IFormatProvider&) const {
  if (this->value < UInt64::MinValue)
    throw OverflowException(caller_);

  if (this->value > UInt64::MaxValue)
    throw OverflowException(caller_);

  return (uint64)Math::Round(this->value);
}

sbyte Single::ToSByte(const IFormatProvider&) const {
  if (this->value < SByte::MinValue)
    throw OverflowException(caller_);

  if (this->value > SByte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)Math::Round(this->value);
}

float Single::ToSingle(const IFormatProvider&) const {
  return this->value;
}

string Single::ToString(const IFormatProvider&) const {
  return ToString();
}

Single::operator float() const {
  return this->value;
}

Single& Single::operator =(const Single& value) {
  this->value = value.value;
  return *this;
}

Single& Single::operator +=(const Single& value) {
  this->value += value.value;
  return *this;
}

Single& Single::operator -=(const Single& value) {
  this->value -= value.value;
  return *this;
}

Single& Single::operator*=(const Single& value) {
  this->value *= value.value;
  return *this;
}

Single& Single::operator /=(const Single& value) {
  if (value == 0)
    throw DivideByZeroException(caller_);

  this->value /= value.value;
  return *this;
}

Single& Single::operator++() {
  ++this->value;
  return *this;
}

const Single Single::operator++(int) {
  return this->value++;
}

Single& Single::operator--() {
  --this->value;
  return *this;
}

const Single Single::operator--(int) {
  return this->value--;
}

