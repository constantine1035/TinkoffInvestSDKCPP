/*
#include "reply.h"
#include "users.pb.h"

using namespace tinkoff::public_::invest::api::contract::v1;

ServiceReply::ServiceReply() {}

ServiceReply::ServiceReply(const std::shared_ptr<google::protobuf::Message> proto_msg, const Status &status,
                           const std::string &error_message) :
    reply_ptr_(proto_msg), status_(status), error_message_(error_message) {}

const std::string ServiceReply::AccountID(const int i) {
    auto response = dynamic_cast<GetAccountsResponse*>(ptr().get());
    if (response && i < response->accounts_size()) {
        return response->accounts(i).id();
    } else {
        return "";
    }
}

const std::string ServiceReply::AccountName(const int i) {
    auto response = dynamic_cast<GetAccountsResponse*>(ptr().get());
    if (response && i < response->accounts_size()) {
        return response->accounts(i).name();
    } else {
        return "";
    }
}

int ServiceReply::AccountCount() {
    auto response = dynamic_cast<GetAccountsResponse*>(ptr().get());
    if (response) {
        return response->accounts_size();
    } else {
        return 0;
    }
}

const std::shared_ptr<google::protobuf::Message> ServiceReply::ptr() {
    return reply_ptr_;
}

const Status &ServiceReply::GetStatus() const {
    return status_;
}

const std::string &ServiceReply::GetErrorMessage() const {
    return error_message_;
}
 */