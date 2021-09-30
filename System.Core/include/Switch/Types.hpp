/// @file
/// @brief Contains Switch::char16, Switch::int32, ... types.
#pragma once

#include <cstddef>
#include <cstdint>
#include <typeinfo>

#include "CoreExport.hpp"

#if defined(NDEBUG)
#  define RELEASE 1
#else
#  define DEBUG 1
#endif

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represents a 8-bit unsigned integer.
  /// @ingroup Types
  using byte = uint8_t;

  /// @brief Represents a 16-bit unicode character.
  /// @ingroup Types
  using char16 = char16_t;

  /// @brief Represents a 32-bit unicode character.
  /// @ingroup Types
  using char32 = char32_t;

  /// @brief Represents a decimal-precision floating-point number.
  /// @ingroup Types
  using decimal = long double;

  /// @brief Represents a 16-bit signed integer.
  /// @ingroup Types
  using int16 = int16_t;

  /// @brief Represents a 32-bit signed integer.
  /// @ingroup Types
  using int32 = int32_t;

  /// @brief Represents a 64-bit signed integer.
  /// @ingroup Types
  using int64 = int64_t;

  /// @brief Represent a pointer or a handle.
  /// @ingroup Types
  using intptr = intptr_t;

  /// @brief Represents a null pointer value.
  /// @par Examples
  /// @code
  /// refptr<Foo> foo = ref_new<Foo>();
  /// ...
  /// foo = null; // release the reference pointer.
  /// @endcode
  /// @ingroup Types
  static std::nullptr_t null;

  /// @brief Represents a 8-bit signed integer.
  /// @ingroup Types
  using sbyte = int8_t;

  /// @brief Represents a size of any object in bytes
  /// @ingroup Types
  using size = size_t;

  /// @brief Stores information about a type.
  /// @ingroup Types
  using type = std::type_info;

  /// @brief Represents a 8-bit unsigned integer.
  /// @ingroup Types
  using uchar = unsigned char;

  /// @brief Represents a 32-bit unsigned integer.
  /// @ingroup Types
  using uint = unsigned int;

  /// @brief Represents a 16-bit unsigned integer.
  /// @ingroup Types
  using uint16 = uint16_t;

  /// @brief Represents a 32-bit unsigned integer.
  /// @ingroup Types
  using uint32 = uint32_t;

  /// @brief Represents a 64-bit unsigned integer.
  /// @ingroup Types
  using uint64 = uint64_t;

  /// @brief Represent a pointer or a handle.
  /// @ingroup Types
  using uintptr = uintptr_t;

  /// @brief Represents a 16-bit unsigned integer.
  /// @ingroup Types
  using ushort = unsigned short;

  /// @brief Represents a 32-bit or 64-bit unsigned integer.
  /// @ingroup Types
  using ulong = unsigned long;

  /// @brief Represents a wide character.
  /// @ingroup Types
  using wchar = wchar_t;

  /// @cond
  #if defined(__linux__) && defined(_LP64)
  using llong = long long int;
  using ullong = unsigned long long int;
  #else
  using llong = long;
  using ullong = unsigned long;
  #endif
  /// @endcond
}

using namespace Switch;
