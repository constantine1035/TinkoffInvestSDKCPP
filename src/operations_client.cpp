#include "tinkoff_invest_cppsdk/operations_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiOperationsClient::InvestApiOperationsClient(const std::string &token)
    : InvestApiBaseClient(token) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
}

InvestApiOperationsClient::~InvestApiOperationsClient() {
}

ServiceReply<V1OperationsResponse> InvestApiOperationsClient::GetOperations(
    std::string account_id, int64_t fromseconds, int32_t fromnanos, int64_t toseconds,
    int32_t tonanos, std::string figi, const std::shared_ptr<V1OperationState> state) const {

    auto body = std::make_shared<V1OperationsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    //to.from_milliseconds();
    //from.from_milliseconds();
    body->setFigi(figi);
    body->setAccountId(account_id);
    body->setState(state);
    body->setFrom(from);
    body->setTo(to);

    std::function<pplx::task<std::shared_ptr<V1OperationsResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1OperationsRequest>)>
        req = &OperationsServiceApi::operationsServiceGetOperations;
    return MakeRequestAsync<ServiceId::OperationsService>(req, body);
};

ServiceReply<V1PortfolioResponse> InvestApiOperationsClient::GetPortfolio(
    std::string account_id, const std::shared_ptr<PortfolioRequestCurrencyRequest> currency) const {

    auto body = std::make_shared<V1PortfolioRequest>();
    body->setAccountId(account_id);
    body->setCurrency(currency);

    std::function<pplx::task<std::shared_ptr<V1PortfolioResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1PortfolioRequest>)>
        req = &OperationsServiceApi::operationsServiceGetPortfolio;
    return MakeRequestAsync<ServiceId::OperationsService>(req, body);
};

ServiceReply<V1PositionsResponse> InvestApiOperationsClient::GetPositions(std::string account_id) const {

    auto body = std::make_shared<V1PositionsRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1PositionsResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1PositionsRequest>)>
        req = &OperationsServiceApi::operationsServiceGetPositions;
    return MakeRequestAsync<ServiceId::OperationsService>(req, body);
};

ServiceReply<V1WithdrawLimitsResponse> InvestApiOperationsClient::GetWithdrawLimits(
    std::string account_id) const {

    auto body = std::make_shared<V1WithdrawLimitsRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1WithdrawLimitsResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1WithdrawLimitsRequest>)>
        req = &OperationsServiceApi::operationsServiceGetWithdrawLimits;
    return MakeRequestAsync<ServiceId::OperationsService>(req, body);
};

ServiceReply<V1BrokerReportResponse> InvestApiOperationsClient::GetBrokerReport(
    const std::shared_ptr<V1GenerateBrokerReportRequest> generate_broker_request,
    const std::shared_ptr<V1GetBrokerReportRequest> get_broker_request) const {

    auto body = std::make_shared<V1BrokerReportRequest>();

    body->setGenerateBrokerReportRequest(generate_broker_request);
    body->setGetBrokerReportRequest(get_broker_request);

    std::function<pplx::task<std::shared_ptr<V1BrokerReportResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1BrokerReportRequest>)>
        req = &OperationsServiceApi::operationsServiceGetBrokerReport;
    return MakeRequestAsync<ServiceId::OperationsService>(req, body);
};

ServiceReply<V1GetDividendsForeignIssuerResponse>
InvestApiOperationsClient::GetDividendsForeignIssuer(
    const std::shared_ptr<V1GenerateDividendsForeignIssuerReportRequest>
        generate_div_foreign_issuer_report,
    const std::shared_ptr<V1GetDividendsForeignIssuerReportRequest> get_div_foreign_issuer_report) const {

    auto body = std::make_shared<V1GetDividendsForeignIssuerRequest>();

    body->setGenerateDivForeignIssuerReport(generate_div_foreign_issuer_report);
    body->setGetDivForeignIssuerReport(get_div_foreign_issuer_report);

    std::function<pplx::task<std::shared_ptr<V1GetDividendsForeignIssuerResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1GetDividendsForeignIssuerRequest>)>
        req = &OperationsServiceApi::operationsServiceGetDividendsForeignIssuer;
    return MakeRequestAsync<ServiceId::OperationsService>(req, body);
};

ServiceReply<V1GetOperationsByCursorResponse> InvestApiOperationsClient::GetOperationsByCursor(
    std::string account_id, std::string instrument_id, int64_t fromseconds, int32_t fromnanos,
    int64_t toseconds, int32_t tonanos, std::string cursor, int32_t limit,
    std::vector<std::shared_ptr<V1OperationType>> operation_types, V1OperationState state,
    bool without_comissions, bool without_trades, bool without_overnights) const {

    auto body = std::make_shared<V1GetOperationsByCursorRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    //to.from_milliseconds();
    //from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setAccountId(account_id);
    body->setInstrumentId(instrument_id);
    body->setCursor(cursor);
    body->setLimit(limit);
    body->setWithoutCommissions(without_comissions);
    body->setWithoutOvernights(without_overnights);
    body->setWithoutTrades(without_trades);
    body->setOperationTypes(operation_types);

    std::function<pplx::task<std::shared_ptr<V1GetOperationsByCursorResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1GetOperationsByCursorRequest>)>
        req = &OperationsServiceApi::operationsServiceGetOperationsByCursor;
    return MakeRequestAsync<ServiceId::OperationsService>(req, body);
};

}  // namespace tinkoff_invest_cppsdk
