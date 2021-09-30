/// @file
/// @brief Contains Switch::System::Net::FtpWebRequest class.
#pragma once

#include <Switch/System/TimeoutException.hpp>
#include "../../SystemExport.hpp"
#include "WebRequest.hpp"
#include "FtpWebResponse.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief Implements a File Transfer Protocol (FTP) client.
      /// @par Library
      /// Switch.System
      class system_export_ FtpWebRequest: public System::Net::WebRequest {
      public:
        property_<bool> UseBinary {
          get_ {return this->GetUseBinary();},
          set_ {this->SetUseBinary(value);}
        };

        WebResponse& GetResponse() override;

        WebRequest::WebRequestStream GetRequestStream() override;

      protected:
        FtpWebRequest(const string& uri);
        FtpWebRequest(const System::Uri& uri);
        FtpWebRequest(const FtpWebRequest& ftpWebRequest) = delete;
        FtpWebRequest operator =(const FtpWebRequest& ftpWebRequest) = delete;

        WebResponse& GetInternalResponse() override;
        void Finished(int32 error) override;

        System::Net::FtpWebResponse ftpWebResponse;

      private:
        friend class System::Net::WebRequest;
        friend class System::Net::FtpWebResponse;

        bool GetUseBinary();
        void SetUseBinary(bool useBinary);

        bool useBinary = false;

        void ProcessMakeDirectory();
        void ProcessListDirectory();
        void ProcessListDirectoryDetails();
      };
    }
  }
}

using namespace Switch;
