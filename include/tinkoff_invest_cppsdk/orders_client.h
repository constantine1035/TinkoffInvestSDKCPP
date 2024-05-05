#pragma once

/*
 * Orders_client.h
 *
 * This is a client class that use OrdersServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiOrdersClient : public InvestApiBaseClient {
public:
    explicit InvestApiOrdersClient(const std::string &token);

    ~InvestApiOrdersClient() override;

    ServiceReply<V1PostOrderResponse> OrdersServicePostOrder(
            const std::string &figi, const std::string &quantity, std::shared_ptr<V1Quotation> price,
            std::shared_ptr<V1OrderDirection> direction, const std::string &account_id, std::shared_ptr<V1OrderType> order_type,
            const std::string &order_id, const std::string &instrument_id
    );

    ServiceReply<V1CancelOrderResponse> OrdersServiceCancelOrder(
            const std::string &account_id, const std::string &order_id
    );

    ServiceReply<Contractv1OrderState> OrdersServiceGetOrderState(
            const std::string &account_id, const std::string &order_id
    );

    ServiceReply<V1GetOrdersResponse> OrdersServiceGetOrders(
            const std::string &account_id
    );

    ServiceReply<V1PostOrderResponse> OrdersServiceReplaceOrder(
            const std::string &account_id, const std::string &order_id, std::string idempotency_key,
            const std::string &quantity, std::shared_ptr<V1Quotation> price, std::shared_ptr<V1PriceType> price_type
    );

};

}  // tinkoff_invest_cppsdk