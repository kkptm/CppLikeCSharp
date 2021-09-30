#define _CRT_SECURE_NO_WARNINGS

#include "../../../../include/Switch/Types.hpp"
#include "../../../../include/Switch/System/IO/FileInfo.hpp"
#include "../../../../include/Switch/System/Security/SecurityException.hpp"
#include "../../../../include/Switch/System/IO/DirectoryInfo.hpp"
#include "../../../../include/Switch/System/IO/File.hpp"
#include "../../../../include/Switch/System/IO/FileNotFoundException.hpp"
#include "../../../../include/Switch/System/IO/Path.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::IO;

const FileInfo FileInfo::Empty;

FileInfo::FileInfo() : Directory(delegate_ {return this->GetDirectory();}) {
}

FileInfo::FileInfo(const string& fileName) : Directory(delegate_ {return this->GetDirectory();}) {
  this->fullPath = Path::GetFullPath(fileName);
}

FileInfo::FileInfo(const FileInfo& fileInfo) : FileSystemInfo(fileInfo), Directory(delegate_ {return this->GetDirectory();}) { }

bool FileInfo::GetExists() const {
  System::IO::FileAttributes fileAttributes = (System::IO::FileAttributes)0;
  return (Native::DirectoryApi::GetFileAttributes(this->fullPath.ToCCharArray().Data(), fileAttributes) == 0 && !Enum<FileAttributes>(fileAttributes).HasFlag(FileAttributes::Directory));
}

DirectoryInfo FileInfo::GetDirectory() const {
  return DirectoryInfo(DirectoryName());
}

string FileInfo::GetDirectoryName() const {
  return Path::Combine(Path::GetPathRoot(this->fullPath), Path::GetDirectoryName(this->fullPath));
}

string FileInfo::GetName() const {
  return Path::GetFileName(this->fullPath);
}

void FileInfo::Delete() {
  if (Native::DirectoryApi::RemoveFile(this->fullPath.ToCCharArray().Data()) != 0)
    throw System::Security::SecurityException(caller_);
}

FileInfo FileInfo::CopyTo(const string& destFileName) {
  if (!Exists())
    throw FileNotFoundException(caller_);

  if (File::Exists(destFileName))
    throw IOException(caller_);

  string fullPathDestFileName = Path::GetFullPath(destFileName);

  FILE* source = fopen(this->fullPath.ToCCharArray().Data(), "rb");
  if (source == null)
    throw IOException(caller_);

  FILE* target = fopen(fullPathDestFileName.ToCCharArray().Data(), "wb");
  if (target == null) {
    fclose(source);
    throw IOException(caller_);
  }

  int32 count = 0;
  do {
    byte buffer[1024];
    count = Convert::ToInt32(fread(buffer, 1, 1024, source));
    if (count > 0)
      fwrite(buffer, 1, count, target);
  } while (count == 1024);

  fclose(source);
  fclose(target);

  return FileInfo(fullPathDestFileName);
}

FileInfo FileInfo::CopyTo(const string& destFileName, bool overwrite) {
  if (overwrite) {
    FileInfo DestFileInfo(destFileName);
    if (DestFileInfo.Exists())
      DestFileInfo.Delete();
  }
  return CopyTo(destFileName);
}

void FileInfo::MoveTo(const string& destFileName) {
  if (!Exists())
    throw FileNotFoundException(caller_);

  if (!Path::HasExtension(destFileName))
    throw ArgumentException(caller_);

  string fullPathDestFileName = Path::GetFullPath(destFileName);
  if (Native::DirectoryApi::RenameFile(this->fullPath, fullPathDestFileName) != 0)
    throw IOException(caller_);

  this->fullPath = fullPathDestFileName;
}

int64 FileInfo::GetLength() const {
  return Native::DirectoryApi::GetFileSize(this->fullPath);
}

FileStream FileInfo::Open(FileMode mode, FileAccess access) {
  return FileStream(this->fullPath, mode, access, FileShare(FileShare::None));
}

FileStream FileInfo::OpenRead() {
  return FileStream(this->fullPath, FileMode(FileMode::Open), FileAccess(FileAccess::Read), FileShare(FileShare::None));
}

FileStream FileInfo::OpenWrite() {
  return FileStream(this->fullPath, FileMode(FileMode::OpenOrCreate), FileAccess(FileAccess::Write), FileShare(FileShare::None));
}

bool FileInfo::Equals(const FileInfo& value) const {
  return this->fullPath.Equals(value.fullPath);
}

bool FileInfo::Equals(const object& obj) const {
  return is<FileInfo>(obj) && Equals((const FileInfo&)obj);
}

string FileInfo::ToString() const {
  return FullName();
}

