/// @file
/// @brief Contains Switch::System::ConsoleKeyInfo class.
#pragma once

#include "../Property.hpp"
#include "../Types.hpp"
#include "ConsoleKey.hpp"
#include "ConsoleModifiers.hpp"
#include "Object.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Specifies the standard keys on a console.
    /// @see Console
    struct core_export_ ConsoleKeyInfo : public Object {
    public:
      /// @brief Create a new instance of ConsoleKeyInfo class.
      /// @remarks This type is not intended to be created by users. Instead, it is returned to the user in response to calling the Console::ReadKey method.
      /// @remarks The ConsoleKeyInfo type does not specify whether the left or right SHIFT, ALT, or CTRL modifier key was pressed
      ConsoleKeyInfo() {}

      /// @brief Create a new instance of ConsoleKeyInfo class.
      /// @remarks This type is not intended to be created by users. Instead, it is returned to the user in response to calling the Console::ReadKey method.
      /// @remarks The ConsoleKeyInfo type does not specify whether the left or right SHIFT, ALT, or CTRL modifier key was pressed
      ConsoleKeyInfo(const ConsoleKeyInfo& keyInfo) : keyChar(keyInfo.keyChar), key(keyInfo.key), modifiers(keyInfo.modifiers) {}

      /// @cond
      ConsoleKeyInfo& operator=(const ConsoleKeyInfo& keyInfo) {
        this->keyChar = keyInfo.keyChar;
        this->key = keyInfo.key;
        this->modifiers = keyInfo.modifiers;
        return *this;
      }
      /// @endcond

      /// @brief Initializes a new instance of the ConsoleKeyInfo class using the specified character, console key, and modifier keys.
      /// @param keyChar The Unicode character that corresponds to the key parameter.
      /// @param key The console key that corresponds to the keyChar parameter.
      /// @param shift true to indicate that a SHIFT key was pressed; otherwise, false.
      /// @param alt true to indicate that an ALT key was pressed; otherwise, false.
      /// @param control true to indicate that a CTRL key was pressed; otherwise, false.
      /// @remarks This type is not intended to be created by users. Instead, it is returned to the user in response to calling the Console::ReadKey method.
      /// @remarks The ConsoleKeyInfo type does not specify whether the left or right SHIFT, ALT, or CTRL modifier key was pressed
      ConsoleKeyInfo(char32 keyChar, ConsoleKey key, bool shift, bool alt, bool control) : keyChar(keyChar), key(key) {
        if (shift == true)
          this->modifiers |= ConsoleModifiers::Shift;
        if (alt == true)
          this->modifiers |= ConsoleModifiers::Alt;
        if (control == true)
          this->modifiers |= ConsoleModifiers::Control;
      }

      /// @brief Gets the console key represented by the current ConsoleKeyInfo object.
      /// @param A System::ConsoleKey value that identifies the console key that was pressed
      property_<ConsoleKey, readonly_> Key {
        get_ {return this->key;}
      };

      /// @brief Gets the Unicode character represented by the current ConsoleKeyInfo object.
      /// @param An char32 object that corresponds to the console key represented by the current ConsoleKeyInfo object.
      property_<char32, readonly_> KeyChar {
        get_ {return this->keyChar;}
      };

      /// @brief Gets a bitwise combination of System::ConsoleModifiers values that specifies one or more modifier keys pressed simultaneously with the console key.
      /// @param A bitwise combination of System::ConsoleModifiers values. There is no default value.
      property_<ConsoleModifiers, readonly_> Modifiers {
        get_ {return this->modifiers;}
      };

      /// @brief Determines whether the specified object is equal to the current object.
      /// @param value The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const ConsoleKeyInfo& value) const { return this->key == value.key && this->keyChar == value.keyChar && this->modifiers == value.modifiers; }

      /// @brief Determines whether this instance of Char and a specified object, which must also be a Char object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const object& obj) const override { return is<ConsoleKeyInfo>(obj) && Equals(static_cast<const ConsoleKeyInfo&>(obj)); }

      /// @brief Serves as a hash function for a particular type.
      /// @return int32 A hash code for the current object.
      virtual int32 GetHashCode() const override { return (int32)this->key ^ (this->keyChar << 16) ^ ((int32)this->modifiers << 24); }

    private:
      char32 keyChar = 0;
      ConsoleKey key = (ConsoleKey)0;
      ConsoleModifiers modifiers = (ConsoleModifiers)0;
    };
  }
}

using namespace Switch;
