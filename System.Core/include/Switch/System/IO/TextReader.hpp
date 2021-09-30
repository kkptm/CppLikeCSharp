/// @file
/// @brief Contains Switch::System::IO::TextReader class.
#pragma once

#include "../../Types.hpp"
#include "../String.hpp"
#include "../Object.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @cond
      class NullTextReader;
      class SynchronizedTextReader;
      /// @endcond

      /// @brief Represents a reader that can read a sequential series of characters.
      class core_export_ TextReader: public Object {
      public:
        /// @brief Provides a TextReader with no data to read from.
        /// @remarks Reading from the cNull text reader is similar to reading from the end of a stream:
        /// @remarks Read and Peek methods return -1.
        /// @remarks ReadBlock method returns zero.
        /// @remarks ReadLine and ReadToEnd methods return a string Empty.
        static NullTextReader& Null();

        /// @brief Closes the System::IO::TextReader and releases any system resources associated with the TextReader
        virtual void Close() {}

        /// @brief Reads the next character without changing the state of the reader or the character source. Returns the next available character without actually reading it from the input stream.
        /// @return int32 An integer representing the next character to be read, or -1 if no more characters are available or the stream does not support seeking.
        /// @return available.
        virtual int32 Peek() const {return -1;}

        /// @brief Reads the next character from the input stream and advances the character position by one character.
        /// @return The next character from the input stream, or -1 if no more characters are available.
        virtual int32 Read() {return -1;}

        /// @brief Reads a line of characters from the current stream and returns the data as a string.
        /// @return The next line from the input stream, or the empty string if all characters have been read.
        virtual String ReadLine();

        /// @brief Reads all characters from the current position to the end of the TextReader and returns them as one string.
        /// @return A string containing all characters from the current position to the end of the TextReader.
        /// @exception IO::IOException An I/O error occurs.
        virtual String ReadToEnd();

        /// @brief Creates a thread-safe (synchronized) wrapper around the specified TextReader object.
        /// @param reader The TextReader object to synchronize.
        /// @return TextReader A thread-safe TextReader object.
        static SynchronizedTextReader Synchronised(TextReader& reader);

      protected:
        /// @brief Initializes a new instance of the System::IO::TextReader class.
        TextReader() {}
      };

      class NullTextReader : public TextReader {
      public:
        NullTextReader() {}
        int32 Read() override {return -1;}
      };

      class SynchronizedTextReader : public TextReader {
      public:
        int32 Read() override {
          lock_(reader)
          return this->reader.Read();
          return 0;
        }

      private:
        friend class TextReader;
        explicit SynchronizedTextReader(System::IO::TextReader& reader) : reader(reader) {}
        SynchronizedTextReader() = delete;
        System::IO::TextReader& reader;
      };
    }
  }
}

using namespace Switch;
