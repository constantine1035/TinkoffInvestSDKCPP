#pragma once

#include "tinkoffinvestsdkcpp_export.h"

#include <pplx/pplxtasks.h>
#include <system_error>

/*
 * service_reply.h
 *
 * This is a struct to hold response.
 */

namespace TINKOFFINVESTSDKCPP_EXPORT tinkoff_invest_cppsdk {

template <class ResponseType>
struct ServiceReply {
    // Request response.
    ResponseType response;

    // Api error message.
    std::string error_message;

    // what function calling.
    std::string error_place;

    // Api error code.
    std::error_code error_code;

    // Request status.
    pplx::task_status status;
};

}  // namespace tinkoff_invest_cppsdk