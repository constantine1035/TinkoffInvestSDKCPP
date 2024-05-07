#include "tinkoff_invest_cppsdk/users_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiUsersClient::InvestApiUsersClient(const std::string &token) : InvestApiBaseClient(token) {
    InitService<ServiceId::UsersService, UsersServiceApi>();
}

InvestApiUsersClient::~InvestApiUsersClient() {
}

ServiceReply<V1GetAccountsResponse> InvestApiUsersClient::UsersServiceGetAccounts() const {
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetAccountsResponse>>(const UsersServiceApi &,
                                                                     std::shared_ptr<Object>)>
        req = &UsersServiceApi::usersServiceGetAccounts;
    return MakeRequestAsync<ServiceId::UsersService>(req, body);
}

ServiceReply<V1GetMarginAttributesResponse> InvestApiUsersClient::UsersServiceGetMarginAttributes(
    const std::string &account_id) const {
    auto body = std::make_shared<V1GetMarginAttributesRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1GetMarginAttributesResponse>>(
        const UsersServiceApi &, std::shared_ptr<V1GetMarginAttributesRequest>)>
        req = &UsersServiceApi::usersServiceGetMarginAttributes;
    return MakeRequestAsync<ServiceId::UsersService>(req, body);
}

ServiceReply<V1GetUserTariffResponse> InvestApiUsersClient::UsersServiceGetUserTariff() const {
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetUserTariffResponse>>(const UsersServiceApi &,
                                                                       std::shared_ptr<Object>)>
        req = &UsersServiceApi::usersServiceGetUserTariff;
    return MakeRequestAsync<ServiceId::UsersService>(req, body);
}

ServiceReply<V1GetInfoResponse> InvestApiUsersClient::UsersServiceGetInfo() const {
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetInfoResponse>>(const UsersServiceApi &,
                                                                 std::shared_ptr<Object>)>
        req = &UsersServiceApi::usersServiceGetInfo;
    return MakeRequestAsync<ServiceId::UsersService>(req, body);
}

}  // namespace tinkoff_invest_cppsdk
