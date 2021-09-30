/// @file
/// @brief Contains Switch::System::IO::MemoryStream class.
#pragma once

#include "../../Types.hpp"
#include "../Array.hpp"
#include "../ObjectDisposedException.hpp"
#include "IOException.hpp"
#include "SeekOrigin.hpp"
#include "Stream.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Exposes a System::IO::Stream in memory, supporting synchronous read and write operations.
      class core_export_ MemoryStream : public Stream {
        int64 GetLength() const override;
        void SetLength(int64 len) override;
        bool GetCanRead() const override {return ! IsClosed();}
        bool GetCanSeek() const override {return ! IsClosed();}
        bool GetCanTimeout() const override {return false;}
        bool GetCanWrite() const override {return IsClosed() ? false : this->data->writable;}
        int64 GetPosition() const override {return static_cast<int64>(this->data->position);}
        void SetPosition(int64 newPosition) override {
          if (newPosition < 0 || newPosition > static_cast<int64>(Int32::MaxValue))
            throw ArgumentOutOfRangeException(caller_);
          if (IsClosed())
            throw ObjectDisposedException(caller_);
          this->data->position = static_cast<int32>(newPosition);
        }

      protected:
        /// @brief Gets the number of bytes allocated for this stream.
        /// @return The length of the usable portion of the buffer for the stream.
        /// @exception System::ObjectDisposedException The current stream is IsClosed().
        /// @deprecated Replaced by System::IO::MemoryStream::Capacity()
        virtual int32 GetCapacity() const;

        /// @brief Sets the number of bytes allocated for this stream.
        /// @exception System::ArgumentOutOfRangeException A capacity is set that is negative or less than the current length of the stream.
        /// @exception System::ObjectDisposedException The current stream is IsClosed().
        /// @exception System::NotSupportedException set is invoked on a stream whose capacity cannot be modified.
        virtual void SetCapacity(int32 newCapacity);

      public:
        /// @brief Initializes a new instance of the System::IO::MemoryStream class with an expandable capacity initialized to zero.
        MemoryStream();

        /// @brief Initializes a new instance of the System::IO::MemoryStream class with an expandable capacity initialized as specified.
        /// @param capacity The initial size of the internal array in bytes.
        /// @exception System::ArgumentOutOfRangeException capacity is negative.
        MemoryStream(int32 capacity);

        /// @brief Initializes a new non-resizable instance of the System::IO::MemoryStream class based on the specified byte array with the System::IO::MemoryStream.CanWrite property set as specified.
        /// @param buffer The array of unsigned bytes from which to create this stream.
        /// @param bufferSize The size of the buffer.
        /// @param writable The setting of the System::IO::MemoryStream.CanWrite property, which determines whether the stream supports writing.
        /// @exception System::ArgumentNullException buffer is null.
        MemoryStream(Array<byte>& buffe, bool writable);

        /// @cond
        MemoryStream(const MemoryStream& memoryStream) : data(memoryStream.data)  {}
        MemoryStream& operator=(const MemoryStream& memoryStream) {this->data = memoryStream.data; return *this;}
        /// @endcond

        /// @brief Gets or sets the number of bytes allocated for this stream.
        /// @return The length of the usable portion of the buffer for the stream.
        /// @exception System::ObjectDisposedException The current stream is IsClosed().
        /// @exception System::ArgumentOutOfRangeException A capacity is set that is negative or less than the current length of the stream.
        /// @exception System::ObjectDisposedException The current stream is IsClosed().
        /// @exception System::NotSupportedException set is invoked on a stream whose capacity cannot be modified.
        property_<int32> Capacity {
          get_ {return this->GetCapacity();},
          set_ {this->SetCapacity(value);}
        };

        /// @brief Returns the array of unsigned bytes from which this stream was created.
        /// @return The byte array from which this stream was created, or the underlying array if a byte array was ! provided to the System::IO::MemoryStream constructor during construction of the current instance.
        /// @exception System::UnauthorizedAccessException The MemoryStream instance was ! created with a publicly visible buffer.
        virtual const byte* Buffer() const;

        /// @brief Reads a block of bytes from the current stream and writes the data to a buffer.
        /// @param buffer When this method returns, contains the specified byte array with the values between offset and (offset + count - 1) replaced by the characters read from the current stream.
        /// @param bufferLength The size of the buffer expressed in bytes.
        /// @param offset The zero-based byte offset in buffer at which to begin storing data from the current stream.
        /// @param count The maximum number of bytes to read.
        /// @return The total number of bytes written into the buffer. This can be less than the number of bytes requested if that number of bytes are ! currently available, or zero if the end of the stream is reached before any bytes are read.
        /// @exception System::ArgumentNullException buffer is null.
        /// @exception System::ArgumentOutOfRangeException offset or count is negative.
        /// @exception System::ArgumentException offset subtracted from the buffer length is less than count.
        /// @exception System::ObjectDisposedException The current stream instance is IsClosed().
        int32 Read(Array<byte>& buffer, int32 offset, int32 count) override;

        /// @brief Reads a byte from the current stream.
        /// @return The byte cast to a System::Int32, or -1 if the end of the stream has been reached.
        /// @exception System::ObjectDisposedException The current stream instance is IsClosed().
        int32 ReadByte() override;

        /// @brief Sets the position within the current stream to the specified value.
        /// @param offset The new position within the stream. This is relative to the loc parameter, and can be positive or negative.
        /// @param loc A value of type System::IO::SeekOrigin, which acts as the seek reference point.
        /// @return The new position within the stream, calculated by combining the initial reference point and the offset.
        /// @exception System::IO::IOException Seeking is attempted before the beginning of the stream.
        /// @exception System::ArgumentOutOfRangeException offset is greater than System::Int32.MaxValue.
        /// @exception System::ArgumentException There is an invalid System::IO::SeekOrigin. or offset caused an arithmetic overflow.
        /// @exception System::ObjectDisposedException The current stream instance is IsClosed().
        int64 Seek(int64 offset, SeekOrigin origin) override;

        /// @brief Writes the stream contents to a byte array, regardless of the System::IO::MemoryStream.Position property.
        /// @return A new byte array.
        Array<byte> ToArray() const;

        /// @brief Writes a block of bytes to the current stream using data read from a buffer.
        /// @param buffer The buffer to write data from.
        /// @param offset The zero-based byte offset in buffer at which to begin copying bytes to the current stream.
        /// @param count The maximum number of bytes to write.
        /// @exception System::ArgumentNullException buffer is null.
        /// @exception System::NotSupportedException The stream does ! support writing. For additional information see System::IO::Stream.CanWrite. or The current position is closer than count bytes to the end of the stream, and the capacity cannot be modified.
        /// @exception System::ArgumentException offset subtracted from the buffer length is less than count.
        /// @exception System::ArgumentOutOfRangeException offset or count are negative.
        /// @exception System::IO::IOException An I/O error occurs.
        /// @exception System::ObjectDisposedException The current stream instance is IsClosed().
        void Write(const Array<byte>& buffer, int32 offset, int32 count) override;

        /// @brief Writes a byte to the current stream at the current position.
        /// @param value The byte to write.
        /// @exception System::NotSupportedException The stream does ! support writing. For additional information see System::IO::Stream.CanWrite. or The current position is at the end of the stream, and the capacity cannot be modified.
        /// @exception System::ObjectDisposedException The current stream is IsClosed().
        void WriteByte(byte value) override;

        /// @brief Writes the entire contents of this memory stream to another stream.
        /// @param stream The stream to write this memory stream to.
        /// @exception System::ArgumentNullException stream is null.
        /// @exception System::ObjectDisposedException The current or target stream is IsClosed().
        virtual void WriteTo(Stream& stream) const;

      private:
        bool IsDynamic() const;
        byte AbstractReadByteUnChecked();
        void AbstractWriteByteUnChecked(byte b);

        struct MemoryStreamData {
          //dynamic
          System::Collections::Generic::List<byte> dynamicBuffer;

          //static
          Array<byte>* staticBuffer = null;
          int32 staticBufferCapacity = 0;

          int32 position = 0;
          bool writable = true;
        };

        refptr<MemoryStreamData> data {new MemoryStreamData()};
      };
    }
  }
}

using namespace Switch;
