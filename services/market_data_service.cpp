#include "market_data_service.h"

#include <thread>

namespace tinkoff_invest_sdk_cpp_market_data_service {

using grpc::Status;
using google::protobuf::Timestamp;

static Timestamp MakeTimestamp(int64_t seconds, int32_t nanos) {
    Timestamp timestamp;
    timestamp.set_seconds(seconds);
    timestamp.set_nanos(nanos);
    return timestamp;
}

MarketData::MarketData(const std::string &token, std::shared_ptr<grpc::Channel> channel) :
    BasedService(token),
    service_(MarketDataService::NewStub(channel)) {
}

ServiceReply MarketData::GetCandles(const std::string &instrument_id, int64_t from_seconds, int32_t from_nanos,
                                         int64_t to_seconds, int32_t to_nanos, CandleInterval interval) {
    auto from = MakeTimestamp(from_seconds, from_nanos);
    auto to = MakeTimestamp(to_seconds, to_nanos);

    GetCandlesRequest request;
    request.set_instrument_id(instrument_id);
    request.set_allocated_from(&from);
    request.set_allocated_to(&to);
    request.set_interval(interval);

    GetCandlesResponse reply;
    Status status = service_->GetCandles(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetCandlesResponse>(status, reply);
}

ServiceReply MarketData::GetLastPrices(const std::vector<std::string> &instruments_id) {
    GetLastPricesRequest request;
    for (const auto& instrument_id : instruments_id) {
        request.add_instrument_id(instrument_id);
    }

    GetLastPricesResponse reply;
    Status status = service_->GetLastPrices(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetLastPricesResponse>(status, reply);
}

ServiceReply MarketData::GetOrderbook(const std::string &instrument_id, int32_t depth) {
    GetOrderBookRequest request;
    request.set_instrument_id(instrument_id);
    request.set_depth(depth);

    GetOrderBookResponse reply;
    Status status = service_->GetOrderBook(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetOrderBookResponse>(status, reply);
}

ServiceReply MarketData::GetTradingStatus(const std::string &instruments_id) {
    GetTradingStatusRequest request;
    request.set_instrument_id(instruments_id);

    GetTradingStatusResponse reply;
    Status status = service_->GetTradingStatus(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetTradingStatusResponse>(status, reply);
}

ServiceReply MarketData::GetTradingStatuses(const std::vector<std::string> &instruments_ids) {
    GetTradingStatusesRequest request;
    for (const auto &el : instruments_ids) {
        request.add_instrument_id(el);
    }

    GetTradingStatusesResponse reply;
    Status status = service_->GetTradingStatuses(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetTradingStatusesResponse>(status, reply);
}

ServiceReply MarketData::GetLastTrades(const std::string &instrument_id, int64_t from_seconds, int32_t from_nanos,
                           int64_t to_seconds, int32_t to_nanos) {
    auto from = MakeTimestamp(from_seconds, from_nanos);
    auto to = MakeTimestamp(to_seconds, to_nanos);

    GetLastTradesRequest request;
    request.set_instrument_id(instrument_id);
    request.set_allocated_from(&from);
    request.set_allocated_to(&to);

    GetLastTradesResponse reply;
    Status status = service_->GetLastTrades(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetLastTradesResponse>(status, reply);
}

ServiceReply MarketData::GetClosePrices(const std::vector<std::string> &instruments_ids) {
    GetClosePricesRequest request;
    for (const auto &el : instruments_ids) {
        auto instrument_request = request.add_instruments();
        instrument_request->set_instrument_id(el);
    }

    GetClosePricesResponse reply;
    Status status = service_->GetClosePrices(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetClosePricesResponse>(status, reply);
}

} // tinkoff_invest_sdk_cpp_market_data_service
