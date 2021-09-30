#include "../../../../../include/Switch/System/Net/WebSockets/WebSocket.hpp"

using namespace System;
using namespace System::Net::WebSockets;

property_<TimeSpan, readonly_> System::Net::WebSockets::WebSocket::DefaultKeepAliveInterval {
  [] {return TimeSpan(30 * TimeSpan::TicksPerSecond);}
};
