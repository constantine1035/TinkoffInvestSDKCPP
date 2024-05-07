#include "tinkoff_invest_cppsdk/operations_stream_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiOperationsStreamClient::InvestApiOperationsStreamClient(const std::string& token)
    : InvestApiBaseClient(token) {
    InitService<ServiceId::OperationsStreamService, OperationsStreamServiceApi>();
}

InvestApiOperationsStreamClient::~InvestApiOperationsStreamClient() {
}

ServiceReply<Stream_result_of_v1PortfolioStreamResponse>
InvestApiOperationsStreamClient::OperationsStreamServicePortfolioStream(
    const std::vector<std::string>& accounts) const {
    auto body = std::make_shared<V1PortfolioStreamRequest>();
    body->setAccounts(accounts);

    std::function<pplx::task<std::shared_ptr<Stream_result_of_v1PortfolioStreamResponse>>(
        const OperationsStreamServiceApi&, std::shared_ptr<V1PortfolioStreamRequest>)>
        req = &OperationsStreamServiceApi::operationsStreamServicePortfolioStream;
    return MakeRequestAsync<ServiceId::OperationsStreamService>(req, body);
}

ServiceReply<Stream_result_of_v1PositionsStreamResponse>
InvestApiOperationsStreamClient::OperationsStreamServicePositionsStream(
    const std::vector<std::string>& accounts) const {
    auto body = std::make_shared<V1PositionsStreamRequest>();
    body->setAccounts(accounts);

    std::function<pplx::task<std::shared_ptr<Stream_result_of_v1PositionsStreamResponse>>(
        const OperationsStreamServiceApi&, std::shared_ptr<V1PositionsStreamRequest>)>
        req = &OperationsStreamServiceApi::operationsStreamServicePositionsStream;
    return MakeRequestAsync<ServiceId::OperationsStreamService>(req, body);
}

}  // namespace tinkoff_invest_cppsdk