/*
#include "orders.h"

Orders::Orders(std::shared_ptr<grpc::Channel> channel, const std::string &token) :
    BasedService(token)
    , orders_service_(OrdersService::NewStub(channel))
{}

Orders::~Orders() {
}

ServiceReply
Orders::PostOrder(const std::string &figi, int64_t quantity, int64_t units, int32_t nano, OrderDirection direction,
                  const std::string &account_id, OrderType order_type, const std::string &order_id) {
    PostOrderRequest request;
    request.set_figi(figi);
    request.set_quantity(quantity);
    auto price = new Quotation();
    price->set_units(units);
    price->set_nano(nano);
    request.set_allocated_price(price);
    request.set_direction(direction);
    request.set_account_id(account_id);
    request.set_order_type(order_type);
    request.set_order_id(order_id);
    PostOrderResponse reply;
    Status status = orders_service_->PostOrder(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<PostOrderResponse>(status, reply);
}

ServiceReply Orders::CancelOrder(const std::string &account_id, const std::string &order_id) {
    CancelOrderRequest request;
    request.set_account_id(account_id);
    request.set_order_id(order_id);
    CancelOrderResponse reply;
    Status status = orders_service_->CancelOrder(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<CancelOrderResponse>(status, reply);
}

ServiceReply Orders::GetOrderState(const std::string &account_id, const std::string &order_id) {
    GetOrderStateRequest request;
    request.set_account_id(account_id);
    request.set_order_id(order_id);
    OrderState reply;
    Status status = orders_service_->GetOrderState(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<OrderState>(status, reply);
}

ServiceReply Orders::GetOrders(const std::string &account_id) {
    GetOrdersRequest request;
    request.set_account_id(account_id);
    GetOrdersResponse reply;
    Status status = orders_service_->GetOrders(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetOrdersResponse>(status, reply);
}
 */