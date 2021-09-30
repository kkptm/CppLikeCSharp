/// @file
/// @brief Contains Switch::System::IO::Stream class.
#pragma once

#include "../../Abstract.hpp"
#include "../../Types.hpp"
#include "../../RefPtr.hpp"
#include "../Array.hpp"
#include "../Object.hpp"
#include "../String.hpp"
#include "../IAsyncResult.hpp"
#include "../AsyncCallback.hpp"
#include "../Text/UTF8Encoding.hpp"
#include "../Threading/AutoResetEvent.hpp"
#include "../Threading/WaitHandle.hpp"
#include "SeekOrigin.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @cond
      class NullStream;
      /// @endcond

      /// @brief Provides a generic view of a sequence of bytes. This is an abstract class.
      class core_export_ Stream abstract_ {
      public:
        static NullStream& Null();

        /// @brief Initializes a new instance of the Stream class
        /// @remarks Use Null to redirect output to a stream that will not consume any operating system resources. When the methods of Stream that provide writing are invoked on cNull, the call simply returns, and no data is written.
        /// @remarks Null also implements a Read method that returns zero without reading data.
        Stream() {}

        /// @brief When overridden in a derived class, gets a value indicating whether the current
        /// stream supports reading.
        /// @return true if the stream supports reading; otherwise, false.
        property_<bool, readonly_> CanRead {
          get_ {return this->GetCanRead();}
        };

        /// @brief When overridden in a derived class, gets a value indicating whether the current
        /// stream supports seeking.
        /// @return true if the stream supports seeking; otherwise, false.
        property_<bool, readonly_> CanSeek {
          get_ {return this->GetCanSeek();}
        };

        /// @brief Gets a value that determines whether the current stream can time out.
        /// @return A value that determines whether the current stream can time out.
        /// @remarks The CanTimeout() function always returns false. Some stream implementations require different behavior, such as NetworkStream, which times out if network connectivity is interrupted or lost. If you are implementing a stream that must be able to time out, this property should be overridden to return true.
        property_<bool, readonly_> CanTimeout {
          get_ {return this->GetCanTimeout();}
        };

        /// @brief When overridden in a derived class, gets a value indicating whether the current
        /// stream supports writing.
        /// @return true if the stream supports writing; otherwise, false.
        property_<bool, readonly_> CanWrite {
          get_ {return this->GetCanWrite();}
        };

        /// @brief When overridden in a derived class, gets the length in bytes of the stream.
        /// @param length The desired length of the current stream in bytes.
        /// @return A long value representing the length of the stream in bytes.
        property_<int64> Length {
          get_ {return this->GetLength();},
          set_ {this->SetLength(value);}
        };

        /// @brief When overridden in a derived class, gets the position within the current stream.
        /// @param position the position within the stream
        /// @return The current position within the stream.
        property_<int64> Position {
          get_ {return this->GetPosition();},
          set_ {this->SetPosition(value);}
        };

        /// @brief Gets a value, in miliseconds, that determines how long the stream will attempt to read before timing out.
        /// @param readTimeout A value, in miliseconds, that determines how long the stream will attempt to read before timing out
        /// @return A value, in miliseconds, that determines how long the stream will attempt to read before timing out.
        property_<int32> ReadTimeout {
          get_ {return this->GetReadTimeout();},
          set_ {this->SetReadTimeout(value);}
        };

        /// @brief Gets a value, in miliseconds, that determines how long the stream will attempt to write before timing out.
        /// @param writeTimeout A value, in miliseconds, that determines how long the stream will attempt to write before timing out
        /// @return A value, in miliseconds, that determines how long the stream will attempt to write before timing out.
        property_<int32> WriteTimeout {
          get_ {return this->GetWriteTimeout();},
          set_ {this->SetWriteTimeout(value);}
        };

        /// @brief Indicates if the stream is closed
        /// @return true if the stream is closed, false otherwise
        property_<bool, readonly_> IsClosed {
          get_ {return this->GetIsClosed();}
        };

        /// @brief Begins an asynchronous read operation.
        /// @param buffer The buffer to read the data into.
        /// @param offset The byte offset in buffer at which to begin writing data read from the stream.
        /// @param count The maximum number of bytes to read.
        /// @param asyncCallback An optional asynchronous callback, to be called when the read is complete.
        /// @param state A user-provided object that distinguishes this particular asynchronous read request from other requests.
        /// @return IAsyncResult An IAsyncResult that represents the asynchronous read, which could still be pending.
        IAsyncResult& BeginRead(byte buffer[], int32 offset, int32 count, void (*callback)(const IAsyncResult&), const object& state) {
          return BeginRead(buffer, offset, count, AsyncCallback(callback), state);
        }

        /// @brief Begins an asynchronous read operation.
        /// @param buffer The buffer to read the data into.
        /// @param offset The byte offset in buffer at which to begin writing data read from the stream.
        /// @param count The maximum number of bytes to read.
        /// @param asyncCallback An optional asynchronous callback, to be called when the read is complete.
        /// @param state A user-provided object that distinguishes this particular asynchronous read request from other requests.
        /// @return IAsyncResult An IAsyncResult that represents the asynchronous read, which could still be pending.
        template<typename T>
        IAsyncResult& BeginRead(byte buffer[], int32 offset, int32 count, const T& caller, void (T::*callback)(const IAsyncResult&), const object& state) {
          return BeginRead(buffer, offset, count, AsyncCallback(caller, callback), state);
        }

        /// @brief Begins an asynchronous read operation.
        /// @param buffer The buffer to read the data into.
        /// @param offset The byte offset in buffer at which to begin writing data read from the stream.
        /// @param count The maximum number of bytes to read.
        /// @param asyncCallback An optional asynchronous callback, to be called when the read is complete.
        /// @param state A user-provided object that distinguishes this particular asynchronous read request from other requests.
        /// @return IAsyncResult An IAsyncResult that represents the asynchronous read, which could still be pending.
        virtual IAsyncResult& BeginRead(byte [], int32, int32, const AsyncCallback&, const object& state) {
          this->asyncResult = AsyncResult(state);
          return this->asyncResult;
        }

        /// @brief Begins an asynchronous write operation.
        /// @param buffer The buffer to write data from.
        /// @param offset The byte offset in buffer from which to begin writing.
        /// @param count The maximum number of bytes to write.
        /// @param asyncCallback An optional asynchronous callback, to be called when the write is complete.
        /// @param state A user-provided object that distinguishes this particular asynchronous write request from other requests.
        /// @return IAsyncResult An IAsyncResult that represents the asynchronous write, which could still be pending.
        IAsyncResult& BeginWrite(const byte buffer[], int32 offset, int32 count, void (*callback)(const IAsyncResult&), const object& state) {
          return BeginWrite(buffer, offset, count, AsyncCallback(callback), state);
        }

        /// @brief Begins an asynchronous write operation.
        /// @param buffer The buffer to write data from.
        /// @param offset The byte offset in buffer from which to begin writing.
        /// @param count The maximum number of bytes to write.
        /// @param asyncCallback An optional asynchronous callback, to be called when the write is complete.
        /// @param state A user-provided object that distinguishes this particular asynchronous write request from other requests.
        /// @return IAsyncResult An IAsyncResult that represents the asynchronous write, which could still be pending.
        template<typename T>
        IAsyncResult& BeginWrite(const byte buffer[], int32 offset, int32 count, const T& caller, void (T::*callback)(const IAsyncResult&), const object& state) {
          return BeginWrite(buffer, offset, count, AsyncCallback(caller, callback), state);
        }

        /// @brief Begins an asynchronous write operation.
        /// @param buffer The buffer to write data from.
        /// @param offset The byte offset in buffer from which to begin writing.
        /// @param count The maximum number of bytes to write.
        /// @param asyncCallback An optional asynchronous callback, to be called when the write is complete.
        /// @param state A user-provided object that distinguishes this particular asynchronous write request from other requests.
        /// @return IAsyncResult An IAsyncResult that represents the asynchronous write, which could still be pending.
        virtual IAsyncResult& BeginWrite(const byte [], int32, int32, const AsyncCallback&, const object& state) {
          this->asyncResult = AsyncResult(state); return this->asyncResult;
        }

        /// @brief Closes the current stream and releases any resources (such as sockets and file handles) associated with the current stream.
        virtual void Close() {
          Flush();
          this->closed = true;
        }

        /// @brief Waits for the pending asynchronous read to complete.
        /// @param asyncResult A reference to the outstanding asynchronous I/O request.
        virtual int32 EndRead(const IAsyncResult&) {return 0;}

        /// @brief Ends an asynchronous write operation.
        /// @param asyncResult The reference to the pending asynchronous request to finish.
        virtual void EndWrite(const IAsyncResult&) {}

        /// @brief When overridden in a derived class, clears all buffers for this stream and
        /// causes any buffered data to be written to the underlying device.
        virtual void Flush() {}

        /// @brief When overridden in a derived class, reads a sequence of bytes from the current stream and advances the position within the stream by the number of bytes read.
        /// @param buffer An array of bytes. When this method returns, the buffer contains the specified byte array with the values between offset and (offset + count - 1) replaced by the bytes read from the current source.
        /// @param bufferLength The length of buffer. (Total number of elements).
        /// @param offset The zero-based byte offset in buffer at which to begin storing the data read from the current stream.
        /// @param count The maximum number of bytes to be read from the current stream.
        /// @return The total number of bytes read into the buffer. This can be less than the number of bytes requested if that many bytes are not currently available, or zero (0) if the end of the stream has been reached.
        /// @exception InvalidOperationException The sum of offset and count is greater than the buffer length specified bufferLength.
        /// @exception ArgumentNullException buffer is null.
        /// @exception ArgumentOutOfRangeException offset or count is negative.
        /// @exception IOException The stream is closed.
        /// @exception NotSupportedException The stream does not support reading.
        /// @exception IOException An I/O error occurs.
        virtual int32 Read(Array<byte>& buffer, int32 offset, int32 count) = 0;

        /// @brief Reads a byte from the stream and advances the position within the stream
        /// by one byte, or returns -1 if at the end of the stream.
        /// @return The unsigned byte cast to an int32, or -1 if at the end of the stream.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception NotSupportedException The stream does not support reading.
        /// @exception IO::IOException An I/O error occurs.
        virtual int32 ReadByte();

        /// @brief When overridden in a derived class, sets the position within the current stream.
        /// @param offset A byte offset relative to the origin parameter.
        /// @param origin A value of type SeekOrigin indicating the reference point used to obtain the new position
        /// @return The new position within the current stream.
        virtual int64 Seek(int64 offset, System::IO::SeekOrigin origin) = 0;

        /// @brief Creates a thread-safe (synchronized) wrapper around the specified Stream object.
        /// @param stream The Stream object to synchronize.
        /// @return Stream A thread-safe Stream object.
        static Stream& Synchronised(Stream& stream);

        /// @brief When overridden in a derived class, writes a sequence of bytes to the current stream and advances the current position within this stream by the number of bytes written.
        /// @param buffer An array of bytes. This method copies count bytes from buffer to the current stream.
        /// @param bufferLength The length of buffer. (Total number of elements).
        /// @param offset The zero-based byte offset in buffer at which to begin copying bytes to the current stream.
        /// @param count The number of bytes to be written to the current stream.
        /// @exception ArgumentException The sum of offset and count is greater than the buffer length specified bufferLength.
        /// @exception ArgumentNullException buffer is null.
        /// @exception ArgumentOutOfRangeException offset or count is negative.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception NotSupportedException The stream does not support writing.
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(const Array<byte>& buffer, int32 offset, int32 count) = 0;

        /// @brief Writes a byte to the current position in the stream and advances the position
        /// within the stream by one byte.
        /// @param value The byte to write to the stream.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception NotSupportedException The stream does not support writing.
        /// @exception IO::IOException An I/O error occurs.
        virtual void WriteByte(byte value);

      protected:
        /// @brief When overridden in a derived class, gets a value indicating whether the current
        /// stream supports reading.
        /// @return true if the stream supports reading; otherwise, false.
        virtual bool GetCanRead() const = 0;

        /// @brief When overridden in a derived class, gets a value indicating whether the current
        /// stream supports seeking.
        /// @return true if the stream supports seeking; otherwise, false.
        virtual bool GetCanSeek() const = 0;

        /// @brief Gets a value that determines whether the current stream can time out.
        /// @return A value that determines whether the current stream can time out.
        /// @remarks The CanTimeout() function always returns false. Some stream implementations require different behavior, such as NetworkStream, which times out if network connectivity is interrupted or lost. If you are implementing a stream that must be able to time out, this property should be overridden to return true.
        virtual bool GetCanTimeout() const {return false;}

        /// @brief When overridden in a derived class, gets a value indicating whether the current
        /// stream supports writing.
        /// @return true if the stream supports writing; otherwise, false.
        virtual bool GetCanWrite() const = 0;

        /// @brief When overridden in a derived class, gets the length in bytes of the stream.
        /// @return A long value representing the length of the stream in bytes.
        virtual int64 GetLength() const = 0;

        /// @brief When overridden in a derived class, sets the length of the current stream.
        /// @param length The desired length of the current stream in bytes.
        virtual void SetLength(int64 length) {}

        /// @brief When overridden in a derived class, gets the position within the current stream.
        /// @return The current position within the stream.
        virtual int64 GetPosition() const = 0;

        /// @brief When overridden in a derived class, sets the position within the current stream.
        /// @param position the position within the stream
        virtual void SetPosition(int64 position) {Seek(position, SeekOrigin::Begin);}

        /// @brief Gets a value, in miliseconds, that determines how long the stream will attempt to read before timing out.
        /// @return A value, in miliseconds, that determines how long the stream will attempt to read before timing out.
        /// @deprecated Replaced by System::IO::Stream::ReadTimeout()
        virtual int32 GetReadTimeout() const {return this->readTimeout;}

        /// @brief Sets a value, in miliseconds, that determines how long the stream will attempt to read before timing out.
        /// @param readTimeout A value, in miliseconds, that determines how long the stream will attempt to read before timing out
        virtual void SetReadTimeout(int32 readTimeout) {this->readTimeout = readTimeout;}

        /// @brief Gets a value, in miliseconds, that determines how long the stream will attempt to write before timing out.
        /// @return A value, in miliseconds, that determines how long the stream will attempt to write before timing out.
        virtual int32 GetWriteTimeout() const {return this->writeTimeout;}

        /// @brief Sets a value, in miliseconds, that determines how long the stream will attempt to write before timing out.
        /// @param writeTimeout A value, in miliseconds, that determines how long the stream will attempt to write before timing out
        virtual void SetWriteTimeout(int32 writeTimeout) {this->writeTimeout = writeTimeout;}

        /// @brief Indicates if the stream is closed
        /// @return true if the stream is closed, false otherwise
        virtual bool GetIsClosed() const {return this->closed;}

        Stream(object& lock) : lock(&lock) {}

        Stream(int32 readTimeout, int32 writeTimeout) : readTimeout(readTimeout), writeTimeout(writeTimeout) {}

        Stream(object& lock, int32 readTimeout, int32 writeTimeout) : lock(&lock), readTimeout(readTimeout), writeTimeout(writeTimeout) {}

        const object& GetLock() const {return *this->lock;}

      private:
        class AsyncResult : public object, public IAsyncResult {

        public:
          AsyncResult() { }
          AsyncResult(const object& state) : state(const_cast<object*>(&state)) { }
          AsyncResult(const AsyncResult& ar) : state(ar.state) { }
          AsyncResult& operator =(const AsyncResult& ar) {this->state = ar.state; return *this;}

          virtual const object& GetAsyncState() const {
            static object o;
            return o;
          }

          virtual const Threading::WaitHandle& GetAsyncWaitHandle() const {
            static Threading::AutoResetEvent e(true);
            return e;
          }

          virtual bool GetCompletedSynchronously() const {return true;}

          virtual bool GetIsCompleted() const {return true;};

        private:
          object* state = null;
        };

        AsyncResult asyncResult;
        object* lock = null;
        int32 readTimeout = 0;
        int32 writeTimeout = 0;
        bool closed = false;
      };

      class NullStream : public System::IO::Stream {
      public:
        NullStream() : Stream() { }
        NullStream(const NullStream&) {}

        void Write(const Array<byte>&, int32, int32) override { }
        int32 Read(Array<byte>&, int32, int32) override {return 0;}
        int64 Seek(int64, SeekOrigin) override {return 0;}

      private:
        bool GetCanRead() const override {return true;}
        bool GetCanSeek() const override {return true;}
        bool GetCanWrite() const override {return true;}
        int64 GetLength() const override {return 0;}
        int64 GetPosition() const override {return 0;}
      };
    }
  }
}

