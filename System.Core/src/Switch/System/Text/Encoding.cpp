#include "../../../../include/Switch/System/Text/Encoding.hpp"
#include "../../../../include/Switch/System/Text/ANSIEncoding.hpp"
#include "../../../../include/Switch/System/Text/ASCIIEncoding.hpp"
#include "../../../../include/Switch/System/Text/UnicodeEncoding.hpp"
#include "../../../../include/Switch/System/Text/UTF32Encoding.hpp"
#include "../../../../include/Switch/System/Text/UTF8Encoding.hpp"
#include "../ArrayAlgorithms.hpp"

using namespace System;
using namespace System::Text;

refptr<System::Collections::Generic::Dictionary<int32, string>> Encoding::names;
refptr<System::Collections::Generic::Dictionary<string, int32>> Encoding::codePagesFromName;
refptr<System::Collections::Generic::Dictionary<int32, string>> Encoding::displayNames;

const refptr<Encoding> Encoding::ASCII = ref_new<ASCIIEncoding>();

const refptr<Encoding> Encoding::UTF8 = ref_new<UTF8Encoding>(true);

const refptr<Encoding> Encoding::Unicode = ref_new<UnicodeEncoding>(false, true);

const refptr<Encoding> Encoding::BigEndianUnicode = ref_new<UnicodeEncoding>(true, true);

const refptr<Encoding> Encoding::UTF16LE = ref_new<UnicodeEncoding>(false, true);

const refptr<Encoding> Encoding::UTF16BE = ref_new<UnicodeEncoding>(true, true);

const refptr<Encoding> Encoding::UTF32 = ref_new<UTF32Encoding>(false, true);

const refptr<Encoding> Encoding::Default = ref_new<UTF8Encoding>(true);

Encoding::Encoding() {
  this->codePage = 0;
}

Encoding::Encoding(int32 codePage) {
  if (codePage < 0) throw ArgumentOutOfRangeException(caller_);
  this->codePage = codePage;
}

Encoding::Encoding(const Encoding& encoding) {
  this->codePage = encoding.codePage;
}

Encoding& Encoding::operator =(const Encoding& encoding) {
  this->codePage = encoding.codePage;
  return *this;
}

int32 Encoding::GetCodePage() const {
  return this->codePage;
}

string Encoding::GetEncodingName() const {
  switch (this->codePage) {
  case 20127 : return "us-ascii";
  case 28591 : return "iso-8859-1";
  case 28592 : return "iso-8859-2";
  case 65001 : return "utf-8";
  case 1200 : return "utf-16";
  case 1201 : return "unicodeFFFE";
  case 437 : return "IBM437";
  case 12000 : return "utf-32";
  case 12001 : return "utf-32BE";
  }
  return "";
}

refptr<Encoding> Encoding::CreateEncoding(int32 codePage) {
  switch (codePage) {
  case 437   : { return ref_new<CodePage437Encoding>(); }
  case 1200  : { return ref_new<UnicodeEncoding>(false, true); }
  case 1201  : { return ref_new<UnicodeEncoding>(true, true); }
  case 12000 : { return ref_new<UTF32Encoding>(false, true); }
  case 12001 : { return ref_new<UTF32Encoding>(true, true); }
  case 20127 : { return ref_new<ASCIIEncoding>(); }
  case 28591 : { return ref_new<CodePage28591Encoding>(); }
  case 28592 : { return ref_new<CodePage28592Encoding>(); }
  case 65001 : { return ref_new<UTF8Encoding>(); }
  }
  throw NotSupportedException(caller_);
}

refptr<Encoding> Encoding::CreateEncoding(const string& codePageName) {
  if (codePageName == "us-ascii") return CreateEncoding(20127);
  if (codePageName == "iso-8859-1") return CreateEncoding(28591);
  if (codePageName == "iso-8859-2") return CreateEncoding(28592);
  if (codePageName == "utf-8") return CreateEncoding(65001);
  if (codePageName == "utf-16") return CreateEncoding(1200);
  if (codePageName == "unicodeFFFE") return CreateEncoding(1201);
  if (codePageName == "IBM437") return CreateEncoding(437);
  if (codePageName == "utf-32") return CreateEncoding(12000);
  if (codePageName == "utf-32BE") return CreateEncoding(12001);
  throw NotSupportedException(caller_);
}

