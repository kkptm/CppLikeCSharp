/// @file
/// @brief Contains Switch::System::Media::SystemSound class.
#pragma once

#include <Switch/Is.hpp>
#include <Switch/Types.hpp>
#include <Switch/System/Object.hpp>
#include "../../SystemExport.hpp"

/// @cond
struct __opaque_sound_access__;
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Media namespace contains classes for playing sound files and accessing sounds provided by the system.
    namespace Media {
      /// @brief Provides a collection of Cursor objects for use by a Windows Forms application.
      /// @par Library
      /// Switch.System
      class system_export_ SystemSound : public object {
      public:
        SystemSound() {}

        void Play() const;

        bool Equals(const object& obj) const override {return is<SystemSound>(obj) && Equals((const SystemSound&)obj);}

        bool Equals(const SystemSound& sound) const {return this->type == sound.type;}

        intptr Tag() const {return (intptr)this->type;}

      private:
        friend struct ::__opaque_sound_access__;
        SystemSound(int32 type) : type(type) {}
        int32 type = 0;
      };
    }
  }
}
