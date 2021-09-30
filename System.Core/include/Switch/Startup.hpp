/// @file
/// @brief Contains #startup_ keyword.
#pragma once

#include<cstdlib>
#include "CoreExport.hpp"
#include "System/Environment.hpp"

/// @cond
#if !(defined(WIN32) && defined(DECLARE_HANDLE))
using HINSTANCE = struct HINSTANCE__ { int unused; }*;
#endif
core_export_ extern HINSTANCE __instance;
core_export_ extern int __commandShow;

#if !defined(_WIN32)
core_export_ extern int __argc;
core_export_ extern char** __argv;
#endif
/// @endcond

namespace Switch {
  /// @brief Defines the entry point to be called when the application loads. Generally this is set either to the main form in your application or to the Main procedure that should run when the application starts.
  /// @param mainClass The class that contains the static Main method.
  /// @par Examples
  /// This example show a Main method without arguments and without return code
  /// @include Main1.cpp
  /// @par
  /// This example show a Main method with a return code without arguments
  /// @include Main2.cpp
  /// @par
  /// This example show a Main method with argument and without return code
  /// @include Main3.cpp
  /// @par
  /// This example show a Main method with argument and return code
  /// @include Main4.cpp
  /// @ingroup Keywords
#define startup_(mainClass) \
  int main(int argc, char* argv[]) {\
    struct Startup {\
      int operator()(void (*startup)(), const System::Array<System::String>& args) {startup(); return System::Environment::ExitCode;}\
      int operator()(int (*startup)(), const System::Array<System::String>& args) {return startup();}\
      int operator()(void (*startup)(const System::Array<System::String>&), const System::Array<System::String>& args) {startup(args); return System::Environment::ExitCode;}\
      int operator()(int (*startup)(const System::Array<System::String>&), const System::Array<System::String>& args) {return startup(args);}\
    };\
    return Startup()(mainClass::Main, System::Environment::SetCommandLineArgs(argv, argc));\
  } \
  \
  int WinMain(HINSTANCE instance, HINSTANCE previousInstance, char* commandLine, int commandShow) {\
    __instance = instance;\
    __commandShow = commandShow;\
    return main(__argc, __argv);\
  }\
  int __unused_main_argc__
}
