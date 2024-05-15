#pragma once

/*
 * base_client.h
 *
 * This is base client class.
 */

#include "CppRestOpenAPIClient/ApiException.h"
#include "tinkoff_invest_cppsdk/include_services_api.h"
#include "tinkoff_invest_cppsdk/include_model.h"
#include "tinkoff_invest_cppsdk/service_reply.h"
#include "tinkoff_invest_cppsdk/types_and_constants.h"
#include "tinkoff_invest_cppsdk/stream_tracker.h"
#include "tinkoff_invest_cppsdk/stream_subscription_tracker.h"
#include "tinkoff_invest_cppsdk/request_rate_limiter.h"

#include <pplx/pplxinterface.h>
#include <cpprest/ws_client.h>
#include <array>
#include <exception>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <type_traits>
#include <variant>

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::ApiClient;
using org::openapitools::client::api::ApiConfiguration;
using org::openapitools::client::api::ApiException;
using tinkoff_invest_cppsdk::ServiceReply;
using web::websockets::client::websocket_callback_client;
using web::websockets::client::websocket_client_config;

class InvestApiBaseClient {
public:
    explicit InvestApiBaseClient(const std::string& token);

    virtual ~InvestApiBaseClient();

protected:
    enum class ServiceId {
        InstrumentsService,
        MarketDataService,
        MarketDataStreamService,
        OperationsService,
        OperationsStreamService,
        OrdersService,
        OrdersStreamService,
        SandboxService,
        StopOrdersService,
        UsersService
    };

    std::string token_;
    std::array<std::shared_ptr<const some_service_t>, kNumberOfServices> services_;
    mutable std::mutex mutex_;
    StreamTracker stream_tracker_;
    StreamSubscriptionTracker stream_subscription_tracker_;
    RequestRateLimiter request_rate_limiter_;

    template <class RequestType>
    void UpdateStreamTracker(int quantity) {
    }

    template <ServiceId id, class RequestType>
    void UpdateRequestRateLimiter(int quantity) {
    }

    std::shared_ptr<const some_service_t>& GetClientService(ServiceId id);

    std::shared_ptr<const some_service_t> GetClientService(ServiceId id) const;

    template <ServiceId id, class ServiceType>
    std::shared_ptr<some_service_t> MakeService(const std::string& base_url,
                                                const std::string& token) const {
        if constexpr (id == ServiceId::MarketDataStreamService ||
                      id == ServiceId::OperationsStreamService ||
                      id == ServiceId::OrdersStreamService) {
            websocket_client_config config;
            config.headers().add(U("Web-Socket-Protocol"), U("json"));
            config.headers().add(U("Authorization"), U("Bearer " + token));

            auto client = std::make_shared<websocket_callback_client>(config);

            return std::make_shared<some_service_t>(ServiceType(client));
        } else {
            auto config = std::make_shared<ApiConfiguration>();
            config->getDefaultHeaders()["Authorization"] = "Bearer " + token;
            config->setBaseUrl(base_url);

            auto client = std::make_shared<ApiClient>(config);

            return std::make_shared<some_service_t>(ServiceType(client));
        }
    }

    template <ServiceId id, class ServiceType>
    void InitService() {
        if (id == ServiceId::SandboxService) {
            GetClientService(id) = MakeService<id, ServiceType>(kSandboxBaseUrl, token_);
        } else {
            GetClientService(id) = MakeService<id, ServiceType>(kDefaultBaseUrl, token_);
        }
    }

    template <ServiceId id, class ServiceType, class RequestType, class ResponseType>
    ServiceReply<ResponseType> MakeRequestSync(
        std::function<pplx::task<std::shared_ptr<ResponseType>>(const ServiceType&,
                                                                std::shared_ptr<RequestType>)>
            req,
        std::shared_ptr<RequestType> body, int retry_max = 0,
        std::function<void(const ServiceReply<ResponseType>&)> callback = nullptr) {

        std::lock_guard<std::mutex> lock(mutex_);

        if (id == ServiceId::OrdersStreamService || id == ServiceId::OperationsStreamService ||
            id == ServiceId::MarketDataStreamService) {
            UpdateStreamTracker<RequestType>(1);
        } else {
            UpdateRequestRateLimiter<id, RequestType>(1);
        }

        ServiceReply<ResponseType> last_reply;

        for (int i = 0; i <= retry_max; ++i) {
            ServiceReply<ResponseType> reply;
            try {
                auto service = std::get<ServiceType>(*GetClientService(id));
                auto response = req(service, body).get();

                reply = ServiceReply<ResponseType>{.response = *response,
                                                   .status = pplx::task_group_status::completed};
            } catch (ApiException& e) {
                constexpr int kBufSz = 1000;
                char api_error_msg[kBufSz]{0};
                e.getContent()->read(api_error_msg, kBufSz);

                reply = ServiceReply<ResponseType>{.error_message = api_error_msg,
                                                   .error_place = e.what(),
                                                   .error_code = e.error_code(),
                                                   .status = pplx::task_group_status::canceled};
            } catch (const std::exception& e) {
                reply = ServiceReply<ResponseType>{.error_place = e.what(),
                                                   .status = pplx::task_group_status::canceled};
            }
            last_reply = std::move(reply);
            if (last_reply.status == pplx::task_group_status::completed) {
                break;
            }
            if (callback) {
                callback(last_reply);
            }
        }

        if (id == ServiceId::OrdersStreamService || id == ServiceId::OperationsStreamService ||
            id == ServiceId::MarketDataStreamService) {
            UpdateStreamTracker<RequestType>(-1);
        } else {
            UpdateRequestRateLimiter<id, RequestType>(-1);
        }
        return last_reply;
    }

