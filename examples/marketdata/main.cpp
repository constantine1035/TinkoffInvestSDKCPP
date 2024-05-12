#include "tinkoff_invest_cppsdk/client.h"
#include <pplx/pplxinterface.h>
#include <iostream>
#include <cstdlib>

using namespace tinkoff_invest_cppsdk;

static const std::string token = std::getenv("MY_TOKEN");

int main() {
    std::cout << "Marketdata examples: " << std::endl;

    InvestApiClient client(token);


    return 0;
}
