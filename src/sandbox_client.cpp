#include "tinkoff_invest_cppsdk/sandbox_client.h"

#include <cpprest/asyncrt_utils.h>

namespace tinkoff_invest_cppsdk {

InvestApiSandboxClient::InvestApiSandboxClient(const std::string &token)
    : InvestApiBaseClient(token) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();
}

InvestApiSandboxClient::~InvestApiSandboxClient() {
}

ServiceReply<V1CancelOrderResponse> InvestApiSandboxClient::SandboxServiceCancelSandboxOrder(
    const std::string &account_id, const std::string &order_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1CancelOrderResponse> &)> callback) {

    auto body = std::make_shared<V1CancelOrderRequest>();
    body->setAccountId(account_id);
    body->setOrderId(order_id);

    std::function<pplx::task<std::shared_ptr<V1CancelOrderResponse>>(
        const SandboxServiceApi &, std::shared_ptr<V1CancelOrderRequest>)>
        req = &SandboxServiceApi::sandboxServiceCancelSandboxOrder;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<Object> InvestApiSandboxClient::SandboxServiceCloseSandboxAccount(
    const std::string &account_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<Object> &)> callback) {

    auto body = std::make_shared<V1CloseSandboxAccountRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<Object>>(
        const SandboxServiceApi &, std::shared_ptr<V1CloseSandboxAccountRequest>)>
        req = &SandboxServiceApi::sandboxServiceCloseSandboxAccount;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<V1GetAccountsResponse> InvestApiSandboxClient::SandboxServiceGetSandboxAccounts(
    bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1GetAccountsResponse> &)> callback) {

    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetAccountsResponse>>(const SandboxServiceApi &,
                                                                     std::shared_ptr<Object>)>
        req = &SandboxServiceApi::sandboxServiceGetSandboxAccounts;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<V1OperationsResponse> InvestApiSandboxClient::SandboxServiceGetSandboxOperations(
    const std::string &account_id, const std::string &figi, utility::datetime from,
    utility::datetime to, std::shared_ptr<V1OperationState> state, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1OperationsResponse> &)> callback) {

    auto body = std::make_shared<V1OperationsRequest>();
    body->setAccountId(account_id);
    body->setFigi(figi);
    body->setFrom(from);
    body->setTo(to);
    body->setState(state);

    std::function<pplx::task<std::shared_ptr<V1OperationsResponse>>(
        const SandboxServiceApi &, std::shared_ptr<V1OperationsRequest>)>
        req = &SandboxServiceApi::sandboxServiceGetSandboxOperations;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<V1GetOperationsByCursorResponse>
InvestApiSandboxClient::SandboxServiceGetSandboxOperationsByCursor(
    const std::string &account_id, const std::string &instrument_id, utility::datetime from,
    utility::datetime to, const std::string &cursor, int32_t limit,
    const std::vector<std::shared_ptr<V1OperationType>> &operation_types,
    std::shared_ptr<V1OperationState> state, bool without_commissions, bool without_trades,
    bool without_overnights, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1GetOperationsByCursorResponse> &)> callback) {

    auto body = std::make_shared<V1GetOperationsByCursorRequest>();
    body->setAccountId(account_id);
    body->setFrom(from);
    body->setTo(to);
    body->setCursor(cursor);
    body->setLimit(limit);
    body->setOperationTypes(operation_types);
    body->setState(state);
    body->setWithoutCommissions(without_commissions);
    body->setWithoutTrades(without_trades);
    body->setWithoutOvernights(without_overnights);

    std::function<pplx::task<std::shared_ptr<V1GetOperationsByCursorResponse>>(
        const SandboxServiceApi &, std::shared_ptr<V1GetOperationsByCursorRequest>)>
        req = &SandboxServiceApi::sandboxServiceGetSandboxOperationsByCursor;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<V1OrderState> InvestApiSandboxClient::SandboxServiceGetSandboxOrderState(
    const std::string &account_id, const std::string &order_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1OrderState> &)> callback) {

    auto body = std::make_shared<V1GetOrderStateRequest>();
    body->setAccountId(account_id);
    body->setOrderId(order_id);

    std::function<pplx::task<std::shared_ptr<V1OrderState>>(
        const SandboxServiceApi &, std::shared_ptr<V1GetOrderStateRequest>)>
        req = &SandboxServiceApi::sandboxServiceGetSandboxOrderState;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<V1GetOrdersResponse> InvestApiSandboxClient::SandboxServiceGetSandboxOrders(
    const std::string &account_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1GetOrdersResponse> &)> callback) {

    auto body = std::make_shared<V1GetOrdersRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1GetOrdersResponse>>(
        const SandboxServiceApi &, std::shared_ptr<V1GetOrdersRequest>)>
        req = &SandboxServiceApi::sandboxServiceGetSandboxOrders;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<V1PortfolioResponse> InvestApiSandboxClient::SandboxServiceGetSandboxPortfolio(
    const std::string &account_id, std::shared_ptr<PortfolioRequestCurrencyRequest> currency,
    bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1PortfolioResponse> &)> callback) {

    auto body = std::make_shared<V1PortfolioRequest>();
    body->setAccountId(account_id);
    body->setCurrency(currency);

    std::function<pplx::task<std::shared_ptr<V1PortfolioResponse>>(
        const SandboxServiceApi &, std::shared_ptr<V1PortfolioRequest>)>
        req = &SandboxServiceApi::sandboxServiceGetSandboxPortfolio;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<V1PositionsResponse> InvestApiSandboxClient::SandboxServiceGetSandboxPositions(
    const std::string &account_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1PositionsResponse> &)> callback) {

    auto body = std::make_shared<V1PositionsRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1PositionsResponse>>(
        const SandboxServiceApi &, std::shared_ptr<V1PositionsRequest>)>
        req = &SandboxServiceApi::sandboxServiceGetSandboxPositions;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<V1WithdrawLimitsResponse>
InvestApiSandboxClient::SandboxServiceGetSandboxWithdrawLimits(
    const std::string &account_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1WithdrawLimitsResponse> &)> callback) {

    auto body = std::make_shared<V1WithdrawLimitsRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1WithdrawLimitsResponse>>(
        const SandboxServiceApi &, std::shared_ptr<V1WithdrawLimitsRequest>)>
        req = &SandboxServiceApi::sandboxServiceGetSandboxWithdrawLimits;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<V1OpenSandboxAccountResponse>
InvestApiSandboxClient::SandboxServiceOpenSandboxAccount(
    const std::string &name, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1OpenSandboxAccountResponse> &)> callback) {

    auto body = std::make_shared<V1OpenSandboxAccountRequest>();
    body->setName(name);

    std::function<pplx::task<std::shared_ptr<V1OpenSandboxAccountResponse>>(
        const SandboxServiceApi &, std::shared_ptr<V1OpenSandboxAccountRequest>)>
        req = &SandboxServiceApi::sandboxServiceOpenSandboxAccount;
    return MakeRequestAsync<ServiceId::SandboxService>(req, body);
}

