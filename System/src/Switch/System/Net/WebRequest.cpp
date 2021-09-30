#include "../../../../include/Switch/System/Net/WebRequest.hpp"

#include <Switch/System/Buffer.hpp>
#include <Switch/System/Convert.hpp>
#include <Switch/System/Math.hpp>
#include <Switch/System/ObjectDisposedException.hpp>
#include <Switch/System/TimeoutException.hpp>
#include <Switch/System/IO/IOException.hpp>
#include <Switch/System/Threading/Timeout.hpp>
#include <Switch/System/Net/WebException.hpp>
#include "../../../../include/Switch/System/Net/FtpWebRequest.hpp"
#include "../../../../include/Switch/System/Net/HttpWebRequest.hpp"
#include "../../../../include/Switch/System/Net/WebRequestMethods.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Net;
using namespace System::IO;
using namespace System::Threading;

int32 WebRequest::pendingRequest = 0;

WebRequest::WebRequest(const string& uri) : uri(uri) {
  InitWebRequest();
}

WebRequest::WebRequest(const Uri& uri) : uri(uri) {
  InitWebRequest();
}

void WebRequest::InitWebRequest() {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false || (pendingRequest == 0 && Native::CurlApi::GlobalInit() != 0))
    throw NotSupportedException(caller_);

  Native::CurlApi::Init(this->requestHandle);

  if (this->requestHandle == IntPtr::Zero)
    throw NotSupportedException(caller_);

  pendingRequest++;
  Native::CurlApi::SetUrl(this->requestHandle, uri.ToString());
  Native::CurlApi::SetVerbose(this->requestHandle, 0L);
}

WebRequest::~WebRequest() {
  if (this->requestHandle != IntPtr::Zero) {
    Native::CurlApi::Cleanup(this->requestHandle);
    pendingRequest--;

    if (pendingRequest == 0)
      Native::CurlApi::GlobalCleanup();
  }
}

refptr<WebRequest> WebRequest::Create(const Uri& requestUriString) {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(caller_);

  if (requestUriString.Scheme == Uri::UriSchemeFtp)
    return new FtpWebRequest(requestUriString);

  if (requestUriString.Scheme == Uri::UriSchemeHttp)
    return new HttpWebRequest(requestUriString);

  if (requestUriString.Scheme == Uri::UriSchemeHttps)
    return new HttpWebRequest(requestUriString);

  throw NotSupportedException(caller_);
}

NetworkCredential&  WebRequest::GetCredential() {
  return this->credential;
}

bool WebRequest::IsRequestStreamNeeded() const {
  return GetMethod() == WebRequestMethods::Ftp::UploadFile || GetMethod() == WebRequestMethods::Http::Put || GetMethod() == WebRequestMethods::Http::Post;
}

bool WebRequest::IsResponseStreamNeeded() const {
  return  GetMethod() == WebRequestMethods::Ftp::DownloadFile || GetMethod() == WebRequestMethods::Ftp::ListDirectory || GetMethod() == WebRequestMethods::Ftp::ListDirectoryDetails || GetMethod() == WebRequestMethods::Http::Get || GetMethod() == WebRequestMethods::Http::Post;
}

void WebRequest::SetCredential(const NetworkCredential& credential) {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(caller_);

  if (this->requestHandle == IntPtr::Zero)
    throw NotSupportedException(caller_);

  Native::CurlApi::SetUserName(this->requestHandle, credential.UserName);
  Native::CurlApi::SetPassword(this->requestHandle, credential.Password);
  this->credential = credential;
}

void WebRequest::ProccessRequestThread() {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(caller_);

  try {
    this->internalError = Native::CurlApi::Perform(this->GetRequestHandle());
    if (this->internalError == 0) {
      double contentLength;
      if (Native::CurlApi::GetContentDownloadLength(this->GetRequestHandle(), contentLength) == 0)
        this->GetInternalResponse().contentLength = Convert::ToInt64(Double(contentLength));

      this->internalError = Native::CurlApi::GetContentType(this->GetRequestHandle(), this->GetInternalResponse().contentType);
    }
    this->Finished(this->internalError);
  } catch (const Exception&) {
    this->internalError = this->IsResponseStreamNeeded() ? 19 : 25;
    this->Finished(this->internalError);
  }
}

void WebRequest::Finished(int32 error) {
  if (!Native::CurlApi::GetOSSupportsWebOperations())
    throw NotSupportedException(caller_);

  //Unlock write thread if finished before sending
  this->requestStream.data->readEvent.Set();
  GetInternalResponse().EndTransfert();

  if (error != 0)
    throw System::Net::WebException(caller_);
}

