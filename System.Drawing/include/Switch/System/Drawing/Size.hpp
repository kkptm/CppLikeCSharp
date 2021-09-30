/// @file
/// @brief Contains Switch::System::Drawing::Size class.
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
      class Point;
      /// @endcond

      /// @brief Stores an ordered pair of integers, which specify a Height and Width.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ Size : public object {
      public:
        /// @brief Gets a Size class that has a Height and Width value of 0. This field is constant.
        static property_<Size, readonly_> Empty;

        /// @brief Initializes a new instance of the Size class that has a Height and Width value of 0.
        Size() = default;

        /// @brief Initializes a new instance of the Size class from the specified Size class.
        /// @param size The Size class from which to initialize this Size class
        /// @exception ArgumentNullException size is null.
        Size(const Size& size) : width(size.width), height(size.height) {}

        /// @brief IInitializes a new instance of the Size class from the specified Point class.
        /// @param point The Point class from which to initialize this Size class
        Size(const Point& point);

        /// @brief Initializes a new instance of the Size class from the specified dimensions.
        /// @param width The width component of the new Size
        /// @param height The height component of the new Size
        Size(int32 width, int32 height) : width(width), height(height) {}

        /// @brief Gets or sets the vertical component of this Size Class.
        /// @return int32 The vertical component of this Size class, typically measured in pixels.
        /// @remarks The unit for the Height and Width of the Size class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
        property_<int32> Height {
          get_ {return this->height;},
          set_ {this->height = value;}
        };

        /// @brief Gets or sets the horizontal component of this Size class.
        /// @return int32 The horizontal component of this Size class, typically measured in pixels.
        /// @remarks The unit for the Height and Width of the Size class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
        property_<int32> Width {
          get_ {return this->width;},
          set_ {this->width = value;}
        };

        /// @brief Determines whether this instance of Size and a specified object, which must also be a Size object, have the same value.
        /// @param value The Size to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        bool Equals(const Size& value) const;

        /// @brief Determines whether this instance of Size and a specified object, which must also be a Size object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override;

        /// @brief Tests whether this Size class has width and height of 0.
        /// @return bool Returns true  when this Size class has both a width and height of 0; otherwise, false.
        bool IsEmpty() const;

        /// @brief Creates a human-readable string that represents this Size class.
        /// @return string A string that represents this Size.
        String ToString() const override { return String::Format("{{Width={0}, Height={1}}}", this->width, this->height); }

        /// @brief Adds the width and height of one Size class to the width and height of another Size class.
        /// @param size1 The first Size class to add.
        /// @param size2 The second Size class to add.
        /// @return Size A Size class that is the result of the addition operation.
        static Size Add(const Size& size1, const Size& size2);

        /// @brief Returns the result of subtracting specified Size from the specified Point.
        /// @param sz1 The Size to be subtracted from.
        /// @param sz2 The Size to subtract from the Size.
        /// @return The Size that is the result of the subtraction operation.
        /// @exception ArgumentNullException sz1 or sz2 are null.
        static Size Subtract(const Size& sz1, const Size& sz2);

      private :
        int32 width = 0;
        int32 height = 0;

      public:
        /// @cond
        Size& operator=(const Size& sz);
        Size operator+(const Size& sz) const;
        Size operator-(const Size& sz) const;
        Size& operator+=(const Size& sz);
        Size& operator-=(const Size& sz);
        /// @endcond
      };
    }
  }
}
