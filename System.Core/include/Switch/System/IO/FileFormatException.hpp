/// @file
/// @brief Contains Switch::System::IO::FileFormatException exception.
#pragma once

#include "../FormatException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief The exception that is thrown when an input file or a data stream that is supposed to conform to a certain file format specification is malformed.
      class core_export_ FileFormatException : public FormatException {
      public:
        /// @brief Create a new instance of class FileFormatException
        /// @remarks Message is set with the default message associate to the error.
        FileFormatException() : FormatException() {}

        /// @brief Create a new instance of class FileFormatException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        FileFormatException(const FileFormatException& value) : FormatException(value) {}

        /// @brief Create a new instance of class FileFormatException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        /// @remarks Message is set with the default message associate to the error.
        FileFormatException(const System::Runtime::CompilerServices::Caller& information) : FormatException(information) {}

        /// @brief Create a new instance of class FileFormatException
        /// @param message Message string associate to the error.
        FileFormatException(const System::String& message) : FormatException(message) {}

        /// @brief Create a new instance of class FileFormatException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        FileFormatException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : FormatException(message, information) {}

        /// @brief Create a new instance of class FileFormatException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        FileFormatException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : FormatException(message, innerException, information) {}

      private:
        System::String GetDefaultMessage() const override {return "Input file or data stream does not conform to the expected file format specification."; }
      };
    }
  }
}

using namespace Switch;
