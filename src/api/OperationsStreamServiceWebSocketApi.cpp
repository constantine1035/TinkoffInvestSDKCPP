#include "tinkoff_invest_cppsdk/api/OperationsStreamServiceWebSocketApi.h"
#include "CppRestOpenAPIClient/ApiException.h"
#include "tinkoff_invest_cppsdk/types_and_constants.h"

#include <cpprest/ws_client.h>
#include <thread>
#include <atomic>

namespace tinkoff_invest_cppsdk {
namespace client {
namespace api {

using org::openapitools::client::api::ApiException;
using web::web_sockets::client::websocket_incoming_message;
using web::web_sockets::client::websocket_outgoing_message;

OperationsStreamServiceWebSocketApi::OperationsStreamServiceWebSocketApi(
    std::shared_ptr<const websocket_callback_client> api_client)
    : api_client_(api_client) {
}

OperationsStreamServiceWebSocketApi::~OperationsStreamServiceWebSocketApi() {
}

void OperationsStreamServiceWebSocketApi::OperationsStreamServicePortfolioStream(
    std::shared_ptr<V1PortfolioStreamRequest> body,
    std::vector<ServiceReply<V1PortfolioStreamResponse>> &responses) const {

    if (body == nullptr) {
        throw ApiException(
            400, utility::conversions::to_string_t(
                     "Missing required parameter 'body' when calling "
                     "MarketDataStreamServiceApi->MarketDataStreamServiceMarketDataStream"));
    }

    if (!api_client_->config().headers().has(U("Web-Socket-Protocol"))) {
        throw ApiException(
            400, utility::conversions::to_string_t(
                     "MarketDataStreamServiceApi->MarketDataStreamServiceMarketDataStream does not "
                     "produce any supported media type"));
    }

    if (!api_client_->config().headers().has(U("Authorization"))) {
        throw ApiException(400,
                           utility::conversions::to_string_t(
                               "MarketDataStreamServiceApi->"
                               "MarketDataStreamServiceMarketDataStream no token in  headers"));
    }

    web::uri address(
        U(kWebSocketBaseUrl +
          "/tinkoff.public.invest.api.contract.v1.MarketDataStreamService/MarketDataStream"));

    websocket_callback_client local_client{api_client_->config()};

    auto status = local_client.connect(address).wait();

    if (status == pplx::task_group_status::canceled) {
        throw ApiException(400, utility::conversions::to_string_t(
                                    "MarketDataStreamServiceApi->"
                                    "MarketDataStreamServiceMarketDataStream couldnt connect"));
    }

    websocket_outgoing_message request;
    request.set_utf8_message(U(body->toJson().serialize()));

    std::atomic<bool> is_stream_connected{true};
    std::atomic<bool> is_msg_received{false};

    local_client.set_message_handler([&](websocket_incoming_message msg) {
        utility::string_t body = msg.extract_string().get();

        if (body.empty()) {
            is_stream_connected.store(false);
            responses.emplace_back(ServiceReply<V1PortfolioStreamResponse>{
                .error_message = "Connection closed by server",
            });
            local_client.close().wait();
        } else {
            is_msg_received.store(true);
        }
        V1PortfolioStreamResponse response;
        web::json::value jsn;
        response.fromString(body, jsn);
        response.fromJson(jsn);
        responses.emplace_back(ServiceReply<V1PortfolioStreamResponse>{
            .response = response, .status = pplx::task_group_status::completed});
    });

    local_client.send(request).wait();

    while (is_stream_connected.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(kPingDelay));
        if (!is_msg_received.load()) {
            is_stream_connected.store(false);
            local_client.close().wait();
        } else {
            is_msg_received.store(false);
        }
    }
}

void OperationsStreamServiceWebSocketApi::OperationsStreamServicePositionsStream(
    std::shared_ptr<V1PositionsStreamRequest> body,
    std::vector<ServiceReply<V1PositionsStreamResponse>> &responses) const {

    if (body == nullptr) {
        throw ApiException(
            400, utility::conversions::to_string_t(
                     "Missing required parameter 'body' when calling "
                     "MarketDataStreamServiceApi->MarketDataStreamServiceMarketDataStream"));
    }

    if (!api_client_->config().headers().has(U("Web-Socket-Protocol"))) {
        throw ApiException(
            400, utility::conversions::to_string_t(
                     "MarketDataStreamServiceApi->MarketDataStreamServiceMarketDataStream does not "
                     "produce any supported media type"));
    }

    if (!api_client_->config().headers().has(U("Authorization"))) {
        throw ApiException(400,
                           utility::conversions::to_string_t(
                               "MarketDataStreamServiceApi->"
                               "MarketDataStreamServiceMarketDataStream no token in  headers"));
    }

    web::uri address(
        U(kWebSocketBaseUrl +
          "/tinkoff.public.invest.api.contract.v1.MarketDataStreamService/MarketDataStream"));

    websocket_callback_client local_client{api_client_->config()};

    auto status = local_client.connect(address).wait();

    if (status == pplx::task_group_status::canceled) {
        throw ApiException(400, utility::conversions::to_string_t(
                                    "MarketDataStreamServiceApi->"
                                    "MarketDataStreamServiceMarketDataStream couldnt connect"));
    }

    websocket_outgoing_message request;
    request.set_utf8_message(U(body->toJson().serialize()));

    std::atomic<bool> is_stream_connected{true};
    std::atomic<bool> is_msg_received{false};

    local_client.set_message_handler([&](websocket_incoming_message msg) {
        utility::string_t body = msg.extract_string().get();

        if (body.empty()) {
            is_stream_connected.store(false);
            responses.emplace_back(ServiceReply<V1PositionsStreamResponse>{
                .error_message = "Connection closed by server",
            });
            local_client.close().wait();
        } else {
            is_msg_received.store(true);
        }
        V1PositionsStreamResponse response;
        web::json::value jsn;
        response.fromString(body, jsn);
        response.fromJson(jsn);
        responses.emplace_back(ServiceReply<V1PositionsStreamResponse>{
            .response = response, .status = pplx::task_group_status::completed});
    });

    local_client.send(request).wait();

    while (is_stream_connected.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(kPingDelay));
        if (!is_msg_received.load()) {
            is_stream_connected.store(false);
            local_client.close().wait();
        } else {
            is_msg_received.store(false);
        }
    }
}

}  // namespace api
}  // namespace client
}  // namespace tinkoff_invest_cppsdk
