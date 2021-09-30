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
      /// @brief Specifies trace data options to be written to the trace output.
      /// @remarks This enumeration is used by trace listeners to determine which options, or elements, should be included in the trace output. Trace listeners store the trace options in the TraceOutputOptions property.
      /// @par Library
      /// Switch.System
      enum class TraceOptions {
        /// @brief Do not write any elements.
        None = 0,
        /// @brief Write the logical operation stack, which is represented by the return value of the CorrelationManager.LogicalOperationStack property.
        LogicalOperationStack = 0b1,
        /// @brief Write the date and time.
        DateTime = 0b10,
        /// @brief Write the timestamp, which is represented by the return value of the GetTimestamp method.
        Timestamp = 0b100,
        /// @brief Write the process identity, which is represented by the return value of the Process.Id property.
        ProcessId = 0b1000,
        /// @brief Write the thread identity, which is represented by the return value of the Thread.ManagedThreadId property for the current thread.
        ThreadId = 0b10000,
        /// @brief Write the call stack, which is represented by the return value of the Environment.StackTrace property.
        Callstack = 0b100000
      };
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Diagnostics::TraceOptions> : public TrueType {};

template<>
struct EnumRegister<System::Diagnostics::TraceOptions> {
  void operator()(System::Collections::Generic::IDictionary<System::Diagnostics::TraceOptions, string>& values, bool& flags) {
    values[System::Diagnostics::TraceOptions::None] = "None";
    values[System::Diagnostics::TraceOptions::LogicalOperationStack] = "LogicalOperationStack";
    values[System::Diagnostics::TraceOptions::DateTime] = "DateTime";
    values[System::Diagnostics::TraceOptions::Timestamp] = "Timestamp";
    values[System::Diagnostics::TraceOptions::ProcessId] = "ProcessId";
    values[System::Diagnostics::TraceOptions::ThreadId] = "ThreadId";
    values[System::Diagnostics::TraceOptions::Callstack] = "Callstack";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
