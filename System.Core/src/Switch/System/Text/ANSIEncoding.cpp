#include "../../../../include/Switch/System/Text/ANSIEncoding.hpp"

using namespace System;
using namespace System::Text;

ANSIEncoding::ANSIEncoding() : Encoding(0) {

}

ANSIEncoding::ANSIEncoding(int32 codePage) : Encoding(codePage) {

}

ANSIEncoding::ANSIEncoding(const ANSIEncoding& encoding) : Encoding(encoding) {

}

ANSIEncoding& ANSIEncoding::operator=(const ANSIEncoding& encoding) {
  Encoding::operator=(encoding);
  return *this;
}

Encoding& ANSIEncoding::operator=(const Encoding& encoding) {
  if (!is<ANSIEncoding>(encoding))
    return Encoding::operator=(encoding);
  return operator= (static_cast<const ANSIEncoding&>(encoding));
}

int32 ANSIEncoding::GetByteCount(char32) const {
  return 1;
}

int32 ANSIEncoding::GetCharCount(const byte bytes[], int32 bytesSize, int32 index, int32 count) const {
  if (bytes == null && bytesSize != 0) throw ArgumentNullException(caller_);
  ValidateGCC(bytesSize, index, count);
  return count;
}

int32 ANSIEncoding::GetMaxByteCount(int32 charCount) const {
  if (charCount < 0) throw ArgumentOutOfRangeException(caller_);
  return charCount;
}

int32 ANSIEncoding::GetMaxCharCount(int32 byteCount) const {
  if (byteCount < 0) throw ArgumentOutOfRangeException(caller_);
  return byteCount;
}

bool ANSIEncoding::Equals(const object& obj) const {
  const ANSIEncoding* enc = dynamic_cast<const ANSIEncoding*>(&obj);
  if (enc == null)
    return false;

  return this->codePage == enc->codePage;
}

CodePage437Encoding::CodePage437Encoding() : ANSIEncoding(437) {

}

refptr<Encoding::Decoder> CodePage437Encoding::CreateDecoder() const {
  return ref_new<Decoder>();
}

refptr<Encoding::Encoder> CodePage437Encoding::CreateEncoder() const {
  return ref_new<Encoder>();
}

int32 CodePage437Encoding::GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 index) const {
  if (bytes == null && bytesLength > 0) throw ArgumentNullException(caller_);
  if (index < 0) throw ArgumentOutOfRangeException(caller_);

  int32 count = GetByteCount(c);
  if (index + count > bytesLength) throw ArgumentOutOfRangeException(caller_);

  Encoder encoder;
  encoder.Encode(c, &bytes[index]);
  return count;
}

CodePage28591Encoding::CodePage28591Encoding() : ANSIEncoding(28591) {

}

refptr<Encoding::Decoder> CodePage28591Encoding::CreateDecoder() const {
  return ref_new<Decoder>();
}

refptr<Encoding::Encoder> CodePage28591Encoding::CreateEncoder() const {
  return ref_new<Encoder>();
}

int32 CodePage28591Encoding::GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 index) const {
  if (bytes == null && bytesLength > 0) throw ArgumentNullException(caller_);
  if (index < 0) throw ArgumentOutOfRangeException(caller_);

  int32 count = GetByteCount(c);
  if (index + count > bytesLength) throw ArgumentOutOfRangeException(caller_);

  Encoder encoder;
  encoder.Encode(c, &bytes[index]);
  return count;
}



CodePage28592Encoding::CodePage28592Encoding() : ANSIEncoding(28592) {

}

refptr<Encoding::Decoder> CodePage28592Encoding::CreateDecoder() const {
  return ref_new<Decoder>();
}

refptr<Encoding::Encoder> CodePage28592Encoding::CreateEncoder() const {
  return ref_new<Encoder>();
}

int32 CodePage28592Encoding::GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 index) const {
  if (bytes == null && bytesLength > 0) throw ArgumentNullException(caller_);
  if (index < 0) throw ArgumentOutOfRangeException(caller_);

  int32 count = GetByteCount(c);
  if (index + count > bytesLength) throw ArgumentOutOfRangeException(caller_);

  Encoder encoder;
  encoder.Encode(c, &bytes[index]);
  return count;
}

ANSIEncoding::Encoder::Encoder(int32 cp) : Encoding::Encoder() {
  codePage = cp;
}

ANSIEncoding::Encoder::Encoder(const ANSIEncoding::Encoder& e) : Encoding::Encoder(e) {
  codePage = e.codePage;
}

ANSIEncoding::Encoder& ANSIEncoding::Encoder::operator=(const ANSIEncoding::Encoder& b) {
  Encoding::Encoder::operator=(b);
  codePage = b.codePage;
  return *this;
}

int32 ANSIEncoding::Encoder::GetNbBytes(char32) const {
  return 1;
}

void ANSIEncoding::Encoder::Encode(char32 codePoint, byte* bytes) const {
  ANSIEncoding::Encoder* encoder = (ANSIEncoding::Encoder*)this;
  bytes[0] = encoder->GetByte(codePoint);
}

String ANSIEncoding::Encoder::ToString() const {
  return String::Format("Code Page {0} Encoder", codePage);
}

