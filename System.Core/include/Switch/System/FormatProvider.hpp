/// @file
/// @brief Contains Switch::System::FormatProvider class.
#pragma once

#include "ICustomFormatter.hpp"
#include "IFormatProvider.hpp"
#include "Object.hpp"
#include "String.hpp"
#include "Type.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Implements the IFormatProvider interface to format data as a string
    class core_export_ FormatProvider : public Object, public IFormatProvider, public ICustomFormatter {
    public:
      /// @brief Returns an object that provides formatting services for the specified type.
      /// @param type An object that specifies the type of format object to return.
      /// @return object An instance of the object specified by formatType, if the IFormatProvider implementation can supply that type of object; otherwise, nullNothingnullptra null reference (Nothing in Visual Basic).
      const Object& GetFormat(const Type& type) const override { return *this; }
      String Format(const String& format, const Object& arg, const IFormatProvider& provider) const override { return ""; };
    };
  }
}

using namespace Switch;
