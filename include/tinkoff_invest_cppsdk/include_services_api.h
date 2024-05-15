#pragma once

#include "CppRestOpenAPIClient/api/InstrumentsServiceApi.h"
#include "CppRestOpenAPIClient/api/MarketDataServiceApi.h"
#include "tinkoff_invest_cppsdk/api/MarketDataStreamServiceWebSocketApi.h"
#include "CppRestOpenAPIClient/api/OperationsServiceApi.h"
#include "tinkoff_invest_cppsdk/api/OperationsStreamServiceWebSocketApi.h"
#include "CppRestOpenAPIClient/api/OrdersServiceApi.h"
#include "tinkoff_invest_cppsdk/api/OrdersStreamServiceWebSocketApi.h"
#include "CppRestOpenAPIClient/api/SandboxServiceApi.h"
#include "CppRestOpenAPIClient/api/StopOrdersServiceApi.h"
#include "CppRestOpenAPIClient/api/UsersServiceApi.h"

#include "tinkoffinvestsdkcpp_export.h"

/*
 * include_services_api.h
 *
 * This is a header to include all headers from CppRestOpenAPIClient/api
 * and tinkoff_invest_cppsdk/api
 */

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::InstrumentsServiceApi;
using org::openapitools::client::api::MarketDataServiceApi;
using tinkoff_invest_cppsdk::client::api::MarketDataStreamServiceWebSocketApi;
using org::openapitools::client::api::OperationsServiceApi;
using tinkoff_invest_cppsdk::client::api::OperationsStreamServiceWebSocketApi;
using org::openapitools::client::api::OrdersServiceApi;
using tinkoff_invest_cppsdk::client::api::OrdersStreamServiceWebSocketApi;
using org::openapitools::client::api::SandboxServiceApi;
using org::openapitools::client::api::StopOrdersServiceApi;
using org::openapitools::client::api::UsersServiceApi;

}  // namespace tinkoff_invest_cppsdk
