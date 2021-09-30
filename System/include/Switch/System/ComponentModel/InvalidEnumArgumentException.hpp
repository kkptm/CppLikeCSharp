/// @file
/// @brief Contains Switch::System::ArgumentNullException exception.
#pragma once

#include <Switch/System/ArgumentException.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    namespace ComponentModel {
      /// @brief The exception thrown when using invalid arguments that are enumerators.
      class system_export_ InvalidEnumArgumentException : public ArgumentException {
      public:
        /// @brief Create a new instance of class InvalidEnumArgumentException
        /// @remarks Message is set with the default message associate to the error.
        InvalidEnumArgumentException() : ArgumentException() {}

        /// @brief Create a new instance of class InvalidEnumArgumentException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        InvalidEnumArgumentException(const InvalidEnumArgumentException& value) : ArgumentException(value) {}

        /// @brief Create a new instance of class InvalidEnumArgumentException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        /// @remarks Message is set with the default message associate to the error.
        InvalidEnumArgumentException(const System::Runtime::CompilerServices::Caller& information) : ArgumentException(information) {}

        /// @brief Create a new instance of class InvalidEnumArgumentException
        /// @param message Message string associate to the error.
        InvalidEnumArgumentException(const System::String& message) : ArgumentException(message) {}

        /// @brief Create a new instance of class InvalidEnumArgumentException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        InvalidEnumArgumentException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : ArgumentException(message, information) {}

        /// @brief Create a new instance of class InvalidEnumArgumentException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        InvalidEnumArgumentException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : ArgumentException(message, innerException, information) {}
      };
    }
  }
}

using namespace Switch;

