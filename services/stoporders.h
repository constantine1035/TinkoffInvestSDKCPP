#pragma once

#include "based_service.h"
#include <grpcpp/grpcpp.h>
#include "stoporders.grpc.pb.h"
#include "reply.h"

using grpc::Channel;
using tinkoff_invest_sdk_cpp_based_service::BasedService;

using namespace tinkoff::public_::invest::api::contract::v1;

class StopOrders : public BasedService {
public:
    StopOrders(std::shared_ptr<Channel> channel, const std::string &token);

    ~StopOrders();

    // Метод выставления стоп-заявки
    ServiceReply PostStopOrder(const std::string &figi, int64_t quantity, int64_t units, int32_t nano,
                               int64_t stopunits, int32_t stopnano, StopOrderDirection direction,
                               const std::string &account_id, StopOrderExpirationType expiration_type,
                               StopOrderType stop_order_type, int64_t expire_seconds, int32_t expire_nanos);

    // Метод получения списка активных стоп заявок по счёту
    ServiceReply GetStopOrders(const std::string &account_id);

    // Метод отмены стоп-заявки
    ServiceReply CancelStopOrder(const std::string &account_id, const std::string &stop_order_id);

private:
    std::unique_ptr<StopOrdersService::Stub> stop_orders_service_;
};