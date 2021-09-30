/// @file
/// @brief Contains Switch::System::MethodAccessException exception.
#pragma once

#include "MemberAccessException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when there is an invalid attempt to access a method, such as accessing a private method from partially trusted code.
    class core_export_ MethodAccessException : public MemberAccessException {
    public:
      /// @brief Create a new instance of class MethodAccessException
      /// @remarks Message is set with the default message associate to the error.
      MethodAccessException() : MemberAccessException() {}

      /// @brief Create a new instance of class MethodAccessException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      MethodAccessException(const MethodAccessException& value) : MemberAccessException(value) {}

      /// @brief Create a new instance of class MethodAccessException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      MethodAccessException(const System::Runtime::CompilerServices::Caller& information) : MemberAccessException(information) {}

      /// @brief Create a new instance of class MethodAccessException
      /// @param message Message string associate to the error.
      MethodAccessException(const System::String& message) : MemberAccessException(message) {}

      /// @brief Create a new instance of class MethodAccessException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      MethodAccessException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : MemberAccessException(message, information) {}

      /// @brief Create a new instance of class MethodAccessException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      MethodAccessException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : MemberAccessException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "Attempt to acces the method failed."; }
    };
  }
}

using namespace Switch;

