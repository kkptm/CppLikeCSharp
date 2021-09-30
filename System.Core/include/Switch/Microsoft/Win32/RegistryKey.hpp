/// @file
/// @brief Contains Switch::Microsoft::Win32::RegistryKey class.
#pragma once

#include "../../System/Object.hpp"
#include "../../System/Convert.hpp"
#include "../../System/Environment.hpp"
#include "../../System/String.hpp"
#include "../../System/UnauthorizedAccessException.hpp"
#include "../../System/Collections/Generic/Dictionary.hpp"
#include "../../Boxing.hpp"
#include "RegistryHive.hpp"
#include "RegistryKeyPermissionCheck.hpp"
#include "RegistryValueKind.hpp"

namespace Switch {
  /// @brief The Microsoft namespace provide Microsoft specific classes.
  namespace Microsoft {
    namespace Win32 {
      /// @brief Represents a key-level node in the Windows registry. This class is a registry encapsulation.
      class core_export_ RegistryKey : public object {
      private:
        friend class Registry;
        RegistryKey(RegistryHive hkey);

      public:
        /// @cond
        RegistryKey();
        RegistryKey(const RegistryKey& rk) : handle(rk.handle), name(rk.name), path(rk.path), permission(rk.permission), values(rk.values) {}

        RegistryKey& operator=(const RegistryKey& rk) {
          this->handle = rk.handle;
          this->name = rk.name;
          this->path = rk.path;
          this->permission = rk.permission;
          this->values = rk.values;
          return *this;
        }

        static const RegistryKey Null;

        virtual ~RegistryKey();
        /// @endcond

        /// @brief Gets a SafeRegistryHandle object that represents the registry key that the current RegistryKey object encapsulates.
        /// @return intptr The handle to the registry key.
        intptr Handle() const { return this->handle->Handle(); }

        /// @brief Retrieves the name of the key.
        /// @return System::String The absolute (qualified) name of the key.
        const System::String& Name() const { return this->name; }

        /// @brief Retrieves the count of subkeys of the current key.
        /// @return Int32 The number of subkeys of the current key.
        int32 SubKeyCount() const;

        /// @brief Retrieves the count of subkeys of the current key.
        /// @return Int32 The number of subkeys of the current key.
        int32 ValueCount() const {
          return this->values.Count;
        }

        /// @brief Closes the key and flushes it to disk if its contents have been modified.
        /// @remarks Calling this method on system keys will have no effect, because system keys are never closed.
        /// @remarks This method does nothing if you call it on an instance of RegistryKey that is already closed.
        void Close();

        /// @brief Creates a new subkey or opens an existing subkey for write access.
        /// @param subKey The name or path of the subkey to create or open. This System::String is ! case-sensitive.
        /// @return RegistryKey The newly created subkey, or RegistryKey::Null() if the operation failed. If a zero-length System::String is specified for subkey, the current RegistryKey object is returned.
        /// @remarks In order to perform this action, the user must have permission at this level and below in the registry hierarchy.
        /// @exception ArgumentNullException subKey is null.
        /// @exception UnauthorizedAccessException The RegistryKey cannot be written to; for example, it was ! opened as a writable key , or the user does ! have the necessary access rights.
        /// @exception IOException The nesting level exceeds 510. -or- A system error occurred, such as deletion of the key, or an attempt to create a key in the LocalMachine root.
        RegistryKey CreateSubKey(const System::String& subKey) { return this->CreateSubKey(subKey, Switch::Microsoft::Win32::RegistryKeyPermissionCheck(Switch::Microsoft::Win32::RegistryKeyPermissionCheck::ReadWriteSubTree)); }

