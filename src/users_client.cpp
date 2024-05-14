#include "tinkoff_invest_cppsdk/users_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiUsersClient::InvestApiUsersClient(const std::string &token) : InvestApiBaseClient(token) {
    InitService<ServiceId::UsersService, UsersServiceApi>();

    InitLimiters();
}

void InvestApiUsersClient::InitLimiters() {
    auto reply = UsersServiceGetUserTariff();
    if (reply.status == pplx::task_group_status::canceled) {
        throw ApiException(reply.error_code.value(), reply.error_message + reply.error_place);
    }
    InitRequestRateLimiter(reply.response.getUnaryLimits());
    InitStreamTracker(reply.response.getStreamLimits());
}

void InvestApiUsersClient::InitRequestRateLimiter(
    const std::vector<std::shared_ptr<V1UnaryLimit>> &client_request_limits) {
    std::array<int, kUnaryLimitsSize> request_limits;
    for (size_t i = 0; i < kUnaryLimitsSize; ++i) {
        request_limits[i] = client_request_limits[i]->getLimitPerMinute();
    }
    request_rate_limiter_.SetLimits(request_limits);
}

void InvestApiUsersClient::InitStreamTracker(
    const std::vector<std::shared_ptr<V1StreamLimit>> &client_stream_limits) {
    std::array<int, kStreamLimitsSize> stream_limits;
    for (size_t i = 0; i < kStreamLimitsSize; ++i) {
        stream_limits[i] = client_stream_limits[i]->getLimit();
    }
    stream_tracker_.SetLimits(stream_limits);
}

InvestApiUsersClient::~InvestApiUsersClient() {
}

ServiceReply<V1GetAccountsResponse> InvestApiUsersClient::UsersServiceGetAccounts(
        bool is_async_req, int retry_max,
        std::function<void(const ServiceReply<V1GetAccountsResponse>&)> callback) {
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetAccountsResponse>>(const UsersServiceApi&, std::shared_ptr<Object>)>
        req = &UsersServiceApi::usersServiceGetAccounts;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::MarketDataService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::MarketDataService>(req, body, retry_max, callback);
}

ServiceReply<V1GetMarginAttributesResponse> InvestApiUsersClient::UsersServiceGetMarginAttributes(
    const std::string &account_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1GetMarginAttributesResponse>&)> callback) {
    auto body = std::make_shared<V1GetMarginAttributesRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1GetMarginAttributesResponse>>(
        const UsersServiceApi&, std::shared_ptr<V1GetMarginAttributesRequest>)>
        req = &UsersServiceApi::usersServiceGetMarginAttributes;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::MarketDataService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::MarketDataService>(req, body, retry_max, callback);
}

ServiceReply<V1GetUserTariffResponse> InvestApiUsersClient::UsersServiceGetUserTariff(
        bool is_async_req, int retry_max,
        std::function<void(const ServiceReply<V1GetUserTariffResponse>&)> callback) {
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetUserTariffResponse>>(const UsersServiceApi&, std::shared_ptr<Object>)>
        req = &UsersServiceApi::usersServiceGetUserTariff;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::MarketDataService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::MarketDataService>(req, body, retry_max, callback);
}

ServiceReply<V1GetInfoResponse> InvestApiUsersClient::UsersServiceGetInfo(
        bool is_async_req, int retry_max,
        std::function<void(const ServiceReply<V1GetInfoResponse>&)> callback) {
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetInfoResponse>>(const UsersServiceApi&, std::shared_ptr<Object>)>
        req = &UsersServiceApi::usersServiceGetInfo;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::MarketDataService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::MarketDataService>(req, body, retry_max, callback);
}

}  // namespace tinkoff_invest_cppsdk
