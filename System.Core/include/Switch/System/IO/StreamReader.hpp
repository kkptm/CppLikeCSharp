/// @file
/// @brief Contains Switch::System::IO::StreamReader class.
#pragma once

#include "../Text/Encoding.hpp"
#include "../Text/UTF8Encoding.hpp"
#include "FileStream.hpp"
#include "TextReader.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Implements a System::IO::TextReader for writing characters to a stream in a particular encoding.
      /// @par Examples
      /// The following example uses an instance of StreamReader to read text from a file.
      /// @include StreamReader.cpp
      class core_export_ StreamReader: public TextReader {
      public:
        static StreamReader& Null() {
          static StreamReader nullStreamReader;
          return nullStreamReader;
        }

        /// @brief Initializes a new instance of the System::IO::StreamReader class for the specified Sream pointer.
        /// @param stream The stream pointer to be read.
        /// @exception ArgumentException The stream to be read.
        template<typename TStream>
        StreamReader(const TStream& stream) {
          static_assert(!std::is_same<System::IO::Stream, TStream>::value, "Must not be System::IO::Stream but inherited");
          static_assert(std::is_base_of<System::IO::Stream, TStream>::value, "Is not inherited from System::IO::Stream");
          if (stream.CanRead() == false)
            throw ArgumentException(caller_);
          this->data->stream = stream.template MemberwiseClone<TStream>().template As<Stream>();
          this->data->encoding = utf8Encoding;

          if (this->data->stream->CanSeek())
            this->data->stream->Seek(0, System::IO::SeekOrigin::Begin);
        }

        /// @brief Initializes a new instance of the System::IO::StreamReader class for the specified Sream pointer.
        /// @param stream The stream pointer to be read.
        /// @exception ArgumentException The stream to be read.
        StreamReader(refptr<Stream> stream) {
          if (stream->CanRead() == false)
            throw ArgumentException(caller_);
          this->data->stream = stream;
          this->data->encoding = utf8Encoding;

          if (this->data->stream->CanSeek())
            this->data->stream->Seek(0, System::IO::SeekOrigin::Begin);
        }

        /// @brief Initializes a new instance of the System::IO::StreamReader class for the specified Sream pointer.
        /// @param stream The stream pointer to be read.
        /// @param encoding The character encoding to use.
        /// @exception ArgumentException The stream to be read.
        template<typename TStream>
        StreamReader(const TStream& stream, Text::Encoding& encoding) {
          static_assert(!std::is_same<System::IO::Stream, TStream>::value, "Must not be System::IO::Stream but inherited");
          static_assert(std::is_base_of<System::IO::Stream, TStream>::value, "Is not inherited from System::IO::Stream");
          if (stream.CanRead() == false)
            throw ArgumentException(caller_);
          this->data->stream = stream.template MemberwiseClone<TStream>().template As<Stream>();
          this->data->encoding = encoding;

          if (this->data->stream->CanSeek())
            this->data->stream->Seek(0, System::IO::SeekOrigin::Begin);
        }

        /// @brief Initializes a new instance of the System::IO::StreamReader class for the specified file name.
        /// @param path The complete file path to be read.
        /// @exception ArgumentException path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception DirectoryNotFoundException the file specified by path does not exist
        StreamReader(const System::String& path);

        /// @brief Initializes a new instance of the System::IO::StreamReader class for the specified file name.
        /// @param path The complete file path to be read.
        /// @param encoding The character encoding to use.
        /// @exception ArgumentException path is null -or- path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception DirectoryNotFoundException the file specified by path does not exist
        StreamReader(const System::String& path, Text::Encoding& encoding);

        /// @cond
        StreamReader();
        StreamReader(const char path[]) : StreamReader(string(path)) {}
        StreamReader(const StreamReader& streamReader) : data(streamReader.data) {}
        StreamReader& operator=(const StreamReader& streamReader) {this->data = streamReader.data; return *this;}
        ~StreamReader() {this->Close();}
        /// @endcond

        /// @brief Gets the underlying stream that interfaces with a backing store.
        /// @return refptr<Stream> The stream this StreamReader is writing to.
        property_<Stream&, readonly_> BaseStream {
          get_->Stream& {return *this->data->stream;}
        };

        /// @brief Gets the current character encoding that the current StreamReader object is using.
        /// @return refptr<Text::Encoding> The current character encoding used by the current reader. The value can be different after the first call to any Read method of StreamReader, since encoding autodetection is not done until the first call to a Read method.
        property_<Text::Encoding&, readonly_> CurrentEncoding {
          get_->Text::Encoding& {return *this->data->encoding;}
        };

        /// @brief Gets a value that indicates whether the current stream position is at the end of the stream.
        /// @return true if the current stream position is at the end of the stream; otherwise false.
        property_<bool, readonly_> EndOfStream {
          get_ {return this->Peek() == -1;}
        };

        /// @brief Closes the current StreamReader object and the underlying stream. (Overrides TextReader::Close().).
        /// @exception IO::IOException an error occurred while the file is being closed
        void Close() override;

        /// @brief Reads the next character without changing the state of the reader or the character source. Returns the next available character without actually reading it from the input stream.
        /// @return int32 An integer representing the next character to be read, or -1 if no more characters are available or the stream does not support seeking.
        int32 Peek() const override;

        /// @brief Reads the next character from the input stream and advances the character position by one character.
        /// @return The next character from the input stream, or -1 if no more characters are available.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        int32 Read() override;

        /// @brief Reads a line of characters from the current stream and returns the data as a System::String.
        /// @return The next line from the input stream, or an empty System::String if the end of the input stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        /// @par Examples
        /// The following code example reads lines from a file until the end of the file is reached.
        /// @include StreamReaderReadLine.cpp
        System::String ReadLine() override;

        /// @brief Reads all characters from the current position to the end of the TextReader and returns them as one System::String.
        /// @return A System::String containing all characters from the current position to the end of the TextReader.
        /// @exception ObjectDisposedException: The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        /// @par Examples
        /// The following code example reads all the way to the end of a file in one operation.
        /// @include StreamReaderReadToEnd.cpp
        System::String ReadToEnd() override;

        virtual bool EndOfText() { return EndOfStream(); }

      protected:
        int32 Read(Text::Encoding::Decoder& decoder);
        int32 ReadCodePoint(Text::Encoding::Decoder& decoder);

        /// @cond
        struct StreamReaderData {
          int32 peekByte {0};
          bool hasPeekByte {false};
          refptr<Stream> stream;
          ref<Text::Encoding> encoding;
        };

        refptr<StreamReaderData> data {new StreamReaderData()};
        static Text::UTF8Encoding utf8Encoding;
        /// @endcond
      };
    }
  }
}

using namespace Switch;
