#include "based_service.h"

#include "../include/xxhr/xxhr/sync.hpp"

namespace tinkoff_invest_sdk_cpp_based_service {

BasedService::BasedService(const std::string &token) : token_(token) {
}

ServiceReply BasedService::DoPostRequestSync(const nlohmann::json &body,
                                             const std::string &url) {
    using namespace xxhr;

    xxhr::sync sync1;

    xxhr::POST(url,
               Header {
                   {"accept", "application/json"},
                   {"Authorization", "Bearer " + token_},
                   {"Content-Type", "application/json"}
               },
               Body {
                   body.dump(2)
               },
               on_response = sync1
    );
    return ServiceReply(sync1());
}

ServiceReply BasedService::DoPostRequestAsync(const nlohmann::json &body,
                                              const std::string& url) {
    using namespace xxhr;

    Response response;

    xxhr::POST(url,
               Header {
                   {"accept", "application/json"},
                   {"Authorization", "Bearer " + token_},
                   {"Content-Type", "application/json"}
               },
               Body {
                   body.dump(2)
               },
               on_response = [&response](auto&& resp) {
                   response = std::move(resp);
               }
    );
    return ServiceReply(response);
}

} // namespace tinkoff_invest_sdk_cpp_based_service
