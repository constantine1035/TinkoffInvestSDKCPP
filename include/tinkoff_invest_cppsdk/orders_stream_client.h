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
    explicit InvestApiOrdersStreamClient(const std::string& token);

    ~InvestApiOrdersStreamClient() override;

    ServiceReply<Stream_result_of_v1TradesStreamResponse> OrdersStreamServiceTradesStream(
        const std::vector<std::string>& accounts);
};

}  // namespace tinkoff_invest_cppsdk
