#pragma once

/*
 * Marketdata_client.h
 *
 * This is a client class that use OperationsStreamServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiOperationsStreamClient : virtual public InvestApiBaseClient {
public:
    explicit InvestApiOperationsStreamClient(const std::string &token, TradingMode trading_mode);

    ~InvestApiOperationsStreamClient() override;

    void OperationsStreamServicePortfolioStream(
        const std::vector<std::string> &accounts,
        std::vector<ServiceReply<V1PortfolioStreamResponse>> &responses, int retry_max = 0,
        std::function<void(const ServiceReply<V1PortfolioStreamResponse> &)> callback = nullptr);

    void OperationsStreamServicePositionsStream(
        const std::vector<std::string> &accounts,
        std::vector<ServiceReply<V1PositionsStreamResponse>> &responses, int retry_max = 0,
        std::function<void(const ServiceReply<V1PositionsStreamResponse> &)> callback = nullptr);
};

}  // namespace tinkoff_invest_cppsdk