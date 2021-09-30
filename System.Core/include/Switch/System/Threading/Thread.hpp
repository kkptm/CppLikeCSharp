/// @file
/// @brief Contains Switch::System::Threading::Thread class.
#pragma once

#include <functional>
#include <memory>
#include <sstream>
#include <thread>

#include "../../Types.hpp"
#include "../Collections/Generic/Dictionary.hpp"
#include "../Collections/Generic/List.hpp"
#include "ManualResetEvent.hpp"
#include "ParameterizedThreadStart.hpp"
#include "ThreadAbortException.hpp"
#include "ThreadInterruptedException.hpp"
#include "ThreadPriority.hpp"
#include "ThreadStart.hpp"
#include "ThreadState.hpp"
#include "ThreadStateException.hpp"
#include "Timeout.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    class Environment;
    /// @endcond

    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @cond
      class ThreadPool;
      /// @endcond
      /// @brief Creates and controls a thread, sets its priority, and gets its status.
      /// @remarks A process can create one or more threads to execute a portion of the program code associated with the process. Use a ThreadStart delegate or the ParameterizedThreadStart delegate to specify the program code executed by a thread. The ParameterizedThreadStart delegate allows you to pass data to the thread procedure.
      /// @remarks For the duration of its existence, a thread is always in one or more of the states defined by ThreadState. A scheduling priority level, as defined by ThreadPriority, can be requested for a thread, but is not guaranteed to be honored by the operating system.
      /// @remarks GetHashCode provides identification for managed threads. For the lifetime of your thread, it will not collide with the value from any other thread, regardless of the application domain from which you obtain the value.
      ///
      /// <b>Starting a Thread</b>
      ///
      /// You start a thread by supplying a delegate that represents the method the thread is to execute in its class constructor. You then call the Start method to begin execution.
      ///
      /// The Thread constructors can take either of two delegate types, depending on whether you can pass an argument to the method to be executed:
      ///  * If the method has no arguments, you pass a ThreadStart delegate to the constructor. It has the signature:
      /// @code using ThreadStart = delegate<void> @endcode
      ///
      /// The following example creates and starts a thread that executes the ExecuteInForeground method. The method displays information about some thread properties, then executes a loop in which it pauses for half a second and displays the elapsed number of seconds. When the thread has executed for at least five seconds, the loop ends and the thread terminates execution.
      /// @include Thread1.cpp
      ///
      /// * If the method has an argument, you pass a ParameterizedThreadStart delegate to the constructor. It has the signature:
      /// @code using ParameterizedThreadStart = delegate<void, const object&> @endcode
      ///
      /// The method executed by the delegate can then cast with as<T>(...) the parameter to the appropriate type.
      ///
      /// The following example is identical to the previous one, except that it calls the Thread(ParameterizedThreadStart) constructor. This version of the ExecuteInForeground method has a single parameter that represents the approximate number of milliseconds the loop is to execute.
      /// @include Thread2.cpp
      /// It is not necessary to join. The thread is joined auomaticaly when destroyed. The thread continues to execute until the thread procedure is complete.
      ///
      /// <b>Retrieving Thread objects</b>
      ///
      /// You can use the static CurrentThread property to retrieve a reference to the currently executing thread from the code that the thread is executing. The following example uses the CurrentThread property to display information about the main application thread, another foreground thread, a background thread, and a thread pool thread.
      /// @include Thread3.cpp
      ///
      /// <b>Foreground and background threads</b>
      ///
      /// Instances of the Thread class represent either foreground threads or background threads. Background threads are identical to foreground threads with one exception: a background thread does not keep a process running if all foreground threads have terminated. Once all foreground threads have been stopped, the runtime stops all background threads and shuts down.
      ///
      /// By default, the following threads execute in the foreground:
      /// * The main application thread.
      /// * All threads created by calling a Thread class constructor.
      ///
      /// The following threads execute in the background by default:
      /// * Thread pool threads, which are a pool of worker threads maintained by the runtime. You can configure the thread pool and schedule work on thread pool threads by using the ThreadPool class.
      ///   @note Task-based asynchronous operations automatically execute on thread pool threads. Task-based asynchronous operations use the Task and Task<TResult> classes to implement the task-based asynchronous pattern.
      /// * All threads not created by calling a Thread class constructor.
      ///
      /// You can change a thread to execute in the background by setting the IsBackground property at any time. Background threads are useful for any operation that should continue as long as an application is running but should not prevent the application from terminating, such as monitoring file system changes or incoming socket connections.
      ///
      /// The following example illustrates the difference between foreground and background threads. It is like the first example in the Starting a thread section, except that it sets the thread to execute in the background before starting it. As the output shows, the loop is interrupted before it executes for five seconds.
      /// @include Thread4.cpp
      ///
      /// <b>Getting information about and controlling threads</b>
      ///
      /// You can retrieve a number of property values that provide information about a thread. In some cases, you can also set these property values to control the operation of the thread. These thread properties include:
      /// * A name. Name is a write-once property that you can use to identify a thread. Its default value is empty.
      /// * A hash code, which you can retrieve by calling the GetHashCode method. The hash code can be used to uniquely identify a thread; for the lifetime of your thread, its hash code will not collide with the value from any other thread, regardless of the application domain from which you obtain the value.
      /// * A thread ID. The value of the read-only ManagedThreadId property is assigned by the runtime and uniquely identifies a thread within its process.
      ///   @note For thread not created by calling a Thread class constructor this value is euqal to 0.
      /// * The thread's current state. For the duration of its existence, a thread is always in one or more of the states defined by the ThreadState property.
      /// * A scheduling priority level, which is defined by the ThreadPriority property. Although you can set this value to request a thread's priority, it is not guaranteed to be honored by the operating system.
      /// * The read-only IsThreadPoolThread property, which indicates whether a thread is a thread pool thread.
      /// * The IsBackground property. For more information, see the Foreground and background threads section.
      ///
      /// @par Examples
      /// The following code example demonstrates simple threading functionality.
      /// @include Thread.cpp
      class core_export_ Thread : public object {
      public:
        /// @brief Initializes a new instance of the Thread class.
        /// @param start A ThreadStart delegate that represents the methods to be invoked when this thread begins executing.
        explicit Thread(System::Threading::ThreadStart start) : data(new ThreadItem(start)) {}

        /// @brief nitializes a new instance of the Thread class, specifying the maximum stack size for the thread.
        /// @param start A ThreadStart delegate that represents the methods to be invoked when this thread begins executing.
        /// @param maxStackSize The maximum stack size, in bytes, to be used by the thread, or 0 to use the default maximum stack size specified in the header for the executable.
        /// @note Important: For partially trusted code, maxStackSize is ignored if it is greater than the default stack size. No exception is thrown.
        /// @note maxStackSize is ignored.
        Thread(System::Threading::ThreadStart start, int32 maxStackSize) : data(new ThreadItem(start)) {}

        /// @brief Initializes a new instance of the Thread class, specifying a delegate that allows an object to be passed to the thread when the thread is started.
        /// @param start A delegate that represents the methods to be invoked when this thread begins executing.
        explicit Thread(ParameterizedThreadStart start) : data(new ThreadItem(start)) {}

        /// @brief Initializes a new instance of the Thread class, specifying a delegate that allows an object to be passed to the thread when the thread is started and specifying the maximum stack size for the thread.
        /// @param start A delegate that represents the methods to be invoked when this thread begins executing.
        /// @param maxStackSize The maximum stack size, in bytes, to be used by the thread, or 0 to use the default maximum stack size specified in the header for the executable.
        /// @note Important: For partially trusted code, maxStackSize is ignored if it is greater than the default stack size. No exception is thrown.
        /// @note maxStackSize is ignored.
        Thread(ParameterizedThreadStart start, int32 maxStackSize) : data(new ThreadItem(start)) {}

        /// @cond
        Thread() : data(new ThreadItem()) {}
        Thread(const Thread& thread) : data(thread.data) {}
        Thread& operator=(const Thread& thread) {
          Close();
          this->data = thread.data;
          return *this;
        }
        ~Thread() {Close();}
        /// @endcond

        /// @brief Gets the currently running thread.
        /// @return A System::Threading::Thread that is the representation of the currently running
        /// @return thread.
        static Thread& CurrentThread();

        property_<intptr, readonly_> Handle {
          get_ {
            if (this->data->managedThreadId == NoneManagedThreadId)
              return (intptr) - 1;
            return (intptr)this->data->thread.native_handle();}
        };

        /// @brief Gets a value indicating the execution status of the current thread.
        /// @return Boolean true if this thread has been started and has not terminated normally or aborted; otherwise, false.
        property_<bool, readonly_> IsAlive {
          get_ {return !Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Unstarted) && !Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Stopped) && !Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Aborted);}
        };

        /// @brief Gets a value indicating whether or not a thread is a background thread.
        /// @return Boolean true if this thread is or is to become a background thread; otherwise, false.
        property_<bool> IsBackground {
          get_ {return Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Background);},
          set_ {
            if (this->data->managedThreadId == NoneManagedThreadId || this->data->managedThreadId == MainManagedThreadId)
              throw InvalidOperationException(caller_);

            if (value)
              this->data->state |= System::Threading::ThreadState::Background;
            else
              this->data->state &= ~System::Threading::ThreadState::Background;
          }
        };

        property_<bool, readonly_> IsThreadPoolThread {
          get_ {return this->data->isThreadPoolThread;}
        };

        /// @brief Gets a unique identifier for the current managed thread.
        /// @return An integer that represents a unique identifier for this managed thread.
        property_<int32, readonly_> ManagedThreadId {
          get_ {
            return this->data->managedThreadId;
          }
        };

        /// @brief Gets or sets the name of the thread.
        /// @return A string containing the name of the thread, or null if no name was set.
        property_<string> Name {
          get_ {return this->data->name;},
          set_ {
            if (this->data->managedThreadId == NoneManagedThreadId)
              throw InvalidOperationException(caller_);
            this->SetName(value);
          }
        };

        /// @brief Gets or sets a value indicating the scheduling priority of a thread.
        /// @return One of the System::Threading::ThreadPriority values. The default value is ThreadPriorityNormal.
        /// @exception ThreadStateException The thread has reached a final state, such as ThreadStateAborted.
        property_<ThreadPriority> Priority {
          get_ {return this->data->priority;},
          set_ {
            if (this->data->managedThreadId == NoneManagedThreadId)
              throw InvalidOperationException(caller_);
            this->SetPriority(value);
          }
        };

        /// @brief Gets a value containing the states of the current thread.
        /// @return One of the System::Threading::ThreadState values indicating the state of the current thread. The initial value is ThreadStateUnstarted.
        property_<System::Threading::ThreadState, readonly_> ThreadState {
          get_ {return this->data->state;}
        };

        /// @brief Raises a ThreadAbortedException in the thread on which it is invoked, to begin the process of terminating the thread. Calling this method usually terminates the thread.
        /// @exception ThreadStateException The thread that is being aborted is currently suspended.
        void Abort();

        /// @brief Notifies a host that execution is about to enter a region of code in which the effects of a thread abort.
        static void BeginCriticalRegion() {
          if (CurrentThread().data->managedThreadId == NoneManagedThreadId)
            throw InvalidOperationException(caller_);
          CurrentThread().data->criticalRegion = true;
        }

        /// @brief Serves as a hash function for a particular type.
        /// @return int32 A hash code for the current Object.
        int32 GetHashCode() const override {return this->data->managedThreadId;}

        /// @brief Determines whether this instance and another specified Thread object have the same value.
        /// @param value The Thread to compare.
        /// @return Boolean true if the value of this instance is the same as the value of value; otherwise, false.
        /// @exception ArgumentNullException The parameters value is null.
        bool Equals(const Thread& value) const {return this->data == value.data;}

        /// @brief Determines whether this instance of Thread and a specified object, which must also be a Thread object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return Boolean true if the specified object is equal to the current object. otherwise, false.
        /// @exception ArgumentNullException The parameters obj is null.
        /// @return @see object
        /// @return @see Boolean
        bool Equals(const Object& obj) const override {return is<Thread>(obj) && Equals((const Thread&)obj);}

        /// @brief Notifies a host that execution is about to leave a region of code in which the effects of a thread abort.
        static void EndCriticalRegion() {
          if (CurrentThread().data->managedThreadId == NoneManagedThreadId)
            throw InvalidOperationException(caller_);
          CurrentThread().data->criticalRegion = false;
        }

        /// @brief Interrupts a thread that is in the WaitSleepJoin thread state.
        /// @return One of the System::Threading::ThreadState values indicating the state of the current thread. The initial value is ThreadStateUnstarted.
        /// @remarks If this thread is not currently blocked in a wait, sleep, or join state, it will be interrupted when it next begins to block.
        /// @remarks ThreadInterruptedException is thrown in the interrupted thread, but not until the thread blocks. If the thread never blocks, the exception is never thrown, and thus the thread might complete without ever being interrupted.
        void Interrupt();

        /// @brief Blocks the calling thread until this thread object terminates, while continuing to
        /// perform standard COM and SendMessage pumping.
        /// @exception ThreadStateExceptionError The caller attempted to join a thread that is in the ThreadStateUnstarted state.
        void Join() {this->Join(Timeout::Infinite);}

        /// @brief Blocks the calling thread until this thread object terminates or the specified time
        /// elapses, while continuing to perform standard COM and SendMessage pumping.
        /// @param millisecondsTimeout The number of milliseconds to wait for the thread to terminate.
        /// @return true if the thread has terminated; false if the thread has not terminated
        /// @return after the amount of time specified by the millisecondsTimeout parameter has
        /// @return elapsed.
        /// @exception ThreadStateExceptionError The caller attempted to join a thread that is in the ThreadStateUnstarted state.
        /// @exception ArgumentOutOfRangeException millisecondsTimeout is a negative number other than -1, which represents an infinite time-out.
        bool Join(int32 millisecondsTimeout) {
          if (this->data->managedThreadId == NoneManagedThreadId || this->data->managedThreadId == MainManagedThreadId)
            throw InvalidOperationException(caller_);
          if (Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Unstarted))
            throw ThreadStateException(caller_);

          if (millisecondsTimeout < Timeout::Infinite)
            throw ArgumentOutOfRangeException(caller_);

          if (this->data->interrupted == true)
            this->Interrupt();

          bool result = this->data->endThreadEvent.WaitOne(millisecondsTimeout);
          if (result == true) {
            try {
              CurrentThread().data->state |= System::Threading::ThreadState::WaitSleepJoin;
              this->data->thread.join();
              CurrentThread().data->state &= ~System::Threading::ThreadState::WaitSleepJoin;
            } catch (...) {
              CurrentThread().data->state &= ~System::Threading::ThreadState::WaitSleepJoin;
            }
          }

          return result;
        }

        /// @brief Blocks the calling thread until this thread object terminates or the specified time
        /// elapses, while continuing to perform standard COM and SendMessage pumping.
        /// @param timeout A System::TimeSpan set to the amount of time to wait for the thread to terminate.
        /// @return true if the thread terminated; false if the thread has not terminated after
        /// @return the amount of time specified by the timeout parameter has elapsed.
        /// @exception ThreadStateExceptionError The caller attempted to join a thread that is in the ThreadStateUnstarted state.
        /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents
        /// @return an infinite time-out.  -or- timeout is greater than System::Int32.MaxValue.
        bool Join(const TimeSpan& timeout) {return this->Join(as<int32>(timeout.TotalMilliseconds()));}

        /// @brief Resumes a thread that has been suspended (Should not be used).
        /// @exception ThreadStateException The thread has not been started, is dead, or is not in the suspended state.
        void Resume();

        /// @brief Suspends the current thread for a specified time.
        /// @param millisecondsTimeout The number of milliseconds for which the thread is blocked. Specify zero (0) to indicate that this thread should be suspended to allow other waiting threads to execute. Specify System::Threading::Timeout.Infinite to block the thread indefinitely.
        /// @exception ArgumentException millisecondsTimeout is a negative number other than -1, which represents an infinite time-out.
        static void Sleep(int32 millisecondsTimeout) {
          if (millisecondsTimeout < Timeout::Infinite)
            throw ArgumentException(caller_);

          if (CurrentThread().data->interrupted)
            CurrentThread().Interrupt();

          CurrentThread().data->state |= System::Threading::ThreadState::WaitSleepJoin;
          if (millisecondsTimeout == Timeout::Infinite) {
            while (true)
              std::this_thread::sleep_for(std::chrono::hours::max());
          } else if (millisecondsTimeout == 0)
            Yield();
          else
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsTimeout));
          CurrentThread().data->state &= ~System::Threading::ThreadState::WaitSleepJoin;
        }

        /// @brief Suspends the current thread for a specified time.
        /// @param timeout A System::TimeSpan set to the amount of time for which the thread is blocked. Specify zero to indicate that this thread should be suspended to allow other waiting threads to execute. Specify System::Threading::Timeout.Infinite to block the thread indefinitely.
        /// @exception ArgumentException The value of timeout is negative and is not equal to System::Threading::Timeout.Infinite in milliseconds, or is greater than System::Int32.MaxValue milliseconds.
        static void Sleep(const TimeSpan& timeout) {Sleep(as<int32>(timeout.TotalMilliseconds()));}

        /// @brief Causes the operating system to change the state of the current instance to
        /// System::Threading::ThreadState.Running.
        /// @exception ThreadStateExceptionError The thread has already been started.
        void Start() {this->ThreadStart(null);}

        /// @brief Causes the operating system to change the state of the current instance to
        /// System::Threading::ThreadState.Running.
        /// @param obj An object that contains data to be used by the method the thread executes.
        /// @exception ThreadStateExceptionError The thread has already been started.
        void Start(const object& obj) {this->ThreadStart(&obj);}

        /// @brief Either suspends the thread, or if the thread is already suspended, has no effect (Should not be used).
        /// @exception ThreadStateException The thread has not been started or is dead.
        void Suspend();

        /// @brief Causes the calling thread to yield execution to another thread that is ready to run on the current processor. The operating system selects the thread to yield to.
        /// @return true if the operating system switched execution to another thread; otherwise, false.
        /// @remarks If this method succeeds, the rest of the thread's current time slice is yielded. The operating system schedules the calling thread for another time slice, according to its priority and the status of other threads that are available to run.
        /// @remarks Yielding is limited to the processor that is executing the calling thread. The operating system will not switch execution to another processor, even if that processor is idle or is running a thread of lower priority. If there are no other threads that are ready to execute on the current processor, the operating system does not yield execution, and this method returns false.
        /// @remarks This method is equivalent to using platform invoke to call the native Win32 SwitchToThread function. You should call the Yield method instead of using platform invoke, because platform invoke bypasses any custom threading behavior the host has requested.
        static bool Yield() {std::this_thread::yield(); return true;}

      private:
        using NativeHandle = std::thread::native_handle_type;
        using ThreadId = std::thread::id;
        using ThreadCollection = System::Collections::Generic::List<Thread>;

        struct ThreadItem {
          ThreadItem() {};
          ThreadItem(System::Threading::ThreadStart threadStart) : threadStart(threadStart), managedThreadId(GenerateManagedThreadId()) {}
          ThreadItem(ParameterizedThreadStart parameterizedThreadStart) : parameterizedThreadStart(parameterizedThreadStart), managedThreadId(GenerateManagedThreadId()) {}
          ThreadItem(const ThreadItem& threadItem) = delete;
          ThreadItem& operator=(const ThreadItem& threadItem) = delete;

          std::thread thread;
          System::Threading::ThreadState state {System::Threading::ThreadState::Unstarted};
          ThreadPriority priority {ThreadPriority::Normal};
          string name;
          bool criticalRegion {false};
          bool interrupted {false};
          System::Threading::ThreadStart threadStart;
          ParameterizedThreadStart parameterizedThreadStart;
          ManualResetEvent endThreadEvent {false};
          int32 managedThreadId {NoneManagedThreadId};
          ThreadId mainThreadId;
          ThreadId detachedThreadId;
          bool isThreadPoolThread = false;

          static int32 GenerateManagedThreadId() {
            static int32 managedThreadIdCounter = MainManagedThreadId;
            managedThreadIdCounter = managedThreadIdCounter == Int32::MaxValue ? 2 : managedThreadIdCounter + 1;
            return managedThreadIdCounter;
          }

          void Run() {RunWithOrWithoutParam(null, false);}
          void ParameterizedRun(const object* obj) {RunWithOrWithoutParam(obj, true);}
          void RunWithOrWithoutParam(const object* obj, bool withParam);
          void SetNameThreadForDebugger();
          bool SetPriority();
          static bool SetPriority(NativeHandle handle, ThreadPriority priority);
        };

        Thread(const refptr<ThreadItem>& data) : data(data) {}

        bool Cancel();
        void Close();
        static bool DoWait(WaitHandle& waitHandle, int32 millisecondsTimeOut);

        static void RegisterCurrentThread() {
          std::lock_guard<std::recursive_mutex> lock(mutex);
          for (const Thread& item : threads)
            if (item.data->managedThreadId == MainManagedThreadId)
              throw InvalidOperationException(caller_);
          Thread thread;
          thread.data->managedThreadId = MainManagedThreadId;
          thread.data->mainThreadId = std::this_thread::get_id();
          thread.data->state &= ~System::Threading::ThreadState::Unstarted;
          threads.Add(thread);
        }

        void SetName(const string& name);
        void SetPriority(ThreadPriority priority);

        void ThreadStart(const object* obj) {
          if (!Enum<System::Threading::ThreadState>(this->data->state).HasFlag(System::Threading::ThreadState::Unstarted))
            throw ThreadStateException(caller_);

          if (obj == null && this->data->threadStart.IsEmpty() && this->data->parameterizedThreadStart.IsEmpty())
            throw InvalidOperationException(caller_);

          if (obj != null && this->data->parameterizedThreadStart.IsEmpty())
            throw InvalidOperationException(caller_);

          std::lock_guard<std::recursive_mutex> lock(mutex);
          threads.Add(*this);
          this->data->state &= ~System::Threading::ThreadState::Unstarted;
          if (obj == null && !this->data->threadStart.IsEmpty())
            this->data->thread = std::thread(std::function<void()>(std::bind(&ThreadItem::Run, this->data.ToPointer())));
          else
            this->data->thread = std::thread(std::function<void(const object*)>(std::bind(&ThreadItem::ParameterizedRun, this->data.ToPointer(), std::placeholders::_1)), obj == null ? this : obj);
        }

        refptr<ThreadItem> data;

        friend class ThreadPool;
        friend struct ThreadItem;
        friend class WaitHandle;
        friend class System::Environment;
        static ThreadCollection threads;
        static const int32 NoneManagedThreadId = 0;
        static const int32 MainManagedThreadId = 1;
        static std::recursive_mutex mutex;
      };
    }
  }
}

using namespace Switch;
