#include "../../include/Switch/__opaque_unicode_string__.hpp"
#include "../../include/Switch/System/Array.hpp"
#include "../../include/Switch/System/ArgumentNullException.hpp"
#include "../../include/Switch/System/ArgumentOutOfRangeException.hpp"
#include "../Native/Api.hpp"

size_t __opaque_unicode_string__::npos = std::string::npos;

__opaque_unicode_string__::__opaque_unicode_string__() {
}

__opaque_unicode_string__::__opaque_unicode_string__(const char32_t* str) {
  int i = 0;
  while (str[i] != 0)
    this->append(str[i++]);
  this->stringSize = i;
}
__opaque_unicode_string__::__opaque_unicode_string__(const __opaque_unicode_string__& str) : string(str.string), stringSize(str.stringSize) {
}

__opaque_unicode_string__::__opaque_unicode_string__(int length, char c) : stringSize(length) {
  while (length--)
    this->string.push_back(c);
}
__opaque_unicode_string__::__opaque_unicode_string__(const char* str, int32_t startIndex) : __opaque_unicode_string__(str, startIndex, (int32_t)npos) {
}

__opaque_unicode_string__::__opaque_unicode_string__(const char* str) : string(str), stringSize(Native::UnicodeEncodingsApi::UTF8::GetLength(string)) {
}

__opaque_unicode_string__::__opaque_unicode_string__(const char* str, int32_t startIndex, int32_t length) {
  if (str == null)
    throw System::ArgumentNullException(caller_);

  __opaque_unicode_string__ other(str);

  int32_t count = static_cast<int32_t>((static_cast<size_t>(length) == npos) ? other.size() : length);
  if (startIndex + count > static_cast<int32_t>(other.size()))
    count = static_cast<int32_t>(other.size()) - startIndex;

  if (startIndex == static_cast<int32_t>(other.size())) {
    this->stringSize = 0;
    return;
  }

  int32_t begin = -1, end = -1;

  for (__opaque_unicode_string__::const_iterator it = ((const __opaque_unicode_string__&)other).begin(); it != ((const __opaque_unicode_string__&)other).end(); it++) {
    if (startIndex == it.get_logical_index())
      begin = it.get_byte_index();

    if (it.get_logical_index() == (startIndex + count))
      end = it.get_byte_index();
  }

  if (begin == -1)
    throw System::ArgumentOutOfRangeException(caller_);

  if (end == -1) {
    this->string = other.string.substr(begin);
    this->stringSize = other.size() - startIndex;
  } else {
    this->string = other.string.substr(begin, end - begin);
    this->stringSize = Native::UnicodeEncodingsApi::UTF8::GetLength(this->string);
  }
}

__opaque_unicode_string__::__opaque_unicode_string__(const char32_t* str, int32_t startIndex) : __opaque_unicode_string__(str, startIndex, (int32_t)npos) {
}

__opaque_unicode_string__::__opaque_unicode_string__(const char32_t* str, int32_t startIndex, int32_t length) {
  if (startIndex < 0 || length < 0)
    throw System::ArgumentOutOfRangeException(caller_);
  this->stringSize = 0;
  for (int i = 0; i < length; i++)
    append(str[i]);
}

__opaque_unicode_string__::__opaque_unicode_string__(__opaque_unicode_string__&& str) : string(std::move(str.string)), stringSize(str.stringSize) {
  str.stringSize = 0;
}

bool __opaque_unicode_string__::operator==(const __opaque_unicode_string__& str) const {
  return this->stringSize == str.stringSize && this->string == str.string;
}

__opaque_unicode_string__& __opaque_unicode_string__::operator=(const __opaque_unicode_string__& str) {
  this->string = str.string;
  this->stringSize = str.stringSize;
  return *this;
}

__opaque_unicode_string__& __opaque_unicode_string__::operator+=(const __opaque_unicode_string__& s) {
  this->string.append(s.string);
  this->stringSize += s.stringSize;
  return *this;
}

