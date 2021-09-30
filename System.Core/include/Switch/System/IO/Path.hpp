/// @file
/// @brief Contains Switch::System::IO::Path class.
#pragma once

#include "../../Types.hpp"
#include "../Array.hpp"
#include "../Convert.hpp"
#include "../String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Performs operations on System::string instances that contain file or directory
      /// path information. These operations are performed in a cross-platform manner.
      class core_export_ Path static_ {
      public:
        /// @brief Provides a platform-specific alternate character used to separate directory levels in a path string that reflects a hierarchical file system organization.
        /// @par Examples
        /// The following code example demonstrates the use of the AltDirectorySeparatorChar() property.
        /// @include DirectorySeparatorChar.cpp
        static char32 AltDirectorySeparatorChar();

        /// @brief Provides a platform-specific character used to separate directory levels in a path string that reflects a hierarchical file system organization.
        /// @par Examples
        /// The following code example demonstrates the use of the DirectorySeparatorChar() property.
        /// @include DirectorySeparatorChar.cpp
        static char32 DirectorySeparatorChar();

        /// @brief A platform-specific separator character used to separate path strings in environment variables.
        /// @par Examples
        /// The following code example demonstrates the use of the PathSeparator() property.
        /// @include DirectorySeparatorChar.cpp
        static char32 PathSeparator();

        /// @brief Provides a platform-specific volume separator character.
        /// @par Examples
        /// The following code example demonstrates the use of the VolumeSeparatorChar() property.
        /// @include DirectorySeparatorChar.cpp
        static char32 VolumeSeparatorChar();

        /// @brief Changes the extension of a path string.
        /// @param path The path information to modify. The path cannot contain any of the characters defined in GetInvalidPathChars.
        /// @param extension The new extension (with or without a leading period). Specify null to remove an existing extension from path.
        /// @return string The modified path information.
        /// @note On Windows-based desktop platforms, if path is an empty string (""), the path information is returned unmodified. If extension is empty string (""), the returned string contains the specified path with its extension removed. If path has no extension, and extension is not empty, the returned path string contains extension appended to the end of path.
        /// @remarks If neither path nor extension contains a period (.), ChangeExtension adds the period.
        /// @remarks The extension parameter can contain multiple periods and any valid path characters, and can be any length. If extension is empty (""), the returned string contains the contents of path with the last period and all characters following it removed.
        /// @remarks If extension is an empty string, the returned path string contains the contents of path with any characters following the last period removed.
        /// @remarks If extension does not contain a leading period, the period is added.
        /// @remarks If path contains a multiple extension separated by multiple periods, the returned string contains the contents of path with the last period and all characters following it replaced by extension. For example, if path is "\Dir1\examples\pathtests.csx.txt" and extension is "cs", the modified path is "\Dir1\examples\pathtests.csx.cs".
        /// @remarks It is not possible to verify that the returned results are valid in all scenarios. For example, if path is empty, extension is appended.
        static string ChangeExtension(const string& path, const string& extension);

        /// @brief Combines two path strings.
        /// @param path1 The first path.
        /// @param path2 The second path.
        /// @return A string containing the combined paths. If one of the specified paths is
        /// @return a zero-length string, this method returns the other path. If path2 contains
        /// @return an absolute path, this method returns path2.
        /// @exception ArgumentException path contains one or more of the invalid characters
        static string Combine(const string& path1, const string& path2) {
          if (path1.IndexOfAny(GetInvalidPathChars()) != -1 || path2.IndexOfAny(GetInvalidPathChars()) != -1)
            throw ArgumentException(caller_);

          if (string::IsNullOrEmpty(path2))
            return path1;

          if (string::IsNullOrEmpty(path1) || IsPathRooted(path2))
            return path2;

          return string::Concat(path1, path1.EndsWith(DirectorySeparatorChar()) ? string::Empty : Char(DirectorySeparatorChar()).ToString(), path2);
        }

        /// @brief Combines three path strings.
        /// @param path1 The first path.
        /// @param path2 The second path.
        /// @param path3 The third path.
        /// @return A string containing the combined paths. If one of the specified paths is
        /// @return a zero-length string, this method returns the other path. If path2 contains
        /// @return an absolute path, this method returns path2.
        /// @exception ArgumentException path contains one or more of the invalid characters
        static string Combine(const string& path1, const string& path2, const string& path3) {return Combine(path1, Combine(path2, path3));}

        /// @brief Combines four path strings.
        /// @param path1 The first path.
        /// @param path2 The second path.
        /// @param path3 The third path.
        /// @param path4 The fourth path.
        /// @return A string containing the combined paths. If one of the specified paths is
        /// @return a zero-length string, this method returns the other path. If path2 contains
        /// @return an absolute path, this method returns path2.
        /// @exception ArgumentException path contains one or more of the invalid characters
        static string Combine(const string& path1, const string& path2, const string& path3, const string& path4) {return Combine(path1, Combine(path2, Combine(path3, path4)));}

        /// @brief Combines path strings array.
        /// @param paths The path array.
        /// @return A string containing the combined paths. If one of the specified paths is a zero-length string, this method returns the other path. If path2 contains an absolute path, this method returns path2.
        /// @exception ArgumentException path contains one or more of the invalid characters
        static string Combine(const Array<string>& paths) {
          string result;
          for (auto path : paths)
            result = Combine(result, path);
          return result;
        }

        /// @brief Returns the directory information for the specified path string.
        /// @param path the path of a file or directory.
        /// @return A System::string containing directory information for path, or null if path
        /// @return denotes a root directory, is the empty string (""), or is null. Returns System::string.Empty
        /// @return if path does not contain directory information.
        /// @exception ArgumentException path contains one or more of the invalid characters
        static string GetDirectoryName(const string& path);

        /// @brief Returns the extension of the specified path string.
        /// @param path The path string from which to get the extension.
        /// @return A System::string containing the extension of the specified path (including
        /// @return the "."), null, or System::string.Empty. If path is null, GetExtension returns
        /// @return null. If path does not have extension information, GetExtension returns Empty.
        /// @exception ArgumentException path contains one or more of the invalid characters
        static string GetExtension(const string& path);

        /// @brief Returns the file name and extension of the specified path string.
        /// @param path The path string from which to obtain the file name and extension.
        /// @return A System::string consisting of the characters after the last directory character
        /// @return in path. If the last character of path is a directory or volume separator
        /// @return character, this method returns System::string.Empty. If path is null, this
        /// @return method returns null.
        /// @exception ArgumentException path contains one or more of the invalid characters
        static string GetFileName(const string& path);

        /// @brief Returns the file name of the specified path string without the extension.
        /// @param path The path of the file.
        /// @return A System::string containing the string returned by System::IO::Path.GetFileName(System::string),
        /// @return minus the last period (.) and all characters following it.
        /// @exception ArgumentException path contains one or more of the invalid characters
        static string GetFileNameWithoutExtension(const string& path);

        /// @brief Returns the absolute path for the specified path string.
        /// @param path The file or directory for which to obtain absolute path information.
        /// @return A string containing the fully qualified location of path, such as "C:\\MyFile.txt".
        /// @exception ArgumentException path is null
        /// -or- path contains one or more of the invalid characters
        /// -or- The system could not retrieve the absolute path.
        static string GetFullPath(const string& path);

        /// @brief Gets an array containing the characters that are not allowed in path names.
        /// @return Array<char32>
        /// An array containing the characters that are not allowed in path names.
        /// @remarks The array returned from this method is not guaranteed to contain the complete set of characters that are invalid in file and directory names. The full set of invalid characters can vary by file system. For example, on Windows-based desktop platforms, invalid path characters might include ASCII/Unicode characters 1 through 31, as well as quote ("), less than (<), greater than (>), pipe (|), backspace (\b), null (\0) and tab (\t).
        static Array<char32> GetInvalidPathChars();

        /// @brief Gets the root directory information of the specified path.
        /// @param path The path from which to obtain root directory information.
        /// @return A string containing the root directory of path, such as "C:\", or null if
        /// @return path is null, or an empty string if path does not contain root directory
        /// @return information.
        /// @exception ArgumentException path contains one or more of the invalid characters
        static string GetPathRoot(const string& path);

        /// @brief Returns a random folder name or file name.
        /// @return A random folder name or file name.
        /// @remarks The GetRandomFileName method returns a cryptographically strong, random string that can be used as either a folder name or a file name. Unlike GetTempFileName, GetRandomFileName does not create a file. When the security of your file system is paramount, this method should be used instead of GetTempFileName.
        static string GetRandomFileName();

        /// @brief Returns the path of the current user's temporary folder.
        /// @return string The path to the temporary folder, ending with a backslash.
        /// @remarks This method checks for the existence of environment variables in the following order and uses the first path found:
        /// * The path specified by the TMP environment variable.
        /// * The path specified by the TEMP environment variable.
        /// * The path specified by the USERPROFILE environment variable.
        /// * The Windows directory.
        static string GetTempPath();

        /// @brief Creates a uniquely named, zero-byte temporary file on disk and returns the full path of that file.
        /// @return The full path of the temporary file.
        /// @exception IOException An I/O error occurs, such as no unique temporary file name is available. - or - This method was unable to create a temporary file.
        /// @remarks This method creates a temporary file with a .TMP file extension. The temporary file is created within the user’s temporary folder, which is the path returned by the GetTempPath method.
        /// @remarks The GetTempFileName method will raise an IOException if it is used to create more than 65535 files without deleting previous temporary files.
        /// @remarks The GetTempFileName method will raise an IOException if no unique temporary file name is available. To resolve this error, delete all unneeded temporary files.
        static string GetTempFileName();

        /// @brief Determines whether a path includes a file name extension.
        /// @param path The path to search for an extension.
        /// @return true if the characters that follow the last directory separator (\\ or /)
        /// @return or volume separator (:) in the path include a period (.) followed by one
        /// @return or more characters; otherwise, false.
        /// @exception ArgumentException path contains one or more of the invalid characters
        static bool HasExtension(const string& path) {return !string::IsNullOrEmpty(GetExtension(path));}

        /// @brief Gets a value indicating whether the specified path string contains absolute
        /// or relative path information.
        /// @param path The path to test.
        /// @return true if path contains an absolute path; otherwise, false.
        /// @exception ArgumentException path contains one or more of the invalid characters
        static bool IsPathRooted(const string& path);
      };
    }
  }
}

using namespace Switch;
