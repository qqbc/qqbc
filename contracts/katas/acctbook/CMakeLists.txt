project(acctbook)

cmake_minimum_required(VERSION 3.5)

include(ExternalProject)

# if no cdt root is given use default path
#if(EOSIO_CDT_ROOT STREQUAL "" OR NOT EOSIO_CDT_ROOT)
#    find_package(eosio.cdt)
#endif()

set( EOSIO_CDT_REPO "$ENV{EOSIO_CDT_ROOT}" )
find_package( eosio.cdt PATHS ${EOSIO_CDT_REPO}/../modules )

ExternalProject_Add(
        acctbook_project
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/src
        BINARY_DIR ${CMAKE_BINARY_DIR}/acctbook
        CMAKE_ARGS -DCMAKE_TOOLCHAIN_FILE=${EOSIO_CDT_REPO}/lib/cmake/eosio.cdt/EosioWasmToolchain.cmake
        UPDATE_COMMAND ""
        PATCH_COMMAND ""
        TEST_COMMAND ""
        INSTALL_COMMAND ""
        BUILD_ALWAYS 1
)

ExternalProject_Add(
        acctbook_test_project
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/tests
        BINARY_DIR ${CMAKE_BINARY_DIR}/tests
        CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DEOSIO_ROOT=${EOSIO_ROOT} -DEOSIO_DEPENDENCY=${EOSIO_DEPENDENCY}
        #TEST_COMMAND ./unit_test
        TEST_COMMAND ./unit_test --color_output  --log_level=all -- --verbose
        INSTALL_COMMAND ""
        BUILD_ALWAYS 1
)

add_dependencies( acctbook_test_project acctbook_project)
