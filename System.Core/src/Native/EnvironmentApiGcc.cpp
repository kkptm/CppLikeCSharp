#if defined(__linux__) || defined(__APPLE__)

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <time.h>
#if !defined(__ANDROID__)
#include <uuid/uuid.h>
#else
#include "../../include/Switch/System/Random.hpp"
#endif

#include <sys/time.h>

#if defined(__APPLE__)
#include <time.h>
#include <sys/sysctl.h>
#else
#include <sys/sysinfo.h>
#endif

#include "Api.hpp"

namespace {
  static string CreateProcess(const string& command) {
    FILE* fs = popen(command.Data(), "r");
    string result;
    while (!feof(fs)) {
      char buf[513];
      int32 l = (int32)fread(buf, 1, 512, fs);
      buf[l] = 0;
      result += buf;
    }
    pclose(fs);
    return result;
  }
}

string Native::EnvironmentApi::NewLine() {
  return "\n";
}

System::PlatformID Native::EnvironmentApi::GetOsPlatformID() {
  #if defined(__APPLE__)
  return System::PlatformID::MacOSX;
  #else
  return System::PlatformID::Unix;
  #endif
}

int32 Native::EnvironmentApi::GetOsVersion(int32& major, int32& minor, int32& build, int32& revision) {
  #if defined(__APPLE__)
  System::Array<string> numbers = CreateProcess("sw_vers -productVersion").Split({'.', '\n'});
  #else
  System::Array<string> numbers = CreateProcess("uname -r").Split({'.', '-', '\n'});
  #endif
  if (numbers.Length() < 1 || !System::Int32::TryParse(numbers[0], major))
    major = 0;
  if (numbers.Length() < 2 || !System::Int32::TryParse(numbers[1], minor))
    minor = 0;
  if (numbers.Length() < 3 || !System::Int32::TryParse(numbers[2], build))
    build = 0;
  if (numbers.Length() < 4 || !System::Int32::TryParse(numbers[3], revision))
    revision = 0;
  return 0;
}

bool Native::EnvironmentApi::IsOs64Bit() {
  return CreateProcess("uname -m").EndsWith("64");
}

string Native::EnvironmentApi::GetMachineName() {
  return CreateProcess("uname -n");
}

int32 Native::EnvironmentApi::GetProcessorCount() {
  return as<int32>(std::thread::hardware_concurrency());
}

int32 Native::EnvironmentApi::GetSystemPageSize() {
  return 4096;
}

int32 Native::EnvironmentApi::GetTickCount() {
  #if defined (__APPLE__)
  // https://stackoverflow.com/questions/3269321/osx-programmatically-get-uptime
  struct timeval boottime, nowtime;
  size_t len = sizeof(boottime);
  int mib[2] = { CTL_KERN, KERN_BOOTTIME };
  sysctl(mib, 2, &boottime, &len, NULL, 0);
  gettimeofday(&nowtime, NULL);
  return (int32)((nowtime.tv_sec - boottime.tv_sec) * 1000) + ((nowtime.tv_usec - boottime.tv_usec) / 1000);
  #else
  // https://stackoverflow.com/questions/1540627/what-api-do-i-call-to-get-the-system-uptime
  struct sysinfo info;
  sysinfo(&info);
  return info.uptime * 1000;
  #endif
}

string Native::EnvironmentApi::GetUserDomainName() {
  return CreateProcess("uname -n").TrimEnd('\n');
}

string Native::EnvironmentApi::GetUserName() {
  char name[512];
  strcpy(name, getenv("USER"));
  return name;
}

int64 Native::EnvironmentApi::GetWorkingSet() {
  return 0;
}

int32 Native::EnvironmentApi::SetEnv(const string& name, const string& value) {
  return setenv(name.Data, value.Data, 1);
}

int32 Native::EnvironmentApi::UnsetEnv(const string& name) {
  return unsetenv(name.Data);
}

System::Guid Native::EnvironmentApi::NewGuid() {
  #if !defined(__ANDROID__)
  byte guid[16];
  uuid_generate(guid);
  #else
  // http://tools.ietf.org/html/rfc4122
  //
  // 0                   1                   2                   3
  // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |                          time_low                             |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |       time_mid                |         time_hi_and_version   |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |clk_seq_hi_res |  clk_seq_low  |         node (0-1)            |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |                         node (2-5)                            |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  //
  // 4.4 Algorithms for Creating a UUID from Truly Random or
  // Pseudo-Random Numbers
  //
  // The version 4 UUID is meant for generating UUIDs from truly-random or pseudo-random numbers.
  //
  // The algorithm is as follows:
  //  o  Set the two most significant bits (bits 6 and 7) of the clock_seq_hi_and_reserved to zero and one, respectively.
  //  o  Set the four most significant bits (bits 12 through 15) of the time_hi_and_version field to the 4-bit version number from Section 4.1.3.
  //  o  Set all the other bits to randomly (or pseudo-randomly) chosen values.
  static System::Random rand;
  System::Array<byte> guid(16);
  rand.NextBytes(guid);
  guid[8] &= 0xDF;
  guid[8] |= 0x40;
  guid[7] &= 0x0F;
  guid[7] |= 0x40;
  #endif
  return System::Guid(guid);
}

#endif
