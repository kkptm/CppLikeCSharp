/// @file
/// @brief Contains Switch::System::DateTimeKind enum.
#pragma once

#include "../Types.hpp"
#include "Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @enum DateTimeKind
    /// @brief Specifies whether a DateTime object represents a local time, a Coordinated Universal Time (UTC), or is not specified as either local time or UTC.
    /// @see DateTime
    enum class DateTimeKind {
      /// @brief The time represented is not specified as either local time or Coordinated.
      /// Universal Time (UTC).
      Unspecified,
      /// @brief The time represented is UTC.
      Utc,
      /// @brief The time represented is local time.
      Local
    };
  }
}

/// @cond
template<>
struct EnumRegister<System::DateTimeKind> {
  void operator()(System::Collections::Generic::IDictionary<System::DateTimeKind, string>& values, bool& flags) {
    values[System::DateTimeKind::Unspecified] = "Unspecified";
    values[System::DateTimeKind::Utc] = "Utc";
    values[System::DateTimeKind::Local] = "Local";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
