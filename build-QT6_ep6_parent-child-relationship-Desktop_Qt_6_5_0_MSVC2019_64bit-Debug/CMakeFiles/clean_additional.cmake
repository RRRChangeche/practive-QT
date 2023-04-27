# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QT6_ep6_parent-child-relationship_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QT6_ep6_parent-child-relationship_autogen.dir\\ParseCache.txt"
  "QT6_ep6_parent-child-relationship_autogen"
  )
endif()
