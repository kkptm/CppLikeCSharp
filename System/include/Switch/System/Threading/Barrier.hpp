/// @file
/// @brief Contains Switch::System::Threading::Barrier class.
#pragma once

#include <mutex>

#include <Switch/RefPtr.hpp>
#include <Switch/System/ArgumentOutOfRangeException.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemExport.hpp"
#include "BarrierPostPhaseException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Enables multiple tasks to cooperatively work on an algorithm in parallel through multiple phases.
      /// @remarks A group of tasks cooperate by moving through a series of phases, where each in the group signals it has arrived at the Barrier in a given phase and implicitly waits for all others to arrive. The same Barrier can be used for multiple phases.
      /// @par Library
      /// Switch.System
      /// @par Examples
      /// The following example shows how to use a barrier:
      /// @include Barrier.cpp
      class system_export_ Barrier : public object {
      public:
        /// @brief Initializes a new instance of the Barrier class.
        /// @param participantCount The number of participating threads.
        /// @exception ArgumentOutOfRangeException participantCount is less than 0 or greater than 32,767.
        explicit Barrier(int32 participantCount) : data(new BarrierData()) {this->AddParticipants(participantCount);}

        /// @brief Initializes a new instance of the Barrier class.
        /// @param participantCount The number of participating threads.
        /// @param postPhaseAction The Action<T> to be executed after each phase.
        /// @exception ArgumentOutOfRangeException participantCount is less than 0 or greater than 32,767.
        /// @remarks The postPhaseAction delegate will be executed after all participants have arrived at the barrier in one phase. The participants will not be released to the next phase until the postPhaseAction delegate has completed execution.
        explicit Barrier(int32 participantCount, const Action<const Barrier&>& postPhaseAction) : data(new BarrierData(postPhaseAction)) {this->AddParticipants(participantCount);}

        /// @cond
        Barrier() : data(new BarrierData()) {}
        Barrier(const Barrier& barrier) : data(barrier.data) {}
        Barrier& operator=(const Barrier& barriere) {
          this->data = data;
          return *this;
        }
        /// @endcond

        /// @brief Gets the number of the barrier's current phase.
        /// @return Returns the number of the barrier's current phase.
        property_<int64, readonly_> CurrentPhaseNumber {
          get_ {return this->data->currentPhaseNumber;}
        };

        /// @brief Gets the total number of participants in the barrier.
        /// @return Returns the total number of participants in the barrier.
        property_<int32, readonly_> ParticipantCount {
          get_ {return this->data->participantCount;}
        };

        /// @brief Gets the number of participants in the barrier that haven’t yet signaled in the current phase.
        /// @return Returns the number of participants in the barrier that haven’t yet signaled in the current phase.
        /// @remarks This could be 0 during a post-phase action delegate execution or if the ParticipantCount is 0.
        property_<int32, readonly_> ParticipantsRemaining {
          get_ {return this->data->participantsRemaining;}
        };

        /// @brief Notifies the Barrier that there will be an additional participant.
        /// @return The phase number of the barrier in which the new participants will first participate.
        /// @exception ArgumentOutOfRangeException participantCount is less than 0.  -or-  Adding participantCount participants would cause the barrier's participant count to exceed 32,767.
        /// @exception InvalidOperation The method was invoked from within a post-phase action.
        /// @remarks If the barrier is currently executing a post phase action, this call is blocked until the post phase action completes and the barrier has moved on to the next phase.
        int64 AddParticipant() {return this->AddParticipants(1);}

        /// @brief Notifies the Barrier that there will be additional participants.
        /// @param participantCount The number of additional participants to add to the barrier.
        /// @return The phase number of the barrier in which the new participants will first participate.
        /// @exception ArgumentOutOfRangeException participantCount is less than 0.  -or-  Adding participantCount participants would cause the barrier's participant count to exceed 32,767.
        /// @exception InvalidOperation The method was invoked from within a post-phase action.
        /// @remarks If the barrier is currently executing a post phase action, this call is blocked until the post phase action completes and the barrier has moved on to the next phase.
        int64 AddParticipants(int32 participantCount) {
          lock_(*this) {
            if (participantCount < 0 || as<int64>(this->data->participantCount) + participantCount > as<int64>(Int32::MaxValue))
              throw ArgumentOutOfRangeException(caller_);
            if (this->data->runPostPhaseAction)
              throw InvalidOperationException(caller_);
            this->data->participantCount += participantCount;
            this->data->participantsRemaining += participantCount;
            return this->data->currentPhaseNumber;
          }
          return this->data->currentPhaseNumber;
        }

        /// @brief Notifies the Barrier that there will be one less participants.
        /// @exception ArgumentoutOfRangeException participantCount is less than 0.
        /// @exception InvalidOperation The barrier already has 0 participants.  -or-  The method was invoked from within a post-phase action.  -or-  current participant count is less than the specified participantCount.
        /// @exception ArgumentoutOfRangeException The total participant count is less than the specified participantCount.
        /// @remarks If the barrier is currently executing a post phase action, this call is blocked until the post phase action completes and the barrier has moved on to the next phase.
        int64 RemoveParticipant() {return this->RemoveParticipants(1);}

        /// @brief Notifies the Barrier that there will be fewer participants.
        /// @param participantCount The number of additional participants to remove from the barrier.
        /// @exception ArgumentoutOfRangeException participantCount is less than 0.
        /// @exception InvalidOperation The barrier already has 0 participants.  -or-  The method was invoked from within a post-phase action.  -or-  current participant count is less than the specified participantCount.
        /// @exception ArgumentoutOfRangeException The total participant count is less than the specified participantCount.
        /// @remarks If the barrier is currently executing a post phase action, this call is blocked until the post phase action completes and the barrier has moved on to the next phase.
        int64 RemoveParticipants(int32 participantCount) {
          lock_(*this) {
            if (participantCount < 0)
              throw ArgumentOutOfRangeException(caller_);
            if (this->data->participantCount == 0 || this->data->runPostPhaseAction || this->data->participantsRemaining < this->data->participantCount - participantCount)
              throw InvalidOperationException(caller_);
            if (this->data->participantCount < participantCount)
              throw ArgumentOutOfRangeException(caller_);
            this->data->participantCount -= participantCount;
            this->data->participantsRemaining -= participantCount;
            return this->data->currentPhaseNumber;
          }
          return this->data->currentPhaseNumber;
        }

        /// @brief Signals that a participant has reached the barrier and waits for all other participants to reach the barrier as well.
        void SignalAndWait() {this->SignalAndWait(-1);}

        /// @brief Signals that a participant has reached the barrier and waits for all other participants to reach the barrier as well, using a TimeSpan object to measure the time interval.
        /// @param timeout A TimeSpan that represents the number of milliseconds to wait, or a TimeSpan that represents -1 milliseconds to wait indefinitely.
        /// @return true if all other participants reached the barrier; otherwise, false.
        bool SignalAndWait(const TimeSpan& timeout) {return this->SignalAndWait(as<int32>(timeout.TotalMilliseconds()));}

        /// @brief Signals that a participant has reached the barrier and waits for all other participants to reach the barrier as well, using a 32-bit signed integer to measure the timeout.
        /// @param millisecondsTimeout The number of milliseconds to wait, or Infinite(-1) to wait indefinitely.
        /// @return if all participants reached the barrier within the specified time; otherwise false.
        bool SignalAndWait(int32 millisecondsTimeout) {
          if (millisecondsTimeout < -1)
            throw ArgumentOutOfRangeException(caller_);

          std::unique_lock<std::mutex> lock(this->data->mutex);
          int64 currentPhaseNumber = this->data->currentPhaseNumber;

          if (Signal())
            return true;

          bool result = false;
          while (currentPhaseNumber == this->data->currentPhaseNumber) {
            if (millisecondsTimeout == -1) {
              this->data->cond.wait(lock);
              result = true;
            } else
              result = this->data->cond.wait_for(lock, std::chrono::milliseconds(millisecondsTimeout)) == std::cv_status::no_timeout;

            if (this->data->participantsPostPhaseExceptionRemainin-- > 0)
              throw BarrierPostPhaseException(caller_);
          }
          return result;
        }

      private:
        bool Signal() {
          lock_(*this) {
            if (--this->data->participantsRemaining == 0) {
              this->data->runPostPhaseAction = true;
              try {
                this->data->postPhaseAction(*this);
              } catch (...) {
                this->data->runPostPhaseAction = false;
                this->data->currentPhaseNumber++;
                this->data->participantsRemaining = this->data->participantCount;
                this->data->participantsPostPhaseExceptionRemainin = this->data->participantCount - 1;
                this->data->cond.notify_all();
                throw BarrierPostPhaseException(caller_);
              }
              this->data->runPostPhaseAction = false;
              this->data->currentPhaseNumber++;
              this->data->participantsRemaining = this->data->participantCount;
              this->data->cond.notify_all();
              return true;
            } else
              this->data->participantsPostPhaseExceptionRemainin = false;
          }
          return false;
        }

        struct BarrierData {
          BarrierData() {}
          BarrierData(const Action<const Barrier&>& postPhaseAction) : postPhaseAction(postPhaseAction) {}
          BarrierData(const BarrierData&) = delete;
          BarrierData operator=(const BarrierData&) = delete;

          std::mutex mutex;
          std::condition_variable cond;
          int32 participantCount = 0;
          int64 currentPhaseNumber = 0;
          int32 participantsRemaining = 0;
          Action<const Barrier&> postPhaseAction;
          bool runPostPhaseAction = false;
          int32 participantsPostPhaseExceptionRemainin = 0;
        };

        refptr<BarrierData> data;
      };
    }
  }
}

using namespace Switch;
