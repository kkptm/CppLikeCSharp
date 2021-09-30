#include "../../../../include/Switch/System/Text/Encoding.hpp"

using namespace System;
using namespace System::Text;

Encoding::Decoder::Decoder() {
  Reset();
}

Encoding::Decoder::Decoder(const Encoding::Decoder& cpb) {
  *this = cpb;
}

Encoding::Decoder::~Decoder() {

}

Encoding::Decoder& Encoding::Decoder::operator =(const Decoder& b) {
  finished = b.finished;
  bytes[0] = b.bytes[0];
  bytes[1] = b.bytes[1];
  bytes[2] = b.bytes[2];
  bytes[3] = b.bytes[3];
  count = b.count;
  codePoint = b.codePoint;
  return *this;
}

void Encoding::Decoder::Reset() {
  finished = false;
  count = 0;
}

void Encoding::Decoder::Add(byte b) {
  if (finished)
    Reset();
  bytes[count++] = b;
}
