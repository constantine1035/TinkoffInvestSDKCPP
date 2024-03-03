cmake_minimum_required(VERSION 3.8)

project(TinkoffInvestSDKCPP)

include(GenerateExportHeader)
include(cmake/common.cmake)

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

file(GLOB PB_IMP "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/protofiles/*.cc")
file(GLOB PB_HDR "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/protofiles/*.h")
file(GLOB GRPC_IMP "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/protofiles/*.cc")
file(GLOB GRPC_HDR "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/protofiles/*.h")

file(GLOB SERVICES_IMP "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.cpp")
file(GLOB SERVICES_HDR "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.h")

add_library(tink_grpc_proto
        ${PB_IMP}
        ${PB_HDR}
        ${GRPC_IMP}
        ${GRPC_HDR}
)

target_link_libraries(tink_grpc_proto
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})

add_library(${PROJECT_NAME} SHARED ${SERVICES_IMP} ${SERVICES_HDR})

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

generate_export_header(${PROJECT_NAME})
