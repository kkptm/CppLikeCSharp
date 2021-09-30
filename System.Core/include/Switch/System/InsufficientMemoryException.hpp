/// @file
/// @brief Contains Switch::System::InsufficientMemoryException exception.
#pragma once

#include "OutOfMemoryException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when a check for sufficient available memory fails.
    class core_export_ InsufficientMemoryException : public OutOfMemoryException {
    public:
      /// @brief Create a new instance of class InsufficientMemoryException
      /// @remarks Message is set with the default message associate to the error.
      InsufficientMemoryException() : OutOfMemoryException() {}

      /// @brief Create a new instance of class InsufficientMemoryException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      InsufficientMemoryException(const InsufficientMemoryException& value) : OutOfMemoryException(value) {}

      /// @brief Create a new instance of class InsufficientMemoryException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      InsufficientMemoryException(const System::Runtime::CompilerServices::Caller& information) : OutOfMemoryException(information) {}

      /// @brief Create a new instance of class InsufficientMemoryException
      /// @param message Message string associate to the error.
      InsufficientMemoryException(const System::String& message) : OutOfMemoryException(message) {}

      /// @brief Create a new instance of class InsufficientMemoryException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      InsufficientMemoryException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : OutOfMemoryException(message, information) {}

      /// @brief Create a new instance of class InsufficientMemoryException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      InsufficientMemoryException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : OutOfMemoryException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "Insufficient memory to continue the execution of the program."; }
    };
  }
}

using namespace Switch;

