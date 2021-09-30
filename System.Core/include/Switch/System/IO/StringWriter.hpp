/// @file
/// @brief Contains Switch::System::IO::StringWriter class.
#pragma once

#include "../../Types.hpp"
#include "../String.hpp"
#include "TextWriter.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Implements a TextWriter for writing information to a string. The information is stored in an underlying StringBuilder.
      /// @remarks tringWriter enables you to write to a string synchronously or asynchronously. You can write a character at a time with the Write(Char) or the WriteAsync(Char) method, a string at a time using the Write(String) or the WriteAsync(String) method. In addition, you can write a character, an array of characters or a string followed by the line terminator asynchronously with one of the WriteLineAsync methods.
      /// @par Examples
      /// The following code example demonstrates the creation of a continuous paragraph from a group of double-spaced sentences, and then the conversion of the paragraph back to the original text.
      /// @include StringReader.cpp
      class core_export_ StringWriter : public TextWriter {
      public:
        static StringWriter& Null() {
          static StringWriter nullStringWriter;
          return nullStringWriter;
        }

        /// @brief Initializes a new instance of the System::IO::StreamWriter class for the specified file on the specified stream pointer.
        StringWriter();
        StringWriter(const StringWriter& sw) : data(sw.data) {}

        /// @cond
        ~StringWriter();
        /// @endcond

        /// @brief Closes the current StringWriter object and the underlying StringBuilder. (Overrides TextWriter::Close().).
        /// @exception ObjectDisposedException The StringBuilder is closed.
        /// @exception IO::IOException an error occurred while the file is being closed -or- An I/O error occurs.
        virtual void Close() override;

        /// @brief Writes the specified System::String value to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        using TextWriter::Write;
        using TextWriter::WriteLine;
        void Write(const System::String& value) override;

        /// @brief Returns a string containing the characters written to the current StringWriter so far.
        /// @return string The string containing the characters written to the current StringWriter.
        String ToString() const override;

      private:
        struct StringWriterData {
          String str;
          bool close = false;
        };

        refptr<StringWriterData> data = refptr<StringWriterData>();
      };
    }
  }
}

using namespace Switch;
