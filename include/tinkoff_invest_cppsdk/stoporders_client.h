#pragma once

/*
 * Orders_client.h
 *
 * This is a client class that use OrdersServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiStopOrdersClient : public InvestApiBaseClient {
public:
    explicit InvestApiStopOrdersClient(const std::string &token);

    ~InvestApiStopOrdersClient() override;

    ServiceReply<V1PostStopOrderResponse> StopOrdersServicePostStopOrder(
        const std::string &figi, const std::string &quantity, std::shared_ptr<V1Quotation> price,
        std::shared_ptr<V1Quotation> stop_price, std::shared_ptr<V1StopOrderDirection> direction,
        const std::string &account_id, std::shared_ptr<V1StopOrderExpirationType> expiration_type,
        std::shared_ptr<V1StopOrderType> stop_order_type,
        const std::string &expire_date, const std::string &instrument_id
    );

    ServiceReply<V1GetStopOrdersResponse> StopOrdersServiceGetStopOrders(
        const std::string &account_id
    );

    ServiceReply<V1CancelStopOrderResponse> StopOrdersServiceCancelStopOrder(
        const std::string &account_id, const std::string &stop_order_id
    );

};

}  // tinkoff_invest_cppsdk