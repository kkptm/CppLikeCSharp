/// @file
/// @brief Contains Switch::System::Net::HttpListenerException exception.
#pragma once

#include <Switch/System/SystemException.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The exception that is thrown when an error occurs processing an HTTP request.
      /// @par Library
      /// Switch.System
      class system_export_ HttpListenerException : public SystemException {
      public:
        /// @brief Create a new instance of class HttpListenerException
        /// @remarks Message is set with the default message associate to the error.
        HttpListenerException() : SystemException() {}

        /// @brief Create a new instance of class HttpListenerException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        HttpListenerException(const HttpListenerException& value) : SystemException(value) {}

        /// @brief Create a new instance of class HttpListenerException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        /// @remarks Message is set with the default message associate to the error.
        HttpListenerException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

        /// @brief Create a new instance of class HttpListenerException
        /// @param message Message string associate to the error.
        HttpListenerException(const System::String& message) : SystemException(message) {}

        /// @brief Create a new instance of class HttpListenerException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        HttpListenerException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

        /// @brief Create a new instance of class HttpListenerException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        HttpListenerException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

      private:
        System::String GetDefaultMessage() const override {return "The HTTP request failed."; }
      };
    }
  }
}

using namespace Switch;
