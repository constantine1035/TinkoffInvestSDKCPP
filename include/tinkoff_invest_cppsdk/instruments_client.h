#pragma once

/*
 * instruments_client.h
 *
 * This is a client class that use InstrumentsServiceApi.h functions.
 */

#include "tinkoff_invest_cppsdk/base_client.h"

#include "tinkoffinvestsdkcpp_export.h"

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

class InvestApiInstrumentsClient : public InvestApiBaseClient {
public:
    explicit InvestApiInstrumentsClient(const std::string &token, TradingMode trading_mode);

    ~InvestApiInstrumentsClient() override;

    /// Метод получения расписания торгов торговых площадок
    ServiceReply<V1TradingSchedulesResponse> TradingSchedules(
        utility::datetime from, utility::datetime to, const std::string &exchange = "none",
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1TradingSchedulesResponse> &)> callback = nullptr);

    /// Метод получения облигации по её идентификатору
    ServiceReply<V1BondResponse> BondBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, const std::string &class_code,
        const std::string &id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1BondResponse> &)> callback = nullptr);

    /// Метод получения списка облигаций
    ServiceReply<V1BondsResponse> Bonds(
        const std::shared_ptr<V1InstrumentStatus> instrument_status, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1BondsResponse> &)> callback = nullptr);

    /// Метод получения графика выплат купонов по облигации
    ServiceReply<V1GetBondCouponsResponse> GetBondCoupons(
        const std::string &figi, utility::datetime from, utility::datetime to,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetBondCouponsResponse> &)> callback = nullptr);

    /// Метод получения событий по облигации
    ServiceReply<V1GetBondEventsResponse> GetBondEvents(
        const std::string &instrument_id, const std::shared_ptr<GetBondEventsRequestEventType> type,
        utility::datetime from, utility::datetime to, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetBondEventsResponse> &)> callback = nullptr);

    /// Метод получения валюты по её идентификатору
    ServiceReply<V1CurrencyResponse> CurrencyBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, const std::string &class_code,
        const std::string &id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1CurrencyResponse> &)> callback = nullptr);

    /// Метод получения списка валют
    ServiceReply<V1CurrenciesResponse> Currencies(
        const std::shared_ptr<V1InstrumentStatus> instrument_status, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1CurrenciesResponse> &)> callback = nullptr);

    /// Метод получения инвестиционного фонда по его идентификатору
    ServiceReply<V1EtfResponse> EtfBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, const std::string &class_code,
        const std::string &id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1EtfResponse> &)> callback = nullptr);

    /// Метод получения списка инвестиционных фондов
    ServiceReply<V1EtfsResponse> Etfs(
        const std::shared_ptr<V1InstrumentStatus> instrument_status, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1EtfsResponse> &)> callback = nullptr);

    /// Метод получения фьючерса по его идентификатору
    ServiceReply<V1FutureResponse> FutureBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, const std::string &class_code,
        const std::string &id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1FutureResponse> &)> callback = nullptr);

    /// Метод получения списка фьючерсов
    ServiceReply<V1FuturesResponse> Futures(
        const std::shared_ptr<V1InstrumentStatus> instrument_status, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1FuturesResponse> &)> callback = nullptr);

    /// Метод получения опциона по его идентификатору
    ServiceReply<V1OptionResponse> OptionBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, const std::string &class_code,
        const std::string &id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1OptionResponse> &)> callback = nullptr);

    /// Deprecated Метод получения списка опционов
    ServiceReply<V1OptionsResponse> Options(
        const std::shared_ptr<V1InstrumentStatus> instrument_status, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1OptionsResponse> &)> callback = nullptr);

    /// Метод получения списка опционов
    ServiceReply<V1OptionsResponse> OptionsBy(
        const std::string &basic_asset_uid, const std::string &basic_asset_position_uid,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1OptionsResponse> &)> callback = nullptr);

    /// Метод получения акции по её идентификатору
    ServiceReply<V1ShareResponse> ShareBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, const std::string &class_code,
        const std::string &id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1ShareResponse> &)> callback = nullptr);

    /// Метод получения списка акций
    ServiceReply<V1SharesResponse> Shares(
        const std::shared_ptr<V1InstrumentStatus> instrument_status, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1SharesResponse> &)> callback = nullptr);

    /// Метод получения индикативных инструментов (индексов, товаров и др.)
    ServiceReply<V1IndicativesResponse> Indicatives(
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1IndicativesResponse> &)> callback = nullptr);

    /// Метод получения накопленного купонного дохода по облигации
    ServiceReply<V1GetAccruedInterestsResponse> GetAccruedInterests(
        const std::string &figi, utility::datetime from, utility::datetime to,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetAccruedInterestsResponse> &)> callback =
            nullptr);

    /// Метод получения размера гарантийного обеспечения по фьючерсам
    ServiceReply<V1GetFuturesMarginResponse> GetFuturesMargin(
        const std::string &figi, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetFuturesMarginResponse> &)> callback = nullptr);

    /// Метод получения основной информации об инструменте
    ServiceReply<V1InstrumentResponse> GetInstrumentBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, const std::string &class_code,
        const std::string &id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1InstrumentResponse> &)> callback = nullptr);

    /// Метод для получения событий выплаты дивидендов по инструменту
    ServiceReply<V1GetDividendsResponse> GetDividends(
        const std::string &figi, utility::datetime from, utility::datetime to,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetDividendsResponse> &)> callback = nullptr);

    /// Метод получения актива по его идентификатору
    ServiceReply<V1AssetResponse> GetAssetBy(
        const std::string &id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1AssetResponse> &)> callback = nullptr);

    /// Метод получения списка активов
    ServiceReply<V1AssetsResponse> GetAssets(
        const std::shared_ptr<V1InstrumentType> instrument_id_type, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1AssetsResponse> &)> callback = nullptr);

    /// Метод получения избранных инструментов
    ServiceReply<V1GetFavoritesResponse> GetFavorites(
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetFavoritesResponse> &)> callback = nullptr);

    /// Метод редактирования избранных инструментов
    ServiceReply<V1EditFavoritesResponse> EditFavorites(
        std::vector<std::shared_ptr<V1EditFavoritesRequestInstrument>> instruments,
        const std::shared_ptr<V1EditFavoritesActionType> action_type, bool is_async_req = true,
        int retry_max = 0,
        std::function<void(const ServiceReply<V1EditFavoritesResponse> &)> callback = nullptr);

    /// Метод получения списка стран
    ServiceReply<V1GetCountriesResponse> GetCountries(
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetCountriesResponse> &)> callback = nullptr);

    /// Метод поиска инструмента
    ServiceReply<V1FindInstrumentResponse> FindInstrument(
        const std::string &query, const std::shared_ptr<V1InstrumentType> instrument_kind,
        bool api_trade_available_flag, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1FindInstrumentResponse> &)> callback = nullptr);

    /// Метод получения списка брендов
    ServiceReply<V1GetBrandsResponse> GetBrands(
        const std::shared_ptr<V1Page> paging, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetBrandsResponse> &)> callback = nullptr);

    /// Метод получения бренда по его идентификатору
    ServiceReply<V1Brand> GetBrandBy(
        const std::string &id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1Brand> &)> callback = nullptr);

    /// Метод получения фундаментальных показателей по активу
    ServiceReply<V1GetAssetFundamentalsResponse> GetAssetFundamentals(
        std::vector<std::string> assets, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetAssetFundamentalsResponse> &)> callback =
            nullptr);

    /// Метод получения расписания выхода отчетностей эмитентов
    ServiceReply<V1GetAssetReportsResponse> GetAssetReports(
        const std::string &instrument_id, utility::datetime from, utility::datetime to,
        bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetAssetReportsResponse> &)> callback = nullptr);

    /// Метод получения мнения аналитиков по инструменту
    ServiceReply<V1GetConsensusForecastsResponse> GetConsensusForecasts(
        const std::shared_ptr<V1Page> paging, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetConsensusForecastsResponse> &)> callback =
            nullptr);

    /// Метод получения прогнозов инвестдомов по инструменту
    ServiceReply<V1GetForecastResponse> GetForecastBy(
        const std::string &instrument_id, bool is_async_req = true, int retry_max = 0,
        std::function<void(const ServiceReply<V1GetForecastResponse> &)> callback = nullptr);
};

}  // namespace tinkoff_invest_cppsdk