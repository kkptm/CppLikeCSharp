#include "../../include/Switch/Any.hpp"

Any::Any() {
}

Any::Any(const Any& any) : value(any.value) {
}

Any& Any::operator=(const Any& any) {
  this->value = any.value; return *this;
}

Any::Any(NullPtr value) {
}

Any::Any(bool value) : value(new System::Boolean(value)) {
}

Any::Any(byte value) : value(new System::Byte(value)) {
}

Any::Any(char value) : value(new System::Char(value)) {
}

Any::Any(wchar value) : value(new System::Char(value)) {
}

Any::Any(char16 value) : value(new System::Char(value)) {
}

Any::Any(char32 value) : value(new System::Char(value)) {
}

Any::Any(double value) : value(new System::Double(value)) {
}

Any::Any(int16 value) : value(new System::Int16(value)) {
}

Any::Any(int32 value) : value(new System::Int32(value)) {
}

Any::Any(int64 value) : value(new System::Int64(value)) {
}

Any::Any(const char* value) : value(new System::String(value)) {
}

Any::Any(char* value) : value(new System::String(value)) {
}

Any::Any(const unsigned char* value) : value(new System::String((const char*)value)) {
}

Any::Any(unsigned char* value) : value(new System::String((const char*)value)) {
}

Any::Any(const wchar* value) : value(new System::String(value)) {
}

Any::Any(wchar* value) : value(new System::String(value)) {
}

Any::Any(const char16* value) : value(new System::String(value)) {
}

Any::Any(char16* value) : value(new System::String(value)) {
}

Any::Any(const char32* value) : value(new System::String(value)) {
}

Any::Any(char32* value) : value(new System::String(value)) {
}

Any::Any(const std::string& value) : value(new System::String(value)) {
}

Any::Any(const std::wstring& value) : value(new System::String(value)) {
}

Any::Any(const std::u16string& value) : value(new System::String(value)) {
}

Any::Any(const std::u32string& value) : value(new System::String(value)) {
}

Any::Any(sbyte value) : value(new System::SByte(value)) {
}

Any::Any(float value) : value(new System::Single(value)) {
}

Any::Any(uint16 value) : value(new System::UInt16(value)) {
}

Any::Any(uint32 value) : value(new System::UInt32(value)) {
}

Any::Any(uint64 value) : value(new System::UInt64(value)) {
}

Any::Any(void* value) : value(new System::IntPtr((intptr)value)) {
}

Any::Any(llong value) : value(sizeof(long) == 8 ? (object*)new System::Int64(value) : (object*)new System::Int32(value)) {
}

Any::Any(ullong value) : value(sizeof(long) == 8 ? (object*)new System::UInt64(value) : (object*)new System::UInt32(value)) {
}

bool Any::operator==(NullPtr value) const {
  return !this->HasValue();
}

bool Any::operator==(bool value) const {
  return As<System::Boolean>() == value;
}

bool Any::operator==(byte value) const {
  return As<System::Byte>() == value;
}

bool Any::operator==(char value) const {
  return As<System::Char>() == char32(value);
}

bool Any::operator==(wchar value) const {
  return As<System::Char>() == char32(value);
}

bool Any::operator==(char16 value) const {
  return As<System::Char>() == value;
}

bool Any::operator==(char32 value) const {
  return As<System::Char>() == value;
}

bool Any::operator==(double value) const {
  return As<System::Double>() == value;
}

bool Any::operator==(int16 value) const {
  return As<System::Int16>() == value;
}

bool Any::operator==(int32 value) const {
  return As<System::Int32>() == value;
}

bool Any::operator==(int64 value) const {
  return As<System::Int64>() == value;
}

bool Any::operator==(const char* value) const {
  return As<System::String>() == value;
}

bool Any::operator==(char* value) const {
  return As<System::String>() == value;
}

bool Any::operator==(const wchar* value) const {
  return As<System::String>() == value;
}

bool Any::operator==(wchar* value) const {
  return As<System::String>() == value;
}

bool Any::operator==(const char16* value) const {
  return As<System::String>() == value;
}

bool Any::operator==(char16* value) const {
  return As<System::String>() == value;
}

bool Any::operator==(const char32* value) const {
  return As<System::String>() == value;
}

bool Any::operator==(char32* value) const {
  return As<System::String>() == value;
}

bool Any::operator==(const std::string& value) const {
  return As<System::String>() == value;
}

bool Any::operator==(const std::wstring& value) const {
  return As<System::String>() == value;
}

bool Any::operator==(const std::u16string& value) const {
  return As<System::String>() == value;
}

bool Any::operator==(const std::u32string& value) const {
  return As<System::String>() == value;
}

bool Any::operator==(sbyte value) const {
  return As<System::SByte>() == value;
}

bool Any::operator==(float value) const {
  return As<System::Single>() == value;
}

bool Any::operator==(uint16 value) const {
  return As<System::UInt16>() == value;
}

bool Any::operator==(uint32 value) const {
  return As<System::UInt32>() == value;
}

bool Any::operator==(uint64 value) const {
  return As<System::UInt64>() == value;
}

bool Any::operator==(void* value) const {
  return As<System::IntPtr>() == (intptr)value;
}

bool Any::operator==(llong value) const {
  return sizeof(long) == 8 ? As<System::Int64>() == value : As<System::Int32>() == value;
}

bool Any::operator==(ullong value) const {
  return sizeof(long) == 8 ? As<System::UInt64>() == value : As<System::UInt32>() == value;
}

int32 Any::CompareTo(const IComparable& obj) const {
  if (!is<Any>(obj)) return -1;
  return CompareTo(as<Any>(obj));
}

int32 Any::CompareTo(const Any& obj) const {
  if (this->value < obj.value) return -1;
  if (this->value > obj.value) return 1;
  return 0;
}

int32 Any::GetHashCode() const {
  if (!this->HasValue) return 0;
  return As<object>().GetHashCode();
}

bool Any::Equals(const object& obj) const {
  if (is<Any>(obj))
    return Equals(as<Any>(obj));
  return *this->value == obj;
}

bool Any::Equals(const Any& value) const {
  if (!this->HasValue && !value.HasValue) return true;
  return *this->value == *value.value;
}
