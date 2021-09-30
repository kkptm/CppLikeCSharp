/// @file
/// @brief Contains Switch::System::Threading::WaitOrTimerCallback delegate.
#pragma once

#include "../Delegate.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Represents a method to be called when a WaitHandle is signaled or times out.
      using WaitOrTimerCallback = Delegate<void, Object&, bool>;
    }
  }
}

using namespace Switch;
