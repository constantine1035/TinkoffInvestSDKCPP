#include "tinkoff_invest_cppsdk/stoporders_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiStopOrdersClient::InvestApiStopOrdersClient(const std::string &token, TradingMode trading_mode)
    : InvestApiBaseClient(token, trading_mode) {
    InitService<ServiceId::StopOrdersService, StopOrdersServiceApi>();
}

InvestApiStopOrdersClient::~InvestApiStopOrdersClient() {
}

ServiceReply<V1PostStopOrderResponse> InvestApiStopOrdersClient::StopOrdersServicePostStopOrder(
    const std::string &figi, const std::string &quantity, std::shared_ptr<V1Quotation> price,
    std::shared_ptr<V1Quotation> stop_price, std::shared_ptr<V1StopOrderDirection> direction,
    const std::string &account_id, std::shared_ptr<V1StopOrderExpirationType> expiration_type,
    std::shared_ptr<V1StopOrderType> stop_order_type, const std::string &expire_date,
    const std::string &instrument_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1PostStopOrderResponse> &)> callback) {

    auto body = std::make_shared<V1PostStopOrderRequest>();
    body->setFigi(figi);
    body->setQuantity(quantity);
    body->setPrice(price);
    body->setDirection(direction);
    body->setAccountId(account_id);
    body->setStopOrderType(stop_order_type);
    body->setInstrumentId(instrument_id);

    std::function<pplx::task<std::shared_ptr<V1PostStopOrderResponse>>(
        const StopOrdersServiceApi &, std::shared_ptr<V1PostStopOrderRequest>)>
        req = &StopOrdersServiceApi::stopOrdersServicePostStopOrder;

    if (is_async_req) {
        return MakeRequestAsync<ServiceId::StopOrdersService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::StopOrdersService>(req, body, retry_max, callback);}

ServiceReply<V1GetStopOrdersResponse> InvestApiStopOrdersClient::StopOrdersServiceGetStopOrders(
    const std::string &account_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1GetStopOrdersResponse> &)> callback) {

    auto body = std::make_shared<V1GetStopOrdersRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1GetStopOrdersResponse>>(
        const StopOrdersServiceApi &, std::shared_ptr<V1GetStopOrdersRequest>)>
        req = &StopOrdersServiceApi::stopOrdersServiceGetStopOrders;

    if (is_async_req) {
        return MakeRequestAsync<ServiceId::StopOrdersService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::StopOrdersService>(req, body, retry_max, callback);}

ServiceReply<V1CancelStopOrderResponse> InvestApiStopOrdersClient::StopOrdersServiceCancelStopOrder(
    const std::string &account_id, const std::string &order_id, bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1CancelStopOrderResponse> &)> callback) {

    auto body = std::make_shared<V1CancelStopOrderRequest>();
    body->setAccountId(account_id);
    body->setStopOrderId(order_id);

    std::function<pplx::task<std::shared_ptr<V1CancelStopOrderResponse>>(
        const StopOrdersServiceApi &, std::shared_ptr<V1CancelStopOrderRequest>)>
        req = &StopOrdersServiceApi::stopOrdersServiceCancelStopOrder;

    if (is_async_req) {
        return MakeRequestAsync<ServiceId::StopOrdersService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::StopOrdersService>(req, body, retry_max, callback);}

}  // namespace tinkoff_invest_cppsdk