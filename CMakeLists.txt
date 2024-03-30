
cmake_minimum_required(VERSION 3.8)

project(TinkoffInvestSDKCPP)

include(GenerateExportHeader)
include(cmake/common.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

file(GLOB TINKOFF_PROTOS "${CMAKE_CURRENT_SOURCE_DIR}/third-party/RussianInvestments/investAPI/src/docs/contracts/*.proto")

set(gRPC_CPP_PLUGIN /Users/eliseymuxin/CLionProjects/test_grpc/cmake-build-debug/vcpkg_installed/arm64-osx/tools/grpc/grpc_cpp_plugin)

set(PROTO_GEN_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/protofiles)

foreach (PROTO_FILE ${TINKOFF_PROTOS})
        get_filename_component(PROTO_FILE_NAME ${PROTO_FILE} NAME_WE)
        get_filename_component(PROTO_FILE_PATH ${PROTO_FILE} PATH)

        execute_process(COMMAND protoc
                --cpp_out=/Users/eliseymuxin/CLionProjects/TinkoffInvestSDKCPP/protofiles
                --grpc_out=/Users/eliseymuxin/CLionProjects/TinkoffInvestSDKCPP/protofiles
                --plugin=protoc-gen-grpc=${gRPC_CPP_PLUGIN}
                -I /Users/eliseymuxin/CLionProjects/TinkoffInvestSDKCPP/third-party/RussianInvestments/investAPI/src/docs/contracts
                ${PROTO_FILE}
        )

        include_directories(${PROTO_GEN_FOLDER})
        list(APPEND GENERATED_PROTOS_IMP "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.pb.cc" "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.grpc.pb.cc")
        list(APPEND GENERATED_PROTOS_HDR "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.pb.cc" "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.grpc.pb.cc")

        #get_filename_component(PROTO_FILE_PATH "${PROTO_FILE}" PATH)
        #file(GLOB PROTO_FILES "${PROTO_FILE}")
        #string(REPLACE ${PROTO_FILE_PATH} ${CMAKE_CURRENT_BINARY_DIR} OUTPUT_FILE_NAMES "${PROTO_FILES}")
        #string(REPLACE ".proto" ".pb.cc" OUTPUT_PB_SOURCE "${OUTPUT_FILE_NAMES}")
        #string(REPLACE ".proto" ".grpc.pb.cc" OUTPUT_GRPC_SOURCE "${OUTPUT_FILE_NAMES}")
        #string(REPLACE ".proto" ".pb.h" OUTPUT_PB_HEADER "${OUTPUT_FILE_NAMES}")
        #string(REPLACE ".proto" ".grpc.pb.h" OUTPUT_GRPC_HEADER "${OUTPUT_FILE_NAMES}")
        #add_custom_command(
         #       OUTPUT ${OUTPUT_PB_SOURCE} ${OUTPUT_PB_HEADER} ${OUTPUT_GRPC_SOURCE} ${OUTPUT_GRPC_HEADER}
         #       COMMAND ${_PROTOBUF_PROTOC}
         #       ARGS --grpc_out "${CMAKE_CURRENT_SOURCE_DIR}/protofiles"
                #--proto_path ${CMAKE_BINARY_DIR}/_deps/grpc-src/third_party/protobuf/src
         #       --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}/protofiles"
         #       -I "${PROTO_FILE_PATH}"
         #       --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
         #       "${PROTO_FILE}")

        #list(APPEND GENERATED_PROTOS_IMP ${OUTPUT_PB_SOURCE} ${OUTPUT_GRPC_SOURCE})
        #list(APPEND GENERATED_PROTOS_HDR ${OUTPUT_PB_HEADER} ${OUTPUT_GRPC_HEADER})

endforeach (PROTO_FILE ${TINKOFF_PROTOS})

file(GLOB SERVICES_IMP "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.cpp")
file(GLOB SERVICES_HDR "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.h")

add_library(tink_grpc_proto
        ${GENERATED_PROTOS_IMP}
        ${GENERATED_PROTOS_HDR}
)

target_link_libraries(tink_grpc_proto
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

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
