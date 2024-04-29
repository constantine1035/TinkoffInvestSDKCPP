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

    ServiceReply<V1CancelOrderResponse> CancelSandboxOrder(
        const std::string& account_id, const std::string& order_id
        );

    ServiceReply<Object> CloseSandboxAccountSync(const std::string& account_id);

    ServiceReply<V1GetAccountsResponse> GetSandboxAccounts();

    ServiceReply<V1OperationsResponse> GetSandboxOperations(
        const std::string &account_id, const std::string &figi,
        int64_t from_seconds, int32_t from_nanos, int64_t to_seconds,
        int32_t to_nanos, V1OperationState::eV1OperationState state
        );

    ServiceReply<V1GetOperationsByCursorResponse> GetSandboxOperationsByCursor(
        const std::string &account_id, const std::string &instrument_id,
        int64_t from_seconds, int32_t from_nanos, int64_t to_seconds,
        int32_t to_nanos, const std::string &cursor, int32_t limit,
        const int &operation_types, V1OperationState state,
        bool without_commissions, bool without_trades,
        bool without_overnights
        );

    ServiceReply<V1OrderState> GetSandboxOrderState(
        const std::string &account_id, const std::string &order_id
        );

    ServiceReply<V1GetOrdersResponse> GetSandboxOrders(const std::string &account_id);

    ServiceReply<V1PortfolioResponse> GetSandboxPortfolio(
        const std::string &account_id,
        PortfolioRequestCurrencyRequest::ePortfolioRequestCurrencyRequest currency
        );

    ServiceReply<V1PositionsResponse> GetSandboxPositions(const std::string &account_id);

    ServiceReply<V1WithdrawLimitsResponse> GetSandboxWithdrawLimits(const std::string &account_id);

    ServiceReply<V1OpenSandboxAccountResponse> OpenSandboxAccountSync(const std::string& name);

    ServiceReply<V1PostOrderResponse> PostSandboxOrder(
        const std::string &account_id, const std::string &order_id,
        const std::string &instrument_id, int64_t quantity,
        int64_t units, int32_t nano,  int direction, int order_type
        );

    ServiceReply<V1PostOrderResponse> ReplaceSandboxOrder(
        const std::string &account_id, const std::string &order_id,
        const std::string &idempotency_key, int64_t quantity,
        int64_t units, int32_t nano, int price_type
        );

    ServiceReply<V1SandboxPayInResponse> PayIn(const std::string &account_id,
                                               const std::string &currency,
                                               int64_t units,
                                               int32_t nano
                                               );

};

}  // tinkoff_invest_cppsdk