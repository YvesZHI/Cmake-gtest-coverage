set(INCLUDES ../${INCLUDES}) # ${INCLUDES} comes from parent
set(SOURCES ../${SOURCES}) # ${SOURCES} comes from parent
set(TESTSOURCES TestStudent.cpp)


set(TESTTARGET ${TARGET}-test)
set(TESTTARGETCOV ${TESTTARGET}-cov)
set(RESULTCOV cov.html)

find_program(GCOVR gcovr)
if(NOT GCOVR)
    message(FATAL_ERROR "gcovr not found!")
endif()
find_package(GTest REQUIRED)

# unit-test bin file
add_executable(${TESTTARGET} ${TESTSOURCES} ${SOURCES})
target_include_directories(${TESTTARGET} PRIVATE ${INCLUDES})
target_compile_options(${TESTTARGET} PRIVATE -std=c++11 -g -O0 -coverage)
#target_link_libraries(${TESTTARGET} -lgtest -lpthread gcov)
target_link_libraries(${TESTTARGET} GTest::GTest GTest::Main gcov)


# unit-test bin file & code coverage
add_custom_target(
    cov ALL # ALL is to make the target cov to be executed automatically while executing the command make
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
    COMMAND echo "gcovr -r ${PROJECT_SOURCE_DIR} --object-directory=${PROJECT_BINARY_DIR} --html --html-details -o ${RESULTCOV}" >>${TESTTARGETCOV}
    COMMAND chmod +x ${TESTTARGETCOV}
    )


# execute make clean-all to delete code coverage files
add_custom_target(
    clean-all
    COMMAND rm -f ${RESULTCOV} ${TESTTARGETCOV} && make clean
    )


enable_testing()
#include(GoogleTest)
#include(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#gtest_add_tests(TARGET ${TESTTARGET} AUTO)
