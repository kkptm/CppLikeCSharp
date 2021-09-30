#if defined(_WIN32)

#define _CRT_SECURE_NO_WARNINGS
#define UNICODE

#include <windows.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"
#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/ArgumentException.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace {
  LOGFONT CreateLOGFONTWithNameAndCharSet(const string& name, int32 charSet) {
    LOGFONT logFont;
    logFont.lfCharSet = (byte)charSet;
    wcscpy(logFont.lfFaceName, name.w_str().c_str());
    logFont.lfPitchAndFamily = 0;
    return logFont;
  }

  int CALLBACK EnumFamilyCallback(CONST LOGFONTW* logFont, CONST TEXTMETRICW* textMetric, DWORD fontType, LPARAM logFonts) {
    if ((fontType & TRUETYPE_FONTTYPE) == TRUETYPE_FONTTYPE && logFont->lfFaceName[0] != '@')
      (*(SortedDictionary<string, LOGFONTW*>*)logFonts)[string(logFont->lfFaceName).ToLower()] = new LOGFONT(*logFont);
    return 1;
  }

  int CALLBACK EnumFamilyFromNameCallback(CONST LOGFONTW* logFont, CONST TEXTMETRICW* textMetric, DWORD fontType, LPARAM result) {
    if ((fontType & TRUETYPE_FONTTYPE) == TRUETYPE_FONTTYPE && logFont->lfFaceName[0] != '@' && (*(LOGFONTW**)result) == null)
      (*(LOGFONTW**)result) = new LOGFONT(*logFont);
    return 1;
  }
}

Array<System::Drawing::FontFamily> Native::FontFamilyApi::GetInstalledFontFamilies() {
  HDC hdc = GetDC(NULL);
  LOGFONT logFont = CreateLOGFONTWithNameAndCharSet("", DEFAULT_CHARSET);
  SortedDictionary<string, LOGFONTW*> logFonts;
  EnumFontFamiliesEx(hdc, &logFont, EnumFamilyCallback, (LPARAM)&logFonts, 0);
  ReleaseDC(NULL, hdc);
  System::Array<System::Drawing::FontFamily> families(logFonts.Count);
  int32 index = 0;
  for (auto item : logFonts)
    families[index++] = System::Drawing::FontFamily((intptr)item.Value());
  return  families;
}

System::Drawing::FontFamily Native::FontFamilyApi::GetFontFamilyFromName(const string& name) {
  HDC hdc = GetDC(NULL);
  LOGFONT logFont = CreateLOGFONTWithNameAndCharSet(name, DEFAULT_CHARSET);
  LOGFONTW* result = null;
  EnumFontFamiliesEx(hdc, &logFont, EnumFamilyFromNameCallback, (LPARAM)&result, 0);
  ReleaseDC(NULL, hdc);
  if (result != null)
    return System::Drawing::FontFamily((intptr)result);
  throw ArgumentException(caller_);
}

string Native::FontFamilyApi::GetName(intptr handle) {
  if (handle == 0) return "";
  return ((LOGFONT*)handle)->lfFaceName;
}

bool Native::FontFamilyApi::IsStyleAvailable(intptr handle, FontStyle style) {
  if (handle == 0) return false;

  /*
  if ((style & FontStyle::Italic) == FontStyle::Italic && result->lfItalic == 0) return false;
  if ((style & FontStyle::Underline) == FontStyle::Underline && result->lfUnderline == 0) return false;
  if ((style & FontStyle::Strikeout) == FontStyle::Strikeout && result->lfStrikeOut == 0) return false;
  */
  return true;
}

void Native::FontFamilyApi::ReleaseResource(intptr handle) {
  if (handle != 0)
    delete (LOGFONT*)handle;
}

#endif
