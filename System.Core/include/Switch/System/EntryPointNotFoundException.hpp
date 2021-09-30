/// @file
/// @brief Contains Switch::System::EntryPointNotFoundException exception.
#pragma once

#include "TypeLoadException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when an attempt to load a class fails due to the absence of an entry method.
    class core_export_ EntryPointNotFoundException : public TypeLoadException {
    public:
      /// @brief Create a new instance of class EntryPointNotFoundException
      /// @remarks Message is set with the default message associate to the error.
      EntryPointNotFoundException() : TypeLoadException() {}

      /// @brief Create a new instance of class EntryPointNotFoundException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      EntryPointNotFoundException(const EntryPointNotFoundException& value) : TypeLoadException(value) {}

      /// @brief Create a new instance of class EntryPointNotFoundException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      EntryPointNotFoundException(const System::Runtime::CompilerServices::Caller& information) : TypeLoadException(information) {}

      /// @brief Create a new instance of class EntryPointNotFoundException
      /// @param message Message string associate to the error.
      EntryPointNotFoundException(const System::String& message) : TypeLoadException(message) {}

      /// @brief Create a new instance of class EntryPointNotFoundException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      EntryPointNotFoundException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : TypeLoadException(message, information) {}

      /// @brief Create a new instance of class EntryPointNotFoundException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      EntryPointNotFoundException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : TypeLoadException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "Entry point was not found."; }
    };
  }
}

using namespace Switch;

