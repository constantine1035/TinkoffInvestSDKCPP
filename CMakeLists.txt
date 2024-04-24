cmake_minimum_required(VERSION 3.28)

project(TinkoffInvestSDKCPP)
set(CMAKE_CXX_STANDARD 17)

#file(GLOB SERVICES_SCRS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.cpp")
#file(GLOB SERVICES_HDRS "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/services/*.h")

add_executable(TinkoffInvestSDKCPP
#        ${SERVICES_SCRS}
#        ${SERVICES_HDRS}
        main.cpp
#        client.cpp
#        client.h
)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

target_link_libraries(TinkoffInvestSDKCPP ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

#target_include_directories()
#include_directories(${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/arm64-osx/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/xxhr)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/better-enums)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/openssl-cpp/include)

#file(GLOB BOOST_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/include/boost/libs/*)
#foreach (BOOST_LIB ${BOOST_LIBS})
#    include_directories(${BOOST_LIB}/include)
#    include_directories(${BOOST_LIB}/conversion/include)
#endforeach ()

#include_directories(${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/arm64-osx/include)


