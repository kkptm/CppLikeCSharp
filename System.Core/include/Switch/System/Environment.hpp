/// @file
/// @brief Contains Switch::System::Environment class.
#pragma once

#include "../Property.hpp"
#include "../Static.hpp"
#include "../Types.hpp"
#include "Array.hpp"
#include "Enum.hpp"
#include "EnvironmentVariableTarget.hpp"
#include "NotImplementedException.hpp"
#include "OperatingSystem.hpp"
#include "String.hpp"
#include "Version.hpp"
#include "Collections/Generic/Dictionary.hpp"
#include "Threading/Thread.hpp"

class __start_up__;

/// @cond
namespace Switch {
  namespace System {
    namespace Diagnoastics {
      class Process;
    }
  }
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Provides information about, and means to manipulate, the current environment
    /// and platform. This class cannot be inherited.
    /// @remarks Use the Environment class to retrieve information such as command-line arguments, the exit code, environment variable settings, contents of the call stack, time since last system boot, and the version of the Switch.
    /// @par Examples
    /// The following example demonstrates displays a list of information about the current environment.
    /// @include Environment.cpp
    class core_export_ Environment static_ {
    public:
      /// @enum SpecialFolder
      /// @brief Specifies enumerated constants used to retrieve directory paths to system special folders.
      /// @remarks The system special folders are folders such as Program Files, Programs, System, or Startup, which contain common information. Special folders are set by default by the system, or explicitly by the user, when installing a version of Windows::
      /// @remarks The GetFolderPath method returns the locations associated with this enumeration. The locations of these folders can have different values on different operating systems, the user can change some of the locations, and the locations are localized.
      /// @remarks For more information about special folders, see the KNOWNFOLDERID constants in the Windows documentation.
      /// @see Environment
      enum class SpecialFolder {
        /// @brief The logical Desktop rather than the physical file system location.
        Desktop = 0,
        /// @brief The directory that contains the user's program groups.
        Programs = 2,
        /// @brief The My Documents folder.
        /// This member is equivalent to Personal.
        MyDocuments = 5,
        /// @brief The directory that serves as a common repository for documents.
        /// This member is equivalent to MyDocuments.
        Personal = 5,
        /// @brief The directory that serves as a common repository for the user's favorite items.
        Favorites = 6,
        /// @brief The directory that corresponds to the user's Startup program group.
        /// The system starts these programs whenever a user logs on or starts Windows NT or later, or starts Windows 98.
        Startup = 7,
        /// @brief The directory that contains the user's most recently used documents.
        Recent = 8,
        /// @brief The directory that contains the Send To menu items.
        SendTo = 9,
        /// @brief The directory that contains the Start menu items.
        StartMenu = 11,
        /// @brief The My Music folder.
        MyMusic = 13,
        /// @brief The file system directory that serves as a repository for videos that belong to a user.
        MyVideos = 14,
        /// @brief The directory used to physically store file objects on the desktop.
        /// Do not confuse this directory with the desktop folder itself, which is a virtual folder.
        DesktopDirectory = 16,
        /// @brief The My Computer folder.
        /// The MyComputer constant always yields the empty string ("") because no path is defined for the My Computer folder.
        MyComputer = 17,
        /// @brief A file system directory that contains the link objects that may exist in the My Network Places virtual folder.
        NetworkShortcuts = 19,
        /// @brief A virtual folder that contains fonts.
        Fonts = 20,
        /// @brief The directory that serves as a common repository for document templates.
        Templates = 21,
        /// @brief The file system directory that contains the programs and folders that appear on the Start menu for all users. This special folder is valid only for Windows NT systems.
        CommonStartMenu = 22,
        /// @brief A folder for components that are shared across applications. This special folder is valid only for Windows NT, Windows 2000, and Windows XP systems.
        CommonPrograms = 23,
        /// @brief The file system directory that contains the programs that appear in the Startup folder for all users. This special folder is valid only for Windows NT systems.
        CommonStartup = 24,
        /// @brief The file system directory that contains files and folders that appear on the desktop for all users. This special folder is valid only for Windows NT systems.
        CommonDesktopDirectory = 25,
        /// @brief The directory that serves as a common repository for application-specific data for the current roaming user.
        /// A roaming user works on more than one computer on a network. A roaming user's profile is kept on a server on the network and is loaded onto a system when the user logs on.
        ApplicationData = 26,
        /// @brief The file system directory that contains the link objects that can exist in the Printers virtual folder.
        PrinterShortcuts = 27,
        /// @brief The directory that serves as a common repository for application-specific data that is used by the current, non-roaming user.
        LocalApplicationData = 28,
        /// @brief The directory that serves as a common repository for temporary Internet files.
        InternetCache = 32,
        /// @brief The directory that serves as a common repository for Internet cookies.
        Cookies = 33,
        /// @brief The directory that serves as a common repository for Internet history items.
        History = 34,
        /// @brief The directory that serves as a common repository for application-specific data that is used by all users.
        CommonApplicationData = 35,
        /// @brief The Windows directory or SYSROOT. This corresponds to the %windir% or %SYSTEMROOT% environment variables.
        Windows = 36,
        /// @brief The System directory.
        System = 37,
        /// @brief The program files directory.On a non-x86 system, passing ProgramFiles to the GetFolderPath method returns the path for non-x86 programs. To get the x86 program files directory on a non-x86 system, use the ProgramFilesX86 member.
        ProgramFiles = 38,
        /// @brief The My Pictures folder.
        MyPictures = 39,
        /// @brief The user's profile folder. Applications should not create files or folders at this level; they should put their data under the locations referred to by ApplicationData.
        UserProfile = 40,
        /// @brief The Windows System folder.
        SystemX86 = 41,
        /// @brief The Program Files folder On an x86 system, passing the ProgramFilesX86 member to the Environment.GetFolderPath method returns string.Empty; use the ProgramFiles member instead. You can determine whether Windows is a 32-bit operating system by calling the Environment.Is64BitOperatingSystem property.
        ProgramFilesX86 = 42,
        /// @brief The directory for components that are shared across applications.To get the x86 common program files directory on a non-x86 system, use the ProgramFilesX86 member.
        CommonProgramFiles = 43,
        /// @brief The Program Files folder.
        CommonProgramFilesX86 = 44,
        /// @brief The file system directory that contains the templates that are available to all users. This special folder is valid only for Windows NT systems.
        CommonTemplates = 45,
        /// @brief The file system directory that contains documents that are common to all users. This special folder is valid for Windows NT systems, Windows 95, and Windows 98 systems with Shfolder.dll installed.
        CommonDocuments = 46,
        /// @brief The file system directory that contains administrative tools for all users of the computer.
        CommonAdminTools = 47,
        /// @brief The file system directory that is used to store administrative tools for an individual user. The Microsoft Management Console (MMC) will save customized consoles to this directory, and it will roam with the user.
        AdminTools = 48,
        /// @brief The file system directory that serves as a repository for music files common to all users.
        CommonMusic = 53,
        /// @brief The file system directory that serves as a repository for image files common to all users.
        CommonPictures = 54,
        /// @brief The file system directory that serves as a repository for video files common to all users.
        CommonVideos = 55,
        /// @brief The file system directory that contains resource data.
        Resources = 56,
        /// @brief The file system directory that contains localized resource data.
        LocalizedResources = 57,
        /// @brief This value is recognized in Windows Vista for backward compatibility, but the special folder itself is no longer used.
        CommonOemLinks = 58,
        /// @brief The file system directory that acts as a staging area for files waiting to be written to a CD.
        CDBurning = 59
      };

