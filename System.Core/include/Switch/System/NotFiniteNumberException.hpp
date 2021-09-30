/// @file
/// @brief Contains Switch::System::NotFiniteNumberException exception.
#pragma once

#include "ArithmeticException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when a floating-point value is positive infinity, negative infinity, or Not-a-Number (NaN).
    class core_export_ NotFiniteNumberException : public ArithmeticException {
    public:
      /// @brief Create a new instance of class NotFiniteNumberException
      /// @remarks Message is set with the default message associate to the error.
      NotFiniteNumberException() : ArithmeticException() {}

      /// @brief Create a new instance of class NotFiniteNumberException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      NotFiniteNumberException(const NotFiniteNumberException& value) : ArithmeticException(value) {}

      /// @brief Create a new instance of class NotFiniteNumberException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      NotFiniteNumberException(const System::Runtime::CompilerServices::Caller& information) : ArithmeticException(information) {}

      /// @brief Create a new instance of class NotFiniteNumberException
      /// @param message Message string associate to the error.
      NotFiniteNumberException(const System::String& message) : ArithmeticException(message) {}

      /// @brief Create a new instance of class NotFiniteNumberException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      NotFiniteNumberException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : ArithmeticException(message, information) {}

      /// @brief Create a new instance of class NotFiniteNumberException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      NotFiniteNumberException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : ArithmeticException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "Number encountered was not a finite quantity."; }
    };
  }
}

using namespace Switch;

