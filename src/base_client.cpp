#include "tinkoff_invest_cppsdk/base_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiBaseClient::InvestApiBaseClient(const std::string& token, TradingMode trading_mode)
    : token_(token),
      trading_mode_(trading_mode),
      stream_tracker_(std::make_unique<StreamTracker>()),
      stream_subscription_tracker_(std::make_unique<StreamSubscriptionTracker>()) {
    if (trading_mode_ == TradingMode::Sandbox) {
        request_rate_limiter_ = std::make_unique<SandboxRequestRateLimiter>();
        dynamic_cast<SandboxRequestRateLimiter*>(request_rate_limiter_.get())->SetLimits({0, 0, 1});
    } else {
        request_rate_limiter_ = std::make_unique<ProdRequestRateLimiter>();
        dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
            ->SetLimits({0, 0, 0, 0, 0, 0, 0, 0, 0, 1});
    }
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
