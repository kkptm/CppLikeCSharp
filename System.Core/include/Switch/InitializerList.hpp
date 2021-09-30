/// @file
/// @brief Contains Switch::InitializerList <T> class.
#pragma once

#include <initializer_list>

namespace Switch {
  template<typename T>
  using InitializerList = std::initializer_list<T>;
}

using namespace Switch;
