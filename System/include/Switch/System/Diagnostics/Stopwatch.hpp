/// @file
/// @brief Contains Switch::System::Diagnostics::Stopwatch class.
#pragma once

#include <Switch/Types.hpp>
#include <Switch/System/TimeSpan.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides a set of methods and properties that you can use to accurately measure elapsed time.
      /// @remarks A Stopwatch instance can measure elapsed time for one interval, or the total of elapsed time across multiple intervals. In a typical Stopwatch scenario, you call the Start method, then eventually call the Stop method, and then you check elapsed time using the Elapsed property.
      /// @remarks A Stopwatch instance is either running or stopped; use IsRunning to determine the current state of a Stopwatch. Use Start to begin measuring elapsed time; use Stop to stop measuring elapsed time. Query the elapsed time value through the properties Elapsed, ElapsedMilliseconds, or ElapsedTicks. You can query the elapsed time properties while the instance is running or stopped. The elapsed time properties steadily increase while the Stopwatch is running; they remain constant when the instance is stopped.
      /// @remarks By default, the elapsed time value of a Stopwatch instance equals the total of all measured time intervals. Each call to Start begins counting at the cumulative elapsed time; each call to Stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the Reset method to clear the cumulative elapsed time in an existing Stopwatch instance.
      /// @remarks The Stopwatch measures elapsed time by counting timer ticks in the underlying timer mechanism. If the installed hardware and operating system support a high-resolution performance counter, then the Stopwatch class uses that counter to measure elapsed time. Otherwise, the Stopwatch class uses the system timer to measure elapsed time. Use the Frequency and IsHighResolution fields to determine the precision and resolution of the Stopwatch timing implementation.
      /// @remarks The Stopwatch class assists the manipulation of timing-related performance counters within managed code. Specifically, the Frequency field and GetTimestamp method can be used in place of the unmanaged Win32 APIs QueryPerformanceFrequency and QueryPerformanceCounter.
      /// @par Library
      /// Switch.System
      /// @par Examples
      /// The following example demonstrates how to use the Stopwatch class to determine the execution time for an application.
      /// @include Stopwatch.cpp
      class system_export_ Stopwatch : public Object {
      public:
        /// @brief Gets the frequency of the timer as the number of ticks per second. This field is read-only.
        /// @return The frequency of the timer as the number of ticks per second.
        /// @remarks The timer frequency indicates the timer precision and resolution. For example, a timer frequency of 2 million ticks per second equals a timer resolution of 500 nanoseconds per tick. In other words, because one second equals 1 billion nanoseconds, a timer frequency of 2 million ticks per second is equivalent to 2 million ticks per 1 billion nanoseconds, which can be further simplified to 1 tick per 500 nanoseconds.
        /// @remarks The Frequency value depends on the resolution of the underlying timing mechanism. If the installed hardware and operating system support a high-resolution performance counter, then the Frequency value reflects the frequency of that counter. Otherwise, the Frequency value is based on the system timer frequency.
        /// @remarks Because the Stopwatch frequency depends on the installed hardware and operating system, the Frequency value remains constant while the system is running.
        static property_<int64, readonly_> Frequency;

        /// @brief Indicates whether the timer is based on a high-resolution performance counter. This field is read-only.
        /// @return true if the timer is based on a high-resolution performance counte; otherwise, false.
        /// @remarks The timer used by the Stopwatch class depends on the system hardware and operating system. IsHighResolution is true if the Stopwatch timer is based on a high-resolution performance counter. Otherwise, IsHighResolution is false, which indicates that the Stopwatch timer is based on the system timer.
        static property_<bool, readonly_> IsHighResolution;

        /// @brief Initializes a new instance of the Stopwatch class.
        /// @remarks The returned Stopwatch instance is stopped, and the elapsed time property of the instance is zero.
        /// @remarks Use the Start method to begin measuring elapsed time with the new Stopwatch instance. Use the StartNew method to initialize a new Stopwatch instance and immediately start it.
        Stopwatch() = default;

        /// @cond
        Stopwatch(const Stopwatch& sw) : running(sw.running), start(sw.start), stop(sw.stop) {}
        Stopwatch& operator =(const Stopwatch& sw) {
          this->running = sw.running;
          this->start = sw.start;
          this->stop = sw.stop;
          return *this;
        }
        /// @endcond

        /// @brief Gets the total elapsed time measured by the current instance.
        /// @return A TimeSpan representing the total elapsed time measured by the current instance.
        /// @remarks In a typical Stopwatch scenario, you call the Start method, then eventually call the Stop method, and then you check elapsed time using the Elapsed property.
        /// @remarks Use the Elapsed property to retrieve the elapsed time value using TimeSpan methods and properties. For example, you can format the returned TimeSpan instance into a text representation, or pass it to another class that requires a TimeSpan parameter.
        /// @remarks You can query the properties Elapsed, ElapsedMilliseconds, and ElapsedTicks while the Stopwatch instance is running or stopped. The elapsed time properties steadily increase while the Stopwatch is running; they remain constant when the instance is stopped.
        /// @remarks By default, the elapsed time value of a Stopwatch instance equals the total of all measured time intervals. Each call to Start begins counting at the cumulative elapsed time; each call to Stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the Reset method to clear the cumulative elapsed time in an existing Stopwatch instance.
        property_<TimeSpan, readonly_> Elapsed {
          get_ {return TimeSpan::FromTicks(ElapsedTicks);}
        };

        /// @brief Gets the total elapsed time measured by the current instance, in milliseconds.
        /// @return A long integer representing the total number of milliseconds measured by the current instance.
        /// @remarks This property represents elapsed time rounded down to the nearest whole millisecond value. For higher precision measurements, use the Elapsed or ElapsedTicks properties.
        /// @remarks You can query the properties Elapsed, ElapsedMilliseconds, and ElapsedTicks while the Stopwatch instance is running or stopped. The elapsed time properties steadily increase while the Stopwatch is running; they remain constant when the instance is stopped.
        /// @remarks By default, the elapsed time value of a Stopwatch instance equals the total of all measured time intervals. Each call to Start begins counting at the cumulative elapsed time; each call to Stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the Reset method to clear the cumulative elapsed time in an existing Stopwatch instance.
        property_<int64, readonly_> ElapsedMilliseconds {
          get_ {return this->GetElapsedTicks() / TimeSpan::TicksPerMillisecond;}
        };

        /// @brief Gets the total elapsed time measured by the current instance, in timer ticks.
        /// @return A long integer representing the total number of timer ticks measured by the current instance.
        /// @remarks This property represents the number of elapsed ticks in the underlying timer mechanism. A tick is the smallest unit of time that the Stopwatch timer can measure. Use the Frequency field to convert the ElapsedTicks value into a number of seconds.
        /// @remarks You can query the properties Elapsed, ElapsedMilliseconds, and ElapsedTicks while the Stopwatch instance is running or stopped. The elapsed time properties steadily increase while the Stopwatch is running; they remain constant when the instance is stopped.
        /// @remarks By default, the elapsed time value of a Stopwatch instance equals the total of all measured time intervals. Each call to Start begins counting at the cumulative elapsed time; each call to Stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the Reset method to clear the cumulative elapsed time in an existing Stopwatch instance.
        property_<int64, readonly_> ElapsedTicks {
          get_ {return this->GetElapsedTicks();}
        };

        /// @brief Gets a value indicating whether the Stopwatch timer is running.
        /// @return true if the Stopwatch instance is currently running and measuring elapsed time for an interval; otherwise, false.
        /// @remarks A Stopwatch instance begins running with a call to Start or StartNew. The instance stops running with a call to Stop or Reset.
        property_<bool, readonly_> IsRunning {
          get_ {return this->running;}
        };

        /// @brief Gets the current number of ticks in the timer mechanism.
        /// @return A long integer representing the tick counter value of the underlying timer mechanism.
        /// @remarks If the Stopwatch class uses a high-resolution performance counter, GetTimestamp returns the current value of that counter. If the Stopwatch class uses the system timer, GetTimestamp returns the current DateTime.Ticks property of the DateTime.Now instance.
        static int64 GetTimestamp();

        /// @brief Stops time interval measurement and resets the elapsed time to zero.
        /// @remarks A Stopwatch instance calculates and retains the cumulative elapsed time across multiple time intervals, until the instance is reset. Use Stop to stop the current interval measurement and retain the cumulative elapsed time value. Use Reset to stop any interval measurement in progress and clear the elapsed time value.
        void Reset() {
          this->start = this->stop = 0;
          this->running = false;
        }

        /// @brief Stops time interval measurement, resets the elapsed time to zero, and starts measuring elapsed time.
        /// @remarks A Stopwatch instance calculates and retains the cumulative elapsed time across multiple time intervals, until the instance is reset or restarted. Use Stop to stop the current interval measurement and retain the cumulative elapsed time value. Use Reset to stop any interval measurement in progress and clear the elapsed time value. Use Restart to stop current interval measurement and start a new interval measurement.
        void Restart() {
          this->Reset();
          this->Start();
        }

        /// @brief Starts, or resumes, measuring elapsed time for an interval.
        /// @remarks n a typical Stopwatch scenario, you call the Start method, then eventually call the Stop method, and then you check elapsed time using the Elapsed property.
        /// @remarks Once started, a Stopwatch timer measures the current interval, in elapsed timer ticks, until the instance is stopped or reset. Starting a Stopwatch that is already running does not change the timer state or reset the elapsed time properties.
        /// @remarks When a Stopwatch instance measures more than one interval, the Start method resumes measuring time from the current elapsed time value. A Stopwatch instance calculates and retains the cumulative elapsed time across multiple time intervals, until the instance is reset. Use the Reset method before calling Start to clear the cumulative elapsed time in a Stopwatch instance. Use the Restart method to Reset and Start the Stopwatch with a single command.
        void Start() {
          this->start = this->GetTimestamp() - (this->stop - this->start);
          this->running = true;
        }

        /// @brief Initializes a new Stopwatch instance, sets the elapsed time property to zero, and starts measuring elapsed time.
        /// @remarks This method is equivalent to calling the Stopwatch constructor and then calling Start on the new instance.
        static Stopwatch StartNew() {return Stopwatch(true);}

        /// @brief Stops measuring elapsed time for an interval.
        /// @remarks In a typical Stopwatch scenario, you call the Start method, then eventually call the Stop method, and then you check elapsed time using the Elapsed property.
        /// @remarks The Stop method ends the current time interval measurement. Stopping a Stopwatch that is not running does not change the timer state or reset the elapsed time properties.
        /// @remarks When a Stopwatch instance measures more than one interval, the Stop method is equivalent to pausing the elapsed time measurement. A subsequent call to Start resumes measuring time from the current elapsed time value. Use the Reset method to clear the cumulative elapsed time in a Stopwatch instance.
        void Stop() {
          this->stop = this->GetTimestamp();
          this->running = false;
        }

      private:
        Stopwatch(bool start) {
          if (start)
            Start();
        }

        int64 GetElapsedTicks() const {
          if (this->running)
            return this->GetTimestamp() - this->start;
          return (this->stop - this->start);
        }

        bool running = false;
        int64 start = 0;
        int64 stop = 0;
      };
    }
  }
}

using namespace Switch;
