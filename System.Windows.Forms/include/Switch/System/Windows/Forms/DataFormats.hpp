/// @file
/// @brief Contains Switch::System::Windows::Forms::DataFormats class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include "../../../SystemWindowsFormsExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Provides static, predefined Clipboard format names. Use them to identify the format of data that you store in an IDataObject.
        /// @remarks The IDataObject and DataObject classes also use the static format list to determine the type of data that is retrieved from the system Clipboard, or that is transferred in a drag-and-drop operation.
        /// @remarks The GetFormat method allows you to:
        /// * Get a predefined DataFormats.Format object for a format name or ID number.
        /// * Add a new format name/ID number pair to the static list in this class, and to register the format with the Windows registry as a Clipboard format when you pass it the format name.
        /// @remarks You can get the Id number or format Name from the appropriate property in the DataFormats.Format instance.
        class system_windows_forms_export_ DataFormats : public object {
        public:
          /// @brief Represents a Clipboard format type.
          /// @remarks A format type consists of a text-based format name and an ID number. The format name/ID number pair can define a system Clipboard or other format.
          /// @par Examples
          ///  The following code example shows how to retrieve a DataFormats.Format representing a format name/ID pair. The UnicodeText format is requested, and the contents of the retrieved DataFormats.Format are displayed in a text box.
          ///
          ///  This code requires that textBox1 has been created.
          /// @code
          /// void GetMyFormatInfomation() {
          ///   // Creates a DataFormats.Format for the Unicode data format.
          ///   DataFormats::Format myFormat = DataFormats::GetFormat(DataFormats::UnicodeText());
          ///   // Displays the contents of myFormat.
          ///   textBox1->Text("ID value: " + myFormat.Id() + '\n' + "Format name: " + myFormat.Name());
          /// }
          /// @endcode
          class Format : public object {
          public:
            Format() : id(0) {}
            Format(int32 id, const string& name) : id(id), name(name) {}

            int32 Id() const { return this->id; }
            const string& Name() const { return this->name; }

          private:
            int32 id;
            string name;
            static System::Collections::Generic::List<Format> formats;
          };

          static string Riff() {return "RiffAudio"; }

          static string Palette() {return "Palette"; }

          static string PenData() {return "PenData"; }

          static string Rtf() {return "Rich Text Format"; }

          static string Serializable() {return "WindowsForms10PersistentObject"; }

          static string StringFormat() {return "System::String"; }

          static string SymbolicLink() {return "SymbolicLink"; }

          static string Text() {return "Text"; }

          static string Tiff() {return "Tiff"; }

          static string UnicodeText() {return "UnicodeText"; }

          static string OemText() {return "OEMText"; }

          static string Bitmap() {return "Bitmap"; }

          static string CommaSeparatedValue() {return "Csv"; }

          static string Dib() {return "DeviceIndependentBitmap"; }

          static string Dif() {return "DataInterchangeFormat"; }

          static string EnhancedMetafile() {return "EnhancedMetafile"; }

          static string FileDrop() {return "FileDrop"; }

          static string Html() {return "HTML Format"; }

          static string Locale() {return "Locale"; }

          static string MetafilePict() {return "MetaFilePict"; }

          static string WaveAudio() {return "WaveAudio"; }

          static refptr<DataFormats> GetFormat(const string& format) {
            return new DataFormats();
          }

        private:
          DataFormats() {
          }
        };
      }
    }
  }
}
