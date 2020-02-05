cmake_minimum_required( VERSION 3.5 )

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package( eosio )

string(FIND "${EOSIO_VERSION}" "${EOSIO_DEPENDENCY}" output)
if (NOT "${output}" EQUAL 0)
    message(FATAL_ERROR "Incorrect EOSIO version, please use version ${EOSIO_DEPENDENCY}.x")
endif()

enable_testing()

configure_file( ${CMAKE_SOURCE_DIR}/contracts.hpp.in ${CMAKE_BINARY_DIR}/contracts.hpp )

#include_directories( ${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/contracts.hpp ${CMAKE_SOURCE_DIR}/../../../../../eosio.cdt/libraries/eosiolib/contracts/ ${CMAKE_SOURCE_DIR}/../include ${CMAKE_SOURCE_DIR}/../../../../../eosio.cdt/libraries/boost/include ${CMAKE_SOURCE_DIR}/../../../../../eosio.contracts/contracts/eosio.token/include)

include_directories( ${CMAKE_BINARY_DIR}  ${CMAKE_SOURCE_DIR}/../../../../../eosio.contracts/contracts/eosio.token/include ${CMAKE_SOURCE_DIR}/../include )

file( GLOB UNIT_TESTS "*.cpp" "*.hpp" )

add_eosio_test( unit_test ${UNIT_TESTS} )

target_compile_options( unit_test PUBLIC -ftemplate-backtrace-limit=0 )
