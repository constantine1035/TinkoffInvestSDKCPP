#pragma once

#include <grpc++/grpc++.h>
#include <functional>
#include "google/protobuf/message.h"

using grpc::Status;

class ServiceReply{
public:
        ServiceReply();

        ServiceReply(const std::shared_ptr<google::protobuf::Message> proto_msg, const Status& status, const std::string& error_message = "");

        int AccountCount();

        const std::string AccountID(const int i);

        const std::string AccountName(const int i);

        const std::shared_ptr<google::protobuf::Message> ptr();

        const Status& GetStatus() const;

        const std::string& GetErrorMessage() const;

        template<class T>
        static const ServiceReply PrepareServiceAnswer(const Status &status, const T &proto_msg, const std::string& error_message = "") {
            return (status.ok()) ?
                   ServiceReply(std::make_shared<T>(proto_msg), status) :
                   ServiceReply(nullptr, status, error_message);
        }

private:
        std::shared_ptr<google::protobuf::Message> reply_ptr_;
        Status status_;
        std::string error_message_;
};
