/// @file
/// @brief Contains Switch::System::Threading::Tasks::Parallel class.
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
        /// @brief Provides support for parallel loops and regions.
        class Parallel static_ {
        public:
          /// @brief Executes each of the provided actions, possibly in parallel.
          /// @param An array of Action to execute.
          /// @remarks This method can be used to execute a set of operations, potentially in parallel.
          /// @remarks No guarantees are made about the order in which the operations execute or whether they execute in parallel. This method does not return until each of the provided operations has completed, regardless of whether completion occurs due to normal or exceptional termination.
          /// @par Examples
          /// This example demonstrates how to use the Invokemethod with other methods, anonymous delegates, and lambda expressions.
          /// @include ParallelInvoke.cpp
          static void Invoke(const Array<Action<>>& actions) {
            System::Collections::Generic::List<Task<>> tasks;
            for (const auto& action : actions)
              tasks.Add(Task<>::Factory().StartNew(action));
            Task<>::WaitAll(tasks.ToArray());
          }

          /// @cond
          template<typename ...Args>
          static void Invoke(Args... args) {Invoke({args...});}
          /// @endcond
        };
      }
    }
  }
}

using namespace Switch;
