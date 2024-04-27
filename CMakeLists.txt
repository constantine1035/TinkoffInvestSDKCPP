cmake_minimum_required(VERSION 3.1)

project(TinkoffInvestSDKCPP)
include(GenerateExportHeader)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

set(GEN_PROJECT_NAME CppRestOpenAPIClient)
set(GEN_DIR ${CMAKE_CURRENT_BINARY_DIR}/gen)
#file(MAKE_DIRECTORY ${GEN_DIR})

#execute_process(COMMAND openapi-generator generate
#        -i ${CMAKE_CURRENT_SOURCE_DIR}/third-party/RussianInvestments/investAPI/src/docs/swagger-ui/openapi.yaml
#        -g cpp-restsdk
#        -o ${GEN_DIR}
#)

add_subdirectory(${GEN_DIR})

include_directories(${GEN_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(include)

file(GLOB SERVICES_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB SERVICES_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/include/tinkoff_invest_cppsdk/*.h")

add_library(${PROJECT_NAME}
        ${SERVICES_SRC_FILES}
        ${SERVICES_HEADER_FILES}
)

#find_package(cpprestsdk REQUIRED)
#include_directories(${CPPRESTSDK_INCLUDE_DIR})

#find_package(Boost REQUIRED)
#include_directories(${Boost_INCLUDE_DIRS})

#find_package(OpenSSL REQUIRED)
#include_directories(${OPENSSL_INCLUDE_DIR})

#target_include_directories(${PROJECT_NAME}
#        PRIVATE
#        ${PROJECT_SOURCE_DIR}
#        ${GEN_DIR}/include
#        include
#)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        ${GEN_PROJECT_NAME}
#        ${Boost_LIBRARIES}
#        ${OPENSSL_LIBRARIES}
#        ${CPPRESTSDK_LIBRARIES}
)

generate_export_header(${PROJECT_NAME})

add_subdirectory(examples)
