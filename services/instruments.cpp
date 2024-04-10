#include "instruments.h"
#include "protofiles/instruments.pb.h"

Instruments::Instruments(std::shared_ptr<Channel> channel, const std::string &token) :
    BasedService(token)
    ,instruments_service_(InstrumentsService::NewStub(channel))
{}

ServiceReply Instruments::TradingSchedules(std::string exchange, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    TradingSchedulesRequest request;
    TradingSchedulesResponse response;
    google::protobuf::Timestamp from;
    google::protobuf::Timestamp to;
    from.set_seconds(fromseconds);
    from.set_nanos(fromnanos);
    to.set_seconds(toseconds);
    to.set_nanos(tonanos);
    request.set_exchange(exchange);
    request.set_allocated_from(&from);
    request.set_allocated_to(&to);
    Status status = instruments_service_->TradingSchedules(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<TradingSchedulesResponse>(status, response);
}

ServiceReply Instruments::BondBy(InstrumentIdType id_type, std::string class_code, std::string id) {
    InstrumentRequest request;
    BondResponse response;
    request.set_id_type(id_type);
    request.set_class_code(class_code);
    request.set_id(id);
    Status status = instruments_service_->BondBy(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<BondResponse>(status, response);
}

ServiceReply Instruments::Bonds(InstrumentStatus instrument_status) {
    InstrumentsRequest request;
    BondsResponse response;
    request.set_instrument_status(instrument_status);
    Status status = instruments_service_->Bonds(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<BondsResponse>(status, response);
}

ServiceReply Instruments::GetBondCoupons(std::string figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    GetBondCouponsRequest request;
    GetBondCouponsResponse response;
    google::protobuf::Timestamp from;
    google::protobuf::Timestamp to;
    from.set_seconds(fromseconds);
    from.set_nanos(fromnanos);
    to.set_seconds(toseconds);
    to.set_nanos(tonanos);
    request.set_figi(figi);
    request.set_allocated_from(&from);
    request.set_allocated_to(&to);
    Status status = instruments_service_->GetBondCoupons(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetBondCouponsResponse>(status, response);
}

ServiceReply Instruments::GetBondEvents(std::string instrument_id, GetBondEventsRequest_EventType type, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    GetBondEventsRequest request;
    GetBondEventsResponse response;
    google::protobuf::Timestamp from;
    google::protobuf::Timestamp to;
    from.set_seconds(fromseconds);
    from.set_nanos(fromnanos);
    to.set_seconds(toseconds);
    to.set_nanos(tonanos);
    request.set_allocated_from(&from);
    request.set_allocated_to(&to);
    request.set_type(type);
    request.set_instrument_id(instrument_id);
    Status status = instruments_service_->GetBondEvents(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetBondEventsResponse>(status, response);
}

ServiceReply Instruments::CurrencyBy(InstrumentIdType id_type, std::string class_code, std::string id) {
    InstrumentRequest request;
    CurrencyResponse response;
    request.set_id_type(id_type);
    request.set_class_code(class_code);
    request.set_id(id);
    Status status = instruments_service_->CurrencyBy(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<CurrencyResponse>(status, response);
}

ServiceReply Instruments::Currencies(InstrumentStatus instrument_status) {
    InstrumentsRequest request;
    CurrenciesResponse response;
    request.set_instrument_status(instrument_status);
    Status status = instruments_service_->Currencies(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<CurrenciesResponse>(status, response);
}

ServiceReply Instruments::EtfBy(InstrumentIdType id_type, std::string class_code, std::string id) {
    InstrumentRequest request;
    EtfResponse response;
    request.set_id_type(id_type);
    request.set_class_code(class_code);
    request.set_id(id);
    Status status = instruments_service_->EtfBy(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<EtfResponse>(status, response);
}

ServiceReply Instruments::Etfs(InstrumentStatus instrument_status) {
    InstrumentsRequest request;
    EtfsResponse response;
    request.set_instrument_status(instrument_status);
    Status status = instruments_service_->Etfs(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<EtfsResponse>(status, response);
}

ServiceReply Instruments::FutureBy(InstrumentIdType id_type, std::string class_code, std::string id) {
    InstrumentRequest request;
    FutureResponse response;
    request.set_id_type(id_type);
    request.set_class_code(class_code);
    request.set_id(id);
    Status status = instruments_service_->FutureBy(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<FutureResponse>(status, response);
}

ServiceReply Instruments::Futures(InstrumentStatus instrument_status) {
    InstrumentsRequest request;
    FuturesResponse response;
    request.set_instrument_status(instrument_status);
    Status status = instruments_service_->Futures(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<FuturesResponse>(status, response);
}

ServiceReply Instruments::OptionBy(InstrumentIdType id_type, std::string class_code, std::string id) {
    InstrumentRequest request;
    OptionResponse response;
    request.set_id_type(id_type);
    request.set_class_code(class_code);
    request.set_id(id);
    Status status = instruments_service_->OptionBy(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<OptionResponse>(status, response);
}

ServiceReply Instruments::Options(InstrumentStatus instrument_status) {
    InstrumentsRequest request;
    OptionsResponse response;
    request.set_instrument_status(instrument_status);
    Status status = instruments_service_->Options(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<OptionsResponse>(status, response);
}

ServiceReply Instruments::OptionsBy(std::string basic_asset_uid, std::string basic_asset_position_uid) {
    FilterOptionsRequest request;
    OptionsResponse response;
    request.set_basic_asset_uid(basic_asset_uid);
    request.set_basic_asset_position_uid(basic_asset_position_uid);
    Status status = instruments_service_->OptionsBy(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<OptionsResponse>(status, response);
}

ServiceReply Instruments::ShareBy(InstrumentIdType id_type, std::string class_code, std::string id) {
    InstrumentRequest request;
    ShareResponse response;
    request.set_id_type(id_type);
    request.set_class_code(class_code);
    request.set_id(id);
    Status status = instruments_service_->ShareBy(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<ShareResponse>(status, response);
}

ServiceReply Instruments::Shares(InstrumentStatus instrument_status) {
    InstrumentsRequest request;
    SharesResponse response;
    request.set_instrument_status(instrument_status);
    Status status = instruments_service_->Shares(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<SharesResponse>(status, response);
}

ServiceReply Instruments::Indicatives() {
    IndicativesRequest request;
    IndicativesResponse response;
    Status status = instruments_service_->Indicatives(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<IndicativesResponse>(status, response);
}

ServiceReply Instruments::GetAccruedInterests(std::string figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    GetAccruedInterestsRequest request;
    GetAccruedInterestsResponse response;
    google::protobuf::Timestamp from;
    google::protobuf::Timestamp to;
    from.set_seconds(fromseconds);
    from.set_nanos(fromnanos);
    to.set_seconds(toseconds);
    to.set_nanos(tonanos);
    request.set_figi(figi);
    request.set_allocated_from(&from);
    request.set_allocated_to(&to);
    Status status = instruments_service_->GetAccruedInterests(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetAccruedInterestsResponse>(status, response);
}

ServiceReply Instruments::GetFuturesMargin(std::string figi, std::string instrument_id) {
    GetFuturesMarginRequest request;
    GetFuturesMarginResponse response;
    request.set_figi(figi);
    request.set_instrument_id(instrument_id);
    Status status = instruments_service_->GetFuturesMargin(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetFuturesMarginResponse>(status, response);
}

ServiceReply Instruments::GetInstrumentBy(InstrumentIdType id_type, std::string class_code, std::string id) {
    InstrumentRequest request;
    InstrumentResponse response;
    request.set_id_type(id_type);
    request.set_class_code(class_code);
    request.set_id(id);
    Status status = instruments_service_->GetInstrumentBy(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<InstrumentResponse>(status, response);
}

ServiceReply Instruments::GetDividends(std::string figi, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    GetDividendsRequest request;
    GetDividendsResponse response;
    google::protobuf::Timestamp from;
    google::protobuf::Timestamp to;
    from.set_seconds(fromseconds);
    from.set_nanos(fromnanos);
    to.set_seconds(toseconds);
    to.set_nanos(tonanos);
    request.set_figi(figi);
    request.set_allocated_from(&from);
    request.set_allocated_to(&to);
    Status status = instruments_service_->GetDividends(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetDividendsResponse>(status, response);
}

ServiceReply Instruments::GetAssetBy(std::string id) {
    AssetRequest request;
    AssetResponse response;
    request.set_id(id);
    Status status = instruments_service_->GetAssetBy(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<AssetResponse>(status, response);
}

ServiceReply Instruments::GetAssets(InstrumentType instrument_id_type) {
    AssetsRequest request;
    AssetsResponse response;
    request.set_instrument_type(instrument_id_type);
    Status status = instruments_service_->GetAssets(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<AssetsResponse>(status, response);
}

ServiceReply Instruments::GetFavorites() {
    GetFavoritesRequest request;
    GetFavoritesResponse response;
    Status status = instruments_service_->GetFavorites(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetFavoritesResponse>(status, response);
}

ServiceReply Instruments::EditFavorites(std::vector<EditFavoritesRequestInstrument> instruments, EditFavoritesActionType action_type) {
    EditFavoritesRequest request;
    EditFavoritesResponse response;
    request.set_action_type(action_type);
    for (auto instrument : instruments) {
        auto instrument_l = request.add_instruments();
        instrument_l->CopyFrom(instrument);
    }
    Status status = instruments_service_->EditFavorites(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<EditFavoritesResponse>(status, response);
}

ServiceReply Instruments::GetCountries() {
    GetCountriesRequest request;
    GetCountriesResponse response;
    Status status = instruments_service_->GetCountries(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetCountriesResponse>(status, response);
}

ServiceReply Instruments::FindInstrument(std::string query, InstrumentType instrument_kind, bool api_trade_available_flag) {
    FindInstrumentRequest request;
    FindInstrumentResponse response;
    request.set_query(query);
    request.set_instrument_kind(instrument_kind);
    request.set_api_trade_available_flag(api_trade_available_flag);
    Status status = instruments_service_->FindInstrument(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<FindInstrumentResponse>(status, response);
}

ServiceReply Instruments::GetBrands(Page paging) {
    GetBrandsRequest request;
    GetBrandsResponse response;
    request.set_allocated_paging(&paging);
    Status status = instruments_service_->GetBrands(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetBrandsResponse>(status, response);
}

ServiceReply Instruments::GetBrandBy(std::string id) {
    GetBrandRequest request;
    Brand response;
    request.set_id(id);
    Status status = instruments_service_->GetBrandBy(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<Brand>(status, response);
}

ServiceReply Instruments::GetAssetFundamentals(std::vector<std::string> assets) {
    GetAssetFundamentalsRequest request;
    GetAssetFundamentalsResponse response;
    for (auto asset : assets) {
        request.add_assets(asset);
    }
    Status status = instruments_service_->GetAssetFundamentals(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetAssetFundamentalsResponse>(status, response);
}

ServiceReply Instruments::GetAssetReports(std::string instrument_id, int64_t fromseconds, int32_t fromnanos, int64_t toseconds, int32_t tonanos) {
    GetAssetReportsRequest request;
    GetAssetReportsResponse response;
    google::protobuf::Timestamp from;
    google::protobuf::Timestamp to;
    from.set_seconds(fromseconds);
    from.set_nanos(fromnanos);
    to.set_seconds(toseconds);
    to.set_nanos(tonanos);
    request.set_allocated_from(&from);
    request.set_allocated_to(&to);
    request.set_instrument_id(instrument_id);
    Status status = instruments_service_->GetAssetReports(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetAssetReportsResponse>(status, response);
}

ServiceReply Instruments::GetConsensusForecasts(Page paging) {
    GetConsensusForecastsRequest request;
    GetConsensusForecastsResponse response;
    request.set_allocated_paging(&paging);
    Status status = instruments_service_->GetConsensusForecasts(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetConsensusForecastsResponse>(status, response);
}

ServiceReply Instruments::GetForecastBy(std::string instrument_id) {
    GetForecastRequest request;
    GetForecastResponse response;
    request.set_instrument_id(instrument_id);
    Status status = instruments_service_->GetForecastBy(MakeContext().get(), request, &response);
    return ServiceReply::PrepareServiceAnswer<GetForecastResponse>(status, response);
}