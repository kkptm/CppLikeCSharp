#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Panel.hpp"
#include "../../../../Native/Api.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Panel::CreateHandle() {
  this->handle = Native::PanelApi::Create(*this);
  this->Control::CreateHandle();
  Native::PanelApi::SetBorderStyle(*this);
}

void Panel::SetBorderStyle(System::Windows::Forms::BorderStyle borderStyle) {
  if (this->borderStyle != borderStyle) {
    this->borderStyle = borderStyle;
    if (this->IsHandleCreated)
      Native::PanelApi::SetBorderStyle(*this);
  }
}

