/// @file
/// @brief Contains Switch::operator""_b, Switch::operator""_c, Switch::operator""_s, ... operators.
#pragma once

#include "System/Type.hpp"

/// @cond
namespace Switch {
  namespace System {
    struct Boolean;
    struct Byte;
    struct Char;
    struct DateTime;
    struct Decimal;
    struct Double;
    struct Int16;
    struct Int32;
    struct Int64;
    struct IntPtr;
    struct SByte;
    class String;
    struct Single;
    struct UInt16;
    struct UInt32;
    struct UInt64;
    struct UIntPtr;
  }
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Used to convert specified value into byte:
  /// @code
  /// System::Console::WriteLine(1.6_b);
  /// @endcode
  byte core_export_ operator""_b(long double n);

  /// @brief Used to convert specified value into byte:
  /// @code
  /// System::Console::WriteLine(54_b);
  /// @endcode
  byte core_export_ operator""_b(unsigned long long n);

  /// @brief Used to convert specified value into byte:
  /// @code
  /// System::Console::WriteLine("125"_b);
  /// @endcode
  byte core_export_ operator""_b(const char* s, size_t);

  /// @brief Used to convert specified value into char32:
  /// @code
  /// System::Console::WriteLine('a'_c);
  /// @endcode
  char32 core_export_ operator""_c(char c);

  /// @brief Used to convert specified value into char32:
  /// @code
  /// System::Console::WriteLine(u'a'_C);
  /// @endcode
  char32 core_export_ operator""_c(char16 c);

  /// @brief Used to convert specified value into char32:
  /// @code
  /// System::Console::WriteLine(U'a'_c);
  /// @endcode
  char32 core_export_ operator""_c(char32 c);

  /// @brief Used to convert specified value into char32:
  /// @code
  /// System::Console::WriteLine(L'a'_c);
  /// @endcode
  char32 core_export_ operator""_c(wchar c);

  /// @brief Used to convert specified value into char32:
  /// @code
  /// System::Console::WriteLine(49_c);
  /// @endcode
  char32 core_export_ operator""_c(unsigned long long c);

  /// @brief Used to convert specified value into double:
  /// @code
  /// System::Console::WriteLine(1.6_d);
  /// @endcode
  double core_export_ operator""_d(long double n);

  /// @brief Used to convert specified value into System::Double:
  /// @code
  /// System::Console::WriteLine(5436_d);
  /// @endcode
  double core_export_ operator""_d(unsigned long long n);

  /// @brief Used to convert specified value into double:
  /// @code
  /// System::Console::WriteLine("12.5"_d);
  /// @endcode
  double core_export_ operator""_d(const char* s, size_t);

  /// @brief Used to convert specified value into int16:
  /// @code
  /// System::Console::WriteLine(5436_s16);
  /// @endcode
  int16 core_export_ operator""_s16(unsigned long long n);

  /// @brief Used to convert specified value into int16:
  /// @code
  /// System::Console::WriteLine(1.6_s16);
  /// @endcode
  int16 core_export_ operator""_s16(long double n);

  /// @brief Used to convert specified value into int16:
  /// @code
  /// System::Console::WriteLine("125"_s16);
  /// @endcode
  int16 core_export_ operator""_s16(const char* s, size_t);

  /// @brief Used to convert specified value into int32:
  /// @code
  /// System::Console::WriteLine(5436_s32);
  /// @endcode
  int32 core_export_ operator""_s32(unsigned long long n);

  /// @brief Used to convert specified value into int32:
  /// @code
  /// System::Console::WriteLine(1.6_s32);
  /// @endcode
  int32 core_export_ operator""_s32(long double n);

  /// @brief Used to convert specified value into int32:
  /// @code
  /// System::Console::WriteLine("125"_s32);
  /// @endcode
  int32 core_export_ operator""_s32(const char* s, size_t);

