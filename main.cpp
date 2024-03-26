#include <iostream>
#include "client.h"
#include "services/users.h"

int main()
{
    InvestApiClient client("invest-public-api.tinkoff.ru:443", "t.9DjFbOC06vcgI55ijIJJTganmdmcMw2NOk1xplPO-NkKMUWHjIy8eamhr1rmdVt5YoDMYYWArqCZyrD_oGodNQ");
//    InvestApiClient client("invest-public-api.tinkoff.ru:443", "t.xkHLcK7d-Bjz8YVC2UCnI6nOU0FQoXAVC0BI7S4hsCGMnJdOQtFB3QYVEv4xGnNH2fZ_cSLY6QaInRLcPSMayg");


    //get references to users service
    auto users = std::dynamic_pointer_cast<Users>(client.Service("users"));

    //print all opened accounts id
    auto accounts = users->GetAccounts();
    std::cout << accounts.AccountCount();
    for (int i = 0; i < accounts.AccountCount(); i++) {
        std::cout << accounts.AccountID(i) << accounts.AccountName(i) << std::endl;
    }


    //print info about your account
//    auto accountId = accounts.accountID(0);
//    auto portfolio = sandbox->GetSandboxPortfolio(accountId, PortfolioRequest_CurrencyRequest_RUB);
//    std::cout << portfolio.ptr()->DebugString() << std::endl;


    return 0;
}