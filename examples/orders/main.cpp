#include "tinkoff_invest_cppsdk/client.h"
#include <pplx/pplxinterface.h>
#include <iostream>
#include <cstdlib>

using namespace tinkoff_invest_cppsdk;

static const std::string token = std::getenv("MY_TOKEN");

template<class T>
void ErrorDescript(T reply) {
    std::cout << "Error code: " << reply.error_code << ";" << std::endl;
    std::cout << "Error msg: '" << reply.error_message << "';" << std::endl;
    std::cout << "Error place: '" << reply.error_place << "';" << std::endl;
}

void PrintMoneyValue(std::shared_ptr<V1MoneyValue> val) {
    std::cout << val->getUnits() << ',' << abs(val->getNano()) << ' ' << val->getCurrency();
}

void PrintQuotation(std::shared_ptr<V1Quotation> val) {
    std::cout << val->getUnits() << ',' << abs(val->getNano());
}

int main() {
    InvestApiClient client(token, InvestApiClient::TradingMode::Sandbox);

    std::string instrument = "BBG004730N88";
    V1Quotation quotation;
    quotation.setUnits("500");
    quotation.setNano(0);
    V1OrderDirection direction;
    direction.setValue(V1OrderDirection::eV1OrderDirection::V1OrderDirection_BUY);
    V1OrderType order_type;
    order_type.setValue(V1OrderType::eV1OrderType::V1OrderType_MARKET);
    std::string account_id = client.UsersServiceGetAccounts().response.getAccounts()[0]->getId();
    auto reply = client.OrdersServicePostOrder(instrument, "5", 0, std::make_shared<V1OrderDirection>(direction),
                                               account_id, std::make_shared<V1OrderType>(order_type), "1", instrument);
    std::cout << "Status: " << reply.status << ";" << std::endl;
    if (reply.status == pplx::task_group_status::completed) {
        std::cout << reply.response.toJson().serialize() << std::endl;
    } else {
        ErrorDescript(reply);
    }

    return 0;
}