      /// @brief Specifies options to use for getting the path to a special folder.
      /// @remarks The System.Environment.SpecialFolderOption enumeration is used to define the precise behavior of the Environment.GetFolderPath method.
      enum class SpecialFolderOption {
        /// @brief The path to the folder is verified. If the folder exists, the path is returned. If the folder does not exist, an empty string is returned. This is the default behavior.
        None = 0,
        /// @brief The path to the folder is returned without verifying whether the path exists. If the folder is located on a network, specifying this option can reduce lag time.
        DoNotVerify = 16384,
        /// @brief The path to the folder is created if it does not already exist.
        Create = 32768
      };

      /// @brief Gets the command line for this process.
      /// @return string A string represented the command line for this process.
      /// @remarks This property provides access to the program name and any arguments specified on the command line when the current process was started.
      /// @remarks The program name can include path information, but is not required to do so. Use the GetCommandLineArgs method to retrieve the command-line information parsed and stored in an array of strings.
      /// @remarks The maximum size of the command-line buffer is not set to a specific number of characters; it varies depending on the Windows operating system that is running on the computer.
      /// @par Example
      /// The following example displays its own command line.
      /// @include EnvironmentCommandLine.cpp
      static property_<String, readonly_> CommandLine;

      /// @brief Gets or sets the current working directory.
      /// @param The current working directory. An empty string return value indicates an error,
      /// @exception IO::IOError An I/O error occurred.
      /// @exception ArgumentException Attempted to set to an empty string ("").
      /// @exception ArgumentNullException Attempted to set to null.
      /// @exception IOException An I/O error occurred.
      /// @exception DirectoryNotFoundException Attempted to set a local path that cannot be found.
      /// @exception SecurityException The caller does not have the appropriate permission.
      /// @remarks By definition, if this process starts in the root directory of a local or network drive, the value of this property is the drive name followed by a trailing slash (for example] = "C:\"). If this process starts in a subdirectory, the value of this property is the drive and subdirectory path, without a trailing slash (for example] = "C:\mySubDirectory").
      /// @par Example
      /// The following example demonstrates setting the CurrentDirectory property.
      /// @include EnvironmentCurrentDirectory.cpp
      static property_<string> CurrentDirectory;

      /// @brief Gets a unique identifier for the current managed thread.
      /// @return int32 An integer that represents a unique identifier for this managed thread.
      static property_<int32, readonly_> CurrentManagedThreadId;

      /// @brief Gets or sets the exit code of the process.
      /// @return Int32 A 32-bit signed integer containing the exit code. The default value is zero.
      /// @remarks If the Main method returns void, you can use this property to set the exit code that will be returned to the calling environment. If Main does not return void, this property is ignored. The initial value of this property is zero.
      /// @warning The ExitCode property is a signed 32-bit integer. To prevent the property from returning a negative exit code, you should not use values greater than or equal to 0x80000000.
      /// @remarks Use a non-zero number to indicate an error. In your application, you can define your own error codes in an enumeration, and return the appropriate error code based on the scenario. For example, return a value of 1 to indicate that the required file is not present and a value of 2 to indicate that the file is in the wrong format. For a list of exit codes used by macOS, Linux or Windows, see errno error code documentation (http://en.cppreference.com/w/cpp/error/errno_macros).
      /// @par Example
      /// The following is a simple app named Double.exe that doubles an integer value passed to it as a command-line argument. The value assigns error codes to the ExitCode property to indicate error conditions.
      /// @include EnvironmentExitCode.cpp
      /// The example can then be invoked on macOS from a batch file such as the following, which makes its error codes accessible by using the $? command.
      /// @code
      /// ./EnvironmentExitCode $1
      ///
      /// case $? in
      ///   89) echo "Missing argument";;
      ///   34) echo "Arithmetic overflow";;
      ///   22) echo "Invalid argument";;
      ///   0) echo "Completed Successfully";;
      /// esac
      /// @endcode
      /// The example can then be invoked on linux from a batch file such as the following, which makes its error codes accessible by using the $? command.
      /// @code
      /// ./EnvironmentExitCode $1
      ///
      /// case $? in
      ///   125) echo "Missing argument";;
      ///   34) echo "Arithmetic overflow";;
      ///   22) echo "Invalid argument";;
      ///   0) echo "Completed Successfully";;
      /// esac
      /// @endcode
      /// The example can then be invoked on Windows from a batch file such as the following, which makes its error codes accessible by using the ERRORLEVEL command.
      /// @code
      /// @echo off
      /// EnvironmentExitCode.exe %1
      ///
      /// if ERRORLEVEL 105 (echo Missing argument
      /// ) else if ERRORLEVEL 34 (echo Arithmetic overflow
      /// ) else if ERRORLEVEL 22 (echo Invalid argument
      /// ) else if ERRORLEVEL 0 (echo Completed Successfully
      /// )
      /// @endcode
      /// The following shows some sample output produced by invoking the batch file.
      /// @code
      /// > ./TestEnvironmentExitCode.sh 123
      /// Result: 246
      /// Completed Successfully
      /// > ./TestEnvironmentExitCode.sh 5912323109093
      /// Arithmetic overflow
      /// > ./TestEnvironmentExitCode.sh
      /// Missing argument
      /// > ./TestEnvironmentExitCode.sh "a string"
      /// Invalid argument
      /// @endcode
      /// Note that code for EnvironmentExitCode is identical in function to the following example, except that the former defines an entry point named Main that has no return value, whereas this example defines an entry point named Main that returns an integer.
      /// @include EnvironmentExitCode2.cpp
      static property_<int32> ExitCode;

