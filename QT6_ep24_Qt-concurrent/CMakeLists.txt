cmake_minimum_required(VERSION 3.14)

project(QT6_ep24_Qt-concurrent LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Concurrent)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Concurrent)

add_executable(QT6_ep24_Qt-concurrent
  main.cpp
)
target_link_libraries(QT6_ep24_Qt-concurrent Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Concurrent)

install(TARGETS QT6_ep24_Qt-concurrent
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
