#pragma once

#include "reply.h"
#include "based_service.h"
#include <grpc++/grpc++.h>
#include "users.pb.h"
#include "common.pb.h"
#include "users.grpc.pb.h"

using grpc::Channel;
using tinkoff_invest_sdk_cpp_based_service::BasedService;

using namespace tinkoff::public_::invest::api::contract::v1;

class Users : public BasedService {
public:
    Users(std::shared_ptr<Channel> channel, const std::string &token);
    ~Users() = default;

    // Метод получения счетов пользователя: тело запроса — GetAccountsRequest, тело ответа — GetAccountsResponse
    ServiceReply GetAccounts();
    // Расчёт маржинальных показателей по счёту: тело запроса — GetMarginAttributesRequest, тело ответа — GetMarginAttributesResponse
    ServiceReply GetMarginAttributes(const std::string &account_id);
    // Запрос тарифа пользователя: тело запроса — GetUserTariffRequest, тело ответа — GetUserTariffResponse
    ServiceReply GetUserTariff();
    // Метод получения информации о пользователе: тело запроса — GetInfoRequest, тело ответа — GetInfoResponse
    ServiceReply GetInfo();

private:
    std::unique_ptr<UsersService::Stub> users_service_;
};
