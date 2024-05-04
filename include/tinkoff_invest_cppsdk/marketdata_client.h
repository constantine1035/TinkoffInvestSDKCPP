#pragma once

/*
 * Marketdata_client.h
 *
 * This is a client class that use MarketDataServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiMarketdataClient : public InvestApiBaseClient {
public:
    explicit InvestApiMarketdataClient(const std::string& token);

    ~InvestApiMarketdataClient() override;

    ServiceReply<V1GetCandlesResponse> MarketDataServiceGetCandles(
        const std::string &instrument_id, int64_t from_seconds, int32_t from_nanos,
        int64_t to_seconds, int32_t to_nanos, std::shared_ptr<V1CandleInterval> interval
        );
    
    ServiceReply<V1GetClosePricesResponse> MarketDataServiceGetClosePrices(
        const std::vector<std::string> &instruments_ids
        );
    
    ServiceReply<V1GetLastPricesResponse> MarketDataServiceGetLastPrices(
        const std::vector<std::string> &instrument_id
        );
    
    ServiceReply<V1GetLastTradesResponse> MarketDataServiceGetLastTrades(
        const std::string &instrument_id, int64_t from_seconds,
        int32_t from_nanos, int64_t to_seconds, int32_t to_nanos
        );
    
    ServiceReply<V1GetOrderBookResponse> MarketDataServiceGetOrderBook(
        const std::string &instrument_id, int32_t depth
        );
    
    ServiceReply<V1GetTechAnalysisResponse> MarketDataServiceGetTechAnalysis();
    
    ServiceReply<V1GetTradingStatusResponse> MarketDataServiceGetTradingStatus(
        const std::string &instrument_id
        );
    
    ServiceReply<V1GetTradingStatusesResponse> MarketDataServiceGetTradingStatuses(
        const std::vector<std::string> &instruments_ids
        );

};

}  // tinkoff_invest_cppsdk