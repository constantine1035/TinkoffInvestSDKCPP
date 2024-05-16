#include "tinkoff_invest_cppsdk/client.h"
#include <pplx/pplxinterface.h>
#include <iostream>
#include <cstdlib>

using namespace tinkoff_invest_cppsdk;

static const std::string token = std::getenv("MY_TOKEN");

std::string OpenAccount(InvestApiClient& client) {
    std::cout << "Open sandbox account:" << std::endl;
    auto reply_open_sandbox_account = client.SandboxServiceOpenSandboxAccount("qwerty");

    std::string account_id;

    std::cout << "Status: " << reply_open_sandbox_account.status << "; " << std::endl;
    if (reply_open_sandbox_account.status == pplx::task_group_status::completed) {
        account_id = reply_open_sandbox_account.response.getAccountId();
        std::cout << "Id: '" << account_id << "'; " << std::endl;
    } else {
        std::cout << "Error code: " << reply_open_sandbox_account.error_code << "; " << std::endl;
        std::cout << "Error msg: '" << reply_open_sandbox_account.error_message << "'; " << std::endl;
        std::cout << "Error place: '" << reply_open_sandbox_account.error_place << "'; " << std::endl;
    }
    return account_id;
}

void CloseAccount(InvestApiClient& client, const std::string& account_id) {
    std::cout << "Close sandbox account:" << std::endl;
    auto reply_close_sandbox_account = client.SandboxServiceCloseSandboxAccount(account_id);

    std::cout << "Status: " << reply_close_sandbox_account.status << "; " << std::endl;

    if (reply_close_sandbox_account.status == pplx::task_group_status::completed) {
    } else {
        std::cout << "Error code: " << reply_close_sandbox_account.error_code << "; " << std::endl;
        std::cout << "Error msg: '" << reply_close_sandbox_account.error_message << "'; " << std::endl;
        std::cout << "Error place: '" << reply_close_sandbox_account.error_place << "'; " << std::endl;
    }
}

void PayIn(InvestApiClient& client, const std::string& account_id,
           const std::string& currency, const std::string& units,
           int32_t nano) {
    std::cout << "Pay in account:" << std::endl;
    auto reply_payin_sandbox_account = client.SandboxServicePayIn(account_id, currency, units, nano);

    std::cout << "Status: " << reply_payin_sandbox_account.status << "; " << std::endl;

    if (reply_payin_sandbox_account.status == pplx::task_group_status::completed) {
        auto balance = reply_payin_sandbox_account.response.getBalance();
        std::cout << "Currency: " << balance->getCurrency() << "; " << std::endl;
        std::cout << "Units: " << balance->getUnits() << "; " << std::endl;
        std::cout << "Nano: " << balance->getNano() << "; " << std::endl;

    } else {
        std::cout << "Error code: " << reply_payin_sandbox_account.error_code << "; " << std::endl;
        std::cout << "Error msg: '" << reply_payin_sandbox_account.error_message << "'; " << std::endl;
        std::cout << "Error place: '" << reply_payin_sandbox_account.error_place << "'; " << std::endl;
    }
}

void WithdrawLimits(InvestApiClient& client, const std::string& account_id) {
    std::cout << "WithdrawLimits account:" << std::endl;
    auto reply_withdrawlimits_sandbox_account = client.SandboxServiceGetSandboxWithdrawLimits(account_id);

    std::cout << "Status: " << reply_withdrawlimits_sandbox_account.status << "; " << std::endl;

    if (reply_withdrawlimits_sandbox_account.status == pplx::task_group_status::completed) {
        auto balance = reply_withdrawlimits_sandbox_account.response.getMoney();
        std::cout << "Balance: " << std::endl;
        int cnt = 0;
        for (const auto& money : balance) {
            std::cout << ++cnt << ") ";
            std::cout << "Currency: " << money->getCurrency() << "; " << std::endl;
            std::cout << "Units: " << money->getUnits() << "; " << std::endl;
            std::cout << "Nano: " << money->getNano() << "; " << std::endl;
        }

    } else {
        std::cout << "Error code: " << reply_withdrawlimits_sandbox_account.error_code << "; " << std::endl;
        std::cout << "Error msg: '" << reply_withdrawlimits_sandbox_account.error_message << "'; " << std::endl;
        std::cout << "Error place: '" << reply_withdrawlimits_sandbox_account.error_place << "'; " << std::endl;
    }
}

void OpenCloseAccount() {
    InvestApiClient client(token, InvestApiClient::TradingMode::Sandbox);

    auto account_id = OpenAccount(client);

    CloseAccount(client, account_id);
}

void PaiInAndGetWithdrawLimits() {
    InvestApiClient client(token, InvestApiClient::TradingMode::Sandbox);

    auto account_id = OpenAccount(client);

    PayIn(client, account_id, "rub", "1360000", 500000000);

    PayIn(client, account_id, "usd", "1360000", 500000000);

    PayIn(client, account_id, "usd", "-200", -200000000);

    WithdrawLimits(client, account_id);

    CloseAccount(client, account_id);
}


int main() {
    std::cout << "Sandbox examples: " << std::endl;

    std::cout << "Example open and close: " << std::endl;

    OpenCloseAccount();

    std::cout << std::endl;

    std::cout << "Example PayIn and get WithdrawLimits: " << std::endl;

    PaiInAndGetWithdrawLimits();

    std::cout << std::endl;

    return 0;
}
