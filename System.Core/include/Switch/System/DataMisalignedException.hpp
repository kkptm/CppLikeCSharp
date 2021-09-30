/// @file
/// @brief Contains Switch::System::DataMisalignedException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when a unit of data is read from or written to an address that is not a multiple of the data size.
    class core_export_ DataMisalignedException : public SystemException {
    public:
      /// @brief Create a new instance of class DataMisalignedException
      /// @remarks Message is set with the default message associate to the error.
      DataMisalignedException() : SystemException() {}

      /// @brief Create a new instance of class DataMisalignedException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      DataMisalignedException(const DataMisalignedException& value) : SystemException(value) {}

      /// @brief Create a new instance of class DataMisalignedException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      DataMisalignedException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

      /// @brief Create a new instance of class DataMisalignedException
      /// @param message Message string associate to the error.
      DataMisalignedException(const System::String& message) : SystemException(message) {}

      /// @brief Create a new instance of class DataMisalignedException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      DataMisalignedException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

      /// @brief Create a new instance of class DataMisalignedException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      DataMisalignedException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "A datatype misalignment was detected in a load or store instruction."; }
    };
  }
}

using namespace Switch;

