#include "../../../../../include/Switch/System/Runtime/Serialization/SerializationInfo.hpp"
#include "../../../../../include/Switch/System/Convert.hpp"
#include "../../../../../include/Switch/System/SystemException.hpp"
#include "../../../../../include/Switch/System/Runtime/Serialization/ISerializable.hpp"

using namespace System;
using namespace System::Runtime::Serialization;

void SerializationInfo::AddValue(const string& name, const string& value) {
  AddValue(name, refptr<object>(new String(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const Boolean& value) {
  AddValue(name, refptr<object>(new Boolean(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const Byte& value) {
  AddValue(name, refptr<object>(new Byte(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const SByte& value) {
  AddValue(name, refptr<object>(new SByte(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const Char& value) {
  AddValue(name, refptr<object>(new Char(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const DateTime& value) {
  AddValue(name, refptr<object>(new DateTime(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const Single& value) {
  AddValue(name, refptr<object>(new Single(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const Double& value) {
  AddValue(name, refptr<object>(new Double(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const Int16& value) {
  AddValue(name, refptr<object>(new Int16(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const Int32& value) {
  AddValue(name, refptr<object>(new Int32(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const Int64& value) {
  AddValue(name, refptr<object>(new Int64(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const UInt16& value) {
  AddValue(name, refptr<object>(new UInt16(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const UInt32& value) {
  AddValue(name, refptr<object>(new UInt32(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const UInt64& value) {
  AddValue(name, refptr<object>(new UInt64(value)), value.GetType().Name());
}

void SerializationInfo::AddValue(const string& name, const ISerializable& value) {
  const object& obj = as<object>(value);
  AddValue(name, value, obj.GetType().FullName());
}

void SerializationInfo::AddValue(const string& name, const ISerializable& value, const string& typeName) {
  refptr<SerializationInfo> infos = new SerializationInfo();
  infos->SetObjectType(typeName);
  value.GetObjectData(*infos);

  mItems.Add(name, SerializationEntry(infos.ChangeType<object>(), typeName));
}

void SerializationInfo::AddValue(const string& name, refptr<Object> value, const string& typeName) {
  if (value == null)
    throw ArgumentNullException(caller_);

  mItems.Add(name, SerializationEntry(value, typeName));
}

void SerializationInfo::AddValue(const string& name, bool value)  {
  AddValue(name, Boolean(value));
}

void SerializationInfo::AddValue(const string& name, byte value)  {
  AddValue(name, Byte(value));
}

void SerializationInfo::AddValue(const string& name, int16 value) {
  AddValue(name, Int16(value));
}

void SerializationInfo::AddValue(const string& name, int32 value) {
  AddValue(name, Int32(value));
}

void SerializationInfo::AddValue(const string& name, int64 value) {
  AddValue(name, Int64(value));
}

void SerializationInfo::AddValue(const string& name, sbyte value) {
  AddValue(name, SByte(value));
}

void SerializationInfo::AddValue(const string& name, float value) {
  AddValue(name, Single(value));
}

void SerializationInfo::AddValue(const string& name, double value) {
  AddValue(name, Double(value));
}

void SerializationInfo::AddValue(const string& name, uint16 value) {
  AddValue(name, UInt16(value));
}

void SerializationInfo::AddValue(const string& name, uint32 value) {
  AddValue(name, UInt32(value));
}

void SerializationInfo::AddValue(const string& name, char32 value) {
  AddValue(name, Char(value));
}

System::Collections::Generic::Enumerator<System::Collections::Generic::KeyValuePair<string, SerializationEntry >> SerializationInfo::GetEnumerator() const {
  return mItems.GetEnumerator();
}

bool SerializationInfo::GetBoolean(const string& name) const {
  return GetValue<Boolean>(name).ToObject();
}

byte SerializationInfo::GetByte(const string& name) const {
  return GetValue<Byte>(name).ToObject();
}

sbyte SerializationInfo::GetSByte(const string& name) const {
  return GetValue<SByte>(name).ToObject();
}

int16 SerializationInfo::GetInt16(const string& name) const {
  return GetValue<Int16>(name).ToObject();
}

int32 SerializationInfo::GetInt32(const string& name) const {
  return GetValue<Int32>(name).ToObject();
}

int64 SerializationInfo::GetInt64(const string& name) const {
  return GetValue<Int64>(name).ToObject();
}

uint16 SerializationInfo::GetUInt16(const string& name) const {
  return GetValue<UInt16>(name).ToObject();
}

uint32 SerializationInfo::GetUInt32(const string& name) const {
  return GetValue<UInt32>(name).ToObject();
}

uint64 SerializationInfo::GetUInt64(const string& name) const {
  return GetValue<UInt64>(name).ToObject();
}

float SerializationInfo::GetSingle(const string& name) const {
  return GetValue<Single>(name).ToObject();
}

double SerializationInfo::GetDouble(const string& name) const {
  return GetValue<Double>(name).ToObject();
}

string SerializationInfo::GetString(const string& name) const {
  return GetValue<string>(name).ToObject();
}

const object& SerializationInfo::GetObject(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  return entry.Value().ToObject();
}

template<>
refptr<Boolean> SerializationInfo::GetValue<Boolean>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<Boolean>(entry.Value().ToObject()))
    return entry.Value().ChangeType<Boolean>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new Boolean(Convert::ToBoolean(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<string> SerializationInfo::GetValue<string>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<string>(entry.Value().ToObject()))
    return entry.Value().ChangeType<string>();
  else
    return new String(entry.Value()->ToString());
}

template<>
refptr<Byte> SerializationInfo::GetValue<Byte>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<Byte>(entry.Value().ToObject()))
    return entry.Value().ChangeType<Byte>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new Byte(Convert::ToByte(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<SByte> SerializationInfo::GetValue<SByte>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<SByte>(entry.Value().ToObject()))
    return entry.Value().ChangeType<SByte>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new SByte(Convert::ToSByte(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<Char> SerializationInfo::GetValue<Char>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<Char>(entry.Value().ToObject()))
    return entry.Value().ChangeType<Char>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new Char(Convert::ToChar(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<DateTime> SerializationInfo::GetValue<DateTime>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<DateTime>(entry.Value().ToObject()))
    return entry.Value().ChangeType<DateTime>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new DateTime(Convert::ToDateTime(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<Single> SerializationInfo::GetValue<Single>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<Single>(entry.Value().ToObject()))
    return entry.Value().ChangeType<Single>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new Single(Convert::ToSingle(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<Double> SerializationInfo::GetValue<Double>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<Double>(entry.Value().ToObject()))
    return entry.Value().ChangeType<Double>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new Double(Convert::ToDouble(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<Int16> SerializationInfo::GetValue<Int16>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<Int16>(entry.Value().ToObject()))
    return entry.Value().ChangeType<Int16>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new Int16(Convert::ToInt16(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<Int32> SerializationInfo::GetValue<Int32>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<Int32>(entry.Value().ToObject()))
    return entry.Value().ChangeType<Int32>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new Int32(Convert::ToInt32(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<Int64> SerializationInfo::GetValue<Int64>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<Int64>(entry.Value().ToObject()))
    return entry.Value().ChangeType<Int64>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new Int64(Convert::ToInt64(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<UInt16> SerializationInfo::GetValue<UInt16>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<UInt16>(entry.Value().ToObject()))
    return entry.Value().ChangeType<UInt16>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new UInt16(Convert::ToUInt16(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<UInt32> SerializationInfo::GetValue<UInt32>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<UInt32>(entry.Value().ToObject()))
    return entry.Value().ChangeType<UInt32>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new UInt32(Convert::ToUInt32(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}

template<>
refptr<UInt64> SerializationInfo::GetValue<UInt64>(const string& name) const {
  const SerializationEntry& entry = mItems[name];
  if (is<UInt64>(entry.Value().ToObject()))
    return entry.Value().ChangeType<UInt64>();
  else if (is<IConvertible>(entry.Value().ToObject()))
    return new UInt64(Convert::ToUInt64(entry.Value().ChangeType<IConvertible>().ToObject()));
  else
    throw SerializationException(caller_);
}
