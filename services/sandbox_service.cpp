#include "sandbox_service.h"

namespace tinkoff_invest_sdk_cpp_sandbox_service {

using grpc::Status;
using google::protobuf::Timestamp;

static Timestamp MakeTimestamp(int64_t seconds, int32_t nanos) {
    Timestamp timestamp;
    timestamp.set_seconds(seconds);
    timestamp.set_nanos(nanos);
    return timestamp;
}

Sandbox::Sandbox(const std::string &token, std::shared_ptr<Channel> channel) :
    BasedService(token),
    service_(SandboxService::NewStub(channel)) {
}

ServiceReply Sandbox::OpenSandboxAccount(const std::string &account_id) {
    OpenSandboxAccountRequest request;
    request.set_name(account_id);
    OpenSandboxAccountResponse reply;
    Status status = service_->OpenSandboxAccount(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<OpenSandboxAccountResponse>(status, reply);
}

ServiceReply Sandbox::GetSandboxAccounts() {
    GetAccountsRequest request;
    GetAccountsResponse reply;
    Status status = service_->GetSandboxAccounts(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetAccountsResponse>(status, reply);
}

ServiceReply Sandbox::CloseSandboxAccount(const std::string &account_id) {
    CloseSandboxAccountRequest request;
    request.set_account_id(account_id);
    CloseSandboxAccountResponse reply;
    Status status = service_->CloseSandboxAccount(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<CloseSandboxAccountResponse>(status, reply);
}

ServiceReply Sandbox::PostSandboxOrder(const std::string &account_id,
                                       const std::string &order_id,
                                       const std::string &instrument_id,
                                       int64_t quantity,
                                       int64_t units,
                                       int32_t nano,
                                       OrderDirection direction,
                                       OrderType order_type) {
    PostOrderRequest request;

    auto price = new Quotation();
    price->set_units(units);
    price->set_nano(nano);

    request.set_account_id(account_id);
    request.set_order_id(order_id);
    request.set_instrument_id(instrument_id);
    request.set_quantity(quantity);
    request.set_allocated_price(price);
    request.set_direction(direction);
    request.set_order_type(order_type);

    PostOrderResponse reply;
    Status status = service_->PostSandboxOrder(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<PostOrderResponse>(status, reply);
}

ServiceReply Sandbox::ReplaceSandboxOrder(const std::string &account_id,
                                          const std::string &order_id,
                                          const std::string &idempotency_key,
                                          int64_t quantity,
                                          int64_t units,
                                          int32_t nano,
                                          PriceType price_type) {
    ReplaceOrderRequest request;

    auto price = new Quotation();
    price->set_units(units);
    price->set_nano(nano);

    request.set_account_id(account_id);
    request.set_order_id(order_id);
    request.set_idempotency_key(idempotency_key);
    request.set_quantity(quantity);
    request.set_allocated_price(price);
    request.set_price_type(price_type);

    PostOrderResponse reply;
    Status status = service_->ReplaceSandboxOrder(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<PostOrderResponse>(status, reply);
}

ServiceReply Sandbox::GetSandboxOrders(const std::string &account_id) {
    GetOrdersRequest request;
    request.set_account_id(account_id);
    GetOrdersResponse reply;
    Status status = service_->GetSandboxOrders(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetOrdersResponse>(status, reply);
}

ServiceReply Sandbox::CancelSandboxOrder(const std::string &account_id, const std::string &order_id) {
    CancelOrderRequest request;
    request.set_account_id(account_id);
    request.set_order_id(order_id);
    CancelOrderResponse reply;
    Status status = service_->CancelSandboxOrder(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<CancelOrderResponse>(status, reply);
}

ServiceReply Sandbox::GetSandboxOrderState(const std::string &account_id, const std::string &order_id) {
    GetOrderStateRequest request;
    request.set_account_id(account_id);
    request.set_order_id(order_id);
    OrderState reply;
    Status status = service_->GetSandboxOrderState(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<OrderState>(status, reply);
}

ServiceReply Sandbox::GetSandboxPositions(const std::string &account_id) {
    PositionsRequest request;
    request.set_account_id(account_id);
    PositionsResponse reply;
    Status status = service_->GetSandboxPositions(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<PositionsResponse>(status, reply);
}

ServiceReply Sandbox::GetSandboxOperations(const std::string &account_id,
                                           const std::string &figi,
                                           int64_t from_seconds,
                                           int32_t from_nanos,
                                           int64_t to_seconds,
                                           int32_t to_nanos,
                                           OperationState state) {
    OperationsRequest request;

    auto from = new Timestamp(MakeTimestamp(from_seconds, from_nanos));
    auto to = new Timestamp(MakeTimestamp(to_seconds, to_nanos));

    request.set_account_id(account_id);
    request.set_figi(figi);
    request.set_allocated_from(from);
    request.set_allocated_to(to);
    request.set_state(state);

    OperationsResponse reply;
    Status status = service_->GetSandboxOperations(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<OperationsResponse>(status, reply);
}

ServiceReply Sandbox::GetSandboxOperationsByCursor(const std::string &account_id,
                                                   const std::string &instrument_id,
                                                   int64_t from_seconds,
                                                   int32_t from_nanos,
                                                   int64_t to_seconds,
                                                   int32_t to_nanos,
                                                   const std::string &cursor,
                                                   int32_t limit,
                                                   const std::vector<OperationType> &operation_types,
                                                   OperationState state,
                                                   bool without_commissions,
                                                   bool without_trades,
                                                   bool without_overnights) {
    GetOperationsByCursorRequest request;

    auto from = new Timestamp(MakeTimestamp(from_seconds, from_nanos));
    auto to = new Timestamp(MakeTimestamp(to_seconds, to_nanos));

    request.set_account_id(account_id);
    request.set_instrument_id(instrument_id);
    request.set_allocated_from(from);
    request.set_allocated_to(to);
    request.set_cursor(cursor);
    request.set_limit(limit);
    for (size_t i = 0; i < operation_types.size(); ++i) {
        request.set_operation_types(i, operation_types[i]);
    }
    request.set_state(state);
    request.set_without_commissions(without_commissions);
    request.set_without_trades(without_trades);
    request.set_without_overnights(without_overnights);


    GetOperationsByCursorResponse reply;
    Status status = service_->GetSandboxOperationsByCursor(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetOperationsByCursorResponse>(status, reply);
}

ServiceReply Sandbox::GetSandboxPortfolio(const std::string &account_id, PortfolioRequest_CurrencyRequest currency) {
    PortfolioRequest request;
    request.set_account_id(account_id);
    request.set_currency(currency);
    PortfolioResponse reply;
    Status status = service_->GetSandboxPortfolio(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<PortfolioResponse>(status, reply);
}

ServiceReply Sandbox::SandboxPayIn(const std::string &account_id, const std::string &currency, int64_t units, int32_t nano) {
    SandboxPayInRequest request;

    MoneyValue *amount = new MoneyValue();
    amount->set_currency(currency);
    amount->set_units(units);
    amount->set_nano(nano);

    request.set_account_id(account_id);
    request.set_allocated_amount(amount);

    SandboxPayInResponse reply;
    Status status = service_->SandboxPayIn(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<SandboxPayInResponse>(status, reply);
}

ServiceReply Sandbox::GetSandboxWithdrawLimits(const std::string &account_id) {
    WithdrawLimitsRequest request;
    request.set_account_id(account_id);
    WithdrawLimitsResponse reply;
    Status status = service_->GetSandboxWithdrawLimits(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<WithdrawLimitsResponse>(status, reply);
}

} // tinkoff_invest_sdk_cpp_sandbox_service
