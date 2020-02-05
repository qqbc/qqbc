project(acctbook)

cmake_minimum_required(VERSION 3.5)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract( acctbook acctbook acctbook.cpp )

target_include_directories(
        acctbook PUBLIC
        ${CMAKE_SOURCE_DIR}/../../../../../eosio.contracts/contracts/eosio.token/include
        ${CMAKE_SOURCE_DIR}/../../../../../eos/libraries/chain/include
        ${CMAKE_SOURCE_DIR}/../include )
#target_ricardian_directory( send_inline ${CMAKE_SOURCE_DIR}/../ricardian )