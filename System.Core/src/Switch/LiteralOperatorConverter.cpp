#include "../../include/Switch/LiteralOperatorConverter.hpp"
#include "../../include/Switch/System/Convert.hpp"

byte Switch::operator""_b(long double n) {
  return System::Convert::ToByte(n);
}

byte Switch::operator""_b(unsigned long long n) {
  return System::Convert::ToByte(n);
}

byte Switch::operator""_b(const char* s, size_t) {
  return System::Convert::ToByte(s);
}

char32 Switch::operator""_c(char c) {
  return c;
}

char32 Switch::operator""_c(char16 c) {
  return c;
}

char32 Switch::operator""_c(char32 c) {
  return c;
}

char32 Switch::operator""_c(wchar c) {
  return c;
}

char32 Switch::operator""_c(unsigned long long c) {
  return (char32)c;
}

double Switch::operator""_d(long double n) {
  return System::Convert::ToDouble(n);
}

double Switch::operator""_d(unsigned long long n) {
  return System::Convert::ToDouble(n);
}

double Switch::operator""_d(const char* s, size_t) {
  return System::Convert::ToDouble(s);
}

int16 Switch::operator""_s16(unsigned long long n) {
  return System::Convert::ToInt16(n);
}

int16 Switch::operator""_s16(long double n) {
  return System::Convert::ToInt16(n);
}

int16 Switch::operator""_s16(const char* s, size_t) {
  return System::Convert::ToInt16(s);
}

int32 Switch::operator""_s32(unsigned long long n) {
  return System::Convert::ToInt32(n);
}

int32 Switch::operator""_s32(long double n) {
  return System::Convert::ToInt32(n);
}

int32 Switch::operator""_s32(const char* s, size_t) {
  return System::Convert::ToInt32(s);
}

int64 Switch::operator""_s64(unsigned long long n) {
  return System::Convert::ToInt64(n);
}

int64 Switch::operator""_s64(long double n) {
  return System::Convert::ToInt64(n);
}

int64 Switch::operator""_s64(const char* s, size_t) {
  return System::Convert::ToInt64(s);
}

sbyte Switch::operator""_sb(long double n) {
  return System::Convert::ToSByte(n);
}

sbyte Switch::operator""_sb(unsigned long long n) {
  return System::Convert::ToSByte(n);
}

sbyte Switch::operator""_sb(const char* s, size_t) {
  return System::Convert::ToSByte(s);
}

float Switch::operator""_f(long double n) {
  return System::Convert::ToSingle(n);
}

float Switch::operator""_f(unsigned long long n) {
  return System::Convert::ToSingle(n);
}

float Switch::operator""_f(const char* s, size_t) {
  return System::Convert::ToSingle(s);
}

uint16 Switch::operator""_u16(unsigned long long n) {
  return System::Convert::ToUInt16(n);
}

uint16 Switch::operator""_u16(long double n) {
  return System::Convert::ToUInt16(n);
}

uint16 Switch::operator""_u16(const char* s, size_t) {
  return System::Convert::ToUInt16(s);
}

uint32 Switch::operator""_u32(unsigned long long n) {
  return System::Convert::ToUInt32(n);
}

uint32 Switch::operator""_u32(long double n) {
  return System::Convert::ToUInt32(n);
}

uint32 Switch::operator""_u32(const char* s, size_t) {
  return System::Convert::ToUInt32(s);
}

uint64 Switch::operator""_u64(unsigned long long n) {
  return System::Convert::ToUInt64(n);
}

uint64 Switch::operator""_u64(long double n) {
  return System::Convert::ToUInt64(n);
}

uint64 Switch::operator""_u64(const char* s, size_t) {
  return System::Convert::ToUInt64(s);
}

System::Byte Switch::operator""_B(long double n) {
  return System::Byte(System::Convert::ToByte(n));
}

System::Byte Switch::operator""_B(unsigned long long n) {
  return System::Byte(System::Convert::ToByte(n));
}

System::Byte Switch::operator""_B(const char* s, size_t) {
  return System::Convert::ToByte(s);
}

System::Char Switch::operator""_C(char c) {
  return System::Char(c);
}

System::Char Switch::operator""_C(char16 c) {
  return System::Char(c);
}

System::Char Switch::operator""_C(char32 c) {
  return System::Char(c);
}

