/// @file
/// @brief Contains Switch::System::Hash class.
#pragma once

#include "System/Object.hpp"
#include "NullPtr.hpp"
#include "Types.hpp"
#include "RefPtr.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Generate a hash code for generic type T.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32  An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  template<typename T>
  int32 GetHashCode(const refptr<T>& value) {
    return int32(int64(value.ToPointer()) & 0x00000000FFFFFFFF) ^ int32((int64(value.ToPointer()) >> 32) & 0x00000000FFFFFFFF);
  }

  /// @brief Generate a hash code for void*.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const void* e);

  /// @brief Generate a hash code for NullPtr.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const NullPtr& value);

  /// @brief Generate a hash code for bool.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const bool& value);

  /// @brief Generate a hash code for signed 8-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const sbyte& value);

  /// @brief  Generate a hash code for char.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const char& value);

  /// @brief Generate a hash code for char16.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const char16& value);

  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const char32& value);

  /// @brief Generate a hash code for wchar.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const wchar& value);

  /// @brief Generate a hash code for signed 16-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const int16& value);

  /// @brief Generate a hash code for signed 32-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const int32& value);

  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const int64& value);

  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const llong& value);

  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const byte& value);

  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const uint16& value);

  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const uint32& value);

  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const ullong& value);

  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const uint64& value);

  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const double& value);

  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  core_export_ int32 GetHashCode(const float& value);

  /// @cond
  struct HasherFromObject {
    template <typename Object>
    int32 operator()(const Object& value) {return value.GetHashCode();}
  };

  struct HasherFromEnum {
    template <typename Enum>
    int32 operator()(const Enum& value) {return int32(int64(value) & 0x00000000FFFFFFFF) ^ int32((int64(value) >> 32) & 0x00000000FFFFFFFF);}
  };

  struct HasherFromOther {
    template <typename Other>
    int32 operator()(const Other& value) {return int32(int64(&value) & 0x00000000FFFFFFFF) ^ int32((int64(&value) >> 32) & 0x00000000FFFFFFFF);}
  };
  /// @endcond

  /// @brief Generate a hash code for generic type T.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  template<typename TValue>
  int32 GetHashCode(const TValue* value) {
    using Hasher = typename std::conditional<std::is_base_of<object, TValue>::value, HasherFromObject, typename std::conditional<std::is_enum<TValue>::value, HasherFromEnum, HasherFromOther>::type>::type;
    Hasher hasher;
    return hasher(*value);
  }

  /// @brief Generate a hash code for generic type T.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  template<typename TValue>
  int32 GetHashCode(const TValue& value) {
    using Hasher = typename std::conditional<std::is_base_of<object, TValue>::value, HasherFromObject, typename std::conditional<std::is_enum<TValue>::value, HasherFromEnum, HasherFromOther>::type>::type;
    Hasher hasher;
    return hasher(value);
  }
}

using namespace Switch;
