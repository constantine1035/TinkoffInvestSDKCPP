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

void RequestRateLimiter::SetLimits(const std::array<int, kUnaryLimitsSize> &limits) {
    limits_ = limits;
}

void RequestRateLimiter::IncrementRequestCount(int request_id) {
    std::lock_guard<std::mutex> lock(mutex_);
    ++request_counts_[request_id];
    if (request_counts_[request_id] > limits_[request_id]) {
        throw ApiException(429,
                           "Too many unary requests. RequestId: " + std::to_string(request_id));
    }
}

int RequestRateLimiter::GetRequestCount(int request_id) const {
    std::lock_guard<std::mutex> lock(mutex_);
    return request_counts_[request_id];
}

void RequestRateLimiter::ResetRequestCount() {
    std::unique_lock<std::mutex> lock(mutex_);
    while (!stop_monitor_thread_) {
        cv_.wait_for(lock, std::chrono::minutes(1));
        for (int &num : request_counts_) {
            num = 0;
        }
    }
}

}  // namespace tinkoff_invest_cppsdk
