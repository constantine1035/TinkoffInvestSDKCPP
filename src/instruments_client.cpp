#include "tinkoff_invest_cppsdk/instruments_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiInstrumentsClient::InvestApiInstrumentsClient(const std::string &token)
    : InvestApiBaseClient(token) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
}

InvestApiInstrumentsClient::~InvestApiInstrumentsClient() {
}

ServiceReply<V1TradingSchedulesResponse> InvestApiInstrumentsClient::TradingSchedules(
    std::string exchange, int64_t fromseconds, int32_t fromnanos, int64_t toseconds,
    int32_t tonanos) const {
    

    auto body = std::make_shared<V1TradingSchedulesRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    //to.from_milliseconds();
    //from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setExchange(exchange);

    std::function<pplx::task<std::shared_ptr<V1TradingSchedulesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1TradingSchedulesRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceTradingSchedules;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения облигации по её идентификатору
ServiceReply<V1BondResponse> InvestApiInstrumentsClient::BondBy(
    const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) const {
    
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1BondResponse>>(const InstrumentsServiceApi &,
                                                              std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceBondBy;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения списка облигаций
ServiceReply<V1BondsResponse> InvestApiInstrumentsClient::Bonds(
    const std::shared_ptr<V1InstrumentStatus> instrument_status) const {
    
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1BondsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceBonds;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения графика выплат купонов по облигации
ServiceReply<V1GetBondCouponsResponse> InvestApiInstrumentsClient::GetBondCoupons(
    std::string figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) const {
    
    auto body = std::make_shared<V1GetBondCouponsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    //to.from_milliseconds();
    //from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetBondCouponsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetBondCouponsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBondCoupons;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения событий по облигации
ServiceReply<V1GetBondEventsResponse> InvestApiInstrumentsClient::GetBondEvents(
    std::string instrument_id, const std::shared_ptr<GetBondEventsRequestEventType> type,
    int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) const {
    
    auto body = std::make_shared<V1GetBondEventsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    //to.from_milliseconds();
    //from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setInstrumentId(instrument_id);
    body->setType(type);

    std::function<pplx::task<std::shared_ptr<V1GetBondEventsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetBondEventsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBondEvents;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения валюты по её идентификатору
ServiceReply<V1CurrencyResponse> InvestApiInstrumentsClient::CurrencyBy(
    const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) const {
    
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1CurrencyResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceCurrencyBy;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения списка валют
ServiceReply<V1CurrenciesResponse> InvestApiInstrumentsClient::Currencies(
    const std::shared_ptr<V1InstrumentStatus> instrument_status) const {
    
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1CurrenciesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceCurrencies;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения инвестиционного фонда по его идентификатору
ServiceReply<V1EtfResponse> InvestApiInstrumentsClient::EtfBy(
    const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) const {
    
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1EtfResponse>>(const InstrumentsServiceApi &,
                                                             std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceEtfBy;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения списка инвестиционных фондов
ServiceReply<V1EtfsResponse> InvestApiInstrumentsClient::Etfs(
    const std::shared_ptr<V1InstrumentStatus> instrument_status) const {
    
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1EtfsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceEtfs;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения фьючерса по его идентификатору
ServiceReply<V1FutureResponse> InvestApiInstrumentsClient::FutureBy(
    const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) const {
    
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1FutureResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceFutureBy;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения списка фьючерсов
ServiceReply<V1FuturesResponse> InvestApiInstrumentsClient::Futures(
    const std::shared_ptr<V1InstrumentStatus> instrument_status) const {
    
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1FuturesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceFutures;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения опциона по его идентификатору
ServiceReply<V1OptionResponse> InvestApiInstrumentsClient::OptionBy(
    const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) const {
    
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1OptionResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceOptionBy;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Deprecated Метод получения списка опционов
ServiceReply<V1OptionsResponse> InvestApiInstrumentsClient::Options(
    const std::shared_ptr<V1InstrumentStatus> instrument_status) const {
    
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1OptionsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceOptions;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения списка опционов
ServiceReply<V1OptionsResponse> InvestApiInstrumentsClient::OptionsBy(
    std::string basic_asset_uid, std::string basic_asset_position_uid) const {
    
    auto body = std::make_shared<V1FilterOptionsRequest>();
    body->setBasicAssetUid(basic_asset_uid);
    body->setBasicAssetPositionUid(basic_asset_position_uid);

    std::function<pplx::task<std::shared_ptr<V1OptionsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1FilterOptionsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceOptionsBy;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения акции по её идентификатору
ServiceReply<V1ShareResponse> InvestApiInstrumentsClient::ShareBy(
    const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) const {
    
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1ShareResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceShareBy;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения списка акций
ServiceReply<V1SharesResponse> InvestApiInstrumentsClient::Shares(
    const std::shared_ptr<V1InstrumentStatus> instrument_status) const {
    
    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1SharesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceShares;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения индикативных инструментов (индексов, товаров и др.)
ServiceReply<V1IndicativesResponse> InvestApiInstrumentsClient::Indicatives() const {
    
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1IndicativesResponse>>(const InstrumentsServiceApi &,
                                                                     std::shared_ptr<Object>)>
        req = &InstrumentsServiceApi::instrumentsServiceIndicatives;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения накопленного купонного дохода по облигации
ServiceReply<V1GetAccruedInterestsResponse> InvestApiInstrumentsClient::GetAccruedInterests(
    std::string figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) const {
    
    auto body = std::make_shared<V1GetAccruedInterestsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    //to.from_milliseconds();
    //from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetAccruedInterestsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetAccruedInterestsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAccruedInterests;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения размера гарантийного обеспечения по фьючерсам
ServiceReply<V1GetFuturesMarginResponse> InvestApiInstrumentsClient::GetFuturesMargin(
    std::string figi) const {
    
    auto body = std::make_shared<V1GetFuturesMarginRequest>();
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetFuturesMarginResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetFuturesMarginRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetFuturesMargin;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения основной информации об инструменте
ServiceReply<V1InstrumentResponse> InvestApiInstrumentsClient::GetInstrumentBy(
    const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id) const {
    
    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1InstrumentResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetInstrumentBy;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод для получения событий выплаты дивидендов по инструменту
ServiceReply<V1GetDividendsResponse> InvestApiInstrumentsClient::GetDividends(
    std::string figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) const {
    
    auto body = std::make_shared<V1GetDividendsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    //to.from_milliseconds();
    //from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetDividendsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetDividendsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetDividends;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения актива по его идентификатору
ServiceReply<V1AssetResponse> InvestApiInstrumentsClient::GetAssetBy(std::string id) const {
    
    auto body = std::make_shared<V1AssetRequest>();
    body->setId(id);

    std::function<pplx::task<std::shared_ptr<V1AssetResponse>>(const InstrumentsServiceApi &,
                                                               std::shared_ptr<V1AssetRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssetBy;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения списка активов
ServiceReply<V1AssetsResponse> InvestApiInstrumentsClient::GetAssets(
    const std::shared_ptr<V1InstrumentType> instrument_id_type) const {
    
    auto body = std::make_shared<V1AssetsRequest>();
    body->setInstrumentType(instrument_id_type);

    std::function<pplx::task<std::shared_ptr<V1AssetsResponse>>(const InstrumentsServiceApi &,
                                                                std::shared_ptr<V1AssetsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssets;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения избранных инструментов
ServiceReply<V1GetFavoritesResponse> InvestApiInstrumentsClient::GetFavorites() const {
    
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetFavoritesResponse>>(const InstrumentsServiceApi &,
                                                                      std::shared_ptr<Object>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetFavorites;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод редактирования избранных инструментов
ServiceReply<V1EditFavoritesResponse> InvestApiInstrumentsClient::EditFavorites(
    std::vector<std::shared_ptr<V1EditFavoritesRequestInstrument>> instruments,
    const std::shared_ptr<V1EditFavoritesActionType> action_type) const {
    
    auto body = std::make_shared<V1EditFavoritesRequest>();
    body->setInstruments(instruments);
    body->setActionType(action_type);

    std::function<pplx::task<std::shared_ptr<V1EditFavoritesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1EditFavoritesRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceEditFavorites;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения списка стран
ServiceReply<V1GetCountriesResponse> InvestApiInstrumentsClient::GetCountries() const {
    
    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetCountriesResponse>>(const InstrumentsServiceApi &,
                                                                      std::shared_ptr<Object>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetCountries;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод поиска инструмента
ServiceReply<V1FindInstrumentResponse> InvestApiInstrumentsClient::FindInstrument(
    std::string query, const std::shared_ptr<V1InstrumentType> instrument_kind,
    bool api_trade_available_flag) const {
    
    auto body = std::make_shared<V1FindInstrumentRequest>();
    body->setQuery(query);
    body->setInstrumentKind(instrument_kind);
    body->setApiTradeAvailableFlag(api_trade_available_flag);

    std::function<pplx::task<std::shared_ptr<V1FindInstrumentResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1FindInstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceFindInstrument;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения списка брендов
ServiceReply<V1GetBrandsResponse> InvestApiInstrumentsClient::GetBrands(
    const std::shared_ptr<V1Page> paging) const {
    
    auto body = std::make_shared<V1GetBrandsRequest>();
    body->setPaging(paging);

    std::function<pplx::task<std::shared_ptr<V1GetBrandsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetBrandsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBrands;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения бренда по его идентификатору
ServiceReply<V1Brand> InvestApiInstrumentsClient::GetBrandBy(std::string id) const {
    
    auto body = std::make_shared<V1GetBrandRequest>();
    body->setId(id);

    std::function<pplx::task<std::shared_ptr<V1Brand>>(const InstrumentsServiceApi &,
                                                       std::shared_ptr<V1GetBrandRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBrandBy;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения фундаментальных показателей по активу
ServiceReply<V1GetAssetFundamentalsResponse> InvestApiInstrumentsClient::GetAssetFundamentals(
    std::vector<std::string> assets) const {
    
    auto body = std::make_shared<V1GetAssetFundamentalsRequest>();
    body->setAssets(assets);

    std::function<pplx::task<std::shared_ptr<V1GetAssetFundamentalsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetAssetFundamentalsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssetFundamentals;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения расписания выхода отчетностей эмитентов
ServiceReply<V1GetAssetReportsResponse> InvestApiInstrumentsClient::GetAssetReports(
    std::string instrument_id, int64_t fromseconds, int32_t fromnanos, int64_t toseconds,
    int32_t tonanos) const {
    
    auto body = std::make_shared<V1GetAssetReportsRequest>();
    utility::datetime from;
    utility::datetime to;
    from.from_seconds(fromseconds);
    to.from_seconds(toseconds);
    //to.from_milliseconds();
    //from.from_milliseconds();
    body->setFrom(from);
    body->setTo(to);
    body->setInstrumentId(instrument_id);

    std::function<pplx::task<std::shared_ptr<V1GetAssetReportsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetAssetReportsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssetReports;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения мнения аналитиков по инструменту
ServiceReply<V1GetConsensusForecastsResponse> InvestApiInstrumentsClient::GetConsensusForecasts(
    const std::shared_ptr<V1Page> paging) const {
    
    auto body = std::make_shared<V1GetConsensusForecastsRequest>();
    body->setPaging(paging);

    std::function<pplx::task<std::shared_ptr<V1GetConsensusForecastsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetConsensusForecastsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetConsensusForecasts;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

/// Метод получения прогнозов инвестдомов по инструменту
ServiceReply<V1GetForecastResponse> InvestApiInstrumentsClient::GetForecastBy(
    std::string instrument_id) const {
    
    auto body = std::make_shared<V1GetForecastRequest>();
    body->setInstrumentId(instrument_id);

    std::function<pplx::task<std::shared_ptr<V1GetForecastResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetForecastRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetForecastBy;
    return MakeRequestAsync<ServiceId::InstrumentsService>(req, body);
}

}  // namespace tinkoff_invest_cppsdk