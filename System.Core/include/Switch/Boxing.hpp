/// @file
/// @brief Contains Switch::Box and Switch::Unbox operators.
#pragma once
#include "Is.hpp"
#include "Property.hpp"
#include "Static.hpp"
#include "Types.hpp"
#include "System/IComparable.hpp"
#include "System/Object.hpp"

/// @cond
namespace Switch {
  namespace System {
    struct Boolean;
    struct Byte;
    struct Char;
    struct DateTime;
    struct Decimal;
    struct Double;
    struct Int16;
    struct Int32;
    struct Int64;
    struct IntPtr;
    struct SByte;
    class String;
    struct Single;
    struct UInt16;
    struct UInt32;
    struct UInt64;
    struct UIntPtr;
  }
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  template<typename T>
  int32 CompareBoxedType(const T& a, const T& b) {
    return memcmp((const void*)&a, (const void*)&b, sizeof(T));
  }

  template<typename T>
  int32 GetHashCodeFromBoxedType(const T& value) {
    using const_iterator = const byte*;
    const_iterator begin = (const_iterator)&value;
    const_iterator end = begin + sizeof(T);
    int32 hash = 0;
    for (const_iterator it = begin; it != end; ++it)
      hash = 5 * hash + *it;
    return hash;
  }

  /// @cond
  template<typename T>
  struct hash {
    size_t operator()(const T& key) const { return GetHashCode(key); }
  };

  template<typename T>
  struct equal_to {
    bool operator()(const T& a, const T& b) const {return Switch::CompareBoxedType(a, b) == 0; }
  };
  /// @endcond

  template<typename T>
  struct Boxer : public T, public System::Object, public System::IComparable {
  public:
    Boxer() {}
    Boxer(const T& value) : T(value) {}
    Boxer(const Boxer& value) : T(value) {}

    int32 CompareTo(const IComparable& value) const override {return is<T>(value) ? this->CompareTo((const T&)value) : 1;}
    int32 CompareTo(const Boxer& value) const {return this->CompareTo((const T&)value);}
    int32 CompareTo(const T& value) const {return CompareBoxedType((const T&) * this, value);}

    bool Equals(const System::Object& obj) const override {return is<T>(obj) && this->Equals((const T&)obj);}
    bool Equals(const Boxer& value) const {return this->Equals((const T&)value);}
    bool Equals(const T& value) const {return this->CompareTo(value) == 0;}

    int32 GetHashCode() const override {return Switch::GetHashCodeFromBoxedType((const T&) * this);}
  };

