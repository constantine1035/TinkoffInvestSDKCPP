#pragma once

/*
 * stream_tracker.h
 *
 *
 *
 * https://russianinvestments.github.io/investAPI/limits/
 */

#include "CppRestOpenAPIClient/ApiException.h"
#include "tinkoff_invest_cppsdk/types_and_constants.h"

#include <array>
#include <mutex>

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::ApiException;

class StreamTracker {
public:
    enum class StreamLimitId {
        MarketDataStream,  //  md_stream_service
        TradesStream,      //  orders_stream_service
        PortfolioStream,   //  operations_stream_service
        PositionsStream    //  operations_stream_service
    };

    void SetLimits(const std::array<int, kStreamLimitsSize> &limits);

    void IncrementStreamCount(StreamLimitId stream_id);

    void DecrementStreamCount(StreamLimitId stream_id);

protected:
    std::array<int, kStreamLimitsSize> limits_;
    std::array<int, kStreamLimitsSize> stream_counts_;
    mutable std::mutex mutex_;
};

}  // namespace tinkoff_invest_cppsdk