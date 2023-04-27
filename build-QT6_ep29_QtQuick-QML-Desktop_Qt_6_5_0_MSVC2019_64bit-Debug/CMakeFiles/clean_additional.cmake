# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appQT6_ep29_QtQuick-QML_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appQT6_ep29_QtQuick-QML_autogen.dir\\ParseCache.txt"
  "appQT6_ep29_QtQuick-QML_autogen"
  )
endif()
