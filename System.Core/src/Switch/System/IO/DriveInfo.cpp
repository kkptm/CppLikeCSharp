#include <cstring>

#include "../../../../include/Switch/System/UnauthorizedAccessException.hpp"
#include "../../../../include/Switch/System/IO/DriveInfo.hpp"
#include "../../../../include/Switch/System/IO/IOException.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::IO;

DriveInfo::DriveInfo(const String& name) {
  if (String::IsNullOrEmpty(name))
    throw ArgumentNullException(caller_);
  this->driveName = name;
}

int64 DriveInfo::GetAvailableFreeSpace() const {
  int64 freeBytes = 0, dummy;
  if (!Native::DriveApi::GetAvailableFreeSpace(this->driveName.Data(), freeBytes, dummy, dummy))
    throw IOException(caller_);

  return freeBytes;
}

String DriveInfo::GetDriveFormat() const {
  string volumeName, fileSystemName;
  if (!Native::DriveApi::GetVolumeInformation(this->driveName, volumeName, fileSystemName))
    throw IOException(caller_);

  return fileSystemName;
}

System::IO::DriveType DriveInfo::GetDriveType() const {
  return (System::IO::DriveType)Native::DriveApi::GetDriveType(this->driveName);
}

bool DriveInfo::GetIsReady() const {
  string volumeName, fileSystemName;
  return Native::DriveApi::GetVolumeInformation(this->driveName, volumeName, fileSystemName);
}

String DriveInfo::GetName() const {
  return this->driveName;
}

DirectoryInfo DriveInfo::GetRootDirectory() const {
  return DirectoryInfo(this->driveName);
}

int64 DriveInfo::GetTotalFreeSpace() const {
  int64 totalNumberOfFreeBytes = 0, dummy;
  if (!Native::DriveApi::GetAvailableFreeSpace(this->driveName.Data(), dummy, dummy, totalNumberOfFreeBytes))
    throw IOException(caller_);

  return totalNumberOfFreeBytes;
}

int64 DriveInfo::GetTotalSize() const {
  int64 totalNumberOfBytes = 0, dummy;
  if (!Native::DriveApi::GetAvailableFreeSpace(this->driveName.Data(), dummy, totalNumberOfBytes, dummy))
    throw IOException(caller_);

  return totalNumberOfBytes;
}

string DriveInfo::GetVolumeLabel() const {
  string volumeName, fileSystemName;
  if (!Native::DriveApi::GetVolumeInformation(this->driveName, volumeName, fileSystemName))
    throw IOException(caller_);
  return volumeName;
}

void DriveInfo::SetVolumeLabel(const String& label) {
  System::IO::DriveType drive = DriveType();
  if (drive == System::IO::DriveType::CDRom || drive == System::IO::DriveType::Network)
    throw UnauthorizedAccessException(caller_);

  if (!Native::DriveApi::SetVolumeLabel(this->driveName.Data(), label.Data()))
    throw IOException(caller_);
}

Array<DriveInfo> DriveInfo::GetDrives() {
  System::Collections::Generic::List<DriveInfo> drives;
  for (string drive : Native::DriveApi::GetDrives())
    drives.Add(DriveInfo(drive));
  return drives.ToArray();
}

String DriveInfo::ToString() const {
  return this->driveName;
}

