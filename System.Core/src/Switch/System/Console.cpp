#include <cstdio>
#include <cstring>
#include <cwchar>
#include <iostream>

#include "../../../include/Switch/System/IO/IOException.hpp"
#include "../../../include/Switch/System/Buffer.hpp"
#include "../../../include/Switch/System/Console.hpp"
#include "../../../include/Switch/System/Environment.hpp"
#include "../../../include/Switch/System/Text/UTF8Encoding.hpp"
#include "../../Native/Api.hpp"

namespace {
  // This hack is necessary in windows because std::cout does not work properly with Utf8 and unicode code page
  // Moreover std::cout on Windows is very slow.
  // printf work correctly...
  std::ostream& operator<<(std::ostream& output, const char* value) {
    printf("%s", value);
    return output;
  }

  refptr<System::Text::Encoding> inputEncoding = ref_new<System::Text::UTF8Encoding>(false);
  refptr<System::Text::Encoding> outputEncoding = ref_new<System::Text::UTF8Encoding>(false);

  bool treatControlCAsInput = false;
}

using namespace System;

void Console::StandardErrorOutput::Write(const System::String& s) {
  if (outputEncoding->GetCodePage() == 65001) // Utf8
    std::cerr << (const char*)s.Data();
  else if (outputEncoding->IsSingleByte()) // Ascii
    std::cerr << s.ToCCharArray(outputEncoding->GetCodePage()).Data();
  else if (outputEncoding->GetCodePage() == 1200) { // Unicode
    System::Array<byte> bytes = outputEncoding->GetBytes(s);
    System::Array<char16> str(bytes.Length + 1);
    Buffer::BlockCopy(bytes, 0, str, 0, bytes.Length);
    str[bytes.Length] = 0;
    std::wcerr << str.Data();
  } else { // Utf32
    System::Array<byte> bytes = outputEncoding->GetBytes(s);
    System::Array<char32> str(bytes.Length + 1);
    Buffer::BlockCopy(bytes, 0, str, 0, bytes.Length);
    str[bytes.Length] = 0;
    std::wcerr << str.Data();
  }
}

void Console::StandardOutput::Write(const System::String& s) {
  if (outputEncoding->GetCodePage() == 65001) // Utf8
    std::cout << (const char*)s.Data();
  else if (outputEncoding->IsSingleByte()) // Ascii
    std::cout << s.ToCCharArray(outputEncoding->GetCodePage()).Data();
  else if (outputEncoding->GetCodePage() == 1200) { // Unicode
    int32 length = outputEncoding->GetByteCount(s);
    System::Array<char16> str(length + 1);
    outputEncoding->GetBytes(s, (byte*)str.Data(), length);
    str[length] = 0;
    std::wcout << str.Data();
  } else { // Utf32
    int32 length = outputEncoding->GetByteCount(s);
    System::Array<char32> str(length + 1);
    outputEncoding->GetBytes(s, (byte*)str.Data(), length);
    str[length] = 0;
    std::wcout << str.Data();
  }
}

namespace {
  Console::StandardInput sin;
  Console::StandardErrorOutput serror;
  Console::StandardOutput sout;
  System::IO::TextReader* defaultIn = &sin;
  System::IO::TextWriter* defaultError = &serror;
  System::IO::TextWriter* defaultOut = &sout;
  System::IO::TextReader* in = &sin;
  System::IO::TextWriter* error = &serror;
  System::IO::TextWriter* out = &sout;
}

property_<ConsoleColor> Console::BackgroundColor {
  [] {return Native::ConsoleApi::GetBackgroundColor();},
  [](ConsoleColor value) {
    if (!Enum<>::IsDefined(value))
      throw ArgumentException(caller_);
    if (!Native::ConsoleApi::SetBackgroundColor(value))
      throw System::IO::IOException(caller_);
  }
};

property_<int32> Console::BufferHeight{
  [] {return Native::ConsoleApi::GetBufferHeight(); },
  [](int32 value) {
    Native::ConsoleApi::SetBufferHeight(value);
  }
};

property_<int32> Console::BufferWidth{
  [] {return Native::ConsoleApi::GetBufferWidth(); },
  [](int32 value) {
    Native::ConsoleApi::SetBufferWidth(value);
  }
};

property_<bool, readonly_> Console::CapsLock {
  [] {return Native::ConsoleApi::GetCapsLock();}
};

