#include <cstdio>
#include <cstdlib>

#include "../../../../include/Switch/System/Diagnostics/Process.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;

namespace {
  class ProcessOutputStream : public Stream {
  public:
    ProcessOutputStream() {}
    ProcessOutputStream(FILE* stream) : stream(stream), isClosed(stream == null) {}

    /// @cond
    ProcessOutputStream(const ProcessOutputStream& pos) : stream(pos.stream), isClosed(pos.isClosed) {}
    ProcessOutputStream& operator=(const ProcessOutputStream& pos) {
      this->stream = pos.stream;
      this->isClosed = pos.isClosed;
      return *this;
    }
    /// @endcond

    void Close() override  {this->isClosed = true;}

    int32 Read(Array<byte>& buffer, int32 offset, int32 count) override {
      if (count < 0 || offset < 0)
        throw ArgumentOutOfRangeException(caller_);
      if (offset + count > buffer.Length)
        throw ArgumentException(caller_);
      if (IsClosed())
        throw ObjectDisposedException(caller_);
      if (feof(this->stream))
        return -1;
      return (int32)fread((char*)&buffer.Data[offset], sizeof(char), count, this->stream);
    }

    void Write(const Array<byte>&, int32, int32) override { }
    int64 Seek(int64, System::IO::SeekOrigin) override { return 0; };

  private:
    bool GetCanRead() const override {return true;}
    bool GetCanSeek() const override {return false;}
    bool GetCanWrite() const override {return false;}
    int64 GetLength() const override {return 0;}
    int64 GetPosition() const override {return 0;}
    bool GetIsClosed() const override {return this->isClosed;}

    FILE* stream;
    bool isClosed = false;
  };
}

Process::~Process() {
  this->Close();
}

void Process::Close() {
  if (this->data.IsUnique()) {
    Native::ProcessApi::Close(this->data->handle);
    this->data->handle = 0;
  }
}

void Process::Kill() {
  Native::ProcessApi::Kill(this->data->handle);
}

Process Process::GetCurrentProcess() {
  return Native::ProcessApi::GetCurrent();
}

Array<Process> Process::GetProcesses() {
  Array<intptr> ids = Native::ProcessApi::GetProcesses();
  System::Collections::Generic::List<Process> processes;
  for (auto id : ids)
    if (id != 0)
      processes.Add(Process(id));
  return processes.ToArray();
}

string Process::GetName() {
  return Native::ProcessApi::GetName(this->data->handle);
}

string Process::GetPath() {
  return Native::ProcessApi::GetPath(this->data->handle);
}

StreamReader Process::GetStreamReader() {
  return StreamReader((const ProcessOutputStream&) * this->data->outputStream);
}

Process Process::Start(const string& fileName) {
  return Start(ProcessStartInfo(fileName));
}

Process Process::Start(const string& fileName, const string& argument) {
  return Start(ProcessStartInfo(fileName, argument));
}

Process Process::Start(const ProcessStartInfo& processStartInfo) {
  return Process((intptr)Native::ProcessApi::Start(processStartInfo));
}

void Process::WaitForExit() {
  if (this->data->handle != 0)
    Native::ProcessApi::WaitForExit(this->data->handle, this->data->exitCode);
}

