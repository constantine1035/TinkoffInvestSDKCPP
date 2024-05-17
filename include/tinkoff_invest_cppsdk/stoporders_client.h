#pragma once

/*
 * Orders_client.h
 *
 * This is a client class that use OrdersServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiStopOrdersClient : virtual public InvestApiBaseClient {
public:
    explicit InvestApiStopOrdersClient(const std::string &token, TradingMode trading_mode);

    ~InvestApiStopOrdersClient() override;

    ServiceReply<V1PostStopOrderResponse> StopOrdersServicePostStopOrder(
        const std::string &figi, const std::string &quantity, std::shared_ptr<V1Quotation> price,
        std::shared_ptr<V1Quotation> stop_price, std::shared_ptr<V1StopOrderDirection> direction,
        const std::string &account_id, std::shared_ptr<V1StopOrderExpirationType> expiration_type,
        std::shared_ptr<V1StopOrderType> stop_order_type, const std::string &expire_date,
        const std::string &instrument_id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1PostStopOrderResponse> &)> callback = nullptr);

    ServiceReply<V1GetStopOrdersResponse> StopOrdersServiceGetStopOrders(
        const std::string &account_id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetStopOrdersResponse> &)> callback = nullptr);

    ServiceReply<V1CancelStopOrderResponse> StopOrdersServiceCancelStopOrder(
        const std::string &account_id, const std::string &stop_order_id, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1CancelStopOrderResponse> &)> callback = nullptr);
};

}  // namespace tinkoff_invest_cppsdk