    template <ServiceId id, class ServiceType, class RequestType, class ResponseType>
    ServiceReply<ResponseType> MakeRequestAsync(
        std::function<pplx::task<std::shared_ptr<ResponseType>>(const ServiceType&,
                                                                std::shared_ptr<RequestType>)>
            req,
        std::shared_ptr<RequestType> body, int retry_max = 0,
        std::function<void(const ServiceReply<ResponseType>&)> callback = nullptr) {

        auto service = std::get<ServiceType>(*GetClientService(id));

        if (id == ServiceId::OrdersStreamService || id == ServiceId::OperationsStreamService ||
            id == ServiceId::MarketDataStreamService) {
            UpdateStreamTracker<RequestType>(1);
        } else {
            UpdateRequestRateLimiter<id, RequestType>(1);
        }

        ServiceReply<ResponseType> reply;

        req(service, body)
            .then([&, this](pplx::task<std::shared_ptr<ResponseType>> task) {
                try {
                    auto status = task.wait();
                    auto response = task.get();

                    reply = ServiceReply<ResponseType>{
                        .response = *response, .status = pplx::task_group_status::completed};

                    if (id == ServiceId::OrdersStreamService ||
                        id == ServiceId::OperationsStreamService ||
                        id == ServiceId::MarketDataStreamService) {
                        UpdateStreamTracker<RequestType>(-1);
                    } else {
                        UpdateRequestRateLimiter<id, RequestType>(-1);
                    }

                } catch (ApiException& e) {
                    if (id == ServiceId::OrdersStreamService ||
                        id == ServiceId::OperationsStreamService ||
                        id == ServiceId::MarketDataStreamService) {
                        UpdateStreamTracker<RequestType>(-1);
                    } else {
                        UpdateRequestRateLimiter<id, RequestType>(-1);
                    }

                    constexpr int kBufSz = 1000;
                    char api_error_msg[kBufSz]{0};
                    e.getContent()->read(api_error_msg, kBufSz);

                    reply = ServiceReply<ResponseType>{.error_message = api_error_msg,
                                                       .error_place = e.what(),
                                                       .error_code = e.error_code(),
                                                       .status = pplx::task_group_status::canceled};

                    if (callback) {
                        callback(reply);
                    }
                    if (retry_max > 0) {
                        reply = MakeRequestAsync<id>(req, body, retry_max - 1, callback);
                    }
                } catch (const std::exception& e) {
                    if (id == ServiceId::OrdersStreamService ||
                        id == ServiceId::OperationsStreamService ||
                        id == ServiceId::MarketDataStreamService) {
                        UpdateStreamTracker<RequestType>(-1);
                    } else {
                        UpdateRequestRateLimiter<id, RequestType>(-1);
                    }

                    reply = ServiceReply<ResponseType>{.error_place = e.what(),
                                                       .status = pplx::task_group_status::canceled};

                    if (callback) {
                        callback(reply);
                    }
                    if (retry_max > 0) {
                        reply = MakeRequestAsync<id>(req, body, retry_max - 1, callback);
                    }
                }
            })
            .wait();

        return reply;
    }

    template <ServiceId id, class ServiceType, class RequestType, class ResponseType>
    void MakeWebSocketRequest(
        std::function<void(const ServiceType&, std::shared_ptr<RequestType>,
                           std::vector<ServiceReply<ResponseType>>&)>
            req,
        std::shared_ptr<RequestType> body, std::vector<ServiceReply<ResponseType>>& responses,
        int retry_max = 0,
        std::function<void(const ServiceReply<ResponseType>&)> callback = nullptr) {

        auto service = std::get<ServiceType>(*GetClientService(id));

        stream_tracker_.IncreaseStreamCount(static_cast<int>(id));

        /*if constexpr (id == ServiceId::MarketDataStreamService) {
            stream_subscription_tracker_.
        }*/

        req(service, body, responses);

        stream_tracker_.DegreaseStreamCount(static_cast<int>(id));
    }
};

}  // namespace tinkoff_invest_cppsdk