#include "../../../../include/Switch/System/Text/UTF32Encoding.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Text;

UTF32Encoding::Encoder& UTF32Encoding::Encoder::operator=(const UTF32Encoding::Encoder& b) {
  Encoding::Encoder::operator=(b);
  this->bigEndian = b.bigEndian;
  return *this;
}

void UTF32Encoding::Encoder::Encode(char32 c, byte bytes[]) const {
  Native::UnicodeEncodingsApi::UTF32::Encode(c, bytes[0], bytes[1], bytes[2], bytes[3], this->bigEndian);
}

String UTF32Encoding::Encoder::ToString() const {
  if (this->bigEndian)
    return "UTF32Encoder Big Endian";
  else
    return "UTF32Encoder";
}

UTF32Encoding::Decoder& UTF32Encoding::Decoder::operator=(const UTF32Encoding::Decoder& b) {
  Encoding::Decoder::operator=(b);
  bigEndian = b.bigEndian;
  return *this;
}

void UTF32Encoding::Decoder::Add(byte b) {
  Encoding::Decoder::Add(b);
  if (count == 4) {
    finished = true;
    codePoint = Native::UnicodeEncodingsApi::UTF32::Decode(bytes[0], bytes[1], bytes[2], bytes[3], bigEndian);
  }
}

String UTF32Encoding::Decoder::ToString() const {
  if (bigEndian)
    return "UTF32Decoder Big Endian";
  else
    return "UTF32Decoder";
}

UTF32Encoding::UTF32Encoding()
  : Encoding(12000) {
  this->shouldEmitPreamble = true;
  this->bigEndian = false;
}

UTF32Encoding::UTF32Encoding(bool bigEndian)
  : Encoding(bigEndian ? 12001 : 12000) {
  this->shouldEmitPreamble = true;
  this->bigEndian = bigEndian;
}

UTF32Encoding::UTF32Encoding(bool bigEndian, bool shouldEmitPreamble)
  : Encoding(bigEndian ? 12001 : 12000) {
  this->shouldEmitPreamble = shouldEmitPreamble;
  this->bigEndian = bigEndian;
}

UTF32Encoding::UTF32Encoding(const UTF32Encoding& encoding)
  : Encoding(encoding) {
  this->shouldEmitPreamble = encoding.shouldEmitPreamble;
  this->bigEndian = encoding.bigEndian;
}

UTF32Encoding& UTF32Encoding::operator=(const UTF32Encoding& encoding) {
  Encoding::operator=(encoding);
  this->shouldEmitPreamble = encoding.shouldEmitPreamble;
  this->bigEndian = encoding.bigEndian;
  return *this;
}

refptr<Encoding::Decoder> UTF32Encoding::CreateDecoder() const {
  return ref_new<Decoder>(this->bigEndian);
}

refptr<Encoding::Encoder> UTF32Encoding::CreateEncoder() const {
  return ref_new<Encoder>(this->bigEndian);
}

int32 UTF32Encoding::GetByteCount(char32) const {
  return 4;
}

int32 UTF32Encoding::GetCharCount(const byte bytes[], int32 bytesSize, int32 index, int32 count) const {
  if (bytes == null && bytesSize != 0) throw ArgumentNullException(caller_);
  ValidateGCC(bytesSize, index, count);
  return count / 4;
}

int32 UTF32Encoding::GetMaxByteCount(int32 charCount) const {
  if (charCount < 0 || charCount > Int32::MaxValue / 4) throw ArgumentOutOfRangeException(caller_);
  return 4 * charCount;
}

int32 UTF32Encoding::GetMaxCharCount(int32 byteCount) const {
  if (byteCount < 0) throw ArgumentOutOfRangeException(caller_);
  return byteCount / 4;
}

Array<byte> UTF32Encoding::GetPreamble() const {
  if (this->shouldEmitPreamble)
    if (this->bigEndian)
      return {0, 0, 0xFE, 0xFF};
    else
      return {0xFF, 0xFE, 0, 0};
  else
    return {};
}

bool UTF32Encoding::Equals(const object& obj) const {
  const UTF32Encoding* ue = dynamic_cast<const UTF32Encoding*>(&obj);
  if (ue == null)
    return false;

  return this->shouldEmitPreamble == ue->shouldEmitPreamble && this->bigEndian == ue->bigEndian;
}

int32 UTF32Encoding::GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 index) const {
  if (bytes == null && bytesLength > 0) throw ArgumentNullException(caller_);
  if (index < 0) throw ArgumentOutOfRangeException(caller_);

  int32 count = GetByteCount(c);
  if (index + count > bytesLength) throw ArgumentOutOfRangeException(caller_);

  Encoder encoder(this->bigEndian);
  encoder.Encode(c, &bytes[index]);
  return count;
}
