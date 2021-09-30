/// @file
/// @brief Contains Switch::System::Threading::AutoResetEvent class.
#pragma once

#include "EventWaitHandle.hpp"
#include "EventResetMode.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Notifies a waiting thread that an event has occurred.
      class core_export_ AutoResetEvent final : public EventWaitHandle {
      public:
        /// @brief Initializes a new instance of the AutoResetEvent class with a Boolean value indicating whether to set the initial state to signaled.
        /// @param initialState true to set the initial state to signaled if the named event is created as a result of this call; false to set it to nonsignaled.
        /// @exception IO::IOException A Win32 error occurred.
        AutoResetEvent(bool initialState) : EventWaitHandle(initialState, EventResetMode::AutoReset) { }

        /// @cond
        AutoResetEvent() {}
        AutoResetEvent(const AutoResetEvent& autoResetEvent) : EventWaitHandle(autoResetEvent) {}
        AutoResetEvent& operator=(const AutoResetEvent& autoResetEvent) {
          this->EventWaitHandle::operator=(autoResetEvent);
          return *this;
        }
        /// @endcond
      };
    }
  }
}

using namespace Switch;
