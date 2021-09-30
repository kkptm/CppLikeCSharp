#include "../../../../include/Switch/System/IO/Directory.hpp"
#include "../../../../include/Switch/System/IO/File.hpp"
#include "../../../../include/Switch/System/IO/DirectoryNotFoundException.hpp"
#include "../../../../include/Switch/System/IO/Path.hpp"
#include "../../../../include/Switch/System/Security/SecurityException.hpp"
#include "../../../../include/Switch/System/Text/StringBuilder.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::IO;

const DirectoryInfo DirectoryInfo::Empty;

DirectoryInfo::DirectoryInfo(const string& path) {
  this->fullPath = Path::GetFullPath(path);
}

bool DirectoryInfo::GetExists() const {
  System::IO::FileAttributes fileAttributes = (System::IO::FileAttributes)0;
  return (Native::DirectoryApi::GetFileAttributes(this->fullPath.Data(), fileAttributes) == 0 && Enum<FileAttributes>(fileAttributes).HasFlag(FileAttributes::Directory));
}

string DirectoryInfo::GetName() const {
  Array<string> array = this->fullPath.Split(Path::DirectorySeparatorChar());
  if (array.Length == 0)
    return this->fullPath;
  return array[array.Length - 1];
}

DirectoryInfo DirectoryInfo::GetParent() const {
  if (this->fullPath == Path::GetPathRoot(this->fullPath))
    return Empty;
  return DirectoryInfo(Path::Combine(this->fullPath, ".."));
}

DirectoryInfo DirectoryInfo::GetRoot() const {
  return DirectoryInfo(Path::GetPathRoot(this->fullPath));
}

void DirectoryInfo::Create() {
  if (Native::DirectoryApi::CreateDirectory(this->fullPath) != 0)
    throw IOException(caller_);
}

DirectoryInfo DirectoryInfo::CreateSubdirectory(const string& path) {
  DirectoryInfo dirInfo(Path::Combine(this->fullPath, path));
  if (!dirInfo.Exists())
    dirInfo.Create();
  return dirInfo;
}

void DirectoryInfo::Delete(bool recursive) {
  if (!this->Exists())
    throw Security::SecurityException(caller_);

  if (recursive) {
    for (string item : Native::DirectoryApi::EnumerateFiles(this->fullPath, "*"))
      File::Delete(Path::Combine(this->fullPath, item));
    for (string item : Native::DirectoryApi::EnumerateDirectories(this->fullPath, "*"))
      Directory::Delete(Path::Combine(this->fullPath, item), true);
  }

  if (Native::DirectoryApi::RemoveDirectory(this->fullPath) != 0)
    throw IOException(caller_);
}

Array<FileInfo> DirectoryInfo::GetFiles(const string& searchPattern) const {
  System::Collections::Generic::List<FileInfo> files;
  for (string item : Native::DirectoryApi::EnumerateFiles(this->fullPath, searchPattern))
    files.Add(FileInfo(Path::Combine(this->fullPath, item)));
  return files.ToArray();
}

Array<DirectoryInfo> DirectoryInfo::GetDirectories(const string& searchPattern) const {
  System::Collections::Generic::List<DirectoryInfo> directories;
  for (string item : Native::DirectoryApi::EnumerateDirectories(this->fullPath, searchPattern))
    directories.Add(DirectoryInfo(Path::Combine(this->fullPath, item)));
  return directories.ToArray();
}

void DirectoryInfo::MoveTo(const string& destDirName) {
  DirectoryInfo destDirInfo(destDirName);

  if (destDirName == "" || destDirInfo.Exists() || Equals(destDirInfo) || !Path::GetPathRoot(this->FullName).Equals(Path::GetPathRoot(destDirInfo.FullName)) || destDirInfo.FullName().StartsWith(this->FullName))
    throw IOException(caller_);

  if (!destDirInfo.Exists())
    throw DirectoryNotFoundException(caller_);

  string targetDirName = Path::Combine(destDirName, this->fullPath.Substring(this->fullPath.LastIndexOf(Path::DirectorySeparatorChar()) + 1));
  Directory::CreateDirectory(targetDirName);

  for (string item : Native::DirectoryApi::EnumerateFiles(this->fullPath, "*"))
    File::Move(Path::Combine(this->fullPath, item), Path::Combine(targetDirName, item));
  for (string item : Native::DirectoryApi::EnumerateDirectories(this->fullPath, "*"))
    Directory::Move(Path::Combine(this->fullPath, item), Path::Combine(targetDirName, item));

  Delete();
  this->fullPath = targetDirName;
}