byte CodePage437Encoding::Encoder::GetByte(char32 cp) {
  if (cp < 0x80) return static_cast<byte>(cp);
  switch (cp) {
  case 0x00c7: return 0x80; //LATIN CAPITAL LETTER C WITH CEDILLA
  case 0x00fc: return 0x81; //LATIN SMALL LETTER U WITH DIAERESIS
  case 0x00e9: return 0x82; //LATIN SMALL LETTER E WITH ACUTE
  case 0x00e2: return 0x83; //LATIN SMALL LETTER A WITH CIRCUMFLEX
  case 0x00e4: return 0x84; //LATIN SMALL LETTER A WITH DIAERESIS
  case 0x00e0: return 0x85; //LATIN SMALL LETTER A WITH GRAVE
  case 0x00e5: return 0x86; //LATIN SMALL LETTER A WITH RING ABOVE
  case 0x00e7: return 0x87; //LATIN SMALL LETTER C WITH CEDILLA
  case 0x00ea: return 0x88; //LATIN SMALL LETTER E WITH CIRCUMFLEX
  case 0x00eb: return 0x89; //LATIN SMALL LETTER E WITH DIAERESIS
  case 0x00e8: return 0x8a; //LATIN SMALL LETTER E WITH GRAVE
  case 0x00ef: return 0x8b; //LATIN SMALL LETTER I WITH DIAERESIS
  case 0x00ee: return 0x8c; //LATIN SMALL LETTER I WITH CIRCUMFLEX
  case 0x00ec: return 0x8d; //LATIN SMALL LETTER I WITH GRAVE
  case 0x00c4: return 0x8e; //LATIN CAPITAL LETTER A WITH DIAERESIS
  case 0x00c5: return 0x8f; //LATIN CAPITAL LETTER A WITH RING ABOVE
  case 0x00c9: return 0x90; //LATIN CAPITAL LETTER E WITH ACUTE
  case 0x00e6: return 0x91; //LATIN SMALL LIGATURE AE
  case 0x00c6: return 0x92; //LATIN CAPITAL LIGATURE AE
  case 0x00f4: return 0x93; //LATIN SMALL LETTER O WITH CIRCUMFLEX
  case 0x00f6: return 0x94; //LATIN SMALL LETTER O WITH DIAERESIS
  case 0x00f2: return 0x95; //LATIN SMALL LETTER O WITH GRAVE
  case 0x00fb: return 0x96; //LATIN SMALL LETTER U WITH CIRCUMFLEX
  case 0x00f9: return 0x97; //LATIN SMALL LETTER U WITH GRAVE
  case 0x00ff: return 0x98; //LATIN SMALL LETTER Y WITH DIAERESIS
  case 0x00d6: return 0x99; //LATIN CAPITAL LETTER O WITH DIAERESIS
  case 0x00dc: return 0x9a; //LATIN CAPITAL LETTER U WITH DIAERESIS
  case 0x00a2: return 0x9b; //CENT SIGN
  case 0x00a3: return 0x9c; //POUND SIGN
  case 0x00a5: return 0x9d; //YEN SIGN
  case 0x20a7: return 0x9e; //PESETA SIGN
  case 0x0192: return 0x9f; //LATIN SMALL LETTER F WITH HOOK
  case 0x00e1: return 0xa0; //LATIN SMALL LETTER A WITH ACUTE
  case 0x00ed: return 0xa1; //LATIN SMALL LETTER I WITH ACUTE
  case 0x00f3: return 0xa2; //LATIN SMALL LETTER O WITH ACUTE
  case 0x00fa: return 0xa3; //LATIN SMALL LETTER U WITH ACUTE
  case 0x00f1: return 0xa4; //LATIN SMALL LETTER N WITH TILDE
  case 0x00d1: return 0xa5; //LATIN CAPITAL LETTER N WITH TILDE
  case 0x00aa: return 0xa6; //FEMININE ORDINAL INDICATOR
  case 0x00ba: return 0xa7; //MASCULINE ORDINAL INDICATOR
  case 0x00bf: return 0xa8; //INVERTED QUESTION MARK
  case 0x2310: return 0xa9; //REVERSED NOT SIGN
  case 0x00ac: return 0xaa; //NOT SIGN
  case 0x00bd: return 0xab; //VULGAR FRACTION ONE HALF
  case 0x00bc: return 0xac; //VULGAR FRACTION ONE QUARTER
  case 0x00a1: return 0xad; //INVERTED EXCLAMATION MARK
  case 0x00ab: return 0xae; //LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
  case 0x00bb: return 0xaf; //RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
  case 0x2591: return 0xb0; //LIGHT SHADE
  case 0x2592: return 0xb1; //MEDIUM SHADE
  case 0x2593: return 0xb2; //DARK SHADE
  case 0x2502: return 0xb3; //BOX DRAWINGS LIGHT VERTICAL
  case 0x2524: return 0xb4; //BOX DRAWINGS LIGHT VERTICAL AND LEFT
  case 0x2561: return 0xb5; //BOX DRAWINGS VERTICAL SINGLE AND LEFT DOUBLE
  case 0x2562: return 0xb6; //BOX DRAWINGS VERTICAL DOUBLE AND LEFT SINGLE
  case 0x2556: return 0xb7; //BOX DRAWINGS DOWN DOUBLE AND LEFT SINGLE
  case 0x2555: return 0xb8; //BOX DRAWINGS DOWN SINGLE AND LEFT DOUBLE
  case 0x2563: return 0xb9; //BOX DRAWINGS DOUBLE VERTICAL AND LEFT
  case 0x2551: return 0xba; //BOX DRAWINGS DOUBLE VERTICAL
  case 0x2557: return 0xbb; //BOX DRAWINGS DOUBLE DOWN AND LEFT
  case 0x255d: return 0xbc; //BOX DRAWINGS DOUBLE UP AND LEFT
  case 0x255c: return 0xbd; //BOX DRAWINGS UP DOUBLE AND LEFT SINGLE
  case 0x255b: return 0xbe; //BOX DRAWINGS UP SINGLE AND LEFT DOUBLE
  case 0x2510: return 0xbf; //BOX DRAWINGS LIGHT DOWN AND LEFT
  case 0x2514: return 0xc0; //BOX DRAWINGS LIGHT UP AND RIGHT
  case 0x2534: return 0xc1; //BOX DRAWINGS LIGHT UP AND HORIZONTAL
  case 0x252c: return 0xc2; //BOX DRAWINGS LIGHT DOWN AND HORIZONTAL
  case 0x251c: return 0xc3; //BOX DRAWINGS LIGHT VERTICAL AND RIGHT
  case 0x2500: return 0xc4; //BOX DRAWINGS LIGHT HORIZONTAL
  case 0x253c: return 0xc5; //BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL
  case 0x255e: return 0xc6; //BOX DRAWINGS VERTICAL SINGLE AND RIGHT DOUBLE
  case 0x255f: return 0xc7; //BOX DRAWINGS VERTICAL DOUBLE AND RIGHT SINGLE
  case 0x255a: return 0xc8; //BOX DRAWINGS DOUBLE UP AND RIGHT
  case 0x2554: return 0xc9; //BOX DRAWINGS DOUBLE DOWN AND RIGHT
  case 0x2569: return 0xca; //BOX DRAWINGS DOUBLE UP AND HORIZONTAL
  case 0x2566: return 0xcb; //BOX DRAWINGS DOUBLE DOWN AND HORIZONTAL
  case 0x2560: return 0xcc; //BOX DRAWINGS DOUBLE VERTICAL AND RIGHT
  case 0x2550: return 0xcd; //BOX DRAWINGS DOUBLE HORIZONTAL
  case 0x256c: return 0xce; //BOX DRAWINGS DOUBLE VERTICAL AND HORIZONTAL
  case 0x2567: return 0xcf; //BOX DRAWINGS UP SINGLE AND HORIZONTAL DOUBLE
  case 0x2568: return 0xd0; //BOX DRAWINGS UP DOUBLE AND HORIZONTAL SINGLE
  case 0x2564: return 0xd1; //BOX DRAWINGS DOWN SINGLE AND HORIZONTAL DOUBLE
  case 0x2565: return 0xd2; //BOX DRAWINGS DOWN DOUBLE AND HORIZONTAL SINGLE
  case 0x2559: return 0xd3; //BOX DRAWINGS UP DOUBLE AND RIGHT SINGLE
  case 0x2558: return 0xd4; //BOX DRAWINGS UP SINGLE AND RIGHT DOUBLE
  case 0x2552: return 0xd5; //BOX DRAWINGS DOWN SINGLE AND RIGHT DOUBLE
  case 0x2553: return 0xd6; //BOX DRAWINGS DOWN DOUBLE AND RIGHT SINGLE
  case 0x256b: return 0xd7; //BOX DRAWINGS VERTICAL DOUBLE AND HORIZONTAL SINGLE
  case 0x256a: return 0xd8; //BOX DRAWINGS VERTICAL SINGLE AND HORIZONTAL DOUBLE
  case 0x2518: return 0xd9; //BOX DRAWINGS LIGHT UP AND LEFT
  case 0x250c: return 0xda; //BOX DRAWINGS LIGHT DOWN AND RIGHT
  case 0x2588: return 0xdb; //FULL BLOCK
  case 0x2584: return 0xdc; //LOWER HALF BLOCK
  case 0x258c: return 0xdd; //LEFT HALF BLOCK
  case 0x2590: return 0xde; //RIGHT HALF BLOCK
  case 0x2580: return 0xdf; //UPPER HALF BLOCK
  case 0x03b1: return 0xe0; //GREEK SMALL LETTER ALPHA
  case 0x00df: return 0xe1; //LATIN SMALL LETTER SHARP S
  case 0x0393: return 0xe2; //GREEK CAPITAL LETTER GAMMA
  case 0x03c0: return 0xe3; //GREEK SMALL LETTER PI
  case 0x03a3: return 0xe4; //GREEK CAPITAL LETTER SIGMA
  case 0x03c3: return 0xe5; //GREEK SMALL LETTER SIGMA
  case 0x00b5: return 0xe6; //MICRO SIGN
  case 0x03c4: return 0xe7; //GREEK SMALL LETTER TAU
  case 0x03a6: return 0xe8; //GREEK CAPITAL LETTER PHI
  case 0x0398: return 0xe9; //GREEK CAPITAL LETTER THETA
  case 0x03a9: return 0xea; //GREEK CAPITAL LETTER OMEGA
  case 0x03b4: return 0xeb; //GREEK SMALL LETTER DELTA
  case 0x221e: return 0xec; //INFINITY
  case 0x03c6: return 0xed; //GREEK SMALL LETTER PHI
  case 0x03b5: return 0xee; //GREEK SMALL LETTER EPSILON
  case 0x2229: return 0xef; //INTERSECTION
  case 0x2261: return 0xf0; //IDENTICAL TO
  case 0x00b1: return 0xf1; //PLUS-MINUS SIGN
  case 0x2265: return 0xf2; //GREATER-THAN OR EQUAL TO
  case 0x2264: return 0xf3; //LESS-THAN OR EQUAL TO
  case 0x2320: return 0xf4; //TOP HALF INTEGRAL
  case 0x2321: return 0xf5; //BOTTOM HALF INTEGRAL
  case 0x00f7: return 0xf6; //DIVISION SIGN
  case 0x2248: return 0xf7; //ALMOST EQUAL TO
  case 0x00b0: return 0xf8; //DEGREE SIGN
  case 0x2219: return 0xf9; //BULLET OPERATOR
  case 0x00b7: return 0xfa; //MIDDLE DOT
  case 0x221a: return 0xfb; //SQUARE ROOT
  case 0x207f: return 0xfc; //SUPERSCRIPT LATIN SMALL LETTER N
  case 0x00b2: return 0xfd; //SUPERSCRIPT TWO
  case 0x25a0: return 0xfe; //BLACK SQUARE
  case 0x00a0: return 0xff; //NO-BREAK SPACE

  // 225 (E1) is both the German sharp S (U+00DF) and the Greek lowercase beta (U+03B2).
  case 0x03B2: return 0xE1;

  // 227 (E3) is the Greek lowercase pi (U+03C0), but early fonts such as
  // Terminal use a variant of pi that is ambiguous in case, and therefore
  // can be used for the Greek capital pi (U+03A0) or the n-ary product sign (U+220F).
  case 0x03A0: return 0xE3;
  case 0x220F: return 0xE3;

  // 228 (E4) is both the n-ary summation sign (U+2211) and the Greek uppercase sigma (U+03A3).
  case 0x2211: return 0xE4;

  //230 (E6) is both the micro sign (U+00B5) and the Greek lowercase mu (U+03BC).
  case 0x03BC: return 0xE6;

  //234 (EA) is both the ohm sign (U+2126) and the Greek uppercase omega (U+03A9).
  case 0x2126: return 0xEA;

  // 235 (EB) is the Greek lowercase delta (U+03B4), but it has also been used
  // as a surrogate for the Icelandic lowercase eth (U+00F0, ð) and the partial
  // derivative sign (U+2202, d).
  case 0x00F0: return 0xEB;
  case 0x2202: return 0xEB;

  // 237 (ED) is supposed to be used as Greek lowercase phi, but is mainly used
  // as the empty set sign (U+2205) and was also used as the Greek phi symbol
  // in italics (U+03D5) to name angles, diameter sign (U+2300, \varnothing),
  // and as a surrogate for the Latin lowercase O with stroke (U+00F8).
  case 0x2205: return 0xED;
  case 0x03D5: return 0xED;
  case 0x2300: return 0xED;
  case 0x00F8: return 0xED;

  // 238 (EE) is both the Greek lowercase epsilon (U+03B5) and the element-of
  // sign (U+2208). Later it was often used for the euro sign (U+20AC).
  case 0x2208: return 0xEE;
  case 0x20AC: return 0xEE;
  }
  return '?';
}

