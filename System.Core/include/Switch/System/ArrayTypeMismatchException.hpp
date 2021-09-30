/// @file
/// @brief Contains Switch::System::ArrayTypeMismatchException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when an attempt is made to store an element of the wrong type within an array.
    class core_export_ ArrayTypeMismatchException : public SystemException {
    public:
      /// @brief Create a new instance of class ArrayTypeMismatchException
      /// @remarks Message is set with the default message associate to the error.
      ArrayTypeMismatchException() : SystemException() {}

      /// @brief Create a new instance of class ArrayTypeMismatchException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      ArrayTypeMismatchException(const ArrayTypeMismatchException& value) : SystemException(value) {}

      /// @brief Create a new instance of class ArrayTypeMismatchException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      explicit ArrayTypeMismatchException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

      /// @brief Create a new instance of class ArrayTypeMismatchException
      /// @param message Message string associate to the error.
      explicit ArrayTypeMismatchException(const System::String& message) : SystemException(message) {}

      /// @brief Create a new instance of class ArrayTypeMismatchException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      ArrayTypeMismatchException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

      /// @brief Create a new instance of class ArrayTypeMismatchException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      ArrayTypeMismatchException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

      /// @cond
      friend core_export_ std::ostream& operator<<(std::ostream& output, const ArrayTypeMismatchException& value) {return output << value.ToString();}
      /// @endcond

    private:
      System::String GetDefaultMessage() const override {return "Attempt to access an element as a type incompatible with the array."; }
    };
  }
}

using namespace Switch;

