cmake_minimum_required(VERSION 3.14)
project(libUTAU)

set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(CMAKE_CXX_STANDARD 17)

include_directories(include/)

aux_source_directory(src UTAU_SRC_SOURCES)
add_library(UTAU STATIC ${UTAU_SRC_SOURCES})

set_target_properties(UTAU PROPERTIES CXX_STANDARD 17 POSITION_INDEPENDENT_CODE ON)


add_executable(ScaleConvertTest test/ScaleConvertTest.cpp)
target_link_libraries(ScaleConvertTest UTAU)

enable_testing()
add_test(NAME test_ScaleConvert_A4 COMMAND ScaleConvertTest A4)
set_tests_properties(test_ScaleConvert_A4 PROPERTIES PASS_REGULAR_EXPRESSION "440")

add_test(NAME test_ScaleConvert_Ab4 COMMAND ScaleConvertTest A\#4)
set_tests_properties(test_ScaleConvert_Ab4 PROPERTIES PASS_REGULAR_EXPRESSION "466.164")

add_test(NAME test_ScaleConvert_Cb4 COMMAND ScaleConvertTest C\#4)
set_tests_properties(test_ScaleConvert_Cb4 PROPERTIES PASS_REGULAR_EXPRESSION "277.183")