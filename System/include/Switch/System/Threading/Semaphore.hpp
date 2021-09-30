/// @file
/// @brief Contains Switch::System::Threading::Semaphore class.
#pragma once

#include <mutex>
#include <condition_variable>

#include <Switch/RefPtr.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Int32.hpp>
#include <Switch/System/ObjectDisposedException.hpp>
#include <Switch/System/Threading/AbandonedMutexException.hpp>
#include <Switch/System/Threading/SemaphoreFullException.hpp>
#include <Switch/System/Threading/WaitHandle.hpp>
#include <Switch/System/Threading/WaitHandleCannotBeOpenedException.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Limits the number of threads that can access a resource or pool of resources concurrently.
      /// @par Library
      /// Switch.System
      class system_export_ Semaphore: public WaitHandle {
      public:
        /// @brief Initializes a new instance of the System::Threading::Semaphore class
        /// @remarks The count is equals to 0 and the maximumCount is equal to Int32::MaxValue.
        /// @exception IO::IOException An Io error occurred.
        Semaphore() {}

        /// @brief Initializes a new instance of the System::Threading::Semaphore class, specifying the maximum number of concurrent entries and optionally reserving some entries.
        /// @param initialCount The initial number of requests for the semaphore that can be granted concurrently.
        /// @param maximumCount The maximum number of requests for the semaphore that can be granted concurrently.
        /// @exception IO::IOException An Io error occurred.
        Semaphore(int32 initialCount, int32 maximumCount) : count(ref_new<int32>(initialCount)), maxCount(ref_new<int32>(maximumCount)) {}

        /// @brief Initializes a new instance of the System::Threading::Semaphore class, specifying the maximum number of concurrent entries, optionally reserving some entries
        /// for the calling thread, and optionally specifying the name of a system semaphore
        /// object.
        /// @param initialCount The initial number of requests for the semaphore that can be granted concurrently.
        /// @param maximumCount The maximum number of requests for the semaphore that can be granted concurrently.
        /// @param name The name of a named system semaphore object.
        /// @exception ArgumentException name is longer than 128 characters -or- initialCount is greater than maximumCount -or- maximumCount is less than 1.
        /// @exception IO::IOException An Io error occurred.
        Semaphore(int32 initialCount, int32 maximumCount, const String& name);

        /// @brief Initializes a new instance of the System::Threading::Semaphore class, specifying the maximum number of concurrent entries, optionally reserving some entries for the calling thread, optionally specifying the name of a system semaphore object, and specifying a variable that receives a value indicating whether a new system semaphore was created.
        /// @param initialCount The initial number of requests for the semaphore that can be granted concurrently.
        /// @param maximumCount The maximum number of requests for the semaphore that can be granted concurrently.
        /// @param name The name of a named system semaphore object.
        /// @param createdNew When this method returns, contains true if a local semaphore was created (that is, if name is null or an empty string) or if the specified named system semaphore was created; false if the specified named system semaphore already existed.
        /// @exception ArgumentException name is longer than 128 characters -or- initialCount is greater than maximumCount -or- maximumCount is less than 1.
        /// @exception IO::IOException An Io error occurred.
        Semaphore(int32 initialCount, int32 maximumCount, const String& name, bool& createdNew);

        /// @cond
        Semaphore(const Semaphore& semaphore) : guard(semaphore.guard), signal(semaphore.signal), count(semaphore.count), maxCount(semaphore.maxCount), name(semaphore.name) {}
        ~Semaphore() {this->Close();}
        Semaphore& operator =(const Semaphore& semaphore) {
          this->guard = semaphore.guard;
          this->signal = semaphore.signal;
          this->count = semaphore.count;
          this->maxCount = semaphore.maxCount;
          this->name = semaphore.name;
          return *this;
        }
        /// @endcond

        /// @brief When overridden in a derived class, releases all resources held by the current System::Threading::WaitHandle.
        void Close() override;

        /// @brief Determines whether this instance and another specified Semaphore object have the same value.
        /// @param value The Mutex to compare.
        /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
        bool Equals(const Semaphore& value) const {return this->guard == value.guard && this->signal == value.signal && this->count == value.count &&  this->maxCount == value.maxCount && this->name == value.name;}

        /// @brief Determines whether this instance of Semaphore and a specified object, which must also be a Semaphore object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const Object& obj) const override {return is<Semaphore>(obj) && this->Equals((const Semaphore&)obj);}

        /// @brief Opens an existing named semaphore.
        /// @param name The name of a named system semaphore.
        /// @return A System::Threading::Semaphore object that represents a named system semaphore.
        /// @exception ArgumentNullException name is null -or- name is a zero-length string
        /// @exception ArgumentException name is longer than 128 characters
        /// @exception IO::IOException An Io error occurred.
        static Semaphore OpenExisting(const String& name);

        /// @brief Exits the semaphore and returns the previous count.
        /// @return The count on the semaphore before the Overload:System::Threading::Semaphore.Release method was called.
        /// @exception SemaphoreFullException The semaphore count is already at the maximum value.
        /// @exception IO::IOException An Io error occurred.
        int32 Release() {return this->Release(1);}

        /// @brief Exits the semaphore and returns the previous count.
        /// @param releaseCount The number of times to exit the semaphore.
        /// @return The count on the semaphore before the Overload:System::Threading::Semaphore.Release method was called.
        /// @exception SemaphoreFullException The semaphore count is already at the maximum value.
        /// @exception IO::IOException An Io error occurred.
        int32 Release(int32 releaseCount) {
          if (this->guard == null)
            throw ObjectDisposedException(caller_);
          std::unique_lock<std::mutex> lock(*this->guard);
          if (*this->count + releaseCount > *this->maxCount)
            throw SemaphoreFullException(caller_);
          *this->count += releaseCount;
          this->signal->notify_all();
          return *this->count - releaseCount;
        }

        /// @brief Opens the specified named semaphore, if it already exists, and returns a value that indicates whether the operation succeeded.
        /// @param name The name of a system-wide named semaphore object.
        /// @param result When this method returns, contains a Semaphore object that represents the named semaphore if the call succeeded, or null if the call failed. This parameter is treated as uninitialized.
        /// @return true if the named semaphore was opened successfully; otherwise, false.
        static bool TryOpenExisting(const String& name, Semaphore& result);

      private:
        bool Signal() override {
          this->Release();
          return true;
        }

        bool Wait(int32 millisecondsTimeOut) override {
          if (this->guard == null)
            throw ObjectDisposedException(caller_);
          if (millisecondsTimeOut < -1)
            throw AbandonedMutexException(caller_);

          std::unique_lock<std::mutex> lock(*this->guard);
          while (*this->count == 0) {
            if (millisecondsTimeOut == -1)
              this->signal->wait(lock);
            else if (this->signal->wait_for(lock, std::chrono::milliseconds(millisecondsTimeOut)) == std::cv_status::timeout)
              return false;
          }

          *this->count -= 1;
          return true;
        }

        refptr<std::mutex> guard = ref_new<std::mutex>();
        refptr<std::condition_variable> signal = ref_new<std::condition_variable>();
        refptr<int32> count = ref_new<int32>(0);
        refptr<int32> maxCount = ref_new<int32>(Int32::MaxValue);
        refptr<string> name = ref_new<string>();
      };
    }
  }
}

using namespace Switch;
