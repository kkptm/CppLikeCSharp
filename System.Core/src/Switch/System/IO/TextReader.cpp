#include "../../../../include/Switch/System/IO/TextReader.hpp"
#include "../../../../include/Switch/System/Convert.hpp"
#include "../../../../include/Switch/System/Text/Encoding.hpp"

using namespace System;
using namespace System::IO;

NullTextReader& TextReader::Null() {
  static NullTextReader nullTextReader;
  return nullTextReader;
}

string TextReader::ReadLine() {
  string line;
  refptr<Text::Encoding::Decoder> decoder = Text::Encoding::UTF8->CreateDecoder();
  for (int32 current = Read(); current != -1 && current != '\n'; current = Read()) {
    if (current == '\r') continue;
    decoder->Add(Convert::ToByte(current));
    if (decoder->CodePointDefined())
      line += decoder->CodePoint();
  }
  return line;
}

string TextReader::ReadToEnd() {
  string text;
  refptr<Text::Encoding::Decoder> decoder = Text::Encoding::UTF8->CreateDecoder();
  for (int32 current = Read(); current != -1; current = Read()) {
    if (current == '\n') continue;
    decoder->Add(Convert::ToByte(current));
    if (decoder->CodePointDefined())
      text += decoder->CodePoint();
  }
  return text;
}

SynchronizedTextReader TextReader::Synchronised(TextReader& reader) {
  return SynchronizedTextReader(reader);
}
