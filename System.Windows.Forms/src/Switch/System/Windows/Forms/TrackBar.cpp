#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/TrackBar.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void TrackBar::CreateHandle() {
  this->handle = Native::TrackBarApi::Create(*this);
  this->Control::CreateHandle();
  Native::TrackBarApi::SetLargeChange(*this);
  Native::TrackBarApi::SetMaximum(*this);
  Native::TrackBarApi::SetMinimum(*this);
  Native::TrackBarApi::SetOrientation(*this);
  Native::TrackBarApi::SetSmallChange(*this);
  Native::TrackBarApi::SetTickFrequency(*this);
  Native::TrackBarApi::SetTickStyle(*this);
  Native::TrackBarApi::SetValue(*this);
}

void TrackBar::WndProc(Message& message) {
  Control::WndProc(message);
  if (message.Msg == (WM_REFLECT + WM_HSCROLL) || message.Msg == (WM_REFLECT + WM_VSCROLL)) {
    int32 value = this->GetValue();
    if (this->value != value) {
      this->value = value;
      OnScroll(EventArgs::Empty);
      OnValueChanged(EventArgs::Empty);
    }
  }
}

void TrackBar::SetLargeChange(int32 largeChange) {
  if (this->largeChange != largeChange) {
    this->largeChange = largeChange;
    if (this->IsHandleCreated)
      Native::TrackBarApi::SetLargeChange(*this);
  }
}

void TrackBar::SetMaximum(int32 maximum) {
  if (this->maximum != maximum) {
    this->maximum = maximum;
    if (this->IsHandleCreated) {
      Native::TrackBarApi::SetMaximum(*this);
      Native::TrackBarApi::SetValue(*this);
    }
  }
}

void TrackBar::SetMinimum(int32 minimum) {
  if (this->minimum != minimum) {
    this->minimum = minimum;
    if (this->IsHandleCreated) {
      Native::TrackBarApi::SetMinimum(*this);
      Native::TrackBarApi::SetValue(*this);
    }
  }
}

void TrackBar::SetOrientation(System::Windows::Forms::Orientation orientation) {
  if (this->orientation != orientation) {
    this->orientation = orientation;
    if (this->IsHandleCreated)
      Native::TrackBarApi::SetOrientation(*this);
  }
}

void TrackBar::SetSmallChange(int32 smallChange) {
  if (this->smallChange != smallChange) {
    this->smallChange = smallChange;
    if (this->IsHandleCreated)
      Native::TrackBarApi::SetSmallChange(*this);
  }
}

void TrackBar::SetTickFrequency(int32 tickFrequency) {
  if (tickFrequency < 0)
    throw ArgumentOutOfRangeException(caller_);
  if (this->tickFrequency != tickFrequency) {
    this->tickFrequency = tickFrequency;
    if (this->IsHandleCreated)
      Native::TrackBarApi::SetTickFrequency(*this);
  }
}

void TrackBar::SetTickStyle(System::Windows::Forms::TickStyle style) {
  if (this->tickStyle != style) {
    this->tickStyle = style;
    if (this->IsHandleCreated)
      Native::TrackBarApi::SetTickStyle(*this);
  }
}

int32 TrackBar::GetValue() const {
  if (this->IsHandleCreated)
    return Native::TrackBarApi::GetValue(*this);
  return this->value;
}

void TrackBar::SetValue(int32 value) {
  if (this->value != value) {
    this->value = value;
    if (this->IsHandleCreated)
      Native::TrackBarApi::SetValue(*this);
    OnValueChanged(EventArgs::Empty);
  }
}
