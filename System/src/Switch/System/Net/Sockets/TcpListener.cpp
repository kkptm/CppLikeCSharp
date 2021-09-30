#include "../../../../../include/Switch/System/Net/Sockets/TcpListener.hpp"

#include <Switch/System/NullReferenceException.hpp>
#include "../../../../../include/Switch/System/Net/Sockets/SocketException.hpp"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

TcpListener::TcpListener(const IPEndPoint& ipEndPoint) {
  this->data->serverIPEndPoint = ipEndPoint;
  this->data->serverSocket = Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
  this->data->serverSocket.SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReuseAddress, true);
}

Socket TcpListener::AcceptSocket() {
  if (!this->data->active)
    throw InvalidOperationException(caller_);

  return this->data->serverSocket.Accept();
}

TcpClient TcpListener::AcceptTcpClient() {
  if (!this->data->active)
    throw InvalidOperationException(caller_);

  Socket pacceptedSocket = this->data->serverSocket.Accept();
  return TcpClient(pacceptedSocket);
}

void TcpListener::Start() {
  Start((int32)SocketOptionName::MaxConnections);
}

void TcpListener::Start(int32 backlog) {
  if (!this->data->active) {
    this->data->serverSocket.Bind(this->data->serverIPEndPoint);
    try {
      this->data->serverSocket.Listen(backlog);
    } catch (const SocketException& e) {
      Stop();
      throw e;
    }
  }
  this->data->active = true;
}

void TcpListener::Stop() {
  bool exclusiveAddressUse = this->data->serverSocket.ExclusiveAddressUse;
  this->data->serverSocket.Shutdown(SocketShutdown::Both);
  this->data->serverSocket.Close();
  this->data->active = false;
  this->data->serverSocket = Socket(this->data->serverIPEndPoint.AddressFamily(), SocketType::Stream, ProtocolType::Tcp);
  this->data->serverSocket.ExclusiveAddressUse = exclusiveAddressUse;
}

bool TcpListener::Pending() {
  if (!this->data->active)
    throw InvalidOperationException(caller_); // net stopped

  return this->data->serverSocket.Poll(0, SelectMode::SelectRead);
}
