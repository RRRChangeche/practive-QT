# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QT6_ep16_OS_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QT6_ep16_OS_autogen.dir\\ParseCache.txt"
  "QT6_ep16_OS_autogen"
  )
endif()
