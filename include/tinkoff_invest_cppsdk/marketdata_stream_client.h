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

    void MarketDataStreamServiceMarketDataServerSideStream(
        std::shared_ptr<V1MarketDataServerSideStreamRequest> body,
        std::vector<ServiceReply<V1MarketDataResponse>> &responses, int retry_max = 0,
        std::function<void(const ServiceReply<V1MarketDataResponse> &)> callback = nullptr);

    void MarketDataStreamServiceMarketDataStream(
        std::shared_ptr<V1MarketDataRequest> body,
        std::vector<ServiceReply<V1MarketDataResponse>> &responses, int retry_max = 0,
        std::function<void(const ServiceReply<V1MarketDataResponse> &)> callback = nullptr);
};

}  // namespace tinkoff_invest_cppsdk