        /// @brief Creates a new subkey or opens an existing subkey with the specified access.
        /// @param subKey TThe name or path of the subkey to create or open. This System::String is ! case-sensitive.
        /// @param writable true to indicate the new subkey is writable; otherwise, false.
        /// @return RegistryKey The newly created subkey, or RegistryKey::Null() if the operation failed. If a zero-length System::String is specified for subkey, the current RegistryKey object is returned.
        /// @remarks In order to perform this action, the user must have permission at this level and below in the registry hierarchy.
        /// @exception ArgumentNullException subKey is null.
        /// @exception UnauthorizedAccessException The RegistryKey cannot be written to; for example, it was ! opened as a writable key , or the user does ! have the necessary access rights.
        /// @exception IOException The nesting level exceeds 510. -or- A system error occurred, such as deletion of the key, or an attempt to create a key in the LocalMachine root.
        RegistryKey CreateSubKey(const System::String& subKey, bool writable) { return this->CreateSubKey(subKey, RegistryKeyPermissionCheck(writable ? RegistryKeyPermissionCheck::ReadWriteSubTree : RegistryKeyPermissionCheck::ReadSubTree)); }

        /// @brief Creates a new subkey or opens an existing subkey for write access, using the specified permission check option.
        /// @param subKey The name or path of the subkey to create or open. This System::String is ! case-sensitive.
        /// @param permissionCheck One of the enumeration values that specifies whether the key is opened for read or read/write access.
        /// @return RegistryKey The newly created subkey, or RegistryKey::Null() if the operation failed. If a zero-length System::String is specified for subkey, the current RegistryKey object is returned.
        /// @remarks In order to perform this action, the user must have permission at this level and below in the registry hierarchy.
        /// @exception ArgumentNullException subKey is null.
        /// @exception UnauthorizedAccessException The RegistryKey cannot be written to; for example, it was ! opened as a writable key , or the user does ! have the necessary access rights.
        /// @exception IOException The nesting level exceeds 510. -or- A system error occurred, such as deletion of the key, or an attempt to create a key in the LocalMachine root.
        RegistryKey CreateSubKey(const System::String& subKey, RegistryKeyPermissionCheck permissionCheck);

        /// @brief Deletes the specified subkey.
        /// @param subKey The name of the subkey to delete. This System::String is ! case-sensitive.
        /// @remarks To delete child subkeys, use DeleteSubKeyTree.
        /// @remarks Use caution when deleting registry keys.
        /// @exception InvalidOperationException The subkey has child subkeys.
        /// @exception ArgumentException The subkey parameter does ! specify a valid registry key.
        /// @exception ArgumentNullException subKey is null.
        /// @exception UnauthorizedAccessException The user does ! have the necessary registry rights.
        void DeleteSubKey(const System::String& subKey) { this->DeleteSubKey(subKey, true); }

        /// @brief Deletes the specified subkey, and specifies whether an exception is raised if the subkey is ! found.
        /// @param subKey The name of the subkey to delete. This System::String is ! case-sensitive.
        /// @param throwOnMissingSubKey Indicates whether an exception should be raised if the value cannot be found.
        /// @remarks To delete child subkeys, use DeleteSubKeyTree.
        /// @remarks Use caution when deleting registry keys.
        /// @exception InvalidOperationException The subkey has child subkeys.
        /// @exception ArgumentException The subkey parameter does ! specify a valid registry key.
        /// @exception ArgumentNullException subKey is null.
        /// @exception UnauthorizedAccessException The user does ! have the necessary registry rights.
        void DeleteSubKey(const System::String& subKey, bool throwOnMissingSubKey);

        /// @brief Deletes a subkey and any child subkeys recursively.
        /// @param name The subkey to delete. This System::String is ! case-sensitive.
        /// @remarks You must have appropriate permissions to delete the subkey and its tree.
        /// @exception ArgumentNullException subKey is null.
        /// @exception ArgumentException Deletion of a root hive is attempted. -or- subKey does ! specify a valid registry subkey.
        /// @exception IOException An I/O error has occurred.
        /// @exception UnauthorizedAccessException The user does ! have the necessary registry rights.
        void DeleteSubKeyTree(const System::String& name) { this->DeleteSubKeyTree(name, true); }

