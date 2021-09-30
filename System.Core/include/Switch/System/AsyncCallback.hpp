/// @file
/// @brief Contains Switch::System::AsyncCallback delegate.
#pragma once

#include "../Types.hpp"
#include "Delegate.hpp"
#include "IAsyncResult.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief References a method to be called when a corresponding asynchronous operation completes.
    /// @param ar The result of the asynchronous operation.
    /// @remarks Use an AsyncCallback delegate to process the results of an asynchronous operation in a separate thread. The AsyncCallback delegate represents a callback method that is called when the asynchronous operation completes. The callback method takes an IAsyncResult parameter, which is subsequently used to obtain the results of the asynchronous operation.
    /// @par Examples
    /// The following code example demonstrates using asynchronous methods in the Dns class to retrieve Domain Name System (DNS) information for user-specified computers. This example creates an AsyncCallback delegate that references the ProcessDnsInformation method. This method is called once for each asynchronous request for DNS information.
    /// @include EventHandler.cpp
    /// @par Examples
    /// This example show how to used a specialized EventHandler.
    /// @include AsyncCallback.cpp
    using AsyncCallback = Delegate<void, const IAsyncResult&>;
  }
}
using namespace Switch;
