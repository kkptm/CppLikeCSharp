/// @file
/// @brief Contains Switch::System::Threading::Timer class.
#pragma once

#include <atomic>
#include "../../Static.hpp"
#include "../../Types.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Provides a mechanism for executing a method at specified intervals.
      /// @remarks The callback method executed by the timer should be reentrant, because it is called on ThreadPool threads. The callback can be executed simultaneously on two thread pool threads if the timer interval is less than the time required to execute the callback, or if all thread pool threads are in use and the callback is queued multiple times.
      /// @par Examples
      /// This example show how to use Timer class
      /// @include Timer.cpp
      struct core_export_ SpinLock : public Object {
      public:
        void Enter(bool lockTaken) {
          while (this->lock.test_and_set(std::memory_order_acquire));
        }

        void Exit() {this->Exit(false);}

        void Exit(bool useMemoryBarrier) {
          this->lock.clear(std::memory_order_release);
        }

      private:
        std::atomic_flag lock = ATOMIC_FLAG_INIT;
      };
    }
  }
}

using namespace Switch;
