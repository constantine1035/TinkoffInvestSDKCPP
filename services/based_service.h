#pragma once

#include <grpcpp/client_context.h>
#include <memory>
#include <string>

namespace tinkoff_invest_sdk_cpp_based_service {

using grpc::ClientContext;

// Based class for all services.
class BasedService {
public:
    explicit BasedService(const std::string &token);

    virtual ~BasedService() = default;

protected:
    std::string token_;

    std::shared_ptr<ClientContext> MakeContext();
};
} // namespace tinkoff_invest_sdk_cpp_based_service
