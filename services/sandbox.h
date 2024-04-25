/*
#pragma once

#include "based_service.h"
#include "reply.h"
#include "sandbox.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <memory>
#include <string>

namespace tinkoff_invest_sdk_cpp_sandbox_service {

using grpc::Channel;
using tinkoff_invest_sdk_cpp_based_service::BasedService;
using namespace tinkoff::public_::invest::api::contract::v1;

class Sandbox : public BasedService {
public:
    Sandbox(std::shared_ptr<Channel> channel, const std::string &token);

    ~Sandbox() = default;

    // Open an account.
    ServiceReply OpenSandboxAccount(const std::string &account_id);

    // Receive user accounts.
    ServiceReply GetSandboxAccounts();

    // Close an account.
    ServiceReply CloseSandboxAccount(const std::string &account_id);

    // Request to issue a trade order.
    ServiceReply PostSandboxOrder(const std::string &account_id, const std::string &order_id,
                                  const std::string &instrument_id, int64_t quantity,
                                  int64_t units, int32_t nano, OrderDirection direction,
                                  OrderType order_type);

    // Change the submitted order.
    ServiceReply ReplaceSandboxOrder(const std::string &account_id, const std::string &order_id,
                                     const std::string &idempotency_key, int64_t quantity, int64_t units,
                                     int32_t nano, PriceType price_type);

    // List of active trading orders
    ServiceReply GetSandboxOrders(const std::string &account_id);

    // Cancel a trade order.
    ServiceReply CancelSandboxOrder(const std::string &account_id, const std::string &order_id);

    // Obtain the status of a trade order.
    ServiceReply GetSandboxOrderState(const std::string &account_id, const std::string &order_id);

    // Portfolio positions by account.
    ServiceReply GetSandboxPositions(const std::string &account_id);

    // Receive the list of account transactions.
    ServiceReply GetSandboxOperations(const std::string &account_id, const std::string &figi,
                                      int64_t from_seconds, int32_t from_nanos,
                                      int64_t to_seconds, int32_t to_nanos,
                                      OperationState state);

    // List of account transactions with pagination.
    ServiceReply GetSandboxOperationsByCursor(const std::string &account_id, const std::string &instrument_id,
                                              int64_t from_seconds, int32_t from_nanos,
                                              int64_t to_seconds, int32_t to_nanos,
                                              const std::string &cursor, int32_t limit,
                                              const std::vector<OperationType> &operation_types,
                                              OperationState state, bool without_commissions,
                                              bool without_trades, bool without_overnights);

    // Retrieve the current portfolio for the account.
    ServiceReply GetSandboxPortfolio(const std::string &account_id, PortfolioRequest_CurrencyRequest currency);

    // Pay in.
    ServiceReply SandboxPayIn(const std::string &account_id, const std::string &currency, int64_t units, int32_t nano);

    // Available balance for output.
    ServiceReply GetSandboxWithdrawLimits(const std::string &account_id);

protected:
    std::unique_ptr<SandboxService::Stub> service_;
};

} // tinkoff_invest_sdk_cpp_sandbox_service
*/