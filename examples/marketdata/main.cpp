#include "tinkoff_invest_cppsdk/client.h"
#include <pplx/pplxinterface.h>
#include <iostream>
#include <cstdlib>

using namespace tinkoff_invest_cppsdk;

static const std::string token = std::getenv("MY_TOKEN");

void GetCandles(const std::string &instrument_id, utility::datetime from,
                utility::datetime to, std::shared_ptr<V1CandleInterval> interval) {
    //  Создаем клиента.
    InvestApiClient client(token, InvestApiClient::TradingMode::Sandbox);

    // Отправляем запрос.
    auto reply = client.MarketDataServiceGetCandles(instrument_id, from, to, interval);

    // Обрабатываем ответ.
    std::cout << "Status: " << reply.status << ";" << std::endl;
    if (reply.status == pplx::task_group_status::completed) {
        auto candles = reply.response.getCandles();
        std::cout << "Candles" << ":" << std::endl;
        for (size_t i = 1; i <= candles.size(); ++i) {
            std::cout << i << ")" << candles[i - 1]->toJson().serialize() << std::endl;
        }
    } else {
        std::cout << "Error code: " << reply.error_code << ";" << std::endl;
        std::cout << "Error msg: '" << reply.error_message << "';" << std::endl;
        std::cout << "Error place: '" << reply.error_place << "';" << std::endl;
    }
}

void GetOrderBook(const std::string &instrument_id, int32_t depth) {
    //  Создаем клиента.
    InvestApiClient client(token, InvestApiClient::TradingMode::Sandbox);

    // Отправляем запрос.
    auto reply = client.MarketDataServiceGetOrderBook(instrument_id, depth);

    // Обрабатываем ответ.
    std::cout << "Status: " << reply.status << ";" << std::endl;
    if (reply.status == pplx::task_group_status::completed) {
        std::cout << reply.response.toJson().serialize() << std::endl;
    } else {
        std::cout << "Error code: " << reply.error_code << ";" << std::endl;
        std::cout << "Error msg: '" << reply.error_message << "';" << std::endl;
        std::cout << "Error place: '" << reply.error_place << "';" << std::endl;
    }
}

int main() {
    // Три российские акции.
    std::vector<std::string> instruments{"BBG004730N88", "BBG00475KKY8", "BBG004RVFCY3"};

    std::cout << "Marketdata examples: " << std::endl;

    std::cout << "GetCandles(" << instruments[0] << "; from 01/05/2024 00:00 to 10/05/2024 00:00): " << std::endl;
    std::string figi = instruments[0];
    utility::datetime from;
    from = from.from_string("2024-05-01T00:00:00Z", utility::datetime::ISO_8601);
    utility::datetime to;
    to = to.from_string("2024-05-10T00:00:00Z", utility::datetime::ISO_8601);
    auto interval = std::make_shared<V1CandleInterval>();
    interval->setValue(org::openapitools::client::model::V1CandleInterval::eV1CandleInterval::V1CandleInterval_DAY);
    GetCandles(figi, from, to, interval);

    std::cout << std::endl;

    std::cout << "GetOrderBook(" << instruments[1] << "), depth=1" << std::endl;
    figi = instruments[1];
    int32_t depth = 1;
    GetOrderBook(figi, depth);

    return 0;
}
