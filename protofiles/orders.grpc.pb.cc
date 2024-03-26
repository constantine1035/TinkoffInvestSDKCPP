// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: orders.proto

#include "orders.pb.h"
#include "orders.grpc.pb.h"

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
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace tinkoff {
namespace public_ {
namespace invest {
namespace api {
namespace contract {
namespace v1 {

static const char* OrdersStreamService_method_names[] = {
  "/tinkoff.public_.invest.api.contract.v1.OrdersStreamService/TradesStream",
};

std::unique_ptr< OrdersStreamService::Stub> OrdersStreamService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< OrdersStreamService::Stub> stub(new OrdersStreamService::Stub(channel, options));
  return stub;
}

OrdersStreamService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_TradesStream_(OrdersStreamService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  {}

::grpc::ClientReader< ::tinkoff::public_::invest::api::contract::v1::TradesStreamResponse>* OrdersStreamService::Stub::TradesStreamRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::TradesStreamRequest& request) {
  return ::grpc::internal::ClientReaderFactory< ::tinkoff::public_::invest::api::contract::v1::TradesStreamResponse>::Create(channel_.get(), rpcmethod_TradesStream_, context, request);
}

void OrdersStreamService::Stub::async::TradesStream(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::TradesStreamRequest* request, ::grpc::ClientReadReactor< ::tinkoff::public_::invest::api::contract::v1::TradesStreamResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::tinkoff::public_::invest::api::contract::v1::TradesStreamResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_TradesStream_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::tinkoff::public_::invest::api::contract::v1::TradesStreamResponse>* OrdersStreamService::Stub::AsyncTradesStreamRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::TradesStreamRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::tinkoff::public_::invest::api::contract::v1::TradesStreamResponse>::Create(channel_.get(), cq, rpcmethod_TradesStream_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::tinkoff::public_::invest::api::contract::v1::TradesStreamResponse>* OrdersStreamService::Stub::PrepareAsyncTradesStreamRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::TradesStreamRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::tinkoff::public_::invest::api::contract::v1::TradesStreamResponse>::Create(channel_.get(), cq, rpcmethod_TradesStream_, context, request, false, nullptr);
}

OrdersStreamService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrdersStreamService_method_names[0],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< OrdersStreamService::Service, ::tinkoff::public_::invest::api::contract::v1::TradesStreamRequest, ::tinkoff::public_::invest::api::contract::v1::TradesStreamResponse>(
          [](OrdersStreamService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::TradesStreamRequest* req,
             ::grpc::ServerWriter<::tinkoff::public_::invest::api::contract::v1::TradesStreamResponse>* writer) {
               return service->TradesStream(ctx, req, writer);
             }, this)));
}

OrdersStreamService::Service::~Service() {
}

::grpc::Status OrdersStreamService::Service::TradesStream(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::TradesStreamRequest* request, ::grpc::ServerWriter< ::tinkoff::public_::invest::api::contract::v1::TradesStreamResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* OrdersService_method_names[] = {
  "/tinkoff.public_.invest.api.contract.v1.OrdersService/PostOrder",
  "/tinkoff.public_.invest.api.contract.v1.OrdersService/CancelOrder",
  "/tinkoff.public_.invest.api.contract.v1.OrdersService/GetOrderState",
  "/tinkoff.public_.invest.api.contract.v1.OrdersService/GetOrders",
  "/tinkoff.public_.invest.api.contract.v1.OrdersService/ReplaceOrder",
};

std::unique_ptr< OrdersService::Stub> OrdersService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< OrdersService::Stub> stub(new OrdersService::Stub(channel, options));
  return stub;
}

OrdersService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_PostOrder_(OrdersService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CancelOrder_(OrdersService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetOrderState_(OrdersService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetOrders_(OrdersService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ReplaceOrder_(OrdersService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status OrdersService::Stub::PostOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostOrderRequest& request, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::PostOrderRequest, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_PostOrder_, context, request, response);
}

void OrdersService::Stub::async::PostOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::PostOrderRequest, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PostOrder_, context, request, response, std::move(f));
}

void OrdersService::Stub::async::PostOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PostOrder_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse>* OrdersService::Stub::PrepareAsyncPostOrderRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostOrderRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse, ::tinkoff::public_::invest::api::contract::v1::PostOrderRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_PostOrder_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse>* OrdersService::Stub::AsyncPostOrderRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostOrderRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncPostOrderRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OrdersService::Stub::CancelOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelOrderRequest& request, ::tinkoff::public_::invest::api::contract::v1::CancelOrderResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::CancelOrderRequest, ::tinkoff::public_::invest::api::contract::v1::CancelOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CancelOrder_, context, request, response);
}

void OrdersService::Stub::async::CancelOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::CancelOrderResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::CancelOrderRequest, ::tinkoff::public_::invest::api::contract::v1::CancelOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CancelOrder_, context, request, response, std::move(f));
}

void OrdersService::Stub::async::CancelOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::CancelOrderResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CancelOrder_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::CancelOrderResponse>* OrdersService::Stub::PrepareAsyncCancelOrderRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelOrderRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::CancelOrderResponse, ::tinkoff::public_::invest::api::contract::v1::CancelOrderRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CancelOrder_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::CancelOrderResponse>* OrdersService::Stub::AsyncCancelOrderRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelOrderRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCancelOrderRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OrdersService::Stub::GetOrderState(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrderStateRequest& request, ::tinkoff::public_::invest::api::contract::v1::OrderState* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::GetOrderStateRequest, ::tinkoff::public_::invest::api::contract::v1::OrderState, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetOrderState_, context, request, response);
}

