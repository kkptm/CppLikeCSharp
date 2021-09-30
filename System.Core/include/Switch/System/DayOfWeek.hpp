/// @file
/// @brief Contains Switch::System::DayOfWeek enum.
#pragma once

#include "../Types.hpp"
#include "Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Specifies the day of the week.
    /// @see DateTime
    enum class DayOfWeek {
      /// @brief Indicates Sunday.
      Sunday,
      /// @brief Indicates Monday.
      Monday,
      /// @brief Indicates Tuesday.
      Tuesday,
      /// @brief Indicates Wednesday.
      Wednesday,
      /// @brief Indicates Thursday.
      Thursday,
      /// @brief Indicates Friday.
      Friday,
      /// @brief Indicates Saturday.
      Saturday,
    };
  }
}

/// @cond
template<>
struct EnumRegister<System::DayOfWeek> {
  void operator()(System::Collections::Generic::IDictionary<System::DayOfWeek, string>& values, bool& flags) {
    values[System::DayOfWeek::Sunday] = "Sunday";
    values[System::DayOfWeek::Monday] = "Monday";
    values[System::DayOfWeek::Tuesday] = "Tuesday";
    values[System::DayOfWeek::Wednesday] = "Wednesday";
    values[System::DayOfWeek::Thursday] = "Thursday";
    values[System::DayOfWeek::Friday] = "Friday";
    values[System::DayOfWeek::Saturday] = "Saturday";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
