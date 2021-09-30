/// @file
/// @brief Contains Switch::System::Windows::Forms::IDataObject interface.
#pragma once

#include <Switch/Interface.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "DataFormats.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @interface IDataObject
        /// @brief Provides a format-independent mechanism for transferring data.
        /// @remarks The IDataObject interface is used by the Clipboard class and in drag-and-drop operations.
        /// @remarks When implemented in a class, the IDataObject methods allow the user to store data in multiple formats in an instance of the class. Storing data in more than one format increases the chance that a target application, whose format requirements you might not know, can retrieve the stored data. To store data in an instance of IDataObject, call the SetData method and specify the data format in the format parameter. Set the autoConvert parameter to false if you do not want stored data to be converted to another format when it is retrieved. Invoke SetData multiple times on one instance of IDataObject to store data in more than one format.
        /// @remarks You retrieve stored data from an IDataObject by calling the GetData method and specifying the data format in the format parameter. Set the autoConvert parameter to false to retrieve only data that was stored in the specified format. To convert the stored data to the specified format, set autoConvert to true, or do not use autoConvert.
        /// @remarks To determine the formats of the data stored in an IDataObject, use the following IDataObject methods.
        /// @remarks Call the GetFormats method to retrieve an array of all the formats in which the data is available. Set the autoConvert parameter to false to get only the formats in which the data is stored. To get all the formats in which the data is available, set autoConvert to true, or do not use this parameter.
        /// @remarks Call the GetDataPresent method to determine whether stored data is available in a certain format. If you do not want stored data to be converted to the specified format, set the autoConvert parameter to false.
        /// @remarks See the DataObject class for an implementation of this interface. See the DataFormats class for the predefined Clipboard data formats.
        class system_windows_forms_export_ IDataObject interface_ {
        public:

        };
      }
    }
  }
}
