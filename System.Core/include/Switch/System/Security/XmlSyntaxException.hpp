/// @file
/// @brief Contains Switch::System::Security::XmlSyntaxException exception.
#pragma once

#include "../SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System.Security namespaces contain classes that represent the Switch Framework security system and permissions. Child namespaces provide types that control access to and audit securable objects, allow authentication, provide crytographic services, control access to operations and resources based on policy, and support rights management of application-created content.
    namespace Security {
      /// @brief The exception that is thrown when there is a syntax error in XML parsing. This class cannot be inherited.
      class core_export_ XmlSyntaxException : public SystemException {
      public:
        /// @brief Create a new instance of class XmlSyntaxException
        /// @remarks Message is set with the default message associate to the error.
        XmlSyntaxException() : SystemException() {}

        /// @brief Create a new instance of class XmlSyntaxException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        XmlSyntaxException(const XmlSyntaxException& value) : SystemException(value) {}

        /// @brief Create a new instance of class XmlSyntaxException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        /// @remarks Message is set with the default message associate to the error.
        XmlSyntaxException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

        /// @brief Create a new instance of class XmlSyntaxException
        /// @param message Message string associate to the error.
        XmlSyntaxException(const System::String& message) : SystemException(message) {}

        /// @brief Create a new instance of class XmlSyntaxException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        XmlSyntaxException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

        /// @brief Create a new instance of class XmlSyntaxException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        XmlSyntaxException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

      private:
        System::String GetDefaultMessage() const override {return "Syntax error in XML."; }
      };
    }
  }
}

using namespace Switch;
