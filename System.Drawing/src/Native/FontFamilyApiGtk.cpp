#if defined(__linux__)
#include "Api.hpp"

#undef interface_
#undef get_
#undef set_

#include <gtkmm.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

Array<System::Drawing::FontFamily> Native::FontFamilyApi::GetInstalledFontFamilies() {
  System::Array<System::Drawing::FontFamily> families;
  return families;
}

System::Drawing::FontFamily Native::FontFamilyApi::GetFontFamilyFromName(const string& name) {
  throw ArgumentException(caller_);
}

string Native::FontFamilyApi::GetName(intptr handle) {
  return "<not implemented>";
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
}

#endif
