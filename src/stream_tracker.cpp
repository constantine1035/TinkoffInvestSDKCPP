#include "tinkoff_invest_cppsdk/stream_tracker.h"

namespace tinkoff_invest_cppsdk {

void StreamTracker::IncreaseStreamCount() {
    std::lock_guard<std::mutex> lock(mutex_);
    ++stream_count_;
}

void StreamTracker::DegreaseStreamCount() {
    std::lock_guard<std::mutex> lock(mutex_);
    --stream_count_;
}

int StreamTracker::GetStreamCount() {
    std::lock_guard<std::mutex> lock(mutex_);
    return stream_count_;
}

}  // namespace tinkoff_invest_cppsdk
