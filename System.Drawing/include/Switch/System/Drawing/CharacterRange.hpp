/// @file
/// @brief Contains Switch::System::Drawing::CharacterRange class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/Property.hpp>
#include "../../SystemDrawingExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Specifies a range of character positions within a string.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ CharacterRange : public object {
      public:
        /// @brief Initializes a new instance of the CharacterRange structure, with default value (0, 0).
        CharacterRange() {}

        /// @brief Initializes a new instance of the CharacterRange structure, specifying a range of character positions within a string.
        /// @param first The position of the first character in the range. For example, if First is set to 0, the first position of the range is position 0 in the string.
        /// @param length The number of positions in the range.
        CharacterRange(int32 first, int32 length) : first(first), length(length) {}

        /// @brief Initializes a new instance of the CharacterRange structure, with default value (0, 0).
        CharacterRange(const CharacterRange& characterRange) {
          this->first = characterRange.first;
          this->length = characterRange.length;
        }

        /// @cond
        CharacterRange& operator =(const CharacterRange& characterRange) {
          this->first = characterRange.first;
          this->length = characterRange.length;
          return *this;
        }
        /// @endcond

        /// @brief Gets or sets the position in the string of the first character of this CharacterRange.
        property_<int32> First {
          get_ {return this->first;},
          set_ {this->first = value;}
        };

        /// @brief Gets or sets the number of positions in this CharacterRange.
        property_<int32> Length {
          get_ {return this->length;},
          set_ {this->length = value;}
        };

        /// @brief Determines whether this instance of CharacterRange and a specified object, which must also be a CharacterRange object, have the same value.
        /// @param obj The CharacterRange to compare with the current object.
        /// @return bool true if the specified obj is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override {
          return is<CharacterRange>(obj) && Equals(as<CharacterRange>(obj));
        }

        /// @brief Determines whether this instance of CharacterRange and a specified object, which must also be a CharacterRange object, have the same value.
        /// @param value The CharacterRange to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        virtual bool Equals(const CharacterRange& value) const {
          return this->first == value.first && this->length == value.length;
        }

      private:
        int32 first = 0;
        int32 length = 0;
      };
    }
  }
}
