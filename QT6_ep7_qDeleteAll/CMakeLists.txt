cmake_minimum_required(VERSION 3.14)

project(QT6_ep7_qDeleteAll LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(QT6_ep7_qDeleteAll
  main.cpp
  test.h
  test.cpp
)
target_link_libraries(QT6_ep7_qDeleteAll Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS QT6_ep7_qDeleteAll
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
