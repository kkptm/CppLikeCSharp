/// @file
/// @brief Contains Switch::System::Windows::Forms::Shortcut enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies shortcut keys that can be used by menu items.
        enum class Shortcut {
          Alt0 = 262192,
          Alt1,
          Alt2,
          Alt3,
          Alt4,
          Alt5,
          Alt6,
          Alt7,
          Alt8,
          Alt9,
          AltBksp = 262152,
          AltDownArrow = 262184,
          AltF1 = 262256,
          AltF10 = 262265,
          AltF11,
          AltF12,
          AltF2 = 262257,
          AltF3,
          AltF4,
          AltF5,
          AltF6,
          AltF7,
          AltF8,
          AltF9,
          AltLeftArrow = 262181,
          AltRightArrow = 262183,
          AltUpArrow = 262182,
          Cmd0 = 131120,
          Cmd1,
          Cmd2,
          Cmd3,
          Cmd4,
          Cmd5,
          Cmd6,
          Cmd7,
          Cmd8,
          Cmd9,
          CmdA = 131137,
          CmdB,
          CmdC,
          CmdD,
          CmdDel = 131118,
          CmdE = 131141,
          CmdF,
          CmdF1 = 131184,
          CmdF10 = 131193,
          CmdF11,
          CmdF12,
          CmdF2 = 131185,
          CmdF3,
          CmdF4,
          CmdF5,
          CmdF6,
          CmdF7,
          CmdF8,
          CmdF9,
          CmdG = 131143,
          CmdH,
          CmdI,
          CmdIns = 131117,
          CmdJ = 131146,
          CmdK,
          CmdL,
          CmdM,
          CmdN,
          CmdO,
          CmdP,
          CmdQ,
          CmdR,
          CmdS,
          CmdShift0 = 196656,
          CmdShift1,
          CmdShift2,
          CmdShift3,
          CmdShift4,
          CmdShift5,
          CmdShift6,
          CmdShift7,
          CmdShift8,
          CmdShift9,
          CmdShiftA = 196673,
          CmdShiftB,
          CmdShiftC,
          CmdShiftD,
          CmdShiftE,
          CmdShiftF,
          CmdShiftF1 = 196720,
          CmdShiftF10 = 196729,
          CmdShiftF11,
          CmdShiftF12,
          CmdShiftF2 = 196721,
          CmdShiftF3,
          CmdShiftF4,
          CmdShiftF5,
          CmdShiftF6,
          CmdShiftF7,
          CmdShiftF8,
          CmdShiftF9,
          CmdShiftG = 196679,
          CmdShiftH,
          CmdShiftI,
          CmdShiftJ,
          CmdShiftK,
          CmdShiftL,
          CmdShiftM,
          CmdShiftN,
          CmdShiftO,
          CmdShiftP,
          CmdShiftQ,
          CmdShiftR,
          CmdShiftS,
          CmdShiftT,
          CmdShiftU,
          CmdShiftV,
          CmdShiftW,
          CmdShiftX,
          CmdShiftY,
          CmdShiftZ,
          CmdT = 131156,
          CmdU,
          CmdV,
          CmdW,
          CmdX,
          CmdY,
          CmdZ,
          Del = 46,
          F1 = 112,
          F10 = 121,
          F11,
          F12,
          F2 = 113,
          F3,
          F4,
          F5,
          F6,
          F7,
          F8,
          F9,
          Ins = 45,
          None = 0,
          ShiftDel = 65582,
          ShiftF1 = 65648,
          ShiftF10 = 65657,
          ShiftF11,
          ShiftF12,
          ShiftF2 = 65649,
          ShiftF3,
          ShiftF4,
          ShiftF5,
          ShiftF6,
          ShiftF7,
          ShiftF8,
          ShiftF9,
          ShiftIns = 65581
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::Shortcut> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::Shortcut, string>& values, bool& flags) {
    values[System::Windows::Forms::Shortcut::Alt0] = "Alt0";
    values[System::Windows::Forms::Shortcut::Alt1] = "Alt1";
    values[System::Windows::Forms::Shortcut::Alt2] = "Alt2";
    values[System::Windows::Forms::Shortcut::Alt3] = "Alt3";
    values[System::Windows::Forms::Shortcut::Alt4] = "Alt4";
    values[System::Windows::Forms::Shortcut::Alt5] = "Alt5";
    values[System::Windows::Forms::Shortcut::Alt6] = "Alt6";
    values[System::Windows::Forms::Shortcut::Alt7] = "Alt7";
    values[System::Windows::Forms::Shortcut::Alt8] = "Alt8";
    values[System::Windows::Forms::Shortcut::Alt9] = "Alt9";
    values[System::Windows::Forms::Shortcut::AltBksp] = "AltBksp";
    values[System::Windows::Forms::Shortcut::AltDownArrow] = "AltDownArrow";
    values[System::Windows::Forms::Shortcut::AltF1] = "AltF1";
    values[System::Windows::Forms::Shortcut::AltF10] = "AltF10";
    values[System::Windows::Forms::Shortcut::AltF11] = "AltF11";
    values[System::Windows::Forms::Shortcut::AltF12] = "AltF12";
    values[System::Windows::Forms::Shortcut::AltF2] = "AltF2";
    values[System::Windows::Forms::Shortcut::AltF3] = "AltF3";
    values[System::Windows::Forms::Shortcut::AltF4] = "AltF4";
    values[System::Windows::Forms::Shortcut::AltF5] = "AltF5";
    values[System::Windows::Forms::Shortcut::AltF6] = "AltF6";
    values[System::Windows::Forms::Shortcut::AltF7] = "AltF7";
    values[System::Windows::Forms::Shortcut::AltF8] = "AltF8";
    values[System::Windows::Forms::Shortcut::AltF9] = "AltF9";
    values[System::Windows::Forms::Shortcut::AltLeftArrow] = "AltLeftArrow";
    values[System::Windows::Forms::Shortcut::AltRightArrow] = "AltRightArrow";
    values[System::Windows::Forms::Shortcut::AltUpArrow] = "AltUpArrow";
    values[System::Windows::Forms::Shortcut::Cmd0] = "Cmd0";
    values[System::Windows::Forms::Shortcut::Cmd1] = "Cmd1";
    values[System::Windows::Forms::Shortcut::Cmd2] = "Cmd2";
    values[System::Windows::Forms::Shortcut::Cmd3] = "Cmd3";
    values[System::Windows::Forms::Shortcut::Cmd4] = "Cmd4";
    values[System::Windows::Forms::Shortcut::Cmd5] = "Cmd5";
    values[System::Windows::Forms::Shortcut::Cmd6] = "Cmd6";
    values[System::Windows::Forms::Shortcut::Cmd7] = "Cmd7";
    values[System::Windows::Forms::Shortcut::Cmd8] = "Cmd8";
    values[System::Windows::Forms::Shortcut::Cmd9] = "Cmd9";
    values[System::Windows::Forms::Shortcut::CmdA] = "CmdA";
    values[System::Windows::Forms::Shortcut::CmdB] = "CmdB";
    values[System::Windows::Forms::Shortcut::CmdC] = "CmdC";
    values[System::Windows::Forms::Shortcut::CmdD] = "CmdD";
    values[System::Windows::Forms::Shortcut::CmdDel] = "CmdDel";
    values[System::Windows::Forms::Shortcut::CmdE] = "CmdE";
    values[System::Windows::Forms::Shortcut::CmdF] = "CmdF";
    values[System::Windows::Forms::Shortcut::CmdF1] = "CmdF1";
    values[System::Windows::Forms::Shortcut::CmdF10] = "CmdF10";
    values[System::Windows::Forms::Shortcut::CmdF11] = "CmdF11";
    values[System::Windows::Forms::Shortcut::CmdF12] = "CmdF12";
    values[System::Windows::Forms::Shortcut::CmdF2] = "CmdF2";
    values[System::Windows::Forms::Shortcut::CmdF3] = "CmdF3";
    values[System::Windows::Forms::Shortcut::CmdF4] = "CmdF4";
    values[System::Windows::Forms::Shortcut::CmdF5] = "CmdF5";
    values[System::Windows::Forms::Shortcut::CmdF6] = "CmdF6";
    values[System::Windows::Forms::Shortcut::CmdF7] = "CmdF7";
    values[System::Windows::Forms::Shortcut::CmdF8] = "CmdF8";
    values[System::Windows::Forms::Shortcut::CmdF9] = "CmdF9";
    values[System::Windows::Forms::Shortcut::CmdG] = "CmdG";
    values[System::Windows::Forms::Shortcut::CmdH] = "CmdH";
    values[System::Windows::Forms::Shortcut::CmdI] = "CmdI";
    values[System::Windows::Forms::Shortcut::CmdIns] = "CmdIns";
    values[System::Windows::Forms::Shortcut::CmdJ] = "CmdJ";
    values[System::Windows::Forms::Shortcut::CmdK] = "CmdK";
    values[System::Windows::Forms::Shortcut::CmdL] = "CmdL";
    values[System::Windows::Forms::Shortcut::CmdM] = "CmdM";
    values[System::Windows::Forms::Shortcut::CmdN] = "CmdN";
    values[System::Windows::Forms::Shortcut::CmdO] = "CmdO";
    values[System::Windows::Forms::Shortcut::CmdP] = "CmdP";
    values[System::Windows::Forms::Shortcut::CmdQ] = "CmdQ";
    values[System::Windows::Forms::Shortcut::CmdR] = "CmdR";
    values[System::Windows::Forms::Shortcut::CmdS] = "CmdS";
    values[System::Windows::Forms::Shortcut::CmdShift0] = "CmdShift0";
    values[System::Windows::Forms::Shortcut::CmdShift1] = "CmdShift1";
    values[System::Windows::Forms::Shortcut::CmdShift2] = "CmdShift2";
    values[System::Windows::Forms::Shortcut::CmdShift3] = "CmdShift3";
    values[System::Windows::Forms::Shortcut::CmdShift4] = "CmdShift4";
    values[System::Windows::Forms::Shortcut::CmdShift5] = "CmdShift5";
    values[System::Windows::Forms::Shortcut::CmdShift6] = "CmdShift6";
    values[System::Windows::Forms::Shortcut::CmdShift7] = "CmdShift7";
    values[System::Windows::Forms::Shortcut::CmdShift8] = "CmdShift8";
    values[System::Windows::Forms::Shortcut::CmdShift9] = "CmdShift9";
    values[System::Windows::Forms::Shortcut::CmdShiftA] = "CmdShiftA";
    values[System::Windows::Forms::Shortcut::CmdShiftB] = "CmdShiftB";
    values[System::Windows::Forms::Shortcut::CmdShiftC] = "CmdShiftC";
    values[System::Windows::Forms::Shortcut::CmdShiftD] = "CmdShiftD";
    values[System::Windows::Forms::Shortcut::CmdShiftE] = "CmdShiftE";
    values[System::Windows::Forms::Shortcut::CmdShiftF] = "CmdShiftF";
    values[System::Windows::Forms::Shortcut::CmdShiftF1] = "CmdShiftF1";
    values[System::Windows::Forms::Shortcut::CmdShiftF10] = "CmdShiftF10";
    values[System::Windows::Forms::Shortcut::CmdShiftF11] = "CmdShiftF11";
    values[System::Windows::Forms::Shortcut::CmdShiftF12] = "CmdShiftF12";
    values[System::Windows::Forms::Shortcut::CmdShiftF2] = "CmdShiftF2";
    values[System::Windows::Forms::Shortcut::CmdShiftF3] = "CmdShiftF3";
    values[System::Windows::Forms::Shortcut::CmdShiftF4] = "CmdShiftF4";
    values[System::Windows::Forms::Shortcut::CmdShiftF5] = "CmdShiftF5";
    values[System::Windows::Forms::Shortcut::CmdShiftF6] = "CmdShiftF6";
    values[System::Windows::Forms::Shortcut::CmdShiftF7] = "CmdShiftF7";
    values[System::Windows::Forms::Shortcut::CmdShiftF8] = "CmdShiftF8";
    values[System::Windows::Forms::Shortcut::CmdShiftF9] = "CmdShiftF9";
    values[System::Windows::Forms::Shortcut::CmdShiftG] = "CmdShiftG";
    values[System::Windows::Forms::Shortcut::CmdShiftH] = "CmdShiftH";
    values[System::Windows::Forms::Shortcut::CmdShiftI] = "CmdShiftI";
    values[System::Windows::Forms::Shortcut::CmdShiftJ] = "CmdShiftJ";
    values[System::Windows::Forms::Shortcut::CmdShiftK] = "CmdShiftK";
    values[System::Windows::Forms::Shortcut::CmdShiftL] = "CmdShiftL";
    values[System::Windows::Forms::Shortcut::CmdShiftM] = "CmdShiftM";
    values[System::Windows::Forms::Shortcut::CmdShiftN] = "CmdShiftN";
    values[System::Windows::Forms::Shortcut::CmdShiftO] = "CmdShiftO";
    values[System::Windows::Forms::Shortcut::CmdShiftP] = "CmdShiftP";
    values[System::Windows::Forms::Shortcut::CmdShiftQ] = "CmdShiftQ";
    values[System::Windows::Forms::Shortcut::CmdShiftR] = "CmdShiftR";
    values[System::Windows::Forms::Shortcut::CmdShiftS] = "CmdShiftS";
    values[System::Windows::Forms::Shortcut::CmdShiftT] = "CmdShiftT";
    values[System::Windows::Forms::Shortcut::CmdShiftU] = "CmdShiftU";
    values[System::Windows::Forms::Shortcut::CmdShiftV] = "CmdShiftV";
    values[System::Windows::Forms::Shortcut::CmdShiftW] = "CmdShiftW";
    values[System::Windows::Forms::Shortcut::CmdShiftX] = "CmdShiftX";
    values[System::Windows::Forms::Shortcut::CmdShiftY] = "CmdShiftY";
    values[System::Windows::Forms::Shortcut::CmdShiftZ] = "CmdShiftZ";
    values[System::Windows::Forms::Shortcut::CmdT] = "CmdT";
    values[System::Windows::Forms::Shortcut::CmdU] = "CmdU";
    values[System::Windows::Forms::Shortcut::CmdV] = "CmdV";
    values[System::Windows::Forms::Shortcut::CmdW] = "CmdW";
    values[System::Windows::Forms::Shortcut::CmdX] = "CmdX";
    values[System::Windows::Forms::Shortcut::CmdY] = "CmdY";
    values[System::Windows::Forms::Shortcut::CmdZ] = "CmdZ";
    values[System::Windows::Forms::Shortcut::Del] = "Del";
    values[System::Windows::Forms::Shortcut::F1] = "F1";
    values[System::Windows::Forms::Shortcut::F10] = "F10";
    values[System::Windows::Forms::Shortcut::F11] = "F11";
    values[System::Windows::Forms::Shortcut::F12] = "F12";
    values[System::Windows::Forms::Shortcut::F2] = "F2";
    values[System::Windows::Forms::Shortcut::F3] = "F3";
    values[System::Windows::Forms::Shortcut::F4] = "F4";
    values[System::Windows::Forms::Shortcut::F5] = "F5";
    values[System::Windows::Forms::Shortcut::F6] = "F6";
    values[System::Windows::Forms::Shortcut::F7] = "F7";
    values[System::Windows::Forms::Shortcut::F8] = "F8";
    values[System::Windows::Forms::Shortcut::F9] = "F9";
    values[System::Windows::Forms::Shortcut::Ins] = "Ins";
    values[System::Windows::Forms::Shortcut::None] = "None";
    values[System::Windows::Forms::Shortcut::ShiftDel] = "ShiftDel";
    values[System::Windows::Forms::Shortcut::ShiftF1] = "ShiftF1";
    values[System::Windows::Forms::Shortcut::ShiftF10] = "ShiftF10";
    values[System::Windows::Forms::Shortcut::ShiftF11] = "ShiftF11";
    values[System::Windows::Forms::Shortcut::ShiftF12] = "ShiftF12";
    values[System::Windows::Forms::Shortcut::ShiftF2] = "ShiftF2";
    values[System::Windows::Forms::Shortcut::ShiftF3] = "ShiftF3";
    values[System::Windows::Forms::Shortcut::ShiftF4] = "ShiftF4";
    values[System::Windows::Forms::Shortcut::ShiftF5] = "ShiftF5";
    values[System::Windows::Forms::Shortcut::ShiftF6] = "ShiftF6";
    values[System::Windows::Forms::Shortcut::ShiftF7] = "ShiftF7";
    values[System::Windows::Forms::Shortcut::ShiftF8] = "ShiftF8";
    values[System::Windows::Forms::Shortcut::ShiftF9] = "ShiftF9";
    values[System::Windows::Forms::Shortcut::ShiftIns] = "ShiftIns";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
