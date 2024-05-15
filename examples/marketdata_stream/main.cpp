#include "tinkoff_invest_cppsdk/client.h"
#include <pplx/pplxinterface.h>
#include <cpprest/ws_client.h>
#include <iostream>
#include <cstdlib>
#include <atomic>
#include <thread>

using namespace tinkoff_invest_cppsdk;

using namespace web;
using namespace web::websockets::client;
using namespace std;

using web::websockets::client::websocket_callback_client;

static const std::string token = std::getenv("MY_TOKEN");

void SubscribeCandles() {
    InvestApiClient client(token);

    auto body = std::make_shared<V1MarketDataRequest>();
    auto sub = std::make_shared<V1SubscribeCandlesRequest>();
    auto sub_act = std::make_shared<V1SubscriptionAction>();
    sub_act->setValue(V1SubscriptionAction::eV1SubscriptionAction::V1SubscriptionAction_SUBSCRIBE);
    auto instrument = std::make_shared<V1CandleInstrument>();
    auto interval = std::make_shared<V1SubscriptionInterval>();
    interval->setValue(V1SubscriptionInterval::eV1SubscriptionInterval::V1SubscriptionInterval_ONE_MINUTE);
    instrument->setInstrumentId("BBG004730N88");
    //instrument->setInstrumentId("2a828e19-88a0-4c1a-8f48-bdd6b5e2f903");
    instrument->setInterval(interval);
    sub->setSubscriptionAction(sub_act);
    sub->setInstruments(std::vector<std::shared_ptr<V1CandleInstrument>>{instrument});
    body->setSubscribeCandlesRequest(sub);

    std::vector<ServiceReply<V1MarketDataResponse>> responses;

    std::thread subscribe_candles([&client, body, &responses]() {
        client.MarketDataStreamServiceMarketDataStream(body, responses);
    });

    int i = 0;
    while (i < 20) {
        if (i < responses.size()) {
            std::cout << responses[i].response.toJson().serialize() << std::endl;
            ++i;
        }
    }
}

int main() {
    std::cout << "Marketdata stream examples: " << std::endl;

    std::cout << "Subscribe candles:" << std::endl;
    SubscribeCandles();

    return 0;
}
