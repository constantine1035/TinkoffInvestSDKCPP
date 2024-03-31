#pragma once

#include "based_service.h"
#include "protofiles/sandbox.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <memory>
#include <string>

namespace tinkoff_invest_sdk_cpp_sandbox_service {

using grpc::Channel;
using tinkoff_invest_sdk_cpp_based_service::BasedService;
using namespace tinkoff::public_::invest::api::contract::v1;

static std::string SandBoxToken() {
    return "sandbox-invest-public-api.tinkoff.ru:443";
}

class Sandbox : BasedService {
public:
    Sandbox(std::shared_ptr<Channel> channel);

    ~Sandbox() = default;

    // Register account.
    ServiceReply OpenSandboxAccount(const std::string &account_id);

    // Get accounts.
    ServiceReply GetSandboxAccounts();

    // Delete account.
    ServiceReply CloseSandboxAccount(const std::string &account_id);

    //
    ServiceReply PostSandboxOrder(); 1111

    //
    ServiceReply ReplaceSandboxOrder(); 1111

    //
    ServiceReply GetSandboxOrders(const std::string &account_id);

    //
    ServiceReply CancelSandboxOrder(const std::string &account_id, const std::string &order_id);

    //
    ServiceReply GetSandboxOrderState(const std::string &account_id, const std::string &order_id);

    //
    ServiceReply GetSandboxPositions(const std::string &account_id);

    //
    ServiceReply GetSandboxOperations(const std::string &account_id, ); 1111

    //
    ServiceReply GetSandboxOperationsByCursor(); 1111

    //
    ServiceReply GetSandboxPortfolio(const std::string &account_id, );

    //
    ServiceReply SandboxPayIn(const std::string &account_id, const std::string &currency, int64_t units, int32_t nano);

    //
    ServiceReply EtSandboxWithdrawLimits(const std::string &account_id, ); 1111

protected:
    std::unique_ptr<SandboxService::Stub> service_;
};

} // tinkoff_invest_sdk_cpp_sandbox_service
