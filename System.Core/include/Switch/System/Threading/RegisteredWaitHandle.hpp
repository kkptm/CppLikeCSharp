/// @file
/// @brief Contains Switch::System::Threading::RegisteredWaitHandle class.
#pragma once

#include "../Object.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @cond
      class ThreadPool;
      /// @endcond

      /// @brief Represents a handle that has been registered when calling RegisterWaitForSingleObject. This class cannot be inherited.
      class core_export_ RegisteredWaitHandle final : public Object {
        /// @cond
        friend class ThreadPool;
        /// @endcond

      public:
        /// @brief Cancels a registered wait operation issued by the RegisterWaitForSingleObject method.
        /// waitObject
        /// @return bool true if the function succeeds; otherwise, false
        /// @remarks If waitObject is specified, it is signaled only if the RegisteredWaitHandle is successfully unregistered. If a callback method is in progress when Unregister executes, waitObject is not signaled until the callback method completes. In particular, if a callback method executes Unregister, waitObject is not signaled until that callback method completes.
        /// @see ThreadPool
        bool Unregister();

        /// @brief Cancels a registered wait operation issued by the RegisterWaitForSingleObject method.
        /// waitObject
        /// @return bool true if the function succeeds; otherwise, false
        /// @remarks If waitObject is specified, it is signaled only if the RegisteredWaitHandle is successfully unregistered. If a callback method is in progress when Unregister executes, waitObject is not signaled until the callback method completes. In particular, if a callback method executes Unregister, waitObject is not signaled until that callback method completes.
        /// @see ThreadPool
        bool Unregister(WaitHandle& waitObject);

      private:
        RegisteredWaitHandle() {}
        void* item = null;
      };
    }
  }
}

using namespace Switch;
