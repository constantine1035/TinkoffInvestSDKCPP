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
    std::shared_ptr<V1MarketDataServerSideStreamRequest> body, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<Stream_result_of_v1MarketDataResponse> &)> callback)
    const {

    std::function<pplx::task<std::shared_ptr<Stream_result_of_v1MarketDataResponse>>(
        const MarketDataStreamServiceApi &, std::shared_ptr<V1MarketDataServerSideStreamRequest>)>
        req = &MarketDataStreamServiceApi::marketDataStreamServiceMarketDataServerSideStream;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::MarketDataService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::MarketDataService>(req, body, retry_max, callback);
}

ServiceReply<Stream_result_of_v1MarketDataResponse>
InvestApiMarketdataStreamClient::MarketDataStreamServiceMarketDataStream(
    std::shared_ptr<V1MarketDataRequest> body, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<Stream_result_of_v1MarketDataResponse> &)> callback)
    const {

    std::function<pplx::task<std::shared_ptr<Stream_result_of_v1MarketDataResponse>>(
        const MarketDataStreamServiceApi &, std::shared_ptr<V1MarketDataRequest>)>
        req = &MarketDataStreamServiceApi::marketDataStreamServiceMarketDataStream;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::MarketDataService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::MarketDataService>(req, body, retry_max, callback);
}

}  // namespace tinkoff_invest_cppsdk