#pragma once

#include "../include/xxhr/xxhr/response.hpp"
#include <nlohmann/json.hpp>
#include <string>

namespace tinkoff_invest_sdk_cpp_reply_service {

using xxhr::Response;
using xxhr::Error;
using xxhr::Header;

class ServiceReply {
public:
    explicit ServiceReply(const Response& service_reply);

    explicit ServiceReply(Response&& service_reply);

    bool Success() const;

    std::int32_t GetStatusCode() const;

    const Error& GetError() const;

    const nlohmann::json& GetStatusMessage() const;

    const nlohmann::json& GetData() const;

protected:
    std::int32_t status_code_;
    Error error_;
    nlohmann::json status_message_;
    nlohmann::json data_;
    Header header_;
};
}  // namespace tinkoff_invest_sdk_cpp_reply_service