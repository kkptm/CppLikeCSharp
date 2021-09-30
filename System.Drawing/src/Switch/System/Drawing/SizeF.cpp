#include "../../../../include/Switch/System/Drawing/PointF.hpp"
#include "../../../../include/Switch/System/Drawing/SizeF.hpp"

using namespace System;
using namespace System::Drawing;

property_<SizeF, readonly_> SizeF::Empty {
  [] {return SizeF();}
};

SizeF::SizeF(const PointF& point) : width(point.X), height(point.Y) {
}

bool SizeF::Equals(const SizeF& value) const {
  return this->width == value.width && this->height == value.height;
}

bool SizeF::Equals(const object& obj) const {
  return is<SizeF>(obj) && Equals((const SizeF&)obj);
}

bool SizeF::IsEmpty() const {
  return this->height == Empty().height && this->width == Empty().width;
}

SizeF SizeF::Add(const SizeF& size1, const SizeF& size2) {
  return SizeF(size1.width + size2.width, size1.height + size2.height);
}

SizeF SizeF::Subtract(const SizeF& sz1, const SizeF& sz2) {
  return SizeF(sz1.width - sz2.width, sz1.height - sz2.height);
}

SizeF& SizeF::operator=(const SizeF& sz) {
  this->width = sz.width;
  this->height = sz.height;
  return *this;
}

SizeF SizeF::operator+(const SizeF& sz) const {
  return Add(*this, sz);
}

SizeF SizeF::operator-(const SizeF& sz) const {
  return Subtract(*this, sz);
}
