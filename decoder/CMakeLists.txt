cmake_minimum_required(VERSION 3.15)

set(SRC_FILES
    )
set(HEADERS
    include/IMorseDictionary.h
    )

add_library(decoder STATIC ${SRC_FILES} ${HEADERS})
target_include_directories(decoder PUBLIC "include")
