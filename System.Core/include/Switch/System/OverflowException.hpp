/// @file
/// @brief Contains Switch::System::OverflowException exception.
#pragma once

#include "ArithmeticException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when an arithmetic, casting, or conversion operation in a checked context results in an overflow.
    class core_export_ OverflowException : public ArithmeticException {
    public:
      /// @brief Create a new instance of class OverflowException
      /// @remarks Message is set with the default message associate to the error.
      OverflowException() : ArithmeticException() {}

      /// @brief Create a new instance of class OverflowException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      OverflowException(const OverflowException& value) : ArithmeticException(value) {}

      /// @brief Create a new instance of class OverflowException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      explicit OverflowException(const System::Runtime::CompilerServices::Caller& information) : ArithmeticException(information) {}

      /// @brief Create a new instance of class OverflowException
      /// @param message Message string associate to the error.
      explicit OverflowException(const System::String& message) : ArithmeticException(message) {}

      /// @brief Create a new instance of class OverflowException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      OverflowException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : ArithmeticException(message, information) {}

      /// @brief Create a new instance of class OverflowException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      OverflowException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : ArithmeticException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "Arithmetic operation resulted in an overflow."; }
    };
  }
}

using namespace Switch;

