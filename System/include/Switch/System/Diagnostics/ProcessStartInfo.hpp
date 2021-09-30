/// @file
/// @brief Contains Switch::System::Diagnostics::ProcessStartInfo class.
#pragma once

#include <Switch/System/Security/SecureString.hpp>
#include <Switch/System/ComponentModel/InvalidEnumArgumentException.hpp>
#include <Switch/System/Environment.hpp>
#include <Switch/System/Nullable.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemExport.hpp"
#include "ProcessWindowStyle.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Specifies a set of values that are used when you start a process.
      /// @remarks ProcessStartInfo is used together with the Process component. When you start a process using the Process class, you have access to process information in addition to that available when attaching to a running process.
      /// @remarks You can use the ProcessStartInfo class for better control over the process you start. You must at least set the FileName property, either manually or using the constructor. The file name is any application or document. Here a document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
      /// @remarks In addition, you can set other properties that define actions to take with that file. You can specify a value specific to the type of the FileName property for the Verb property. For example, you can specify "print" for a document type. Additionally, you can specify Arguments property values to be command-line arguments to pass to the file's open procedure. For example, if you specify a text editor application in the FileName property, you can use the Arguments property to specify a text file to be opened by the editor.
      /// @remarks Standard input is usually the keyboard, and standard output and standard error are usually the monitor screen. However, you can use the RedirectStandardInput, RedirectStandardOutput, and RedirectStandardError properties to cause the process to get input from or return output to a file or other device. If you use the StandardInput, StandardOutput, or StandardError properties on the Process component, you must first set the corresponding value on the ProcessStartInfo property. Otherwise, the system throws an exception when you read or write to the stream.
      /// @remarks Set UseShellExecute to specify whether to start the process by using the operating system shell.
      /// @remarks You can change the value of any ProcessStartInfo property up to the time that the process starts. After you start the process, changing these values has no effect.
      /// @note This class contains a link demand at the class level that applies to all members. A SecurityException is thrown when the immediate caller does not have full-trust permission. For details about security demands, see Link Demands.
      /// @par Library
      /// Switch.System
      class system_export_ ProcessStartInfo final : public Object {
      public:
        /// @brief Initializes a new instance of the ProcessStartInfo class without specifying a file name with which to start the process.
        /// @remarks You must set at least the SetFileName() property before you start the process. The file name is any application or document. In this case, a document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
        /// @remarks Optionally, you can also set other properties before you start the process. The SetVerb() property supplies actions to take, such as "print", with the file indicated in the FileName property. The SetArguments() property supplies a way to pass command-line arguments to the file when the system opens it.
        ProcessStartInfo() {}

        /// @brief Initializes a new instance of the ProcessStartInfo class and specifies a file name such as an application or document with which to start the process.
        /// @param fileName An application or document with which to start a process.
        /// @remarks The file name is any application or document. In this case, a document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
        /// @remarks You can change the FileName property after you call this constructor, up to the time that the process starts. After you start the process, changing these values has no effect.
        explicit ProcessStartInfo(const String& fileName) {this->data->fileName = fileName;}

        /// @brief Initializes a new instance of the ProcessStartInfo class, specifies an application file name with which to start the process, and specifies a set of command-line arguments to pass to the application.
        /// @param fileName  An application with which to start a process.
        /// @param arguments Command-line arguments to pass to the application when the process starts.
        /// @remarks The file name is any application or document. In this case, a document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
        /// @remarks You can change the FileName or Arguments properties after you call this constructor, up to the time that the process starts. After you start the process, changing these values has no effect.
        ProcessStartInfo(const String& fileName, const String& arguments) {
          this->data->fileName = fileName;
          this->data->arguments = arguments;
        }

        /// @cond
        ProcessStartInfo(const ProcessStartInfo& psi) : data(psi.data) {}
        /// @endcond

        /// @brief Sets or Gets the set of command-line arguments to use when starting the application.
        /// @return string File type–specific arguments that the system can associate with the application specified in the FileName property. The default is an empty string (""). On Windows Vista and earlier versions of the Windows operating system, the length of the arguments added to the length of the full path to the process must be less than 2080. On Windows 7 and later versions, the length must be less than 32699.
        property_<string> Arguments {
          get_ {return this->data->arguments;},
          set_ {this->data->arguments = value;}
        };

        /// @brief Gets a value indicating whether to start the process in a new window.
        /// @param createWindow true if the process should be started without creating a new window to contain it; otherwise, false. The default is false.
        /// @return Boolean true if the process should be started without creating a new window to contain it; otherwise, false. The default is false.
        /// @remarks If the UseShellExecute property is true or the UserName and Password properties are not null, the CreateNoWindow property value is ignored and a new window is created.
        property_<bool> CreateNoWindow {
          get_ {return this->data->createNoWindow;},
          set_ {this->data->createNoWindow = value;}
        };

        /// @brief Gets a value that identifies the domain to use when starting the process.
        /// @return string The Active Directory domain to use when starting the process. The domain property is primarily of interest to users within enterprise environments that use Active Directory.
        property_<string> Domain {
          get_ {return this->data->domain;},
          set_ {this->data->domain = value;}
        };

        /// @brief Gets the environment variables that apply to this process and its child processes.
        /// @return IDictionary<string, string> A generic dictionary containing the environment variables that apply to this process and its child processes.
        /// @remarks The environment variables contain search paths for files, directories for temporary files, application-specific options, and other similar information. Although you cannot directly set the Environment property, you can modify the generic dictionary returned by the property. For example, the following code adds a TempPath environment variable: myProcess.StartInfo.Environment.Add("TempPath", "C:\\Temp"). You must set the UseShellExecute property to false to start the process after changing the Environment property. If UseShellExecute is true, an InvalidOperationException is thrown when the Start method is called.
        /// @remarks On Switch Framework applications, using the Environment property is the same as using the EnvironmentVariables property.
        property_<Collections::Generic::IDictionary<string, string>&, readonly_> Environment {
          get_->Collections::Generic::IDictionary<string, string>& { return this->data->environmentVariables; }
        };

        /// @brief Gets search paths for files, directories for temporary files, application-specific options, and other similar information.
        /// @return Dictionary<string, string> A string dictionary that provides environment variables that apply to this process and child processes. The default is empty.
        /// @remarks Although you cannot set the EnvironmentVariables property, you can modify the StringDictionary returned by the property. For example, the following code adds a TempPath environment variable: myProcess.StartInfo.EnvironmentVariables.Add("TempPath", "C:\\Temp"). You must set the UseShellExecute property to false to start the process after changing the EnvironmentVariables property. If UseShellExecute is true, an InvalidOperationException is thrown when the Start method is called.
        property_<Collections::Generic::Dictionary<string, string>&, readonly_> EnvironmentVariables {
          get_->Collections::Generic::Dictionary<string, string>& { return this->data->environmentVariables; }
        };

        /// @brief Gets or sets a value indicating whether an error dialog box is displayed to the user if the process cannot be started.
        /// @return bool true if an error dialog box should be displayed on the screen if the process cannot be started; otherwise, false. The default is false.
        /// @note UseShellExecute must be true if you want to set ErrorDialog to true.
        property_<bool> ErrorDialog {
          get_ {return this->data->errorDialog;},
          set_ {this->data->errorDialog = value;}
        };

        /// @brief Gets or sets the window handle to use when an error dialog box is shown for a process that cannot be started.
        /// @return intptr A pointer to the handle of the error dialog box that results from a process start failure.
        /// @remarks If ErrorDialog is true, the ErrorDialogParentHandle property specifies the parent window for the dialog box that is shown. It is useful to specify a parent to keep the dialog box in front of the application.
        property_<intptr> ErrorDialogParamHandle {
          get_ {return this->data->errorDialogParamHandle;},
          set_ {this->data->errorDialogParamHandle = value;}
        };

        /// @brief Gets the application or document to start.
        /// @return string The name of the application to start, or the name of a document of a file type that is associated with an application and that has a default open action available to it. The default is an empty string ("").
        /// @remarks You must set at least the FileName property before you start the process. The file name is any application or document. A document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
        /// @remarks The set of file types available to you depends in part on the value of the UseShellExecute property. If UseShellExecute is true, you can start any document and perform operations on the file, such as printing, with the Process component. When UseShellExecute is false, you can start only executables with the Process component.
        /// @remarks You can start a ClickOnce application by setting the FileName property to the location (for example, a Web address) from which you originally installed the application. Do not start a ClickOnce application by specifying its installed location on your hard disk.
        property_<string> FileName {
          get_ {return this->data->fileName;},
          set_ {this->data->fileName = value;}
        };

        /// @brief Gets or sets a value that indicates whether the Windows user profile is to be loaded from the registry.
        /// @return bool true if the Windows user profile should be loaded; otherwise, false. The default is false.
        /// @remarks This property is referenced if the process is being started by using the user name, password, and domain.
        /// @remarks If the value is true, the user's profile in the HKEY_USERS registry key is loaded. Loading the profile can be time-consuming. Therefore, it is best to use this value only if you must access the information in the HKEY_CURRENT_USER registry key.
        property_<bool> LoadUserProfile {
          get_ {return this->data->loadUserProfile;},
          set_ {this->data->loadUserProfile = value;}
        };

        /// @brief Gets or sets a secure string that contains the user password to use when starting the process.
        /// @return System::Security::SecureString The user password to use when starting the process.
        /// @par Important
        /// The WorkingDirectory property must be set if UserName and Password are provided. If the property is not set, the default working directory is %SYSTEMROOT%\system32.
        /// @note Setting the Domain, UserName, and the Password properties in a ProcessStartInfo object is the recommended practice for starting a process with user credentials.
        /// @remarks A SecureString object is like a String object in that it has a text value. However, the value of a SecureString object is automatically encrypted, it can be modified until your application marks it as read-only, and it can be deleted from computer memory by either your application.
        /// @remarks For more information about secure strings and an example of how to obtain a password to set this property, see the SecureString class.
        /// @note If you provide a value for the Password property, the UseShellExecute property must be false, or an InvalidOperationException will be thrown when the Process.Start(ProcessStartInfo) method is called.
        property_<System::Security::SecureString> Pasword {
          get_ {return this->data->password;},
          set_ {this->data->password = value;}
        };

        /// @brief Gets or sets the user password in clear text to use when starting the process.
        /// @return string The user password in clear text.
        property_<string> PasswordInClearText {
          get_ {return this->GetPasswordInClearText();},
          set_ {this->SetPasswordInClearText(value);}
        };

        /// @brief Gets or sets a value that indicates whether the error output of an application is written to the Process.StandardError stream.
        /// @return bool true if error output should be written to Process::StandardError; otherwise, false. The default is false.
        /// @remarks When a Process writes text to its standard error stream, that text is typically displayed on the console. By redirecting the StandardError stream, you can manipulate or suppress the error output of a process. For example, you can filter the text, format it differently, or write the output to both the console and a designated log file.
        /// @note You must set UseShellExecute to false if you want to set RedirectStandardError to true. Otherwise, reading from the StandardError stream throws an exception.
        /// @remarks The redirected StandardError stream can be read synchronously or asynchronously. Methods such as Read, ReadLine and ReadToEnd perform synchronous read operations on the error output stream of the process. These synchronous read operations do not complete until the associated Process writes to its StandardError stream, or closes the stream.
        /// @remarks In contrast, BeginErrorReadLine starts asynchronous read operations on the StandardError stream. This method enables a designated event handler for the stream output and immediately returns to the caller, which can perform other work while the stream output is directed to the event handler.
        /// @note The application that is processing the asynchronous output should call the WaitForExit method to ensure that the output buffer has been flushed.
        /// @remarks Synchronous read operations introduce a dependency between the caller reading from the StandardError stream and the child process writing to that stream. These dependencies can cause deadlock conditions. When the caller reads from the redirected stream of a child process, it is dependent on the child. The caller waits for the read operation until the child writes to the stream or closes the stream. When the child process writes enough data to fill its redirected stream, it is dependent on the parent. The child process waits for the next write operation until the parent reads from the full stream or closes the stream. The deadlock condition results when the caller and child process wait for each other to complete an operation, and neither can continue. You can avoid deadlocks by evaluating dependencies between the caller and child process.
        /// For example, the following code shows how to read from a redirected stream and wait for the child process to exit.
        /// @code
        /// // Start the child process.
        /// Process p;
        /// Redirect the error stream of the child process.
        /// p.StartInfo().UseShellExecute = false;
        /// p.StartInfo().RedirectStandardError = true;
        /// p.StartInfo().FileName = "Write500Lines.exe";
        /// p.Start();
        /// // Do not wait for the child process to exit before
        /// // reading to the end of its redirected error stream.
        /// // p.WaitForExit();
        /// // Read the error stream first and then wait.
        /// string error = p.StandardError().ReadToEnd();
        /// p.WaitForExit();
        /// @endcode
        /// @remarks The code example avoids a deadlock condition by calling p.StandardError.ReadToEnd before p.WaitForExit. A deadlock condition can result if the parent process calls p.WaitForExit before p.StandardError.ReadToEnd and the child process writes enough text to fill the redirected stream. The parent process would wait indefinitely for the child process to exit. The child process would wait indefinitely for the parent to read from the full StandardError stream.
        /// @remarks There is a similar issue when you read all text from both the standard output and standard error streams. For example, the following code performs a read operation on both streams.
        /// @code
        /// // Do not perform a synchronous read to the end of both
        /// // redirected streams.
        /// // string output = p.StandardOutput().ReadToEnd();
        /// // string error = p.StandardError().ReadToEnd();
        /// // p.WaitForExit();
        /// // Use asynchronous read operations on at least one of the streams.
        /// p.BeginOutputReadLine();
        /// string error = p.StandardError().ReadToEnd();
        /// p.WaitForExit();
        /// @endcode
        /// @remarks The code example avoids the deadlock condition by performing asynchronous read operations on the StandardOutput stream. A deadlock condition results if the parent process calls p.StandardOutput.ReadToEnd followed by p.StandardError.ReadToEnd and the child process writes enough text to fill its error stream. The parent process would wait indefinitely for the child process to close its StandardOutput stream. The child process would wait indefinitely for the parent to read from the full StandardError stream.
        /// @remarks You can use asynchronous read operations to avoid these dependencies and their deadlock potential. Alternately, you can avoid the deadlock condition by creating two threads and reading the output of each stream on a separate thread.
        property_<bool> RedirectStandardError {
          get_ {return this->data->redirectStandardError;},
          set_ {this->data->redirectStandardError = value;}
        };

        /// @biref Gets or sets a value indicating whether the input for an application is read from the Process.StandardInput stream.
        /// @return bool true if input should be read from Process.StandardInput; otherwise, false. The default is false.
        /// @remarks A Process can read input text from its standard input stream, typically the keyboard. By redirecting the StandardInput stream, you can programmatically specify the input of a process. For example, instead of using keyboard input, you can provide text from the contents of a designated file or output from another application.
        /// @note You must set UseShellExecute to false if you want to set RedirectStandardInput to true. Otherwise, writing to the StandardInput stream throws an exception.
        property_<bool> RedirectStandardInput {
          get_ {return this->data->redirectStandardInput;},
          set_ {this->data->redirectStandardInput = value;}
        };

        /// @brief Gets or sets a value that indicates whether the textual output of an application is written to the Process.StandardOutput stream.
        /// @return bool true if output should be written to Process.StandardOutput; otherwise, false. The default is false.
        /// @remarks When a Process writes text to its standard stream, that text is typically displayed on the console. By setting RedirectStandardOutput to true to redirect the StandardOutput stream, you can manipulate or suppress the output of a process. For example, you can filter the text, format it differently, or write the output to both the console and a designated log file.
        /// @note You must set UseShellExecute to false if you want to set RedirectStandardOutput to true. Otherwise, reading from the StandardOutput stream throws an exception.
        /// @remarks The redirected StandardOutput stream can be read synchronously or asynchronously. Methods such as Read, ReadLine, and ReadToEnd perform synchronous read operations on the output stream of the process. These synchronous read operations do not complete until the associated Process writes to its StandardOutput stream, or closes the stream.
        /// @remarks In contrast, BeginOutputReadLine starts asynchronous read operations on the StandardOutput stream. This method enables a designated event handler (see OutputDataReceived) for the stream output and immediately returns to the caller, which can perform other work while the stream output is directed to the event handler.
        /// @note The application that is processing the asynchronous output should call the WaitForExit method to ensure that the output buffer has been flushed.
        /// @remarks Synchronous read operations introduce a dependency between the caller reading from the StandardOutput stream and the child process writing to that stream. These dependencies can cause deadlock conditions. When the caller reads from the redirected stream of a child process, it is dependent on the child. The caller waits for the read operation until the child writes to the stream or closes the stream. When the child process writes enough data to fill its redirected stream, it is dependent on the parent. The child process waits for the next write operation until the parent reads from the full stream or closes the stream. The deadlock condition results when the caller and child process wait for each other to complete an operation, and neither can continue. You can avoid deadlocks by evaluating dependencies between the caller and child process.
        /// @remarks For example, the following code shows how to read from a redirected stream and wait for the child process to exit.
        /// @code
        /// Process p;
        /// p.StartInfo().UseShellExecute = false;
        /// p.StartInfo().RedirectStandardOutput = true;
        /// p.StartInfo().FileName = "Write500Lines.exe";
        /// p.Start();
        ///
        /// // To avoid deadlocks, always read the output stream first and then wait.
        /// string output = p.StandardOutput.ReadToEnd();
        /// p.WaitForExit();
        /// @endcode
        /// @remarks The code example avoids a deadlock condition by calling p.StandardOutput.ReadToEnd before p.WaitForExit. A deadlock condition can result if the parent process calls p.WaitForExit before p.StandardOutput.ReadToEnd and the child process writes enough text to fill the redirected stream. The parent process would wait indefinitely for the child process to exit. The child process would wait indefinitely for the parent to read from the full StandardOutput stream.
        /// @remarks There is a similar issue when you read all text from both the standard output and standard error streams. For example, the following C# code performs a read operation on both streams.
        /// @code
        /// // To avoid deadlocks, use asynchronous read operations on at least one of the streams.
        /// // Do not perform a synchronous read to the end of both redirected streams.
        /// p.BeginOutputReadLine();
        /// string error = p.StandardError().ReadToEnd();
        /// p.WaitForExit();
        /// @endcode
        /// @remarks The code example avoids the deadlock condition by performing asynchronous read operations on the StandardOutput stream. A deadlock condition results if the parent process calls p.StandardOutput.ReadToEnd followed by p.StandardError.ReadToEnd and the child process writes enough text to fill its error stream. The parent process would wait indefinitely for the child process to close its StandardOutput stream. The child process would wait indefinitely for the parent to read from the full StandardError stream.
        /// @remarks You can use asynchronous read operations to avoid these dependencies and their deadlock potential. Alternately, you can avoid the deadlock condition by creating two threads and reading the output of each stream on a separate thread.
        property_<bool> RedirectStandardOutput {
          get_ {return this->data->redirectStandardOutput;},
          set_ {this->data->redirectStandardOutput = value;}
        };

        /// @brief Gets or sets the user name to be used when starting the process.
        /// @return string The user name to use when starting the process.
        /// @par Important
        /// The WorkingDirectory property must be set if UserName and Password are provided. If the property is not set, the default working directory is %SYSTEMROOT%\system32.
        /// @remarks If the UserName property is not an empty string, the UseShellExecute property must be false, or an InvalidOperationException will be thrown when the Process.Start(ProcessStartInfo) method is called.
        property_<string> UserName {
          get_ {return this->data->userName;},
          set_ {this->data->userName = value;}
        };

        /// @brief Gets or sets a value indicating whether to use the operating system shell to start the process.
        /// @return string true if the shell should be used when starting the process; false if the process should be created directly from the executable file. The default is true.
        /// @remarks Setting this property to false enables you to redirect input, output, and error streams.
        /// @note UseShellExecute must be false if the UserName property is not null or an empty string, or an InvalidOperationException will be thrown when the Process.Start(ProcessStartInfo) method is called.
        /// @remarks When you use the operating system shell to start processes, you can start any document (which is any registered file type associated with an executable that has a default open action) and perform operations on the file, such as printing, by using the Process object. When UseShellExecute is false, you can start only executables by using the Process object.
        /// @note UseShellExecute must be true if you set the ErrorDialog property to true.
        /// @remarks The WorkingDirectory property behaves differently depending on the value of the UseShellExecute property. When UseShellExecute is true, the WorkingDirectory property specifies the location of the executable. If WorkingDirectory is an empty string, it is assumed that the current directory contains the executable.
        /// @remarks When UseShellExecute is false, the WorkingDirectory property is not used to find the executable. Instead, it is used only by the process that is started and has meaning only within the context of the new process. When UseShellExecute is false, the FileName property can be either a fully qualified path to the executable, or a simple executable name that the system will attempt to find within folders specified by the PATH environment variable.
        property_<bool> UseShellExecute {
          get_ {return this->data->useShellExecute;},
          set_ {this->data->useShellExecute = value;}
        };

        /// @brief Gets or sets the verb to use when opening the application or document specified by the FileName property.
        /// @return string The action to take with the file that the process opens. The default is an empty string (""), which signifies no action.
        /// @remarks Each file name extension has its own set of verbs, which can be obtained by using the Verbs property. For example, the "print" verb will print a document specified by using FileName. The default verb can be specified by using an empty string (""). Examples of verbs are "Edit", "Open", "OpenAsReadOnly", "Print", and "Printto". You should use only verbs that appear in the set of verbs returned by the Verbs property.
        /// @remarks When you use the Verb property, you must include the file name extension when you set the value of the FileName property. The file name does not need to have an extension if you manually enter a value for the Verb property.
        property_<string> Verb {
          get_ {return this->data->verb;},
          set_ {this->data->verb = value;}
        };

        /// @brief Gets the set of verbs associated with the type of file specified by the FileName property.
        /// @return Array<string> The actions that the system can apply to the file indicated by the FileName property.
        /// @remarks The Verbs property enables you to determine the verbs that can be used with the file specified by the FileName property. You can set the Verb property to the value of any verb in the set. Examples of verbs are "Edit", "Open", "OpenAsReadOnly", "Print", and "Printto".
        /// @remarks When you use the Verbs property, you must include the file name extension when you set the value of the FileName property. The file name extension determines the set of possible verbs.
        property_<Array<string>, readonly_> Verbs {
          get_ {return this->data->verbs;}
        };

        /// @brief Gets or sets the window state to use when the process is started.
        /// @return ProcessWindowStyle One of the enumeration values that indicates whether the process is started in a window that is maximized, minimized, normal (neither maximized nor minimized), or not visible. The default is Normal.
        /// @exception InvalidEnumArgumentException The window style is not one of the ProcessWindowStyle enumeration members.
        property_<ProcessWindowStyle> WindowStyle {
          get_ {return this->data->windowStyle;},
          set_ {
            if (!Enum<>::IsDefined<ProcessWindowStyle>(value))
              throw System::ComponentModel::InvalidEnumArgumentException(caller_);
            this->data->windowStyle = value;
          }
        };

        /// When the UseShellExecute property is false, gets or sets the working directory for the process to be started. When UseShellExecute is true, gets or sets the directory that contains the process to be started.
        /// @return string When UseShellExecute is true, the fully qualified name of the directory that contains the process to be started. When the UseShellExecute property is false, the working directory for the process to be started. The default is an empty string ("").
        /// @par Important
        /// The WorkingDirectory property must be set if UserName and Password are provided. If the property is not set, the default working directory is %SYSTEMROOT%\system32.
        /// @remarks If the directory is already part of the system path variable, you do not have to repeat the directory's location in this property.
        /// @remarks The WorkingDirectory property behaves differently when UseShellExecute is true than when UseShellExecute is false. When UseShellExecute is true, the WorkingDirectory property specifies the location of the executable. If WorkingDirectory is an empty string, the current directory is understood to contain the executable.
        /// @note When UseShellExecute is true, the working directory of the application that starts the executable is also the working directory of the executable.
        /// @remarks When UseShellExecute is false, the WorkingDirectory property is not used to find the executable. Instead, its value applies to the process that is started and only has meaning within the context of the new process.
        property_<string> WorkingDirectory {
          get_ {return this->data->workingDirectory;},
          set_ {this->data->workingDirectory = value;}
        };

      private:
        string GetPasswordInClearText() const;
        void SetPasswordInClearText(const string& password);
        Array<string> GetVerbs(const string& fileName);
        struct ProcessStartInfoData {
          String arguments;
          bool createNoWindow = false;
          String domain;
          bool errorDialog = false;
          intptr errorDialogParamHandle = 0;
          Collections::Generic::Dictionary<string, string> environmentVariables;
          String fileName;
          bool loadUserProfile = false;
          System::Security::SecureString password;
          bool redirectStandardError;
          bool redirectStandardInput;
          bool redirectStandardOutput;
          string userName;
          bool useShellExecute;
          string verb;
          Array<string> verbs;
          ProcessWindowStyle windowStyle = ProcessWindowStyle::Normal;
          string workingDirectory;
        };
        refptr<ProcessStartInfoData> data = ref_new<ProcessStartInfoData>();
      };
    }
  }
}

using namespace Switch;
