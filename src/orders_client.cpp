#include "tinkoff_invest_cppsdk/orders_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiOrdersClient::InvestApiOrdersClient(const std::string &token, TradingMode trading_mode)
    : InvestApiBaseClient(token, trading_mode) {
    InitService<ServiceId::OrdersService, OrdersServiceApi>();
}

InvestApiOrdersClient::~InvestApiOrdersClient() {
}

ServiceReply<V1PostOrderResponse> InvestApiOrdersClient::OrdersServicePostOrder(
    const std::string &figi, const std::string &quantity, std::shared_ptr<V1Quotation> price,
    std::shared_ptr<V1OrderDirection> direction, const std::string &account_id,
    std::shared_ptr<V1OrderType> order_type, const std::string &order_id,
    const std::string &instrument_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1PostOrderResponse> &)> callback) {
    auto body = std::make_shared<V1PostOrderRequest>();
    body->setFigi(figi);
    body->setQuantity(quantity);
    body->setPrice(price);
    body->setDirection(direction);
    body->setAccountId(account_id);
    body->setOrderType(order_type);
    body->setOrderId(order_id);
    body->setInstrumentId(instrument_id);

    std::function<pplx::task<std::shared_ptr<V1PostOrderResponse>>(
        const OrdersServiceApi &, std::shared_ptr<V1PostOrderRequest>)>
        req = &OrdersServiceApi::ordersServicePostOrder;

    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OrdersService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OrdersService>(req, body, retry_max, callback);
}

ServiceReply<V1CancelOrderResponse> InvestApiOrdersClient::OrdersServiceCancelOrder(
    const std::string &account_id, const std::string &order_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1CancelOrderResponse> &)> callback) {
    auto body = std::make_shared<V1CancelOrderRequest>();
    body->setAccountId(account_id);
    body->setOrderId(order_id);

    std::function<pplx::task<std::shared_ptr<V1CancelOrderResponse>>(
        const OrdersServiceApi &, std::shared_ptr<V1CancelOrderRequest>)>
        req = &OrdersServiceApi::ordersServiceCancelOrder;

    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OrdersService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OrdersService>(req, body, retry_max, callback);
}

ServiceReply<V1OrderState> InvestApiOrdersClient::OrdersServiceGetOrderState(
    const std::string &account_id, const std::string &order_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1OrderState> &)> callback) {
    auto body = std::make_shared<V1GetOrderStateRequest>();
    body->setAccountId(account_id);
    body->setOrderId(order_id);

    std::function<pplx::task<std::shared_ptr<V1OrderState>>(
        const OrdersServiceApi &, std::shared_ptr<V1GetOrderStateRequest>)>
        req = &OrdersServiceApi::ordersServiceGetOrderState;

    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OrdersService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OrdersService>(req, body, retry_max, callback);
}

ServiceReply<V1GetOrdersResponse> InvestApiOrdersClient::OrdersServiceGetOrders(
    const std::string &account_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1GetOrdersResponse> &)> callback) {
    auto body = std::make_shared<V1GetOrdersRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1GetOrdersResponse>>(
        const OrdersServiceApi &, std::shared_ptr<V1GetOrdersRequest>)>
        req = &OrdersServiceApi::ordersServiceGetOrders;

    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OrdersService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OrdersService>(req, body, retry_max, callback);
}

ServiceReply<V1PostOrderResponse> InvestApiOrdersClient::OrdersServiceReplaceOrder(
    const std::string &account_id, const std::string &order_id, const std::string &idempotency_key,
    const std::string &quantity, std::shared_ptr<V1Quotation> price,
    std::shared_ptr<V1PriceType> price_type, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1PostOrderResponse> &)> callback) {
    auto body = std::make_shared<V1ReplaceOrderRequest>();
    body->setAccountId(account_id);
    body->setOrderId(order_id);
    body->setIdempotencyKey(idempotency_key);
    body->setQuantity(quantity);
    body->setPrice(price);
    body->setPriceType(price_type);

    std::function<pplx::task<std::shared_ptr<V1PostOrderResponse>>(
        const OrdersServiceApi &, std::shared_ptr<V1ReplaceOrderRequest>)>
        req = &OrdersServiceApi::ordersServiceReplaceOrder;

    if (is_async_req) {
        return MakeRequestAsync<ServiceId::OrdersService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::OrdersService>(req, body, retry_max, callback);
}

}  // namespace tinkoff_invest_cppsdk
