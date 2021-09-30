/// @file
/// @brief Contains Switch::System::MissingMethodException exception.
#pragma once

#include "MissingMemberException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when there is an attempt to dynamically access a method that does not exist.
    class core_export_ MissingMethodException : public MissingMemberException {
    public:
      /// @brief Create a new instance of class MissingMethodException
      /// @remarks Message is set with the default message associate to the error.
      MissingMethodException() : MissingMemberException() {}

      /// @brief Create a new instance of class MissingMethodException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      MissingMethodException(const MissingMethodException& value) : MissingMemberException(value) {}

      /// @brief Create a new instance of class MissingMethodException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      MissingMethodException(const System::Runtime::CompilerServices::Caller& information) : MissingMemberException(information) {}

      /// @brief Create a new instance of class MissingMethodException
      /// @param message Message string associate to the error.
      MissingMethodException(const System::String& message) : MissingMemberException(message) {}

      /// @brief Create a new instance of class MissingMethodException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      MissingMethodException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : MissingMemberException(message, information) {}

      /// @brief Create a new instance of class MissingMethodException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      MissingMethodException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : MissingMemberException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "Attempt to acces a missing method."; }
    };
  }
}

using namespace Switch;

