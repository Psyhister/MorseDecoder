cmake_minimum_required(VERSION 3.15)

set(SRC_FILES
    src/StaticMorseDictionary.cpp
    src/MorseDecoder.cpp
    )
set(HEADERS
    include/IMorseDictionary.h
    include/StaticMorseDictionary.h
    include/MorseDecoder.h
    )

add_library(decoder STATIC ${SRC_FILES} ${HEADERS})
target_include_directories(decoder PUBLIC "include")
