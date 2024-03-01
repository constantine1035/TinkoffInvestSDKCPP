#pragma once

#include "../protofiles/instruments.pb.h"
#include "google/protobuf/message.h"
#include "reply.h"
#include <grpcpp/grpcpp.h>
#include "based_service.h"

using namespace std;
using namespace ::tinkoff::public_::invest::api::contract::v1;
using namespace tinkoff_invest_sdk_cpp_based_service;

class InstrumentsService : public BasedService {

public:
    InstrumentsService(const std::string &token);
    /// Метод получения расписания торгов торговых площадок
    ServiceReply TradingSchedules(const std::string &exchange, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    /// Метод получения облигации по её идентификатору
    ServiceReply BondBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод получения списка облигаций
    ServiceReply Bonds(InstrumentStatus instrumentStatus);
    /// Метод получения графика выплат купонов по облигации
    ServiceReply GetBondCoupons(const std::string  &figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    /// Метод получения событий по облигации
    ServiceReply GetBondEvents(std::string instrument_id, GetBondEventsRequest.EventType type, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos)
    /// Метод получения валюты по её идентификатору
    ServiceReply CurrencyBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод получения списка валют
    ServiceReply Currencies(InstrumentStatus instrumentStatus);
    /// Метод получения инвестиционного фонда по его идентификатору
    ServiceReply EtfBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод получения списка инвестиционных фондов
    ServiceReply Etfs(InstrumentStatus instrumentStatus);
    /// Метод получения фьючерса по его идентификатору
    ServiceReply FutureBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод получения списка фьючерсов
    ServiceReply Futures(InstrumentStatus instrumentStatus);
    /// Метод получения опциона по его идентификатору
    ServiceReply OptionBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Deprecated Метод получения списка опционов
    ServiceReply Options(InstrumentStatus instrumentStatus);
    /// Метод получения списка опционов
    ServiceReply OptionsBy(const std::string &basic_asset_uid, const std::string &basic_asset_position_uid);
    /// Метод получения акции по её идентификатору
    ServiceReply ShareBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод получения списка акций
    ServiceReply Shares(InstrumentStatus instrumentStatus);
    /// Метод получения индикативных инструментов (индексов, товаров и др.)
    ServiceReply Indicatives(const std::vector<IndicativeResponse> &instruments);
    /// Метод получения накопленного купонного дохода по облигации
    ServiceReply GetAccruedInterests(const std::string  &figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    /// Метод получения размера гарантийного обеспечения по фьючерсам
    ServiceReply GetFuturesMargin(const std::string  &figi);
    /// Метод получения основной информации об инструменте
    ServiceReply GetInstrumentBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод для получения событий выплаты дивидендов по инструменту
    ServiceReply GetDividends(const std::string  &figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    /// Метод получения актива по его идентификатору
    ServiceReply GetAssetBy(const std::string  &id);
    /// Метод получения списка активов
    ServiceReply GetAssets(InstrumentType instrument_id_type);
    /// Метод получения избранных инструментов
    ServiceReply GetFavorites(const std::vector<FavoriteInstrument> &favorite_instruments);
    /// Метод редактирования избранных инструментов
    ServiceReply EditFavorites(const std::vector<EditFavoritesRequestInstrument> &instruments, EditFavoritesActionType actionType);
    /// Метод получения списка стран
    ServiceReply GetCountries();
    /// Метод поиска инструмента
    ServiceReply FindInstrument();
    /// Метод получения списка брендов
    ServiceReply GetBrands();
    /// Метод получения бренда по его идентификатору
    ServiceReply GetBrandBy();
    /// Метод получения фундаментальных показателей по активу
    ServiceReply GetAssetFundamentals();
    /// Метод получения расписания выхода отчетностей эмитентов
    ServiceReply GetAssetReports();
    /// Метод получения мнения аналитиков по инструменту
    ServiceReply GetConsensusForecasts();
    /// Метод получения прогнозов инвестдомов по инструменту
    ServiceReply GetForecastBy();
};
