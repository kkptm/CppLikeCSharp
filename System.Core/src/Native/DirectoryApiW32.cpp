#if defined(_WIN32)

#define _CRT_SECURE_NO_WARNINGS

#include <direct.h>
#include <shlobj.h>
#include <sys/stat.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <windows.h>
#include "../../include/Switch/Undef.hpp"

#include "Api.hpp"

namespace {
  class Enumerator : public System::Collections::Generic::IEnumerator<string> {
  public:
    enum class FileType {
      File,
      Directory
    };

    Enumerator(const string& path, const string& pattern, FileType fileType) : path(path), pattern(pattern), fileType(fileType) {}
    ~Enumerator() { Reset(); }

    bool MoveNext() override {
      WIN32_FIND_DATAA item;
      string searchPattern = string::Format("{0}{1}{2}", this->path, this->path.EndsWith('\\') ? "" : System::Char('\\').ToString(), this->pattern);
      bool result = this->handle == null ? (this->handle = FindFirstFileA(searchPattern.Data(), &item)) != null : FindNextFileA(this->handle, &item) != FALSE;
      while (result == true && (((this->fileType == FileType::Directory && (item.dwFileAttributes & 0x0010) != 0x0010) || (this->fileType == FileType::File && (item.dwFileAttributes & 0x0010) == 0x0010)) || string(item.cFileName) == "." || string(item.cFileName) == ".."))
        result = FindNextFileA(this->handle, &item) != FALSE;

      if (result)
        this->current = string::Format("{0}{1}{2}", this->path, this->path.EndsWith('\\') ? "" : System::Char('\\').ToString(), item.cFileName);
      return result;
    }

    void Reset() override {
      if (this->handle != null)
        FindClose(this->handle);
      this->handle = null;
    }

  protected:
    const string& GetCurrent() const override {
      if (this->handle == null)
        throw System::InvalidOperationException(caller_);
      return this->current;
    }

  private:
    string path;
    string pattern;
    HANDLE handle = null;
    mutable string current;
    FileType fileType;
  };
}

char32 Native::DirectoryApi::AltDirectorySeparatorChar() {
  return '/';
}

char32 Native::DirectoryApi::DirectorySeparatorChar() {
  return '\\';
}

char32 Native::DirectoryApi::PathSeparator() {
  return ';';
}

System::Array<char32> Native::DirectoryApi::InvalidPathChars() {
  return {34, 60, 62, 124, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0};
}

char32 Native::DirectoryApi::VolumeSeparator() {
  return ':';
}

System::Collections::Generic::Enumerator<string> Native::DirectoryApi::EnumerateDirectories(const string& path, const string& pattern) {
  return System::Collections::Generic::Enumerator<string>(new Enumerator(path, pattern, Enumerator::FileType::Directory));
}

System::Collections::Generic::Enumerator<string> Native::DirectoryApi::EnumerateFiles(const string& path, const string& pattern) {
  return System::Collections::Generic::Enumerator<string>(new Enumerator(path, pattern, Enumerator::FileType::File));
}

int32 Native::DirectoryApi::GetFileAttributes(const string& path, System::IO::FileAttributes& attributes) {
  attributes = (System::IO::FileAttributes)GetFileAttributesA(path.Data());
  if (attributes == (System::IO::FileAttributes)INVALID_FILE_ATTRIBUTES)
    return -1;
  return 0;
}

int32 Native::DirectoryApi::GetFileTime(const string& path, int64& creationTime, int64& lastAccessTime, int64& lastWriteTime) {
  struct stat fileStat;
  if (stat(path.Data(), &fileStat) != 0)
    return -1;
  creationTime = (int64)fileStat.st_ctime;
  lastAccessTime = (int64)fileStat.st_atime;
  lastWriteTime = (int64)fileStat.st_mtime;
  return 0;
}


string Native::DirectoryApi::GetFullPath(const string& relPath) {
  char buffer[MAX_PATH];
  if (_fullpath(buffer, relPath.Data(), MAX_PATH) == null)
    return string::Empty;
  return buffer;
}

string Native::DirectoryApi::GetCurrentDirectory() {
  char buffer[MAX_PATH];
  if (_getcwd(buffer, MAX_PATH) == null)
    return string::Empty;
  return buffer;
}

int32 Native::DirectoryApi::SetCurrentDirectory(const string& directoryName) {
  return _chdir(directoryName.Data());
}

int64 Native::DirectoryApi::GetFileSize(const string& path) {
  WIN32_FIND_DATAA file;
  void* handle = FindFirstFileA(path.Data(), &file);
  if (handle == INVALID_HANDLE_VALUE)
    return 0;

  ULARGE_INTEGER size;
  size.HighPart = file.nFileSizeHigh;
  size.LowPart = file.nFileSizeLow;
  FindClose(handle);
  return size.QuadPart;
}

int32 Native::DirectoryApi::CreateDirectory(const string& directoryName) {
  return CreateDirectoryA(directoryName.Data(), null) != FALSE ? 0 : -1;
}

int32 Native::DirectoryApi::RemoveDirectory(const string& directoryName) {
  return RemoveDirectoryA(directoryName.Data()) != FALSE ? 0 : -1;
}

int32 Native::DirectoryApi::RemoveFile(const string& path) {
  return ::remove(path.Data());
}

int32 Native::DirectoryApi::RenameFile(const string& oldPath, const string& newPath) {
  System::IO::FileAttributes fileAttributes = (System::IO::FileAttributes)0;
  if (GetFileAttributes(newPath, fileAttributes) == 0)
    return -1;
  return ::rename(oldPath.Data(), newPath.Data());
}

string Native::DirectoryApi::GetKnowFolderPath(System::Environment::SpecialFolder id) {
  char path[MAX_PATH];
  if (SHGetFolderPathA(null, static_cast<int>(id), null, SHGFP_TYPE_CURRENT, path) != S_OK)
    return string::Empty;
  return path;
}

string Native::DirectoryApi::GetTempPath() {
  if (getenv("TMP") != null)
    return getenv("TMP");

  if (getenv("TEMP") != null)
    return getenv("TEMP");

  if (getenv("USERPROFILE") != null)
    return getenv("USERPROFILE");

  return getenv("WINDIR");
}

#endif
