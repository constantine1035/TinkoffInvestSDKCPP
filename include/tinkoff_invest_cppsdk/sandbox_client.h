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
        utility::datetime from, utility::datetime to,
        std::shared_ptr<V1OperationState> state
        );

    ServiceReply<V1GetOperationsByCursorResponse> SandboxServiceGetSandboxOperationsByCursor(
        const std::string &account_id, const std::string &instrument_id,
        utility::datetime from, utility::datetime to,
        const std::string &cursor, int32_t limit,
        const std::vector<std::shared_ptr<V1OperationType>>& operation_types,
        std::shared_ptr<V1OperationState> state,
        bool without_commissions, bool without_trades, bool without_overnights
        );

    ServiceReply<V1OrderState> SandboxServiceGetSandboxOrderState(
        const std::string &account_id, const std::string &order_id
        );

    ServiceReply<V1GetOrdersResponse> SandboxServiceGetSandboxOrders(
        const std::string &account_id
        );

    ServiceReply<V1PortfolioResponse> SandboxServiceGetSandboxPortfolio(
        const std::string &account_id,
        std::shared_ptr<PortfolioRequestCurrencyRequest> currency
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
        const std::string &instrument_id, const std::string& quantity,
        const std::string& units, int32_t nano,
        std::shared_ptr<V1OrderDirection> direction,
        std::shared_ptr<V1OrderType> order_type
        );

    ServiceReply<V1PostOrderResponse> SandboxServiceReplaceSandboxOrder(
        const std::string &account_id, const std::string &order_id,
        const std::string &idempotency_key, const std::string& quantity,
        const std::string& units, int32_t nano,
        std::shared_ptr<V1PriceType> price_type
        );

    ServiceReply<V1SandboxPayInResponse> SandboxServicePayIn(const std::string &account_id,
                                               const std::string &currency,
                                               const std::string& units,
                                               int32_t nano
                                               );

};

}  // tinkoff_invest_cppsdk