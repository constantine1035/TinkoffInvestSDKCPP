#include "tinkoff_invest_cppsdk/client.h"

namespace tinkoff_invest_cppsdk {

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

    std::function<pplx::task<std::shared_ptr<V1OpenSandboxAccountResponse>>(const SandboxServiceApi&, std::shared_ptr<V1OpenSandboxAccountRequest>)> req = &SandboxServiceApi::sandboxServiceOpenSandboxAccount;
    return MakeRequest<SandboxServiceApi, V1OpenSandboxAccountRequest, V1OpenSandboxAccountResponse, ServiceId::SandboxService>(body, req);
}

ServiceReply<Object> InvestApiClient::CloseSandboxAccountSync(const std::string& account_id) {
    InitService<SandboxServiceApi, ServiceId::SandboxService>();

    auto body = std::make_shared<V1CloseSandboxAccountRequest>();
    body->setAccountId(account_id);

    std::function<pplx::task<std::shared_ptr<Object>>(const SandboxServiceApi&, std::shared_ptr<V1CloseSandboxAccountRequest>)> req = &SandboxServiceApi::sandboxServiceCloseSandboxAccount;
    return MakeRequest<SandboxServiceApi, V1CloseSandboxAccountRequest, Object, ServiceId::SandboxService>(body, req);
}

}
