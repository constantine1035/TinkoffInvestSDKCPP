#pragma once

#include "../protofiles/instruments.pb.h"
#include "google/protobuf/message.h"
#include <grpcpp/grpcpp.h>
#include "based_service.h"
#include <string.h>

using grpc::Channel;
using namespace ::tinkoff::public_::invest::api::contract::v1;

class InstrumentsService : public BasedService {

public:
    InstrumentsService(const std::string &token);
    /// Метод получения расписания торгов торговых площадок
    TradingSchedulesResponse TradingSchedules(const std::string &exchange, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    /// Метод получения облигации по её идентификатору
    BondResponse BondBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод получения списка облигаций
    BondsResponse Bonds(InstrumentStatus instrumentStatus);
    /// Метод получения графика выплат купонов по облигации
    GetBondCouponsResponse GetBondCoupons(const std::string  &figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    /// Метод получения событий по облигации
    GetBondEventsResponse GetBondEvents(std::string instrument_id, GetBondEventsRequest.EventType type, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos)
    /// Метод получения валюты по её идентификатору
    CurrencyResponse CurrencyBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод получения списка валют
    CurrenciesResponse Currencies(InstrumentStatus instrumentStatus);
    /// Метод получения инвестиционного фонда по его идентификатору
    EtfResponse EtfBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод получения списка инвестиционных фондов
    EtfResponse Etfs(InstrumentStatus instrumentStatus);
    /// Метод получения фьючерса по его идентификатору
    FutureResponse FutureBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод получения списка фьючерсов
    FuturesResponse Futures(InstrumentStatus instrumentStatus);
    OptionResponse OptionBy();
    OptionsResponse Options();
    OptionsResponse OptionsBy();
    /// Метод получения акции по её идентификатору
    ShareResponse ShareBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод получения списка акций
    SharesResponse Shares(InstrumentStatus instrumentStatus);
    IndicativesResponse Indicatives();
    /// Метод получения накопленного купонного дохода по облигации
    GetAccruedInterestsResponse GetAccruedInterests(const std::string  &figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    /// Метод получения размера гарантийного обеспечения по фьючерсам
    GetFuturesMarginResponse GetFuturesMargin(const std::string  &figi);
    /// Метод получения основной информации об инструменте
    InstrumentResponse GetInstrumentBy(InstrumentIdType idType, const std::string &classCode, const std::string &id);
    /// Метод для получения событий выплаты дивидендов по инструменту
    GetDividendsResponse GetDividends(const std::string  &figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos);
    /// Метод получения актива по его идентификатору
    ServiceReply GetAssetBy(const std::string  &id);
    /// Метод получения списка активов
    ServiceReply GetAssets();
    /// Метод получения избранных инструментов
    ServiceReply GetFavorites();
    /// Метод редактирования избранных инструментов
    ServiceReply EditFavorites(const std::vector<EditFavoritesRequestInstrument> &instruments, EditFavoritesActionType actionType);
};
