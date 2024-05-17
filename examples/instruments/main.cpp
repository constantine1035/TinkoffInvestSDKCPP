#include "tinkoff_invest_cppsdk/client.h"
#include <iostream>

using namespace tinkoff_invest_cppsdk;

static const std::string token = std::getenv("MY_TOKEN")

void TradingSchedules(InvestApiClient &client, utility::datetime from, utility::datetime to) {
    std::cout << "Trading schedules: \n";
    auto reply = client.TradingSchedules(from, to);
    if (reply.status == pplx::task_group_status::completed) {
        for (auto i : reply.response.getExchanges()) {
            auto a = *i;
            std::cout << "\tList of trading days for " << a.getExchange() <<":\n";
            for (auto day : a.getDays()) {
                auto b = *day;
                std::cout <<"\t\t"<< b.getDate().to_string() << std::endl;
            }
        }
    } else {
        std::cout << "Error code: " << reply.error_code << ";" << std::endl;
        std::cout << "Error msg: '" << reply.error_message << "';" << std::endl;
        std::cout << "Error place: '" << reply.error_place << "';" << std::endl;
    }
}

int main() {
    InvestApiClient client(token, InvestApiClient::TradingMode::Sandbox);
    utility::datetime from;
    from = from.from_string("2024-05-16T00:00:00Z", utility::datetime::ISO_8601);
    utility::datetime to;
    to = to.from_string("2024-05-20T00:00:00Z", utility::datetime::ISO_8601);
    TradingSchedules(client, from, to);

    return 0;
}
