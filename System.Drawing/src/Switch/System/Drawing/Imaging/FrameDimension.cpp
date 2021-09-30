#include "../../../../../include/Switch/System/Drawing/Imaging/FrameDimension.hpp"

using namespace System::Drawing::Imaging;

property_<FrameDimension, readonly_> FrameDimension::Page {
  [] {return FrameDimension("7462dc86-6180-4c7e-8e3f-ee7333a7a483", "Page");}
};

property_<FrameDimension, readonly_> FrameDimension::Resolution {
  [] {return FrameDimension("84236f7b-3bd3-428f-8dab-4ea1439ca315", "Resolution");}
};

property_<FrameDimension, readonly_> FrameDimension::Time {
  [] {return FrameDimension("6aedbd6d-3fb5-418a-83a6-7f45229dc872", "Time");}
};

