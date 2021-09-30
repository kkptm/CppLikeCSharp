/// @file
/// @brief Contains Switch::System::Uri class.
#pragma once

#include <Switch/Property.hpp>
#include <Switch/Types.hpp>
#include <Switch/System/Char.hpp>
#include <Switch/System/ConsoleKeyInfo.hpp> // must be included (if not build error) TODO : Remove...
#include <Switch/System/Object.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/SystemException.hpp>
#include <Switch/System/IO/Path.hpp>
#include <Switch/System/Net/IPAddress.hpp>
#include <Switch/System/Runtime/Serialization/ISerializable.hpp>
#include "UriComponents.hpp"
#include "UriFormat.hpp"
#include "UriFormatException.hpp"
#include "UriKind.hpp"
#include "UriHostNameType.hpp"
#include "UriPartial.hpp"
#include "../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Provides an object representation of a uniform resource identifier (URI) and easy access to the parts of the URI.
    /// @remarks A URI is a compact representation of a resource available to your application on the intranet or Internet. The Uri class defines the properties and methods for handling URIs, including parsing, comparing, and combining. The Uri class properties are read-only; to create a modifiable object, use the UriBuilder class.
    /// @remarks Relative URIs (for example, "/new/index.htm") must be expanded with respect to a base URI so that they are absolute. The MakeRelative method is provided to convert absolute URIs to relative URIs when necessary.
    /// @remarks The Uri constructors do ! escape URI strings if the string is a well-formed URI including a scheme identifier.
    /// @remarks The Uri properties return a canonical data representation in escaped encoding, with all characters with Unicode values greater than 127 replaced with their hexadecimal equivalents. To put the URI in canonical form, the Uri constructor performs the following steps:
    /// @remarks Converts the URI scheme to lowercase.
    /// @remarks Converts the host name to lowercase.
    /// @remarks If the host name is an IPv6 address, the canonical IPv6 address is used. ScopeId and other optional IPv6 data are removed.
    /// @remarks Removes default and empty port numbers.
    /// @remarks Canonicalizes the path for hierarchical URIs by compacting sequences such as /./, /../, //, including escaped representations. Note that there are some schemes for which escaped representations are ! compacted.
    /// @remarks For hierarchical URIs, if the host is ! terminated with a forward slash (/), one is added.
    /// @remarks By default, any reserved characters in the URI are escaped in accordance with RFC 2396. This behavior changes if International Resource Identifiers or International Domain Name parsing is enabled in which case reserved characters in the URI are escaped in accordance with RFC 3986 and RFC 3987.
    /// @remarks As part of canonicalization in the constructor for some schemes, escaped representations are compacted. The schemes for which URI will compact escaped sequences include the following: file, http, https, net.pipe, and net.tcp. For all other schemes, escaped sequences are ! compacted. For example: if you percent encode the two dots ".." as "%2E%2E" then the URI constructor will compact this sequence for some schemes. For example, the following code sample shows a URI constructor for the http scheme.
    /// @par Library
    /// Switch.System
    class system_export_ Uri : public Object, public System::Runtime::Serialization::ISerializable {
    public:
      /// @cond
      void SetUri(const String& uri, UriKind kind) {
        this->originalUri = uri;
        this->kind = kind;

        String originalUri = this->originalUri.TrimStart(' ').TrimEnd(' ');

        SetScheme(originalUri);
        if (this->scheme != "news") {
          SetUserInfo(originalUri);
          SetHost(originalUri);
          SetPort(originalUri);
        }
        SetPath(originalUri);
        SetFragment(originalUri);
        SetQuery(originalUri);

        if (this->kind == UriKind::Absolute) {
          if (this->scheme.Length() == 0)
            throw UriFormatException(caller_);

          if (this->scheme != "news" && this->host.Length() == 0)
            throw UriFormatException(caller_);

          if (CheckSchemeName(this->scheme) == false)
            throw UriFormatException(caller_);
        } else if (this->kind == UriKind::Relative) {
          if (this->scheme.Length() != 0 && this->host.Length() != 0)
            throw UriFormatException(caller_);
        }

        if (originalUri.Length() != 0)
          throw UriFormatException(caller_);
      }
      /// @endcond

      /// @brief Specifies the characters that separate the communication protocol scheme from the address portion of the URI. This field is read-only.
      static property_<string, readonly_> SchemeDelimiter;

      /// @brief Specifies that the URI is a pointer to a file. This field is read-only.
      static property_<string, readonly_> UriSchemeFile;

      /// @brief Specifies that the URI is accessed through the File Transfer Protocol (FTP). This field is read-only.
      static property_<string, readonly_> UriSchemeFtp;

      /// @brief Specifies that the URI is accessed through the Gopher protocol. This field is read-only.
      static property_<string, readonly_> UriSchemeGopher;

      /// @brief Specifies that the URI is accessed through the Hypertext Transfer Protocol (HTTP). This field is read-only.
      static property_<string, readonly_> UriSchemeHttp;

      /// @brief Specifies that the URI is accessed through the Hypertext Transfer Protocol (HTTPS). This field is read-only.
      static property_<string, readonly_> UriSchemeHttps;

      /// @brief Specifies that the URI is an e-mail address and is accessed through the Simple Mail Transport Protocol (SMTP). This field is read-only.
      static property_<string, readonly_> UriSchemeMailto;

      /// @brief Specifies that the URI is accessed through the NetPipe scheme used by Windows Communication Foundation (WCF). This field is read-only.
      static property_<string, readonly_> UriSchemeNetPipe;

      /// @brief Specifies that the URI is accessed through the NetTcp scheme used by Windows Communication Foundation (WCF). This field is read-only.
      static property_<string, readonly_> UriSchemeNetTcp;

      /// @brief Specifies that the URI is an Internet news group and is accessed through the Network News Transport Protocol (NNTP). This field is read-only.
      static property_<string, readonly_> UriSchemeNews;

      /// @brief Specifies that the URI is an Internet news group and is accessed through the Network News Transport Protocol (NNTP). This field is read-only.
      static property_<string, readonly_> UriSchemeNntp;

      /// @brief Initializes a new instance of the Uri class.
      Uri() = default;

      /// @brief Initializes a new instance of the Uri class by copy.
      Uri(const Uri& uri) : originalUri(uri.originalUri), scheme(uri.scheme), schemeDelimiter(uri.schemeDelimiter), userInfo(uri.userInfo), host(uri.host), port(uri.port), path(uri.path), query(uri.query), fragment(uri.fragment), kind(uri.kind) {}

      /// @brief Initializes a new instance of the Uri class with the specified URI.
      /// @param uri : A URI.
      /// @exception ArgumentNullException uri is null.
      explicit Uri(const String& uri) {
        SetUri(uri, UriKind::Absolute);
      }

      /// @brief Initializes a new instance of the Uri class with the specified URI.
      /// @param uri : A URI.
      /// @exception ArgumentNullException uri is null.
      Uri(const String& uri, UriKind kind) {
        SetUri(uri, kind);
      }

      /// @brief Initializes a new instance of the Uri class based on the specified base URI and relative URI string.
      /// @param baseUri : The base URI.
      /// @param relativeUri : The relative URI to add to the base URI.
      /// @exception ArgumentNullException uri is null.
      Uri(const Uri& baseUri, const String& relativeUri) {
        SetUri(baseUri.originalUri + relativeUri, baseUri.kind);
      }

      /// @brief Initializes a new instance of the Uri class based on the combination of a specified base Uri instance and a relative Uri instance.
      /// @param baseUri : An absolute Uri that is the base for the new Uri instance.
      /// @param relativeUri : A relative Uri instance that is combined with baseUri.
      /// @exception ArgumentNullException uri is null.
      Uri(const Uri& baseUri, const Uri& relativeUri) {
        SetUri(baseUri.originalUri + relativeUri.originalUri, baseUri.kind);
      }

      /// @brief Gets the absolute path of the URI.
      /// @return string A string containing the absolute path to the resource.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The AbsolutePath property contains the path information that the server uses to resolve requests for information. Typically this is the path to the desired information on the server's file system, although it also can indicate the application or script the server must run to provide the information.
      /// @remarks The path information does ! include the scheme, host name, or query portion of the URI.
      property_<String, readonly_> AbsolutePath {
        get_ {return this->GetComponents(UriComponents::Path, UriFormat::UriEscaped);}
      };

      /// @brief Gets the absolute URI.
      /// @return string A string containing the entire URI.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The AbsoluteUri property includes the entire URI stored in the Uri instance, including all fragments and query strings.
      property_<String, readonly_> AbsoluteUri {
        get_ {return this->GetComponents(UriComponents::AbsoluteUri, UriFormat::UriEscaped);}
      };

      /// @brief Gets the Domain Name System (DNS) host name or IP address and the port number for a server.
      /// @return string A string containing the authority component of the URI represented by this instance.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The Authority property is typically a server DNS host name or IP address. This property might include the service port number if it differs from the default port for the URI. If the Authority component contains reserved characters, these are escaped in the string value returned by this property.
      property_<String, readonly_> Authority {
        get_ {return this->GetComponents(UriComponents((int32)UriComponents::UserInfo | (int32)UriComponents::KeepDelimiter), UriFormat::UriEscaped) + GetComponents(UriComponents((int32)UriComponents::Host | (int32)UriComponents::KeepDelimiter), UriFormat::UriEscaped) + GetComponents(UriComponents((int32)UriComponents::Port | (int32)UriComponents::KeepDelimiter), UriFormat::UriEscaped);}
      };

      /// @brief Gets an unescaped host name that is safe to use for DNS resolution.
      /// @return string A string that contains the unescaped host part of the URI that is suitable for DNS resolution; or the original unescaped host string, if it is already suitable for resolution.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks For IPv6 addresses, the brackets ([]) are removed and the ScopeId property is set, if one was specified when this instance was constructed.
      property_<String, readonly_> DnsSafeHost {
        get_ {return this->GetComponents(UriComponents::Host, UriFormat::SafeUnescaped);}
      };

      /// @brief Gets the escaped URI fragment.
      /// @return string A string that contains any URI fragment information.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The Fragment property gets any text following a fragment marker (#) in the URI, including the fragment marker itself. Given the URI http://www.contoso.com/index.htm#main, the Fragment property would return #main.
      /// @remarks The Fragment property is ! considered in any Equals comparison.
      property_<String, readonly_> Fragment {
        get_ {return this->GetComponents(UriComponents((int32)UriComponents::Fragment | (int32)UriComponents::KeepDelimiter), UriFormat::UriEscaped);}
      };

      /// @brief Gets the host component of this instance.
      /// @return string A string that contains the host name. This is usually the DNS host name or IP address of the server.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks Unlike the Authority property, this property value does ! include the port number.
      property_<String, readonly_> Host {
        get_ {return this->GetComponents(UriComponents::Host, UriFormat::UriEscaped);}
      };

      /// @brief Gets the type of the host name specified in the URI.
      /// @return UriHostNameType A member of the UriHostNameType enumeration.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      property_<UriHostNameType, readonly_> HostNameType {
        get_ {
          if (this->kind != UriKind::Absolute)
            throw InvalidOperationException(caller_);

          if (!String::IsNullOrEmpty(this->Host)) {
            System::Net::IPAddress ipAddress;
            if (System::Net::IPAddress::TryParse(this->Host, ipAddress) == false)
              return UriHostNameType::Dns;

            if (ipAddress.AddressFamily == System::Net::Sockets::AddressFamily::InterNetwork)
              return UriHostNameType::IPv4;

            if (ipAddress.AddressFamily == System::Net::Sockets::AddressFamily::InterNetworkV6)
              return UriHostNameType::IPv6;
          }

          if (this->Scheme() == Uri::UriSchemeMailto || this->Scheme() == Uri::UriSchemeFile)
            return UriHostNameType::Basic;

          return UriHostNameType::Unknown;
        }
      };

      /// @brief Gets whether the Uri instance is absolute.
      /// @return bool A bool value that is true if the Uri instance is absolute; otherwise, false.
      /// @remarks This property is true if the string or Uri instance that was passed into the constructor can be parsed as an absolute Uri instance, which contains a scheme, an authority, and a path. Otherwise, the Uri instance is treated as relative and might omit the scheme or other URI components.
      property_<bool, readonly_> IsAbsoluteUri {
        get_ {return this->kind == UriKind::Absolute;}
      };

      /// @brief Gets whether the port value of the URI is the default for this scheme.
      /// @return bool A bool value that is true if the value in the Port property is the default port for this scheme; otherwise, false.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      property_<bool, readonly_> IsDefaultPort {
        get_ {
          if (this->kind != UriKind::Absolute)
            throw InvalidOperationException(caller_);

          return (this->Port() == -1 || this->Port() == 21 || this->Port() == 70 || this->Port() == 80 || this->Port() == 443 || this->Port() == 389 || this->Port() == 25 || this->Port() == 119);
        }
      };

      /// @brief Gets a value indicating whether the specified Uri is a file URI.
      /// @return bool A bool value that is true if the Uri is a file URI; otherwise, false.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The IsFile property is true when the Scheme property equals UriSchemeFile.
      property_<bool, readonly_> IsFile {
        get_ {
          if (this->kind != UriKind::Absolute)
            throw InvalidOperationException(caller_);

          return this->Scheme() == UriSchemeFile;
        }
      };

      /// @brief Gets whether the specified Uri references the local host.
      /// @return bool A bool value that is true if this Uri references the local host; otherwise, false.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks IsLoopback returns true if the URI specified when this instance was created was 127.0.0.1, loopback, or localhost, or if the URI did ! specify host information (for example, file:///c:Dir/file.txt). All other URIs return false.
      property_<bool, readonly_> IsLoopback {
        get_ {
          if (this->kind != UriKind::Absolute)
            throw InvalidOperationException(caller_);

          return this->Host() == System::Net::IPAddress::Loopback().ToString() || this->Host() == System::Net::IPAddress::IPv6Loopback().ToString() || this->Host() == "loopback" || this->Host() == "localhost" || String::IsNullOrEmpty(this->Host());
        }
      };

      /// @brief Gets whether the specified Uri is a universal naming convention (UNC) path.
      /// @return bool A bool value that is true if the Uri is a UNC path; otherwise, false.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The IsUnc property is true if the specified Uri instance is a UNC path (such as \\server\folder or file://server/folder). This property always returns true if the URI has the file:// scheme and specifies a host component.
      property_<bool, readonly_> IsUnc {
        get_ {
          if (this->kind != UriKind::Absolute)
            throw InvalidOperationException(caller_);

          return this->Scheme() == Uri::UriSchemeFile && !String::IsNullOrEmpty(this->Host());
        }
      };

      /// @brief Gets the original URI string that was passed to the Uri constructor.
      /// @return string A string containing the exact URI specified when this instance was constructed; otherwise, Empty.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks If the URI specified to the constructor contained leading or trailing spaces, these spaces are preserved.
      /// @remarks The value returned by this property differs from ToString and AbsoluteUri. ToString returns the canonically unescaped form of the URI. AbsoluteUri returns the canonically escaped form of the URI.
      /// @remarks When International Resource Identifier (IRI) and Internationalized Domain Name (IDN) support are enabled, OriginalString returns the original non normalized string with Punycode host name if one was used to initialize the Uri instance. Punycode names contain only ASCII characters and always start with the xn-- prefix.
      /// @remarks For more information on IRI support, see the Remarks section for the Uri class.
      /// @remarks When a Uri object is serialized, the OriginalString is ! preserved. The serialization process uses the fully escaped and canonicalized AbsoluteUri property when serializing. For a Uri that contains an IPv6 address, the IPv6 address and the scope ID are included in the serialized Uri object.
      property_<String, readonly_> LocalPath {
        get_ {return this->GetComponents(UriComponents::Path, UriFormat::Unescaped).Replace('/', System::IO::Path::DirectorySeparatorChar());}
      };

      /// @brief Gets the original URI string that was passed to the Uri constructor.
      /// @return string A string containing the exact URI specified when this instance was constructed; otherwise, Empty.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks If the URI specified to the constructor contained leading or trailing spaces, these spaces are preserved.
      /// @remarks The value returned by this property differs from ToString and AbsoluteUri. ToString returns the canonically unescaped form of the URI. AbsoluteUri returns the canonically escaped form of the URI.
      /// @remarks When International Resource Identifier (IRI) and Internationalized Domain Name (IDN) support are enabled, OriginalString returns the original non normalized string with Punycode host name if one was used to initialize the Uri instance. Punycode names contain only ASCII characters and always start with the xn-- prefix.
      /// @remarks For more information on IRI support, see the Remarks section for the Uri class.
      /// @remarks When a Uri object is serialized, the OriginalString is ! preserved. The serialization process uses the fully escaped and canonicalized AbsoluteUri property when serializing. For a Uri that contains an IPv6 address, the IPv6 address and the scope ID are included in the serialized Uri object.
      property_<const String&, readonly_> OriginalString {
        get_->const string& {
          if (this->kind != UriKind::Absolute)
            throw InvalidOperationException(caller_);

          return this->originalUri;
        }
      };

      /// @brief Gets the AbsolutePath and Query properties separated by a question mark (?).
      /// @return string A string that contains the AbsolutePath and Query properties separated by a question mark (?).
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The PathAndQuery property contains the absolute path on the server and the query information sent with the request. It is identical to concatenating the AbsolutePath and Query properties.
      /// @remarks The PathAndQuery property is escaped according to RFC 2396 by default. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the PathAndQuery property is escaped according to RFC 3986 and RFC 3987.
      /// @remarks For more information on IRI support, see the Remarks section for the Uri class.
      property_<String, readonly_> PathAndQuery {
        get_ {return this->GetComponents(UriComponents::PathAndQuery, UriFormat::UriEscaped);}
      };

      /// @brief Gets the port number of this URI.
      /// @return int32 An int32 value that contains the port number for this URI.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The port number defines the protocol port used for contacting the server referenced in the URI. If a port is ! specified as part of the URI, the Port property returns the default value for the protocol. If there is no default port number, this property returns -1.
      property_<int32, readonly_> Port {
        get_ {
          int32 port = -1;
          if (Int32::TryParse(this->GetComponents(UriComponents::Port, UriFormat::UriEscaped), port) == true)
            return port;

          if (Scheme() == Uri::UriSchemeFtp)
            return 21;
          if (Scheme() == Uri::UriSchemeGopher)
            return 70;
          if (Scheme() == Uri::UriSchemeHttp)
            return 80;
          if (Scheme() == Uri::UriSchemeHttps)
            return 443;
          if (Scheme() == "ldap")
            return 389;
          if (Scheme() == Uri::UriSchemeMailto)
            return 25;
          if (Scheme() == Uri::UriSchemeNntp)
            return 119;
          return -1;
        }
      };

      /// @brief Gets any query information included in the specified URI.
      /// @return string A string that contains any query information included in the specified URI.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The Query property contains any query information included in the URI. Query information is separated from the path information by a question mark (?) and continues to the end of the URI. The query information returned includes the leading question mark.
      /// @remarks The query information is escaped according to RFC 2396 by default. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the query information is escaped according to RFC 3986 and RFC 3987.
      /// @remarks For more information on IRI support, see the Remarks section for the Uri class.
      property_<String, readonly_> Query {
        get_ {return this->GetComponents(UriComponents((int32)UriComponents::Query | (int32)UriComponents::KeepDelimiter), UriFormat::UriEscaped);}
      };

      /// @brief Gets the scheme name for this URI.
      /// @return string A string that contains the scheme for this URI, converted to lowercase.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The Scheme property returns the scheme used to initialize the Uri instance. This property does ! indicate that the scheme used to initialize the Uri instance was recognized.
      /// @remarks The following table shows examples of some possible values returned by the Scheme property.
      /// | Scheme   | Description                                                                                    |
      /// |----------| -----------------------------------------------------------------------------------------------|
      /// | file     | The resource is a file on the local computer.                                                  |
      /// | ftp      | The resource is accessed through FTP.                                                          |
      /// | gopher   | The resource is accessed through the Gopher protocol.                                          |
      /// | http     | The resource is accessed through HTTP.                                                         |
      /// | https    | The resource is accessed through SSL-encrypted HTTP.                                           |
      /// | ldap     | The resource is accessed through the LDAP protocol.                                            |
      /// | mailto   | The resource is an e-mail address and accessed through the SMTP protocol.                      |
      /// | net.pipe | The resource is accessed through a named pipe.                                                 |
      /// | net.tcp  | The resource is accessed from TCP endpoint.                                                    |
      /// | news     | The resource is accessed through the NNTP protocol.                                            |
      /// | nntp     | The resource is accessed through the NNTP protocol.                                            |
      /// | telnet   | The resource is accessed through the TELNET protocol.                                          |
      /// | uuid     | The resource is accessed through a unique UUID endpoint name for communicating with a service. |
      property_<String, readonly_> Scheme {
        get_ {return GetComponents(UriComponents::Scheme, UriFormat::UriEscaped);}
      };

      /// @brief Gets an array containing the path segments that make up the specified URI.
      /// @return Array<Srtring> A string array that contains the path segments that make up the specified URI.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The Segments property returns an array of strings containing the "segments" (substrings) that form the URI's absolute path. The first segment is obtained by parsing the absolute path from its first character until you reach a slash (/) or the end of the path. Each additional segment begins at the first character after the preceding segment, and terminates with the next slash or the end of the path. (A URI's absolute path contains everything after the host and port and before the query and fragment.)
      /// @remarks The following example shows the absolute path and segments for two URIs. The second example illustrates that the fragment and query are ! part of the absolute path and therefore are ! segments.
      /// @remarks Absolute URI
      /// @remarks     http://www.contoso.com/Chapters/Chapter1/Sections/Section1.htm
      /// @remarks Absolute path
      /// @remarks     /Chapters/Chapter1/Sections/Section1.htm
      /// @remarks Segments
      /// @remarks     /Chapters/Chapter1/Sections/Section1.htm
      /// @remarks Absolute URI
      /// @remarks     http://www.contoso.com/Chapters/Chapter1/Sections/Section1.htm#page1?answer=NO
      /// @remarks Absolute path
      /// @remarks     /Chapters/Chapter1/Sections/Section1.htm
      /// @remarks Segments
      /// @remarks     /Chapters/Chapter1/Sections/Section1.htm
      /// @remarks Note that because the absolute path starts with a '/', the first segment contains it and nothing else.
      property_<Array<String>, readonly_> Segments {
        get_ {
          String absolutePath = this->AbsolutePath();
          if (string::IsNullOrEmpty(absolutePath) == true)
            return Array<String>();

          Array<String> segments;
          int32 startIndex = 0;
          int32 length = 1;

          if (absolutePath[startIndex] == '/') {
            Array<>::Resize(segments, segments.Length + 1);
            segments[segments.Length - 1] = absolutePath.Substring(startIndex, length);
            startIndex += length;
          }

          while (startIndex < absolutePath.Length()) {
            length = absolutePath.IndexOf('/', startIndex);
            if (length == -1)
              length = absolutePath.Length() - startIndex;

            Array<>::Resize(segments, segments.Length + 1);
            segments[segments.Length - 1] = absolutePath.Substring(startIndex, length);
            startIndex += length;
          }
          return segments;
        }
      };

      /// @brief Gets the user name, password, or other user-specific information associated with the specified URI.
      /// @return string A string that contains the user information associated with the URI. The returned value does ! include the '@' character reserved for delimiting the user information part of the URI.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks The value returned by this property is usually in the format "userName:password".
      property_<String, readonly_> UserInfo {
        get_ {return GetComponents(UriComponents::UserInfo, UriFormat::UriEscaped);}
      };

      /// @brief Determines whether the specified scheme name is valid.
      /// @param scheme The scheme name to validate.
      /// @return bool A bool value that is true if the scheme name is valid; otherwise, false.
      /// @remarks This method checks the scheme name for validity according to RFC 2396 by default. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, this method checks the scheme name for validity according to RFC 3986. The scheme name must begin with a letter and must contain only letters, digits, and the characters ".", "+", or "-".
      /// @remarks For more information on IRI support, see the Remarks section for the Uri class.
      static bool CheckSchemeName(const String& scheme) {
        bool first = true;
        for (char32 c : scheme) {
          if (first) {
            first = false;
            if (! Char::IsLetter(c))
              return false;
          } else {
            if (! Char::IsLetterOrDigit(c) && c != '.' && c != '+' && c != '-')
              return false;
          }
        }

        return ! first;
      }

      /// @brief Converts a string to its escaped representation.
      /// @param value The string to escape.
      /// @return string A string that contains the escaped representation of stringToEscape.
      /// @exception ArgumentNullException value is null.
      /// @exception UriFormatException The length of value exceeds 32766 characters.
      /// @remarks By default, the EscapeDataString method converts all characters except for RFC 2396 unreserved characters to their hexadecimal representation. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the EscapeDataString method converts all characters, except for RFC 3986 unreserved characters, to their hexadecimal representation. All Unicode characters are converted to UTF-8 format before being escaped.
      /// @remarks This method assumes that stringToEscape has no escape sequences in it.
      /// @remarks By default, the string is escaped according to RFC 2396. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the string is escaped according to RFC 3986 and RFC 3987. See these RFCs for a definition of reserved and unreserved characters.
      /// @remarks For more information on IRI support, see the Remarks section for the Uri class.
      static String EscapeDataString(const String& value) {
        if (value.Length() > 32766)
          throw UriFormatException(caller_);

        bool escapeNeeded = false;
        for (int32 index = 0; !escapeNeeded && index < value.Length(); index++)
          escapeNeeded = !IsHexEncoding(value, index) && NeedToEscapeDataChar(value[index]);

        if (escapeNeeded) {
          String retValue;
          for (int32 index = 0; index < value.Length(); index++) {
            if (!IsHexEncoding(value, index) && NeedToEscapeDataChar(value[index]))
              retValue += HexEscape(value[index]);
            else
              retValue += Char(value[index]).ToString();
          }
          return retValue;
        }

        return value;
      }

      /// @brief Converts a URI string to its escaped representation.
      /// @param value The string to escape.
      /// @return string A string that contains the escaped representation of stringToEscape.
      /// @exception ArgumentNullException value is null.
      /// @exception UriFormatException The length of value exceeds 32766 characters.
      /// @remarks Use the EscapeUriString method to prepare an unescaped URI string to be a parameter to the Uri constructor.
      /// @remarks By default, the EscapeUriString method converts all characters, except RFC 2396 unreserved characters, to their hexadecimal representation. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the EscapeUriString method converts all characters, except for RFC 3986 unreserved characters, to their hexadecimal representation. All Unicode characters are converted to UTF-8 format before being escaped.
      /// @remarks This method assumes that stringToEscape has no escape sequences in it.
      /// @remarks By default, the string is escaped according to RFC 2396. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the string is escaped according to RFC 3986 and RFC 3987. See these RFCs for a definition of reserved and unreserved characters.
      /// @remarks For more information on IRI support, see the Remarks section for the Uri class.
      static String EscapeUriString(const String& value) {
        if (value.Length() > 32766)
          throw UriFormatException(caller_);

        bool escapeNeeded = false;
        for (int32 index = 0; !escapeNeeded && index < value.Length(); index++)
          escapeNeeded = !IsHexEncoding(value, index) && NeedToEscapeUriChar(value[index]);

        if (escapeNeeded) {
          String retValue;
          for (int32 index = 0; index < value.Length(); index++) {
            if (!IsHexEncoding(value, index) && NeedToEscapeUriChar(value[index]))
              retValue += HexEscape(value[index]);
            else
              retValue += Char(value[index]).ToString();
          }
          return retValue;
        }

        return value;
      }

      /// @brief Gets the decimal value of a hexadecimal digit.
      /// @param digit The hexadecimal digit (0-9, a-f, A-F) to convert.
      /// @return int32 An int32 value that contains a number from 0 to 15 that corresponds to the specified hexadecimal digit.
      /// @exception ArgumentException digit is ! a valid hexadecimal digit (0-9, a-f, A-F).
      /// @remarks The FromHex method converts a character representing a hexadecimal digit (0-9, a-f, A-F) to its decimal value (0 to 15). If digit is ! a valid hexadecimal digit, an ArgumentException exception is thrown.
      static int32 FromHex(char32 digit) {
        if ('0' <= digit && digit <= '9')
          return digit - '0';

        if ('a' <= digit && digit <= 'f')
          return 10 + digit - 'a';

        if ('A' <= digit && digit <= 'F')
          return 10 + digit - 'A';

        throw ArgumentException(caller_);
      }

      /// @brief Gets the specified components of the current instance using the specified escaping for special characters.
      /// @param components A bitwise combination of the UriComponents values that specifies which parts of the current instance to return to the caller.
      /// @param format One of the UriFormat values that controls how special characters are escaped.
      /// @return string A string that contains the components.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @remarks When Query or Fragment is specified alone, the return value includes the delimiter. The Scheme, UserInfo, Host, Port, and Path components do ! include the delimiter. For all other UriComponents values, and combinations of values, the delimiters are included in the returned value.
      /// @remarks The components are returned in the order that they appear in the URI. For example, if Scheme is specified, it appears first.
      /// @remarks When International Resource Identifier (IRI) and Internationalized Domain Name (IDN) support are enabled, the number of characters returned in the string increases. Punycode names used to support IRI contain only ASCII characters and always start with the xn-- prefix. When IRI and IDN are enabled, Unicode surrogate characters are handled correctly by the GetComponents method.
      /// @remarks For more information on IRI support, see the Remarks section for the Uri class.
      String GetComponents(UriComponents components, UriFormat format) const {
        if (this->kind != UriKind::Absolute)
          throw InvalidOperationException(caller_);

        String str;

        if (Enum<UriComponents>(components).HasFlag(UriComponents::Scheme))
          str += this->scheme;
        if (Enum<UriComponents>(components).HasFlag(UriComponents::Scheme) && (components & ~UriComponents::Scheme) != UriComponents::None)
          str += this->schemeDelimiter;
        if (Enum<UriComponents>(components).HasFlag(UriComponents::UserInfo))
          str += this->userInfo;
        if (Enum<UriComponents>(components).HasFlag(UriComponents::UserInfo) && this->userInfo.Length() && (components & ~UriComponents::UserInfo) != UriComponents::None)
          str += "@";
        if (Enum<UriComponents>(components).HasFlag(UriComponents::Host))
          str += this->host;
        if (Enum<UriComponents>(components).HasFlag(UriComponents::Port) && this->port.Length() && (components & ~UriComponents::Port) != UriComponents::None)
          str += ":";
        if (Enum<UriComponents>(components).HasFlag(UriComponents::Port))
          str += this->port;
        if (Enum<UriComponents>(components).HasFlag(UriComponents::Path))
          str += this->path;
        if (Enum<UriComponents>(components).HasFlag(UriComponents::Query) && this->query.Length() && (components & ~UriComponents::Query) != UriComponents::None)
          str += "?";
        if (Enum<UriComponents>(components).HasFlag(UriComponents::Query))
          str += this->query;
        if (Enum<UriComponents>(components).HasFlag(UriComponents::Fragment) && this->fragment.Length() && (components & ~UriComponents::Fragment) != UriComponents::None)
          str += "#";
        if (Enum<UriComponents>(components).HasFlag(UriComponents::Fragment))
          str += this->fragment;
        if (Enum<UriComponents>(components).HasFlag(UriComponents::StrongPort) && (components & ~UriComponents::StrongPort) != UriComponents::None)
          str += ":";
        if (Enum<UriComponents>(components).HasFlag(UriComponents::StrongPort))
          str += String::Format("{0}", Port());

        if (format == UriFormat::SafeUnescaped)
          str = UnescapeDataString(str);
        else if (format == UriFormat::Unescaped)
          str = UnescapeDataString(str);
        else
          str = EscapeUriString(str);

        return str;
      }

      /// @brief Gets the specified portion of a Uri instance.
      /// @param part = One of the UriPartial values that specifies the end of the URI portion to return.
      /// @return string A string that contains the specified portion of the Uri instance.
      /// @exception InvalidOperationException This instance represents a relative URI, and this property is valid only for absolute URIs.
      /// @exception ArgumentException The specified part is ! valid.
      /// @remarks The GetLeftPart method returns a string containing the leftmost portion of the URI string, ending with the portion specified by part.
      /// @remarks GetLeftPart includes delimiters in the following cases:
      /// @remarks   * Scheme includes the scheme delimiter.
      /// @remarks   * Authority does ! include the path delimiter.
      /// @remarks   * Path includes any delimiters in the original URI up to the query or fragment delimiter.
      /// @remarks   * Query includes the Path, plus the query and its delimiter.
      /// @remarks The following examples show a URI and the results of calling GetLeftPart with Scheme, Authority, Path, or Query.
      /// | URI                                         | Scheme  | Autority                | Path                                       | Query                                       |
      /// |---------------------------------------------|---------|-------------------------|--------------------------------------------|---------------------------------------------|
      /// | http://www.contoso.com/index.htm?date=today | http:// | http://www.contoso.com  | http://www.contoso.com/index.htm           | http://www.contoso.com/index.htm?date=today |
      /// | http://www.contoso.com/index.htm#main       | http:// | http://www.contoso.com  | http://www.contoso.com/index.htm           | http://www.contoso.com/index.htm            |
      /// | mailto:user@contoso.com?subject=uri         | mailto: | mailto:user@contoso.com | mailto:user@contoso.com?subject=uri        | <None>                                      |
      /// | nntp://news.contoso.com/123456@contoso.com  | nntp:// | nntp://news.contoso.com | nntp://news.contoso.com/123456@contoso.com | nntp://news.contoso.com/123456@contoso.com  |
      /// | news:123456@contoso.com                     | news:   | news:123456@contoso.com | news:123456@contoso.com                    | <None>                                      |
      /// | file://server/filename.ext                  | file:// | file://server           | file://server/filename.ext                 | file://server/filename.ext                  |
      String GetLeftPart(UriPartial part) const {
        switch (part) {
        case UriPartial::Scheme: return GetComponents(UriComponents((int32)UriComponents::Scheme | (int32)UriComponents::KeepDelimiter), UriFormat::UriEscaped);
        case UriPartial::Authority: return GetComponents(UriComponents((int32)UriComponents::Scheme | (int32)UriComponents::UserInfo | (int32)UriComponents::Host | (int32)UriComponents::Port), UriFormat::UriEscaped);
        case UriPartial::Path: return GetComponents(UriComponents((int32)UriComponents::Scheme | (int32)UriComponents::UserInfo | (int32)UriComponents::Host | (int32)UriComponents::Port | (int32)UriComponents::Path), UriFormat::UriEscaped);
        case UriPartial::Query: return GetComponents(UriComponents((int32)UriComponents::Scheme | (int32)UriComponents::UserInfo | (int32)UriComponents::Host | (int32)UriComponents::Port | (int32)UriComponents::PathAndQuery), UriFormat::UriEscaped);
        default: break;
        }
        throw ArgumentException(caller_);
      }

      /// @brief Returns the data needed to serialize the current instance.
      /// @param info The SerializationInfo to populate with data.
      /// @remarks Any objects that are included in the SerializationInfo are automatically tracked and serialized by the formatter.
      /// @remarks Code that calls GetObjectData requires the SecurityPermission for providing serialization services. Associated enumeration: SecurityPermissionFlag.SerializationFormatter.
      /// @note It is ! guaranteed that this method will be called only once per object instance during serialization. Therefore, the method should be implemented in such a way that its behavior will be the same regardless of the number of times it is called.
      void GetObjectData(System::Runtime::Serialization::SerializationInfo& info) const override {
        info.AddValue(Enum<UriComponents>(UriComponents::Scheme).ToString(), this->scheme);
        info.AddValue("SchemeDelimiter", this->schemeDelimiter);
        info.AddValue(Enum<UriComponents>(UriComponents::UserInfo).ToString(), this->userInfo);
        info.AddValue(Enum<UriComponents>(UriComponents::Host).ToString(), this->host);
        info.AddValue(Enum<UriComponents>(UriComponents::Port).ToString(), this->port);
        info.AddValue(Enum<UriComponents>(UriComponents::Path).ToString(), this->path);
        info.AddValue(Enum<UriComponents>(UriComponents::Query).ToString(), this->query);
        info.AddValue(Enum<UriComponents>(UriComponents::Fragment).ToString(), this->fragment);
        info.AddValue("UriKind", (int32)this->kind);
      }

      /// @brief Converts a specified character into its hexadecimal equivalent.
      /// @param character The character to convert to hexadecimal representation.
      /// @return string The hexadecimal representation of the specified character.
      /// @exception ArgumentOutOfRangeException character is greater than 255.
      static String HexEscape(char32 character) {
        if (character > 255)
          throw ArgumentOutOfRangeException(caller_);

        return String::Format("%{0:X2}", Convert::ToInt32(character));
      }

      /// @brief Converts a specified hexadecimal representation of a character to the character.
      /// @param pattern The hexadecimal representation of a character.
      /// @param index The location in pattern where the hexadecimal representation of a character begins.
      /// @return Char The character represented by the hexadecimal encoding at position index. If the character at index is ! hexadecimal encoded, the character at index is returned. The value of index is incremented to point to the character following the one returned.
      /// @exception ArgumentOutOfRangeException index is less than 0 or greater than or equal to the number of characters in pattern.
      static char32 HexUnescape(const String& pattern, int32& index) {
        index += 3;
        return Int32::Parse(pattern.Substring(index - 2, 2), 16);
      }

      /// @brief Determines whether the current Uri instance is a base of the specified Uri instance.
      /// @param uri The specified Uri instance to test.
      /// @return bool true if the current Uri instance is a base of uri; otherwise, false.
      /// @exception ArgumentNullException uri is null.
      /// @remarks IsBaseOf is used to compare the current Uri instance to a specified Uri to determine whether this URI is a base for the specified Uri. When comparing two Uri objects to determine a base relationship, the user information (UserInfo) is ! evaluated. When comparing two URIs (uri1 and uri2), uri1 is the base of uri2 if, when you ignore everything in uri2 after the last slash (/), the two URIs are identical. Using http://host/path/path/file?query as the base URI, the following table shows whether it is a base for other URIs.
      /// | URI                                   | http://host/path/path/file?query is base of |
      /// |---------------------------------------|---------------------------------------------|
      /// | http://host/path/path/file/           | yes                                         |
      /// | http://host/path/path/#fragment       | yes                                         |
      /// | http://host/path/path/MoreDir/"       | yes                                         |
      /// | http://host/path/path/OtherFile?Query | yes                                         |
      /// | http://host/path/path/                | yes                                         |
      /// | http://host/path/path/file            | yes                                         |
      /// | http://host/path/path                 | no                                          |
      /// | http://host/path/path?query           | no                                          |
      /// | http://host/path/path#Fragment        | no                                          |
      /// | http://host/path/path2/               | no                                          |
      /// | http://host/path/path2/MoreDir        | no                                          |
      /// | http://host/path/File                 | no                                          |
      bool IsBasOf(const Uri& uri) const {
        String path = (this->path.Remove(this->path.Length() - 1).LastIndexOf('/') == -1 ? this->path : this->path.Remove(this->path.Remove(this->path.Length() - 1).LastIndexOf('/')));
        String uripath = (uri.path.Remove(uri.path.Length() - 1).LastIndexOf('/') == -1 ? uri.path : uri.path.Remove(uri.path.Remove(uri.path.Length() - 1).LastIndexOf('/')));

        return this->scheme == uri.scheme && this->schemeDelimiter == uri.schemeDelimiter && this->host == uri.host && this->port == uri.port && path == uripath;
      }

      /// @brief  Determines whether a specified character is a valid hexadecimal digit.
      /// @param character The character to validate.
      /// @return bool A bool value that is true if the character is a valid hexadecimal digit; otherwise false.
      /// @remarks Hexadecimal digits are the digits 0 to 9 and the letters A-F or a-f.
      static bool IsHexDigit(char32 character) {return (character >= '0' && character <= '9') || (character >= 'A' && character <= 'F') || (character >= 'a' && character <= 'f');}

      /// @brief Determines whether a character in a string is hexadecimal encoded.
      /// @param pattern The string to check.
      /// @param index The location in pattern to check for hexadecimal encoding.
      /// @return bool A bool value that is true if pattern is hexadecimal encoded at the specified location; otherwise, false.
      /// @remarks The IsHexEncoding method checks for hexadecimal encoding that follows the pattern "%hexhex" in a string, where "hex" is a digit from 0 to 9 or a letter from A-F (case-insensitive).
      static bool IsHexEncoding(const String& pattern, int32 index) {
        if (index < 0 || pattern.Length() < index + 3)
          return false;

        System::Collections::Generic::Enumerator<char32> enumerator = pattern.GetEnumerator();
        enumerator.MoveNext();
        while (index--) enumerator.MoveNext();
        if (enumerator.Current() != '%') return false;
        enumerator.MoveNext();
        if (! IsHexDigit(enumerator.Current)) return false;
        enumerator.MoveNext();
        if (! IsHexDigit(enumerator.Current)) return false;

        return true;
      }

      /// @brief Indicates whether the string used to construct this Uri was well-formed and is ! required to be further escaped.
      /// @return bool A bool value that is true if the string was well-formed; else false.
      /// @remarks The string is considered to be well-formed in accordance with RFC 2396 and RFC 2732 by default. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the string is considered to be well-formed in accordance with RFC 3986 and RFC 3987
      /// @remarks The string is considered poorly formed, causing the method to return false, if any of the following conditions occur.
      /// | Error                                                                                  | Example                                       |
      /// |----------------------------------------------------------------------------------------|-----------------------------------------------|
      /// | The string is ! correctly escaped.                                                     | http://www.contoso.com/path???/file name      |
      /// | The string is an absolute Uri that represents an implicit file Uri.                    | c:\\directory\filename                        |
      /// | The string is an absolute URI that is missing a slash before the path.                 | file://c:/directory/filename                  |
      /// | The string contains unescaped backslashes even if they are treated as forward slashes. | http:\\host/path/file                         |
      /// | The string represents a hierarchical absolute Uri and does ! contain "://".            | www.contoso.com/path/file                     |
      /// | The parser for the Uri.Scheme indicates that the original string was ! well-formed.    | The example depends on the scheme of the URI. |
      /// @remarks By default, the string used to construct this Uri are considered well-formed in accordance with RFC 2396 and RFC 2732.
      /// @remarks When International Resource Identifier (IRI) and Internationalized Domain Name (IDN) support are enabled, the string used to construct this Uri are considered well-formed in accordance with RFC 3986 and RFC 3987. Punycode names used to support IRI contain only ASCII characters and always start with the xn-- prefix.
      /// @remarks For more information on IRI support, see the Remarks section for the Uri class.
      bool IsWellFormedOriginalString() {
        bool wellFormatedOriginalString = true;

        for (int32 index = 0; !wellFormatedOriginalString && index < this->originalUri.Length(); index++)
          wellFormatedOriginalString = !(IsHexEncoding(this->originalUri, index) || NeedToEscapeUriChar(this->originalUri[index]));

        if (wellFormatedOriginalString == true)
          wellFormatedOriginalString = IO::Path::IsPathRooted(this->originalUri);

        if (wellFormatedOriginalString == true)
          wellFormatedOriginalString = this->originalUri.IndexOf('\\') != -1;

        if (wellFormatedOriginalString == true)
          wellFormatedOriginalString = !(this->schemeDelimiter.Length() == 0 && this->host.Length() != 0);

        if (wellFormatedOriginalString == true)
          wellFormatedOriginalString = CheckSchemeName(this->scheme);

        return wellFormatedOriginalString;
      }

      /// @brief Indicates whether the string is well-formed by attempting to construct a URI with the string and ensures that the string does ! require further escaping.
      /// @param uriString The string used to attempt to construct a Uri.
      /// @param uriKind The type of the Uri in uriString.
      /// @return bool A bool value that is true if the string was well-formed; else false.
      /// @remarks By default, the string is considered well-formed in accordance with RFC 2396 and RFC 2732. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the string is considered well-formed in accordance with RFC 3986 and RFC 3987.
      /// @remarks The string is considered poorly formed, causing the method to return false, if any of the following conditions occur
      /// | Error                                                                                  | Example                                       |
      /// |----------------------------------------------------------------------------------------|-----------------------------------------------|
      /// | The string is ! correctly escaped.                                                     | http://www.contoso.com/path???/file name      |
      /// | The string is an absolute Uri that represents an implicit file Uri.                    | c:\\directory\filename                        |
      /// | The string is an absolute URI that is missing a slash before the path.                 | file://c:/directory/filename                  |
      /// | The string contains unescaped backslashes even if they are treated as forward slashes. | http:\\host/path/file                         |
      /// | The string represents a hierarchical absolute Uri and does ! contain "://".            | www.contoso.com/path/file                     |
      /// | The parser for the Uri.Scheme indicates that the original string was ! well-formed.    | The example depends on the scheme of the URI. |
      /// @remarks For more information on IRI support, see the Remarks section for the Uri class.
      static bool IsWellFormedUriString(const String& uriString, UriKind uriKind) {
        bool wellFormedUriString = true;

        try {
          Uri uri(uriString, uriKind);
          wellFormedUriString = uri.IsWellFormedOriginalString();
        } catch (...) {
          wellFormedUriString = false;
        }

        return wellFormedUriString;
      }

      /// @brief Converts a string to its unescaped representation.
      /// @param value The string to unescape.
      /// @return string A string that contains the unescaped representation of stringToUnescape.
      /// @exception ArgumentNullException value is null.
      /// @remarks You should use this method with care. Unescaping a string that has been previously unescaped can lead to ambiguities and errors.
      /// @remarks Many Web browsers escape spaces inside of URIs into plus ("+") characters; however, the UnescapeDataString method does ! convert plus characters into spaces because this behavior is ! standard across all URI schemes.
      static String UnescapeDataString(const String& value) {
        // See http://www.geekhideout.com/urlcode.shtml
        bool unescapeNeeded = false;
        for (int32 index = 0; !unescapeNeeded && index < value.Length(); index++)
          unescapeNeeded = IsHexEncoding(value, index);

        if (!unescapeNeeded)
          return value;

        String retValue;
        int32 index = 0;
        while (index < value.Length()) {
          if (IsHexEncoding(value, index))
            retValue += String::Format("{0}", Char(HexUnescape(value, index)));
          else
            retValue += Char(value[index++]).ToString();
        }
        return retValue;
      }

      bool Equals(const Uri& uri) const {
        return this->scheme == uri.scheme && this->schemeDelimiter == uri.schemeDelimiter && this->host == uri.host && this->port == uri.port && this->path == uri.path && this->query == uri.query && this->kind == uri.kind;
      }

      bool Equals(const Object& obj) const override {
        return is<Uri>(obj) && Equals((const Uri&)obj);
      }

      /// @brief Gets a canonical string representation for the specified Uri instance.
      /// @return string A string instance that contains the unescaped canonical representation of the Uri instance. All characters are unescaped except #, ?, and %.
      /// @remarks The string returned by this method does ! contain port information when the port is the default port for the scheme.
      String ToString() const override { return GetComponents(UriComponents::AbsoluteUri, UriFormat::Unescaped); }

    private :
      void SetScheme(String& escapeUri) {
        int32 indexStart = escapeUri.IndexOf(SchemeDelimiter);
        if (indexStart != -1)
          this->schemeDelimiter = SchemeDelimiter;
        else {
          indexStart = escapeUri.IndexOf(':');
          if (indexStart != -1)
            this->schemeDelimiter = ":";
        }

        if (indexStart != -1) {
          this->scheme = escapeUri.Remove(indexStart).ToLower();
          escapeUri = escapeUri.Substring(indexStart + this->schemeDelimiter.Length());
        }
      }

      void SetUserInfo(String& escapeUri) {
        static Array<char32> endHostChars = {char32('/'), char32('?'), char32('#')};
        int32 indexStart = escapeUri.IndexOf('@');
        if (indexStart != -1 && indexStart < escapeUri.IndexOfAny(endHostChars)) {
          this->userInfo = escapeUri.Remove(indexStart);
          if (indexStart < escapeUri.Length())
            indexStart++;
          escapeUri = escapeUri.Substring(indexStart);
        }
      }

      void SetHost(String& escapeUri) {
        static Array<char32> endHostChars = {char32(':'), char32('/'), char32('?'), char32('#')};
        int32 indexStart = escapeUri.IndexOfAny(endHostChars);
        if (indexStart == -1)
          indexStart = escapeUri.Length();
        if (indexStart != -1) {
          this->host = escapeUri.Remove(indexStart).ToLower();
          escapeUri = escapeUri.Substring(indexStart);
        }
      }

      void SetPort(String& escapeUri) {
        try {
          int32 indexStart = escapeUri.IndexOf(':');
          if (indexStart == -1)
            return;

          escapeUri = escapeUri.Substring(1);
          indexStart = escapeUri.IndexOf('/');
          if (indexStart == -1)
            indexStart = escapeUri.Length();

          if (indexStart == -1)
            return;

          this->port = escapeUri.Remove(indexStart);
          Int32::Parse(this->port);

          escapeUri = escapeUri.Substring(indexStart);
        } catch (...) {
          throw UriFormatException(caller_);
        }
      }

      void SetPath(String& escapeUri) {
        static Array<char32> endPathChars = {char32('?'), char32('#')};
        int32 indexStart = escapeUri.IndexOfAny(endPathChars);
        if (indexStart != -1) {
          this->path = escapeUri.Remove(indexStart);
          escapeUri = escapeUri.Substring(indexStart);
          return;
        }

        this->path = string::IsNullOrEmpty(escapeUri) ? "/" : escapeUri;
        escapeUri = string::Empty;
      }

      void SetFragment(String& escapeUri) {
        int32 indexStart = escapeUri.IndexOf('#') + 1;
        if (indexStart == 0)
          indexStart = escapeUri.Length();
        if (indexStart == -1)
          return;

        this->fragment = escapeUri.Substring(indexStart, escapeUri.Length() - indexStart);
        if (indexStart != escapeUri.Length())
          escapeUri = escapeUri.Remove(indexStart - 1, escapeUri.Length() - indexStart + 1);
      }

      void SetQuery(String& escapeUri) {
        int32 indexStart = escapeUri.IndexOf('?') + 1;
        if (indexStart == 0)
          indexStart = escapeUri.Length();
        if (indexStart == -1)
          return;

        this->query = escapeUri.Substring(indexStart, escapeUri.Length() - indexStart);
        if (indexStart != escapeUri.Length())
          escapeUri = escapeUri.Remove(indexStart - 1, escapeUri.Length() - indexStart + 1);
      }

      static bool NeedToEscapeDataChar(char32 character) {
        static String notEscapedChars = "!-_.~";

        return !(Char::IsLetterOrDigit(character) || notEscapedChars.IndexOf(character) != -1);
      }

      static bool NeedToEscapeUriChar(char32 character) {
        static String notEscapedChars = "!@#=?/:-_.~";

        return !(Char::IsLetterOrDigit(character) || notEscapedChars.IndexOf(character) != -1);
      }

      String originalUri;
      String scheme;
      String schemeDelimiter;
      String userInfo;
      String host;
      String port;
      String path;
      String query;
      String fragment;
      UriKind kind = UriKind::Absolute;
    };
  }
}

using namespace Switch;

