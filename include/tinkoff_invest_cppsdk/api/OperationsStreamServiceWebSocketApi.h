#pragma once

/*
 *
 *
 *
 */

#include "CppRestOpenAPIClient/ApiClient.h"

#include "CppRestOpenAPIClient/model/RpcStatus.h"
#include "CppRestOpenAPIClient/model/Stream_result_of_v1PortfolioStreamResponse.h"
#include "CppRestOpenAPIClient/model/Stream_result_of_v1PositionsStreamResponse.h"
#include "CppRestOpenAPIClient/model/V1PortfolioStreamRequest.h"
#include "CppRestOpenAPIClient/model/V1PositionsStreamRequest.h"
#include "tinkoff_invest_cppsdk/service_reply.h"
#include <boost/optional.hpp>
#include <cpprest/ws_client.h>

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {
namespace client {
namespace api {

using namespace org::openapitools::client::model;
using web::websockets::client::websocket_callback_client;

class OperationsStreamServiceWebSocketApi {
public:
    explicit OperationsStreamServiceWebSocketApi(
        std::shared_ptr<const websocket_callback_client> api_client);

    virtual ~OperationsStreamServiceWebSocketApi();

    void OperationsStreamServicePortfolioStream(
        std::shared_ptr<V1PortfolioStreamRequest> body,
        std::vector<ServiceReply<V1PortfolioStreamResponse>> &responses) const;

    void OperationsStreamServicePositionsStream(
        std::shared_ptr<V1PositionsStreamRequest> body,
        std::vector<ServiceReply<V1PositionsStreamResponse>> &responses) const;

protected:
    std::shared_ptr<const websocket_callback_client> api_client_;
};

}  // namespace api
}  // namespace client
}  // namespace tinkoff_invest_cppsdk
