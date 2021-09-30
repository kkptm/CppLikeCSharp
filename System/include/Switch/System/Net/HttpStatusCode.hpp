/// @file
/// @brief Contains Switch::System::Net::HttpStatusCode enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Specifies the status codes returned for a Hyper Text Transfer Protocol (HTTP) operation.
      /// @par Library
      /// Switch.System
      enum class HttpStatusCode {
        /// @brief Included for completeness, this value is never returned by servers.
        Undefined = 0,
        /// @brief Equivalent to HTTP status 100. Continue indicates that the client can continue with its request.
        Continue  = 100,
        /// @brief  Equivalent to HTTP status 101. SwitchingProtocols indicates that the protocol version or protocol is being changed.
        SwitchingProtocols = 101,
        /// @brief Equivalent to HTTP status 200. OK indicates that the request succeeded and that the requested information is in the response. This is the most common status code to receive.
        OK = 200,
        /// @brief  Equivalent to HTTP status 201. Created indicates that the request resulted in a new resource created before the response was sent.
        Created = 201,
        /// @brief Equivalent to HTTP status 202. Accepted indicates that the request has been accepted for further processing.
        Accepted = 202,
        /// @brief Equivalent to HTTP status 203. NonAuthoritativeInformation indicates that the returned metainformation is from a cached copy instead of the origin server and therefore may be incorrect.
        NonAuthoritativeInformation = 203,
        /// @brief Equivalent to HTTP status 204. NoContent indicates that the request has been successfully processed and that the response is intentionally blank.
        NoContent = 204,
        /// @brief Equivalent to HTTP status 205. ResetContent indicates that the client should reset (not reload) the current resource.
        ResetContent = 205,
        /// @brief Equivalent to HTTP status 206. PartialContent indicates that the response is a partial response as requested by a GET request that includes a byte range.
        PartialContent = 206,
        /// @brief Equivalent to HTTP status 300. MultipleChoices indicates that the requested information has multiple representations. The default action is to treat this status as a redirect and follow the contents of the Location header associated with this response. If the HttpWebRequest.AllowAutoRedirect property is false, MultipleChoices will cause an exception to be thrown. MultipleChoices is a synonym for Ambiguous.
        MultipleChoices = 300,
        /// @brief Equivalent to HTTP status 301. MovedPermanently indicates that the requested information has been moved to the URI specified in the Location header. The default action when this status is received is to follow the Location header associated with the response. MovedPermanently is a synonym for Moved.
        MovedPermanently = 301,
        /// @brief Equivalent to HTTP status 302. Redirect indicates that the requested information is located at the URI specified in the Location header. The default action when this status is received is to follow the Location header associated with the response. When the original request method was POST, the redirected request will use the GET method. If the HttpWebRequest.AllowAutoRedirect property is false, Redirect will cause an exception to be thrown.
        Redirect = 302,
        /// @brief Equivalent to HTTP status 303. SeeOther automatically redirects the client to the URI specified in the Location header as the result of a POST. The request to the resource specified by the Location header will be made with a GET. If the HttpWebRequest.AllowAutoRedirect property is false, SeeOther will cause an exception to be thrown.
        SeeOther = 303,
        /// @brief Equivalent to HTTP status 304. NotModified indicates that the client's cached copy is up to date. The contents of the resource are not transferred.
        NotModified = 304,
        /// @brief Equivalent to HTTP status 305. UseProxy indicates that the request should use the proxy server at the URI specified in the Location header.
        UseProxy = 305,
        /// @brief Equivalent to HTTP status 306. Unused is a proposed extension to the HTTP/1.1 specification that is not fully specified.
        Unused  = 306,
        /// @brief Equivalent to HTTP status 307. TemporaryRedirect indicates that the request information is located at the URI specified in the Location header. The default action when this status is received is to follow the Location header associated with the response. When the original request method was POST, the redirected request will also use the POST method. If the HttpWebRequest.AllowAutoRedirect property is false, TemporaryRedirect will cause an exception to be thrown.
        TemporaryRedirect = 307,
        /// @brief Equivalent to HTTP status 400. BadRequest indicates that the request could not be understood by the server. BadRequest is sent when no other error is applicable, or if the exact error is unknown or does not have its own error code.
        BadRequest = 400,
        /// @brief Equivalent to HTTP status 401. Unauthorized indicates that the requested resource requires authentication. The WWW-Authenticate header contains the details of how to perform the authentication.
        Unauthorized = 401,
        /// @brief Equivalent to HTTP status 402. PaymentRequired is reserved for future use.
        PaymentRequired = 402,
        /// @brief Equivalent to HTTP status 403. Forbidden indicates that the server refuses to fulfill the request.
        Forbidden = 403,
        /// @brief Equivalent to HTTP status 404. NotFound indicates that the requested resource does not exist on the server.
        NotFound = 404,
        /// @brief Equivalent to HTTP status 405. MethodNotAllowed indicates that the request method (POST or GET) is not allowed on the requested resource.
        MethodNotAllowed = 405,
        /// @brief Equivalent to HTTP status 406. NotAcceptable indicates that the client has indicated with Accept headers that it will not accept any of the available representations of the resource.
        NotAcceptable = 406,
        /// @brief Equivalent to HTTP status 407. ProxyAuthenticationRequired indicates that the requested proxy requires authentication. The Proxy-authenticate header contains the details of how to perform the authentication.
        ProxyAuthenticationRequired = 407,
        /// @brief Equivalent to HTTP status 408. RequestTimeout indicates that the client did not send a request within the time the server was expecting the request.
        RequestTimeout  = 408,
        /// @brief Equivalent to HTTP status 409. Conflict indicates that the request could not be carried out because of a conflict on the server.
        Conflict = 409,
        /// @brief Equivalent to HTTP status 410. Gone indicates that the requested resource is no longer available.
        Gone = 410,
        /// @brief Equivalent to HTTP status 411. LengthRequired indicates that the required Content-length header is missing.
        LengthRequired  = 411,
        /// @brief Equivalent to HTTP status 412. PreconditionFailed indicates that a condition set for this request failed, and the request cannot be carried out. Conditions are set with conditional request headers like If-Match, If-None-Match, or If-Unmodified-Since.
        PreconditionFailed = 412,
        /// @brief Equivalent to HTTP status 413. RequestEntityTooLarge indicates that the request is too large for the server to process.
        RequestEntityTooLarge = 413,
        /// @brief Equivalent to HTTP status 414. RequestUriTooLong indicates that the URI is too long.
        RequestUriTooLong = 414,
        /// @brief Equivalent to HTTP status 415. UnsupportedMediaType indicates that the request is an unsupported type.
        UnsupportedMediaType = 415,
        /// @brief Equivalent to HTTP status 416. RequestedRangeNotSatisfiable indicates that the range of data requested from the resource cannot be returned, either because the beginning of the range is before the beginning of the resource, or the end of the range is after the end of the resource.
        RequestedRangeNotSatisfiable = 416,
        /// @brief Equivalent to HTTP status 417. ExpectationFailed indicates that an expectation given in an Expect header could not be met by the server.
        ExpectationFailed = 417,
        /// @brief Equivalent to HTTP status 426. UpgradeRequired indicates that the client should switch to a different protocol such as TLS/1.0.
        UpgradeRequired = 426,
        /// @brief Equivalent to HTTP status 500. InternalServerError indicates that a generic error has occurred on the server.
        InternalServerError = 500,
        /// @brief Equivalent to HTTP status 501. NotImplemented indicates that the server does not support the requested function.
        NotImplemented = 501,
        /// @brief Equivalent to HTTP status 502. BadGateway indicates that an intermediate proxy server received a bad response from another proxy or the origin server.
        BadGateway = 502,
        /// @brief Equivalent to HTTP status 503. ServiceUnavailable indicates that the server is temporarily unavailable, usually due to high load or maintenance.
        ServiceUnavailable = 503,
        /// @brief Equivalent to HTTP status 504. GatewayTimeout indicates that an intermediate proxy server timed out while waiting for a response from another proxy or the origin server.
        GatewayTimeout = 504,
        /// @brief Equivalent to HTTP status 505. HttpVersionNotSupported indicates that the requested HTTP version is not supported by the server.
        HttpVersionNotSupported = 505
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Net::HttpStatusCode> {
  void operator()(System::Collections::Generic::IDictionary<System::Net::HttpStatusCode, string>& values, bool& flags) {
    values[System::Net::HttpStatusCode::Undefined] = "Undefined";
    values[System::Net::HttpStatusCode::SwitchingProtocols] = "SwitchingProtocols";
    values[System::Net::HttpStatusCode::OK] = "OK";
    values[System::Net::HttpStatusCode::Created] = "Created";
    values[System::Net::HttpStatusCode::Accepted] = "Accepted";
    values[System::Net::HttpStatusCode::NonAuthoritativeInformation] = "NonAuthoritativeInformation";
    values[System::Net::HttpStatusCode::NoContent] = "NoContent";
    values[System::Net::HttpStatusCode::ResetContent] = "ResetContent";
    values[System::Net::HttpStatusCode::PartialContent] = "PartialContent";
    values[System::Net::HttpStatusCode::MultipleChoices] = "MultipleChoices";
    values[System::Net::HttpStatusCode::MovedPermanently] = "MovedPermanently";
    values[System::Net::HttpStatusCode::Redirect] = "Redirect";
    values[System::Net::HttpStatusCode::SeeOther] = "SeeOther";
    values[System::Net::HttpStatusCode::NotModified] = "NotModified";
    values[System::Net::HttpStatusCode::UseProxy] = "UseProxy";
    values[System::Net::HttpStatusCode::Unused] = "Unused";
    values[System::Net::HttpStatusCode::TemporaryRedirect] = "TemporaryRedirect";
    values[System::Net::HttpStatusCode::BadRequest] = "BadRequest";
    values[System::Net::HttpStatusCode::Unauthorized] = "Unauthorized";
    values[System::Net::HttpStatusCode::PaymentRequired] = "PaymentRequired";
    values[System::Net::HttpStatusCode::Forbidden] = "Forbidden";
    values[System::Net::HttpStatusCode::NotFound] = "NotFound";
    values[System::Net::HttpStatusCode::MethodNotAllowed] = "MethodNotAllowed";
    values[System::Net::HttpStatusCode::NotAcceptable] = "NotAcceptable";
    values[System::Net::HttpStatusCode::ProxyAuthenticationRequired] = "ProxyAuthenticationRequired";
    values[System::Net::HttpStatusCode::RequestTimeout] = "RequestTimeout";
    values[System::Net::HttpStatusCode::Conflict] = "Conflict";
    values[System::Net::HttpStatusCode::Gone] = "Gone";
    values[System::Net::HttpStatusCode::LengthRequired] = "LengthRequired";
    values[System::Net::HttpStatusCode::PreconditionFailed] = "PreconditionFailed";
    values[System::Net::HttpStatusCode::RequestEntityTooLarge] = "RequestEntityTooLarge";
    values[System::Net::HttpStatusCode::RequestUriTooLong] = "RequestUriTooLong";
    values[System::Net::HttpStatusCode::UnsupportedMediaType] = "UnsupportedMediaType";
    values[System::Net::HttpStatusCode::RequestedRangeNotSatisfiable] = "RequestedRangeNotSatisfiable";
    values[System::Net::HttpStatusCode::ExpectationFailed] = "ExpectationFailed";
    values[System::Net::HttpStatusCode::UpgradeRequired] = "UpgradeRequired";
    values[System::Net::HttpStatusCode::InternalServerError] = "InternalServerError";
    values[System::Net::HttpStatusCode::NotImplemented] = "NotImplemented";
    values[System::Net::HttpStatusCode::BadGateway] = "BadGateway";
    values[System::Net::HttpStatusCode::ServiceUnavailable] = "ServiceUnavailable";
    values[System::Net::HttpStatusCode::GatewayTimeout] = "GatewayTimeout";
    values[System::Net::HttpStatusCode::HttpVersionNotSupported] = "HttpVersionNotSupported";
    flags = false;
  }
};
/// @endcond

using namespace Switch;
