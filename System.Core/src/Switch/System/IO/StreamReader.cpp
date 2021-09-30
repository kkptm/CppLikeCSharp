#include "../../../../include/Switch/System/IO/StreamReader.hpp"
#include "../../../../include/Switch/System/Array.hpp"
#include "../../../../include/Switch/System/Convert.hpp"
#include "../../../../include/Switch/System/ObjectDisposedException.hpp"
#include "../../../../include/Switch/System/IO/FileStream.hpp"
#include "../../../../include/Switch/System/Text/StringBuilder.hpp"

using namespace System;
using namespace System::IO;

Text::UTF8Encoding StreamReader::utf8Encoding {false};

StreamReader::StreamReader() {
  this->data->stream = new NullStream();
  this->data->encoding = utf8Encoding;
}

StreamReader::StreamReader(const string& path) {
  this->data->stream = new FileStream(path, FileMode::Open, FileAccess::Read, FileShare::ReadWrite);
  this->data->encoding = utf8Encoding;
}

StreamReader::StreamReader(const string& path, Text::Encoding& encoding) {
  this->data->stream = new FileStream(path, FileMode::Open, FileAccess::Read, FileShare::ReadWrite);
  this->data->encoding = encoding;
}

void StreamReader::Close() {
  this->data->stream->Close();
}

int32 StreamReader::Peek() const {
  if (this->data->stream->CanSeek) {
    int64 position = this->data->stream->Position;
    int32 peek = const_cast<StreamReader&>(*this).data->stream->ReadByte();
    const_cast<StreamReader&>(*this).data->stream->Seek(position, System::IO::SeekOrigin::Begin);
    return peek;
  }

  if (!this->data->hasPeekByte) {
    const_cast<StreamReader&>(*this).data->peekByte = const_cast<StreamReader&>(*this).data->stream->ReadByte();
    const_cast<StreamReader&>(*this).data->hasPeekByte = true;
  }
  return this->data->peekByte;
}

int32 StreamReader::Read() {
  return Read(*this->data->encoding->CreateDecoder());
}

int32 StreamReader::Read(Text::Encoding::Decoder& decoder) {
  if (this->data->stream->CanSeek)
    return ReadCodePoint(decoder);

  if (!this->data->hasPeekByte) {
    int32 result = ReadCodePoint(decoder);
    this->data->peekByte = ReadCodePoint(decoder);
    this->data->hasPeekByte = true;
    return result;
  }

  int32 result = this->data->peekByte;
  this->data->peekByte = ReadCodePoint(decoder);
  return result;
}

int32 StreamReader::ReadCodePoint(Text::Encoding::Decoder& decoder) {
  for (int32 value = this->data->stream->ReadByte(); value != -1; value = this->data->stream->ReadByte()) {
    decoder.Add(Convert::ToByte(value));
    if (decoder.CodePointDefined())
      return (int32)decoder.CodePoint();
  }
  return -1;
}

string StreamReader::ReadLine() {
  refptr<Text::Encoding::Decoder> decoder = this->data->encoding->CreateDecoder();
  string result;
  for (int32 value = this->Read(*decoder); value != -1 && value != '\n'; value = this->Read(*decoder)) {
    if (value != '\r')
      result += (char32)value;
  }

  return result;
}

string StreamReader::ReadToEnd() {
  refptr<Text::Encoding::Decoder> decoder = this->data->encoding->CreateDecoder();
  String result;
  for (int32 value = this->Read(*decoder); value != -1; value = this->Read(*decoder)) {
    if (value != '\r')
      result += (char32)value;
  }

  return result;
}
