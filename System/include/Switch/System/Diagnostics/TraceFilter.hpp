/// @file
/// @brief Contains Switch::System::Diagnostics::TraceFilter class.
#pragma once

#include <Switch/Abstract.hpp>
#include "../../SystemExport.hpp"
#include "TraceEventCache.hpp"
#include "TraceEventType.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides the base class for trace filter implementations.
      /// @par Library
      /// Switch.System
      class system_export_ TraceFilter abstract_ {
      public:
        /// @brief Initializes a new instance of the TraceFilter class.
        TraceFilter() {}

        /// @brief When overridden in a derived class, determines whether the trace listener should trace the event.
        /// @param cache The TraceEventCache that contains information for the trace event.
        /// @param source The name of the source.
        /// @param eventType One of the TraceEventType values specifying the type of event that has caused the trace.
        /// @param id A trace identifier number.
        /// @param formatOrMessage Either the format to use for writing an array of arguments specified by the args parameter, or a message to write.
        /// @param args An array of argument objects.
        /// @param data1 A trace data object.
        /// @param data An array of trace data objects.
        /// @return true to trace the specified event; otherwise, false.
        /// @remarks Implementations of this method should return true if the event specified by the passed parameters should be traced. Otherwise the method should return false. For example, a filter that allows only error events to pass through to the listener should inspect the eventType parameter and return true if the trace event type level is set to TraceEventType.Error or greater; otherwise, it should return false.
        /// @remarks Implementations of the method should be prepared to handle null in the following parameters: args, data1, data, formatOrMessage, and cache. If the parameter value is null, the parameter is not part of the event. For example, if the args parameter is null, it means that the event does not have any arguments. If the data parameter is null, then there are either one or no data objects. If there is one data object, it will be found in the data1 parameter. The reason for the distinction between a single data object and an array of data objects is for performance. There is no reason to create an object array if only one object is traced, as is normally the case. If the data parameter is not null, the data1 parameter must also not be null.
        /// @remarks It is guaranteed that the source parameter is not null and not an empty string ("").
        /// @remarks Implementations of the method can optionally throw the following exceptions:
        ///  * ArgumentNullException if source is null.
        ///  * ArgumentException if eventType is not one of the TraceEventType values.
        ///  * Exceptions unrelated to the implementation of the method. For example, a ThreadAbortException.
        virtual bool ShouldTrace(const TraceEventCache& cache, const string& source, const TraceEventType& eventType, int id, const string& formatOrMessage, const Array<any>& args, const object& data1, const Array<any>& data) = 0;
      };
    }
  }
}

using namespace Switch;
