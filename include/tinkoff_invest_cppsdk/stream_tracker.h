#pragma once

/*
 * stream_tracker.h
 *
 *
 *
 * https://russianinvestments.github.io/investAPI/limits/
 */

#include <CppRestOpenAPIClient/ApiException.h>

#include <mutex>

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::ApiException;

class StreamTracker {
public:
    void IncreaseStreamCount();

    void DegreaseStreamCount();

    int GetStreamCount();

protected:
    std::mutex mutex_;
    int stream_count_;
};

}  // namespace tinkoff_invest_cppsdk