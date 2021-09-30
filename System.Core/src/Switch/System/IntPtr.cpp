#include "../../../include/Switch/System/IntPtr.hpp"
#include "../../../include/Switch/System/Array.hpp"
#include "../../../include/Switch/System/Int32.hpp"
#include "../../../include/Switch/System/Int64.hpp"
#include "../../../include/Switch/System/OverflowException.hpp"

using namespace System;

constexpr intptr IntPtr::Zero;

constexpr int32 IntPtr::Size;

IntPtr::IntPtr(const Int32& value) {
  this->value = (int32)value;
}

IntPtr::IntPtr(const Int64& value) {
  if (Size == 4 && (value < Int32::MinValue || value > Int32::MaxValue))
    throw OverflowException(caller_);

  this->value = (intptr)value;
}

IntPtr::IntPtr(intptr value) {
  this->value = value;
}

bool IntPtr::Equals(const IntPtr& value) const {
  return this->value == value.value;
}

bool IntPtr::Equals(const object& obj) const {
  return is<IntPtr>(obj) && Equals(static_cast<const IntPtr&>(obj));
}

int32 IntPtr::GetHashCode() const {
  int64 handleValue = (int64)this->value;
  int32 hash = 0;

  hash = static_cast<int32>(handleValue & 0x00000000FFFFFFFF);
  hash = hash ^ static_cast<int32>((handleValue >> 32) & 0x00000000FFFFFFFF);

  return hash;
}

int32 IntPtr::CompareTo(const IntPtr& value) const {
  return static_cast<int32>(this->value - value.value);
}

int32 IntPtr::CompareTo(const IComparable& obj) const {
  if (!is<IntPtr>(obj))
    return 1;
  return CompareTo(static_cast<const IntPtr&>(obj));
}

int32 IntPtr::ToInt32() const {
  if (Size == 8 && (this->value < Int32::MinValue || this->value > Int32::MaxValue))
    throw OverflowException(caller_);

  return *((int32*)&this->value);
}

int64 IntPtr::ToInt64() const {
  if (IntPtr::Size == 4)
    return *((int32*)&value);
  return int64(value);
}

void* IntPtr::ToPointer() const {
  return (void*)this->value;
}

string IntPtr::ToString() const {
  return Int64(ToInt64()).ToString();
}

string IntPtr::ToString(const string& format) const {
  return Int64(ToInt64()).ToString(format);
}

string IntPtr::ToString(const string& format, const IFormatProvider& formatProvider) const {
  return Int64(ToInt64()).ToString(format);
}

IntPtr::operator intptr() const {
  return this->value;
}

IntPtr& IntPtr::operator =(const IntPtr& value) {
  this->value = value.value;
  return *this;
}
