#include "../../../../include/Switch/System/IO/FileSystemInfo.hpp"
#include "../../../../include/Switch/System/IO/IOException.hpp"
#include "../../../../include/Switch/System/IO/Path.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::IO;

FileAttributes FileSystemInfo::GetAttributes() const {
  System::IO::FileAttributes fileAttributes = (System::IO::FileAttributes)0;
  if (Native::DirectoryApi::GetFileAttributes(this->fullPath.ToCCharArray().Data(), fileAttributes) != 0)
    throw IOException(caller_);

  return fileAttributes;
}

DateTime FileSystemInfo::GetCreationTime() const {
  int64 time = 0;
  int64 dummy;
  if (Native::DirectoryApi::GetFileTime(this->fullPath.ToCCharArray().Data(), time, dummy, dummy) != 0)
    throw IOException(caller_);

  return DateTime::FromFileTime((int64)time * 10000000LL);
}

DateTime FileSystemInfo::GetCreationTimeUtc() const {
  return GetCreationTime().ToUniversalTime();
}

string FileSystemInfo::GetExtension() const {
  return Path::GetExtension(this->fullPath);
}

DateTime FileSystemInfo::GetLastAccessTime() const {
  int64 time = 0;
  int64 dummy;
  if (Native::DirectoryApi::GetFileTime(this->fullPath.ToCCharArray().Data(), dummy, time, dummy) != 0)
    throw IOException(caller_);

  return DateTime::FromFileTime((int64)time);
}

DateTime FileSystemInfo::GetLastAccessTimeUtc() const {
  return GetLastAccessTime().ToUniversalTime();
}

DateTime FileSystemInfo::GetLastWriteTime() const {
  int64 time = 0;
  int64 dummy;
  if (Native::DirectoryApi::GetFileTime(this->fullPath.ToCCharArray().Data(), dummy, dummy, time) != 0)
    throw IOException(caller_);

  return DateTime::FromFileTime((int64)time);
}

DateTime FileSystemInfo::GetLastWriteTimeUtc() const {
  return GetLastWriteTime().ToUniversalTime();
}

bool FileSystemInfo::IsNullOrEmpty(const FileSystemInfo& fileSystemInfo) {
  return string::IsNullOrEmpty(fileSystemInfo.fullPath);
}
