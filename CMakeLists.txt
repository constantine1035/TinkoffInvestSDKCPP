cmake_minimum_required(VERSION 3.28)

project(TinkoffInvestSDKCPP)
set(CMAKE_CXX_STANDARD 20)

file(GLOB SERVICES_SCRS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.cpp")
file(GLOB SERVICES_HDRS "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.h")

add_executable(TinkoffInvestSDKCPP
        ${SERVICES_SCRS}
        ${SERVICES_HDRS}
        main.cpp
        client.cpp
        client.h
)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

find_package(nlohmann_json REQUIRED)
include_directories(${NLOHMANN_INCLUDE_DIRS})

target_link_libraries(TinkoffInvestSDKCPP ${BOOST_LIBRARIES} ${OPENSSL_LIBRARIES} ${NLOHMANN_LIBRARIES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/xxhr)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/better-enums)