# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ServerQt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ServerQt_autogen.dir\\ParseCache.txt"
  "ServerQt_autogen"
  )
endif()
