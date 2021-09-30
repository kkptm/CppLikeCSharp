/// @file
/// @brief Contains Switch::System::PlatformNotSupportedException exception.
#pragma once

#include "NotSupportedException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when a feature does not run on a particular platform.
    class core_export_ PlatformNotSupportedException : public NotSupportedException {
    public:
      /// @brief Create a new instance of class PlatformNotSupportedException
      /// @remarks Message is set with the default message associate to the error.
      PlatformNotSupportedException() : NotSupportedException() {}

      /// @brief Create a new instance of class PlatformNotSupportedException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      PlatformNotSupportedException(const PlatformNotSupportedException& value) : NotSupportedException(value) {}

      /// @brief Create a new instance of class PlatformNotSupportedException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      PlatformNotSupportedException(const System::Runtime::CompilerServices::Caller& information) : NotSupportedException(information) {}

      /// @brief Create a new instance of class PlatformNotSupportedException
      /// @param message Message string associate to the error.
      PlatformNotSupportedException(const System::String& message) : NotSupportedException(message) {}

      /// @brief Create a new instance of class PlatformNotSupportedException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      PlatformNotSupportedException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : NotSupportedException(message, information) {}

      /// @brief Create a new instance of class PlatformNotSupportedException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      PlatformNotSupportedException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : NotSupportedException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "Operation is not supported on this platform."; }
    };
  }
}

using namespace Switch;

