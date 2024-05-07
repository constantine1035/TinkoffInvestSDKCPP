#include "tinkoff_invest_cppsdk/base_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiBaseClient::InvestApiBaseClient(const std::string& token) : token_(token) {
}

InvestApiBaseClient::~InvestApiBaseClient() {
}

std::shared_ptr<some_service_t> InvestApiBaseClient::GetClientService(ServiceId id) const {
    return services_[static_cast<int>(id)];
}

std::shared_ptr<some_service_t>& InvestApiBaseClient::GetClientService(ServiceId id) {
    return services_[static_cast<int>(id)];
}

}  // namespace tinkoff_invest_cppsdk
