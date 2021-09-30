/// @file
/// @brief Contains Switch::System::IFormattable interface.
#pragma once

#include "../Interface.hpp"
#include "_String.hpp"
#include "IFormatProvider.hpp"

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
    /// @interface IFormattable
    /// @brief Provides functionality to format the value of an object into a string representation.
    class core_export_ IFormattable interface_ {
    public:
      /// @brief Formats the value of the current instance using the specified format.
      /// @param format The string specifying the format to use -or-  null to use the default format defined for the type of the IFormattable implementation.
      /// @param formatProvider The IFormatProvider to use to format the value -or- null to obtain the numeric format information from the current locale setting of the operating system.
      /// @return string A string containing the value of the current instance in the specified format.
      virtual String ToString(const String& format, const IFormatProvider& formatProvider) const = 0;
    };
  }
}

using namespace Switch;