        /// @brief Deletes the specified subkey and any child subkeys recursively, and specifies whether an exception is raised if the subkey is ! found.
        /// @param name The subkey to delete. This System::String is ! case-sensitive.
        /// @param throwOnMissingSubKey Indicates whether an exception should be raised if the value cannot be found.
        /// @remarks You must have appropriate permissions to delete the subkey and its tree.
        /// @exception ArgumentNullException subKey is null.
        /// @exception ArgumentException Deletion of a root hive is attempted. -or- subKey does ! specify a valid registry subkey.
        /// @exception IOException An I/O error has occurred.
        /// @exception UnauthorizedAccessException The user does ! have the necessary registry rights.
        void DeleteSubKeyTree(const System::String& name, bool throwOnMissingSubKey);

        /// @brief Deletes the specified value from this key.
        /// @param name The name of the value to delete.
        /// @exception ArgumentException name is ! a valid reference to a value.
        /// @exception UnthorizedAccessException The RegistryKey being manipulated is read-only.
        void DeleteValue(const System::String& name) { this->DeleteValue(name, true); }

        /// @brief Deletes the specified value from this key, and specifies whether an exception is raised if the value is ! found.
        /// @param name The name of the value to delete.
        /// @param throwOnMissingSubKey Indicates whether an exception should be raised if the value cannot be found.
        /// @exception ArgumentException name is ! a valid reference to a value.
        /// @exception UnthorizedAccessException The RegistryKey being manipulated is read-only.
        void DeleteValue(const System::String& name, bool throwOnMissingValue) {
          if (this->permission != RegistryKeyPermissionCheck::ReadWriteSubTree)
            throw System::UnauthorizedAccessException(caller_);

          if ((this->values.ContainsKey(name.ToLower()) == false || this->values.Remove(name.ToLower()) == false) && throwOnMissingValue == true)
            throw System::ArgumentException(caller_);

          this->Flush();
        }

        /// @brief Determines whether this instance of RegistryKey and a specified object, which must also be a RegistryKey object, have the same value.
        /// @param value The RegistryKey to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        bool Equals(const RegistryKey& value) const { return this->handle == value.handle && this->name == value.name && this->path == value.path; }

        /// @brief Determines whether this instance of RegistryKey and a specified object, which must also be a RegistryKey object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override { return is<RegistryKey>(obj) && Equals(static_cast<const RegistryKey&>(obj)); }

        /// @brief Retrieves an array of strings that contains all the subkey names.
        System::Array<System::String> GetSubKeyNames();

        const object& GetValue(const System::String& name) const {
          if (! this->values.ContainsKey(name.ToLower()))
            return Null;

          return this->values[name.ToLower()].Value();
        }

        template<typename T>
        const object& GetValue(const System::String& name, const T& defaultValue) const {
          return this->GetValue(name, Switch::Box(defaultValue), true);
        }

        RegistryValueKind GetValueKind(const System::String& name) const  {
          if (! values.ContainsKey(name.ToLower()))
            throw System::InvalidOperationException(caller_);

          return values[name.ToLower()].Kind();
        }

        /// @brief Retrieves an array of strings that contains all the value names associated with this key..
        System::Array<System::String> GetValueNames() { return System::Array<System::String>(values.Keys()); }

        /// @brief Writes all the attributes of the specified open registry key into the registry.
        /// @remarks It is ! necessary to call Flush to write out changes to a key. Registry changes are flushed to disk when the registry uses its lazy flusher. Lazy flushing occurs automatically and regularly after a system-specified time interval. Registry changes are also flushed to disk at system shutdown.
        /// @remarks Unlike Close, the Flush function returns only when all the data has been written to the registry.
        /// @remarks The Flush function might also write out parts of or all of the other keys. Calling this function excessively can have a negative effect on an application's performance.
        /// @remarks An application should only call Flush if it must be absolute certain that registry changes are recorded to disk. In general, Flush rarely, if ever, need be used.
        void Flush();

