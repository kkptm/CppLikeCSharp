#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/GroupBox.hpp"
#include "../../../../Native/Api.hpp"

#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Drawing/SystemColors.hpp>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

GroupBox::GroupBox() {
  if (System::Environment::OSVersion().Platform == System::PlatformID::MacOSX)
    this->backColor = System::Drawing::Color::FromArgb(255, 228, 228, 228);
}

void GroupBox::CreateHandle() {
  this->handle = Native::GroupBoxApi::Create(*this);
  this->Control::CreateHandle();
}

