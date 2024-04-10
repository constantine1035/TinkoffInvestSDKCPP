#include "sandbox_service.h"

namespace tinkoff_invest_sdk_cpp_sandbox_service {

using grpc::Status;

Sandbox::Sandbox(std::shared_ptr<Channel> channel) :
    BasedService(SandBoxToken()),
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

// post sandbox order.

// replace sandbox order.

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

// get sandbox operations

// get sandbox operations by cursor

ServiceReply Sandbox::GetSandboxPortfolio(const std::string &account_id) {
    PortfolioRequest request;
    request.set_account_id(account_id);
    PortfolioResponse reply;
    Status status = service_->GetSandboxPortfolio(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<PortfolioResponse>(status, reply);
}

ServiceReply Sandbox::SandboxPayIn(const std::string &account_id, const std::string &currency, int64_t units, int32_t nano) {
    SandboxPayInRequest request;
    request.set_account_id(account_id);
    MoneyValue *amount = new MoneyValue();
    amount->set_currency(currency);
    amount->set_units(units);
    amount->set_nano(nano);
    request.set_allocated_amount(amount);
    SandboxPayInResponse reply;
    Status status = service_->SandboxPayIn(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<SandboxPayInResponse>(status, reply);
}

// et....

} // tinkoff_invest_sdk_cpp_sandbox_service
