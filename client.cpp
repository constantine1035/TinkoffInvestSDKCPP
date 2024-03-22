#include "client.h"

#include "services/reply.h"
#include "services/users.h"
//#include "instruments.h"  TBD
//#include "operations.h"  TBD
//#include "orders.h"  TBD
//#include "ordersstream.h"  TBD
//#include "stoporders.h"  TBD
//#include "sandbox.h"   TBD
//#include "marketdata.h"  TBD
//#include "marketdatastream.h"  TBD

//#ifdef _WIN32
//#include <Windows.h>
//#include <wincrypt.h>
//
//std::string utf8Encode(const std::wstring& wstr)
//{
//	if (wstr.empty())
//		return std::string();
//
//	int sizeNeeded = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
//	std::string strTo(sizeNeeded, 0);
//	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], sizeNeeded, NULL, NULL);
//	return strTo;
//}
//
//grpc::SslCredentialsOptions getSslOptions()
//{
//	// Fetch root certificate as required on Windows (s. issue 25533).
//	grpc::SslCredentialsOptions result;
//
//	// Open root certificate store.
//	HANDLE hRootCertStore = CertOpenSystemStoreW(NULL, L"ROOT");
//	if (!hRootCertStore)
//		return result;
//
//	// Get all root certificates.
//	PCCERT_CONTEXT pCert = NULL;
//	while ((pCert = CertEnumCertificatesInStore(hRootCertStore, pCert)) != NULL)
//	{
//		// Append this certificate in PEM formatted data.
//		DWORD size = 0;
//		CryptBinaryToStringW(pCert->pbCertEncoded, pCert->cbCertEncoded, CRYPT_STRING_BASE64HEADER, NULL, &size);
//		std::vector<WCHAR> pem(size);
//		CryptBinaryToStringW(pCert->pbCertEncoded, pCert->cbCertEncoded, CRYPT_STRING_BASE64HEADER, pem.data(), &size);
//
//		result.pem_root_certs += utf8Encode(pem.data());
//	}
//	CertCloseStore(hRootCertStore, 0);
//
//	return result;
//}
//#endif               IDK WHAT IS IT something for windows

InvestApiClient::InvestApiClient(const std::string &host, const std::string &pass)
{
    auto channel = grpc::CreateChannel(host, grpc::SslCredentials(
#ifdef _WIN32
       getSslOptions()
#else
       grpc::SslCredentialsOptions()
#endif
    ));

    services_["users"] = std::make_shared<Users>(channel, pass);
//    services_["sandbox"] = std::make_shared<Sandbox>(channel, pass);  TBD
//    services_["marketdata"] = std::make_shared<MarketData>(channel, pass);  TBD
//    services_["instruments"] = std::make_shared<Instruments>(channel, pass);  TBD
//    services_["operations"] = std::make_shared<Operations>(channel, pass);  TBD
//    services_["orders"] = std::make_shared<Orders>(channel, pass);  TBD
//    services_["stoporders"] = std::make_shared<StopOrders>(channel, pass);  TBD
//    services_["marketdatastream"] = std::make_shared<MarketDataStream>(channel, pass);  TBD
//    services_["ordersstream"] = std::make_shared<OrdersStream>(channel, pass);  TBD
}

InvestApiClient::~InvestApiClient() {
}

std::shared_ptr<BasedService> InvestApiClient::Service(const std::string &service_name) {
    return services_.count(service_name) ? services_[service_name] : nullptr;
}
