#if defined(__linux__) || defined(__APPLE__)

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#include "../../include/Switch/System/Collections/Generic/Dictionary.hpp"
#include "../../include/Switch/System/IO/FileAttributes.hpp"
#include "../../include/Switch/System/Environment.hpp"
#include "Api.hpp"

namespace {
  class Enumerator : public System::Collections::Generic::IEnumerator<string> {
  public:
    enum class FileType {
      File,
      Directory
    };

    Enumerator(const string& path, const string& pattern, FileType fileType) : path(path), pattern(pattern), fileType(fileType) {Reset();}
    ~Enumerator() {
      if (this->handle != null)
        closedir(this->handle);
    }

    bool MoveNext() override {
      dirent* item;
      System::IO::FileAttributes attributes;

      do {
        if ((item = readdir(this->handle)) != null)
          Native::DirectoryApi::GetFileAttributes(string::Format("{0}/{1}", this->path, item->d_name), attributes);
      } while (item != null && ((this->fileType == FileType::Directory && (attributes & System::IO::FileAttributes::Directory) != System::IO::FileAttributes::Directory) || (this->fileType == FileType::File && (attributes & System::IO::FileAttributes::Directory) == System::IO::FileAttributes::Directory) || string(item->d_name) == "." ||  string(item->d_name) == ".." ||  string(item->d_name).EndsWith(".app") || !PatternCompare(item->d_name, this->pattern)));

      if (item == null)
        return false;
      this->current = string::Format("{0}{1}{2}", this->path, this->path.EndsWith('/') ? "" : System::Char('/').ToString(), item->d_name);
      return true;
    }

    void Reset() override {
      if (this->handle != null)
        closedir(this->handle);
      this->handle = opendir(path.Data());
    }

  protected:
    const string& GetCurrent() const override {
      if (this->handle == null)
        throw System::InvalidOperationException(caller_);
      return this->current;
    }

  private:
    bool PatternCompare(const string& fileName, const string& pattern) {
      if (string::IsNullOrEmpty(pattern))
        return string::IsNullOrEmpty(fileName);

      if (string::IsNullOrEmpty(fileName))
        return false;

      if (pattern == "*")
        return true;

      if (pattern[0] == '*')
        return PatternCompare(fileName, pattern.Substring(1)) || PatternCompare(fileName.Substring(1), pattern);

      return ((pattern[0] == '?') || (fileName[0] == pattern[0])) && PatternCompare(fileName.Substring(1), pattern.Substring(1));
    }

    string path;
    string pattern;
    DIR* handle = null;
    mutable string current;
    FileType fileType;
  };
}

char32 Native::DirectoryApi::AltDirectorySeparatorChar() {
  return '/';
}

char32 Native::DirectoryApi::DirectorySeparatorChar() {
  return '/';
}

char32 Native::DirectoryApi::PathSeparator() {
  return ':';
}

System::Array<char32> Native::DirectoryApi::InvalidPathChars() {
  return {34, 60, 62, 124, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0};
}

char32 Native::DirectoryApi::VolumeSeparator() {
  return '/';
}

System::Collections::Generic::Enumerator<string> Native::DirectoryApi::EnumerateDirectories(const string& path, const string& pattern) {
  return System::Collections::Generic::Enumerator<string>(new Enumerator(path, pattern, Enumerator::FileType::Directory));
}

System::Collections::Generic::Enumerator<string> Native::DirectoryApi::EnumerateFiles(const string& path, const string& pattern) {
  return System::Collections::Generic::Enumerator<string>(new Enumerator(path, pattern, Enumerator::FileType::File));
}

