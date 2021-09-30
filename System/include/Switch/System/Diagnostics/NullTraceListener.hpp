/// @file
/// @brief Contains Switch::System::Diagnostics::NullTraceListener class.
#pragma once

#include "../../SystemExport.hpp"
#include "TraceListener.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Directs tracing or debugging output to either the standard output or the standard error stream.
      /// @par Library
      /// Switch.System
      class system_export_ NullTraceListener : public TraceListener {
      public:
        /// @brief Initializes a new instance of the ConsoleTraceListener class with trace output written to the standard output stream.
        /// @remarks This constructor initializes a ConsoleTraceListener object to write messages to either the Console.Out or the Console.Error stream. Its Name property is initialized to an empty string ("").
        NullTraceListener() {}

        /// @cond
        NullTraceListener(const NullTraceListener& ntl) : TraceListener(ntl) {}
        NullTraceListener& operator=(const NullTraceListener& ntl) {this->TraceListener::operator=(ntl); return *this;}
        /// @endcond

        void Write(const String& message) override {}
        void WriteLine(const String& message) override {}
      };
    }
  }
}

using namespace Switch;
