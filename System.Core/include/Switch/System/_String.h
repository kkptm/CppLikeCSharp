#pragma once

#include <type_traits>
#include "../Any.hpp"
#include "../Boxing.hpp"
#include "Convert.hpp"
#include "Decimal.hpp"
#include "Enum.hpp"
#include "FormatProvider.hpp"
#include "SystemException.hpp"
#include "Type.hpp"

/// @cond
class __opaque_format_item__ {
  class refobj {
    template<typename T, typename B = ref<T>>
    class Factory {
      refobj operator()(const T& value) {return refiobj(value);}
    };

    template<typename T>
    class Factory<T, refptr<T>> {
      //class Factory<T, typename std::enable_if<std::is_base_of<refptr<T>, T>::value>::type> {
    public:
      refobj operator()(const T& value) {return refobj(new T(value));}
    };
  public:
    refobj() {}

    refobj(const refobj& refobj) : obj(refobj.obj), ptr(refobj.ptr) {}

    template<typename T>
    refobj(const T& value, bool clone) {
      if (clone == true)
        ptr = new T(value);
      else
        obj = value;
    }

    template<typename T>
    refobj(T* value) : ptr(value) {}

    const object& operator*() const { return this->ptr != null ? this->ptr() : this->obj(); }
    object& operator*() { return this->ptr != null ? this->ptr() : this->obj(); }

    bool operator==(const refobj& refobj) const {return this->obj == refobj.obj && this->ptr == refobj.ptr;}
    bool operator!=(const refobj& refobj) const {return !this->operator==(refobj);}

  private:
    ref<object> obj;
    refptr<object> ptr;
  };

  friend class Switch::System::String;
  template <typename T, typename Bool>
  struct EnumOrOtherToAny {};

  template <typename T>
  struct EnumOrOtherToAny<T, std::true_type> {
    refobj operator()(const T& value, bool clone) {return new System::Enum<T>(value);}
  };

  template <typename T>
  struct EnumOrOtherToAny<T, std::false_type> {
    refobj operator()(const T& value, bool clone) {return new System::IntPtr(*((intptr*)&value));}
  };

  template <typename T, typename Bool>
  struct ObjectOrOtherToAny {};

  template <typename T>
  struct ObjectOrOtherToAny<T, std::true_type> {
    refobj operator()(const T& value, bool clone) {return refobj(value, clone);}
  };

  template <typename T>
  struct ObjectOrOtherToAny<T, std::false_type> {
    refobj operator()(const T& value, bool clone) {return EnumOrOtherToAny<T, typename std::conditional<std::is_enum<T>::value, std::true_type, std::false_type>::type>()(value, clone);}
  };

