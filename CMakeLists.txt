cmake_minimum_required(VERSION 3.5)

project(MorseDecoder)
include(cmake/PreventInSourceBuilds.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/StaticAnalyzers.cmake)

find_package(Qt5Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)

add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(decoder)

set(SRC_FILES
    main.cpp
    MainWindow.h
    MainWindow.cpp)


add_executable(MorseDecoder ${SRC_FILES})
target_link_libraries(MorseDecoder PRIVATE decoder
                                           project_warnings
                                           Qt5::Widgets)

option(ENABLE_FUZZING "Enable fuzz testing" OFF)
if(ENABLE_FUZZING)
    message("Building fuzz tests")
    add_subdirectory(fuzz_test)
endif()
