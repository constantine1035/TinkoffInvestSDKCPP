/*

#pragma once

#include <grpcpp/grpcpp.h>
#include "services/based_service.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using tinkoff_invest_sdk_cpp_based_service::BasedService;

class InvestApiClient {
public:
    InvestApiClient(const std::string &host, const std::string &pass);
    ~InvestApiClient();

    std::shared_ptr<BasedService> Service(const std::string &service_name);

private:
    std::map<std::string, std::shared_ptr<BasedService>> services_;
};
*/