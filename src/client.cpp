#include "tinkoff_invest_cppsdk/client.h"

#include "tinkoff_invest_cppsdk/types_and_constants.h"

namespace tinkoff_invest_cppsdk {

InvestApiClient::InvestApiClient(const std::string& token, TradingMode trading_mode)
    : InvestApiBaseClient(token, trading_mode),
      InvestApiInstrumentsClient(token, trading_mode),
      InvestApiMarketdataClient(token, trading_mode),
      InvestApiMarketdataStreamClient(token, trading_mode),
      InvestApiOperationsClient(token, trading_mode),
      InvestApiOperationsStreamClient(token, trading_mode),
      InvestApiOrdersClient(token, trading_mode),
      InvestApiOrdersStreamClient(token, trading_mode),
      InvestApiSandboxClient(token, trading_mode),
      InvestApiStopOrdersClient(token, trading_mode),
      InvestApiUsersClient(token, trading_mode) {

    InitLimiters();
}

InvestApiClient::~InvestApiClient() {
}

}  // namespace tinkoff_invest_cppsdk
