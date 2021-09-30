/// @file
/// @brief Contains Switch::System::SystemException exception.
#pragma once

#include "Exception.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Defines the base class for predefined exceptions in the System namespace.
    class core_export_ SystemException : public Exception {
    public:
      /// @brief Create a new instance of class SystemException
      /// @remarks Message is set with the default message associate to the error.
      SystemException() : Exception() {}

      /// @brief Create a new instance of class SystemException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      SystemException(const SystemException& value) : Exception(value) {}

      /// @brief Create a new instance of class SystemException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      explicit SystemException(const System::Runtime::CompilerServices::Caller& information) : Exception(information) {}

      /// @brief Create a new instance of class SystemException
      /// @param message Message string associate to the error.
      explicit SystemException(const System::String& message) : Exception(message) {}

      /// @brief Create a new instance of class SystemException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      SystemException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : Exception(message, information) {}

      /// @brief Create a new instance of class SystemException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      SystemException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : Exception(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "System error."; }
    };
  }
}

using namespace Switch;

