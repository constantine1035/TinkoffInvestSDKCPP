#include "tinkoff_invest_cppsdk/operations_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiOperationsClient::InvestApiOperationsClient(const std::string &token)
    : InvestApiBaseClient(token) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
}

InvestApiOperationsClient::~InvestApiOperationsClient() {
}

ServiceReply<V1OperationsResponse> InvestApiOperationsClient::GetOperations(
    std::string account_id, int64_t fromseconds, int32_t frommilisecs, int64_t toseconds,
    int32_t tomilisecs, std::string figi, const std::shared_ptr<V1OperationState> state, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1OperationsResponse> &)> callback) {

    auto body = std::make_shared<V1OperationsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    to.from_milliseconds(tomilisecs);
    from.from_milliseconds(frommilisecs);
    body->setFigi(figi);
    body->setAccountId(account_id);
    body->setState(state);
    body->setFrom(from);
    body->setTo(to);

    std::function<pplx::task<std::shared_ptr<V1OperationsResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1OperationsRequest>)>
        req = &OperationsServiceApi::operationsServiceGetOperations;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OperationsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OperationsService>(req, body, retry_max, callback);
};

ServiceReply<V1PortfolioResponse> InvestApiOperationsClient::GetPortfolio(
    std::string account_id, const std::shared_ptr<PortfolioRequestCurrencyRequest> currency, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1PortfolioResponse> &)> callback) {

    auto body = std::make_shared<V1PortfolioRequest>();
    body->setAccountId(account_id);
    body->setCurrency(currency);

    std::function<pplx::task<std::shared_ptr<V1PortfolioResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1PortfolioRequest>)>
        req = &OperationsServiceApi::operationsServiceGetPortfolio;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OperationsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OperationsService>(req, body, retry_max, callback);
};

ServiceReply<V1PositionsResponse> InvestApiOperationsClient::GetPositions(std::string account_id, bool is_async_req, int retry_max,
                                                                          std::function<void(const ServiceReply<V1PositionsResponse> &)> callback) {

    auto body = std::make_shared<V1PositionsRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1PositionsResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1PositionsRequest>)>
        req = &OperationsServiceApi::operationsServiceGetPositions;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OperationsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OperationsService>(req, body, retry_max, callback);
};

ServiceReply<V1WithdrawLimitsResponse> InvestApiOperationsClient::GetWithdrawLimits(
    std::string account_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1WithdrawLimitsResponse> &)> callback) {

    auto body = std::make_shared<V1WithdrawLimitsRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1WithdrawLimitsResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1WithdrawLimitsRequest>)>
        req = &OperationsServiceApi::operationsServiceGetWithdrawLimits;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OperationsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OperationsService>(req, body, retry_max, callback);
};

ServiceReply<V1BrokerReportResponse> InvestApiOperationsClient::GetBrokerReport(
    const std::shared_ptr<V1GenerateBrokerReportRequest> generate_broker_request,
    const std::shared_ptr<V1GetBrokerReportRequest> get_broker_request, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1BrokerReportResponse> &)> callback) {

    auto body = std::make_shared<V1BrokerReportRequest>();

    body->setGenerateBrokerReportRequest(generate_broker_request);
    body->setGetBrokerReportRequest(get_broker_request);

    std::function<pplx::task<std::shared_ptr<V1BrokerReportResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1BrokerReportRequest>)>
        req = &OperationsServiceApi::operationsServiceGetBrokerReport;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OperationsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OperationsService>(req, body, retry_max, callback);
};

ServiceReply<V1GetDividendsForeignIssuerResponse>
InvestApiOperationsClient::GetDividendsForeignIssuer(
    const std::shared_ptr<V1GenerateDividendsForeignIssuerReportRequest>
        generate_div_foreign_issuer_report,
    const std::shared_ptr<V1GetDividendsForeignIssuerReportRequest> get_div_foreign_issuer_report, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1GetDividendsForeignIssuerResponse> &)> callback) {

    auto body = std::make_shared<V1GetDividendsForeignIssuerRequest>();

    body->setGenerateDivForeignIssuerReport(generate_div_foreign_issuer_report);
    body->setGetDivForeignIssuerReport(get_div_foreign_issuer_report);

    std::function<pplx::task<std::shared_ptr<V1GetDividendsForeignIssuerResponse>>(
        const OperationsServiceApi &, std::shared_ptr<V1GetDividendsForeignIssuerRequest>)>
        req = &OperationsServiceApi::operationsServiceGetDividendsForeignIssuer;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OperationsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OperationsService>(req, body, retry_max, callback);
};

ServiceReply<V1GetOperationsByCursorResponse> InvestApiOperationsClient::GetOperationsByCursor(
    std::string account_id, std::string instrument_id, int64_t fromseconds, int32_t frommilisecs,
    int64_t toseconds, int32_t tomilisecs, std::string cursor, int32_t limit,
    std::vector<std::shared_ptr<V1OperationType>> operation_types, V1OperationState state,
    bool without_comissions, bool without_trades, bool without_overnights, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1GetOperationsByCursorResponse> &)> callback) {

    auto body = std::make_shared<V1GetOperationsByCursorRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    to.from_milliseconds(tomilisecs);
    from.from_milliseconds(frommilisecs);
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
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OperationsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OperationsService>(req, body, retry_max, callback);
};

}  // namespace tinkoff_invest_cppsdk