Array<byte> Encoding::Convert(const Encoding& srcEncoding, const Encoding& dstEncoding, const byte bytes[], int32 bytesSize) {
  ArrayAlgorithms::ValidateArray(bytes, bytesSize);
  if (bytesSize == 0) return Array<byte>();
  return Convert(srcEncoding, dstEncoding, bytes, bytesSize, 0, bytesSize);
}

Array<byte> Encoding::Convert(const Encoding& srcEncoding, const Encoding& dstEncoding, const byte bytes[], int32 bytesSize, int32 index, int32 count) {
  ArrayAlgorithms::ValidateArray(bytes, bytesSize);
  ArrayAlgorithms::ValidateRange(bytesSize, index, count);
  if (count == 0) return Array<byte>();
  int32 nbChars = srcEncoding.GetCharCount(bytes, bytesSize, index, count);
  Array<char32> chars(nbChars);
  srcEncoding.GetChars(bytes, bytesSize, index, count, (char32*)chars.Data(), nbChars, 0);
  return dstEncoding.GetBytes(chars.Data, chars.Length);
}

bool Encoding::Equals(const object& obj) const {
  const Encoding* enc = dynamic_cast<const Encoding*>(&obj);
  if (enc == null) return false;
  return this->codePage == enc->codePage;
}

int32 Encoding::GetByteCount(const char32 chars[], int32 charsSize) const {
  ArrayAlgorithms::ValidateArray(chars, charsSize);
  if (charsSize == 0) return 0;
  int32 count = 0;
  for (int32 index = 0; index < charsSize; index++)
    count += GetByteCount(chars[index]);
  return count;
}

int32 Encoding::GetByteCount(const char32 chars[], int32 charsSize, int32 index, int32 count) const {
  ArrayAlgorithms::ValidateArray(chars, charsSize);
  ArrayAlgorithms::ValidateRange(charsSize, index, count);
  int32 byteCount = 0;
  for (int i = index; i < index + count; i += 1)
    byteCount += GetByteCount(chars[i]);
  return byteCount;
}

int32 Encoding::GetByteCount(const string& s) const {
  int32 count = 0;
  System::Collections::Generic::Enumerator<char32> enumerator = s.GetEnumerator();
  while (enumerator.MoveNext())
    count += GetByteCount(enumerator.Current);
  return count;
}

// string
int32 Encoding::GetBytes(const String& s, byte bytes[], int32 bytesSize) const {
  ArrayAlgorithms::ValidateArray(bytes, bytesSize);

  int32 index = 0;
  System::Collections::Generic::Enumerator<char32> enumerator = s.GetEnumerator();
  while (enumerator.MoveNext())
    index += GetBytes(enumerator.Current, bytes, bytesSize, index);
  return index;
}

Array<byte> Encoding::GetBytes(const string& s) const {
  if (string::IsNullOrEmpty(s)) return Array<byte>();
  int32 nbBytes = GetByteCount(s);
  Array<byte> bytes(nbBytes);
  GetBytes(s, (byte*)bytes.Data(), nbBytes);
  return bytes;
}

// chars
int32 Encoding::GetBytes(const char32 chars[], int32 charsSize, byte bytes[], int32 bytesSize) const {
  return GetBytes(chars, charsSize, 0, charsSize, bytes, bytesSize, 0);
}

Array<byte> Encoding::GetBytes(const char32 chars[], int32 charsSize) const {
  return GetBytes(chars, charsSize, 0, charsSize);
}

