#include "../../../../include/Switch/System/Text/UTF8Encoding.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Text;

UTF8Encoding::Encoder& UTF8Encoding::Encoder::operator =(const UTF8Encoding::Encoder& b) {
  Encoding::Encoder::operator =(b);
  return *this;
}

int32 UTF8Encoding::Encoder::GetNbBytes(char32 c) const {
  return Native::UnicodeEncodingsApi::UTF8::GetByteCount(c);
}

void UTF8Encoding::Encoder::Encode(char32 c, byte bytes[]) const {
  Native::UnicodeEncodingsApi::UTF8::Encode(c, bytes);
}

String UTF8Encoding::Encoder::ToString() const {
  return "UTF8Encoder";
}

UTF8Encoding::Decoder& UTF8Encoding::Decoder::operator =(const UTF8Encoding::Decoder& b) {
  Encoding::Decoder::operator =(b);
  format = b.format;
  return *this;
}

void UTF8Encoding::Decoder::Add(byte b) {
  // first, if we are in a multibyte situation, check that we receive a valid continuation byte
  if (finished || (count > 0 && Native::UnicodeEncodingsApi::UTF8::GetFormat(b) != 0))
    Reset();
  Encoding::Decoder::Add(b);
  if (count == 1) {
    format = Native::UnicodeEncodingsApi::UTF8::GetFormat(b);
    if (format == 0xFF || format == 0) {
      Reset();
      return;
    }
  }
  if (format == count) {
    codePoint = Native::UnicodeEncodingsApi::UTF8::GetCode(bytes, static_cast<byte>(count));
    finished = true;
  } else {
    if (count == 4) Reset();
  }
}

void UTF8Encoding::Decoder::Reset() {
  Encoding::Decoder::Reset();
  format = 0;
}

String UTF8Encoding::Decoder::ToString() const {
  return "UTF8Decoder";
}

UTF8Encoding::UTF8Encoding()
  : Encoding(65001) {
  this->shouldEmitPreamble = false;
}

UTF8Encoding::UTF8Encoding(bool shouldEmitPreamble)
  : Encoding(65001) {
  this->shouldEmitPreamble = shouldEmitPreamble;
}

UTF8Encoding::UTF8Encoding(const UTF8Encoding& encoding)
  : Encoding(encoding) {
  this->shouldEmitPreamble = encoding.shouldEmitPreamble;
}

UTF8Encoding& UTF8Encoding::operator =(const UTF8Encoding& encoding) {
  Encoding::operator =(encoding);
  this->shouldEmitPreamble = encoding.shouldEmitPreamble;
  return *this;
}

refptr<Encoding::Decoder> UTF8Encoding::CreateDecoder() const {
  return ref_new<Decoder>();
}

refptr<Encoding::Encoder> UTF8Encoding::CreateEncoder() const {
  return ref_new<Encoder>();
}

int32 UTF8Encoding::GetByteCount(char32 c) const {
  return Native::UnicodeEncodingsApi::UTF8::GetByteCount(c);
}

int32 UTF8Encoding::GetCharCount(const byte bytes[], int32 bytesSize, int32 index, int32 count) const {
  if (bytes == null && bytesSize != 0) throw ArgumentNullException(caller_);
  ValidateGCC(bytesSize, index, count);

  std::string s;
  for (int32 i = 0 ; i < count ; i += 1)
    s.push_back(bytes[index + i]);

  return Native::UnicodeEncodingsApi::UTF8::GetLength(s);
}

int32 UTF8Encoding::GetMaxByteCount(int32 charCount) const {
  if (charCount < 0 || charCount > Int32::MaxValue / 4) throw ArgumentOutOfRangeException(caller_);
  return 4 * charCount;
}

int32 UTF8Encoding::GetMaxCharCount(int32 byteCount) const {
  if (byteCount < 0) throw ArgumentOutOfRangeException(caller_);
  return byteCount;
}

Array<byte> UTF8Encoding::GetPreamble() const {
  if (this->shouldEmitPreamble)
    return {239, 187, 191};
  else
    return {};
}

bool UTF8Encoding::Equals(const object& obj) const {
  const UTF8Encoding* utf8 = dynamic_cast<const UTF8Encoding*>(&obj);
  if (utf8 == null)
    return false;

  return this->shouldEmitPreamble == utf8->shouldEmitPreamble;
}

int32 UTF8Encoding::GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 index) const {
  if (bytes == null && bytesLength > 0) throw ArgumentNullException(caller_);
  if (index < 0) throw ArgumentOutOfRangeException(caller_);

  int32 count = GetByteCount(c);
  if (index + count > bytesLength) throw ArgumentOutOfRangeException(caller_);

  Encoder encoder;
  encoder.Encode(c, &bytes[index]);
  return count;
}
