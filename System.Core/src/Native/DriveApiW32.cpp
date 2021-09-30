#if defined(_WIN32)

#include <windows.h>
#include "../../include/Switch/Undef.hpp"

#include "Api.hpp"
#include "../../include/Switch/System/Collections/Generic/List.hpp"

bool Native::DriveApi::GetAvailableFreeSpace(const string& rootPathName, int64& freeBytes, int64& totalNumberOfBytes, int64& totalNumberOfFreeBytes) {
  bool retValue = false;
  WCHAR rootPathNameName[MAX_PATH];
  if (rootPathName.Length() + 1 <= MAX_PATH) {
    ::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, rootPathName.Data(), -1, rootPathNameName, sizeof(rootPathNameName) / sizeof(rootPathNameName[0]));
    retValue = ::GetDiskFreeSpaceExW(rootPathNameName, (PULARGE_INTEGER)&freeBytes, (PULARGE_INTEGER)&totalNumberOfBytes, (PULARGE_INTEGER)&totalNumberOfFreeBytes) != FALSE;
  }
  return retValue;
}

System::IO::DriveType Native::DriveApi::GetDriveType(const string& rootPathName) {
  return (System::IO::DriveType)::GetDriveTypeA(rootPathName.Data());
}

System::Array<string> Native::DriveApi::GetDrives() {
  char buffer[MAX_PATH];
  int32 bufferLenght = MAX_PATH;
  if (::GetLogicalDriveStringsA(bufferLenght, buffer) <= 0)
    return {};
  System::Collections::Generic::List<string> drives;
  for (const char* drive = buffer; drive[0] != 0; drive += strlen(drive) + 1)
    drives.Add(drive);
  return drives.ToArray();
}

bool Native::DriveApi::GetVolumeInformation(const string& rootPathName, string& volumeName, string& fileSystemName) {
  DWORD fileSystemFlags = 0;
  char volume[MAX_PATH];
  char fileSystem[MAX_PATH];
  if (::GetVolumeInformationA(rootPathName.Data(), volume, MAX_PATH, null, null, &fileSystemFlags, fileSystem, MAX_PATH) == FALSE)
    return false;

  volumeName = volume;
  fileSystemName = fileSystem;

  return true;
}

bool Native::DriveApi::SetVolumeLabel(const string& rootPathName, const string& volumeName) {
  return ::SetVolumeLabelA(rootPathName.Data(), volumeName.Data()) > 0;
}

#endif
