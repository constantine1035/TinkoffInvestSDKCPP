#pragma once

/*
 * sandbox_client.h
 *
 * This is a client class that use SandboxServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiSandboxClient : public InvestApiBaseClient {
public:
    explicit InvestApiSandboxClient(const std::string& token);

    ~InvestApiSandboxClient() override;

    ServiceReply<V1CancelOrderResponse> SandboxServiceCancelSandboxOrder(
        const std::string& account_id, const std::string& order_id
        );

    ServiceReply<Object> SandboxServiceCloseSandboxAccountSync(
        const std::string& account_id
        );

    ServiceReply<V1GetAccountsResponse> SandboxServiceGetSandboxAccounts();

    ServiceReply<V1OperationsResponse> SandboxServiceGetSandboxOperations(
        const std::string &account_id, const std::string &figi,
        int64_t from_seconds, int32_t from_nanos, int64_t to_seconds,
        int32_t to_nanos, V1OperationState::eV1OperationState state
        );

    ServiceReply<V1GetOperationsByCursorResponse> SandboxServiceGetSandboxOperationsByCursor(
        const std::string &account_id, const std::string &instrument_id,
        int64_t from_seconds, int32_t from_nanos, int64_t to_seconds,
        int32_t to_nanos, const std::string &cursor, int32_t limit,
        const int &operation_types, V1OperationState state,
        bool without_commissions, bool without_trades,
        bool without_overnights
        );

    ServiceReply<V1OrderState> SandboxServiceGetSandboxOrderState(
        const std::string &account_id, const std::string &order_id
        );

    ServiceReply<V1GetOrdersResponse> SandboxServiceGetSandboxOrders(
        const std::string &account_id
        );

    ServiceReply<V1PortfolioResponse> SandboxServiceGetSandboxPortfolio(
        const std::string &account_id,
        PortfolioRequestCurrencyRequest::ePortfolioRequestCurrencyRequest currency
        );

    ServiceReply<V1PositionsResponse> SandboxServiceGetSandboxPositions(
        const std::string &account_id
        );

    ServiceReply<V1WithdrawLimitsResponse> SandboxServiceGetSandboxWithdrawLimits(
        const std::string &account_id
        );

    ServiceReply<V1OpenSandboxAccountResponse> SandboxServiceOpenSandboxAccountSync(
        const std::string& name
        );

    ServiceReply<V1PostOrderResponse> SandboxServicePostSandboxOrder(
        const std::string &account_id, const std::string &order_id,
        const std::string &instrument_id, int64_t quantity,
        int64_t units, int32_t nano,  int direction, int order_type
        );

    ServiceReply<V1PostOrderResponse> SandboxServiceReplaceSandboxOrder(
        const std::string &account_id, const std::string &order_id,
        const std::string &idempotency_key, int64_t quantity,
        int64_t units, int32_t nano, int price_type
        );

    ServiceReply<V1SandboxPayInResponse> SandboxServicePayIn(const std::string &account_id,
                                               const std::string &currency,
                                               const std::string& units,
                                               int32_t nano
                                               );

};

}  // tinkoff_invest_cppsdk