char32_t __opaque_unicode_string__::operator[](int i) const {
  if (i < 0)
    throw System::ArgumentOutOfRangeException(caller_);

  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++)
    if (it.get_logical_index() == i)
      return *it;

  throw System::ArgumentOutOfRangeException(caller_);
}

char32_t& __opaque_unicode_string__::operator[](int i) {
  if (i < 0)
    throw System::ArgumentOutOfRangeException(caller_);

  for (__opaque_unicode_string__::iterator it = (*this).begin(); it != (*this).end(); it++)
    if (it.get_logical_index() == i)
      return *it;

  throw System::ArgumentOutOfRangeException(caller_);
}

__opaque_unicode_string__& __opaque_unicode_string__::erase(size_t pos, size_t len) {
  int byteIndexIn = -1;
  __opaque_unicode_string__::iterator it = begin();

  if (len == 0) return *this;

  for (; it != end(); it++) {
    if (static_cast<size_t>(it.get_logical_index()) == pos && byteIndexIn == -1) {
      byteIndexIn = it.get_byte_index();
      break;
    }
  }

  if (byteIndexIn == -1)
    throw System::ArgumentOutOfRangeException(caller_);

  if (len == npos) {
    this->string.erase(byteIndexIn);
    this->stringSize = Native::UnicodeEncodingsApi::UTF8::GetLength(this->string);
    return *this;
  }

  int byteIndexOut = static_cast<int>(this->string.size());
  for (; it != end(); it++) {
    if (--len == 0) {
      int next = Native::UnicodeEncodingsApi::UTF8::GetNextCodeIndex(this->string, it.get_byte_index());
      if (next != -1)
        byteIndexOut = next;
    }
  }

  this->string.erase(byteIndexIn, byteIndexOut - byteIndexIn);
  this->stringSize = Native::UnicodeEncodingsApi::UTF8::GetLength(this->string);
  return *this;
}

__opaque_unicode_string__& __opaque_unicode_string__::replace(size_t pos,  size_t len,  size_t n, char c) {
  __opaque_unicode_string__ str(static_cast<int32_t>(n), c);
  return replace(pos, len, str);
}

__opaque_unicode_string__& __opaque_unicode_string__::replace(size_t pos,  size_t len,  const __opaque_unicode_string__& str) {
  __opaque_unicode_string__ before = substr(0, pos);
  __opaque_unicode_string__ after = substr(pos).erase(0, len);
  this->string = before.string.append(str.string).append(after.string);
  this->stringSize = before.stringSize + str.stringSize + after.stringSize;
  return *this;
}

__opaque_unicode_string__& __opaque_unicode_string__::trim_end(const std::vector<char32_t>& toRemove) {
  int byteIndex = -1;
  for (__opaque_unicode_string__::reverse_iterator rit = (*this).rbegin(); rit != (*this).rend(); rit++) {
    bool matched = false;
    for (uint32 i = 0; i < toRemove.size(); i++) {
      if (*rit == toRemove[i]) {
        byteIndex = rit.get_byte_index();
        matched = true;
      }
    }
    if (!matched)
      rit = rend();
  }

  if (byteIndex == -1)
    return *this;

  this->string.erase(byteIndex);
  this->stringSize = Native::UnicodeEncodingsApi::UTF8::GetLength(this->string);
  return *this;
}

__opaque_unicode_string__& __opaque_unicode_string__::append(size_t n, char32_t code) {
  for (size_t i = 0; i < n; i++)
    Native::UnicodeEncodingsApi::UTF8::Encode(code, string);
  this->stringSize += n;
  return *this;
}

__opaque_unicode_string__& __opaque_unicode_string__::append(char32_t code) {
  Native::UnicodeEncodingsApi::UTF8::Encode(code, string);
  this->stringSize += 1;
  return *this;
}

__opaque_unicode_string__::const_iterator __opaque_unicode_string__::begin() const {
  return const_iterator(&this->string);
}

__opaque_unicode_string__::const_iterator __opaque_unicode_string__::end() const {
  return const_iterator(&this->string, true);
}

