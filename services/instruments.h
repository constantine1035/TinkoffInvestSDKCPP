#pragma once

#include "based_service.h"
#include "common.pb.h"
#include <grpc++/grpc++.h>
#include "instruments.pb.h"
#include "instruments.grpc.pb.h"
#include "reply.h"

using grpc::Channel;
using tinkoff_invest_sdk_cpp_based_service::BasedService;

using namespace tinkoff::public_::invest::api::contract::v1;

class Instruments : public BasedService {

public:
    Instruments(std::shared_ptr<Channel> channel, const std::string &token);

    ~Instruments() = default;

    /// Метод получения расписания торгов торговых площадок
    ServiceReply TradingSchedules(std::string exchange, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);

    /// Метод получения облигации по её идентификатору
    ServiceReply BondBy(InstrumentIdType id_type, std::string class_code, std::string id);

    /// Метод получения списка облигаций
    ServiceReply Bonds(InstrumentStatus instrument_status);

    /// Метод получения графика выплат купонов по облигации
    ServiceReply GetBondCoupons(std::string  figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);

    /// Метод получения событий по облигации
    ServiceReply GetBondEvents(std::string instrument_id, GetBondEventsRequest_EventType type, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);

    /// Метод получения валюты по её идентификатору
    ServiceReply CurrencyBy(InstrumentIdType id_type, std::string class_code, std::string id);

    /// Метод получения списка валют
    ServiceReply Currencies(InstrumentStatus instrument_status);

    /// Метод получения инвестиционного фонда по его идентификатору
    ServiceReply EtfBy(InstrumentIdType id_type, std::string class_code, std::string id);

    /// Метод получения списка инвестиционных фондов
    ServiceReply Etfs(InstrumentStatus instrument_status);

    /// Метод получения фьючерса по его идентификатору
    ServiceReply FutureBy(InstrumentIdType id_type, std::string class_code, std::string id);

    /// Метод получения списка фьючерсов
    ServiceReply Futures(InstrumentStatus instrument_status);

    /// Метод получения опциона по его идентификатору
    ServiceReply OptionBy(InstrumentIdType id_type, std::string class_code, std::string id);

    /// Deprecated Метод получения списка опционов
    ServiceReply Options(InstrumentStatus instrument_status);

    /// Метод получения списка опционов
    ServiceReply OptionsBy(std::string basic_asset_uid, std::string basic_asset_position_uid);

    /// Метод получения акции по её идентификатору
    ServiceReply ShareBy(InstrumentIdType id_type, std::string class_code, std::string id);

    /// Метод получения списка акций
    ServiceReply Shares(InstrumentStatus instrument_status);

    /// Метод получения индикативных инструментов (индексов, товаров и др.)
    ServiceReply Indicatives();

    /// Метод получения накопленного купонного дохода по облигации
    ServiceReply GetAccruedInterests(std::string  figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);

    /// Метод получения размера гарантийного обеспечения по фьючерсам
    ServiceReply GetFuturesMargin(std::string figi, std::string instrument_id);

    /// Метод получения основной информации об инструменте
    ServiceReply GetInstrumentBy(InstrumentIdType id_type, std::string class_code, std::string id);

    /// Метод для получения событий выплаты дивидендов по инструменту
    ServiceReply GetDividends(std::string  figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);

    /// Метод получения актива по его идентификатору
    ServiceReply GetAssetBy(std::string id);

    /// Метод получения списка активов
    ServiceReply GetAssets(InstrumentType instrument_id_type);

    /// Метод получения избранных инструментов
    ServiceReply GetFavorites();

    /// Метод редактирования избранных инструментов
    ServiceReply EditFavorites(std::vector<EditFavoritesRequestInstrument> instruments, EditFavoritesActionType action_type);

    /// Метод получения списка стран
    ServiceReply GetCountries();

    /// Метод поиска инструмента
    ServiceReply FindInstrument(std::string query, InstrumentType instrument_kind, bool api_trade_available_flag);

    /// Метод получения списка брендов
    ServiceReply GetBrands(Page paging);

    /// Метод получения бренда по его идентификатору
    ServiceReply GetBrandBy(std::string id);

    /// Метод получения фундаментальных показателей по активу
    ServiceReply GetAssetFundamentals(std::vector<std::string> assets);

    /// Метод получения расписания выхода отчетностей эмитентов
    ServiceReply GetAssetReports(std::string instrument_id, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);

    /// Метод получения мнения аналитиков по инструменту
    ServiceReply GetConsensusForecasts(Page paging);

    /// Метод получения прогнозов инвестдомов по инструменту
    ServiceReply GetForecastBy(std::string instrument_id);

private:
    std::unique_ptr<InstrumentsService::Stub> instruments_service_;
};