/// @file
/// @brief Contains Switch::System::Net::FtpWebResponse class.
#pragma once

#include "../../SystemExport.hpp"
#include "FtpStatusCode.hpp"
#include "WebResponse.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Encapsulates a File Transfer Protocol (FTP) server's response to a request.
      /// @par Library
      /// Switch.System
      class system_export_ FtpWebResponse : public System::Net::WebResponse {
      public:
        property_<System::Net::FtpStatusCode, readonly_> StatusCode {
          get_ {return this->GetStatusCode();}
        };

        property_<string, readonly_> StatusDescription {
          get_ {return this->GetStatusDescription();}
        };

        WebResponse::WebResponseStream GetResponseStream() override;

      protected:
        FtpWebResponse();

      private:
        friend class FtpWebRequest;

        System::Net::FtpStatusCode GetStatusCode() const;
        const String GetStatusDescription() const;
      };
    }
  }
}

using namespace Switch;
