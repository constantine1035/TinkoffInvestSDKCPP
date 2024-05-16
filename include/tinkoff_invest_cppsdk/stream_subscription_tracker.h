#pragma once

/*
 * stream_subscription_tracker.h
 *
 *
 *
 * https://russianinvestments.github.io/investAPI/limits/
 */

#include "CppRestOpenAPIClient/ApiException.h"

#include <array>
#include <mutex>

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::ApiException;

class StreamSubscriptionTracker {
public:
    void IncreaseStreamSubscriptionCount(int quantity);

    void DegreaseStreamCount(int quantity);

protected:
    int subscription_counts_;
    mutable std::mutex mutex_;
};

}  // namespace tinkoff_invest_cppsdk