/// @file
/// @brief Contains Switch::System::IO::FileStream class.
#pragma once

#include <fstream>

#include "../../Types.hpp"
#include "../ObjectDisposedException.hpp"
#include "../String.hpp"
#include "FileAccess.hpp"
#include "FileMode.hpp"
#include "FileShare.hpp"
#include "Stream.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Exposes a System::IO::Stream around a file, supporting both synchronous and asynchronous read and write operations.
      class core_export_ FileStream: public Stream {
      public:
        /// @brief Initializes a new instance of the System::IO::FileStream class.
        /// @param path A relative or absolute path for the file that the current FileStream object will encapsulate
        /// @param mode A FileMode constant that determines how to open or create the file
        FileStream(const String& path, FileMode mode) : FileStream(path, mode, mode == FileMode::Append ? FileAccess::Write : FileAccess::ReadWrite, FileShare::None) {}

        /// @brief Initializes a new instance of the System::IO::FileStream class.
        /// @param path A relative or absolute path for the file that the current FileStream object will encapsulate
        /// @param mode A FileMode constant that determines how to open or create the file
        /// @param access A FileAccess constant that determines how the file can be accessed by the FileStream object. This gets the CanRead and CanWrite properties of the FileStream object. CanSeek is true if path specifies a disk file.
        /// @exception ArgumentException path is null  -or-   path contains one or more of the invalid characters  -or-   The system could not retrieve the absolute path.
        /// @exception ArgumentException specifying FileModeOpen and the file specified by path does not exist  -or-  specifying FileModeCreate with FileAccessRead  -or- specifying FileModeOpenOrCreate with FileAccessRead and the specified file does not exist
        /// @exception DirectoryNotFoundException specifying FileModeOpen and the file specified by path does not exist  -or-  specifying FileModeTruncate and the specified file does not exist  -or-  specifying FileModeAppend and the specified file does not exist
        /// @exception IOError the handle of the specified file cannot be opened
        FileStream(const String& path, FileMode mode, FileAccess access) : FileStream(path, mode, access, FileShare::None) {}

        /// @brief Initializes a new instance of the System::IO::FileStream class.
        /// @param path A relative or absolute path for the file that the current FileStream object will encapsulate
        /// @param mode A FileMode constant that determines how to open or create the file
        /// @param access A FileAccess constant that determines how the file can be accessed by the FileStream object. This gets the CanRead and CanWrite properties of the FileStream object. CanSeek is true if path specifies a disk file.
        /// @param share A FileShare constant that determines how the file will be shared by processes.
        /// @exception ArgumentException path is null  -or-  path contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path.
        /// @exception ArgumentException specifying FileModeOpen and the file specified by path does not exist  -or- specifying FileModeCreate with FileAccessRead  -or-  specifying FileModeOpenOrCreate with FileAccessRead and the specified file does not exist
        /// @exception DirectoryNotFoundException specifying FileModeOpen and the file specified by path does not exist  -or-  specifying FileModeTruncate and the specified file does not exist  -or-  specifying FileModeAppend and the specified file does not exist
        /// @exception IOError the handle of the specified file cannot be opened
        FileStream(const String& path, FileMode mode, FileAccess access, FileShare share);

        /// @brief Initializes a new instance of the System::IO::FileStream class.
        /// @param path A relative or absolute path for the file that the current FileStream object will encapsulate
        /// @param mode A FileMode constant that determines how to open or create the file
        /// @param bufferSize A positive int32 value greater than 0 indicating the buffer size. For bufferSize values between one and eight, the actual buffer size is set to eight bytes.
        FileStream(const String& path, FileMode mode, int32 bufferSize)  : FileStream(path, mode, FileAccess::Write, FileShare::None) {}

        /// @brief Initializes a new instance of the System::IO::FileStream class.
        /// @param path A relative or absolute path for the file that the current FileStream object will encapsulate
        /// @param mode A FileMode constant that determines how to open or create the file
        /// @param access A FileAccess constant that determines how the file can be accessed by the FileStream object. This gets the CanRead and CanWrite properties of the FileStream object. CanSeek is true if path specifies a disk file.
        /// @param bufferSize A positive int32 value greater than 0 indicating the buffer size. For bufferSize values between one and eight, the actual buffer size is set to eight bytes.
        /// @exception ArgumentException path is null  -or-  path contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path.
        /// @exception ArgumentException specifying FileModeOpen and the file specified by path does not exist  -or-  specifying FileModeCreate with FileAccessRead  -or-  specifying FileModeOpenOrCreate with FileAccessRead and the specified file does not exist
        /// @exception DirectoryNotFoundException specifying FileModeOpen and the file specified by path does not exist  -or-  specifying FileModeTruncate and the specified file does not exist  -or-  specifying FileModeAppend and the specified file does not exist
        /// @exception IOError the handle of the specified file cannot be opened
        FileStream(const String& path, FileMode mode, FileAccess access, int32 bufferSize) : FileStream(path, mode, access, FileShare::None) {}

        /// @brief Initializes a new instance of the System::IO::FileStream class.
        /// @param path A relative or absolute path for the file that the current FileStream object will encapsulate
        /// @param mode A FileMode constant that determines how to open or create the file
        /// @param access A FileAccess constant that determines how the file can be accessed by the FileStream object. This gets the CanRead and CanWrite properties of the FileStream object. CanSeek is true if path specifies a disk file.
        /// @param share A FileShare constant that determines how the file will be shared by processes.
        /// @param bufferSize A positive int32 value greater than 0 indicating the buffer size. For bufferSize values between one and eight, the actual buffer size is set to eight bytes.
        /// @exception ArgumentException path is null  -or-  path contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path.
        /// @exception ArgumentException specifying FileModeOpen and the file specified by path does not exist  -or-  specifying FileModeCreate with FileAccessRead  -or-  specifying FileModeOpenOrCreate with FileAccessRead and the specified file does not exist
        /// @exception DirectoryNotFoundException specifying FileModeOpen and the file specified by path does not exist  -or-  specifying FileModeTruncate and the specified file does not exist  -or-  specifying FileModeAppend and the specified file does not exist
        /// @exception IOError the handle of the specified file cannot be opened
        FileStream(const String& path, FileMode mode, FileAccess access, FileShare share, int32 bufferSize) : FileStream(path, mode, access, share) {}

        /// @cond
        FileStream() {}
        FileStream(const FileStream& fileStream) : data(fileStream.data) {};
        FileStream& operator=(const FileStream& fileStream) {
          this->data = fileStream.data;
          return *this;
        }
        /// @endcond

        /// @brief Gets the name of the FileStream that was passed to the constructor.
        /// @return string that is the name of the FileStream.
        property_<String, readonly_> Name {
          get_ {return this->data->fullPath;}
        };

        /// @brief Closes the current FileStream and releases any resources (such as sockets and file handles) associated with the current stream.
        /// @exception IO::IOException an error occurred while the file is being closed
        void Close() override;

        /// @brief Clears all buffers for this stream and causes any buffered data to be written to the file system.
        /// @exception IO::IOException An I/O error occurs.
        void Flush() override;

        /// @brief Reads a byte from the stream and advances the position within the stream
        /// by one byte, or returns -1 if at the end of the stream.
        /// @return The unsigned byte cast to an int32, or -1 if at the end of the stream.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception NotSupportedException The stream does not support reading.
        /// @exception IO::IOException An I/O error occurs.
        int32 ReadByte() override;

        /// @brief When overridden in a derived class, reads a sequence of bytes from the current stream and advances the position within the stream by the number of bytes read.
        /// @param buffer An array of bytes. When this method returns, the buffer contains the specified byte array with the values between offset and (offset + count - 1) replaced by the bytes read from the current source.
        /// @param bufferLength The length of buffer. (Total number of elements).
        /// @param offset The zero-based byte offset in buffer at which to begin storing the data read from the current stream.
        /// @param count The maximum number of bytes to be read from the current stream.
        /// @return The total number of bytes read into the buffer. This can be less than the number of bytes requested if that many bytes are not currently available, or zero (0) if the end of the stream has been reached.
        /// @exception ArgumentException The sum of offset and count is greater than the buffer length specified bufferLength.
        /// @exception ArgumentNullException buffer is null.
        /// @exception ArgumentOutOfRangeException offset or count is negative.
        /// @exception ObjectDisposedException The stream is closed.
        /// @exception NotSupportedException The stream does not support writing.
        /// @exception IO::IOException An I/O error occurs.
        int32 Read(Array<byte>& buffer, int32 offset, int32 count) override;

        /// @brief When overridden in a derived class, sets the position within the current stream.
        /// @param offset A byte offset relative to the origin parameter.
        /// @param origin A value of type SeekOrigin indicating the reference point used to obtain the new position
        /// @return The new position within the current stream.
        int64 Seek(int64 offset, SeekOrigin origin) override;

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
        void Write(const Array<byte>& buffer, int32 offset, int32 count) override;

      private:
        bool GetCanRead() const override {return (this->data->fileAccess != FileAccess::Write);}
        bool GetCanSeek() const override {return true;}
        bool GetCanWrite() const override {return this->data->fileAccess != FileAccess::Read;}
        int64 GetLength() const override;
        void SetLength(int64 length) override;
        int64 GetPosition() const override;
        bool GetIsClosed() const override;

        friend class StreamReader;
        int32 Peek();

        struct FileStreamData {
          FileMode fileMode = FileMode::Open;
          FileAccess fileAccess = FileAccess::Read;
          String fullPath;
          std::fstream stream;
          std::fstream::openmode openMode = (std::fstream::openmode)0;
        };

        refptr<FileStreamData> data = new FileStreamData();
      };
    }
  }
}

using namespace Switch;
