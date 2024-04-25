/*
#pragma once

#include "based_service.h"
#include <grpcpp/grpcpp.h>
#include "orders.grpc.pb.h"
#include "reply.h"

using grpc::Channel;
using tinkoff_invest_sdk_cpp_based_service::BasedService;
using namespace tinkoff::public_::invest::api::contract::v1;

class Orders : public BasedService {
public:
    Orders(std::shared_ptr<Channel> channel, const std::string &token);

    ~Orders();

    // Метод выставления заявки
    ServiceReply
    PostOrder(const std::string &figi, int64_t quantity, int64_t units, int32_t nano, OrderDirection direction,
              const std::string &account_id, OrderType order_type, const std::string &order_id);

    // Метод отмены биржевой заявки
    ServiceReply CancelOrder(const std::string &account_id, const std::string &order_id);

    // Метод получения статуса торгового поручения
    ServiceReply GetOrderState(const std::string &account_id, const std::string &order_id);

    // Метод получения списка активных заявок по счёту
    ServiceReply GetOrders(const std::string &account_id);

private:
    std::unique_ptr<OrdersService::Stub> orders_service_;

};
 */