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

add_executable(PitchBendTest test/PitchBendTest.cpp)
target_link_libraries(PitchBendTest UTAU)

add_executable(libUTAUTest test/libUTAUTest.cpp)
target_link_libraries(libUTAUTest UTAU)

enable_testing()
add_test(NAME test_ScaleConvert_A4 COMMAND ScaleConvertTest A4)
set_tests_properties(test_ScaleConvert_A4 PROPERTIES PASS_REGULAR_EXPRESSION "440")

add_test(NAME test_ScaleConvert_Ab4 COMMAND ScaleConvertTest A\#4)
set_tests_properties(test_ScaleConvert_Ab4 PROPERTIES PASS_REGULAR_EXPRESSION "466")

add_test(NAME test_libUTAU COMMAND libUTAUTest '偄.wav 2_偄_F\#4_fF2qSv.wav F\#4 89 g100 5.0 1350 52.0 87.0 119 0 !137 AA\#87\#///9/6/3/z/w/t/q/o/n/o/q/t/y/5ABAJATAcAmAuA2A8BABCBBA+A3AuAjAWAG/2/l/U/D+0+o+e+X+U+V+a+j+w/B/V/sAEAdA2BOBkB3CGCRCWCWCRCGB2BgBHApAK/p/I+o+K9w9b9L9B8+9C9O9i99+c++/jAJAvBTB0CRCoC6DEDIDEC5CoCQBzBSAuAI/i+9+a989j9Q9F9A9D9M9b9x+K+o/I/qALArBJBkB6CMCYCeCeCZCOB+BqBTA6AfAD/p/Q+5+m+W+L+E+C+F+M+X+m+3/K/f/0AJAcAuA+BKBUBaBcBbBXBQBGA6AtAeAPAA/z/m/b/S/L/H/F/F/H/M/S/Z/i/q/z/8AEALARAWAZAb\#2\#AZAWATAPALAIAFACAA///+//AA\#1\#')
set_tests_properties(test_libUTAU PROPERTIES PASS_REGULAR_EXPRESSION "")