      /// @brief Gets a value that indicates whether the current application domain is shutting down.
      /// @return bool true if the current application domain is shutting down; otherwise, false.
      /// @remarks At this time the return value is always false.
      static property_<bool, readonly_> HasShutdownStarted;

      /// @brief Determines whether the current operating system is a 64-bit operating system.
      /// @return bool true if the operating system is 64-bit; otherwise, false.
      static property_<bool, readonly_> Is64BitOperatingSystem;

      /// @brief Determines whether the current process is a 64-bit process.
      /// @return bool true if the process is 64-bit; otherwise, false.
      static property_<bool, readonly_> Is64BitProcess;

      /// @brief Gets the NetBIOS name of this local computer.
      /// @return string A string containing the name of this computer.
      /// @exception InvalidOperationException The name of this computer cannot be obtained.
      /// @remarks The name of this computer is established at system startup when the name is read from the registry. If this computer is a node in a cluster, the name of the node is returned.
      /// @par Example
      /// The following example displays the name of the computer that runs the code example. (The machine name is omitted from the example output for security reasons.)
      /// @include EnvironmentMachineName.cpp
      static property_<String, readonly_> MachineName;

      /// @brief Gets the newline string defined for this environment.
      /// @return string A string containing "\r\n" for non-Unix platforms, or a string containing "\n" for Unix platforms.
      /// @remarks The property value of NewLine is a constant customized specifically for the current platform and implementation of the Switch. For more information about the escape characters in the property value, see Character Escapes in Regular Expressions.
      /// @remarks The functionality provided by NewLine is often what is meant by the terms newline, line feed, line break, carriage return, CRLF, and end of line.
      /// @remarks NewLine is automatically appended to text processed by the Console.WriteLine and StringBuilder.AppendLine methods.
      /// @par Example
      /// The following example displays three lines separated by newlines.
      /// @include EnvironmentNewLine.cpp
      static const string NewLine;

      /// @brief Gets an OperatingSystem object that contains the current platform identifier and version number.
      /// @return OperatingSystem An object that contains the platform identifier and version number.
      /// @note Starting with Windows 8, the OSVersion property returns the same major and minor version numbers for all Windows platforms. Therefore, we do not recommend that you retrieve the value of this property to determine the operating system version.
      /// @remarks Typically, the OSVersion property is used to ensure that an app is running on some base version of an operating system in which a particular feature was introduced. When this is the case, you should perform a version check by testing whether the current operating system version returned by the OSVersion property is the same as, or greater than, the base operating system version. For more information, see the Version class topic.
      /// @remarks Through Windows 8, the OSVersion property returns the version reported by the Windows GetVersionEx function. For a list of Windows desktop operating system versions and their corresponding version numbers, see Operating System Version in the Windows Dev Center.
      /// @note The OSVersion property reports the same version number (6.2.0.0) for both Windows 8 and Windows 8.1 and the same major and minor version number for Windows 10.
      /// @remarks In some cases, the OSVersion property may not return the operating system version that matches the version specified for the Windows Program Compatibility mode feature.
      /// @par Example
      /// The following example displays the platform identifier and version number of the computer that runs the code example.
      /// @include EnvironmentOSVersion.cpp
      static property_<const OperatingSystem&, readonly_> OSVersion;

      /// @brief Gets the number of processors on the current machine.
      /// @return int32 The 32-bit signed integer that specifies the number of processors on the current machine. There is no default. If the current machine contains multiple processor groups, this property returns the number of logical processors.
      /// @remarks For more information about processor groups and logical processors, see Processor Groups.
      /// @par Example
      /// The following example demonstrates the ProcessorCount property.
      /// @include EnvironmentProcessorCount.cpp
      static property_<int32, readonly_> ProcessorCount;

