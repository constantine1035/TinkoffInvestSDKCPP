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

InvestApiClient::InvestApiClient(const std::string& host, const std::string& pass) {
    auto options = grpc::SslCredentialsOptions();
    setenv("GRPC_DEFAULT_SSL_ROOTS_FILE_PATH", "/Users/admin/CLionProjects/TinkoffInvestSDKCPP/cmake-build-debug/vcpkg_installed/arm64-osx/share/grpc/roots.pem", 1);
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
