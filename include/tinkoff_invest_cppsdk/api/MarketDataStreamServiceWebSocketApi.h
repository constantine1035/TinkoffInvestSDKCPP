#pragma once

/*
 *
 *
 *
 */

#include "CppRestOpenAPIClient/ApiClient.h"

#include "CppRestOpenAPIClient/model/RpcStatus.h"
#include "CppRestOpenAPIClient/model/V1MarketDataResponse.h"
#include "CppRestOpenAPIClient/model/V1MarketDataRequest.h"
#include "CppRestOpenAPIClient/model/V1MarketDataServerSideStreamRequest.h"
#include "tinkoff_invest_cppsdk/service_reply.h"
#include <boost/optional.hpp>
#include <cpprest/ws_client.h>

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {
namespace client {
namespace api {

using namespace org::openapitools::client::model;
using web::websockets::client::websocket_callback_client;

class MarketDataStreamServiceWebSocketApi {
public:
    explicit MarketDataStreamServiceWebSocketApi(
        std::shared_ptr<const websocket_callback_client> api_client);

    virtual ~MarketDataStreamServiceWebSocketApi();

    void MarketDataStreamServiceMarketDataServerSideStream(
        std::shared_ptr<V1MarketDataServerSideStreamRequest> body,
        std::vector<ServiceReply<V1MarketDataResponse>> &responses) const;

    void MarketDataStreamServiceMarketDataStream(
        std::shared_ptr<V1MarketDataRequest> body,
        std::vector<ServiceReply<V1MarketDataResponse>> &responses) const;

protected:
    std::shared_ptr<const websocket_callback_client> api_client_;
};

}  // namespace api
}  // namespace client
}  // namespace tinkoff_invest_cppsdk