__opaque_unicode_string__::iterator __opaque_unicode_string__::begin() {
  return iterator(&this->string);
}

__opaque_unicode_string__::iterator __opaque_unicode_string__::end() {
  return iterator(&this->string, true);
}

__opaque_unicode_string__::const_reverse_iterator __opaque_unicode_string__::rbegin() const {
  return const_reverse_iterator(&this->string);
}
__opaque_unicode_string__::const_reverse_iterator __opaque_unicode_string__::rend() const {
  return const_reverse_iterator(&this->string, true);
}

__opaque_unicode_string__::reverse_iterator __opaque_unicode_string__::rbegin() {
  return reverse_iterator(&this->string);
}

__opaque_unicode_string__::reverse_iterator __opaque_unicode_string__::rend() {
  return reverse_iterator(&this->string, true);
}

bool __opaque_unicode_string__::equals(__opaque_unicode_string__::const_iterator src, const __opaque_unicode_string__::const_iterator& src_end, __opaque_unicode_string__::const_iterator match, const __opaque_unicode_string__::const_iterator& match_end) {
  for (; match != match_end; match++, src++) {
    if (src == src_end)
      return false;
    if (*src != *match)
      return false;
  }
  return true;
}

size_t __opaque_unicode_string__::rfind(const __opaque_unicode_string__& match, size_t pos) const {
  size_t foundIndex = npos;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++) {
    if ((pos != npos) && ((size_t)it.get_logical_index() > pos))
      return foundIndex;

    if (equals(it, end(), match.begin(), match.end()))
      foundIndex = it.get_logical_index();
  }
  return foundIndex;
}

size_t __opaque_unicode_string__::rfind(char32_t match, size_t pos) const {
  size_t foundIndex = npos;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++) {
    if ((pos != npos) && ((size_t)it.get_logical_index() > pos))
      return foundIndex;

    if (*it == match)
      foundIndex = it.get_logical_index();
  }
  return foundIndex;
}

__opaque_unicode_string__& __opaque_unicode_string__::insert(int32_t pos, const __opaque_unicode_string__& str) {
  __opaque_unicode_string__ before = substr(0, pos);
  __opaque_unicode_string__ after = substr(pos);
  this->string = before.string;
  this->string.append(str.string);
  this->string.append(after.string);
  this->stringSize = before.stringSize + str.stringSize + after.stringSize;
  return *this;
}

__opaque_unicode_string__ __opaque_unicode_string__::substr(size_t pos, size_t len) const {
  return __opaque_unicode_string__(this->string.c_str(), static_cast<int32_t>(pos), static_cast<int32_t>(len));
}

size_t __opaque_unicode_string__::find(const __opaque_unicode_string__& match, size_t pos, size_t count) const {
  size_t len = 0;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++) {
    len += 1;
    if ((pos != npos) && ((size_t)it.get_logical_index() < pos))
      continue;

    if ((pos != npos) && (count != npos) && ((size_t)it.get_logical_index() >= pos + count))
      return npos;

    if (equals(it, end(), match.begin(), match.end()))
      return it.get_logical_index();
  }
  if (pos != npos && pos > len)
    throw System::ArgumentOutOfRangeException(caller_);
  return npos;
}

size_t __opaque_unicode_string__::find(char32_t match, size_t pos, size_t count) const {
  size_t len = 0;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++) {
    len += 1;
    if ((pos != npos) && ((size_t)it.get_logical_index() < pos))
      continue;

    if ((pos != npos) && (count != npos) && ((size_t)it.get_logical_index() >= pos + count))
      return npos;

    if (*it == match)
      return it.get_logical_index();
  }
  if (pos != npos && pos > len)
    throw System::ArgumentOutOfRangeException(caller_);
  return npos;
}

