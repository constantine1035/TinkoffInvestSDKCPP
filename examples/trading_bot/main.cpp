#include <tinkoff_invest_cppsdk/client.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>

using namespace tinkoff_invest_cppsdk;

struct CurrData {
    long double price = 0;
    std::shared_ptr<V1Quotation> price_ = {};
    bool can_buy = false;
    bool can_sell = false;
    std::string uid = "";

};

// Function to calculate the Simple Moving Average
double CalculateSMA(const std::vector<long double>& prices, int period) {
    if (prices.size() < period) return 0.0;
    double sum = std::accumulate(prices.end() - period, prices.end(), 0.0);
    return sum / period;
}

CurrData getCurrentPrice(tinkoff_invest_cppsdk::InvestApiClient &client, std::string isin) {
    std::shared_ptr<V1InstrumentIdType> type = std::make_shared<V1InstrumentIdType>();
    type->setValue(V1InstrumentIdType::eV1InstrumentIdType::V1InstrumentIdType_TYPE_FIGI);
    auto reply = client.ShareBy(type, "", "BBG004730N88");
    if (reply.status == pplx::canceled) {
        return {};
    }
    auto nom = (*(reply.response.getInstrument())->getNominal());
    auto price = std::make_shared<V1Quotation>();
    price->setNano(nom.getNano());
    price->setUnits(nom.getUnits());
    long double frac = nom.getNano();
    while (frac > 1) {
        frac = frac / 10;
    }
    long double units = std::stoi(nom.getUnits()); //for some reason units are returned as string, even though they're supposed to be int
    return {units + frac, price, reply.response.getInstrument()->isBuyAvailableFlag(), reply.response.getInstrument()->isSellAvailableFlag(), reply.response.getInstrument()->getFigi()};

}

void PlaceBuyOrder(tinkoff_invest_cppsdk::InvestApiClient &client, std::shared_ptr<V1Quotation> price, std::string orderid, std::string instrid) {
    auto resp = client.UsersServiceGetAccounts().response.getAccounts();
    std::shared_ptr<V1Account> account;
    if (resp.size() > 0) {
        account = resp[0];
    } else {
        return;
    }
    auto dirtype = std::make_shared<V1OrderDirection>();
    client.SandboxServicePayIn(account->getId(), "rub", "1360000", 500000000);

    dirtype->setValue(V1OrderDirection::eV1OrderDirection::V1OrderDirection_BUY);
    auto ordtype = std::make_shared<V1OrderType>();
    ordtype->setValue(V1OrderType::eV1OrderType::V1OrderType_BESTPRICE);
    //auto timeinforce = std::make_shared<V1TimeInForceType>();
    //timeinforce->setValue(V1TimeInForceType::eV1TimeInForceType::V1TimeInForceType_UNSPECIFIED);
    //auto pricetype = std::make_shared<V1PriceType>();
    //pricetype->setValue(V1PriceType::eV1PriceType::V1PriceType_CURRENCY);
    auto responce = client.OrdersServicePostOrder("BBG004730N88", "1", price, dirtype, account->getId(), ordtype, "", "BBG004730N88", 0, 0);
    std::cout << "Bought Stock\n";

}

void PlaceSellOrder(tinkoff_invest_cppsdk::InvestApiClient &client, std::shared_ptr<V1Quotation> price, std::string orderid, std::string instrid) {
    auto resp = client.UsersServiceGetAccounts().response.getAccounts();
    std::shared_ptr<V1Account> account;
    if (resp.size() > 0) {
        account = resp[0];
    } else {
        return;
    }
    auto dirtype = std::make_shared<V1OrderDirection>();
    dirtype->setValue(V1OrderDirection::eV1OrderDirection::V1OrderDirection_SELL);
    auto ordtype = std::make_shared<V1OrderType>();
    ordtype->setValue(V1OrderType::eV1OrderType::V1OrderType_BESTPRICE);
    //auto timeinforce = std::make_shared<V1TimeInForceType>();
    //timeinforce->setValue(V1TimeInForceType::eV1TimeInForceType::V1TimeInForceType_UNSPECIFIED);
    //auto pricetype = std::make_shared<V1PriceType>();
    //pricetype->setValue(V1PriceType::eV1PriceType::V1PriceType_CURRENCY);
    auto responce = client.OrdersServicePostOrder("BBG004730N88", "1", price, dirtype, account->getId(), ordtype, "", "BBG004730N88", 0, 0);
    std::cout << "Sold Stock\n";
}

// Trading bot class
class TradingBot {
public:
    TradingBot(int period, std::string token, std::string stock) : client(InvestApiClient(token, InvestApiClient::TradingMode::Sandbox)) {
        sma_period = period;
        last_price = 0.0;
        stocks = stock;
    }

    void run() {
        CurrData current = getCurrentPrice(client, stocks);
         if (historical.size() >= sma_period) {
            ordid += 1;
            double sma = CalculateSMA(historical, sma_period);

            std::cout << "Current Price: " << current.price << " | SMA: " << sma << std::endl;

            if (current.price >= sma && holding < 4 && current.can_buy) {
                PlaceBuyOrder(client, current.price_, std::to_string(ordid), current.uid);
                holding++;
            } else if (current.price < sma && holding > 0 && current.can_sell) {
                PlaceSellOrder(client, current.price_, std::to_string(ordid), current.uid);
                holding--;
            }

            last_price = current.price;
            historical.push_back(current.price);
        } else {
            historical.push_back(current.price);
        }
    }

private:
    std::vector<long double> historical;
    InvestApiClient client;
    std::string stocks;
    int sma_period;
    double last_price;
    int holding = 0;
    int64_t ordid = 892873959892;
};

int main() {
    std::string token = std::getenv("MY_TOKEN");
    std::string stocks = "US87238U2033";
    //InvestApiClient client(token, InvestApiClient::TradingMode::Sandbox);
    //auto responce = client.SandboxServiceOpenSandboxAccount({"myacc"}, true,  2);
    int sma_period = 1; // Example period for SMA
    TradingBot bot(sma_period, token, stocks);

    while(1) {
        bot.run();
        sleep(30);
    }
}