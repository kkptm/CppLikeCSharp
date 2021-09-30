#include "../../../../include/Switch/System/Text/ASCIIEncoding.hpp"

using namespace System;
using namespace System::Text;

ASCIIEncoding::Decoder::Decoder() : Encoding::Decoder() {
}

ASCIIEncoding::Decoder::Decoder(const ASCIIEncoding::Decoder& b) : Encoding::Decoder(b) {
}

ASCIIEncoding::Decoder& ASCIIEncoding::Decoder::operator=(const ASCIIEncoding::Decoder& b) {
  Encoding::Decoder::operator=(b);
  return *this;
}

void ASCIIEncoding::Decoder::Add(byte b) {
  Encoding::Decoder::Add(b);
  finished = true;
  codePoint = b;
}

void ASCIIEncoding::Decoder::Reset() {
  Encoding::Decoder::Reset();
}

String ASCIIEncoding::Decoder::ToString() const {
  return "ASCIIDecoder";
}

ASCIIEncoding::Encoder& ASCIIEncoding::Encoder::operator=(const ASCIIEncoding::Encoder& b) {
  Encoding::Encoder::operator=(b);
  return *this;
}

int32 ASCIIEncoding::Encoder::GetNbBytes(char32) const {
  return 1;
}

void ASCIIEncoding::Encoder::Encode(char32 c, byte* bytes) const {
  bytes[0] = (c > 127) ? Encoding::Unknown() : static_cast<byte>(c);
}

String ASCIIEncoding::Encoder::ToString() const {
  return "ASCIIEncoder";
}

ASCIIEncoding::ASCIIEncoding() : Encoding(20127) {
}

ASCIIEncoding::ASCIIEncoding(const ASCIIEncoding& encoding) : Encoding(encoding) {
}

ASCIIEncoding& ASCIIEncoding::operator=(const ASCIIEncoding& encoding) {
  Encoding::operator=(encoding);
  return *this;
}

refptr<Encoding::Decoder> ASCIIEncoding::CreateDecoder() const {
  return ref_new<Decoder>();
}

refptr<Encoding::Encoder> ASCIIEncoding::CreateEncoder() const {
  return ref_new<Encoder>();
}

int32 ASCIIEncoding::GetByteCount(char32) const {
  return 1;
}

int32 ASCIIEncoding::GetCharCount(const byte bytes[], int32 bytesSize, int32 index, int32 count) const {
  if (bytes == null && bytesSize != 0) throw ArgumentNullException(caller_);
  ValidateGCC(bytesSize, index, count);
  return count;
}

int32 ASCIIEncoding::GetMaxByteCount(int32 charCount) const {
  if (charCount < 0) throw ArgumentOutOfRangeException(caller_);
  return charCount;
}

int32 ASCIIEncoding::GetMaxCharCount(int32 byteCount) const {
  if (byteCount < 0) throw ArgumentOutOfRangeException(caller_);
  return byteCount;
}

bool ASCIIEncoding::Equals(const object& obj) const {
  return is<ASCIIEncoding>(obj);
}

int32 ASCIIEncoding::GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 index) const {
  if (bytes == null && bytesLength > 0) throw ArgumentNullException(caller_);
  if (index < 0) throw ArgumentOutOfRangeException(caller_);

  int32 count = GetByteCount(c);
  if (index + count > bytesLength) throw ArgumentOutOfRangeException(caller_);

  Encoder encoder;
  encoder.Encode(c, &bytes[index]);
  return count;
}
