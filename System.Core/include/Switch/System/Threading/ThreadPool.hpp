/// @file
/// @brief Contains Switch::System::Threading::ThreadPool class.
#pragma once

#include "../../Types.hpp"
#include "../../RefPtr.hpp"
#include "../../Static.hpp"
#include "../TimeSpan.hpp"
#include "../Collections/Generic/List.hpp"
#include "Thread.hpp"
#include "RegisteredWaitHandle.hpp"
#include "WaitCallback.hpp"
#include "WaitHandle.hpp"
#include "WaitOrTimerCallback.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Provides a pool of threads that can be used to post work items, process asynchronous I/O, wait on behalf of other threads, and process timers.
      class core_export_ ThreadPool static_ {
      public:
        /// @brief Retrieves the difference between the maximum number of thread pool threads returned by the GetMaxThreads method, and the number currently active.
        /// @param workerThreads The number of available worker threads
        /// @param completionPortThreads The number of available asynchronous I/O threads.
        /// @exception ArgumentNullException The workerThreads or completionPortThreads param is null.
        /// @remarks When GetAvailableThreads returns, the variable specified by workerThreads contains the number of additional worker threads that can be started, and the variable specified by completionPortThreads contains the number of additional asynchronous I/O threads that can be started.
        static void GetAvailableThreads(int32& workerThreads, int32& completionPortThreads);

        /// @brief Retrieves the number of requests to the thread pool that can be active concurrently. All requests above that number remain queued until thread pool threads become available.
        /// @param workerThreads The maximum number of worker threads in the thread pool.
        /// @param completionPortThreads The maximum number of asynchronous I/O threads in the thread pool.
        /// @exception ArgumentNullException The workerThreads or completionPortThreads param is null.
        /// @remarks When GetMaxThreads returns, the variable specified by workerThreads contains the maximum number of worker threads allowed in the thread pool, and the variable specified by completionPortThreads contains the maximum number of asynchronous I/O threads allowed in the thread pool.
        /// @remarks You can use the GetAvailableThreads method to determine the actual number of threads in the thread pool at any given time.
        /// @remarks You can use the SetMaxThreads to set the maximum number of worker threads and asynchronous I/O threads in the thread pool.
        static void GetMaxThreads(int32& workerThreads, int32& completionPortThreads);

        /// @brief Retrieves the number of idle threads the thread pool maintains in anticipation of new requests. Always 0 for both.
        /// @param workerThreads The maximum number of worker threads in the thread pool.
        /// @param completionPortThreads The maximum number of asynchronous I/O threads in the thread pool.
        /// @exception ArgumentNullException The workerThreads or completionPortThreads param is null.
        /// @remarks To develop in the future for optimization.
        static void GetMinThreads(int32& workerThreads, int32& completionPortThreads);

        /// @brief Queues a method for execution. The method executes when a thread pool thread becomes available.
        /// @param callBack A pointer function that represents the method to be executed.
        /// @return Boolean true if the method is successfully queued; NotSupportException is thrown if the work item could not be queued
        /// @exception ArgumentNullException The callBack param is null.
        static bool QueueUserWorkItem(const WaitCallback& callBack);

        /// @brief Queues a method for execution. The method executes when a thread pool thread becomes available.
        /// @param callBack A pointer function that represents the method to be executed.
        /// @param state An object containing data to be used by the method.
        /// @return Boolean true if the method is successfully queued; NotSupportedException is thrown if the work item could not be queued
        /// @exception ArgumentNullException The callBack param is null.
        static bool QueueUserWorkItem(const WaitCallback& callBack, object& state);

        /// @brief Registers a delegate to wait for a WaitHandle, specifying a 32-bit signed integer for the time-out in milliseconds.
        /// @param waitObject The WaitHandle to register. Use a WaitHandle other than Mutex
        /// @param callBack A pointer function to call when the waitObject parameter is signaled.
        /// @param state The object that is passed to the callBack.
        /// @param millisecondsTimeoutInterval The time-out in milliseconds. If the millisecondsTimeoutInterval parameter is 0 (zero), the function tests the object's state and returns immediately. If millisecondsTimeoutInterval is -1, the function's time-out interval never elapses.
        /// @param executeOnlyOnce true to indicate that the thread will no longer wait on the waitObject parameter after the callBack has been called; false to indicate that the timer is reset every time the wait operation completes until the wait is unregistered.
        /// @return RegisteredWaitHandle The RegisteredWaitHandle that encapsulates the native handle.
        /// @exception ArgumentNullException The callBack param is null.
        /// @exception ArgumentOutOfRangeException The millisecondsTimeoutInterval parameter is less than -1.
        static RegisteredWaitHandle RegisterWaitForSingleObject(WaitHandle& waitObject, const WaitOrTimerCallback& callBack, Object& state, int32 millisecondsTimeoutInterval, bool executeOnlyOnce);

        /// @brief Registers a delegate to wait for a WaitHandle, specifying a 32-bit signed integer for the time-out in milliseconds.
        /// @param waitObject The WaitHandle to register. Use a WaitHandle other than Mutex
        /// @param callBack A pointer function to call when the waitObject parameter is signaled.
        /// @param state The object that is passed to the callBack.
        /// @param millisecondsTimeoutInterval The time-out in milliseconds. If the millisecondsTimeoutInterval parameter is 0 (zero), the function tests the object's state and returns immediately. If millisecondsTimeoutInterval is -1, the function's time-out interval never elapses.
        /// @param executeOnlyOnce true to indicate that the thread will no longer wait on the waitObject parameter after the callBack has been called; false to indicate that the timer is reset every time the wait operation completes until the wait is unregistered.
        /// @return RegisteredWaitHandle The RegisteredWaitHandle that encapsulates the native handle.
        /// @exception ArgumentNullException The callBack param is null.
        /// @exception ArgumentOutOfRangeException The millisecondsTimeoutInterval parameter is less than -1.
        static RegisteredWaitHandle RegisterWaitForSingleObject(WaitHandle& waitObject, const WaitOrTimerCallback& callBack, Object& state, int64 millisecondsTimeoutInterval, bool executeOnlyOnce)  {return RegisterWaitForSingleObject(waitObject, callBack, state, TimeSpan::FromMilliseconds(as<int32>(millisecondsTimeoutInterval)), executeOnlyOnce);}

        /// @brief Registers a delegate to wait for a WaitHandle, specifying a 32-bit signed integer for the time-out in milliseconds.
        /// @param waitObject The WaitHandle to register. Use a WaitHandle other than Mutex
        /// @param callBack A pointer function to call when the waitObject parameter is signaled.
        /// @param state The object that is passed to the callBack.
        /// @param timeout The time-out represented by a TimeSpan.If timeout is 0 (zero), the function tests the object's state and returns immediately.If timeout is -1, the function's time-out interval never elapses.
        /// @param executeOnlyOnce true to indicate that the thread will no longer wait on the waitObject parameter after the callBack has been called; false to indicate that the timer is reset every time the wait operation completes until the wait is unregistered.
        /// @return RegisteredWaitHandle The RegisteredWaitHandle that encapsulates the native handle.
        /// @exception ArgumentNullException The callBack param is null.
        /// @exception ArgumentOutOfRangeException The millisecondsTimeoutInterval parameter is less than -1.
        static RegisteredWaitHandle RegisterWaitForSingleObject(WaitHandle& waitObject, const WaitOrTimerCallback& callBack, Object& state, const TimeSpan& timeout, bool executeOnlyOnce) {return RegisterWaitForSingleObject(waitObject, callBack, state, as<int32>(timeout.TotalMilliseconds()), executeOnlyOnce);}

        /// @brief Registers a delegate to wait for a WaitHandle, specifying a 32-bit signed integer for the time-out in milliseconds.
        /// @param waitObject The WaitHandle to register. Use a WaitHandle other than Mutex
        /// @param callBack A pointer function to call when the waitObject parameter is signaled.
        /// @param state The object that is passed to the callBack.
        /// @param millisecondsTimeoutInterval The time-out in milliseconds. If the millisecondsTimeoutInterval parameter is 0 (zero), the function tests the object's state and returns immediately. If millisecondsTimeoutInterval is -1, the function's time-out interval never elapses.
        /// @param executeOnlyOnce true to indicate that the thread will no longer wait on the waitObject parameter after the callBack has been called; false to indicate that the timer is reset every time the wait operation completes until the wait is unregistered.
        /// @return RegisteredWaitHandle The RegisteredWaitHandle that encapsulates the native handle.
        /// @exception ArgumentNullException The callBack param is null.
        static RegisteredWaitHandle RegisterWaitForSingleObject(WaitHandle& waitObject, const WaitOrTimerCallback& callBack, object& state, uint32 millisecondsTimeoutInterval, bool executeOnlyOnce) {return RegisterWaitForSingleObject(waitObject, callBack, state, TimeSpan::FromMilliseconds(as<int32>(millisecondsTimeoutInterval)), executeOnlyOnce);}

        /// @brief Sets the number of requests to the thread pool that can be active concurrently. All requests above that number remain queued until thread pool threads become available.
        /// @param workerThreads The maximum number of worker threads in the thread pool.
        /// @param completionPortThreads The maximum number of asynchronous I/O threads in the thread pool.
        /// @return Boolean true if the change is successful; otherwise, false.
        /// @exception ArgumentOutOfRangeException if the workerThreads  is < 0 or > MaxThreads  - or - if the completionPortThreads  is < 0 or > MaxAsynchronousIoThreads.
        /// @remarks The maximum value that can be set is 256.
        /// @see MaxThreads
        /// @see MaxAsynchronousIoThreads
        static bool SetMaxThreads(int32 workerThreads, int32 completionPortThreads);

        /// @brief Sets the number of idle threads the thread pool maintains in anticipation of new requests.
        /// @param workerThreads The new minimum number of idle worker threads to be maintained by the thread pool.
        /// @param completionPortThreads The new minimum number of idle asynchronous I/O threads to be maintained by the thread pool.
        /// @return Boolean true if the change is successful; otherwise, false.
        /// @exception ArgumentOutOfRangeException if the workerThreads  is different of 0 - or - if the completionPortThreads  is different of 0.
        /// @remarks The only value that can be set is 0.
        /// @remarks To develop in the future for optimization.
        static bool SetMinThreads(int32 workerThreads, int32 completionPortThreads);

      private:
        static int32 maxThreads;
        static int32 maxAsynchronousIOThreads;
        static int32 minThreads;
        static int32 minAsynchronousIOThreads;
        static bool closed;

        template<typename T>
        struct ThreadItem : public Object {
          ThreadItem() {}
          ThreadItem(const T& callback) : callback(callback) {}
          ThreadItem(const T& callback, object& state) : callback(callback), state(&state) {}
          ThreadItem(const T& callback, object& state, WaitHandle& waitObject, int32 millisecondsTimeoutInterval, bool executeOnlyOnce) : callback(callback), state(&state), waitObject(&waitObject), millisecondsTimeoutInterval(millisecondsTimeoutInterval), executeOnlyOnce(executeOnlyOnce) {}

          T callback;
          Object* state = null;
          WaitHandle* waitObject = null;
          int32 millisecondsTimeoutInterval;
          bool executeOnlyOnce = true;
          bool unregistered = false;

          void Run() {
            do {
              this->callback(*state);
            } while (!executeOnlyOnce);
          }
        };

        using ThreadPoolItem = ThreadItem<WaitCallback>;
        using ThreadPoolAsynchronousIOItem = ThreadItem<WaitOrTimerCallback>;

        using ThreadPoolItemCollection = System::Collections::Generic::List<refptr<ThreadPoolItem>>;
        using ThreadPoolAsynchronousIOItemCollection = System::Collections::Generic::List<refptr<ThreadPoolAsynchronousIOItem>>;

        static ThreadPoolItemCollection threadPoolItems;
        static ThreadPoolAsynchronousIOItemCollection threadPoolAsynchronousIOItems;

        static void Run();
        static void AsynchronousIORun();

        static void CreateThreads();
        static void CreateAsynchronousIOThreads();

        friend class RegisteredWaitHandle;
        class ThreadArray : public Array<Thread> {
        public:
          ThreadArray() {}
          ThreadArray(int32 count) : Array<Thread>(count) {}
          ~ThreadArray();
        };
        class AsynchronousThreadArray : public Array<Thread> {
        public:
          AsynchronousThreadArray() {}
          AsynchronousThreadArray(int32 count) : Array<Thread>(count) {}
          ~AsynchronousThreadArray();
        };
        static ThreadArray threads;
        static AsynchronousThreadArray asynchronousIOThreads;
      };
    }
  }
}

using namespace Switch;
