cmake_minimum_required(VERSION 3.20)
project(sketchup-api-demo)

set(CMAKE_OSX_ARCHITECTURES "x86_64" CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 20)

if(USE_SKETCHUP_2020_2_171)
    set(SKETCHUP_LIBRARY_HINT ${CMAKE_SOURCE_DIR}/extern/sketchup/SDK_Mac_2020-2-171)
elseif(USE_SKETCHUP_2021_0_338)
    set(SKETCHUP_LIBRARY_HINT ${CMAKE_SOURCE_DIR}/extern/sketchup/SDK_Mac_2021-0-338)
elseif (USE_SKETCHUP_2021_1_331)
    set(SKETCHUP_LIBRARY_HINT ${CMAKE_SOURCE_DIR}/extern/sketchup/SDK_Mac_2021-1-331)
elseif(USE_SKETCHUP_2022_0_353)
    set(SKETCHUP_LIBRARY_HINT ${CMAKE_SOURCE_DIR}/extern/sketchup/SDK_Mac_2022-0-353)
endif()

message(STATUS "Using SketchUp SDK ${SKETCHUP_LIBRARY_HINT}")

find_library(SKETCHUP_LIBRARY
        NAMES SketchUpAPI
        HINTS ${SKETCHUP_LIBRARY_HINT})
add_executable(sketchup-api-demo main.cpp)
target_link_libraries(sketchup-api-demo ${SKETCHUP_LIBRARY})
