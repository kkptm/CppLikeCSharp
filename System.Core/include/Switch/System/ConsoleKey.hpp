/// @file
/// @brief Contains Switch::System::ConsoleKey enum.
#pragma once

#include "../Types.hpp"
#include "Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @enum ConsoleKey
    /// @brief Specifies the standard keys on a console.
    /// @see Console
    enum class ConsoleKey {
      /// @brief The BACKSPACE key.
      Backspace = 8,
      /// @brief The TAB key.
      Tab = 9,
      /// @brief The CLEAR key.
      Clear = 12,
      /// @brief The ENTER key.
      Enter = 13,
      /// @brief The PAUSE key.
      Pause = 19,
      /// @brief The CapsLock key.
      CapsLock = 20,
      /// @brief The ESC (ESCAPE) key.
      Escape = 27,
      /// @brief The SPACEBAR key.
      Spacebar = 32,
      /// @brief The PAGE UP key.
      PageUp = 33,
      /// @brief The PAGE DOWN key.
      PageDown = 34,
      /// @brief The END key.
      End = 35,
      /// @brief The HOME key.
      Home = 36,
      /// @brief The LEFT ARROW key.
      LeftArrow = 37,
      /// @brief The UP ARROW key.
      UpArrow = 38,
      /// @brief The RIGHT ARROW key.
      RightArrow = 39,
      /// @brief The DOWN ARROW key.
      DownArrow = 40,
      /// @brief The SELECT key.
      Select = 41,
      /// @brief The PRINT key.
      Print = 42,
      /// @brief The EXECUTE key.
      Execute = 43,
      /// @brief The PRINT SCREEN key.
      PrintScreen = 44,
      /// @brief The INS (INSERT) key.
      Insert = 45,
      /// @brief The DEL (DELETE) key.
      Delete = 46,
      /// @brief The HELP key.
      Help = 47,
      /// @brief The 0 key.
      D0 = 48,
      /// @brief The 1 key.
      D1 = 49,
      /// @brief The 2 key.
      D2 = 50,
      /// @brief The 3 key.
      D3 = 51,
      /// @brief The 4 key.
      D4 = 52,
      /// @brief The 5 key.
      D5 = 53,
      /// @brief The 6 key.
      D6 = 54,
      /// @brief The 7 key.
      D7 = 55,
      /// @brief The 8 key.
      D8 = 56,
      /// @brief The 9 key.
      D9 = 57,
      /// @brief The A key.
      A = 65,
      /// @brief The B key.
      B = 66,
      /// @brief The C key.
      C = 67,
      /// @brief The D key.
      D = 68,
      /// @brief The E key.
      E = 69,
      /// @brief The F key.
      F = 70,
      /// @brief The G key.
      G = 71,
      /// @brief The H key.
      H = 72,
      /// @brief The I key.
      I = 73,
      /// @brief The J key.
      J = 74,
      /// @brief The K key.
      K = 75,
      /// @brief The L key.
      L = 76,
      /// @brief The M key.
      M = 77,
      /// @brief The N key.
      N = 78,
      /// @brief The O key.
      O = 79,
      /// @brief The P key.
      P = 80,
      /// @brief The Q key.
      Q = 81,
      /// @brief The R key.
      R = 82,
      /// @brief The S key.
      S = 83,
      /// @brief The T key.
      T = 84,
      /// @brief The U key.
      U = 85,
      /// @brief The V key.
      V = 86,
      /// @brief The W key.
      W = 87,
      /// @brief The X key.
      X = 88,
      /// @brief The Y key.
      Y = 89,
      /// @brief The Z key.
      Z = 90,
      /// @brief The left Windows logo key (Microsoft Natural Keyboard).
      LeftWindows = 91,
      /// @brief The right Windows logo key (Microsoft Natural Keyboard).
      RightWindows = 92,
      /// @brief The Application key (Microsoft Natural Keyboard).
      Applications = 93,
      /// @brief The Computer Sleep key.
      Sleep = 95,
      /// @brief The 0 key on the numeric keypad.
      NumPad0 = 96,
      /// @brief The 1 key on the numeric keypad.
      NumPad1 = 97,
      /// @brief The 2 key on the numeric keypad.
      NumPad2 = 98,
      /// @brief The 3 key on the numeric keypad.
      NumPad3 = 99,
      /// @brief The 4 key on the numeric keypad.
      NumPad4 = 100,
      /// @brief The 5 key on the numeric keypad.
      NumPad5 = 101,
      /// @brief The 6 key on the numeric keypad.
      NumPad6 = 102,
      /// @brief The 7 key on the numeric keypad.
      NumPad7 = 103,
      /// @brief The 8 key on the numeric keypad.
      NumPad8 = 104,
      /// @brief The 9 key on the numeric keypad.
      NumPad9 = 105,
      /// @brief The Multiply key.
      Multiply = 106,
      /// @brief The Add key.
      Add = 107,
      /// @brief The Separator key.
      Separator = 108,
      /// @brief The Subtract key.
      Subtract = 109,
      /// @brief The Decimal key.
      Decimal = 110,
      /// @brief The Divide key.
      Divide = 111,
      /// @brief The F1 key.
      F1 = 112,
      /// @brief The F2 key.
      F2 = 113,
      /// @brief The F3 key.
      F3 = 114,
      /// @brief The F4 key.
      F4 = 115,
      /// @brief The F5 key.
      F5 = 116,
      /// @brief The F6 key.
      F6 = 117,
      /// @brief The F7 key.
      F7 = 118,
      /// @brief The F8 key.
      F8 = 119,
      /// @brief The F9 key.
      F9 = 120,
      /// @brief The F10 key.
      F10 = 121,
      /// @brief The F11 key.
      F11 = 122,
      /// @brief The F12 key.
      F12 = 123,
      /// @brief The F13 key.
      F13 = 124,
      /// @brief The F14 key.
      F14 = 125,
      /// @brief The F15 key.
      F15 = 126,
      /// @brief The F16 key.
      F16 = 127,
      /// @brief The F17 key.
      F17 = 128,
      /// @brief The F18 key.
      F18 = 129,
      /// @brief The F19 key.
      F19 = 130,
      /// @brief The F20 key.
      F20 = 131,
      /// @brief The F21 key.
      F21 = 132,
      /// @brief The F22 key.
      F22 = 133,
      /// @brief The F23 key.
      F23 = 134,
      /// @brief The F24 key.
      F24 = 135,
      /// @brief The Browser Back key (Windows 2000 or later).
      BrowserBack = 166,
      /// @brief The Browser Forward key (Windows 2000 or later).
      BrowserForward = 167,
      /// @brief The Browser Refresh key (Windows 2000 or later).
      BrowserRefresh = 168,
      /// @brief The Browser Stop key (Windows 2000 or later).
      BrowserStop = 169,
      /// @brief The Browser Search key (Windows 2000 or later).
      BrowserSearch = 170,
      /// @brief The Browser Favorite key (Windows 2000 or later).
      BrowserFavorites = 171,
      /// @brief The Browser Home key (Windows 2000 or later).
      BrowserHome = 172,
      /// @brief The Volume Mute key (Microsoft Natural Keyboard, Windows 2000 or later).
      VolumeMute = 173,
      /// @brief The Volume Down key (Microsoft Natural Keyboard, Windows 2000 or later).
      VolumeDown = 174,
      /// @brief The Volume Up key (Microsoft Natural Keyboard, Windows 2000 or later).
      VolumeUp = 175,
      /// @brief The Media Next Track key (Microsoft Natural Keyboard, Windows 2000 or later).
      MediaNext = 176,
      /// @brief The Media Previous Track key (Microsoft Natural Keyboard, Windows 2000 or later).
      MediaPrevious = 177,
      /// @brief The Media Stop key (Microsoft Natural Keyboard, Windows 2000 or later).
      MediaStop = 178,
      /// @brief The Media Play/Pause key (Microsoft Natural Keyboard, Windows 2000 or later).
      MediaPlay = 179,
      /// @brief The Start Mail key (Microsoft Natural Keyboard, Windows 2000 or later).
      LaunchMail = 180,
      /// @brief The Select Media key (Microsoft Natural Keyboard, Windows 2000 or later).
      LaunchMediaSelect = 181,
      /// @brief The Start Application 1 key (Microsoft Natural Keyboard, Windows 2000 or later).
      LaunchApp1 = 182,
      /// @brief The Start Application 2 key (Microsoft Natural Keyboard, Windows 2000 or later).
      LaunchApp2 = 183,
      /// @brief The OEM 1 key (OEM specific).
      Oem1 = 186,
      /// @brief The OEM Plus key on any country/region keyboard (Windows 2000 or later).
      OemPlus = 187,
      /// @brief The OEM Comma key on any country/region keyboard (Windows 2000 or later).
      OemComma = 188,
      /// @brief The OEM Minus key on any country/region keyboard (Windows 2000 or later).
      OemMinus = 189,
      /// @brief The OEM Period key on any country/region keyboard (Windows 2000 or later).
      OemPeriod = 190,
      /// @brief The OEM 2 key (OEM specific).
      Oem2 = 191,
      /// @brief The OEM " key (OEM specific).
      Oem3 = 192,
      /// @brief The OEM 4 key (OEM specific).
      Oem4 = 219,
      /// @brief The OEM 5 key (OEM specific).
      Oem5 = 220,
      /// @brief The OEM 6 key (OEM specific).
      Oem6 = 221,
      /// @brief The OEM 7 key (OEM specific).
      Oem7 = 222,
      /// @brief The OEM 8 key (OEM specific).
      Oem8 = 223,
      /// @brief The OEM 102 key (OEM specific).
      Oem102 = 226,
      /// @brief The IME PROCESS key.
      Process = 229,
      /// @brief The PACKET key (used to pass Unicode characters with keystrokes).
      Packet = 231,
      /// @brief The ATTN key.
      Attention = 246,
      /// @brief The CRSEL (CURSOR SELECT) key.
      CrSel = 247,
      /// @brief The EXSEL (EXTEND SELECTION) key.
      ExSel = 248,
      /// @brief The ERASE EOF key.
      EraseEndOfFile = 249,
      /// @brief The Play key.
      Play = 250,
      /// @brief The ZOOM key.
      Zoom = 251,
      /// @brief A constant reserved for future use.
      NoName = 252,
      /// @brief The PA1 key.
      Pa1 = 253,
      /// @brief The CLEAR key (OEM specific).
      OemClear = 254
    };
  }
}

