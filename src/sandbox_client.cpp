#include "tinkoff_invest_cppsdk/sandbox_client.h"

#include <cpprest/asyncrt_utils.h>

namespace tinkoff_invest_cppsdk {

InvestApiSandboxClient::InvestApiSandboxClient(
    const std::string &token
    ) : InvestApiBaseClient(token) {
}

InvestApiSandboxClient::~InvestApiSandboxClient() {
}

ServiceReply<V1CancelOrderResponse> InvestApiSandboxClient::CancelSandboxOrder(
    const std::string &account_id, const std::string &order_id
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1CancelOrderRequest>();
    body->setAccountId(account_id);
    body->setOrderId(order_id);

    std::function<pplx::task<std::shared_ptr<V1CancelOrderResponse>>(const SandboxServiceApi&, std::shared_ptr<V1CancelOrderRequest>)> req = &SandboxServiceApi::sandboxServiceCancelSandboxOrder;
    return MakeRequest<SandboxServiceApi, V1CancelOrderRequest, V1CancelOrderResponse, ServiceId::SandboxService>(body, req);
}

ServiceReply<Object> InvestApiSandboxClient::CloseSandboxAccountSync(
    const std::string& account_id
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1CloseSandboxAccountRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<Object>>(const SandboxServiceApi&, std::shared_ptr<V1CloseSandboxAccountRequest>)> req = &SandboxServiceApi::sandboxServiceCloseSandboxAccount;
    return MakeRequest<SandboxServiceApi, V1CloseSandboxAccountRequest, Object, ServiceId::SandboxService>(body, req);
}

ServiceReply<V1GetAccountsResponse> InvestApiSandboxClient::GetSandboxAccounts() {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetAccountsResponse>>(const SandboxServiceApi&, std::shared_ptr<Object>)> req = &SandboxServiceApi::sandboxServiceGetSandboxAccounts;
    return MakeRequest<SandboxServiceApi, Object, V1GetAccountsResponse, ServiceId::SandboxService>(body, req);
}

ServiceReply<V1OperationsResponse> InvestApiSandboxClient::GetSandboxOperations(
    const std::string &account_id, const std::string &figi,
    int64_t from_seconds, int32_t from_nanos, int64_t to_seconds,
    int32_t to_nanos, V1OperationState::eV1OperationState state
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1OperationsRequest>();
    auto operation_state = std::make_shared<V1OperationState>();
    operation_state->setValue(state);

    // date

    body->setAccountId(account_id);
    body->setFigi(figi);
    body->setState(operation_state);

    std::function<pplx::task<std::shared_ptr<V1OperationsResponse>>(const SandboxServiceApi&, std::shared_ptr<V1OperationsRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxOperations;
    return MakeRequest<SandboxServiceApi, V1OperationsRequest, V1OperationsResponse, ServiceId::SandboxService>(body, req);
}

ServiceReply<V1GetOperationsByCursorResponse> InvestApiSandboxClient::GetSandboxOperationsByCursor(
    const std::string &account_id, const std::string &instrument_id,
    int64_t from_seconds, int32_t from_nanos, int64_t to_seconds,
    int32_t to_nanos, const std::string &cursor, int32_t limit,
    const int &operation_types, V1OperationState state,
    bool without_commissions, bool without_trades, bool without_overnights
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1GetOperationsByCursorRequest>();
    body->setAccountId(account_id);
    // ....

    std::function<pplx::task<std::shared_ptr<V1GetOperationsByCursorResponse>>(const SandboxServiceApi&, std::shared_ptr<V1GetOperationsByCursorRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxOperationsByCursor;
    return MakeRequest<SandboxServiceApi, V1GetOperationsByCursorRequest, V1GetOperationsByCursorResponse, ServiceId::SandboxService>(body, req);
}

ServiceReply<V1OrderState> InvestApiSandboxClient::GetSandboxOrderState(
    const std::string &account_id, const std::string &order_id
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1GetOrderStateRequest>();
    body->setAccountId(account_id);
    body->setOrderId(order_id);

    std::function<pplx::task<std::shared_ptr<V1OrderState>>(const SandboxServiceApi&, std::shared_ptr<V1GetOrderStateRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxOrderState;
    return MakeRequest<SandboxServiceApi, V1GetOrderStateRequest, V1OrderState, ServiceId::SandboxService>(body, req);
}

ServiceReply<V1GetOrdersResponse> InvestApiSandboxClient::GetSandboxOrders(
    const std::string &account_id
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1GetOrdersRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1GetOrdersResponse>>(const SandboxServiceApi&, std::shared_ptr<V1GetOrdersRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxOrders;
    return MakeRequest<SandboxServiceApi, V1GetOrdersRequest, V1GetOrdersResponse, ServiceId::SandboxService>(body, req);
}

ServiceReply<V1PortfolioResponse> InvestApiSandboxClient::GetSandboxPortfolio(
    const std::string &account_id,
    PortfolioRequestCurrencyRequest::ePortfolioRequestCurrencyRequest currency
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1PortfolioRequest>();
    auto portfolio_request_currency_request = std::make_shared<PortfolioRequestCurrencyRequest>();
    portfolio_request_currency_request->setValue(currency);

    body->setAccountId(account_id);
    body->setCurrency(portfolio_request_currency_request);

    std::function<pplx::task<std::shared_ptr<V1PortfolioResponse>>(const SandboxServiceApi&, std::shared_ptr<V1PortfolioRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxPortfolio;
    return MakeRequest<SandboxServiceApi, V1PortfolioRequest, V1PortfolioResponse, ServiceId::SandboxService>(body, req);
}

ServiceReply<V1PositionsResponse> InvestApiSandboxClient::GetSandboxPositions(const std::string &account_id) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1PositionsRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1PositionsResponse>>(const SandboxServiceApi&, std::shared_ptr<V1PositionsRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxPositions;
    return MakeRequest<SandboxServiceApi, V1PositionsRequest, V1PositionsResponse, ServiceId::SandboxService>(body, req);
}

ServiceReply<V1WithdrawLimitsResponse> InvestApiSandboxClient::GetSandboxWithdrawLimits(
    const std::string &account_id
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1WithdrawLimitsRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1WithdrawLimitsResponse>>(const SandboxServiceApi&, std::shared_ptr<V1WithdrawLimitsRequest>)> req = &SandboxServiceApi::sandboxServiceGetSandboxWithdrawLimits;
    return MakeRequest<SandboxServiceApi, V1WithdrawLimitsRequest, V1WithdrawLimitsResponse, ServiceId::SandboxService>(body, req);
}

ServiceReply<V1OpenSandboxAccountResponse> InvestApiSandboxClient::OpenSandboxAccountSync(
    const std::string &name
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1OpenSandboxAccountRequest>();
    body->setName(name);

    std::function<pplx::task<std::shared_ptr<V1OpenSandboxAccountResponse>>(const SandboxServiceApi&, std::shared_ptr<V1OpenSandboxAccountRequest>)> req = &SandboxServiceApi::sandboxServiceOpenSandboxAccount;
    return MakeRequest<SandboxServiceApi, V1OpenSandboxAccountRequest, V1OpenSandboxAccountResponse, ServiceId::SandboxService>(body, req);
}

ServiceReply<V1PostOrderResponse> InvestApiSandboxClient::PostSandboxOrder(
    const std::string &account_id, const std::string &order_id,
    const std::string &instrument_id, int64_t quantity,
    int64_t units, int32_t nano, int direction, int order_type
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1PostOrderRequest>();
    body->setAccountId(account_id);
    // ...

    std::function<pplx::task<std::shared_ptr<V1PostOrderResponse>>(const SandboxServiceApi&, std::shared_ptr<V1PostOrderRequest>)> req = &SandboxServiceApi::sandboxServicePostSandboxOrder;
    return MakeRequest<SandboxServiceApi, V1PostOrderRequest, V1PostOrderResponse, ServiceId::SandboxService>(body, req);
}

ServiceReply<V1PostOrderResponse> InvestApiSandboxClient::ReplaceSandboxOrder(
    const std::string &account_id, const std::string &order_id,
    const std::string &idempotency_key, int64_t quantity,
    int64_t units, int32_t nano, int price_type
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1ReplaceOrderRequest>();
    body->setAccountId(account_id);
    //....

    std::function<pplx::task<std::shared_ptr<V1PostOrderResponse>>(const SandboxServiceApi&, std::shared_ptr<V1ReplaceOrderRequest>)> req = &SandboxServiceApi::sandboxServiceReplaceSandboxOrder;
    return MakeRequest<SandboxServiceApi, V1ReplaceOrderRequest, V1PostOrderResponse, ServiceId::SandboxService>(body, req);

}

ServiceReply<V1SandboxPayInResponse> InvestApiSandboxClient::PayIn(
    const std::string &account_id,
    const std::string &currency,
    int64_t units, int32_t nano
    ) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1SandboxPayInRequest>();

    auto money_value = std::make_shared<V1MoneyValue>();
    money_value->setCurrency(currency);
  //  money_value->setUnits(units);
    money_value->setNano(nano);

    body->setAccountId(account_id);
    body->setAmount(money_value);

    std::function<pplx::task<std::shared_ptr<V1SandboxPayInResponse>>(const SandboxServiceApi&, std::shared_ptr<V1SandboxPayInRequest>)> req = &SandboxServiceApi::sandboxServiceSandboxPayIn;
    return MakeRequest<SandboxServiceApi, V1SandboxPayInRequest, V1SandboxPayInResponse, ServiceId::SandboxService>(body, req);
}

}  // tinkoff_invest_cppsdk
