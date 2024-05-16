#include "tinkoff_invest_cppsdk/request_rate_limiter.h"

#include <chrono>

namespace tinkoff_invest_cppsdk {

BaseRequestRateLimiter::~BaseRequestRateLimiter() {
}

ProdRequestRateLimiter::ProdRequestRateLimiter() {
    monitor_thread_ = std::thread(&ProdRequestRateLimiter::ResetRequestCount, this);
}

ProdRequestRateLimiter::~ProdRequestRateLimiter() {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        stop_monitor_thread_ = true;
    }
    cv_.notify_one();
    monitor_thread_.join();
}

void ProdRequestRateLimiter::SetLimits(const std::array<int, kUnaryProdLimitsSize> &limits) {
    limits_ = limits;
}

void ProdRequestRateLimiter::IncrementRequestCount(UnaryProdLimitId request_id) {
    std::lock_guard<std::mutex> lock(mutex_);
    int id = static_cast<int>(request_id);
    ++request_counts_[id];
    if (request_counts_[id] > limits_[id]) {
        throw ApiException(429, "Too many unary requests. RequestId: " + std::to_string(id));
    }
}

void ProdRequestRateLimiter::ResetRequestCount() {
    std::unique_lock<std::mutex> lock(mutex_);
    while (!stop_monitor_thread_) {
        cv_.wait_for(lock, std::chrono::minutes(1));
        for (int &num : request_counts_) {
            num = 0;
        }
    }
}

SandboxRequestRateLimiter::SandboxRequestRateLimiter() {
    monitor_thread_ = std::thread(&SandboxRequestRateLimiter::ResetRequestCount, this);
}

SandboxRequestRateLimiter::~SandboxRequestRateLimiter() {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        stop_monitor_thread_ = true;
    }
    cv_.notify_one();
    monitor_thread_.join();
}

void SandboxRequestRateLimiter::SetLimits(const std::array<int, kUnarySandboxLimitsSize> &limits) {
    limits_ = limits;
}

void SandboxRequestRateLimiter::IncrementRequestCount(UnarySandboxLimitId request_id) {
    std::lock_guard<std::mutex> lock(mutex_);
    int id = static_cast<int>(request_id);
    ++request_counts_[id];
    if (request_counts_[id] > limits_[id]) {
        throw ApiException(429, "Too many unary requests. RequestId: " + std::to_string(id));
    }
}

void SandboxRequestRateLimiter::ResetRequestCount() {
    std::unique_lock<std::mutex> lock(mutex_);
    while (!stop_monitor_thread_) {
        cv_.wait_for(lock, std::chrono::minutes(1));
        for (int &num : request_counts_) {
            num = 0;
        }
    }
}

}  // namespace tinkoff_invest_cppsdk
