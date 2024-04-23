cmake_minimum_required(VERSION 3.28)

project(TinkoffInvestSDKCPP)

include(GenerateExportHeader)
include(cmake/common.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

file(GLOB TINKOFF_PROTOS "${CMAKE_CURRENT_SOURCE_DIR}/third-party/RussianInvestments/investAPI/src/docs/contracts/*.proto")

set(gRPC_CPP_PLUGIN /Users/eliseymuxin/.vcpkg-clion/vcpkg/packages/grpc_arm64-osx/tools/grpc/grpc_cpp_plugin)
set(PROTOC /Users/eliseymuxin/.vcpkg-clion/vcpkg/packages/protobuf_arm64-osx/tools/protobuf/protoc)
set(PROTO_GEN_FOLDER ${CMAKE_CURRENT_BINARY_DIR})

file(MAKE_DIRECTORY "${PROTO_GEN_FOLDER}/google/api")

execute_process(COMMAND ${PROTOC}
        --cpp_out=${PROTO_GEN_FOLDER}/google/api
        --grpc_out=${PROTO_GEN_FOLDER}/google/api
        --plugin=protoc-gen-grpc=${gRPC_CPP_PLUGIN}
        -I ../third-party/RussianInvestments/investAPI/src/docs/contracts/google/api
        field_behavior.proto
)

foreach (PROTO_FILE ${TINKOFF_PROTOS})
    get_filename_component(PROTO_FILE_NAME ${PROTO_FILE} NAME_WE)
    get_filename_component(PROTO_FILE_PATH ${PROTO_FILE} PATH)

    #execute_process(COMMAND ${PROTOC}
    #        --cpp_out=${PROTO_GEN_FOLDER}
    #        --grpc_out=${PROTO_GEN_FOLDER}
    #        --plugin=protoc-gen-grpc=${gRPC_CPP_PLUGIN}
    #        -I ${PROTO_FILE_PATH}
    #        ${PROTO_FILE}
    #)

    list(APPEND GENERATED_PROTOS_SCRS "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.pb.cc" "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.grpc.pb.cc")
    list(APPEND GENERATED_PROTOS_HDRS "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.pb.cc" "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.grpc.pb.cc")

endforeach (PROTO_FILE ${TINKOFF_PROTOS})

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

file(GLOB SERVICES_SCRS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.cpp")
file(GLOB SERVICES_HDRS "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.h")

#file(GLOB EXAMPLES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.h")

#add_library(tink_grpc_proto
#        ${GENERATED_PROTOS_SRCS}
#        ${GENERATED_PROTOS_HDRS}
#)

#target_link_libraries(tink_grpc_proto
#        ${_REFLECTION}
#        ${_GRPC_GRPCPP}
#        ${_PROTOBUF_LIBPROTOBUF}
#)

#add_library(TinkoffInvestSDKCPP SHARED ${SERVICES_SCRS} ${SERVICES_HDRS} main.cpp) # ${EXAMPLES}

#target_include_directories(TinkoffInvestSDKCPP
#        PUBLIC
#        ${CMAKE_CURRENT_BINARY_DIR}
#        ${CMAKE_CURRENT_SOURCE_DIR}
#        ${CMAKE_CURRENT_BINARY_DIR}/services
#        ${CMAKE_CURRENT_SOURCE_DIR}/services
#        ${CMAKE_CURRENT_BINARY_DIR}/examples
#        ${CMAKE_CURRENT_SOURCE_DIR}/examples
#)

add_executable(TinkoffInvestSDKCPP
        ${GENERATED_PROTOS_SCRS}
        ${GENERATED_PROTOS_HDRS}
        ${SERVICES_SCRS}
        ${SERVICES_HDRS}
        main.cpp
        client.cpp
        client.h
)

target_link_libraries(TinkoffInvestSDKCPP
        PRIVATE
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF}
)

generate_export_header(TinkoffInvestSDKCPP)
