#include "tinkoff_invest_cppsdk/marketdata_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiMarketdataClient::InvestApiMarketdataClient(const std::string &token) : InvestApiBaseClient(token) {
}

InvestApiMarketdataClient::~InvestApiMarketdataClient() {
}

ServiceReply<V1GetCandlesResponse> InvestApiMarketdataClient::MarketDataServiceGetCandles(
    const std::string &instrument_id, int64_t from_seconds, int32_t from_nanos,
    int64_t to_seconds, int32_t to_nanos, std::shared_ptr<V1CandleInterval> interval
    ) {
    InitService<ServiceId::MarketDataService, MarketDataServiceApi>();

    auto body = std::make_shared<V1GetCandlesRequest>();

    body->setInstrumentId(instrument_id);
    //body->setFrom();
    //body->setTo();
    body->setInterval(interval);

    std::function<pplx::task<std::shared_ptr<V1GetCandlesResponse>>(const MarketDataServiceApi&, std::shared_ptr<V1GetCandlesRequest>)> req = &MarketDataServiceApi::marketDataServiceGetCandles;
    return MakeRequest<ServiceId::MarketDataService>(body, req);
}

ServiceReply<V1GetClosePricesResponse> InvestApiMarketdataClient::MarketDataServiceGetClosePrices(
    const std::vector<std::string> &instruments_ids
    ) {
    InitService<ServiceId::MarketDataService, MarketDataServiceApi>();

    auto body = std::make_shared<V1GetClosePricesRequest>();

    //body->setInstruments(instruments_ids);

    std::function<pplx::task<std::shared_ptr<V1GetClosePricesResponse>>(const MarketDataServiceApi&, std::shared_ptr<V1GetClosePricesRequest>)> req = &MarketDataServiceApi::marketDataServiceGetClosePrices;
    return MakeRequest<ServiceId::MarketDataService>(body, req);
}

ServiceReply<V1GetLastPricesResponse> InvestApiMarketdataClient::MarketDataServiceGetLastPrices(
    const std::vector<std::string> &instrument_id) {
    InitService<ServiceId::MarketDataService, MarketDataServiceApi>();

    auto body = std::make_shared<V1GetLastPricesRequest>();
    body->setInstrumentId(instrument_id);

    std::function<pplx::task<std::shared_ptr<V1GetLastPricesResponse>>(const MarketDataServiceApi&, std::shared_ptr<V1GetLastPricesRequest>)> req = &MarketDataServiceApi::marketDataServiceGetLastPrices;
    return MakeRequest<ServiceId::MarketDataService>(body, req);
}

ServiceReply<V1GetLastTradesResponse> InvestApiMarketdataClient::MarketDataServiceGetLastTrades(
    const std::string &instrument_id, int64_t from_seconds, int32_t from_nanos,
    int64_t to_seconds, int32_t to_nanos
    ) {
    InitService<ServiceId::MarketDataService, MarketDataServiceApi>();

    auto body = std::make_shared<V1GetLastTradesRequest>();

    body->setInstrumentId(instrument_id);
    //body->setFrom();
    //body->setTo();

    std::function<pplx::task<std::shared_ptr<V1GetLastTradesResponse>>(const MarketDataServiceApi&, std::shared_ptr<V1GetLastTradesRequest>)> req = &MarketDataServiceApi::marketDataServiceGetLastTrades;
    return MakeRequest<ServiceId::MarketDataService>(body, req);
}

ServiceReply<V1GetOrderBookResponse> InvestApiMarketdataClient::MarketDataServiceGetOrderBook(
    const std::string &instrument_id, int32_t depth
    ) {
    InitService<ServiceId::MarketDataService, MarketDataServiceApi>();

    auto body = std::make_shared<V1GetOrderBookRequest>();

    body->setInstrumentId(instrument_id);
    body->setDepth(depth);

    std::function<pplx::task<std::shared_ptr<V1GetOrderBookResponse>>(const MarketDataServiceApi&, std::shared_ptr<V1GetOrderBookRequest>)> req = &MarketDataServiceApi::marketDataServiceGetOrderBook;
    return MakeRequest<ServiceId::MarketDataService>(body, req);
}

// MarketDataServiceGetTechAnalysis

ServiceReply<V1GetTradingStatusResponse> InvestApiMarketdataClient::MarketDataServiceGetTradingStatus(
    const std::string &instrument_id
    ) {
    InitService<ServiceId::MarketDataService, MarketDataServiceApi>();

    auto body = std::make_shared<V1GetTradingStatusRequest>();

    body->setInstrumentId(instrument_id);

    std::function<pplx::task<std::shared_ptr<V1GetTradingStatusResponse>>(const MarketDataServiceApi&, std::shared_ptr<V1GetTradingStatusRequest>)> req = &MarketDataServiceApi::marketDataServiceGetTradingStatus;
    return MakeRequest<ServiceId::MarketDataService>(body, req);
}

ServiceReply<V1GetTradingStatusesResponse> InvestApiMarketdataClient::MarketDataServiceGetTradingStatuses(
    const std::vector<std::string> &instruments_ids
    ) {
    InitService<ServiceId::MarketDataService, MarketDataServiceApi>();

    auto body = std::make_shared<V1GetTradingStatusesRequest>();

    body->setInstrumentId(instruments_ids);

    std::function<pplx::task<std::shared_ptr<V1GetTradingStatusesResponse>>(const MarketDataServiceApi&, std::shared_ptr<V1GetTradingStatusesRequest>)> req = &MarketDataServiceApi::marketDataServiceGetTradingStatuses;
    return MakeRequest<ServiceId::MarketDataService>(body, req);
}

}  // tinkoff_invest_cppsdk
