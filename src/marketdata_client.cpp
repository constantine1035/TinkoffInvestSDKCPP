#include "tinkoff_invest_cppsdk/marketdata_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiMarketdataClient::InvestApiMarketdataClient(const std::string &token) : InvestApiBaseClient(token) {
}

InvestApiMarketdataClient::~InvestApiMarketdataClient() {
}

ServiceReply<V1GetCandlesResponse> InvestApiMarketdataClient::MarketDataServiceGetCandles(
    const std::string &instrument_id, utility::datetime from,
    utility::datetime to, std::shared_ptr<V1CandleInterval> interval
    ) {
    InitService<ServiceId::MarketDataService, MarketDataServiceApi>();

    auto body = std::make_shared<V1GetCandlesRequest>();

    body->setInstrumentId(instrument_id);
    body->setFrom(from);
    body->setTo(to);
    body->setInterval(interval);

    std::function<pplx::task<std::shared_ptr<V1GetCandlesResponse>>(const MarketDataServiceApi&, std::shared_ptr<V1GetCandlesRequest>)> req = &MarketDataServiceApi::marketDataServiceGetCandles;
    return MakeRequest<ServiceId::MarketDataService>(body, req);
}

ServiceReply<V1GetClosePricesResponse> InvestApiMarketdataClient::MarketDataServiceGetClosePrices(
    const std::vector<std::string> &instruments_ids
    ) {
    InitService<ServiceId::MarketDataService, MarketDataServiceApi>();

    auto body = std::make_shared<V1GetClosePricesRequest>();

    size_t n = instruments_ids.size();
    std::vector<std::shared_ptr<V1InstrumentClosePriceRequest>> instruments(n);
    for (size_t i = 0; i < n; ++i) {
        instruments[i] = std::make_shared<V1InstrumentClosePriceRequest>();
        instruments[i]->setInstrumentId(instruments_ids[i]);
    }
    body->setInstruments(instruments);

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
    const std::string &instrument_id,
    utility::datetime from, utility::datetime to
    ) {
    InitService<ServiceId::MarketDataService, MarketDataServiceApi>();

    auto body = std::make_shared<V1GetLastTradesRequest>();
    body->setInstrumentId(instrument_id);
    body->setFrom(from);
    body->setTo(to);

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

ServiceReply<V1GetTechAnalysisResponse> InvestApiMarketdataClient::MarketDataServiceGetTechAnalysis(
    std::shared_ptr<GetTechAnalysisRequestIndicatorType> indicator_type,
    const std::string &instrument_id,
    utility::datetime from, utility::datetime to,
    std::shared_ptr<GetTechAnalysisRequestIndicatorInterval> interval,
    std::shared_ptr<GetTechAnalysisRequestTypeOfPrice> type_of_price,
    int32_t length, const std::string &units, int32_t nano,
    int32_t fast_length, int32_t slow_length, int32_t signal_smoothing) {
    InitService<ServiceId::MarketDataService, MarketDataServiceApi>();

    auto body = std::make_shared<V1GetTechAnalysisRequest>();

    auto quotation = std::make_shared<V1Quotation>();
    quotation->setUnits(units);
    quotation->setNano(nano);
    auto deviation = std::make_shared<GetTechAnalysisRequestDeviation>();
    deviation->setDeviationMultiplier(quotation);

    auto smoothing = std::make_shared<GetTechAnalysisRequestSmoothing>();
    smoothing->setFastLength(fast_length);
    smoothing->setSlowLength(slow_length);
    smoothing->setSignalSmoothing(signal_smoothing);

    body->setIndicatorType(indicator_type);
    body->setInstrumentUid(instrument_id);
    body->setFrom(from);
    body->setTo(to);
    body->setInterval(interval);
    body->setTypeOfPrice(type_of_price);
    body->setLength(length);
    body->setDeviation(deviation);
    body->setSmoothing(smoothing);

    std::function<pplx::task<std::shared_ptr<V1GetTechAnalysisResponse>>(const MarketDataServiceApi&, std::shared_ptr<V1GetTechAnalysisRequest>)> req = &MarketDataServiceApi::marketDataServiceGetTechAnalysis;
    return MakeRequest<ServiceId::MarketDataService>(body, req);
}

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
