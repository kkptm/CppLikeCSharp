/// @file
/// @brief Contains Switch::System::IO::Directory class.
#pragma once

#include "../../Types.hpp"
#include "DirectoryInfo.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Provides static methods for the creation, copying, deletion, moving, and opening of Directories, and aids in the creation of System::IO::DirectoryStream objects.
      class core_export_ Directory static_ {
      public:
        /// @brief Creates all directories and subdirectories as specified by path.
        /// @param path The directory path to create.
        /// @return A System::IO::DirectoryInfo as specified by path.
        /// @exception ArgumentException path is null -or- path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception IO::IOException The subdirectory cannot be created.
        static DirectoryInfo CreateDirectory(const String& path);

        /// @brief Deletes the specified Directory.
        /// @param path The name of the Directory to be deleted.
        /// @return DirectoryStream An unshared DirectoryStream that provides access to the specified Directory, with the specified mode and access.
        /// @exception ArgumentException path is null -or- path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception DirectoryNotFoundException The directory described by this System::IO::DirectoryInfo object does not exist or could not be found.
        /// @exception IO::IOException The directory is not empty. -or- The directory is the application's current working directory.
        static void Delete(const String& path);

        /// @brief Deletes the specified Directory.
        /// @param path The name of the Directory to be deleted.
        /// @param recursive true to remove directories, subdirectories, and files in path; otherwise, false.
        /// @return DirectoryStream An unshared DirectoryStream that provides access to the specified Directory, with the specified mode and access.
        /// @exception ArgumentException path is null -or- path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception UnauthorizedAccessException The caller does not have the required permission
        /// @exception IO::IOException The directory is the application's current working directory.
        static void Delete(const String& path, bool recursive);

        /// @brief Returns an enumerable collection of directory names in a specified path.
        /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
        /// @return Collections::Generic::List<string> An enumerable collection of the full names (including paths) for the directories in the directory specified by path.
        static System::Collections::Generic::Enumerator<string> EnumerateDirectories(const string& path);

        static System::Collections::Generic::Enumerator<string> EnumerateDirectories(const string& path, const string& pattern);

        static System::Collections::Generic::Enumerator<string> EnumerateFiles(const string& path);

        static System::Collections::Generic::Enumerator<string> EnumerateFiles(const string& path, const string& pattern);

        /// @brief Determines whether the given path refers to an existing directory on disk.
        /// @param path The path to test.
        /// @return true if path refers to an existing directory; otherwise, false.
        static bool Exists(const String& path);

        /// @brief Gets the creation date and time of a directory.
        /// @param path The path of the directory.
        /// @return A System::DateTime structure set to the creation date and time for the specified directory. This value is expressed in local time.
        /// @exception ArgumentException path is null -or- path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception IO::IOException system error when retrieving the file information
        static DateTime GetCreationTime(const String& path);

        /// @brief Gets the creation date and time, in Coordinated Universal Time (UTC) format, of a directory.
        /// @param path The path of the directory.
        /// @return A DateTime class set to the creation date and time for the specified directory. This value is expressed in UTC time.
        /// @exception ArgumentException path is null -or- path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception IO::IOException system error when retrieving the file information
        static DateTime GetCreationTimeUtc(const String& path);

        static System::Array<string> GetDirectories(const string& path);

        static System::Array<string> GetDirectories(const string& path, const string& pattern);

        static System::Array<string> GetFiles(const string& path);

        static System::Array<string> GetFiles(const string& path, const string& pattern);

        /// @brief Returns the date and time the specified file or directory was last accessed.
        /// @param path The file or directory for which to obtain access date and time information.
        /// @return A System::DateTime structure set to the date and time the specified file or directory was last accessed. This value is expressed in local time.
        /// @exception ArgumentException path is null -or- path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception IO::IOException system error when retrieving the file information
        static DateTime GetLastAccessTime(const String& path);

        /// @brief Returns the date and time the specified file or directory was last written to.
        /// @param path The file or directory for which to obtain write date and time information.
        /// @return A System::DateTime structure set to the date and time that the specified file or directory was last written to. This value is expressed in local time.
        /// @exception ArgumentException path is null -or- path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception IO::IOException system error when retrieving the file information
        static DateTime GetLastWriteTime(const String& path);

        /// @brief Gets the current working directory of the application.
        /// @return A string containing the path of the current working directory.
        /// @exception IOError An I/O error occurred.
        static String GetCurrentDirectory();

        /// @brief Retrieves the parent directory of the specified path.
        /// @return The parent directory, or null if path is the root directory
        /// @exception ArgumentException path is null -or- path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        static DirectoryInfo GetParent(const String& path);

        /// @brief Moves a file or a directory and its contents to a new location.
        /// @param srcDir The path of the file or directory to move.
        /// @param destDir The path to the new location for sourceDirName. If sourceDirName is a file, then destDirName must also be a file name.
        /// @return The parent directory, or null if path is the root directory
        /// @exception ArgumentException srcDir or destDir is null -or- srcDir or destDir contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
        /// @exception DirectoryNotFoundException The file is not found.
        /// @exception IO::IOException The directory to be moved does not exist.
        /// @exception DirectoryNotFoundException The destination directory cannot be found.
        /// @exception IO::IOException An I/O error occurs, such as the destination file already exists -or- The directory being moved and the destination directory have the same name -or- The directory cannot be created.
        static void Move(const String& srcDir, const String& destDir);
      };
    }
  }
}

using namespace Switch;