      /// @brief Gets current stack trace information.
      /// @return string A string containing stack trace information. This value can be string.Empty.
      /// @remarks The StackTrace property lists method calls in reverse chronological order, that is, the most recent method call is described first, and one line of stack trace information is listed for each method call on the stack. However, the StackTrace property might not report as many method calls as expected due to code transformations that occur during optimization.
      /// @note For a hierarchical view of the stack trace information by class, use the StackTrace class.
      /// @remarks The StackTrace property formats the stack trace information for each method call as follows:
      /// @remarks "at FullClassName.MethodName(MethodParams) in FilePath :line LineNumber "
      /// @remarks The literal "at" is preceded by three spaces, and the entire substring starting with "in" is omitted if debug symbols are not available. The placeholders, FullClassName, MethodName, MethodParams, FilePath, and LineNumber, are replaced by actual values, and are defined as follows:
      /// * FullClassName The full name of the class, including the namespace.
      /// * MethodName The name of the method.
      /// * MethodParams The list of parameter type/name pairs. Each pair is separated by a comma (","). This information is omitted if MethodName takes no parameters.
      /// * FilePath The name of the source file where the MethodName method is declared. This information is omitted if debug symbols are not available.
      /// * LineNumber The number of the line in FilePath that contains the source code from MethodName for the instruction that is on the call stack. This information is omitted if debug symbols are not available.
      /// @remarks The Environment.NewLine string terminates each line of the stack trace.
      /// @par Example
      /// The following example demonstrates the StackTrace property.
      /// @include EnvironmentStackTrace.cpp
      static property_<String, readonly_> StackTrace;

      /// @brief Gets the fully qualified path of the system directory.
      /// @return string A string containing a directory path.
      /// @remarks An example of the value returned is the string "C:\WinNT\System32".
      /// @par Example
      /// The following example displays the system directory of the computer that runs the code example. (The system directory is omitted from the example output for security reasons.)
      /// @include EnvironmentsystemDirectory.cpp
      static property_<String, readonly_> SystemDirectory;

      /// @brief Gets the number of bytes in the operating system's memory page.
      /// @return The number of bytes in the system memory page.
      /// @remarks This information can be useful when determining whether to use the MemoryMappedFileOptions.DelayAllocatePages option when you work with memory-mapped files.
      /// @remarks In Windows, this value is the dwPageSize member in the SYSTEM_INFO structure.
      /// @remarks At this time the return value is always 4096.
      static property_<int32, readonly_> SystemPageSize;

      /// @brief Gets the number of milliseconds elapsed since the system started.
      /// @return Int32 A 32-bit signed integer containing the amount of time in milliseconds that has passed since the last time the computer was started.
      /// @remarks The value of this property is derived from the system timer and is stored as a 32-bit signed integer. Consequently, if the system runs continuously, TickCount will increment from zero to Int32.MaxValue for approximately 24.9 days, then jump to Int32.MinValue, which is a negative number, then increment back to zero during the next 24.9 days.
      /// @remarks TickCount is different from the Ticks property, which is the number of 100-nanosecond intervals that have elapsed since 1/1/0001, 12:00am.
      /// @remarks Use the DateTime::Now property to obtain the current local date and time on this computer.
      /// @par Example
      /// The following example demonstrates how to retrieve the positive range of values returned by the TickCount property. The TickCount property cycles between Int32.MinValue, which is a negative number, and Int32.MaxValue once every 49.8 days. This code sample removes the sign bit to yield a nonnegative number that cycles between zero and MaxValue once every 24.9 days.
      /// @include EnvironmentTickCount.cpp
      static property_<int32, readonly_> TickCount;

      /// @brief Gets the network domain name associated with the current user.
      /// @return string The network domain name associated with the current user.
      /// @remarks The domain account credentials for a user are formatted as the user's domain name, the '\' character, and user name. Use the UserDomainName property to obtain the user's domain name without the user name, and the UserName property to obtain the user name without the domain name. For example, if a user's domain name and user name are CORPORATENETWORK\john, the UserDomainName property returns "CORPORATENETWORK".
      /// @remarks The UserDomainName property first attempts to get the domain name component of the Windows account name for the current user. If that attempt fails, this property attempts to get the domain name associated with the user name provided by the UserName property. If that attempt fails because the host computer is not joined to a domain, then the host computer name is returned.
      static property_<String, readonly_> UserDomainName;

      /// @brief Gets a value indicating whether the current process is running in user interactive mode.
      /// @return bool true if the current process is running in user interactive mode; otherwise, false.
      /// @remarks The UserInteractive property reports false for a Os process or a service like IIS that runs without a user interface. If this property is false, do not display modal dialogs or message boxes because there is no graphical user interface for the user to interact with.
      /// @par Example
      /// The following example displays whether the current process is running in user interactive mode.
      /// @include EnvironmentUserInteractive.cpp
      static property_<bool, readonly_> UserInteractive;

      /// @brief Gets the user name of the person who is currently logged on to the Windows operating system.
      /// @return string The user name of the person who is logged on to Windows/Linux/macOS/... .
      /// @remarks You can use the UserName property to identify the user on the current thread, to the system and application for security or access purposes. It can also be used to customize a particular application for each user.
      /// @remarks The UserName property wraps a call to the Windows GetUserName function. The domain account credentials for a user are formatted as the user's domain name, the '\' character, and user name. Use the UserDomainName property to obtain the user's domain name and the UserName property to obtain the user name.
      /// @par Example
      /// The following example displays the user name of the person who started the current thread.
      /// @include EnvironmentUserName.cpp
      static property_<String, readonly_> UserName;

      /// @brief Gets a Version object that describes the major, minor, build, and revision numbers of the Switch.
      /// @return Version An object that displays the version of the Switch.
      /// @par Example
      /// The following example displays the version of the Switch.
      /// @include EnvironmentVersion.cpp
      static property_<const System::Version, readonly_> Version;

      /// @brief Gets the amount of physical memory mapped to the process context.
      /// @return Int64 A 64-bit signed integer containing the number of bytes of physical memory mapped to the process context.
      /// @remarks Windows 98, Windows Millennium Edition, Linux, macOS, Android,... Platform Note: This property always returns zero.
      /// @par Example
      /// The following example displays the size of the working set of the computer that runs the code example.
      /// @include EnvironmentWorkingSet.cpp
      static property_<int64, readonly_> WorkingSet;

