cmake_minimum_required (VERSION 2.8.11)

set(MAIN_NAME advanced_cryptography_trivium)

project ( ${MAIN_NAME} CXX )

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package( Qt5Widgets REQUIRED )
find_package( Qt5Core REQUIRED )
find_package( Qt5Gui REQUIRED )

set( SOURCE
   ${SOURCE}
   core/trivium.cpp
   gui/mainwindow.cpp
   gui/triviumwidget.cpp
   gui/bit.cpp
)

set( HEADERS
   ${HEADERS}
   core/trivium.h
   gui/mainwindow.h
   gui/triviumwidget.h
   gui/bit.h
)

set( UI_FILES
   ${UI_FILES}
   gui/ui/mainwindow.ui
   gui/ui/bit.ui
   gui/ui/trivium.ui
)

QT5_WRAP_UI( UI_HEADERS
   ${UI_FILES}
)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library (${MAIN_NAME}_library ${SOURCE} ${HEADERS} ${UI_HEADERS} ${UI_FILES} )
add_executable( ${MAIN_NAME} WIN32 main.cpp )

qt5_use_modules( ${MAIN_NAME}_library Widgets Core Gui )
target_link_libraries( ${MAIN_NAME} ${MAIN_NAME}_library )
