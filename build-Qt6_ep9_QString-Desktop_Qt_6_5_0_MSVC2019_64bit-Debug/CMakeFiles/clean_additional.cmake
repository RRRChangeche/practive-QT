# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Qt6_ep9_QString_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Qt6_ep9_QString_autogen.dir\\ParseCache.txt"
  "Qt6_ep9_QString_autogen"
  )
endif()
