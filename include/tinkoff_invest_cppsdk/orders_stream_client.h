#pragma once

/*
 * Marketdata_client.h
 *
 * This is a client class that use OrdersStreamServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiOrdersStreamClient : public InvestApiBaseClient {
public:
    explicit InvestApiOrdersStreamClient(const std::string& token, TradingMode trading_mode);

    ~InvestApiOrdersStreamClient() override;

    void OrdersStreamServiceTradesStream(
        const std::vector<std::string>& accounts,
        std::vector<ServiceReply<V1TradesStreamResponse>> &responses,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1TradesStreamResponse> &)> callback =
            nullptr);
};

}  // namespace tinkoff_invest_cppsdk
