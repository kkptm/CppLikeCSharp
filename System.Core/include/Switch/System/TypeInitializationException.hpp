/// @file
/// @brief Contains Switch::System::TypeInitializationException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown as a wrapper around the exception thrown by the class initializer.
    class core_export_ TypeInitializationException : public SystemException {
    public:
      TypeInitializationException(const System::TypeInitializationException& exception) : SystemException(exception) {
        this->fullTypeName = exception.fullTypeName;
        this->SetStackTrace(*this);
      }

      TypeInitializationException(const String& fullTypeName, ref<System::Exception> innerException) : SystemException() {
        this->SetInnerException(innerException);
        this->fullTypeName = fullTypeName;
        this->SetStackTrace(*this);
      }

      TypeInitializationException(const String& fullTypeName, ref<System::Exception> innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {
        this->SetInnerException(innerException);
        this->fullTypeName = fullTypeName;
        this->SetStackTrace(*this);
      }

    private:
      String GetDefaultMessage() const override {return String::Format("The type initializer for '{0}' threw an exception.", this->fullTypeName);}
      String fullTypeName;
    };
  }
}

using namespace Switch;