void OrdersService::Stub::async::GetOrderState(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrderStateRequest* request, ::tinkoff::public_::invest::api::contract::v1::OrderState* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::GetOrderStateRequest, ::tinkoff::public_::invest::api::contract::v1::OrderState, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetOrderState_, context, request, response, std::move(f));
}

void OrdersService::Stub::async::GetOrderState(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrderStateRequest* request, ::tinkoff::public_::invest::api::contract::v1::OrderState* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetOrderState_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::OrderState>* OrdersService::Stub::PrepareAsyncGetOrderStateRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrderStateRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::OrderState, ::tinkoff::public_::invest::api::contract::v1::GetOrderStateRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetOrderState_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::OrderState>* OrdersService::Stub::AsyncGetOrderStateRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrderStateRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetOrderStateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OrdersService::Stub::GetOrders(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrdersRequest& request, ::tinkoff::public_::invest::api::contract::v1::GetOrdersResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::GetOrdersRequest, ::tinkoff::public_::invest::api::contract::v1::GetOrdersResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetOrders_, context, request, response);
}

void OrdersService::Stub::async::GetOrders(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrdersRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetOrdersResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::GetOrdersRequest, ::tinkoff::public_::invest::api::contract::v1::GetOrdersResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetOrders_, context, request, response, std::move(f));
}

void OrdersService::Stub::async::GetOrders(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrdersRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetOrdersResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetOrders_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::GetOrdersResponse>* OrdersService::Stub::PrepareAsyncGetOrdersRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrdersRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::GetOrdersResponse, ::tinkoff::public_::invest::api::contract::v1::GetOrdersRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetOrders_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::GetOrdersResponse>* OrdersService::Stub::AsyncGetOrdersRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrdersRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetOrdersRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OrdersService::Stub::ReplaceOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::ReplaceOrderRequest& request, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tinkoff::public_::invest::api::contract::v1::ReplaceOrderRequest, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_ReplaceOrder_, context, request, response);
}

void OrdersService::Stub::async::ReplaceOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::ReplaceOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tinkoff::public_::invest::api::contract::v1::ReplaceOrderRequest, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ReplaceOrder_, context, request, response, std::move(f));
}

void OrdersService::Stub::async::ReplaceOrder(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::ReplaceOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ReplaceOrder_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse>* OrdersService::Stub::PrepareAsyncReplaceOrderRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::ReplaceOrderRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse, ::tinkoff::public_::invest::api::contract::v1::ReplaceOrderRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_ReplaceOrder_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse>* OrdersService::Stub::AsyncReplaceOrderRaw(::grpc::ClientContext* context, const ::tinkoff::public_::invest::api::contract::v1::ReplaceOrderRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncReplaceOrderRaw(context, request, cq);
  result->StartCall();
  return result;
}

OrdersService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrdersService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OrdersService::Service, ::tinkoff::public_::invest::api::contract::v1::PostOrderRequest, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OrdersService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::PostOrderRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse* resp) {
               return service->PostOrder(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrdersService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OrdersService::Service, ::tinkoff::public_::invest::api::contract::v1::CancelOrderRequest, ::tinkoff::public_::invest::api::contract::v1::CancelOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OrdersService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::CancelOrderRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::CancelOrderResponse* resp) {
               return service->CancelOrder(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrdersService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OrdersService::Service, ::tinkoff::public_::invest::api::contract::v1::GetOrderStateRequest, ::tinkoff::public_::invest::api::contract::v1::OrderState, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OrdersService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::GetOrderStateRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::OrderState* resp) {
               return service->GetOrderState(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrdersService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OrdersService::Service, ::tinkoff::public_::invest::api::contract::v1::GetOrdersRequest, ::tinkoff::public_::invest::api::contract::v1::GetOrdersResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OrdersService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::GetOrdersRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::GetOrdersResponse* resp) {
               return service->GetOrders(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrdersService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OrdersService::Service, ::tinkoff::public_::invest::api::contract::v1::ReplaceOrderRequest, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OrdersService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tinkoff::public_::invest::api::contract::v1::ReplaceOrderRequest* req,
             ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse* resp) {
               return service->ReplaceOrder(ctx, req, resp);
             }, this)));
}

OrdersService::Service::~Service() {
}

::grpc::Status OrdersService::Service::PostOrder(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::PostOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OrdersService::Service::CancelOrder(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::CancelOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::CancelOrderResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OrdersService::Service::GetOrderState(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrderStateRequest* request, ::tinkoff::public_::invest::api::contract::v1::OrderState* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OrdersService::Service::GetOrders(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::GetOrdersRequest* request, ::tinkoff::public_::invest::api::contract::v1::GetOrdersResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OrdersService::Service::ReplaceOrder(::grpc::ServerContext* context, const ::tinkoff::public_::invest::api::contract::v1::ReplaceOrderRequest* request, ::tinkoff::public_::invest::api::contract::v1::PostOrderResponse* response) {
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

