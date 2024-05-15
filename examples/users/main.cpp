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

void GetMarginAttributes(InvestApiClient &client, std::string account_id) {
    std::cout << "Margin attributes: \n";
    auto reply = client.UsersServiceGetMarginAttributes(account_id);
    if (reply.status == pplx::task_group_status::completed) {
        auto a = reply.response.getLiquidPortfolio();
        std::cout << "Liquid Portfolio: ";
        PrintMoneyValue(reply.response.getLiquidPortfolio());
        std::cout << ", Starting Margin: ";
        PrintMoneyValue(reply.response.getStartingMargin());
        std::cout << ", Minimal Margin: ";
        PrintMoneyValue(reply.response.getMinimalMargin());
        std::cout << ", Funds Sufficiency Level: ";
        PrintQuotation(reply.response.getFundsSufficiencyLevel());
        std::cout << ", Amount of Missing Funds: ";
        PrintMoneyValue(reply.response.getAmountOfMissingFunds());
        std::cout << ", Corrected Margin: ";
        PrintMoneyValue(reply.response.getCorrectedMargin());
        std::cout << "\n\n";
    } else {
        ErrorDescript(reply);
    }
}

int main() {
    InvestApiClient client(token);

    //print all opened accounts id
    auto reply = client.UsersServiceGetAccounts();
    std::cout << "Status: " << reply.status << ";" << std::endl;
    if (reply.status == pplx::task_group_status::completed) {
        auto accounts = reply.response.getAccounts();
        std::cout << accounts.size();
        for (auto account: accounts) {
            std::cout << "ID: " << account->getId() << ", Name: " << account->getName() << ", Type: "
                      << account->getType() << ", Status: " << account->getStatus() << "\n";
            GetMarginAttributes(client, account->getId());
        }
    } else {
        ErrorDescript(reply);
    }

    auto reply_info = client.UsersServiceGetInfo();
    std::cout << "Status: " << reply_info.status << ";" << std::endl;
    if (reply_info.status == pplx::task_group_status::completed) {
        std::cout << "Premium status: " << reply_info.response.isPremStatus() << "\n";
        std::cout << "Qualified status: " << reply_info.response.isQualStatus() << "\n";
        std::cout << "Tariff: " << reply_info.response.getTariff() << "\n";
    } else {
        ErrorDescript(reply_info);
    }

    return 0;
}
