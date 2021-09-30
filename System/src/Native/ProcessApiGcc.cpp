#if defined(__linux__) || defined(__APPLE__)

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include "Api.hpp"
#include <Switch/System/IO/Path.hpp>
#include <Switch/System/Threading/Thread.hpp>

#if defined(__APPLE__)
#  include "TargetConditionals.h"
#endif

#if defined(__APPLE__) && TARGET_OS_IPHONE == 0
#include <libproc.h>

namespace {
  /*
  struct ProcessInfo : public object {
    ProcessInfo() {}
    ProcessInfo(pid_t pid, const string &name, const string& path) : pid(pid), name(name), path(path) {}
    ProcessInfo(const ProcessInfo& pi) : pid(pi.pid),  name(pi.name), path(pi.path) {}

    property_<intptr, readonly_> Id {
      get_ {return this->pid;}
    };

    property_<string, readonly_> Name {
      get_ {return this->name;}
    };

    property_<string, readonly_> Path {
      get_ {return this->path;}
    };

    String ToString() const override {return string::Format("{{pid={0}, Name={1}, Path={2}}}", this->pid, this->name, this->path);}

  private:
    intptr pid = 0;
    string name;
    string path;
  };*/

  string GetProcessPath(pid_t id) {
    char path[PROC_PIDPATHINFO_SIZE + 1] = {0};
    if (proc_pidinfo(id, PROC_PIDPATHINFO, 0, &path, PROC_PIDPATHINFO_SIZE) != 0)
      throw System::InvalidOperationException(caller_);
    return path;
  }

  string GetProcessName(pid_t id) {
    char name[1024] = {0};
    if (proc_name(id, name, 1024) != 0 || string::IsNullOrEmpty(name))
      return System::IO::Path::GetFileNameWithoutExtension(GetProcessPath(id));
    return name;
  }

  /*
  ProcessInfo GetProcessInfo(pid_t id) {
    return {id, GetProcessName(id), GetProcessPath(id)};
  }*/

  System::Array<intptr> GetProcesses() {
    System::Collections::Generic::List<intptr> processes;

    pid_t pids[16384];
    int count = proc_listallpids(&pids, 16384 * sizeof(pid_t));
    for (int index = 0; index < count; index++)
      if (pids[index] != 0)
        processes.Add(pids[index]);
    return processes.ToArray();
  }
}
#else
string GetProcessPath(pid_t id) {
  return "";
}

string GetProcessName(pid_t id) {
  return "";
}

/*
ProcessInfo GetProcessInfo(pid_t id) {
  return {id, GetProcessName(id), GetProcessPath(id)};
}*/

System::Array<intptr> GetProcesses() {
  System::Collections::Generic::List<intptr> processes;
  return processes.ToArray();
}
#endif

intptr Native::ProcessApi::Start(const System::Diagnostics::ProcessStartInfo& processStartInfo) {
  pid_t processId = fork();
  if (processId == 0) {
    System::Array<string> subStrings = string::Format("{0}{1}{2}", processStartInfo.FileName, string::IsNullOrEmpty(processStartInfo.Arguments) ? "" : " ", processStartInfo.Arguments()).Split(' ');
    System::Array<const char*> arguments(subStrings.Length + 1);
    for (int i = 0; i < subStrings.Length; i++)
      arguments[i] = subStrings[i].Data();
    arguments[subStrings.Length] = null;
    execv(processStartInfo.FileName().Data(), (char* const*)arguments.Data());
    exit(errno);
  }
  return processId;
}

bool Native::ProcessApi::Close(intptr handle) {
  return true;
}

bool Native::ProcessApi::Kill(intptr handle) {
  return kill((pid_t)handle, SIGKILL) == 0;
}

intptr Native::ProcessApi::GetCurrent() {
  return getpid();
}

intptr Native::ProcessApi::GetParent() {
  return getppid();
}

string Native::ProcessApi::GetName(intptr handle) {
  return ::GetProcessName((int32_t)handle);
}

string Native::ProcessApi::GetPath(intptr handle) {
  return ::GetProcessPath((int32_t)handle);
}

System::Array<intptr> Native::ProcessApi::GetProcesses() {
  return ::GetProcesses();
}

void Native::ProcessApi::WaitForExit(intptr handle, int32& exitCode) {
  siginfo_t waitInfo;
  memset(&waitInfo, 0, sizeof(siginfo_t));
  waitInfo.si_pid = (int32_t)handle;
  waitid(P_PID, (int32_t)handle, &waitInfo, WEXITED | WSTOPPED | WCONTINUED | WNOWAIT);
  exitCode = waitInfo.si_code;
}

bool Native::ProcessApi::WaitForExit(intptr handle, int32 timeout, int32& exitCode) {
  return false;
}

#endif
