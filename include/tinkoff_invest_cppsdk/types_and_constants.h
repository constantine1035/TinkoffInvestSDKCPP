#pragma once

/*
 * types.h
 *
 * These are the SDK types and constants
 */

#include "tinkoffinvestsdkcpp_export.h"

#include <string>
#include <variant>

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

inline constexpr int kNumberOfServices = 10;
inline const std::string kDefaultBaseUrl = "https://invest-public-api.tinkoff.ru/rest";
inline const std::string kSandboxBaseUrl = "https://sandbox-invest-public-api.tinkoff.ru/rest";

using some_service_t =
    std::variant<InstrumentsServiceApi, MarketDataServiceApi, MarketDataStreamServiceApi,
                 OperationsServiceApi, OperationsStreamServiceApi, OrdersServiceApi,
                 OrdersStreamServiceApi, SandboxServiceApi, StopOrdersServiceApi, UsersServiceApi>;

}  // namespace tinkoff_invest_cppsdk