#include "tinkoff_invest_cppsdk/instruments_client.h"

namespace tinkoff_invest_cppsdk {

InvestApiInstrumentsClient::InvestApiInstrumentsClient(const std::string &token)
    : InvestApiBaseClient(token) {
    InitService<ServiceId::InstrumentsService, InstrumentsServiceApi>();
}

InvestApiInstrumentsClient::~InvestApiInstrumentsClient() {
}

ServiceReply<V1TradingSchedulesResponse> InvestApiInstrumentsClient::TradingSchedules(
    utility::datetime from, utility::datetime to, std::string exchange,
    bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1TradingSchedulesResponse> &)> callback) {

    auto body = std::make_shared<V1TradingSchedulesRequest>();
    body->setFrom(from);
    body->setTo(to);
    if (exchange != "none") {
        body->setExchange(exchange);
    }

    std::function<pplx::task<std::shared_ptr<V1TradingSchedulesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1TradingSchedulesRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceTradingSchedules;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения облигации по её идентификатору
ServiceReply<V1BondResponse> InvestApiInstrumentsClient::BondBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1BondResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1BondResponse>>(const InstrumentsServiceApi &,
                                                              std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceBondBy;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения списка облигаций
ServiceReply<V1BondsResponse> InvestApiInstrumentsClient::Bonds(
        const std::shared_ptr<V1InstrumentStatus> instrument_status,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1BondsResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1BondsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceBonds;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения графика выплат купонов по облигации
ServiceReply<V1GetBondCouponsResponse> InvestApiInstrumentsClient::GetBondCoupons(
    std::string figi, utility::datetime from, utility::datetime to,
    bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1GetBondCouponsResponse> &)> callback) {

    auto body = std::make_shared<V1GetBondCouponsRequest>();
    body->setFrom(from);
    body->setTo(to);
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetBondCouponsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetBondCouponsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBondCoupons;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения событий по облигации
ServiceReply<V1GetBondEventsResponse> InvestApiInstrumentsClient::GetBondEvents(
    std::string instrument_id, const std::shared_ptr<GetBondEventsRequestEventType> type,
    utility::datetime from, utility::datetime to,
    bool is_async_req, int retry_max,
    std::function<void(const ServiceReply<V1GetBondEventsResponse> &)> callback) {

    auto body = std::make_shared<V1GetBondEventsRequest>();
    body->setFrom(from);
    body->setTo(to);
    body->setInstrumentId(instrument_id);
    body->setType(type);

    std::function<pplx::task<std::shared_ptr<V1GetBondEventsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetBondEventsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBondEvents;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения валюты по её идентификатору
ServiceReply<V1CurrencyResponse> InvestApiInstrumentsClient::CurrencyBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1CurrencyResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1CurrencyResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceCurrencyBy;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения списка валют
ServiceReply<V1CurrenciesResponse> InvestApiInstrumentsClient::Currencies(
        const std::shared_ptr<V1InstrumentStatus> instrument_status,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1CurrenciesResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1CurrenciesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceCurrencies;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения инвестиционного фонда по его идентификатору
ServiceReply<V1EtfResponse> InvestApiInstrumentsClient::EtfBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1EtfResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1EtfResponse>>(const InstrumentsServiceApi &,
                                                             std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceEtfBy;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения списка инвестиционных фондов
ServiceReply<V1EtfsResponse> InvestApiInstrumentsClient::Etfs(
        const std::shared_ptr<V1InstrumentStatus> instrument_status,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1EtfsResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1EtfsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceEtfs;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения фьючерса по его идентификатору
ServiceReply<V1FutureResponse> InvestApiInstrumentsClient::FutureBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1FutureResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1FutureResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceFutureBy;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения списка фьючерсов
ServiceReply<V1FuturesResponse> InvestApiInstrumentsClient::Futures(
        const std::shared_ptr<V1InstrumentStatus> instrument_status,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1FuturesResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1FuturesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceFutures;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения опциона по его идентификатору
ServiceReply<V1OptionResponse> InvestApiInstrumentsClient::OptionBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1OptionResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1OptionResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceOptionBy;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Deprecated Метод получения списка опционов
ServiceReply<V1OptionsResponse> InvestApiInstrumentsClient::Options(
        const std::shared_ptr<V1InstrumentStatus> instrument_status,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1OptionsResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1OptionsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceOptions;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения списка опционов
ServiceReply<V1OptionsResponse> InvestApiInstrumentsClient::OptionsBy(
        std::string basic_asset_uid, std::string basic_asset_position_uid,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1OptionsResponse> &)> callback) {

    auto body = std::make_shared<V1FilterOptionsRequest>();
    body->setBasicAssetUid(basic_asset_uid);
    body->setBasicAssetPositionUid(basic_asset_position_uid);

    std::function<pplx::task<std::shared_ptr<V1OptionsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1FilterOptionsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceOptionsBy;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения акции по её идентификатору
ServiceReply<V1ShareResponse> InvestApiInstrumentsClient::ShareBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1ShareResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1ShareResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceShareBy;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения списка акций
ServiceReply<V1SharesResponse> InvestApiInstrumentsClient::Shares(
        const std::shared_ptr<V1InstrumentStatus> instrument_status,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1SharesResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentsRequest>();
    body->setInstrumentStatus(instrument_status);

    std::function<pplx::task<std::shared_ptr<V1SharesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceShares;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения индикативных инструментов (индексов, товаров и др.)
ServiceReply<V1IndicativesResponse> InvestApiInstrumentsClient::Indicatives(
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1IndicativesResponse> &)> callback) {

    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1IndicativesResponse>>(const InstrumentsServiceApi &,
                                                                     std::shared_ptr<Object>)>
        req = &InstrumentsServiceApi::instrumentsServiceIndicatives;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения накопленного купонного дохода по облигации
ServiceReply<V1GetAccruedInterestsResponse> InvestApiInstrumentsClient::GetAccruedInterests(
        std::string figi, utility::datetime from, utility::datetime to,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1GetAccruedInterestsResponse> &)> callback) {

    auto body = std::make_shared<V1GetAccruedInterestsRequest>();
    body->setFrom(from);
    body->setTo(to);
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetAccruedInterestsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetAccruedInterestsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAccruedInterests;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения размера гарантийного обеспечения по фьючерсам
ServiceReply<V1GetFuturesMarginResponse> InvestApiInstrumentsClient::GetFuturesMargin(
        std::string figi, bool is_async_req, int retry_max,
        std::function<void(const ServiceReply<V1GetFuturesMarginResponse> &)> callback) {

    auto body = std::make_shared<V1GetFuturesMarginRequest>();
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetFuturesMarginResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetFuturesMarginRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetFuturesMargin;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения основной информации об инструменте
ServiceReply<V1InstrumentResponse> InvestApiInstrumentsClient::GetInstrumentBy(
        const std::shared_ptr<V1InstrumentIdType> id_type, std::string class_code, std::string id,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1InstrumentResponse> &)> callback) {

    auto body = std::make_shared<V1InstrumentRequest>();
    body->setIdType(id_type);
    body->setId(id);
    body->setClassCode(class_code);

    std::function<pplx::task<std::shared_ptr<V1InstrumentResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1InstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetInstrumentBy;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод для получения событий выплаты дивидендов по инструменту
ServiceReply<V1GetDividendsResponse> InvestApiInstrumentsClient::GetDividends(
        std::string figi, utility::datetime from, utility::datetime to,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1GetDividendsResponse> &)> callback) {

    auto body = std::make_shared<V1GetDividendsRequest>();
    body->setFrom(from);
    body->setTo(to);
    body->setFigi(figi);

    std::function<pplx::task<std::shared_ptr<V1GetDividendsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetDividendsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetDividends;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения актива по его идентификатору
ServiceReply<V1AssetResponse> InvestApiInstrumentsClient::GetAssetBy(
        std::string id, bool is_async_req, int retry_max,
        std::function<void(const ServiceReply<V1AssetResponse> &)> callback) {

    auto body = std::make_shared<V1AssetRequest>();
    body->setId(id);

    std::function<pplx::task<std::shared_ptr<V1AssetResponse>>(const InstrumentsServiceApi &,
                                                               std::shared_ptr<V1AssetRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssetBy;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения списка активов
ServiceReply<V1AssetsResponse> InvestApiInstrumentsClient::GetAssets(
        const std::shared_ptr<V1InstrumentType> instrument_id_type,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1AssetsResponse> &)> callback) {

    auto body = std::make_shared<V1AssetsRequest>();
    body->setInstrumentType(instrument_id_type);

    std::function<pplx::task<std::shared_ptr<V1AssetsResponse>>(const InstrumentsServiceApi &,
                                                                std::shared_ptr<V1AssetsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssets;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения избранных инструментов
ServiceReply<V1GetFavoritesResponse> InvestApiInstrumentsClient::GetFavorites(
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1GetFavoritesResponse> &)> callback) {

    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetFavoritesResponse>>(const InstrumentsServiceApi &,
                                                                      std::shared_ptr<Object>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetFavorites;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод редактирования избранных инструментов
ServiceReply<V1EditFavoritesResponse> InvestApiInstrumentsClient::EditFavorites(
    std::vector<std::shared_ptr<V1EditFavoritesRequestInstrument>> instruments,
    const std::shared_ptr<V1EditFavoritesActionType> action_type,
    bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1EditFavoritesResponse> &)> callback) {

    auto body = std::make_shared<V1EditFavoritesRequest>();
    body->setInstruments(instruments);
    body->setActionType(action_type);

    std::function<pplx::task<std::shared_ptr<V1EditFavoritesResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1EditFavoritesRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceEditFavorites;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения списка стран
ServiceReply<V1GetCountriesResponse> InvestApiInstrumentsClient::GetCountries(
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1GetCountriesResponse> &)> callback) {

    auto body = std::make_shared<Object>();

    std::function<pplx::task<std::shared_ptr<V1GetCountriesResponse>>(const InstrumentsServiceApi &,
                                                                      std::shared_ptr<Object>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetCountries;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод поиска инструмента
ServiceReply<V1FindInstrumentResponse> InvestApiInstrumentsClient::FindInstrument(
        std::string query, const std::shared_ptr<V1InstrumentType> instrument_kind,
        bool api_trade_available_flag, bool is_async_req, int retry_max,
        std::function<void(const ServiceReply<V1FindInstrumentResponse> &)> callback) {

    auto body = std::make_shared<V1FindInstrumentRequest>();
    body->setQuery(query);
    body->setInstrumentKind(instrument_kind);
    body->setApiTradeAvailableFlag(api_trade_available_flag);

    std::function<pplx::task<std::shared_ptr<V1FindInstrumentResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1FindInstrumentRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceFindInstrument;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения списка брендов
ServiceReply<V1GetBrandsResponse> InvestApiInstrumentsClient::GetBrands(
        const std::shared_ptr<V1Page> paging, bool is_async_req, int retry_max,
        std::function<void(const ServiceReply<V1GetBrandsResponse> &)> callback) {

    auto body = std::make_shared<V1GetBrandsRequest>();
    body->setPaging(paging);

    std::function<pplx::task<std::shared_ptr<V1GetBrandsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetBrandsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBrands;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения бренда по его идентификатору
ServiceReply<V1Brand> InvestApiInstrumentsClient::GetBrandBy(
        std::string id, bool is_async_req, int retry_max,
        std::function<void(const ServiceReply<V1Brand> &)> callback) {

    auto body = std::make_shared<V1GetBrandRequest>();
    body->setId(id);

    std::function<pplx::task<std::shared_ptr<V1Brand>>(const InstrumentsServiceApi &,
                                                       std::shared_ptr<V1GetBrandRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetBrandBy;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения фундаментальных показателей по активу
ServiceReply<V1GetAssetFundamentalsResponse> InvestApiInstrumentsClient::GetAssetFundamentals(
        std::vector<std::string> assets, bool is_async_req, int retry_max,
        std::function<void(const ServiceReply<V1GetAssetFundamentalsResponse> &)> callback) {

    auto body = std::make_shared<V1GetAssetFundamentalsRequest>();
    body->setAssets(assets);

    std::function<pplx::task<std::shared_ptr<V1GetAssetFundamentalsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetAssetFundamentalsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssetFundamentals;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения расписания выхода отчетностей эмитентов
ServiceReply<V1GetAssetReportsResponse> InvestApiInstrumentsClient::GetAssetReports(
        std::string instrument_id, utility::datetime from, utility::datetime to,
        bool is_async_req, int retry_max, std::function<void(const ServiceReply<V1GetAssetReportsResponse> &)> callback) {

    auto body = std::make_shared<V1GetAssetReportsRequest>();
    body->setFrom(from);
    body->setTo(to);
    body->setInstrumentId(instrument_id);

    std::function<pplx::task<std::shared_ptr<V1GetAssetReportsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetAssetReportsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetAssetReports;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения мнения аналитиков по инструменту
ServiceReply<V1GetConsensusForecastsResponse> InvestApiInstrumentsClient::GetConsensusForecasts(
        const std::shared_ptr<V1Page> paging, bool is_async_req, int retry_max,
        std::function<void(const ServiceReply<V1GetConsensusForecastsResponse> &)> callback) {

    auto body = std::make_shared<V1GetConsensusForecastsRequest>();
    body->setPaging(paging);

    std::function<pplx::task<std::shared_ptr<V1GetConsensusForecastsResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetConsensusForecastsRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetConsensusForecasts;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

/// Метод получения прогнозов инвестдомов по инструменту
ServiceReply<V1GetForecastResponse> InvestApiInstrumentsClient::GetForecastBy(
        std::string instrument_id, bool is_async_req, int retry_max,
        std::function<void(const ServiceReply<V1GetForecastResponse> &)> callback) {

    auto body = std::make_shared<V1GetForecastRequest>();
    body->setInstrumentId(instrument_id);

    std::function<pplx::task<std::shared_ptr<V1GetForecastResponse>>(
        const InstrumentsServiceApi &, std::shared_ptr<V1GetForecastRequest>)>
        req = &InstrumentsServiceApi::instrumentsServiceGetForecastBy;
    if (is_async_req) {
        return MakeRequestAsync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
    }
    return MakeRequestSync<ServiceId::InstrumentsService>(req, body, retry_max, callback);
}

}  // namespace tinkoff_invest_cppsdk