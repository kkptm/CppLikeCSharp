#include "../../../../include/Switch/System/Drawing/SystemColors.hpp"

using namespace System;
using namespace System::Drawing;

property_<Color, readonly_> SystemColors::ActiveBorder {
  [] {return Color::FromKnownColor(KnownColor::ActiveBorder);}
};

property_<Color, readonly_> SystemColors::ActiveCaption {
  [] {return Color::FromKnownColor(KnownColor::ActiveCaption);}
};

property_<Color, readonly_> SystemColors::ActiveCaptionText {
  [] {return Color::FromKnownColor(KnownColor::ActiveCaptionText);}
};

property_<Color, readonly_> SystemColors::AppWorkspace {
  [] {return Color::FromKnownColor(KnownColor::AppWorkspace);}
};

property_<Color, readonly_> SystemColors::Control {
  [] {return Color::FromKnownColor(KnownColor::Control);}
};

property_<Color, readonly_> SystemColors::ControlDark {
  [] {return Color::FromKnownColor(KnownColor::ControlDark);}
};

property_<Color, readonly_> SystemColors::ControlDarkDark {
  [] {return Color::FromKnownColor(KnownColor::ControlDarkDark);}
};

property_<Color, readonly_> SystemColors::ControlLight {
  [] {return Color::FromKnownColor(KnownColor::ControlLight);}
};

property_<Color, readonly_> SystemColors::ControlLightLight {
  [] {return Color::FromKnownColor(KnownColor::ControlLightLight);}
};

property_<Color, readonly_> SystemColors::ControlText {
  [] {return Color::FromKnownColor(KnownColor::ControlText);}
};

property_<Color, readonly_> SystemColors::Desktop {
  [] {return Color::FromKnownColor(KnownColor::Desktop);}
};

property_<Color, readonly_> SystemColors::GrayText {
  [] {return Color::FromKnownColor(KnownColor::GrayText);}
};

property_<Color, readonly_> SystemColors::Highlight {
  [] {return Color::FromKnownColor(KnownColor::Highlight);}
};

property_<Color, readonly_> SystemColors::HighlightText {
  [] {return Color::FromKnownColor(KnownColor::HighlightText);}
};

property_<Color, readonly_> SystemColors::HotTrack {
  [] {return Color::FromKnownColor(KnownColor::HotTrack);}
};

property_<Color, readonly_> SystemColors::InactiveBorder {
  [] {return Color::FromKnownColor(KnownColor::InactiveBorder);}
};

property_<Color, readonly_> SystemColors::InactiveCaption {
  [] {return Color::FromKnownColor(KnownColor::InactiveCaption);}
};

property_<Color, readonly_> SystemColors::InactiveCaptionText {
  [] {return Color::FromKnownColor(KnownColor::InactiveCaptionText);}
};

property_<Color, readonly_> SystemColors::Info {
  [] {return Color::FromKnownColor(KnownColor::Info);}
};

property_<Color, readonly_> SystemColors::InfoText {
  [] {return Color::FromKnownColor(KnownColor::InfoText);}
};

property_<Color, readonly_> SystemColors::Menu {
  [] {return Color::FromKnownColor(KnownColor::Menu);}
};

property_<Color, readonly_> SystemColors::MenuText {
  [] {return Color::FromKnownColor(KnownColor::MenuText);}
};

property_<Color, readonly_> SystemColors::ScrollBar {
  [] {return Color::FromKnownColor(KnownColor::ScrollBar);}
};

property_<Color, readonly_> SystemColors::Window {
  [] {return Color::FromKnownColor(KnownColor::Window);}
};

property_<Color, readonly_> SystemColors::WindowFrame {
  [] {return Color::FromKnownColor(KnownColor::WindowFrame);}
};

property_<Color, readonly_> SystemColors::WindowText {
  [] {return Color::FromKnownColor(KnownColor::WindowText);}
};

property_<Color, readonly_> SystemColors::ButtonFace {
  [] {return Color::FromKnownColor(KnownColor::ButtonFace);}
};

property_<Color, readonly_> SystemColors::ButtonHighlight {
  [] {return Color::FromKnownColor(KnownColor::ButtonHighlight);}
};

property_<Color, readonly_> SystemColors::ButtonShadow {
  [] {return Color::FromKnownColor(KnownColor::ButtonShadow);}
};

property_<Color, readonly_> SystemColors::GradientActiveCaption {
  [] {return Color::FromKnownColor(KnownColor::GradientActiveCaption);}
};

property_<Color, readonly_> SystemColors::GradientInactiveCaption {
  [] {return Color::FromKnownColor(KnownColor::GradientInactiveCaption);}
};

property_<Color, readonly_> SystemColors::MenuBar {
  [] {return Color::FromKnownColor(KnownColor::MenuBar);}
};

property_<Color, readonly_> SystemColors::MenuHighlight {
  [] {return Color::FromKnownColor(KnownColor::MenuHighlight);}
};
