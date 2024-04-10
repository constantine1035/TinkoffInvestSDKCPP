#include "operations.h"

Operations::Operations(std::shared_ptr<Channel> channel, const std::string &token) :
    BasedService(token)
    ,operations_service_(OperationsService::NewStub(channel))
{}

ServiceReply Operations::GetOperations(std::string account_id, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos, std::string figi, OperationState state) {
    OperationsRequest request;
    OperationsResponse response;
    google::protobuf::Timestamp from;
    google::protobuf::Timestamp to;
    from.set_seconds(fromseconds);
    from.set_nanos(fromnanos);
    to.set_seconds(toseconds);
    to.set_nanos(tonanos);
    request.set_account_id(account_id);
    request.set_allocated_from(&from);
    request.set_allocated_to(&to);
    request.set_state(state);
    request.set_figi(figi);
    Status status = operations_service_->GetOperations(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<OperationsResponse>(status, response);
}

ServiceReply Operations::GetPortfolio(std::string account_id, PortfolioRequest_CurrencyRequest currency) {
    PortfolioRequest request;
    PortfolioResponse response;
    request.set_account_id(account_id);
    request.set_currency(currency);
    Status status = operations_service_->GetPortfolio(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<PortfolioResponse>(status, response);
}

ServiceReply Operations::GetPositions(std::string account_id) {
    PositionsRequest request;
    PositionsResponse response;
    request.set_account_id(account_id);
    Status status = operations_service_->GetPositions(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<PositionsResponse>(status, response);
}

ServiceReply Operations::GetWithdrawLimits(std::string account_id) {
    WithdrawLimitsRequest request;
    WithdrawLimitsResponse response;
    request.set_account_id(account_id);
    Status status = operations_service_->GetWithdrawLimits(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<WithdrawLimitsResponse>(status, response);
}

ServiceReply Operations::GetBrokerReport(GenerateBrokerReportRequest generate_broker_report_request, GetBrokerReportRequest get_broker_report_request) {
    BrokerReportRequest request;
    BrokerReportResponse response;
    request.set_allocated_generate_broker_report_request(&generate_broker_report_request);
    request.set_allocated_get_broker_report_request(&get_broker_report_request);
    Status status = operations_service_->GetBrokerReport(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<BrokerReportResponse>(status, response);
}

ServiceReply Operations::GetDividendsForeignIssuer(GenerateDividendsForeignIssuerReportRequest generate_div_foreign_issuer_report, GetDividendsForeignIssuerReportRequest get_div_foreign_issuer_report) {
    GetDividendsForeignIssuerRequest request;
    GetDividendsForeignIssuerResponse response;
    request.set_allocated_generate_div_foreign_issuer_report(&generate_div_foreign_issuer_report);
    request.set_allocated_get_div_foreign_issuer_report(&get_div_foreign_issuer_report);
    Status status = operations_service_->GetDividendsForeignIssuer(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetDividendsForeignIssuerResponse>(status, response);
}

ServiceReply Operations::GetOperationsByCursor(std::string account_id, std::string instrument_id, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos, std::string cursor, int32_t limit, std::vector<OperationType> operation_types, OperationState state, bool without_comissions, bool without_trades, bool without_overnights) {
    GetOperationsByCursorRequest request;
    GetOperationsByCursorResponse response;
    google::protobuf::Timestamp from;
    google::protobuf::Timestamp to;
    from.set_seconds(fromseconds);
    from.set_nanos(fromnanos);
    to.set_seconds(toseconds);
    to.set_nanos(tonanos);
    request.set_account_id(account_id);
    request.set_instrument_id(instrument_id);
    request.set_allocated_from(&from);
    request.set_allocated_to(&to);
    request.set_cursor(cursor);
    request.set_limit(limit);
    for (const auto &operation_type : operation_types) {
        request.add_operation_types(operation_type);
    }
    request.set_state(state);
    request.set_without_commissions(without_comissions);
    request.set_without_trades(without_trades);
    request.set_without_overnights(without_overnights);
    Status status = operations_service_->GetOperationsByCursor(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetOperationsByCursorResponse>(status, response);
}