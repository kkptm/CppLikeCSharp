/// @file
/// @brief Contains #abstract_ keyword.
#pragma once

#include "System/Object.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent an abstract class.
  /// @ingroup SwitchCore
  struct core_export_ Abstract : public System::Object {
    ~Abstract() override = 0;
  };

  /// @brief This keyword is used to represents an abstract class.
  /// @par Examples
  /// @code
  /// #include <Switch/Switch>
  ///
  /// using namespace System;
  ///
  /// namespace TestReader {
  ///   class TextReader abstract_ {
  ///   public:
  ///     virtual int ReadByte() = 0;
  ///
  ///     string ReadLine() {
  ///       string line;
  ///       for (int b = ReadByte(); b != -1 && b != '\n'; b = ReadByte())
  ///         line += as<char32>(b);
  ///       return line;
  ///     }
  ///
  ///     string ReadText() {
  ///       string text;
  ///       for (int b = ReadByte(); b != -1; b = ReadByte())
  ///         text += as<char32>(b);
  ///       return text;
  ///     }
  ///   };
  ///
  ///   class StringReader : public TextReader {
  ///   public:
  ///     StringReader(const string& value) : enumerator(value.GetEnumerator()) {}
  ///
  ///     int ReadByte() override {
  ///       if (this->enumerator.MoveNext() == false)
  ///         return -1;
  ///       return as<int>(this->enumerator.Current());
  ///     }
  ///
  ///   private:
  ///     System::Collections::Generic::Enumerator<char32> enumerator;
  ///   };
  ///
  ///   class Program {
  ///   public:
  ///     static void Main() {
  ///       string text = "Line 1\nLine 2\nLine 3";
  ///
  ///       StringReader sr(text);
  ///       Console::WriteLine(sr.ReadLine());
  ///     }
  ///   };
  /// }
  ///
  /// startup_(TestReader::Program)
  /// @endcode
  /// @ingroup Keywords
#define abstract_ \
: public Abstract
}

using namespace Switch;
