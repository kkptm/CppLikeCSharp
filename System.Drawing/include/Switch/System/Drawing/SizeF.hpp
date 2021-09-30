/// @file
/// @brief Contains Switch::System::Drawing::SizeF class.
#pragma once

#include <Switch/System/Convert.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/SystemException.hpp>
#include "../../SystemDrawingExport.hpp"
#include "Size.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @cond
      class PointF;
      /// @endcond

      /// @brief Stores an ordered pair of singles, which specify a Height and Width.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ SizeF : public object {
      public:
        /// @brief Gets a SizeF class that has a Height and Width value of 0.0f. This field is constant.
        static property_<SizeF, readonly_> Empty;

        /// @brief Initializes a new instance of the SizeF class that has a Height and Width value of 0.0f.
        SizeF() {}

        /// @brief Initializes a new instance of the SizeF class that has a Height and Width value of 0.0f.
        SizeF(const SizeF& size) : width(size.width), height(size.height) {}

        /// @brief IInitializes a new instance of the SizeF class from the specified PointF class.
        /// @param point The PointF class from which to initialize this SizeF class
        SizeF(const PointF& point);

        /// @brief Initializes a new instance of the SizeF class from the specified dimensions.
        /// @param width The width component of the new SizeF
        /// @param height The height component of the new SizeF
        SizeF(float width, float height) : width(width), height(height) {}

        /// @brief Gets the vertical component of this SizeF Class.
        /// @return single The vertical component of this SizeF class, typically measured in pixels.
        /// @remarks The unit for the Height and Width of the SizeF class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
        property_<float> Height {
          get_ {return this->height;},
          set_ {this->height = value;}
        };

        /// @brief Gets the horizontal component of this SizeF class.
        /// @return single The horizontal component of this SizeF class, typically measured in pixels.
        /// @remarks The unit for the Height and Width of the SizeF class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
        property_<float> Width {
          get_ {return this->width;},
          set_ {this->width = value;}
        };

        /// @brief Determines whether this instance of SizeF and a specified object, which must also be a SizeF object, have the same value.
        /// @param value The SizeF to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        bool Equals(const SizeF& value) const;

        /// @brief Determines whether this instance of SizeF and a specified object, which must also be a SizeF object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override;

        /// @brief Tests whether this SizeF class has width and height of 0.
        /// @return bool Returns true  when this SizeF class has both a width and height of 0; otherwise, false.
        bool IsEmpty() const;

        Size ToSize() const {return Size(Convert::ToInt32(this->width), Convert::ToInt32(this->height));}

        /// @brief Creates a human-readable string that represents this SizeF class.
        /// @return string A string that represents this SizeF.
        String ToString() const override { return String::Format("{{Width={0}, Height={1}}}", this->width, this->height); }

        /// @brief Adds the width and height of one SizeF class to the width and height of another SizeF class.
        /// @param size1 The first SizeF class to add.
        /// @param size2 The second SizeF class to add.
        /// @return SizeF A SizeF class that is the result of the addition operation.
        static SizeF Add(const SizeF& size1, const SizeF& size2);

        /// @brief Returns the result of subtracting specified Size from the specified SizeF.
        /// @param sz1 The SizeF to be subtracted from.
        /// @param sz2 The SizeF to subtract from the Size.
        /// @return The SizeF that is the result of the subtraction operation.
        /// @exception ArgumentNullException sz1 or sz2 are null.
        static SizeF Subtract(const SizeF& sz1, const SizeF& sz2);

      private :
        float width = .0f;
        float height = .0f;

      public:
        /// @cond
        SizeF& operator=(const SizeF& sz);

        SizeF operator +(const SizeF& sz) const;

        SizeF operator -(const SizeF& sz) const;
        /// @endcond
      };
    }
  }
}