size_t __opaque_unicode_string__::find_any(const std::vector<char32_t>& any, size_t pos, size_t count) const {
  size_t len = 0;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++) {
    len += 1;
    if ((pos != npos) && ((size_t)it.get_logical_index() < pos))
      continue;

    if ((pos != npos) && (count != npos) && ((size_t)it.get_logical_index() >= pos + count))
      return npos;

    for (size_t i = 0; i < any.size(); i++)
      if (*it == any[i])
        return it.get_logical_index();
  }
  if (pos != npos && pos > len)
    throw System::ArgumentOutOfRangeException(caller_);
  return npos;
}

size_t __opaque_unicode_string__::length() const {
  return this->stringSize;
}

bool __opaque_unicode_string__::ends_with(const __opaque_unicode_string__& s) const {
  if (s.string.size() > this->string.size())
    return false;

  return this->string.substr(this->string.size() - s.string.size()) == s.string;
}

size_t __opaque_unicode_string__::size() const {
  return length();
}

size_t __opaque_unicode_string__::nb_bytes() const {
  return this->string.size();
}

const char* __opaque_unicode_string__::data() const {
  return this->string.data();
}

const char* __opaque_unicode_string__::c_str() const {
  return this->string.c_str();
}

__opaque_unicode_string__ __opaque_unicode_string__::to_lower() const {
  __opaque_unicode_string__ lower;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++)
    lower.append(Native::UnicodeEncodingsApi::ToLower(*it));
  return lower;
}

__opaque_unicode_string__ __opaque_unicode_string__::to_upper() const {
  __opaque_unicode_string__ upper;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++)
    upper.append(Native::UnicodeEncodingsApi::ToUpper(*it));
  return upper;
}

int __opaque_unicode_string__::compare(const __opaque_unicode_string__& str)  const {
  __opaque_unicode_string__::const_iterator it2 = str.begin();
  for (__opaque_unicode_string__::const_iterator it1 = (*this).begin(); it1 != (*this).end(); it1++) {
    if (it2 == str.end()) // str is a prefix of *this
      return 1;

    if (*it1 < *it2)
      return -1;
    if (*it1 > *it2)
      return 1;

    it2++;
  }

  if (it2 != str.end()) // *this is a prefix of str
    return -1;

  return 0;
}

int __opaque_unicode_string__::compare_ignore_case(const __opaque_unicode_string__& str) const {
  __opaque_unicode_string__ left_op(to_lower());
  __opaque_unicode_string__ right_op(str.to_lower());
  return left_op.compare(right_op);
}

__opaque_unicode_string__::const_iterator::const_iterator(const std::string* str, bool at_end) {
  string_pointer = str;
  if (*str == "" || at_end) {
    this->position = -1;
    this->index = -1;
    this->format = 0;
  } else {
    this->index = this->position = 0;
    this->format = Native::UnicodeEncodingsApi::UTF8::GetFormat((uint8_t)string_pointer->operator[](this->position));
  }
}

__opaque_unicode_string__::const_iterator __opaque_unicode_string__::const_iterator::operator++(int) {
  const_iterator temp_it(*this);
  operator++();
  return temp_it;
}

bool __opaque_unicode_string__::const_iterator::operator==(const const_iterator& rhs) const {
  return (string_pointer == rhs.string_pointer) && (this->position == rhs.position);
}

bool __opaque_unicode_string__::const_iterator::operator!=(const const_iterator& rhs) const {
  return !(*this == rhs);
}

char32_t __opaque_unicode_string__::const_iterator::operator*() const {
  const uint8_t* data = (const uint8_t*)string_pointer->data();
  return Native::UnicodeEncodingsApi::UTF8::GetCode(&data[this->position], format);
}

__opaque_unicode_string__::const_iterator::const_iterator(const const_iterator& it) {
  string_pointer = it.string_pointer;
  this->position = it.position;
  this->index = it.index;
  this->format = it.format;
}

__opaque_unicode_string__::const_iterator& __opaque_unicode_string__::const_iterator::operator++() {
  if (this->position == -1) return *this;
  for (size_t i = this->position + 1; i < string_pointer->size() ; i += 1) {
    uint8_t b = (uint8_t)(*string_pointer)[i];
    this->format = Native::UnicodeEncodingsApi::UTF8::GetFormat(b);
    if (this->format > 0) {
      this->index += 1;
      this->position = (int)i;
      return *this;
    }
  }
  this->position = -1;
  return *this;
}

