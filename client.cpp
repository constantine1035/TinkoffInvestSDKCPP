#include "client.h"

#include "services/reply.h"
#include "services/users.h"
//#include "instruments.h"  TBD
//#include "operations.h"  TBD
#include "services/orders.h"
//#include "ordersstream.h"  TBD
#include "services/stoporders.h"
//#include "sandbox.h"   TBD
//#include "marketdata.h"  TBD
//#include "marketdatastream.h"  TBD

#include <grpcpp/security/credentials.h>
#include <grpcpp/security/server_credentials.h>
#include <Security/Security.h>
#include <openssl/bio.h>
#include <openssl/pem.h>

//Mac fix not working?
//std::string utf8Encode(const std::wstring& wstr)
//{
//    if (wstr.empty())
//        return std::string();
//
//    CFStringRef cfString = CFStringCreateWithCharacters(NULL, reinterpret_cast<const UniChar*>(wstr.c_str()), wstr.size());
//    CFDataRef utf8Data = CFStringCreateExternalRepresentation(NULL, cfString, kCFStringEncodingUTF8, 0);
//    CFRelease(cfString);
//
//    std::string strTo(reinterpret_cast<const char*>(CFDataGetBytePtr(utf8Data)), CFDataGetLength(utf8Data));
//    CFRelease(utf8Data);
//
//    return strTo;
//}
//
//grpc::SslCredentialsOptions getSslOptions()
//{
//    grpc::SslCredentialsOptions result;
//
//    // Load root certificates.
//    CFArrayRef rootCerts;
//    OSStatus status = SecTrustCopyAnchorCertificates(&rootCerts);
//    if (status != errSecSuccess)
//        return result;
//
//    for (CFIndex i = 0; i < CFArrayGetCount(rootCerts); ++i)
//    {
//        SecCertificateRef cert = (SecCertificateRef)CFArrayGetValueAtIndex(rootCerts, i);
//        CFDataRef certData = SecCertificateCopyData(cert);
//
//        const UInt8* certDataBytes = CFDataGetBytePtr(certData);
//        CFIndex certDataLength = CFDataGetLength(certData);
//
//        // Convert certificate data to PEM format.
//        BIO* certBio = BIO_new(BIO_s_mem());
//        PEM_write_bio(certBio, "CERTIFICATE", NULL, certDataBytes, certDataLength);
//
//        // Read PEM data into a string.
//        char* pemData;
//        long pemLength = BIO_get_mem_data(certBio, &pemData);
//        result.pem_root_certs += std::string(pemData, pemLength);
//
//        BIO_free(certBio);
//        CFRelease(certData);
//    }
//
//    CFRelease(rootCerts);
//
//    return result;
//}


InvestApiClient::InvestApiClient(const std::string& host, const std::string& pass) {
    auto options = getSslOptions();
//    setenv("GRPC_DEFAULT_SSL_ROOTS_FILE_PATH", "/Users/admin/CLionProjects/TinkoffInvestSDKCPP/cmake-build-debug/vcpkg_installed/arm64-osx/share/grpc/roots.pem", 1);
//    options.pem_root_certs = "./cmake-build-debug/vcpkg_installed/arm64-osx/share/grpc/roots.pem";
    auto credentials = grpc::SslCredentials(options);
//    auto credentials = grpc::InsecureChannelCredentials();
//    auto channel = grpc::CreateChannel(host, grpc::GoogleDefaultCredentials());
    auto channel = grpc::CreateChannel(host, credentials);

    services_["users"] = std::make_shared<Users>(channel, pass);
//    services_["sandbox"] = std::make_shared<Sandbox>(channel, pass);  TBD
//    services_["marketdata"] = std::make_shared<MarketData>(channel, pass);  TBD
//    services_["instruments"] = std::make_shared<Instruments>(channel, pass);  TBD
//    services_["operations"] = std::make_shared<Operations>(channel, pass);  TBD
    services_["orders"] = std::make_shared<Orders>(channel, pass);
    services_["stoporders"] = std::make_shared<StopOrders>(channel, pass);
//    services_["marketdatastream"] = std::make_shared<MarketDataStream>(channel, pass);  TBD
//    services_["ordersstream"] = std::make_shared<OrdersStream>(channel, pass);  TBD
}

InvestApiClient::~InvestApiClient() {
}

std::shared_ptr<BasedService> InvestApiClient::Service(const std::string &service_name) {
    return services_.count(service_name) ? services_[service_name] : nullptr;
}
