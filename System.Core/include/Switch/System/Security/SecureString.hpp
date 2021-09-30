/// @file
/// @brief Contains Switch::System::Security::SecurityException exception.
#pragma once

#include "../Collections/Generic/List.hpp"
#include "../Char.hpp"

/// @cond
namespace Native { class SecurityApi; }
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System.Security namespaces contain classes that represent the Switch Framework security system and permissions. Child namespaces provide types that control access to and audit securable objects, allow authentication, provide crytographic services, control access to operations and resources based on policy, and support rights management of application-created content.
    namespace Security {
      /// @brief The exception that is thrown when a security error is detected.
      /// @remarks SecureString is a string type that provides a measure of security. It tries to avoid storing potentially sensitive strings in process memory as plain text. (For limitations, however, see the How secure is SecureString? section.) The value of an instance of SecureString is automatically protected using a mechanism supported by the underlying platform when the instance is initialized or when the value is modified. Your application can render the instance immutable and prevent further modification by invoking the MakeReadOnly method.
      /// @remarks The maximum length of a SecureString instance is 65,536 characters.
      class core_export_ SecureString final : public object {
      public:
        /// @brief Initializes a new instance of the SecureString class.
        SecureString() {}

        /// @brief This API supports the product infrastructure and is not intended to be used directly from your code. Initializes a new instance of the SecureString class from a subarray of System.Char objects.
        /// @param value A pointer to an array of char.
        /// @param length The number of elements of value to include in the new instance.
        /// @remarks This constructor initializes the new SecureString object to the number of characters in value specified by length; the value of the instance is then encrypted.
        SecureString(const char32 value[], int32 length);

        /// @cond
        SecureString(const SecureString& secureString) : data(secureString.data), readOnly(secureString.readOnly) {}
        ~SecureString() {
          this->readOnly = false;
          this->Clear();
        }
        /// @endcond

        /// @brief Gets the number of characters in the current secure string.
        /// @return int32 The number of System.Char objects in this secure string.
        property_<int32, readonly_> Length {
          get_ {return this->data.Count();}
        };

        /// @brief Appends a character to the end of the current secure string.
        /// @param c A character to append to this secure string.
        /// @exception InvalidOperationException This secure string is read-only.
        /// @remarks If the implementation uses a protection mechanism, such as encryption, the value of this secure string, if any, is unprotected; c is appended; then the new value of the secure string is re-protected.
        void AppendChar(char32 c);

        /// @breif Deletes the value of the current secure string.
        /// @brief The computer memory that contains the value of this secure string is zeroed, then the length of the value of this secure string is set to zero.
        void Clear();

        /// Creates a copy of the current secure string.
        /// @return SecureString A duplicate of this secure string.
        /// @exception InvalidOperationException This secure string is read-only.
        /// @remarks If an instance of a SecureString is marked read-only, the copy of that instance will not be read-only.
        SecureString Copy() const {
          SecureString secureString;
          secureString.data = this->data;
          return secureString;
        }

        /// @brief Inserts a character in this secure string at the specified index position.
        /// @param index The index position where parameter c is inserted.
        /// @param c The character to insert.
        /// @exception InvalidOperationException This secure string is read-only.
        /// @exception ArgumentOutOfRange ndex is less than zero, or greater than the length of this secure string.  -or-  Performing this operation would make the length of this secure string greater than 65,536 characters.
        /// @remarks The index is zero-based; the first character in this secure string is at index position zero.
        /// @remarks If the implementation uses a protection mechanism, such as encryption, the value of the secure string, if any, is unprotected; c is inserted at the specified index position; then the new value is re-protected. The InsertAt method yields the same results as the AppendChar method, which inserts a character at the end of a secure string, if the index parameter of InsertAt is set to the length of this instance.
        void InsertAt(int32 index, char32 c);

        /// @brief Indicates whether this secure string is marked read-only.
        /// @return bool true if this secure string is marked read-only; otherwise, false.
        /// @remarks After an instance of SecureString is marked read-only by the MakeReadOnly method, any attempt to modify the value of the instance throws an InvalidOperationException. Use the IsReadOnly method to test whether a SecureString is read-only before attempting to modify it.
        bool IsReadOnly() const {return this->readOnly;}

        /// @brief Makes the text value of this secure string read-only.
        /// @remarks Initialize the text value of an instance of the SecureString class with the SecureString constructors, and modify the value with the Clear, RemoveAt, SetAt, InsertAt, and AppendChar methods.
        /// @remarks After you have made your final modifications, use the MakeReadOnly method to make the value of the instance immutable (read-only). After the value is marked as read-only, any further attempt to modify it throws an InvalidOperationException.
        /// @remarks The effect of invoking MakeReadOnly is permanent because the SecureString class provides no means to make the secure string modifiable again. Use the IsReadOnly method to test whether an instance of SecureString is read-only.
        void MakeReadOnly() {this->readOnly = true;}

        /// @brief Removes the character at the specified index position from this secure string.
        /// @param index The index position of a character in this secure string.
        /// @exception InvalidOperationException This secure string is read-only.
        /// @exception ArgumentOutOfRange ndex is less than zero, or greater than the length of this secure string.  -or-  Performing this operation would make the length of this secure string greater than 65,536 characters.
        /// @remarks The index is zero-based; the first character in this instance is at index position zero.
        /// @remarks If the implementation uses a protection mechanism, such as encryption, the value of this secure string, if any, is unprotected; the character at the specified index position is removed; then the new value is re-protected.
        void RemoveAt(int32 index);

        /// @brief Replaces the existing character at the specified index position with another character.
        /// @param index The index position of an existing character in this secure string
        /// @param c A character that replaces the existing character.
        /// @exception InvalidOperationException This secure string is read-only.
        /// @exception ArgumentOutOfRange ndex is less than zero, or greater than the length of this secure string.  -or-  Performing this operation would make the length of this secure string greater than 65,536 characters.
        /// @remarks The index is zero-based; the first character in this instance is at index position zero.
        /// @remarks If the implementation uses a protection mechanism, such as encryption, the value of the secure string, if any, is unprotected; c is assigned to the specified index position; then the new value is re-protected.
        void SetAt(int32 index, char32 c);

      private:
        /// @cond
        friend class Native::SecurityApi;
        /// @endcond
        System::Collections::Generic::List<char32> data;
        bool readOnly = false;
      };
    }
  }
}

using namespace Switch;
