#include "tinkoff_invest_cppsdk/stream_tracker.h"

#include <string>

namespace tinkoff_invest_cppsdk {

void StreamTracker::SetLimits(const std::array<int, kStreamLimitsSize> &limits) {
    limits_ = limits;
}

void StreamTracker::IncreaseStreamCount(int stream_id) {
    std::lock_guard<std::mutex> lock(mutex_);
    ++stream_counts_[stream_id];
    if (stream_counts_[stream_id] > limits_[stream_id]) {
        throw ApiException(429, "Too many streams. StreamId: " + std::to_string(stream_id));
    }
}

void StreamTracker::DegreaseStreamCount(int stream_id) {
    std::lock_guard<std::mutex> lock(mutex_);
    --stream_counts_[stream_id];
    if (stream_counts_[stream_id] > limits_[stream_id]) {
        throw ApiException(429, "Stream counts < 0. StreamId: " + std::to_string(stream_id));
    }
}

int StreamTracker::GetStreamCount(int stream_id) const {
    std::lock_guard<std::mutex> lock(mutex_);
    return stream_counts_[stream_id];
}

}  // namespace tinkoff_invest_cppsdk
