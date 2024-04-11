#include "market_data_subscription_service.h"

#include <thread>

namespace tinkoff_invest_sdk_cpp_market_data_subscription_service {

using grpc::ClientReaderWriter;
using grpc::ClientAsyncReaderWriter;
using grpc::Status;

MarketDataStream::MarketDataStream(const std::string &token, std::shared_ptr<grpc::Channel> channel) :
    BasedService(token),
    service_(MarketDataStreamService::NewStub(channel)) {
}

bool MarketDataStream::SubscribeCandles(const std::vector<std::pair<std::string,SubscriptionInterval>> &candle_instruments) {
    std::shared_ptr<ClientReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->MarketDataStream(MakeContext().get()));

    MarketDataRequest request;

    auto sub = new SubscribeCandlesRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_SUBSCRIBE);
    for (const auto &[instrument_id, interval]: candle_instruments) {
        auto candle_instrument = sub->add_instruments();
        candle_instrument->set_instrument_id(instrument_id);
        candle_instrument->set_interval(interval);
    }

    request.set_allocated_subscribe_candles_request(sub);

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone();
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status = stream->Finish();
    return status.ok();
}

bool MarketDataStream::UnsubscribeCandles() {
    std::shared_ptr<ClientReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->MarketDataStream(MakeContext().get()));

    MarketDataRequest request;

    auto sub = new SubscribeCandlesRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_UNSUBSCRIBE);

    request.set_allocated_subscribe_candles_request(sub);

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone();
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status = stream->Finish();
    return status.ok();
}

bool MarketDataStream::SubscribeOrderBook(const std::vector<std::pair<std::string, int32_t>> &order_book_instruments) {
    std::shared_ptr<ClientReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->MarketDataStream(MakeContext().get()));

    MarketDataRequest request;

    auto sub = new SubscribeOrderBookRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_SUBSCRIBE);
    for (const auto &[instrument_id, depth]: order_book_instruments) {
        auto order_book_instrument = sub->add_instruments();
        order_book_instrument->set_instrument_id(instrument_id);
        order_book_instrument->set_depth(depth);
    }

    request.set_allocated_subscribe_order_book_request(sub);

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone();
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status = stream->Finish();
    return status.ok();
}

bool MarketDataStream::UnsubscribeOrderBook() {
    std::shared_ptr<ClientReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->MarketDataStream(MakeContext().get()));

    MarketDataRequest request;

    auto sub = new SubscribeOrderBookRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_UNSUBSCRIBE);
    request.set_allocated_subscribe_order_book_request(sub);

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone();
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status = stream->Finish();
    return status.ok();
}

bool MarketDataStream::SubscribeTrades(const std::vector<std::string> &instrument_ids) {
    std::shared_ptr<ClientReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->MarketDataStream(MakeContext().get()));

    MarketDataRequest request;

    auto sub = new SubscribeTradesRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_SUBSCRIBE);
    for (const auto &instrument_id: instrument_ids) {
        auto trades_instrument = sub->add_instruments();
        trades_instrument->set_instrument_id(instrument_id);
    }

    request.set_allocated_subscribe_trades_request(sub);

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone();
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status = stream->Finish();
    return status.ok();
}

bool MarketDataStream::UnsubscribeTrades() {
    std::shared_ptr<ClientReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->MarketDataStream(MakeContext().get()));

    MarketDataRequest request;

    auto sub = new SubscribeTradesRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_UNSUBSCRIBE);
    request.set_allocated_subscribe_trades_request(sub);

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone();
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status = stream->Finish();
    return status.ok();
}

bool MarketDataStream::SubscribeInfo(const std::vector<std::string> &instrument_ids) {
    std::shared_ptr<ClientReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->MarketDataStream(MakeContext().get()));

    MarketDataRequest request;

    auto sub = new SubscribeInfoRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_SUBSCRIBE);
    for (const auto &instrument_id: instrument_ids) {
        auto info_instrument = sub->add_instruments();
        info_instrument->set_instrument_id(instrument_id);
    }
    request.set_allocated_subscribe_info_request(sub);

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone();
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status = stream->Finish();
    return status.ok();
}

bool MarketDataStream::UnsubscribeInfo() {
    std::shared_ptr<ClientReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->MarketDataStream(MakeContext().get()));

    MarketDataRequest request;

    auto sub = new SubscribeInfoRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_UNSUBSCRIBE);
    request.set_allocated_subscribe_info_request(sub);

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone();
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status = stream->Finish();
    return status.ok();
}

bool MarketDataStream::SubscribeLastPrice(const std::vector<std::string> &instrument_ids) {
    std::shared_ptr<ClientReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->MarketDataStream(MakeContext().get()));

    MarketDataRequest request;

    auto sub = new SubscribeLastPriceRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_SUBSCRIBE);
    for (const auto &instrument_id: instrument_ids) {
        auto last_price_instrument = sub->add_instruments();
        last_price_instrument->set_instrument_id(instrument_id);
    }

    request.set_allocated_subscribe_last_price_request(sub);

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone();
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status = stream->Finish();
    return status.ok();
}

bool MarketDataStream::UnsubscribeLastPrice() {
    std::shared_ptr<ClientReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->MarketDataStream(MakeContext().get()));

    MarketDataRequest request;

    auto sub = new SubscribeLastPriceRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_UNSUBSCRIBE);
    request.set_allocated_subscribe_last_price_request(sub);

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone();
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status = stream->Finish();
    return status.ok();
}

/*

void MarketDataStream::SubscribeCandlesAsync(const std::vector<std::pair<std::string,SubscriptionInterval>> &candle_instruments) {
    std::shared_ptr<ClientAsyncReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->PrepareAsyncMarketDataStream(MakeContext().get(), &queue_));

    MarketDataRequest request;

    auto sub = new SubscribeCandlesRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_SUBSCRIBE);
    for (const auto &[instrument_id, interval]: candle_instruments) {
        auto candle_instrument = sub->add_instruments();
        candle_instrument->set_instrument_id(instrument_id);
        candle_instrument->set_interval(interval);
    }

    request.set_allocated_subscribe_candles_request(sub);

    stream->

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone(nullptr);
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status;
    stream->Finish(&status, nullptr);
    // return status.ok();
}

void MarketDataStream::UnsubscribeCandlesAsync() {
    std::shared_ptr<ClientAsyncReaderWriter<MarketDataRequest, MarketDataResponse> > stream(
        service_->PrepareAsyncMarketDataStream(MakeContext().get(), &queue_));

    MarketDataRequest request;

    auto sub = new SubscribeCandlesRequest();
    sub->set_subscription_action(SubscriptionAction::SUBSCRIPTION_ACTION_UNSUBSCRIBE);

    request.set_allocated_subscribe_candles_request(sub);

    std::thread writer([stream, request]() {
        stream->Write(request);
        stream->WritesDone();
    });

    MarketDataResponse reply;
    while (stream->Read(&reply)) {
    }
    writer.join();

    Status status = stream->Finish();
}

*/

} // tinkoff_invest_sdk_cpp_market_data_subscription_service
