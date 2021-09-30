/// @file
/// @brief Contains __opaque_unicode_string__ class.
#pragma once

#include <cstddef>
#include <ostream>
#include <string>
#include <vector>

#include "CoreExport.hpp"

/// @cond
namespace Switch {
  namespace System {
    class String;
  }
}

class core_export_ __opaque_unicode_string__ {
  friend class Switch::System::String;
  __opaque_unicode_string__();
  explicit __opaque_unicode_string__(const char* str);
  explicit __opaque_unicode_string__(const char32_t* str);
  __opaque_unicode_string__(const __opaque_unicode_string__& str);
  __opaque_unicode_string__(int length, char c);
  __opaque_unicode_string__(const char* str, int32_t startIndex);
  __opaque_unicode_string__(const char* str, int32_t startIndex, int32_t length);
  __opaque_unicode_string__(const char32_t* str, int32_t startIndex);
  __opaque_unicode_string__(const char32_t* str, int32_t startIndex, int32_t length);
  __opaque_unicode_string__(__opaque_unicode_string__&& str);

  bool operator==(const __opaque_unicode_string__& str) const;
  __opaque_unicode_string__& operator=(const __opaque_unicode_string__& str);
  __opaque_unicode_string__& operator+=(const __opaque_unicode_string__& s);

  char32_t operator[](int i) const;
  char32_t& operator[](int i);

  __opaque_unicode_string__ substr(size_t pos = 0, size_t len = npos) const;
  __opaque_unicode_string__ to_upper() const;
  __opaque_unicode_string__ to_lower() const;
  size_t find(const __opaque_unicode_string__& s, size_t pos = npos, size_t count = npos) const;
  size_t find(char32_t code, size_t pos = npos, size_t count = npos) const;
  size_t find_any(const std::vector<char32_t>& any, size_t pos = npos, size_t count = npos) const;
  size_t rfind(const __opaque_unicode_string__& s, size_t pos = npos) const;
  size_t rfind(char32_t code, size_t pos = npos) const;
  size_t length() const;
  bool ends_with(const __opaque_unicode_string__& s) const;
  size_t size() const;
  size_t nb_bytes() const;

  const char* data() const;
  const char* c_str() const;

  int compare(const __opaque_unicode_string__& str) const;
  int compare_ignore_case(const __opaque_unicode_string__& str) const;

  __opaque_unicode_string__& trim_end(const std::vector<char32_t>& toRemove);
  __opaque_unicode_string__& append(size_t n, char32_t c);
  __opaque_unicode_string__& append(const __opaque_unicode_string__& s) {
    this->string.append(s.string);
    this->stringSize += s.stringSize;
    return *this;
  }
  __opaque_unicode_string__& append(char32_t code);
  size_t capacity() const {return this->string.capacity();}
  __opaque_unicode_string__& insert(int32_t pos, const __opaque_unicode_string__& str);
  __opaque_unicode_string__& erase(size_t pos = 0, size_t len = npos);
  __opaque_unicode_string__& replace(size_t pos,  size_t len,  size_t n, char c);
  __opaque_unicode_string__& replace(size_t pos,  size_t len,  const __opaque_unicode_string__& str);
  void reserve(size_t value) {this->string.reserve(value);}

  class core_export_ const_iterator : public std::iterator<std::forward_iterator_tag, char32_t> {
  public:
    const_iterator(const const_iterator& it);
    const_iterator& operator++();
    const_iterator operator++(int);
    bool operator==(const const_iterator& rhs) const;
    bool operator !=(const const_iterator& rhs) const;
    char32_t operator*() const;

    int get_byte_index() const;
    int get_format() const;
    int get_logical_index() const;

  private:
    friend class __opaque_unicode_string__;
    const std::string* string_pointer;
    int position;
    uint8_t format;
    int index;

    const_iterator(const std::string* str, bool at_end = false);
  };

  class core_export_ const_reverse_iterator : public std::iterator<std::forward_iterator_tag, char32_t> {
  public:
    const_reverse_iterator(const const_reverse_iterator& it);
    const_reverse_iterator& operator++();
    const_reverse_iterator operator++(int);
    bool operator==(const const_reverse_iterator& rhs) const;
    bool operator!=(const const_reverse_iterator& rhs) const;
    char32_t operator*() const;

    int get_byte_index() const;
    int get_format() const;
    int get_logical_index() const;

  private:
    friend class __opaque_unicode_string__;
    const std::string* string_pointer;
    int position;
    uint8_t format;
    int index;

    const_reverse_iterator(const std::string* str, bool at_end = false);
  };

  class core_export_ iterator : public std::iterator<std::forward_iterator_tag, char32_t> {
  public:
    iterator(const iterator& it);
    iterator& operator++();
    iterator operator++(int);
    bool operator==(const iterator& rhs) const;
    bool operator!=(const iterator& rhs) const;
    char32_t operator*() const;
    char32_t& operator*();

    int get_byte_index() const;
    int get_format() const;
    int get_logical_index() const;

  private:
    friend class __opaque_unicode_string__;
    std::string* string_pointer;
    int position;
    uint8_t format;
    int index;

    iterator(std::string* str, bool at_end = false);
  };

  class core_export_ reverse_iterator : public std::iterator<std::forward_iterator_tag, char32_t> {
  public:
    reverse_iterator(const reverse_iterator& it);
    reverse_iterator& operator++();
    reverse_iterator operator++(int);
    bool operator==(const reverse_iterator& rhs) const;
    bool operator!=(const reverse_iterator& rhs) const;
    char32_t operator*() const;
    char32_t& operator*();

    int get_byte_index() const;
    int get_format() const;
    int get_logical_index() const;

  private:
    friend class __opaque_unicode_string__;
    std::string* string_pointer;
    int position;
    uint8_t format;
    int index;

    reverse_iterator(std::string* str, bool at_end = false);
  };

  const_iterator begin() const;
  const_iterator end() const;
  iterator begin();
  iterator end();
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
  reverse_iterator rbegin();
  reverse_iterator rend();

  static size_t npos;
  static bool equals(__opaque_unicode_string__::const_iterator src, const __opaque_unicode_string__::const_iterator& src_end, __opaque_unicode_string__::const_iterator match, const __opaque_unicode_string__::const_iterator& match_end);

  std::string string;
  size_t stringSize = 0;
};
/// @endcond

