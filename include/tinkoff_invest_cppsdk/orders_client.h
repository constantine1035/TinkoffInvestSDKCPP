#pragma once

/*
 * Orders_client.h
 *
 * This is a client class that use OrdersServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiOrdersClient : virtual public InvestApiBaseClient {
public:
    explicit InvestApiOrdersClient(const std::string &token, TradingMode trading_mode);

    ~InvestApiOrdersClient() override;

    ServiceReply<V1PostOrderResponse> OrdersServicePostOrder(
        const std::string &figi, const std::string &quantity, std::shared_ptr<V1Quotation> price,
        std::shared_ptr<V1OrderDirection> direction, const std::string &account_id,
        std::shared_ptr<V1OrderType> order_type, const std::string &order_id,
        const std::string &instrument_id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1PostOrderResponse> &)> callback = nullptr);

    ServiceReply<V1CancelOrderResponse> OrdersServiceCancelOrder(
        const std::string &account_id, const std::string &order_id, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1CancelOrderResponse> &)> callback = nullptr);

    ServiceReply<V1OrderState> OrdersServiceGetOrderState(
        const std::string &account_id, const std::string &order_id, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1OrderState> &)> callback = nullptr);

    ServiceReply<V1GetOrdersResponse> OrdersServiceGetOrders(
        const std::string &account_id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetOrdersResponse> &)> callback = nullptr);

    ServiceReply<V1PostOrderResponse> OrdersServiceReplaceOrder(
        const std::string &account_id, const std::string &order_id,
        const std::string &idempotency_key, const std::string &quantity,
        std::shared_ptr<V1Quotation> price, std::shared_ptr<V1PriceType> price_type,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1PostOrderResponse> &)> callback = nullptr);
};

}  // namespace tinkoff_invest_cppsdk