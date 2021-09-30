#include "../../../../include/Switch/System/Net/HttpWebResponse.hpp"

#include <Switch/System/Convert.hpp>
#include "../../../../include/Switch/System/Net/HttpWebRequest.hpp"
#include "../../../../include/Switch/System/Net/WebRequestMethods.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Net;

HttpWebResponse::HttpWebResponse(): WebResponse() {
}

HttpWebResponse::~HttpWebResponse() {
}

WebResponse::WebResponseStream HttpWebResponse::GetResponseStream() {
  if (this->webRequest->Method() == WebRequestMethods::Http::Get || this->webRequest->Method() == WebRequestMethods::Http::Post)
    return WebResponse::GetResponseStream();
  else
    throw InvalidOperationException(caller_);
}

HttpStatusCode HttpWebResponse::GetStatusCode() const {
  return HttpStatusCode(Convert::ToInt32(WebResponse::GetResponseCode()));
}

const string HttpWebResponse::GetStatusDescription() const {
  string description;
  static Dictionary<int32, string> statusDescriptions;

  if (statusDescriptions.Count == 0) {
    statusDescriptions[(int32)HttpStatusCode::Continue] = "The server has received the request headers, and the client should proceed to send the request body";
    statusDescriptions[(int32)HttpStatusCode::SwitchingProtocols] = "The requester has asked the server to switch protocols";
    statusDescriptions[(int32)HttpStatusCode::OK] = "The request is OK";
    statusDescriptions[(int32)HttpStatusCode::Created] = "The request has been fulfilled, and a new resource is created ";
    statusDescriptions[(int32)HttpStatusCode::Accepted] = "The request has been accepted for processing, but the processing has not been completed";
    statusDescriptions[(int32)HttpStatusCode::NonAuthoritativeInformation] = "The request has been successfully processed, but is returning information that may be from another source";
    statusDescriptions[(int32)HttpStatusCode::NoContent] = "The request has been successfully processed, but is not returning any content";
    statusDescriptions[(int32)HttpStatusCode::ResetContent] = "The request has been successfully processed, but is not returning any content, and requires that the requester reset the document view";
    statusDescriptions[(int32)HttpStatusCode::PartialContent] = "The server is delivering only part of the resource due to a range header sent by the client";
    statusDescriptions[(int32)HttpStatusCode::MultipleChoices] = "A link list. The user can select a link and go to that location. Maximum five addresses";
    statusDescriptions[(int32)HttpStatusCode::MovedPermanently] = "The requested page has moved to a new URL";
    statusDescriptions[(int32)HttpStatusCode::Redirect] = "The requested page has moved temporarily to a new URL";
    statusDescriptions[(int32)HttpStatusCode::SeeOther] = "The requested page can be found under a different URL";
    statusDescriptions[(int32)HttpStatusCode::NotModified] = "Indicates the requested page has not been modified since last requested";
    statusDescriptions[(int32)HttpStatusCode::UseProxy] = "Use proxy";
    statusDescriptions[(int32)HttpStatusCode::Unused] = "No longer used";
    statusDescriptions[(int32)HttpStatusCode::TemporaryRedirect] = "The requested page has moved temporarily to a new URL";
    statusDescriptions[(int32)HttpStatusCode::BadRequest] = "The request cannot be fulfilled due to bad syntax";
    statusDescriptions[(int32)HttpStatusCode::Unauthorized] = "The request was a legal request, but the server is refusing to respond to it. For use when authentication is possible but has failed or not yet been provided";
    statusDescriptions[(int32)HttpStatusCode::PaymentRequired] = "Reserved for future use";
    statusDescriptions[(int32)HttpStatusCode::Forbidden] = "The request was a legal request, but the server is refusing to respond to it";
    statusDescriptions[(int32)HttpStatusCode::NotFound] = "The requested page could not be found but may be available again in the future";
    statusDescriptions[(int32)HttpStatusCode::MethodNotAllowed] = "A request was made of a page using a request method not supported by that page";
    statusDescriptions[(int32)HttpStatusCode::NotAcceptable] = "The server can only generate a response that is not accepted by the client";
    statusDescriptions[(int32)HttpStatusCode::ProxyAuthenticationRequired] = "The client must first authenticate itself with the proxy";
    statusDescriptions[(int32)HttpStatusCode::RequestTimeout] = "The server timed out waiting for the request";
    statusDescriptions[(int32)HttpStatusCode::Conflict] = "The request could not be completed because of a conflict in the request";
    statusDescriptions[(int32)HttpStatusCode::Gone] = "The requested page is no longer available";
    statusDescriptions[(int32)HttpStatusCode::LengthRequired] = "The \"Content-Length\" is not defined. The server will not accept the request without it ";
    statusDescriptions[(int32)HttpStatusCode::PreconditionFailed] = "The precondition given in the request evaluated to false by the server";
    statusDescriptions[(int32)HttpStatusCode::RequestEntityTooLarge] = "The server will not accept the request, because the request entity is too large";
    statusDescriptions[(int32)HttpStatusCode::RequestUriTooLong] = "The server will not accept the request, because the URL is too long. Occurs when you convert a POST request to a GET request with a long query information";
    statusDescriptions[(int32)HttpStatusCode::UnsupportedMediaType] = "The server will not accept the request, because the media type is not supported";
    statusDescriptions[(int32)HttpStatusCode::RequestedRangeNotSatisfiable] = "The client has asked for a portion of the file, but the server cannot supply that portion";
    statusDescriptions[(int32)HttpStatusCode::ExpectationFailed] = "The server cannot meet the requirements of the Expect request-header field";
    statusDescriptions[(int32)HttpStatusCode::UpgradeRequired] = "Upgrade required";
    statusDescriptions[(int32)HttpStatusCode::InternalServerError] = "A generic error message, given when no more specific message is suitable";
    statusDescriptions[(int32)HttpStatusCode::NotImplemented] = "The server either does not recognize the request method, or it lacks the ability to fulfill the request";
    statusDescriptions[(int32)HttpStatusCode::BadGateway] = "The server was acting as a gateway or proxy and received an invalid response from the upstream server";
    statusDescriptions[(int32)HttpStatusCode::ServiceUnavailable] = "The server is currently unavailable (overloaded or down)";
    statusDescriptions[(int32)HttpStatusCode::GatewayTimeout] = "The server was acting as a gateway or proxy and did not receive a timely response from the upstream server";
    statusDescriptions[(int32)HttpStatusCode::HttpVersionNotSupported] = "The server does not support the HTTP protocol version used in the request";
  }
  HttpStatusCode statusCode = GetStatusCode();
  if (statusDescriptions.ContainsKey((int32)statusCode))
    description = statusDescriptions[(int32)statusCode];
  else
    description = "Unknown status code.";

  return description;
}

