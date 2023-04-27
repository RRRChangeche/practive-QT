cmake_minimum_required(VERSION 3.16)

project(QT6_ep29_QtQuick-QML VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appQT6_ep29_QtQuick-QML
    main.cpp
    calculate.h
    calculate.cpp
)

qt_add_qml_module(appQT6_ep29_QtQuick-QML
    URI QT6_ep29_QtQuick-QML
    VERSION 1.0
    QML_FILES Main.qml
    calculate.cpp
    calculate.h
)

set_target_properties(appQT6_ep29_QtQuick-QML PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQT6_ep29_QtQuick-QML
    PRIVATE Qt6::Quick
)

install(TARGETS appQT6_ep29_QtQuick-QML
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
