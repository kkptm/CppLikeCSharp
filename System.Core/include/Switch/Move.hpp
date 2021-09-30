/// @file
/// @brief Contains Switch::Move <> operator.
#pragma once

#include <utility>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent the move operator.
  /// @remarks For more information read C++11 documention and specificaly std::move() method.
  template< class T >
  inline constexpr typename std::remove_reference<T>::type&& Move(T&& t) {return std::move(t);}
}

using namespace Switch;