int __opaque_unicode_string__::const_iterator::get_byte_index() const { return this->position; }
int __opaque_unicode_string__::const_iterator::get_format() const { return this->format; }
int __opaque_unicode_string__::const_iterator::get_logical_index() const { return this->index; }

__opaque_unicode_string__::iterator::iterator(std::string* str, bool at_end) {
  string_pointer = str;
  if (*str == "" || at_end) {
    this->position = -1;
    this->index = -1;
    this->format = 0;
  } else {
    this->index = this->position = 0;
    this->format = Native::UnicodeEncodingsApi::UTF8::GetFormat((uint8_t)string_pointer->operator[](this->position));
  }
}

__opaque_unicode_string__::iterator __opaque_unicode_string__::iterator::operator++(int) {
  iterator temp_it(*this);
  operator++();
  return temp_it;
}

bool __opaque_unicode_string__::iterator::operator==(const iterator& rhs) const {
  return (string_pointer == rhs.string_pointer) && (this->position == rhs.position);
}

bool __opaque_unicode_string__::iterator::operator!=(const iterator& rhs) const {
  return !(*this == rhs);
}

char32_t __opaque_unicode_string__::iterator::operator*() const {
  const uint8_t* data = (const uint8_t*)string_pointer->data();
  return Native::UnicodeEncodingsApi::UTF8::GetCode(&data[this->position], format);
}

char32_t& __opaque_unicode_string__::iterator::operator*() {
  uint8_t* data = (uint8_t*)string_pointer->data();
  static char32 value;
  value = Native::UnicodeEncodingsApi::UTF8::GetCode(&data[this->position], format);
  return value;
}

__opaque_unicode_string__::iterator::iterator(const iterator& it) {
  string_pointer = it.string_pointer;
  this->position = it.position;
  this->index = it.index;
  this->format = it.format;
}

__opaque_unicode_string__::iterator& __opaque_unicode_string__::iterator::operator++() {
  if (this->position == -1) return *this;
  for (size_t i = this->position + 1; i < string_pointer->size() ; i += 1) {
    uint8_t b = (uint8_t)(*string_pointer)[i];
    this->format = Native::UnicodeEncodingsApi::UTF8::GetFormat(b);
    if (this->format > 0) {
      this->index += 1;
      this->position = (int)i;
      return *this;
    }
  }
  this->position = -1;
  return *this;
}

int __opaque_unicode_string__::iterator::get_byte_index() const { return this->position; }
int __opaque_unicode_string__::iterator::get_format() const { return this->format; }
int __opaque_unicode_string__::iterator::get_logical_index() const { return this->index; }

__opaque_unicode_string__::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& it) {
  string_pointer = it.string_pointer;
  this->position = it.position;
  index = it.index;
  this->format = it.format;
}

__opaque_unicode_string__::const_reverse_iterator::const_reverse_iterator(const std::string* str, bool at_end) {
  string_pointer = str;
  if (*str == "" || at_end) {
    this->position = -1;
    this->index = -1;
    this->format = 0;
  } else {
    this->index = Native::UnicodeEncodingsApi::UTF8::GetLength(*str) - 1;
    this->position = Native::UnicodeEncodingsApi::UTF8::GetLastIndex(*str);
    if (this->position == -1)
      this->format = 0;
    else
      this->format = Native::UnicodeEncodingsApi::UTF8::GetFormat((uint8_t)string_pointer->operator[](this->position));
  }
}

__opaque_unicode_string__::const_reverse_iterator __opaque_unicode_string__::const_reverse_iterator::operator++(int) {
  const_reverse_iterator temp_it(*this);
  operator++();
  return temp_it;
}

bool __opaque_unicode_string__::const_reverse_iterator::operator==(const const_reverse_iterator& rhs) const {
  return (string_pointer == rhs.string_pointer) && (this->position == rhs.position);
}

