/// @file
/// @brief Contains Switch::System::Drawing::RectangleF class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Math.hpp>
#include <Switch/System/SystemException.hpp>
#include "../../SystemDrawingExport.hpp"
#include "PointF.hpp"
#include "SizeF.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Stores a set of four singles that represent the location and size of a rectangle
      /// @remarks A rectangle is defined by its Width, Height, and upper-left corner represented by the Location property.
      /// @remarks To draw rectangles, you need a Graphics object and a Pen object. The Graphics object provides the DrawRectangle method, and the Pen object stores features of the line, such as color and width. The units the rectangle is drawn in is determined by the PageUnit and PageScale properties of the graphics object used for drawing. The default unit is pixels.
      /// @remarks To draw a Rectangle filled with color, you need a Graphics object and an object derived from Brush such as SolidBrush or LinearGradientBrush. The Graphics object provides the FillRectangle method and the Brush object provides the color and fill information.
      /// @remarks For more advanced shapes, use a Region object.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ RectangleF : public object {
      public:
        /// @brief Represents a Rectangle structure with its properties left uninitialized.
        static property_<RectangleF, readonly_> Empty;

        /// @brief Initializes a new instance of the Point class that has a X and Y value of 0.
        RectangleF() {}

        /// @brief Initializes a new instance of the Point class from the specified Point class.
        /// @param point The Point class from which to initialize this Point class
        /// @exception ArgumentNullException point is null.
        RectangleF(const PointF& location, const SizeF& size) : x(location.X()), y(location.Y()), width(size.Width()), height(size.Height()) {}

        /// @brief Initializes a new instance of the Point class from the specified Size class.
        /// @param size The Size class from which to initialize this Point class
        /// @exception ArgumentNullException size is null.
        RectangleF(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {}

        /// @cond
        RectangleF(const RectangleF& rect) : x(rect.x), y(rect.y), width(rect.width), height(rect.height) {}
        RectangleF& operator=(const RectangleF& rect) {
          this->x = rect.x;
          this->y = rect.y;
          this->width = rect.width;
          this->height = rect.height;
          return *this;
        }
        /// @endcond

        /// @brief Gets the y-coordinate that is the sum of the Y and Height property values of this Rectangle structure.
        /// @return int32 The height of this Rectangle structure. The default is 0.
        /// @remarks The value of the Bottom property represents the y-coordinate of the first point at the bottom edge of the Rectangle that is not contained in the Rectangle.
        property_<float, readonly_> Bottom {
          get_ {return this->y + this->height;}
        };

        /// @brief Gets or sets the height of this Rectangle structure.
        /// @return int32 The height of this Rectangle structure. The default is 0.
        /// @remarks Changing the Height property will also cause a change in the Bottom property of the Rectangle. The units the rectangle is drawn in is determined by the PageUnit and PageScale properties of the graphics object used for drawing. The default unit is pixels.
        property_<float> Height {
          get_ {return this->height;},
          set_ {this->height = value;}
        };

        /// @brief Gets the x-coordinate of the left edge of this Rectangle structure.
        /// @return int32 The x-coordinate of the left edge of this Rectangle structure.
        property_<float, readonly_> Left {
          get_ {return this->x;}
        };

        /// @brief Gets or sets the coordinates of the upper-left corner of this Rectangle structure.
        /// @return A Point that represents the upper-left corner of this Rectangle structure.
        property_<PointF> Location {
          get_ {return PointF(this->x, this->y);},
          set_ {
            this->x = value.X;
            this->y = value.Y;
          }
        };

        /// @brief Gets the x-coordinate that is the sum of X and Width property values of this Rectangle structure.
        /// @return int32 The x-coordinate that is the sum of X and Width of this Rectangle.
        /// @remarks The value of the Right property represents the x-coordinate of the first point at the right edge of the rectangle that is not contained in the rectangle.
        property_<float, readonly_> Right {
          get_ {return this->x + this->width;}
        };

        /// @brief Gets the size of this Rectangle.
        /// @return A Size that represents the width and height of this Rectangle structure.
        property_<SizeF> Size {
          get_ {return SizeF(this->width, this->height);},
          set_ {
            this->width = value.Width;
            this->height = value.Height;
          }
        };

        /// @brief Gets the y-coordinate of the top edge of this Rectangle structure.
        /// @return int32 The y-coordinate of the top edge of this Rectangle structure.
        property_<float, readonly_> Top {
          get_ {return this->y;}
        };

        /// @brief Gets or sets the wisth of this Rectangle structure.
        /// @return int32 The width of this Rectangle structure. The default is 0.
        /// @remarks Changing the Width property will also cause a change in the Rigth property of the Rectangle. The units the rectangle is drawn in is determined by the PageUnit and PageScale properties of the graphics object used for drawing. The default unit is pixels.
        property_<float> Width {
          get_ {return this->width;},
          set_ {this->width = value;}
        };

        /// @brief Gets or sets the x-coordinate of the upper-left corner of this Rectangle structure.
        /// @return int32 The x-coordinate of the upper-left corner of this Rectangle structure. The default is 0.
        /// @remarks Changing the X property will also cause a change in the Right property of the Rectangle.
        property_<float> X {
          get_ {return this->x;},
          set_ {this->x = value;}
        };

        /// @brief Gets or sets the y-coordinate of the upper-left corner of this Rectangle structure.
        /// @return int32 The y-coordinate of the upper-left corner of this Rectangle structure. The default is 0.
        /// @remarks Changing the y property will also cause a change in the Bottom property of the Rectangle.
        property_<float> Y {
          get_ {return this->y;},
          set_ {this->y = value;}
        };

        /// @brief Determines if the specified point is contained within this Rectangle structure.
        /// @param pt The Point to test.
        /// @return This method returns true if the point represented by pt is contained within this Rectangle structure; otherwise false.
        bool Contains(const PointF& pt) {return pt.X >= this->Left && pt.X <= this->Right && pt.Y >= this->Top && pt.Y <= this->Bottom;}

        /// @brief Determines if the specified point is contained within this Rectangle structure.
        /// @param x The x-coordinate of the point to test.
        /// @param y The y-coordinate of the point to test.
        /// @return This method returns true if the point defined by x and y is contained within this Rectangle structure; otherwise false.
        bool Contains(float x, float y) { return Contains(PointF(x, y)); }

        /// @brief Determines if the rectangular region represented by rect is entirely contained within this Rectangle structure.
        /// @param rect The Rectangle to test.
        /// @return This method returns true if the rectangular region represented by rect is entirely contained within this Rectangle structure; otherwise false.
        bool Contains(const RectangleF& rect) {return Contains(PointF(rect.Left(), rect.Top())) && Contains(PointF(rect.Right(), rect.Bottom()));}

        /// @brief Determines whether this instance of Point and a specified object, which must also be a Point object, have the same value.
        /// @param value The Point to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        bool Equals(const RectangleF& value) const {return this->x == value.x && this->y == value.y && this->width == value.width && this->height == value.height;}

        /// @brief Determines whether this instance of Point and a specified object, which must also be a Point object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override {return is<RectangleF>(obj) && Equals((const RectangleF&)obj);}

        /// @brief Creates a Rectangle structure with the specified edge locations.
        /// @param left The x-coordinate of the upper-left corner of this Rectangle structure.
        /// @param top The y-coordinate of the upper-left corner of this Rectangle structure.
        /// @param right The x-coordinate of the lower-right corner of this Rectangle structure.
        /// @param bottom The y-coordinate of the lower-right corner of this Rectangle structure.
        /// @return The new Rectangle that this method creates.
        /// @remarks This method creates a Rectangle with the specified upper-left and lower-right corners.
        static RectangleF FromLTRB(float left, float top, float right, float bottom) { return RectangleF(left, top, right - left, bottom - top); }

        /// @brief Enlarges this Rectangle by the specified amount.
        /// @param size The amount to inflate this rectangle.
        /// @remarks This method enlarges this rectangle, not a copy of it. The rectangle is enlarged in both directions along an axis. For example, if a 50 by 50 rectangle is enlarged by 50 in the x-axis, the resultant rectangle will be 150 units long (the original 50, the 50 in the minus direction, and the 50 in the plus direction) maintaining the rectangle's geometric center.
        void Inflate(const SizeF& size) {Inflate(size.Width(), size.Height());}

        /// @brief Enlarges this Rectangle by the specified amount.
        /// @param width The amount to inflate this Rectangle horizontally.
        /// @param height The amount to inflate this Rectangle vertically.
        /// @remarks This method enlarges this rectangle, not a copy of it. The rectangle is enlarged in both directions along an axis. For example, if a 50 by 50 rectangle is enlarged by 50 in the x-axis, the resultant rectangle will be 150 units long (the original 50, the 50 in the minus direction, and the 50 in the plus direction) maintaining the rectangle's geometric center.
        /// @remarks If either x or y is negative, the Rectangle structure is deflated in the corresponding direction.
        void Inflate(float width, float height) { *this = Inflate(*this, width, height); }

        /// @brief Creates and returns an enlarged copy of the specified Rectangle structure. The copy is enlarged by the specified amount. The original Rectangle structure remains unmodified.
        /// @param rect The Rectangle with which to start. This rectangle is not modified.
        /// @param x The amount to inflate this Rectangle horizontally.
        /// @param y The amount to inflate this Rectangle vertically.
        /// @return The enlarged Rectangle.
        /// @remarks This method makes a copy of rect, enlarges the copy, and then returns the enlarged copy. The rectangle is enlarged in both directions along an axis. For example, if a 50 by 50 rectangle is enlarged by 50 in the x-axis, the resultant rectangle will be 150 units long (the original 50, the 50 in the minus direction, and the 50 in the plus direction) maintaining the rectangle's geometric center.
        static RectangleF Inflate(const RectangleF& rect, float x, float y) {return RectangleF(rect.X() - x, rect.Y() - y, rect.Width() + 2 * x, rect.Height() + 2 * y);}

        /// @brief Replaces this Rectangle with the intersection of itself and the specified Rectangle.
        /// @param rect The Rectangle with which to intersect.
        void Intersect(const RectangleF& rect) { *this = Intersect(*this, rect); }

        /// @brief Returns a third Rectangle structure that represents the intersection of two other Rectangle structures. If there is no intersection, an empty Rectangle is returned.
        /// @param a A rectangle to intersect.
        /// @param b A rectangle to intersect.
        /// @return A Rectangle that represents the intersection of a and b.
        static RectangleF Intersect(const RectangleF& a, const RectangleF& b) {
          if (! a.IntersectWith(b))
            return RectangleF::Empty;
          return RectangleF(Math::Max(a.x, b.x), Math::Max(a.y, b.y), Math::Min(a.width, b.width), Math::Min(a.height, b.height));
        }

        /// @brief Determines if this rectangle intersects with rect.
        /// @param rect A rectangle to intersect.
        /// @return This method returns true if there is any intersection, otherwise false.
        bool IntersectWith(const RectangleF& rect) const {return Math::Max(x, rect.x) < Math::Max(y, rect.y) && Math::Min(width, rect.width) < Math::Min(height, rect.height);}

        /// @brief Tests whether this Point class has X and Y of 0.
        /// @return bool Returns true  when this Point class has both a X and Y of 0; otherwise, false.
        bool IsEmpty() const { return this->x == 0 && this->y == 0 && this->width == 0 && this->height == 0; }

        /// @brief Adjusts the location of this rectangle by the specified amount.
        /// @param pos Amount to offset the location.
        /// @remarks This method adjusts the location of the upper-left corner horizontally by the x-coordinate of the specified point, and vertically by the y-coordinate of the specified point.

        void Offset(const PointF& pos) {this->Offset(pos.X(), pos.Y());}

        /// @brief Adjusts the location of this rectangle by the specified amount.
        /// @param x The horizontal offset.
        /// @param y The vertical offset.
        void Offset(float x, float y) {
          this->x = x;
          this->y = y;
        }

        /// @brief Creates a human-readable string that represents this Point class.
        /// @return string A string that represents this Point.
        String ToString() const override { return String::Format("{{X={0},Y={1},Width={2},Height={3}}}", this->x, this->y, this->width, this->height); }

        /// @brief Returns a third Rectangle structure that represents the union of two other Rectangle structures.
        /// @param a A rectangle to union.
        /// @param b A rectangle to union.
        /// @return A Rectangle that represents the intersection of a and b.
        static RectangleF Union(const RectangleF& a, const RectangleF& b) {return RectangleF(Math::Min(a.x, b.x), Math::Min(a.y, b.y), Math::Max(a.width, b.width), Math::Max(a.height, b.height));}

      private :
        float x = .0f;
        float y = .0f;
        float width = .0f;
        float height = .0f;
      };
    }
  }
}
