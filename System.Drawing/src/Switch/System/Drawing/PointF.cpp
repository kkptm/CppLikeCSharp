#include "../../../../include/Switch/System/Drawing/PointF.hpp"
#include "../../../../include/Switch/System/Drawing/SizeF.hpp"

using namespace System;
using namespace System::Drawing;

property_<PointF, readonly_> PointF::Empty {
  [] {return PointF();}
};

PointF::PointF(const SizeF& sz) {
  this->x = sz.Width();
  this->y = sz.Height();
}

bool PointF::Equals(const PointF& value) const {
  return this->x == value.x && this->y == value.y;
}

bool PointF::Equals(const object& obj) const {
  return is<PointF>(obj) && Equals((const PointF&)obj);
}

PointF PointF::Add(const PointF& pt, const SizeF& sz) {
  return PointF(pt.x + sz.Width(), pt.y + sz.Height());
}

PointF PointF::Subtract(const PointF& pt, const SizeF& sz) {
  return PointF(pt.x - sz.Width(), pt.y - sz.Height());
}

PointF& PointF::operator=(const PointF& pt) {
  this->x = pt.x;
  this->y = pt.y;
  return *this;
}

PointF PointF::operator+(const SizeF& sz) const {
  return Add(*this, sz);
}

PointF PointF::operator-(const SizeF& sz) const {
  return Subtract(*this, sz);
}

