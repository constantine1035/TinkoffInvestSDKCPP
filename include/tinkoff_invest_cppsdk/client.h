#pragma once

#include "CppRestOpenAPIClient/ApiException.h"
#include "tinkoff_invest_cppsdk/include_services_api.h"
#include "tinkoff_invest_cppsdk/include_model.h"
#include "tinkoff_invest_cppsdk/service_reply.h"
#include "tinkoff_invest_cppsdk/types_and_constants.h"

#include <pplx/pplxinterface.h>
#include <array>
#include <exception>
#include <functional>
#include <memory>
#include <string>
#include <type_traits>
#include <variant>

#include "tinkoffinvestsdkcpp_export.h"

/*
 * client.h
 *
 *
 */

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::ApiClient;
using org::openapitools::client::api::ApiConfiguration;
using org::openapitools::client::api::ApiException;
using tinkoff_invest_cppsdk::ServiceReply;

class InvestApiClient {
public:
    explicit InvestApiClient(const std::string& token);

    ServiceReply<V1OpenSandboxAccountResponse> OpenSandboxAccountSync(const std::string& name);

    ServiceReply<Object> CloseSandboxAccountSync(const std::string& account_id);

protected:
    class ClientService {
    public:
        template <class ServiceType>
        void InitializeService(const std::string& base_url, const std::string& token);

        const std::shared_ptr<some_service_t> GetService() const;

        bool ServiceIsInitialized() const;

    protected:
        bool isInitialized_{false};
        std::shared_ptr<some_service_t> service_;
    };

    std::string token_;
    std::array<ClientService, kNumberOfServices> services_;
    // class that will calculate req per min;
    // class-counter: sub in streams;
    // class-counter: number of streams;

    ClientService& GetClientService(ServiceId id);

    template <class ServiceType, ServiceId id>
    void InitService() {
        if (GetClientService(id).ServiceIsInitialized()) {
            return;
        }
        if (std::is_same_v<SandboxServiceApi, ServiceType>) {
            GetClientService(id).InitializeService<ServiceType>(kSandboxBaseUrl, token_);
        } else {
            GetClientService(id).InitializeService<ServiceType>(kDefaultBaseUrl, token_);
        }
    }

    template<class ServiceType, class RequestType, class ResponseType, ServiceId id>
    ServiceReply<ResponseType> MakeRequest(std::shared_ptr<RequestType> body,
                                           std::function<pplx::task<std::shared_ptr<ResponseType>>(const ServiceType&, std::shared_ptr<RequestType>)> req) {
        pplx::task_status status = pplx::task_group_status::not_complete;

        try {
            auto task = req(std::get<ServiceType>(*GetClientService(id).GetService()), body);

            status = task.wait();
            auto response = task.get();

            return ServiceReply<ResponseType>{
                .response = *response,
                .status = status
            };
        } catch (ApiException& e) {
            constexpr int kBufSz = 1000;
            char api_error_msg[kBufSz]{0};
            e.getContent()->read(api_error_msg, kBufSz);

            return ServiceReply<ResponseType>{
                .error_message = api_error_msg,
                .error_place = e.what(),
                .error_code = e.error_code(),
                .status = pplx::task_group_status::canceled
            };
        } catch (const std::exception& e) {
            return ServiceReply<ResponseType>{
                .error_place = e.what(),
                .status = pplx::task_group_status::canceled
            };
        }
    }
};

}  // namespace tinkoff_invest_cppsdk
