#include "tinkoff_invest_cppsdk/stream_tracker.h"

#include <string>

namespace tinkoff_invest_cppsdk {

void StreamTracker::SetLimits(const std::array<int, kStreamLimitsSize> &limits) {
    limits_ = limits;
}

void StreamTracker::IncreaseStreamCount(StreamLimitId stream_id) {
    std::lock_guard<std::mutex> lock(mutex_);
    int id = static_cast<int>(stream_id);
    ++stream_counts_[id];
    if (stream_counts_[id] > limits_[id]) {
        throw ApiException(429, "Too many streams. StreamId: " + std::to_string(id));
    }
}

void StreamTracker::DegreaseStreamCount(StreamLimitId stream_id) {
    std::lock_guard<std::mutex> lock(mutex_);
    int id = static_cast<int>(stream_id);
    --stream_counts_[id];
    if (stream_counts_[id] < 0) {
        throw ApiException(429, "Stream counts < 0. StreamId: " + std::to_string(id));
    }
}

}  // namespace tinkoff_invest_cppsdk
