#pragma once

/*
 * types.h
 *
 * These are the SDK types and constants
 */

#include "tinkoff_invest_cppsdk/include_services_api.h"

#include "tinkoffinvestsdkcpp_export.h"

#include <string>
#include <variant>

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

inline constexpr int kNumberOfServices = 10;
inline constexpr int kUnaryLimitsSize = 10;
inline constexpr int kStreamLimitsSize = 4;
inline constexpr int kSubscriptionLimit = 300;
inline constexpr int kPingDelay = 120000;
inline const std::string kDefaultBaseUrl = "https://invest-public-api.tinkoff.ru/rest";
inline const std::string kSandboxBaseUrl = "https://sandbox-invest-public-api.tinkoff.ru/rest";
inline const std::string kWebSocketBaseUrl = "wss://invest-public-api.tinkoff.ru/ws";

using some_service_t =
    std::variant<InstrumentsServiceApi, MarketDataServiceApi, MarketDataStreamServiceWebSocketApi,
                 OperationsServiceApi, OperationsStreamServiceWebSocketApi, OrdersServiceApi,
                 OrdersStreamServiceWebSocketApi, SandboxServiceApi, StopOrdersServiceApi,
                 UsersServiceApi>;

}  // namespace tinkoff_invest_cppsdk