#include "stoporders.h"

#include "google/protobuf/timestamp.pb.h"

StopOrders::StopOrders(std::shared_ptr<grpc::Channel> channel, const std::string &token) :
        BasedService(token)
        , stop_orders_service_(StopOrdersService::NewStub(channel)) {
}

StopOrders::~StopOrders() {
}

ServiceReply
StopOrders::PostStopOrder(const std::string &figi, int64_t quantity, int64_t units, int32_t nano, int64_t stopunits,
                          int32_t stopnano, StopOrderDirection direction, const std::string &account_id,
                          StopOrderExpirationType expiration_type, StopOrderType stop_order_type, int64_t expire_seconds,
                          int32_t expire_nanos) {
    PostStopOrderRequest request;
    request.set_figi(figi);
    request.set_quantity(quantity);
    auto price = new Quotation();
    price->set_units(units);
    price->set_nano(nano);
    request.set_allocated_price(price);
    auto stopprice = new Quotation();
    stopprice->set_units(stopunits);
    stopprice->set_nano(stopnano);
    request.set_allocated_stop_price(stopprice);
    request.set_direction(direction);
    request.set_account_id(account_id);
    request.set_expiration_type(expiration_type);
    request.set_stop_order_type(stop_order_type);
    google::protobuf::Timestamp *expire_date = new google::protobuf::Timestamp();
    expire_date->set_seconds(expire_seconds);
    expire_date->set_nanos(expire_nanos);
    request.set_allocated_expire_date(expire_date);
    PostStopOrderResponse reply;
    Status status = stop_orders_service_->PostStopOrder(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<PostStopOrderResponse>(status, reply);
}

ServiceReply StopOrders::GetStopOrders(const std::string &account_id) {
    GetStopOrdersRequest request;
    request.set_account_id(account_id);
    GetStopOrdersResponse reply;
    Status status = stop_orders_service_->GetStopOrders(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetStopOrdersResponse>(status, reply);
}

ServiceReply StopOrders::CancelStopOrder(const std::string &account_id, const std::string &stop_order_id) {
    CancelStopOrderRequest request;
    request.set_account_id(account_id);
    request.set_stop_order_id(stop_order_id);
    CancelStopOrderResponse reply;
    Status status = stop_orders_service_->CancelStopOrder(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<CancelStopOrderResponse>(status, reply);
}