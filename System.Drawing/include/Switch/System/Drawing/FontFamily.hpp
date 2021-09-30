/// @file
/// @brief Contains Switch::System::Drawing::FontFamily class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../../SystemDrawingExport.hpp"
#include "FontStyle.hpp"
#include "Text/GenericFontFamilies.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Defines a group of type faces having a similar basic design and certain variations in styles. This class cannot be inherited.
      /// @par Library
      /// Switch.System.Drawing
      class system_drawing_export_ FontFamily final : public object {
      public:
        FontFamily(const string& name);
        FontFamily(System::Drawing::Text::GenericFontFamilies genericFamily);

        /// @cond
        FontFamily()  = default;
        FontFamily(const FontFamily& fontFamily) : data(fontFamily.data) {}
        FontFamily(intptr handle) { this->data().handle = handle; }
        ~FontFamily();
        /// @endcond

        /// @brief Returns an array that contains all the FontFamily objects associated with the current graphics context.
        /// @return Array<FontFamily> An array of FontFamily objects associated with the current graphics context.
        static property_<Array<FontFamily>, readonly_> Families;

        static property_<FontFamily, readonly_> GenericMonospace;

        static property_<FontFamily, readonly_> GenericSansSerif;

        static property_<FontFamily, readonly_> GenericSerif;

        property_<string, readonly_> Name{
          get_ {return this->GetName();}
        };

        bool IsStyleAvailable(FontStyle style) const;

      private:
        string GetName() const;
        struct FontFamilyData {
          intptr handle = 0;
        };
        refptr<FontFamilyData> data = ref_new<FontFamilyData>();
      };
    }
  }
}
