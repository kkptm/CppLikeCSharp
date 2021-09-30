/// @file
/// @brief Contains Switch::System::Threading::Tasks::ITask interface.
#pragma once

#include "../../../Interface.hpp"
#include "../../../Types.hpp"
#include "../../Int32.hpp"
#include "../../TimeSpan.hpp"

/// @cond
namespace Switch {
  namespace System {
    namespace Threading {
      namespace Tasks {
        template <typename TResult = void>
        class Task;
      }
    }
  }
}

class __opaque_task_id_generator__ {
  template <typename TResult>
  friend class System::Threading::Tasks::Task;
  __opaque_task_id_generator__() {}
  int32 operator()() {
    static int32 taskIdCounter = 0;
    taskIdCounter = taskIdCounter == System::Int32::MaxValue ? 1 : taskIdCounter + 1;
    return taskIdCounter;
  }
  static thread_local int32 currentId;
};
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief The System::Threading::Tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are System::Threading::Tasks::Task which represents an asynchronous operation that can be waited on and cancelled, and System::Threading::Tasks::Task<TResult>, which is a task that can return a value. The System::Threading::Tasks::TaskFactory class provides static methods for creating and starting tasks, and the System::Threading::Tasks::TaskScheduler class provides the default thread scheduling infrastructure.
      namespace Tasks {
        /// @brief Represents an interface for an asynchronous operation.
        class ITask interface_ {
        public:
          /// @brief Starts the Task, scheduling it for execution to the current TaskScheduler.
          virtual void Start() = 0;

          /// @brief Waits for the Task to complete execution.
          virtual void Wait() = 0;

          /// @brief Waits for the Task to complete execution within a specified number of milliseconds.
          virtual bool Wait(int32 millisecondsTimeout) = 0;

          /// @brief Waits for the Task to complete execution within a specified time interval.
          virtual bool Wait(const TimeSpan& timeout) = 0;
        };
      }
    }
  }
}

using namespace Switch;
