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

    ServiceReply<V1GetAccountsResponse> UsersServiceGetAccounts();

    ServiceReply<V1GetMarginAttributesResponse> UsersServiceGetMarginAttributes(
        const std::string& account_id);

    ServiceReply<V1GetUserTariffResponse> UsersServiceGetUserTariff();

    ServiceReply<V1GetInfoResponse> UsersServiceGetInfo();

protected:
    void InitLimiters();

    void InitRequestRateLimiter(
        const std::vector<std::shared_ptr<V1UnaryLimit>>& client_request_limits);

    void InitStreamTracker(const std::vector<std::shared_ptr<V1StreamLimit>>& client_stream_limits);
};

}  // namespace tinkoff_invest_cppsdk