      /// @brief Terminates this process and gives the underlying operating system the specified exit code.
      /// @param exitCode Exit code to be given to the operating system.
      /// @remarks For the exitCode parameter, use a non-zero number to indicate an error. In your application, you can define your own error codes in an enumeration, and return the appropriate error code based on the scenario. For example, return a value of 1 to indicate that the required file is not present, and a value of 2 to indicate that the file is in the wrong format. For a list of exit codes used by macOS, Linux or Windows, see errno error code documentation (http://en.cppreference.com/w/cpp/error/errno_macros).
      /// @remarks Calling the Exit method differs from using your programming language's return statement in the following ways:
      /// * Exit always terminates an application. Using the return statement may terminate an application only if it is used in the application entry point, such as in the Main method.
      /// * Exit terminates an application immediately, even if other threads are running. If the return statement is called in the application entry point, it causes an application to terminate only after all foreground threads have terminated.
      static void Exit(int32 exitCode);

      /// @brief Replaces the name of each environment variable embedded in the specified string with the string equivalent of the value of the variable, then returns the resulting string.
      /// @param name A string containing the names of zero or more environment variables. Each environment variable is quoted with the percent sign character (%).
      /// @return A string with each environment variable replaced by its value.
      /// @remarks Replacement only occurs for environment variables that are set. For example, suppose name is "MyENV = %MyENV%". If the environment variable, MyENV, is set to 42, this method returns "MyENV = 42". If MyENV is not set, no change occurs; this method returns "MyENV = %MyENV%".
      /// @remarks The size of the return value is limited to 32K.
      /// @par Example
      /// The following example shows how to obtain the system drive and system root variables.
      /// @include EnvironmentExpandEnvironmentVariables.cpp
      static String ExpandEnvironmentVariables(const String& name);

      /// @brief Immediately terminates a process after writing a message to the Windows Application event log, and then includes the message in error reporting to Microsoft.
      /// @param message A message that explains why the process was terminated, or null if no explanation is provided.
      /// @remarks This method terminates a process without running any active try/catch blocks or finalizers.
      /// @remarks The FailFast method writes the message string to the Windows Application event log, creates a dump of your application, and then terminates the current process. The message string is also included in error reporting to Microsoft.
      /// @remarks Use the FailFast method instead of the Exit method to terminate your application if the state of your application is damaged beyond repair, and executing your application's try/catch blocks and finalizers will corrupt program resources.
      /// @remarks Information is reported to Microsoft by using Windows Error Reporting. For more information, see Windows Error Reporting: Getting Started.
      /// @exception NotImplementedException This method always throw NotImplementedException.
      static void FailFast(const string& message) {throw NotImplementedException("Use System::Environment::Exit method instead", caller_);}

      /// @brief Returns a string array containing the command-line arguments for the current process.
      /// @return Array<string> An array of string where each element contains a command-line argument. The first element is the executable file name, and the following zero or more elements contain the remaining command-line arguments.
      /// @remarks The first element in the array contains the file name of the executing program. If the file name is not available, the first element is equal to String.Empty. The remaining elements contain any additional tokens entered on the command line.
      /// @remarks The program file name can, but is not required to, include path information.
      /// @remarks Command line arguments are delimited by spaces. You can use double quotation marks (") to include spaces within an argument. The single quotation mark ('), however, does not provide this functionality.
      /// @remarks If a double quotation mark follows two or an even number of backslashes, each proceeding backslash pair is replaced with one backslash and the double quotation mark is removed. If a double quotation mark follows an odd number of backslashes, including just one, each preceding pair is replaced with one backslash and the remaining backslash is removed; however, in this case the double quotation mark is not removed.
      /// @remarks The following table shows how command line arguments can be delimited, and assumes MyApp as the current executing application.
      /// | Input at the command line                    | Resulting command line argumen             |
      /// |----------------------------------------------|--------------------------------------------|
      /// | MyApp alpha beta                             | MyApp, alpha, beta                         |
      /// | MyApp "alpha with spaces" "beta with spaces" | MyApp, alpha with spaces, beta with spaces |
      /// | MyApp 'alpha with spaces' beta               | MyApp, 'alpha, with, spaces', beta         |
      /// | MyApp \\\alpha \\\\"beta                     | MyApp, \\\alpha, \\beta                    |
      /// | MyApp \\\\\"alpha \"beta                     | MyApp, \\"alpha] = "beta                     |
      /// @remarks To obtain the command line as a single string, use the CommandLine property.
      /// @par Example
      /// The following example displays the application's command line arguments.
      /// @include EnvironmentGetCommandLineArgs.cpp
      static const Array<String>& GetCommandLineArgs();

      /// @brief Retrieves the value of an environment variable from the current process.
      /// @param variable The name of the environment variable.
      /// @return String The value of the environment variable specified by variable, or String::Empty if the environment variable is not found.
      /// @remarks The GetEnvironmentVariable(String) method retrieves an environment variable from the environment block of the current process only. It is equivalent to calling the GetEnvironmentVariable(String, EnvironmentVariableTarget) method with a target value of EnvironmentVariableTarget.Process. The environment block of the current process includes the following environment variables:
      /// * All per-machine environment variables that are defined at the time the process is created, along with their values.
      /// * All per-user environment variables that are defined at the time the process is created, along with their values.
      /// * Any variables added to the process block while the process is running by calling either the SetEnvironmentVariable(String, String) method or the SetEnvironmentVariable(String, String, EnvironmentVariableTarget) method with a target value of EnvironmentVariableTarget.Process.
      /// @remarks If environment variables are created after the process has started, you can use this method to retrieve only those variables that were created by calling the SetEnvironmentVariable(String, String) method or the SetEnvironmentVariable(String, String, EnvironmentVariableTarget) method with a target value of .EnvironmentVariableTarget.Process.
      /// @remarks To retrieve all environment variables along with their values, call the GetEnvironmentVariables method.
      /// @remarks On Windows Environment variable names <b>are not</b> case-sensitive.
      /// @remarks On macOS and linux Environment variable names <b>are</b> case-sensitive.
      /// @par Example
      /// The following example uses the GetEnvironmentVariable method to retrieve the windir environment variable, which contains the path of the Windows directory.
      /// @include EnvironmentGetEnvironmentVariable.cpp
      /// The following example attempts to retrieve the value of an environment variable named Test1 from the process environment block. If the variable doesn't exist, the example creates its and retrieves its value. The example displays the value of the variable. If the example created the variable, it also calls the GetEnvironmentVariables(EnvironmentVariableTarget) method with each member of the EnvironmentVariableTarget enumeration to establish that the variable can be retrieved only from the current process environment block. Finally, if the example created the variable, it deletes it.
      /// @include EnvironmentGetEnvironmentVariable2.cpp
      static String GetEnvironmentVariable(const String& variable) {return GetEnvironmentVariable(variable, EnvironmentVariableTarget::Process);}

