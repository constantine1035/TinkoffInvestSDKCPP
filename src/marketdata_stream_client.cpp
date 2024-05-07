#include "tinkoff_invest_cppsdk/marketdata_stream_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiMarketdataStreamClient::InvestApiMarketdataStreamClient(const std::string &token)
    : InvestApiBaseClient(token) {
    InitService<ServiceId::MarketDataStreamService, MarketDataStreamServiceApi>();
}

InvestApiMarketdataStreamClient::~InvestApiMarketdataStreamClient() {
}

ServiceReply<Stream_result_of_v1MarketDataResponse>
InvestApiMarketdataStreamClient::MarketDataStreamServiceMarketDataServerSideStream(
    std::shared_ptr<V1MarketDataServerSideStreamRequest> body) const {
    std::function<pplx::task<std::shared_ptr<Stream_result_of_v1MarketDataResponse>>(
        const MarketDataStreamServiceApi &, std::shared_ptr<V1MarketDataServerSideStreamRequest>)>
        req = &MarketDataStreamServiceApi::marketDataStreamServiceMarketDataServerSideStream;
    return MakeRequestAsync<ServiceId::MarketDataStreamService>(req, body);
}

ServiceReply<Stream_result_of_v1MarketDataResponse>
InvestApiMarketdataStreamClient::MarketDataStreamServiceMarketDataStream(
    std::shared_ptr<V1MarketDataRequest> body) const {
    std::function<pplx::task<std::shared_ptr<Stream_result_of_v1MarketDataResponse>>(
        const MarketDataStreamServiceApi &, std::shared_ptr<V1MarketDataRequest>)>
        req = &MarketDataStreamServiceApi::marketDataStreamServiceMarketDataStream;
    return MakeRequestAsync<ServiceId::MarketDataStreamService>(req, body);
}

}  // namespace tinkoff_invest_cppsdk