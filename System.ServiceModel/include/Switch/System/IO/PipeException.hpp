/// @file
/// @brief Contains Switch::System::IO::PipeException exception.
#pragma once

#include <Switch/System/IO/IOException.hpp>
#include "../../SystemServiceModelExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Thrown when an error occurs within a named pipe.
      /// @par Library
      /// Switch.System.ServiceModel
      class system_servicemodel_export_ PipeException : public IOException {
      public:
        /// @brief Create a new instance of class PipeException
        /// @remarks Message is set with the default message associate to the error.
        PipeException() : IOException() {}

        /// @brief Create a new instance of class PipeException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        PipeException(const PipeException& value) : IOException(value) {}

        /// @brief Create a new instance of class PipeException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        /// @remarks Message is set with the default message associate to the error.
        PipeException(const System::Runtime::CompilerServices::Caller& information) : IOException(information) {}

        /// @brief Create a new instance of class PipeException
        /// @param message Message string associate to the error.
        PipeException(const System::String& message) : IOException(message) {}

        /// @brief Create a new instance of class PipeException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        PipeException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : IOException(message, information) {}

        /// @brief Create a new instance of class PipeException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        PipeException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : IOException(message, innerException, information) {}

      private:
        System::String GetDefaultMessage() const override {return "I/O error occured."; }
      };
    }
  }
}

using namespace Switch;
