/// @file
/// @brief Contains Switch::System::AppDomainUnloadedException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when an attempt is made to access an unloaded application domain.
    class core_export_ AppDomainUnloadedException : public SystemException {
    public:
      /// @brief Create a new instance of class AppDomainUnloadedException
      /// @remarks Message is set with the default message associate to the error.
      AppDomainUnloadedException() : SystemException() {}

      /// @brief Create a new instance of class AppDomainUnloadedException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      AppDomainUnloadedException(const AppDomainUnloadedException& value) : SystemException(value) {}

      /// @brief Create a new instance of class AppDomainUnloadedException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      AppDomainUnloadedException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

      /// @brief Create a new instance of class AppDomainUnloadedException
      /// @param message Message string associate to the error.
      AppDomainUnloadedException(const System::String& message) : SystemException(message) {}

      /// @brief Create a new instance of class AppDomainUnloadedException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AppDomainUnloadedException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

      /// @brief Create a new instance of class AppDomainUnloadedException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AppDomainUnloadedException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

      /// @cond
      friend core_export_ std::ostream& operator<<(std::ostream& output, const AppDomainUnloadedException& value) {return output << value.ToString();}
      /// @endcond

    private:
      System::String GetDefaultMessage() const override {return "Attempted to access an unloaded AppDomain."; }
    };
  }
}

using namespace Switch;

