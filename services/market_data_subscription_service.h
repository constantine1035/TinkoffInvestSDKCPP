#pragma once

#include "based_service.h"
#include "protofiles/marketdata.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <utility>

namespace tinkoff_invest_sdk_cpp_market_data_subscription_service {

using grpc::Channel;
using tinkoff_invest_sdk_cpp_based_service::BasedService;
using namespace tinkoff::public_::invest::api::contract::v1;

/*
 *
 * Service for obtaining exchange information in streaming mode.
 * 1. Candles.
 * 2. Orderbook
 * 3. Trading status.
 * 4. Last prices.
 *
 */

class MarketDataStream : public BasedService {
public:

    MarketDataStream(const std::string &token, std::shared_ptr<grpc::Channel> channel);

    ~MarketDataStream() = default;

    // Candle subscription request.
    bool SubscribeCandles(const std::vector<std::pair<std::string,SubscriptionInterval>> &candle_instruments);

    // Candle unsubscription request.
    bool UnSubscribeCandles();

    // Candle subscription request, asynchronous call.
    void SubscribeCandlesAsync(const std::vector<std::pair<std::string,SubscriptionInterval>> &candle_instruments);

    // Candle unsubscription request, asynchronous call.
    void UnSubscribeCandlesAsync();

    // Order book subscription request.
    bool SubscribeOrderBook(const std::vector<std::pair<std::string, int32_t>> &order_book_instruments);

    // Order book unsubscription request.
    bool UnSubscribeOrderBook();

    // Order book subscription request, asynchronous call.
    void SubscribeOrderBookAsync(const std::vector<std::pair<std::string, int32_t>> &order_book_instruments);

    // Order book unsubscription request, asynchronous call.
    bool UnSubscribeOrderBookAsync();

    // subscription request.
    bool SubscribeTrades(const std::vector<std::string> &instruments_ids);

    // unsubscription request.
    bool UnSubscribeTrades();

    // subscription request, asynchronous call.
    void SubscribeTradesAsync(const std::vector<std::string> &instruments_ids, CallbackFunc callback);

    // unsubscription request, asynchronous call.
    bool UnSubscribeSubscribeTradesAsync();

    // Trading statuses of instruments subscription request, synchronous call.
    bool SubscribeInfo(const std::vector<std::string> &instruments_ids, CallbackFunc callback);

    // Trading statuses of instruments subscription request, asynchronous call.
    void SubscribeInfoAsync(const std::vector<std::string> &instruments_ids, CallbackFunc callback);

    // Last price subscription request, synchronous call.
    bool SubscribeLastPriceTimestamp(const std::vector<std::string> &instruments_ids, CallbackFunc callback);

    // Last price subscription request, asynchronous call.
    void SubscribeLastPriceAsync(const std::vector<std::string> &instruments_ids, CallbackFunc callback);

protected:
    std::unique_ptr<MarketDataStreamService::Stub> service_;
};

} // tinkoff_invest_sdk_cpp_market_data_subscription_service
