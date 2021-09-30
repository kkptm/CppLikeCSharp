#include "../../../include/Switch/System/Decimal.hpp"
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

constexpr decimal Decimal::Epsilon;

constexpr decimal Decimal::MaxValue;

constexpr decimal Decimal::MinValue;

constexpr decimal Decimal::NaN;

constexpr decimal Decimal::NegativeInfinity;

constexpr decimal Decimal::PositiveInfinity;

decimal Decimal::Parse(const String& str) {
  return atof(str.Data());
}

bool Decimal::Equals(const Decimal& value) const {
  return this->value == value;
}

bool Decimal::Equals(const object& obj) const {
  return is<Decimal>(obj) && Equals(static_cast<const Decimal&>(obj));
}

int32 Decimal::GetHashCode() const {
  return Int64(*((int64*)&this->value)).GetHashCode();
}

String Decimal::ToString() const {
  return ToString("G", ref<IFormatProvider>::Null());
}

String Decimal::ToString(const String& format) const {
  return ToString(format, ref<IFormatProvider>::Null());
}

String Decimal::ToString(const String& format, const IFormatProvider&) const {
  if (IsNaN(this->value))
    return "NaN";
  if (IsNegativeInfinity(this->value))
    return "-Infinity";
  if (IsPositiveInfinity(this->value))
    return "Infinity";

  int32 precision;
  decimal arg = this->value;
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

int32 Decimal::CompareTo(const Decimal& value) const {
  if (this->value > value)
    return 1;

  if (this->value < value.value)
    return -1;

  return 0;
}

int32 Decimal::CompareTo(const IComparable& obj) const {
  if (!is<Decimal>(obj))
    return 1;

  return CompareTo(static_cast<const Decimal&>(obj));
}

TypeCode Decimal::GetTypeCode() const {
  return TypeCode::Decimal;
}

bool Decimal::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte Decimal::ToByte(const IFormatProvider&) const {
  if (this->value < (decimal)Byte::MinValue)
    throw OverflowException(caller_);
  if (this->value > Byte::MaxValue)
    throw OverflowException(caller_);
  return static_cast<sbyte>(Math::Round(this->value));
}

char32 Decimal::ToChar(const IFormatProvider&) const {
  if (this->value < Char::MinValue)
    throw OverflowException(caller_);
  if (this->value > Char::MaxValue)
    throw OverflowException(caller_);
  return static_cast<char>(Math::Round(this->value));
}

DateTime Decimal::ToDateTime(const IFormatProvider&) const {
  if (DateTime(static_cast<int64>(this->value)) < DateTime::MinValue)
    throw OverflowException(caller_);
  if (DateTime(static_cast<int64>(this->value)) > DateTime::MaxValue)
    throw OverflowException(caller_);
  return DateTime((int64)Math::Round(this->value));
}

double Decimal::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 Decimal::ToInt16(const IFormatProvider&) const {
  if (this->value < Int16::MinValue)
    throw OverflowException(caller_);
  if (this->value > Int16::MaxValue)
    throw OverflowException(caller_);
  return (int16)Math::Round(this->value);
}

int32 Decimal::ToInt32(const IFormatProvider&) const {
  if (this->value < Int32::MinValue)
    throw OverflowException(caller_);
  if (this->value > Int32::MaxValue)
    throw OverflowException(caller_);
  return (int32)Math::Round(this->value);
}

int64 Decimal::ToInt64(const IFormatProvider&) const {
  if (this->value < Int64::MinValue)
    throw OverflowException(caller_);
  if (this->value > Int64::MaxValue)
    throw OverflowException(caller_);
  return (int64)Math::Round(this->value);
}

uint16 Decimal::ToUInt16(const IFormatProvider&) const {
  if (this->value < UInt16::MinValue)
    throw OverflowException(caller_);
  if (this->value > UInt16::MaxValue)
    throw OverflowException(caller_);
  return (uint16)Math::Round(this->value);
}

uint32 Decimal::ToUInt32(const IFormatProvider&) const {
  if (this->value < UInt32::MinValue)
    throw OverflowException(caller_);
  if (this->value > UInt32::MaxValue)
    throw OverflowException(caller_);
  return (uint32)Math::Round(this->value);
}

uint64 Decimal::ToUInt64(const IFormatProvider&) const {
  if (this->value < UInt64::MinValue)
    throw OverflowException(caller_);
  if (this->value > UInt64::MaxValue)
    throw OverflowException(caller_);
  return (uint64)Math::Round(this->value);
}

sbyte Decimal::ToSByte(const IFormatProvider&) const {
  if (this->value < SByte::MinValue)
    throw OverflowException(caller_);
  if (this->value > SByte::MaxValue)
    throw OverflowException(caller_);
  return (sbyte)Math::Round(this->value);
}

float Decimal::ToSingle(const IFormatProvider&) const {
  if (this->value < Single::MinValue)
    throw OverflowException(caller_);
  else if (this->value > Single::MaxValue)
    throw OverflowException(caller_);
  return (float)this->value;
}

String Decimal::ToString(const IFormatProvider&) const {
  return ToString();
}

Decimal::operator decimal() const {
  return this->value;
}

Decimal& Decimal::operator =(const Decimal& value) {
  this->value = value.value;
  return *this;
}

Decimal& Decimal::operator +=(const Decimal& value) {
  this->value += value.value;
  return *this;
}

Decimal& Decimal::operator -=(const Decimal& value) {
  this->value -= value.value;
  return *this;
}

Decimal& Decimal::operator *=(const Decimal& value) {
  this->value *= value.value;
  return *this;
}

Decimal& Decimal::operator /=(const Decimal& value) {
  if (value == 0)
    throw DivideByZeroException(caller_);

  this->value /= value.value;
  return *this;
}

Decimal& Decimal::operator ++() {
  ++this->value;
  return *this;
}

const Decimal Decimal::operator ++(int) {
  return this->value++;
}

Decimal& Decimal::operator --() {
  --this->value;
  return *this;
}

const Decimal Decimal::operator --(int) {
  return this->value--;
}

