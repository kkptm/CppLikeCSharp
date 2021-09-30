/// @file
/// @brief Contains Switch::System::IO::TextWriter class.
#pragma once

#include "../../Property.hpp"
#include "../../Types.hpp"
#include "../../RefPtr.hpp"
#include "../Boolean.hpp"
#include "../Byte.hpp"
#include "../Char.hpp"
#include "../Decimal.hpp"
#include "../Double.hpp"
#include "../Environment.hpp"
#include "../Int16.hpp"
#include "../Int32.hpp"
#include "../Int64.hpp"
#include "../SByte.hpp"
#include "../Single.hpp"
#include "../String.hpp"
#include "../UInt16.hpp"
#include "../UInt32.hpp"
#include "../UInt64.hpp"
#include "../Object.hpp"
#include "../Text/Encoding.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @cond
      class NullTextWriter;
      class SynchronizedTextWriter;
      /// @endcond

      /// @brief Represents a writer that can write a sequential series of characters.
      class core_export_ TextWriter: public Object {
      public:
        /// @brief Provides a TextWriter with no backing store that can be written to, but not read from.
        /// @remarks Use cNull to redirect output to a stream that will not consume any operating system resources.
        /// @remarks When the TextWriter::Write methods are invoked on cNull, the call simply returns, and no data is actually written to any backing store.
        static NullTextWriter& Null();

        /// @brief When overridden in a derived class, returns the character encoding in which the output is written.
        property_<Text::Encoding&, readonly_> Encoding {
          get_->Text::Encoding& {return this->GetEncoding();}
        };

        /// @brief Gets or sets the line terminator string used by the current TextWriter.
        property_<const string&> NewLine {
          get_->const string& {return this->GetNewLine();},
          set_ {this->SetNewLine(value);}
        };

        /// @brief Closes the current writer and releases any system resources associated with the writer.
        virtual void Close() { }

        /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
        /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
        virtual void Flush() { }

        /// @brief Creates a thread-safe (synchronized) wrapper around the specified TextWriter object.
        /// @param writer The TextWriter object to synchronize.
        /// @return TextWriter A thread-safe TextWriter object.
        static SynchronizedTextWriter Synchronised(TextWriter& writer);

        /// @brief Writes the specified bool value to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void Write(bool value) {this->Write(Boolean(value).ToString());}

        /// @brief Writes the specified Char value to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void Write(char32 value) {this->Write(Char(value).ToString());}

        /// @brief Writes the specified double value to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void Write(double value) {this->Write(Double(value).ToString());}

        /// @brief Writes the specified int32 value to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void Write(int32 value) {this->Write(Int32(value).ToString());}

        /// @brief Writes the specified int64 value to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void Write(int64 value) {this->Write(Int64(value).ToString());}

        /// @brief Writes the specified Single value to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void Write(float value) {this->Write(Single(value).ToString());}

        /// @brief Writes the specified UInt32 value to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void Write(uint32 value) {this->Write(UInt32(value).ToString());}

        /// @brief Writes the specified uint64 value to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void Write(uint64 value) {this->Write(UInt64(value).ToString());}

        /// @cond
        void Write(const char* value) {this->Write(String(value));}
        void Write(const wchar* value) {this->Write(String(value));}
        void Write(const char16* value) {this->Write(String(value));}
        void Write(const char32* value) {this->Write(String(value));}
        void Write(const std::string& value) {this->Write(String(value));}
        void Write(const std::wstring& value) {this->Write(String(value));}
        /// @endcond

        void Write(const String& format, const Array< ref<Object>>& array) {this->Write(String::Format(format, array));}

        template<typename T0>
        void Write(const String& format, const T0& arg0) {
          this->Write(String::Format(format, arg0));
        }

        template<typename T0, typename T1>
        void Write(const String& format, const T0& arg0, const T1& arg1) {
          this->Write(String::Format(format, arg0, arg1));
        }

        template<typename T0, typename T1, typename T2>
        void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2) {
          this->Write(String::Format(format, arg0, arg1, arg2));
        }

        template<typename T0, typename T1, typename T2, typename T3>
        void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3) {
          this->Write(String::Format(format, arg0, arg1, arg2, arg3));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4>
        void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4) {
          this->Write(String::Format(format, arg0, arg1, arg2, arg3, arg4));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
        void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5) {
          this->Write(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
        void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6) {
          this->Write(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
        void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7) {
          this->Write(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
        void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7, const T8& arg8) {
          this->Write(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
        void Write(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7, const T8& arg8, const T9& arg9) {
          this->Write(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9));
        }

        /// @brief Writes the current line terminator to the text stream.
        /// @exception IO::IOException An I/O error occurs.
        void WriteLine() {this->Write(this->newLine);}

        /// @brief Writes the specified bool value, followed by the current line terminator, to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void WriteLine(bool value) {this->WriteLine(Boolean(value).ToString());}

        /// @brief Writes the specified Char value, followed by the current line terminator, to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void WriteLine(char32 value) {this->WriteLine(Char(value).ToString());}

        /// @brief Writes the specified double value, followed by the current line terminator, to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void WriteLine(double value) {this->WriteLine(Double(value).ToString());}

        /// @brief Writes the specified int32 value, followed by the current line terminator, to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void WriteLine(int32 value) {this->WriteLine(Int32(value).ToString());}

        /// @brief Writes the specified int64 value, followed by the current line terminator, to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void WriteLine(int64 value) {this->WriteLine(Int64(value).ToString());}

        /// @brief Writes the specified Single value, followed by the current line terminator, to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void WriteLine(float value) {this->WriteLine(Single(value).ToString());}

        /// @brief Writes the specified UInt32 value, followed by the current line terminator, to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void WriteLine(uint32 value) {this->WriteLine(UInt32(value).ToString());}

        /// @brief Writes the specified uint64 value, followed by the current line terminator, to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        void WriteLine(uint64 value) {this->WriteLine(UInt64(value).ToString());}

        /// @cond
        void WriteLine(const char* value) {this->WriteLine(String(value));}
        void WriteLine(const wchar* value) {this->WriteLine(String(value));}
        void WriteLine(const char16* value) {this->WriteLine(String(value));}
        void WriteLine(const char32* value) {this->WriteLine(String(value));}
        void WriteLine(const std::string& value) {this->WriteLine(String(value));}
        void WriteLine(const std::wstring& value) {this->WriteLine(String(value));}
        /// @endcond

        /// @brief Writes the specified String value, followed by the current line terminator, to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        /// @exception ArgumentNullException value is null
        virtual void WriteLine(const String& value) {
          this->Write(value);
          this->WriteLine();
        }

        /// @brief Writes the specified String value to the text stream.
        /// @param value The value to write
        /// @exception IO::IOException An I/O error occurs.
        virtual void Write(const String&) { }

        void WriteLine(const String& format, const Array< ref<Object>>& array) {this->WriteLine(String::Format(format, array));}

        template<typename T0>
        void WriteLine(const String& format, const T0& arg0) {
          this->WriteLine(String::Format(format, arg0));
        }

        template<typename T0, typename T1>
        void WriteLine(const String& format, const T0& arg0, const T1& arg1) {
          this->WriteLine(String::Format(format, arg0, arg1));
        }

        template<typename T0, typename T1, typename T2>
        void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2) {
          this->WriteLine(String::Format(format, arg0, arg1, arg2));
        }

        template<typename T0, typename T1, typename T2, typename T3>
        void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3) {
          this->WriteLine(String::Format(format, arg0, arg1, arg2, arg3));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4>
        void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4) {
          this->WriteLine(String::Format(format, arg0, arg1, arg2, arg3, arg4));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
        void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5) {
          this->WriteLine(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
        void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6) {
          this->WriteLine(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
        void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7) {
          this->WriteLine(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
        void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7, const T8& arg8) {
          this->WriteLine(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8));
        }

        template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
        void WriteLine(const String& format, const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7, const T8& arg8, const T9& arg9) {
          this->WriteLine(String::Format(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9));
        }

      protected:
        /// @brief Initializes a new instance of the System::IO::TextWriter class.
        TextWriter();

        /// @brief Initializes a new instance of the System::IO::TextWriter class with Encoding Specified.
        /// @param encoding Text::Encoding Specifie the encoding for TextWriter.
        TextWriter(Text::Encoding& encoding) : encoding(encoding) {}

        virtual Text::Encoding& GetEncoding() const {return this->encoding;}
        virtual const string& GetNewLine() const {return this->newLine;}
        virtual void SetNewLine(const string& newLine) {this->newLine = newLine;}

      private:
        Text::Encoding& encoding;
        TextWriter& operator =(const TextWriter&) { return *this; }
        string newLine = "\n";
      };

      class NullTextWriter : public TextWriter {
      public:
        NullTextWriter() : TextWriter() {}
        void Write(const string&) override { }

      private:
        NullTextWriter(const NullTextWriter&) = delete;
        NullTextWriter& operator=(const NullTextWriter&) = delete;
      };

      class SynchronizedTextWriter : public TextWriter {
      public:
        SynchronizedTextWriter(const SynchronizedTextWriter& stw) : writer(stw.writer) {}
        SynchronizedTextWriter& operator =(const SynchronizedTextWriter& stw) {
          this->writer = stw.writer;
          return *this;
        }
        void Write(const string& value) override;

      private:
        friend TextWriter;
        SynchronizedTextWriter(System::IO::TextWriter& w);
        SynchronizedTextWriter() = delete;
        System::IO::TextWriter* writer;
      };
    }
  }
}

