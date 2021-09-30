/// @file
/// @brief Contains Switch::System::Threading::TimerCallback delegate.
#pragma once

#include "../Action.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Represents the method that handles calls from a Timer.
      /// @param state An object containing application-specific information relevant to the method invoked by this delegate, or null.
      /// @remarks Use a TimerCallback delegate to specify the method that is called by a Timer. This method does not execute in the thread that created the timer; it executes in a separate thread pool thread that is provided by the system. The TimerCallback delegate invokes the method once after the start time elapses, and continues to invoke it once per timer interval until the Dispose method is called, or until the Timer.Change method is called with the interval value Infinite.
      /// @note Callbacks can occur after the Dispose() method overload has been called, because the timer queues callbacks for execution by thread pool threads. You can use the Dispose(WaitHandle) method overload to wait until all callbacks have completed.
      /// @note The timer delegate is specified when the timer is constructed, and cannot be changed. The start time for a Timer is passed in the dueTime parameter of the Timer constructors, and the period is passed in the period parameter. For an example that demonstrates creating and using a TimerCallback delegate, see System::Threading::Timer.
      using TimerCallback = Action<Object&>;
    }
  }
}

using namespace Switch;
