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

    enum class TradingMode {
        Sandbox,
        Prod,
    };

    explicit InvestApiBaseClient(const std::string &token, TradingMode trading_mode);

    virtual ~InvestApiBaseClient();

protected:
    const std::string token_;
    std::array<std::shared_ptr<const some_service_t>, kNumberOfServices> services_;
    const TradingMode trading_mode_;
    mutable std::mutex mutex_;
    std::unique_ptr<StreamTracker> stream_tracker_;
    std::unique_ptr<StreamSubscriptionTracker> stream_subscription_tracker_;
    std::unique_ptr<BaseRequestRateLimiter> request_rate_limiter_;

    std::shared_ptr<const some_service_t> &GetClientService(ServiceId id);

    std::shared_ptr<const some_service_t> GetClientService(ServiceId id) const;

    template <ServiceId id, class RequestType>
    void IncrementRequestRateLimiter() {
        if (trading_mode_ == TradingMode::Sandbox) {
            if (id == ServiceId::InstrumentsService) {
                dynamic_cast<SandboxRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(
                        SandboxRequestRateLimiter::UnarySandboxLimitId::InstrumentsService);
            } else if (id == ServiceId::MarketDataService) {
                dynamic_cast<SandboxRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(
                        SandboxRequestRateLimiter::UnarySandboxLimitId::MarketDataService);
            } else {
                dynamic_cast<SandboxRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(
                        SandboxRequestRateLimiter::UnarySandboxLimitId::OtherServices);
            }
        } else {
            if (id == ServiceId::InstrumentsService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::InstrumentsService);
            } else if (id == ServiceId::MarketDataService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::MarketDataService);
            } else if (id == ServiceId::SandboxService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::SandboxService);
            } else if (id == ServiceId::StopOrdersService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::StopOrdersService);
            } else if (id == ServiceId::UsersService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(ProdRequestRateLimiter::UnaryProdLimitId::UsersService);
            } else if (std::is_same_v<RequestType, V1BrokerReportRequest>) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::OperationsServiceGetBrokerReport);
            } else if (std::is_same_v<RequestType, V1GetDividendsForeignIssuerReportRequest>) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(ProdRequestRateLimiter::UnaryProdLimitId::
                                                OperationsServiceGetDividendsForeignIssuer);
            } else if (id == ServiceId::OperationsService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::OperationsService);
            } else if (std::is_same_v<RequestType, V1GetOrdersRequest>) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::OrdersServiceGetOrders);
            } else {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->IncrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::OrdersService);
            }
        }
    }

    template <ServiceId id, class RequestType>
    void DecrementRequestRateLimiter() {
        if (trading_mode_ == TradingMode::Sandbox) {
            if constexpr (id == ServiceId::InstrumentsService) {
                dynamic_cast<SandboxRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(
                        SandboxRequestRateLimiter::UnarySandboxLimitId::InstrumentsService);
            } else if constexpr (id == ServiceId::MarketDataService) {
                dynamic_cast<SandboxRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(
                        SandboxRequestRateLimiter::UnarySandboxLimitId::MarketDataService);
            } else {
                dynamic_cast<SandboxRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(
                        SandboxRequestRateLimiter::UnarySandboxLimitId::OtherServices);
            }
        } else {
            if constexpr (id == ServiceId::InstrumentsService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::InstrumentsService);
            } else if constexpr (id == ServiceId::MarketDataService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::MarketDataService);
            } else if constexpr (id == ServiceId::SandboxService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::SandboxService);
            } else if constexpr (id == ServiceId::StopOrdersService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::StopOrdersService);
            } else if constexpr (id == ServiceId::UsersService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(ProdRequestRateLimiter::UnaryProdLimitId::UsersService);
            } else if constexpr (std::is_same_v<RequestType, V1BrokerReportRequest>) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::OperationsServiceGetBrokerReport);
            } else if constexpr (std::is_same_v<RequestType,
                                                V1GetDividendsForeignIssuerReportRequest>) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(ProdRequestRateLimiter::UnaryProdLimitId::
                                                OperationsServiceGetDividendsForeignIssuer);
            } else if constexpr (id == ServiceId::OperationsService) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::OperationsService);
            } else if constexpr (std::is_same_v<RequestType, V1GetOrdersRequest>) {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::OrdersServiceGetOrders);
            } else {
                dynamic_cast<ProdRequestRateLimiter *>(request_rate_limiter_.get())
                    ->DecrementRequestCount(
                        ProdRequestRateLimiter::UnaryProdLimitId::OrdersService);
            }
        }
    }

    template <ServiceId id, class ServiceType>
    std::shared_ptr<some_service_t> MakeService(const std::string &base_url,
                                                const std::string &token) const {
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
        if (trading_mode_ == TradingMode::Sandbox) {
            GetClientService(id) = MakeService<id, ServiceType>(kSandboxBaseUrl, token_);
        } else {
            GetClientService(id) = MakeService<id, ServiceType>(kDefaultBaseUrl, token_);
        }
    }

    template <ServiceId id, class ServiceType, class RequestType, class ResponseType>
    ServiceReply<ResponseType> MakeRequestSync(
        std::function<pplx::task<std::shared_ptr<ResponseType>>(const ServiceType &,
                                                                std::shared_ptr<RequestType>)>
            req,
        std::shared_ptr<RequestType> body, int retry_max = 0,
        std::function<void(const ServiceReply<ResponseType> &)> callback = nullptr) {

        std::lock_guard<std::mutex> lock(mutex_);

        IncrementRequestRateLimiter<id, RequestType>();

        ServiceReply<ResponseType> last_reply;

        for (int i = 0; i <= retry_max; ++i) {
            ServiceReply<ResponseType> reply;
            try {
                auto service = std::get<ServiceType>(*GetClientService(id));
                auto response = req(service, body).get();

                reply = ServiceReply<ResponseType>{.response = *response,
                                                   .status = pplx::task_group_status::completed};
            } catch (ApiException &e) {
                constexpr int kBufSz = 1000;
                char api_error_msg[kBufSz]{0};
                e.getContent()->read(api_error_msg, kBufSz);

                reply = ServiceReply<ResponseType>{.error_message = api_error_msg,
                                                   .error_place = e.what(),
                                                   .error_code = e.error_code(),
                                                   .status = pplx::task_group_status::canceled};
            } catch (const std::exception &e) {
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

        DecrementRequestRateLimiter<id, RequestType>();
        return last_reply;
    }

    template <ServiceId id, class ServiceType, class RequestType, class ResponseType>
    ServiceReply<ResponseType> MakeRequestAsync(
        std::function<pplx::task<std::shared_ptr<ResponseType>>(const ServiceType &,
                                                                std::shared_ptr<RequestType>)>
            req,
        std::shared_ptr<RequestType> body, int retry_max = 0,
        std::function<void(const ServiceReply<ResponseType> &)> callback = nullptr) {

        auto service = std::get<ServiceType>(*GetClientService(id));

        IncrementRequestRateLimiter<id, RequestType>();

        ServiceReply<ResponseType> reply;

        req(service, body)
            .then([&, this](pplx::task<std::shared_ptr<ResponseType>> task) {
                try {
                    auto status = task.wait();
                    auto response = task.get();

                    reply = ServiceReply<ResponseType>{
                        .response = *response, .status = pplx::task_group_status::completed};
                } catch (ApiException &e) {
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
                } catch (const std::exception &e) {
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

        DecrementRequestRateLimiter<id, RequestType>();
        return reply;
    }

    template <ServiceId id, class ServiceType, class RequestType, class ResponseType>
    void MakeWebSocketRequest(
        std::function<void(const ServiceType &, std::shared_ptr<RequestType>,
                           std::vector<ServiceReply<ResponseType>> &)>
            req,
        std::shared_ptr<RequestType> body, std::vector<ServiceReply<ResponseType>> &responses,
        int retry_max = 0,
        std::function<void(const ServiceReply<ResponseType> &)> callback = nullptr) {

        auto service = std::get<ServiceType>(*GetClientService(id));

        if constexpr (id == ServiceId::MarketDataStreamService) {
            stream_tracker_->IncrementStreamCount(StreamTracker::StreamLimitId::MarketDataStream);
        } else if constexpr (id == ServiceId::OrdersStreamService) {
            stream_tracker_->IncrementStreamCount(StreamTracker::StreamLimitId::TradesStream);
        } else if constexpr (std::is_same_v<RequestType, V1PortfolioStreamRequest>) {
            stream_tracker_->IncrementStreamCount(StreamTracker::StreamLimitId::PortfolioStream);
        } else {
            stream_tracker_->IncrementStreamCount(StreamTracker::StreamLimitId::PositionsStream);
        }

        try {
            req(service, body, responses);
        } catch (ApiException &e) {
            constexpr int kBufSz = 1000;
            char api_error_msg[kBufSz]{0};
            e.getContent()->read(api_error_msg, kBufSz);

            responses.emplace_back(
                ServiceReply<ResponseType>{.error_message = api_error_msg,
                                           .error_place = e.what(),
                                           .error_code = e.error_code(),
                                           .status = pplx::task_group_status::canceled});

            if (retry_max > 0) {
                MakeWebSocketRequest<id>(req, body, responses, retry_max, callback);
            }
        } catch (const std::exception &e) {
            responses.emplace_back(ServiceReply<ResponseType>{
                .error_place = e.what(), .status = pplx::task_group_status::canceled});
        }

        if constexpr (id == ServiceId::MarketDataStreamService) {
            stream_tracker_->DecrementStreamCount(StreamTracker::StreamLimitId::MarketDataStream);
        } else if constexpr (id == ServiceId::OrdersStreamService) {
            stream_tracker_->DecrementStreamCount(StreamTracker::StreamLimitId::TradesStream);
        } else if constexpr (std::is_same_v<RequestType, V1PortfolioStreamRequest>) {
            stream_tracker_->DecrementStreamCount(StreamTracker::StreamLimitId::PortfolioStream);
        } else {
            stream_tracker_->DecrementStreamCount(StreamTracker::StreamLimitId::PositionsStream);
        }
    }
};

}  // namespace tinkoff_invest_cppsdk