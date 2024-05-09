#pragma once

/*
 * request_rate_limiter.h
 *
 *
 *
 * https://russianinvestments.github.io/investAPI/limits/
 */

#include <CppRestOpenAPIClient/ApiException.h>

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

    void IncrementRequestCount();

    int GetRequestCount();

protected:
    std::mutex mutex_;
    std::thread monitor_thread_;
    int request_count_;
    std::condition_variable cv_;
    bool stop_monitor_thread_;

    void ResetRequestCount();
};

}  // namespace tinkoff_invest_cppsdk