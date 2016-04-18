cmake_minimum_required (VERSION 2.8.11)

set(MAIN_NAME advanced_cryptography_trivium_implementation)

project ( ${MAIN_NAME} CXX )

add_subdirectory(trivium)
add_subdirectory(tests)
