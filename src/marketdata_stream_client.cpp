#include "tinkoff_invest_cppsdk/marketdata_stream_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiMarketdataStreamClient::InvestApiMarketdataStreamClient(const std::string &token, TradingMode trading_mode)
    : InvestApiBaseClient(token, trading_mode) {
    InitService<ServiceId::MarketDataStreamService, MarketDataStreamServiceWebSocketApi>();
}

InvestApiMarketdataStreamClient::~InvestApiMarketdataStreamClient() {
}

void InvestApiMarketdataStreamClient::MarketDataStreamServiceMarketDataServerSideStream(
    std::shared_ptr<V1MarketDataServerSideStreamRequest> body,
    std::vector<ServiceReply<V1MarketDataResponse>> &responses, int retry_max,
    std::function<void(const ServiceReply<V1MarketDataResponse> &)> callback) {

    std::function<void(const MarketDataStreamServiceWebSocketApi &,
                       std::shared_ptr<V1MarketDataServerSideStreamRequest>,
                       std::vector<ServiceReply<V1MarketDataResponse>> &)>
        req =
            &MarketDataStreamServiceWebSocketApi::MarketDataStreamServiceMarketDataServerSideStream;
    MakeWebSocketRequest<ServiceId::MarketDataStreamService>(req, body, responses, retry_max,
                                                             callback);
}

void InvestApiMarketdataStreamClient::MarketDataStreamServiceMarketDataStream(
    std::shared_ptr<V1MarketDataRequest> body,
    std::vector<ServiceReply<V1MarketDataResponse>> &responses, int retry_max,
    std::function<void(const ServiceReply<V1MarketDataResponse> &)> callback) {

    std::function<void(const MarketDataStreamServiceWebSocketApi &,
                       std::shared_ptr<V1MarketDataRequest>,
                       std::vector<ServiceReply<V1MarketDataResponse>> &)>
        req = &MarketDataStreamServiceWebSocketApi::MarketDataStreamServiceMarketDataStream;
    MakeWebSocketRequest<ServiceId::MarketDataStreamService>(req, body, responses, retry_max,
                                                             callback);
}

}  // namespace tinkoff_invest_cppsdk