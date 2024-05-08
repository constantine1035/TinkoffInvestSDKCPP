#pragma once

/*
 * stream_counter.h
 *
 *
 *
 * https://russianinvestments.github.io/investAPI/limits/
 */

#include <CppRestOpenAPIClient/ApiException.h>

#include <unordered_set>

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::ApiException;

class StreamCounter {
public:
    explicit StreamCounter(int max_count) :
          max_count_(max_count),
          streams_(max_count) {
    }

    void IncreaseStreams(int stream_id) {
        if (streams_.size() >= max_count_) {
            throw ApiException(429, "Too Many Stream Requests");
        }
        streams_.insert(stream_id);
    }

    void DegreaseStreams(int id) {
        streams_.erase(id);
    }

protected:
    std::unordered_set<int> streams_;
    int max_count_;
};






class SubscriptionCounter {
public:
    explicit SubscriptionCounter(const std::unordered_map<std::string, int>& max_count) :
          max_count_(max_count),
          stream_(max_count.size()) {
    }

    void IncreaseStreams(const std::string& subscription_name) {
        if (stream_[subscription_name] >= max_count_[subscription_name]) {
            throw ApiException(429, "Too Many Stream Requests");
        }
        ++stream_[subscription_name];
    }

    void DegreaseStreams(const std::string& subscription_name) {
        if (stream_[subscription_name] == 0) {
            return;
        }
        --stream_[subscription_name];
    }

protected:
    std::unordered_map<std::string, int> stream_;
    std::unordered_map<std::string, int> max_count_;
};

}  // namespace tinkoff_invest_cppsdk