/// @file
/// @brief Contains Switch::System::Threading::ThreadStateException exception.
#pragma once

#include "../SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// SystemException addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief The exception that is thrown when a Thread is in an invalid ThreadState for the method call.
      class core_export_ ThreadStateException : public SystemException {
      public:
        /// @brief Create a new instance of class ThreadStateException
        /// @remarks Message is set with the default message associate to the error.
        ThreadStateException() : SystemException() {}

        /// @brief Create a new instance of class ThreadStateException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        ThreadStateException(const ThreadStateException& value) : SystemException(value) {}

        /// @brief Create a new instance of class ThreadStateException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        /// @remarks Message is set with the default message associate to the error.
        ThreadStateException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

        /// @brief Create a new instance of class ThreadStateException
        /// @param message Message string associate to the error.
        ThreadStateException(const System::String& message) : SystemException(message) {}

        /// @brief Create a new instance of class ThreadStateException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        ThreadStateException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

        /// @brief Create a new instance of class ThreadStateException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        ThreadStateException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

      private:
        System::String GetDefaultMessage() const override {return "Thread was in an invalid state for the operation being executed."; }
      };
    }
  }
}

using namespace Switch;
