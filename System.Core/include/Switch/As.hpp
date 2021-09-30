/// @file
/// @brief Contains Switch::as <> operator.
#pragma once

#include "Ref.hpp"
#include "RefPtr.hpp"

/// @cond
core_export_ void __throw_cast_exception__();
/// @endcond

namespace Switch {
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Switch
  template<typename TT, typename T>
  ref<TT> as(const ref<T>& value) {
    return value.template As<TT>();
  }

  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Switch
  template<typename TT, typename T>
  ref<TT> as(ref<T>& value) {
    return value.template As<TT>();
  }

  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Switch
  template<typename TT, typename T>
  refptr<TT> as(const refptr<T>& value) {
    return value.template As<TT>();
  }

  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Switch
  template<typename TT, typename T>
  refptr<TT> as(refptr<T>& value) {
    return value.template As<TT>();
  }

  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Switch
  template<typename TT, typename T>
  const TT& as(const T& value) {
    try {
      return dynamic_cast<const TT&>(value);
    } catch (...) {
      __throw_cast_exception__();
    }
    throw std::bad_cast();
  }

  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Switch
  template<typename TT, typename T>
  TT& as(T& value) {
    try {
      return dynamic_cast<TT&>(value);
    } catch (...) {
      __throw_cast_exception__();
    }
    throw std::bad_cast();
  }

  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Switch
  template<typename TT, typename T>
  const TT* as(const T* value) {
    if (value == null)
      return null;
    return &as<TT>(*value);
  }

  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Switch
  template<typename TT, typename T>
  TT* as(T* value) {
    if (value == null)
      return null;
    return &as<TT>(*value);
  }
}

using namespace Switch;
