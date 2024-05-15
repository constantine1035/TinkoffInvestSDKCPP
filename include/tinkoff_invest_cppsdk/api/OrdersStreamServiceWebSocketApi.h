#pragma once

/*
 *
 *
 *
 */

#include "CppRestOpenAPIClient/ApiClient.h"

#include "CppRestOpenAPIClient/model/RpcStatus.h"
#include "CppRestOpenAPIClient/model/Stream_result_of_v1TradesStreamResponse.h"
#include "CppRestOpenAPIClient/model/V1TradesStreamRequest.h"
#include "tinkoff_invest_cppsdk/service_reply.h"
#include <boost/optional.hpp>
#include <cpprest/ws_client.h>

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {
namespace client {
namespace api {

using namespace org::openapitools::client::model;
using web::websockets::client::websocket_callback_client;

class OrdersStreamServiceWebSocketApi {
public:
    explicit OrdersStreamServiceWebSocketApi(
        std::shared_ptr<const websocket_callback_client> api_client);

    virtual ~OrdersStreamServiceWebSocketApi();

    void OrdersStreamServiceTradesStream(
        std::shared_ptr<V1TradesStreamRequest> body,
        std::vector<ServiceReply<V1TradesStreamResponse>>& responses) const;

protected:
    std::shared_ptr<const websocket_callback_client> api_client_;
};

}  // namespace api
}  // namespace client
}  // namespace tinkoff_invest_cppsdk
