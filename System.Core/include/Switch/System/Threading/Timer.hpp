/// @file
/// @brief Contains Switch::System::Threading::Timer class.
#pragma once

#include "../Convert.hpp"
#include "../Object.hpp"
#include "../TimeSpan.hpp"
#include "AutoResetEvent.hpp"
#include "ThreadPool.hpp"
#include "TimerCallback.hpp"

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
      class core_export_ Timer : public Object {
      public:
        /// @brief Initializes a new instance of the Timer class with an infinite period and an infinite due time, using the newly created Timer object as the state object.
        /// @param callback the address of a method to be executed
        /// @exception ArgumentNullException The callback is null.
        /// @remarks Call this constructor when you want to use the Timer object itself as the state object. After creating the timer, use the Change method to set the interval and due time.
        /// @remarks This constructor specifies an infinite due time before the first callback and an infinite interval between callbacks, in order to prevent the first callback from occurring before the Timer object is assigned to the state object.
        explicit Timer(const TimerCallback& callback) : Timer(callback, *this, -1, -1) {}

        /// @brief Initializes a new instance of the Timer class, using a 32-bit signed integer to specify the time interval.
        /// @param callback the address of a method to be executed
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentNullException The callback is null.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        /// @remarks The callback parameter is invoked once after dueTime elapses, and thereafter each time the period time interval elapses.
        Timer(const TimerCallback& callback, int32 dueTime, int32 period) : Timer(callback, *this, dueTime, period) {}

        /// @brief Initializes a new instance of the Timer class, using a 64-bit signed integer to specify the time interval.
        /// @param callback the address of a method to be executed
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentNullException The callback is null.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        /// @remarks The callback parameter is invoked once after dueTime elapses, and thereafter each time the period time interval elapses.
        Timer(const TimerCallback& callback, int64 dueTime, int64 period) : Timer(callback, *this, as<int32>(dueTime), as<int32>(period)) {}

        /// @brief Initializes a new instance of the Timer class, using a TimaSpan to specify the time interval.
        /// @param callback the address of a method to be executed
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentNullException The callback or dueTime or period param is null.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        /// @remarks The callback parameter is invoked once after dueTime elapses, and thereafter each time the period time interval elapses.
        Timer(const TimerCallback& callback, const TimeSpan& dueTime, const TimeSpan& period) : Timer(callback, *this, as<int32>(dueTime.TotalMilliseconds()), as<int32>(period.TotalMilliseconds())) {}

        /// @brief Initializes a new instance of the Timer class, using a 32-bit unsigned integer to specify the time interval.
        /// @param callback the address of a method to be executed
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentNullException The callback is null.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        /// @remarks The callback parameter is invoked once after dueTime elapses, and thereafter each time the period time interval elapses.
        Timer(const TimerCallback& callback, uint32 dueTime, uint32 period) : Timer(callback, *this, as<int32>(dueTime), as<int32>(period)) {}

        /// @brief Initializes a new instance of the Timer class, using a 32-bit signed integer to specify the time interval.
        /// @param callback the address of a method to be executed
        /// @param state An object containing information to be used by the callback method, or null.
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentNullException The callback is null.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        /// @remarks The callback parameter is invoked once after dueTime elapses, and thereafter each time the period time interval elapses.
        Timer(const TimerCallback& callback, Object& state, int32 dueTime, int32 period) {
          this->data->callback = callback;
          this->data->state = &state;
          this->data->dueTime = dueTime;
          this->data->period = period;
          this->data->thread.Start();
          Change(dueTime, period);
        }

        /// @brief Initializes a new instance of the Timer class, using a 64-bit signed integer to specify the time interval.
        /// @param callback the address of a method to be executed
        /// @param state An object containing information to be used by the callback method, or null.
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentNullException The callback is null.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        /// @remarks The callback parameter is invoked once after dueTime elapses, and thereafter each time the period time interval elapses.
        Timer(const TimerCallback& callback, object& state, int64 dueTime, int64 period) : Timer(callback, state, as<int32>(dueTime), as<int32>(period)) {}

        /// @brief Initializes a new instance of the Timer class, using a TimaSpan to specify the time interval.
        /// @param callback the address of a method to be executed
        /// @param state An object containing information to be used by the callback method, or null.
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentNullException The callback or dueTime or period param is null.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        /// @remarks The callback parameter is invoked once after dueTime elapses, and thereafter each time the period time interval elapses.
        Timer(const TimerCallback& callback, object& state, const TimeSpan& dueTime, const TimeSpan& period) : Timer(callback, state, as<int32>(dueTime.TotalMilliseconds()), as<int32>(period.TotalMilliseconds())) {}

        /// @brief Initializes a new instance of the Timer class, using a 32-bit unsigned integer to specify the time interval.
        /// @param callback the address of a method to be executed
        /// @param state An object containing information to be used by the callback method, or null.
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentNullException The callback is null.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        /// @remarks The callback parameter is invoked once after dueTime elapses, and thereafter each time the period time interval elapses.
        Timer(const TimerCallback& callback, object& state, uint32 dueTime, uint32 period) : Timer(callback, state, as<int32>(dueTime), as<int32>(period)) {}

        /// @cond
        Timer() {}
        Timer(const Timer& timer) : data(timer.data) {}
        Timer& operator=(const Timer& timer) {
          this->Close();
          this->data = timer.data;
          return *this;
        }
        ~Timer() {this->Close();}
        /// @endcond

        /// @brief Changes the start time and the interval between method invocations for a timer, using 32-bit signed integers to measure time intervals.
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        void Change(int32 dueTime, int32 period) {
          if (this->data->callback.IsEmpty())
            throw InvalidOperationException(caller_);
          if (dueTime < Timeout::Infinite || period < Timeout::Infinite)
            throw ArgumentOutOfRangeException(caller_);

          this->data->dueTime = dueTime;
          this->data->period = period;
          this->data->event.Set();
        }

        /// @brief Changes the start time and the interval between method invocations for a timer, using 64-bit signed integers to measure time intervals.
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        void Change(int64 dueTime, int64 period) {this->Change(as<int32>(dueTime), as<int32>(period));}

        /// @brief Changes the start time and the interval between method invocations for a timer, using TimeSpan values to measure time intervals.
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentNullException The dueTime or period param is null.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        void Change(const TimeSpan& dueTime, const TimeSpan& period) {this->Change(as<int32>(dueTime.TotalMilliseconds()), as<int32>(period.TotalMilliseconds()));}

        /// @brief Changes the start time and the interval between method invocations for a timer, using 32-bit unsigned integers to measure time intervals.
        /// @param dueTime The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
        /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
        /// @exception ArgumentOutOfRangeException The dueTime or period parameter is negative and is not equal to Timeout::Infinite.
        void Change(uint32 dueTime, uint32 period) {this->Change(as<int32>(dueTime), as<int32>(period));}

      private:
        void Close() {
          if (this->data.GetUseCount() == 1) {
            this->data->closed = true;
            this->data->event.Set();
            this->data->thread.Join();
          }
        }
        struct TimerData : public object {
          TimerCallback callback;
          bool closed{false};
          int32 dueTime{-1};
          AutoResetEvent event {false};
          int32 period {-1};
          Object* state{this};
          Thread thread {ThreadStart {delegate_ {
                bool runOnce = false;
                while (!this->closed) {
                  if (!this->event.WaitOne(runOnce ? this->period : this->dueTime)) {
                    runOnce = true;
                    ThreadPool::QueueUserWorkItem(this->callback, *this->state);
                  }
                }
              }}};
        };

        refptr<TimerData> data = new TimerData();
      };
    }
  }
}

using namespace Switch;
