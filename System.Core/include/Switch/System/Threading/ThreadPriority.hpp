/// @file
/// @brief Contains Switch::System::Threading::ThreadPriority enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Specifies the scheduling priority of a System::Threading::Thread.
      enum class ThreadPriority {
        /// @brief The System::Threading::Thread can be scheduled after threads with any other priority.
        Lowest = 0,
        /// @brief The System::Threading::Thread can be scheduled after threads with Normal priority and before those with Lowest priority.
        BelowNormal = 1,
        /// @brief The System::Threading::Thread can be scheduled after threads with AboveNormal priority and before those with BelowNormal priority. Threads have Normal priority by default.
        Normal = 2,
        /// @brief The System::Threading::Thread can be scheduled after threads with Highest priority and before those with Normal priority.
        AboveNormal = 3,
        /// @brief The System::Threading::Thread can be scheduled before threads with any other priority.
        Highest = 4
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Threading::ThreadPriority> {
  void operator()(System::Collections::Generic::IDictionary<System::Threading::ThreadPriority, string>& values, bool& flags) {
    values[System::Threading::ThreadPriority::Lowest] = "Lowest";
    values[System::Threading::ThreadPriority::BelowNormal] = "BelowNormal";
    values[System::Threading::ThreadPriority::Normal] = "Normal";
    values[System::Threading::ThreadPriority::AboveNormal] = "AboveNormal";
    values[System::Threading::ThreadPriority::Highest] = "Highest";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