      /// @brief Retrieves the value of an environment variable from the current process or from the Windows operating system registry key for the current user or local machine.
      /// @param variable The name of an environment variable.
      /// @param target One of the EnvironmentVariableTarget values.
      /// @return The value of the environment variable specified by the variable and target parameters, or string::Empty if the environment variable is not found.
      /// @remarks The target parameter specifies whether the environment variable is retrieved from the current process or from the Windows operating system registry key for the current user or local machine. All per-user and per-machine environment variables are automatically copied into the environment block of the current process. However, environment variables added only to the environment block of the current process persist only for the duration of the process.
      /// @remarks To retrieve all environment variables along with their values, call the GetEnvironmentVariables method.
      /// @remarks On Windows Environment variable names <b>are not</b> case-sensitive.
      /// @remarks On macOS and linux Environment variable names <b>are</b> case-sensitive.
      /// @par Example
      /// The following example creates environment variables for the Process, User, and Machine targets, checks whether the operating system registry contains the User and Machine environment variables, then deletes the environment variables.
      /// @include EnvironmentGetEnvironmentVariable3.cpp
      static String GetEnvironmentVariable(const String& variable, EnvironmentVariableTarget target);

      /// @brief Retrieves all environment variable names and their values from the current process.
      /// @return Collections::Generic::IDictionary<string, string> A dictionary that contains all environment variable names and their values; otherwise, an empty dictionary if no environment variables are found.
      /// @remarks The names and values for the environment variables are stored as key-value pairs in the returned IDictionary.
      /// @par Example
      /// The following example demonstrates the GetEnvironmentVariables method.
      /// @include EnvironmentGetEnvironmentVariables.cpp
      static const Collections::Generic::IDictionary<String, String>& GetEnvironmentVariables() {return GetEnvironmentVariables(System::EnvironmentVariableTarget::Process);}

      /// @brief Retrieves all environment variable names and their values from the current process, or from the Windows operating system registry key for the current user or local machine.
      /// @param target One of the EnvironmentVariableTarget values.
      /// @return A dictionary that contains all environment variable names and their values from the source specified by the target parameter; otherwise, an empty dictionary if no environment variables are found.
      /// @remarks The target parameter specifies whether the source is the current process, the registry key for the current user, or the registry key for the local machine.
      /// @remarks The names and values of the environment variables are stored as key/value pairs in the returned IDictionary object.
      /// @par Example
      /// The following example creates environment variables for the Process, User, and Machine targets, checks whether the operating system registry contains the User and Machine environment variables, then deletes the environment variables.
      /// @include EnvironmentGetEnvironmentVariables2.cpp
      static const Collections::Generic::IDictionary<String, String>& GetEnvironmentVariables(EnvironmentVariableTarget target);

      /// @brief Gets the path to the system special folder that is identified by the specified enumeration.
      /// @param folder An enumerated constant that identifies a system special folder.
      /// @return string The path to the specified system special folder, if that folder physically exists on your computer; otherwise, an empty string ("").
      /// @exception ArgumentException folder is not a member of System.Environment.SpecialFolder.
      /// @remarks A folder will not physically exist if the operating system did not create it, the existing folder was deleted, or the folder is a virtual directory, such as My Computer, which does not correspond to a physical path.
      /// @remarks This method retrieves the path to a system special folder, such as Program Files, Programs, System, or Startup, which can be used to access common information. Special folders are set by default by the system, or explicitly by the user, when installing a version of Windows::
      /// @remarks The folder parameter designates the special folder to retrieve and must be one of the values in the Environment.SpecialFolder enumeration; any other value throws an exception.
      /// @remarks For more information about special folders, see the CSIDL values topic.
      /// @par Example
      /// The following example demonstrates how to use the GetFolderPath method to return and display the path associated with the folder parameter.
      /// @include EnvironmentGetFolderPath.cpp
      static String GetFolderPath(Environment::SpecialFolder folder) {return GetFolderPath(folder, Environment::SpecialFolderOption::None);}

      /// @brief Gets the path to the system special folder that is identified by the specified enumeration, and uses a specified option for accessing special folders.
      /// @exception ArgumentException folder is not a member of System.Environment.SpecialFolder.
      /// @param folder An enumerated constant that identifies a system special folder.
      /// @param option Specifies options to use for accessing a special folder.
      /// @remarks The path to the specified system special folder, if that folder physically exists on your computer; otherwise, an empty string ("").
      /// @remarks A folder will not physically exist if the operating system did not create it, the existing folder was deleted, or the folder is a virtual directory, such as My Computer, which does not correspond to a physical path.
      /// @remarks This method retrieves the path to a system special folder, such as Program Files, Programs, System, or Startup, which can be used to access common information. Special folders are set by default by the system, or explicitly by the user, when installing a version of Windows.
      /// @remarks The folder parameter designates the special folder to retrieve and must be one of the values in the Environment.SpecialFolder enumeration; any other value throws an exception.
      /// @remarks For more information about special folders, see the CSIDL values topic.
      static String GetFolderPath(Environment::SpecialFolder folder, Environment::SpecialFolderOption option);

