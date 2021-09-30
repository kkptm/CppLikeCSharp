/// @file
/// @brief Contains Switch::System::Threading::ThreadStartException exception.
#pragma once

#include "../SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// SystemException addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief The exception that is thrown when a failure occurs in a thread after the underlying operating system thread has been started, but before the thread is ready to execute user code.
      class core_export_ ThreadStartException : public SystemException {
      public:
        /// @brief Create a new instance of class ThreadStartException
        /// @remarks Message is set with the default message associate to the error.
        ThreadStartException() : SystemException() {}

        /// @brief Create a new instance of class ThreadStartException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        ThreadStartException(const ThreadStartException& value) : SystemException(value) {}

        /// @brief Create a new instance of class ThreadStartException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        /// @remarks Message is set with the default message associate to the error.
        ThreadStartException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

        /// @brief Create a new instance of class ThreadStartException
        /// @param message Message string associate to the error.
        ThreadStartException(const System::String& message) : SystemException(message) {}

        /// @brief Create a new instance of class ThreadStartException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        ThreadStartException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

        /// @brief Create a new instance of class ThreadStartException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        ThreadStartException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

      private:
        System::String GetDefaultMessage() const override {return "Thread start failure."; }
      };
    }
  }
}

using namespace Switch;
