#pragma once

/*
 * Users_client.h
 *
 * This is a client class that use UsersServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiUsersClient : public InvestApiBaseClient {
public:
    explicit InvestApiUsersClient(const std::string& token);

    ~InvestApiUsersClient() override;

    ServiceReply<V1GetAccountsResponse> UsersServiceGetAccounts() const;

    ServiceReply<V1GetMarginAttributesResponse> UsersServiceGetMarginAttributes(
        const std::string& account_id) const;

    ServiceReply<V1GetUserTariffResponse> UsersServiceGetUserTariff() const;

    ServiceReply<V1GetInfoResponse> UsersServiceGetInfo() const;
};

}  // namespace tinkoff_invest_cppsdk