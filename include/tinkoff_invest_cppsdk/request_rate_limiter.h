#pragma once

/*
 * request_rate_limiter.h
 *
 *
 *
 * https://russianinvestments.github.io/investAPI/limits/
 */

#include "CppRestOpenAPIClient/ApiException.h"
#include "tinkoff_invest_cppsdk/types_and_constants.h"

#include <array>
#include <mutex>
#include <thread>
#include <condition_variable>

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::ApiException;

class RequestRateLimiter {
public:
    RequestRateLimiter();

    ~RequestRateLimiter();

    void SetLimits(const std::array<int, kUnaryLimitsSize> &limits);

    void IncrementRequestCount(int request_id);

    int GetRequestCount(int request_id) const;

protected:
    enum class UnaryLimitId {
        InstrumentsService,
        MarketDataService,
        OperationsService,
        OperationsServiceGetBrokerReport,
        OperationsServiceGetDividendsForeignIssuer,
        OrdersService,
        OrdersServiceGetOrders,
        SandboxService,
        StopOrdersService,
        UsersService
    };

    std::array<int, kUnaryLimitsSize> limits_;
    std::array<int, kUnaryLimitsSize> request_counts_;
    mutable std::mutex mutex_;
    std::thread monitor_thread_;
    std::condition_variable cv_;
    bool stop_monitor_thread_;

    void ResetRequestCount();
};

}  // namespace tinkoff_invest_cppsdk