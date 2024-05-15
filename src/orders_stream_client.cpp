#include "tinkoff_invest_cppsdk/orders_stream_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiOrdersStreamClient::InvestApiOrdersStreamClient(const std::string& token)
    : InvestApiBaseClient(token) {
    InitService<ServiceId::OrdersStreamService, OrdersStreamServiceApi>();
}

InvestApiOrdersStreamClient::~InvestApiOrdersStreamClient() {
}

ServiceReply<Stream_result_of_v1TradesStreamResponse>
InvestApiOrdersStreamClient::OrdersStreamServiceTradesStream(
    const std::vector<std::string>& accounts, int retry_max,
    std::function<void(const ServiceReply<Stream_result_of_v1TradesStreamResponse> &)> callback) {
    auto body = std::make_shared<V1TradesStreamRequest>();
    body->setAccounts(accounts);

    std::function<pplx::task<std::shared_ptr<Stream_result_of_v1TradesStreamResponse>>(
        const OrdersStreamServiceApi&, std::shared_ptr<V1TradesStreamRequest>)>
        req = &OrdersStreamServiceApi::ordersStreamServiceTradesStream;
    return MakeRequestAsync<ServiceId::OrdersStreamService>(req, body, retry_max, callback);
}

}  // namespace tinkoff_invest_cppsdk