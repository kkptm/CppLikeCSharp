/// @file
/// @brief Contains Switch::System::Diagnostics::Debug class.
#pragma once

#include "../../SystemExport.hpp"
#include "Trace.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides a set of methods and properties that help you debug the execution of your code. This class cannot be inherited.
      /// @remarks You can use the properties and methods in the Debug class to instrument release builds. Instrumentation allows you to monitor the health of your application running in real-life settings. Tracing helps you isolate problems and fix them without disturbing a running system.
      /// @remarks This class provides methods to display an Assert dialog box, and to emit an assertion that will always Fail. This class provides write methods in the following variations: Write, WriteLine, WriteIf, and WriteLineIf.
      /// @remarks The BooleanSwitch and TraceSwitch classes provide means to dynamically control the tracing output. You can modify the values of these switches without recompiling your application. For information on using the configuration file to set a switch, see the Switch class and the How to: Create, Initialize and Configure Debug Switches topic.
      /// @remarks You can customize the tracing output's target by adding TraceListener instances to or removing instances from the Listeners collection. The Listeners collection is shared by both the Debug and the Debug classes; adding a trace listener to either class adds the listener to both. By default, trace output is emitted using the DefaultTraceListener class.
      /// @note Adding a trace listener to the Listeners collection can cause an exception to be thrown while tracing, if a resource used by the trace listener is not available. The conditions and the exception thrown depend on the trace listener and cannot be enumerated in this topic. It may be useful to place calls to the Debug methods in try/catch blocks to detect and handle any exceptions from trace listeners.
      /// @remarks The Debug class provides properties to get or set the level of Indent, the IndentSize, and whether to AutoFlush after each write.
      /// @remarks You must enable debug mode to use a trace listener. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build nanager.
      ///  * To enable debug mode with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your porject, or you can add #define DEBUG to the top of your file.
      /// @remarks To activete your code if DEBUG is defined, you must enclose calls to the methods of Debug in an #if defined(DEBUG) ... #endif block, and add the /DDEBUG option to the compiler command line or add #define DEBUG to the file.
      /// @par Library
      /// Switch.System
      /// @par Examples
      /// The following example uses Debug to indicate the beginning and the end of a program's execution. The example also uses the Debug.Indent and Debug.Unindent methods to distinguish the tracing output.
      /// @include Debug.cpp
      class system_export_ Debug static_ {
      public:
        /// @brief Gets or sets whether Flush should be called on the Listeners after every write.
        /// @return bool true if Flush is called on the Listeners after every write; otherwise, false.
        /// @remarks The default is false.
        /// @remarks Flushing the stream will not flush its underlying encoder unless you explicitly call Flush or Close. Setting AutoFlush to true means that data will be flushed from the buffer to the stream, but the encoder state will not be flushed. This allows the encoder to keep its state (partial characters) so that it can encode the next block of characters correctly. This scenario affects UTF8 and UTF7 where certain characters can only be encoded after the encoder receives the adjacent character or characters.
        static property_<bool> AutoFlush;

        /// @brief Gets or sets the indent level.
        /// @return int32 The indent level. The default is zero.
        /// @remarks The IndentLevel property represents the number of times the indent of size IndentSize is applied. This property is stored on per-thread/per-request basis.
        static property_<int32> IndentLevel;

        /// @brief Gets or sets the number of spaces in an indent.
        /// @return int32 The number of spaces in an indent. The default is four.
        /// @remarks A TextWriterTraceListener interprets this number as spaces. An EventLogTraceListener ignores this value.
        /// @remarks This property is stored on per-thread/per-request basis.
        static property_<int32> IndentSize;

        /// @brief Gets the collection of listeners that is monitoring the trace output.
        /// @return TraceListenerCollection A TraceListenerCollection that represents a collection of type TraceListener monitoring the trace output.
        /// @remarks The listeners produce formatted output from the trace output. By default, the collection contains an instance of the DefaultTraceListener class. If you want to remove the default listener, call the Remove method, and pass it the instance of the DefaultTraceListener. To redirect output to the console window, add an instance of the ConsoleTraceListener class.
        /// @note The Listeners collection is shared by both the Debug and the Debug classes; adding a trace listener to either class adds the listener to both.
        static property_<TraceListenerCollection&, readonly_> Listeners;

        /// @brief Gets or sets a value indicating whether the global lock should be used.
        /// @return bool true if the global lock is to be used; otherwise, false. The default is true.
        /// @remarks The global lock is always used if the trace listener is not thread safe, regardless of the value of UseGlobalLock. The IsThreadSafe property is used to determine if the listener is thread safe. The global lock is not used only if the value of UseGlobalLock is false and the value of IsThreadSafe is true. The default behavior is to use the global lock.
        static property_<bool> UseGlobalLock;

        /// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
        /// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
        static void Assert(bool condition) {
          #if defined(DEBUG)
          Assert(condition, "");
          #endif
        }

        /// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
        /// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
        /// @param message The message to send to the Listeners collection.
        static void Assert(bool condition, const string& message) {
          #if defined(DEBUG)
          assert(condition);
          if (!condition)
            Fail(message);
          #endif
        }

        /// @brief Flushes the output buffer, and then closes the Listeners.
        /// @remarks Use this method when the output is going to a file, such as to the TextWriterTraceListener.
        /// @remarks Flushing the stream will not flush its underlying encoder unless you explicitly call Flush or Close. Setting AutoFlush to true means that data will be flushed from the buffer to the stream, but the encoder state will not be flushed. This allows the encoder to keep its state (partial characters) so that it can encode the next block of characters correctly. This scenario affects UTF8 and UTF7 where certain characters can only be encoded after the encoder receives the adjacent character or characters.
        static void Close() {
          TraceEventCache eventCache;
          for (auto& listener : Listeners()) {
            listener.Flush();
            listener.Close();
          }
        }

        /// @brief Emits the specified error message.
        /// @brief message A message to emit.
        /// @remarks The default behavior for the default trace listener is to output the message parameter to a message box when the application runs in user-interface mode, and to the TraceListener instances in the Listeners collection.
        static void Fail(const string& message) {
          #if defined(DEBUG)
          TraceEventCache eventCache;
          for (auto& listener : Listeners()) {
            if (!listener.IsThreadSafe && UseGlobalLock) {
              lock_(Trace::lock)
              listener.Fail(message);
            } else
              listener.Fail(message);
          }
          if (AutoFlush)
            Flush();
          #endif
        }

        /// @brief Emits an error message, and a detailed error message.
        /// @param message A message to emit.
        /// @param detailMessage A detailed message to emit.
        /// @remarks The default behavior is for the default trace listener to output the message parameter and the detailedMessage parameter to a message box when the application runs in user-interface mode, and to the TraceListener instances in the Listeners collection.
        static void Fail(const string& message, const string& detailMessage) {
          #if defined(DEBUG)
          TraceEventCache eventCache;
          for (auto& listener : Listeners()) {
            if (!listener.IsThreadSafe && UseGlobalLock) {
              lock_(Trace::lock)
              listener.Fail(message, detailMessage);
            } else
              listener.Fail(message, detailMessage);
          }
          if (AutoFlush)
            Flush();
          #endif
        }

        /// @brief Flushes the output buffer, and causes buffered data to be written to the Listeners.
        /// @remarks Flushing the stream will not flush its underlying encoder unless you explicitly call Flush or Close. Setting AutoFlush to true means that data will be flushed from the buffer to the stream, but the encoder state will not be flushed. This allows the encoder to keep its state (partial characters) so that it can encode the next block of characters correctly. This scenario affects UTF8 and UTF7 where certain characters can only be encoded after the encoder receives the adjacent character or characters.
        static void Flush() {
          #if defined(DEBUG)
          TraceEventCache eventCache;
          for (auto& listener : Listeners())
            listener.Flush();
          #endif
        }

        /// @brief Increases the current IndentLevel by one.
        static void Indent() {
          if (IndentLevel < Int32::MaxValue) {
            IndentLevel += 1;
            for (auto& listener : Trace::listeners)
              listener.IndentLevel = IndentLevel();
          }
        }

        /// @brief Refreshes the trace configuration data.
        /// @remarks Debug configuration data is captured when the application is started. If the configuration data is changed after the application is started, call the Refresh method to update the trace configuration data.
        static void Refresh() {}

        /// @brief Writes an error message to the trace listeners in the Listeners collection using the specified message.
        /// @param message The informative message to write.
        /// @remarks TraceError calls the TraceEvent method for each trace listener, with the trace event type Error, passing the informative message as the message string.
        static void TraceError(const string& message) {TraceEvent(TraceEventType::Error, message);}

        /// @brief Writes an error message to the trace listeners in the Listeners collection using the specified array of objects and formatting information.
        /// @param format A format string that contains zero or more format items, which correspond to objects in the args array.
        /// @param args An object array containing zero or more objects to format.
        /// @remarks TraceError calls the TraceEvent methods in the trace listeners with the trace event type Error, passing the message content as an object array with formatting information. See the Format method for more information about the format and args parameters.
        template<typename ...Objects>
        static void TraceError(const string& format, const Objects& ... args) {TraceEvent(TraceEventType::Error, string::Format(format, args...));}

        /// @brief Writes an informational message to the trace listeners in the Listeners collection using the specified message.
        /// @param message The informative message to write.
        /// @remarks TraceInformation calls the TraceEvent method for each trace listener, with the trace event type Information, passing the informative message as the message string.
        static void TraceInformation(const string& message) {TraceEvent(TraceEventType::Information, message);}

        /// @brief Writes an informational message to the trace listeners in the Listeners collection using the specified array of objects and formatting information.
        /// @param format A format string that contains zero or more format items, which correspond to objects in the args array.
        /// @param args An object array containing zero or more objects to format.
        /// @remarks TraceInformation calls the TraceEvent methods in the trace listeners with the trace event type Information, passing the message content as an object array with formatting information. See the Format method for more information about the format and args parameters.
        template<typename ...Objects>
        static void TraceInformation(const string& format, const Objects& ... args) {TraceEvent(TraceEventType::Information, string::Format(format, args...));}

        /// @brief Writes a warning message to the trace listeners in the Listeners collection using the specified message.
        /// @param message The informative message to write.
        /// @remarks TraceWarning calls the TraceEvent method for each trace listener with the trace event type Warning, passing the informative message as the message string.
        static void TraceWarning(const string& message) {TraceEvent(TraceEventType::Warning, message);}

        /// @brief Writes a warning message to the trace listeners in the Listeners collection using the specified array of objects and formatting information.
        /// @param format A format string that contains zero or more format items, which correspond to objects in the args array.
        /// @param args An object array containing zero or more objects to format.
        /// @remarks TraceWarning calls the TraceEvent methods in the trace listeners with the trace event type Warning, passing the message content as an object array with formatting information. See the Format method for more information about the format and args parameters.
        template<typename ...Objects>
        static void TraceWarning(const string& format, const Objects& ... args) {TraceEvent(TraceEventType::Warning, string::Format(format, args...));}

        /// @brief Decreases the current IndentLevel by one.
        static void Unindent() {
          if (IndentLevel > 0) {
            IndentLevel -= 1;
            for (auto& listener : Trace::listeners)
              listener.IndentLevel = IndentLevel();
          }
        }

        /// @brief Writes the value of the object's ToString method to the trace listeners in the Listeners collection.
        /// @param value An Object whose name is sent to the Listeners.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks This method calls the Write method of the trace listener.
        static void Write(const object& value) {
          #if defined(DEBUG)
          for (auto& listener : Listeners())
            if (!listener.IsThreadSafe && UseGlobalLock) {
              lock_(Trace::lock)
              listener.Write(value);
            } else
              listener.Write(value);
          if (AutoFlush)
            Flush();
          #endif
        }

        /// @brief Writes a category name and the value of the object's ToString method to the trace listeners in the Listeners collection.
        /// @param value An Object whose name is sent to the Listeners.
        /// @param category A category name used to organize the output.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks The category parameter can be used to group output messages.
        /// @remarks This method calls the Write method of the trace listener.
        static void Write(const object& value, const string& category) {
          #if defined(DEBUG)
          for (auto& listener : Listeners())
            if (!listener.IsThreadSafe && UseGlobalLock) {
              lock_(Trace::lock)
              listener.Write(value, category);
            } else
              listener.Write(value, category);
          if (AutoFlush)
            Flush();
          #endif
        }

        /// @brief Writes a message to the trace listeners in the Listeners collection.
        /// @param message A message to write.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks This method calls the Write method of the trace listener.
        static void Write(const string& message) {
          #if defined(DEBUG)
          for (auto& listener : Listeners()) {
            if (!listener.IsThreadSafe && UseGlobalLock) {
              lock_(Trace::lock)
              listener.Write(message);
            } else
              listener.Write(message);
          }
          if (AutoFlush)
            Flush();
          #endif
        }

        /// @brief Writes a category name and the value of the object's ToString method to the listener you create when you implement the TraceListener class.
        /// @param message A message to write.
        /// @param category A category name used to organize the output.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks The category parameter can be used to group output messages.
        /// @remarks This method calls the Write method of the trace listener.
        static void Write(const string& message, const string& category) {
          #if defined(DEBUG)
          for (auto& listener : Listeners()) {
            if (!listener.IsThreadSafe && UseGlobalLock) {
              lock_(Trace::lock)
              listener.Write(message, category);
            } else
              listener.Write(message, category);
          }
          if (AutoFlush)
            Flush();
          #endif
        }

        /// @brief Writes the value of the object's ToString method to the trace listeners in the Listeners collection.
        /// @param value An Object whose name is sent to the Listeners.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks This method calls the WriteLine method of the trace listener.
        static void WriteLine(const object& value) {
          #if defined(DEBUG)
          for (auto& listener : Listeners()) {
            if (!listener.IsThreadSafe && UseGlobalLock) {
              lock_(Trace::lock)
              listener.WriteLine(value);
            } else
              listener.WriteLine(value);
          }
          if (AutoFlush)
            Flush();
          #endif
        }

        /// @brief Writes a category name and the value of the object's ToString method to the trace listeners in the Listeners collection.
        /// @param value An Object whose name is sent to the Listeners.
        /// @param category A category name used to organize the output.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks The category parameter can be used to group output messages.
        /// @remarks This method calls the WriteLine method of the trace listener.
        static void WriteLine(const object& value, const string& category) {
          #if defined(DEBUG)
          for (auto& listener : Listeners()) {
            if (!listener.IsThreadSafe && UseGlobalLock) {
              lock_(Trace::lock)
              listener.WriteLine(value, category);
            } else
              listener.WriteLine(value, category);
          }
          if (AutoFlush)
            Flush();
          #endif
        }

        /// @brief Writes a message to the trace listeners in the Listeners collection.
        /// @param message A message to write.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks This method calls the WriteLine method of the trace listener.
        static void WriteLine(const string& message) {
          #if defined(DEBUG)
          for (auto& listener : Listeners()) {
            if (!listener.IsThreadSafe && UseGlobalLock) {
              lock_(Trace::lock)
              listener.WriteLine(message);
            } else
              listener.WriteLine(message);
          }
          if (AutoFlush)
            Flush();
          #endif
        }

        /// @brief Writes a formatted message followed by a line terminator to the trace listeners in the Listeners collection.
        /// @param format A composite format string (see Remarks) that contains text intermixed with zero or more format items, which correspond to objects in the args array.
        /// @param args An object array that contains zero or more objects to format.
        /// @remarks This method uses the of the Switch to convert the value of an object to its text representation and embed that representation in a string.
        /// @remarks The keyword in the syntax for this method implies that the object array can be a single value. The exception to this is the String object. Explicit overloads take precedence, so an arg value of a single string will default to the Debug.WriteLine(String, String) overload.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks This method calls the WriteLine method of the trace listener.
        template<typename ...Objects>
        static void WriteLine(const string& format, const Objects& ... args) { WriteLine(string::Format(format, args...)); }

        /// @brief Writes a category name and message to the trace listeners in the Listeners collection.
        /// @param message A message to write.
        /// @param category A category name used to organize the output.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks The category parameter can be used to group output messages.
        /// @remarks This method calls the WriteLine method of the trace listener.
        static void WriteLine(const string& message, const string& category) {
          #if defined(DEBUG)
          for (auto& listener : Listeners()) {
            if (!listener.IsThreadSafe && UseGlobalLock) {
              lock_(Trace::lock)
              listener.WriteLine(message, category);
            } else
              listener.WriteLine(message, category);
          }
          if (AutoFlush)
            Flush();
          #endif
        }

        /// @brief Writes the value of the object's ToString method to the trace listeners in the Listeners collection if a condition is true.
        /// @param condition true to cause a message to be written; otherwise, false.
        /// @param value An Object whose name is sent to the Listeners.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks This method calls the WriteLine method of the trace listener.
        static void WriteLineIf(bool condition, const object& value) {
          #if defined(DEBUG)
          if (condition)
            WriteLine(value);
          #endif
        }

        /// @brief Writes a category name and the value of the object's ToString method to the trace listeners in the Listeners collection if a condition is true.
        /// @param condition true to cause a message to be written; otherwise, false.
        /// @param value An Object whose name is sent to the Listeners.
        /// @param category A category name used to organize the output.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks The category parameter can be used to group output messages.
        /// @remarks This method calls the WriteLine method of the trace listener.
        static void WriteLineIf(bool condition, const object& value, const string& category) {
          #if defined(DEBUG)
          if (condition)
            WriteLine(value, category);
          #endif
        }

        /// @brief Writes a message to the trace listeners in the Listeners collection if a condition is true.
        /// @param condition true to cause a message to be written; otherwise, false.
        /// @param message A message to write.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks This method calls the WriteLine method of the trace listener.
        static void WriteLineIf(bool condition, const string& message) {
          #if defined(DEBUG)
          if (condition)
            WriteLine(message);
          #endif
        }

        /// @brief Writes a category name and message to the trace listeners in the Listeners collection if a condition is true.
        /// @param condition true to cause a message to be written; otherwise, false.
        /// @param message A message to write.
        /// @param category A category name used to organize the output.
        /// @remarks By default, the output is written to an instance of DefaultTraceListener.
        /// @remarks The category parameter can be used to group output messages.
        /// @remarks This method calls the WriteLine method of the trace listener.
        static void WriteLineIf(bool condition, const string& message, const string& category) {
          #if defined(DEBUG)
          if (condition)
            WriteLine(message, category);
          #endif
        }

      private:
        static void TraceEvent(const TraceEventType& traceEventType, const string& message) {
          #if defined(DEBUG)
          TraceEventCache eventCache;
          static string sourceName = System::IO::Path::GetFileName(Environment::GetCommandLineArgs()[0]);
          for (auto& listener : Listeners()) {
            if (!listener.IsThreadSafe && UseGlobalLock) {
              lock_(Trace::lock)
              listener.TraceEvent(eventCache, sourceName, traceEventType, 0, message);
            } else
              listener.TraceEvent(eventCache, sourceName, traceEventType, 0, message);
          }
          if (AutoFlush)
            Flush();
          #endif
        }
      };
    }
  }
}

using namespace Switch;