      /// @brief Returns an array of string containing the names of the logical drives on the current computer.
      /// @return Array<string> An array of strings where each element contains the name of a logical drive. For example, if the computer's hard drive is the first logical drive, the first element returned is "C:\".
      /// @Exception IOException An I/O error occurs.
      /// @par Example
      /// The following example shows how to display the logical drives of the current computer using the GetLogicalDrives method.
      /// @include EnvironmentGetLogicalDrives.cpp
      static Array<String> GetLogicalDrives();

      /// @brief Initailize CommandLineArgs with specified command line arguments.
      /// @param argv Command line arguments.
      /// @param argc Number of command line arguments.
      /// @return Array<string> A string array that contains the arguments without the command line.
      /// @exception InvalidOperationException Call more than once. CommandeLine has already been set and is not empty.
      /// @remarks This methode must be call only once in main.
      /// @remarks if you use #startup_(default) you don't need to call this method; otherwise if you use the standerd C++ main method you need to call it.
      /// @par Example
      /// This example show how to call SetCommandLineArgs with sandard C++ main method:
      /// @include Main5.cpp
      static Array<string> SetCommandLineArgs(char* argv[], int argc);

      /// @brief Creates, modifies, or deletes an environment variable stored in the current process.
      /// @param name The name of an environment variable.
      /// @param value A value to assign to variable.
      /// @exception ArgumentException variable contains a zero-length string, an initial hexadecimal zero character (0x00), or an equal sign ("=").  -or-  The length of variable or value is greater than or equal to 32,767 characters.  -or-  An error occurred during the execution of this operation.
      /// @remarks Calling this method is equivalent to calling the SetEnvironmentVariable(String, String, EnvironmentVariableTarget) overload with a value of EnvironmentVariableTarget.Process for the target argument.
      /// @remarks If the value argument is not empty (see the discussion of deleting an environment variable later in this section for the definition of an empty value) and the environment variable named by the variable parameter does not exist, the environment variable is created and assigned the contents of value. If it does exist, its value is modified. Because the environment variable is defined in the environment block of the current process only, it does not persist after the process has ended.
      /// @remarks If variable contains a non-initial hexadecimal zero character, the characters before the zero character are considered the environment variable name and all subsequent characters are ignored.
      /// @remarks If value contains a non-initial hexadecimal zero character, the characters before the zero character are assigned to the environment variable and all subsequent characters are ignored.
      /// @remarks If value is empty and the environment variable named by variable exists, the environment variable is deleted. If variable does not exist, no error occurs even though the operation cannot be performed. value is considered empty under any of the following conditions:
      /// * It is String.Empty.
      /// * It consists of a single character whose value is U+0000.
      /// @par Example
      /// The following example attempts to retrieve the value of an environment variable named Test1 from the process environment block. If the variable doesn't exist, the example creates the variable and retrieves its value. The example displays the value of the variable. If the example created the variable, it also calls the GetEnvironmentVariables(EnvironmentVariableTarget) method with each member of the EnvironmentVariableTarget enumeration to establish that the variable can be retrieved only from the current process environment block. Finally, if the example created the variable, it deletes it.
      /// @include EnvironmentSetEnvironmentVariable.cpp
      static void SetEnvironmentVariable(const String& name, const String& value) {SetEnvironmentVariable(name, value, System::EnvironmentVariableTarget::Process);}

      /// @brief Creates, modifies, or deletes an environment variable stored in the current process or in the Windows operating system registry key reserved for the current user or local machine.
      /// @param name The name of an environment variable.
      /// @param value A value to assign to variable.
      /// @param One of the enumeration values that specifies the location of the environment variable.
      /// @exception ArgumentException variable contains a zero-length string, an initial hexadecimal zero character (0x00), or an equal sign ("=").  -or-  The length of variable is greater than or equal to 32,767 characters.  -or-  target is not a member of the EnvironmentVariableTarget enumeration.  -or-  target is Machine or User, and the length of variable is greater than or equal to 255.  -or-  arget is Process and the length of value is greater than or equal to 32,767 characters.  -or-  An error occurred during the execution of this operation.
      /// @remarks The SetEnvironmentVariable(String, String, EnvironmentVariableTarget) method lets you define an environment variable that is available to all processes that run on a machine (the EnvironmentVariableTarget.Machine value), to all processes run by a user (the EnvironmentVariableTarget.User value), or to the current process (the Process value). Per-machine and per-user environment variables are copied into the environment block of the current process. However, environment variables that are unique to the current process environment block persist only until the process ends.
      /// @remarks If the value argument is not empty (see the discussion of deleting an environment variable later in this section for the definition of an empty value) and the environment variable named by the variable parameter does not exist, the environment variable is created and assigned the contents of value. If it does exist, its value is modified.
      /// @remarks If variable contains a non-initial hexadecimal zero character, the characters before the zero character are considered the environment variable name and all subsequent characters are ignored.
      /// @remarks If value contains a non-initial hexadecimal zero character, the characters before the zero character are assigned to the environment variable and all subsequent characters are ignored.
      /// @remarks If value is empty and the environment variable named by variable exists, the environment variable is deleted. value is considered empty under any of the following conditions:
      /// * It is String.Empty.
      /// * It consists of a single character whose value is U+0000.
      /// @remarks If variable does not exist, no error occurs although the operation cannot be performed. Be careful when target is Machine, because you can accidentally delete an environment variable that affects your entire local machine, not just the current process or user.
      /// @remarks If target is User, the environment variable is stored in the HKEY_CURRENT_USER\Environment key of the local computer's registry. It is also copied to instances of File Explorer that are running as the current user. The environment variable is then inherited by any new processes that the user launches from File Explorer.
      /// @remarks Similarly, if target is EnvironmentVariableTarget.Machine, the environment variable is stored in the HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Session Manager\Environment key of the local computer's registry. It is also copied to all instances of File Explorer. The environment variable is then inherited by any new processes that are launched from File Explorer.
      /// @remarks If target is User or Machine, other applications are notified of the set operation by a Windows WM_SETTINGCHANGE message.
      /// @remarks If target is EnvironmentVariableTarget.User or EnvironmentVariableTarget.Machine, we recommend that the length of value be less than 2048 characters.
      /// @par Example
      /// The following example creates environment variables for the EnvironmentVariableTarget.Process, EnvironmentVariableTarget.User, and Machine targets, checks whether the operating system registry contains the user and machine environment variables, then deletes the environment variables.
      /// @include EnvironmentGetEnvironmentVariables2.cpp
      static void SetEnvironmentVariable(const String& name, const String& value, EnvironmentVariableTarget target);