void WebRequest::ProccessRequest() {
  if (!Native::CurlApi::GetOSSupportsWebOperations())
    throw NotSupportedException(caller_);

  //Thread already opened by the other stream (response or request)
  if (this->requestThread.IsAlive())
    return;

  Native::CurlApi::SetTimeout(this->requestHandle, Timeout());

  if (IsResponseStreamNeeded()) {
    Native::CurlApi::SetWriteFunction(this->requestHandle, WebResponse::WriteStream);
    Native::CurlApi::SetWriteData(this->requestHandle, &GetInternalResponse().responseStream);
  } else
    Native::CurlApi::SetWriteFunction(this->requestHandle, WebResponse::WriteNullStream);

  if (IsRequestStreamNeeded()) {
    Native::CurlApi::SetReadFunction(this->requestHandle, WebRequest::ReadStream);
    Native::CurlApi::SetReadData(this->requestHandle, &this->requestStream);

    if (GetMethod() == WebRequestMethods::Http::Post) {
      Native::CurlApi::SetUpload(this->requestHandle, 0L);
      if (this->contentLength > 0)
        Native::CurlApi::SetPostFieldSize(this->requestHandle, this->contentLength);
    } else {
      Native::CurlApi::SetUpload(this->requestHandle, 1L);
      if (this->contentLength > 0)
        Native::CurlApi::SetInFileSize(this->requestHandle, this->contentLength);
    }
  }

  this->requestThread.Start();
}

size_t WebRequest::ReadStream(void* buffer, size_t size, size_t nmemb, void* stream) {
  try {
    WebRequestStream* webRequestStream = (WebRequestStream*)stream;
    return webRequestStream->Send(buffer, static_cast<int32>(size * nmemb));
  } catch (const System::Exception&) {
    //Time out occurs during reading abort using CURL_READFUNC_ABORT return code
    return 0x10000000;
  }
}

System::Net::WebRequest::WebRequestStream WebRequest::GetRequestStream() {
  return this->requestStream;
}

int64 WebRequest::WebRequestStream::Seek(int64, System::IO::SeekOrigin) {
  throw NotSupportedException(caller_);
}

void WebRequest::WebRequestStream::Write(const Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0)
    throw ArgumentOutOfRangeException(caller_);
  if (IsClosed())
    throw ObjectDisposedException(caller_);
  if (!CanWrite())
    throw NotSupportedException(caller_);

  if (CanWrite())
    Write((void*)&buffer.Data()[offset], count);
}

void WebRequest::WebRequestStream::Write(const void* handle, int32 count) {
  if (IsClosed())
    throw IO::IOException(caller_);

  //If the request is not started launch the writing thread
  if (!this->data->started) {
    this->data->started = true;
    this->data->webRequest->ProccessRequest();
  }

  if (this->data->webRequest->internalError == 0) {
    this->data->buffer = (void*)handle;
    this->data->bufferSize = count;
    this->data->bufferOffset = 0;
    //release read
    this->data->writeEvent.Set();
    //Wait read is finished

    if (!this->data->readEvent.WaitOne(this->data->webRequest->Timeout()))
      throw TimeoutException(caller_);
  } else {
    //release read
    this->data->writeEvent.Set();
    throw InvalidOperationException(caller_);
  }
}

int32 WebRequest::WebRequestStream::Send(void* handle, int32 count) {
  int32 byteToCopy = 0;
  // Wait data to read
  if (!this->data->writeEvent.WaitOne(this->data->webRequest->Timeout()))
    throw TimeoutException(caller_);

  if (this->data->webRequest->internalError == 0) {
    byteToCopy = Math::Min(count, (this->data->bufferSize - this->data->bufferOffset));
    Buffer::BlockCopy(this->data->buffer, this->data->bufferSize, this->data->bufferOffset, handle, count, 0, byteToCopy);
    this->data->bufferOffset += byteToCopy;
    if (this->data->bufferOffset == this->data->bufferSize) {
      // Release write thread if all the data has been read
      this->data->writeEvent.Reset();
      this->data->readEvent.Set();
    }
  } else {
    this->data->readEvent.Set();
    byteToCopy = 0x10000000 ; //CURL_READFUNC_ABORT  0x10000000
  }

  return byteToCopy;
}

void WebRequest::WebRequestStream::Close() {
  if (!IsClosed()) {
    Stream::Close();
    //Unlock sending thread with an empty buffer
    this->data->bufferSize = 0;
    this->data->bufferOffset = 0;
    this->data->writeEvent.Set();
    if (this->data->started && !this->data->webRequest->IsResponseStreamNeeded())
      this->data->webRequest->requestThread.Join();
  }
}


