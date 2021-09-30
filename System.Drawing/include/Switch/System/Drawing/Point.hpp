/// @file
/// @brief Contains Switch::System::Drawing::Point class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/SystemException.hpp>
#include "../../SystemDrawingExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @cond
      class Size;
      class PointF;
      /// @endcond

      /// @brief Stores an ordered pair of integers, which specify a X and Y.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ Point : public object {
      public:
        /// @brief Gets a Point class that has a X and Y value of 0. This field is constant.
        static property_<Point, readonly_> Empty;

        /// @brief Initializes a new instance of the Point class that has a X and Y value of 0.
        Point() = default;

        /// @brief Initializes a new instance of the Point class from the specified Point class.
        /// @param point The Point class from which to initialize this Point class
        /// @exception ArgumentNullException point is null.
        Point(const Point& point) : x(point.x), y(point.y) {}

        /// @brief Initializes a new instance of the Point class from the specified Size class.
        /// @param size The Size class from which to initialize this Point class
        /// @exception ArgumentNullException size is null.
        Point(const Size& size);

        static Point Ceiling(const PointF& pt);

        /// @brief Initializes a new instance of the Point class from the specified dimensions.
        /// @param x The X component of the new Size
        /// @param y The Y component of the new Size
        Point(int32 x, int32 y) : x(x), y(y) {}

        /// @brief Gets or sets the X component of this Point Class.
        /// @return int32 The X component of this Point class, typically measured in pixels.
        /// @remarks The unit for the X and Y of the Point class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
        property_<int32> X {
          get_ {return this->x;},
          set_ {this->x = value;}
        };

        /// @brief Gets or sets the Y component of this Point class.
        /// @return int32 The Y component of this Point class, typically measured in pixels.
        /// @remarks The unit for the X and Y of the Point class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
        property_<int32> Y {
          get_ {return this->y;},
          set_ {this->y = value;}
        };

        /// @brief Determines whether this instance of Point and a specified object, which must also be a Point object, have the same value.
        /// @param value The Point to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        bool Equals(const Point& value) const;

        /// @brief Determines whether this instance of Point and a specified object, which must also be a Point object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override;

        /// @brief Serves as a hash function for a particular type.
        /// @return int32 A hash code for the current Object.
        int32 GetHashCode() const override {return this->x ^ this->y;}

        /// @brief Tests whether this Point class has X and Y of 0.
        /// @return bool Returns true  when this Point class has both a X and Y of 0; otherwise, false.
        bool IsEmpty() const { return this->x == Empty().x && this->y == Empty().y; }

        static Point Round(const PointF& pt);

        static Point Truncate(const PointF& pt);

        /// @brief Creates a human-readable string that represents this Point class.
        /// @return string A string that represents this Point.
        String ToString() const override { return String::Format("{{X={0},Y={1}}}", this->x, this->y); }

        /// @brief Translates this Point by the specified Point.
        /// @param pt The Point used offset this Point.
        /// @exception ArgumentNullException pt is null.
        /// @remarks This method adjusts the X and Y values of this Point to the sum of the X and Y values of this Point and pt.
        void Offset(const Point& pt) {
          this->x += pt.x;
          this->y += pt.y;
        }

        /// @brief Translates this Point by the specified amount.
        /// @param dx The amount to offset the x-coordinate.
        /// @param dy The amount to offset the y-coordinate.
        /// @exception ArgumentNullException pt is null.
        /// @remarks This method adjusts the X and Y values of this Point to the sum of the X and Y values of this Point and pt.
        void Offset(int32 dx, int32 dy) {
          this->x += dx;
          this->y += dy;
        }

        /// @brief Adds the specified Size to the specified Point.
        /// @param pt The Point to add.
        /// @param sz The Size to add.
        /// @return The Point that is the result of the addition operation.
        /// @exception ArgumentNullException pt or sz are null.
        static Point Add(const Point& pt, const Size& sz);

        /// @brief Returns the result of subtracting specified Size from the specified Point.
        /// @param pt The Point to be subtracted from.
        /// @param sz The Size to subtract from the Point.
        /// @return The Point that is the result of the subtraction operation.
        /// @exception ArgumentNullException pt or sz are null.
        static Point Subtract(const Point& pt, const Size& sz);

      private :
        int32 x = 0;
        int32 y = 0;

      public:
        /// @cond
        Point& operator=(const Point& pt);
        Point operator +(const Size& sz) const;
        Point operator -(const Size& sz) const;
        Point& operator +=(const Size& sz);
        Point& operator -=(const Size& sz);
        /// @endcond
      };
    }
  }
}