  /// @brief Used to convert specified value into int64:
  /// @code
  /// System::Console::WriteLine(5436_s64);
  /// @endcode
  int64 core_export_ operator""_s64(unsigned long long n);

  /// @brief Used to convert specified value into int64:
  /// @code
  /// System::Console::WriteLine(1.6_s64);
  /// @endcode
  int64 core_export_ operator""_s64(long double n);

  /// @brief Used to convert specified value into int64:
  /// @code
  /// System::Console::WriteLine("125"_s64);
  /// @endcode
  int64 core_export_ operator""_s64(const char* s, size_t);

  /// @brief Used to convert specified value into sbyte:
  /// @code
  /// System::Console::WriteLine(1.6_sb);
  /// @endcode
  sbyte core_export_ operator""_sb(long double n);

  /// @brief Used to convert specified value into sbyte:
  /// @code
  /// System::Console::WriteLine(54_sb);
  /// @endcode
  sbyte core_export_ operator""_sb(unsigned long long n);

  /// @brief Used to convert specified value into sbyte:
  /// @code
  /// System::Console::WriteLine("125"_S64);
  /// @endcode
  sbyte core_export_ operator""_sb(const char* s, size_t);

  /// @brief Used to convert specified value into single:
  /// @code
  /// System::Console::WriteLine(1.6_F);
  /// @endcode
  float core_export_ operator""_f(long double n);

  /// @brief Used to convert specified value into single:
  /// @code
  /// System::Console::WriteLine(5436_F);
  /// @endcode
  float core_export_ operator""_f(unsigned long long n);

  /// @brief Used to convert specified value into single:
  /// @code
  /// System::Console::WriteLine("12.5"_f);
  /// @endcode
  float core_export_ operator""_f(const char* s, size_t);

  /// @brief Used to convert specified value into uint16:
  /// @code
  /// System::Console::WriteLine(5436_u16);
  /// @endcode
  uint16 core_export_ operator""_u16(unsigned long long n);

  /// @brief Used to convert specified value into uint16:
  /// @code
  /// System::Console::WriteLine(1.6_u16);
  /// @endcode
  uint16 core_export_ operator""_u16(long double n);

  /// @brief Used to convert specified value into uint16:
  /// @code
  /// System::Console::WriteLine("125"_u16);
  /// @endcode
  uint16 core_export_ operator""_u16(const char* s, size_t);

  /// @brief Used to convert specified value into uint32:
  /// @code
  /// System::Console::WriteLine(5436_u32);
  /// @endcode
  uint32 core_export_ operator""_u32(unsigned long long n);

  /// @brief Used to convert specified value into uint32:
  /// @code
  /// System::Console::WriteLine(1.6_u32);
  /// @endcode
  uint32 core_export_ operator""_u32(long double n);

  /// @brief Used to convert specified value into uint32:
  /// @code
  /// System::Console::WriteLine("125"_u32);
  /// @endcode
  uint32 core_export_ operator""_u32(const char* s, size_t);

  /// @brief Used to convert specified value into uint64:
  /// @code
  /// System::Console::WriteLine(5436_u64);
  /// @endcode
  uint64 core_export_ operator""_u64(unsigned long long n);

  /// @brief Used to convert specified value into uint64:
  /// @code
  /// System::Console::WriteLine(1.6_u64);
  /// @endcode
  uint64 core_export_ operator""_u64(long double n);

  /// @brief Used to convert specified value into uint64:
  /// @code
  /// System::Console::WriteLine("125"_u64);
  /// @endcode
  uint64 core_export_ operator""_u64(const char* s, size_t);

  /// @brief Used to convert specified value into System::Byte:
  /// @code
  /// System::Console::WriteLine(1.6_B);
  /// @endcode
  System::Byte core_export_ operator""_B(long double n);

  /// @brief Used to convert specified value into System::Byte:
  /// @code
  /// System::Console::WriteLine(54_B);
  /// @endcode
  System::Byte core_export_ operator""_B(unsigned long long n);

