/// @file
/// @brief Contains Switch::System::TypeAccessException exception.
#pragma once

#include "TypeLoadException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when a method attempts to use a type that it does not have access to.
    class core_export_ TypeAccessException : public TypeLoadException {
    public:
      /// @brief Create a new instance of class TypeAccessException
      /// @remarks Message is set with the default message associate to the error.
      TypeAccessException() : TypeLoadException() {}

      /// @brief Create a new instance of class TypeAccessException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      TypeAccessException(const TypeAccessException& value) : TypeLoadException(value) {}

      /// @brief Create a new instance of class TypeAccessException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      TypeAccessException(const System::Runtime::CompilerServices::Caller& information) : TypeLoadException(information) {}

      /// @brief Create a new instance of class TypeAccessException
      /// @param message Message string associate to the error.
      TypeAccessException(const System::String& message) : TypeLoadException(message) {}

      /// @brief Create a new instance of class TypeAccessException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      TypeAccessException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : TypeLoadException(message, information) {}

      /// @brief Create a new instance of class TypeAccessException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      TypeAccessException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : TypeLoadException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "Attempt to access the type failed."; }
    };
  }
}

using namespace Switch;