ServiceReply<V1PostOrderResponse> InvestApiSandboxClient::SandboxServicePostSandboxOrder(
    const std::string &account_id, const std::string &order_id, const std::string &instrument_id,
    const std::string &quantity, const std::string &units, int32_t nano,
    std::shared_ptr<V1OrderDirection> direction, std::shared_ptr<V1OrderType> order_type,
    bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1PostOrderResponse> &)> callback) {

    auto body = std::make_shared<V1PostOrderRequest>();

    auto quotation = std::make_shared<V1Quotation>();
    quotation->setUnits(units);
    quotation->setNano(nano);

    body->setAccountId(account_id);
    body->setOrderId(order_id);
    body->setInstrumentId(instrument_id);
    body->setQuantity(quantity);
    body->setPrice(quotation);
    body->setDirection(direction);
    body->setOrderType(order_type);

    std::function<pplx::task<std::shared_ptr<V1PostOrderResponse>>(
        const SandboxServiceApi &, std::shared_ptr<V1PostOrderRequest>)>
        req = &SandboxServiceApi::sandboxServicePostSandboxOrder;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<V1PostOrderResponse> InvestApiSandboxClient::SandboxServiceReplaceSandboxOrder(
    const std::string &account_id, const std::string &order_id, const std::string &idempotency_key,
    const std::string &quantity, const std::string &units, int32_t nano,
    std::shared_ptr<V1PriceType> price_type, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1PostOrderResponse> &)> callback) {

    auto body = std::make_shared<V1ReplaceOrderRequest>();

    auto quotation = std::make_shared<V1Quotation>();
    quotation->setUnits(units);
    quotation->setNano(nano);

    body->setAccountId(account_id);
    body->setOrderId(order_id);
    body->setIdempotencyKey(idempotency_key);
    body->setQuantity(quantity);
    body->setPrice(quotation);
    body->setPriceType(price_type);

    std::function<pplx::task<std::shared_ptr<V1PostOrderResponse>>(
        const SandboxServiceApi &, std::shared_ptr<V1ReplaceOrderRequest>)>
        req = &SandboxServiceApi::sandboxServiceReplaceSandboxOrder;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

ServiceReply<V1SandboxPayInResponse> InvestApiSandboxClient::SandboxServicePayIn(
    const std::string &account_id, const std::string &currency, const std::string &units,
    int32_t nano, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1SandboxPayInResponse> &)> callback) {

    auto body = std::make_shared<V1SandboxPayInRequest>();

    auto money_value = std::make_shared<V1MoneyValue>();
    money_value->setCurrency(currency);
    money_value->setUnits(units);
    money_value->setNano(nano);

    body->setAccountId(account_id);
    body->setAmount(money_value);

    std::function<pplx::task<std::shared_ptr<V1SandboxPayInResponse>>(
        const SandboxServiceApi &, std::shared_ptr<V1SandboxPayInRequest>)>
        req = &SandboxServiceApi::sandboxServiceSandboxPayIn;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::SandboxService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::SandboxService>(req, body, retry_max, callback);
}

}  // namespace tinkoff_invest_cppsdk
