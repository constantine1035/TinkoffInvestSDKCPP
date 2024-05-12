#pragma once

/*
 * Marketdata_client.h
 *
 * This is a client class that use OperationsStreamServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiOperationsStreamClient : public InvestApiBaseClient {
public:
    explicit InvestApiOperationsStreamClient(const std::string& token);

    ~InvestApiOperationsStreamClient() override;

    ServiceReply<Stream_result_of_v1PortfolioStreamResponse> OperationsStreamServicePortfolioStream(
        const std::vector<std::string>& accounts);

    ServiceReply<Stream_result_of_v1PositionsStreamResponse> OperationsStreamServicePositionsStream(
        const std::vector<std::string>& accounts);
};

}  // namespace tinkoff_invest_cppsdk