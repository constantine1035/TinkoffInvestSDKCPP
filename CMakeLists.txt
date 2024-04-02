cmake_minimum_required(VERSION 3.27)

project(TinkoffInvestSDKCPP C CXX)

include(GenerateExportHeader)
include(cmake/common.cmake)

#find_package(gRPC CONFIG REQUIRED)

#target_link_libraries(TinkoffInvestSDKCPP PRIVATE gRPC::gpr gRPC::grpc gRPC::grpc++ gRPC::grpc++_alts)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

file(GLOB TINKOFF_PROTOS "${CMAKE_CURRENT_SOURCE_DIR}/third-party/RussianInvestments/investAPI/src/docs/contracts/*.proto")

set(gRPC_CPP_PLUGIN /Users/eliseymuxin/.vcpkg-clion/vcpkg/packages/grpc_arm64-osx/tools/grpc/grpc_cpp_plugin)
set(PROTOC /Users/eliseymuxin/.vcpkg-clion/vcpkg/packages/protobuf_arm64-osx/tools/protobuf/protoc)

set(PROTO_GEN_FOLDER /Users/eliseymuxin/CLionProjects/TinkoffInvestSDKCPP/protofiles)

foreach (PROTO_FILE ${TINKOFF_PROTOS})
        get_filename_component(PROTO_FILE_NAME ${PROTO_FILE} NAME_WE)
        get_filename_component(PROTO_FILE_PATH ${PROTO_FILE} PATH)

        execute_process(COMMAND /Users/eliseymuxin/.vcpkg-clion/vcpkg/packages/protobuf_arm64-osx/tools/protobuf/protoc
                --cpp_out=/Users/eliseymuxin/CLionProjects/TinkoffInvestSDKCPP/protofiles
                --grpc_out=/Users/eliseymuxin/CLionProjects/TinkoffInvestSDKCPP/protofiles
                --plugin=protoc-gen-grpc=/Users/eliseymuxin/.vcpkg-clion/vcpkg/packages/grpc_arm64-osx/tools/grpc/grpc_cpp_plugin
                -I /Users/eliseymuxin/CLionProjects/TinkoffInvestSDKCPP/third-party/RussianInvestments/investAPI/src/docs/contracts
                "${PROTO_FILE}"
        )

        list(APPEND GENERATED_PROTOS_SCRS "/Users/eliseymuxin/CLionProjects/TinkoffInvestSDKCPP/protofiles/${PROTO_FILE_NAME}.pb.cc" "/Users/eliseymuxin/CLionProjects/TinkoffInvestSDKCPP/protofiles/${PROTO_FILE_NAME}.grpc.pb.cc")
        list(APPEND GENERATED_PROTOS_HDRS "/Users/eliseymuxin/CLionProjects/TinkoffInvestSDKCPP/protofiles/${PROTO_FILE_NAME}.pb.cc" "/Users/eliseymuxin/CLionProjects/TinkoffInvestSDKCPP/protofiles/${PROTO_FILE_NAME}.grpc.pb.cc")

endforeach (PROTO_FILE ${TINKOFF_PROTOS})

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

file(GLOB SERVICES_IMP "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.cpp")
file(GLOB SERVICES_HDR "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.h")

add_library(tink_grpc_proto
        ${GENERATED_PROTOS_SRCS}
        ${GENERATED_PROTOS_HDRS}
)

target_link_libraries(tink_grpc_proto
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})

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
