#pragma once

#include "tinkoff_invest_cppsdk/sandbox_client.h"
#include "tinkoff_invest_cppsdk/marketdata_client.h"

#include "tinkoffinvestsdkcpp_export.h"

/*
 * client.h
 *
 *
 */

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using tinkoff_invest_cppsdk::InvestApiSandboxClient;

class InvestApiClient : public InvestApiSandboxClient,
                        public InvestApiMarketdataClient {
public:
    inline explicit InvestApiClient(const std::string& token) :
          InvestApiSandboxClient(token),
          InvestApiMarketdataClient(token) {
    }

    inline ~InvestApiClient() override {
    }

};

}  // namespace tinkoff_invest_cppsdk
