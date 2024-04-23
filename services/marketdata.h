#pragma once

#include "based_service.h"
#include <>
#include "reply.h"
#include "marketdata.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <memory>
#include <string>
#include <vector>

namespace tinkoff_invest_sdk_cpp_market_data_service {

using grpc::Channel;
using tinkoff_invest_sdk_cpp_based_service::BasedService;
using namespace tinkoff::public_::invest::api::contract::v1;

/*
 *
 * Service for obtaining exchange information.
 * 1. Candles.
 * 2. Orderbook
 * 3. Trading status.
 * 4. Last prices.
 *
 */

class MarketData : public BasedService {
public:

    MarketData(std::shared_ptr<Channel> channel, const std::string &token);

    ~MarketData() = default;

    // Requesting historical candlesticks by instrument, asynchronous call.
    ServiceReply GetCandles(const std::string &instrument_id, int64_t from_seconds, int32_t from_nanos,
                            int64_t to_seconds, int32_t to_nanos, CandleInterval interval);

    // Requesting prices of recent transactions on instruments.
    ServiceReply GetLastPrices(const std::vector<std::string> &instruments_id);

    // Obtaining a glass by instrument.
    ServiceReply GetOrderbook(const std::string &instrument_id, int32_t depth);

    // Requesting the trading status of instruments.
    ServiceReply GetTradingStatus(const std::string &instruments_id);

    // Requesting the trading status of instruments.
    ServiceReply GetTradingStatuses(const std::vector<std::string> &instruments_ids);

    // Requesting depersonalized transactions for the last hour.
    ServiceReply GetLastTrades(const std::string &instrument_id, int64_t from_seconds, int32_t from_nanos,
                               int64_t to_seconds, int32_t to_nanos);

    // Requesting the closing prices of a trading session for instruments.
    ServiceReply GetClosePrices(const std::vector<std::string> &instruments_ids);

protected:
    std::unique_ptr<MarketDataService::Stub> service_;
};

} // tinkoff_invest_sdk_cpp_market_data_service