byte CodePage28591Encoding::Encoder::GetByte(char32 cp) {
  if (cp > 0xFF)
    return '?';
  return static_cast<byte>(cp);

}

byte CodePage28592Encoding::Encoder::GetByte(char32 cp) {
  if (cp < 0xA1) return static_cast<byte>(cp);
  switch (cp) {
  case 0x0104: return 0xA1; // LATIN CAPITAL LETTER A WITH OGONEK
  case 0x02D8: return 0xA2; // BREVE
  case 0x0141: return 0xA3; // LATIN CAPITAL LETTER L WITH STROKE
  case 0x00A4: return 0xA4; // CURRENCY SIGN
  case 0x013D: return 0xA5; // LATIN CAPITAL LETTER L WITH CARON
  case 0x015A: return 0xA6; // LATIN CAPITAL LETTER S WITH ACUTE
  case 0x00A7: return 0xA7; // SECTION SIGN
  case 0x00A8: return 0xA8; // DIAERESIS
  case 0x0160: return 0xA9; // LATIN CAPITAL LETTER S WITH CARON
  case 0x015E: return 0xAA; // LATIN CAPITAL LETTER S WITH CEDILLA
  case 0x0164: return 0xAB; // LATIN CAPITAL LETTER T WITH CARON
  case 0x0179: return 0xAC; // LATIN CAPITAL LETTER Z WITH ACUTE
  case 0x00AD: return 0xAD; // SOFT HYPHEN
  case 0x017D: return 0xAE; // LATIN CAPITAL LETTER Z WITH CARON
  case 0x017B: return 0xAF; // LATIN CAPITAL LETTER Z WITH DOT ABOVE
  case 0x00B0: return 0xB0; // DEGREE SIGN
  case 0x0105: return 0xB1; // LATIN SMALL LETTER A WITH OGONEK
  case 0x02DB: return 0xB2; // OGONEK
  case 0x0142: return 0xB3; // LATIN SMALL LETTER L WITH STROKE
  case 0x00B4: return 0xB4; // ACUTE ACCENT
  case 0x013E: return 0xB5; // LATIN SMALL LETTER L WITH CARON
  case 0x015B: return 0xB6; // LATIN SMALL LETTER S WITH ACUTE
  case 0x02C7: return 0xB7; // CARON
  case 0x00B8: return 0xB8; // CEDILLA
  case 0x0161: return 0xB9; // LATIN SMALL LETTER S WITH CARON
  case 0x015F: return 0xBA; // LATIN SMALL LETTER S WITH CEDILLA
  case 0x0165: return 0xBB; // LATIN SMALL LETTER T WITH CARON
  case 0x017A: return 0xBC; // LATIN SMALL LETTER Z WITH ACUTE
  case 0x02DD: return 0xBD; // DOUBLE ACUTE ACCENT
  case 0x017E: return 0xBE; // LATIN SMALL LETTER Z WITH CARON
  case 0x017C: return 0xBF; // LATIN SMALL LETTER Z WITH DOT ABOVE
  case 0x0154: return 0xC0; // LATIN CAPITAL LETTER R WITH ACUTE
  case 0x00C1: return 0xC1; // LATIN CAPITAL LETTER A WITH ACUTE
  case 0x00C2: return 0xC2; // LATIN CAPITAL LETTER A WITH CIRCUMFLEX
  case 0x0102: return 0xC3; // LATIN CAPITAL LETTER A WITH BREVE
  case 0x00C4: return 0xC4; // LATIN CAPITAL LETTER A WITH DIAERESIS
  case 0x0139: return 0xC5; // LATIN CAPITAL LETTER L WITH ACUTE
  case 0x0106: return 0xC6; // LATIN CAPITAL LETTER C WITH ACUTE
  case 0x00C7: return 0xC7; // LATIN CAPITAL LETTER C WITH CEDILLA
  case 0x010C: return 0xC8; // LATIN CAPITAL LETTER C WITH CARON
  case 0x00C9: return 0xC9; // LATIN CAPITAL LETTER E WITH ACUTE
  case 0x0118: return 0xCA; // LATIN CAPITAL LETTER E WITH OGONEK
  case 0x00CB: return 0xCB; // LATIN CAPITAL LETTER E WITH DIAERESIS
  case 0x011A: return 0xCC; // LATIN CAPITAL LETTER E WITH CARON
  case 0x00CD: return 0xCD; // LATIN CAPITAL LETTER I WITH ACUTE
  case 0x00CE: return 0xCE; // LATIN CAPITAL LETTER I WITH CIRCUMFLEX
  case 0x010E: return 0xCF; // LATIN CAPITAL LETTER D WITH CARON
  case 0x0110: return 0xD0; // LATIN CAPITAL LETTER D WITH STROKE
  case 0x0143: return 0xD1; // LATIN CAPITAL LETTER N WITH ACUTE
  case 0x0147: return 0xD2; // LATIN CAPITAL LETTER N WITH CARON
  case 0x00D3: return 0xD3; // LATIN CAPITAL LETTER O WITH ACUTE
  case 0x00D4: return 0xD4; // LATIN CAPITAL LETTER O WITH CIRCUMFLEX
  case 0x0150: return 0xD5; // LATIN CAPITAL LETTER O WITH DOUBLE ACUTE
  case 0x00D6: return 0xD6; // LATIN CAPITAL LETTER O WITH DIAERESIS
  case 0x00D7: return 0xD7; // MULTIPLICATION SIGN
  case 0x0158: return 0xD8; // LATIN CAPITAL LETTER R WITH CARON
  case 0x016E: return 0xD9; // LATIN CAPITAL LETTER U WITH RING ABOVE
  case 0x00DA: return 0xDA; // LATIN CAPITAL LETTER U WITH ACUTE
  case 0x0170: return 0xDB; // LATIN CAPITAL LETTER U WITH DOUBLE ACUTE
  case 0x00DC: return 0xDC; // LATIN CAPITAL LETTER U WITH DIAERESIS
  case 0x00DD: return 0xDD; // LATIN CAPITAL LETTER Y WITH ACUTE
  case 0x0162: return 0xDE; // LATIN CAPITAL LETTER T WITH CEDILLA
  case 0x00DF: return 0xDF; // LATIN SMALL LETTER SHARP S
  case 0x0155: return 0xE0; // LATIN SMALL LETTER R WITH ACUTE
  case 0x00E1: return 0xE1; // LATIN SMALL LETTER A WITH ACUTE
  case 0x00E2: return 0xE2; // LATIN SMALL LETTER A WITH CIRCUMFLEX
  case 0x0103: return 0xE3; // LATIN SMALL LETTER A WITH BREVE
  case 0x00E4: return 0xE4; // LATIN SMALL LETTER A WITH DIAERESIS
  case 0x013A: return 0xE5; // LATIN SMALL LETTER L WITH ACUTE
  case 0x0107: return 0xE6; // LATIN SMALL LETTER C WITH ACUTE
  case 0x00E7: return 0xE7; // LATIN SMALL LETTER C WITH CEDILLA
  case 0x010D: return 0xE8; // LATIN SMALL LETTER C WITH CARON
  case 0x00E9: return 0xE9; // LATIN SMALL LETTER E WITH ACUTE
  case 0x0119: return 0xEA; // LATIN SMALL LETTER E WITH OGONEK
  case 0x00EB: return 0xEB; // LATIN SMALL LETTER E WITH DIAERESIS
  case 0x011B: return 0xEC; // LATIN SMALL LETTER E WITH CARON
  case 0x00ED: return 0xED; // LATIN SMALL LETTER I WITH ACUTE
  case 0x00EE: return 0xEE; // LATIN SMALL LETTER I WITH CIRCUMFLEX
  case 0x010F: return 0xEF; // LATIN SMALL LETTER D WITH CARON
  case 0x0111: return 0xF0; // LATIN SMALL LETTER D WITH STROKE
  case 0x0144: return 0xF1; // LATIN SMALL LETTER N WITH ACUTE
  case 0x0148: return 0xF2; // LATIN SMALL LETTER N WITH CARON
  case 0x00F3: return 0xF3; // LATIN SMALL LETTER O WITH ACUTE
  case 0x00F4: return 0xF4; // LATIN SMALL LETTER O WITH CIRCUMFLEX
  case 0x0151: return 0xF5; // LATIN SMALL LETTER O WITH DOUBLE ACUTE
  case 0x00F6: return 0xF6; // LATIN SMALL LETTER O WITH DIAERESIS
  case 0x00F7: return 0xF7; // DIVISION SIGN
  case 0x0159: return 0xF8; // LATIN SMALL LETTER R WITH CARON
  case 0x016F: return 0xF9; // LATIN SMALL LETTER U WITH RING ABOVE
  case 0x00FA: return 0xFA; // LATIN SMALL LETTER U WITH ACUTE
  case 0x0171: return 0xFB; // LATIN SMALL LETTER U WITH DOUBLE ACUTE
  case 0x00FC: return 0xFC; // LATIN SMALL LETTER U WITH DIAERESIS
  case 0x00FD: return 0xFD; // LATIN SMALL LETTER Y WITH ACUTE
  case 0x0163: return 0xFE; // LATIN SMALL LETTER T WITH CEDILLA
  case 0x02D9: return 0xFF; // DOT ABOVE
  }
  return '?';
}

