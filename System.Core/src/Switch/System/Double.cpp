#include "../../../include/Switch/System/Double.hpp"
#include "../../../include/Switch/System/Byte.hpp"
#include "../../../include/Switch/System/Char.hpp"
#include "../../../include/Switch/System/DateTime.hpp"
#include "../../../include/Switch/System/DivideByZeroException.hpp"
#include "../../../include/Switch/System/Int16.hpp"
#include "../../../include/Switch/System/Int32.hpp"
#include "../../../include/Switch/System/Int64.hpp"
#include "../../../include/Switch/System/Math.hpp"
#include "../../../include/Switch/System/SByte.hpp"
#include "../../../include/Switch/System/Single.hpp"
#include "../../../include/Switch/System/SystemException.hpp"
#include "../../../include/Switch/System/TimeSpan.hpp"
#include "../../../include/Switch/System/UInt16.hpp"
#include "../../../include/Switch/System/UInt32.hpp"
#include "../../../include/Switch/System/UInt64.hpp"
#include "../../../include/Switch/System/NumericalFormat.hpp"

using namespace System;

constexpr double Double::Epsilon;

constexpr double Double::MaxValue;

constexpr double Double::MinValue;

constexpr double Double::NaN;

constexpr double Double::NegativeInfinity;

constexpr double Double::PositiveInfinity;

double Double::Parse(const String& str) {
  return atof(str.Data());
}

bool Double::Equals(const Double& value) const {
  return this->value == value;
}

bool Double::Equals(const object& obj) const {
  return is<Double>(obj) && Equals(static_cast<const Double&>(obj));
}

int32 Double::GetHashCode() const {
  return Int64(*((int64*)&this->value)).GetHashCode();
}

String Double::ToString() const {
  return ToString("G", ref<IFormatProvider>::Null());
}

String Double::ToString(const String& format) const {
  return ToString(format, ref<IFormatProvider>::Null());
}

String Double::ToString(const String& format, const IFormatProvider&) const {
  if (IsNaN(this->value))
    return "NaN";
  if (IsNegativeInfinity(this->value))
    return "-Infinity";
  if (IsPositiveInfinity(this->value))
    return "Infinity";

  int32 precision;
  double arg = this->value;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch (type) {
  case 0:   return NumericalFormat::Format_Custom(arg, format);
  case 'b': throw FormatException(caller_);
  case 'd': throw FormatException(caller_);
  case 'e': return NumericalFormat::Format_E(this->value, precision == 0 ? 15 : precision, false);
  case 'E': return NumericalFormat::Format_E(this->value, precision == 0 ? 15 : precision, true);
  case 'f':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_F(this->value, precision);
  case 'g':
  case 'G': {
    if (precision == 0) precision = 15;
    return NumericalFormat::Format_G(arg, precision, type == 'G');
  }
  case 'n':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_N(this->value, precision);
  case 'p':
    if (format.Length() == 1) precision = 2;
    return NumericalFormat::Format_P(this->value, precision);
  case 'x':
  case 'X': throw FormatException(caller_);
  }
  return format;
}

int32 Double::CompareTo(const Double& value) const {
  if (this->value > value)
    return 1;

  if (this->value < value.value)
    return -1;

  return 0;
}

int32 Double::CompareTo(const IComparable& obj) const {
  if (!is<Double>(obj))
    return 1;

  return CompareTo(static_cast<const Double&>(obj));
}

TypeCode Double::GetTypeCode() const {
  return TypeCode::Double;
}

bool Double::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte Double::ToByte(const IFormatProvider&) const {
  if (this->value < (double)Byte::MinValue)
    throw OverflowException(caller_);
  if (this->value > Byte::MaxValue)
    throw OverflowException(caller_);
  return static_cast<sbyte>(Math::Round(this->value));
}

char32 Double::ToChar(const IFormatProvider&) const {
  if (this->value < Char::MinValue)
    throw OverflowException(caller_);
  if (this->value > Char::MaxValue)
    throw OverflowException(caller_);
  return static_cast<char>(Math::Round(this->value));
}

DateTime Double::ToDateTime(const IFormatProvider&) const {
  if (DateTime(static_cast<int64>(this->value)) < DateTime::MinValue)
    throw OverflowException(caller_);
  if (DateTime(static_cast<int64>(this->value)) > DateTime::MaxValue)
    throw OverflowException(caller_);
  return DateTime((int64)Math::Round(this->value));
}

double Double::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 Double::ToInt16(const IFormatProvider&) const {
  if (this->value < Int16::MinValue)
    throw OverflowException(caller_);
  if (this->value > Int16::MaxValue)
    throw OverflowException(caller_);
  return (int16)Math::Round(this->value);
}

int32 Double::ToInt32(const IFormatProvider&) const {
  if (this->value < Int32::MinValue)
    throw OverflowException(caller_);
  if (this->value > Int32::MaxValue)
    throw OverflowException(caller_);
  return (int32)Math::Round(this->value);
}

int64 Double::ToInt64(const IFormatProvider&) const {
  if (this->value < Int64::MinValue)
    throw OverflowException(caller_);
  if (this->value > Int64::MaxValue)
    throw OverflowException(caller_);
  return (int64)Math::Round(this->value);
}

uint16 Double::ToUInt16(const IFormatProvider&) const {
  if (this->value < UInt16::MinValue)
    throw OverflowException(caller_);
  if (this->value > UInt16::MaxValue)
    throw OverflowException(caller_);
  return (uint16)Math::Round(this->value);
}

uint32 Double::ToUInt32(const IFormatProvider&) const {
  if (this->value < UInt32::MinValue)
    throw OverflowException(caller_);
  if (this->value > UInt32::MaxValue)
    throw OverflowException(caller_);
  return (uint32)Math::Round(this->value);
}

uint64 Double::ToUInt64(const IFormatProvider&) const {
  if (this->value < UInt64::MinValue)
    throw OverflowException(caller_);
  if (this->value > UInt64::MaxValue)
    throw OverflowException(caller_);
  return (uint64)Math::Round(this->value);
}

sbyte Double::ToSByte(const IFormatProvider&) const {
  if (this->value < SByte::MinValue)
    throw OverflowException(caller_);
  if (this->value > SByte::MaxValue)
    throw OverflowException(caller_);
  return (sbyte)Math::Round(this->value);
}

float Double::ToSingle(const IFormatProvider&) const {
  if (this->value < Single::MinValue)
    throw OverflowException(caller_);
  else if (this->value > Single::MaxValue)
    throw OverflowException(caller_);
  return (float)this->value;
}

String Double::ToString(const IFormatProvider&) const {
  return ToString();
}

Double::operator double() const {
  return this->value;
}

Double& Double::operator =(const Double& value) {
  this->value = value.value;
  return *this;
}

Double& Double::operator +=(const Double& value) {
  this->value += value.value;
  return *this;
}

Double& Double::operator -=(const Double& value) {
  this->value -= value.value;
  return *this;
}

Double& Double::operator *=(const Double& value) {
  this->value *= value.value;
  return *this;
}

Double& Double::operator /=(const Double& value) {
  if (value == 0)
    throw DivideByZeroException(caller_);

  this->value /= value.value;
  return *this;
}

Double& Double::operator ++() {
  ++this->value;
  return *this;
}

const Double Double::operator ++(int) {
  return this->value++;
}

Double& Double::operator --() {
  --this->value;
  return *this;
}

const Double Double::operator --(int) {
  return this->value--;
}

