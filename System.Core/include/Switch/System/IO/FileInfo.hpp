/// @file
/// @brief Contains Switch::System::IO::FileInfo class.
#pragma once

#include "../../Types.hpp"
#include "../String.hpp"
#include "FileAccess.hpp"
#include "FileMode.hpp"
#include "FileStream.hpp"
#include "FileSystemInfo.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @cond
      class DirectoryInfo;
      class FileStream;
      /// @endcond

      /// @brief Provides instance methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of System::IO::FileStream objects.
      /// This class cannot be inherited.
      class core_export_ FileInfo final : public FileSystemInfo {
      public:
        /// @brief Represents the uninitialized file object. This field is constant.
        static const FileInfo Empty;

        /// @brief Initializes a new instance of the System::IO::FileInfo class, which acts as a wrapper for a file path.
        FileInfo();

        /// @brief Initializes a new instance of the System::IO::FileInfo class, which acts as
        /// a wrapper for a file path.
        /// @param fileName The fully qualified name of the new file, or the relative file name.
        /// @exception ArgumentException fileName is null
        /// -or- fileName contains one or more of the invalid characters
        /// -or- The system could not retrieve the absolute path.
        FileInfo(const String& fileName);

        /// @cond
        FileInfo(const FileInfo& fileInfo);
        FileInfo& operator=(const FileInfo& fileInfo) {this->FileSystemInfo::operator=(fileInfo); return *this;}
        /// @endcond

        /// @brief Gets an instance of the parent directory.
        /// @return A System::IO::DirectoryInfo object representing the parent directory of this file.
        property_<DirectoryInfo, readonly_> Directory;

        /// @brief Gets a string representing the directory's full path.
        /// @return A string representing the directory's full path.
        property_<String, readonly_> DirectoryName {
          get_ {return this->GetDirectoryName();}
        };

        /// @brief Permanently deletes a file.
        /// @exception Security::SecurityException  The caller does not have the required permission.  -or- path is a directory. -or- path specified a read-only file.
        void Delete() override;

        /// @brief Copies an existing file to a new file, disallowing the overwriting of an
        /// existing file.
        /// @param destFileName The name of the new file to copy to.
        /// @return A new file with a fully qualified path.
        /// @exception FileNotFoundException the original file does not exist
        /// @exception ArgumentException destFileName is null
        /// -or- destFileName contains one or more of the invalid characters
        /// -or- The system could not retrieve the absolute path of destFileName.
        /// @exception IOException An error occurs, or the destination file already exists.
        FileInfo CopyTo(const String& destFileName);

        /// @brief Copies an existing file to a new file, allowing the overwriting of an existing file.
        /// @param destFileName The name of the new file to copy to.
        /// @param overwrite true to allow an existing file to be overwritten; otherwise, false.
        /// @return A new file, or an overwrite of an existing file if overwrite is true. If the file exists and overwrite is false, an System::IO::IOException is thrown.
        /// @exception FileNotFoundException the original file does not exist
        /// @exception ArgumentException destFileName is null
        /// -or- destFileName contains one or more of the invalid characters
        /// -or- The system could not retrieve the absolute path of destFileName.
        /// @exception IOException destFileName is read-only, or destFileName exists and overwrite is false.
        /// -or- An I/O error has occurred.
        FileInfo CopyTo(const String& destFileName, bool overwrite);

        /// @brief Moves a specified file to a new location, providing the option to specify
        /// a new file name.
        /// @param destFileName The path to move the file to, which can specify a different file name.
        /// @exception IOException An I/O error occurs, such as the destination file already exists
        /// @exception FileNotFoundException The file is not found.
        /// @exception ArgumentException destFileName is null
        /// -or- destFileName contains one or more of the invalid characters
        /// -or- The system could not retrieve the absolute path of destFileName.
        void MoveTo(const String& destFileName);

        /// @brief Gets the size, in bytes, of the current file.
        /// @return The size of the current file in bytes.
        int64 GetLength() const;

        /// @brief Opens a file in the specified mode with read, write, or read/write access.
        /// @param mode A System::IO::FileMode constant specifying the mode (for example, Open or Append)
        /// in which to open the file.
        /// @param access A System::IO::FileAccess constant specifying whether to open the file with
        /// Read, Write, or ReadWrite file access.
        /// @return A System::IO::FileStream object opened in the specified mode and access, and unshared.
        /// @exception ArgumentException specifying FileModeOpen and the file specified by path does not exist
        /// -or- specifying FileModeCreate with FileAccessRead
        /// -or- specifying FileModeOpenOrCreate with FileAccessRead and the specified file does not exist
        /// @exception DirectoryNotFoundException specifying FileModeOpen and the file specified by path does not exist
        /// -or- specifying FileModeTruncate and the specified file does not exist
        /// -or- specifying FileModeAppend and the specified file does not exist
        /// @exception IOException the handle of the specified file cannot be opened
        FileStream Open(FileMode mode, FileAccess access);

        /// @brief Creates a read-only System::IO::FileStream.
        /// @return A new read-only System::IO::FileStream object.
        /// @exception DirectoryNotFoundException the file specified by path does not exist
        /// @exception IOException the handle of the specified file cannot be opened
        FileStream OpenRead();

        /// @brief Creates a write-only System::IO::FileStream.
        /// @return A new write-only unshared System::IO::FileStream object.
        /// @exception IOException the handle of the specified file cannot be opened
        FileStream OpenWrite();

        /// @brief Determines whether this instance of FileInfo and a specified FileInfo have the same value.
        /// @param value The object to compare with the current object.
        /// @return Boolean true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const FileInfo& value) const;

        /// @brief Determines whether this instance of FileInfo and a specified object, which must also be a FileInfo object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override;

        /// @brief Returns the full path.
        /// @return the full path.
        String ToString() const override;

      private:
        DirectoryInfo GetDirectory() const;
        bool GetExists() const override;
        String GetDirectoryName() const;
        String GetName() const override;
      };
    }
  }
}

using namespace Switch;
