#pragma once

#include "tinkoff_invest_cppsdk/include_services_api.h"
#include "tinkoff_invest_cppsdk/include_model.h"
#include "tinkoff_invest_cppsdk/service_reply.h"
#include "tinkoff_invest_cppsdk/types_and_constants.h"

#include "tinkoffinvestsdkcpp_export.h"

#include <array>
#include <memory>
#include <string>
#include <type_traits>
#include <variant>

/*
 * client.h
 *
 *
 */

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::ApiClient;
using org::openapitools::client::api::ApiConfiguration;
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
};

}  // namespace tinkoff_invest_cppsdk
