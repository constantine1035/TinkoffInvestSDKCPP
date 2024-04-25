/*
#include "based_service.h"

namespace tinkoff_invest_sdk_cpp_based_service {
BasedService::BasedService(const std::string &token) : token_(token) {
    queue_ = std::make_shared<CompletionQueue>();
}

std::shared_ptr<ClientContext> BasedService::MakeContext() {
    auto context = std::make_shared<grpc::ClientContext>();
    context->AddMetadata("authorization", "Bearer " + token_);
    //  context->AddMetadata("x-app-name", APP_NAME);
    return context;
}

std::shared_ptr<CompletionQueue> BasedService::GetQueue() {
    return queue_;
}

} // namespace tinkoff_invest_sdk_cpp_based_service
*/