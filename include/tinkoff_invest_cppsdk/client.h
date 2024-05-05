#pragma once

#include "tinkoff_invest_cppsdk/marketdata_client.h"
#include "tinkoff_invest_cppsdk/marketdata_stream_client.h"
#include "tinkoff_invest_cppsdk/orders_client.h"
#include "tinkoff_invest_cppsdk/orders_stream_client.h"
#include "tinkoff_invest_cppsdk/sandbox_client.h"
#include "tinkoff_invest_cppsdk/users_client.h"

#include "tinkoffinvestsdkcpp_export.h"

/*
 * client.h
 *
 * This is a client class that use all services functions.
 */

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using tinkoff_invest_cppsdk::InvestApiSandboxClient;

class InvestApiClient : public InvestApiMarketdataClient,
                        public InvestApiMarketdataStreamClient,
                        public InvestApiOrdersClient,
                        public InvestApiOrdersStreamClient,
                        public InvestApiSandboxClient,
                        public InvestApiUsersClient {
public:
    inline explicit InvestApiClient(const std::string& token) :
          InvestApiMarketdataClient(token),
          InvestApiMarketdataStreamClient(token),
          InvestApiOrdersClient(token),
          InvestApiOrdersStreamClient(token),
          InvestApiSandboxClient(token),
          InvestApiUsersClient(token)
        {
    }

    inline ~InvestApiClient() override {
    }

};

}  // namespace tinkoff_invest_cppsdk
