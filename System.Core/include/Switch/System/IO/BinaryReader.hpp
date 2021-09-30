/// @file
/// @brief Contains Switch::System::IO::BinaryReader class.
#pragma once

#include "../../Property.hpp"
#include "../../Types.hpp"
#include "../../RefPtr.hpp"
#include "../Array.hpp"
#include "../BitConverter.hpp"
#include "../Object.hpp"
#include "EndOfStreamException.hpp"
#include "Stream.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Reads primitive data types as binary values in a specific encoding.
      class BinaryReader : public Object {
      public:
        /// @brief Initializes a new instance of the System::IO::BinaryReader class.
        BinaryReader() {}

        /// @brief Initializes a new instance of the System::IO::BinaryReader class for the specified Sream pointer.
        /// @param stream The stream pointer to be read.
        /// @exception ArgumentNullException stream is null.
        /// @exception ArgumentException stream is not readable.
        template<typename TStream>
        BinaryReader(const TStream& stream) : stream(stream.template MemberwiseClone<TStream>().template As<Stream>()) {
          static_assert(!std::is_same<System::IO::Stream, TStream>::value, "Must not be System::IO::Stream but inherited");
          static_assert(std::is_base_of<System::IO::Stream, TStream>::value, "Is not inherited from System::IO::Stream");
          if (!stream.CanRead())
            throw ArgumentException(caller_);
        }

        /// @brief Initializes a new instance of the System::IO::BinaryReader class for the specified Sream pointer.
        /// @param stream The stream pointer to be read.
        /// @exception ArgumentNullException stream is null.
        /// @exception ArgumentException stream is not readable.
        BinaryReader(refptr<Stream> stream) : stream(stream) {
          if (!stream->CanRead())
            throw ArgumentException(caller_);
        }

        /// @cond
        ~BinaryReader() {Close();}
        /// @endcond

        /// @brief Gets the underlying stream that interfaces with a backing store.
        /// @return The stream this BinaryReader is reading from.
        property_<Stream&, readonly_> BaseStream {
          get_->Stream& {return this->GetBaseStream();}
        };

        /// @brief Closes the current BinaryReader object and the underlying stream.
        /// @exception IO::IOException an error occurred while the file is being closed
        virtual void Close() {this->stream->Close();}

        /// @brief Reads the next character without changing the state of the reader or the character source. Returns the next available character without actually reading it from the input stream.
        /// @return An integer representing the next character to be read, or -1 if no more characters are available or the stream does not support seeking.
        /// @return available.
        virtual int32 PeekChar() {
          if (!this->stream->CanSeek()) return -1;
          int32 value = this->stream->ReadByte();
          if (value != -1)
            this->stream->Seek(-1, SeekOrigin::Current);
          return value;
        }

        /// @brief Reads the next character from the input stream and advances the character
        /// position by one character.
        /// @return The next character from the input stream, or -1 if no more characters are
        /// @return available.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual int32 Read() {return this->stream->ReadByte();}

        /// @brief Reads the specified number of bytes from the stream, starting from a specified point in the byte array.
        /// @param buffer When this method returns, this parameter contains the specified byte
        /// array with the values between index and (index + count -1) replaced by the
        /// characters read from the current source.
        /// @param bufferSize Size of buffer.
        /// @param index The place in buffer at which to begin writing.
        /// @param count The maximum number of characters to read.
        /// @return The number of bytes read into buffer. This might be less than the number of bytes requested if that many bytes are not available, or it might be zero if the end of the stream is reached.
        /// @exception ArgumentNullException buffer is null.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual int32 Read(Array<byte>& buffer, int32 index, int32 count) {return this->stream->Read(buffer, index, count);}

        /// @brief Reads a bool value from the current stream and advances the current position of the stream by one byte.
        /// @return true if the byte is nonzero; otherwise, false.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual bool ReadBoolean() {return BitConverter::ToBoolean(ReadBytes(sizeof(bool)), 0);}


        /// @brief Reads the next byte from the current stream and advances the current position of the stream by one byte.
        /// @return The next byte read from the current stream.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual byte ReadByte() {return ReadBytes(1)[0];}

        /// @brief Reads the specified number of bytes from the current stream into a byte array and advances the current position by that number of bytes.
        /// @param count The number of bytes to read.
        /// @return A byte array containing data read from the underlying stream. This might be less than the number of bytes requested if the end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual Array<byte> ReadBytes(int32 count) {
          Array<byte> values(count);
          if (Read(values, 0, count) != count)
            throw EndOfStreamException(caller_);
          return values;
        }

        /// @brief Reads the next char from the current stream and advances the current position of the stream by one byte.
        /// @return The next byte read from the current stream.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual char32 ReadChar() {return BitConverter::ToChar(ReadBytes(sizeof(char32)), 0);}

        /// @brief Reads the specified number of char from the current stream into a char array and advances the current position by that number of char.
        /// @param count The number of bytes to read.
        /// @return A byte array containing data read from the underlying stream. This might be less than the number of bytes requested if the end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual Array<char32> ReadChars(int32 count) {
          Array<char32> values(count);
          for (int32 index = 0; index < count; index++)
            values[index] = BitConverter::ToChar(ReadBytes(sizeof(char32)), 0);
          return values;
        }

        /// @brief Reads an 8-byte floating point value from the current stream and advances the current position of the stream by eight bytes.
        /// @return An 8-byte floating point value read from the current stream.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual double ReadDouble() {return BitConverter::ToDouble(ReadBytes(sizeof(double)), 0);}

        /// @brief Reads a 2-byte signed integer from the current stream and advances the current position of the stream by two bytes.
        /// @return A 2-byte signed integer read from the current stream.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual int16 ReadInt16() {return BitConverter::ToInt16(ReadBytes(sizeof(int16)), 0);}

        /// @brief Reads a 4-byte signed integer from the current stream and advances the current position of the stream by four bytes.
        /// @return A 4-byte signed integer read from the current stream.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual int32 ReadInt32() {return BitConverter::ToInt32(ReadBytes(sizeof(int32)), 0);}

        /// @brief Reads a 8-byte signed integer from the current stream and advances the current position of the stream by height bytes.
        /// @return A 8-byte signed integer read from the current stream.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual int64 ReadInt64() {return BitConverter::ToInt64(ReadBytes(sizeof(int64)), 0);}

        /// @brief Reads the next signed byte from the current stream and advances the current position of the stream by one byte.
        /// @return The next signed byte read from the current stream.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual sbyte ReadSByte() {return (sbyte)ReadBytes(1)[0];}

        /// @brief Reads an 4-byte floating point value from the current stream and advances the current position of the stream by four bytes.
        /// @return An 4-byte floating point value read from the current stream.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual float ReadSingle() {return BitConverter::ToSingle(ReadBytes(sizeof(float)), 0);}

        /// @brief Reads a String from the current stream. The String is prefixed with the length, encoded as an integer seven bits at a time.
        /// @return The String being read.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual String ReadString() {
          int32 length = BitConverter::ToInt32(ReadBytes(sizeof(int32)), 0);
          return string((char*)ReadBytes(length).Data(), length);
        }

        /// @brief Reads a 2-byte unsigned integer from the current stream and advances the current position of the stream by two bytes.
        /// @return A 2-byte unsigned integer read from the current stream.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual uint16 ReadUInt16() {return BitConverter::ToUInt16(ReadBytes(sizeof(uint16)), 0);;}

        /// @brief Reads a 4-byte unsigned integer from the current stream and advances the current position of the stream by four bytes.
        /// @return A 4-byte unsigned integer read from the current stream.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual uint32 ReadUInt32() {return BitConverter::ToUInt32(ReadBytes(sizeof(uint32)), 0);}

        /// @brief Reads a 8-byte unsigned integer from the current stream and advances the current position of the stream by height bytes.
        /// @return A 8-byte unsigned integer read from the current stream.
        /// @exception EndOfStreamException The end of the stream is reached.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException An I/O error occurs.
        virtual uint64 ReadUInt64() {return BitConverter::ToUInt64(ReadBytes(sizeof(uint64)), 0);}

      protected :
        /// @brief Gets the underlying stream that interfaces with a backing store.
        /// @return The stream this BinaryReader is reading from.
        virtual Stream& GetBaseStream() const {return *this->stream;}

      private :
        mutable refptr<Stream> stream {Stream::Null().MemberwiseClone<NullStream>().template As<Stream>()};
      };
    }
  }
}

using namespace Switch;
