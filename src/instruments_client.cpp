#include "tinkoff_invest_cppsdk/instruments_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiInstrumentsClient::InvestApiInstrumentsClient(const std::string &token) : InvestApiBaseClient(token) {
}

InvestApiInstrumentsClient::~InvestApiInstrumentsClient() {
}

ServiceReply<V1TradingSchedulesResponse> InvestApiInstrumentsClient::TradingSchedules(std::string exchange, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();

    auto body = std::make_shared<V1TradingSchedulesRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    to.from_milliseconds();
    from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setExchange(exchange);

    std::function<pplx::task<std::shared_ptr<V1TradingSchedulesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1TradingSchedulesRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceTradingSchedules;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения облигации по её идентификатору
ServiceReply<V1BondResponse> InvestApiInstrumentsClient::BondBy(const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1BondResponse>>(const InstrumentsServiceApi &,
                                                              std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceBondBy;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения списка облигаций
ServiceReply<V1BondsResponse> InvestApiInstrumentsClient::Bonds(const std::shared_ptr<V1InstrumentStatus> instrument_status) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1BondsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceBonds;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения графика выплат купонов по облигации
ServiceReply<V1GetBondCouponsResponse> InvestApiInstrumentsClient::GetBondCoupons(std::string  figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1GetBondCouponsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    to.from_milliseconds();
    from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetBondCouponsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetBondCouponsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBondCoupons;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения событий по облигации
ServiceReply<V1GetBondEventsResponse> InvestApiInstrumentsClient::GetBondEvents(std::string instrument_id, const std::shared_ptr<GetBondEventsRequestEventType> type, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1GetBondEventsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    to.from_milliseconds();
    from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setInstrumentId(instrument_id);
    body->setType(type);

    std::function<pplx::task<std::shared_ptr<V1GetBondEventsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetBondEventsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBondEvents;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения валюты по её идентификатору
ServiceReply<V1CurrencyResponse> InvestApiInstrumentsClient::CurrencyBy(const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1CurrencyResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceCurrencyBy;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения списка валют
ServiceReply<V1CurrenciesResponse> InvestApiInstrumentsClient::Currencies(const std::shared_ptr<V1InstrumentStatus> instrument_status) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1CurrenciesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceCurrencies;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения инвестиционного фонда по его идентификатору
ServiceReply<V1EtfResponse> InvestApiInstrumentsClient::EtfBy(const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1EtfResponse>>(const InstrumentsServiceApi &,
                                                             std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceEtfBy;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения списка инвестиционных фондов
ServiceReply<V1EtfsResponse> InvestApiInstrumentsClient::Etfs(const std::shared_ptr<V1InstrumentStatus> instrument_status) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1EtfsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceEtfs;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения фьючерса по его идентификатору
ServiceReply<V1FutureResponse> InvestApiInstrumentsClient::FutureBy(const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1FutureResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceFutureBy;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения списка фьючерсов
ServiceReply<V1FuturesResponse> InvestApiInstrumentsClient::Futures(const std::shared_ptr<V1InstrumentStatus> instrument_status) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1FuturesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceFutures;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения опциона по его идентификатору
ServiceReply<V1OptionResponse> InvestApiInstrumentsClient::OptionBy(const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1OptionResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceOptionBy;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Deprecated Метод получения списка опционов
ServiceReply<V1OptionsResponse> InvestApiInstrumentsClient::Options(const std::shared_ptr<V1InstrumentStatus> instrument_status) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1OptionsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceOptions;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения списка опционов
ServiceReply<V1OptionsResponse> InvestApiInstrumentsClient::OptionsBy(std::string basic_asset_uid, std::string basic_asset_position_uid) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1FilterOptionsRequest>();
    body->setBasicAssetUid(basic_asset_uid);
    body->setBasicAssetPositionUid(basic_asset_position_uid);

    std::function<pplx::task<std::shared_ptr<V1OptionsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1FilterOptionsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceOptionsBy;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения акции по её идентификатору
ServiceReply<V1ShareResponse> InvestApiInstrumentsClient::ShareBy(const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1ShareResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceShareBy;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения списка акций
ServiceReply<V1SharesResponse> InvestApiInstrumentsClient::Shares(const std::shared_ptr<V1InstrumentStatus> instrument_status) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1SharesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceShares;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения индикативных инструментов (индексов, товаров и др.)
ServiceReply<V1IndicativesResponse> InvestApiInstrumentsClient::Indicatives() {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1IndicativesResponse>>(const InstrumentsServiceApi &,
                                                                     std::shared_ptr<Object>)>
        req = &InstrumentsServiceApi::instrumentsServiceIndicatives;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения накопленного купонного дохода по облигации
ServiceReply<V1GetAccruedInterestsResponse> InvestApiInstrumentsClient::GetAccruedInterests(std::string  figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1GetAccruedInterestsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    to.from_milliseconds();
    from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetAccruedInterestsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetAccruedInterestsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAccruedInterests;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения размера гарантийного обеспечения по фьючерсам
ServiceReply<V1GetFuturesMarginResponse> InvestApiInstrumentsClient::GetFuturesMargin(std::string figi) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1GetFuturesMarginRequest>();
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetFuturesMarginResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetFuturesMarginRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetFuturesMargin;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения основной информации об инструменте
ServiceReply<V1InstrumentResponse> InvestApiInstrumentsClient::GetInstrumentBy(const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1InstrumentResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetInstrumentBy;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод для получения событий выплаты дивидендов по инструменту
ServiceReply<V1GetDividendsResponse> InvestApiInstrumentsClient::GetDividends(std::string  figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1GetDividendsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    to.from_milliseconds();
    from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetDividendsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetDividendsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetDividends;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения актива по его идентификатору
ServiceReply<V1AssetResponse> InvestApiInstrumentsClient::GetAssetBy(std::string id) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1AssetRequest>();
    body->setId(id);

    std::function<pplx::task<std::shared_ptr<V1AssetResponse>>(const InstrumentsServiceApi &,
                                                               std::shared_ptr<V1AssetRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssetBy;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения списка активов
ServiceReply<V1AssetsResponse> InvestApiInstrumentsClient::GetAssets(const std::shared_ptr<V1InstrumentType> instrument_id_type) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1AssetsRequest>();
    body->setInstrumentType(instrument_id_type);

    std::function<pplx::task<std::shared_ptr<V1AssetsResponse>>(const InstrumentsServiceApi &,
                                                                std::shared_ptr<V1AssetsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssets;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения избранных инструментов
ServiceReply<V1GetFavoritesResponse> InvestApiInstrumentsClient::GetFavorites() {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetFavoritesResponse>>(const InstrumentsServiceApi &,
                                                                      std::shared_ptr<Object>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetFavorites;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод редактирования избранных инструментов
ServiceReply<V1EditFavoritesResponse> InvestApiInstrumentsClient::EditFavorites(std::vector<std::shared_ptr<V1EditFavoritesRequestInstrument>> instruments, const std::shared_ptr<V1EditFavoritesActionType> action_type) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1EditFavoritesRequest>();
    body->setInstruments(instruments);
    body->setActionType(action_type);

    std::function<pplx::task<std::shared_ptr<V1EditFavoritesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1EditFavoritesRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceEditFavorites;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения списка стран
ServiceReply<V1GetCountriesResponse> InvestApiInstrumentsClient::GetCountries() {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetCountriesResponse>>(const InstrumentsServiceApi &,
                                                                      std::shared_ptr<Object>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetCountries;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод поиска инструмента
ServiceReply<V1FindInstrumentResponse> InvestApiInstrumentsClient::FindInstrument(std::string query, const std::shared_ptr<V1InstrumentType> instrument_kind, bool api_trade_available_flag) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1FindInstrumentRequest>();
    body->setQuery(query);
    body->setInstrumentKind(instrument_kind);
    body->setApiTradeAvailableFlag(api_trade_available_flag);

    std::function<pplx::task<std::shared_ptr<V1FindInstrumentResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1FindInstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceFindInstrument;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения списка брендов
ServiceReply<V1GetBrandsResponse> InvestApiInstrumentsClient::GetBrands(const std::shared_ptr<V1Page> paging) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1GetBrandsRequest>();
    body->setPaging(paging);

    std::function<pplx::task<std::shared_ptr<V1GetBrandsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetBrandsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBrands;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения бренда по его идентификатору
ServiceReply<V1Brand> InvestApiInstrumentsClient::GetBrandBy(std::string id) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1GetBrandRequest>();
    body->setId(id);

    std::function<pplx::task<std::shared_ptr<V1Brand>>(const InstrumentsServiceApi &,
                                                       std::shared_ptr<V1GetBrandRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBrandBy;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения фундаментальных показателей по активу
ServiceReply<V1GetAssetFundamentalsResponse> InvestApiInstrumentsClient::GetAssetFundamentals(std::vector<std::string> assets) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1GetAssetFundamentalsRequest>();
    body->setAssets(assets);

    std::function<pplx::task<std::shared_ptr<V1GetAssetFundamentalsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetAssetFundamentalsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssetFundamentals;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения расписания выхода отчетностей эмитентов
ServiceReply<V1GetAssetReportsResponse> InvestApiInstrumentsClient::GetAssetReports(std::string instrument_id, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1GetAssetReportsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    to.from_milliseconds();
    from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setInstrumentId(instrument_id);

    std::function<pplx::task<std::shared_ptr<V1GetAssetReportsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetAssetReportsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssetReports;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения мнения аналитиков по инструменту
ServiceReply<V1GetConsensusForecastsResponse> InvestApiInstrumentsClient::GetConsensusForecasts(const std::shared_ptr<V1Page> paging) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1GetConsensusForecastsRequest>();
    body->setPaging(paging);

    std::function<pplx::task<std::shared_ptr<V1GetConsensusForecastsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetConsensusForecastsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetConsensusForecasts;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

/// Метод получения прогнозов инвестдомов по инструменту
ServiceReply<V1GetForecastResponse> InvestApiInstrumentsClient::GetForecastBy(std::string instrument_id) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
    auto body = std::make_shared<V1GetForecastRequest>();
    body->setInstrumentId(instrument_id);

    std::function<pplx::task<std::shared_ptr<V1GetForecastResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetForecastRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetForecastBy;
    return MakeRequest<ServiceId::InstrumentsService>(body, req);
}

}