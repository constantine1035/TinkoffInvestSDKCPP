#include "reply.h"

namespace tinkoff_invest_sdk_cpp_reply_service {

static constexpr std::int32_t kStatusCodeSuccess = 200;

ServiceReply::ServiceReply(const xxhr::Response &service_reply)
    : status_code_(service_reply.status_code),
      error_(service_reply.error),
      header_(service_reply.header) {
    if (Success()) {
        data_ = nlohmann::json::parse(service_reply.text);
    } else {
        status_message_ = nlohmann::json::parse(service_reply.text);
    }
}

ServiceReply::ServiceReply(xxhr::Response&& service_reply)
    : status_code_(std::move(service_reply.status_code)),
      error_(std::move(service_reply.error)),
      header_(std::move(service_reply.header)) {
    if (Success()) {
        data_ = nlohmann::json::parse(std::move(service_reply.text));
    } else {
        status_message_ = nlohmann::json::parse(std::move(service_reply.text));
    }
}

bool ServiceReply::Success() const {
    return status_code_ == kStatusCodeSuccess && !error_;
}

std::int32_t ServiceReply::GetStatusCode() const {
    return status_code_;
}

const Error& ServiceReply::GetError() const {
    return error_;
}

const nlohmann::json& ServiceReply::GetStatusMessage() const {
    return status_message_;
}

const nlohmann::json& ServiceReply::GetData() const {
    return data_;
}

}  // namespace tinkoff_invest_sdk_cpp_reply_service
