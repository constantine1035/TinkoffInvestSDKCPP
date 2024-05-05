#include "tinkoff_invest_cppsdk/orders_stream_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiOrdersStreamClient::InvestApiOrdersStreamClient(
    const std::string &token
    ) : InvestApiBaseClient(token) {
}

InvestApiOrdersStreamClient::~InvestApiOrdersStreamClient() {
}

ServiceReply<Stream_result_of_v1TradesStreamResponse> InvestApiOrdersStreamClient::ordersStreamServiceTradesStream(
    const std::vector<std::string>& accounts
    ) {
    InitService<ServiceId::OrdersStreamService, OrdersStreamServiceApi>();

    auto body = std::make_shared<V1TradesStreamRequest>();
    body->setAccounts(accounts);

    std::function<pplx::task<std::shared_ptr<Stream_result_of_v1TradesStreamResponse>>(const OrdersStreamServiceApi&, std::shared_ptr<V1TradesStreamRequest>)> req = &OrdersStreamServiceApi::ordersStreamServiceTradesStream;
    return MakeRequest<ServiceId::OrdersStreamService>(body, req);
}

}  // tinkoff_invest_cppsdk