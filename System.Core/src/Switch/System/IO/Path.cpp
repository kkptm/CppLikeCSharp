#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

#include "../../../../include/Switch/System/IO/Path.hpp"
#include "../../../../include/Switch/System/IO/File.hpp"
#include "../../../../include/Switch/System/IO/DriveInfo.hpp"
#include "../../../../include/Switch/System/IO/FileAttributes.hpp"
#include "../../../../include/Switch/System/Char.hpp"
#include "../../../../include/Switch/System/Random.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::IO;

char32 Path::AltDirectorySeparatorChar() {
  return Native::DirectoryApi::AltDirectorySeparatorChar();
}

char32 Path::DirectorySeparatorChar() {
  return Native::DirectoryApi::DirectorySeparatorChar();
}

char32 Path::PathSeparator() {
  return Native::DirectoryApi::PathSeparator();
}

char32 Path::VolumeSeparatorChar() {
  return Native::DirectoryApi::VolumeSeparator();
}

Array<char32> DirectorySeparatorChars = {'/', '\\'};

string Path::ChangeExtension(const string& path, const string& extension) {
  string pathWithoutExtension = Combine(GetDirectoryName(path), GetFileNameWithoutExtension(path));
  if (string::IsNullOrEmpty(pathWithoutExtension) && !string::IsNullOrEmpty(extension))
    return pathWithoutExtension;
  return string::Format("{0}{1}{2}", pathWithoutExtension, pathWithoutExtension.EndsWith('.')  || extension.StartsWith('.') ? "" : ".", extension);
}

string Path::GetDirectoryName(const string& path) {
  int32 index = path.LastIndexOfAny(DirectorySeparatorChars);
  if (index == -1 || index == path.Length)
    return "";
  string directory = path.Remove(index + 1);
  return (directory.LastIndexOfAny(DirectorySeparatorChars) == directory.Length - 1) ? directory.Remove(directory.Length - 1) : directory;
}

string Path::GetExtension(const string& path) {
  string file = GetFileName(path);
  int32 index = file.LastIndexOf('.');
  return (index == -1 || index == file.Length) ? "" : file.Substring(index);
}

String Path::GetFileName(const String& path) {
  int32 index = path.LastIndexOfAny(DirectorySeparatorChars);
  return (index == -1 || index == path.Length) ? path : path.Substring(index + 1);
}

string Path::GetFileNameWithoutExtension(const string& path) {
  string file = GetFileName(path);
  int32 index = file.LastIndexOf('.');
  return (index == -1 || index == file.Length) ? file : file.Remove(index);
}

string Path::GetFullPath(const string& path) {
  if (path.IndexOfAny(GetInvalidPathChars()) != -1)
    throw ArgumentException(caller_);

  return Native::DirectoryApi::GetFullPath(path);
}

Array<char32> Path::GetInvalidPathChars() {
  return Array<char32>(Native::DirectoryApi::InvalidPathChars());
}

namespace {
  bool IsDrive(const string& path) {
    for (auto drive : DriveInfo::GetDrives())
      if (drive.Name == path)
        return true;
    return false;
  }

  static int32 GetIndexPathRooted(const String& path) {
    int32 index = path.IndexOfAny(DirectorySeparatorChars);
    return (index == -1 || index == path.Length || (index != 0 && !IsDrive(path.Substring(0, index + 1)))) ? -1 : index;
  }
}

string Path::GetPathRoot(const string& path) {
  return IsPathRooted(path) ? path.Remove(GetIndexPathRooted(path) + 1) : "";
}

string Path::GetRandomFileName() {
  static string validChars = "1234567890abcdefghijklmnopqrstuvwxyz";
  static Random rand;
  string randomFileName;

  for (int32 i = 0; i < 11; i++) {
    randomFileName += validChars[rand.Next(validChars.Length)];
    if (i == 7)
      randomFileName += '.';
  }

  return randomFileName;
}

string Path::GetTempPath() {
  return Native::DirectoryApi::GetTempPath();
}

string Path::GetTempFileName() {
  static string validChars = "1234567890abcdef";
  string tempFileName;
  do {
    static Random rand;
    tempFileName = "tmp";

    for (int32 i = 0; i < 8; i++) {
      if (i == 0)
        tempFileName += validChars[rand.Next(10)];
      else
        tempFileName += validChars[rand.Next(validChars.Length)];
    }
    tempFileName += ".tmp";
  } while (File::Exists(Combine(GetTempPath(), tempFileName)));

  FILE* file = fopen(Combine(GetTempPath(), tempFileName).Data(), "w");
  if (file != null)
    fclose(file);

  return Combine(GetTempPath(), tempFileName);
}

bool Path::IsPathRooted(const String& path) {
  return GetIndexPathRooted(path) != -1;
}

