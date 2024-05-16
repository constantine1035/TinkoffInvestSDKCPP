cmake_minimum_required(VERSION 3.5.1)

project(trading_bot LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
        main.cpp
)

target_link_libraries(${PROJECT_NAME}
        TinkoffInvestSDKCPP
        CppRestOpenAPIClient
)
