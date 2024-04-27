#include "tinkoff_invest_cppsdk/client.h"
#include <pplx/pplxinterface.h>
#include <iostream>

using namespace tinkoff_invest_cppsdk;

static const std::string token = "t.oCCIjlXTnrRcIvWV8-W9c92ZVPwQbUyGuSfbX2l3a8O_X0VLKGJEWeIWoH2b0lhkveSPzRuZ355hlErOexHDkA";

void OpenCloseAccount() {
    InvestApiClient client(token);

    std::cout << "Open sandbox account:" << std::endl;
    auto reply_open_sandbox_account = client.OpenSandboxAccountSync("qwerty");

    std::cout << "Status: " << reply_open_sandbox_account.status << "; " << std::endl;
    if (reply_open_sandbox_account.status == pplx::task_group_status::completed) {
        std::cout << "Id: '" << reply_open_sandbox_account.response.getAccountId() << "'; "
                  << std::endl;
    } else {
        std::cout << "Error code: " << reply_open_sandbox_account.error_code << "; " << std::endl;
        std::cout << "Error msg: '" << reply_open_sandbox_account.error_message << "'; " << std::endl;
        std::cout << "Error place: '" << reply_open_sandbox_account.error_place << "'; " << std::endl;
    }

    std::cout << "Close sandbox account:" << std::endl;
    auto reply_close_sandbox_account = client.CloseSandboxAccountSync(reply_open_sandbox_account.response.getAccountId());

    std::cout << "Status: " << reply_close_sandbox_account.status << "; " << std::endl;

    if (reply_close_sandbox_account.status == pplx::task_group_status::completed) {
    } else {
        std::cout << "Error code: " << reply_open_sandbox_account.error_code << "; " << std::endl;
        std::cout << "Error msg: '" << reply_close_sandbox_account.error_message << "'; " << std::endl;
        std::cout << "Error place: '" << reply_close_sandbox_account.error_place << "'; " << std::endl;
    }
}


int main() {
    OpenCloseAccount();

    return 0;
}