int32 Native::DirectoryApi::GetFileAttributes(const string& path, System::IO::FileAttributes& attributes) {
  struct IntToFileAttributeConverter {
    System::IO::FileAttributes operator()(int32 attribute) {
      System::IO::FileAttributes fileAttributes = (System::IO::FileAttributes)0;
      if ((attribute & S_IRUSR) == S_IRUSR && (attribute & S_IWUSR) == 0)
        fileAttributes |= System::IO::FileAttributes::ReadOnly;
      if ((attribute & S_IFSOCK) == S_IFSOCK || (attribute & S_IFIFO) == S_IFIFO)
        fileAttributes |= System::IO::FileAttributes::System;
      if ((attribute & S_IFDIR) == S_IFDIR)
        fileAttributes |= System::IO::FileAttributes::Directory;
      if ((attribute & S_IFREG) == S_IFREG)
        fileAttributes |= System::IO::FileAttributes::Archive;
      if ((attribute & S_IFBLK) == S_IFBLK || (attribute & S_IFCHR) == S_IFCHR)
        fileAttributes |= System::IO::FileAttributes::Device;
      if ((attribute & S_IFREG) == S_IFREG)
        fileAttributes |= System::IO::FileAttributes::Normal;
      return fileAttributes;
    }
  };
  struct stat status {0};
  int32 retValue = stat(path.Data(), &status);
  attributes = IntToFileAttributeConverter()(status.st_mode);
  return retValue;
}

int32 Native::DirectoryApi::GetFileTime(const string& path, int64& creationTime, int64& lastAccessTime, int64& lastWriteTime) {
  struct stat status {0};
  if (stat(path.Data(), &status) != 0)
    return -1;

  creationTime = status.st_ctime;
  lastAccessTime = status.st_atime;
  lastWriteTime = status.st_mtime;
  return 0;
}

string Native::DirectoryApi::GetFullPath(const string& relativePath) {
  System::Array<string> directories = relativePath.Split(DirectorySeparatorChar(), System::StringSplitOptions::RemoveEmptyEntries);
  string fullPath;

  if (relativePath[0] != DirectorySeparatorChar())
    fullPath = GetCurrentDirectory();

  for (string& item : directories) {
    if (item == ".." && fullPath.LastIndexOf(DirectorySeparatorChar()) != -1)
      fullPath = fullPath.Remove(fullPath.LastIndexOf(DirectorySeparatorChar()));
    else if (item != ".")
      fullPath = string::Format("{0}{1}{2}", fullPath, DirectorySeparatorChar(), item);
  }

  if (relativePath[relativePath.Length - 1] == DirectorySeparatorChar())
    fullPath = string::Format("{0}{1}", fullPath, DirectorySeparatorChar());

  return fullPath;
}

string Native::DirectoryApi::GetCurrentDirectory() {
  char buffer[PATH_MAX];
  if (getcwd(buffer, PATH_MAX) == null)
    return string::Empty;
  return buffer;
}

int32 Native::DirectoryApi::SetCurrentDirectory(const string& directoryName) {
  return chdir(directoryName.Data());
}

int64 Native::DirectoryApi::GetFileSize(const string& path) {
  struct stat status;
  if (stat(path.Data(), &status) != 0)
    return 0;
  return status.st_size;
}