    private:
      friend class System::Diagnoastics::Process;
      void SetUserInteractive(bool userInteractive);
    };
  }
}

/// @cond
template<>
struct EnumRegister<System::Environment::SpecialFolder> {
  void operator()(System::Collections::Generic::IDictionary<System::Environment::SpecialFolder, string>& values, bool& flags) {
    values[System::Environment::SpecialFolder::Desktop] = "Desktop";
    values[System::Environment::SpecialFolder::Programs] = "Programs";
    values[System::Environment::SpecialFolder::MyDocuments] = "MyDocuments";
    //values[System::Environment::SpecialFolder::Personal] = "Personal";
    values[System::Environment::SpecialFolder::Favorites] = "Favorites";
    values[System::Environment::SpecialFolder::Startup] = "Startup";
    values[System::Environment::SpecialFolder::Recent] = "Recent";
    values[System::Environment::SpecialFolder::SendTo] = "SendTo";
    values[System::Environment::SpecialFolder::StartMenu] = "StartMenu";
    values[System::Environment::SpecialFolder::MyMusic] = "MyMusic";
    values[System::Environment::SpecialFolder::MyVideos] = "MyVideos";
    values[System::Environment::SpecialFolder::DesktopDirectory] = "DesktopDirectory";
    values[System::Environment::SpecialFolder::MyComputer] = "MyComputer";
    values[System::Environment::SpecialFolder::NetworkShortcuts] = "NetworkShortcuts";
    values[System::Environment::SpecialFolder::Fonts] = "Fonts";
    values[System::Environment::SpecialFolder::Templates] = "Templates";
    values[System::Environment::SpecialFolder::CommonStartMenu] = "CommonStartMenu";
    values[System::Environment::SpecialFolder::CommonPrograms] = "CommonPrograms";
    values[System::Environment::SpecialFolder::CommonStartup] = "CommonStartup";
    values[System::Environment::SpecialFolder::CommonDesktopDirectory] = "CommonDesktopDirectory";
    values[System::Environment::SpecialFolder::ApplicationData] = "ApplicationData";
    values[System::Environment::SpecialFolder::PrinterShortcuts] = "PrinterShortcuts";
    values[System::Environment::SpecialFolder::LocalApplicationData] = "LocalApplicationData";
    values[System::Environment::SpecialFolder::InternetCache] = "InternetCache";
    values[System::Environment::SpecialFolder::Cookies] = "Cookies";
    values[System::Environment::SpecialFolder::History] = "History";
    values[System::Environment::SpecialFolder::CommonApplicationData] = "CommonApplicationData";
    values[System::Environment::SpecialFolder::Windows] = "Windows";
    values[System::Environment::SpecialFolder::System] = "System";
    values[System::Environment::SpecialFolder::ProgramFiles] = "ProgramFiles";
    values[System::Environment::SpecialFolder::MyPictures] = "MyPictures";
    values[System::Environment::SpecialFolder::UserProfile] = "UserProfile";
    values[System::Environment::SpecialFolder::SystemX86] = "SystemX86";
    values[System::Environment::SpecialFolder::ProgramFilesX86] = "ProgramFilesX86";
    values[System::Environment::SpecialFolder::CommonProgramFiles] = "CommonProgramFiles";
    values[System::Environment::SpecialFolder::CommonProgramFilesX86] = "CommonProgramFilesX86";
    values[System::Environment::SpecialFolder::CommonTemplates] = "CommonTemplates";
    values[System::Environment::SpecialFolder::CommonDocuments] = "CommonDocuments";
    values[System::Environment::SpecialFolder::CommonAdminTools] = "CommonAdminTools";
    values[System::Environment::SpecialFolder::AdminTools] = "AdminTools";
    values[System::Environment::SpecialFolder::CommonMusic] = "CommonMusic";
    values[System::Environment::SpecialFolder::CommonPictures] = "CommonPictures";
    values[System::Environment::SpecialFolder::CommonVideos] = "CommonVideos";
    values[System::Environment::SpecialFolder::Resources] = "Resources";
    values[System::Environment::SpecialFolder::LocalizedResources] = "LocalizedResources";
    values[System::Environment::SpecialFolder::CommonOemLinks] = "CommonOemLinks";
    values[System::Environment::SpecialFolder::CDBurning] = "CDBurning";
    flags = false;
  }
};

template<>
struct EnumRegister<System::Environment::SpecialFolderOption> {
  void operator()(System::Collections::Generic::IDictionary<System::Environment::SpecialFolderOption, string>& values, bool& flags) {
    values[System::Environment::SpecialFolderOption::None] = "None";
    values[System::Environment::SpecialFolderOption::DoNotVerify] = "DoNotVerify";
    values[System::Environment::SpecialFolderOption::Create] = "Create";
    flags = false;
  }
};
/// @endcond

using namespace Switch;

