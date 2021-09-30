#if defined(_WIN32)

#include <csignal>
#include <conio.h>
#include <windows.h>
#include "../../include/Switch/Undef.hpp"

#include "Api.hpp"

using namespace System;

namespace {
  static ConsoleColor backColor = Native::ConsoleApi::GetBackgroundColor();
  static ConsoleColor foreColor = Native::ConsoleApi::GetForegroundColor();
}

void Native::ConsoleApi::Beep(int32 frequency, int32 duration) {
  ::Beep(frequency, duration);
}

void Native::ConsoleApi::Clrscr() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  const COORD coord = {0, 0};
  DWORD nbCharsWritten = 0;
  FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &nbCharsWritten);
  FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &nbCharsWritten);
  SetCursorPosition(0, 0);
}

ConsoleColor Native::ConsoleApi::GetBackgroundColor() {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  return ConsoleColor((bufferInfo.wAttributes & 0x00F0) >> 4);
}

int32 Native::ConsoleApi::GetBufferHeight() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwSize.Y;
}

int32 Native::ConsoleApi::GetBufferWidth() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwSize.X;
}

bool Native::ConsoleApi::GetCapsLock() {
  return (GetKeyState(VK_CAPITAL) & 0x0001) == 0x0001;
}

int32 Native::ConsoleApi::GetCursorLeft() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwCursorPosition.X;
}

int32 Native::ConsoleApi::GetCursorSize() {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
  return cursorInfo.dwSize;
}

int32 Native::ConsoleApi::GetCursorTop() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwCursorPosition.Y;
}

bool Native::ConsoleApi::GetCursorVisible() {
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
  return cursorInfo.bVisible != FALSE;
}

ConsoleColor Native::ConsoleApi::GetForegroundColor() {
  CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
  return ConsoleColor(bufferInfo.wAttributes & 0x000F);
}

int32 Native::ConsoleApi::GetInputCodePage() {
  return GetConsoleCP();
}

int32 Native::ConsoleApi::GetLargestWindowHeight() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwMaximumWindowSize.Y;
}

int32 Native::ConsoleApi::GetLargestWindowWidth() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwMaximumWindowSize.X;
}

bool Native::ConsoleApi::GetNumberLock() {
  return (GetKeyState(VK_NUMLOCK) & 0x0001) == 0x0001;
}

int32 Native::ConsoleApi::GetOutputCodePage() {
  return GetConsoleOutputCP();
}

System::Collections::Generic::Dictionary<int32, System::ConsoleSpecialKey> Native::ConsoleApi::GetSignalKeys() {
  return {{SIGBREAK, System::ConsoleSpecialKey::ControlBreak}, {SIGINT, System::ConsoleSpecialKey::ControlC}};
}

string Native::ConsoleApi::GetTitle() {
  return "";
}

int32 Native::ConsoleApi::GetWindowHeight() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int32 Native::ConsoleApi::GetWindowLeft() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Left;
}

int32 Native::ConsoleApi::GetWindowTop() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Top;
}

int32 Native::ConsoleApi::GetWindowWidth() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

bool Native::ConsoleApi::KeyAvailable() {
  return _kbhit() != 0;
}

void Native::ConsoleApi::ReadKey(int32& keyChar, int32& keyCode, bool& alt, bool& shift, bool& ctrl) {
  INPUT_RECORD inputRecord;
  do {
    DWORD nbEventsRead = 0;
    ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &inputRecord, 1, &nbEventsRead);
  } while (!(inputRecord.EventType == KEY_EVENT && (inputRecord.Event.KeyEvent.bKeyDown == 1 && inputRecord.Event.KeyEvent.wVirtualKeyCode != 0x10 && inputRecord.Event.KeyEvent.wVirtualKeyCode != 0x11 && inputRecord.Event.KeyEvent.wVirtualKeyCode != 0x12)));

  keyChar = inputRecord.Event.KeyEvent.uChar.AsciiChar;
  keyCode = inputRecord.Event.KeyEvent.wVirtualKeyCode;
  alt = (inputRecord.Event.KeyEvent.dwControlKeyState & LEFT_ALT_PRESSED) == LEFT_ALT_PRESSED || (inputRecord.Event.KeyEvent.dwControlKeyState & RIGHT_ALT_PRESSED) == RIGHT_ALT_PRESSED;
  shift = (inputRecord.Event.KeyEvent.dwControlKeyState & SHIFT_PRESSED) == SHIFT_PRESSED;
  ctrl = (inputRecord.Event.KeyEvent.dwControlKeyState & LEFT_CTRL_PRESSED) == LEFT_CTRL_PRESSED || (inputRecord.Event.KeyEvent.dwControlKeyState & RIGHT_CTRL_PRESSED) == RIGHT_CTRL_PRESSED;
}

bool Native::ConsoleApi::ResetColor() {
  return SetBackgroundColor(backColor) && SetForegroundColor(foreColor);
}

bool Native::ConsoleApi::SetBackgroundColor(ConsoleColor color) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  csbi.wAttributes &= 0xFF0F;
  csbi.wAttributes |= (int32)color << 4;
  return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes) == TRUE;
}

bool Native::ConsoleApi::SetBufferHeight(int32 height) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwSize.Y = (int16)height;
  return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwSize) == TRUE;
}

bool Native::ConsoleApi::SetBufferWidth(int32 width) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwSize.X = (int16)width;
  return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwSize) == TRUE;
}

bool Native::ConsoleApi::SetCursorPosition(int32 left, int32 top) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwCursorPosition.X = (int16)left;
  csbi.dwCursorPosition.Y = (int16)top;
  return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwCursorPosition) == TRUE;
}

void Native::ConsoleApi::SetCursorSize(int32 size) {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

  cci.dwSize = size;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Native::ConsoleApi::SetCursorVisible(bool visible) {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

  cci.bVisible = visible;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Native::ConsoleApi::SetEchoVisible(bool visible) {
  // Only for Linux terminal...
}

bool Native::ConsoleApi::SetForegroundColor(ConsoleColor color) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  csbi.wAttributes &= 0xFFF0;
  csbi.wAttributes |= (int32)color;
  return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes) == TRUE;
}

bool Native::ConsoleApi::SetInputCodePage(int32 codePage) {
  return SetConsoleCP(codePage) == TRUE;
}

bool Native::ConsoleApi::SetOutputCodePage(int32 codePage) {
  return SetConsoleOutputCP(codePage) == TRUE;
}

bool Native::ConsoleApi::SetTitle(const string& title) {
  return true;
}

bool Native::ConsoleApi::SetWindowHeight(int32 height) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Bottom = int16(csbi.srWindow.Top + height - 1);
  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}

bool Native::ConsoleApi::SetWindowLeft(int32 left) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Left = (int16)left;
  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}

bool Native::ConsoleApi::SetWindowTop(int32 top) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Top = (int16)top;
  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}

bool Native::ConsoleApi::SetWindowWidth(int32 width) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Right = int16(csbi.srWindow.Left + width - 1);
  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}

#endif
