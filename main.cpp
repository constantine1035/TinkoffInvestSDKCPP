#include <iostream>
#include <string>
#include "include/xxhr/xxhr/xxhr.hpp"
#include "include/xxhr/xxhr/sync.hpp"
#include <nlohmann/json.hpp>
#include <nlohmann/detail/conversions/to_json.hpp>

struct AccountId {
    std::string accountId;
};

struct AccountName {
    std::string name;
};

struct Amount {
    int32_t nano;
    std::string currency;
    int64_t units;
};

struct PayIn {
    AccountId accountId;
    Amount amount;
};

inline void to_json(nlohmann::json &j, const AccountId& acc) {
    j = nlohmann::json{{"accountId", acc.accountId}};
}

inline void from_json(const nlohmann::json &j, AccountId& acc) {
    j.at("accountId").get_to(acc.accountId);
}

inline void to_json(nlohmann::json &j, const AccountName& acc) {
    j = nlohmann::json{{"name", acc.name}};
}

inline void from_json(const nlohmann::json &j, AccountName& acc) {
    j.at("name").get_to(acc.name);
}

inline void to_json(nlohmann::json &j, const Amount& amount) {
    j = nlohmann::json{
        {"nano", amount.nano},
        {"currency", amount.currency},
        {"units", amount.units},
    };
}


inline void from_json(const nlohmann::json &j, Amount& amount) {
    j.at("nano").get_to(amount.nano);
    j.at("currency").get_to(amount.currency);
    j.at("units").get_to(amount.units);
}

inline void to_json(nlohmann::json &j, const PayIn& pay_in) {
    j = nlohmann::json{{"accountId", pay_in.accountId.accountId}, {"amount", pay_in.amount}};
}

inline void from_json(const nlohmann::json &j, PayIn& pay_in) {
    j.at("accountId").get_to(pay_in.accountId.accountId);
    j.at("amount").get_to(pay_in.amount);
}

