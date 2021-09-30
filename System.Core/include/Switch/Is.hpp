/// @file
/// @brief Contains Switch::is <> operator.
#pragma once

#include "Ref.hpp"
#include "RefPtr.hpp"
#include "Types.hpp"

namespace Switch {
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  /// @ingroup Switch
  template<typename TT, typename T>
  bool is(const ref<T>& value) {
    return value.template Is<TT>();
  }

  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  /// @ingroup Switch
  template<typename TT, typename T>
  bool is(ref<T>& value) {
    return value.template Is<TT>();
  }

  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  /// @ingroup Switch
  template<typename TT, typename T>
  bool is(const refptr<T>& value) {
    return value.template Is<TT>();
  }

  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  /// @ingroup Switch
  template<typename TT, typename T>
  bool is(refptr<T>& value) {
    return value.template Is<TT>();
  }

  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  /// @ingroup Switch
  template<typename TT, typename T>
  bool is(const T* value) {
    try {
      if (value == null)
        return false;
      return dynamic_cast<const TT*>(value) != null;
    } catch (const std::bad_cast&) {
      return false;
    }
  }

  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  template<typename TT, typename T>
  bool is(T* value) {
    try {
      if (value == null)
        return false;
      return dynamic_cast<TT*>(value) != null;
    } catch (const std::bad_cast&) {
      return false;
    }
  }

  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  /// @ingroup Switch
  template<typename TT, typename T>
  bool is(const T& value) {
    return is<TT>(&value);
  }

  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  /// @ingroup Switch
  template<typename TT, typename T>
  bool is(T& value) {
    return is<TT>(&value);
  }

  template<typename T>
  inline bool is(int32 value) {
    return false;
  }

  template<>
  inline bool is<int32>(int32 value) {
    return true;
  }

  template<typename T>
  inline bool is(double value) {
    return false;
  }

  template<>
  inline bool is<double>(double value) {
    return true;
  }

  template<typename T>
  inline bool is(float value) {
    return false;
  }

  template<>
  inline bool is<float>(float value) {
    return true;
  }
}

using namespace Switch;
