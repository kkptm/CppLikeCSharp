#include "../../include/Switch/Boxing.hpp"
#include "../../include/Switch/System/Boolean.hpp"
#include "../../include/Switch/System/Byte.hpp"
#include "../../include/Switch/System/Char.hpp"
#include "../../include/Switch/System/DateTime.hpp"
#include "../../include/Switch/System/Decimal.hpp"
#include "../../include/Switch/System/Double.hpp"
#include "../../include/Switch/System/IComparable.hpp"
#include "../../include/Switch/System/Int16.hpp"
#include "../../include/Switch/System/Int32.hpp"
#include "../../include/Switch/System/Int64.hpp"
#include "../../include/Switch/System/IntPtr.hpp"
#include "../../include/Switch/System/Object.hpp"
#include "../../include/Switch/System/SByte.hpp"
#include "../../include/Switch/System/_String.hpp"
#include "../../include/Switch/System/Single.hpp"
#include "../../include/Switch/System/UInt16.hpp"
#include "../../include/Switch/System/UInt32.hpp"
#include "../../include/Switch/System/UInt64.hpp"
#include "../../include/Switch/System/UIntPtr.hpp"

System::Boolean TypeBoxer::Boxing(bool value) {
  return value;
}

System::Byte TypeBoxer::Boxing(byte value) {
  return value;
}

System::Double TypeBoxer::Boxing(double value) {
  return value;
}

System::Int16 TypeBoxer::Boxing(int16 value) {
  return value;
}

System::Int32 TypeBoxer::Boxing(int32 value) {
  return value;
}

System::Int64 TypeBoxer::Boxing(int64 value) {
  return value;
}

System::SByte TypeBoxer::Boxing(sbyte value) {
  return value;
}

System::Single TypeBoxer::Boxing(float value) {
  return value;
}

System::String TypeBoxer::Boxing(const char* value) {
  return value;
}

System::String TypeBoxer::Boxing(const wchar* value) {
  return value;
}

System::String TypeBoxer::Boxing(const char16* value) {
  return value;
}

System::String TypeBoxer::Boxing(const char32* value) {
  return value;
}

System::Char TypeBoxer::Boxing(char value) {
  return value;
}

System::Char TypeBoxer::Boxing(wchar value) {
  return value;
}

System::Char TypeBoxer::Boxing(char16 value) {
  return value;
}

System::Char TypeBoxer::Boxing(char32 value) {
  return value;
}

System::UInt16 TypeBoxer::Boxing(uint16 value) {
  return value;
}

System::UInt32 TypeBoxer::Boxing(uint32 value) {
  return value;
}

System::UInt64 TypeBoxer::Boxing(uint64 value) {
  return value;
}

System::Int64 TypeBoxer::Boxing(llong value) {
  return value;
}

System::UInt64 TypeBoxer::Boxing(ullong value) {
  return value;
}

System::IntPtr TypeBoxer::Boxing(void* value) {
  return (intptr)value;
}

bool TypeUnboxer::Unboxing(const System::Boolean& value) {
  return value;
}

byte TypeUnboxer::Unboxing(const System::Byte& value) {
  return value;
}

double TypeUnboxer::Unboxing(const System::Double& value) {
  return value;
}

System::DateTime TypeUnboxer::Unboxing(const System::DateTime& value) {
  return value;
}

int16 TypeUnboxer::Unboxing(const System::Int16& value) {
  return value;
}

int32 TypeUnboxer::Unboxing(System::Int32& value) {
  return value;
}

int32 TypeUnboxer::Unboxing(const System::Int32& value) {
  return value;
}

int64 TypeUnboxer::Unboxing(const System::Int64& value) {
  return value;
}

intptr TypeUnboxer::Unboxing(const System::IntPtr& value) {
  return value;
}

sbyte TypeUnboxer::Unboxing(const System::SByte& value) {
  return value;
}

float TypeUnboxer::Unboxing(const System::Single& value) {
  return value;
}

const char* TypeUnboxer::Unboxing(const System::String& value) {
  return value.Data;
}

char32 TypeUnboxer::Unboxing(const System::Char& value) {
  return value;
}

uint16 TypeUnboxer::Unboxing(const System::UInt16& value) {
  return value;
}

uint32 TypeUnboxer::Unboxing(const System::UInt32& value) {
  return value;
}

