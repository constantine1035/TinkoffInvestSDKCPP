cmake_minimum_required(VERSION 3.5)
project(TinkoffInvestSDKCPP)

# Укажите версию CMake
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Найдите gRPC
find_package(gRPC REQUIRED)
find_package(Protobuf REQUIRED)

# Укажите путь к протофайлам
set(PROTO_FILES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/protofiles)

# Укажите протофайлы для компиляции
set(PROTO_FILES
        ${PROTO_FILES_PATH}/common.proto
        ${PROTO_FILES_PATH}/instruments.proto
        ${PROTO_FILES_PATH}/marketdata.proto
        ${PROTO_FILES_PATH}/operations.proto
        ${PROTO_FILES_PATH}/orders.proto
        ${PROTO_FILES_PATH}/sandbox.proto
        ${PROTO_FILES_PATH}/stoporders.proto
        ${PROTO_FILES_PATH}/users.proto
        # Укажите здесь все ваши протофайлы
)

set(gRPC_CPP_PLUGIN ${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/arm64-osx/tools/grpc/grpc_cpp_plugin)
#set(gRPC_CPP_PLUGIN /opt/homebrew/Cellar/grpc/1.62.1_1/bin/grpc_cpp_plugin)

# Сгенерировать протофайлы
foreach(PROTO_FILE ${PROTO_FILES})
    get_filename_component(PROTO_FILE_NAME ${PROTO_FILE} NAME_WE)
    set(PROTO_GEN_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/protofiles)

    # Генерация C++ кода
    execute_process(COMMAND ${Protobuf_PROTOC_EXECUTABLE}
            --cpp_out=${PROTO_GEN_FOLDER}
            --grpc_out=${PROTO_GEN_FOLDER}
            --plugin=protoc-gen-grpc=${gRPC_CPP_PLUGIN}
            -I ${PROTO_FILES_PATH}
            ${PROTO_FILE}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

    # Добавить сгенерированные файлы в цель компиляции
    include_directories(${PROTO_GEN_FOLDER})
    list(APPEND GENERATED_PROTO_SOURCES "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.pb.cc" "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.grpc.pb.cc")
    list(APPEND GENERATED_PROTO_HEADERS "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.pb.h" "${PROTO_GEN_FOLDER}/${PROTO_FILE_NAME}.grpc.pb.h")
endforeach()

# Укажите исполняемый файл и его исходные файлы
add_executable(TinkoffInvestSDKCPP
        #main.cpp
        #client.h
        #client.cpp
        ./services/based_service.h
        ./services/based_service.cpp
        ./services/reply.h
        ./services/reply.cpp
        ./services/users.h
        ./services/users.cpp
        ./services/orders.h
        ./services/orders.cpp
        ./services/instruments.h
        ./services/instruments.cpp
        ./services/operations.h
        ./services/operations.cpp
        ${GENERATED_PROTO_SOURCES}
        ${GENERATED_PROTO_HEADERS}
)

# Укажите, что необходимо подключить библиотеки gRPC и protobuf
target_link_libraries(TinkoffInvestSDKCPP
        gRPC::grpc++
        gRPC::grpc
        protobuf::libprotobuf
)