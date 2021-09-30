#include "../../../../include/Switch/System/Text/UnicodeEncoding.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Text;

UnicodeEncoding::Encoder& UnicodeEncoding::Encoder::operator=(const UnicodeEncoding::Encoder& b) {
  Encoding::Encoder::operator=(b);
  this->bigEndian = b.bigEndian;
  return *this;
}

int32 UnicodeEncoding::Encoder::GetNbBytes(char32 c) const {
  return Native::UnicodeEncodingsApi::UTF16::GetByteCount(c);
}

void UnicodeEncoding::Encoder::Encode(char32 c, byte bytes[]) const {
  Native::UnicodeEncodingsApi::UTF16::Encode(c, bytes, this->bigEndian);
}

String UnicodeEncoding::Encoder::ToString() const {
  if (this->bigEndian)
    return "UnicodeEncoder Big Endian";
  else
    return "UnicodeEncoder";
}

UnicodeEncoding::Decoder& UnicodeEncoding::Decoder::operator=(const UnicodeEncoding::Decoder& b) {
  Encoding::Decoder::operator=(b);
  bigEndian = b.bigEndian;
  return *this;
}

void UnicodeEncoding::Decoder::Add(byte b) {
  Encoding::Decoder::Add(b);
  if (count == 2) {
    uint32 cp;
    if (Native::UnicodeEncodingsApi::UTF16::Decode(bytes, count, bigEndian, cp) == 2) {
      codePoint = char32(cp);
      finished = true;
      return;
    }
  }

  if (count == 4) {
    uint32 cp;
    if (Native::UnicodeEncodingsApi::UTF16::Decode(bytes, count, bigEndian, cp) == 4) {
      codePoint = char32(cp);
      finished = true;
      return;
    }
    Reset();
  }
}

String UnicodeEncoding::Decoder::ToString() const {
  if (bigEndian)
    return "UnicodeDecoder Big Endian";
  else
    return "UnicodeDecoder";
}

UnicodeEncoding::UnicodeEncoding()
  : Encoding(1200) {
  this->shouldEmitPreamble = true;
  this->bigEndian = false;
}

UnicodeEncoding::UnicodeEncoding(bool bigEndian)
  : Encoding(bigEndian ? 1201 : 1200) {
  this->shouldEmitPreamble = true;
  this->bigEndian = bigEndian;
}

UnicodeEncoding::UnicodeEncoding(bool bigEndian, bool shouldEmitPreamble)
  : Encoding(bigEndian ? 1201 : 1200) {
  this->shouldEmitPreamble = shouldEmitPreamble;
  this->bigEndian = bigEndian;
}

UnicodeEncoding::UnicodeEncoding(const UnicodeEncoding& encoding)
  : Encoding(encoding) {
  this->shouldEmitPreamble = encoding.shouldEmitPreamble;
  this->bigEndian = encoding.bigEndian;
}

UnicodeEncoding& UnicodeEncoding::operator=(const UnicodeEncoding& encoding)  {
  Encoding::operator=(encoding);
  this->shouldEmitPreamble = encoding.shouldEmitPreamble;
  this->bigEndian = encoding.bigEndian;
  return *this;
}

refptr<Encoding::Decoder> UnicodeEncoding::CreateDecoder() const {
  return ref_new<Decoder>(this->bigEndian);
}

refptr<Encoding::Encoder> UnicodeEncoding::CreateEncoder() const {
  return ref_new<Encoder>(this->bigEndian);
}

int32 UnicodeEncoding::GetByteCount(char32 c) const {
  return Native::UnicodeEncodingsApi::UTF16::GetByteCount(c);
}

int32 UnicodeEncoding::GetCharCount(const byte bytes[], int32 bytesSize, int32 index, int32 count) const {
  if (bytes == null && bytesSize != 0) throw ArgumentNullException(caller_);
  ValidateGCC(bytesSize, index, count);
  if (bytesSize == 0) return 0;
  return Native::UnicodeEncodingsApi::UTF16::GetLength(&bytes[index], count, this->bigEndian);
}

int32 UnicodeEncoding::GetMaxByteCount(int32 charCount) const {
  if (charCount < 0 || charCount > Int32::MaxValue / 4) throw ArgumentOutOfRangeException(caller_);
  return 4 * charCount; // 4 is maximum bytes per char
}

int32 UnicodeEncoding::GetMaxCharCount(int32 byteCount) const {
  if (byteCount < 0) throw ArgumentOutOfRangeException(caller_);
  return byteCount / 2; // 2 is minimum bytes per char
}

Array<byte> UnicodeEncoding::GetPreamble() const {
  if (this->shouldEmitPreamble)
    if (this->bigEndian)
      return {0xFE, 0xFF};
    else
      return {0xFF, 0xFE};
  else
    return {};
}

bool UnicodeEncoding::Equals(const object& obj) const {
  const UnicodeEncoding* ue = dynamic_cast<const UnicodeEncoding*>(&obj);
  if (ue == null)
    return false;

  return this->shouldEmitPreamble == ue->shouldEmitPreamble && this->bigEndian == ue->bigEndian;
}

int32 UnicodeEncoding::GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 index) const {
  if (bytes == null && bytesLength > 0) throw ArgumentNullException(caller_);
  if (index < 0) throw ArgumentOutOfRangeException(caller_);

  int32 count = GetByteCount(c);
  if (index + count > bytesLength) throw ArgumentOutOfRangeException(caller_);

  Encoder encoder(this->bigEndian);
  encoder.Encode(c, &bytes[index]);
  return count;
}
