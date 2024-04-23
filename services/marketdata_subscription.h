#pragma once

#include "based_service.h"
#include "reply.h"
#include "marketdata.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <utility>

namespace tinkoff_invest_sdk_cpp_market_data_subscription_service {

using grpc::Channel;
using grpc::CompletionQueue;
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

    MarketDataStream(std::shared_ptr<Channel> channel, const std::string &token);

    ~MarketDataStream() = default;

    // Candle subscription request, synchronous call.
    bool SubscribeCandles(const std::vector<std::pair<std::string,SubscriptionInterval>> &candle_instruments);

    // Candle unsubscription request, synchronous call.
    bool UnsubscribeCandles();

    // Candle subscription request, asynchronous call.
    void SubscribeCandlesAsync(const std::vector<std::pair<std::string,SubscriptionInterval>> &candle_instruments);

    // Candle unsubscription request, asynchronous call.
    void UnsubscribeCandlesAsync();

    // Order book subscription request, synchronous call.
    bool SubscribeOrderBook(const std::vector<std::pair<std::string, int32_t>> &order_book_instruments);

    // Order book unsubscription request, synchronous call.
    bool UnsubscribeOrderBook();

    // Order book subscription request, asynchronous call.
    void SubscribeOrderBookAsync(const std::vector<std::pair<std::string, int32_t>> &order_book_instruments);

    // Order book unsubscription request, asynchronous call.
    bool UnsubscribeOrderBookAsync();

    // Trading statuses of instruments subscription request, synchronous call.
    bool SubscribeTrades(const std::vector<std::string> &instruments_ids);

    // Trading statuses of instruments unsubscription request, synchronous call.
    bool UnsubscribeTrades();

    // Trading statuses of instruments subscription request, asynchronous call.
    void SubscribeTradesAsync(const std::vector<std::string> &instruments_ids);

    // Trading statuses of instruments unsubscription request, asynchronous call.
    bool UnsubscribeTradesAsync();

    // Info subscription request, synchronous call.
    bool SubscribeInfo(const std::vector<std::string> &instrument_ids);

    // Info unsubscription request, synchronous call.
    bool UnsubscribeInfo();

    // Info subscription request, asynchronous call.
    void SubscribeInfoAsync(const std::vector<std::string> &instruments_ids);

    // Info unsubscription request, asynchronous call.
    bool UnsubscribeInfoAsync();
    
    // Last price subscription request, synchronous call.
    bool SubscribeLastPrice(const std::vector<std::string> &instrument_ids);

    // Last price unsubscription request, synchronous call.
    bool UnsubscribeLastPrice();

    // Last price subscription request, asynchronous call.
    void SubscribeLastPriceAsync(const std::vector<std::string> &instruments_ids);

    // Last price unsubscription request, asynchronous call.
    bool UnsubscribeLastPriceAsync();

protected:
    std::unique_ptr<MarketDataStreamService::Stub> service_;
    CompletionQueue queue_;
};

} // tinkoff_invest_sdk_cpp_market_data_subscription_service
