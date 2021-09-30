/// @file
/// @brief Contains Switch::System::Drawing::Imaging::FrameDimension class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Guid.hpp>
#include "../../../SystemDrawingExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief The System::Drawing::Imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the System::Drawing namespace.
      namespace Imaging {
        class system_drawing_export_ FrameDimension : public object {
        public:
          static property_<FrameDimension, readonly_> Page;

          static property_<FrameDimension, readonly_> Resolution;

          static property_<FrameDimension, readonly_> Time;

          FrameDimension(const Guid& guid) : guid(guid) {}
          FrameDimension(const Guid& guid, const string name) : guid(guid), name(name) {}
          FrameDimension(const string& guid, const string name) : guid(guid), name(name) {}
          FrameDimension(const FrameDimension& fd) : guid(fd.guid), name(fd.name) {}

          property_<System::Guid, readonly_> Guid {
            get_ {return this->guid;}
          };

          property_<string, readonly_> Name {
            get_ {return this->name;}
          };

        private:
          System::Guid guid;
          string name;
        };
      }
    }
  }
}
