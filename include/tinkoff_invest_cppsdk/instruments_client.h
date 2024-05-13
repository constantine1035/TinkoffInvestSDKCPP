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
    explicit InvestApiInstrumentsClient(const std::string &token);

    ~InvestApiInstrumentsClient() override;

    /// Метод получения расписания торгов торговых площадок
    ServiceReply<V1TradingSchedulesResponse> TradingSchedules(std::string exchange,
                                                              int64_t fromseconds,
                                                              int32_t frommilisecs, int64_t toseconds,
                                                              int32_t tomilisecs);

    /// Метод получения облигации по её идентификатору
    ServiceReply<V1BondResponse> BondBy(const std::shared_ptr<V1InstrumentIdType> id_type,
                                        std::string class_code, std::string id);

    /// Метод получения списка облигаций
    ServiceReply<V1BondsResponse> Bonds(
        const std::shared_ptr<V1InstrumentStatus> instrument_status);

    /// Метод получения графика выплат купонов по облигации
    ServiceReply<V1GetBondCouponsResponse> GetBondCoupons(std::string figi, int64_t fromseconds,
                                                          int32_t frommilisecs, int64_t toseconds,
                                                          int32_t tomilisecs);

    /// Метод получения событий по облигации
    ServiceReply<V1GetBondEventsResponse> GetBondEvents(
        std::string instrument_id, const std::shared_ptr<GetBondEventsRequestEventType> type,
        int64_t fromseconds, int32_t frommilisecs, int64_t toseconds, int32_t tomilisecs);

    /// Метод получения валюты по её идентификатору
    ServiceReply<V1CurrencyResponse> CurrencyBy(const std::shared_ptr<V1InstrumentIdType> id_type,
                                                std::string class_code, std::string id);

    /// Метод получения списка валют
    ServiceReply<V1CurrenciesResponse> Currencies(
        const std::shared_ptr<V1InstrumentStatus> instrument_status);

    /// Метод получения инвестиционного фонда по его идентификатору
    ServiceReply<V1EtfResponse> EtfBy(const std::shared_ptr<V1InstrumentIdType> id_type,
                                      std::string class_code, std::string id);

    /// Метод получения списка инвестиционных фондов
    ServiceReply<V1EtfsResponse> Etfs(const std::shared_ptr<V1InstrumentStatus> instrument_status);

    /// Метод получения фьючерса по его идентификатору
    ServiceReply<V1FutureResponse> FutureBy(const std::shared_ptr<V1InstrumentIdType> id_type,
                                            std::string class_code, std::string id);

    /// Метод получения списка фьючерсов
    ServiceReply<V1FuturesResponse> Futures(
        const std::shared_ptr<V1InstrumentStatus> instrument_status);

    /// Метод получения опциона по его идентификатору
    ServiceReply<V1OptionResponse> OptionBy(const std::shared_ptr<V1InstrumentIdType> id_type,
                                            std::string class_code, std::string id);

    /// Deprecated Метод получения списка опционов
    ServiceReply<V1OptionsResponse> Options(
        const std::shared_ptr<V1InstrumentStatus> instrument_status);

    /// Метод получения списка опционов
    ServiceReply<V1OptionsResponse> OptionsBy(std::string basic_asset_uid,
                                              std::string basic_asset_position_uid);

    /// Метод получения акции по её идентификатору
    ServiceReply<V1ShareResponse> ShareBy(const std::shared_ptr<V1InstrumentIdType> id_type,
                                          std::string class_code, std::string id);

    /// Метод получения списка акций
    ServiceReply<V1SharesResponse> Shares(
        const std::shared_ptr<V1InstrumentStatus> instrument_status);

    /// Метод получения индикативных инструментов (индексов, товаров и др.)
    ServiceReply<V1IndicativesResponse> Indicatives();

    /// Метод получения накопленного купонного дохода по облигации
    ServiceReply<V1GetAccruedInterestsResponse> GetAccruedInterests(std::string figi,
                                                                    int64_t fromseconds,
                                                                    int32_t frommilisecs,
                                                                    int64_t toseconds,
                                                                    int32_t tomilisecs);

    /// Метод получения размера гарантийного обеспечения по фьючерсам
    ServiceReply<V1GetFuturesMarginResponse> GetFuturesMargin(std::string figi);

    /// Метод получения основной информации об инструменте
    ServiceReply<V1InstrumentResponse> GetInstrumentBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id);

    /// Метод для получения событий выплаты дивидендов по инструменту
    ServiceReply<V1GetDividendsResponse> GetDividends(std::string figi, int64_t fromseconds,
                                                      int32_t frommilisecs, int64_t toseconds,
                                                      int32_t tomilisecs);

    /// Метод получения актива по его идентификатору
    ServiceReply<V1AssetResponse> GetAssetBy(std::string id);

    /// Метод получения списка активов
    ServiceReply<V1AssetsResponse> GetAssets(
        const std::shared_ptr<V1InstrumentType> instrument_id_type);

    /// Метод получения избранных инструментов
    ServiceReply<V1GetFavoritesResponse> GetFavorites();

    /// Метод редактирования избранных инструментов
    ServiceReply<V1EditFavoritesResponse> EditFavorites(
        std::vector<std::shared_ptr<V1EditFavoritesRequestInstrument>> instruments,
        const std::shared_ptr<V1EditFavoritesActionType> action_type);

    /// Метод получения списка стран
    ServiceReply<V1GetCountriesResponse> GetCountries();

    /// Метод поиска инструмента
    ServiceReply<V1FindInstrumentResponse> FindInstrument(
        std::string query, const std::shared_ptr<V1InstrumentType> instrument_kind,
        bool api_trade_available_flag);

    /// Метод получения списка брендов
    ServiceReply<V1GetBrandsResponse> GetBrands(const std::shared_ptr<V1Page> paging);

    /// Метод получения бренда по его идентификатору
    ServiceReply<V1Brand> GetBrandBy(std::string id);

    /// Метод получения фундаментальных показателей по активу
    ServiceReply<V1GetAssetFundamentalsResponse> GetAssetFundamentals(
        std::vector<std::string> assets);

    /// Метод получения расписания выхода отчетностей эмитентов
    ServiceReply<V1GetAssetReportsResponse> GetAssetReports(std::string instrument_id,
                                                            int64_t fromseconds, int32_t frommilisecs,
                                                            int64_t toseconds, int32_t tomilisecs);

    /// Метод получения мнения аналитиков по инструменту
    ServiceReply<V1GetConsensusForecastsResponse> GetConsensusForecasts(
        const std::shared_ptr<V1Page> paging);

    /// Метод получения прогнозов инвестдомов по инструменту
    ServiceReply<V1GetForecastResponse> GetForecastBy(std::string instrument_id);
};

}  // namespace tinkoff_invest_cppsdk