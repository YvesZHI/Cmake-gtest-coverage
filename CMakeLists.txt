cmake_minimum_required(VERSION 3.9)
project(Student CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)

set(SOURCES src/Student.cpp)
set(TARGET student)
set(TESTSOURCES unittest/TestStudent.cpp)
set(TESTTARGET student-test)
set(TESTTARGETCOV ${TESTTARGET}-cov)
set(RESULTCOV cov.html)
set(INCLUDES include)

find_program(GCOVR gcovr)
if(NOT GCOVR)
    message(FATAL_ERROR "gcovr not found!")
endif()
find_package(GTest REQUIRED)

# normal bin file
add_executable(${TARGET} src/main.cpp ${SOURCES})
target_include_directories(${TARGET} PRIVATE ${INCLUDES})
target_compile_options(${TARGET} PRIVATE -std=c++11 -g)

# unit-test bin file
add_executable(${TESTTARGET} ${TESTSOURCES} ${SOURCES})
target_include_directories(${TESTTARGET} PRIVATE ${INCLUDES})
target_compile_options(${TESTTARGET} PRIVATE -std=c++11 -g -O0 -coverage)
#target_link_libraries(${TESTTARGET} -lgtest -lpthread gcov)
target_link_libraries(${TESTTARGET} GTest::GTest GTest::Main gcov)


# unit-test bin file & code coverage
add_custom_target(
    cov ALL
    DEPENDS ${TESTTARGET}
    )

# bash script to generate code coverage
add_custom_command(
    TARGET cov
    COMMAND touch ${TESTTARGETCOV}
    COMMAND echo "'#!/bin/bash'" >${TESTTARGETCOV}
    COMMAND echo >>${TESTTARGETCOV}
    COMMAND echo >>${TESTTARGETCOV}
    COMMAND echo "./${TESTTARGET}" >>${TESTTARGETCOV}
    COMMAND echo "gcovr -r ${PROJECT_SOURCE_DIR} --object-directory=${PROJECT_BINARY_DIR} --html -o cov.html" >>${TESTTARGETCOV}
    COMMAND chmod +x ${TESTTARGETCOV}
    )

enable_testing()
include(GoogleTest)
gtest_add_tests(TARGET student-test AUTO)
