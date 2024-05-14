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

static const std::string token = std::getenv("MY_TOKEN");

void Example1(std::vector<ServiceReply<V1MarketDataResponse>> &responses) {
    // Адрес для подключения
    uri address(U("wss://invest-public-api.tinkoff.ru/ws/tinkoff.public.invest.api.contract.v1.MarketDataStreamService/MarketDataStream"));

    websocket_client_config config;
    config.headers().add(U("Web-Socket-Protocol"), U("json"));
    config.headers().add(U("Authorization"), U("Bearer " + token));

    websocket_callback_client client(config);

    auto status = client.connect(address).wait();

    if (status == pplx::task_group_status::canceled) {  // not connected.
        responses.emplace_back();
        responses.back() = ServiceReply<V1MarketDataResponse>{.status = status};
        return;
    }

    std::atomic<bool> is_stream_connected{true};
    std::atomic<bool> is_msg_received{false};
    // Установка заголовка с токеном
    client.set_message_handler([&](websocket_incoming_message msg) {
        // Получение массива значений из сообщения
        utility::string_t body = msg.extract_string().get();
        cout << "Received: " << body << endl;

        // Проверка на обрыв потока
        if (body.empty()) {
            cout << "Connection closed by server" << endl;
            is_stream_connected.store(false);
            responses.emplace_back(ServiceReply<V1MarketDataResponse>{
                .error_message = "Connection closed by server"});
            client.close().wait();
        } else {
            is_msg_received.store(true);
        }
        V1MarketDataResponse response;
        json::value jsn;
        response.fromString(body, jsn);
        response.fromJson(jsn);
        responses.emplace_back();
        //responses.back() = response;
    });

    // Отправка запроса с заголовком Authorization
    websocket_outgoing_message request;

    auto body = std::make_shared<V1MarketDataRequest>();
    auto sub = std::make_shared<V1SubscribeCandlesRequest>();
    auto sub_act = std::make_shared<V1SubscriptionAction>();
    sub_act->setValue(V1SubscriptionAction::eV1SubscriptionAction::V1SubscriptionAction_SUBSCRIBE);
    auto instrument = std::make_shared<V1CandleInstrument>();
    auto interval = std::make_shared<V1SubscriptionInterval>();
    interval->setValue(V1SubscriptionInterval::eV1SubscriptionInterval::V1SubscriptionInterval_ONE_MINUTE);
    //instrument->setInstrumentId("BBG004730N88");
    //instrument->setInstrumentId("2a828e19-88a0-4c1a-8f48-bdd6b5e2f903");
    instrument->setInterval(interval);
    sub->setSubscriptionAction(sub_act);
    sub->setInstruments(std::vector<std::shared_ptr<V1CandleInstrument>>{instrument});
    body->setSubscribeCandlesRequest(sub);

    request.set_utf8_message(U(body->toJson().serialize()));

    client.send(request).wait();

    /*auto instrument2 = std::make_shared<V1CandleInstrument>();
    auto interval2 = std::make_shared<V1SubscriptionInterval>();
    interval2->setValue(V1SubscriptionInterval::eV1SubscriptionInterval::V1SubscriptionInterval_FIVE_MINUTES);
    instrument2->setInstrumentId("BBG00475KKY8");
    instrument2->setInterval(interval);
    body->getSubscribeCandlesRequest()->getInstruments().emplace_back(instrument2);

    request.set_utf8_message(U(body->toJson().serialize()));
    client.send(request).wait();*/

    // Постоянный цикл для ожидания сообщений
    while (is_stream_connected.load()) {
        this_thread::sleep_for(chrono::milliseconds(120000));
        if (!is_msg_received.load()) {
            is_stream_connected.store(false);
            client.close().wait();
        } else {
            is_msg_received.store(false);
        }
    }
}

int main() {
    std::cout << "Marketdata stream examples: " << std::endl;

    std::cout << "Subscribe candles:" << std::endl;
    std::vector<ServiceReply<V1MarketDataResponse>> responses;
    std::thread subscribe_candles{&Example1, std::ref(responses)};

    subscribe_candles.join();

    return 0;
}