/// @cond
inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, const string& value) {
  textWriter.Write(value);
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, const char* value) {
  textWriter << string(value);
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, const wchar* value) {
  textWriter << string(value);
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, const char16* value) {
  textWriter << string(value);
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, const char32* value) {
  textWriter << string(value);
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, const std::string& value) {
  textWriter << string(value);
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, const std::wstring& value) {
  textWriter << string(value);
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, bool value) {
  textWriter << System::Boolean(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, byte value) {
  textWriter << System::Byte(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, char value) {
  textWriter << System::Char(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, wchar value) {
  textWriter << System::Char(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, char16 value) {
  textWriter << System::Char(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, char32 value) {
  textWriter << System::Char(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, double value) {
  textWriter << System::Double(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, int16 value) {
  textWriter << System::Int16(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, int32 value) {
  textWriter << System::Int32(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, int64 value) {
  textWriter << System::Int64(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, void* value) {
  textWriter << System::IntPtr((intptr)value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, sbyte value) {
  textWriter << System::SByte(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, float value) {
  textWriter << System::Single(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, uint16 value) {
  textWriter << System::UInt16(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, uint32 value) {
  textWriter << System::UInt32(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, uint64 value) {
  textWriter << System::UInt64(value).ToString();
  return textWriter;
}

inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, const object& value) {
  textWriter << value.ToString();
  return textWriter;
}

template<typename T>
inline System::IO::TextWriter& operator<<(System::IO::TextWriter& textWriter, const T& value) {
  textWriter << string::Format("{0}", value);
  return textWriter;
}
/// @endcond

using namespace Switch;