  /// @brief Used to convert specified value into System::Byte:
  /// @code
  /// System::Console::WriteLine("125"_B);
  /// @endcode
  System::Byte core_export_ operator""_B(const char* s, size_t);

  /// @brief Used to convert specified value into System::Char:
  /// @code
  /// System::Console::WriteLine('a'_C);
  /// @endcode
  System::Char core_export_ operator""_C(char c);

  /// @brief Used to convert specified value into System::Char:
  /// @code
  /// System::Console::WriteLine(u'a'_C);
  /// @endcode
  System::Char core_export_ operator""_C(char16 c);

  /// @brief Used to convert specified value into System::Char:
  /// @code
  /// System::Console::WriteLine(U'a'_C);
  /// @endcode
  System::Char core_export_ operator""_C(char32 c);

  /// @brief Used to convert specified value into System::Char:
  /// @code
  /// System::Console::WriteLine(L'a'_C);
  /// @endcode
  System::Char core_export_ operator""_C(wchar c);

  /// @brief Used to convert specified value into System::Char:
  /// @code
  /// System::Console::WriteLine(49_C);
  /// @endcode
  System::Char core_export_ operator""_C(unsigned long long c);

  /// @brief Used to convert specified value into System::Double:
  /// @code
  /// System::Console::WriteLine(1.6_D);
  /// @endcode
  System::Double core_export_ operator""_D(long double n);

  /// @brief Used to convert specified value into System::Double:
  /// @code
  /// System::Console::WriteLine(5436_D);
  /// @endcode
  System::Double core_export_ operator""_D(unsigned long long n);

  /// @brief Used to convert specified value into System::Double:
  /// @code
  /// System::Console::WriteLine("12.5"_D);
  /// @endcode
  System::Double core_export_ operator""_D(const char* s, size_t);

  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = "This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  System::String core_export_ operator""_s(const char* s, size_t);

  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = u"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  System::String core_export_ operator""_s(const char16* s, size_t);

  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = U"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  System::String core_export_ operator""_s(const char32* s, size_t);

  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = L"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  System::String core_export_ operator""_s(const wchar* s, size_t);

  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = "This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  System::String core_export_ operator""_S(const char* s, size_t);

  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = u"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  System::String core_export_ operator""_S(const char16* s, size_t);

  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = U"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  System::String core_export_ operator""_S(const char32* s, size_t);

  /// @brief Used to convert specified value into System::String:
  /// @code
  /// Switch::string s = L"This is a "_S + "simple test"_S;
  /// System::Console::WriteLine(s);
  /// @endcode
  System::String core_export_ operator""_S(const wchar* s, size_t);

  /// @brief Used to convert specified value into System::Int16:
  /// @code
  /// System::Console::WriteLine(5436_S16);
  /// @endcode
  System::Int16 core_export_ operator""_S16(unsigned long long n);

  /// @brief Used to convert specified value into System::Int16:
  /// @code
  /// System::Console::WriteLine(1.6_S16);
  /// @endcode
  System::Int16 core_export_ operator""_S16(long double n);

  /// @brief Used to convert specified value into System::Int16:
  /// @code
  /// System::Console::WriteLine("125"_S16);
  /// @endcode
  System::Int16 core_export_ operator""_S16(const char* s, size_t);

  /// @brief Used to convert specified value into System::Int32:
  /// @code
  /// System::Console::WriteLine(5436_S32);
  /// @endcode
  System::Int32 core_export_ operator""_S32(unsigned long long n);

  /// @brief Used to convert specified value into System::Int32:
  /// @code
  /// System::Console::WriteLine(1.6_S32);
  /// @endcode
  System::Int32 core_export_ operator""_S32(long double n);

  /// @brief Used to convert specified value into System::Int32:
  /// @code
  /// System::Console::WriteLine("125"_S32);
  /// @endcode
  System::Int32 core_export_ operator""_S32(const char* s, size_t);

