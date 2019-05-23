cmake_minimum_required(VERSION 3.14)
project(libUTAU)

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -O3 -Wall -fPIC")
set(CMAKE_CXX_STANDARD 17)

include_directories(src/UTAU/)

aux_source_directory(src UTAU_SRC_SOURCES)
add_library(UTAU STATIC ${UTAU_SRC_SOURCES})

set_target_properties(UTAU PROPERTIES
        CXX_STANDARD 17
        POSITION_INDEPENDENT_CODE ON
        )