uint64 TypeUnboxer::Unboxing(const System::UInt64& value) {
  return value;
}

uintptr TypeUnboxer::Unboxing(const System::UIntPtr& value) {
  return value;
}

System::Boolean Switch::Box(bool value) {
  return TypeBoxer::Boxing(value);
}

System::Byte Switch::Box(byte value) {
  return TypeBoxer::Boxing(value);
}

System::Double Switch::Box(double value) {
  return TypeBoxer::Boxing(value);
}

System::Int16 Switch::Box(int16 value) {
  return TypeBoxer::Boxing(value);
}

System::Int32 Switch::Box(int32 value) {
  return TypeBoxer::Boxing(value);
}

System::Int64 Switch::Box(int64 value) {
  return TypeBoxer::Boxing(value);
}

System::SByte Switch::Box(sbyte value) {
  return TypeBoxer::Boxing(value);
}

System::Single Switch::Box(float value) {
  return TypeBoxer::Boxing(value);
}

System::String Switch::Box(const char* value) {
  return TypeBoxer::Boxing(value);
}

System::String Switch::Box(const wchar* value) {
  return TypeBoxer::Boxing(value);
}

System::String Switch::Box(const char16* value) {
  return TypeBoxer::Boxing(value);
}

System::String Switch::Box(const char32* value) {
  return TypeBoxer::Boxing(value);
}

System::Char Switch::Box(char value) {
  return TypeBoxer::Boxing(value);
}

System::Char Switch::Box(wchar value) {
  return TypeBoxer::Boxing(value);
}

System::Char Switch::Box(char16 value) {
  return TypeBoxer::Boxing(value);
}

System::Char Switch::Box(char32 value) {
  return TypeBoxer::Boxing(value);
}

System::UInt16 Switch::Box(uint16 value) {
  return TypeBoxer::Boxing(value);
}

System::UInt32 Switch::Box(uint32 value) {
  return TypeBoxer::Boxing(value);
}

System::UInt64 Switch::Box(uint64 value) {
  return TypeBoxer::Boxing(value);
}

System::Int64 Switch::Box(llong value) {
  return TypeBoxer::Boxing(value);
}

System::UInt64 Switch::Box(ullong value) {
  return TypeBoxer::Boxing(value);
}

System::IntPtr Switch::Box(void* value) {
  return TypeBoxer::Boxing(value);
}

bool Switch::Unbox(const System::Boolean& value) {
  return TypeUnboxer::Unboxing(value);
}

byte Switch::Unbox(const System::Byte& value) {
  return TypeUnboxer::Unboxing(value);
}

double Switch::Unbox(const System::Double& value) {
  return TypeUnboxer::Unboxing(value);
}

System::DateTime Switch::Unbox(const System::DateTime& value) {
  return TypeUnboxer::Unboxing(value);
}

int16 Switch::Unbox(const System::Int16& value) {
  return TypeUnboxer::Unboxing(value);
}

int32 Switch::Unbox(System::Int32& value) {
  return TypeUnboxer::Unboxing(value);
}

int32 Switch::Unbox(const System::Int32& value) {
  return TypeUnboxer::Unboxing(value);
}

int64 Switch::Unbox(const System::Int64& value) {
  return TypeUnboxer::Unboxing(value);
}

intptr Switch::Unbox(const System::IntPtr& value) {
  return TypeUnboxer::Unboxing(value);
}

sbyte Switch::Unbox(const System::SByte& value) {
  return TypeUnboxer::Unboxing(value);
}

float Switch::Unbox(const System::Single& value) {
  return TypeUnboxer::Unboxing(value);
}

const char* Switch::Unbox(const System::String& value) {
  return TypeUnboxer::Unboxing(value);
}

char32 Switch::Unbox(const System::Char& value) {
  return TypeUnboxer::Unboxing(value);
}

uint16 Switch::Unbox(const System::UInt16& value) {
  return TypeUnboxer::Unboxing(value);
}

uint32 Switch::Unbox(const System::UInt32& value) {
  return TypeUnboxer::Unboxing(value);
}

uint64 Switch::Unbox(const System::UInt64& value) {
  return TypeUnboxer::Unboxing(value);
}

uintptr Switch::Unbox(const System::UIntPtr& value) {
  return TypeUnboxer::Unboxing(value);
}
