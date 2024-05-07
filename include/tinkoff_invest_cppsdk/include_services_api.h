#pragma once

#include "CppRestOpenAPIClient/api/InstrumentsServiceApi.h"
#include "CppRestOpenAPIClient/api/MarketDataServiceApi.h"
#include "CppRestOpenAPIClient/api/MarketDataStreamServiceApi.h"
#include "CppRestOpenAPIClient/api/OperationsServiceApi.h"
#include "CppRestOpenAPIClient/api/OperationsStreamServiceApi.h"
#include "CppRestOpenAPIClient/api/OrdersServiceApi.h"
#include "CppRestOpenAPIClient/api/OrdersStreamServiceApi.h"
#include "CppRestOpenAPIClient/api/SandboxServiceApi.h"
#include "CppRestOpenAPIClient/api/StopOrdersServiceApi.h"
#include "CppRestOpenAPIClient/api/UsersServiceApi.h"

#include "tinkoffinvestsdkcpp_export.h"

/*
 * include_services_api.h
 *
 * This is a header to include all headers from CppRestOpenAPIClient/api
 */

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

using org::openapitools::client::api::InstrumentsServiceApi;
using org::openapitools::client::api::MarketDataServiceApi;
using org::openapitools::client::api::MarketDataStreamServiceApi;
using org::openapitools::client::api::OperationsServiceApi;
using org::openapitools::client::api::OperationsStreamServiceApi;
using org::openapitools::client::api::OrdersServiceApi;
using org::openapitools::client::api::OrdersStreamServiceApi;
using org::openapitools::client::api::SandboxServiceApi;
using org::openapitools::client::api::StopOrdersServiceApi;
using org::openapitools::client::api::UsersServiceApi;

}  // namespace tinkoff_invest_cppsdk