  /// @brief Used to convert specified value into System::Int64:
  /// @code
  /// System::Console::WriteLine(5436_S64);
  /// @endcode
  System::Int64 core_export_ operator""_S64(unsigned long long n);

  /// @brief Used to convert specified value into System::Int64:
  /// @code
  /// System::Console::WriteLine(1.6_S64);
  /// @endcode
  System::Int64 core_export_ operator""_S64(long double n);

  /// @brief Used to convert specified value into System::Int64:
  /// @code
  /// System::Console::WriteLine("125"_S64);
  /// @endcode
  System::Int64 core_export_ operator""_S64(const char* s, size_t);

  /// @brief Used to convert specified value into System::SByte:
  /// @code
  /// System::Console::WriteLine(1.6_SB);
  /// @endcode
  System::SByte core_export_ operator""_SB(long double n);

  /// @brief Used to convert specified value into System::SByte:
  /// @code
  /// System::Console::WriteLine(54_SB);
  /// @endcode
  System::SByte core_export_ operator""_SB(unsigned long long n);

  /// @brief Used to convert specified value into System::SByte:
  /// @code
  /// System::Console::WriteLine("125"_SB);
  /// @endcode
  System::SByte core_export_ operator""_SB(const char* s, size_t);

  /// @brief Used to convert specified value into System::Single:
  /// @code
  /// System::Console::WriteLine(1.6_F);
  /// @endcode
  System::Single core_export_ operator""_F(long double n);

  /// @brief Used to convert specified value into System::Single:
  /// @code
  /// System::Console::WriteLine(5436_F);
  /// @endcode
  System::Single core_export_ operator""_F(unsigned long long n);

  /// @brief Used to convert specified value into System::Single:
  /// @code
  /// System::Console::WriteLine("12.5"_F);
  /// @endcode
  System::Single core_export_ operator""_F(const char* s, size_t);

  /// @brief Used to convert specified value into System::UInt16:
  /// @code
  /// System::Console::WriteLine(5436_U16);
  /// @endcode
  System::UInt16 core_export_ operator""_U16(unsigned long long n);

  /// @brief Used to convert specified value into System::UInt16:
  /// @code
  /// System::Console::WriteLine(1.6_U16);
  /// @endcode
  System::UInt16 core_export_ operator""_U16(long double n);

  /// @brief Used to convert specified value into System::UInt16:
  /// @code
  /// System::Console::WriteLine("125"_U16);
  /// @endcode
  System::UInt16 core_export_ operator""_U16(const char* s, size_t);

  /// @brief Used to convert specified value into System::UInt32:
  /// @code
  /// System::Console::WriteLine(5436_U32);
  /// @endcode
  System::UInt32 core_export_ operator""_U32(unsigned long long n);

  /// @brief Used to convert specified value into System::UInt32:
  /// @code
  /// System::Console::WriteLine(1.6_U32);
  /// @endcode
  System::UInt32 core_export_ operator""_U32(long double n);

  /// @brief Used to convert specified value into System::UInt32:
  /// @code
  /// System::Console::WriteLine("125"_U32);
  /// @endcode
  System::UInt32 core_export_ operator""_U32(const char* s, size_t);

  /// @brief Used to convert specified value into System::UInt64:
  /// @code
  /// System::Console::WriteLine(5436_U64);
  /// @endcode
  System::UInt64 core_export_ operator""_U64(unsigned long long n);

  /// @brief Used to convert specified value into System::UInt64:
  /// @code
  /// System::Console::WriteLine(1.6_U64);
  /// @endcode
  System::UInt64 core_export_ operator""_U64(long double n);

  /// @brief Used to convert specified value into System::UInt64:
  /// @code
  /// System::Console::WriteLine("125"_U64);
  /// @endcode
  System::UInt64 core_export_ operator""_U64(const char* s, size_t);
}

using namespace Switch;
