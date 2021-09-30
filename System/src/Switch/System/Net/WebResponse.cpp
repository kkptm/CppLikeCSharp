#include "../../../../include/Switch/System/Net/WebResponse.hpp"

#include <Switch/Types.hpp>
#include <Switch/System/Buffer.hpp>
#include <Switch/System/Math.hpp>
#include <Switch/System/TimeoutException.hpp>
#include <Switch/System/IO/IOException.hpp>
#include "../../../../include/Switch/System/Net/WebRequest.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Net;
using namespace System::IO;
using namespace System::Threading;

WebResponse::WebResponse() {
  if (!Native::CurlApi::GetOSSupportsWebOperations())
    throw NotSupportedException(caller_);
}

void WebResponse::SetWebRequest(WebRequest& webRequest) {
  if (!Native::CurlApi::GetOSSupportsWebOperations())
    throw NotSupportedException(caller_);

  this->webRequest = &webRequest;
  this->responseStream.SetWebRequest(this->webRequest);
}

WebResponse::~WebResponse() {
  this->responseStream.Close();
}

System::Net::WebResponse::WebResponseStream WebResponse::GetResponseStream() {
  return this->responseStream;
}

size_t WebResponse::WriteNullStream(void* buffer, size_t size, size_t nmemb, void* stream) {
  return nmemb * size;
}

size_t WebResponse::WriteStream(void* buffer, size_t size, size_t nmemb, void* stream) {
  WebResponseStream* webResponseStream = (WebResponseStream*)stream;
  int32 ret = webResponseStream->Receive(buffer, static_cast<int32>(size * nmemb));
  return ret;
}

void WebResponse::StartTransfert() {
  this->responseStream.StartTransfert();
}


void WebResponse::EndTransfert() {
  this->responseStream.EndTransfert();
}

int64 WebResponse::GetResponseCode() const {
  if (!Native::CurlApi::GetOSSupportsWebOperations())
    throw NotSupportedException(caller_);

  int64 code = 0;
  Native::CurlApi::GetResponseCode(this->webRequest->GetRequestHandle(), code);
  return int64(code);
}

void WebResponse::WebResponseStream::SetWebRequest(WebRequest* webRequest) {
  this->data->webRequest = webRequest;
}

void WebResponse::WebResponseStream::StartTransfert() {
  //If the request is not started launch the writing thread
  if (!this->data->started) {
    this->data->started = true;
    //Launch the writing thread
    this->data->writeEvent.Reset();
    this->data->readEvent.Set();
    this->data->webRequest->ProccessRequest();
    //Wait the first response packet
    if (!this->data->writeEvent.WaitOne(this->data->webRequest->Timeout))
      throw TimeoutException(caller_);
  }
}

int64 WebResponse::WebResponseStream::Seek(int64, System::IO::SeekOrigin) {
  throw NotSupportedException(caller_);
}

int32 WebResponse::WebResponseStream::Read(Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0)
    throw ArgumentOutOfRangeException(caller_);
  if (IsClosed())
    throw IOException(caller_);
  if (!CanRead())
    throw NotSupportedException(caller_);

  int32 nbBytesRead = 0;
  if (CanRead())
    nbBytesRead = Read((void*)&buffer.Data()[offset], count);

  if (nbBytesRead == -1)
    nbBytesRead = 0;

  return nbBytesRead;
}


int32 WebResponse::WebResponseStream::Read(void* handle, int32 count) {
  int32 byteToCopy  = 0;
  StartTransfert();
  //Wait data to read
  bool isTimeout = !this->data->writeEvent.WaitOne(this->data->webRequest->Timeout);
  if (this->data->webRequest->internalError == 0) {
    if (!isTimeout && !this->data->finished) {
      byteToCopy = Math::Min(count, (this->data->bufferSize - this->data->bufferOffset));
      Buffer::BlockCopy(this->data->buffer, this->data->bufferSize, this->data->bufferOffset, handle, count, 0, byteToCopy);

      if (byteToCopy < (this->data->bufferSize - this->data->bufferOffset))
        this->data->bufferOffset = this->data->bufferOffset + byteToCopy;
      else {
        //Release write thread if all the data has been read
        this->data->writeEvent.Reset();
        this->data->readEvent.Set();
      }
    } else {
      if (isTimeout)
        throw TimeoutException(caller_);

      //Transfer is finished
      this->data->finished = true;
      this->data->readEvent.Set();
      byteToCopy = -1;
    }
  } else {
    //Internal error occur
    this->data->finished = true;
    this->data->readEvent.Set();
    byteToCopy = -1;
  }

  return byteToCopy;
}

int32 WebResponse::WebResponseStream::Receive(const void* handle, int32 count) {
  //Wait previous read is finished
  if (!this->data->readEvent.WaitOne(ReadTimeout()))
    throw TimeoutException(caller_);

  if (this->data->webRequest->internalError != 0)
    return 0;

  if (!this->data->finished) {
    this->data->buffer = const_cast<void*>(handle);
    this->data->bufferSize = count;
    this->data->bufferOffset = 0;
    //Unlock Read thread
    this->data->readEvent.Reset();
    this->data->writeEvent.Set();

    //Wait end of read
    if (!this->data->readEvent.WaitOne(ReadTimeout()))
      throw TimeoutException(caller_);
  }

  return count;
}

void WebResponse::WebResponseStream::EndTransfert() {
  this->data->finished = true;
  this->data->writeEvent.Set();
  this->data->readEvent.Set();
}

void WebResponse::WebResponseStream::Close() {
  if (!IsClosed()) {
    Stream::Close();
    EndTransfert();
    if (this->data->started)
      this->data->webRequest->requestThread.Join();
  }
}


