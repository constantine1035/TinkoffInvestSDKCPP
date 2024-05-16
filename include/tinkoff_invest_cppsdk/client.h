#pragma once

#include "tinkoff_invest_cppsdk/instruments_client.h"
#include "tinkoff_invest_cppsdk/marketdata_client.h"
#include "tinkoff_invest_cppsdk/marketdata_stream_client.h"
#include "tinkoff_invest_cppsdk/operations_client.h"
#include "tinkoff_invest_cppsdk/operations_stream_client.h"
#include "tinkoff_invest_cppsdk/orders_client.h"
#include "tinkoff_invest_cppsdk/orders_stream_client.h"
#include "tinkoff_invest_cppsdk/sandbox_client.h"
#include "tinkoff_invest_cppsdk/stoporders_client.h"
#include "tinkoff_invest_cppsdk/users_client.h"

#include "tinkoffinvestsdkcpp_export.h"

/*
 * client.h
 *
 * This is a client class that use all services functions.
 */

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using tinkoff_invest_cppsdk::InvestApiSandboxClient;

class InvestApiClient : public InvestApiInstrumentsClient,
                        public InvestApiMarketdataClient,
                        public InvestApiMarketdataStreamClient,
                        public InvestApiOperationsClient,
                        public InvestApiOperationsStreamClient,
                        public InvestApiOrdersClient,
                        public InvestApiOrdersStreamClient,
                        public InvestApiSandboxClient,
                        public InvestApiStopOrdersClient,
                        public InvestApiUsersClient {
public:
    inline explicit InvestApiClient(const std::string& token, TradingMode trading_mode)
        : InvestApiInstrumentsClient(token, trading_mode),
          InvestApiMarketdataClient(token, trading_mode),
          InvestApiMarketdataStreamClient(token, trading_mode),
          InvestApiOperationsClient(token, trading_mode),
          InvestApiOperationsStreamClient(token, trading_mode),
          InvestApiOrdersClient(token, trading_mode),
          InvestApiOrdersStreamClient(token, trading_mode),
          InvestApiSandboxClient(token, trading_mode),
          InvestApiStopOrdersClient(token, trading_mode),
          InvestApiUsersClient(token, trading_mode) {
    }

    inline ~InvestApiClient() override {
    }
};

}  // namespace tinkoff_invest_cppsdk