        /// @brief Retrieves a subkey as read-only.
        /// @param hKey The name or path of the subkey to open as read-only.
        static RegistryKey OpenBaseKey(RegistryHive hKey) { return RegistryKey(hKey); }
        //static RegistryKey OpenBaseKey(RegistryHive hKey, RegistryView view) { return RegistryKey(hKey); }

        /// @brief Retrieves a subkey as read-only.
        /// @param name The name or path of the subkey to open as read-only.
        RegistryKey OpenSubKey(const System::String& name) { return OpenSubKey(name, RegistryKeyPermissionCheck(RegistryKeyPermissionCheck::ReadSubTree)); }

        /// @brief Retrieves a subkey as read-only.
        /// @param name The name or path of the subkey to open as read-only.
        /// @param writable Set to true if you need write access to the key.
        RegistryKey OpenSubKey(const System::String& name, System::Boolean writable) { return OpenSubKey(name, writable ? RegistryKeyPermissionCheck::ReadWriteSubTree : RegistryKeyPermissionCheck::ReadSubTree); }

        /// @brief Retrieves a subkey as read-only.
        /// @param name The name or path of the subkey to open as read-only.
        /// @param permissionCheck One of the enumeration values that specifies whether the key is opened for read or read/write access.
        RegistryKey OpenSubKey(const System::String& name, RegistryKeyPermissionCheck permissionCheck);

        /// @brief Sets the specified name/value pair.
        /// @param name The name of the value to store.
        /// @param value The data to be stored.
        template<typename T>
        void SetValue(const System::String& name, T value) {
          if (this->permission != RegistryKeyPermissionCheck::ReadWriteSubTree)
            throw System::UnauthorizedAccessException(caller_);
          if (is<System::Int32>(Switch::Box(value)))
            this->values[name.ToLower()] = RegistryKeyValue(name, Switch::Box(value), Switch::Microsoft::Win32::RegistryValueKind::DWord);
          else if (is<System::Array<System::String>>(Switch::Box(value)))
            this->values[name.ToLower()] = RegistryKeyValue(name, Switch::Box(value), Switch::Microsoft::Win32::RegistryValueKind::MultiString);
          else if (is<System::Array<byte>>(Switch::Box(value)))
            this->values[name.ToLower()] = RegistryKeyValue(name, Switch::Box(value), Switch::Microsoft::Win32::RegistryValueKind::Binary);
          else
            this->values[name.ToLower()] = RegistryKeyValue(name, Switch::Box(value).ToString(), Switch::Microsoft::Win32::RegistryValueKind::String);
          Flush();
        }

        /// @brief Sets the value of a name/value pair in the registry key, using the specified registry data type.
        /// @param name The name of the value to be stored.
        /// @param value The data to be stored.
        /// @param valueKind The registry data type to use when storing the data.
        template<typename T>
        void SetValue(const System::String& name, T value, Switch::Microsoft::Win32::RegistryValueKind valueKind) {
          if (this->permission != RegistryKeyPermissionCheck::ReadWriteSubTree)
            throw System::UnauthorizedAccessException(caller_);
          switch (valueKind) {
          case RegistryValueKind::Binary: this->values[name.ToLower()] = RegistryKeyValue(name, Switch::Box(value), valueKind); break;
          case RegistryValueKind::MultiString: this->values[name.ToLower()] = RegistryKeyValue(name, Switch::Box(value), valueKind); break;
          case RegistryValueKind::DWord: this->values[name.ToLower()] = RegistryKeyValue(name, Switch::Box(System::Convert::ToInt32(value)), valueKind); break;
          case RegistryValueKind::QWord: this->values[name.ToLower()] = RegistryKeyValue(name, Switch::Box(System::Convert::ToInt64(value)), valueKind); break;
          default: this->values[name.ToLower()] = RegistryKeyValue(name, Switch::Box(value).ToString(), valueKind); break;
          }
          Flush();
        }

