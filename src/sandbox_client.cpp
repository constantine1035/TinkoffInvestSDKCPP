#include "tinkoff_invest_cppsdk/sandbox_client.h"

#include <cpprest/asyncrt_utils.h>

namespace tinkoff_invest_cppsdk {

InvestApiSandboxClient::InvestApiSandboxClient(
    const std::string &token
    ) : InvestApiBaseClient(token) {
}

InvestApiSandboxClient::~InvestApiSandboxClient() {
}

ServiceReply<V1CancelOrderResponse> InvestApiSandboxClient::SandboxServiceCancelSandboxOrder(
    const std::string &account_id, const std::string &order_id
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1CancelOrderRequest>();
    body->setAccountId(account_id);
    body->setOrderId(order_id);

    std::function<pplx::task<std::shared_ptr<V1CancelOrderResponse>>(const SandboxServiceApi&, std::shared_ptr<V1CancelOrderRequest>)> req = &SandboxServiceApi::sandboxServiceCancelSandboxOrder;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<Object> InvestApiSandboxClient::SandboxServiceCloseSandboxAccountSync(
    const std::string& account_id
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1CloseSandboxAccountRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<Object>>(const SandboxServiceApi&, std::shared_ptr<V1CloseSandboxAccountRequest>)> req = &SandboxServiceApi::sandboxServiceCloseSandboxAccount;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<V1GetAccountsResponse> InvestApiSandboxClient::SandboxServiceGetSandboxAccounts() {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetAccountsResponse>>(const SandboxServiceApi&, std::shared_ptr<Object>)> req = &SandboxServiceApi::sandboxServiceGetSandboxAccounts;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<V1OperationsResponse> InvestApiSandboxClient::SandboxServiceGetSandboxOperations(
    const std::string &account_id, const std::string &figi,
    int64_t from_seconds, int32_t from_nanos, int64_t to_seconds,
    int32_t to_nanos, V1OperationState::eV1OperationState state
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1OperationsRequest>();
    auto operation_state = std::make_shared<V1OperationState>();
    operation_state->setValue(state);

    // date

    body->setAccountId(account_id);
    body->setFigi(figi);
    body->setState(operation_state);

    std::function<pplx::task<std::shared_ptr<V1OperationsResponse>>(const SandboxServiceApi&, std::shared_ptr<V1OperationsRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxOperations;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<V1GetOperationsByCursorResponse> InvestApiSandboxClient::SandboxServiceGetSandboxOperationsByCursor(
    const std::string &account_id, const std::string &instrument_id,
    int64_t from_seconds, int32_t from_nanos, int64_t to_seconds,
    int32_t to_nanos, const std::string &cursor, int32_t limit,
    const int &operation_types, V1OperationState state,
    bool without_commissions, bool without_trades, bool without_overnights
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1GetOperationsByCursorRequest>();
    body->setAccountId(account_id);
    // ....

    std::function<pplx::task<std::shared_ptr<V1GetOperationsByCursorResponse>>(const SandboxServiceApi&, std::shared_ptr<V1GetOperationsByCursorRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxOperationsByCursor;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<V1OrderState> InvestApiSandboxClient::SandboxServiceGetSandboxOrderState(
    const std::string &account_id, const std::string &order_id
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1GetOrderStateRequest>();
    body->setAccountId(account_id);
    body->setOrderId(order_id);

    std::function<pplx::task<std::shared_ptr<V1OrderState>>(const SandboxServiceApi&, std::shared_ptr<V1GetOrderStateRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxOrderState;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<V1GetOrdersResponse> InvestApiSandboxClient::SandboxServiceGetSandboxOrders(
    const std::string &account_id
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1GetOrdersRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1GetOrdersResponse>>(const SandboxServiceApi&, std::shared_ptr<V1GetOrdersRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxOrders;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<V1PortfolioResponse> InvestApiSandboxClient::SandboxServiceGetSandboxPortfolio(
    const std::string &account_id,
    PortfolioRequestCurrencyRequest::ePortfolioRequestCurrencyRequest currency
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1PortfolioRequest>();
    auto portfolio_request_currency_request = std::make_shared<PortfolioRequestCurrencyRequest>();
    portfolio_request_currency_request->setValue(currency);

    body->setAccountId(account_id);
    body->setCurrency(portfolio_request_currency_request);

    std::function<pplx::task<std::shared_ptr<V1PortfolioResponse>>(const SandboxServiceApi&, std::shared_ptr<V1PortfolioRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxPortfolio;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<V1PositionsResponse> InvestApiSandboxClient::SandboxServiceGetSandboxPositions(
    const std::string &account_id
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1PositionsRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1PositionsResponse>>(const SandboxServiceApi&, std::shared_ptr<V1PositionsRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxPositions;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<V1WithdrawLimitsResponse> InvestApiSandboxClient::SandboxServiceGetSandboxWithdrawLimits(
    const std::string &account_id
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1WithdrawLimitsRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1WithdrawLimitsResponse>>(const SandboxServiceApi&, std::shared_ptr<V1WithdrawLimitsRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxWithdrawLimits;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<V1OpenSandboxAccountResponse> InvestApiSandboxClient::SandboxServiceOpenSandboxAccountSync(
    const std::string &name
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1OpenSandboxAccountRequest>();
    body->setName(name);

    std::function<pplx::task<std::shared_ptr<V1OpenSandboxAccountResponse>>(const SandboxServiceApi&, std::shared_ptr<V1OpenSandboxAccountRequest>)> req = &SandboxServiceApi::sandboxServiceOpenSandboxAccount;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<V1PostOrderResponse> InvestApiSandboxClient::SandboxServicePostSandboxOrder(
    const std::string &account_id, const std::string &order_id,
    const std::string &instrument_id, int64_t quantity,
    int64_t units, int32_t nano, int direction, int order_type
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1PostOrderRequest>();
    body->setAccountId(account_id);
    // ...

    std::function<pplx::task<std::shared_ptr<V1PostOrderResponse>>(const SandboxServiceApi&, std::shared_ptr<V1PostOrderRequest>)> req = &SandboxServiceApi::sandboxServicePostSandboxOrder;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

ServiceReply<V1PostOrderResponse> InvestApiSandboxClient::SandboxServiceReplaceSandboxOrder(
    const std::string &account_id, const std::string &order_id,
    const std::string &idempotency_key, int64_t quantity,
    int64_t units, int32_t nano, int price_type
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1ReplaceOrderRequest>();
    body->setAccountId(account_id);
    //....

    std::function<pplx::task<std::shared_ptr<V1PostOrderResponse>>(const SandboxServiceApi&, std::shared_ptr<V1ReplaceOrderRequest>)> req = &SandboxServiceApi::sandboxServiceReplaceSandboxOrder;
    return MakeRequest<ServiceId::SandboxService>(body, req);

}

ServiceReply<V1SandboxPayInResponse> InvestApiSandboxClient::SandboxServicePayIn(
    const std::string &account_id,
    const std::string &currency,
    const std::string& units, int32_t nano
    ) {
    InitService<ServiceId::SandboxService, SandboxServiceApi>();

    auto body = std::make_shared<V1SandboxPayInRequest>();

    auto money_value = std::make_shared<V1MoneyValue>();
    money_value->setCurrency(currency);
    money_value->setUnits(units);
    money_value->setNano(nano);

    body->setAccountId(account_id);
    body->setAmount(money_value);

    std::function<pplx::task<std::shared_ptr<V1SandboxPayInResponse>>(const SandboxServiceApi&, std::shared_ptr<V1SandboxPayInRequest>)> req = &SandboxServiceApi::sandboxServiceSandboxPayIn;
    return MakeRequest<ServiceId::SandboxService>(body, req);
}

}  // tinkoff_invest_cppsdk
