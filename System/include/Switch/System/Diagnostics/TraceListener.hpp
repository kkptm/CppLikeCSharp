/// @file
/// @brief Contains Switch::System::Diagnostics::TraceListener class.
#pragma once

#include <Switch/Abstract.hpp>
#include <Switch/Types.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/Guid.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Collections/ArrayList.hpp>
#include "../../SystemExport.hpp"
#include "../Collections/Specialized/StringDictionary.hpp"
#include "TraceEventCache.hpp"
#include "TraceEventType.hpp"
#include "TraceOptions.hpp"
#include "TraceFilter.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides the abstract base class for the listeners who monitor trace and debug output.
      /// @remarks For examples of how to implement a TraceListener, see the DefaultTraceListener, TextWriterTraceListener and the EventLogTraceListener classes.
      /// @remarks You must enable tracing or debugging to use a trace listener. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build nanager.
      ///  * To enable debugging with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your porject, or you can add #define DEBUG to the top of your file but in this case, the compiler options for debug is not activated.
      ///  * To enable tracing with cmake, add the add_definitions(-DTRACE) command line in the CMakeLists.txt of your porject, or you can add #define TRACE to the top of your file.
      /// @note <b>to Inheritors:</b> Inherit from this class to implement a custom listener for the Debug and Trace classes. At a minimum, you must implement the Write and WriteLine methods. Additionally, you can implement the Fail, Close and Flush methods.
      /// @par Library
      /// Switch.System
      class system_export_ TraceListener abstract_ {
      public:
        /// @brief Initializes a new instance of the TraceListener class.
        /// @remarks The following table shows initial property values for an instance of TraceListener.
        /// | Property    | Default Value          |
        /// |-------------|------------------------|
        /// | Name        | The empty string (""). |
        /// | IndentLevel | Zero.                  |
        /// | IndentSize  | Four spaces.           |
        TraceListener() {}

        /// @cond
        TraceListener(const TraceListener& tl) : data(tl.data) {};
        TraceListener& operator=(const TraceListener& tl) {this->data = tl.data; return *this;};
        /// @endcond

        /// @brief Initializes a new instance of the TraceListener class using the specified name as the listener.
        /// @param name The name of the TraceListener.
        explicit TraceListener(const string& name) {this->data->name = name;}

        /// @brief Gets the custom trace listener attributes defined in the application configuration file.
        /// @return A StringDictionary containing the custom attributes for the trace listener.
        /// @remarks Classes that inherit from the TraceListener class can add custom attributes by overriding the GetSupportedAttributes method and returning a string array of custom attribute names. The Attributes property identifies the custom attributes that are referenced in the application's configuration file. For example, in the following configuration file excerpt the DelimitedListTraceListener custom attribute "delimiter" is referenced. In this case, the Attributes property returns a StringDictionary containing the string "delimiter".
        property_<const Collections::Specialized::StringDictionary&, readonly_> Attributes {
          get_->const Collections::Specialized::StringDictionary& {return this->data->attibutes;}
        };

        property_<const TraceFilter&> Filter {
          get_->const TraceFilter& {return *this->data->filter;},
          set_ {this->data->filter = &value;}
        };

        /// @brief Gets or sets the indent level.
        /// @return int32 The indent level. The default is zero.
        /// @remarks The IndentLevel property represents the number of times that the indent specified by the IndentSize property is applied. This property is stored on per-thread/per-request basis.
        property_<int32> IndentLevel {
          get_ {return this->data->indentLevel;},
          set_ {this->data->indentLevel = value;}
        };

        /// @brief Gets or sets the number of spaces in an indent.
        /// @return int32 The number of spaces in an indent. The default is four spaces.
        /// @exception ArgumentOutOfRangeException Set operation failed because the value is less than zero.
        /// @remarks The property is stored on per-thread/per-request basis.
        property_<int32> IndentSize {
          get_ {return this->data->indentSize;},
          set_ {
            if (value < 0)
              throw ArgumentOutOfRangeException(caller_);
            this->data->indentSize = value;
          }
        };

        /// @brief Gets a value indicating whether the trace listener is thread safe.
        /// @return bool true if the trace listener is thread safe; otherwise, false. The default is false.
        /// @remarks The value of IsThreadSafe is used to determine whether to use a global lock when writing to the listener. If the value of IsThreadSafe is false, the global lock is used regardless of the value of UseGlobalLock. The global lock is not used only if the value of IsThreadSafe is true and the value of UseGlobalLock is false. The default behavior is to use the global lock whenever writing to the listener.
        property_<bool, readonly_> IsThreadSafe {
          get_ {return this->data->isThreadSafe;}
        };

        /// @brief Gets or sets a name for this TraceListener.
        /// @return string A name for this TraceListener. The default is an empty string ("").
        /// @remarks The name can be used to organize and access listeners in a TraceListenerCollection collection.
        property_<string> Name {
          get_ {return this->data->name;},
          set_ {this->data->name = value;}
        };

        /// @brief Gets or sets the trace output options.
        /// @return TraceOptions A bitwise combination of the enumeration values. The default is None.
        /// @remarks The TraceOutputOptions property determines the optional content of trace output. The property can be set in the configuration file or programmatically during execution to include additional data specifically for a section of code. For example, you can set the TraceOutputOptions property for the console trace listener to TraceOptions.Callstack to add call stack information to the trace output.
        /// @remarks The TraceOptions enumeration is not used by the following classes and methods:
        /// * The EventLogTraceListener class, because it can cause a large volume of data to be written to the log.
        /// * The Write and WriteLine methods of the ConsoleTraceListener, DefaultTraceListener, and TextWriterTraceListener classes.
        /// * The Write and WriteLine methods of the TraceListener class when they are not overridden in a derived class.
        property_<TraceOptions> TraceOutputOptions {
          get_ {return this->data->traceOutputOptions;},
          set_ {this->data->traceOutputOptions = value;}
        };

        /// @brief When overridden in a derived class, closes the output stream so it no longer receives tracing or debugging output.
        /// @remarks Use this method when the output is going to a file, such as to the TextWriterTraceListener. After a call to this method, you must reinitialize the object.
        virtual void Close() {this->Flush();}

        /// @brief Emits an error message to the listener you create when you implement the TraceListener class.
        /// @param message A message to emit.
        /// @remarks The default behavior is to display the specified message in a message box when the application is running in a user-interface mode, and to the TraceListener instances in a TraceListenerCollection collection. By default, the TraceListenerCollection collection has an instance of a DefaultTraceListener. You can customize this behavior by adding a TraceListener to or removing one from the collection.
        virtual void Fail(const string& message) {WriteLine(string::Format("Fail: {0}", message));}

        /// @brief Emits the specified error message.
        /// @param message A message to emit.
        /// @param detailMessage A detailed message to emit.
        /// @remarks The default behavior is to display the message and detailed message in a message box when the application is running in a user-interface mode, and to the TraceListener instances in a TraceListenerCollection collection. By default, the TraceListenerCollection collection has an instance of a DefaultTraceListener. You can customize this behavior by adding a TraceListener to or removing one from the collection.
        virtual void Fail(const string& message, const string& detailMessage) {WriteLine(string::Format("Fail: {0} {1}", message, detailMessage));}

        /// @brief When overridden in a derived class, flushes the output buffer.
        virtual void Flush() {}

        /// @brief Writes trace information, a data object and event information to the listener specific output.
        /// @param eventCache A TraceEventCache object that contains the current process ID, thread ID, and stack trace information.
        /// @param source A name used to identify the output, typically the name of the application that generated the trace event.
        /// @param eventType One of the TraceEventType values specifying the type of event that has caused the trace.
        /// @param id A numeric identifier for the event.
        /// @param data The trace data to emit.
        /// @remarks <b>Important</b> This method is not intended to be called directly by application code but by members of the Debug, Trace, and TraceSource classes to write trace data to output.
        /// @remarks The default implementation writes the eventCache, source, eventType and id parameters in the header and footer of the trace. The data parameter is written as the body of the trace message. The ToString method of the data object is used to convert the object to a String.
        template<typename Object>
        void TraceData(const TraceEventCache& eventCache, const string& source, const TraceEventType& eventType, int32 id, const Object& data) {
          this->WriteLine(string::Format("{0} {1}: {2} : {3}", source, eventType, id, data));
          this->WriteEventCache(eventCache);
        }

        /// @brief Writes trace information, a data object and event information to the listener specific output.
        /// @param eventCache A TraceEventCache object that contains the current process ID, thread ID, and stack trace information.
        /// @param source A name used to identify the output, typically the name of the application that generated the trace event.
        /// @param eventType One of the TraceEventType values specifying the type of event that has caused the trace.
        /// @param id A numeric identifier for the event.
        /// @param data The trace data to emit.
        /// @remarks <b>Important</b> This method is not intended to be called directly by application code but by members of the Debug, Trace, and TraceSource classes to write trace data to output.
        /// @remarks The default implementation writes the eventCache, source, eventType and id parameters in the header and footer of the trace. The data parameter is written as the body of the trace message. The ToString method of the data object is used to convert the object to a String.
        template<typename Object>
        void TraceData(const TraceEventCache& eventCache, const string& source, const TraceEventType& eventType, int32 id, const Array<Object>& data) {
          this->WriteLine(string::Format("{0} {1}: {2} : {3}", source, eventType, id, data));
          this->WriteEventCache(eventCache);
        }

        /// @brief Writes trace information, a data object and event information to the listener specific output.
        /// @param eventCache A TraceEventCache object that contains the current process ID, thread ID, and stack trace information.
        /// @param source A name used to identify the output, typically the name of the application that generated the trace event.
        /// @param eventType One of the TraceEventType values specifying the type of event that has caused the trace.
        /// @param id A numeric identifier for the event.
        /// @param data The trace data to emit.
        /// @remarks <b>Important</b> This method is not intended to be called directly by application code but by members of the Debug, Trace, and TraceSource classes to write trace data to output.
        /// @remarks The default implementation writes the eventCache, source, eventType and id parameters in the header and footer of the trace. The data parameter is written as the body of the trace message. The ToString method of the data object is used to convert the object to a String.
        virtual void TraceData(const TraceEventCache& eventCache, const string& source, const TraceEventType& eventType, int32 id, const Object& data) {
          this->WriteLine(string::Format("{0} {1}: {2} : {3}", source, eventType, id, data));
          this->WriteEventCache(eventCache);
        }

        /// @brief Writes trace information, an array of data objects and event information to the listener specific output.
        /// @param eventCache A TraceEventCache object that contains the current process ID, thread ID, and stack trace information.
        /// @param source A name used to identify the output, typically the name of the application that generated the trace event.
        /// @param eventType One of the TraceEventType values specifying the type of event that has caused the trace.
        /// @param id A numeric identifier for the event.
        /// @param data An array of objects to emit as data.
        /// @remarks <b>Important</b> This method is not intended to be called directly by application code but by members of the Debug, Trace, and TraceSource classes to write trace data to output.
        /// @remarks The default implementation writes the eventCache, source, eventType and id parameters in the header and footer of the trace. The data parameter is written as the body of the trace message. The ToString method of the data object is used to convert the object to a String.
        template<typename ...Objects>
        void TraceData(const TraceEventCache& eventCache, const string& source, const TraceEventType& eventType, int32 id, const Objects& ... data) {
          this->WriteLine(string::Format("{0} {1}: {2} : {3}", source, eventType, id, String::Join(", ", {data...})));
          this->WriteEventCache(eventCache);
        }

        /// @brief Writes trace information, an array of data objects and event information to the listener specific output.
        /// @param eventCache A TraceEventCache object that contains the current process ID, thread ID, and stack trace information.
        /// @param source A name used to identify the output, typically the name of the application that generated the trace event.
        /// @param eventType One of the TraceEventType values specifying the type of event that has caused the trace.
        /// @param id A numeric identifier for the event.
        /// @param data An array of objects to emit as data.
        /// @remarks <b>Important</b> This method is not intended to be called directly by application code but by members of the Debug, Trace, and TraceSource classes to write trace data to output.
        /// @remarks The default implementation writes the eventCache, source, eventType and id parameters in the header and footer of the trace. The data parameter is written as the body of the trace message. The ToString method of the data object is used to convert the object to a String.
        virtual void TraceData(const TraceEventCache& eventCache, const string& source, const TraceEventType& eventType, int32 id, const Collections::ArrayList& data) {
          this->WriteLine(string::Format("{0} {1}: {2} : {3}", source, eventType, id, String::Join(", ", data)));
          this->WriteEventCache(eventCache);
        }

        /// @brief Writes trace and event information to the listener specific output.
        /// @param eventCache A TraceEventCache object that contains the current process ID, thread ID, and stack trace information.
        /// @param source A name used to identify the output, typically the name of the application that generated the trace event.
        /// @param eventType One of the TraceEventType values specifying the type of event that has caused the trace.
        /// @param id A numeric identifier for the event.
        /// @remarks <b>Important</b> This method is not intended to be called directly by application code but by members of the Debug, Trace, and TraceSource classes to write trace data to output.
        /// @remarks The default implementation writes the values of the source, eventType and id parameters as a header. The eventCache data is written as a footer, the nature of the output data being dependent on the value of the TraceOutputOptions property.
        virtual void TraceEvent(const TraceEventCache& eventCache, const string& source, const TraceEventType& eventType, int32 id) {
          this->WriteLine(string::Format("{0} {1}: {2}", source, eventType, id));
          this->WriteEventCache(eventCache);
        }

        /// @brief Writes trace information, a message, and event information to the listener specific output.
        /// @param eventCache A TraceEventCache object that contains the current process ID, thread ID, and stack trace information.
        /// @param source A name used to identify the output, typically the name of the application that generated the trace event.
        /// @param eventType One of the TraceEventType values specifying the type of event that has caused the trace.
        /// @param id A numeric identifier for the event.
        /// @param message A message to write.
        /// @remarks <b>Important</b> This method is not intended to be called directly by application code but by members of the Debug, Trace, and TraceSource classes to write trace data to output.
        /// @remarks The default implementation writes the values of the source, eventType and id parameters as a header. The eventCache data is written as a footer, the nature of the output data being dependent on the value of the TraceOutputOptions property.
        virtual void TraceEvent(const TraceEventCache& eventCache, const string& source, const TraceEventType& eventType, int32 id, const string& message) {
          this->WriteLine(string::Format("{0} {1}: {2} : {3}", source, eventType, id, message));
          this->WriteEventCache(eventCache);
        }

        /// @brief Writes trace information, a formatted array of objects and event information to the listener specific output.
        /// @param eventCache A TraceEventCache object that contains the current process ID, thread ID, and stack trace information.
        /// @param source A name used to identify the output, typically the name of the application that generated the trace event.
        /// @param eventType One of the TraceEventType values specifying the type of event that has caused the trace.
        /// @param id A numeric identifier for the event.
        /// @param format A format string that contains zero or more format items, which correspond to objects in the args array.
        /// @param args An object array containing zero or more objects to format.
        /// @remarks <b>Important</b> This method is not intended to be called directly by application code but by members of the Debug, Trace, and TraceSource classes to write trace data to output.
        /// @remarks The default implementation writes the values of the source, eventType and id parameters as a header. The args object array is converted to a string using the Format method, passing the format string and args array to format the string as the message portion of the trace. The eventCache data is written as a footer, the nature of the output data being dependent on the value of the TraceOutputOptions property.
        template<typename ...Objects>
        void TraceEvent(const TraceEventCache& eventCache, const string& source, const TraceEventType& eventType, int32 id, const string& format, const Objects& ... args) {
          this->WriteLine(string::Format("{0} {1}: {2} : {3}", source, eventType, id, string::Format(format, args...)));
          this->WriteEventCache(eventCache);
        }

        /// @brief Writes trace information, a formatted array of objects and event information to the listener specific output.
        /// @param eventCache A TraceEventCache object that contains the current process ID, thread ID, and stack trace information.
        /// @param source A name used to identify the output, typically the name of the application that generated the trace event.
        /// @param eventType One of the TraceEventType values specifying the type of event that has caused the trace.
        /// @param id A numeric identifier for the event.
        /// @param format A format string that contains zero or more format items, which correspond to objects in the args array.
        /// @param args An object array containing zero or more objects to format.
        /// @remarks <b>Important</b> This method is not intended to be called directly by application code but by members of the Debug, Trace, and TraceSource classes to write trace data to output.
        /// @remarks The default implementation writes the values of the source, eventType and id parameters as a header. The args object array is converted to a string using the Format method, passing the format string and args array to format the string as the message portion of the trace. The eventCache data is written as a footer, the nature of the output data being dependent on the value of the TraceOutputOptions property.
        void TraceEvent(const TraceEventCache& eventCache, const string& source, const TraceEventType& eventType, int32 id, const string& format, const System::Collections::ArrayList& args) {
          this->WriteLine(string::Format("{0} {1}: {2} : {3}", source, eventType, id, string::Format(format, args)));
          this->WriteEventCache(eventCache);
        }

        /// @brief Writes trace information, a message, a related activity identity and event information to the listener specific output.
        /// @param eventCache A TraceEventCache object that contains the current process ID, thread ID, and stack trace information.
        /// @param source A name used to identify the output, typically the name of the application that generated the trace event.
        /// @param id A numeric identifier for the event.
        /// @param message A message to write.
        /// @param relatedActivityId A Guid object identifying a related activity.
        /// @remarks <b>Important</b> This method is not intended to be called directly by application code but by members of the Debug, Trace, and TraceSource classes to write trace data to output.
        /// @remarks The TraceTransfer method is used for the correlation of related traces. The TraceTransfer method calls the TraceEvent method to process the call, with the eventType level set to Transfer and the relatedActivityIdGuid as a string appended to the message.
        virtual void TraceTransfert(const TraceEventCache& eventCache, const string& source, int32 id, const string& message, const Guid& relatedActivityId) {
          this->WriteLine(string::Format("{0} Transfert: {1} : {2}, relatedActivityId={3}", source, id, message, relatedActivityId));
          this->WriteEventCache(eventCache);
        }

        /// @brief Writes the value of the object's ToString method to the listener you create when you implement the TraceListener class.
        /// @param o An Object whose fully qualified class name you want to write.
        virtual void Write(const Object& o) {Write(o.ToString());}

        /// @brief Writes a category name and the value of the object's ToString method to the listener you create when you implement the TraceListener class.
        /// @param o An Object whose fully qualified class name you want to write.
        /// @param category A category name used to organize the output.
        virtual void Write(const Object& o, const string& category) {Write(o.ToString(), category);}

        /// @brief When overridden in a derived class, writes the specified msg to the listener you create in the derived class.
        /// @param message A message to write.
        /// @note <b>to Inheritors:</b> When inheriting from this class, you must implement this method. To support an indentation, you should call WriteIndent if NeedIndent is true. If you need to indent the following line, you must reset NeedIndent to true.
        virtual void Write(const string& message) = 0;

        /// @brief Writes a category name and a msg to the listener you create when you implement the TraceListener class.
        /// @param message A message to write.
        /// @param category  A category name used to organize the output.
        virtual void Write(const string& message, const string& category) {WriteLine(string::Format("{0}: {1}", category, message));}

        /// @brief Writes the value of the object's ToString method to the listener you create when you implement the TraceListener class, followed by a line terminator.
        /// @param o An Object whose fully qualified class name you want to write.
        /// @remarks The typical line terminator you might implement is a carriage return followed by a line feed (\r\n).
        virtual void WriteLine(const Object& o) {WriteLine(o.ToString());}

        /// @brief Writes a category name and the value of the object's ToString method to the listener you create when you implement the TraceListener class, followed by a line terminator.
        /// @param o An Object whose fully qualified class name you want to write.
        /// @param category A category name used to organize the output.
        /// @remarks The typical line terminator you might implement is a carriage return followed by a line feed (\r\n).
        virtual void WriteLine(const Object& o, const string& category) {WriteLine(o.ToString(), category);}

        /// @brief When overridden in a derived class, writes a message to the listener you create in the derived class, followed by a line terminator.
        /// @param message A message to write.
        /// @remarks The typical line terminator you might implement is a carriage return followed by a line feed (\r\n).
        /// @note <b>to Inheritors:</b> When inheriting from this class, you must implement this method. To support an indentation, call WriteIndent if NeedIndent is true. To indent the following line, you must reset NeedIndent to true.
        virtual void WriteLine(const string& message) = 0;

        /// @brief Writes a category name and a msg to the listener you create when you implement the TraceListener class, followed by a line terminator.
        /// @param message A message to write.
        /// @param category A category name used to organize the output.
        /// @remarks The typical line terminator you might implement is a carriage return followed by a line feed (\r\n).
        virtual void WriteLine(const string& message, const string& category) {WriteLine(string::Format("{0}: {1}", category, message));}

      protected:
        /// @brief Gets or sets a value indicating whether to indent the output.
        /// @return bool true if the output should be indented; otherwise, false.
        /// @remarks The WriteIndent method, called by the DefaultTraceListener and TextWriterTraceListener classes, sets the NeedIndent property value to false to prevent later, unnecessary indents. You must set the NeedIndent property to true each time you wish to indent trace output.
        property_<bool> NeedIndent {
          get_ {return this->data->needIndent;},
          set_ {this->data->needIndent = value;}
        };

        /// @brief Writes the indent to the listener you create when you implement this class, and resets the NeedIndent property to false.
        /// @remarks This method writes the indent and resets the NeedIndent property to false. Call this method if NeedIndent is true when you are overriding the Write and WriteLine methods. By default, this method uses blank spaces for indentation. The size of the indent is determined by the values of the IndentSize and IndentLevel properties. The IndentLevel property represents the number of times the indent of the size specified by the IndentSize property is applied. This method is called by the DefaultTraceListener and TextWriterTraceListener classes.
        virtual void WriteIndent() {
          this->data->needIndent = false;
          for (int32 i = 0; i < this->data->indentLevel; ++i)
            this->Write(String(' ', this->data->indentSize));
        }

      private:
        void WriteEventCache(const TraceEventCache& eventCache) {
          if (Enum<TraceOptions>(this->data->traceOutputOptions).HasFlag(TraceOptions::ProcessId))
            WriteLine(string::Format("{0}ProcessId={1}", String(' ', this->data->indentSize), eventCache.ProcessdId));
          if (Enum<TraceOptions>(this->data->traceOutputOptions).HasFlag(TraceOptions::LogicalOperationStack))
            WriteLine(string::Format("{0}LogicalOperationStack={1}", String(' ', this->data->indentSize), string::Join(", ", eventCache.LogicalOperationStack())));
          if (Enum<TraceOptions>(this->data->traceOutputOptions).HasFlag(TraceOptions::ThreadId))
            WriteLine(string::Format("{0}ThreadId={1}", String(' ', this->data->indentSize), eventCache.ThreadId));
          if (Enum<TraceOptions>(this->data->traceOutputOptions).HasFlag(TraceOptions::DateTime))
            WriteLine(string::Format("{0}DateTime={1}T{2}.{3:D7}Z", String(' ', this->data->indentSize), eventCache.DateTime().ToShortDateString(), eventCache.DateTime().ToLongTimeString(), eventCache.DateTime().Ticks % 10000000));
          if (Enum<TraceOptions>(this->data->traceOutputOptions).HasFlag(TraceOptions::Timestamp))
            WriteLine(string::Format("{0}Timestamp={1}", String(' ', this->data->indentSize), eventCache.Timestamp));
          if (Enum<TraceOptions>(this->data->traceOutputOptions).HasFlag(TraceOptions::Callstack))
            WriteLine(string::Format("{0}Callstack={1}", String(' ', this->data->indentSize), eventCache.CallStack));
        }

        struct TraceListenerData {
          Collections::Specialized::StringDictionary attibutes;
          const TraceFilter* filter;
          int32 indentLevel = 0;
          int32 indentSize = 4;
          bool isThreadSafe = false;
          string name;
          bool needIndent = true;
          TraceOptions traceOutputOptions = TraceOptions::None;
        };

        refptr<TraceListenerData> data = ref_new<TraceListenerData>();
      };
    }
  }
}

using namespace Switch;