int main()
{
    //    printf("123");
    //    InvestApiClient client("invest-public-api.tinkoff.ru:443", "t.9DjFbOC06vcgI5xplPO-NkKMUWHjIy8eamhr1rmdVt5YoDMYYWArqCZyrD_oGodNQ");
    //    InvestApiClient client("invest-public-api.tinkoff.ru:443", "t.xkHLcK7d-Bjz8YVC2UCnI6nOU0FQoXAVC0BI7S4hsCGMnJdOQtFB3QYVEv4xGnNH2fZ_cSLY6QaInRLcPSMayg");
    //    InvestApiClient client("sandbox-invest-public-api.tinkoff.ru:443", "t.oCCIjlXTnrRcIvWV8-W9c92ZVPwQbUyGuSfbX2l3a8O_X0VLKGJEWeIWoH2b0lhkveSPzRuZ355hlErOexHDkA");



    using namespace xxhr;

    std::cout << "/////////////////OPEN//////////////////////////////////////" << std::endl;
    nlohmann::json cat_name_in_json = nlohmann::json::object();
    cat_name_in_json = AccountName{.name = "qwerty"};
    std::cout << cat_name_in_json.dump(2) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    xxhr::sync sync1;
    xxhr::POST("https://sandbox-invest-public-api.tinkoff.ru/rest/tinkoff.public.invest.api.contract.v1.SandboxService/OpenSandboxAccount"s,
               Header {
                   {"accept", "application/json"},
                   {"Authorization", "Bearer t.oCCIjlXTnrRcIvWV8-W9c92ZVPwQbUyGuSfbX2l3a8O_X0VLKGJEWeIWoH2b0lhkveSPzRuZ355hlErOexHDkA"},
                   {"Content-Type", "application/json"}
               },
               Body {
                   cat_name_in_json.dump(2)
               },
               on_response = sync1
    );

    auto resp = sync1();

    nlohmann::json cat_id_in_json = nlohmann::json::object();
    cat_id_in_json = nlohmann::json::parse(resp.text);

    std::cout << "Open account Reply: " << resp.status_code << ": '" << resp.text << "'\n " <<
        resp.error << "\n Header:" << std::endl;
    for (const auto& [k, v] : resp.header) {
        std::cout << k << ": " << v << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "/////////////////GET//////////////////////////////////////" << std::endl;
    nlohmann::json cat_empty_in_json = nlohmann::json::object();
    std::cout << cat_empty_in_json.dump(2) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    xxhr::sync sync2;
    xxhr::POST("https://sandbox-invest-public-api.tinkoff.ru/rest/tinkoff.public.invest.api.contract.v1.SandboxService/GetSandboxAccounts"s,
               Header {
                   {"accept", "application/json"},
                   {"Authorization", "Bearer t.oCCIjlXTnrRcIvWV8-W9c92ZVPwQbUyGuSfbX2l3a8O_X0VLKGJEWeIWoH2b0lhkveSPzRuZ355hlErOexHDkA"},
                   {"Content-Type", "application/json"}
               },
               Body {
                   cat_empty_in_json.dump(2)
               },
               on_response = sync2
    );

    resp = sync2();
    std::cout << "Get accounts Reply: " << resp.status_code << ": '" << resp.text << "'\n " <<
        resp.error << "\n Header:" << std::endl;
    for (const auto& [k, v] : resp.header) {
        std::cout << k << ": " << v << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "/////////////////PAYIN//////////////////////////////////////" << std::endl;
    std::string account_id;
    cat_id_in_json["accountId"].get_to(account_id);
    nlohmann::json cat_payin_in_json = nlohmann::json::object();
    cat_payin_in_json = PayIn{.accountId{account_id},
                              .amount{.nano = 500000000, .currency = "rub", .units = 1360000}};
    std::cout << cat_payin_in_json.dump(2) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    xxhr::sync sync3;
    xxhr::POST("https://sandbox-invest-public-api.tinkoff.ru/rest/tinkoff.public.invest.api.contract.v1.SandboxService/SandboxPayIn"s,
               Header {
                   {"accept", "application/json"},
                   {"Authorization", "Bearer t.oCCIjlXTnrRcIvWV8-W9c92ZVPwQbUyGuSfbX2l3a8O_X0VLKGJEWeIWoH2b0lhkveSPzRuZ355hlErOexHDkA"},
                   {"Content-Type", "application/json"}
               },
               Body {
                   cat_payin_in_json.dump(2)
               },
               on_response = sync3
    );
    resp = sync3();
    std::cout << "PayIn Reply: " << resp.status_code << ": '" << resp.text << "'\n " <<
        resp.error << "\n Header:" << std::endl;
    for (const auto& [k, v] : resp.header) {
        std::cout << k << ": " << v << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "/////////////////CLOSE//////////////////////////////////////" << std::endl;
    std::cout << cat_id_in_json.dump(2) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    xxhr::sync sync_n;
    xxhr::POST("https://sandbox-invest-public-api.tinkoff.ru/rest/tinkoff.public.invest.api.contract.v1.SandboxService/CloseSandboxAccount"s,
               Header {
                   {"accept", "application/json"},
                   {"Authorization", "Bearer t.oCCIjlXTnrRcIvWV8-W9c92ZVPwQbUyGuSfbX2l3a8O_X0VLKGJEWeIWoH2b0lhkveSPzRuZ355hlErOexHDkA"},
                   {"Content-Type", "application/json"}
               },
               Body {
                   cat_id_in_json.dump(2)
               },
               on_response = sync_n
    );
    resp = sync_n();
    std::cout << "Close account Reply: " << resp.status_code << ": '" << resp.text << "'\n " <<
        resp.error << "\n Header:" << std::endl;
    for (const auto& [k, v] : resp.header) {
        std::cout << k << ": " << v << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;


    return 0;
}

/*
on_response = [&](auto&& resp) {
                   std::cout << "Reply: " << resp.status_code << ": '" << resp.text << "', " <<
                       resp.error << ", header:" << std::endl;
                   for (const auto& [k, v] : resp.header) {
                       std::cout << k << ": " << v << std::endl;
                   }
               }
 */
