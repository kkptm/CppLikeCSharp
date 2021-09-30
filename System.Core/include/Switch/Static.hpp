/// @file
/// @brief Contains Switch::Static class and #static_ keyword.
#pragma once

#include "CoreExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent a static class. A static class can't be instancied (constructors are deleted).
  struct core_export_ Static {
    /// @cond
    Static() = delete;
    Static(const Static&) = delete;
    Static& operator=(const Static&) = delete;
    /// @endcond
  };
}

/// @brief This keyword is use to represent a static class. A static class can't be instancied (constructors are deleted).
/// @par Examples
/// @code
/// class Foo static_ {
/// public:
///   static string ToString() {return "Foo";}
/// };
/// @endcode
/// @ingroup Keywords
#define static_ \
  final : Static

using namespace Switch;
