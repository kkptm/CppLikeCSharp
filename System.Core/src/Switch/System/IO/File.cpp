#include "../../../../include/Switch/System/IO/File.hpp"
#include "../../../../include/Switch/System/IO/FileInfo.hpp"
#include "../../../../include/Switch/Using.hpp"

using namespace System;
using namespace System::IO;

void File::AppendAllLines(const string& path, const Collections::Generic::IEnumerable<string>& contents) {
  StreamWriter sw(path, true);
  for (const auto& line : contents)
    sw.WriteLine(line);
}

void File::AppendAllLines(const string& path, const Array<string>& contents) {
  StreamWriter sw(path, true);
  for (const auto& line : contents)
    sw.WriteLine(line);
}

void File::AppendAllLines(const string& path, const Collections::Generic::IEnumerable<string>& contents, Text::Encoding& encoding) {
  StreamWriter sw(path, true, encoding);
  for (const auto& line : contents)
    sw.WriteLine(line);
}

void File::AppendAllLines(const string& path, const Array<string>& contents, Text::Encoding& encoding) {
  StreamWriter sw(path, true, encoding);
  for (const auto& line : contents)
    sw.WriteLine(line);
}

void File::AppendAllText(const string& path, const string& contents) {
  StreamWriter sw(path, true);
  sw.Write(contents);
}

void File::AppendAllText(const string& path, const string& contents, Text::Encoding& encoding) {
  StreamWriter sw(path, true, encoding);
  sw.Write(contents);
}

StreamWriter File::AppendText(const string& path) {
  return StreamWriter(path, true);
}

void File::Copy(const string& src, const string& dest) {
  FileInfo(src).CopyTo(dest);
}

void File::Copy(const string& src, const string& dest, bool overwrite) {
  FileInfo(src).CopyTo(dest, overwrite);
}

void File::Delete(const string& path) {
  FileInfo(path).Delete();
}

bool File::Exists(const string& path) {
  try {
    return FileInfo(path).Exists();
  } catch (const Exception&) {
    return false;
  }
}

FileStream File::Open(const String& path, FileMode mode, FileAccess access) {
  return FileStream(path, mode, access, FileShare(FileShare::None));
}

FileStream File::OpenRead(const string& path) {
  return FileInfo(path).OpenRead();
}

FileStream File::OpenWrite(const string& path) {
  return FileInfo(path).OpenWrite();
}

StreamWriter File::CreateText(const string& path) {
  return StreamWriter(path, false);
}

StreamReader File::OpenText(const string& path) {
  return StreamReader(path);
}

FileAttributes File::GetAttributes(const string& src) {
  return FileInfo(src).Attributes();
}

void File::Move(const string& src, const string& dest) {
  FileInfo(src).MoveTo(dest);
}

Array<string> File::ReadAllLines(const string& path) {
  System::Collections::Generic::List<string> lines;
  StreamReader reader(path);
  while (!reader.EndOfStream())
    lines.Add(reader.ReadLine());
  return lines.ToArray();
}

Array<string> File::ReadAllLines(const string& path, Text::Encoding& encoding) {
  System::Collections::Generic::List<string> lines;
  StreamReader reader(path, encoding);
  while (!reader.EndOfStream())
    lines.Add(reader.ReadLine());
  return lines.ToArray();
}

string File::ReadAllText(const string& path) {
  return StreamReader(path).ReadToEnd();
}

string File::ReadAllText(const string& path, Text::Encoding& encoding) {
  return StreamReader(path, encoding).ReadToEnd();
}

void File::WriteAllLines(const string& path, const Array<string>& contents) {
  StreamWriter sw(path);
  for (string line : contents)
    sw.WriteLine(line);
}

void File::WriteAllLines(const string& path, const Collections::Generic::IEnumerable<string>& contents) {
  StreamWriter sw(path);
  for (string line : contents)
    sw.WriteLine(line);
}

void File::WriteAllLines(const string& path, const Array<string>& contents, Text::Encoding& encoding) {
  StreamWriter sw(path, false, encoding);
  for (string line : contents)
    sw.WriteLine(line);
}

void File::WriteAllLines(const string& path, const Collections::Generic::IEnumerable<string>& contents, Text::Encoding& encoding) {
  StreamWriter sw(path, false, encoding);
  for (string line : contents)
    sw.WriteLine(line);
}

void File::WriteAllText(const string& path, const string& contents) {
  StreamWriter(path).Write(contents);
}

void File::WriteAllText(const string& path, const string& contents, Text::Encoding& encoding) {
  StreamWriter(path, false, encoding).Write(contents);
}

