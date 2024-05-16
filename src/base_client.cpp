#include "tinkoff_invest_cppsdk/base_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiBaseClient::InvestApiBaseClient(const std::string& token, TradingMode trading_mode)
    : token_(token),
      trading_mode_(trading_mode),
      stream_tracker_(std::make_unique<StreamTracker>()),
      stream_subscription_tracker_(std::make_unique<StreamSubscriptionTracker>()) {
}

InvestApiBaseClient::~InvestApiBaseClient() {
}

std::shared_ptr<const some_service_t> InvestApiBaseClient::GetClientService(ServiceId id) const {
    return services_[static_cast<int>(id)];
}

std::shared_ptr<const some_service_t>& InvestApiBaseClient::GetClientService(ServiceId id) {
    return services_[static_cast<int>(id)];
}

}  // namespace tinkoff_invest_cppsdk