  template <typename T>
  struct ObjectOrEnumOrOtherToAny {
    refobj operator()(const T& value, bool clone) {return ObjectOrOtherToAny<T, typename std::conditional<std::is_base_of<object, T>::value, std::true_type, std::false_type>::type>()(value, clone);}
  };

public:
  __opaque_format_item__() {}
  __opaque_format_item__(const __opaque_format_item__& any) : value(any.value) {}
  bool operator==(const __opaque_format_item__& any) const {return value == any.value;}
  bool operator!=(const __opaque_format_item__& any) const {return value != any.value;}

private:
  __opaque_format_item__(byte value) : value(new System::Byte(value)) {}
  __opaque_format_item__(char value) : value(new System::Char(value)) {}
  __opaque_format_item__(wchar value) : value(new System::Char(value)) {}
  __opaque_format_item__(char16 value) : value(new System::Char(value)) {}
  __opaque_format_item__(char32 value) : value(new System::Char(value)) {}
  __opaque_format_item__(Switch::decimal value) : value(new System::Decimal(value)) {}
  __opaque_format_item__(double value) : value(new System::Double(value)) {}
  __opaque_format_item__(int16 value) : value(new System::Int16(value)) {}
  __opaque_format_item__(int32 value) : value(new System::Int32(value)) {}
  __opaque_format_item__(int64 value) : value(new System::Int64(value)) {}
  __opaque_format_item__(bool value) : value(new System::Boolean(value)) {}
  __opaque_format_item__(const char* value) : value(new System::String(value)) {}
  __opaque_format_item__(char* value) : value(new System::String(value)) {}
  __opaque_format_item__(const unsigned char* value) : value(new System::String((const char*)value)) {}
  __opaque_format_item__(unsigned char* value) : value(new System::String((const char*)value)) {}
  __opaque_format_item__(const wchar* value) : value(new System::String(value)) {}
  __opaque_format_item__(wchar* value) : value(new System::String(value)) {}
  __opaque_format_item__(const char16* value) : value(new System::String(value)) {}
  __opaque_format_item__(char16* value) : value(new System::String(value)) {}
  __opaque_format_item__(const char32* value) : value(new System::String(value)) {}
  __opaque_format_item__(char32* value) : value(new System::String(value)) {}
  __opaque_format_item__(const std::string& value) : value(new System::String(value)) {}
  __opaque_format_item__(const std::wstring& value) : value(new System::String(value)) {}
  __opaque_format_item__(const std::u16string& value) : value(new System::String(value)) {}
  __opaque_format_item__(const std::u32string& value) : value(new System::String(value)) {}
  __opaque_format_item__(sbyte value) : value(new System::SByte(value)) {}
  __opaque_format_item__(float value) : value(new System::Single(value)) {}
  __opaque_format_item__(uint16 value) : value(new System::UInt16(value)) {}
  __opaque_format_item__(uint32 value) : value(new System::UInt32(value)) {}
  __opaque_format_item__(uint64 value) : value(new System::UInt64(value)) {}
  __opaque_format_item__(void* value) : value(new System::IntPtr((intptr)value)) {}
  __opaque_format_item__(llong value) : value(sizeof(long) == 8 ? (object*)new System::Int64(value) : (object*)new System::Int32(value)) {}
  __opaque_format_item__(ullong value) : value(sizeof(long) == 8 ? (object*)new System::UInt64(value) : (object*)new System::UInt32(value)) {}
  __opaque_format_item__(Any value) : value(new Any(value)) {}

  template<typename T, typename Attribute>
  __opaque_format_item__(const property_<const T&, Attribute>& value) : __opaque_format_item__(value()) {}

  template<typename T, typename Attribute>
  __opaque_format_item__(const property_<T, Attribute>& value) : __opaque_format_item__(value(), true) {}

  template<typename T>
  __opaque_format_item__(const T& value) : value(ObjectOrEnumOrOtherToAny<T>()(value, false)) {}

