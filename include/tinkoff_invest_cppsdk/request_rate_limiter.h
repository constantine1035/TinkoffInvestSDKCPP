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
#include <condition_variable>
#include <mutex>
#include <thread>

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::ApiException;

class BaseRequestRateLimiter {
public:
    virtual ~BaseRequestRateLimiter();
};

class ProdRequestRateLimiter : public BaseRequestRateLimiter {
public:
    enum class UnaryProdLimitId {
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

    ProdRequestRateLimiter();

    ~ProdRequestRateLimiter() override;

    void SetLimits(const std::array<int, kUnaryProdLimitsSize> &limits);

    void IncrementRequestCount(UnaryProdLimitId request_id);

protected:
    std::array<int, kUnaryProdLimitsSize> limits_;
    std::array<int, kUnaryProdLimitsSize> request_counts_;
    mutable std::mutex mutex_;
    std::thread monitor_thread_;
    std::condition_variable cv_;
    bool stop_monitor_thread_;

    void ResetRequestCount();
};

class SandboxRequestRateLimiter : public BaseRequestRateLimiter {
public:
    enum class UnarySandboxLimitId {
        InstrumentsService,
        MarketDataService,
        OtherServices,
    };

    SandboxRequestRateLimiter();

    ~SandboxRequestRateLimiter() override;

    void SetLimits(const std::array<int, kUnarySandboxLimitsSize> &limits);

    void IncrementRequestCount(UnarySandboxLimitId request_id);

protected:
    std::array<int, kUnarySandboxLimitsSize> limits_;
    std::array<int, kUnarySandboxLimitsSize> request_counts_;
    mutable std::mutex mutex_;
    std::thread monitor_thread_;
    std::condition_variable cv_;
    bool stop_monitor_thread_;

    void ResetRequestCount();
};

}  // namespace tinkoff_invest_cppsdk