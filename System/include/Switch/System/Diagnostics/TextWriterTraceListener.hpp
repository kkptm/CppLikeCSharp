/// @file
/// @brief Contains Switch::System::Diagnostics::TextWriterTraceListener class.
#pragma once

#include <Switch/System/Console.hpp>
#include <Switch/System/IO/StreamWriter.hpp>
#include "../../SystemExport.hpp"
#include "TraceListener.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Directs tracing or debugging output to a TextWriter or to a Stream, such as FileStream.
      /// @remarks The TextWriterTraceListener class provides the Writer property to get or set the text writer that receives the tracing or debugging output.
      /// @remarks This class also provides methods to Close the Writer so that it no longer receives tracing or debugging output, to Flush the output buffer for the Writer, and to Write a message to the Writer.
      /// @remarks You must enable tracing or debugging to use a trace listener. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build nanager.
      ///  * To enable debugging with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your porject, or you can add #define DEBUG to the top of your file but in this case, the compiler options for debug is not activated.
      ///  * To enable tracing with cmake, add the add_definitions(-DTRACE) command line in the CMakeLists.txt of your porject, or you can add #define TRACE to the top of your file.
      /// @note If an attempt is made to write to a file that is in use or unavailable, the file name is automatically prefixed by a GUID.
      /// @par Library
      /// Switch.System
      /// @par Examples
      /// The following example implements an instance of the TextWriterTraceListener class that uses a StreamWriter called myOutputWriter to write to a file named TestFile.txt. First the example creates a file for output. Then it creates the StreamWriter for the first text writer, assigns it the output file, and adds it to the Listeners. Then, the code outputs one line of text to the file. Finally, the example flushes the output buffer.
      ///
      /// After running this sample, you can open the TestFile.txt file to see the output.
      /// @include TextWriterTraceListener.cpp
      class system_export_ TextWriterTraceListener : public TraceListener {
        struct InitTextWriter {
          template<typename TTextWriter>
          void operator()(const TTextWriter& textWriter, TextWriterTraceListener& twtl) {
            static_assert(!std::is_same<System::IO::TextWriter, TTextWriter>::value, "Must not be System::IO::TextWriter but inherited");
            static_assert(std::is_base_of<System::IO::TextWriter, TTextWriter>::value, "Is not inherited from System::IO::TextWriter");
            twtl.textWriter = textWriter.template MemberwiseClone<TTextWriter>().template As<System::IO::TextWriter>();
          }
        };

        struct InitStream {
          template<typename TStream>
          void operator()(const TStream& stream, TextWriterTraceListener& twtl) {
            twtl.textWriter = new System::IO::StreamWriter(stream);
          }
        };

      public:
        /// @brief Initializes a new instance of the TextWriterTraceListener class with TextWriter as the output recipient.
        /// @remarks This constructor uses the TextWriter stream as the recipient of the tracing or debugging output. Its Name property is initialized to an empty string ("", or String.Empty).
        TextWriterTraceListener() {}

        /// @brief When overridden in a derived class, closes the output stream so it no longer receives tracing or debugging output.
        /// @remarks Use this method when the output is going to a file, such as to the TextWriterTraceListener. After a call to this method, you must reinitialize the object.
        void Close() override {
          this->textWriter->Flush();
          this->textWriter->Close();
        }

        template<typename TTextWriterOrStream>
        TextWriterTraceListener(const TTextWriterOrStream& textWriterOrStream) {
          typename std::conditional<std::is_base_of<System::IO::Stream, TTextWriterOrStream>::value, InitStream, InitTextWriter>::type init;
          init(textWriterOrStream, *this);
        }

        TextWriterTraceListener(const string& path) {this->textWriter = new System::IO::StreamWriter(path);}

        /// @cond
        TextWriterTraceListener(const char* path) : TextWriterTraceListener(string(path)) {}
        TextWriterTraceListener(const TextWriterTraceListener& twtl) : TraceListener(twtl), textWriter(twtl.textWriter) {}
        TextWriterTraceListener& operator=(const TextWriterTraceListener& twtl) {
          this->TraceListener::operator=(twtl);
          this->textWriter = twtl.textWriter;
          return *this;
        }
        /// @endcond

        /// @brief Gets the text writer that receives the tracing or debugging output.
        /// @return System::IO::TextWriter A TextWriter that represents the writer that receives the tracing or debugging output.
        property_<System::IO::TextWriter&, readonly_> Writer {
          get_->System::IO::TextWriter& {return *this->textWriter;}
        };

        void Write(const String& message) override {
          #if defined(DEBUG) || defined(TRACE)
          if (this->NeedIndent)
            this->WriteIndent();
          this->textWriter->Write(message);
          #endif
        }

        void WriteLine(const String& message) override {
          #if defined(DEBUG) || defined(TRACE)
          if (this->NeedIndent)
            this->WriteIndent();
          this->textWriter->WriteLine(message);
          this->NeedIndent = true;
          #endif
        }

      private:
        refptr<System::IO::TextWriter> textWriter;
      };
    }
  }
}

using namespace Switch;
