#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <tlhelp32.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"

intptr Native::ProcessApi::Start(const System::Diagnostics::ProcessStartInfo& processStartInfo) {
  System::Array<string> variables(processStartInfo.EnvironmentVariables().Count + 1);
  System::Array<const char*> environmentVariables(processStartInfo.EnvironmentVariables().Count + 1);
  int32 index = 0;
  for (const auto& keyValue : processStartInfo.EnvironmentVariables()) {
    variables[index] = string::Format("{0}={1}", keyValue.Key, keyValue.Value);
    environmentVariables[index] = variables[index].c_str();
    index++;
  }
  environmentVariables[index] = null;

  //for (const char* value = *environmentVariables.Data(); *value != 0; value = value + strlen(value) + 1)
  //  System::Console::WriteLine(value);

  const char* const vars[] = {"Var1=MyVariable1", "Var2=MyVariable2", null};
  //const char* const* vars2 = environmentVariables.Data();
  const char* const* vars3 = vars;

  STARTUPINFO startupInfo;
  memset(&startupInfo, 0, sizeof(STARTUPINFO));
  startupInfo.cb = sizeof(STARTUPINFO);
  PROCESS_INFORMATION processInformation;
  CreateProcess(processStartInfo.FileName().w_str().c_str(), (wchar*)processStartInfo.Arguments().w_str().c_str(), NULL, NULL, FALSE, 0, (LPVOID)vars3, string::IsNullOrEmpty(processStartInfo.WorkingDirectory()) ? NULL : processStartInfo.WorkingDirectory().w_str().c_str(), &startupInfo, &processInformation);
  //CreateProcess(processStartInfo.FileName().w_str().c_str(), (wchar*)processStartInfo.Arguments().w_str().c_str(), NULL, NULL, FALSE, 0, (LPVOID)*environmentVariables.Data(), processStartInfo.WorkingDirectory().IsEmpty() ? NULL : processStartInfo.WorkingDirectory().w_str().c_str(), &startupInfo, &processInformation);
  ///CreateProcess(processStartInfo.FileName().w_str().c_str(), (wchar*)processStartInfo.Arguments().w_str().c_str(), NULL, NULL, FALSE, 0, NULL, processStartInfo.WorkingDirectory().IsEmpty() ? NULL : processStartInfo.WorkingDirectory().w_str().c_str(), &startupInfo, &processInformation);
  return (intptr)processInformation.hProcess;
}

bool Native::ProcessApi::Close(intptr handle) {
  return CloseHandle((HANDLE)handle) != FALSE;
}

bool Native::ProcessApi::Kill(intptr handle) {
  return TerminateProcess((HANDLE)handle, (uint32) - 1) != FALSE;
}

intptr Native::ProcessApi::GetCurrent() {
  return (intptr)GetCurrentProcess();
}

intptr Native::ProcessApi::GetParent() {
  HANDLE hSnapshot;
  PROCESSENTRY32 pe32;
  DWORD ppid = 0, pid = GetCurrentProcessId();

  hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  __try {
    if (hSnapshot == INVALID_HANDLE_VALUE) __leave;

    ZeroMemory(&pe32, sizeof(pe32));
    pe32.dwSize = sizeof(pe32);
    if (!Process32First(hSnapshot, &pe32)) __leave;

    do {
      if (pe32.th32ProcessID == pid) {
        ppid = pe32.th32ParentProcessID;
        break;
      }
    } while (Process32Next(hSnapshot, &pe32));

  } __finally {
    if (hSnapshot != INVALID_HANDLE_VALUE) CloseHandle(hSnapshot);
  }
  return ppid;
}

string Native::ProcessApi::GetName(intptr handle) {
  return "";  // ::GetProcessName(handle);
}

string Native::ProcessApi::GetPath(intptr handle) {
  return ""; //::GetProcessPath(handle);
}

System::Array<intptr> Native::ProcessApi::GetProcesses() {
  return {}; // ::GetProcesses();
}
void Native::ProcessApi::WaitForExit(intptr handle, int32& exitCode) {
  WaitForSingleObject((HANDLE)handle, INFINITE);
}

bool Native::ProcessApi::WaitForExit(intptr handle, int32 timeout, int32& exitCode) {
  bool result = WaitForSingleObject((HANDLE)handle, timeout) == 0;
  return result;
}

#endif
