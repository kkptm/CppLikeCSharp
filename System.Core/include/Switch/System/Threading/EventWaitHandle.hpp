/// @file
/// @brief Contains Switch::System::Threading::EventWaitHandle class.
#pragma once

#include <condition_variable>
#include <mutex>

#include "../../RefPtr.hpp"
#include "../String.hpp"
#include "../ObjectDisposedException.hpp"
#include "AbandonedMutexException.hpp"
#include "WaitHandle.hpp"
#include "EventResetMode.hpp"
#include "WaitHandleCannotBeOpenedException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Represents a thread synchronization event.
      class core_export_ EventWaitHandle: public WaitHandle {
      public:
        /// @brief Initializes a new instance of the System::Threading::EventWaitHandle class.
        /// @exception IO::IOException A Win32 error occurred.
        EventWaitHandle() {}

        /// @brief Initializes a new instance of the System::Threading::EventWaitHandle class, specifying whether the wait handle is initially signaled, and whether it resets automatically or manually.
        /// @param initialState true to set the initial state to signaled if the named event is created as a result of this call; false to set it to nonsignaled.
        /// @param mode One of the System::Threading::EventResetMode values that determines whether the event resets automatically or manually.
        /// @exception IO::IOException A Win32 error occurred.
        EventWaitHandle(bool initialState, EventResetMode mode) : mode(ref_new<EventResetMode>(mode)) {
          if (initialState)
            this->Set();
        }

        /// @brief Initializes a new instance of the System::Threading::EventWaitHandle class, specifying whether the wait handle is initially signaled if created as a result of this call, whether it resets automatically or manually, the name of a system synchronization event.
        /// @param initialState true to set the initial state to signaled if the named event is created as a result of this call; false to set it to nonsignaled.
        /// @param mode One of the System::Threading::EventResetMode values that determines whether the event resets automatically or manually.
        /// @param name The name of a system-wide synchronization event.
        /// @exception ArgumentNullException name is null
        /// @exception ArgumentException name is longer than 128 characters
        /// @exception IO::IOException A Win32 error occurred.
        EventWaitHandle(bool initialState, EventResetMode mode, const System::String& name);

        /// @brief Initializes a new instance of the System::Threading::EventWaitHandle class, specifying whether the wait handle is initially signaled if created as a result of this call, whether it resets automatically or manually, the name of a system synchronization event, and a Boolean variable whose value after the call indicates whether the named system event was created.
        /// @param initialState true to set the initial state to signaled if the named event is created as a result of this call; false to set it to nonsignaled.
        /// @param mode One of the System::Threading::EventResetMode values that determines whether the event resets automatically or manually.
        /// @param name The name of a system-wide synchronization event.
        /// @param createdNew When this method returns, contains true if a local event was created (that is, if name is null or an empty System::String) or if the specified named system event was created; false if the specified named system event already existed. This parameter is passed uninitialized.
        /// @exception ArgumentNullException name is null
        /// @exception ArgumentException name is longer than 128 characters
        /// @exception IO::IOException A Win32 error occurred.
        EventWaitHandle(bool initialState, EventResetMode mode, const System::String& name, bool& createdNew);

        /// @cond
        EventWaitHandle(const EventWaitHandle& evh) : guard(evh.guard), signal(evh.signal), event(evh.event), mode(evh.mode), name(evh.name) {}
        ~EventWaitHandle()  {Close();}
        EventWaitHandle& operator=(const EventWaitHandle& evh) {
          this->guard = evh.guard;
          this->signal = evh.signal;
          this->event = evh.event;
          this->mode = evh.mode;
          this->name = evh.name;
          return *this;
        }
        /// @endcond

        /// @brief Releases all resources held by the current EventWaitHandle.
        void Close() override;

        /// @brief Opens an existing named synchronization event.
        /// @param name The name of a system-wide synchronization event.
        /// @return A System::Threading::EventWaitHandle object that represents the named system event.
        /// @exception ArgumentNullException name is null
        /// @exception ArgumentException name is longer than 128 characters
        /// @exception IO::IOException A Win32 error occurred.
        static EventWaitHandle OpenExisting(const System::String& name);

        /// @brief Sets the state of the event to nonsignaled, causing threads to block.
        /// @return true if the operation succeeds; otherwise, false.
        bool Reset() {
          if (this->guard == null)
            throw ObjectDisposedException(caller_);
          std::unique_lock<std::mutex> lock(*this->guard);
          *this->event = false;
          return true;
        }

        /// @brief Sets the state of the event to signaled, allowing one or more waiting threads to proceed.
        /// @return true if the operation succeeds; otherwise, false.
        bool Set() {
          if (this->guard == null)
            throw ObjectDisposedException(caller_);
          std::unique_lock<std::mutex> lock(*this->guard);
          *this->event = true;
          this->signal->notify_all();
          return true;
        }

        /// @brief Determines whether this instance and another specified EventWaitHandle object have the same value.
        /// @param value The EventWaitHandle to compare.
        /// @return Boolean true if the value of this instance is the same as the value of value; otherwise, false.
        /// @exception ArgumentNullException The parameters value is null.
        bool Equals(const EventWaitHandle& value) const {return this->guard == value.guard && this->signal == value.signal && this->event == value.event &&  this->mode == value.mode && this->name == value.name;}

        /// @brief Determines whether this instance of EventWaitHandle and a specified object, which must also be a EventWaitHandle object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        /// @exception ArgumentNullException The parameters obj is null.
        bool Equals(const object& obj) const override {return is<EventWaitHandle>(obj) && this->Equals((const EventWaitHandle&)obj);}

      private:
        bool Signal() override {return this->Set();}

        bool Wait(int32 millisecondsTimeOut) override {
          if (this->guard == null)
            throw ObjectDisposedException(caller_);
          if (millisecondsTimeOut < -1)
            throw AbandonedMutexException(caller_);

          std::unique_lock<std::mutex> lock(*this->guard);
          while (*this->event == false) {
            if (millisecondsTimeOut == -1)
              this->signal->wait(lock);
            else if (this->signal->wait_for(lock, std::chrono::milliseconds(millisecondsTimeOut)) == std::cv_status::timeout)
              return false;
          }

          if (*this->mode == EventResetMode::AutoReset)
            *this->event = false;
          return true;
        }

        refptr<std::mutex> guard = ref_new<std::mutex>();
        refptr<std::condition_variable> signal = ref_new<std::condition_variable>();
        refptr<bool> event = ref_new<bool>(false);
        refptr<EventResetMode> mode = ref_new<EventResetMode>(EventResetMode::ManualReset);
        refptr<string> name = ref_new<string>();
      };
    }
  }
}

using namespace Switch;
