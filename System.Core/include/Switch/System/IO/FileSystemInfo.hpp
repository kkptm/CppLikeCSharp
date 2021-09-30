/// @file
/// @brief Contains Switch::System::IO::FileSystemInfo class.
#pragma once

#include "../../Types.hpp"
#include "../../Abstract.hpp"
#include "../DateTime.hpp"
#include "../String.hpp"
#include "FileAttributes.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Provides the base class for both System::IO::FileInfo and System::IO::DirectoryInfo objects.
      class core_export_ FileSystemInfo abstract_ {
      protected:
        /// @brief Initializes a new instance of the System::IO::FileSystemInfo class.
        FileSystemInfo() { }

        /// @cond
        FileSystemInfo(const FileSystemInfo& fileSystemInfo) : fullPath(fileSystemInfo.fullPath) { }
        FileSystemInfo& operator=(const FileSystemInfo& fileSystemInfo) {this->fullPath = fileSystemInfo.fullPath; return *this;}
        /// @endcond

      public:
        /// @brief Gets the System::IO::FileAttributes of the current System::IO::FileSystemInfo.
        /// @return System::IO::FileAttributes of the current System::IO::FileSystemInfo.
        /// @exception IOErrorException system error when retrieving the file information
        property_<FileAttributes, readonly_> Attributes {
          get_ {return this->GetAttributes();}
        };

        /// @brief Gets the creation time
        /// @return The creation date and time
        /// @exception IOErrorException system error when retrieving the file information
        property_<DateTime, readonly_> CreationTime {
          get_ {return this->GetCreationTime();}
        };

        /// @brief Gets the creation time, in coordinated universal time (UTC)
        /// @return The creation date and time
        /// @exception IOErrorException system error when retrieving the file information
        property_<DateTime, readonly_> CreationTimeUtc {
          get_ {return this->GetCreationTimeUtc();}
        };

        /// @brief Gets a value indicating whether the file or directory exists.
        /// @return true if the file or directory exists; otherwise, false.
        property_<bool, readonly_> Exists {
          get_ {return this->GetExists();}
        };

        /// @brief Gets the string representing the extension part of the file.
        /// @return A string containing the System::IO::FileSystemInfo extension.
        property_<String, readonly_> Extension {
          get_ {return this->GetExtension();}
        };

        /// @brief Gets the full path of the directory or file.
        /// @return A string containing the full path.
        property_<String, readonly_> FullName {
          get_ {return this->GetFullName();}
        };

        /// @brief Gets the time the current file or directory was last accessed.
        /// @return The time that the current file or directory was last accessed.
        /// @exception IOErrorException system error when retrieving the file information
        property_<DateTime, readonly_> LastAccessTime {
          get_ {return this->GetLastAccessTime();}
        };

        /// @brief Gets the time, in coordinated universal time (UTC), of the current file or directory was last accessed.
        /// @return The time that the current file or directory was last accessed.
        /// @exception IOErrorException system error when retrieving the file information
        property_<DateTime, readonly_> LastAccessTimeUtc {
          get_ {return this->GetLastAccessTimeUtc();}
        };

        /// @brief Gets or sets the time when the current file or directory was last written to.
        /// @return The time the current file was last written.
        /// @exception IOErrorException system error when retrieving the file information
        property_<DateTime, readonly_> LastWriteTime {
          get_ {return this->GetLastWriteTime();}
        };

        /// @brief Gets or sets the time, in coordinated universal time (UTC), when the current file or directory was last written to.
        /// @return The time the current file was last written.
        /// @exception IOErrorException system error when retrieving the file information
        property_<DateTime, readonly_> LastWriteTimeUtc {
          get_ {return this->GetLastWriteTimeUtc();}
        };

        /// @brief For files, gets the name of the file. For directories, gets the name of the last directory in the hierarchy if a hierarchy exists. Otherwise, the Name property gets the name of the directory.
        /// @return A string that is the name of the parent directory, the name of the last directory in the hierarchy, or the name of a file, including the file name extension.
        property_<String, readonly_> Name {
          get_ {return this->GetName();}
        };

        /// @brief Deletes a file or directory.
        /// @return zero if successful, otherwise an error code indicating the reason of the failure
        virtual void Delete() = 0;

        /// @brief Indicates whether the specified file system object is initialized.
        /// @return bool true if the value parameter is an uninitialized file system object; otherwise, false.
        static bool IsNullOrEmpty(const FileSystemInfo& fileSystemInfo);

      protected:
        /// @brief Gets a value indicating whether the file or directory exists.
        /// @return true if the file or directory exists; otherwise, false.
        virtual bool GetExists() const = 0;

        /// @brief Gets the full path of the directory or file.
        /// @return A string containing the full path.
        virtual String GetFullName() const { return this->fullPath; }

        /// @brief For files, gets the name of the file. For directories, gets the name of the last directory in the hierarchy if a hierarchy exists. Otherwise, the Name property gets the name of the directory.
        /// @return A string that is the name of the parent directory, the name of the last directory in the hierarchy, or the name of a file, including the file name extension.
        virtual String GetName() const = 0;

        /// @cond
        String fullPath;
        /// @endcond

      private:
        FileAttributes GetAttributes()const;
        DateTime GetCreationTime() const;
        DateTime GetCreationTimeUtc() const;
        String GetExtension() const;
        DateTime GetLastAccessTime()const;
        DateTime GetLastAccessTimeUtc()const;
        DateTime GetLastWriteTime()const;
        DateTime GetLastWriteTimeUtc()const;
      };
    }
  }
}

using namespace Switch;
