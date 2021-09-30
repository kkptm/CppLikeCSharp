/// @file
/// @brief Contains Switch::System::Threading::Mutex class.
#pragma once

#include <mutex>

#include "../../RefPtr.hpp"
#include "../ObjectDisposedException.hpp"
#include "../String.hpp"
#include "WaitHandle.hpp"
#include "WaitHandleCannotBeOpenedException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief A synchronization primitive that can also be used for interprocess synchronization.
      class core_export_ Mutex: public WaitHandle {
      private:
      public:
        /// @brief Initializes a new instance of the System::Threading::Mutex class with a Boolean value that indicates whether the calling thread should have initial ownership of the mutex.
        /// @exception ArgumentException name is longer than 128 characters
        /// @exception IO::IOException An Io error occurred.
        Mutex() {this->WaitOne();}

        /// @brief Initializes a new instance of the System::Threading::Mutex class with a Boolean
        /// value that indicates whether the calling thread should have initial ownership
        /// of the mutex.
        /// @param initiallyOwned true to give the calling thread initial ownership of the named system mutex
        /// if the named system mutex is created as a result of this call; otherwise,
        /// false.
        /// @exception ArgumentException name is longer than 128 characters
        /// @exception IO::IOException An Io error occurred.
        Mutex(bool initiallyOwned) {
          if (initiallyOwned)
            this->WaitOne();
        }

        /// @brief Initializes a new instance of the System::Threading::Mutex class with a Boolean
        /// value that indicates whether the calling thread should have initial ownership
        /// of the mutex, and a string that is the name of the mutex.
        /// @param initiallyOwned true to give the calling thread initial ownership of the named system mutex
        /// if the named system mutex is created as a result of this call; otherwise,
        /// false.
        /// @param name The name of the System::Threading::Mutex. If the value is null, the System::Threading::Mutex is unnamed.
        /// @exception ArgumentException name is longer than 128 characters
        /// @exception IO::IOException An Io error occurred.
        Mutex(bool initiallyOwned, const String& name);

        /// @brief Initializes a new instance of the System::Threading::Mutex class with a Boolean
        /// value that indicates whether the calling thread should have initial ownership
        /// of the mutex, a string that is the name of the mutex, and a Boolean value
        /// that, when the method returns, indicates whether the calling thread was granted
        /// initial ownership of the mutex.
        /// @param initiallyOwned true to give the calling thread initial ownership of the named system mutex if the named system mutex is created as a result of this call; otherwise, false.
        /// @param name The name of the System::Threading::Mutex. If the value is null, the System::Threading::Mutex is unnamed.
        /// @param createdNew When this method returns, contains a Boolean that is true if a local mutex was created (that is, if name is null or an empty string) or if the specified named system mutex was created; false if the specified named system mutex already existed.
        /// @exception AgumentException name is longer than 128 characters
        /// @exception IO::IOException An Io error occurred.
        Mutex(bool initiallyOwned, const String& name, bool& createdNew);

        /// @cond
        Mutex(const Mutex& mutex) : mutex(mutex.mutex), name(mutex.name) {}
        ~Mutex() {Close();}
        Mutex& operator=(const Mutex& mutex) {
          this->mutex = mutex.mutex;
          this->name = mutex.name;
          return *this;
        }
        /// @endcond

        /// @brief When overridden in a derived class, releases all resources held by the current System::Threading::WaitHandle.
        void Close() override;

        /// @brief Opens an existing named mutex.
        /// @param name The name of a system-wide named mutex object.
        /// @return A System::Threading::Mutex object that represents a named system mutex.
        /// @exception ArgumentNullException is null -or- name is a zero-length string
        /// @exception ArgumentException name is longer than 128 characters
        /// @exception IO::IOException A Win32 error occurred.
        static Mutex OpenExisting(const String& name);

        /// @brief Releases the System::Threading::Mutex once.
        /// @param name The name of a system-wide named mutex object.
        /// @return A System::Threading::Mutex object that represents a named system mutex.
        /// @exception ApplicationException The calling thread does not own the mutex.
        void ReleaseMutex() {
          if (this->mutex == null)
            throw ObjectDisposedException(caller_);
          this->mutex->unlock();
        }

        /// @brief Determines whether this instance and another specified Mutex object have the same value.
        /// @param value The Mutex to compare.
        /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
        bool Equals(const Mutex& value) const {return this->mutex == value.mutex && this->name == value.name;}

        /// @brief Determines whether this instance of Mutex and a specified object, which must also be a Mutex object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const Object& obj) const override {return is<Mutex>(obj) && Equals((const Mutex&)obj);}

        /// @brief Opens the specified named mutex, if it already exists, and returns a value that indicates whether the operation succeeded.
        /// @param name The name of a system-wide named mutex object.
        /// @param result When this method returns, contains a Mutex object that represents the named mutex if the call succeeded, or null if the call failed. This parameter is treated as uninitialized.
        /// @return true if the named mutex was opened successfully; otherwise, false.
        static bool TryOpenExisting(const String& name, Mutex& result);

      private:
        bool Signal() override {
          this->ReleaseMutex();
          return true;
        }

        bool Wait(int32 millisecondsTimeOut) override {
          if (this->mutex == null)
            throw ObjectDisposedException(caller_);
          if (millisecondsTimeOut < -1)
            throw ArgumentOutOfRangeException(caller_);
          if (millisecondsTimeOut == -1) {
            this->mutex->lock();
            return true;
          }
          return this->mutex->try_lock_for(std::chrono::milliseconds(millisecondsTimeOut));
        }

        refptr<std::recursive_timed_mutex> mutex = ref_new<std::recursive_timed_mutex>();
        refptr<string> name = ref_new<string>();
      };
    }
  }
}

using namespace Switch;
