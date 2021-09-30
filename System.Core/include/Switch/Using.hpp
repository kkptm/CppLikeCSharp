/// @file
/// @brief Contains #using_ keyword.
#pragma once

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The specified expression is cleared automaticaly when the scope is ended.
  /// @par Examples
  /// @code
  /// // sr is released automatically after the end cosure }.
  /// using_(refptr<StreamReader> sr = ref_new<StreamReader>(path)) {
  ///   Console::WriteLine(sr->ReadToEnd());
  /// }
  /// @endcode
  /// @ingroup Keywords
#define using_(expression) \
  for (bool __switch_using__ = true; __switch_using__; __switch_using__ = false)\
    for (expression; __switch_using__; __switch_using__ = false)
}

using namespace Switch;
