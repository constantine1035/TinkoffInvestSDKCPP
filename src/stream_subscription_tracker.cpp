#include "tinkoff_invest_cppsdk/stream_subscription_tracker.h"

#include "tinkoff_invest_cppsdk/types_and_constants.h"

namespace tinkoff_invest_cppsdk {

void StreamSubscriptionTracker::IncreaseStreamSubscriptionCount(int quantity) {
    std::lock_guard<std::mutex> lock(mutex_);
    subscription_counts_ += quantity;
    if (subscription_counts_ > kSubscriptionLimit) {
        throw ApiException(429, "Too many subscriptions.");
    }
}

void StreamSubscriptionTracker::DegreaseStreamCount(int quantity) {
    std::lock_guard<std::mutex> lock(mutex_);
    subscription_counts_ -= quantity;
    if (subscription_counts_ > kSubscriptionLimit) {
        throw ApiException(429, "Subscriptions counts < 0.");
    }
}

int StreamSubscriptionTracker::GetStreamCount() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return subscription_counts_;
}

}  // namespace tinkoff_invest_cppsdk
