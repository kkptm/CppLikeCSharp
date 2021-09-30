/// @file
/// @brief Contains Switch::System::Net::Sockets::SocketException exception.
#pragma once

#include <Switch/System/SystemException.hpp>
#include "../../../SystemExport.hpp"
#include "SocketError.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief The exception that is thrown when a socket error occurs.
        /// @par Library
        /// Switch.System
        class system_export_ SocketException : public SystemException {
        public:
          /// @brief Create a new instance of class SocketException
          /// @remarks Message is set with the default message associate to the error.
          SocketException() : SystemException() {}

          /// @brief Create a new instance of class SocketException
          /// @param value The Excetion to copy.
          /// @remarks Message is set with the default message associate to the error.
          SocketException(const SocketException& value) : SystemException(value), error(value.error) {}

          /// @brief Create a new instance of class SocketException
          /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
          /// @remarks Message is set with the default message associate to the error.
          SocketException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

          /// @brief Create a new instance of class SocketException
          /// @param message Message string associate to the error.
          SocketException(const System::String& message) : SystemException(message) {}

          /// @brief Create a new instance of class SocketException
          /// @param message Message string associate to the error.
          /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
          SocketException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

          /// @brief Create a new instance of class SocketException
          /// @param message Message string associate to the error.
          /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
          /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
          SocketException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

          /// @brief Create a new instance of class SocketException
          /// @param error The error code that indicates the error that occurred.
          /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
          SocketException(int32 error, const System::Runtime::CompilerServices::Caller& information) : SystemException("The Socket operation failed.", information), error((System::Net::Sockets::SocketError)error) {}

          /// @brief Get the SocketError associated with this exception
          /// @return An error code associated with the exception
          property_<const Sockets::SocketError&, readonly_> SocketErrorCode {
            get_->const Sockets::SocketError& {return this->error; }
          };

        private:
          System::String GetDefaultMessage() const override {return "The Socket operation failed."; }
          Sockets::SocketError error;
        };
      }
    }
  }
}

using namespace Switch;
