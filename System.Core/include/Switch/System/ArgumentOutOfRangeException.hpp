/// @file
/// @brief Contains Switch::System::ArgumentOutOfRangeException exception.
#pragma once

#include "ArgumentException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when the value of an argument is outside the allowable range of values as defined by the invoked method.
    class core_export_ ArgumentOutOfRangeException : public ArgumentException {
    public:
      /// @brief Create a new instance of class ArgumentOutOfRangeException
      /// @remarks Message is set with the default message associate to the error.
      ArgumentOutOfRangeException() : ArgumentException() {}

      /// @brief Create a new instance of class ArgumentOutOfRangeException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      ArgumentOutOfRangeException(const ArgumentOutOfRangeException& value) : ArgumentException(value) {}

      /// @brief Create a new instance of class ArgumentOutOfRangeException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      explicit ArgumentOutOfRangeException(const System::Runtime::CompilerServices::Caller& information) : ArgumentException(information) {}

      /// @brief Create a new instance of class ArgumentOutOfRangeException
      /// @param message Message string associate to the error.
      explicit ArgumentOutOfRangeException(const System::String& message) : ArgumentException(message) {}

      /// @brief Create a new instance of class ArgumentOutOfRangeException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      ArgumentOutOfRangeException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : ArgumentException(message, information) {}

      /// @brief Create a new instance of class ArgumentOutOfRangeException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      ArgumentOutOfRangeException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : ArgumentException(message, innerException, information) {}

      /// @cond
      friend core_export_ std::ostream& operator<<(std::ostream& output, const ArgumentOutOfRangeException& value) {return output << value.ToString();}
      /// @endcond

    private:
      System::String GetDefaultMessage() const override {return "Specified argument is out of range of valid values."; }
    };
  }
}

using namespace Switch;

