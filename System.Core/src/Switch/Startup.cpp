#include "../../include/Switch/Types.hpp"

using HINSTANCE = struct HINSTANCE__ {int unused;}*;
core_export_ HINSTANCE __instance = null;
core_export_ int __commandShow = 10; // SW_SHOWDEFAULT;

#if !defined __argc
int __argc = 0;
#endif
#if !defined __argv
char** __argv = nullptr;
#endif