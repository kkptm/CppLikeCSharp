/// @file
/// @brief Contains Switch::System::ICustomFormatter interface.
#pragma once

#include "../Interface.hpp"
#include "IFormatProvider.hpp"
#include "Object.hpp"
#include "String.hpp"

/// @cond
namespace Switch {
  namespace System {
    class IFormatProvider;
  }
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @interface ICustomFormatter
    /// @brief Defines a method that supports custom, user-defined formatting of the value of an object.
    class core_export_ ICustomFormatter interface_ {
    public:
      /// @brief Converts the value of a specified object to an equivalent string representation using specified format and culture-specific formatting information.
      /// @param format A format string containing formatting specifications.
      /// @param arg An object to format
      /// @param provider An IFormatProvider object that supplies format information about the current instance.
      /// @return The string representation of the value of arg, formatted as specified by format and formatProvider.
      virtual String Format(const String& format, const Object& arg, const IFormatProvider& provider) const = 0;
    };
  }
}

using namespace Switch;
