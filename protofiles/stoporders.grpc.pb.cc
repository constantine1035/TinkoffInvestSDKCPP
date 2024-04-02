// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: stoporders.proto

#include "stoporders.pb.h"
#include "stoporders.grpc.pb.h"

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

static const char* StopOrdersService_method_names[] = {
  "/tinkoff.public_.invest.api.contract.v1.StopOrdersService/PostStopOrder",
  "/tinkoff.public_.invest.api.contract.v1.StopOrdersService/GetStopOrders",
  "/tinkoff.public_.invest.api.contract.v1.StopOrdersService/CancelStopOrder",
};

std::unique_ptr< StopOrdersService::Stub> StopOrdersService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< StopOrdersService::Stub> stub(new StopOrdersService::Stub(channel, options));
  return stub;
}

StopOrdersService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_PostStopOrder_(StopOrdersService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetStopOrders_(StopOrdersService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CancelStopOrder_(StopOrdersService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status StopOrdersService::Stub::PostStopOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostStopOrderRequest& request, ::tinkoff::public_::invest::api::contract::v1::PostStopOrderResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::PostStopOrderRequest, ::tinkoff::public_::invest::api::contract::v1::PostStopOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_PostStopOrder_, context, request, response);
}

void StopOrdersService::Stub::async::PostStopOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostStopOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::PostStopOrderResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::PostStopOrderRequest, ::tinkoff::public_::invest::api::contract::v1::PostStopOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PostStopOrder_, context, request, response, std::move(f));
}

void StopOrdersService::Stub::async::PostStopOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostStopOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::PostStopOrderResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PostStopOrder_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::PostStopOrderResponse>* StopOrdersService::Stub::PrepareAsyncPostStopOrderRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostStopOrderRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::PostStopOrderResponse, ::tinkoff::public_::invest::api::contract::v1::PostStopOrderRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_PostStopOrder_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::PostStopOrderResponse>* StopOrdersService::Stub::AsyncPostStopOrderRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostStopOrderRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncPostStopOrderRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status StopOrdersService::Stub::GetStopOrders(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersRequest& request, ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersRequest, ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetStopOrders_, context, request, response);
}

void StopOrdersService::Stub::async::GetStopOrders(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersRequest, ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetStopOrders_, context, request, response, std::move(f));
}

void StopOrdersService::Stub::async::GetStopOrders(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetStopOrders_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersResponse>* StopOrdersService::Stub::PrepareAsyncGetStopOrdersRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersResponse, ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetStopOrders_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersResponse>* StopOrdersService::Stub::AsyncGetStopOrdersRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetStopOrdersRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status StopOrdersService::Stub::CancelStopOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderRequest& request, ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderRequest, ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CancelStopOrder_, context, request, response);
}

void StopOrdersService::Stub::async::CancelStopOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderRequest, ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CancelStopOrder_, context, request, response, std::move(f));
}

void StopOrdersService::Stub::async::CancelStopOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CancelStopOrder_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderResponse>* StopOrdersService::Stub::PrepareAsyncCancelStopOrderRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderResponse, ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CancelStopOrder_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderResponse>* StopOrdersService::Stub::AsyncCancelStopOrderRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCancelStopOrderRaw(context, request, cq);
  result->StartCall();
  return result;
}

StopOrdersService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StopOrdersService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StopOrdersService::Service, ::tinkoff::public_::invest::api::contract::v1::PostStopOrderRequest, ::tinkoff::public_::invest::api::contract::v1::PostStopOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StopOrdersService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::PostStopOrderRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::PostStopOrderResponse* resp) {
               return service->PostStopOrder(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StopOrdersService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StopOrdersService::Service, ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersRequest, ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StopOrdersService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersResponse* resp) {
               return service->GetStopOrders(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StopOrdersService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StopOrdersService::Service, ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderRequest, ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](StopOrdersService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderResponse* resp) {
               return service->CancelStopOrder(ctx, req, resp);
             }, this)));
}

StopOrdersService::Service::~Service() {
}

::grpc::Status StopOrdersService::Service::PostStopOrder(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostStopOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::PostStopOrderResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status StopOrdersService::Service::GetStopOrders(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetStopOrdersResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status StopOrdersService::Service::CancelStopOrder(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::CancelStopOrderResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace tinkoff
}  // namespace public_
}  // namespace invest
}  // namespace api
}  // namespace contract
}  // namespace v1

