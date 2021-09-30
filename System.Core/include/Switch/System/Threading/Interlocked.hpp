/// @file
/// @brief Contains Switch::System::Threading::Interlocked class.
#pragma once

#include <atomic>
#include <mutex>

#include "../../Static.hpp"
#include "../Object.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Provides atomic operations for variables that are shared by multiple threads.
      /// @remarks The methods of this class help protect against errors that can occur when the scheduler switches contexts while a thread is updating a variable that can be accessed by other threads, or when two threads are executing concurrently on separate processors. The members of this class do not throw exceptions.
      /// @remarks The Increment and Decrement methods increment or decrement a variable and store the resulting value in a single operation. On most computers, incrementing a variable is not an atomic operation, requiring the following steps:
      /// @remarks   1. Load a value from an instance variable into a register.
      /// @remarks   2. Increment or decrement the value.
      /// @remarks   3. Store the value in the instance variable.
      /// @remarks If you do not use Increment and Decrement, a thread can be preempted after executing the first two steps. Another thread can then execute all three steps. When the first thread resumes execution, it overwrites the value in the instance variable, and the effect of the increment or decrement performed by the second thread is lost.
      /// @remarks The Exchange method atomically exchanges the values of the specified variables. The CompareExchange method combines two operations: comparing two values and storing a third value in one of the variables, based on the outcome of the comparison. The compare and exchange operations are performed as an atomic operation.
      /// @par Examples
      /// The following code example shows a thread-safe resource locking mechanism.
      /// @include Interlocked.cpp
      class core_export_ Interlocked static_ {
      public:
        /// @brief Adds two 32-bit integers and replaces the first integer with the sum, as an atomic operation.
        /// @param location A variable containing the first value to be added. The sum of the two values is stored in location.
        /// @param value The value to be added to the integer at location.
        /// @return int32 The new value stored at location.
        static int32 Add(int32& location, int32 value);

        /// @brief Adds two 64-bit integers and replaces the first integer with the sum, as an atomic operation.
        /// @param location A variable containing the first value to be added. The sum of the two values is stored in location.
        /// @param value The value to be added to the integer at location.
        /// @return int64 The new value stored at location.
        static int64 Add(int64& location, int64 value);

        /// @brief Compares two Double for equality and, if they are equal, replaces one of the values.
        /// @param location The destination, whose value is compared with comparand and possibly replaced.
        /// @param value The value that replaces the destination value if the comparison results in equality.
        /// @param comparand The value that is compared to the value at location.
        /// @return The original value in location.
        static double CompareExchange(double& location, double value, double comparand);

        /// @brief Compares two 32-bit signed integers for equality and, if they are equal, replaces one of the values.
        /// @param location The destination, whose value is compared with Comparand and possibly replaced.
        /// @param value The value that replaces the destination value if the comparison results in equality.
        /// @param Comparand The value that is compared to the value at location.
        /// @return The original value in location.
        static int32 CompareExchange(int32& location, int32 value, int32 comparand);

        /// @brief Compares two 64-bit signed integers for equality and, if they are equal, replaces one of the values.
        /// @param location The destination, whose value is compared with comparand and possibly replaced.
        /// @param value The value that replaces the destination value if the comparison results in equality.
        /// @param comparand The value that is compared to the value at location.
        /// @return The original value in location.
        static int64 CompareExchange(int64& location, int64 value, int64 comparand);

        /// @cond
        static llong CompareExchange(llong& location, llong value, llong comparand);
        /// @endcond

        /// @brief Compares two platform-specific handles or pointers for equality and, if they are equal, replaces one of them.
        /// @param location The destination, whose value is compared with comparand and possibly replaced.
        /// @param value The value that replaces the destination value if the comparison results in equality.
        /// @param comparand The value that is compared to the value at location.
        /// @return The original value in location.
        static void* CompareExchange(void*& location, void* value, void* comparand);

        /// @brief Compares two Objects for equality and, if they are equal, replaces one of them.
        /// @param location The destination, whose value is compared with comparand and possibly replaced.
        /// @param value The value that replaces the destination value if the comparison results in equality.
        /// @param comparand The value that is compared to the value at location.
        /// @return The original value in location.
        template<typename T>
        static T CompareExchange(object& location, const object& value, const object& comparand) {
          T retValue = location;
          std::lock_guard<std::mutex> lock(guard);
          if (location == comparand)
            location = value;
          return retValue;
        }

        /// @brief Compares two instances of the specified reference type T for equality and, if they are equal, replaces one of them.
        /// @param location The destination, whose value is compared with comparand and possibly replaced.
        /// @param value The value that replaces the destination value if the comparison results in equality.
        /// @param comparand The value that is compared to the value at location.
        /// @return The original value in location.
        template<typename T>
        static T CompareExchange(T& location, T value, T comparand) {
          T retValue = location;
          std::lock_guard<std::mutex> lock(guard);
          if (location == comparand)
            location = value;
          return retValue;
        }

        /// @brief Compares two Single for equality and, if they are equal, replaces one of the values.
        /// @param location The destination, whose value is compared with comparand and possibly replaced.
        /// @param value The value that replaces the destination value if the comparison results in equality.
        /// @param comparand The value that is compared to the value at location.
        /// @return The original value in location.
        static float CompareExchange(float& location, float value, float comparand);

        /// @brief Decrements a specified variable and stores the result, as an atomic operation.
        /// @param location The variable whose value is to be decremented.
        /// @return The decremented value.
        /// @par Examples
        /// The following code example shows a thread-safe way to increment and decrement an integer value. SafeInstanceCount will always be zero. However, UnsafeInstanceCount will not necessarily be zero because a race condition occurs between incrementing and decrementing the count. This effect is especially marked on a multiprocessor computer.
        /// @include Interlocked.Decrement.cpp
        static int32 Decrement(int32& location);

        /// @brief Decrements a specified variable and stores the result, as an atomic operation.
        /// @param location The variable whose value is to be decremented.
        /// @return The decremented value.
        static int64 Decrement(int64& location);

        /// @brief Sets a variable of the specified type T to a specified value and returns the original value, as an atomic operation.
        /// @param location The variable to set to the specified value.
        /// @param value The value to which the location parameter is set.
        /// @return The original value of location.
        template<typename T>
        static T Exchange(T& location, T value) {
          T original = location;
          std::lock_guard<std::mutex> lock(guard);
          location = value;
          return original;
        }

        /// @brief Sets a double-precision floating point number to a specified value and returns the original value, as an atomic operation.
        /// @param location The variable to set to the specified value.
        /// @param value The value to which the location_d parameter is set.
        /// @return The original value of location_d.
        static double Exchange(double& location, double value);

        /// @brief Sets a 32-bit signed integer to a specified value and returns the original value, as an atomic operation.
        /// @param location The variable to set to the specified value.
        /// @param value The value to which the location parameter is set.
        /// @return The original value of location.
        static int32 Exchange(int32& location, int32 value);

        /// @brief Sets a 64-bit signed integer to a specified value and returns the original value, as an atomic operation.
        /// @param location The variable to set to the specified value.
        /// @param value The value to which the location parameter is set.
        /// @return The original value of location.
        static int64 Exchange(int64& location, int64 value);

        /// @cond
        static llong Exchange(llong& location, llong value);
        /// @endcond

        /// @brief Sets a platform-specific handles or pointers to a specified value and returns the original value, as an atomic operation.
        /// @param location The variable to set to the specified value.
        /// @param value The value to which the location parameter is set.
        /// @return The original value of location.
        static void* Exchange(void*& location, void* value);

        /// @brief Sets an object to a specified value and returns the original value, as an atomic operation.
        /// @param location The variable to set to the specified value.
        /// @param value The value to which the location parameter is set.
        /// @return The original value of location.
        template<typename T>
        static T Exchange(object& location, const object& value) {
          T original = location;
          std::lock_guard<std::mutex> lock(guard);
          location = value;
          return original;
        }

        /// @brief Sets a double-precision floating point number to a specified value and returns the original value, as an atomic operation.
        /// @param location The variable to set to the specified value.
        /// @param value The value to which the location_f parameter is set.
        /// @return The original value of location_f.
        static float Exchange(float& location, float value);

        /// @brief Increments a specified variable and stores the result, as an atomic operation.
        /// @param location The variable whose value is to be incremented.
        /// @return The incremented value.
        /// @par Examples
        /// The following code example shows a thread-safe way to increment and decrement an integer value. SafeInstanceCount will always be zero. However, UnsafeInstanceCount will not necessarily be zero because a race condition occurs between incrementing and decrementing the count. This effect is especially marked on a multiprocessor computer.
        /// @include Interlocked.Decrement.cpp
        static int32 Increment(int32& location);

        /// @brief Increments a specified variable and stores the result, as an atomic operation.
        /// @param location The variable whose value is to be incremented.
        /// @return The incremented value.
        static int64 Increment(int64& location);

        /// @brief Synchronizes memory access as follows: The processor that executes the current thread cannot reorder instructions in such a way that memory accesses before the call to MemoryBarrier execute after memory accesses that follow the call to MemoryBarrier.
        /// @remarks This method was added to the Interlocked class in the .NET Framework 4.5 as a convenience; it's a wrapper for the Thread.MemoryBarrier method.
        /// @remarks MemoryBarrier is required only on multiprocessor systems that have weak memory ordering (for example, a system that employs multiple Intel Itanium processors).
        /// @remarks For most purposes, the lock_ statement, or the Monitor class provide easier ways to synchronize data.
        static void MemoryBarrier();

        /// @brief Returns a 64-bit value, loaded as an atomic operation.
        /// @param location The 64-bit value to be loaded.
        /// @return The loaded value.
        static int64 Read(int64& location);

      private:
        /// @brief Represent The object used to create a lock section
        static std::mutex guard;
      };
    }
  }
}

using namespace Switch;