        /// @brief Retrieves a string representation of this key.
        /// @return A string representing the key. If the specified key is invalid (cannot be found) then "" is returned.
        System::String ToString() const override { return this->name; }

      private:
        void Load();

        template<typename T>
        const object& GetValue(const System::String& name, const T& defaultValue, bool) const {
          if (! this->values.ContainsKey(name.ToLower())) {
            static refptr<object> value;
            value = new T(defaultValue);
            return value.ToObject();
          }
          return this->values[name.ToLower()].Value();
        }

        static bool IsBaseKey(const System::String& subKey) { return subKey == "HKEY_CLASSES_ROOT" || subKey == "HKEY_CURRENT_USER" || subKey == "HKEY_LOCAL_MACHINE" || subKey == "HKEY_USERS" || subKey == "HKEY_PERFORMANCE_DATA" || subKey == "HKEY_CURRENT_CONFIG" || subKey == "HKEY_DYN_DATA"; }

        static System::String ToName(RegistryHive rhive) {
          switch (rhive) {
          case RegistryHive::ClassesRoot: return "HKEY_CLASSES_ROOT";
          case RegistryHive::CurrentUser: return "HKEY_CURRENT_USER";
          case RegistryHive::LocalMachine: return "HKEY_LOCAL_MACHINE";
          case RegistryHive::Users: return "HKEY_USERS";
          case RegistryHive::PerformanceData: return "HKEY_PERFORMANCE_DATA";
          case RegistryHive::CurrentConfig: return "HKEY_CURRENT_CONFIG";
          case RegistryHive::DynData: return "HKEY_DYN_DATA";
          default: throw System::ArgumentException(caller_);
          }
        }

        class RegistryKeyValue : public object {
        public:
          RegistryKeyValue() {}
          RegistryKeyValue(const RegistryKeyValue& rkv) : key(rkv.key), value(rkv.value), kind(rkv.kind) {}
          template<typename T>
          RegistryKeyValue(const System::String& key, T value, RegistryValueKind kind) : key(key), value(new T(value)), kind(kind) {
            switch (kind) {
            case RegistryValueKind::Binary : if (! is<System::Array<byte>>(value)) throw System::ArgumentException(caller_); break;
            case RegistryValueKind::DWord : if (! is<System::Int32>(value)) throw System::ArgumentException(caller_); break;
            case RegistryValueKind::MultiString : if (! is<System::Array<System::String>>(value)) throw System::ArgumentException(caller_); break;
            case RegistryValueKind::QWord : if (! is<System::Int64>(value)) throw System::ArgumentException(caller_); break;
            default: if (! is<System::String>(value)) throw System::ArgumentException(caller_); break;
            }
          }

          RegistryKeyValue& operator=(const RegistryKeyValue& rkv) {
            this->key = rkv.key;
            this->value = rkv.value;
            this->kind = rkv.kind;
            return *this;
          }

          const System::String& Key() const { return this->key; }
          const object& Value() const {
            if (this->kind == RegistryValueKind::ExpandString) {
              static string expandedValue;
              expandedValue = System::Environment::ExpandEnvironmentVariables(as<string>(this->value)());
              return expandedValue;
            }
            return this->value();
          }
          RegistryValueKind Kind() const { return this->kind; }

