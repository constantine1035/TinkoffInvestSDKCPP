#include "tinkoff_invest_cppsdk/users_client.h"

namespace tinkoff_invest_cppsdk {

    InvestApiUsersClient::InvestApiUsersClient(const std::string &token) : InvestApiBaseClient(token) {
    }

    InvestApiUsersClient::~InvestApiUsersClient() {
    }

    ServiceReply<V1GetAccountsResponse> InvestApiUsersClient::UsersServiceGetAccounts() {
        InitService<ServiceId::UsersService, UsersServiceApi>();

        auto body = std::make_shared<V1GetAccountsRequest>();

        std::function<pplx::task<std::shared_ptr<V1GetAccountsResponse>>(const UsersServiceApi&, std::shared_ptr<V1GetAccountsRequest>)> req = &UsersServiceApi::usersServiceGetAccounts;
        return MakeRequest<ServiceId::UsersService>(body, req);
    }

    ServiceReply<V1GetMarginAttributesResponse> InvestApiUsersClient::UsersServiceGetMarginAttributes(
            const std::string &account_id
    ) {
        InitService<ServiceId::MarketDataService, UsersServiceApi>();

        auto body = std::make_shared<V1GetMarginAttributesRequest>();

        body->setAccountId(account_id);

        std::function<pplx::task<std::shared_ptr<V1GetMarginAttributesResponse>>(const UsersServiceApi&, std::shared_ptr<V1GetMarginAttributesRequest>)> req = &UsersServiceApi::marketDataServiceGetMarginAttributes;
        return MakeRequest<ServiceId::UsersService>(body, req);
    }

    ServiceReply<V1GetUserTariffResponse> InvestApiUsersClient::UsersServiceGetUserTariff() {
        InitService<ServiceId::UsersService, UsersServiceApi>();

        auto body = std::make_shared<V1GetUserTariffRequest>();

        std::function<pplx::task<std::shared_ptr<V1GetUserTariffResponse>>(const UsersServiceApi&, std::shared_ptr<V1GetUserTariffRequest>)> req = &UsersServiceApi::usersServiceGetUserTariff;
        return MakeRequest<ServiceId::UsersService>(body, req);
    }

    ServiceReply<V1GetInfoResponse> InvestApiUsersClient::UsersServiceGetInfo() {
        InitService<ServiceId::UsersService, UsersServiceApi>();

        auto body = std::make_shared<V1GetInfoRequest>();

        std::function<pplx::task<std::shared_ptr<V1GetInfoResponse>>(const UsersServiceApi&, std::shared_ptr<V1GetInfoRequest>)> req = &UsersServiceApi::usersServiceGetInfo;
        return MakeRequest<ServiceId::UsersService>(body, req);
    }

}  // tinkoff_invest_cppsdk
