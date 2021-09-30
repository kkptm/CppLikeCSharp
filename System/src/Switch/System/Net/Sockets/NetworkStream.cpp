#include "../../../../../include/Switch/System/Net/Sockets/NetworkStream.hpp"

#include <Switch/System/ArgumentNullException.hpp>
#include <Switch/System/ObjectDisposedException.hpp>
#include <Switch/System/IO/IOException.hpp>
#include "../../../../../include/Switch/System/Net/Sockets/SocketException.hpp"

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;

NetworkStream::NetworkStream(const System::Net::Sockets::Socket& socket, FileAccess access) {
  if (!socket.Connected || socket.SocketType != SocketType::Stream || !socket.Blocking)
    throw IOException(caller_);

  this->data->streamSocket = socket;
  switch (access) {
  case FileAccess::Read: this->data->readable = true; break;
  case FileAccess::Write: this->data->writeable = true; break;
  case FileAccess::ReadWrite: this->data->readable = this->data->writeable = true; break;
  }
}

NetworkStream::~NetworkStream() {
  if (this->data.IsUnique())
    Close();
}

void NetworkStream::Close() {
  this->data->readable = false;
  this->data->writeable = false;
  Stream::Close();
  this->data->streamSocket = Socket();
}

int32 NetworkStream::Read(Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0 || offset >= buffer.Length)
    throw ArgumentOutOfRangeException(caller_);
  if (!this->data->readable)
    throw NotSupportedException(caller_);
  return this->data->streamSocket.Receive(buffer, offset, count, SocketFlags::None);
}

void NetworkStream::Write(const Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0 || offset >= buffer.Length)
    throw ArgumentOutOfRangeException(caller_);
  if (!this->data->writeable)
    throw NotSupportedException(caller_);
  this->data->streamSocket.Send(buffer, offset, count, SocketFlags::None);
}
