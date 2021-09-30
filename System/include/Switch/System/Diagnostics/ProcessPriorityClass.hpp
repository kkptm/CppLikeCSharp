/// @file
/// @brief Contains Switch::System::Diagnostics::TraceOptions enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Indicates the priority that the system associates with a process. This value, together with the priority value of each thread of the process, determines each thread's base priority level.
      /// @remarks A process priority class encompasses a range of thread priority levels. Threads with different priorities running in the process run relative to the process's priority class. The operating system uses the base-priority level of all executable threads to determine which thread gets the next slice of processor time.
      /// @remarks Win32 uses four priority classes with seven base priority levels per class. Based on time elapsed or other boosts, the operating system can change the base priority level when a process needs to be put ahead of others for access to the processor. In addition, you can set PriorityBoostEnabled to temporarily boost the priority level of threads that have been taken out of the wait state. The priority is reset when the process returns to the wait state.
      /// @par Library
      /// Switch.System
      enum class ProcessPriorityClass {
        /// @brief Specifies that the process has no special scheduling needs.
        Normal = 32,
        /// @brief Specifies that the threads of this process run only when the system is idle, such as a screen saver. The threads of the process are preempted by the threads of any process running in a higher priority class.
        Idle = 64,
        /// @brief Specifies that the process performs time-critical tasks that must be executed immediately, such as the Task List dialog, which must respond quickly when called by the user, regardless of the load on the operating system. The threads of the process preempt the threads of normal or idle priority class processes.
        High = 128,
        /// @brief Specifies that the process has the highest possible priority.
        RealTime = 256,
        /// @brief Specifies that the process has priority above Idle but below Normal.
        BelowNormal = 16384,
        /// @brief Specifies that the process has priority above Normal but below High.
        AboveNormal = 32768
      };
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Diagnostics::ProcessPriorityClass> : public TrueType {};

template<>
struct EnumRegister<System::Diagnostics::ProcessPriorityClass> {
  void operator()(System::Collections::Generic::IDictionary<System::Diagnostics::ProcessPriorityClass, string>& values, bool& flags) {
    values[System::Diagnostics::ProcessPriorityClass::Normal] = "Normal";
    values[System::Diagnostics::ProcessPriorityClass::Idle] = "Idle";
    values[System::Diagnostics::ProcessPriorityClass::High] = "High";
    values[System::Diagnostics::ProcessPriorityClass::BelowNormal] = "BelowNormal";
    values[System::Diagnostics::ProcessPriorityClass::AboveNormal] = "AboveNormal";
    values[(int64)System::Diagnostics::TraceOptions::ThreadId] = "ThreadId";
    values[(int64)System::Diagnostics::TraceOptions::Callstack] = "Callstack";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