ANSIEncoding::Decoder::Decoder(const ANSIEncoding::Decoder& b) : Encoding::Decoder(b) {
  codePage = b.codePage;
}

ANSIEncoding::Decoder& ANSIEncoding::Decoder::operator=(const ANSIEncoding::Decoder& b) {
  Encoding::Decoder::operator=(b);
  codePage = b.codePage;
  return *this;
}

void ANSIEncoding::Decoder::Add(byte b) {
  Encoding::Decoder::Add(b);
  finished = true;
  codePoint = GetCodePoint(b);
}

void ANSIEncoding::Decoder::Reset() {
  Encoding::Decoder::Reset();
}

String ANSIEncoding::Decoder::ToString() const {
  return String::Format("Code Page {0} Decoder", codePage);
}

char32 ANSIEncoding::Decoder::GetCodePoint(byte b, const std::vector<char32>& codePoints, uint32 unchanged) {
  // if 0 <= b < unchanged, codePoint corresponds to byte
  if (static_cast<char32>(b) < unchanged) return b;
  return codePoints[b - unchanged];
}

char32 CodePage437Encoding::Decoder::GetCodePoint(byte b) {
  if (b < 0x80) return b;
  switch (b) {
  case 0x80: return  0x00c7; //LATIN CAPITAL LETTER C WITH CEDILLA
  case 0x81: return  0x00fc; //LATIN SMALL LETTER U WITH DIAERESIS
  case 0x82: return  0x00e9; //LATIN SMALL LETTER E WITH ACUTE
  case 0x83: return  0x00e2; //LATIN SMALL LETTER A WITH CIRCUMFLEX
  case 0x84: return  0x00e4; //LATIN SMALL LETTER A WITH DIAERESIS
  case 0x85: return  0x00e0; //LATIN SMALL LETTER A WITH GRAVE
  case 0x86: return  0x00e5; //LATIN SMALL LETTER A WITH RING ABOVE
  case 0x87: return  0x00e7; //LATIN SMALL LETTER C WITH CEDILLA
  case 0x88: return  0x00ea; //LATIN SMALL LETTER E WITH CIRCUMFLEX
  case 0x89: return  0x00eb; //LATIN SMALL LETTER E WITH DIAERESIS
  case 0x8a: return  0x00e8; //LATIN SMALL LETTER E WITH GRAVE
  case 0x8b: return  0x00ef; //LATIN SMALL LETTER I WITH DIAERESIS
  case 0x8c: return  0x00ee; //LATIN SMALL LETTER I WITH CIRCUMFLEX
  case 0x8d: return  0x00ec; //LATIN SMALL LETTER I WITH GRAVE
  case 0x8e: return  0x00c4; //LATIN CAPITAL LETTER A WITH DIAERESIS
  case 0x8f: return  0x00c5; //LATIN CAPITAL LETTER A WITH RING ABOVE
  case 0x90: return  0x00c9; //LATIN CAPITAL LETTER E WITH ACUTE
  case 0x91: return  0x00e6; //LATIN SMALL LIGATURE AE
  case 0x92: return  0x00c6; //LATIN CAPITAL LIGATURE AE
  case 0x93: return  0x00f4; //LATIN SMALL LETTER O WITH CIRCUMFLEX
  case 0x94: return  0x00f6; //LATIN SMALL LETTER O WITH DIAERESIS
  case 0x95: return  0x00f2; //LATIN SMALL LETTER O WITH GRAVE
  case 0x96: return  0x00fb; //LATIN SMALL LETTER U WITH CIRCUMFLEX
  case 0x97: return  0x00f9; //LATIN SMALL LETTER U WITH GRAVE
  case 0x98: return  0x00ff; //LATIN SMALL LETTER Y WITH DIAERESIS
  case 0x99: return  0x00d6; //LATIN CAPITAL LETTER O WITH DIAERESIS
  case 0x9a: return  0x00dc; //LATIN CAPITAL LETTER U WITH DIAERESIS
  case 0x9b: return  0x00a2; //CENT SIGN
  case 0x9c: return  0x00a3; //POUND SIGN
  case 0x9d: return  0x00a5; //YEN SIGN
  case 0x9e: return  0x20a7; //PESETA SIGN
  case 0x9f: return  0x0192; //LATIN SMALL LETTER F WITH HOOK
  case 0xa0: return  0x00e1; //LATIN SMALL LETTER A WITH ACUTE
  case 0xa1: return  0x00ed; //LATIN SMALL LETTER I WITH ACUTE
  case 0xa2: return  0x00f3; //LATIN SMALL LETTER O WITH ACUTE
  case 0xa3: return  0x00fa; //LATIN SMALL LETTER U WITH ACUTE
  case 0xa4: return  0x00f1; //LATIN SMALL LETTER N WITH TILDE
  case 0xa5: return  0x00d1; //LATIN CAPITAL LETTER N WITH TILDE
  case 0xa6: return  0x00aa; //FEMININE ORDINAL INDICATOR
  case 0xa7: return  0x00ba; //MASCULINE ORDINAL INDICATOR
  case 0xa8: return  0x00bf; //INVERTED QUESTION MARK
  case 0xa9: return  0x2310; //REVERSED NOT SIGN
  case 0xaa: return  0x00ac; //NOT SIGN
  case 0xab: return  0x00bd; //VULGAR FRACTION ONE HALF
  case 0xac: return  0x00bc; //VULGAR FRACTION ONE QUARTER
  case 0xad: return  0x00a1; //INVERTED EXCLAMATION MARK
  case 0xae: return  0x00ab; //LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
  case 0xaf: return  0x00bb; //RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
  case 0xb0: return  0x2591; //LIGHT SHADE
  case 0xb1: return  0x2592; //MEDIUM SHADE
  case 0xb2: return  0x2593; //DARK SHADE
  case 0xb3: return  0x2502; //BOX DRAWINGS LIGHT VERTICAL
  case 0xb4: return  0x2524; //BOX DRAWINGS LIGHT VERTICAL AND LEFT
  case 0xb5: return  0x2561; //BOX DRAWINGS VERTICAL SINGLE AND LEFT DOUBLE
  case 0xb6: return  0x2562; //BOX DRAWINGS VERTICAL DOUBLE AND LEFT SINGLE
  case 0xb7: return  0x2556; //BOX DRAWINGS DOWN DOUBLE AND LEFT SINGLE
  case 0xb8: return  0x2555; //BOX DRAWINGS DOWN SINGLE AND LEFT DOUBLE
  case 0xb9: return  0x2563; //BOX DRAWINGS DOUBLE VERTICAL AND LEFT
  case 0xba: return  0x2551; //BOX DRAWINGS DOUBLE VERTICAL
  case 0xbb: return  0x2557; //BOX DRAWINGS DOUBLE DOWN AND LEFT
  case 0xbc: return  0x255d; //BOX DRAWINGS DOUBLE UP AND LEFT
  case 0xbd: return  0x255c; //BOX DRAWINGS UP DOUBLE AND LEFT SINGLE
  case 0xbe: return  0x255b; //BOX DRAWINGS UP SINGLE AND LEFT DOUBLE
  case 0xbf: return  0x2510; //BOX DRAWINGS LIGHT DOWN AND LEFT
  case 0xc0: return  0x2514; //BOX DRAWINGS LIGHT UP AND RIGHT
  case 0xc1: return  0x2534; //BOX DRAWINGS LIGHT UP AND HORIZONTAL
  case 0xc2: return  0x252c; //BOX DRAWINGS LIGHT DOWN AND HORIZONTAL
  case 0xc3: return  0x251c; //BOX DRAWINGS LIGHT VERTICAL AND RIGHT
  case 0xc4: return  0x2500; //BOX DRAWINGS LIGHT HORIZONTAL
  case 0xc5: return  0x253c; //BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL
  case 0xc6: return  0x255e; //BOX DRAWINGS VERTICAL SINGLE AND RIGHT DOUBLE
  case 0xc7: return  0x255f; //BOX DRAWINGS VERTICAL DOUBLE AND RIGHT SINGLE
  case 0xc8: return  0x255a; //BOX DRAWINGS DOUBLE UP AND RIGHT
  case 0xc9: return  0x2554; //BOX DRAWINGS DOUBLE DOWN AND RIGHT
  case 0xca: return  0x2569; //BOX DRAWINGS DOUBLE UP AND HORIZONTAL
  case 0xcb: return  0x2566; //BOX DRAWINGS DOUBLE DOWN AND HORIZONTAL
  case 0xcc: return  0x2560; //BOX DRAWINGS DOUBLE VERTICAL AND RIGHT
  case 0xcd: return  0x2550; //BOX DRAWINGS DOUBLE HORIZONTAL
  case 0xce: return  0x256c; //BOX DRAWINGS DOUBLE VERTICAL AND HORIZONTAL
  case 0xcf: return  0x2567; //BOX DRAWINGS UP SINGLE AND HORIZONTAL DOUBLE
  case 0xd0: return  0x2568; //BOX DRAWINGS UP DOUBLE AND HORIZONTAL SINGLE
  case 0xd1: return  0x2564; //BOX DRAWINGS DOWN SINGLE AND HORIZONTAL DOUBLE
  case 0xd2: return  0x2565; //BOX DRAWINGS DOWN DOUBLE AND HORIZONTAL SINGLE
  case 0xd3: return  0x2559; //BOX DRAWINGS UP DOUBLE AND RIGHT SINGLE
  case 0xd4: return  0x2558; //BOX DRAWINGS UP SINGLE AND RIGHT DOUBLE
  case 0xd5: return  0x2552; //BOX DRAWINGS DOWN SINGLE AND RIGHT DOUBLE
  case 0xd6: return  0x2553; //BOX DRAWINGS DOWN DOUBLE AND RIGHT SINGLE
  case 0xd7: return  0x256b; //BOX DRAWINGS VERTICAL DOUBLE AND HORIZONTAL SINGLE
  case 0xd8: return  0x256a; //BOX DRAWINGS VERTICAL SINGLE AND HORIZONTAL DOUBLE
  case 0xd9: return  0x2518; //BOX DRAWINGS LIGHT UP AND LEFT
  case 0xda: return  0x250c; //BOX DRAWINGS LIGHT DOWN AND RIGHT
  case 0xdb: return  0x2588; //FULL BLOCK
  case 0xdc: return  0x2584; //LOWER HALF BLOCK
  case 0xdd: return  0x258c; //LEFT HALF BLOCK
  case 0xde: return  0x2590; //RIGHT HALF BLOCK
  case 0xdf: return  0x2580; //UPPER HALF BLOCK
  case 0xe0: return  0x03b1; //GREEK SMALL LETTER ALPHA
  case 0xe1: return  0x00df; //LATIN SMALL LETTER SHARP S
  case 0xe2: return  0x0393; //GREEK CAPITAL LETTER GAMMA
  case 0xe3: return  0x03c0; //GREEK SMALL LETTER PI
  case 0xe4: return  0x03a3; //GREEK CAPITAL LETTER SIGMA
  case 0xe5: return  0x03c3; //GREEK SMALL LETTER SIGMA
  case 0xe6: return  0x00b5; //MICRO SIGN
  case 0xe7: return  0x03c4; //GREEK SMALL LETTER TAU
  case 0xe8: return  0x03a6; //GREEK CAPITAL LETTER PHI
  case 0xe9: return  0x0398; //GREEK CAPITAL LETTER THETA
  case 0xea: return  0x03a9; //GREEK CAPITAL LETTER OMEGA
  case 0xeb: return  0x03b4; //GREEK SMALL LETTER DELTA
  case 0xec: return  0x221e; //INFINITY
  case 0xed: return  0x03c6; //GREEK SMALL LETTER PHI
  case 0xee: return  0x03b5; //GREEK SMALL LETTER EPSILON
  case 0xef: return  0x2229; //INTERSECTION
  case 0xf0: return  0x2261; //IDENTICAL TO
  case 0xf1: return  0x00b1; //PLUS-MINUS SIGN
  case 0xf2: return  0x2265; //GREATER-THAN OR EQUAL TO
  case 0xf3: return  0x2264; //LESS-THAN OR EQUAL TO
  case 0xf4: return  0x2320; //TOP HALF INTEGRAL
  case 0xf5: return  0x2321; //BOTTOM HALF INTEGRAL
  case 0xf6: return  0x00f7; //DIVISION SIGN
  case 0xf7: return  0x2248; //ALMOST EQUAL TO
  case 0xf8: return  0x00b0; //DEGREE SIGN
  case 0xf9: return  0x2219; //BULLET OPERATOR
  case 0xfa: return  0x00b7; //MIDDLE DOT
  case 0xfb: return  0x221a; //SQUARE ROOT
  case 0xfc: return  0x207f; //SUPERSCRIPT LATIN SMALL LETTER N
  case 0xfd: return  0x00b2; //SUPERSCRIPT TWO
  case 0xfe: return  0x25a0; //BLACK SQUARE
  case 0xff: return  0x00a0; //NO-BREAK SPACE
  }
  return 0;
}

