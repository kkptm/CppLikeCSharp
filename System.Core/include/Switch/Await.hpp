/// @file
/// @brief Contains Switch::Await class and #await_ keyword.
#pragma once

#include "Async.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The await object is applied to a task in an asynchronous method to suspend the execution of the method until the awaited task completes.
  /// @par Examples
  /// This example demontrate how to use async and await
  /// @include Async1.cpp
  class core_export_ Await {
  public:
    Await();

    /// @brief The await operator is applied to a task in an asynchronous method to suspend the execution of the method until the awaited task completes.
    /// @param async the asynchronous method to wait.
    template <typename TResult>
    TResult operator<<(Async<System::Threading::Tasks::Task<TResult>>& async) {
      async().Wait();
      return async().Result;
    }

    template <typename TResult>
    TResult operator<<(System::Threading::Tasks::Task<TResult> task) {
      task.Wait();
      return task.Result;
    }


    /// @brief The await operator is applied to a task in an asynchronous method to suspend the execution of the method until the awaited task completes.
    /// @param async the asynchronous method to wait.
    void operator<<(Async<System::Threading::Tasks::Task<>>& async);

    /// @brief The await operator is applied to a task in an asynchronous method to suspend the execution of the method until the awaited task completes.
    /// @param async the asynchronous method to wait.
    void operator<<(System::Threading::Tasks::Task<> task);

  private:
    Await(const Await&) = delete;
    Await& operator=(const Await&) = delete;
  };

  /// @brief The await object is applied to a task in an asynchronous method to suspend the execution of the method until the awaited task completes.
  /// @par Examples
  /// This example demontrate how to use async and await
  /// @include Async1.cpp
  using await = Await;

  /// @brief The await operator is applied to a task in an asynchronous method to suspend the execution of the method until the awaited task completes.
  /// @par Examples
  /// This example demontrate how to use async and await
  /// @include Async2.cpp
  /// @ingroup Keywords
#define await_ \
  await() <<
}

using namespace Switch;
