/// @file
/// @brief Contains Switch::System::IO::DirectoryInfo class.
#pragma once

#include "../../Types.hpp"
#include "../Array.hpp"
#include "../String.hpp"
#include "FileInfo.hpp"
#include "FileSystemInfo.hpp"
#include "IOException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Exposes instance methods for creating, moving, and enumerating through directories and subdirectories. This class cannot be inherited.
      class core_export_ DirectoryInfo final : public FileSystemInfo {
      public:
        /// @brief Represents the uninitialized directory object. This field is constant.
        static const DirectoryInfo Empty;

        /// @brief Initializes a new instance of the System::IO::DirectoryInfo class on the specified path.
        DirectoryInfo() { }

        /// @brief Initializes a new instance of the System::IO::DirectoryInfo class on the specified path.
        /// @param path A string specifying the path on which to create the DirectoryInfo.
        /// @exception ArgumentException path is null -or- path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        DirectoryInfo(const String& path);

        /// @cond
        DirectoryInfo(const DirectoryInfo& directoryInfo) : FileSystemInfo(directoryInfo) { }
        DirectoryInfo& operator=(const DirectoryInfo& directoryInfo) {this->FileSystemInfo::operator=(directoryInfo); return *this;}
        /// @endcond

        /// @brief Gets the parent directory of a specified subdirectory.
        /// @return The parent directory, or the empty directory if the path is null or if the file path denotes a root (such as "\", "C:", or * "\\server\share").
        property_<DirectoryInfo, readonly_> Parent {
          get_ {return this->GetParent();}
        };

        /// @brief Gets the root portion of a path.
        /// @return A System::IO::DirectoryInfo object representing the root of a path.
        property_<DirectoryInfo, readonly_> Root {
          get_ {return this->GetRoot();}
        };

        /// @brief Creates a directory.
        /// @exception IO::IOException The directory cannot be created.
        void Create();

        /// @brief Creates a subdirectory or subdirectories on the specified path. The specified path can be relative to this instance of the System::IO::DirectoryInfo class.
        /// @param path The specified path. This cannot be a different disk volume or Universal Naming Convention (UNC) name.
        /// @return The last directory specified in path.
        /// @exception IO::IOException The subdirectory cannot be created.
        DirectoryInfo CreateSubdirectory(const String& path);

        /// @brief Deletes this System::IO::DirectoryInfo if it is empty.
        /// @exception DirectoryNotFoundException The directory described by this System::IO::DirectoryInfo object does not exist - or - could not be found.
        /// @exception IOEexception The directory is not empty. -or- The directory is the application's current working directory.
        void Delete() override {return this->Delete(false);}

        /// @brief Deletes this instance of a System::IO::DirectoryInfo, specifying whether to delete subdirectories and files.
        /// @param recursive true to delete this directory, its subdirectories, and all files; otherwise false.
        /// @exception UnauthorizedAccessException The caller does not have the required permission
        /// @exception IO::IOException The directory is the application's current working directory.
        void Delete(bool recursive);

        /// @brief Returns a file list from the current directory.
        Array<FileInfo> GetFiles() const {return GetFiles("*");}

        /// @brief Returns a file list from the current directory.
        /// @param searchPattern The search string, such as "System*", used to search for all files beginning with the word "System".
        /// @return An array of FileInfo objects.
        /// @exception ArgmentException searchPattern is null or contains one or more of the invalid characters
        Array<FileInfo> GetFiles(const String& searchPattern) const;

        /// @brief Returns the subdirectories of the current directory.
        /// @return An array of DirectoryInfo objects.
        Array<DirectoryInfo> GetDirectories() const {return GetDirectories("*");}

        /// @brief Returns the subdirectories of the current directory.
        /// @param searchPattern The search string, such as "System*", used to search for all directories beginning with the word "System".
        /// @return An array of DirectoryInfo objects.
        /// @exception ArgmentException searchPattern is null or contains one or more of the invalid characters
        Array<DirectoryInfo> GetDirectories(const String& searchPattern) const;

        /// @brief Moves a System::IO::DirectoryInfo instance and its contents to a new path.
        /// @param destDirName The name and path to which to move this directory. The destination cannot be another disk volume or a directory with the identical name. It can be an existing directory to which you want to add this directory as a subdirectory.
        /// @exception ArgumentNullException destDirName is null.
        /// @exception ArgumentException destDirName is an empty string (''").
        /// @exception IOException An attempt was made to move a directory to a different volume. -or- destDirName already exists. -or- You are not authorized to access this path. -or- The directory being moved and the destination directory have the same name.
        /// @exception DirectoryNotFoundException The destination directory cannot be found.
        void MoveTo(const String& destDirName);

        /// @brief Determines whether this instance of DirectoryInfo and a specified DirectoryInfo have the same value.
        /// @param value The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const DirectoryInfo& value) const {return this->fullPath.Equals(value.fullPath);}

        /// @brief Determines whether this instance of DirectoryInfo and a specified object, which must also be a DirectoryInfo object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override {return is<DirectoryInfo>(obj) && Equals((const DirectoryInfo&)obj);}

        /// @brief Returns the original path that was passed by the user.
        /// @return the original path that was passed by the user.
        String ToString() const override {return this->Name;}

      private:
        bool GetExists() const override;
        String GetName() const override;
        DirectoryInfo GetParent() const;
        DirectoryInfo GetRoot() const;
      };
    }
  }
}

using namespace Switch;
