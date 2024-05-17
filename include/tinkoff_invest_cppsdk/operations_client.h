#pragma once

/*
 * instruments_client.h
 *
 * This is a client class that use InstrumentsServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiOperationsClient : virtual public InvestApiBaseClient {
public:
    explicit InvestApiOperationsClient(const std::string &token, TradingMode trading_mode);

    ~InvestApiOperationsClient() override;

    /// Метод получения списка операций по счёту.При работе с данным методом необходимо учитывать
    /// особенности взаимодействия с данным методом.
    ServiceReply<V1OperationsResponse> GetOperations(
        const std::string &account_id, utility::datetime from, utility::datetime to,
        const std::string &figi, const std::shared_ptr<V1OperationState> state,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1OperationsResponse> &)> callback = nullptr);

    /// Метод получения портфеля по счёту.
    ServiceReply<V1PortfolioResponse> GetPortfolio(
        const std::string &account_id,
        const std::shared_ptr<PortfolioRequestCurrencyRequest> currency, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1PortfolioResponse> &)> callback = nullptr);

    /// Метод получения списка позиций по счёту.
    ServiceReply<V1PositionsResponse> GetPositions(
        const std::string &account_id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1PositionsResponse> &)> callback = nullptr);

    /// Метод получения доступного остатка для вывода средств.
    ServiceReply<V1WithdrawLimitsResponse> GetWithdrawLimits(
        const std::string &account_id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1WithdrawLimitsResponse> &)> callback = nullptr);

    /// Метод получения брокерского отчёта
    ServiceReply<V1BrokerReportResponse> GetBrokerReport(
        const std::shared_ptr<V1GenerateBrokerReportRequest> generate_broker_request,
        const std::shared_ptr<V1GetBrokerReportRequest> get_broker_request,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1BrokerReportResponse> &)> callback = nullptr);

    /// Метод получения отчёта "Справка о доходах за пределами РФ".
    ServiceReply<V1GetDividendsForeignIssuerResponse> GetDividendsForeignIssuer(
        const std::shared_ptr<V1GenerateDividendsForeignIssuerReportRequest>
            generate_div_foreign_issuer_report,
        const std::shared_ptr<V1GetDividendsForeignIssuerReportRequest>
            get_div_foreign_issuer_report,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetDividendsForeignIssuerResponse> &)> callback =
            nullptr);

    /// Метод получения списка операций по счёту с пагинацией. При работе с данным методом
    /// необходимо учитывать особенности взаимодействия с данным методом.
    ServiceReply<V1GetOperationsByCursorResponse> GetOperationsByCursor(
        const std::string &account_id, const std::string &instrument_id, utility::datetime from,
        utility::datetime to, const std::string &cursor, int32_t limit,
        std::vector<std::shared_ptr<V1OperationType>> operation_types, V1OperationState state,
        bool without_comissions, bool without_trades, bool without_overnights,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetOperationsByCursorResponse> &)> callback =
            nullptr);
};

}  // namespace tinkoff_invest_cppsdk