// span of chars
int32 Encoding::GetBytes(const char32 chars[], int32 charsSize, int32 index, int32 count, byte bytes[], int32 bytesSize) const {
  return GetBytes(chars, charsSize, index, count, bytes, bytesSize, 0);
}

Array<byte> Encoding::GetBytes(const char32 chars[], int32 charsSize, int32 index, int32 count) const {
  ArrayAlgorithms::ValidateArray(chars, charsSize);
  ArrayAlgorithms::ValidateRange(charsSize, index, count);
  if (count == 0) return Array<byte>();
  int32 neededBytes = GetByteCount(chars, charsSize, index, count);
  Array<byte> bytes(neededBytes);
  GetBytes(chars, charsSize, index, count, (byte*)bytes.Data(), neededBytes, 0);
  return bytes;
}

// span of chars into span of bytes
int32 Encoding::GetBytes(const char32 chars[], int32 charsSize, int32 charIndex, int32 charCount, byte bytes[], int32 bytesSize, int32 byteIndex) const {
  ArrayAlgorithms::ValidateArray(chars, charsSize);
  ArrayAlgorithms::ValidateArray(bytes, bytesSize);
  ArrayAlgorithms::ValidateRange(charsSize, charIndex, charCount);
  ArrayAlgorithms::ValidateIndex(byteIndex, bytesSize);

  if (byteIndex < 0) throw ArgumentOutOfRangeException(caller_);
  int32 count = 0;
  for (int32 i = charIndex; i < charIndex + charCount; i += 1)
    count += GetBytes(chars[i], bytes, bytesSize, byteIndex + count);
  return count;
}

// string span
int32 Encoding::GetBytes(const String& source, int32 charIndex, int32 charCount, byte bytes[], int32 bytesLength, int32 byteIndex) const {
  ArrayAlgorithms::ValidateArray(bytes, bytesLength);
  ArrayAlgorithms::ValidateRange(source.Length(), charIndex, charCount);
  ArrayAlgorithms::ValidateIndex(byteIndex, bytesLength);
  int32 index = 0;
  int32 iteration = 0;
  for (char32 c : source) {
    if (charCount == 0) break;
    if (iteration >= charIndex && charCount-- > 0) {
      int32 count = GetBytes(c, bytes, bytesLength, index + byteIndex);
      index += count;
    }
    iteration += 1;
  }

  if (iteration <= charIndex && charIndex > 0)
    throw ArgumentOutOfRangeException(caller_);

  return index;
}

Array<byte> Encoding::GetBytes(const String& s, int32 index, int32 count) const {
  ArrayAlgorithms::ValidateRange(s.Length(), index, count);

  if (count == 0) return Array<byte>();

  // todo optimize
  return GetBytes(s.Substring(index, count));
}

int32 Encoding::GetCharCount(const byte bytes[], int32 bytesSize) const {
  ArrayAlgorithms::ValidateArray(bytes, bytesSize);
  if (bytesSize == 0) return 0;
  return GetCharCount(bytes, bytesSize, 0, bytesSize);
}

int32 Encoding::GetChars(const byte bytes[], int32 bytesSize, char32 chars[], int32 charsSize) const {
  ArrayAlgorithms::ValidateArray(bytes, bytesSize);
  ArrayAlgorithms::ValidateArray(chars, charsSize);
  if (bytesSize == 0) return 0;
  return GetChars(bytes, bytesSize, 0, bytesSize, chars, charsSize, 0);
}

Array<char32> Encoding::GetChars(const byte bytes[], int32 bytesSize) const {
  ArrayAlgorithms::ValidateArray(bytes, bytesSize);
  int32 nbChars = GetCharCount(bytes, bytesSize);
  if (nbChars == 0) return Array<char32>();
  Array<char32> chars(nbChars);
  GetChars(bytes, bytesSize, 0, bytesSize, (char32*)chars.Data(), nbChars, 0);
  return chars;
}

