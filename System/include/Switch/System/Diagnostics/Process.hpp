/// @file
/// @brief Contains Switch::System::Diagnostics::Process class.
#pragma once

#include <Switch/Property.hpp>
#include <Switch/Types.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/ObjectDisposedException.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/IO/StreamReader.hpp>
#include "../../SystemExport.hpp"
#include "ProcessStartInfo.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides access to local and remote processes and enables you to start and stop local system processes.
      /// @remarks A Process component provides access to a process that is running on a computer. A process, in the simplest terms, is a running app. A thread is the basic unit to which the operating system allocates processor time. A thread can execute any part of the code of the process, including parts currently being executed by another thread.
      /// @remarks The Process component is a useful tool for starting, stopping, controlling, and monitoring apps. You can use the Process component, to obtain a list of the processes that are running, or you can start a new process. A Process component is used to access system processes. After a Process component has been initialized, it can be used to obtain information about the running process. Such information includes the set of threads, the loaded modules (.dll and .exe files), and performance information such as the amount of memory the process is using.
      /// @remarks This type implements the IDisposable interface. When you have finished using the type, you should dispose of it either directly or indirectly. To dispose of the type directly, call its Dispose method in a try/catch block. To dispose of it indirectly, use a language construct such as using (in C#) or Using (in Visual Basic). For more information, see the “Using an Object that Implements IDisposable” section in the IDisposable interface topic.
      /// @remarks 32-bit processes cannot access the modules of a 64-bit process. If you try to get information about a 64-bit process from a 32-bit process, you will get a Win32Exception exception. A 64-bit process, on the other hand, can access the modules of a 32-bit process.
      /// @remarks The process component obtains information about a group of properties all at once. After the Process component has obtained information about one member of any group, it will cache the values for the other properties in that group and not obtain new information about the other members of the group until you call the Refresh method. Therefore, a property value is not guaranteed to be any newer than the last call to the Refresh method. The group breakdowns are operating-system dependent.
      /// @remarks If you have a path variable declared in your system using quotes, you must fully qualify that path when starting any process found in that location. Otherwise, the system will not find the path. For example, if c:\mypath is not in your path, and you add it using quotation marks: path = %path%;"c:\mypath", you must fully qualify any process in c:\mypath when starting it.
      /// @remarks A system process is uniquely identified on the system by its process identifier. Like many Windows resources, a process is also identified by its handle, which might not be unique on the computer. A handle is the generic term for an identifier of a resource. The operating system persists the process handle, which is accessed through the Handle property of the Process component, even when the process has exited. Thus, you can get the process's administrative information, such as the ExitCode (usually either zero for success or a nonzero error code) and the ExitTime. Handles are an extremely valuable resource, so leaking handles is more virulent than leaking memory.
      /// @note This class contains a link demand and an inheritance demand at the class level that applies to all members. A SecurityException is thrown when either the immediate caller or the derived class does not have full-trust permission. For details about security demands, see Link Demands.
      /// @par Library
      /// Switch.System
      class system_export_ Process : public Object {
        refptr<IO::Stream> GetStandardOutput() const;
      public:
        /// @cond
        Process() {}
        Process(const Process& process) : data(process.data) {}
        Process& operator=(const Process& process) {this->data = process.data; return *this;}
        virtual ~Process();
        /// @endcond

        /// @brief Gets the base priority of the associated process.
        /// @exception InvalidOperationException The process has exited.  - or -  The process has not started, so there is no process ID.
        /// @remarks The BasePriority of the process is the starting priority for threads created within the associated process. You can view information about the base priority through the System Monitor's Priority Base counter.
        /// @remarks Based on the time elapsed or other boosts, the operating system can change the base priority when a process should be placed ahead of others.
        /// @remarks The BasePriority property lets you view the starting priority assigned to a process. However, because it is read-only, you cannot use the BasePriority to set the priority of the process. To change the priority, use the PriorityClass property. The BasePriority is viewable using the System Monitor, while the PriorityClass is not. Both the BasePriority and the PriorityClass can be viewed programmatically. The following table shows the relationship between BasePriority values and PriorityClass values.
        /// | BasePriority | PriorityClass |
        /// |--------------|---------------|
        /// | 4            | Idle          |
        /// | 8            | Normal        |
        /// | 13           | High          |
        /// | 24           | RealTime      |
        property_<int32, readonly_> BasePriority {
          get_ {return this->data->basePriority;}
        };

        property_<int32, readonly_> ExitCode {
          get_ {return this->data->exitCode;}
        };

        property_<int32, readonly_> Id {
          get_ {return *((int32*)&this->data->handle);}
        };

        property_<string, readonly_> ProcessName {
          get_ {return this->GetName();}
        };

        property_<string, readonly_> Path {
          get_ {return this->GetPath();}
        };

        property_<ProcessStartInfo&> StartInfo {
          get_->ProcessStartInfo& {return this->data->startInfo;},
          set_ {this->data->startInfo = value;}
        };

        property_<System::IO::StreamReader, readonly_> StandardOutput {
          get_ {return this->GetStreamReader();}
        };

        void Close();

        void Kill();

        static Process GetCurrentProcess();

        static Array<Process> GetProcesses();

        static Process Start(const String& fileName);

        static Process Start(const String& fileName, const String& argument);

        static Process Start(const ProcessStartInfo& startInfo);

        String ToString() const override {return string::Format("{0} ({1})", this->GetType(), this->ProcessName);};

        void WaitForExit();

      private:
        Process(intptr handle) {this->data->handle = handle;}
        int32 GetId();
        string GetName();
        string GetPath();
        System::IO::StreamReader GetStreamReader();

        struct ProcessData {
          int32 basePriority = 8;
          int32 exitCode = 0;
          intptr handle = 0;
          refptr<System::IO::Stream> outputStream;
          ProcessStartInfo startInfo;
        };
        refptr<ProcessData> data = ref_new<ProcessData>();
      };
    }
  }
}

using namespace Switch;
