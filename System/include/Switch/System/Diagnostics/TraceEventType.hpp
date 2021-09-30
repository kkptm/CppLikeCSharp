/// @file
/// @brief Contains Switch::System::Diagnostics::TraceEventType class.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Identifies the type of event that has caused the trace.
      /// @par Library
      /// Switch.System
      /// @see Trace
      enum class TraceEventType {
        /// @brief Fatal error or application crash.
        Critical,
        /// @brief Recoverable error.
        Error,
        /// @brief Informational message.
        Information,
        /// @brief Resumption of a logical operation.
        Resume,
        /// @brief Starting of a logical operation.
        Start,
        /// @brief Stopping of a logical operation.
        Stop,
        /// @brief Suspension of a logical operation.
        Suspend,
        /// @brief Changing of correlation identity.
        Transfer,
        /// @brief Debugging trace.
        Verbose,
        /// @brief Warning Noncritical problem.
        Warning
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Diagnostics::TraceEventType> {
  void operator()(System::Collections::Generic::IDictionary<System::Diagnostics::TraceEventType, string>& values, bool& flags) {
    values[System::Diagnostics::TraceEventType::Critical] = "Critical";
    values[System::Diagnostics::TraceEventType::Error] = "Error";
    values[System::Diagnostics::TraceEventType::Information] = "Information";
    values[System::Diagnostics::TraceEventType::Resume] = "Resume";
    values[System::Diagnostics::TraceEventType::Start] = "Start";
    values[System::Diagnostics::TraceEventType::Stop] = "Stop";
    values[System::Diagnostics::TraceEventType::Suspend] = "Suspend";
    values[System::Diagnostics::TraceEventType::Transfer] = "Transfer";
    values[System::Diagnostics::TraceEventType::Verbose] = "Verbose";
    values[System::Diagnostics::TraceEventType::Warning] = "Warning";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
