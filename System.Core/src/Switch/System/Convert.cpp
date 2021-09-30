#include "../../../include/Switch/System/Convert.hpp"
#include "../../../include/Switch/System/InvalidCastException.hpp"
#include "../../../include/Switch/Any.hpp"

using namespace System;

IFormatProvider* Convert::provider = null;

void __throw_cast_exception__() {
  throw System::InvalidCastException(caller_);
}

byte Convert::ToByte(Any& value) {
  return ToByte(value.Value());
}

byte Convert::ToByte(const Any& value) {
  return ToByte(value.Value());
}

bool Convert::ToBoolean(Any& value) {
  return ToBoolean(value.Value());
}

bool Convert::ToBoolean(const Any& value) {
  return ToBoolean(value.Value());
}

char32 Convert::ToChar(Any& value) {
  return ToChar(value.Value());
}

char32 Convert::ToChar(const Any& value) {
  return ToChar(value.Value());
}

DateTime Convert::ToDateTime(Any& value) {
  return ToDateTime(value.Value());
}

DateTime Convert::ToDateTime(const Any& value) {
  return ToDateTime(value.Value());
}

double Convert::ToDouble(Any& value) {
  return ToDouble(value.Value());
}

double Convert::ToDouble(const Any& value) {
  return ToDouble(value.Value());
}

int16 Convert::ToInt16(Any& value) {
  return ToInt16(value.Value());
}

int16 Convert::ToInt16(const Any& value) {
  return ToInt16(value.Value());
}

int32 Convert::ToInt32(Any& value) {
  return ToInt32(value.Value());
}

int32 Convert::ToInt32(const Any& value) {
  return ToInt32(value.Value());
}

int64 Convert::ToInt64(Any& value) {
  return ToInt64(value.Value());
}

int64 Convert::ToInt64(const Any& value) {
  return ToInt64(value.Value());
}

sbyte Convert::ToSByte(Any& value) {
  return ToSByte(value.Value());
}

sbyte Convert::ToSByte(const Any& value) {
  return ToSByte(value.Value());
}

float Convert::ToSingle(Any& value) {
  return ToSingle(value.Value());
}

float Convert::ToSingle(const Any& value) {
  return ToSingle(value.Value());
}

uint16 Convert::ToUInt16(Any& value) {
  return ToUInt16(value.Value());
}

uint16 Convert::ToUInt16(const Any& value) {
  return ToUInt16(value.Value());
}

uint32 Convert::ToUInt32(Any& value) {
  return ToUInt32(value.Value());
}

uint32 Convert::ToUInt32(const Any& value) {
  return ToUInt32(value.Value());
}

uint64 Convert::ToUInt64(Any& value) {
  return ToUInt64(value.Value());
}

uint64 Convert::ToUInt64(const Any& value) {
  return ToUInt64(value.Value());
}

char32 Convert::ToChar(const DateTime& value) {
  return value.ToChar(*provider);
}

DateTime Convert::ToDateTime(const IConvertible& converter) {
  return converter.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(object& value) {
  return ToDateTime((const object&)value);
}

DateTime Convert::ToDateTime(const object& value) {
  if (is<Boolean>(value)) return ToDateTime(static_cast<const Boolean&>(value));
  if (is<Byte>(value)) return ToDateTime(static_cast<const Byte&>(value));
  if (is<Char>(value)) return ToDateTime(static_cast<const Char&>(value));
  if (is<DateTime>(value)) return ToDateTime(static_cast<const DateTime&>(value));
  if (is<Double>(value)) return ToDateTime(static_cast<const Double&>(value));
  if (is<Int16>(value)) return ToDateTime(static_cast<const Int16&>(value));
  if (is<Int32>(value)) return ToDateTime(static_cast<const Int32&>(value));
  if (is<Int64>(value)) return ToDateTime(static_cast<const Int64&>(value));
  if (is<SByte>(value)) return ToDateTime(static_cast<const SByte&>(value));
  if (is<Single>(value)) return ToDateTime(static_cast<const Single&>(value));
  if (is<String>(value)) return ToDateTime(static_cast<const String&>(value));
  if (is<UInt16>(value)) return ToDateTime(static_cast<const UInt16&>(value));
  if (is<UInt32>(value)) return ToDateTime(static_cast<const UInt32&>(value));
  if (is<UInt64>(value)) return ToDateTime(static_cast<const UInt64&>(value));
  throw InvalidCastException(caller_);
}

DateTime Convert::ToDateTime(bool value) {
  return Boolean(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const Boolean& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(byte value) {
  return Byte(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const Byte& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(char value) {
  return Char(value).ToDateTime(*provider);
}


DateTime Convert::ToDateTime(char32 value) {
  return Char(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const Char& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const DateTime& value) {
  return value;
}

DateTime Convert::ToDateTime(decimal value) {
  return Decimal(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(double value) {
  return Double(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const Double& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(int16 value) {
  return Int16(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const Int16& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(int32 value) {
  return Int32(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const Int32& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(int64 value) {
  return Int64(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const Int64& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(sbyte value) {
  return SByte(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const SByte& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(float value) {
  return Single(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const Single& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const char* value) {
  return DateTime::Parse(value);
}

DateTime Convert::ToDateTime(const String& value) {
  return DateTime::Parse(value);
}

DateTime Convert::ToDateTime(uint16 value) {
  return UInt16(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const UInt16& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(uint32 value) {
  return UInt32(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const UInt32& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(uint64 value) {
  return UInt64(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(const UInt64& value) {
  return value.ToDateTime(*provider);
}

DateTime Convert::ToDateTime(llong value) {
  return Int64(value).ToDateTime(*provider);
}

DateTime Convert::ToDateTime(ullong value) {
  return UInt64(value).ToDateTime(*provider);
}

double Convert::ToDouble(const DateTime& value) {
  return value.ToDouble(*provider);
}

int16 Convert::ToInt16(const DateTime& value) {
  return value.ToInt16(*provider);
}

int32 Convert::ToInt32(const DateTime& value) {
  return value.ToInt32(*provider);
}

int64 Convert::ToInt64(const DateTime& value) {
  return value.ToInt64(*provider);
}

sbyte Convert::ToSByte(const DateTime& value) {
  return value.ToSByte(*provider);
}

float Convert::ToSingle(const DateTime& value) {
  return value.ToSingle(*provider);
}

String Convert::ToString(const DateTime& value) {
  return value.ToString(*provider);
}

uint16 Convert::ToUInt16(const DateTime& value) {
  return value.ToUInt16(*provider);
}

uint32 Convert::ToUInt32(const DateTime& value) {
  return value.ToUInt32(*provider);
}

uint64 Convert::ToUInt64(const DateTime& value) {
  return value.ToUInt64(*provider);
}

