/// @file
/// @brief Contains Switch::System::Drawing::Font class.
#pragma once

#include <Switch/System/String.hpp>
#include "../../SystemDrawingExport.hpp"
#include "FontFamily.hpp"
#include "FontStyle.hpp"
#include "GraphicsUnit.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Defines a particular format for text, including font face, size, and style attributes. This class cannot be inherited.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ Font : public object {
      public:
        Font(const string& name) {this->FromName(name, this->data().size, this->data().fontStyle);}

        Font(const string& name, float size) {this->FromName(name, size, this->data().fontStyle);}

        Font(const string& name, float size, const System::Drawing::FontStyle& style) {this->FromName(name, size, style);}

        Font(const System::Drawing::FontFamily& fontFamily) {this->FromName(fontFamily.Name, this->data().size, this->data().fontStyle);}

        /// @cond
        Font() {}
        Font(const System::Drawing::Font& font) : data(font.data) {}
        /// @endcond

        property_<bool, readonly_> Bold{
          get_{ return (this->data().fontStyle & System::Drawing::FontStyle::Bold) == System::Drawing::FontStyle::Bold; }
        };

        property_<System::Drawing::FontFamily, readonly_> FontFamily{
          get_{ return this->data().fontFamily; }
        };

        property_<bool, readonly_> Italic{
          get_{ return (this->data().fontStyle & System::Drawing::FontStyle::Italic) == System::Drawing::FontStyle::Italic; }
        };

        property_<bool, readonly_> Strikeout{
          get_{ return (this->data().fontStyle & System::Drawing::FontStyle::Strikeout) == System::Drawing::FontStyle::Strikeout; }
        };

        property_<bool, readonly_> Underline{
          get_{ return (this->data().fontStyle & System::Drawing::FontStyle::Underline) == System::Drawing::FontStyle::Underline; }
        };

        property_<const string&, readonly_> Name {
          get_->const string& {return this->data().name;}
        };

        property_<System::Drawing::FontStyle, readonly_> Style {
          get_ {return this->data().fontStyle;}
        };

        property_<float, readonly_> Size {
          get_ {return this->data().size;}
        };

        static System::Drawing::Font FromHdc(intptr hdc);

        static System::Drawing::Font FromHFont(intptr hfont);

        template<typename object>
        static System::Drawing::Font FromLogFont(const object& lf) { return FromLogFont(lf, 0); }

        template<typename object>
        static System::Drawing::Font FromLogFont(const object& lf, intptr hdc) { return FromLogFontHandle((intptr)&lf, hdc); }

        intptr ToHFont() const {return this->data().hfont;}

        bool IsStyleAvaible(const System::Drawing::FontStyle& style) const {
          if (style == System::Drawing::FontStyle::Regular)
            return true;
          return System::Drawing::FontStyle(int(this->data().fontStyle) & int(style)) == style;
        }

        String ToString() const override { return string::Format("[{0}: Name={1}, Size={2}, Units={3}, GdiCharSet={4}, GdiVerticalFont={5}]", this->GetType().Name, this->data().fontFamily.Name, this->data().size, (int32)this->data().fontUnit, this->data().gdiCharSet, this->data().gdiVerticalFont); }

      private:
        void FromName(const string& name, float size, System::Drawing::FontStyle style);
        static System::Drawing::Font FromLogFontHandle(intptr lf, intptr hdc);

        struct FontData {
          System::Drawing::FontFamily fontFamily;
          System::Drawing::FontStyle fontStyle = System::Drawing::FontStyle::Regular;
          System::Drawing::GraphicsUnit fontUnit = System::Drawing::GraphicsUnit::World;
          bool gdiCharSet = false;
          bool gdiVerticalFont = false;
          intptr hfont = 0;
          string name;
          float size = .0f;
        };
        refptr<FontData> data = ref_new<FontData>();
      };
    }
  }
}
