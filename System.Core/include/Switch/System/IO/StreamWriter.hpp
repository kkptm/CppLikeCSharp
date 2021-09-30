/// @file
/// @brief Contains Switch::System::IO::StreamWriter class.
#pragma once

#include "../Text/Encoding.hpp"
#include "FileStream.hpp"
#include "TextWriter.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Implements a System::IO::TextWriter for writing characters to a stream in a particular encoding.
      class core_export_ StreamWriter : public TextWriter {
      public:
        static StreamWriter& Null() {
          static StreamWriter nullStreamWriter;
          return nullStreamWriter;
        }

        /// @brief Initializes a new instance of the System::IO::StreamWriter class for the specified file on the specified stream pointer.
        /// @param stream The stream pointer to write to.
        /// @exception ArgumentException stream is not writable.
        template<typename TStream>
        StreamWriter(const TStream& stream) {
          static_assert(!std::is_same<System::IO::Stream, TStream>::value, "Must not be System::IO::Stream but inherited");
          static_assert(std::is_base_of<System::IO::Stream, TStream>::value, "Is not inherited from System::IO::Stream");
          if (!stream.CanWrite())
            throw ArgumentException(caller_);
          this->data->stream = stream.template MemberwiseClone<TStream>().template As<Stream>();
        }

        /// @brief Initializes a new instance of the System::IO::StreamWriter class for the specified file on the specified stream pointer.
        /// @param stream The stream pointer to write to.
        /// @exception ArgumentException stream is not writable.
        StreamWriter(refptr<Stream> stream) {
          if (!stream->CanWrite())
            throw ArgumentException(caller_);
          this->data->stream = stream;
        }

        /// @brief Initializes a new instance of the StreamWriter class for the specified stream by using the specified encoding and the default buffer size
        /// @param stream The stream pointer to write to.
        /// @param encoding The character encoding to use.
        /// @exception ArgumentException stream is not writable.
        template<typename TStream>
        StreamWriter(const TStream& stream, Text::Encoding& encoding) : TextWriter(encoding) {
          struct CheckStreamType {void operator()(const Stream&) {}};
          CheckStreamType()(stream);

          if (!stream.CanWrite())
            throw ArgumentException(caller_);
          this->data->stream = stream.template MemberwiseClone<TStream>().template As<Stream>();
        }

        /// @brief Initializes a new instance of the System::IO::StreamWriter class for the specified file on the specified path, using the default encoding and buffer size. If the file exists, it can be either overwritten or appended to. If the file does not exist, this constructor creates a new file.
        /// @param path The complete file path to write to.
        /// @exception ArgumentException path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception IOError the handle of the specified file cannot be opened
        StreamWriter(const String& path);

        /// @brief Initializes a new instance of the System::IO::StreamWriter class for the specified file on the specified path, using the default encoding and buffer size. If the file exists, it can be either overwritten or appended to. If the file does not exist, this constructor creates a new file.
        /// @param path The complete file path to write to.
        /// @param append Determines whether data is to be appended to the file. If the file exists and append is false, the file is overwritten. If the file exists and append is true, the data is appended to the file. Otherwise, a new file is created.
        /// @exception ArgumentException path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception IOError the handle of the specified file cannot be opened
        StreamWriter(const System::String& path, bool append);

        /// @brief Initializes a new instance of the System::IO::StreamWriter class for the specified file on the specified path, using the default encoding and buffer size. If the file exists, it can be either overwritten or appended to. If the file does not exist, this constructor creates a new file.
        /// @param path The complete file path to write to.
        /// @param append Determines whether data is to be appended to the file. If the file exists and append is false, the file is overwritten. If the file exists and append is true, the data is appended to the file. Otherwise, a new file is created.
        /// @param encoding The character encoding to use.
        /// @exception ArgumentException path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception IOError the handle of the specified file cannot be opened
        StreamWriter(const System::String& path, bool append, Text::Encoding& encoding);

        /// @cond
        StreamWriter();
        StreamWriter(const char path[]) : StreamWriter(string(path)) {}
        StreamWriter(const StreamWriter& streamWriter) : data(streamWriter.data) {}
        StreamWriter& operator=(const StreamWriter& streamWriter) {this->data = streamWriter.data; return *this;}
        ~StreamWriter() {this->Close();}
        /// @endcond

        /// @brief Gets or Sets a value indicating whether the System::IO::StreamWriter will flush its buffer to the underlying stream after every call to System::IO::StreamWriter.Write(System::Char).
        /// @param autoFlush true to force System::IO::StreamWriter to flush its buffer; otherwise, false.
        /// @return bool true to force System::IO::StreamWriter to flush its buffer; otherwise, false.
        property_<bool> AutoFlush {
          get_ {return this->GetAutoFlush();},
          set_ {this->SetAutoFlush(value);}
        };

        /// @brief Gets the underlying stream that interfaces with a backing store.
        /// @return refptr<Stream> The stream this StreamWriter is writing to.
        property_<Stream&, readonly_> BaseStream {
          get_->Stream& {return this->GetBaseStream();}
        };

        /// @brief Closes the current StreamWriter object and the underlying stream. (Overrides TextWriter::Close().).
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException an error occurred while the file is being closed -or- An I/O error occurs.
        void Close() override;

        /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying stream. (Overrides TextWriter::Flush().).
        /// @exception IO::IOException An I/O error occurs.
        void Flush() override;

        using TextWriter::Write;
        using TextWriter::WriteLine;
        /// @brief Writes the specified System::String value to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void Write(const System::String& value) override;

      protected:
        /// @brief Gets a value indicating whether the System::IO::StreamWriter will flush its buffer to the underlying stream after every call to System::IO::StreamWriter.Write(System::Char).
        /// @return bool true to force System::IO::StreamWriter to flush its buffer; otherwise, false.
        virtual bool GetAutoFlush() const;

        /// @brief Sets a value indicating whether the System::IO::StreamWriter will flush its buffer to the underlying stream after every call to System::IO::StreamWriter.Write(System::Char).
        /// @param autoFlush true to force System::IO::StreamWriter to flush its buffer; otherwise, false.
        virtual void SetAutoFlush(bool autoFlush);

      private:
        Stream& GetBaseStream();

        struct StreamWriterData {
          bool autoFlush {false};
          refptr<Stream> stream;
        };

        refptr<StreamWriterData> data {new StreamWriterData()};

      };
    }
  }
}

using namespace Switch;
