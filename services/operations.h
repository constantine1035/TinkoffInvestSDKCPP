#pragma once

#include "based_service.h"
#include "common.pb.h"
#include <grpc++/grpc++.h>
#include "operations.pb.h"
#include "operations.grpc.pb.h"
#include "reply.h"

using grpc::Channel;
using tinkoff_invest_sdk_cpp_based_service::BasedService;

using namespace tinkoff::public_::invest::api::contract::v1;

class Operations : public BasedService {
public:
    Operations(std::shared_ptr<Channel> channel, const std::string &token);

    ~Operations() = default;

    /// Метод получения списка операций по счёту.При работе с данным методом необходимо учитывать особенности взаимодействия с данным методом.
    ServiceReply GetOperations(std::string account_id, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos, std::string figi, OperationState state = OPERATION_STATE_UNSPECIFIED);

    /// Метод получения портфеля по счёту.
    ServiceReply GetPortfolio(std::string account_id, PortfolioRequest_CurrencyRequest currency);

    /// Метод получения списка позиций по счёту.
    ServiceReply GetPositions(std::string account_id);

    /// Метод получения доступного остатка для вывода средств.
    ServiceReply GetWithdrawLimits(std::string account_id);

    /// Метод получения брокерского отчёта
    ServiceReply GetBrokerReport(GenerateBrokerReportRequest generate_broker_request, GetBrokerReportRequest get_broker_request);

    /// Метод получения отчёта "Справка о доходах за пределами РФ".
    ServiceReply GetDividendsForeignIssuer(GenerateDividendsForeignIssuerReportRequest generate_div_foreign_issuer_report, GetDividendsForeignIssuerReportRequest get_div_foreign_issuer_report);

    /// Метод получения списка операций по счёту с пагинацией. При работе с данным методом необходимо учитывать особенности взаимодействия с данным методом.
    ServiceReply GetOperationsByCursor(std::string account_id, std::string instrument_id, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos, std::string cursor, int32_t limit, std::vector<OperationType> operation_types, OperationState state, bool without_comissions, bool without_trades, bool without_overnights);

private:
    std::unique_ptr<OperationsService::Stub> operations_service_;
};

class OperationsStream : public BasedService {
public:
    OperationsStream(std::shared_ptr<Channel> channel, const std::string &token);

    ~OperationsStream() = default;

    /// Server-side stream обновлений портфеля
    ServiceReply PortfolioStream(std::vector<std::string> accounts);

    /// Server-side stream обновлений информации по изменению позиций портфеля
    ServiceReply PositionsStream(std::vector<std::string> accounts);

private:
    std::unique_ptr<OperationsStreamService::Stub> operations_stream_service_;
};