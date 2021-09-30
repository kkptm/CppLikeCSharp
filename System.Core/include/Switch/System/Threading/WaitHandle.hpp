/// @file
/// @brief Contains Switch::System::Threading::WaitHandle class.
#pragma once

#include "../../Abstract.hpp"
#include "../../Types.hpp"
#include "../../Ref.hpp"
#include "../../RefPtr.hpp"
#include "../ArgumentException.hpp"
#include "../Array.hpp"
#include "../Convert.hpp"
#include "../IntPtr.hpp"
#include "../TimeSpan.hpp"
#include "../Collections/Generic/IList.hpp"
#include "Timeout.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Encapsulates operating system specific objects that wait for exclusive access to shared resources.
      class core_export_ WaitHandle abstract_ {
        /// @cond
        friend class RegisteredWaitHandle;
        friend class Thread;
        /// @endcond
      public:
        /// @brief Represents an invalid native operating system handle. This field is constant.
        static intptr InvalidHandle() {return IntPtr::Zero;}

        /// @brief Indicates that a System::Threading::WaitHandle::WaitAny(const System::Threading::WaitHandle[], int32, bool)
        /// operation timed out before any of the wait handles were signaled. This field is constant.
        static constexpr int32 WaitTimeout = -1; // 258 in .Net

        /// @brief Initializes a new instance of the System::IO::WaitHandle class.
        WaitHandle() {}

        /// @brief Destroy instance of the class WaitHandle
        ~WaitHandle() { Close(); }


        /// @brief When overridden in a derived class, releases all resources held by the current System::Threading::WaitHandle.
        virtual void Close() {}

        /// @brief Signals one WaitHandle and waits on another.
        /// @param toSignal The WaitHandle to signal.
        /// @param toWait The WaitHandle to wait on.
        /// @return bool true if both the signal and the wait complete successfully; if the wait does not complete, the method does not return.
        /// @exception ArgumentNullException toSignal is null or toWait is null.
        static bool SignalAndWait(WaitHandle& toSignal, WaitHandle& toWait) {return SignalAndWait(toSignal, toWait, Timeout::Infinite);}

        /// @brief Signals one WaitHandle and waits on another, specifying a time-out interval as a 32-bit signed integer.
        /// @param toSignal The WaitHandle to signal.
        /// @param toWait The WaitHandle to wait on.
        /// @param millisecondsTimeOut An integer that represents the interval to wait. If the value is Timeout::Infinite, that is, -1, the wait is infinite
        /// @return bool true if both the signal and the wait complete successfully; if the wait does not complete, the method does not return.
        /// @exception ArgumentNullException toSignal is null or toWait is null.
        static bool SignalAndWait(WaitHandle& toSignal, WaitHandle& toWait, int32 millisecondsTimeOut) {return toSignal.Signal() && toWait.Wait(millisecondsTimeOut);}

        /// @brief Signals one WaitHandle and waits on another, specifying a time-out interval as a TimeSpan.
        /// @param toSignal The WaitHandle to signal.
        /// @param toWait The WaitHandle to wait on.
        /// @param timeout A TimeSpan that represents the interval to wait. If the value is -1, the wait is infinite
        /// @return bool true if both the signal and the wait complete successfully; if the wait does not complete, the method does not return.
        /// @exception ArgumentNullException toSignal is null or toWait is null.
        static bool SignalAndWait(WaitHandle& toSignal, WaitHandle& toWait, const TimeSpan& timeout) {return SignalAndWait(toSignal, toWait, as<int32>(timeout.TotalMilliseconds()));}

        /// @brief Blocks the current thread until the current System::Threading::WaitHandle receives a signal.
        /// @return true if the current instance receives a signal. If the current instance is never signaled, System::Threading::WaitHandle.WaitOne(int32, bool) never returns.
        /// @exception ObjectDisposedException the handle is invalid
        virtual bool WaitOne() {return DoWait(Timeout::Infinite);}

        /// @brief Blocks the current thread until the current System::Threading::WaitHandle receives
        /// a signal, using 32-bit signed integer to measure the time interval.
        /// @param millisecondsTimeOut The number of milliseconds to wait, or System::Threading::Timeout.Infinite (-1) to wait indefinitely.
        /// @return if the current instance receives a signal. If the current instance is never signaled, System::Threading::WaitHandle.WaitOne(int32, bool) never returns.
        /// @exception ObjectDisposedException the handle is invalid
        /// @exception ArgumentException millisecondsTimeout is a negative number other than -1, which represents an infinite time-out.
        virtual bool WaitOne(int32 millisecondsTimeOut) {
          if (millisecondsTimeOut < Timeout::Infinite)
            throw ArgumentException(caller_);
          return Wait(millisecondsTimeOut);
        }

        /// @brief Blocks the current thread until the current instance receives a signal, using
        /// a System.TimeSpan to measure the time interval.
        /// @param timeOut A System.TimeSpan that represents the number of milliseconds to wait, or
        /// a System.TimeSpan that represents -1 milliseconds to wait indefinitely.
        /// @return true if the current instance receives a signal. If the current instance is never signaled, System::Threading::WaitHandle.WaitOne(System.Int32, System.Boolean) never returns.
        /// @exception ObjectDisposedException the handle is invalid
        /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.  -or- timeout is greater than System.Int32.MaxValue.
        virtual bool WaitOne(const TimeSpan& timeOut) {return WaitOne(as<int32>(timeOut.TotalMilliseconds()));}

        /// @brief Waits for all the elements in the specified array to receive a signal.
        /// @param waitHandles A WaitHandle array containing the objects for which the current instance
        /// will wait. This array cannot contain multiple references to the same object.
        /// @return true when every element in waitHandles has received a signal; otherwise the method never returns.
        /// @exception ArgumentNullException The waitHandles parameter is null
        /// @exception ArgumentException The number of objects in waitHandles is greater than the system permits.
        /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
        static bool WaitAll(Array<ref<WaitHandle>> waitHandles);

        /// @brief Waits for all the elements in the specified array to receive a signal, using
        /// an System.Int32 value to measure the time interval.
        /// @param waitHandles A WaitHandle array containing the objects for which the current instance
        /// will wait. This array cannot contain multiple references to the same object.
        /// @param millisecondsTimeOut The number of milliseconds to wait, or System::Threading::Timeout.Infinite
        /// (-1) to wait indefinitely.
        /// @return true when every element in waitHandles has received a signal; otherwise the
        /// method never returns.
        /// @exception ArgumentNullException The waitHandles parameter is null
        /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents
        /// an infinite time-out.
        /// -or-  The number of objects in waitHandles is greater than the system permits.
        /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
        static bool WaitAll(Array<ref<WaitHandle>> waitHandles, int32 millisecondsTimeOut);

        /// @brief Waits for all the elements in the specified array to receive a signal, using
        /// a System.TimeSpan value to measure the time interval.
        /// @param waitHandles A WaitHandle array containing the objects for which the current instance
        /// will wait. This array cannot contain multiple references to the same object.
        /// @param timeOut A System::TimeSpan that represents the number of milliseconds to wait, or a System::TimeSpan that represents -1 milliseconds, to wait indefinitely.
        /// @return true when every element in waitHandles has received a signal; otherwise the
        /// method never returns.
        /// @exception ArgumentNullException The waitHandles parameter is null
        /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents
        /// an infinite time-out.
        /// -or- timeout is greater than System.Int32.MaxValue.
        /// -or- The number of objects in waitHandles is greater than the system permits.
        /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
        static bool WaitAll(Array<ref<WaitHandle>> waitHandles, const TimeSpan& timeOut);

        /// @brief Waits for any of the elements in the specified array to receive a signal.
        /// @param waitHandles A WaitHandle array containing the objects for which the current instance
        /// will wait. This array cannot contain multiple references to the same object.
        /// @return The array index of the object that satisfied the wait.
        /// @exception ArgumentNullException The waitHandles parameter is null
        /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents
        /// an infinite time-out.
        /// -or-  The number of objects in waitHandles is greater than the system permits.
        /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
        static int32 WaitAny(Array<ref<WaitHandle>> waitHandles);

        /// @brief Waits for any of the elements in the specified array to receive a signal,
        /// using a 32-bit signed integer to measure the time interval.
        /// @param waitHandles A WaitHandle array containing the objects for which the current instance
        /// will wait. This array cannot contain multiple references to the same object.
        /// @param millisecondsTimeOut The number of milliseconds to wait, or System::Threading::Timeout.Infinite
        /// (-1) to wait indefinitely.
        /// @return The array index of the object that satisfied the wait, or System::Threading::WaitHandle.WaitTimeout
        /// if no object satisfied the wait and a time interval equivalent to millisecondsTimeout
        /// has passed.
        /// @exception ArgumentNullException The waitHandles parameter is null
        /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents
        /// an infinite time-out.
        /// -or-  The number of objects in waitHandles is greater than the system permits.
        /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
        static int32 WaitAny(Array<ref<WaitHandle>> waitHandles, int32 millisecondsTimeOut);

        /// @brief Waits for any of the elements in the specified array to receive a signal,
        /// using a System.TimeSpan to measure the time interval.
        /// @param waitHandles A WaitHandle array containing the objects for which the current instance
        /// will wait. This array cannot contain multiple references to the same object.
        /// @param timeOut A System.TimeSpan that represents the number of milliseconds to wait, or
        /// a System.TimeSpan that represents -1 milliseconds to wait indefinitely.
        /// @return The array index of the object that satisfied the wait, or System::Threading::WaitHandle.WaitTimeout
        /// if no object satisfied the wait and a time interval equivalent to timeout
        /// has passed.
        /// @exception ArgumentNullException The waitHandles parameter is null
        /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents
        /// an infinite time-out. -or-  The number of objects in waitHandles is greater than the system permits.
        /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
        static int32 WaitAny(Array<ref<WaitHandle>> waitHandles, const TimeSpan& timeOut);

      protected:
        /// @brief Releases ownership of the specified WaitHandle object.
        /// @return true If the function succeeds, false otherwise.
        /// @remarks Override this function for all derived object
        virtual bool Signal() = 0;

        /// @brief Wait ownership of the specified mutex object.
        /// @param handle A valid handle to an open object.
        /// @param millisecondsTimeOut The number of milliseconds to wait, or -1 to wait indefinitely.
        /// @return true if the current instance receives a signal; otherwise, false.
        /// @remarks If millisecondsTimeout is zero, the method does not block. It tests the state of the wait handle and returns immediately.
        /// @remarks Override this function for all derived object
        virtual bool Wait(int32 millisecondsTimeOut) = 0;

        /// @cond
        bool DoWait(int32 millisecondsTimeOut);
        /// @endcond
      };
    }
  }
}

using namespace Switch;
