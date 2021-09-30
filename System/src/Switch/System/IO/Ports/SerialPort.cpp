#include "../../../../../include/Switch/System/IO/Ports/SerialPort.hpp"

using namespace System;
using namespace System::IO::Ports;

Array<string> SerialPort::GetPortNames() {
  // from registry HKEY_LOCAL_MACHINE\HARDWARE\DEVICEMAP\SERIALCOMM on Windowd
  // from disk /dev/tty* on Linux or Mac
  return {"COM1", "COM2", "COM3", "COM4", "COM5", "COM6", "COM7", "COM8", "COM9", "COM10"};
}