int32 Encoding::GetChars(const byte bytes[], int32 bytesLength, int32 byteIndex, int32 byteCount, char32 chars[], int32 charsLength, int32 charIndex) const {
  ArrayAlgorithms::ValidateArray(bytes, bytesLength);
  ArrayAlgorithms::ValidateArray(chars, charsLength);
  ArrayAlgorithms::ValidateRange(bytesLength, byteIndex, byteCount);
  ArrayAlgorithms::ValidateIndex(charIndex, charsLength);
  if (bytesLength == 0) return 0;
  refptr<Decoder> decoder = CreateDecoder();
  int index = charIndex;
  for (int32 i = byteIndex; i < byteIndex + byteCount; i += 1) {
    decoder->Add(bytes[i]);
    if (decoder->CodePointDefined()) {
      if (index >= charsLength)
        throw ArgumentException(caller_);
      chars[index++] = decoder->CodePoint();
    }
  }

  return index - charIndex;
}

int32 Encoding::GetChars(const byte bytes[], int32 bytesSize, int32 index, int32 count, char32 chars[], int32 charsSize) const {
  return GetChars(bytes, bytesSize, index, count, chars, charsSize, 0);
}

Array<char32> Encoding::GetChars(const byte bytes[], int32 bytesSize, int32 index, int32 count) const {
  ArrayAlgorithms::ValidateArray(bytes, bytesSize);
  ArrayAlgorithms::ValidateRange(bytesSize, index, count);
  int32 nbChars = GetCharCount(bytes, bytesSize, index, count);
  if (nbChars == 0) return Array<char32>();
  Array<char32> chars(nbChars);
  GetChars(bytes, bytesSize, index, count, (char32*)chars.Data(), nbChars,  0);
  return chars;
}

Array<byte> Encoding::GetPreamble() const {
  return Array<byte>();
}

string Encoding::GetString(const Array<byte>& bytes) const {
  return this->GetString(bytes.Data, bytes.Length);
}

string Encoding::GetString(const byte bytes[], int32 bytesSize) const {
  ArrayAlgorithms::ValidateArray(bytes, bytesSize);
  if (bytesSize == 0) return string();
  int32 charsSize = GetCharCount(bytes, bytesSize);
  Array<char32> chars(charsSize);
  GetChars(bytes, bytesSize, 0, bytesSize, (char32*)chars.Data(), charsSize, 0);
  return string(chars);
}

string Encoding::GetString(const byte bytes[], int32 bytesSize, int32 index, int32 count) const {
  if (bytes == null && bytesSize != 0) throw ArgumentNullException(caller_);

  if (bytesSize == 0) return string();
  int32 nbChars = GetCharCount(bytes, bytesSize, index, count);
  if (nbChars == 0) return string();

  Array<char32> chars(nbChars);
  GetChars(bytes, bytesSize, index, count, (char32*)chars.Data(), nbChars, 0);
  return string(chars.Data(), nbChars, 0, nbChars);
}

bool Encoding::IsAlwaysNormalized() const {
  //todo
  return false;
}

string Encoding::ToString() const {
  return GetEncodingName();
}

void Encoding::ValidateGBC(int32 charsLength, int32 index, int32 count) const {
  if (index < 0 || count < 0 || index > charsLength || index + count > charsLength)
    throw ArgumentOutOfRangeException(caller_);
}

void Encoding::ValidateGCC(int32 bytesLength, int32 index, int32 count) const {
  if (index < 0 || count < 0 || (index > bytesLength && index > 0))
    throw ArgumentOutOfRangeException(caller_);

  if (index + count > bytesLength)
    throw ArgumentOutOfRangeException(caller_);
}

void Encoding::ValidateGC(int32 bytesLength, int32 byteIndex, int32 byteCount, int32 charsLength, int32 charIndex) const {
  if (byteIndex < 0 || byteCount < 0 || byteIndex > bytesLength || byteIndex + byteCount > bytesLength)
    throw ArgumentOutOfRangeException(caller_);

  if (charIndex < 0 || charIndex >= charsLength)
    throw ArgumentOutOfRangeException(caller_);
}

