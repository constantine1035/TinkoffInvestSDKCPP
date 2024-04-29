#include "tinkoff_invest_cppsdk/base_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiBaseClient::InvestApiBaseClient(const std::string &token) : token_(token) {
}

InvestApiBaseClient::~InvestApiBaseClient() {
}

bool InvestApiBaseClient::ClientService::ServiceIsInitialized() const {
    return isInitialized_;
}

const std::shared_ptr<some_service_t> InvestApiBaseClient::ClientService::GetService() const {
    return service_;
}

InvestApiBaseClient::ClientService& InvestApiBaseClient::GetClientService(ServiceId id) {
    return services_[static_cast<int>(id)];
}

}  // tinkoff_invest_cppsdk
