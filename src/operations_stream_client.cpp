#include "tinkoff_invest_cppsdk/operations_stream_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiOperationsStreamClient::InvestApiOperationsStreamClient(const std::string &token)
    : InvestApiBaseClient(token) {
    InitService<ServiceId::OperationsStreamService, OperationsStreamServiceWebSocketApi>();
}

InvestApiOperationsStreamClient::~InvestApiOperationsStreamClient() {
}

void InvestApiOperationsStreamClient::OperationsStreamServicePortfolioStream(
    const std::vector<std::string> &accounts,
    std::vector<ServiceReply<V1PortfolioStreamResponse>> &responses, int retry_max,
    std::function<void(const ServiceReply<V1PortfolioStreamResponse> &)> callback) {
    auto body = std::make_shared<V1PortfolioStreamRequest>();
    body->setAccounts(accounts);

    std::function<void(const OperationsStreamServiceWebSocketApi &,
                       std::shared_ptr<V1PortfolioStreamRequest>,
                       std::vector<ServiceReply<V1PortfolioStreamResponse>> &)>
        req = &OperationsStreamServiceWebSocketApi::OperationsStreamServicePortfolioStream;
    return MakeWebSocketRequest<ServiceId::OperationsStreamService>(req, body, responses, retry_max,
                                                                    callback);
}

void InvestApiOperationsStreamClient::OperationsStreamServicePositionsStream(
    const std::vector<std::string> &accounts,
    std::vector<ServiceReply<V1PositionsStreamResponse>> &responses, int retry_max,
    std::function<void(const ServiceReply<V1PositionsStreamResponse> &)> callback) {

    auto body = std::make_shared<V1PositionsStreamRequest>();
    body->setAccounts(accounts);

    std::function<void(const OperationsStreamServiceWebSocketApi &,
                       std::shared_ptr<V1PositionsStreamRequest>,
                       std::vector<ServiceReply<V1PositionsStreamResponse>> &)>
        req = &OperationsStreamServiceWebSocketApi::OperationsStreamServicePositionsStream;
    return MakeWebSocketRequest<ServiceId::OperationsStreamService>(req, body, responses, retry_max,
                                                                    callback);
}

}  // namespace tinkoff_invest_cppsdk