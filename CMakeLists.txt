cmake_minimum_required(VERSION 3.1)

project(TinkoffInvestSDKCPP)
include(GenerateExportHeader)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

# Bad generation openapi-generator (crypto = OpenSSL::Crypto)
find_package(OpenSSL CONFIG REQUIRED)
if (UNIX)
    add_library(crypto INTERFACE IMPORTED)
    set_target_properties(crypto PROPERTIES
            INTERFACE_LINK_LIBRARIES OpenSSL::Crypto
    )
else()
    add_library(bcrypt INTERFACE IMPORTED)
    set_target_properties(bcrypt PROPERTIES
            INTERFACE_LINK_LIBRARIES OpenSSL::BCrypt
    )
endif()

# Generate sdk with openapi-generator
set(GEN_PROJECT_NAME CppRestOpenAPIClient)
set(GEN_DIR ${CMAKE_CURRENT_BINARY_DIR}/gen)
file(MAKE_DIRECTORY ${GEN_DIR})

execute_process(COMMAND openapi-generator generate
        -i ${CMAKE_CURRENT_SOURCE_DIR}/third-party/RussianInvestments/investAPI/src/docs/swagger-ui/openapi.yaml
        -g cpp-restsdk
        -o ${GEN_DIR}
)

# Link project files
add_subdirectory(${GEN_DIR})

include_directories(${GEN_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(include)

file(GLOB_RECURSE SERVICES_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE SERVICES_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/tinkoff_invest_cppsdk/*.h")

add_library(${PROJECT_NAME}
        ${SERVICES_SRC_FILES}
        ${SERVICES_HEADER_FILES}
)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        ${GEN_PROJECT_NAME}
)

generate_export_header(${PROJECT_NAME})

# Directory with examples
add_subdirectory(examples)
