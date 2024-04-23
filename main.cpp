#include <iostream>
#include "client.h"
//#include "services/users.h"
#include "services/sandbox.h"

#include <grpc++/grpc++.h>

using tinkoff_invest_sdk_cpp_sandbox_service::Sandbox;

// 3021000

using grpc::Channel;

int main()
{
//    printf("123");
//    InvestApiClient client("invest-public-api.tinkoff.ru:443", "t.9DjFbOC06vcgI5xplPO-NkKMUWHjIy8eamhr1rmdVt5YoDMYYWArqCZyrD_oGodNQ");
//    InvestApiClient client("invest-public-api.tinkoff.ru:443", "t.xkHLcK7d-Bjz8YVC2UCnI6nOU0FQoXAVC0BI7S4hsCGMnJdOQtFB3QYVEv4xGnNH2fZ_cSLY6QaInRLcPSMayg");
    InvestApiClient client("sandbox-invest-public-api.tinkoff.ru:443", "t.oCCIjlXTnrRcIvWV8-W9c92ZVPwQbUyGuSfbX2l3a8O_X0VLKGJEWeIWoH2b0lhkveSPzRuZ355hlErOexHDkA");

    auto sandbox = std::dynamic_pointer_cast<Sandbox>(client.Service("sandbox"));

    auto res = sandbox->OpenSandboxAccount("qwerty");
    std::cout << res.GetStatus().ok() << std::endl;
    std::cout << res.GetErrorMessage() << std::endl;


    //get references to users service
//    auto users = std::dynamic_pointer_cast<Users>(client.Service("users"));

    //print all opened accounts id
//    auto accounts = users->GetAccounts();
//    std::cout << accounts.AccountCount();
//    for (int i = 0; i < accounts.AccountCount(); i++) {
//        std::cout << accounts.AccountID(i) << accounts.AccountName(i) << std::endl;
//    }


    //print info about your account
//    auto accountId = accounts.accountID(0);
//    auto portfolio = sandbox->GetSandboxPortfolio(accountId, PortfolioRequest_CurrencyRequest_RUB);
//    std::cout << portfolio.ptr()->DebugString() << std::endl;


    return 0;
}
