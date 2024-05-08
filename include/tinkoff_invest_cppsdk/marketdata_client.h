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
    explicit InvestApiMarketdataClient(const std::string &token);

    ~InvestApiMarketdataClient() override;

    ServiceReply<V1GetCandlesResponse> MarketDataServiceGetCandles(
        const std::string &instrument_id, utility::datetime from, utility::datetime to,
        std::shared_ptr<V1CandleInterval> interval,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetCandlesResponse> &)> callback = nullptr) const;

    ServiceReply<V1GetClosePricesResponse> MarketDataServiceGetClosePrices(
        const std::vector<std::string> &instruments_ids,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetClosePricesResponse> &)> callback = nullptr) const;

    ServiceReply<V1GetLastPricesResponse> MarketDataServiceGetLastPrices(
        const std::vector<std::string> &instrument_id,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetLastPricesResponse> &)> callback = nullptr) const;

    ServiceReply<V1GetLastTradesResponse> MarketDataServiceGetLastTrades(
        const std::string &instrument_id, utility::datetime from, utility::datetime to,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetLastTradesResponse> &)> callback = nullptr) const;

    ServiceReply<V1GetOrderBookResponse> MarketDataServiceGetOrderBook(
        const std::string &instrument_id, int32_t depth,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetOrderBookResponse> &)> callback = nullptr) const;

    ServiceReply<V1GetTechAnalysisResponse> MarketDataServiceGetTechAnalysis(
        std::shared_ptr<GetTechAnalysisRequestIndicatorType> indicator_type,
        const std::string &instrument_id, utility::datetime from, utility::datetime to,
        std::shared_ptr<GetTechAnalysisRequestIndicatorInterval> interval,
        std::shared_ptr<GetTechAnalysisRequestTypeOfPrice> type_of_price, int32_t length,
        const std::string &units, int32_t nano, int32_t fast_length, int32_t slow_length,
        int32_t signal_smoothing,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetTechAnalysisResponse> &)> callback = nullptr) const;

    ServiceReply<V1GetTradingStatusResponse> MarketDataServiceGetTradingStatus(
        const std::string &instrument_id,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetTradingStatusResponse> &)> callback = nullptr) const;

    ServiceReply<V1GetTradingStatusesResponse> MarketDataServiceGetTradingStatuses(
        const std::vector<std::string> &instruments_ids,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetTradingStatusesResponse> &)> callback = nullptr) const;
};

}  // namespace tinkoff_invest_cppsdk