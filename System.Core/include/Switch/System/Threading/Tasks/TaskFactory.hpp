/// @file
/// @brief Contains Switch::System::Threading::Tasks::TaskFactory class.
#pragma once

#include "Task.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief The System::Threading::Tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are System::Threading::Tasks::Task which represents an asynchronous operation that can be waited on and cancelled, and System::Threading::Tasks::Task<TResult>, which is a task that can return a value. The System::Threading::Tasks::TaskFactory class provides static methods for creating and starting tasks, and the System::Threading::Tasks::TaskScheduler class provides the default thread scheduling infrastructure.
      namespace Tasks {
        /// @brief Provides support for creating and scheduling Task objects.
        class TaskFactory : public object {
        public:
          TaskFactory() {}

          /// @cond
          TaskFactory(const TaskFactory& taskFactory) {}
          TaskFactory& operator=(const TaskFactory& taskFactory) {return *this;}
          /// @endcond

          /// @brief Creates and starts a task.
          /// @param action The action delegate to execute asynchronously.
          /// @return The started task.
          /// @remarks Calling StartNew is functionally equivalent to creating a task by using one of its constructors, and then calling the Task.Start method to schedule the task for execution.
          Task<> StartNew(const Action<>& action) {
            Task<> task(action);
            task.Start();
            return task;
          }

          /// @brief Creates and starts a task.
          /// @param action The action delegate to execute asynchronously.
          /// @return The started task.
          /// @remarks Calling StartNew is functionally equivalent to creating a task by using one of its constructors, and then calling the Task.Start method to schedule the task for execution.
          Task<> StartNew(const Action<object&>& action, object& state) {
            Task<> task(action, state);
            task.Start();
            return task;
          }

          /// @brief Creates and starts a task.
          /// @param action The action delegate to execute asynchronously.
          /// @return The started task.
          /// @remarks Calling StartNew is functionally equivalent to creating a task by using one of its constructors, and then calling the Task.Start method to schedule the task for execution.
          Task<> StartNew(const Action<const object&>& action, const object& state) {
            Task<> task(action, state);
            task.Start();
            return task;
          }

          /// @brief Creates and starts a task.
          /// @param action The action delegate to execute asynchronously.
          /// @return The started task.
          /// @remarks Calling StartNew is functionally equivalent to creating a task by using one of its constructors, and then calling the Task.Start method to schedule the task for execution.
          template<typename TResult>
          Task<TResult> StartNew(const Func<TResult>& function) {
            Task<TResult> task(function);
            task.Start();
            return task;
          }

          /// @brief Creates and starts a task.
          /// @param action The action delegate to execute asynchronously.
          /// @return The started task.
          /// @remarks Calling StartNew is functionally equivalent to creating a task by using one of its constructors, and then calling the Task.Start method to schedule the task for execution.
          template<typename TResult>
          Task<TResult> StartNew(const Func<object&, TResult>& function, object& state) {
            Task<TResult> task(function, state);
            task.Start();
            return task;
          }

          /// @brief Creates and starts a task.
          /// @param action The action delegate to execute asynchronously.
          /// @return The started task.
          /// @remarks Calling StartNew is functionally equivalent to creating a task by using one of its constructors, and then calling the Task.Start method to schedule the task for execution.
          template<typename TResult>
          Task<TResult> StartNew(const Func<const object&, TResult>& function, const object& state) {
            Task<TResult> task(function, state);
            task.Start();
            return task;
          }
        };
      }
    }
  }
}

using namespace Switch;
