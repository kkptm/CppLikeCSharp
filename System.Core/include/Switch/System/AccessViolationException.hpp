/// @file
/// @brief Contains Switch::System::AccessViolationException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when there is an attempt to read or write protected memory.
    /// @remarks An access violation occurs in unmanaged or unsafe code when the code attempts to read or write to memory that has not been allocated, or to which it does not have access. This usually occurs because a pointer has a bad value. Not all reads or writes through bad pointers lead to access violations, so an access violation usually indicates that several reads or writes have occurred through bad pointers, and that memory might be corrupted. Thus, access violations almost always indicate serious programming errors. An AccessViolationException clearly identifies these serious errors.
    /// @remarks In programs consisting entirely of verifiable managed code, all references are either valid or null, and access violations are impossible. Any operation that attempts to reference a null reference in verifiable code throws a NullReferenceException exception. An AccessViolationException occurs only when verifiable managed code interacts with unmanaged code or with unsafe managed code.
    /// @par Troubleshooting AccessViolationException exceptions
    /// An AccessViolationException exception can occur only in unsafe managed code or when verifiable managed code interacts with unmanaged code:
    /// * An access violation that occurs in unsafe managed code can be expressed as either a NullReferenceException exception or an AccessViolationException exception, depending on the platform.
    /// * An access violation in unmanaged code that bubbles up to managed code is always wrapped in an AccessViolationException exception.
    ///
    /// In either case, you can identify and correct the cause of the AccessViolationException exception as follows:
    ///
    /// Make sure that the memory that you are attempting to access has been allocated.
    ///
    /// <pre>
    ///      AccessViolationException exception is always thrown by an attempt to access protected memory -- that is, to access
    ///      memory that is not allocated or that is not owned by a process.
    ///
    ///      Automatic memory management is one of the services that the common language runtime provides. If managed code provides
    ///      the same functionality as your unmanagede code, you may wish to move to managed code to take advantage of this functionality.
    ///      For more information, see Automatic Memory Management.
    /// </pre>
    ///
    /// Make sure that the memory that you are attempting to access has not been corrupted.
    ///
    /// <pre>
    ///      If several read or write operations have occurred through bad pointers, memory may be corrupted. This typically occurs when
    ///      reading or writing to addresses outside of a predefined buffer.
    /// </pre>
    class core_export_ AccessViolationException : public SystemException {
    public:
      /// @brief Create a new instance of class AccessViolationException
      /// @remarks Message is set with the default message associate to the error.
      AccessViolationException() : SystemException() {}

      /// @brief Create a new instance of class AccessViolationException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      AccessViolationException(const AccessViolationException& value) : SystemException(value) {}

      /// @brief Create a new instance of class AccessViolationException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      AccessViolationException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

      /// @brief Create a new instance of class AccessViolationException
      /// @param message Message string associate to the error.
      AccessViolationException(const System::String& message) : SystemException(message) {}

      /// @brief Create a new instance of class AccessViolationException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AccessViolationException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

      /// @brief Create a new instance of class AccessViolationException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AccessViolationException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

      /// @cond
      friend core_export_ std::ostream& operator<<(std::ostream& output, const AccessViolationException& value) {return output << value.ToString();}
      /// @endcond

    private:
      System::String GetDefaultMessage() const override {return "Attempted to read or write protected memory. This is often an indication that other memory is corrupt."; }
    };
  }
}

using namespace Switch;

