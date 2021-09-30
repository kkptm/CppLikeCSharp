/// @file
/// @brief Contains Switch::System::Threading::EventResetMode enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @enum EventResetMode
      /// @brief Indicates whether an System::Threading::EventWaitHandle is reset automatically or manually after receiving a signal.
      /// @see EventWaitHandle
      enum class EventResetMode {
        /// @brief When signaled, the System::Threading::EventWaitHandle resets automatically after releasing a single thread. If no threads are waiting, the System::Threading::EventWaitHandle remains signaled until a thread blocks, and resets after releasing the thread.
        AutoReset,
        /// @brief When signaled, the System::Threading::EventWaitHandle releases all waiting threads and remains signaled until it is manually reset.
        ManualReset
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Threading::EventResetMode> {
  void operator()(System::Collections::Generic::IDictionary<System::Threading::EventResetMode, string>& values, bool& flags) {
    values[System::Threading::EventResetMode::AutoReset] = "AutoReset";
    values[System::Threading::EventResetMode::ManualReset] = "ManualReset";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
