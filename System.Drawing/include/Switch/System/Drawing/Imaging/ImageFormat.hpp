/// @file
/// @brief Contains Switch::System::Drawing::Imaging::ImageFormat class.
#pragma once

#include <Switch/System/Guid.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../../../SystemDrawingExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief The System::Drawing::Imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the System::Drawing namespace.
      namespace Imaging {
        class system_drawing_export_ ImageFormat : public object {
        public:
          static property_<ImageFormat, readonly_> Bmp;

          static property_<ImageFormat, readonly_> Emf;

          static property_<ImageFormat, readonly_> Exif;

          static property_<ImageFormat, readonly_> Gif;

          static property_<ImageFormat, readonly_> Icon;

          static property_<ImageFormat, readonly_> Jpeg;

          static property_<ImageFormat, readonly_> MemoryBmp;

          static property_<ImageFormat, readonly_> Png;

          static  property_<ImageFormat, readonly_> Tiff;

          static property_<ImageFormat, readonly_> Wmf;

          ImageFormat() = default;
          ImageFormat(const Guid& guid) : guid(guid) {}
          ImageFormat(const string name, const Guid& guid) : name(name), guid(guid) {}
          ImageFormat(const string name, const string& guid) : name(name), guid(guid) {}
          ImageFormat(const ImageFormat& format) : name(format.name), guid(format.guid) {}

          property_<System::Guid, readonly_> Guid {
            get_ {return this->guid;}
          };

          property_<string, readonly_> Name {
            get_ {return this->name;}
          };

        private:
          string name;
          System::Guid guid;
        };
      }
    }
  }
}