/// @cond
template<>
struct EnumRegister<System::ConsoleKey> {
  void operator()(System::Collections::Generic::IDictionary<System::ConsoleKey, string>& values, bool& flags) {
    values[System::ConsoleKey::Backspace] = "Backspace";
    values[System::ConsoleKey::Tab] = "Tab";
    values[System::ConsoleKey::Clear] = "Clear";
    values[System::ConsoleKey::Enter] = "Enter";
    values[System::ConsoleKey::Pause] = "Pause";
    values[System::ConsoleKey::CapsLock] = "CapsLock";
    values[System::ConsoleKey::Escape] = "Escape";
    values[System::ConsoleKey::Spacebar] = "Spacebar";
    values[System::ConsoleKey::PageUp] = "PageUp";
    values[System::ConsoleKey::PageDown] = "PageDown";
    values[System::ConsoleKey::End] = "End";
    values[System::ConsoleKey::Home] = "Home";
    values[System::ConsoleKey::LeftArrow] = "LeftArrow";
    values[System::ConsoleKey::UpArrow] = "UpArrow";
    values[System::ConsoleKey::RightArrow] = "RightArrow";
    values[System::ConsoleKey::DownArrow] = "DownArrow";
    values[System::ConsoleKey::Select] = "Select";
    values[System::ConsoleKey::Print] = "Print";
    values[System::ConsoleKey::Execute] = "Execute";
    values[System::ConsoleKey::PrintScreen] = "PrintScreen";
    values[System::ConsoleKey::Insert] = "Insert";
    values[System::ConsoleKey::Delete] = "Delete";
    values[System::ConsoleKey::Help] = "Help";
    values[System::ConsoleKey::D0] = "D0";
    values[System::ConsoleKey::D1] = "D1";
    values[System::ConsoleKey::D2] = "D2";
    values[System::ConsoleKey::D3] = "D3";
    values[System::ConsoleKey::D4] = "D4";
    values[System::ConsoleKey::D5] = "D5";
    values[System::ConsoleKey::D6] = "D6";
    values[System::ConsoleKey::D7] = "D7";
    values[System::ConsoleKey::D8] = "D8";
    values[System::ConsoleKey::D9] = "D9";
    values[System::ConsoleKey::A] = "A";
    values[System::ConsoleKey::B] = "B";
    values[System::ConsoleKey::C] = "C";
    values[System::ConsoleKey::D] = "D";
    values[System::ConsoleKey::E] = "E";
    values[System::ConsoleKey::F] = "F";
    values[System::ConsoleKey::G] = "G";
    values[System::ConsoleKey::H] = "H";
    values[System::ConsoleKey::I] = "I";
    values[System::ConsoleKey::J] = "J";
    values[System::ConsoleKey::K] = "K";
    values[System::ConsoleKey::L] = "L";
    values[System::ConsoleKey::M] = "M";
    values[System::ConsoleKey::N] = "N";
    values[System::ConsoleKey::O] = "O";
    values[System::ConsoleKey::P] = "P";
    values[System::ConsoleKey::Q] = "Q";
    values[System::ConsoleKey::R] = "R";
    values[System::ConsoleKey::S] = "S";
    values[System::ConsoleKey::T] = "T";
    values[System::ConsoleKey::U] = "U";
    values[System::ConsoleKey::V] = "V";
    values[System::ConsoleKey::W] = "W";
    values[System::ConsoleKey::X] = "X";
    values[System::ConsoleKey::Y] = "Y";
    values[System::ConsoleKey::Z] = "Z";
    values[System::ConsoleKey::LeftWindows] = "LeftWindows";
    values[System::ConsoleKey::RightWindows] = "RightWindows";
    values[System::ConsoleKey::Applications] = "Applications";
    values[System::ConsoleKey::Sleep] = "Sleep";
    values[System::ConsoleKey::NumPad0] = "NumPad0";
    values[System::ConsoleKey::NumPad1] = "NumPad1";
    values[System::ConsoleKey::NumPad2] = "NumPad2";
    values[System::ConsoleKey::NumPad3] = "NumPad3";
    values[System::ConsoleKey::NumPad4] = "NumPad4";
    values[System::ConsoleKey::NumPad5] = "NumPad5";
    values[System::ConsoleKey::NumPad6] = "NumPad6";
    values[System::ConsoleKey::NumPad7] = "NumPad7";
    values[System::ConsoleKey::NumPad8] = "NumPad8";
    values[System::ConsoleKey::NumPad9] = "NumPad9";
    values[System::ConsoleKey::Multiply] = "Multiply";
    values[System::ConsoleKey::Add] = "Add";
    values[System::ConsoleKey::Separator] = "Separator";
    values[System::ConsoleKey::Subtract] = "Subtract";
    values[System::ConsoleKey::Decimal] = "Decimal";
    values[System::ConsoleKey::Divide] = "Divide";
    values[System::ConsoleKey::F1] = "F1";
    values[System::ConsoleKey::F2] = "F2";
    values[System::ConsoleKey::F3] = "F3";
    values[System::ConsoleKey::F4] = "F4";
    values[System::ConsoleKey::F5] = "F5";
    values[System::ConsoleKey::F6] = "F6";
    values[System::ConsoleKey::F7] = "F7";
    values[System::ConsoleKey::F8] = "F8";
    values[System::ConsoleKey::F9] = "F9";
    values[System::ConsoleKey::F10] = "F10";
    values[System::ConsoleKey::F11] = "F11";
    values[System::ConsoleKey::F12] = "F12";
    values[System::ConsoleKey::F13] = "F13";
    values[System::ConsoleKey::F14] = "F14";
    values[System::ConsoleKey::F15] = "F15";
    values[System::ConsoleKey::F16] = "F16";
    values[System::ConsoleKey::F17] = "F17";
    values[System::ConsoleKey::F18] = "F18";
    values[System::ConsoleKey::F19] = "F19";
    values[System::ConsoleKey::F20] = "F20";
    values[System::ConsoleKey::F21] = "F21";
    values[System::ConsoleKey::F22] = "F22";
    values[System::ConsoleKey::F23] = "F23";
    values[System::ConsoleKey::F24] = "F24";
    values[System::ConsoleKey::BrowserBack] = "BrowserBack";
    values[System::ConsoleKey::BrowserForward] = "BrowserForward";
    values[System::ConsoleKey::BrowserRefresh] = "BrowserRefresh";
    values[System::ConsoleKey::BrowserStop] = "BrowserStop";
    values[System::ConsoleKey::BrowserSearch] = "BrowserSearch";
    values[System::ConsoleKey::BrowserFavorites] = "BrowserFavorite";
    values[System::ConsoleKey::BrowserHome] = "BrowserHome";
    values[System::ConsoleKey::VolumeMute] = "VolumeMute";
    values[System::ConsoleKey::VolumeDown] = "VolumeDown";
    values[System::ConsoleKey::VolumeUp] = "VolumeUp";
    values[System::ConsoleKey::MediaNext] = "MediaNext";
    values[System::ConsoleKey::MediaPrevious] = "MediaPrevious";
    values[System::ConsoleKey::MediaStop] = "MediaStop";
    values[System::ConsoleKey::MediaPlay] = "MediaPlay";
    values[System::ConsoleKey::LaunchMail] = "LaunchMail";
    values[System::ConsoleKey::LaunchMediaSelect] = "LaunchMediaSelect";
    values[System::ConsoleKey::LaunchApp1] = "LaunchApp1";
    values[System::ConsoleKey::LaunchApp2] = "LaunchApp2";
    values[System::ConsoleKey::Oem1] = "Oem1";
    values[System::ConsoleKey::OemPlus] = "OemPlus";
    values[System::ConsoleKey::OemComma] = "OemComma";
    values[System::ConsoleKey::OemMinus] = "OemMinus";
    values[System::ConsoleKey::OemPeriod] = "OemPeriod";
    values[System::ConsoleKey::Oem2] = "Oem2";
    values[System::ConsoleKey::Oem3] = "Oem3";
    values[System::ConsoleKey::Oem4] = "Oem4";
    values[System::ConsoleKey::Oem5] = "Oem5";
    values[System::ConsoleKey::Oem6] = "Oem6";
    values[System::ConsoleKey::Oem7] = "Oem7";
    values[System::ConsoleKey::Oem8] = "Oem8";
    values[System::ConsoleKey::Oem102] = "Oem102";
    values[System::ConsoleKey::Process] = "Process";
    values[System::ConsoleKey::Packet] = "Packet";
    values[System::ConsoleKey::Attention] = "Attention";
    values[System::ConsoleKey::CrSel] = "CrSel";
    values[System::ConsoleKey::ExSel] = "ExSel";
    values[System::ConsoleKey::EraseEndOfFile] = "EraseEndOfFile";
    values[System::ConsoleKey::Play] = "Play";
    values[System::ConsoleKey::Zoom] = "Zoom";
    values[System::ConsoleKey::NoName] = "NoName";
    values[System::ConsoleKey::Pa1] = "Pa1";
    values[System::ConsoleKey::OemClear] = "OemClear";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
