cmake_minimum_required(VERSION 3.8)

project(TinkoffInvestSDKCPP)

include(GenerateExportHeader)
include(cmake/common.cmake)

file(GLOB INVEST_API_PROTOS "${CMAKE_CURRENT_SOURCE_DIR}/investAPI/src/docs/contracts/*.proto")



add_library(tink_grpc_proto
        ${OUTPUT_PB_SOURCES}
        ${OUTPUT_PB_HEADERS}
        ${OUTPUT_GRPC_SOURCES}
        ${OUTPUT_GRPC_HEADERS}
        )

target_link_libraries(tink_grpc_proto
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF}
        )

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

file(GLOB SERVICES_IMP "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.cpp")
file(GLOB SERVICES_HDR "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.h")

add_library(${PROJECT_NAME} SHARED ${SERVICES_IMP} ${SERVICES_HDR})

generate_export_header(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}/services
        ${CMAKE_CURRENT_SOURCE_DIR}/services
        )

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        tink_grpc_proto
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF}
        )
