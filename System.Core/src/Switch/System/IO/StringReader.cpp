#include "../../../../include/Switch/System/IO/StringReader.hpp"
#include "../../../../include/Switch/System/Array.hpp"
#include "../../../../include/Switch/System/ObjectDisposedException.hpp"
#include "../../../../include/Switch/System/IO/IOException.hpp"

using namespace System;
using namespace System::IO;

StringReader::StringReader(const String& s) : input(s), enumerator(input.GetEnumerator()) {
  this->finished = (this->enumerator.MoveNext() == false);
}

StringReader::StringReader(const StringReader& sr) : input(sr.input), enumerator(input.GetEnumerator()) {
  this->finished = (this->enumerator.MoveNext() == false);
}

StringReader& StringReader::operator =(const StringReader& sr) {
  this->closed = false;
  this->input = sr.input;
  this->enumerator = this->input.GetEnumerator();
  this->finished = (this->enumerator.MoveNext() == false);
  this->position = 0;
  return *this;
}


void StringReader::Close() {
  this->closed = true;
  this->input = "";
}

int32 StringReader::Peek() const {
  if (this->closed)
    throw ObjectDisposedException(caller_);

  if (this->finished)
    return -1;

  return Convert::ToInt32(this->enumerator.Current());
}

int32 StringReader::Read() {
  int32 peek = Peek();
  this->finished = (this->enumerator.MoveNext() == false);
  this->position += 1;
  return peek;
}

string StringReader::ReadLine() {
  string line;
  while (!finished) {
    int32 c = Read();
    if (c == 10)
      return line;
    if (c == 13)
      continue;
    line += char32(c);
  }
  return line;
}

string StringReader::ReadToEnd() {
  if (this->closed)
    throw ObjectDisposedException(caller_);
  this->finished = true;
  return this->input.Substring(this->position);
}
