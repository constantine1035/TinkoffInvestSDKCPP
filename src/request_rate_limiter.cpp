#include "tinkoff_invest_cppsdk/request_rate_limiter.h"

#include <chrono>

namespace tinkoff_invest_cppsdk {

RequestRateLimiter::RequestRateLimiter() {
    monitor_thread_ = std::thread(&RequestRateLimiter::ResetRequestCount, this);
}

RequestRateLimiter::~RequestRateLimiter() {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        stop_monitor_thread_ = true;
    }
    cv_.notify_one();
    monitor_thread_.join();
}

void RequestRateLimiter::IncrementRequestCount() {
    std::lock_guard<std::mutex> lock(mutex_);
    ++request_count_;
}

int RequestRateLimiter::GetRequestCount() {
    std::lock_guard<std::mutex> lock(mutex_);
    return request_count_;
}

void RequestRateLimiter::ResetRequestCount() {
    std::unique_lock<std::mutex> lock(mutex_);
    while (!stop_monitor_thread_) {
        cv_.wait_for(lock, std::chrono::minutes(1));
        request_count_ = 0;
    }
}

}  // namespace tinkoff_invest_cppsdk
