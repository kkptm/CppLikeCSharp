#if defined(__linux__) || defined(__APPLE__)

#include <cxxabi.h>
#include "Api.hpp"

string Native::TypeApi::Demangle(const string& name) {
  struct AutoDeleteCharPointer {
    AutoDeleteCharPointer(char* value) : value(value) {}
    ~AutoDeleteCharPointer() {free(value);}
    char* operator()() const {return this->value;}
  private:
    char* value;
  };
  int32 status = 0;
  return AutoDeleteCharPointer(abi::__cxa_demangle(name.Data(), 0, 0, &status))();
}

#endif
