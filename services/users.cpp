#include "users.h"

Users::Users(std::shared_ptr<grpc::Channel> channel, const std::string &token) :
        BasedService(token)
        , users_service_(UsersService::NewStub(channel))
{}

ServiceReply Users::GetAccounts() {
    GetAccountsRequest request;
    GetAccountsResponse reply;
    Status status = users_service_->GetAccounts(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetAccountsResponse>(status, reply);
}

ServiceReply Users::GetMarginAttributes(const std::string &account_id) {
    GetMarginAttributesRequest request;
    request.set_account_id(account_id);
    GetMarginAttributesResponse reply;
    Status status = users_service_->GetMarginAttributes(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetMarginAttributesResponse>(status, reply);
}

ServiceReply Users::GetUserTariff() {
    GetUserTariffRequest request;
    GetUserTariffResponse reply;
    Status status = users_service_->GetUserTariff(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetUserTariffResponse>(status, reply);
}

ServiceReply Users::GetInfo() {
    GetInfoRequest request;
    GetInfoResponse reply;
    Status status = users_service_->GetInfo(MakeContext().get(), request, &reply);
    return ServiceReply::PrepareServiceAnswer<GetInfoResponse>(status, reply);
}