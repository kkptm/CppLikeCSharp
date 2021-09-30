#include "../../../../include/Switch/System/Drawing/Point.hpp"
#include "../../../../include/Switch/System/Drawing/Size.hpp"

using namespace System;
using namespace System::Drawing;

property_<Size, readonly_> Size::Empty {
  [] {return Size();}
};

Size::Size(const Point& point) : width(point.X), height(point.Y) {
}

bool Size::Equals(const Size& value) const {
  return this->width == value.width && this->height == value.height;
}

bool Size::Equals(const object& obj) const {
  return is<Size>(obj) && Equals((const Size&)obj);
}

bool Size::IsEmpty() const {
  return this->height == Empty().height && this->width == Empty().width;
}

Size Size::Add(const Size& sz1, const Size& sz2) {
  return Size(sz1.width + sz2.width, sz1.height + sz2.height);
}

Size Size::Subtract(const Size& sz1, const Size& sz2) {
  return Size(sz1.width - sz2.width, sz1.height - sz2.height);
}

Size& Size::operator=(const Size& sz) {
  this->width = sz.width;
  this->height = sz.height;
  return *this;
}

Size Size::operator +(const Size& sz) const {
  return Add(*this, sz);
}

Size Size::operator -(const Size& sz) const {
  return Subtract(*this, sz);
}

Size& Size::operator +=(const Size& sz) {
  *this = Add(*this, sz);
  return *this;
}

Size& Size::operator -=(const Size& sz) {
  *this =  Subtract(*this, sz);
  return *this;
}
