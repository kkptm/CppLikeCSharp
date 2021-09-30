/// @file
/// @brief Contains Switch::System::Diagnostics::ConsoleTraceListener class.
#pragma once

#include "../../SystemExport.hpp"
#include "Switch/System/Console.hpp"
#include "TextWriterTraceListener.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Directs tracing or debugging output to either the standard output or the standard error stream.
      /// @par Library
      /// Switch.System
      class system_export_ ConsoleTraceListener : public TextWriterTraceListener {
      public:
        /// @brief Initializes a new instance of the ConsoleTraceListener class with trace output written to the standard output stream.
        /// @remarks This constructor initializes a ConsoleTraceListener object to write messages to either the Console.Out or the Console.Error stream. Its Name property is initialized to an empty string ("").
        ConsoleTraceListener() : TextWriterTraceListener(Console::Out()) {}

        /// @brief Initializes a new instance of the ConsoleTraceListener class with an option to write trace output to the standard output stream or the standard error stream.
        /// @param useErrorStream true to write tracing and debugging output to the standard error stream; false to write tracing and debugging output to the standard output stream.
        /// @remarks This constructor initializes a ConsoleTraceListener object to write messages to either the Console.Out or the Console.Error stream. Its Name property is initialized to an empty string ("").
        ConsoleTraceListener(bool useErrorStream) : TextWriterTraceListener(Console::Error()) {}

        /// @cond
        ConsoleTraceListener(const ConsoleTraceListener&) = default;
        ConsoleTraceListener& operator=(const ConsoleTraceListener&) = default;
        /// @endcond

        /// @brief When overridden in a derived class, closes the output stream so it no longer receives tracing or debugging output.
        /// @remarks Use this method when the output is going to a file, such as to the TextWriterTraceListener. After a call to this method, you must reinitialize the object.
        void Close() override {this->Writer().Flush();}
      };
    }
  }
}

using namespace Switch;
