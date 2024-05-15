#include "tinkoff_invest_cppsdk/orders_stream_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiOrdersStreamClient::InvestApiOrdersStreamClient(const std::string& token)
    : InvestApiBaseClient(token) {
    InitService<ServiceId::OrdersStreamService, OrdersStreamServiceWebSocketApi>();
}

InvestApiOrdersStreamClient::~InvestApiOrdersStreamClient() {
}

void InvestApiOrdersStreamClient::OrdersStreamServiceTradesStream(
    const std::vector<std::string>& accounts,
    std::vector<ServiceReply<V1TradesStreamResponse>>& responses, int retry_max,
    std::function<void(const ServiceReply<V1TradesStreamResponse>&)> callback) {

    auto body = std::make_shared<V1TradesStreamRequest>();
    body->setAccounts(accounts);

    std::function<void(const OrdersStreamServiceWebSocketApi &,
                       std::shared_ptr<V1TradesStreamRequest>,
                       std::vector<ServiceReply<V1TradesStreamResponse>> &)>
        req = &OrdersStreamServiceWebSocketApi::OrdersStreamServiceTradesStream;
    return MakeWebSocketRequest<ServiceId::OrdersStreamService>(req, body, responses, retry_max,
                                                                callback);
}

}  // namespace tinkoff_invest_cppsdk