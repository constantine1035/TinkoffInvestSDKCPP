#include "tinkoff_invest_cppsdk/stoporders_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiStopOrdersClient::InvestApiStopOrdersClient(const std::string &token)
    : InvestApiBaseClient(token) {
    InitService<ServiceId::StopOrdersService, StopOrdersServiceApi>();
}

InvestApiStopOrdersClient::~InvestApiStopOrdersClient() {
}

ServiceReply<V1PostStopOrderResponse> InvestApiStopOrdersClient::StopOrdersServicePostStopOrder(
    const std::string &figi, const std::string &quantity, std::shared_ptr<V1Quotation> price,
    std::shared_ptr<V1Quotation> stop_price, std::shared_ptr<V1StopOrderDirection> direction,
    const std::string &account_id, std::shared_ptr<V1StopOrderExpirationType> expiration_type,
    std::shared_ptr<V1StopOrderType> stop_order_type, const std::string &expire_date,
    const std::string &instrument_id) const {
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
    return MakeRequestAsync<ServiceId::StopOrdersService>(req, body);
}

ServiceReply<V1GetStopOrdersResponse> InvestApiStopOrdersClient::StopOrdersServiceGetStopOrders(
    const std::string &account_id) const {
    auto body = std::make_shared<V1GetStopOrdersRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<V1GetStopOrdersResponse>>(
        const StopOrdersServiceApi &, std::shared_ptr<V1GetStopOrdersRequest>)>
        req = &StopOrdersServiceApi::stopOrdersServiceGetStopOrders;
    return MakeRequestAsync<ServiceId::StopOrdersService>(req, body);
}

ServiceReply<V1CancelStopOrderResponse> InvestApiStopOrdersClient::StopOrdersServiceCancelStopOrder(
    const std::string &account_id, const std::string &order_id) const {
    auto body = std::make_shared<V1CancelStopOrderRequest>();
    body->setAccountId(account_id);
    body->setStopOrderId(order_id);

    std::function<pplx::task<std::shared_ptr<V1CancelStopOrderResponse>>(
        const StopOrdersServiceApi &, std::shared_ptr<V1CancelStopOrderRequest>)>
        req = &StopOrdersServiceApi::stopOrdersServiceCancelStopOrder;
    return MakeRequestAsync<ServiceId::StopOrdersService>(req, body);
}

}  // namespace tinkoff_invest_cppsdk