#pragma once

/*
 * stream_subscription_tracker.h
 *
 *
 *
 * https://russianinvestments.github.io/investAPI/limits/
 */

#include <CppRestOpenAPIClient/ApiException.h>

#include <mutex>
#include <unordered_map>

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::ApiException;

class StreamSubscriptionTracker {
public:
    void IncreaseStreamSubscriptionCount(int stream_id);

    void DegreaseStreamCount(int stream_id);

    int GetStreamCount(int stream_id);

protected:
    std::mutex mutex_;
    std::unordered_map<int, int> subscription_count_;
};

}  // namespace tinkoff_invest_cppsdk