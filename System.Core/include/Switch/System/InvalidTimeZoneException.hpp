/// @file
/// @brief Contains Switch::System::InvalidTimeZoneException exception.
#pragma once

#include "Exception.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when time zone information is invalid.
    class core_export_ InvalidTimeZoneException : public Exception {
    public:
      /// @brief Create a new instance of class InvalidTimeZoneException
      /// @remarks Message is set with the default message associate to the error.
      InvalidTimeZoneException() : Exception() {}

      /// @brief Create a new instance of class InvalidTimeZoneException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      InvalidTimeZoneException(const InvalidTimeZoneException& value) : Exception(value) {}

      /// @brief Create a new instance of class InvalidTimeZoneException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      InvalidTimeZoneException(const System::Runtime::CompilerServices::Caller& information) : Exception(information) {}

      /// @brief Create a new instance of class InvalidTimeZoneException
      /// @param message Message string associate to the error.
      InvalidTimeZoneException(const System::String& message) : Exception(message) {}

      /// @brief Create a new instance of class InvalidTimeZoneException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      InvalidTimeZoneException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : Exception(message, information) {}

      /// @brief Create a new instance of class InvalidTimeZoneException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      InvalidTimeZoneException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : Exception(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "The time zone information is not valid."; }
    };
  }
}

using namespace Switch;

