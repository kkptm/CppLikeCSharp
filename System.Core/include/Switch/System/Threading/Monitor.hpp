/// @file
/// @brief Contains Switch::System::Threading::Monitor class.
#pragma once

#include <map>

#include "../../RefPtr.hpp"
#include "../../Static.hpp"
#include "../IntPtr.hpp"
#include "../Object.hpp"
#include "../Nullable.hpp"
#include "../TimeSpan.hpp"
#include "AutoResetEvent.hpp"
#include "Mutex.hpp"
#include "Timeout.hpp"
#include "../SystemException.hpp"
#include "../Collections/Generic/Dictionary.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Provides a mechanism that synchronizes access to objects.
      class core_export_ Monitor static_ {
      public:
        /// @brief Acquires an exclusive lock on the specified obj.
        /// @param obj The object on which to acquire the monitor lock.
        /// @exception ArgumentNullException The obj parameter is null.
        /// @remarks Use Enter to acquire the Monitor on the object passed as the parameter. If another thread has executed an Enter on the object, but has not yet executed the corresponding Exit, the current thread will block until the other thread releases the object. It is legal for the same thread to invoke Enter more than once without it blocking; however, an equal number of Exit calls must be invoked before other threads waiting on the object will unblock.
        /// @remarks Usex Monitor to lock objects (that is, reference types), not value types. When you pass a value type variable to Enter, it is boxed as an object. If you pass the same variable to Enter again, the thread is block. The code that Monitor is supposedly protecting is not protected. Furthermore, when you pass the variable to Exit, still another separate object is created. Because the object passed to Exit is different from the object passed to Enter, Monitor throws SynchronizationLockException. For details, see the conceptual topic Monitors.
        static void Enter(const object& obj) {
          bool lockTaken = false;
          Enter(obj, lockTaken);
        }

        /// @brief Acquires an exclusive lock on the specified obj.
        /// @param obj The object on which to acquire the monitor lock.
        /// @param lockTaken The result of the attempt to acquire the lock, passed by reference. The input must be false. The output is true if the lock is acquired; otherwise, the output is false. The output is set even if an exception occurs during the attempt to acquire the lock.
        /// @note   If no exception occurs, the output of this method is always true.
        /// @exception ArgumentNullException The obj parameter is null.
        /// @remarks Use Enter to acquire the Monitor on the object passed as the parameter. If another thread has executed an Enter on the object, but has not yet executed the corresponding Exit, the current thread will block until the other thread releases the object. It is legal for the same thread to invoke Enter more than once without it blocking; however, an equal number of Exit calls must be invoked before other threads waiting on the object will unblock.
        /// @remarks Use Monitor to lock objects (that is, reference types), not value types. When you pass a value type variable to Enter, it is boxed as an object. If you pass the same variable to Enter again, the thread is block. The code that Monitor is supposedly protecting is not protected. Furthermore, when you pass the variable to Exit, still another separate object is created. Because the object passed to Exit is different from the object passed to Enter, Monitor throws SynchronizationLockException. For details, see the conceptual topic Monitors.
        static void Enter(const object& obj, bool& lockTaken) {
          if (TryEnter(obj, lockTaken) == false)
            throw InvalidOperationException(caller_);
        }

        /// @brief Acquires an exclusive lock on the specified obj.
        /// @param obj The object on which to acquire the monitor lock.
        /// @exception ArgumentNullException The obj parameter is null.
        /// @remarks Use Enter to acquire the Monitor on the object passed as the parameter. If another thread has executed an Enter on the object, but has not yet executed the corresponding Exit, the current thread will block until the other thread releases the object. It is legal for the same thread to invoke Enter more than once without it blocking; however, an equal number of Exit calls must be invoked before other threads waiting on the object will unblock.
        /// @remarks Usex Monitor to lock objects (that is, reference types), not value types. When you pass a value type variable to Enter, it is boxed as an object. If you pass the same variable to Enter again, the thread is block. The code that Monitor is supposedly protecting is not protected. Furthermore, when you pass the variable to Exit, still another separate object is created. Because the object passed to Exit is different from the object passed to Enter, Monitor throws SynchronizationLockException. For details, see the conceptual topic Monitors.
        static bool IsEntered(const object& obj) {
          return MonitorItems().ContainsKey(ToKey(obj));
        }

        /// @brief Notifies a thread in the waiting queue of a change in the locked object's state.
        /// @param obj The object a thread is waiting for.
        /// @exception ArgumentNullException The obj parameter is null.
        /// Only the current owner of the lock can signal a waiting object using Pulse.
        /// The thread that currently owns the lock on the specified object invokes this method to signal the next thread in line for the lock. Upon receiving the pulse, the waiting thread is moved to the ready queue. When the thread that invoked Pulse releases the lock, the next thread in the ready queue (which is not necessarily the thread that was pulsed) acquires the lock.
        static void Pulse(const object& obj);

        /// @brief Notifies all waiting threads of a change in the object's state.
        /// @param obj The object a thread is waiting for.
        /// @exception ArgumentNullException The obj parameter is null.
        /// @remarks The thread that currently owns the lock on the specified object invokes this method to signal all threads waiting to acquire the lock on the object. After the signal is sent, the waiting threads are moved to the ready queue. When the thread that invoked PulseAll releases the lock, the next thread in the ready queue acquires the lock.
        /// @remarks Note that a synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
        /// @remarks The Pulse, PulseAll, and Wait methods must be invoked from within a synchronized block of code.
        /// @remarks The remarks for the Pulse method explain what happens if Pulse is called when no threads are waiting.
        /// @remarks To signal a single thread, use the Pulse method.
        static void PulseAll(const object& obj);

        /// @brief Releases an exclusive lock on the specified obj.
        /// @param obj The object on which to release the lock.
        /// @exception ArgumentNullException The obj parameter is null.
        /// @remarks The calling thread must own the lock on the obj parameter. If the calling thread owns the lock on the specified object, and has made an equal number of Exit and Enter calls for the object, then the lock is released. If the calling thread has not invoked Exit as many times as Enter, the lock is not released.
        /// @remarks If the lock is released and other threads are in the ready queue for the object, one of the threads acquires the lock. If other threads are in the waiting queue waiting to acquire the lock, they are not automatically moved to the ready queue when the owner of the lock calls Exit. To move one or more waiting threads into the ready queue, call Pulse or PulseAll before invoking Exit.
        static void Exit(const object& obj) {Remove(obj);}

        /// @brief Attempts to acquire an exclusive lock on the specified object.
        /// @param obj The object on which to acquire the lock.
        /// @return bool true if the current thread acquires the lock; otherwise, false
        /// @exception ArgumentNullException The obj parameter is null.
        /// @remarks If successful, this method acquires an exclusive lock on the obj parameter. This method returns immediately, whether or not the lock is available.
        /// @remarks This method is similar to Enter, but it will never block. If the thread cannot enter without blocking, the method returns false, and the thread does not enter the critical section.
        static bool TryEnter(const object& obj) {return TryEnter(obj, Timeout::Infinite);}

        /// @brief Attempts to acquire an exclusive lock on the specified object.
        /// @param obj The object on which to acquire the lock.
        /// @param lockTaken The result of the attempt to acquire the lock, passed by reference. The input must be false. The output is true if the lock is acquired; otherwise, the output is false. The output is set even if an exception occurs during the attempt to acquire the lock.
        /// @note   If no exception occurs, the output of this method is always true.
        /// @return bool true if the current thread acquires the lock; otherwise, false
        /// @exception ArgumentNullException The obj parameter is null.
        /// @remarks If successful, this method acquires an exclusive lock on the obj parameter. This method returns immediately, whether or not the lock is available.
        /// @remarks This method is similar to Enter, but it will never block. If the thread cannot enter without blocking, the method returns false, and the thread does not enter the critical section.
        static bool TryEnter(const object& obj, bool& lockTaken) {return TryEnter(obj, Timeout::Infinite, lockTaken);}

        /// @brief Attempts, for the specified number of milliseconds, to acquire an exclusive lock on the specified object.
        /// @param obj The object on which to acquire the lock.
        /// @param millisecondsTimeout The number of milliseconds to wait for the lock.
        /// @return bool true if the current thread acquires the lock; otherwise, false
        /// @exception ArgumentNullException The obj parameter is null.
        /// @remarks If the millisecondsTimeout parameter equals Timeout::Infinite, this method is equivalent to Enter. If millisecondsTimeout equals 0, this method is equivalent to TryEnter.
        static bool TryEnter(const object& obj, int32 millisecondsTimeout) {
          bool lockTacken = false;
          return TryEnter(obj, millisecondsTimeout, lockTacken);
        }

        /// @brief Attempts, for the specified number of milliseconds, to acquire an exclusive lock on the specified object.
        /// @param obj The object on which to acquire the lock.
        /// @param millisecondsTimeout The number of milliseconds to wait for the lock.
        /// @param lockTaken The result of the attempt to acquire the lock, passed by reference. The input must be false. The output is true if the lock is acquired; otherwise, the output is false. The output is set even if an exception occurs during the attempt to acquire the lock.
        /// @note   If no exception occurs, the output of this method is always true.
        /// @return bool true if the current thread acquires the lock; otherwise, false
        /// @exception ArgumentNullException The obj parameter is null.
        /// @remarks If the millisecondsTimeout parameter equals Timeout::Infinite, this method is equivalent to Enter. If millisecondsTimeout equals 0, this method is equivalent to TryEnter.
        static bool TryEnter(const object& obj, int32 millisecondsTimeout, bool& lockTaken) {
          if (millisecondsTimeout < -1)
            return false;

          lockTaken = Add(obj, millisecondsTimeout);
          return true;
        }

        /// @brief Attempts, for the specified number of milliseconds, to acquire an exclusive lock on the specified object.
        /// @param obj The object on which to acquire the lock.
        /// @param millisecondsTimeout The number of milliseconds to wait for the lock.
        /// @return bool true if the current thread acquires the lock; otherwise, false
        /// @exception ArgumentNullException The obj parameter is null.
        /// @remarks If the millisecondsTimeout parameter equals Timeout::Infinite, this method is equivalent to Enter. If millisecondsTimeout equals 0, this method is equivalent to TryEnter.
        static bool TryEnter(const object& obj, int64 millisecondsTimeout) {
          bool lockTacken = false;
          return TryEnter(obj, millisecondsTimeout, lockTacken);
        }

        /// @brief Attempts, for the specified number of milliseconds, to acquire an exclusive lock on the specified object.
        /// @param obj The object on which to acquire the lock.
        /// @param millisecondsTimeout The number of milliseconds to wait for the lock.
        /// @param lockTaken The result of the attempt to acquire the lock, passed by reference. The input must be false. The output is true if the lock is acquired; otherwise, the output is false. The output is set even if an exception occurs during the attempt to acquire the lock.
        /// @note   If no exception occurs, the output of this method is always true.
        /// @return bool true if the current thread acquires the lock; otherwise, false
        /// @exception ArgumentNullException The obj parameter is null.
        /// @remarks If the millisecondsTimeout parameter equals Timeout::Infinite, this method is equivalent to Enter. If millisecondsTimeout equals 0, this method is equivalent to TryEnter.
        static bool TryEnter(const object& obj, int64 millisecondsTimeout, bool& lockTaken) {
          if (millisecondsTimeout < -1)
            return false;

          lockTaken = Add(obj, (int32)millisecondsTimeout);
          return true;
        }

        /// @brief Attempts, for the specified amount of time, to acquire an exclusive lock on the specified object.
        /// @param obj The object on which to acquire the lock.
        /// @param timeout A TimeSpan representing the amount of time to wait for the lock. A value of -1 millisecond specifies an infinite wait.
        /// @return bool true if the current thread acquires the lock; otherwise, false
        /// @exception ArgumentNullException The obj timeout or  parameter is null.
        /// @remarks If the value of the timeout parameter converted to milliseconds equals -1, this method is equivalent to Enter. If the value of timeout equals 0, this method is equivalent to TryEnter.
        static bool TryEnter(const object& obj, const TimeSpan& timeout) {
          bool lockTaken = false;
          return TryEnter(obj, as<int32>(timeout.TotalMilliseconds()), lockTaken);
        }

        /// @brief Attempts, for the specified amount of time, to acquire an exclusive lock on the specified object.
        /// @param obj The object on which to acquire the lock.
        /// @param timeout A TimeSpan representing the amount of time to wait for the lock. A value of -1 millisecond specifies an infinite wait.
        /// @param lockTaken The result of the attempt to acquire the lock, passed by reference. The input must be false. The output is true if the lock is acquired; otherwise, the output is false. The output is set even if an exception occurs during the attempt to acquire the lock.
        /// @note   If no exception occurs, the output of this method is always true.
        /// @return bool true if the current thread acquires the lock; otherwise, false
        /// @exception ArgumentNullException The obj timeout or  parameter is null.
        /// @remarks If the value of the timeout parameter converted to milliseconds equals -1, this method is equivalent to Enter. If the value of timeout equals 0, this method is equivalent to TryEnter.
        static bool TryEnter(const object& obj, const TimeSpan& timeout, bool& lockTaken) {return TryEnter(obj, as<int32>(timeout.TotalMilliseconds()), lockTaken);}

        /// @brief Releases the lock on an object and blocks the current thread until it reacquires the lock.
        /// @param obj The object on which to wait.
        /// @return Boolean true if the call returned because the caller reacquired the lock for the specified object. This method does not return if the lock is not reacquired.
        /// @exception ArgumentNullException The obj parameter is null.
        /// The thread that currently owns the lock on the specified object invokes this method in order to release the object so that another thread can access it. The caller is blocked while waiting to reacquire the lock. This method is called when the caller needs to wait for a state change that will occur as a result of another thread's operations.
        /// When a thread calls Wait, it releases the lock on the object and enters the object's waiting queue. The next thread in the object's ready queue (if there is one) acquires the lock and has exclusive use of the object. All threads that call Wait remain in the waiting queue until they receive a signal from Pulse or PulseAll, sent by the owner of the lock. If Pulse is sent, only the thread at the head of the waiting queue is affected. If PulseAll is sent, all threads that are waiting for the object are affected. When the signal is received, one or more threads leave the waiting queue and enter the ready queue. A thread in the ready queue is permitted to reacquire the lock.
        /// This method returns when the calling thread reacquires the lock on the object. Note that this method blocks indefinitely if the holder of the lock does not call Pulse or PulseAll.
        /// The caller executes Wait once, regardless of the number of times Enter has been invoked for the specified object. Conceptually, the Wait method stores the number of times the caller invoked Enter on the object and invokes Exit as many times as necessary to fully release the locked object. The caller then blocks while waiting to reacquire the object. When the caller reacquires the lock, the system calls Enter as many times as necessary to restore the saved Enter count for the caller. Calling Wait releases the lock for the specified object only; if the caller is the owner of locks on other objects, these locks are not released.
        /// Note that a synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
        /// The Pulse, PulseAll, and Wait methods must be invoked from within a synchronized block of code.
        /// The remarks for the Pulse method explain what happens if Pulse is called when no threads are waiting.
        static bool Wait(const object& obj) {return Wait(obj, Timeout::Infinite);}

        /// @brief Releases the lock on an object and blocks the current thread until it reacquires the lock.
        /// @param obj The object on which to wait.
        /// @param millisecondsTimeout The number of milliseconds to wait before the thread enters the ready queue.
        /// @return bool true if the lock was reacquired before the specified time elapsed; false if the lock was reacquired after the specified time elapsed. The method does not return until the lock is reacquired.
        /// @exception ArgumentNullException The obj parameter is null.
        /// This method does not return until it reacquires an exclusive lock on the obj parameter.
        /// The thread that currently owns the lock on the specified object invokes this method in order to release the object so that another thread can access it. The caller is blocked while waiting to reacquire the lock. This method is called when the caller needs to wait for a state change that will occur as a result of another thread's operations.
        /// The time-out ensures that the current thread does not block indefinitely if another thread releases the lock without first calling the Pulse or PulseAll method. It also moves the thread to the ready queue, bypassing other threads ahead of it in the wait queue, so that it can reacquire the lock sooner. The thread can test the return value of the Wait method to determine whether it reacquired the lock prior to the time-out. The thread can evaluate the conditions that caused it to enter the wait, and if necessary call the Wait method again.
        /// When a thread calls Wait, it releases the lock on the object and enters the object's waiting queue. The next thread in the object's ready queue (if there is one) acquires the lock and has exclusive use of the object. The thread that invoked Wait remains in the waiting queue until either a thread that holds the lock invokes PulseAll, or it is the next in the queue and a thread that holds the lock invokes Pulse. However, if millisecondsTimeout elapses before another thread invokes this object's Pulse or PulseAll method, the original thread is moved to the ready queue in order to regain the lock.
        /// If Timeout::Infinite is specified for the millisecondsTimeout parameter, this method blocks indefinitely unless the holder of the lock calls Pulse or PulseAll. If millisecondsTimeout equals 0, the thread that calls Wait releases the lock and then immediately enters the ready queue in order to regain the lock.
        /// The caller executes Wait once, regardless of the number of times Enter has been invoked for the specified object. Conceptually, the Wait method stores the number of times the caller invoked Enter on the object and invokes Exit as many times as necessary to fully release the locked object. The caller then blocks while waiting to reacquire the object. When the caller reacquires the lock, the system calls Enter as many times as necessary to restore the saved Enter count for the caller. Calling Wait releases the lock for the specified object only; if the caller is the owner of locks on other objects, these locks are not released.
        /// A synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
        /// The Pulse, PulseAll, and Wait methods must be invoked from within a synchronized block of code.
        /// The remarks for the Pulse method explain what happens if Pulse is called when no threads are waiting.
        static bool Wait(const object& obj, int32 millisecondsTimeout);

        /// @brief Releases the lock on an object and blocks the current thread until it reacquires the lock. If the specified time-out interval elapses, the thread enters the ready queue.
        /// @param obj The object on which to wait.
        /// @param timeout A TimeSpan representing the amount of time to wait before the thread enters the ready queue.
        /// @return bool true if the lock was reacquired before the specified time elapsed; false if the lock was reacquired after the specified time elapsed. The method does not return until the lock is reacquired.
        /// @exception ArgumentNullException The obj parameter is null.
        /// This method does not return until it reacquires an exclusive lock on the obj parameter.
        /// The thread that currently owns the lock on the specified object invokes this method in order to release the object so that another thread can access it. The caller is blocked while waiting to reacquire the lock. This method is called when the caller needs to wait for a state change that will occur as a result of another thread's operations.
        /// The time-out ensures that the current thread does not block indefinitely if another thread releases the lock without first calling the Pulse or PulseAll method. It also moves the thread to the ready queue, bypassing other threads ahead of it in the wait queue, so that it can reacquire the lock sooner. The thread can test the return value of the Wait method to determine whether it reacquired the lock prior to the time-out. The thread can evaluate the conditions that caused it to enter the wait, and if necessary call the Wait method again.
        /// When a thread calls Wait, it releases the lock on the object and enters the object's waiting queue. The next thread in the object's ready queue (if there is one) acquires the lock and has exclusive use of the object. The thread that invoked Wait remains in the waiting queue until either a thread that holds the lock invokes PulseAll, or it is the next in the queue and a thread that holds the lock invokes Pulse. However, if timeout elapses before another thread invokes this object's Pulse or PulseAll method, the original thread is moved to the ready queue in order to regain the lock.
        /// If a TimeSpan representing -1 millisecond is specified for the timeout parameter, this method blocks indefinitely unless the holder of the lock calls Pulse or PulseAll. If timeout is 0 milliseconds, the thread that calls Wait releases the lock and then immediately enters the ready queue in order to regain the lock.
        /// The caller executes Wait once, regardless of the number of times Enter has been invoked for the specified object. Conceptually, the Wait method stores the number of times the caller invoked Enter on the object and invokes Exit as many times as necessary to fully release the locked object. The caller then blocks while waiting to reacquire the object. When the caller reacquires the lock, the system calls Enter as many times as necessary to restore the saved Enter count for the caller. Calling Wait releases the lock for the specified object only; if the caller is the owner of locks on other objects, these locks are not released.
        /// A synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
        /// The Pulse, PulseAll, and Wait methods must be invoked from within a synchronized block of code.
        ///The remarks for the Pulse method explain what happens if Pulse is called when no threads are waiting.
        static bool Wait(const object& obj, const TimeSpan& timeout) {return Wait(obj, as<int32>(timeout.TotalMilliseconds()));}

      private:
        struct MonitorItem {
          MonitorItem() {}
          MonitorItem(const string& name) : name(name) {}
          bool operator==(const MonitorItem& monitorItem) const {return this->event == monitorItem.event && this->usedCounter == monitorItem.usedCounter;}
          bool operator!=(const MonitorItem& monitorItem) const {return !this->operator==(monitorItem);}

          Mutex event {false};
          int32 usedCounter {0};
          Nullable<string> name;
        };

        static const object* ToKey(const object& obj) {
          if (is<string>(obj)) {
            for (const auto& item : MonitorItems())
              if (item.Value().name.HasValue && item.Value().name.Value().Equals((const string&)obj))
                return item.Key;
          }
          return &obj;
        }

        static System::Collections::Generic::Dictionary<const object*, MonitorItem>& MonitorItems() {
          static System::Collections::Generic::Dictionary<const object*, MonitorItem> monitorItems;
          return monitorItems;
        }

        static bool Add(const object& obj, int32 millisecondsTimeout);
        static void Remove(const object& obj);
      };
    }
  }
}

using namespace Switch;
