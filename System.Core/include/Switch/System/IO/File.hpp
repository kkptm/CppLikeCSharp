/// @file
/// @brief Contains Switch::System::IO::File class.
#pragma once

#include "../../Static.hpp"
#include "../../Types.hpp"
#include "../Array.hpp"
#include "../String.hpp"
#include "../Collections/Generic/IEnumerable.hpp"
#include "../Text/Encoding.hpp"
#include "FileAccess.hpp"
#include "FileAttributes.hpp"
#include "FileMode.hpp"
#include "FileStream.hpp"
#include "IOException.hpp"
#include "Stream.hpp"
#include "StreamReader.hpp"
#include "StreamWriter.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Provides static methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of System::IO::FileStream objects.
      class core_export_ File static_ {
      public:
        /// @brief Appends lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
        /// @param path The file to write to.
        /// @param contents The lines to append to the file.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void AppendAllLines(const String& path, const Collections::Generic::IEnumerable<String>& contents);

        /// @brief Appends lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
        /// @param path The file to write to.
        /// @param contents The lines to append to the file.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void AppendAllLines(const String& path, const Array<String>& contents);

        /// @brief Appends lines to a file by using a specified encoding, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
        /// @param path The file to write to.
        /// @param contents The lines to append to the file.
        /// @param encoding The character encoding to use.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void AppendAllLines(const String& path, const Collections::Generic::IEnumerable<String>& contents, Text::Encoding& encoding);

        /// @brief Appends lines to a file by using a specified encoding, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
        /// @param path The file to write to.
        /// @param contents The lines to append to the file.
        /// @param encoding The character encoding to use.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void AppendAllLines(const String& path, const Array<String>& contents, Text::Encoding& encoding);

        /// @brief Appends text to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
        /// @param path The file to write to.
        /// @param contents The text to append to the file.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void AppendAllText(const String& path, const String& contents);

        /// @brief Appends text to a file by using a specified encoding, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
        /// @param path The file to write to.
        /// @param contents The text to append to the file.
        /// @param encoding The character encoding to use.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void AppendAllText(const String& path, const String& contents, Text::Encoding& encoding);

        /// @brief Creates a System::IO::StreamWriter that appends UTF-8 encoded text to an existing file.
        /// @param path The path to the file to append to.
        /// @return A StreamWriter that appends UTF-8 encoded text to an existing file.
        /// @exception ArgumentException path is null  -or- path contains one or more of the invalid characters  -or- The system could not retrieve the absolute path.
        /// @exception IOException the handle of the specified file cannot be opened
        static StreamWriter AppendText(const String& path);

        /// @brief Copies an existing file to a new file. Overwriting a file of the same name is not allowed.
        /// @param src The file to be opened for reading.
        /// @param dest The name of the destination file. This cannot be a directory or an existing file.
        /// @return None.
        /// @remarks The destination path must be on the same volume as the source.
        /// @exception DirectpryNotFoundException the original file does not exist
        /// @exception ArgumentException dest is null  -or- dest contains one or more of the invalid characters  -or- The system could not retrieve the absolute path of dest.
        /// @exception IO::IOException An error occurs, or the destination file already exists.
        static void Copy(const String& src, const String& dest);

        /// @brief Copies an existing file to a new file. Overwriting a file of the same name is allowed.
        /// @param src The file to be opened for reading.
        /// @param dest The name of the destination file. This cannot be a directory.
        /// @param overwrite true if the destination file can be overwritten; otherwise, false.
        /// @return A System::IO::StreamReader on the specified path.
        /// @remarks The destination path must be on the same volume as the source.
        /// @exception DirectoryNotFoundException the original file does not exist
        /// @exception ArgumentException dest is null  -or- dest contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path of dest.
        /// @exception IO::IOException destFileName is read-only, or destFileName exists and overwrite is false.  -or-  An I/O error has occurred.
        static void Copy(const String& src, const String& dest, bool overwrite);

        /// @brief Creates or overwrites a file in the specified path.
        /// @param The path and name of the file to create.
        /// @return A FileStream that provides read/write access to the file specified in path.
        static FileStream Create(const String& path) {return FileStream(path, FileMode::Create);}

        /// @brief Deletes the specified file.
        /// @param path The name of the file to be deleted.
        /// @return FileStream An unshared FileStream that provides access to the specified file, with the specified mode and access.
        /// @exception ArgumentException path is null  -or-  path contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path.
        /// @exception UnauthorizedAccessException The caller does not have the required permission.  -or-  path is a directory.  -or-  path specified a read-only file.
        static void Delete(const String& path);

        /// @brief Determines whether the specified file exists.
        /// @param path The file to check.
        /// @return true if the caller has the required permissions and path contains the name
        /// @return of an existing file; otherwise, false. This method also returns false if
        /// @return path is null, an invalid path, or a zero-length System::String. If the caller does
        /// @return not have sufficient permissions to read the specified file, no exception
        /// @return is thrown and the method returns false regardless of the existence of path.
        static bool Exists(const String& path);

        /// @brief Opens a FileStream on the specified path.
        /// @param path The file to open.
        /// @param mode A FileMode value that specifies whether a file is created if one does not exist, and determines whether the contents of existing files are retained or overwritten.
        /// @param access A FileAccess value that specifies the operations that can be performed on the file.
        /// @return FileStream An unshared FileStream that provides access to the specified file, with the specified mode and access.
        /// @exception ArgumentException path is null  -or-  path contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path.
        /// @exception ArgumentException specifying FileModeOpen and the file specified by path does not exist  -or-  specifying FileModeCreate with FileAccessRead  -or-  specifying FileModeOpenOrCreate with FileAccessRead and the specified file does not exist
        /// @exception DirectoryNotFoundException specifying FileModeOpen and the file specified by path does not exist  -or-  specifying FileModeTruncate and the specified file does not exist  -or-  specifying FileModeAppend and the specified file does not exist
        /// @exception IOException the handle of the specified file cannot be opened
        static FileStream Open(const String& path, FileMode mode, FileAccess access);

        /// @brief Opens an existing file for reading.
        /// @param path The file to be opened for reading.
        /// @return A read-only System::IO::FileStream on the specified path.
        /// @exception ArgumentException path is null  -or-  path contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path.
        /// @exception DirectoryNotFoundException the file specified by path does not exist
        /// @exception IOException the handle of the specified file cannot be opened
        static FileStream OpenRead(const String& path);

        /// @brief Opens an existing file for writing.
        /// @param path The file to be opened for writing.
        /// @return An unshared System::IO::FileStream object on the specified path with System::IO::FileAccess.Write
        /// @return access.
        /// @exception ArgumentException path is null  -or-  path contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path.
        /// @exception IOException the handle of the specified file cannot be opened
        static FileStream OpenWrite(const String& path);

        /// @brief Creates or opens a file for writing UTF-8 encoded text.
        /// @param path The file to be opened for writing.
        /// @return A System::IO::StreamWriter that writes to the specified file using UTF-8 encoding.
        /// @exception ArgumentException path is null  -or-  path contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path.
        /// @exception IOException the handle of the specified file cannot be opened
        static StreamWriter CreateText(const String& path);

        /// @brief Opens an existing UTF-8 encoded text file for reading.
        /// @param path The file to be opened for reading.
        /// @return A System::IO::StreamReader on the specified path.
        /// @exception ArgumentException path is null  -or-  path contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path.
        /// @exception DirectoryNotFoundException the file specified by path does not exist
        static StreamReader OpenText(const String& path);

        /// @brief Gets the System::IO::FileAttributes of the file on the path.
        /// @param src The path to the file.
        /// @return The System::IO::FileAttributes of the file on the path.
        /// @exception ArgumentException path is null  -or-  path contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path.
        static FileAttributes GetAttributes(const String& src);

        /// @brief Moves a specified file to a new location, providing the option to specify a new file name.
        /// @param src The name of the file to move.
        /// @param dest The new path for the file.
        /// @exception ArgumentException src or dest is null  -or-  src or dest contains one or more of the invalid characters  -or-  The system could not retrieve the absolute path.
        /// @exception IO::IOException An I/O error occurs, such as the destination file already exists
        /// @exception DirectoryNotFoundException The file is not found.
        static void Move(const String& src, const String& dest);

        /// @brief Opens a text file, reads all lines of the file, and then closes the file.
        /// @param path The file to open for reading.
        /// @return A System::String array containing all lines of the file.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception FileNotFoundException The file specified in path was not found.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks This method opens a file, reads each line of the file, then adds each line as an element of a System::String array. It then closes the file. A line is defined as a sequence of characters followed by a carriage return ('\r'), a line feed ('\n'), or a carriage return immediately followed by a line feed. The resulting System::String does not contain the terminating carriage return and/or line feed.
        /// @remarks This method attempts to automatically detect the encoding of a file based on the presence of byte order marks. Encoding formats UTF-8 and UTF-32 (both big-endian and little-endian) can be detected.
        static Array<String> ReadAllLines(const String& path);

        /// @brief Opens a file, reads all lines of the file with the specified encoding, and then closes the file.
        /// @param path The file to open for reading.
        /// @param encoding The encoding applied to the contents of the file.
        /// @return A System::String array containing all lines of the file.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception FileNotFoundException The file specified in path was not found.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks This method opens a file, reads each line of the file, then adds each line as an element of a System::String array. It then closes the file. A line is defined as a sequence of characters followed by a carriage return ('\r'), a line feed ('\n'), or a carriage return immediately followed by a line feed. The resulting System::String does not contain the terminating carriage return and/or line feed.
        /// @remarks This method attempts to automatically detect the encoding of a file based on the presence of byte order marks. Encoding formats UTF-8 and UTF-32 (both big-endian and little-endian) can be detected.
        static Array<String> ReadAllLines(const String& path, Text::Encoding& encoding);

        /// @brief Opens a text file, reads all text of the file, and then closes the file.
        /// @param path The file to open for reading.
        /// @return A System::String containing all text of the file.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception FileNotFoundException The file specified in path was not found.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks This method opens a file, reads each line of the file, then adds each line as an element of a System::String array. It then closes the file. A line is defined as a sequence of characters followed by a carriage return ('\r'), a line feed ('\n'), or a carriage return immediately followed by a line feed. The resulting System::String does not contain the terminating carriage return and/or line feed.
        /// @remarks This method attempts to automatically detect the encoding of a file based on the presence of byte order marks. Encoding formats UTF-8 and UTF-32 (both big-endian and little-endian) can be detected.
        static String ReadAllText(const String& path);

        /// @brief Opens a file, reads all text of the file with the specified encoding, and then closes the file.
        /// @param path The file to open for reading.
        /// @param encoding The encoding applied to the contents of the file.
        /// @return A System::String containing all text of the file.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception FileNotFoundException The file specified in path was not found.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks This method opens a file, reads each line of the file, then adds each line as an element of a System::String array. It then closes the file. A line is defined as a sequence of characters followed by a carriage return ('\r'), a line feed ('\n'), or a carriage return immediately followed by a line feed. The resulting System::String does not contain the terminating carriage return and/or line feed.
        /// @remarks This method attempts to automatically detect the encoding of a file based on the presence of byte order marks. Encoding formats UTF-8 and UTF-32 (both big-endian and little-endian) can be detected.
        static String ReadAllText(const String& path, Text::Encoding& encoding);

        /// @brief Creates a new file, write the specified System::String array to the file, and then closes the file.
        /// @param path The file to write to.
        /// @param contents The System::String array to write to the file.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void WriteAllLines(const String& path, const Array<String>& contents);

        /// @brief Creates a new file, write the specified System::String collection to the file, and then closes the file.
        /// @param path The file to write to.
        /// @param contents The System::String collection to write to the file.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void WriteAllLines(const String& path, const Collections::Generic::IEnumerable<String>& contents);

        /// @brief Creates a new file by using the specified encoding, writes a strings array to the file, and then closes the file.
        /// @param path The file to write to.
        /// @param contents The System::String array to write to the file.
        /// @param encoding The character encoding to use.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void WriteAllLines(const String& path, const Array<String>& contents, Text::Encoding& encoding);

        /// @brief Creates a new file by using the specified encoding, writes a collection of strings to the file, and then closes the file.
        /// @param path The file to write to.
        /// @param contents The System::String collection to write to the file.
        /// @param encoding The character encoding to use.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void WriteAllLines(const String& path, const Collections::Generic::IEnumerable<String>& contents, Text::Encoding& encoding);

        /// @brief Creates a new file, writes the specified System::String to the file, and then closes the file. If the target file already exists, it is overwritten.
        /// @param path The file to write to.
        /// @param contents The System::String to write to the file.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void WriteAllText(const String& path, const String& contents);

        /// @brief Creates a new file, writes the specified System::String to the file using the specified encoding, and then closes the file. If the target file already exists, it is overwritten.
        /// @param path The file to write to.
        /// @param contents The System::String to write to the file.
        /// @param encoding The character encoding to use.
        /// @exception ArgumentException path is a zero-length System::String, contains only white space, or contains one or more invalid characters as defined by InvalidPathChars.
        /// @exception ArgumentNullException path is null.
        /// @exception PathTooLongException The specified path, file name, or both exceed the system-defined maximum length. For example, on Windows-based platforms, paths must be less than 248 characters, and file names must be less than 260 characters.
        /// @exception DirectoryNotFoundException The specified path is invalid (for example, it is on an unmapped drive).
        /// @exception IOException An I/O error occurred while opening the file.
        /// @exception UnauthorizedAccessException path specified a file that is read-only.  -or-  This operation is not supported on the current platform.  -or-  path specified a directory.  -or-  The caller does not have the required permission.
        /// @exception NotSupportedException path is in an invalid format.
        /// @exception SecurityException The caller does not have the required permission.
        /// @remarks If the target file already exists, it is overwritten.
        /// @remarks The default behavior of the WriteAllLines method is to write out data using UTF-8 encoding without a byte order mark (BOM). If it is necessary to include a UTF-8 identifier, such as a byte order mark, at the beginning of a file, use the WriteAllLines(String, String[], Encoding) method overload with UTF8 encoding.
        /// @remarks Given a System::String array and a file path, this method opens the specified file, writes the System::String array to the file, and then closes the file.
        static void WriteAllText(const String& path, const System::String& contents, Text::Encoding& encoding);
      };
    }
  }
}

using namespace Switch;