char32 CodePage28591Encoding::Decoder::GetCodePoint(byte b) {
  return b;
}

char32 CodePage28592Encoding::Decoder::GetCodePoint(byte b) {
  if (b < 0xA1) return b;
  switch (b) {
  case 0xA1: return  0x0104; // LATIN CAPITAL LETTER A WITH OGONEK
  case 0xA2: return  0x02D8; // BREVE
  case 0xA3: return  0x0141; // LATIN CAPITAL LETTER L WITH STROKE
  case 0xA4: return  0x00A4; // CURRENCY SIGN
  case 0xA5: return  0x013D; // LATIN CAPITAL LETTER L WITH CARON
  case 0xA6: return  0x015A; // LATIN CAPITAL LETTER S WITH ACUTE
  case 0xA7: return  0x00A7; // SECTION SIGN
  case 0xA8: return  0x00A8; // DIAERESIS
  case 0xA9: return  0x0160; // LATIN CAPITAL LETTER S WITH CARON
  case 0xAA: return  0x015E; // LATIN CAPITAL LETTER S WITH CEDILLA
  case 0xAB: return  0x0164; // LATIN CAPITAL LETTER T WITH CARON
  case 0xAC: return  0x0179; // LATIN CAPITAL LETTER Z WITH ACUTE
  case 0xAD: return  0x00AD; // SOFT HYPHEN
  case 0xAE: return  0x017D; // LATIN CAPITAL LETTER Z WITH CARON
  case 0xAF: return  0x017B; // LATIN CAPITAL LETTER Z WITH DOT ABOVE
  case 0xB0: return  0x00B0; // DEGREE SIGN
  case 0xB1: return  0x0105; // LATIN SMALL LETTER A WITH OGONEK
  case 0xB2: return  0x02DB; // OGONEK
  case 0xB3: return  0x0142; // LATIN SMALL LETTER L WITH STROKE
  case 0xB4: return  0x00B4; // ACUTE ACCENT
  case 0xB5: return  0x013E; // LATIN SMALL LETTER L WITH CARON
  case 0xB6: return  0x015B; // LATIN SMALL LETTER S WITH ACUTE
  case 0xB7: return  0x02C7; // CARON
  case 0xB8: return  0x00B8; // CEDILLA
  case 0xB9: return  0x0161; // LATIN SMALL LETTER S WITH CARON
  case 0xBA: return  0x015F; // LATIN SMALL LETTER S WITH CEDILLA
  case 0xBB: return  0x0165; // LATIN SMALL LETTER T WITH CARON
  case 0xBC: return  0x017A; // LATIN SMALL LETTER Z WITH ACUTE
  case 0xBD: return  0x02DD; // DOUBLE ACUTE ACCENT
  case 0xBE: return  0x017E; // LATIN SMALL LETTER Z WITH CARON
  case 0xBF: return  0x017C; // LATIN SMALL LETTER Z WITH DOT ABOVE
  case 0xC0: return  0x0154; // LATIN CAPITAL LETTER R WITH ACUTE
  case 0xC1: return  0x00C1; // LATIN CAPITAL LETTER A WITH ACUTE
  case 0xC2: return  0x00C2; // LATIN CAPITAL LETTER A WITH CIRCUMFLEX
  case 0xC3: return  0x0102; // LATIN CAPITAL LETTER A WITH BREVE
  case 0xC4: return  0x00C4; // LATIN CAPITAL LETTER A WITH DIAERESIS
  case 0xC5: return  0x0139; // LATIN CAPITAL LETTER L WITH ACUTE
  case 0xC6: return  0x0106; // LATIN CAPITAL LETTER C WITH ACUTE
  case 0xC7: return  0x00C7; // LATIN CAPITAL LETTER C WITH CEDILLA
  case 0xC8: return  0x010C; // LATIN CAPITAL LETTER C WITH CARON
  case 0xC9: return  0x00C9; // LATIN CAPITAL LETTER E WITH ACUTE
  case 0xCA: return  0x0118; // LATIN CAPITAL LETTER E WITH OGONEK
  case 0xCB: return  0x00CB; // LATIN CAPITAL LETTER E WITH DIAERESIS
  case 0xCC: return  0x011A; // LATIN CAPITAL LETTER E WITH CARON
  case 0xCD: return  0x00CD; // LATIN CAPITAL LETTER I WITH ACUTE
  case 0xCE: return  0x00CE; // LATIN CAPITAL LETTER I WITH CIRCUMFLEX
  case 0xCF: return  0x010E; // LATIN CAPITAL LETTER D WITH CARON
  case 0xD0: return  0x0110; // LATIN CAPITAL LETTER D WITH STROKE
  case 0xD1: return  0x0143; // LATIN CAPITAL LETTER N WITH ACUTE
  case 0xD2: return  0x0147; // LATIN CAPITAL LETTER N WITH CARON
  case 0xD3: return  0x00D3; // LATIN CAPITAL LETTER O WITH ACUTE
  case 0xD4: return  0x00D4; // LATIN CAPITAL LETTER O WITH CIRCUMFLEX
  case 0xD5: return  0x0150; // LATIN CAPITAL LETTER O WITH DOUBLE ACUTE
  case 0xD6: return  0x00D6; // LATIN CAPITAL LETTER O WITH DIAERESIS
  case 0xD7: return  0x00D7; // MULTIPLICATION SIGN
  case 0xD8: return  0x0158; // LATIN CAPITAL LETTER R WITH CARON
  case 0xD9: return  0x016E; // LATIN CAPITAL LETTER U WITH RING ABOVE
  case 0xDA: return  0x00DA; // LATIN CAPITAL LETTER U WITH ACUTE
  case 0xDB: return  0x0170; // LATIN CAPITAL LETTER U WITH DOUBLE ACUTE
  case 0xDC: return  0x00DC; // LATIN CAPITAL LETTER U WITH DIAERESIS
  case 0xDD: return  0x00DD; // LATIN CAPITAL LETTER Y WITH ACUTE
  case 0xDE: return  0x0162; // LATIN CAPITAL LETTER T WITH CEDILLA
  case 0xDF: return  0x00DF; // LATIN SMALL LETTER SHARP S
  case 0xE0: return  0x0155; // LATIN SMALL LETTER R WITH ACUTE
  case 0xE1: return  0x00E1; // LATIN SMALL LETTER A WITH ACUTE
  case 0xE2: return  0x00E2; // LATIN SMALL LETTER A WITH CIRCUMFLEX
  case 0xE3: return  0x0103; // LATIN SMALL LETTER A WITH BREVE
  case 0xE4: return  0x00E4; // LATIN SMALL LETTER A WITH DIAERESIS
  case 0xE5: return  0x013A; // LATIN SMALL LETTER L WITH ACUTE
  case 0xE6: return  0x0107; // LATIN SMALL LETTER C WITH ACUTE
  case 0xE7: return  0x00E7; // LATIN SMALL LETTER C WITH CEDILLA
  case 0xE8: return  0x010D; // LATIN SMALL LETTER C WITH CARON
  case 0xE9: return  0x00E9; // LATIN SMALL LETTER E WITH ACUTE
  case 0xEA: return  0x0119; // LATIN SMALL LETTER E WITH OGONEK
  case 0xEB: return  0x00EB; // LATIN SMALL LETTER E WITH DIAERESIS
  case 0xEC: return  0x011B; // LATIN SMALL LETTER E WITH CARON
  case 0xED: return  0x00ED; // LATIN SMALL LETTER I WITH ACUTE
  case 0xEE: return  0x00EE; // LATIN SMALL LETTER I WITH CIRCUMFLEX
  case 0xEF: return  0x010F; // LATIN SMALL LETTER D WITH CARON
  case 0xF0: return  0x0111; // LATIN SMALL LETTER D WITH STROKE
  case 0xF1: return  0x0144; // LATIN SMALL LETTER N WITH ACUTE
  case 0xF2: return  0x0148; // LATIN SMALL LETTER N WITH CARON
  case 0xF3: return  0x00F3; // LATIN SMALL LETTER O WITH ACUTE
  case 0xF4: return  0x00F4; // LATIN SMALL LETTER O WITH CIRCUMFLEX
  case 0xF5: return  0x0151; // LATIN SMALL LETTER O WITH DOUBLE ACUTE
  case 0xF6: return  0x00F6; // LATIN SMALL LETTER O WITH DIAERESIS
  case 0xF7: return  0x00F7; // DIVISION SIGN
  case 0xF8: return  0x0159; // LATIN SMALL LETTER R WITH CARON
  case 0xF9: return  0x016F; // LATIN SMALL LETTER U WITH RING ABOVE
  case 0xFA: return  0x00FA; // LATIN SMALL LETTER U WITH ACUTE
  case 0xFB: return  0x0171; // LATIN SMALL LETTER U WITH DOUBLE ACUTE
  case 0xFC: return  0x00FC; // LATIN SMALL LETTER U WITH DIAERESIS
  case 0xFD: return  0x00FD; // LATIN SMALL LETTER Y WITH ACUTE
  case 0xFE: return  0x0163; // LATIN SMALL LETTER T WITH CEDILLA
  case 0xFF: return  0x02D9; // DOT ABOVE
  }
  return 0;
}