property_<int32> Console::CursorLeft {
  [] {return Native::ConsoleApi::GetCursorLeft();},
  [](int32 value) {
    if (value < 0 || value >= Native::ConsoleApi::GetWindowWidth())
      throw ArgumentOutOfRangeException(caller_);

    SetCursorPosition(value, Native::ConsoleApi::GetCursorTop());
  }
};

property_<int32> Console::CursorSize {
  [] {return Native::ConsoleApi::GetCursorSize();},
  [](int32 value) {
    if (value < 1 || value > 100)
      throw ArgumentOutOfRangeException(caller_);

    Native::ConsoleApi::SetCursorSize(value);
  }
};

property_<int32> Console::CursorTop {
  [] {return Native::ConsoleApi::GetCursorTop();},
  [](int32 value) {
    if (value < 0 || value >= Native::ConsoleApi::GetBufferHeight())
      throw ArgumentOutOfRangeException(caller_);

    SetCursorPosition(Native::ConsoleApi::GetCursorLeft(), value);
  }
};

property_<bool> Console::CursorVisible {
  [] {return Native::ConsoleApi::GetCursorVisible();},
  [](bool value) {Native::ConsoleApi::SetCursorVisible(value);}
};

property_<Console::StandardErrorOutput&, readonly_> Console::Error {
  []()->Console::StandardErrorOutput& {
    static StandardErrorOutput e;
    return e;
  }
};

property_<ConsoleColor> Console::ForegroundColor {
  [] {return Native::ConsoleApi::GetForegroundColor();},
  [](ConsoleColor value) {
    if (!Enum<>::IsDefined(value))
      throw ArgumentException(caller_);
    Native::ConsoleApi::SetForegroundColor(value);
  }
};

property_<Console::StandardInput&, readonly_> Console::In {
  []()->Console::StandardInput& {
    static StandardInput i;
    return i;
  }
};

property_<const refptr<System::Text::Encoding>&> Console::InputEncoding {
  []()->const refptr<System::Text::Encoding>& {return inputEncoding;},
  [](const refptr<System::Text::Encoding>& value) {
    inputEncoding = value;
    Native::ConsoleApi::SetInputCodePage(inputEncoding->GetCodePage());
  }
};

property_<bool, readonly_> Console::IsErrorRedirected{
  [] {return error != defaultError; }
};

property_<bool, readonly_> Console::IsInputRedirected{
  [] {return in != defaultIn; }
};

property_<bool, readonly_> Console::IsOutputRedirected{
  [] {return out != defaultOut; }
};

property_<bool, readonly_> Console::KeyAvailable {
  [] {
    Console::__f();
    return Native::ConsoleApi::KeyAvailable();
  }
};

property_<int32, readonly_> Console::LargestWindowHeight{
  [] {return Native::ConsoleApi::GetLargestWindowHeight(); }
};

property_<int32, readonly_> Console::LargestWindowWidth{
  [] {return Native::ConsoleApi::GetLargestWindowWidth(); }
};

property_<bool, readonly_> Console::NumberLock{
  [] {return Native::ConsoleApi::GetNumberLock(); }
};

property_<Console::StandardOutput&, readonly_> Console::Out {
  []()->Console::StandardOutput& {
    static StandardOutput o;
    return o;
  }
};

property_<const refptr<System::Text::Encoding>&> Console::OutputEncoding {
  []()->const refptr<System::Text::Encoding>& {return outputEncoding;},
  [](const refptr<System::Text::Encoding>& value) {
    outputEncoding = value;
    Native::ConsoleApi::SetOutputCodePage(outputEncoding->GetCodePage());
  }
};

property_<string> Console::Title {
  [] {return Native::ConsoleApi::GetTitle(); },
  [](const string & value) {Native::ConsoleApi::SetTitle(value);}
};

property_<bool> Console::TreatControlCAsInput {
  [] {return treatControlCAsInput;},
  [](bool value) {treatControlCAsInput = value;}
};

property_<int32> Console::WindowHeight {
  []{return Native::ConsoleApi::GetWindowHeight(); },
  [](int32 value) {
    Native::ConsoleApi::SetWindowHeight(value);
  }
};

property_<int32> Console::WindowLeft {
  []{return Native::ConsoleApi::GetWindowLeft(); },
  [](int32 value) {
    Native::ConsoleApi::SetWindowLeft(value);
  }
};