  const object& operator*() const {return *this->value;}
  object& operator*() {return *this->value;}
  const object& ToObject() const {return *this->value;}

private:
  __opaque_format_item__(byte value, bool clone) : value(new System::Byte(value)) {}
  __opaque_format_item__(char value, bool clone) : value(new System::Char(value)) {}
  __opaque_format_item__(wchar value, bool clone) : value(new System::Char(value)) {}
  __opaque_format_item__(char16 value, bool clone) : value(new System::Char(value)) {}
  __opaque_format_item__(char32 value, bool clone) : value(new System::Char(value)) {}
  __opaque_format_item__(Switch::decimal value, bool clone) : value(new System::Decimal(value)) {}
  __opaque_format_item__(double value, bool clone) : value(new System::Double(value)) {}
  __opaque_format_item__(int16 value, bool clone) : value(new System::Int16(value)) {}
  __opaque_format_item__(int32 value, bool clone) : value(new System::Int32(value)) {}
  __opaque_format_item__(int64 value, bool clone) : value(new System::Int64(value)) {}
  __opaque_format_item__(bool value, bool clone) : value(new System::Boolean(value)) {}
  __opaque_format_item__(const char* value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(char* value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(const unsigned char* value, bool clone) : value(new System::String((const char*)value)) {}
  __opaque_format_item__(unsigned char* value, bool clone) : value(new System::String((const char*)value)) {}
  __opaque_format_item__(const wchar* value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(wchar* value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(const char16* value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(char16* value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(const char32* value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(char32* value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(const std::string& value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(const std::wstring& value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(const std::u16string& value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(const std::u32string& value, bool clone) : value(new System::String(value)) {}
  __opaque_format_item__(sbyte value, bool clone) : value(new System::SByte(value)) {}
  __opaque_format_item__(float value, bool clone) : value(new System::Single(value)) {}
  __opaque_format_item__(uint16 value, bool clone) : value(new System::UInt16(value)) {}
  __opaque_format_item__(uint32 value, bool clone) : value(new System::UInt32(value)) {}
  __opaque_format_item__(uint64 value, bool clone) : value(new System::UInt64(value)) {}
  __opaque_format_item__(void* value, bool clone) : value(new System::IntPtr((intptr)value)) {}
  __opaque_format_item__(llong value, bool clone) : value(sizeof(long) == 8 ? (object*)new System::Int64(value) : (object*)new System::Int32(value)) {}
  __opaque_format_item__(ullong value, bool clone) : value(sizeof(long) == 8 ? (object*)new System::UInt64(value) : (object*)new System::UInt32(value)) {}
  __opaque_format_item__(Any value, bool clone) : value(new Any(value)) {}

  template<typename T>
  __opaque_format_item__(const T& value, bool clone) : value(ObjectOrEnumOrOtherToAny<T>()(value, clone)) {}

  refobj value;
};
/// @endcond

template<typename T>
System::String System::String::Concat(const System::Collections::Generic::IEnumerable<T>& objs) {
  int32 size = 0;;
  for (T item : objs)
    size += static_cast<int32>(System::Convert::ToString(item).string.length());

  StringType str;
  str.reserve(size);
  for (T item : objs)
    str.append(System::Convert::ToString(item).string);
  return str.c_str();
}

template<typename T, int32 length>
System::String System::String::Concat(const T(&objs)[length]) {
  if (objs == null)
    throw ArgumentNullException(caller_);

  int32 size = 0;
  for (int32 index = 0; index < length; index ++)
    size += System::Convert::ToString(objs[index]).string.length();

  StringType str;
  str.reserve(size);
  for (int32 index = 0; index < length; index ++)
    str.append(System::Convert::ToString(objs[index]).string);
  return str.c_str();
}

template<typename T>
System::String System::String::Join(const System::String& separator, const System::Array<T>& objs) {
  return Join(separator, objs, 0, objs.Length);
}

template<typename T>
System::String System::String::Join(const System::String& separator, const System::Array<T>& objs, int32 startIndex, int32 count) {
  if (startIndex < 0 || count < 0 || startIndex + count > objs.Length)
    throw ArgumentOutOfRangeException(caller_);
  System::String str;
  bool first = true;
  for (int32 i = startIndex; i < startIndex + count; i++) {
    if (first)
      first = false;
    else
      str += separator;
    str += System::Convert::ToString(objs[i]);
  }
  return str;
}

template<typename T>
System::String System::String::Join(const System::String& separator, const System::Collections::Generic::IEnumerable<T>& objs) {
  System::String str;
  bool first = true;
  System::Collections::Generic::Enumerator<T> enumerator = objs.GetEnumerator();
  while (enumerator.MoveNext()) {
    if (!first)
      str += separator;
    str += System::Convert::ToString(enumerator.Current);
    first = false;
  }
  return str;
}

template<typename T>
System::String System::String::Join(const System::String& separator, const System::Collections::Generic::IEnumerable<T>& objs, int32 startIndex, int32 count) {
  if (startIndex < 0 || count < 0 || startIndex + count > objs.Length)
    throw ArgumentOutOfRangeException(caller_);
  System::String str;
  bool first = true;
  int32 index = 0;
  System::Collections::Generic::Enumerator<T> enumerator = objs.GetEnumerator();
  while (enumerator.MoveNext()) {
    if (index < startIndex) continue;
    if (index++ > startIndex + count) break;
    if (!first)
      str += separator;
    str += System::Convert::ToString(enumerator.Current);
    first = false;
  }
  return str;
}

template<typename T, int32 len>
System::String System::String::Join(const System::String& separator, const T(&objs)[len]) {
  System::String str;
  bool first = true;

  for (int32 index = 0; index < len; index++) {
    if (first)
      first = false;
    else
      str += separator;
    str += System::Convert::ToString(objs[index]);
  }
  return str;
}

template<typename ...Args>
System::String System::String::Format(const System::String& format, const Args& ... args) {
  return System::String::FormatToString(System::FormatProvider(), format, System::Array<__opaque_format_item__> {args...});
}

template<typename ...Args>
System::String System::String::Format(const IFormatProvider& provider, const System::String& format, const Args& ... args) {
  return System::String::FormatToString(provider, format, System::Array<__opaque_format_item__> {args...});
}

using namespace Switch;