  /// @brief Support boxing of type
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0}", ready);                     // console output : ready = 1
  /// Console::WriteLine("ready = {0}", TypeBoxer::Boxing(ready));  // console output : ready = true
  /// @endcode
  class core_export_ TypeBoxer static_ {
  public:
    /// @brief Boxing a bool to a Boolean
    /// @param value bool to Boxing.
    /// @return Boolean boxed value
    static System::Boolean Boxing(bool value);

    /// @brief Boxing a byte to a Byte
    /// @param value byte to Boxing.
    /// @return Byte boxed value
    static System::Byte Boxing(byte value);

    /// @brief Boxing a double to a Double
    /// @param value double to Boxing.
    /// @return Double boxed value
    static System::Double Boxing(double value);

    /// @brief Boxing an int16 to an Int16
    /// @param value int16 to Boxing.
    /// @return Int16 boxed value
    static System::Int16 Boxing(int16 value);

    /// @brief Boxing an int32 to an Int32
    /// @param value int32 to Boxing.
    /// @return Int32 boxed value
    static System::Int32 Boxing(int32 value);

    /// @brief Boxing an int64 to an Int64
    /// @param value int64 to Boxing.
    /// @return Int64 boxed value
    static System::Int64 Boxing(int64 value);

    /// @brief Boxing a sbyte to a SByte
    /// @param value sbyte to Boxing.
    /// @return SByte boxed value
    static System::SByte Boxing(sbyte value);

    /// @brief Boxing a single to a Single
    /// @param value single to Boxing.
    /// @return Single boxed value
    static System::Single Boxing(float value);

    /// @brief Boxing a const char* to a String
    /// @param value const char* to Boxing.
    /// @return String boxed value
    static System::String Boxing(const char* value);

    /// @brief Boxing a const char* to a String
    /// @param value const char* to Boxing.
    /// @return String boxed value
    static System::String Boxing(const wchar* value);

    /// @brief Boxing a const char* to a String
    /// @param value const char* to Boxing.
    /// @return String boxed value
    static System::String Boxing(const char16* value);

    /// @brief Boxing a const char* to a String
    /// @param value const char* to Boxing.
    /// @return String boxed value
    static System::String Boxing(const char32* value);

    /// @brief Boxing a char to a Char
    /// @param value Char to Boxing.
    /// @return Char boxed value
    static System::Char Boxing(char value);

    /// @brief Boxing a char to a Char
    /// @param value Char to Boxing.
    /// @return Char boxed value
    static System::Char Boxing(wchar value);

    /// @brief Boxing a char32 to a Char
    /// @param value Char to Boxing.
    /// @return Char boxed value
    static System::Char Boxing(char16 value);

    /// @brief Boxing a char32 to a Char
    /// @param value Char to Boxing.
    /// @return Char boxed value
    static System::Char Boxing(char32 value);

    /// @brief Boxing an uint16 to an UInt16
    /// @param value uint16 to Boxing.
    /// @return UInt16 boxed value
    static System::UInt16 Boxing(uint16 value);

    /// @brief Boxing an uint32 to an UInt32
    /// @param value uint32 to Boxing.
    /// @return UInt32 boxed value
    static System::UInt32 Boxing(uint32 value);

    /// @brief Boxing an uint64 to an UInt64
    /// @param value uint64 to Boxing.
    /// @return UInt64 boxed value
    static System::UInt64 Boxing(uint64 value);

    /// @cond
    static System::Int64 Boxing(llong value);
    static System::UInt64 Boxing(ullong value);
    /// @endcond

    /// @brief Boxing an void* to an UIntPtr
    /// @param value void* to Boxing.
    /// @return UIntPtr boxed value
    static System::IntPtr Boxing(void* value);

    /// @cond
    template<typename T>
    static const T& Boxing(const T& value) {return value;}
    /// @endcond
  };

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);                         // console output : ready = true
  /// Console::WriteLine("ready = {0}", TypeUnboxer::Unboxing(ready));  // console output : ready = 1
  /// @endcode
  class core_export_ TypeUnboxer static_ {
  public:
    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static bool Unboxing(const System::Boolean& value);

    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static byte Unboxing(const System::Byte& value);

    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static double Unboxing(const System::Double& value);

    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static System::DateTime Unboxing(const System::DateTime& value);

    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static int16 Unboxing(const System::Int16& value);

    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static int32 Unboxing(System::Int32& value);

    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static int32 Unboxing(const System::Int32& value);

    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static int64 Unboxing(const System::Int64& value);

    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static intptr Unboxing(const System::IntPtr& value);

    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static sbyte Unboxing(const System::SByte& value);

    /// @brief Unboxing a Boolean type to a bool Type
    /// @param value Boolean to Unboxing.
    /// @return bool unboxed value
    static float Unboxing(const System::Single& value);

    /// @brief Unboxing a String type to a bool Type
    /// @param value String to Unboxing.
    /// @return bool unboxed value
    static const char* Unboxing(const System::String& value);

    /// @brief Unboxing a Char type to a char32 Type
    /// @param value Char to Unboxing.
    /// @return char32 unboxed value
    static char32 Unboxing(const System::Char& value);

    /// @brief Unboxing an UInt16 type to an uint16 Type
    /// @param value UInt16 to Unboxing.
    /// @return uint16 unboxed value
    static uint16 Unboxing(const System::UInt16& value);

    /// @brief Unboxing an UInt32 type to an uint32 Type
    /// @param value UInt32 to Unboxing.
    /// @return uint32 unboxed value
    static uint32 Unboxing(const System::UInt32& value);

    /// @brief Unboxing an UInt64 type to an uint64 Type
    /// @param value UInt64 to Unboxing.
    /// @return uint64 unboxed value
    static uint64 Unboxing(const System::UInt64& value);

    /// @brief Unboxing a UIntPtr type to a void* Type
    /// @param value UIntPtr to Unboxing.
    /// @return void* unboxed value
    static uintptr Unboxing(const System::UIntPtr& value);

    /// @cond
    template<typename T>
    static const T& Unboxing(const T& value) {return value;}
    /// @endcond
  };

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::Boolean Box(bool value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::Byte Box(byte value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::Double Box(double value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::Int16 Box(int16 value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::Int32 Box(int32 value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::Int64 Box(int64 value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::SByte Box(sbyte value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// @remarks Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::Single Box(float value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::String Box(const char* value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::String Box(const wchar* value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::String Box(const char16* value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::String Box(const char32* value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::Char Box(char value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::Char Box(wchar value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::Char Box(char16 value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::Char Box(char32 value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::UInt16 Box(uint16 value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::UInt32 Box(uint32 value);

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::UInt64 Box(uint64 value);

  /// @cond
  core_export_ System::Int64 Box(llong value);
  core_export_ System::UInt64 Box(ullong value);
  /// @endcond

  /// @brief Support boxing of type.
  /// You can use this when you want convert an unboxed type to a boxed type (e.g. int32 to Int32)
  /// @remarks Is an alias on Switch::TypeBoxer.
  /// @par Examples
  /// @code
  /// bool ready = true;
  /// @remarks Console::WriteLine("ready = {0]", ready);       // console output : ready = 1
  /// Console::WriteLine("ready = {0}", Box(ready));  // console output : ready = true
  /// @endcode
  core_export_ System::IntPtr Box(void* value);

  /// @cond
  template<typename T>
  inline const T& Box(const T& value) {return TypeBoxer::Boxing(value);}

  template<typename T, typename Attribute>
  inline T Box(const property_<T, Attribute>& value) {return T(Box(value()));}
  /// @endcond

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ bool Unbox(const System::Boolean& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// @remarks Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// @remarks Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ byte Unbox(const System::Byte& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ double Unbox(const System::Double& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ System::DateTime Unbox(const System::DateTime& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ int16 Unbox(const System::Int16& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ int32 Unbox(System::Int32& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ int32 Unbox(const System::Int32& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ int64 Unbox(const System::Int64& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ intptr Unbox(const System::IntPtr& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ sbyte Unbox(const System::SByte& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ float Unbox(const System::Single& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ const char* Unbox(const System::String& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ char32 Unbox(const System::Char& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ uint16 Unbox(const System::UInt16& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ uint32 Unbox(const System::UInt32& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ uint64 Unbox(const System::UInt64& value);

  /// @brief Support unboxing of type
  /// You can use this when you want convert a boxed type to an unboxed type (e.g. Int32 to int32)
  /// @remarks Is an alias on Switch::TypeUnboxer.
  /// @par Examples
  /// @code
  /// Boolean ready = true;
  /// Console::WriteLine("ready = {0}", ready);         // console output : ready = true
  /// Console::WriteLine("ready = {0}", Unbox(ready));  // console output : ready = 1
  /// @endcode
  core_export_ uintptr Unbox(const System::UIntPtr& value);

  /// @cond
  template<typename T>
  inline T& Unbox(T& value) {return TypeUnboxer::Unboxing(value);}

  template<typename T>
  inline const T& Unbox(const T& value)  {return TypeUnboxer::Unboxing(value);}
  /// @endcond
}

using namespace Switch;
