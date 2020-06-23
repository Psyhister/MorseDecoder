cmake_minimum_required(VERSION 3.5)

project(MorseDecoder)
include(cmake/PreventInSourceBuilds.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/StaticAnalyzers.cmake)

add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(decoder)
add_executable(MorseDecoder main.cpp)
target_link_libraries(MorseDecoder PRIVATE decoder)
target_link_libraries(MorseDecoder PRIVATE project_warnings)
