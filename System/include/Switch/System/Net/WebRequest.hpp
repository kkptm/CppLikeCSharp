/// @file
/// @brief Contains Switch::System::Net::WebRequest class.
#pragma once

#include <Switch/Abstract.hpp>
#include <Switch/Types.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/IO/Stream.hpp>
#include <Switch/System/Threading/AutoResetEvent.hpp>
#include <Switch/System/Threading/ManualResetEvent.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <Switch/System/Threading/Timeout.hpp>
#include "NetworkCredential.hpp"
#include "../../SystemExport.hpp"
#include "../Uri.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @cond
      class WebResponse;
      /// @end cond

      ///@brief Makes a request to a Uniform Resource Identifier (URI). This is an abstract class.
      /// @par Library
      /// Switch.System
      class system_export_ WebRequest abstract_ {
        /// @cond
        friend class System::Net::WebResponse;
        /// @endcond
      public:
        class WebRequestStream: public System::IO::Stream {
        public:
          WebRequestStream() {}
          WebRequestStream(WebRequest* webRequest) {this->data->webRequest = webRequest;}
          WebRequestStream(const WebRequestStream& wrs) {}

          void Write(const void* handle, int32 count);
          void Write(const Array<byte>& buffzer, int32 offset, int32 count) override;
          int32 Read(Array<byte>& buffer, int32 offset, int32 count) override { return 0; }
          int64 Seek(int64, System::IO::SeekOrigin) override;
          int32 Send(void* handle, int32 count);
          void Close() override;

        protected:
          friend class WebRequest;
          bool GetCanRead() const override {return false;}
          bool GetCanSeek()  const override {return false;}
          bool GetCanTimeout() const override {return true;}
          bool GetCanWrite() const override {return true;}
          int64 GetLength() const override {return 0;}
          int64 GetPosition() const override {return 0;}

        private:
          struct WebRequestStreamData {
            bool started = false;
            void* buffer = null;
            System::Net::WebRequest* webRequest = null;
            System::Threading::ManualResetEvent writeEvent {false};
            System::Threading::AutoResetEvent readEvent {false};
            int32 bufferSize = 0;
            int32 bufferOffset = 0;
          };
          refptr<WebRequestStreamData> data = ref_new<WebRequestStreamData>();
        };


        /// @brief Initializes a new WebRequest instance for the specified URI scheme.
        /// @param requestUriString The URI that identifies the Internet resource.
        /// @return WebRequest A WebRequest descendant for the specified URI scheme.
        /// @remarks The Create method returns a descendant of the WebRequest class determined at run time as the closest registered match for requestUri.
        /// @remarks For example, if you create a WebRequest descendant, Handler1, to handle requests to http://www.contoso.com/text/ and another named Handler2 to handle requests to http://www.contoso.com/code/, you can use Create method to return the WebRequest descendant associated with either specified URI.
        /// @remarks To return a descendant of the WebRequest class based on only the scheme portion of a URI, use the CreateDefault method.
        /// @remarks For example, when a URI beginning with http:// or https:// is passed in requestUri, an HttwebRequest is returned by Create. If a URI beginning with ftp:// is passed instead, the Create method will return a FileWebRequest instance. If a URI beginning with file:// is passed instead, the Create method will return a FileWebRequest instance.
        /// @remarks The pre-registered reserve types already registered include the following:
        /// @remarks http://
        /// @remarks ftp://
        /// @remarks The Switch includes support for the http://, ftp:// URI schemes.
        /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
        static refptr<WebRequest> Create(const String& requestUriString) { return Create(Uri(requestUriString)); }

        /// @brief Initializes a new WebRequest instance for the specified URI scheme.
        /// @param requestUriString A Uri containing the URI of the requested resource.
        /// @return WebRequest A WebRequest descendant for the specified URI scheme.
        /// @remarks The Create method returns a descendant of the WebRequest class determined at run time as the closest registered match for requestUri.
        /// @remarks For example, if you create a WebRequest descendant, Handler1, to handle requests to http://www.contoso.com/text/ and another named Handler2 to handle requests to http://www.contoso.com/code/, you can use Create method to return the WebRequest descendant associated with either specified URI.
        /// @remarks To return a descendant of the WebRequest class based on only the scheme portion of a URI, use the CreateDefault method.
        /// @remarks For example, when a URI beginning with http:// or https:// is passed in requestUri, an HttwebRequest is returned by Create. If a URI beginning with ftp:// is passed instead, the Create method will return a FileWebRequest instance. If a URI beginning with file:// is passed instead, the Create method will return a FileWebRequest instance.
        /// @remarks The pre-registered reserve types already registered include the following:
        /// @remarks http://
        /// @remarks ftp://
        /// @remarks The Switch includes support for the http://, ftp:// URI schemes.
        /// @note This member outputs trace information when you enable network tracing in your application. For more information, see Network Tracing.
        static refptr<WebRequest> Create(const Uri& requestUriString);

        property_<int64> ContentLength {
          get_ {return this->GetContentLength();},
          set_ {this->SetContentLength(value);}
        };

        property_<string> Method {
          get_ {return this->GetMethod();},
          set_ {this->SetMethod(value);}
        };

        property_<const System::Net::NetworkCredential&> Credentials {
          get_->System::Net::NetworkCredential& {return this->GetCredential();},
          set_ {this->SetCredential(value);}
        };

        property_<System::Uri, readonly_> RequestUri {
          get_ {return this->GetRequestUri();}
        };

        property_<int32> Timeout {
          get_ {return this->timeout;},
          set_ {this->timeout = value;}
        };

        virtual WebResponse& GetResponse() = 0;
        virtual WebRequestStream GetRequestStream();

        virtual ~WebRequest();

      protected:
        virtual int64 GetContentLength() const { return this->contentLength; }
        virtual void SetContentLength(int64 contentLength) { this->contentLength = contentLength; }
        virtual System::Net::NetworkCredential& GetCredential();
        virtual void SetCredential(const System::Net::NetworkCredential& credential);
        virtual String GetMethod() const { return this->method; }
        virtual void SetMethod(const String& method) { this->method = method;}
        virtual System::Uri GetRequestUri() const { return uri;}
        intptr GetRequestHandle() {return this->requestHandle;}

        bool IsResponseStreamNeeded() const;
        bool IsRequestStreamNeeded() const;

        virtual WebResponse& GetInternalResponse() = 0;

        /// @brief Initializes a new instance of the WebRequest class.
        /// @param uri : A Uri containing the URI of the requested resource.
        /// @remarks Use the Create method to initialize new WebRequest instances. Do not use the constructor.
        WebRequest(const String& uri);
        WebRequest(const System::Uri& uri);
        WebRequest(const WebRequest& webRequest) = delete;
        WebRequest& operator =(const WebRequest& webRequest) = delete;

        static int32 pendingRequest;
        intptr requestHandle = IntPtr::Zero;
        string method;
        NetworkCredential credential;
        int64 contentLength = 0;
        int32 timeout = 300000;
        System::Uri uri;
        System::Net::WebRequest::WebRequestStream  requestStream {this};
        int32 internalError = 0;

        void ProccessRequest();
        virtual void Finished(int32 error);
        static size_t ReadStream(void* buffer, size_t size, size_t nmemb, void* stream);

      private:
        void ProccessRequestThread();
        System::Threading::Thread requestThread {System::Threading::ThreadStart(*this, &WebRequest::ProccessRequestThread)};

        void InitWebRequest();
      };
    }
  }
}

using namespace Switch;
