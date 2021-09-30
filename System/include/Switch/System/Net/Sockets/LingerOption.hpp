/// @file
/// @brief Contains Switch::System::Net::Sockets::LingerOption enum.
#pragma once

#include <Switch/Property.hpp>
#include <Switch/Types.hpp>
#include <Switch/System/Object.hpp>
#include "../../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The System::Net::Sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
      namespace Sockets {
        /// @brief Specifies whether a Socket will remain connected after a call to the Close or Close methods and the length of time it will remain connected, if data remains to be sent.
        /// @remarks There may still be data available in the outgoing network buffer after an application calls the Socket or TcpClient method. If you want to specify the amount of time that the Socket will attempt to transmit unsent data after closing, create a LingerOption with the enable parameter set to true, and the seconds parameter set to the desired amount of time. The seconds parameter is used to indicate how long you would like the Socket to remain connected before timing out. If you do not want the Socket to stay connected for any length of time after closing, create a LingerOption instance with the enable parameter set to true and the seconds parameter set to zero. In this case, the Socket will close immediately and any unsent data will be lost. Once created, pass the LingerOption to the Socket.SetSocketOption method. If you are sending and receiving data with a TcpClient, then set the LingerOption instance in the TcpClient.LingerState property.
        /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a Socket when the LingerState property is not set and for a TcpClient when the LingerState property is not set.
        /// @par Library
        /// Switch.System
        class system_export_ LingerOption : public Object {
        public:
          /// @brief Initializes a new version of the LingerOption class.
          /// @remarks There may still be data available in the outgoing network buffer after you close the Socket. Use the enable parameter to specify whether you would like the Socket to continue transmitting unsent data after the close method is called. Use the seconds parameter to indicate how long you would like the Socket to attempt transferring unsent data before timing out. If you specify true for the enable parameter and 0 for the seconds parameter, the Socket will attempt to send data until there is no data left in the outgoing network buffer. If you specify false for the enable parameter, the Socket will close immediately and any unsent data will be lost.
          /// @remarks The following table describes the behavior on the Socket::Close and TcpClient::Close methods based on the possible values of the enable and seconds parameters when an System::Net::Sockets::LingerOption instance is created and set in the Socket::LingerState or TcpClient::LingerState property.
          /// | enable                              | seconds                                    | Behavior                                                                                                                          |
          /// |-------------------------------------|--------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
          /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data for a connection-oriented socket (TCP, for example) until the default IP protocol time-out expires. |
          /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
          /// | true (enabled)                      | A zero timeout.                            | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
          /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the LingerState property is not set.
          /// @remarks When the LingerTime property stored in the LingerState property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
          LingerOption() {}

          /// @brief Initializes a new version of the LingerOption class for the specified IP multicast group.
          /// @param enabled true to remain connected after the Socket.Close method is called; otherwise, false.
          /// @param lingerTime The number of seconds to remain connected after the Socket.Close method is called.
          /// @remarks There may still be data available in the outgoing network buffer after you close the Socket. Use the enable parameter to specify whether you would like the Socket to continue transmitting unsent data after the close method is called. Use the seconds parameter to indicate how long you would like the Socket to attempt transferring unsent data before timing out. If you specify true for the enable parameter and 0 for the seconds parameter, the Socket will attempt to send data until there is no data left in the outgoing network buffer. If you specify false for the enable parameter, the Socket will close immediately and any unsent data will be lost.
          /// @remarks The following table describes the behavior on the Socket::Close and TcpClient::Close methods based on the possible values of the enable and seconds parameters when an System::Net::Sockets::LingerOption instance is created and set in the Socket::LingerState or TcpClient::LingerState property.
          /// | enable                              | seconds                                    | Behavior                                                                                                                          |
          /// |-------------------------------------|--------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
          /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data for a connection-oriented socket (TCP, for example) until the default IP protocol time-out expires. |
          /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
          /// | true (enabled)                      | A zero timeout.                            | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
          /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the LingerState property is not set.
          /// @remarks When the LingerTime property stored in the LingerState property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
          LingerOption(bool enabled, int32 lingerTime) : enabled(enabled), lingerTime(lingerTime) {}

          /// @cond
          LingerOption(const LingerOption& lingerOption) : enabled(lingerOption.enabled), lingerTime(lingerOption.lingerTime) {}
          LingerOption& operator=(const LingerOption& lingerOption) {
            this->enabled = lingerOption.enabled;
            this->lingerTime = lingerOption.lingerTime;
            return *this;
          }
          /// @endcond

          /// @brief Gets or Sets a value that indicates whether to linger after the Socket is closed.
          /// @param enabled true if the Socket should linger after Socket.Close is called; otherwise, false.
          /// @return bool true if the Socket should linger after Socket.Close is called; otherwise, false.
          /// @remarks You can use the Enabled property to determine whether the Socket will linger after closing. Change this value to true or false and pass the altered LingerOption to the SetSocketOption method or set the LingerState or LingerState property.to disable or enable lingering.
          /// @remarks The following table describes the behavior for the possible values of the Enabled property and the LingerTime property stored in the LingerState property.
          /// | enable                              | seconds                                    | Behavior                                                                                                                          |
          /// |-------------------------------------|--------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
          /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data for a connection-oriented socket (TCP, for example) until the default IP protocol time-out expires. |
          /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
          /// | true (enabled)                      | A zero timeout.                            | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
          /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the LingerState property is not set.
          /// @remarks When the LingerTime property stored in the LingerState property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
          property_<bool> Enabled {
            get_ {return this->enabled;},
            set_ {this->enabled = value;}
          };

          /// @brief Gets the amount of time to remain connected after calling the Socket.Close method if data remains to be sent.
          /// @param lingerTime The amount of time, in seconds, to remain connected after calling Socket.Close.
          /// @return int32 The amount of time, in seconds, to remain connected after calling Socket.Close.
          /// @remarks Use this value if you want to determine how long a closed Socket will attempt to transfer unsent data before timing out. You can also set this value to the desired time-out period, in seconds.
          /// @remarks If the Enabled property is true, and you set LingerTime to 0, the Socket discards any pending data to send in the outgoing network buffer. If you change this value, you must pass the altered LingerOption instance to the SetSocketOption method or set the LingerState or LingerState property.
          /// @remarks The following table describes the behavior for the possible values of the Enabled property and the LingerTime property stored in the LingerState property.
          /// | enable                              | seconds                                    | Behavior                                                                                                                          |
          /// |-------------------------------------|--------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
          /// | false (disabled), the default value | The time-out is not applicable, (default). | Attempts to send pending data for a connection-oriented socket (TCP, for example) until the default IP protocol time-out expires. |
          /// | true (enabled)                      | A nonzero time-out                         | Attempts to send pending data until the specified time-out expires, and if the attempt fails, then Winsock resets the connection. |
          /// | true (enabled)                      | A zero timeout.                            | Discards any pending data. For connection-oriented socket (TCP, for example), Winsock resets the connection.                      |
          /// @remarks The IP stack computes the default IP protocol time-out period to use based on the round trip time of the connection. In most cases, the time-out computed by the stack is more relevant than one defined by an application. This is the default behavior for a socket when the LingerState property is not set.
          /// @remarks When the LingerTime property stored in the LingerState property is set greater than the default IP protocol time-out, the default IP protocol time-out will still apply and virtual.
          property_<int32> LingerTime {
            get_ {return this->lingerTime;},
            set_ {this->lingerTime = value;}
          };

        private:
          bool enabled = false;
          int32 lingerTime = 0;
        };
      }
    }
  }
}

using namespace Switch;
