// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: operations.proto

#include "operations.pb.h"
#include "operations.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace tinkoff {
namespace public_ {
namespace invest {
namespace api {
namespace contract {
namespace v1 {

static const char* OperationsService_method_names[] = {
  "/tinkoff.public_.invest.api.contract.v1.OperationsService/GetOperations",
  "/tinkoff.public_.invest.api.contract.v1.OperationsService/GetPortfolio",
  "/tinkoff.public_.invest.api.contract.v1.OperationsService/GetPositions",
  "/tinkoff.public_.invest.api.contract.v1.OperationsService/GetWithdrawLimits",
  "/tinkoff.public_.invest.api.contract.v1.OperationsService/GetBrokerReport",
  "/tinkoff.public_.invest.api.contract.v1.OperationsService/GetDividendsForeignIssuer",
  "/tinkoff.public_.invest.api.contract.v1.OperationsService/GetOperationsByCursor",
};

std::unique_ptr< OperationsService::Stub> OperationsService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< OperationsService::Stub> stub(new OperationsService::Stub(channel, options));
  return stub;
}

OperationsService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetOperations_(OperationsService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetPortfolio_(OperationsService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetPositions_(OperationsService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetWithdrawLimits_(OperationsService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetBrokerReport_(OperationsService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetDividendsForeignIssuer_(OperationsService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetOperationsByCursor_(OperationsService_method_names[6], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status OperationsService::Stub::GetOperations(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::OperationsRequest& request, ::tinkoff::public_::invest::api::contract::v1::OperationsResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::OperationsRequest, ::tinkoff::public_::invest::api::contract::v1::OperationsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetOperations_, context, request, response);
}

void OperationsService::Stub::async::GetOperations(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::OperationsRequest* request, ::tinkoff::public_::invest::api::contract::v1::OperationsResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::OperationsRequest, ::tinkoff::public_::invest::api::contract::v1::OperationsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetOperations_, context, request, response, std::move(f));
}

void OperationsService::Stub::async::GetOperations(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::OperationsRequest* request, ::tinkoff::public_::invest::api::contract::v1::OperationsResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetOperations_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::OperationsResponse>* OperationsService::Stub::PrepareAsyncGetOperationsRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::OperationsRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::OperationsResponse, ::tinkoff::public_::invest::api::contract::v1::OperationsRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetOperations_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::OperationsResponse>* OperationsService::Stub::AsyncGetOperationsRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::OperationsRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetOperationsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OperationsService::Stub::GetPortfolio(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PortfolioRequest& request, ::tinkoff::public_::invest::api::contract::v1::PortfolioResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::PortfolioRequest, ::tinkoff::public_::invest::api::contract::v1::PortfolioResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetPortfolio_, context, request, response);
}

void OperationsService::Stub::async::GetPortfolio(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PortfolioRequest* request, ::tinkoff::public_::invest::api::contract::v1::PortfolioResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::PortfolioRequest, ::tinkoff::public_::invest::api::contract::v1::PortfolioResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPortfolio_, context, request, response, std::move(f));
}

void OperationsService::Stub::async::GetPortfolio(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PortfolioRequest* request, ::tinkoff::public_::invest::api::contract::v1::PortfolioResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPortfolio_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::PortfolioResponse>* OperationsService::Stub::PrepareAsyncGetPortfolioRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PortfolioRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::PortfolioResponse, ::tinkoff::public_::invest::api::contract::v1::PortfolioRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetPortfolio_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::PortfolioResponse>* OperationsService::Stub::AsyncGetPortfolioRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PortfolioRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetPortfolioRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OperationsService::Stub::GetPositions(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PositionsRequest& request, ::tinkoff::public_::invest::api::contract::v1::PositionsResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::PositionsRequest, ::tinkoff::public_::invest::api::contract::v1::PositionsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetPositions_, context, request, response);
}

void OperationsService::Stub::async::GetPositions(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PositionsRequest* request, ::tinkoff::public_::invest::api::contract::v1::PositionsResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::PositionsRequest, ::tinkoff::public_::invest::api::contract::v1::PositionsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPositions_, context, request, response, std::move(f));
}

void OperationsService::Stub::async::GetPositions(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PositionsRequest* request, ::tinkoff::public_::invest::api::contract::v1::PositionsResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPositions_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::PositionsResponse>* OperationsService::Stub::PrepareAsyncGetPositionsRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PositionsRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::PositionsResponse, ::tinkoff::public_::invest::api::contract::v1::PositionsRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetPositions_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::PositionsResponse>* OperationsService::Stub::AsyncGetPositionsRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PositionsRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetPositionsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OperationsService::Stub::GetWithdrawLimits(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsRequest& request, ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsRequest, ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetWithdrawLimits_, context, request, response);
}

void OperationsService::Stub::async::GetWithdrawLimits(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsRequest* request, ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsRequest, ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetWithdrawLimits_, context, request, response, std::move(f));
}

void OperationsService::Stub::async::GetWithdrawLimits(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsRequest* request, ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetWithdrawLimits_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsResponse>* OperationsService::Stub::PrepareAsyncGetWithdrawLimitsRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsResponse, ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetWithdrawLimits_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsResponse>* OperationsService::Stub::AsyncGetWithdrawLimitsRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetWithdrawLimitsRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OperationsService::Stub::GetBrokerReport(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::BrokerReportRequest& request, ::tinkoff::public_::invest::api::contract::v1::BrokerReportResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::BrokerReportRequest, ::tinkoff::public_::invest::api::contract::v1::BrokerReportResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetBrokerReport_, context, request, response);
}

void OperationsService::Stub::async::GetBrokerReport(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::BrokerReportRequest* request, ::tinkoff::public_::invest::api::contract::v1::BrokerReportResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::BrokerReportRequest, ::tinkoff::public_::invest::api::contract::v1::BrokerReportResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetBrokerReport_, context, request, response, std::move(f));
}

void OperationsService::Stub::async::GetBrokerReport(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::BrokerReportRequest* request, ::tinkoff::public_::invest::api::contract::v1::BrokerReportResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetBrokerReport_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::BrokerReportResponse>* OperationsService::Stub::PrepareAsyncGetBrokerReportRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::BrokerReportRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::BrokerReportResponse, ::tinkoff::public_::invest::api::contract::v1::BrokerReportRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetBrokerReport_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::BrokerReportResponse>* OperationsService::Stub::AsyncGetBrokerReportRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::BrokerReportRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetBrokerReportRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OperationsService::Stub::GetDividendsForeignIssuer(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerRequest& request, ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerRequest, ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetDividendsForeignIssuer_, context, request, response);
}

void OperationsService::Stub::async::GetDividendsForeignIssuer(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerRequest, ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetDividendsForeignIssuer_, context, request, response, std::move(f));
}

void OperationsService::Stub::async::GetDividendsForeignIssuer(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetDividendsForeignIssuer_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerResponse>* OperationsService::Stub::PrepareAsyncGetDividendsForeignIssuerRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerResponse, ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetDividendsForeignIssuer_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerResponse>* OperationsService::Stub::AsyncGetDividendsForeignIssuerRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetDividendsForeignIssuerRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OperationsService::Stub::GetOperationsByCursor(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorRequest& request, ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorRequest, ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetOperationsByCursor_, context, request, response);
}

void OperationsService::Stub::async::GetOperationsByCursor(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorRequest, ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetOperationsByCursor_, context, request, response, std::move(f));
}

void OperationsService::Stub::async::GetOperationsByCursor(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetOperationsByCursor_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorResponse>* OperationsService::Stub::PrepareAsyncGetOperationsByCursorRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorResponse, ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetOperationsByCursor_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorResponse>* OperationsService::Stub::AsyncGetOperationsByCursorRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetOperationsByCursorRaw(context, request, cq);
  result->StartCall();
  return result;
}

OperationsService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OperationsService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OperationsService::Service, ::tinkoff::public_::invest::api::contract::v1::OperationsRequest, ::tinkoff::public_::invest::api::contract::v1::OperationsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OperationsService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::OperationsRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::OperationsResponse* resp) {
               return service->GetOperations(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OperationsService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OperationsService::Service, ::tinkoff::public_::invest::api::contract::v1::PortfolioRequest, ::tinkoff::public_::invest::api::contract::v1::PortfolioResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OperationsService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::PortfolioRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::PortfolioResponse* resp) {
               return service->GetPortfolio(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OperationsService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OperationsService::Service, ::tinkoff::public_::invest::api::contract::v1::PositionsRequest, ::tinkoff::public_::invest::api::contract::v1::PositionsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OperationsService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::PositionsRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::PositionsResponse* resp) {
               return service->GetPositions(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OperationsService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OperationsService::Service, ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsRequest, ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OperationsService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsResponse* resp) {
               return service->GetWithdrawLimits(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OperationsService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OperationsService::Service, ::tinkoff::public_::invest::api::contract::v1::BrokerReportRequest, ::tinkoff::public_::invest::api::contract::v1::BrokerReportResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OperationsService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::BrokerReportRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::BrokerReportResponse* resp) {
               return service->GetBrokerReport(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OperationsService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OperationsService::Service, ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerRequest, ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OperationsService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerResponse* resp) {
               return service->GetDividendsForeignIssuer(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OperationsService_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OperationsService::Service, ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorRequest, ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OperationsService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorResponse* resp) {
               return service->GetOperationsByCursor(ctx, req, resp);
             }, this)));
}

OperationsService::Service::~Service() {
}

::grpc::Status OperationsService::Service::GetOperations(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::OperationsRequest* request, ::tinkoff::public_::invest::api::contract::v1::OperationsResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OperationsService::Service::GetPortfolio(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::PortfolioRequest* request, ::tinkoff::public_::invest::api::contract::v1::PortfolioResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OperationsService::Service::GetPositions(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::PositionsRequest* request, ::tinkoff::public_::invest::api::contract::v1::PositionsResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OperationsService::Service::GetWithdrawLimits(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsRequest* request, ::tinkoff::public_::invest::api::contract::v1::WithdrawLimitsResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OperationsService::Service::GetBrokerReport(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::BrokerReportRequest* request, ::tinkoff::public_::invest::api::contract::v1::BrokerReportResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OperationsService::Service::GetDividendsForeignIssuer(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetDividendsForeignIssuerResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OperationsService::Service::GetOperationsByCursor(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetOperationsByCursorResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* OperationsStreamService_method_names[] = {
  "/tinkoff.public_.invest.api.contract.v1.OperationsStreamService/PortfolioStream",
  "/tinkoff.public_.invest.api.contract.v1.OperationsStreamService/PositionsStream",
};

std::unique_ptr< OperationsStreamService::Stub> OperationsStreamService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< OperationsStreamService::Stub> stub(new OperationsStreamService::Stub(channel, options));
  return stub;
}

OperationsStreamService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_PortfolioStream_(OperationsStreamService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_PositionsStream_(OperationsStreamService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  {}

::grpc::ClientReader< ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamResponse>* OperationsStreamService::Stub::PortfolioStreamRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamRequest& request) {
  return ::grpc::internal::ClientReaderFactory< ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamResponse>::Create(channel_.get(), rpcmethod_PortfolioStream_, context, request);
}

void OperationsStreamService::Stub::async::PortfolioStream(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamRequest* request, ::grpc::ClientReadReactor< ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_PortfolioStream_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamResponse>* OperationsStreamService::Stub::AsyncPortfolioStreamRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamResponse>::Create(channel_.get(), cq, rpcmethod_PortfolioStream_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamResponse>* OperationsStreamService::Stub::PrepareAsyncPortfolioStreamRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamResponse>::Create(channel_.get(), cq, rpcmethod_PortfolioStream_, context, request, false, nullptr);
}

::grpc::ClientReader< ::tinkoff::public_::invest::api::contract::v1::PositionsStreamResponse>* OperationsStreamService::Stub::PositionsStreamRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PositionsStreamRequest& request) {
  return ::grpc::internal::ClientReaderFactory< ::tinkoff::public_::invest::api::contract::v1::PositionsStreamResponse>::Create(channel_.get(), rpcmethod_PositionsStream_, context, request);
}

void OperationsStreamService::Stub::async::PositionsStream(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PositionsStreamRequest* request, ::grpc::ClientReadReactor< ::tinkoff::public_::invest::api::contract::v1::PositionsStreamResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::tinkoff::public_::invest::api::contract::v1::PositionsStreamResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_PositionsStream_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::tinkoff::public_::invest::api::contract::v1::PositionsStreamResponse>* OperationsStreamService::Stub::AsyncPositionsStreamRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PositionsStreamRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::tinkoff::public_::invest::api::contract::v1::PositionsStreamResponse>::Create(channel_.get(), cq, rpcmethod_PositionsStream_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::tinkoff::public_::invest::api::contract::v1::PositionsStreamResponse>* OperationsStreamService::Stub::PrepareAsyncPositionsStreamRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PositionsStreamRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::tinkoff::public_::invest::api::contract::v1::PositionsStreamResponse>::Create(channel_.get(), cq, rpcmethod_PositionsStream_, context, request, false, nullptr);
}

OperationsStreamService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OperationsStreamService_method_names[0],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< OperationsStreamService::Service, ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamRequest, ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamResponse>(
          [](OperationsStreamService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamRequest* req,
             ::grpc::ServerWriter<::tinkoff::public_::invest::api::contract::v1::PortfolioStreamResponse>* writer) {
               return service->PortfolioStream(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OperationsStreamService_method_names[1],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< OperationsStreamService::Service, ::tinkoff::public_::invest::api::contract::v1::PositionsStreamRequest, ::tinkoff::public_::invest::api::contract::v1::PositionsStreamResponse>(
          [](OperationsStreamService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::PositionsStreamRequest* req,
             ::grpc::ServerWriter<::tinkoff::public_::invest::api::contract::v1::PositionsStreamResponse>* writer) {
               return service->PositionsStream(ctx, req, writer);
             }, this)));
}

OperationsStreamService::Service::~Service() {
}

::grpc::Status OperationsStreamService::Service::PortfolioStream(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamRequest* request, ::grpc::ServerWriter< ::tinkoff::public_::invest::api::contract::v1::PortfolioStreamResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OperationsStreamService::Service::PositionsStream(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::PositionsStreamRequest* request, ::grpc::ServerWriter< ::tinkoff::public_::invest::api::contract::v1::PositionsStreamResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace tinkoff
}  // namespace public_
}  // namespace invest
}  // namespace api
}  // namespace contract
}  // namespace v1
