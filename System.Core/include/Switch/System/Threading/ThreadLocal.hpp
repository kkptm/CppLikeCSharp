/// @file
/// @brief Contains Switch::System::Threading::ThreadLocal class.
#pragma once

#include <functional>
#include <memory>
#include <sstream>
#include <thread>

#include "../../Types.hpp"
#include "../Collections/Generic/Dictionary.hpp"
#include "Thread.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Provides thread-local storage of data.
      /// @par Examples
      /// The following example shows how to use ThreadLocal<T>:
      /// @include ThreadLocal.cpp
      template <class T>
      struct ThreadLocal : public object {
      public:
        /// @brief nitializes the ThreadLocal<T> instance.
        /// @remarks The default value of T is used to initialize the instance when Value is accessed for the first time.
        /// @remarks This constructor is equivalent to calling the ThreadLocal<T>(Boolean) constructor with a value of false for the trackAllValues argument.
        ThreadLocal() {}

        /// @brief Initializes the ThreadLocal<T> instance and specifies whether all values are accessible from any thread.
        /// @param trackAllValues) true to track all values set on the instance and expose them through the Values property; false otherwise.
        /// @remarks If trackAllValues is false, only the value of this instance for the current thread is accessible. Attempting to use the Values property to retrieve all values throws an InvalidOperationException exception.
        ThreadLocal(bool trackAllValues) : trackAllValues(trackAllValues) {}

        /// @brief Initializes the ThreadLocal<T> instance with the specified valueFactory function.
        /// @param valueFactory The System.Func<TResult> invoked to produce a lazily-initialized value when an attempt is made to retrieve Value without it having been previously initialized.
        ThreadLocal(const Func<T>& valueFactory) {this->valueFactory = valueFactory;}

        /// @brief Initializes the ThreadLocal<T> instance with the specified valueFactory function and a flag that indicates whether all values are accessible from any thread.
        /// @param valueFactory The System.Func<TResult> invoked to produce a lazily-initialized value when an attempt is made to retrieve Value without it having been previously initialized.
        /// @param trackAllValues) true to track all values set on the instance and expose them through the Values property; false otherwise.
        ThreadLocal(const Func<T>& valueFactory, bool trackAllValues) : trackAllValues(trackAllValues) {this->valueFactory = valueFactory;}

        /// @cond
        ThreadLocal(const ThreadLocal& value) : values(value.values), trackAllValues(value.trackAllValues) {this->valueFactory = value.valueFactory;}

        ThreadLocal& operator =(const ThreadLocal& value) {
          this->values = value.values;
          this->valueFactory = value.valueFactory;
          this->trackAllValues = value.trackAllValues;
          return *this;
        }
        /// @endcond

        /// @brief Gets whether Value is initialized on the current thread.
        /// @return true if Value is initialized on the current thread; otherwise false.
        property_<bool, readonly_> IsValueCreated {
          get_ {return this->values.ContainsKey(Thread::CurrentThread().ManagedThreadId);}
        };

        /// @brief Gets or sets the value of this instance for the current thread.
        /// @return Returns an instance of the object that this ThreadLocal is responsible for initializing.
        property_<T> Value {
          get_ {return this->GetValue();},
          set_ {this->SetValue(value);}
        };

        /// @brief Gets a list for all of the values currently stored by all of the threads that have accessed this instance.
        /// @return A array for all of the values currently stored by all of the threads that have accessed this instance.
        /// @exception InvalidOperationException Values stored by all threads are not available because this instance was initialized with the trackAllValues argument set to false in the call to a class constructor.
        property_<Array<T>, readonly_> Values {
          get_ {return this->GetValues();}
        };

        /// @brief Creates and returns a string representation of this instance for the current thread
        /// @return The result of calling ToString on the Value.
        String ToString() const override {return string::Format("{0}", this->Value());}

      private:
        const T& GetValue() const {
          lock_(this->values.SyncRoot) {
            if (!this->valueFactory.IsEmpty() && !this->IsValueCreated)
              this->values[Thread::CurrentThread().ManagedThreadId] = this->valueFactory();
            return this->values[Thread::CurrentThread().ManagedThreadId];
          }
          return this->values[Thread::CurrentThread().ManagedThreadId];
        }

        void SetValue(const T& value) {
          lock_(this->values.SyncRoot) {
            this->values[Thread::CurrentThread().ManagedThreadId] = value;
          }
        }

        Array<T> GetValues() const {
          if (!trackAllValues)
            throw InvalidOperationException(caller_);
          lock_(this->values.SyncRoot) {
            return Array<T>(this->values.Values());
          }
          return Array<T>(this->values.Values());
        }

        mutable System::Collections::Generic::Dictionary<int32, T> values;
        Func<T> valueFactory;
        bool trackAllValues = false;
      };
    }
  }
}

using namespace Switch;
