/// @file
/// @brief Contains Switch::System::Threading::WaitHandleCannotBeOpenedException exception.
#pragma once

#include "../ApplicationException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// ApplicationException addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief The exception that is thrown when an attempt is made to open a system mutex or semaphore that does not exist.
      class core_export_ WaitHandleCannotBeOpenedException : public ApplicationException {
      public:
        /// @brief Create a new instance of class WaitHandleCannotBeOpenedException
        /// @remarks Message is set with the default message associate to the error.
        WaitHandleCannotBeOpenedException() : ApplicationException() {}

        /// @brief Create a new instance of class WaitHandleCannotBeOpenedException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        WaitHandleCannotBeOpenedException(const WaitHandleCannotBeOpenedException& value) : ApplicationException(value) {}

        /// @brief Create a new instance of class WaitHandleCannotBeOpenedException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        /// @remarks Message is set with the default message associate to the error.
        WaitHandleCannotBeOpenedException(const System::Runtime::CompilerServices::Caller& information) : ApplicationException(information) {}

        /// @brief Create a new instance of class WaitHandleCannotBeOpenedException
        /// @param message Message string associate to the error.
        WaitHandleCannotBeOpenedException(const System::String& message) : ApplicationException(message) {}

        /// @brief Create a new instance of class WaitHandleCannotBeOpenedException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        WaitHandleCannotBeOpenedException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : ApplicationException(message, information) {}

        /// @brief Create a new instance of class WaitHandleCannotBeOpenedException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        WaitHandleCannotBeOpenedException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : ApplicationException(message, innerException, information) {}

      private:
        System::String GetDefaultMessage() const override {return "No handle of the given name exists."; }
      };
    }
  }
}

using namespace Switch;
