#pragma once

#include <grpcpp/grpcpp.h>
#include <functional>
#include "google/protobuf/message.h"

using grpc::Status;

class ServiceReply{
public:
        ServiceReply();

        ServiceReply(const std::shared_ptr<google::protobuf::Message> protoMsg, const Status& status, const std::string& error_message = "");
        
        int accountCount();
        
        const std::string accountID(const int i);
        
        const std::string accountName(const int i);
        
        const std::shared_ptr<google::protobuf::Message> ptr();

        const Status& GetStatus() const;

        const std::string& GetErrorMessage() const;

        template<class T>
        static const ServiceReply PrepareServiceAnswer(const Status &status, const T &protoMsg, const std::string& error_message = "") {
            return (status.ok()) ?
                   ServiceReply(std::make_shared<T>(protoMsg), status) :
                   ServiceReply(nullptr, status, error_message);
        }

private:
        std::shared_ptr<google::protobuf::Message> reply_ptr_;
        Status status_;
        std::string error_message_;
};
