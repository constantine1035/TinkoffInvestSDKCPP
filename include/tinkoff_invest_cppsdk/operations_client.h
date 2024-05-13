#pragma once

/*
 * instruments_client.h
 *
 * This is a client class that use InstrumentsServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiOperationsClient : public InvestApiBaseClient {
public:
    explicit InvestApiOperationsClient(const std::string &token);

    ~InvestApiOperationsClient() override;

    /// Метод получения списка операций по счёту.При работе с данным методом необходимо учитывать
    /// особенности взаимодействия с данным методом.
    ServiceReply<V1OperationsResponse> GetOperations(std::string account_id, int64_t fromseconds,
                                                     int32_t frommilisecs, int64_t toseconds,
                                                     int32_t tomilisecs, std::string figi,
                                                     const std::shared_ptr<V1OperationState> state);

    /// Метод получения портфеля по счёту.
    ServiceReply<V1PortfolioResponse> GetPortfolio(
        std::string account_id, const std::shared_ptr<PortfolioRequestCurrencyRequest> currency);

    /// Метод получения списка позиций по счёту.
    ServiceReply<V1PositionsResponse> GetPositions(std::string account_id);

    /// Метод получения доступного остатка для вывода средств.
    ServiceReply<V1WithdrawLimitsResponse> GetWithdrawLimits(std::string account_id);

    /// Метод получения брокерского отчёта
    ServiceReply<V1BrokerReportResponse> GetBrokerReport(
        const std::shared_ptr<V1GenerateBrokerReportRequest> generate_broker_request,
        const std::shared_ptr<V1GetBrokerReportRequest> get_broker_request);

    /// Метод получения отчёта "Справка о доходах за пределами РФ".
    ServiceReply<V1GetDividendsForeignIssuerResponse> GetDividendsForeignIssuer(
        const std::shared_ptr<V1GenerateDividendsForeignIssuerReportRequest>
            generate_div_foreign_issuer_report,
        const std::shared_ptr<V1GetDividendsForeignIssuerReportRequest>
            get_div_foreign_issuer_report);

    /// Метод получения списка операций по счёту с пагинацией. При работе с данным методом
    /// необходимо учитывать особенности взаимодействия с данным методом.
    ServiceReply<V1GetOperationsByCursorResponse> GetOperationsByCursor(
        std::string account_id, std::string instrument_id, int64_t fromseconds, int32_t frommilisecs,
        int64_t toseconds, int32_t tomilisecs, std::string cursor, int32_t limit,
        std::vector<std::shared_ptr<V1OperationType>> operation_types, V1OperationState state,
        bool without_comissions, bool without_trades, bool without_overnights);
};

}  // namespace tinkoff_invest_cppsdk