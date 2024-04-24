#include <iostream>
#include "include/xxhr/xxhr/xxhr.hpp"

int main()
{
//    printf("123");
//    InvestApiClient client("invest-public-api.tinkoff.ru:443", "t.9DjFbOC06vcgI5xplPO-NkKMUWHjIy8eamhr1rmdVt5YoDMYYWArqCZyrD_oGodNQ");
//    InvestApiClient client("invest-public-api.tinkoff.ru:443", "t.xkHLcK7d-Bjz8YVC2UCnI6nOU0FQoXAVC0BI7S4hsCGMnJdOQtFB3QYVEv4xGnNH2fZ_cSLY6QaInRLcPSMayg");
//    InvestApiClient client("sandbox-invest-public-api.tinkoff.ru:443", "t.oCCIjlXTnrRcIvWV8-W9c92ZVPwQbUyGuSfbX2l3a8O_X0VLKGJEWeIWoH2b0lhkveSPzRuZ355hlErOexHDkA");

    using namespace xxhr;

    GET( "http://httpbin.org/anything"s,
        on_response = [](auto&& resp) {

            std::cout << resp.text;

        }
    );

    return 0;
}
