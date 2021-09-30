#if defined(_WIN32)

#define UNICODE
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <Lmcons.h>
#include "../../include/Switch/Undef.hpp"

#include "Api.hpp"

System::PlatformID Native::EnvironmentApi::GetOsPlatformID() {
  return System::PlatformID::Win32NT;
}

string Native::EnvironmentApi::NewLine() {
  return "\r\n";
}

int32 Native::EnvironmentApi::GetOsVersion(int32& major, int32& minor, int32& build, int32& revision) {
#pragma warning(push)
#pragma warning(disable : 4996)
  OSVERSIONINFOEX versionInfo;
  ZeroMemory(&versionInfo, sizeof(OSVERSIONINFOEX));
  versionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  if (GetVersionEx((LPOSVERSIONINFO)&versionInfo)) {
    major = versionInfo.dwMajorVersion;
    minor = versionInfo.dwMinorVersion;
    build = versionInfo.dwBuildNumber;
    revision = versionInfo.wServicePackMajor << 16;
  }
#pragma warning(pop)
  return 0;
}

bool Native::EnvironmentApi::IsOs64Bit() {
  SYSTEM_INFO systemInfo;
  GetNativeSystemInfo(&systemInfo);
  return (systemInfo.wProcessorArchitecture & (PROCESSOR_ARCHITECTURE_AMD64 | PROCESSOR_ARCHITECTURE_ARM64 | PROCESSOR_ARCHITECTURE_IA64)) != 0;
}

string Native::EnvironmentApi::GetMachineName() {
  wchar machineName[MAX_COMPUTERNAME_LENGTH + 1];
  DWORD size = MAX_COMPUTERNAME_LENGTH + 1;
  if (!GetComputerName(machineName, &size))
    return "";
  return machineName;
}

int32 Native::EnvironmentApi::GetProcessorCount() {
  SYSTEM_INFO systemInfo;
  GetNativeSystemInfo(&systemInfo);
  return systemInfo.dwNumberOfProcessors;
}

int32 Native::EnvironmentApi::GetSystemPageSize() {
  SYSTEM_INFO systemInfo;
  GetNativeSystemInfo(&systemInfo);
  return systemInfo.dwPageSize;
}

int32 Native::EnvironmentApi::GetTickCount() {
  return ::GetTickCount();
}

string Native::EnvironmentApi::GetUserDomainName() {
  char name[512];
  strcpy_s(name, 512, getenv("USERDOMAIN"));
  return name;

  /*
  DWORD size = 0;
  GetComputerNameEx(ComputerNameDnsHostname, null, &size);
  System::Array<wchar> userDomainName(size);
  if (!GetComputerNameEx(ComputerNameDnsHostname, (wchar*)userDomainName.Data(), &size))
    return "";
  return userDomainName.Data();
  */
}

string Native::EnvironmentApi::GetUserName() {
  wchar userName[UNLEN + 1];
  DWORD size = UNLEN + 1;
  if (!GetUserNameW(userName, &size))
    return "";
  return userName;
}

int64 Native::EnvironmentApi::GetWorkingSet() {
  return 0;
}

int32 Native::EnvironmentApi::SetEnv(const string& name, const string& value) {
  return _putenv(string::Format("{0}={1}", name, value).Data);
}

int32 Native::EnvironmentApi::UnsetEnv(const string& name) {
  return _putenv(string::Format("{0}=", name).Data);
}

System::Guid Native::EnvironmentApi::NewGuid() {
  UUID guid;
  UuidCreate(&guid);
  return System::Guid(guid.Data1, guid.Data2, guid.Data3, guid.Data4);
}

#endif
