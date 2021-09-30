#include "../../../../include/Switch/System/IO/Stream.hpp"
#include "../../../../include/Switch/System/Array.hpp"
#include "../../../../include/Switch/System/ObjectDisposedException.hpp"

using namespace System;
using namespace System::IO;
using namespace System::Threading;

int32 Stream::ReadByte() {
  if (this->closed) throw ObjectDisposedException(caller_);
  static Array<byte> b(1);
  if (Read(b, 0, 1) == 1)
    return int32(b[0]);
  return -1;
}

Stream& Stream::Synchronised(Stream& stream) {
  stream.lock = &stream;
  return stream;
}

void Stream::WriteByte(byte value) {
  if (this->closed) throw ObjectDisposedException(caller_);
  Array<byte> b = {value};
  Write(b, 0, 1);
}

NullStream& Stream::Null() {
  static NullStream nullStream;
  return nullStream;
}
