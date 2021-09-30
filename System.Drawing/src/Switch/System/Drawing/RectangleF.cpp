#include "../../../../include/Switch/System/Drawing/RectangleF.hpp"

using namespace System;
using namespace System::Drawing;

property_<RectangleF, readonly_> RectangleF::Empty {
  [] {return RectangleF();}
};
