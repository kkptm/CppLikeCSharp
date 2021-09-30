/// @file
/// @brief Contains Switch::System::Threading::Tasks::TaskStatus enum.
#pragma once

#include "../../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief The System::Threading::Tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are System::Threading::Tasks::Task which represents an asynchronous operation that can be waited on and cancelled, and System::Threading::Tasks::Task<TResult>, which is a task that can return a value. The System::Threading::Tasks::TaskFactory class provides static methods for creating and starting tasks, and the System::Threading::Tasks::TaskScheduler class provides the default thread scheduling infrastructure.
      namespace Tasks {
        /// @brief Represents the current stage in the lifecycle of a Task.
        /// @remarks The Task.Status property returns a member of the TaskStatus enumeration to indicate the task's current status.
        enum class TaskStatus {
          /// @brief The task has been initialized but has not yet been scheduled.
          Created,
          /// @brief The task is waiting to be activated and scheduled internally by the Switch infrastructure.
          WaitingForActivation,
          /// @brief The task has been scheduled for execution but has not yet begun executing.
          WaitingToRun,
          /// @brief The task is running but has not yet completed.
          Running,
          /// @brief The task has finished executing and is implicitly waiting for attached child tasks to complete.
          WaitingForChildrenToComplete,
          /// @brief The task completed execution successfully.
          RanToCompletion,
          /// @brief The task acknowledged cancellation by throwing an OperationCanceledException with its own CancellationToken while the token was in signaled state, or the task's CancellationToken was already signaled before the task started executing. For more information, see Task Cancellation.
          Canceled,
          /// @brief The task completed due to an unhandled exception.
          Faulted
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Threading::Tasks::TaskStatus> {
  void operator()(System::Collections::Generic::IDictionary<System::Threading::Tasks::TaskStatus, string>& values, bool& flags) {
    values[System::Threading::Tasks::TaskStatus::Created] = "Created";
    values[System::Threading::Tasks::TaskStatus::WaitingForActivation] = "WaitingForActivation";
    values[System::Threading::Tasks::TaskStatus::WaitingToRun] = "WaitingToRun";
    values[System::Threading::Tasks::TaskStatus::Running] = "Running";
    values[System::Threading::Tasks::TaskStatus::WaitingForChildrenToComplete] = "WaitingForChildrenToComplete";
    values[System::Threading::Tasks::TaskStatus::RanToCompletion] = "RanToCompletion";
    values[System::Threading::Tasks::TaskStatus::Canceled] = "Canceled";
    values[System::Threading::Tasks::TaskStatus::Faulted] = "Faulted";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
