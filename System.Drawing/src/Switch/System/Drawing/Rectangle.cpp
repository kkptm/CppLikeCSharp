#include "../../../../include/Switch/System/Drawing/Rectangle.hpp"

using namespace System;
using namespace System::Drawing;

property_<Rectangle, readonly_> Rectangle::Empty {
  [] {return Rectangle();}
};