/// @cond
inline System::IO::Stream& operator<<(System::IO::Stream& stream, const string& value) {
  static System::Text::UTF8Encoding utf8Encoding(false);
  System::Array<byte> bytes = utf8Encoding.GetBytes(value);
  if (bytes.Length != 0)
    stream.Write(bytes, 0,  bytes.Length);
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, const char* value) {
  stream << string(value);
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, const wchar* value) {
  stream << string(value);
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, const char16* value) {
  stream << string(value);
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, const char32* value) {
  stream << string(value);
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, const std::string& value) {
  stream << string(value);
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, const std::wstring& value) {
  stream << string(value);
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, bool value) {
  stream << System::Boolean(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, byte value) {
  stream << System::Byte(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, char value) {
  stream << System::Char(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, wchar value) {
  stream << System::Char(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, char16 value) {
  stream << System::Char(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, char32 value) {
  stream << System::Char(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, double value) {
  stream << System::Double(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, int16 value) {
  stream << System::Int16(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, int32 value) {
  stream << System::Int32(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, int64 value) {
  stream << System::Int64(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, void* value) {
  stream << System::IntPtr((intptr)value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, sbyte value) {
  stream << System::SByte(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, float value) {
  stream << System::Single(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, uint16 value) {
  stream << System::UInt16(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, uint32 value) {
  stream << System::UInt32(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, uint64 value) {
  stream << System::UInt64(value).ToString();
  return stream;
}

inline System::IO::Stream& operator<<(System::IO::Stream& stream, const object& value) {
  stream << value.ToString();
  return stream;
}
/// @endcond

using namespace Switch;
