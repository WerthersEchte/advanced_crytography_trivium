cmake_minimum_required (VERSION 2.8.11)

set(MAIN_NAME advanced_cryptography_trivium_tests)

project ( ${MAIN_NAME} CXX )

FIND_PACKAGE( Boost COMPONENTS system unit_test_framework REQUIRED )

include_directories(    ../trivium
                        ${Boost_INCLUDE_DIR} )

set( SOURCE
   ${SOURCE}
   trivium/trivium_test.cpp
)

set( HEADERS
   ${HEADERS}
)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable( ${MAIN_NAME} WIN32 ${SOURCE} ${HEADERS}  )

target_link_libraries( ${MAIN_NAME} advanced_cryptography_trivium_library ${Boost_LIBRARIES} )
