#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Label.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void Label::CreateHandle() {
  this->handle = Native::LabelApi::Create(*this);
  this->Control::CreateHandle();
}
