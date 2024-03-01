#pragma once

#include <grpc/grpc.h>
#include <grpc++/client_context.h>

#include <string>
#include <memory>

using namespace grpc;

namespace tinkoff_invest_sdk_cpp_based_service {

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
