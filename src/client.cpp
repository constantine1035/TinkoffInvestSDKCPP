#include "tinkoff_invest_cppsdk/client.h"

#include "CppRestOpenAPIClient/ApiException.h"

#include <pplx/pplxinterface.h>
#include <exception>

namespace tinkoff_invest_cppsdk {

using org::openapitools::client::api::ApiException;

template <class ServiceType>
void InvestApiClient::ClientService::InitializeService(const std::string& base_url,
                                                       const std::string& token) {
    auto config = std::make_shared<ApiConfiguration>();
    config->getDefaultHeaders()["Authorization"] = "Bearer " + token;
    config->setBaseUrl(base_url);

    auto client = std::make_shared<ApiClient>(config);

    service_ = std::make_shared<some_service_t>(ServiceType(client));

    isInitialized_ = true;
}

bool InvestApiClient::ClientService::ServiceIsInitialized() const {
    return isInitialized_;
}

const std::shared_ptr<some_service_t> InvestApiClient::ClientService::GetService() const {
    return service_;
}

InvestApiClient::ClientService& InvestApiClient::GetClientService(ServiceId id) {
    return services_[static_cast<int>(id)];
}


InvestApiClient::InvestApiClient(const std::string &token) : token_(token) {
}

ServiceReply<V1OpenSandboxAccountResponse> InvestApiClient::OpenSandboxAccountSync(const std::string &name) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1OpenSandboxAccountRequest>();
    body->setName(name);

    pplx::task_status status = pplx::task_group_status::not_complete;

    try {
        auto task =
            std::get<SandboxServiceApi>(
                *GetClientService(ServiceId::SandboxService).GetService()
                ).sandboxServiceOpenSandboxAccount(body);

        status = task.wait();
        auto response = task.get();

        return ServiceReply<V1OpenSandboxAccountResponse>{.response = *response,
                                                          .status = status};
    } catch (ApiException& e) {
        constexpr int kBufSz = 1000;
        char api_error_msg[kBufSz]{0};
        e.getContent()->read(api_error_msg, kBufSz);

        return ServiceReply<V1OpenSandboxAccountResponse>{.error_message = api_error_msg,
                                    .error_place = e.what(),
                                    .error_code = e.error_code(),
                                    .status = pplx::task_group_status::canceled};
    } catch (const std::exception& e) {
        return ServiceReply<V1OpenSandboxAccountResponse>{.error_place = e.what(),
                                    .status = pplx::task_group_status::canceled};
    }
}

ServiceReply<Object> InvestApiClient::CloseSandboxAccountSync(const std::string& account_id) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1CloseSandboxAccountRequest>();
    body->setAccountId(account_id);

    pplx::task_status status = pplx::task_group_status::not_complete;
    try {
        auto task =
            std::get<SandboxServiceApi>(*GetClientService(ServiceId::SandboxService).GetService())
                .sandboxServiceCloseSandboxAccount(body);

        status = task.wait();
        auto response = task.get();

        return ServiceReply<Object>{.response = *response,
                                    .status = status};
    } catch (ApiException& e) {
        constexpr int kBufSz = 1000;
        char api_error_msg[kBufSz]{0};
        e.getContent()->read(api_error_msg, kBufSz);

        return ServiceReply<Object>{.error_message = api_error_msg,
                                    .error_place = e.what(),
                                    .error_code = e.error_code(),
                                    .status = pplx::task_group_status::canceled};
    } catch (const std::exception& e) {
        return ServiceReply<Object>{.error_place = e.what(),
                                    .status = pplx::task_group_status::canceled};
    }
}

}
