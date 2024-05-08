#pragma once

/*
 * Marketdata_client.h
 *
 * This is a client class that use MarketDataStreamServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiMarketdataStreamClient : public InvestApiBaseClient {
public:
    explicit InvestApiMarketdataStreamClient(const std::string &token);

    ~InvestApiMarketdataStreamClient() override;

    ServiceReply<Stream_result_of_v1MarketDataResponse>
    MarketDataStreamServiceMarketDataServerSideStream(
        std::shared_ptr<V1MarketDataServerSideStreamRequest> body, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<Stream_result_of_v1MarketDataResponse> &)> callback =
            nullptr) const;

    ServiceReply<Stream_result_of_v1MarketDataResponse> MarketDataStreamServiceMarketDataStream(
        std::shared_ptr<V1MarketDataRequest> body, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<Stream_result_of_v1MarketDataResponse> &)> callback =
            nullptr) const;
};

}  // namespace tinkoff_invest_cppsdk
