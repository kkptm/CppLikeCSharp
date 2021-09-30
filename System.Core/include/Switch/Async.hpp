/// @file
/// @brief Contains Switch::Async class and #async_ keyword.
#pragma once

#include "System/Threading/Tasks/Task.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent an asynchronous task
  /// @par Examples
  /// This example demontrate how to use async and await
  /// @include Async1.cpp
  template<typename Task>
  class Async {
  public:
    /// @brief Create an asynchronous task
    /// @param task The asynchronous task
    template<typename T>
    Async(T task) : task(task) {this->task.Start();}

    /// @brief Get the asynchronous task
    /// @return The asynchronous task
    System::Threading::Tasks::Task<typename Task::TaskResult>& operator()() {return this->task;}

  private:
    System::Threading::Tasks::Task<typename Task::TaskResult> task;
  };

  /// @brief Represent an asynchronous task
  /// @par Examples
  /// This example demontrate how to use async and await
  /// @include Async1.cpp
  template<typename Task>
  using async = Async<Task>;

  /// @brief Represent an asynchronous task
  /// @par Examples
  /// This example demontrate how to use async and await
  /// @include Async2.cpp
  /// @ingroup Keywords
#define async_(Task, name, method) \
  async<Task> name{[&] method}
}

using namespace Switch;