int32 Native::DirectoryApi::CreateDirectory(const string& directoryName) {
  return mkdir(directoryName.Data(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH);
}

int32 Native::DirectoryApi::RemoveDirectory(const string& directoryName) {
  return rmdir(directoryName.Data());
}

int32 Native::DirectoryApi::RemoveFile(const string& path) {
  return unlink(path.Data());
}

int32 Native::DirectoryApi::RenameFile(const string& oldPath, const string& newPath) {
  System::IO::FileAttributes fileAttributes = (System::IO::FileAttributes)0;
  if (GetFileAttributes(newPath, fileAttributes) == 0)
    return -1;
  return rename(oldPath.Data(), newPath.Data());
}

string Native::DirectoryApi::GetKnowFolderPath(System::Environment::SpecialFolder id) {
  #if defined(__APPLE__)
  static System::Collections::Generic::Dictionary<System::Environment::SpecialFolder, string> specialFolders = {{System::Environment::SpecialFolder::Desktop, System::Environment::ExpandEnvironmentVariables("%HOME%/Desktop")}, {System::Environment::SpecialFolder::Personal, System::Environment::ExpandEnvironmentVariables("%HOME%")}, {System::Environment::SpecialFolder::Favorites, System::Environment::ExpandEnvironmentVariables("%HOME%/Library/Favorites")}, {System::Environment::SpecialFolder::MyMusic, System::Environment::ExpandEnvironmentVariables("%HOME%/Music")}, {System::Environment::SpecialFolder::MyVideos, System::Environment::ExpandEnvironmentVariables("%HOME%/Videos")}, {System::Environment::SpecialFolder::DesktopDirectory, System::Environment::ExpandEnvironmentVariables("%HOME%/Desktop")}, {System::Environment::SpecialFolder::Fonts, System::Environment::ExpandEnvironmentVariables("%HOME%/Library/Fonts")}, {System::Environment::SpecialFolder::Templates, System::Environment::ExpandEnvironmentVariables("%HOME%/Templates")}, {System::Environment::SpecialFolder::ApplicationData, System::Environment::ExpandEnvironmentVariables("%HOME%/.config")}, {System::Environment::SpecialFolder::LocalApplicationData, System::Environment::ExpandEnvironmentVariables("%HOME%/.local/share")}, {System::Environment::SpecialFolder::InternetCache, System::Environment::ExpandEnvironmentVariables("%HOME%/Library/Caches")}, {System::Environment::SpecialFolder::CommonApplicationData, "/usr/share"}, {System::Environment::SpecialFolder::ProgramFiles, "/Applications"}, {System::Environment::SpecialFolder::MyPictures, System::Environment::ExpandEnvironmentVariables("%HOME%/Pictures")}, {System::Environment::SpecialFolder::UserProfile, System::Environment::ExpandEnvironmentVariables("%HOME%")}, {System::Environment::SpecialFolder::CommonTemplates, "/usr/share/templates"}};
  #else
  static System::Collections::Generic::Dictionary<System::Environment::SpecialFolder, string> specialFolders = {{System::Environment::SpecialFolder::Desktop, System::Environment::ExpandEnvironmentVariables("%HOME%/Desktop")}, {System::Environment::SpecialFolder::MyDocuments, System::Environment::ExpandEnvironmentVariables("%HOME%")}, {System::Environment::SpecialFolder::MyMusic, System::Environment::ExpandEnvironmentVariables("%HOME%/Music")}, {System::Environment::SpecialFolder::MyVideos, System::Environment::ExpandEnvironmentVariables("%HOME%/Videos")}, {System::Environment::SpecialFolder::DesktopDirectory, System::Environment::ExpandEnvironmentVariables("%HOME%/Desktop")}, {System::Environment::SpecialFolder::Fonts, System::Environment::ExpandEnvironmentVariables("%HOME%/.fonts")}, {System::Environment::SpecialFolder::Templates, System::Environment::ExpandEnvironmentVariables("%HOME%/Templates")}, {System::Environment::SpecialFolder::ApplicationData, System::Environment::ExpandEnvironmentVariables("%HOME%/.config")}, {System::Environment::SpecialFolder::LocalApplicationData, System::Environment::ExpandEnvironmentVariables("%HOME%/.local/share")}, {System::Environment::SpecialFolder::CommonApplicationData, "/usr/share"}, {System::Environment::SpecialFolder::MyPictures, System::Environment::ExpandEnvironmentVariables("%HOME%/Pictures")}, {System::Environment::SpecialFolder::UserProfile, System::Environment::ExpandEnvironmentVariables("%HOME%")}, {System::Environment::SpecialFolder::CommonTemplates, "/usr/share/templates"}};
  #endif
  if (!specialFolders.ContainsKey(id))
    return "";
  return specialFolders[id];
}

string Native::DirectoryApi::GetTempPath() {
  if (getenv("TMPDIR") != null)
    return getenv("TMPDIR");
  return "/tmp/";
}

#endif
