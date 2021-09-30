#include "../../include/Switch/GetHashCode.hpp"
#include "../../include/Switch/System/Byte.hpp"
#include "../../include/Switch/System/Boolean.hpp"
#include "../../include/Switch/System/Char.hpp"
#include "../../include/Switch/System/Decimal.hpp"
#include "../../include/Switch/System/Double.hpp"
#include "../../include/Switch/System/SByte.hpp"
#include "../../include/Switch/System/Int16.hpp"
#include "../../include/Switch/System/Int32.hpp"
#include "../../include/Switch/System/Int64.hpp"
#include "../../include/Switch/System/IntPtr.hpp"
#include "../../include/Switch/System/Single.hpp"
#include "../../include/Switch/System/String.hpp"
#include "../../include/Switch/System/UInt16.hpp"
#include "../../include/Switch/System/UInt32.hpp"
#include "../../include/Switch/System/UInt64.hpp"

int32 Switch::GetHashCode(const void* value) {
  return int32(int64(value) & 0x00000000FFFFFFFF) ^ int32((int64(value) >> 32) & 0x00000000FFFFFFFF);
}

int32 Switch::GetHashCode(const NullPtr&) {
  return 0;
}

int32 Switch::GetHashCode(const bool& value) {
  return System::Boolean(value).GetHashCode();
}

int32 Switch::GetHashCode(const sbyte& value) {
  return System::SByte(value).GetHashCode();
}

int32 Switch::GetHashCode(const char& value) {
  return System::Char(value).GetHashCode();
}

int32 Switch::GetHashCode(const char16& value) {
  return System::Char(value).GetHashCode();
}

int32 Switch::GetHashCode(const char32& value) {
  return System::Char(value).GetHashCode();
}

int32 Switch::GetHashCode(const wchar& value) {
  return System::Char(value).GetHashCode();
}

int32 Switch::GetHashCode(const int16& value) {
  return System::Int16(value).GetHashCode();
}

int32 Switch::GetHashCode(const int32& value) {
  return System::Int32(value).GetHashCode();
}

int32 Switch::GetHashCode(const int64& value) {
  return System::Int64(value).GetHashCode();
}

int32 Switch::GetHashCode(const llong& value) {
  return System::Int64(value).GetHashCode();
}

int32 Switch::GetHashCode(const byte& value) {
  return System::Byte(value).GetHashCode();
}

int32 Switch::GetHashCode(const uint16& value) {
  return System::UInt16(value).GetHashCode();
}

int32 Switch::GetHashCode(const uint32& value) {
  return System::UInt32(value).GetHashCode();
}

int32 Switch::GetHashCode(const uint64& value) {
  return System::UInt64(value).GetHashCode();
}

int32 Switch::GetHashCode(const ullong& value) {
  return System::UInt64(value).GetHashCode();
}

int32 Switch::GetHashCode(const double& value) {
  return System::Double(value).GetHashCode();
}

int32 Switch::GetHashCode(const float& value) {
  return System::Single(value).GetHashCode();
}
