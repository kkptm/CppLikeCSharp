/// @file
/// @brief Contains Switch::System::IO::BinaryWriter class.
#pragma once

#include "../../Types.hpp"
#include "../../RefPtr.hpp"
#include "../Array.hpp"
#include "../BitConverter.hpp"
#include "../Object.hpp"
#include "Stream.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Writes primitive types in binary to a stream and supports writing strings in a specific encoding.
      class BinaryWriter : public Object {
      public:
        /// @brief Initializes a new instance of the System::IO::BinaryWriter class.
        BinaryWriter() {}

        /// @brief Initializes a new instance of the System::IO::BinaryWriter class for the specified file on the specified stream pointer.
        /// @param stream The stream pointer to write to.
        /// @exception ArgumentException stream is null.
        /// @exception ArgumentException stream is not writable.
        template<typename TStream>
        BinaryWriter(const TStream& stream) : stream(stream.template MemberwiseClone<TStream>().template As<Stream>()) {
          static_assert(!std::is_same<System::IO::Stream, TStream>::value, "Must not be System::IO::Stream but inherited");
          static_assert(std::is_base_of<System::IO::Stream, TStream>::value, "Is not inherited from System::IO::Stream");
          if (!stream.CanWrite())
            throw ArgumentException(caller_);
        }

        /// @brief Initializes a new instance of the System::IO::BinaryWriter class for the specified file on the specified stream pointer.
        /// @param stream The stream pointer to write to.
        /// @exception ArgumentException stream is null.
        /// @exception ArgumentException stream is not writable.
        BinaryWriter(refptr<Stream> stream) : stream(stream) {
          if (!stream->CanWrite())
            throw ArgumentException(caller_);
        }

        /// @cond
        ~BinaryWriter() {this->Close();}
        /// @endcond

        /// @brief Gets the underlying stream that interfaces with a backing store.
        /// @return The stream this StreamWriter is writing to.
        property_<Stream&, readonly_> BaseStream {
          get_->Stream& {return this->GetBaseStream();}
        };

        /// @brief Closes the current BinaryWriter object and the underlying stream.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception IO::IOException an error occurred while the file is being closed -or- An I/O error occurs.
        virtual void Close() {this->stream->Close();}

        /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying stream.
        /// @exception IO::IOException An I/O error occurs.
        virtual void Flush() {this->stream->Flush();}

        /// @brief Sets the position within the current stream.
        /// @param A byte offset relative to origin.
        /// @param A field of SeekOrigin indicating the reference point from which the new position is to be obtained.
        /// @return The position with the current stream.
        virtual int64 Seek(int32 offset, SeekOrigin origin) {return this->stream->Seek(Convert::ToInt64(offset), origin);}

        /// @brief Writes the specified bool value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(bool value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified byte value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(byte value) {Write(Array<byte> {value});}

        /// @brief Writes the specified byte Array value to the binary stream.
        /// @param value The byte Array to write
        /// @exception ArgumentNullException param is null.
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(const Array<byte>& value) {this->stream->Write(value, 0, value.Length);}

        /// @brief Writes the specified Char value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(char value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified Char value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(char16 value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified Char value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(char32 value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified Char value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(wchar value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified Char Array value to the binary stream.
        /// @param value The Char Array to write
        /// @exception ArgumentNullException param is null.
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(const Array<char32>& value) {
          for (char32 c : value)
            Write(BitConverter::GetBytes(c));
        }

        /// @brief Writes the specified double value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(double value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified int16 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(int16 value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified int32 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(int32 value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified int64 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(int64 value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified signed byte value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(sbyte value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified single value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(float value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes a length-prefixed String to this stream in the current encoding of the BinaryWriter, and advances the current position of the stream in accordance with the encoding used and the specific characters being written to the stream.
        /// @param value The value to write
        /// @exception ArgumentNullException param is null.
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(const String& value) {
          int32 length = (int32)strlen(value.Data());
          Write(length);
          Write(Array<byte> {(byte*)value.Data(), length});
        }

        /// @cond
        virtual void Write(const char value[]) {Write(string(value));}
        virtual void Write(const wchar value[]) {Write(string(value));}
        virtual void Write(const char16 value[]) {Write(string(value));}
        virtual void Write(const char32 value[]) {Write(string(value));}
        /// @endcond

        /// @brief Writes the specified uint16 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(uint16 value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified uint32 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(uint32 value) {Write(BitConverter::GetBytes(value));}

        /// @brief Writes the specified uint64 value to the binary stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(uint64 value) {Write(BitConverter::GetBytes(value));}

      protected:
        /// @brief Gets the underlying stream that interfaces with a backing store.
        /// @return The stream this StreamWriter is writing to.
        virtual Stream& GetBaseStream() const {return *this->stream;}

      private:
        mutable refptr<Stream> stream {Stream::Null().MemberwiseClone<NullStream>().template As<Stream>()};
      };
    }
  }
}

using namespace Switch;
