#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/TabControl.hpp"
#include "../../../../Native/Api.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void TabControl::CreateHandle() {
  this->handle = Native::TabControlApi::Create(*this);
  this->Control::CreateHandle();
  Native::TabControlApi::SetAlignment(*this);
}

void TabControl::SetAlignment(TabAlignment alignment) {
  if (this->alignment != alignment) {
    this->alignment = alignment;
    if (this->IsHandleCreated)
      Native::TabControlApi::SetAlignment(*this);
  }
}

