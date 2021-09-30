/// @file
/// @brief Contains Switch::System::AggregateException exception.
#pragma once

#include "../ExceptionPtr.hpp"
#include "Environment.hpp"
#include "Exception.hpp"
#include "Collections/Generic/List.hpp"
#include "AccessViolationException.hpp"
#include "AppDomainUnloadedException.hpp"
#include "ArgumentNullException.hpp"
#include "ArrayTypeMismatchException.hpp"
#include "BadImageFormatException.hpp"
#include "CannotUnloadAppDomainException.hpp"
#include "ContextMarshalException.hpp"
#include "DataMisalignedException.hpp"
#include "DivideByZeroException.hpp"
#include "DllNotFoundException.hpp"
#include "DuplicateWaitObjectException.hpp"
#include "EntryPointNotFoundException.hpp"
#include "ExecutionEngineException.hpp"
#include "Exception.hpp"
#include "FieldAccessException.hpp"
#include "InsufficientExecutionStackException.hpp"
#include "InsufficientMemoryException.hpp"
#include "InvalidProgramException.hpp"
#include "InvalidTimeZoneException.hpp"
#include "MemberAccessException.hpp"
#include "MethodAccessException.hpp"
#include "MissingFieldException.hpp"
#include "MissingMemberException.hpp"
#include "MissingMethodException.hpp"
#include "MulticastNotSupportedException.hpp"
#include "NotFiniteNumberException.hpp"
#include "NotImplementedException.hpp"
#include "NullPointerException.hpp"
#include "NullReferenceException.hpp"
#include "ObjectDisposedException.hpp"
#include "ObjectDisposedException.hpp"
#include "OperationCanceledException.hpp"
#include "PlatformNotSupportedException.hpp"
#include "StackOverflowException.hpp"
#include "SystemException.hpp"
#include "TimeoutException.hpp"
#include "TimeZoneNotFoundException.hpp"
#include "TypeAccessException.hpp"
#include "TypeInitializationException.hpp"
#include "TypeUnloadedException.hpp"
#include "UnauthorizedAccessException.hpp"
#include "IO/DirectoryNotFoundException.hpp"
#include "IO/DriveNotFoundException.hpp"
#include "IO/EndOfStreamException.hpp"
#include "IO/FileFormatException.hpp"
#include "IO/FileLoadException.hpp"
#include "IO/FileNotFoundException.hpp"
#include "IO/IOException.hpp"
#include "IO/PathTooLongException.hpp"
#include "Security/HostProtectionException.hpp"
#include "Security/SecurityException.hpp"
#include "Security/VerificationException.hpp"
#include "Security/XmlSyntaxException.hpp"
#include "Threading/AbandonedMutexException.hpp"
#include "Threading/LockRecursionException.hpp"
#include "Threading/SynchronizationLockException.hpp"
#include "Threading/ThreadAbortException.hpp"
#include "Threading/ThreadInterruptedException.hpp"
#include "Threading/ThreadStartException.hpp"
#include "Threading/ThreadStateException.hpp"
#include "Threading/WaitHandleCannotBeOpenedException.hpp"
#include "Runtime/Serialization/SerializationException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents one or more errors that occur during application execution.
    /// @remarks AggregateException is used to consolidate multiple failures into a single, throwable exception object.
    /// @par Examples
    /// The following example catches the AggregateException exception and calls the Handle method to handle each exception it contains. Compiling and running the example with the first task1 variable should result in an AggregateException object that contains an UnauthorizedAccessException exception. Commenting out that line, uncommenting the second task1 variable, and compiling and running the example produces an AggregateException object that contains an IndexOutOfRangeException exception.
    /// @include AggregateException.cpp
    class core_export_ AggregateException : public Exception {
    public:
      /// @brief Gets a read-only collection of the Exception instances that caused the current exception.
      /// @return Returns a read-only collection of the Exception instances that caused the current exception.
      property_<const Array<excptr>&, readonly_> InnerExceptions {
        get_->const Array<excptr>& {return this->innerExceptions;}
      };

      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const Array<excptr>& innerExceptions) : innerExceptions(innerExceptions) {}

      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const Exception& innerException) {
        this->innerExceptions = Array<excptr>(1);
        this->innerExceptions[0] = excptr::Create(innerException);
      }

      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const Array<ref<Exception>>& innerExceptions) {
        this->innerExceptions = Array<excptr>(innerExceptions.Count);
        for (int index = 0; index < innerExceptions.Count; index++)
          this->innerExceptions[index] = excptr::Create(innerExceptions[index]());
      }

      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AggregateException(const Array<excptr>& innerExceptions, const System::Runtime::CompilerServices::Caller& information) : Exception(information), innerExceptions(innerExceptions) {}

      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AggregateException(const Array<ref<Exception>>& innerExceptions, const System::Runtime::CompilerServices::Caller& information) : Exception(information) {
        this->innerExceptions = Array<excptr>(innerExceptions.Count);
        for (int index = 0; index < innerExceptions.Count; index++)
          this->innerExceptions[index] = excptr::Create(innerExceptions[index]());
      }

      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const System::Collections::Generic::IEnumerable<excptr>& innerExceptions) : innerExceptions(innerExceptions) {}

      /// @brief Initializes a new instance of the AggregateException class with references to the inner exceptions that are the cause of this exception.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AggregateException(const System::Collections::Generic::IEnumerable<excptr>& innerExceptions, const System::Runtime::CompilerServices::Caller& information) : Exception(information), innerExceptions(innerExceptions) {}

      /// @brief Create a new instance of class AggregateException
      /// @remarks Message is set with the default message associate to the error.
      AggregateException() : Exception() {}

      /// @brief Create a new instance of class AggregateException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      AggregateException(const AggregateException& value) : Exception(value), innerExceptions(value.innerExceptions) {}

      /// @brief Create a new instance of class AggregateException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      AggregateException(const System::Runtime::CompilerServices::Caller& information) : Exception(information) {}

      /// @brief Create a new instance of class AggregateException
      /// @param message Message string associate to the error.
      AggregateException(const System::String& message) : Exception(message) {}

      /// @brief Create a new instance of class AggregateException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AggregateException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : Exception(message, information) {}

      /// @brief Create a new instance of class AggregateException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AggregateException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : Exception(message, information) {
        this->innerExceptions = Array<excptr>(1);
        this->innerExceptions[0] = excptr::Create(innerException);
      }

      /// @brief Initializes a new instance of the AggregateException class with a specified error message and references to the inner exceptions that are the cause of this exception.
      /// @param message Message string associate to the error.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const System::String& message, const Array<excptr>& innerExceptions) : innerExceptions(innerExceptions) {}

      /// @brief Initializes a new instance of the AggregateException class with a specified error message and references to the inner exceptions that are the cause of this exception.
      /// @param message Message string associate to the error.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      AggregateException(const System::String& message, const Array<ref<Exception>>& innerExceptions) {
        this->innerExceptions = Array<excptr>(innerExceptions.Count);
        for (int index = 0; index < innerExceptions.Count; index++)
          this->innerExceptions[index] = excptr::Create(innerExceptions[index]());
      }

      /// @brief Initializes a new instance of the AggregateException class with a specified error message and references to the inner exceptions that are the cause of this exception.
      /// @param message Message string associate to the error.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AggregateException(const System::String& message, const Array<excptr>& innerExceptions, const System::Runtime::CompilerServices::Caller& information) : Exception(message, information), innerExceptions(innerExceptions) {}

      /// @brief Initializes a new instance of the AggregateException class with a specified error message and references to the inner exceptions that are the cause of this exception.
      /// @param message Message string associate to the error.
      /// @param innerExceptions The exceptions that are the cause of the current exception.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      AggregateException(const System::String& message, const Array<ref<Exception>>& innerExceptions, const System::Runtime::CompilerServices::Caller& information) : Exception(message, information) {
        this->innerExceptions = Array<excptr>(innerExceptions.Count);
        for (int index = 0; index < innerExceptions.Count; index++)
          this->innerExceptions[index] = excptr::Create(innerExceptions[index]());
      }

      /// @brief Invokes a handler on each Exception contained by this AggregateException.
      /// @param predicate The predicate to execute for each exception. The predicate accepts as an argument the Exception to be processed and returns a Boolean to indicate whether the exception was handled.
      /// @remarks Each invocation of the predicate returns true or false to indicate whether the Exception was handled. After all invocations, if any exceptions went unhandled, all unhandled exceptions will be put into a new AggregateException which will be thrown. Otherwise, the Handle method simply returns. If any invocations of the predicate throws an exception, it will halt the processing of any more exceptions and immediately propagate the thrown exception as-is.
      void Handle(const Func<const Exception&, bool>& predicate) const {
        System::Collections::Generic::List<excptr> notHandledExceptions;
        for (int32 index = 0; index < this->innerExceptions.Count; ++index) {
          try {
            this->innerExceptions[index].Rethrow();
          } catch (const Exception& innerException) {
            if (!predicate(innerException))
              notHandledExceptions.Add(this->innerExceptions[index]);
          }
        }

        if (notHandledExceptions.Count != 0)
          throw AggregateException(notHandledExceptions, caller_);
      }

      String ToString() const override {
        string result = this->Exception::ToString();
        result += string::Format("   --- End of inner exception stack trace ---{0}", Environment::NewLine);
        for (int32 index = 0; index < this->innerExceptions.Count; index++) {
          try {
            this->innerExceptions[index].Rethrow();
          } catch (const Exception& innerException) {
            result += string::Format("---> (Inner Exception {0}) {1}", index, innerException.ToString());
          }
        }
        return result;
      }

      /// @cond
      friend core_export_ std::ostream& operator<<(std::ostream& output, const AggregateException& value) {return output << value.ToString();}
      /// @endcond

    private:
      String GetDefaultMessage() const override {return "One or more errors occured."; }
      Array<excptr> innerExceptions;
    };
  }
}

using namespace Switch;

