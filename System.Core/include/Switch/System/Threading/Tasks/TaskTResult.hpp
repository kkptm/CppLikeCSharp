/// @file
/// @brief Contains Switch::System::Threading::Tasks::Task <TResult> class.
#pragma once

#include <chrono>

#include "../../../Move.hpp"
#include "../../AggregateException.hpp"
#include "../../ArgumentOutOfRangeException.hpp"
#include "../../Nullable.hpp"
#include "../AutoResetEvent.hpp"
#include "../ManualResetEvent.hpp"
#include "../ThreadPool.hpp"
#include "ITask.hpp"
#include "TaskStatus.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief The System::Threading::Tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are System::Threading::Tasks::Task which represents an asynchronous operation that can be waited on and cancelled, and System::Threading::Tasks::Task<TResult>, which is a task that can return a value. The System::Threading::Tasks::TaskFactory class provides static methods for creating and starting tasks, and the System::Threading::Tasks::TaskScheduler class provides the default thread scheduling infrastructure.
      namespace Tasks {
        /// @cond
        class TaskFactory;
        /// @endcond

        /// @brief Represents an asynchronous operation that can return a value.
        template <typename TResult>
        class Task : public object, public ITask {
        public:
          using TaskResult = TResult;
          /// @brief Initializes a new Task<TResult> with the specified function.
          /// @param function The delegate that represents the code to execute in the task. When the function has completed, the task's Result property will be set to return the result value of the function.
          /// @remarks Rather than calling this constructor, the most common way to instantiate a Task object and launch a task is by calling the static TaskFactory.StartNew(Action<Object>, Object) method. The only advantage offered by this constructor is that it allows object instantiation to be separated from task invocation.
          Task(const Func<TResult>& function) {this->data->task = function;}

          /// @brief Initializes a new Task<TResult> with the specified function and state.
          /// @param function The delegate that represents the code to execute in the task. When the function has completed, the task's Result property will be set to return the result value of the function.
          /// @param state An object representing data to be used by the function.
          /// @remarks Rather than calling this constructor, the most common way to instantiate a Task object and launch a task is by calling the static TaskFactory.StartNew(Action<Object>, Object) method. The only advantage offered by this constructor is that it allows object instantiation to be separated from task invocation.
          Task(const Func<object&, TResult>& function, object& state) {
            this->data->parameterizedTask = function;
            this->data->state = &state;
          }

          /// @brief Initializes a new Task<TResult> with the specified function and state.
          /// @param function The delegate that represents the code to execute in the task. When the function has completed, the task's Result property will be set to return the result value of the function.
          /// @param state An object representing data to be used by the function.
          /// @remarks Rather than calling this constructor, the most common way to instantiate a Task object and launch a task is by calling the static TaskFactory.StartNew(Action<Object>, Object) method. The only advantage offered by this constructor is that it allows object instantiation to be separated from task invocation.
          Task(const Func<const object&, TResult>& task, const object& state) {
            this->data->constParameterizedTask = task;
            this->data->state = const_cast<object*>(&state);
          }

          /// @cond
          Task() {}
          Task(const Task& task) : data(task.data) {}
          Task& operator=(const Task& task) {this->data = task.data; return *this;}
          ~Task() {
            if (this->data.GetUseCount() == 1 && this->data->status != TaskStatus::Created)
              this->data->endEvent.WaitOne();
          }
          /// @endcond

          /// @brief Returns the ID of the currently executing Task.
          /// @return An integer that was assigned by the system to the currently-executing task.
          /// @remarks CurrentId is a static property that is used to get the identifier of the currently executing task from the code that the task is executing. It differs from the Id property, which returns the identifier of a particular Task instance. If you attempt to retrieve the CurrentId value from outside the code that a task is executing, the property returns null.
          static Nullable<int32> CurrentId();

          /// @brief Provides access to factory methods for creating and configuring Task and Task<TResult> instances.
          /// @return A factory object that can create a variety of Task and Task<TResult> objects.
          static TaskFactory& Factory();

          /// @brief Gets an ID for this Task instance.
          /// @brief The identifier that is assigned by the system to this Task instance.
          /// @remarks Task IDs are assigned on-demand and do not necessarily represent the order in which task instances are created. Note that although collisions are very rare, task identifiers are not guaranteed to be unique.
          /// @remarks To get the task ID of the currently executing task from within code that that task is executing, use the CurrentId property.
          property_<int32, readonly_> Id {
            get_ {return this->data->id;}
          };

          /// @brief Gets whether this Task instance has completed execution due to being canceled.
          /// @return true if the task has completed due to being canceled; otherwise false.
          property_<bool, readonly_> IsCanceled {
            get_ {return this->data->status == TaskStatus::Canceled;}
          };

          /// @brief Gets whether this Task has completed.
          /// @return rue if the task has completed; otherwise false.
          /// @remarks IsCompleted will return true when the task is in one of the three final states: RanToCompletion, Faulted, or Canceled.
          property_<bool, readonly_> IsCompleted {
            get_ {return this->data->status == TaskStatus::RanToCompletion || this->data->status == TaskStatus::Faulted || this->data->status == TaskStatus::Canceled;}
          };

          /// @brief Gets whether the Task completed due to an unhandled exception.
          /// @return true if the task has thrown an unhandled exception; otherwise false.
          /// @remarks If IsFaulted is true, the task's Status is equal to Faulted, and its Exception property will be non-null.
          property_<bool, readonly_> IsFaulted {
            get_ {return this->data->status == TaskStatus::Faulted;}
          };

          /// @brief Gets the TaskStatus of this task.
          /// @return The current TaskStatus of this task instance.
          property_<TaskStatus, readonly_> Status {
            get_ {return this->data->status;}
          };

          /// @brief Gets the result value of this Task<TResult>.
          /// @return The result value of this Task<TResult>, which is the same type as the task's type parameter.
          /// @remarks Accessing the property's get accessor blocks the calling thread until the asynchronous operation is complete; it is equivalent to calling the Wait method.
          property_<TResult, readonly_> Result {
            get_ {
              this->Wait();
              return this->data->result;
            }
          };

          /// @brief Creates a task that completes after a specified time interval.
          /// @param delay The time span to wait before completing the returned task, or TimeSpan.FromMilliseconds(-1) to wait indefinitely.
          /// @return A task that represents the time delay.
          /// @exception ArgumentOutOfRangeException The millisecondsDelay argument is less than -1.
          /// @par Examples
          /// The following example shows a simple use of the Delay method.
          /// @include TaskDelay.cpp
          static Task<TResult> Delay(const TimeSpan& delay) {return Delay(as<int32>(delay.TotalMilliseconds()));}

          /// @brief Creates a task that completes after a time delay.
          /// @param millisecondsDelay The number of milliseconds to wait before completing the returned task, or -1 to wait indefinitely.
          /// @return A task that represents the time delay.
          /// @exception ArgumentOutOfRangeException The millisecondsDelay argument is less than -1.
          /// @par Examples
          /// The following example shows a simple use of the Delay method.
          /// @include TaskDelay.cpp
          static Task<TResult> Delay(int32 millisecondsDelay) {
            Task<TResult> task;
            task.data->millisecondsDelay = millisecondsDelay;
            task.Start();
            return task;
          }

          /// @brief Queues the specified work to run on the thread pool and returns a Task object that represents that work.
          /// @param action The work to execute asynchronously
          /// @return A task that represents the work queued to execute in the ThreadPool.
          template<typename T>
          static Task<TResult> Run(const Action<>& action) {
            Task<TResult> task(action);
            task.Start();
            return task;
          }

          /// @brief Queues the specified work to run on the thread pool and returns a Task object that represents that work.
          /// @param action The work to execute asynchronously
          /// @param state An object representing data to be used by the action.
          /// @return A task that represents the work queued to execute in the ThreadPool.
          template<typename T>
          static Task<TResult> Run(const Action<Object&>& action, object& state) {
            Task<TResult> task(action, state);
            task.Start();
            return task;
          }

          /// @brief Queues the specified work to run on the thread pool and returns a Task object that represents that work.
          /// @param action The work to execute asynchronously
          /// @param state An object representing data to be used by the action.
          /// @return A task that represents the work queued to execute in the ThreadPool.
          template<typename T>
          static Task<TResult> Run(const Action<const Object&>& action, const Object& state) {
            Task<TResult> task(action, state);
            task.Start();
            return task;
          }

          /// @brief Queues the specified work to run on the thread pool and returns a Task<TResult> object that represents that work.
          /// @param function The work to execute asynchronously.
          /// @return A task that represents the work queued to execute in the ThreadPool.
          static Task<TResult> Run(const Func<TResult>& func) {
            Task<TResult> task(func);
            task.Start();
            return task;
          }

          /// @brief Queues the specified work to run on the thread pool and returns a Task object that represents that work.
          /// @param function The work to execute asynchronously.
          /// @param state An object representing data to be used by the action.
          /// @return A task that represents the work queued to execute in the ThreadPool.
          static Task<TResult> Run(const Func<object&, TResult>& func, object& state) {
            Task<TResult> task(func, state);
            task.Start();
            return task;
          }

          /// @brief Queues the specified work to run on the thread pool and returns a Task object that represents that work.
          /// @param function The work to execute asynchronously.
          /// @param state An object representing data to be used by the action.
          /// @return A task that represents the work queued to execute in the ThreadPool.
          static Task<TResult> Run(const Func<const object&, TResult>& func, const object& state) {
            Task<TResult> task(func, state);
            task.Start();
            return task;
          }

          /// @brief Runs the Task synchronously on the current TaskScheduler.
          /// @remarks Ordinarily, tasks are executed asynchronously on a thread pool thread and do not block the calling thread. Tasks executed by calling the RunSynchronously() method are associated with the current TaskScheduler and are run on the calling thread. If the target scheduler does not support running this task on the calling thread, the task will be scheduled for execution on the scheduler, and the calling thread will block until the task has completed execution. Even though the task runs synchronously, the calling thread should still call Wait to handle any exceptions that the task might throw. For more information on exception handling, see Exception Handling (Task Parallel Library).
          /// @remarks Tasks executed by calling the RunSynchronously method are instantiated by calling a Task or Task<TResult> class constructor. The task to be run synchronously must be in the TaskStatus.Created state. A task may be started and run only once. Any attempts to schedule a task a second time results in an exception.
          void RunSynchronously() {
            if (this->data->status != TaskStatus::Created || (this->data->millisecondsDelay == -2 && this->data->task.IsEmpty() && this->data->parameterizedTask.IsEmpty() && this->data->constParameterizedTask.IsEmpty()))
              throw InvalidOperationException(caller_);

            this->data->status = TaskStatus::WaitingToRun;
            this->data->waitOrTimerCallback(*this->data->state, false);
            this->data->startEvent.Set();
            __opaque_task_id_generator__::currentId = 0;
          }

          /// @brief Starts the Task, scheduling it for execution to the current TaskScheduler.
          /// @exception InvalidOperationException The Task is not in a valid state to be started. It may have already been started, executed, or canceled, or it may have been created in a manner that doesn't support direct scheduling.
          /// @remarks A task may be started and run only once. Any attempts to schedule a task a second time will result in an exception.
          /// @remarks The Start is used to execute a task that has been created by calling one of the Task constructors. Typically, you do this when you need to separate the task's creation from its execution, such as when you conditionally execute tasks that you've created. For the more common case in which you don't need to separate task instantiation from execution, we recommend that you call an overload of the Task.Run or TaskFactory.StartNew method.
          /// @remarks For information on handling exceptions thrown by task operations, see Exception Handling (Task Parallel Library).
          void Start() override {
            if (this->data->status != TaskStatus::Created)
              throw InvalidOperationException(caller_);
            this->data->status = TaskStatus::WaitingForActivation;
            ThreadPool::RegisterWaitForSingleObject(this->data->startEvent, this->data->waitOrTimerCallback, *this->data->state, Timeout::Infinite, true);
            this->data->status = TaskStatus::WaitingToRun;
            this->data->startEvent.Set();
          }

          /// @brief Waits for the Task to complete execution.
          /// @remarks Wait is a synchronization method that causes the calling thread to wait until the current task has completed. If the current task has not started execution, the Wait method attempts to remove the task from the scheduler and execute it inline on the current thread. If it is unable to do that, or if the current task has already started execution, it blocks the calling thread until the task completes. For more information, see Task.Wait and "Inlining" in the Parallel Programming with .NET blog.
          void Wait() override {this->Wait(Timeout::Infinite);}

          /// @brief Waits for the Task to complete execution within a specified number of milliseconds.
          /// @param millisecondsTimeout The number of milliseconds to wait, or Infinite (-1) to wait indefinitely.
          /// @return true if the Task completed execution within the allotted time; otherwise, false.
          /// @exception ArgumentOutOfRangeException millisecondsTimeout is a negative number other than -1, which represents an infinite time-out.
          bool Wait(int32 millisecondsTimeout) override {
            bool result = this->data->endEvent.WaitOne(millisecondsTimeout);
            if (this->data->status == TaskStatus::Faulted)
              throw this->data->aggregateException;
            this->data->status = TaskStatus::RanToCompletion;
            return result;
          }

          /// @brief Waits for the Task to complete execution within a specified time interval.
          /// @param timeout A TimeSpan that represents the number of milliseconds to wait, or a TimeSpan that represents -1 milliseconds to wait indefinitely.
          /// @return true if the Task completed execution within the allotted time; otherwise, false.
          /// @exception ArgumentOutOfRangeException timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.
          bool Wait(const TimeSpan& timeout) override {return this->Wait(as<int32>(timeout.TotalMilliseconds()));}

          /// @brief Waits for all of the provided Task objects to complete execution.
          /// @param tasks An array of ITask instances on which to wait.
          static void WaitAll(Array<ref<ITask>> tasks) {WaitAll(tasks, Timeout::Infinite);}

          /// @brief Waits for all of the provided Task objects to complete execution.
          /// @param tasks An array of Task instances on which to wait.
          static void WaitAll(Array<Task<TResult>> tasks) {WaitAll(tasks, Timeout::Infinite);}

          /// @brief Waits for all of the provided Task objects to complete execution.
          /// @param tasks An array of Task instances on which to wait.
          template<typename T>
          static void WaitAll(Array<Task<T>> tasks) {WaitAll(tasks, Timeout::Infinite);}

          /// @brief Waits for all of the provided cancellable Task objects to complete execution within a specified time interval.
          /// @param tasks An array of ITask instances on which to wait.
          /// @param timeout A TimeSpan that represents the number of milliseconds to wait, or a TimeSpan that represents -1 milliseconds to wait indefinitely.
          /// @exception ArgumentOutOfRangeException timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.
          static bool WaitAll(Array<ref<ITask>> tasks, const TimeSpan& timeout) {return WaitAll(tasks, as<int32>(timeout.TotalMilliseconds()));}

          /// @brief Waits for all of the provided cancellable Task objects to complete execution within a specified time interval.
          /// @param tasks An array of Task instances on which to wait.
          /// @param timeout A TimeSpan that represents the number of milliseconds to wait, or a TimeSpan that represents -1 milliseconds to wait indefinitely.
          /// @exception ArgumentOutOfRangeException timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.
          static bool WaitAll(Array<Task<TResult>> tasks, const TimeSpan& timeout) {return WaitAll(tasks, as<int32>(timeout.TotalMilliseconds()));}

          /// @brief Waits for all of the provided cancellable Task objects to complete execution within a specified time interval.
          /// @param tasks An array of Task instances on which to wait.
          /// @param timeout A TimeSpan that represents the number of milliseconds to wait, or a TimeSpan that represents -1 milliseconds to wait indefinitely.
          /// @exception ArgumentOutOfRangeException timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.
          template<typename T>
          static bool WaitAll(Array<Task<T>> tasks, const TimeSpan& timeout) {return WaitAll(tasks, as<int32>(timeout.TotalMilliseconds()));}

          /// @brief Waits for all of the provided Task objects to complete execution within a specified number of milliseconds.
          /// @param tasks An array of ITask instances on which to wait.
          /// @param millisecondsTimeout The number of milliseconds to wait, or Infinite (-1) to wait indefinitely.
          /// @exception ArgumentOutOfRangeException millisecondsTimeout is a negative number other than -1, which represents an infinite time-out.
          static bool WaitAll(Array<ref<ITask>> tasks, int32 millisecondsTimeout) {
            if (millisecondsTimeout < Timeout::Infinite)
              ArgumentOutOfRangeException(System::Runtime::CompilerServices::Caller(__FILE__, __LINE__));

            if (millisecondsTimeout == Timeout::Infinite) {
              for (auto& task : tasks)
                task().Wait();
              return true;
            }

            int32 timeout = millisecondsTimeout;
            int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
            for (auto& item : tasks) {
              if (item().Wait(timeout) == false)
                return false;
              timeout = millisecondsTimeout - (int32)(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start);
              if (timeout < 0)
                return false;
            }
            return true;
          }

          /// @brief Waits for all of the provided Task objects to complete execution within a specified number of milliseconds.
          /// @param tasks An array of Task instances on which to wait.
          /// @param millisecondsTimeout The number of milliseconds to wait, or Infinite (-1) to wait indefinitely.
          /// @exception ArgumentOutOfRangeException millisecondsTimeout is a negative number other than -1, which represents an infinite time-out.
          static bool WaitAll(Array<Task<TResult>> tasks, int32 millisecondsTimeout) {
            if (millisecondsTimeout < Timeout::Infinite)
              ArgumentOutOfRangeException(System::Runtime::CompilerServices::Caller(__FILE__, __LINE__));

            if (millisecondsTimeout == Timeout::Infinite) {
              for (auto& task : tasks)
                task.Wait();
              return true;
            }

            int32 timeout = millisecondsTimeout;
            int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
            for (auto& item : tasks) {
              if (item.Wait(timeout) == false)
                return false;
              timeout = millisecondsTimeout - (int32)(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start);
              if (timeout < 0)
                return false;
            }
            return true;
          }

          /// @brief Waits for all of the provided Task objects to complete execution within a specified number of milliseconds.
          /// @param tasks An array of Task instances on which to wait.
          /// @param millisecondsTimeout The number of milliseconds to wait, or Infinite (-1) to wait indefinitely.
          /// @exception ArgumentOutOfRangeException millisecondsTimeout is a negative number other than -1, which represents an infinite time-out.
          template<typename T>
          static bool WaitAll(Array<Task<T>> tasks, int32 millisecondsTimeout) {
            if (millisecondsTimeout < Timeout::Infinite)
              ArgumentOutOfRangeException(System::Runtime::CompilerServices::Caller(__FILE__, __LINE__));

            if (millisecondsTimeout == Timeout::Infinite) {
              for (auto& task : tasks)
                task.Wait();
              return true;
            }

            int32 timeout = millisecondsTimeout;
            int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
            for (auto& item : tasks) {
              if (item.Wait(timeout) == false)
                return false;
              timeout = millisecondsTimeout - (int32)(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start);
              if (timeout < 0)
                return false;
            }
            return true;
          }

          /// @brief Waits for any of the provided Task objects to complete execution.
          /// @param tasks An array of ITask instances on which to wait.
          static void WaitAny(Array<ref<ITask>> tasks) {WaitAny(tasks, Timeout::Infinite);}

          /// @brief Waits for any of the provided Task objects to complete execution.
          /// @param tasks An array of Task instances on which to wait.
          static void WaitAny(Array<Task<TResult>> tasks) {WaitAny(tasks, Timeout::Infinite);}

          /// @brief Waits for any of the provided Task objects to complete execution.
          /// @param tasks An array of Task instances on which to wait.
          template<typename T>
          static void WaitAny(Array<Task<T>> tasks) {WaitAny(tasks, Timeout::Infinite);}

          /// @brief Waits for any of the provided cancellable Task objects to complete execution within a specified time interval.
          /// @param tasks An array of ITask instances on which to wait.
          /// @param timeout A TimeSpan that represents the number of milliseconds to wait, or a TimeSpan that represents -1 milliseconds to wait indefinitely.
          /// @exception ArgumentOutOfRangeException timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.
          static int32 WaitAny(Array<ref<ITask>> tasks, const TimeSpan& timeout) {return WaitAny(tasks, as<int32>(timeout.TotalMilliseconds()));}

          /// @brief Waits for any of the provided cancellable Task objects to complete execution within a specified time interval.
          /// @param tasks An array of Task instances on which to wait.
          /// @param timeout A TimeSpan that represents the number of milliseconds to wait, or a TimeSpan that represents -1 milliseconds to wait indefinitely.
          /// @exception ArgumentOutOfRangeException timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.
          static int32 WaitAny(Array<Task<TResult>> tasks, const TimeSpan& timeout) {return WaitAny(tasks, as<int32>(timeout.TotalMilliseconds()));}

          /// @brief Waits for any of the provided cancellable Task objects to complete execution within a specified time interval.
          /// @param tasks An array of Task instances on which to wait.
          /// @param timeout A TimeSpan that represents the number of milliseconds to wait, or a TimeSpan that represents -1 milliseconds to wait indefinitely.
          /// @exception ArgumentOutOfRangeException timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.
          template<typename T>
          static int32 WaitAny(Array<Task<T>> tasks, const TimeSpan& timeout) {return WaitAny(tasks, as<int32>(timeout.TotalMilliseconds()));}

          /// @brief Waits for any of the provided Task objects to complete execution within a specified number of milliseconds.
          /// @param tasks An array of ITask instances on which to wait.
          /// @param millisecondsTimeout The number of milliseconds to wait, or Infinite (-1) to wait indefinitely.
          /// @exception ArgumentOutOfRangeException millisecondsTimeout is a negative number other than -1, which represents an infinite time-out.
          static int32 WaitAny(Array<ref<ITask>> tasks, int32 millisecondsTimeout) {
            if (millisecondsTimeout < Timeout::Infinite)
              ArgumentOutOfRangeException(System::Runtime::CompilerServices::Caller(__FILE__, __LINE__));

            if (millisecondsTimeout == Timeout::Infinite) {
              for (int32 index = 0; index < tasks.Count; index++) {
                if (tasks[index]().Wait(0) == true)
                  return index;
                Thread::Yield();
                Thread::Sleep(1);
              }
              return -1;
            }

            int32 timeout = millisecondsTimeout;
            int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
            do {
              for (int32 index = 0; index < tasks.Count; index++) {
                if (tasks[index]().Wait(0) == true)
                  return index;
                timeout = millisecondsTimeout - (int32)(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start);
                if (timeout < 0)
                  return -1;
                Thread::Yield();
                Thread::Sleep(1);
              }
            } while (timeout >= 0);
            return -1;
          }

          /// @brief Waits for any of the provided Task objects to complete execution within a specified number of milliseconds.
          /// @param tasks An array of Task instances on which to wait.
          /// @param millisecondsTimeout The number of milliseconds to wait, or Infinite (-1) to wait indefinitely.
          /// @exception ArgumentOutOfRangeException millisecondsTimeout is a negative number other than -1, which represents an infinite time-out.
          static int32 WaitAny(Array<Task<TResult>> tasks, int32 millisecondsTimeout) {
            if (millisecondsTimeout < Timeout::Infinite)
              ArgumentOutOfRangeException(System::Runtime::CompilerServices::Caller(__FILE__, __LINE__));

            if (millisecondsTimeout == Timeout::Infinite) {
              for (int32 index = 0; index < tasks.Count; index++) {
                if (tasks[index].Wait(0) == true)
                  return index;
                Thread::Yield();
                Thread::Sleep(1);
              }
              return -1;
            }

            int32 timeout = millisecondsTimeout;
            int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
            do {
              for (int32 index = 0; index < tasks.Count; index++) {
                if (tasks[index].Wait(0) == true)
                  return index;
                timeout = millisecondsTimeout - (int32)(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start);
                if (timeout < 0)
                  return -1;
                Thread::Yield();
                Thread::Sleep(1);
              }
            } while (timeout >= 0);
            return -1;
          }

          /// @brief Waits for any of the provided Task objects to complete execution within a specified number of milliseconds.
          /// @param tasks An array of Task instances on which to wait.
          /// @param millisecondsTimeout The number of milliseconds to wait, or Infinite (-1) to wait indefinitely.
          /// @exception ArgumentOutOfRangeException millisecondsTimeout is a negative number other than -1, which represents an infinite time-out.
          template<typename T>
          static int32 WaitAny(Array<Task<T>> tasks, int32 millisecondsTimeout) {
            if (millisecondsTimeout < Timeout::Infinite)
              ArgumentOutOfRangeException(System::Runtime::CompilerServices::Caller(__FILE__, __LINE__));

            if (millisecondsTimeout == Timeout::Infinite) {
              for (int32 index = 0; index < tasks.Count; index++) {
                if (tasks[index].Wait(0) == true)
                  return index;
                Thread::Yield();
                Thread::Sleep(1);
              }
              return -1;
            }

            int32 timeout = millisecondsTimeout;
            int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
            do {
              for (int32 index = 0; index < tasks.Count; index++) {
                if (tasks[index].Wait(0) == true)
                  return index;
                timeout = millisecondsTimeout - (int32)(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start);
                if (timeout < 0)
                  return -1;
                Thread::Yield();
                Thread::Sleep(1);
              }
            } while (timeout >= 0);
            return -1;
          }

          /// @brief Creates an awaitable task that asynchronously yields back to the current context when awaited.
          static bool Yield() {return Thread::Yield();}

        private:
          class TaskData {
            friend class Task<TResult>;
            TaskData() = default;
            TaskData(const TaskData&) = delete;
            TaskData operator=(const TaskData&) = delete;
            Func<TResult> task;
            Func<Object&, TResult> parameterizedTask;
            Func<const Object&, TResult> constParameterizedTask;
            int32 id {__opaque_task_id_generator__()()};
            TaskStatus status {TaskStatus::Created};
            AutoResetEvent startEvent;
            ManualResetEvent endEvent;
            object* state = null;
            TResult result;
            int32 millisecondsDelay = -2;
            AggregateException aggregateException;
            WaitOrTimerCallback waitOrTimerCallback = delegate_(object& state, bool timeout) {
              __opaque_task_id_generator__::currentId = this->id;
              this->status = TaskStatus::Running;
              try {
                if (this->millisecondsDelay != -2)
                  Thread::Sleep(this->millisecondsDelay);
                if (!this->task.IsEmpty())
                  this->result = Move(this->task());
                else if (!this->parameterizedTask.IsEmpty())
                  this->result = Move(this->parameterizedTask(state));
                else if (!this->constParameterizedTask.IsEmpty())
                  this->result = Move(this->constParameterizedTask(*this->state));
                this->status = TaskStatus::WaitingForChildrenToComplete;
                this->endEvent.Set();
              } catch (...) {
                this->aggregateException = AggregateException(Array<ExceptionPtr> {excptr::CurrentException()}, caller_);
                this->status = TaskStatus::Faulted;
                this->endEvent.Set();
              }
            };
          };

          refptr<TaskData> data {new TaskData()};
        };
      }
    }
  }
}

using namespace Switch;
