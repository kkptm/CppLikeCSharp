/// @file
/// @brief Contains Switch::System::Drawing::PointF class.
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
      class SizeF;
      /// @endcond

      /// @brief Stores an ordered pair of singles, which specify a X and Y.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ PointF : public object {
      public:
        /// @brief Gets a PointF class that has a X and Y value of 0. This field is constant.
        static property_<PointF, readonly_> Empty;

        /// @brief Initializes a new instance of the PointF class that has a X and Y value of 0.0f.
        PointF() = default;

        /// @brief Initializes a new instance of the PointF class from the specified PointF class.
        /// @param point The PointF class from which to initialize this PointF class
        /// @exception ArgumentNullException point is null.
        PointF(const PointF& point) : x(point.x), y(point.y) {}

        /// @brief Initializes a new instance of the PointF class from the specified SizeF class.
        /// @param size The SizeF class from which to initialize this PointF class
        /// @exception ArgumentNullException size is null.
        PointF(const SizeF& size);

        /// @brief Initializes a new instance of the PointF class from the specified dimensions.
        /// @param x The X component of the new SizeF
        /// @param y The Y component of the new SizeF
        PointF(float x, float y) : x(x), y(y) {}

        /// @brief Gets or sets the X component of this PointF Class.
        /// @return int32 The X component of this PointF class, typically measured in pixels.
        /// @remarks The unit for the X and Y of the PointF class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
        property_<float> X {
          get_ {return this->x;},
          set_ {this->x = value;}
        };

        /// @brief Gets or sets the Y component of this PointF class.
        /// @return int32 The Y component of this PointF class, typically measured in pixels.
        /// @remarks The unit for the X and Y of the PointF class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
        property_<float> Y {
          get_ {return this->y;},
          set_ {this->y = value;}
        };

        /// @brief Determines whether this instance of PointF and a specified object, which must also be a PointF object, have the same value.
        /// @param value The PointF to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        bool Equals(const PointF& value) const;

        /// @brief Determines whether this instance of PointF and a specified object, which must also be a PointF object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override;

        /// @brief Tests whether this PointF class has X and Y of 0.
        /// @return bool Returns true  when this PointF class has both a X and Y of 0; otherwise, false.
        bool IsEmpty() const { return this->x == Empty().x && this->y == Empty().y; }

        /// @brief Creates a human-readable string that represents this PointF class.
        /// @return string A string that represents this PointF.
        String ToString() const override { return String::Format("{{X={0},Y={1}}}", this->x, this->y); }

        /// @brief Translates this PointF by the specified PointF.
        /// @param pt The PointF used offset this PointF.
        /// @exception ArgumentNullException pt is null.
        /// @remarks This method adjusts the X and Y values of this PointF to the sum of the X and Y values of this PointF and pt.
        void Offset(const PointF& pt) {
          this->x += pt.x;
          this->y += pt.y;
        }

        /// @brief Translates this PointF by the specified amount.
        /// @param dx The amount to offset the x-coordinate.
        /// @param dy The amount to offset the y-coordinate.
        /// @exception ArgumentNullException pt is null.
        /// @remarks This method adjusts the X and Y values of this PointF to the sum of the X and Y values of this PointF and pt.
        void Offset(float dx, float dy) {
          this->x += dx;
          this->y += dy;
        }

        /// @brief Adds the specified SizeF to the specified PointF.
        /// @param pt The PointF to add.
        /// @param sz The SizeF to add.
        /// @return The PointF that is the result of the addition operation.
        /// @exception ArgumentNullException pt or sz are null.
        static PointF Add(const PointF& pt, const SizeF& sz);

        /// @brief Returns the result of subtracting specified SizeF from the specified PointF.
        /// @param pt The PointF to be subtracted from.
        /// @param sz The SizeF to subtract from the PointF.
        /// @return The PointF that is the result of the subtraction operation.
        /// @exception ArgumentNullException pt or sz are null.
        static PointF Subtract(const PointF& pt, const SizeF& sz);

      private :
        float x = .0f;
        float y = .0f;

      public:
        /// @cond
        PointF& operator=(const PointF& pt);

        PointF operator +(const SizeF& sz) const;

        PointF operator -(const SizeF& sz) const;
        /// @endcond
      };
    }
  }
}
