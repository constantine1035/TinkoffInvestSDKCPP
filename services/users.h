#pragma once

#include "reply.h"
#include "customservice.h"
#include <grpcpp/grpcpp.h>
#include "../protofiles/users.pb.h"

using grpc::Channel;

using namespace tinkoff::public_::invest::api::contract::v1;

class Users : public CustomService {
public:
    Users(std::shared_ptr<Channel> channel, const std::string &token)
    ~Users() = default;

    // Метод получения счетов пользователя: тело запроса — GetAccountsRequest, тело ответа — GetAccountsResponse
    ServiceReply GetAccounts();
    // Расчёт маржинальных показателей по счёту: тело запроса — GetMarginAttributesRequest, тело ответа — GetMarginAttributesResponse
    ServiceReply GetMarginAttributes(const std::string &accountId);
    // Запрос тарифа пользователя: тело запроса — GetUserTariffRequest, тело ответа — GetUserTariffResponse
    ServiceReply GetUserTariff();
    // Метод получения информации о пользователе: тело запроса — GetInfoRequest, тело ответа — GetInfoResponse
    ServiceReply GetInfo();

private:
    std::unique_ptr<UsersService::Stub> users_service_;
};
