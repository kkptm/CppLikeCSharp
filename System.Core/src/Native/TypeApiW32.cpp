#if defined(_WIN32)

#include "Api.hpp"

string Native::TypeApi::Demangle(const string& name) {
  System::Array<string> types = {"enum ", "class ", "union ", "struct "};
  string result = name;
  for (string item : types)
    result = result.Replace(item, "");
  return result;
}

#endif
