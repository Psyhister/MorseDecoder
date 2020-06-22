cmake_minimum_required(VERSION 3.5)

project(MorseDecoder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(decoder)
add_executable(MorseDecoder main.cpp)
target_link_libraries(MorseDecoder PRIVATE decoder)
