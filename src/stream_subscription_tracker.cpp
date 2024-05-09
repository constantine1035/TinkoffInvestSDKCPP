#include "tinkoff_invest_cppsdk/stream_subscription_tracker.h"

namespace tinkoff_invest_cppsdk {

void StreamSubscriptionTracker::IncreaseStreamSubscriptionCount(int stream_id) {
    std::lock_guard<std::mutex> lock(mutex_);
    ++subscription_count_[stream_id];
}

void StreamSubscriptionTracker::DegreaseStreamCount(int stream_id) {
    std::lock_guard<std::mutex> lock(mutex_);
    --subscription_count_[stream_id];
}

int StreamSubscriptionTracker::GetStreamCount(int stream_id) {
    std::lock_guard<std::mutex> lock(mutex_);
    return subscription_count_[stream_id];
}

}  // namespace tinkoff_invest_cppsdk