property_<int32> Console::WindowTop {
  []{return Native::ConsoleApi::GetWindowTop(); },
  [](int32 value) {
    Native::ConsoleApi::SetWindowTop(value);
  }
};

property_<int32> Console::WindowWidth {
  [] {return Native::ConsoleApi::GetWindowWidth(); },
  [](int32 value) {
    Native::ConsoleApi::SetWindowWidth(value);
  }
};

ConsoleCancelEventHandler Console::CancelKeyPress;

void Console::Beep(int32 frequency, int32 duration) {
  if (frequency < 37 || frequency > 32767 || duration <= 0)
    throw ArgumentOutOfRangeException(caller_);

  Native::ConsoleApi::Beep(frequency, duration);
}

void Console::Clear() {
  Native::ConsoleApi::Clrscr();
}

void Console::MoveBufferArea(int32 sourceLeft, int32 sourceTop, int32 sourceWidth, int32 sourceHeight, int32 targetLeft, int32 targetTop, char32 sourceChar, ConsoleColor sourceForeColor, ConsoleColor sourceBackColor) {

}

int32 Console::Read() {
  out->Flush();
  return in->Read();
}

struct AutoEchoVisible {
  AutoEchoVisible() {Native::ConsoleApi::SetEchoVisible(true);}
  ~AutoEchoVisible() {Native::ConsoleApi::SetEchoVisible(false);}
};

String Console::ReadLine() {
  AutoEchoVisible autoEchoVisible;
  out->Flush();
  return in->ReadLine();
}

ConsoleKeyInfo Console::ReadKey() {
  return ReadKey(false);
}

ConsoleKeyInfo Console::ReadKey(bool intercept) {
  int32 KeyChar = 0;
  int32 KeyCode = 0;
  bool alt = false;
  bool shift = false;
  bool ctrl = false;
  ConsoleKeyInfo keyInfo;

  out->Flush();
  Native::ConsoleApi::ReadKey(KeyChar, KeyCode, alt, shift, ctrl);
  keyInfo = ConsoleKeyInfo(KeyChar, (ConsoleKey)KeyCode, shift, alt, ctrl);

  if (intercept == false)
    Write(Char(keyInfo.KeyChar()));

  return keyInfo;
}

void Console::ResetColor() {
  Native::ConsoleApi::ResetColor();
}

void Console::SetCursorPosition(int32 left, int32 top) {
  Native::ConsoleApi::SetCursorPosition(left, top);
}

void Console::SetError(System::IO::TextWriter& e) {
  error = &e;
}

void Console::SetInt(System::IO::TextReader& i) {
  in = &i;
}

void Console::SetOut(System::IO::TextWriter& o) {
  out = &o;
}

void Console::Write(bool value) {
  Write(string::Format("{0}", value));
}

void Console::Write(char value) {
  Write(string::Format("{0}", value));
}

void Console::Write(char16 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(char32 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(wchar value) {
  Write(string::Format("{0}", value));
}

void Console::Write(double value) {
  Write(string::Format("{0}", value));
}

void Console::Write(int32 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(int64 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(const object& value) {
  Write(string::Format("{0}", value.ToString()));
}

void Console::Write(float value) {
  Write(string::Format("{0}", value));
}

void Console::Write(const String& value) {
  lock_(*out) {
    out->Write(value);
  }
}

void Console::Write(uint32 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(uint64 value) {
  Write(string::Format("{0}", value));
}

void Console::Write(const char value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(const char16 value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(const char32 value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(const wchar value[]) {
  Write(string::Format("{0}", value));
}

void Console::Write(llong value) {
  Write(String::Format("{0}", value));
}

void Console::Write(ullong value) {
  Write(String::Format("{0}", value));
}

void Console::Write(unsigned char* value) {
  Write(String::Format("{0}", value));
}

void Console::WriteLine() {
  Write(Environment::NewLine);
}

void Console::WriteLine(bool value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(char value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(char16 value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(char32 value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(wchar value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(double value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(int32 value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(int64 value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(const object& value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(float value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(const String& value) {
  lock_(*out) {
    Write(value);
    WriteLine();
  }
}

void Console::WriteLine(uint32 value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(uint64 value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(llong value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(ullong value) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(const char value[]) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(const char16 value[]) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(const char32 value[]) {
  WriteLine(String::Format("{0}", value));
}

void Console::WriteLine(const wchar value[]) {
  WriteLine(String::Format("{0}", value));
}

void Console::__f() {
  out->Flush();
}
