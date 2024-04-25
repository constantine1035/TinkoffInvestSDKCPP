#pragma once

#include "reply.h"
#include "../include/xxhr/xxhr/xxhr.hpp"
#include <nlohmann/json.hpp>
#include <string>

namespace tinkoff_invest_sdk_cpp_based_service {

using tinkoff_invest_sdk_cpp_reply_service::ServiceReply;

// Base class for all services.
class BasedService {
public:
    explicit BasedService(const std::string &token);

    virtual ~BasedService() = default;

protected:
    std::string token_;

    virtual ServiceReply DoPostRequestSync(const nlohmann::json& body,
                                           const std::string& url);

    virtual ServiceReply DoPostRequestAsync(const nlohmann::json& body,
                                            const std::string& url); // have to add retry + callback.
};
} // namespace tinkoff_invest_sdk_cpp_based_service