System::Char Switch::operator""_C(wchar c) {
  return System::Char(c);
}

System::Char Switch::operator""_C(unsigned long long c) {
  return System::Char((char32)c);
}

System::Double Switch::operator""_D(long double n) {
  return System::Double(System::Convert::ToDouble(n));
}

System::Double Switch::operator""_D(unsigned long long n) {
  return System::Double(System::Convert::ToDouble(n));
}

System::Double Switch::operator""_D(const char* s, size_t) {
  return System::Convert::ToDouble(s);
}

System::String Switch::operator""_s(const char* s, size_t) {
  return System::String(s);
}

System::String Switch::operator""_s(const char16* s, size_t) {
  return System::String(s);
}

System::String Switch::operator""_s(const char32* s, size_t) {
  return System::String(s);
}

System::String Switch::operator""_s(const wchar* s, size_t) {
  return System::String(s);
}

System::String Switch::operator""_S(const char* s, size_t) {
  return System::String(s);
}

System::String Switch::operator""_S(const char16* s, size_t) {
  return System::String(s);
}

System::String Switch::operator""_S(const char32* s, size_t) {
  return System::String(s);
}

System::String Switch::operator""_S(const wchar* s, size_t) {
  return System::String(s);
}

System::Int16 Switch::operator""_S16(unsigned long long n) {
  return System::Int16(System::Convert::ToInt16(n));
}

System::Int16 Switch::operator""_S16(long double n) {
  return System::Int16(System::Convert::ToInt16(n));
}

System::Int16 Switch::operator""_S16(const char* s, size_t) {
  return System::Convert::ToInt16(s);
}

System::Int32 Switch::operator""_S32(unsigned long long n) {
  return System::Int32(System::Convert::ToInt32(n));
}

System::Int32 Switch::operator""_S32(long double n) {
  return System::Int32(System::Convert::ToInt32(n));
}

System::Int32 Switch::operator""_S32(const char* s, size_t) {
  return System::Convert::ToInt32(s);
}

System::Int64 Switch::operator""_S64(unsigned long long n) {
  return System::Int64(System::Convert::ToInt64(n));
}

System::Int64 Switch::operator""_S64(long double n) {
  return System::Int64(System::Convert::ToInt64(n));
}

System::Int64 Switch::operator""_S64(const char* s, size_t) {
  return System::Convert::ToInt64(s);
}

System::SByte Switch::operator""_SB(long double n) {
  return System::SByte(System::Convert::ToSByte(n));
}

System::SByte Switch::operator""_SB(unsigned long long n) {
  return System::SByte(System::Convert::ToSByte(n));
}

System::SByte Switch::operator""_SB(const char* s, size_t) {
  return System::Convert::ToSByte(s);
}

System::Single Switch::operator""_F(long double n) {
  return System::Single(System::Convert::ToSingle(n));
}

System::Single Switch::operator""_F(unsigned long long n) {
  return System::Single(System::Convert::ToSingle(n));
}

System::Single Switch::operator""_F(const char* s, size_t) {
  return System::Convert::ToSingle(s);
}

System::UInt16 Switch::operator""_U16(unsigned long long n) {
  return System::UInt16(System::Convert::ToUInt16(n));
}

System::UInt16 Switch::operator""_U16(long double n) {
  return System::UInt16(System::Convert::ToUInt16(n));
}

System::UInt16 Switch::operator""_U16(const char* s, size_t) {
  return System::Convert::ToUInt16(s);
}

System::UInt32 Switch::operator""_U32(unsigned long long n) {
  return System::UInt32(System::Convert::ToUInt32(n));
}

System::UInt32 Switch::operator""_U32(long double n) {
  return System::UInt32(System::Convert::ToUInt32(n));
}

System::UInt32 Switch::operator""_U32(const char* s, size_t) {
  return System::Convert::ToUInt32(s);
}

System::UInt64 Switch::operator""_U64(unsigned long long n) {
  return System::UInt64(System::Convert::ToUInt64(n));
}

System::UInt64 Switch::operator""_U64(long double n) {
  return System::UInt64(System::Convert::ToUInt64(n));
}

System::UInt64 Switch::operator""_U64(const char* s, size_t) {
  return System::Convert::ToUInt64(s);
}