bool __opaque_unicode_string__::const_reverse_iterator::operator!=(const const_reverse_iterator& rhs) const {
  return !(*this == rhs);
}

char32_t __opaque_unicode_string__::const_reverse_iterator::operator*() const {
  const uint8_t* data = (const uint8_t*)string_pointer->data();
  return Native::UnicodeEncodingsApi::UTF8::GetCode(&data[this->position], format);
}

__opaque_unicode_string__::const_reverse_iterator& __opaque_unicode_string__::const_reverse_iterator::operator++() {
  if (this->position == -1) return *this;
  for (int32_t i = this->position - 1 ; i >= 0 ; i -= 1) {
    uint8_t b = (uint8_t)(*string_pointer)[i];
    this->format = Native::UnicodeEncodingsApi::UTF8::GetFormat(b);
    if (this->format > 0) {
      this->index -= 1;
      this->position = i;
      return *this;
    }
  }
  this->position = -1;
  return *this;
}

int __opaque_unicode_string__::const_reverse_iterator::get_byte_index() const { return this->position; }
int __opaque_unicode_string__::const_reverse_iterator::get_format() const { return this->format; }
int __opaque_unicode_string__::const_reverse_iterator::get_logical_index() const { return this->index; }

__opaque_unicode_string__::reverse_iterator::reverse_iterator(const reverse_iterator& it) {
  string_pointer = it.string_pointer;
  this->position = it.position;
  this->index = it.index;
  this->format = it.format;
}

__opaque_unicode_string__::reverse_iterator::reverse_iterator(std::string* str, bool at_end) {
  string_pointer = str;
  if (*str == "" || at_end) {
    this->position = -1;
    this->index = -1;
    this->format = 0;
  } else {
    this->index = Native::UnicodeEncodingsApi::UTF8::GetLength(*str) - 1;
    this->position = Native::UnicodeEncodingsApi::UTF8::GetLastIndex(*str);
    if (this->position == -1)
      this->format = 0;
    else
      this->format = Native::UnicodeEncodingsApi::UTF8::GetFormat((uint8_t)string_pointer->operator[](this->position));
  }
}

__opaque_unicode_string__::reverse_iterator __opaque_unicode_string__::reverse_iterator::operator++(int) {
  reverse_iterator temp_it(*this);
  operator++();
  return temp_it;
}

bool __opaque_unicode_string__::reverse_iterator::operator==(const reverse_iterator& rhs) const {
  return (string_pointer == rhs.string_pointer) && (this->position == rhs.position);
}

bool __opaque_unicode_string__::reverse_iterator::operator!=(const reverse_iterator& rhs) const {
  return !(*this == rhs);
}

char32_t __opaque_unicode_string__::reverse_iterator::operator*() const {
  const uint8_t* data = (const uint8_t*)string_pointer->data();
  return Native::UnicodeEncodingsApi::UTF8::GetCode(&data[this->position], format);
}

char32_t& __opaque_unicode_string__::reverse_iterator::operator*() {
  uint8_t* data = (uint8_t*)string_pointer->data();
  return (char32_t&) * data;
}

__opaque_unicode_string__::reverse_iterator& __opaque_unicode_string__::reverse_iterator::operator++() {
  if (this->position == -1) return *this;
  for (int32_t i = this->position - 1 ; i >= 0 ; i -= 1) {
    uint8_t b = (uint8_t)(*string_pointer)[i];
    this->format = Native::UnicodeEncodingsApi::UTF8::GetFormat(b);
    if (this->format > 0) {
      this->index -= 1;
      this->position = i;
      return *this;
    }
  }
  this->position = -1;
  return *this;
}

int __opaque_unicode_string__::reverse_iterator::get_byte_index() const { return this->position; }
int __opaque_unicode_string__::reverse_iterator::get_format() const { return this->format; }
int __opaque_unicode_string__::reverse_iterator::get_logical_index() const { return this->index; }