          static RegistryKeyValue Parse(const System::String& s) {
            try {
              RegistryKeyValue rkv;
              System::String toParse = s.Remove(s.IndexOf("</Value>"));
              toParse = toParse.Substring(toParse.IndexOf("<Value>") + 7);
              toParse = toParse.Replace(System::Environment::NewLine, "");
              rkv.key = toParse.Remove(toParse.IndexOf("\"Kind=")).Substring(toParse.IndexOf("Key=\"") + 5);
              toParse = toParse.Remove(0, toParse.IndexOf("\"Kind=\"") + 1);
              rkv.kind = (RegistryValueKind)System::Enum<>::Parse<RegistryValueKind>(toParse.Remove(toParse.IndexOf("\">")).Substring(toParse.IndexOf("Kind=\"") + 6));
              toParse = toParse.Remove(0, toParse.IndexOf("\">"));
              toParse = toParse.Substring(toParse.IndexOf("\">") + 2);

              switch (rkv.kind) {
              case RegistryValueKind::DWord: rkv.value = ref_new<System::Int32>(System::Int32::Parse(toParse)); break;
              case RegistryValueKind::QWord: rkv.value = ref_new<System::Int64>(System::Int64::Parse(toParse)); break;
              case RegistryValueKind::String: rkv.value = ref_new<string>(toParse); break;
              case RegistryValueKind::ExpandString: rkv.value = ref_new<string>(toParse); break;
              case RegistryValueKind::Binary: rkv.value = ref_new<System::Array<byte>>(ParseBytes(toParse)); break;
              case RegistryValueKind::MultiString: rkv.value = ref_new<System::Array<System::String>>(ParseStrings(toParse)); break;
              default:
                break;
              }
              return rkv;
            } catch (const System::Exception&) {
              throw System::FormatException(caller_);
            }
          }

          System::String ToString() const {
            System::String value;
            if (this->kind == RegistryValueKind::Binary) {
              for (byte item : as<System::Array<byte>>(*this->value))
                value = System::String::Format("{0}{1:X2}", value, item);
            } else if (this->kind == RegistryValueKind::MultiString)
              value = System::String::Format("\n<String>{0}</String>\n", System::String::Join("</String>\n<String>", as<System::Array<System::String>>(*this->value)));
            else
              value = this->value->ToString();

            return System::String::Format("<Value Key=\"{0}\"{1}Kind=\"{2}\">{3}</Value>", this->key, System::Environment::NewLine, this->kind, value);
          }

        private:
          friend class RegistryKey;
          const object& InternalValue() const {return this->value();}

          static System::Array<byte> ParseBytes(const System::String& s) {
            try {
              System::Array<byte> bytes;
              System::String toParse = s;
              while (! string::IsNullOrEmpty(toParse)) {
                System::Array<>::Resize(bytes, bytes.Length + 1);
                bytes[bytes.Length - 1] = System::Byte::Parse(toParse.Remove(2), 16);
                toParse = toParse.Substring(2);
              }
              return bytes;
            } catch (const System::Exception&) {
              throw System::FormatException(caller_);
            }
          }

          static System::Array<System::String> ParseStrings(const System::String& s) {
            try {
              System::Array<System::String> strings;
              System::String toParse = s;
              while (! string::IsNullOrEmpty(toParse)) {
                System::Array<>::Resize(strings, strings.Length + 1);
                strings[strings.Length - 1] = toParse.Remove(toParse.IndexOf("</String>")).Substring(toParse.IndexOf("<String>") + 8);
                toParse = toParse.Substring(toParse.IndexOf("</String>") + 9);
              }
              return strings;
            } catch (const System::Exception&) {
              throw System::FormatException(caller_);
            }
          }

          System::String key;
          refptr<object> value;
          RegistryValueKind kind;
        };

        class RegistryHandle : public object {
        public:
          RegistryHandle() : handle((intptr)this) {}
          RegistryHandle(intptr handle) : handle(handle) {}
          RegistryHandle(intptr key, const System::String& name);
          RegistryHandle(RegistryHive rhive);
          ~RegistryHandle();

          intptr Handle() const { return this->handle; }
          void Handle(intptr handle) { this->handle = handle; }

          bool Equals(const RegistryHandle& value) const { return this->handle == value.handle; }

          bool Equals(const object& obj) const override { return is<RegistryHandle>(obj) && Equals(static_cast<const RegistryHandle&>(obj)); }

        private:
          intptr handle;
        };

        refptr<RegistryHandle> handle;
        System::String name;
        System::String path;
        RegistryKeyPermissionCheck permission;
        System::Collections::Generic::Dictionary<System::String, RegistryKeyValue> values;
      };
    }
  }
}
